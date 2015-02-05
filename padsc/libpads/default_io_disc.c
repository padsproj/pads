/*
 * Implementations of some standard IO disciplines
 *
 *   fwrec:        an IO discipline for data with fixed-width records.
 *
 *   ctrec:        an IO discipline for character-terminated variable-width records
 *
 *                   For ASCII newline-terminated records use, '\n' or P_ASCII_NEWLINE
 *                   as the term character.  for EBCDIC newline-terminated records, use
 *                   P_EBCDIC_NEWLINE as the term character.
 *
 *   ctrec_eolcmt: a version of ctrec that adds the stripping of end-of-line comments
 *		   before passing IO elements to the parsing functions.
 *		     E.g.	20  # FTP Port 
 *		     becomes:	20
 *
 *                   The comment is assumed to be introduced by a single character which
 *		     is a parameter to the discipline.
 *
 *   vlrec:        an IO discipline for IBM style variable length records
 *                 with length specified at front
 *
 *   norec:        a raw bytes IO discipline that does not use EOR
 *
 *   fwrec_noseek: a version of fwrec that does not require that
 *                 the sfio stream be seekable
 *
 *   ctrec_noseek: a version of ctrec that does not require that
 *                 the sfio stream be seekable
 *
 *   ctrec_noseek_eolcmt: a version of ctrec_eolcmt that does not require that
 *                 the sfio stream be seekable
 *
 *   vlrec_noseek: a version of vlrec that does not require that
 *                 the sfio stream be seekable
 *
 *   norec_noseek: a version of norec that does not require that
 *                 the sfio stream be seekable
 *
 * NB In the current implementations of record-based disciplines, each elt
 * is an entire record (both bor and eor set) except possibly for the last
 * elt which sometimes has bor but NOT eor set (e.g., for a partial fwrec
 * or for a missing term char for ctrec).  Should we make this behavior a
 * requirement?  That would get rid of the need for the 'bor' flag.
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "pads-internal.h"
#include "pads-macros-gen.h"
#include "out_macros.h"
#include <stdio.h>

#ifdef IODISC_ALLOC_DEBUG
static unsigned long long IODISC_allocd_mem_ = 0ULL;
void IODISC_dbg_report(const char *context) {
  error(0, "%s: IODISC_allocd_mem_ = %llu", context, IODISC_allocd_mem_);
}

#define IODISC_NEW_ALLOC(sz) \
do { \
  IODISC_allocd_mem_ += (sz); \
  error(0, "XXX[%s:%d] new alloc of %d, IODISC_allocd_mem_ now = %llu", \
	__FILE__, __LINE__, (sz), IODISC_allocd_mem_); \
} while (0)

#define IODISC_REALLOC(old_sz, new_sz) \
do { \
  IODISC_allocd_mem_ += ((new_sz) - (old_sz)); \
  error(0, "XXX[%s:%d] realloc from %d to %d, IODISC_allocd_mem_ now = %llu", \
	__FILE__, __LINE__, (old_sz), (new_sz), IODISC_allocd_mem_); \
} while (0)

#define IODISC_FREE(sz) \
do { \
  IODISC_allocd_mem_ -= (sz); \
  error(0, "XXX[%s:%d] free of %d, IODISC_allocd_mem_ now = %llu", \
	__FILE__, __LINE__, (sz), IODISC_allocd_mem_); \
} while (0)

#define IODISC_VMCLOSE_CALLED \
do { \
  error(0, "XXX[%s:%d] vmclose called, assuming just freed %llu, resetting to 0", \
	__FILE__, __LINE__, IODISC_allocd_mem_); \
  IODISC_allocd_mem_ = 0; \
} while (0)
#else

#define IODISC_NEW_ALLOC(sz)             P_NULL_STMT
#define IODISC_REALLOC(old_sz, new_sz)   P_NULL_STMT
#define IODISC_FREE(sz)                  P_NULL_STMT
#define IODISC_VMCLOSE_CALLED            P_NULL_STMT

#endif


#define IODISC_NEED_AN_ELT(fn_name, elt, f_head, vm) \
  do { \
    if (P_SOME_ELTS(f_head)) { \
      (elt) = P_FIRST_ELT(f_head); \
      P_REMOVE_ELT(elt); \
    } else { \
      if (!((elt) = vmnewof((vm), 0, Pio_elt_t, 1, 0))) { \
	P_WARN(pads->disc, fn_name ": could not alloc space for input record"); \
      } \
      IODISC_NEW_ALLOC(sizeof(Pio_elt_t)); \
    } \
  } while (0)

#define IODISC_NEED_AN_ELT_W_IODATA(fn_name, elt, f_head, vm, iodata_t, xtra_bytes) \
  do { \
    if (P_SOME_ELTS(f_head)) { \
      (elt) = P_FIRST_ELT(f_head); \
      P_REMOVE_ELT(elt); \
    } else { \
      if (!((elt) = vmnewof((vm), 0, Pio_elt_t, 1, 0)) || \
	  !((elt)->disc_ptr = vmoldof((vm), 0, iodata_t, 1, xtra_bytes))) { \
	P_WARN(pads->disc, fn_name ": could not alloc space for input record"); \
      } \
      IODISC_NEW_ALLOC(sizeof(Pio_elt_t) + sizeof(iodata_t) + xtra_bytes); \
    } \
  } while (0)

#if 0
#define IODISC_RELOC_DBG(diff) \
  do { \
    if (pads->disc->error_fn) { \
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE DATA SHIFTED BY %d BYTES", diff); \
    } \
  } while (0)
#else
#define IODISC_RELOC_DBG(diff)  P_NULL_STMT
#endif

#if 0
#define IODISC_RELOC_DBG_ELT(elt) \
  do { \
    if (pads->disc->error_fn) { \
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d offset %d) = AT NEW LOC =>\n[%s]", elt->unit, elt->num, elt->offset, P_fmt_cstr_n(elt->begin, elt->len)); \
    } \
  } while (0)
#else
#define IODISC_RELOC_DBG_ELT(elt)          P_NULL_STMT
#endif

#define IODISC_RELOC_ELTS(fn_name, head, diff, tmpelt) \
  do { \
    IODISC_RELOC_DBG(diff); \
    for (tmpelt = P_FIRST_ELT(head); tmpelt != (head); tmpelt = tmpelt->next) { \
      (tmpelt->begin) += diff; \
      (tmpelt->end)   += diff; \
      IODISC_RELOC_DBG_ELT(tmpelt); \
    } \
  } while (0)

/* remove all elts from list -- put them on the free list */
#define IODISC_REMOVE_ALL_ELTS(head, f_head, tmpelt) \
  do { \
    while (P_SOME_ELTS(head)) { \
      tmpelt = P_FIRST_ELT(head); \
      P_REMOVE_ELT(tmpelt); \
      P_APPEND_ELT((f_head), tmpelt); \
    } \
  } while (0)

/* remove some elts from list -- put them on the free list */
#define IODISC_REMOVE_SOME_ELTS(head, f_head, keepelt, tmpelt) \
  do { \
    while (P_SOME_ELTS(head) && (tmpelt = P_FIRST_ELT(head)) != (keepelt)) { \
      P_REMOVE_ELT(tmpelt); \
      P_APPEND_ELT((f_head), tmpelt); \
    } \
  } while (0)

/* ================================================================================ */
/* P_io_disc_unmake: */

Perror_t P_io_disc_unmake(Pio_disc_t *io_disc)
{
  if (!io_disc || !io_disc->unmake_fn) return P_ERR;
  return io_disc->unmake_fn(io_disc);
}

/* ================================================================================ */
/* PDCI_iodisc_report_partial mimics PDCI_report_err for just one error case,
 * a missing EOR before encountering an EOF.
 */
void
PDCI_iodisc_report_partial(P_t *pads, Pio_elt_t *elt, int missing_term, size_t readlen, Pbyte *begin,
			   const char *whatfn, const char *format, ...)
{
  char       *severity = "Error";
  char       *msg      = "EOF encountered prior to expected EOR";
  char       *infn, *tmpstr1;
  Ploc_t loc;

  if (!pads->disc->error_fn || pads->disc->e_rep == PerrorRep_None) return;

  loc.b.num   = elt->num;
  loc.b.byte  = 1;
  loc.e.num   = elt->num;
  loc.e.byte  = readlen;

  PDCI_sfstr_seek2zero(pads->tmp2);
  sfprintf(pads->tmp2, "[in %s]", whatfn);
  infn = PDCI_sfstr_use(pads->tmp2);
  PDCI_sfstr_seek2zero(pads->tmp1);

  if (pads->disc->e_rep == PerrorRep_Min) {
    pads->disc->error_fn(NiL, P_LEV_WARN, "%s %s: %s %d byte %d: errCode %d",
		       severity, infn, elt->unit, loc.b.num, loc.b.byte, P_EOF_BEFORE_EOR);
    return;
  }

  if (readlen <= 1) {
    sfprintf(pads->tmp1, "%s %s: at %s %d at byte %d : ",
	     severity, infn,
	     elt->unit, loc.b.num, loc.b.byte);
  } else {
    sfprintf(pads->tmp1, "%s %s: at %s %d from byte %d to byte %d: ",
	     severity, infn,
	     elt->unit, loc.b.num, loc.b.byte, loc.e.byte);
  }

  if (format && strlen(format)) {
    va_list ap;
    va_start(ap, format);
    sfvprintf(pads->tmp1, format, ap);
    va_end(ap);
  } else {
    sfprintf(pads->tmp1, "%s", msg);
  }

  if (readlen && pads->disc->e_rep == PerrorRep_Max) {
    sfprintf(pads->tmp1, "\n[%s %d]", elt->unit, loc.b.num);
    tmpstr1 = P_fmt_cstr_n((char*)begin, readlen);
    if (missing_term) {
      sfprintf(pads->tmp1, "%s>>><<<", tmpstr1);
    } else {
      sfprintf(pads->tmp1, ">>>%s<<<", tmpstr1);
    }
  }
  pads->disc->error_fn(NiL, P_LEV_WARN, "%s", PDCI_sfstr_use(pads->tmp1));
}

/* ================================================================================ */
/* P_fwrec_noseek IMPLEMENTATION */

/* private types */
typedef struct P_fwrec_noseek_data_s {
  /* configuration fields */
  size_t          leader_len;
  size_t          data_len;
  size_t          trailer_len;
  size_t          block_size; /* leader_len + data_len + trailer_len */
  /* other fields */
  Vmalloc_t      *disc_vm;    /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;       /* head of IO rec list */
  Pio_elt_t      *f_head;     /* head of free list   */
  Sfio_t         *io;         /* Sfio stream to read from */
  int             eof;        /* hit EOF? */
  size_t          num;        /* unit number */
  char            unit[100];  /* unit description when reading blocks */
  Sfoff_t         tail_off;   /* tail offset (obtained on open + each sfread) */
} P_fwrec_noseek_data_t;

typedef struct P_fwrec_noseek_iodata_s {
  size_t    eof_putback; /* non-zero only if partial block was read */
  Pbyte     saved_byte;  /* we NULL byte after last data byte, use saved_byte to restore it */
  Pbyte     dbuf[1];     /* actual size : block_size+1 */
} P_fwrec_noseek_iodata_t;

Perror_t
P_fwrec_noseek_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t *sfio, Pio_elt_t *head)
{
  P_fwrec_noseek_data_t *data;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_fwrec_noseek_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_fwrec_noseek_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_fwrec_noseek_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_fwrec_noseek_sfopen: not in a valid closed state");
    return P_ERR;
  }
  data->io       = sfio;
  data->eof      = 0;
  data->head     = head;
  data->num      = 1;
  data->tail_off = sftell(sfio);
  return P_OK;
}

Perror_t
P_fwrec_noseek_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_fwrec_noseek_data_t     *data;
  P_fwrec_noseek_iodata_t   *iodata;
  Pio_elt_t                 *elt;
  int                        c, ctr;
  Pbyte                     *b, *bmin;
  Pdisc_t                   *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_fwrec_noseek_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_fwrec_noseek_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_fwrec_noseek_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_fwrec_noseek_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_fwrec_noseek_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    /* return remaining bytes to Sfio stream using sfungetc */
    ctr = 0;
    for (elt = P_LAST_ELT(data->head); (elt != io_cur_elt->prev) && (elt != data->head); elt = elt->prev) {
      iodata = (P_fwrec_noseek_iodata_t*)elt->disc_ptr;
      if (elt->eof) {
	/* eof elt, restore eof_putback bytes */
	bmin = iodata->dbuf;
	b = bmin + iodata->eof_putback - 1;
      } else {
	*(elt->end) = iodata->saved_byte;
	if (elt != io_cur_elt || elt->len == remain) {
	  /* restore all elt bytes, including leader and trailer bytes */
	  bmin = iodata->dbuf;
	  b = bmin + data->block_size - 1;
	} else {
	  /* elt is io_cur_elt and remain < elt->len; restore trailer plus remain only */
	  b = &(iodata->dbuf[data->block_size - 1]);
	  bmin = b - (remain + data->trailer_len);
	}
      }
      for (; b >= bmin; b--, ctr++) {
	c = *b;
	if (c != sfungetc(data->io, c)) {
	  P_WARN1(disc, "P_fwrec_noseek_sfclose: sfungetc failed, some bytes not restored -- restored %d bytes", ctr);
	  goto after_restore;
	}
      }
    }
    if (ctr) {
      P_DBG1(disc, "P_fwrec_noseek_sfclose: restored %d bytes using sfungetc", ctr);
    }
  }
 after_restore:

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  data->io      = 0;
  data->head    = 0; 
  return P_OK;
}

Perror_t
P_fwrec_noseek_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t** next_elt_out)
{
  P_fwrec_noseek_data_t     *data;
  P_fwrec_noseek_iodata_t   *iodata;
  Pio_elt_t                 *elt, *keepelt;
  ssize_t                    readlen;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_fwrec_noseek_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_fwrec_noseek_data_t*)io_disc->data;

  if (!data->io) {
    P_WARN(pads->disc, "P_fwrec_noseek_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_fwrec_noseek_read: called after returning eof flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_fwrec_noseek_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  /* move some elts to the free list */
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);
  IODISC_NEED_AN_ELT_W_IODATA("P_fwrec_noseek_read", elt, data->f_head, data->disc_vm, P_fwrec_noseek_iodata_t, data->block_size);
  if (!elt) {
    return P_ERR;
  }
  iodata = (P_fwrec_noseek_iodata_t*)elt->disc_ptr;
  elt->offset = data->tail_off;
  readlen = sfread(data->io, iodata->dbuf, data->block_size);
  data->tail_off = sftell(data->io);
  if (readlen < 0) {
    P_SYSERR(pads->disc, "P_fwrec_noseek_read: Error reading IO stream");
    readlen = 0;
  }
  elt->num = (data->num)++;
  if (readlen < data->block_size) { /* EOF case */
    elt->bor = 1;
    elt->eor = 0;
    elt->eof = 1;
    data->eof = 1;
    elt->len = 0; /* ignore partial data except for putback */
    elt->begin = elt->end = iodata->dbuf;
    iodata->eof_putback = readlen;
    elt->unit = "(EOF)";
    if (readlen) { /* report partial read */
      if (readlen > data->leader_len) {
	PDCI_iodisc_report_partial(pads, elt, 0, readlen - data->leader_len, elt->begin + data->leader_len,
				   "P_fwrec_noseek_read", "Insufficient bytes in final record read, got %lu, expecting %lu",
				   (unsigned long)readlen, (unsigned long)data->block_size);
      } else {
	PDCI_iodisc_report_partial(pads, elt, 0, 0, elt->begin,
				   "P_fwrec_noseek_read", "Insufficient bytes in final record read, got %lu, expecting %lu",
				   (unsigned long)readlen, (unsigned long)data->block_size);
      }
    }
  } else {
    elt->bor = 1;
    elt->eor = 1;
    elt->eof = 0;
    elt->len = data->data_len;
    elt->begin = iodata->dbuf + data->leader_len;
    elt->end   = elt->begin + elt->len;
    iodata->eof_putback = 0;
    iodata->saved_byte = *(elt->end);
    elt->unit = (const char*)data->unit;
  }
  *(elt->end) = 0; /* null-terminate the bytes read */
  P_APPEND_ELT(data->head, elt);
#if 0
  if (pads->disc->error_fn) {
    pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
  }
#endif
  (*next_elt_out) = elt;
  return P_OK;
}

ssize_t
P_fwrec_noseek_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  /* nothing to fill in */
  return 0;
}

ssize_t
P_fwrec_noseek_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  /* nothing to fill in */
  return 0;
}

ssize_t
P_fwrec_noseek_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_fwrec_noseek_blk_close: not a record-block-based discipline!");
  return -1;
}

Perror_t
P_fwrec_noseek_unmake(Pio_disc_t* io_disc)
{
  P_fwrec_noseek_data_t   *data;

  if (!io_disc) {
    P_WARN(&Pdefault_disc, "P_fwrec_noseek_unmake: bad param(s)");
    return P_ERR;
  }
  data = (P_fwrec_noseek_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_fwrec_noseek_unmake: sfclose should have been called first, calling it now.");
      P_fwrec_noseek_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_fwrec_noseek_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  P_fwrec_noseek_data_t     *data;

  if (!io_disc || !io_disc->data) return 0;
  data = (P_fwrec_noseek_data_t*)io_disc->data;
  return data->unit;
}

Pio_disc_t *
P_fwrec_noseek_make(size_t leader_len, size_t data_len, size_t trailer_len)
{
  Vmalloc_t              *disc_vm = 0;
  P_fwrec_noseek_data_t  *data;
  Pio_disc_t             *io_disc;
  Pio_elt_t              *f_head;

  if (data_len < 1) {
    P_WARN(&Pdefault_disc, "P_fwrec_noseek_make: data_len must be > 0");
    return 0;
  }

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_fwrec_noseek_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_fwrec_noseek_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->leader_len    = leader_len;
  data->data_len      = data_len;
  data->trailer_len   = trailer_len;
  data->block_size    = leader_len + data_len + trailer_len;
  data->f_head        = f_head;

  if ((data->block_size % 1024) == 0) {
    sprintf(data->unit,  "%dKB Block", data->block_size / 1024);
  } else {
    sprintf(data->unit,  "%dB Block", data->block_size);
  }

  io_disc->unmake_fn    = P_fwrec_noseek_unmake;
  io_disc->sfopen_fn    = P_fwrec_noseek_sfopen;
  io_disc->sfclose_fn   = P_fwrec_noseek_sfclose;
  io_disc->read_fn      = P_fwrec_noseek_read;
  io_disc->rec_close_buf_fn = P_fwrec_noseek_rec_buf_close;
  io_disc->rec_close_io_fn = P_fwrec_noseek_rec_io_close;
  io_disc->blk_close_fn = P_fwrec_noseek_blk_close;
  io_disc->read_unit_fn = P_fwrec_noseek_read_unit;

  io_disc->name         = "fwrec_noseek";
  io_disc->descr        = "an IO discipline for data with fixed-width records";
  io_disc->rec_based    = 1;
  io_disc->has_rblks    = 0;
  io_disc->rec_obytes   = 0;
  io_disc->rec_cbytes   = 0;
  io_disc->blk_obytes   = 0;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_fwrec_noseek_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

/* ================================================================================ */
/* P_norec_noseek IMPLEMENTATION */

/* when not specified, use blocks of this size (bytes): */
#define P_NOREC_NOSEEK_DEF_BSIZE    512
/* initial block alloc */
#define P_NOREC_NOSEEK_INIT_BLOCKS   16
/* once we can free at least this many blocks, do so */
#define P_NOREC_NOSEEK_GC_AT_BLOCK    8
/* if growth is necessary, add this many blocks at a time */
#define P_NOREC_NOSEEK_ADD_BLOCKS     8

/* private types */
typedef struct P_norec_noseek_data_s {
  /* configuration fields */
  size_t          block_size;
  /* other fields */
  Vmalloc_t      *disc_vm;    /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;       /* head of IO rec list */
  Pio_elt_t      *f_head;     /* head of free list   */
  Sfio_t         *io;         /* Sfio stream to read from */
  int             eof;        /* hit EOF? */
  size_t          num;        /* unit number */
  char            unit[100];  /* unit description when reading blocks */
  Pbyte          *dbuf;       /* resizable data buffer */
  Pbyte          *dbuf_end;   /* 1 beyond last byte read */
  size_t          balloc;     /* # blocks allocated */
  size_t          btail;      /* idx of last block in use */
  size_t          gc_point;
  Sfoff_t         tail_off;   /* tail offset (obtained on open + each sfread) */
} P_norec_noseek_data_t;

Perror_t
P_norec_noseek_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t* sfio, Pio_elt_t* head)
{
  P_norec_noseek_data_t *data;

  if (!pads || !pads->disc) {
      return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_norec_noseek_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_norec_noseek_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_norec_noseek_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_norec_noseek_sfopen: not in a valid closed state");
    return P_ERR;
  }

  data->io       = sfio;
  data->eof      = 0;
  data->head     = head;
  data->num      = 1;
  data->btail    = 0;
  data->dbuf_end = data->dbuf;
  data->tail_off = sftell(sfio);

  return P_OK;
}

Perror_t
P_norec_noseek_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_norec_noseek_data_t  *data;
  Pio_elt_t              *elt;
  int                     c, ctr;
  Pbyte                  *b, *bmin;
  Pdisc_t                *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_norec_noseek_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_norec_noseek_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_norec_noseek_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_norec_noseek_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_norec_noseek_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    /* return remaining bytes to Sfio stream using sfungetc */
    ctr = 0;
    b = data->dbuf_end - 1;
    bmin = io_cur_elt->end - remain;
    for (; b >= bmin; b--, ctr++) {
      c = *b;
      if (c != sfungetc(data->io, c)) {
	P_WARN1(disc, "P_norec_noseek_sfclose: sfungetc failed, some bytes not restored -- restored %d bytes", ctr);
	goto after_restore;
      }
    }
    if (ctr) {
      P_DBG1(disc, "P_norec_noseek_sfclose: restored %d bytes using sfungetc", ctr);
    }
  }
 after_restore:

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  data->io      = 0;
  data->head    = 0; 

  return P_OK;
}

Perror_t
P_norec_noseek_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t** next_elt_out)
{
  P_norec_noseek_data_t  *data;
  Pio_elt_t              *elt, *keepelt;
  size_t                  keep_len;
  ssize_t                 readlen;
  Sfoff_t                 diff;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_norec_noseek_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_norec_noseek_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(pads->disc, "P_norec_noseek_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_norec_noseek_read: called after returning EOF flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_norec_noseek_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  /* move some elts to the free list */
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);

  if (!io_cur_elt) {
    data->btail = 0; /* starting from scratch */
    data->dbuf_end = data->dbuf;
  } else {
    /* choose or alloc block to use */
    if (++(data->btail) >= data->balloc) {
      /* need space */
      if (io_cur_elt->begin - data->dbuf >= data->gc_point) {
	/* garbage collect */
	diff = data->dbuf - io_cur_elt->begin; /* data moving down - negative offset */
	keep_len = data->dbuf_end - io_cur_elt->begin;
	memmove((void*)data->dbuf, (const void*)io_cur_elt->begin, keep_len);
	data->btail = (keep_len/data->block_size); /* # blocks copied => correct block index for next read */
	data->dbuf_end = data->dbuf + keep_len;
      } else {
	/* grow dbuf */
	Pbyte *dbuf_next;
	size_t balloc_next = data->balloc + P_NOREC_NOSEEK_ADD_BLOCKS;
	keep_len = data->dbuf_end - data->dbuf;
	if (!(dbuf_next = vmcpyoldof(data->disc_vm, data->dbuf, Pbyte, balloc_next * data->block_size, 1))) {
	  P_WARN(pads->disc, "P_norec_noseek_read: could not alloc space for input record");
	  (data->btail)--;
	  return P_ERR;
	}
	IODISC_REALLOC(data->balloc * data->block_size, balloc_next * data->block_size);
	diff           = dbuf_next - data->dbuf;
	data->balloc   = balloc_next;
	data->dbuf     = dbuf_next;
	data->dbuf_end = dbuf_next + keep_len;
	data->gc_point += (P_NOREC_NOSEEK_ADD_BLOCKS * data->block_size);
      }
      if (diff) { /* data moved, redo begin/end pointers */
	IODISC_RELOC_ELTS("P_norec_noseek_read", data->head, diff, elt);
      }
    } else {
      /* dbuf already had space at block btail */
    }
  }

  IODISC_NEED_AN_ELT("P_norec_noseek_read", elt, data->f_head, data->disc_vm);
  if (!elt) {
    return P_ERR;
  }

  elt->bor         = 0; /* norec_noseek never uses bor */
  elt->eor         = 0; /* norec_noseek never uses eor */
  elt->begin       = data->dbuf_end;
  elt->offset = data->tail_off;
  readlen = sfread(data->io, elt->begin, data->block_size);
  data->tail_off = sftell(data->io);
  if (readlen < 0) {
    P_SYSERR(pads->disc, "P_norec_noseek_read: Error reading IO stream");
    readlen = 0;
  }
  data->dbuf_end += readlen;
  *(data->dbuf_end) = 0; /* null-terminate dbuf -- note use of extra byte in vmoldof calls */
  elt->len = readlen;
  elt->end = data->dbuf_end;
  elt->num = (data->num)++;
  if (readlen == data->block_size) { /* full read */
    elt->eof = 0;
    elt->unit = (const char*)data->unit;
  } else { /* partial read, hit EOF */
    elt->eof = 1;
    data->eof = 1;
    if (elt->len == 0) { /* trivial EOF record */
      elt->unit = "(EOF)";
    } else { /* partial-read EOF record */
      elt->unit = (const char*)data->unit;
    }
  }
  P_APPEND_ELT(data->head, elt);
#if 0
  if (pads->disc->error_fn) {
    pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
  }
#endif
  (*next_elt_out) = elt;
  return P_OK;
}

ssize_t
P_norec_noseek_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_noseek_rec_buf_close: not a record-based discipline!");
  return -1;
}

ssize_t
P_norec_noseek_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_noseek_rec_io_close: not a record-based discipline!");
  return -1;
}

ssize_t
P_norec_noseek_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_noseek_blk_close: not a record-block-based discipline!");
  return -1;
}

Perror_t
P_norec_noseek_unmake(Pio_disc_t* io_disc)
{
  P_norec_noseek_data_t   *data;

  if (!io_disc) {
    P_WARN(&Pdefault_disc, "P_norec_noseek_unmake: bad param(s)");
    return P_ERR;
  }
  data = (P_norec_noseek_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_norec_noseek_unmake: sfclose should have been called first, calling it now");
      P_norec_noseek_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_norec_noseek_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  P_norec_noseek_data_t     *data;

  if (!io_disc || !io_disc->data) return 0;
  data = (P_norec_noseek_data_t*)io_disc->data;
  return data->unit;
}

Pio_disc_t *
P_norec_noseek_make(size_t block_size_hint)
{
  Vmalloc_t               *disc_vm = 0;
  P_norec_noseek_data_t   *data;
  Pio_disc_t              *io_disc;
  Pio_elt_t               *f_head;
  Pbyte                   *dbuf;
  size_t                   block_size;

  block_size = (block_size_hint) ? block_size_hint : P_NOREC_NOSEEK_DEF_BSIZE;

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_norec_noseek_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_norec_noseek_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));
  if (!(dbuf = vmoldof(disc_vm, 0, Pbyte, P_NOREC_NOSEEK_INIT_BLOCKS * block_size, 1))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(P_NOREC_NOSEEK_INIT_BLOCKS * block_size);

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->block_size    = block_size;
  data->f_head        = f_head;
  data->dbuf          = dbuf;
  data->gc_point      = P_NOREC_NOSEEK_GC_AT_BLOCK * block_size;
  data->balloc        = P_NOREC_NOSEEK_INIT_BLOCKS;

  if ((block_size % 1024) == 0) {
    sprintf(data->unit,  "%dKB Block", block_size / 1024);
  } else {
    sprintf(data->unit,  "%dB Block", block_size);
  }

  io_disc->unmake_fn    = P_norec_noseek_unmake;
  io_disc->sfopen_fn    = P_norec_noseek_sfopen;
  io_disc->sfclose_fn   = P_norec_noseek_sfclose;
  io_disc->read_fn      = P_norec_noseek_read;
  io_disc->rec_close_buf_fn = P_norec_noseek_rec_buf_close;
  io_disc->rec_close_io_fn = P_norec_noseek_rec_io_close;
  io_disc->blk_close_fn = P_norec_noseek_blk_close;
  io_disc->read_unit_fn = P_norec_noseek_read_unit;

  io_disc->name         = "norec_noseek";
  io_disc->descr        = "a raw bytes IO discipline that does not use EOR";
  io_disc->rec_based    = 0;
  io_disc->has_rblks    = 0;
  io_disc->rec_obytes   = 0;
  io_disc->rec_cbytes   = 0;
  io_disc->blk_obytes   = 0;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_norec_noseek_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

/* ================================================================================ */
/* P_ctrec_noseek_eolcmt IMPLEMENTATION */

/* when not specified, use blocks of this size (bytes): */
#define P_CTREC_NOSEEK_EOLCMT_DEF_BSIZE     512
/* initial block alloc */
#define P_CTREC_NOSEEK_EOLCMT_INIT_BLOCKS    16
/* once we can free at least this many blocks, do so */
#define P_CTREC_NOSEEK_EOLCMT_GC_AT_BLOCK     8
/* but only check if there are <= this many blocks left */
#define P_CTREC_NOSEEK_EOLCMT_GC_BLOCKS_LEFT  4
/* if growth is necessary, add this many blocks at a time */
#define P_CTREC_NOSEEK_EOLCMT_ADD_BLOCKS      8

/* private types */
typedef struct P_ctrec_noseek_eolcmt_data_s {
  /* configuration fields */
  Pbyte           cterm;
  Pbyte           cmtChar;
  size_t          block_size;
  /* other fields */
  Vmalloc_t      *disc_vm;     /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;        /* head of IO rec list */
  Pio_elt_t      *f_head;      /* head of free list   */
  Pio_elt_t      *eof_elt;     /* always keep around an elt to be used as EOF elt */
  Sfio_t         *io;          /* Sfio stream to read from */
  int             eof;         /* hit EOF? */
  size_t          num;         /* unit number */
  Pbyte          *dbuf;        /* resizable data buffer */
  Pbyte          *dbuf_end;    /* 1 beyond last byte read */ 
  size_t          un_bytes;    /* unread bytes: # bytes not yet part of IO rec list */
  size_t          balloc;      /* # blocks allocated */
  size_t          btail;       /* idx of last block in use */
  size_t          gc_point;
  char            descr[256];  /* description */ 
  Sfoff_t         tail_off;    /* tail offset (obtained on open + each sfread) */
} P_ctrec_noseek_eolcmt_data_t;

Perror_t
P_ctrec_noseek_eolcmt_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t* sfio, Pio_elt_t* head)
{
  P_ctrec_noseek_eolcmt_data_t  *data;
  Pio_elt_t             *elt; 

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_sfopen: not in a valid closed state");
    return P_ERR;
  }
  IODISC_NEED_AN_ELT("P_ctrec_noseek_eolcmt_sfopen", elt, data->f_head, data->disc_vm);
  if (!elt) {
    return P_ERR;
  }

  data->io           = sfio;
  data->eof          = 0;
  data->eof_elt      = elt;
  data->head         = head;
  data->num          = 1;
  data->btail        = 0;
  data->dbuf_end     = data->dbuf;
  data->un_bytes     = 0;
  data->tail_off     = sftell(sfio);

  return P_OK;
}

Perror_t
P_ctrec_noseek_eolcmt_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_ctrec_noseek_eolcmt_data_t  *data;
  Pio_elt_t              *elt;
  int                     c, ctr;
  Pbyte                  *b, *bmin;
  Pdisc_t                *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_ctrec_noseek_eolcmt_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_ctrec_noseek_eolcmt_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_ctrec_noseek_eolcmt_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_ctrec_noseek_eolcmt_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    /* return remaining bytes to Sfio stream using sfungetc */
    ctr = 0;
    b = data->dbuf_end - 1;
    bmin = io_cur_elt->end - remain;
    for (; b >= bmin; b--, ctr++) {
      c = *b;
      if (c != sfungetc(data->io, c)) {
	P_WARN1(disc, "P_ctrec_noseek_eolcmt_sfclose: sfungetc failed, some bytes not restored -- restored %d bytes", ctr);
	goto after_restore;
      }
    }
    if (ctr) {
      P_DBG1(disc, "P_ctrec_noseek_eolcmt_sfclose: restored %d bytes using sfungetc", ctr);
    }
  }
 after_restore:

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  if (data->eof_elt) {
    elt = data->eof_elt;
    data->eof_elt = 0;
    P_APPEND_ELT(data->f_head, elt);
  }

  data->io      = 0;
  data->head    = 0; 

  return P_OK;
}

Perror_t
P_ctrec_noseek_eolcmt_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t** next_elt_out)
{
  P_ctrec_noseek_eolcmt_data_t  *data;
  Pio_elt_t              *elt, *keepelt;
  ssize_t                 readlen, keep_len, discard_len, bytes_read;
  Pbyte                  *tmp;
  Pbyte                  *found_cterm;
  Pbyte                  *found_eolcmt;
  Sfoff_t                 diff, next_elt_off;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data;

  if (!data->io) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: called after returning EOF flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  /* move some elts to the free list */
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);
  /*
   * garbage collect if <= P_CTREC_NOSEEK_EOLCMT_GC_BLOCKS_LEFT and there is
   * a good chunk of data to be discarded
   */
  if (io_cur_elt) {
    keep_len = data->dbuf_end - io_cur_elt->begin;
    if (keep_len % data->block_size) { /* round up to nearest block size */
      keep_len += (data->block_size - (keep_len % data->block_size));
    }
  } else if (data->un_bytes) {
    keep_len = data->block_size;
  } else {
    keep_len = 0;
  }
  discard_len = (data->dbuf_end - data->dbuf) - keep_len;
  if (keep_len) {
    if (data->balloc - data->btail < P_CTREC_NOSEEK_EOLCMT_GC_BLOCKS_LEFT && discard_len >= data->gc_point) {
      /* garbage collect */
      diff = - discard_len; /* data moving down - negative offset */
      memmove((void*)data->dbuf, (const void*)(data->dbuf_end - keep_len), keep_len);
      data->btail = keep_len/data->block_size; /* # blocks copied -> index of next block index */
      data->dbuf_end = data->dbuf + keep_len;
      /* redo begin/end ptrs */
      IODISC_RELOC_ELTS("P_ctrec_noseek_eolcmt_read", data->head, diff, elt);
      *(data->dbuf_end) = 0; /* null-terminate dbuf */
    } /* keep everything -- postpone the memmove */
  } else {
    /* starting from scratch, no io_cur_elt or unread bytes */
    data->btail = 0;
    data->dbuf_end = data->dbuf;
    *(data->dbuf_end) = 0; /* null-terminate dbuf */
  }

  bytes_read      = 0;
  found_cterm     = 0;
  found_eolcmt	  = 0;
  next_elt_off   = data->tail_off - data->un_bytes;
  while (1) { /* read blocks until find cterm or EOF */
    /* choose or alloc block to use */
    if (data->btail >= data->balloc) {
      /* need space -- grow dbuf */
      Pbyte *dbuf_next;
      size_t balloc_next = data->balloc + P_CTREC_NOSEEK_EOLCMT_ADD_BLOCKS;
      keep_len = data->dbuf_end - data->dbuf;
      if (!(dbuf_next = vmcpyoldof(data->disc_vm, data->dbuf, Pbyte, balloc_next * data->block_size, 1))) {
	P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: could not alloc space for input record");
	readlen = 0;
	break; /* continue after while to take care of earlier bytes_read, if any */
      }
      IODISC_REALLOC(data->balloc * data->block_size, balloc_next * data->block_size);
      diff           = dbuf_next - data->dbuf;
      data->balloc   = balloc_next;
      data->dbuf     = dbuf_next;
      data->dbuf_end = dbuf_next + keep_len;
      data->gc_point += (P_CTREC_NOSEEK_EOLCMT_ADD_BLOCKS * data->block_size);
      if (diff) { /* data moved, redo begin/end pointers */
	IODISC_RELOC_ELTS("P_ctrec_noseek_eolcmt_read", data->head, diff, elt);
      }
    } else {
      /* dbuf already had space at block index btail */
    }
    readlen = sfread(data->io, data->dbuf_end, data->block_size);
    data->tail_off = sftell(data->io);
    if (readlen < 0) {
      P_SYSERR(pads->disc, "P_ctrec_noseek_eolcmt_read: Error reading IO stream");
      readlen = 0;
      break;
    }
    if (readlen == 0) {
      break;
    }
    (data->btail)++;
    bytes_read += readlen;
    tmp = data->dbuf_end;
    data->dbuf_end += readlen;
    *(data->dbuf_end) = 0; /* null-terminate dbuf -- note use of extra byte in vmoldof calls */
    if ((found_cterm = PDCI_findfirst(tmp, data->dbuf_end, data->cterm))) {
      break;
    }
    /* read another block */
  }
  /* bytes_read reflects all reads, readlen reflects last read */
  data->un_bytes += bytes_read;
  tmp = data->dbuf_end - data->un_bytes;
  /* first add any EOR-based records */
  while (found_cterm) {
    IODISC_NEED_AN_ELT("P_ctrec_noseek_eolcmt_read", elt, data->f_head, data->disc_vm);
    if (!elt) { /* turn this error into an EOF case */
      P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_read: internal memory alloc error, entering EOF state");
      readlen = 0;
      break;
    }
    /* AJF: do the comment scan here */
    found_eolcmt = PDCI_findfirst(tmp, data->dbuf_end, data->cmtChar);

    elt->begin     = tmp;
    elt->end       = (found_eolcmt < found_cterm ? (found_eolcmt ? found_eolcmt : found_cterm) : found_cterm);
    elt->len       = (found_eolcmt < found_cterm ? (found_eolcmt ? found_eolcmt : found_cterm) : found_cterm) - tmp;
    elt->bor       = 1;
    elt->eor       = 1;
    elt->eof       = 0;
    elt->num       = (data->num)++;
    elt->unit      = "record";
    elt->offset = next_elt_off;	/* AJF!!! */
    next_elt_off += ((found_cterm - tmp) + 1); /* account for cterm */ 
    data->un_bytes -= ((found_cterm - tmp) + 1); /* acount for cterm */ 
    elt->begin[elt->len] = 0; /* null-terminate the record, replaces cterm/cmtChar with NULL */
    P_APPEND_ELT(data->head, elt);
#if 0
    if (pads->disc->error_fn) {
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
    }
#endif
    if (!(*next_elt_out)) {
      (*next_elt_out) = elt;
    }
    tmp = data->dbuf_end - data->un_bytes;
    found_cterm = PDCI_findfirst(tmp, data->dbuf_end, data->cterm);
  }
  if (readlen < data->block_size) { /* put rest of bytes in EOF IO rec */
    elt = data->eof_elt;
    data->eof_elt  = 0;

    /* AJF: do cmt scan here too */
    found_eolcmt = PDCI_findfirst(tmp, data->dbuf_end, data->cmtChar);

    elt->bor       = 1;
    elt->eor       = 0;
    elt->eof       = 1;
    data->eof      = 1;
    elt->begin     = tmp;
    elt->end       = (found_eolcmt ? found_eolcmt : data->dbuf_end);	/* AJF !!! */
    elt->len       = (found_eolcmt ? (found_eolcmt - tmp) : data->un_bytes);	/* AJF !!! */
    elt->offset	   = next_elt_off;
    data->un_bytes = 0;
    elt->num  = (data->num)++;
    if (elt->len == 0) { /* trivial EOF record */
      elt->unit = "(EOF)";
    } else { /* partial-read EOF record */
      //      char* missing = (data->cterm == '\n') ? "newline" : "terminating char";
      elt->unit = "record";
      //      PDCI_iodisc_report_partial(pads, elt, 1, elt->len, elt->begin,
      //			 "P_ctrec_noseek_eolcmt_read", "Final record not terminated properly, missing %s",
      //			 missing);
    }
    elt->begin[elt->len] = 0; /* null-terminate the record */
    P_APPEND_ELT(data->head, elt);
#if 0
    if (pads->disc->error_fn) {
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
    }
#endif
    if (!(*next_elt_out)) {
      (*next_elt_out) = elt;
    }
  } /* else found cterm in a full block read */
  return P_OK;
}

ssize_t
P_ctrec_noseek_eolcmt_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  P_ctrec_noseek_eolcmt_data_t  *data;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !(data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data) || !data->io || !rec_start) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_rec_buf_close: bad param(s)");
    return -1;
  }
  data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data;
  *buf = data->cterm;
  return 1;
}

ssize_t
P_ctrec_noseek_eolcmt_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  P_ctrec_noseek_eolcmt_data_t  *data;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !(data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data) || !io ) {
    P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_rec_io_close: bad param(s)");
    return -1;
  }
  return (-1 != sfprintf(io, "%c", data->cterm) ? 1 : 0);
}

ssize_t
P_ctrec_noseek_eolcmt_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_ctrec_noseek_eolcmt_blk_close: not a record-block-based discipline!");
  return -1;
}

Perror_t
P_ctrec_noseek_eolcmt_unmake(Pio_disc_t* io_disc)
{
  P_ctrec_noseek_eolcmt_data_t  *data;

  data = (P_ctrec_noseek_eolcmt_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_ctrec_noseek_eolcmt_unmake: sfclose should have been called first, calling it now");
      P_ctrec_noseek_eolcmt_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_ctrec_noseek_eolcmt_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  return "record";
}

Pio_disc_t *
P_ctrec_noseek_eolcmt_make(Pbyte termChar, Pbyte cmtChar, size_t block_size_hint)
{
  Vmalloc_t              *disc_vm = 0;
  P_ctrec_noseek_eolcmt_data_t  *data;
  Pio_disc_t             *io_disc;
  Pio_elt_t              *f_head;
  Pbyte                  *dbuf;
  size_t                  block_size;

  block_size = (block_size_hint) ? block_size_hint : P_CTREC_NOSEEK_EOLCMT_DEF_BSIZE;

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_ctrec_noseek_eolcmt_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_ctrec_noseek_eolcmt_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));
  if (!(dbuf = vmoldof(disc_vm, 0, Pbyte, P_CTREC_NOSEEK_EOLCMT_INIT_BLOCKS * block_size, 1))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(P_CTREC_NOSEEK_EOLCMT_INIT_BLOCKS * block_size);

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->cterm         = termChar;
  data->cmtChar       = cmtChar;
  data->block_size    = block_size;
  data->f_head        = f_head;
  data->dbuf          = dbuf;
  data->gc_point      = P_CTREC_NOSEEK_EOLCMT_GC_AT_BLOCK * block_size;
  data->balloc        = P_CTREC_NOSEEK_EOLCMT_INIT_BLOCKS;
  sprintf(data->descr, 
  "an IO discipline for variable-width records terminated by char %d (ASCII char %s) with eol comments introduced by char %d (ASCII char %s)",
	  termChar, P_qfmt_char(termChar), cmtChar, P_qfmt_char(cmtChar));

  io_disc->unmake_fn    = P_ctrec_noseek_eolcmt_unmake;
  io_disc->sfopen_fn    = P_ctrec_noseek_eolcmt_sfopen;
  io_disc->sfclose_fn   = P_ctrec_noseek_eolcmt_sfclose;
  io_disc->read_fn      = P_ctrec_noseek_eolcmt_read;
  io_disc->rec_close_buf_fn = P_ctrec_noseek_eolcmt_rec_buf_close;
  io_disc->rec_close_io_fn = P_ctrec_noseek_eolcmt_rec_io_close;
  io_disc->blk_close_fn = P_ctrec_noseek_eolcmt_blk_close;
  io_disc->read_unit_fn = P_ctrec_noseek_eolcmt_read_unit;

  io_disc->name         = "ctrec_noseek_eolcmt";
  io_disc->descr        = data->descr;
  io_disc->rec_based    = 1;
  io_disc->has_rblks    = 0;
  io_disc->rec_obytes   = 0;
  io_disc->rec_cbytes   = 1;
  io_disc->blk_obytes   = 0;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_ctrec_noseek_eolcmt_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

/* ================================================================================ */
/* P_ctrec_noseek IMPLEMENTATION */

/* when not specified, use blocks of this size (bytes): */
#define P_CTREC_NOSEEK_DEF_BSIZE     512
/* initial block alloc */
#define P_CTREC_NOSEEK_INIT_BLOCKS    16
/* once we can free at least this many blocks, do so */
#define P_CTREC_NOSEEK_GC_AT_BLOCK     8
/* but only check if there are <= this many blocks left */
#define P_CTREC_NOSEEK_GC_BLOCKS_LEFT  4
/* if growth is necessary, add this many blocks at a time */
#define P_CTREC_NOSEEK_ADD_BLOCKS      8

/* private types */
typedef struct P_ctrec_noseek_data_s {
  /* configuration fields */
  Pbyte           cterm;
  size_t          block_size;
  /* other fields */
  Vmalloc_t      *disc_vm;     /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;        /* head of IO rec list */
  Pio_elt_t      *f_head;      /* head of free list   */
  Pio_elt_t      *eof_elt;     /* always keep around an elt to be used as EOF elt */
  Sfio_t         *io;          /* Sfio stream to read from */
  int             eof;         /* hit EOF? */
  size_t          num;         /* unit number */
  Pbyte          *dbuf;        /* resizable data buffer */
  Pbyte          *dbuf_end;    /* 1 beyond last byte read */ 
  size_t          un_bytes;    /* unread bytes: # bytes not yet part of IO rec list */
  size_t          balloc;      /* # blocks allocated */
  size_t          btail;       /* idx of last block in use */
  size_t          gc_point;
  char            descr[100];  /* description */ 
  Sfoff_t         tail_off;    /* tail offset (obtained on open + each sfread) */
} P_ctrec_noseek_data_t;

Perror_t
P_ctrec_noseek_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t* sfio, Pio_elt_t* head)
{
  P_ctrec_noseek_data_t  *data;
  Pio_elt_t             *elt; 

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_ctrec_noseek_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_ctrec_noseek_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_ctrec_noseek_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_ctrec_noseek_sfopen: not in a valid closed state");
    return P_ERR;
  }
  IODISC_NEED_AN_ELT("P_ctrec_noseek_sfopen", elt, data->f_head, data->disc_vm);
  if (!elt) {
    return P_ERR;
  }

  data->io           = sfio;
  data->eof          = 0;
  data->eof_elt      = elt;
  data->head         = head;
  data->num          = 1;
  data->btail        = 0;
  data->dbuf_end     = data->dbuf;
  data->un_bytes     = 0;
  data->tail_off     = sftell(sfio);

  return P_OK;
}

Perror_t
P_ctrec_noseek_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_ctrec_noseek_data_t  *data;
  Pio_elt_t              *elt;
  int                     c, ctr;
  Pbyte                  *b, *bmin;
  Pdisc_t                *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_ctrec_noseek_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_ctrec_noseek_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_ctrec_noseek_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_ctrec_noseek_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_ctrec_noseek_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    /* return remaining bytes to Sfio stream using sfungetc */
    ctr = 0;
    b = data->dbuf_end - 1;
    bmin = io_cur_elt->end - remain;
    for (; b >= bmin; b--, ctr++) {
      c = *b;
      if (c != sfungetc(data->io, c)) {
	P_WARN1(disc, "P_ctrec_noseek_sfclose: sfungetc failed, some bytes not restored -- restored %d bytes", ctr);
	goto after_restore;
      }
    }
    if (ctr) {
      P_DBG1(disc, "P_ctrec_noseek_sfclose: restored %d bytes using sfungetc", ctr);
    }
  }
 after_restore:

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  if (data->eof_elt) {
    elt = data->eof_elt;
    data->eof_elt = 0;
    P_APPEND_ELT(data->f_head, elt);
  }

  data->io      = 0;
  data->head    = 0; 

  return P_OK;
}

Perror_t
P_ctrec_noseek_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t** next_elt_out)
{
  P_ctrec_noseek_data_t  *data;
  Pio_elt_t              *elt, *keepelt;
  ssize_t                 readlen, keep_len, discard_len, bytes_read;
  Pbyte                  *tmp;
  Pbyte                  *found_cterm;
  Sfoff_t                 diff, next_elt_off;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_ctrec_noseek_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_ctrec_noseek_data_t*)io_disc->data;

  if (!data->io) {
    P_WARN(pads->disc, "P_ctrec_noseek_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_ctrec_noseek_read: called after returning EOF flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_ctrec_noseek_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  /* move some elts to the free list */
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);
  /*
   * garbage collect if <= P_CTREC_NOSEEK_GC_BLOCKS_LEFT and there is
   * a good chunk of data to be discarded
   */
  if (io_cur_elt) {
    keep_len = data->dbuf_end - io_cur_elt->begin;
    if (keep_len % data->block_size) { /* round up to nearest block size */
      keep_len += (data->block_size - (keep_len % data->block_size));
    }
  } else if (data->un_bytes) {
    keep_len = data->block_size;
  } else {
    keep_len = 0;
  }
  discard_len = (data->dbuf_end - data->dbuf) - keep_len;
  if (keep_len) {
    if (data->balloc - data->btail < P_CTREC_NOSEEK_GC_BLOCKS_LEFT && discard_len >= data->gc_point) {
      /* garbage collect */
      diff = - discard_len; /* data moving down - negative offset */
      memmove((void*)data->dbuf, (const void*)(data->dbuf_end - keep_len), keep_len);
      data->btail = keep_len/data->block_size; /* # blocks copied -> index of next block index */
      data->dbuf_end = data->dbuf + keep_len;
      /* redo begin/end ptrs */
      IODISC_RELOC_ELTS("P_ctrec_noseek_read", data->head, diff, elt);
      *(data->dbuf_end) = 0; /* null-terminate dbuf */
    } /* keep everything -- postpone the memmove */
  } else {
    /* starting from scratch, no io_cur_elt or unread bytes */
    data->btail = 0;
    data->dbuf_end = data->dbuf;
    *(data->dbuf_end) = 0; /* null-terminate dbuf */
  }

  bytes_read      = 0;
  found_cterm     = 0;
  next_elt_off   = data->tail_off - data->un_bytes;
  while (1) { /* read blocks until find cterm or EOF */
    /* choose or alloc block to use */
    if (data->btail >= data->balloc) {
      /* need space -- grow dbuf */
      Pbyte *dbuf_next;
      size_t balloc_next = data->balloc + P_CTREC_NOSEEK_ADD_BLOCKS;
      keep_len = data->dbuf_end - data->dbuf;
      if (!(dbuf_next = vmcpyoldof(data->disc_vm, data->dbuf, Pbyte, balloc_next * data->block_size, 1))) {
	P_WARN(pads->disc, "P_ctrec_noseek_read: could not alloc space for input record");
	readlen = 0;
	break; /* continue after while to take care of earlier bytes_read, if any */
      }
      IODISC_REALLOC(data->balloc * data->block_size, balloc_next * data->block_size);
      diff           = dbuf_next - data->dbuf;
      data->balloc   = balloc_next;
      data->dbuf     = dbuf_next;
      data->dbuf_end = dbuf_next + keep_len;
      data->gc_point += (P_CTREC_NOSEEK_ADD_BLOCKS * data->block_size);
      if (diff) { /* data moved, redo begin/end pointers */
	IODISC_RELOC_ELTS("P_ctrec_noseek_read", data->head, diff, elt);
      }
    } else {
      /* dbuf already had space at block index btail */
    }
    readlen = sfread(data->io, data->dbuf_end, data->block_size);
    data->tail_off = sftell(data->io);
    if (readlen < 0) {
      P_SYSERR(pads->disc, "P_ctrec_noseek_read: Error reading IO stream");
      readlen = 0;
      break;
    }
    if (readlen == 0) {
      break;
    }
    (data->btail)++;
    bytes_read += readlen;
    tmp = data->dbuf_end;
    data->dbuf_end += readlen;
    *(data->dbuf_end) = 0; /* null-terminate dbuf -- note use of extra byte in vmoldof calls */
    if ((found_cterm = PDCI_findfirst(tmp, data->dbuf_end, data->cterm))) {
      break;
    }
    /* read another block */
  }
  /* bytes_read reflects all reads, readlen reflects last read */
  data->un_bytes += bytes_read;
  tmp = data->dbuf_end - data->un_bytes;
  /* first add any EOR-based records */
  while (found_cterm) {
    IODISC_NEED_AN_ELT("P_ctrec_noseek_read", elt, data->f_head, data->disc_vm);
    if (!elt) { /* turn this error into an EOF case */
      P_WARN(pads->disc, "P_ctrec_noseek_read: internal memory alloc error, entering EOF state");
      readlen = 0;
      break;
    }
    elt->begin     = tmp;
    elt->end       = found_cterm;
    elt->len       = found_cterm - tmp;
    elt->bor       = 1;
    elt->eor       = 1;
    elt->eof       = 0;
    elt->num       = (data->num)++;
    elt->unit      = "record";
    elt->offset = next_elt_off;
    next_elt_off += (elt->len + 1); /* account for cterm */
    data->un_bytes -= (elt->len + 1); /* acount for cterm */
    elt->begin[elt->len] = 0; /* null-terminate the record, replaces cterm with NULL */
    P_APPEND_ELT(data->head, elt);
#if 0
    if (pads->disc->error_fn) {
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
    }
#endif
    if (!(*next_elt_out)) {
      (*next_elt_out) = elt;
    }
    tmp = data->dbuf_end - data->un_bytes;
    found_cterm = PDCI_findfirst(tmp, data->dbuf_end, data->cterm);
  }
  if (readlen < data->block_size) { /* put rest of bytes in EOF IO rec */
    elt = data->eof_elt;
    data->eof_elt  = 0;
    elt->bor       = 1;
    elt->eor       = 0;
    elt->eof       = 1;
    data->eof      = 1;
    elt->begin     = tmp;
    elt->end       = data->dbuf_end;
    elt->len       = data->un_bytes;
    elt->offset = next_elt_off;
    data->un_bytes = 0;
    elt->num  = (data->num)++;
    if (elt->len == 0) { /* trivial EOF record */
      elt->unit = "(EOF)";
    } else { /* partial-read EOF record */
      //      char* missing = (data->cterm == '\n') ? "newline" : "terminating char";
      elt->unit = "record";
      //      PDCI_iodisc_report_partial(pads, elt, 1, elt->len, elt->begin,
      //			 "P_ctrec_noseek_read", "Final record not terminated properly, missing %s",
      //			 missing);
    }
    elt->begin[elt->len] = 0; /* null-terminate the record */
    P_APPEND_ELT(data->head, elt);
#if 0
    if (pads->disc->error_fn) {
      pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
    }
#endif
    if (!(*next_elt_out)) {
      (*next_elt_out) = elt;
    }
  } /* else found cterm in a full block read */
  return P_OK;
}

ssize_t
P_ctrec_noseek_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  P_ctrec_noseek_data_t  *data;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !(data = (P_ctrec_noseek_data_t*)io_disc->data) || !data->io || !rec_start) {
    P_WARN(pads->disc, "P_ctrec_noseek_rec_buf_close: bad param(s)");
    return -1;
  }
  data = (P_ctrec_noseek_data_t*)io_disc->data;
  *buf = data->cterm;
  return 1;
}

ssize_t
P_ctrec_noseek_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  P_ctrec_noseek_data_t  *data;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !(data = (P_ctrec_noseek_data_t*)io_disc->data) || !io ) {
    P_WARN(pads->disc, "P_ctrec_noseek_rec_io_close: bad param(s)");
    return -1;
  }
  return (-1 != sfprintf(io, "%c", data->cterm) ? 1 : 0);
}

ssize_t
P_ctrec_noseek_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_ctrec_noseek_blk_close: not a record-block-based discipline!");
  return -1;
}

Perror_t
P_ctrec_noseek_unmake(Pio_disc_t* io_disc)
{
  P_ctrec_noseek_data_t  *data;

  data = (P_ctrec_noseek_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_ctrec_noseek_unmake: sfclose should have been called first, calling it now");
      P_ctrec_noseek_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_ctrec_noseek_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  return "record";
}

Pio_disc_t *
P_ctrec_noseek_make(Pbyte termChar, size_t block_size_hint)
{
  Vmalloc_t              *disc_vm = 0;
  P_ctrec_noseek_data_t  *data;
  Pio_disc_t             *io_disc;
  Pio_elt_t              *f_head;
  Pbyte                  *dbuf;
  size_t                  block_size;

  block_size = (block_size_hint) ? block_size_hint : P_CTREC_NOSEEK_DEF_BSIZE;

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_ctrec_noseek_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_ctrec_noseek_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));
  if (!(dbuf = vmoldof(disc_vm, 0, Pbyte, P_CTREC_NOSEEK_INIT_BLOCKS * block_size, 1))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(P_CTREC_NOSEEK_INIT_BLOCKS * block_size);

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->cterm         = termChar;
  data->block_size    = block_size;
  data->f_head        = f_head;
  data->dbuf          = dbuf;
  data->gc_point      = P_CTREC_NOSEEK_GC_AT_BLOCK * block_size;
  data->balloc        = P_CTREC_NOSEEK_INIT_BLOCKS;
  sprintf(data->descr, "an IO discipline for variable-width records terminated by char %d (ASCII char %s)",
	  termChar, P_qfmt_char(termChar));

  io_disc->unmake_fn    = P_ctrec_noseek_unmake;
  io_disc->sfopen_fn    = P_ctrec_noseek_sfopen;
  io_disc->sfclose_fn   = P_ctrec_noseek_sfclose;
  io_disc->read_fn      = P_ctrec_noseek_read;
  io_disc->rec_close_buf_fn = P_ctrec_noseek_rec_buf_close;
  io_disc->rec_close_io_fn = P_ctrec_noseek_rec_io_close;
  io_disc->blk_close_fn = P_ctrec_noseek_blk_close;
  io_disc->read_unit_fn = P_ctrec_noseek_read_unit;

  io_disc->name         = "ctrec_noseek";
  io_disc->descr        = data->descr;
  io_disc->rec_based    = 1;
  io_disc->has_rblks    = 0;
  io_disc->rec_obytes   = 0;
  io_disc->rec_cbytes   = 1;
  io_disc->blk_obytes   = 0;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_ctrec_noseek_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

/* ================================================================================ */
/* P_vlrec_noseek IMPLEMENTATION */

/* default expected avg rlen, must be > 4 */
#define P_VLREC_NOSEEK_DEF_AVG_RLEN 512
/* multiply expected avg rlen by the following to get intial allocation */
#define P_VLREC_NOSEEK_INIT_RECS 8
/* multiply expected avg rlen by the following to get growth increment */
#define P_VLREC_NOSEEK_GROW_RECS 8
/* once we can free at least this pcnt of bytes, do so (specify pcnt using 1--100) */
#define P_VLREC_NOSEEK_GC_PCNT 25

/* private types */
typedef struct P_vlrec_noseek_data_s {
  /* configuration fields */
  int             blocked;     /* are records grouped into blocks? */
  size_t          rlen_hint;   /* if set, a running avg is not computed */
  /* other fields */
  Vmalloc_t      *disc_vm;     /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;        /* head of IO rec list */
  Pio_elt_t      *f_head;      /* head of free list   */
  Pio_elt_t      *eof_elt;     /* always keep around an elt to be used as EOF elt */
  Sfio_t         *io;          /* Sfio stream to read from */
  int             eof;         /* hit EOF? */
  size_t          num;         /* unit number */
  Pbyte          *dbuf;        /* resizable data buffer */
  Pbyte          *dbuf_end;    /* 1 beyond last byte read */ 
  size_t          dbuf_alloc;  /* current size of dbuf */
  size_t          gc_point;    /* always == (dbuf_alloc * P_VLREC_NOSEEK_GC_PCNT)/100 */
  Puint32_acc     acc;         /* used to accumulate record lengths */
  Pbase_pd        pd;          /* used with acc */
  size_t          avg_rlen;    /* latest computed record length avg */
  size_t          blk_expect;  /* total bytes in current block (expected) -- only used if blocked is set */
  size_t          blk_seen;    /* bytes read in current block -- only used if blocked is set */
  char            descr[100];  /* description */ 
  Sfoff_t         tail_off;   /* tail offset (obtained on open + each sfread) */
} P_vlrec_noseek_data_t;

Perror_t
P_vlrec_noseek_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t* sfio, Pio_elt_t* head)
{
  P_vlrec_noseek_data_t  *data;
  Pio_elt_t             *elt; 

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_vlrec_noseek_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_vlrec_noseek_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_vlrec_noseek_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_vlrec_noseek_sfopen: not in a valid closed state");
    return P_ERR;
  }
  IODISC_NEED_AN_ELT("P_vlrec_noseek_sfopen", elt, data->f_head, data->disc_vm);
  if (!elt) {
    return P_ERR;
  }

  data->io           = sfio;
  data->eof          = 0;
  data->eof_elt      = elt;
  data->head         = head;
  data->num          = 1;
  data->dbuf_end     = data->dbuf;
  data->blk_expect   = (data->blocked) ? 0 : 1;
  data->tail_off     = sftell(sfio);

  /* the combination blocked == 0, blk_expect != 0 is sufficient to suppress all block processing */
  /* if blocked is set, we set blk_expect to zero to force the block length to be read */

  if (data->rlen_hint) {
    data->avg_rlen = data->rlen_hint;
  } else {
    data->avg_rlen = P_VLREC_NOSEEK_DEF_AVG_RLEN;
    Puint32_acc_init(pads, &(data->acc));
  }
  return P_OK;
}

Perror_t
P_vlrec_noseek_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_vlrec_noseek_data_t  *data;
  Pio_elt_t              *elt;
  int                     c, ctr;
  Pbyte                  *b, *bmin;
  Pdisc_t                *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_vlrec_noseek_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_vlrec_noseek_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_vlrec_noseek_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_vlrec_noseek_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_vlrec_noseek_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    /* return remaining bytes to Sfio stream using sfungetc */
    ctr = 0;
    b = data->dbuf_end - 1;
    bmin = io_cur_elt->end - remain;
    for (; b >= bmin; b--, ctr++) {
      c = *b;
      if (c != sfungetc(data->io, c)) {
	P_WARN1(disc, "P_vlrec_noseek_sfclose: sfungetc failed, some bytes not restored -- restored %d bytes", ctr);
	goto after_restore;
      }
    }
    if (ctr) {
      P_DBG1(disc, "P_vlrec_noseek_sfclose: restored %d bytes using sfungetc", ctr);
    }
  }
 after_restore:

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  if (data->eof_elt) {
    elt = data->eof_elt;
    data->eof_elt = 0;
    P_APPEND_ELT(data->f_head, elt);
  }

  data->io      = 0;
  data->head    = 0; 
#if 0
  Puint32_acc_report (pads, "XXX_REMOVE_vlrec_noseek.record_len", "Puint32", 0, &(data->acc));
#endif
  Puint32_acc_cleanup(pads, &(data->acc));

  return P_OK;
}

Perror_t
P_vlrec_noseek_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t** next_elt_out)
{
  P_vlrec_noseek_data_t   *data;
  Pio_elt_t               *elt, *keepelt;
  ssize_t                  readlen, keep_len, discard_len;
  size_t                   record_len = 0, xtra;
  Sfoff_t                  diff, elt_off;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_vlrec_noseek_data_t*)io_disc->data;

  if (!data->io) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: called after returning EOF flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  /* move some elts to the free list */
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);
  /*
   * garbage collect if there is a good chunk of data to be discarded
   */
  if (io_cur_elt) {
    keep_len = data->dbuf_end - io_cur_elt->begin;
  } else {
    keep_len = 0;
  }
  if (keep_len == 0) {
    /* starting from scratch, no io_cur_elt or unread bytes */
    data->dbuf_end = data->dbuf;
    *(data->dbuf_end) = 0; /* null-terminate dbuf */
  } else {
    discard_len = (data->dbuf_end - data->dbuf) - keep_len;
    if (discard_len > data->gc_point) {
      /* garbage collect */
      diff = - discard_len; /* data moving down - negative offset */
      memmove((void*)data->dbuf, (const void*)(data->dbuf_end - keep_len), keep_len);
      data->dbuf_end = data->dbuf + keep_len;
      /* redo begin/end ptrs */
      IODISC_RELOC_ELTS("P_vlrec_noseek_read", data->head, diff, elt);
      *(data->dbuf_end) = 0; /* null-terminate dbuf */
    }
  }

  /* set extra to 4 if it is time to read a new block length, else 0 */
  xtra = (data->blk_expect == 0) ? 4 : 0;

  /* grow dbuf if there are fewer than avg_rlen bytes left (note always > 4) */
  readlen = 0;
  diff = data->dbuf_end - data->dbuf;
  elt_off = data->tail_off; /* in case we go to eof_case on alloc error */
  if (data->dbuf_alloc - diff < data->avg_rlen + xtra) {
    /* grow with room for more than one record */
    Pbyte *dbuf_next; 
    size_t    dbuf_alloc_next = data->dbuf_alloc + (data->avg_rlen * P_VLREC_NOSEEK_GROW_RECS) + xtra + 1;
    if (!(dbuf_next = vmcpyoldof(data->disc_vm, data->dbuf, Pbyte, dbuf_alloc_next, 1))) {
      P_WARN(pads->disc, "P_vlrec_noseek_read: could not alloc space for input record");
      readlen = 0;
      goto eof_case;
    }
    IODISC_REALLOC(data->dbuf_alloc, dbuf_alloc_next);
#if 0
    P_WARN2(pads->disc, "XXX_REMOVE grew dbuf from %lu to %lu",
	      (unsigned long)data->dbuf_alloc, (unsigned long)dbuf_alloc_next);
#endif
    data->dbuf_alloc = dbuf_alloc_next;
    data->gc_point   = (data->dbuf_alloc * P_VLREC_NOSEEK_GC_PCNT) / 100;
    diff = dbuf_next - data->dbuf;
    if (diff) {
      keep_len         = data->dbuf_end - data->dbuf;
      data->dbuf       = dbuf_next;
      data->dbuf_end   = dbuf_next + keep_len;
      IODISC_RELOC_ELTS("P_vlrec_noseek_read", data->head, diff, elt);
    }
  }

  /* read 4 (or 8) bytes to determine record_len, goto eof_case if not enough bytes */
  readlen = sfread(data->io, data->dbuf_end, 4+xtra);
  elt_off = data->tail_off = sftell(data->io);
  if (readlen != 4+xtra) {
    if (readlen < 0) {
      P_SYSERR(pads->disc, "P_vlrec_noseek_read: Error reading IO stream, entering EOF state");
      readlen = 0;
    } else if (readlen > 0) {
      P_WARN(pads->disc, "P_vlrec_noseek_read: bytes remaining < record length field, entering EOF state");
    }
    readlen = 0;
    goto eof_case;
  }

  if (xtra) {
    /* initialize blk_expect and blk_seen */
    data->blk_expect = (data->dbuf_end[0] << 8) + data->dbuf_end[1]; /* third and fourth bytes ignored */
    /* XXX should only do this if some paranoid flag is set */
    if (data->dbuf_end[2] || data->dbuf_end[3]) {
      P_WARN(pads->disc, "P_vlrec_noseek_read: block length field has non-null bytes 3/4, ignoring");
    }
    /*    P_WARN1(pads->disc, "XXX_REMOVE starting new block of size %lu", (unsigned long)data->blk_expect); */
    data->dbuf_end += 4;
    data->blk_seen = 4;
    if (data->blk_expect < 8) {
      P_WARN(pads->disc, "P_vlrec_noseek_read: Invalid block length, entering EOF state");
      readlen = 0;
      goto eof_case;
    }
  }

  record_len = (data->dbuf_end[0] << 8) + data->dbuf_end[1]; /* third and fourth bytes ignored */
  /* XXX should only do this if some paranoid flag is set */
  if (data->dbuf_end[2] || data->dbuf_end[3]) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: record length field has non-null bytes 3/4, ignoring");
  }
  /* XXX should only do this if some paranoid flag is set */
  if (record_len > P_MAX_INT16) {
    P_WARN2(pads->disc, "P_vlrec_noseek_read: record_len %ld is greater than %ld as established by IBM",
	      (long)record_len, (long)P_MAX_INT16);
  }
  data->dbuf_end += 4;
  if (data->rlen_hint == 0) {
    Puint32 ui32 = record_len + 5;
    Puint32_acc_add(pads, &(data->acc), &(data->pd), &ui32);
    if (data->num % 10 == 0) {
      data->avg_rlen = Puint32_acc_ravg(pads, &(data->acc));
      /*  P_WARN1(pads->disc, "XXX_REMOVE changed avg_rlen to %ld", (long)data->avg_rlen); */
    }
  }
  if (record_len < 4) {
    P_WARN(pads->disc, "P_vlrec_noseek_read: Invalid record length, entering EOF state");
    readlen = 0;
    goto eof_case;
  }
  record_len -= 4; /* record_len is now == bytes remaining to be read */

  /* grow dbuf if there are fewer than (record_len + 1) bytes left */
  readlen = 0;
  diff = data->dbuf_end - data->dbuf;
  if (data->dbuf_alloc - diff < record_len + 1) {
    /* grow with room for more than one record */
    Pbyte *dbuf_next; 
    size_t    dbuf_alloc_next = data->dbuf_alloc + record_len + (data->avg_rlen * P_VLREC_NOSEEK_GROW_RECS) + 1;
    if (!(dbuf_next = vmcpyoldof(data->disc_vm, data->dbuf, Pbyte, dbuf_alloc_next, 1))) {
      P_WARN(pads->disc, "P_vlrec_noseek_read: could not alloc space for input record");
      readlen = 0;
      goto eof_case;
    }
    IODISC_REALLOC(data->dbuf_alloc, dbuf_alloc_next);
#if 0
    P_WARN2(pads->disc, "XXX_REMOVE grew dbuf from %lu to %lu", data->dbuf_alloc, dbuf_alloc_next);
#endif
    data->dbuf_alloc = dbuf_alloc_next;
    data->gc_point   = (data->dbuf_alloc * P_VLREC_NOSEEK_GC_PCNT) / 100;
    diff = dbuf_next - data->dbuf;
    if (diff) {
      keep_len         = data->dbuf_end - data->dbuf;
      data->dbuf       = dbuf_next;
      data->dbuf_end   = dbuf_next + keep_len;
      IODISC_RELOC_ELTS("P_vlrec_noseek_read", data->head, diff, elt);
    }
  }

  /* read record_len bytes, goto eof_case if not enough bytes */
  readlen = sfread(data->io, data->dbuf_end, record_len);
  data->tail_off = sftell(data->io);
  if (readlen != record_len) {
    if (readlen < 0) {
      P_SYSERR(pads->disc, "P_vlrec_noseek_read: Error reading IO stream");
      readlen = 0;
    }
    goto eof_case;
  }

  if (data->blocked) {
    data->blk_seen += (readlen+4);
    if (data->blk_seen > data->blk_expect) {
#if 0
      P_WARN2(pads->disc, "XXX_REMOVE seen: %lu  expect:  %lu",
		(unsigned long)data->blk_seen, (unsigned long)data->blk_expect);
#endif
      P_WARN(pads->disc, "P_vlrec_noseek_read: length of records in block exceeds block length, entering EOF state");
      readlen = 0;
      goto eof_case;
    }
    if (data->blk_seen == data->blk_expect) {
      /* P_WARN(pads->disc, "XXX_REMOVE finished reading a block"); */
      data->blk_expect = 0; /* force next block length to be read */
    }
  }

  /* make an elt using the bytes just read */
  IODISC_NEED_AN_ELT("P_vlrec_noseek_read", elt, data->f_head, data->disc_vm);
  if (!elt) { /* turn this error into an EOF case */
    P_WARN(pads->disc, "P_vlrec_noseek_read: internal memory alloc error, entering EOF state");
    readlen = 0;
    goto eof_case;
  }
  elt->offset  = elt_off;
  elt->begin        = data->dbuf_end;
  data->dbuf_end += readlen;
  elt->end          = data->dbuf_end;
  elt->len          = readlen;
  elt->bor          = 1;
  elt->eor          = 1;
  elt->eof          = 0;
  elt->unit         = "record";
  goto done;

 eof_case:
  elt = data->eof_elt;
  data->eof_elt     = 0;
  data->dbuf_end += readlen;
  elt->offset  = elt_off;
  elt->begin        = data->dbuf_end;
  elt->end          = data->dbuf_end;
  elt->len          = 0; /* ignore readlen except for putback (captured in dbuf_end) */
  elt->bor          = 1;
  elt->eor          = 0;
  elt->eof          = 1;
  data->eof         = 1;
  elt->unit         = "(EOF)";
  if (readlen) { /* report partial read */
    PDCI_iodisc_report_partial(pads, elt, 0, 0, elt->begin,
			       "P_vlrec_noseek_read", "Insufficient bytes in final record read, got %lu, expecting %lu",
			       (unsigned long)readlen, (unsigned long)record_len);
  }

 done:
  elt->num             = (data->num)++;
  elt->begin[elt->len] = 0; /* null-terminate the record */
  P_APPEND_ELT(data->head, elt);
#if 0
  if (pads->disc->error_fn) {
    pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d)\n[%s]", elt->unit, elt->num, P_fmt_cstr_n(elt->begin, elt->len));
  }
#endif
  (*next_elt_out) = elt;
  return P_OK;
}

ssize_t
P_vlrec_noseek_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  Pbyte *ibytes;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !buf || !rec_start) {
    P_WARN(pads->disc, "P_vlrec_noseek_rec_buf_close: bad param(s)");
    return -1;
  }
  /* num_bytes already equal to total bytes in record */
  ibytes = (Pbyte*)(&num_bytes);
  if (pads->m_endian == PlittleEndian) {
    rec_start[0] = ibytes[1];
    rec_start[1] = ibytes[0]; 
    rec_start[2] = 0;
    rec_start[3] = 0;
  } else {
    rec_start[0] = ibytes[2];
    rec_start[1] = ibytes[3];
    rec_start[2] = 0;
    rec_start[3] = 0;
  }
  return 0; /* no bytes added at end */
}

ssize_t
P_vlrec_noseek_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc) {
    P_WARN(pads->disc, "P_vlrec_noseek_rec_io_close: bad param(s)");
    return -1;
  }
  P_WARN(pads->disc, "P_vlrec_noseek_rec_io_close: cannot seek on non-seekable io!");
  return -1;
}

ssize_t
P_vlrec_noseek_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  Pbyte *ibytes;

  if (!pads || !pads->disc) {
    return -1;
  }
  if (!io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_vlrec_noseek_blk_close: bad param(s)");
    return -1;
  }
  /* num_bytes already equal to total bytes in block */
  ibytes = (Pbyte*)(&num_bytes);
  if (pads->m_endian == PlittleEndian) {
    blk_start[0] = ibytes[1];
    blk_start[1] = ibytes[0];
  } else {
    blk_start[0] = ibytes[0];
    blk_start[1] = ibytes[1];
  }
  blk_start[2] = 0;
  blk_start[3] = 0;
  return 0; /* no bytes added at end */
}

Perror_t
P_vlrec_noseek_unmake(Pio_disc_t* io_disc)
{
  P_vlrec_noseek_data_t  *data;

  data = (P_vlrec_noseek_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_vlrec_noseek_unmake: sfclose should have been called first, calling it now");
      P_vlrec_noseek_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_vlrec_noseek_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  return "record";
}

Pio_disc_t *
P_vlrec_noseek_make(int blocked, size_t avg_rlen_hint)
{
  Vmalloc_t                 *disc_vm = 0;
  P_vlrec_noseek_data_t   *data;
  Pio_disc_t             *io_disc;
  Pio_elt_t              *f_head;
  Pbyte                  *dbuf;
  size_t                     dbuf_alloc;
  size_t                     rlen;

  if (avg_rlen_hint > 0 && avg_rlen_hint < 5) {
    P_WARN(&Pdefault_disc, "P_vlrec_noseek_make: avg_rlen_hint is > 0 but less than min of 5; changing to 5");
    avg_rlen_hint = 5;
  }
  rlen = (avg_rlen_hint) ? avg_rlen_hint : P_VLREC_NOSEEK_DEF_AVG_RLEN;

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_vlrec_noseek_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_vlrec_noseek_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));
  dbuf_alloc = P_VLREC_NOSEEK_INIT_RECS * rlen;
  if (!(dbuf = vmoldof(disc_vm, 0, Pbyte, dbuf_alloc, 1))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(dbuf_alloc);

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->blocked       = blocked;
  data->rlen_hint     = avg_rlen_hint;
  data->f_head        = f_head;
  data->dbuf          = dbuf;
  data->dbuf_alloc    = dbuf_alloc;
  data->gc_point      = (data->dbuf_alloc * P_VLREC_NOSEEK_GC_PCNT) / 100;
  sprintf(data->descr, "an IO discipline for IBM-stle variable-length records");

  io_disc->unmake_fn    = P_vlrec_noseek_unmake;
  io_disc->sfopen_fn    = P_vlrec_noseek_sfopen;
  io_disc->sfclose_fn   = P_vlrec_noseek_sfclose;
  io_disc->read_fn      = P_vlrec_noseek_read;
  io_disc->rec_close_buf_fn = P_vlrec_noseek_rec_buf_close;
  io_disc->rec_close_io_fn = P_vlrec_noseek_rec_io_close; 
  io_disc->blk_close_fn = P_vlrec_noseek_blk_close;
  io_disc->read_unit_fn = P_vlrec_noseek_read_unit;

  io_disc->name         = "vlrec_noseek";
  io_disc->descr        = data->descr;
  io_disc->rec_based    = 1;
  io_disc->has_rblks    = 1;
  io_disc->rec_obytes   = 4;
  io_disc->rec_cbytes   = 0;
  io_disc->blk_obytes   = 4;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  /* data->pd starts zeroed due to vmnewof */

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_vlrec_noseek_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

/* ================================================================================ */
/* P_fwrec IMPLEMENTATION */

Pio_disc_t *
P_fwrec_make(size_t leader_len, size_t data_len, size_t trailer_len)
{
  /* XXX_TODO */
  return P_fwrec_noseek_make(leader_len, data_len, trailer_len);
}

/* ================================================================================ */
/* P_ctrec IMPLEMENTATION */

Pio_disc_t *
P_ctrec_make(Pbyte termChar, size_t block_size_hint)
{
  /* XXX_TODO */
  return P_ctrec_noseek_make(termChar, block_size_hint);
}

/* ================================================================================ */
/* P_ctrec_eolcmt IMPLEMENTATION */

Pio_disc_t *
P_ctrec_eolcmt_make(Pbyte termChar, Pbyte cmtChar, size_t block_size_hint)
{
  /* XXX_TODO */
  return P_ctrec_noseek_eolcmt_make(termChar, cmtChar, block_size_hint);
}

/* ================================================================================ */
/* P_vlrec IMPLEMENTATION */

Pio_disc_t *
P_vlrec_make(int blocked, size_t avg_rlen_hint)
{
  /* XXX_TODO */
  return P_vlrec_noseek_make(blocked, avg_rlen_hint);
}

/* ================================================================================ */
/* P_norec IMPLEMENTATION */

/* when not specified, use blocks of this size (bytes): */
#define P_NOREC_DEF_BSIZE    512

/* private types */
typedef struct P_norec_data_s {
  /* configuration fields */
  size_t          block_size;
  /* other fields */
  Vmalloc_t      *disc_vm;    /* lifetime: make/unmake pairing */
  Pio_elt_t      *head;       /* head of IO rec list */
  Pio_elt_t      *f_head;     /* head of free list   */
  Pio_elt_t      *eof_elt;    /* always keep around an elt to be used as EOF elt */
  Sfio_t         *io;         /* Sfio stream to read from */
  int             eof;        /* hit EOF? */
  size_t          num;        /* unit number */
  Pbyte           dummy[1];   /* for immediate EOF error */
  char            unit[100];  /* unit description when reading blocks */
  Pbyte          *r_begin;    /* begin of reserved sfio bytes */
  Pbyte          *r_end;      /* 1 byte past end of reserved sfio bytes */
  Pbyte           saved_byte; /* we NULL *(r_end) after each sfreserve, restore it prior to next sfreserve */
  Sfoff_t         tail_off;   /* tail offset (obtained on open + each sfreserve) */
} P_norec_data_t;

Perror_t
P_norec_sfopen(P_t *pads, Pio_disc_t* io_disc, Sfio_t *sfio, Pio_elt_t *head)
{
  P_norec_data_t *data;
  Pio_elt_t      *elt; 

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!sfio || !head || !io_disc || !io_disc->data) {
    P_WARN(pads->disc, "P_norec_sfopen: bad param(s)");
    return P_ERR;
  }
  if (head->next != head || head->prev != head) {
    P_WARN(pads->disc, "P_norec_sfopen: head->next and head->prev must both point to head");
    return P_ERR;
  }
  data = (P_norec_data_t*)io_disc->data;
  if (data->io) {
    P_WARN(pads->disc, "P_norec_sfopen: not in a valid closed state");
    return P_ERR;
  }
  IODISC_NEED_AN_ELT("P_norec_sfopen", elt, data->f_head, data->disc_vm);
  if (!elt) {
    return P_ERR;
  }

  data->io       = sfio;
  data->eof      = 0;
  data->eof_elt  = elt;
  data->head     = head;
  data->num      = 1;
  data->tail_off = sftell(sfio);
  data->r_begin  = 0;
  data->r_end    = 0;

  return P_OK;
}

Perror_t
P_norec_sfclose(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain)
{
  P_norec_data_t   *data;
  Pio_elt_t        *elt;
  Pdisc_t          *disc;

  if (!pads || !pads->disc) {
    disc = &Pdefault_disc;
  } else {
    disc = pads->disc;
  }

  if (!io_disc || !io_disc->data) {
    P_WARN(disc, "P_norec_sfclose: bad param(s)");
    return P_ERR;
  }
  data = (P_norec_data_t*)io_disc->data;
  if (!data->io) {
    P_WARN(disc, "P_norec_sfclose: not in a valid open state");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(disc, "P_norec_sfclose: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (io_cur_elt && remain > io_cur_elt->len) {
    P_WARN(disc, "P_norec_sfclose: remain > io_cur_elt->len!");
    return P_ERR;
  }
  if (io_cur_elt) {
    Sfoff_t offset;

    if (data->r_end) { /* restore in case we are returning saved_byte to stream */ 
      *(data->r_end) = data->saved_byte;
    }
    offset = io_cur_elt->offset + io_cur_elt->len - remain;
    if (offset < data->tail_off) {
      unsigned long long to_return = data->tail_off - offset;
      if (-1 == sfseek(data->io, offset, 0)) {
	P_WARN1(disc, "P_norec_sfclose: failed to return %llu bytes to IO stream", to_return);
      } else {
	P_DBG1(disc, "P_norec_sfclose: restored %llu bytes to IO stream using sfseek", to_return);
      }
    }
  }

  /* remove all elts from list -- put them on the free list */
  IODISC_REMOVE_ALL_ELTS(data->head, data->f_head, elt);
  if (data->eof_elt) {
    elt = data->eof_elt;
    data->eof_elt = 0;
    P_APPEND_ELT(data->f_head, elt);
  }

  data->io      = 0;
  data->head    = 0; 

  return P_OK;
}

Perror_t
P_norec_read(P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, Pio_elt_t **next_elt_out)
{
  P_norec_data_t    *data;
  Pio_elt_t        *elt, *firstelt, *keepelt;
  ssize_t              readlen, to_keep, to_discard, to_reserve;
  Sfoff_t              new_data_off, diff;
  Pbyte            *new_r_begin, *new_data;

  if (!pads || !pads->disc) {
    return P_ERR;
  }
  if (!io_disc || !io_disc->data || !next_elt_out) {
    P_WARN(pads->disc, "P_norec_read: bad param(s)");
    return P_ERR;
  }
  (*next_elt_out) = 0;
  data = (P_norec_data_t*)io_disc->data;

  if (!data->io) {
    P_WARN(pads->disc, "P_norec_read: not in a valid open state");
    return P_ERR;
  }
  if (data->eof) {
    P_WARN(pads->disc, "P_norec_read: called after returning EOF flag in previous call");
    return P_ERR;
  }
  if (io_cur_elt == data->head) {
    P_WARN(pads->disc, "P_norec_read: io_cur_elt == head not a valid elt!");
    return P_ERR;
  }
  if (data->r_end) {
    *(data->r_end) = data->saved_byte;
  }
  /* move some elts to the free list */
  keepelt = io_cur_elt ? io_cur_elt : data->head;
  IODISC_REMOVE_SOME_ELTS(data->head, data->f_head, keepelt, elt);

  firstelt = P_FIRST_ELT(data->head);
  if (firstelt == data->head) {
    to_keep = 0;
  } else {
    /* seek to offset of first elt */
    if (-1 == sfseek(data->io, firstelt->offset, 0)) {
      P_FATAL(pads->disc, "P_norec_read: unexpected sfseek failure");
    }
    to_keep = data->tail_off - firstelt->offset;
  }
  new_data_off = data->tail_off;
  to_discard = (data->r_end - data->r_begin) - to_keep;
  to_reserve = to_keep + data->block_size;
  new_r_begin = sfreserve(data->io, to_reserve, 0);
  readlen = sfvalue(data->io);
  if (readlen > to_reserve) { /* hint from sfio that we could have reserved more -- ignore */
    readlen = to_reserve;
  }
  if (!new_r_begin && readlen) {
    if (!(new_r_begin = sfreserve(data->io, 0, SF_LASTR))) {
      /*
       * For some reason if data->io was created from a string, we need to use
       * the following to get the final bytes (SF_LASTR is not working).
       */
      if (!(new_r_begin = sfreserve(data->io, readlen, 0))) {
	readlen = 0; 
      }
    }
  }
  data->tail_off = sftell(data->io);
  data->r_end = 0;
  if (readlen) {
    data->r_end = new_r_begin + readlen;
    if (readlen < to_keep) {
      P_FATAL(pads->disc, "P_norec_read: unexpected failure, reserve got even fewer bytes than last time");
    }
    readlen -= to_keep; /* readlen now == the bytes that go in the new elt(s) */
    if (data->r_begin) {
      data->r_begin += to_discard; /* need this adjustment before we compute diff */
      diff = new_r_begin - data->r_begin;
      if (diff) { /* data moved, redo begin/end pointers */
	IODISC_RELOC_ELTS("P_norec_read", data->head, diff, elt);
      }
    }
    data->r_begin = new_r_begin;
  }
  if (data->r_end) {
    data->saved_byte = *(data->r_end);
    *(data->r_end) = 0; /* null-terminate the data bytes -- note sfio's sfbuf must be allocated with extra byte */
  }
  if (readlen == data->block_size) { /* full block read */
    IODISC_NEED_AN_ELT("P_norec_read", elt, data->f_head, data->disc_vm);
    if (!elt) {
      P_WARN(pads->disc, "P_norec_read memory alloc error, entering EOF state");
      goto eof_case;
    }
    new_data  = data->r_begin + to_keep; /* new bytes start here */
    elt->eof  = 0;
    elt->unit = (const char*)data->unit;
    goto done;
  }

 eof_case:
  if (data->r_begin) {
    new_data = data->r_begin + to_keep; /* new bytes start here */
  } else {
    new_data = data->dummy; /* no bytes ever read before EOF, need a dummy location */ 
  }
  elt = data->eof_elt;
  data->eof_elt = 0;
  elt->eof  = 1;
  data->eof = 1;
  if (readlen) {
    elt->unit = (const char*)data->unit;
  } else {
    elt->unit = "(EOF)";
  }

 done:
  elt->bor = 0; /* norec never uses bor */
  elt->eor = 0; /* norec never uses eor */
  elt->num = (data->num)++;
  elt->begin = new_data;
  elt->end   = new_data + readlen;
  elt->len   = readlen;
  elt->offset = new_data_off;
  P_APPEND_ELT(data->head, elt);
#if 0
  if (pads->disc->error_fn) {
    pads->disc->error_fn(NiL, 0, "XXX_REMOVE(%s %d offset %d)\n[%s]", elt->unit, elt->num, elt->offset, P_fmt_cstr_n(elt->begin, elt->len));
  }
#endif
  (*next_elt_out) = elt;
  return P_OK;
}

ssize_t
P_norec_rec_buf_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *rec_start, size_t num_bytes)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_rec_buf_close: not a record-based discipline!");
  return -1;
}

ssize_t
P_norec_rec_io_close(P_t *pads, Pio_disc_t* io_disc, Sfio_t *io)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_rec_io_close: not a record-based discipline!");
  return -1;
}

ssize_t
P_norec_blk_close(P_t *pads, Pio_disc_t* io_disc, Pbyte *buf, Pbyte *blk_start, size_t num_bytes, Puint32 num_recs)
{
  if (!pads || !pads->disc) {
    return -1;
  }
  P_WARN(pads->disc, "P_norec_blk_close: not a record-block-based discipline!");
  return -1;
}

Perror_t
P_norec_unmake(Pio_disc_t* io_disc)
{
  P_norec_data_t  *data;

  data = (P_norec_data_t*)io_disc->data;
  if (data) {
    if (data->io) {
      P_WARN(&Pdefault_disc, "P_norec_unmake: sfclose should have been called first, calling it now");
      P_norec_sfclose(0, io_disc, 0, 0);
    }
    if (data->disc_vm) {
      vmclose(data->disc_vm);
      IODISC_VMCLOSE_CALLED;
    }
  }
  return P_ERR;
}

const char *
P_norec_read_unit(P_t *pads, Pio_disc_t* io_disc)
{
  P_norec_data_t     *data;

  if (!io_disc || !io_disc->data) return 0;
  data = (P_norec_data_t*)io_disc->data;
  return data->unit;
}

Pio_disc_t *
P_norec_make(size_t block_size_hint)
{
  Vmalloc_t          *disc_vm = 0;
  P_norec_data_t   *data;
  Pio_disc_t      *io_disc;
  Pio_elt_t       *f_head;
  size_t              block_size;

  block_size = (block_size_hint) ? block_size_hint : P_NOREC_DEF_BSIZE;

  if (!(disc_vm = vmopen(Vmdcheap, Vmbest, 0))) {
    goto alloc_err;
  }
  if (!(io_disc = vmnewof(disc_vm, 0, Pio_disc_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_disc_t));
  if (!(data = vmnewof(disc_vm, 0, P_norec_data_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(P_norec_data_t));
  if (!(f_head = vmnewof(disc_vm, 0, Pio_elt_t, 1, 0))) {
    goto alloc_err;
  }
  IODISC_NEW_ALLOC(sizeof(Pio_elt_t));

  f_head->prev = f_head;
  f_head->next = f_head;

  data->disc_vm       = disc_vm;
  data->block_size    = block_size;
  data->f_head        = f_head;

  if ((block_size % 1024) == 0) {
    sprintf(data->unit,  "%dKB Block", block_size / 1024);
  } else {
    sprintf(data->unit,  "%dB Block", block_size);
  }

  io_disc->unmake_fn    = P_norec_unmake;
  io_disc->sfopen_fn    = P_norec_sfopen;
  io_disc->sfclose_fn   = P_norec_sfclose;
  io_disc->read_fn      = P_norec_read;
  io_disc->rec_close_buf_fn = P_norec_rec_buf_close;
  io_disc->rec_close_io_fn = P_norec_rec_io_close;
  io_disc->blk_close_fn = P_norec_blk_close;
  io_disc->read_unit_fn = P_norec_read_unit;

  io_disc->name         = "norec";
  io_disc->descr        = "a raw bytes IO discipline that does not use EOR";
  io_disc->rec_based    = 0;
  io_disc->has_rblks    = 0;
  io_disc->rec_obytes   = 0;
  io_disc->rec_cbytes   = 0;
  io_disc->blk_obytes   = 0;
  io_disc->blk_cbytes   = 0;
  io_disc->data         = data;

  return io_disc;

 alloc_err:
  P_WARN(&Pdefault_disc, "P_norec_make: out of space");
  if (disc_vm) {
    vmclose(disc_vm);
    IODISC_VMCLOSE_CALLED;
  }
  return 0;
}

