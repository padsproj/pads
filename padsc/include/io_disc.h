/*
 * PADS io discipline header file
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PADS_H__
#error "Do not include io_disc.h directly -- include pads.h instead"
#endif

#ifndef __P_IO_DISC_H__
#define __P_IO_DISC_H__

// Uncomment the following to debug IO discipline memory allocations
// #define IODISC_ALLOC_DEBUG 1

/* ================================================================================ */
/* THE IO DISCIPLINE
 *
 * Type Pio_disc_t is used to control the 'raw' reading of data
 * from a file or from some other data source.  
 *
 * Implementations of the standard IO disciplines can be found in
 * libpads/default_io_disc.c.  Anyone planning to implement a new IO
 * discipline should consult default_io_disc.c.
 *
 * From a user standpoint, what is needed is knowledge about how to
 * install different disciplines.  The standard disciplines are
 * installed by making an instance of an IO discipline using one
 * of the following make functions, and then either passing 
 * the resulting handle either to P_open or to P_set_io_disc.
 *
 * Note that there are two versions of each kind of IO discipline:
 *    fwrec and fwrec_noseek
 *    ctrec and ctrec_noseek
 *    ctrec_eolcmt and ctrec_noseek_eolcmt
 *    vlrec and vlrec_noseek
 *    norec and norec_noseek
 * The noseek versions do not require that the sfio stream
 * be seekable, while the other versions do.  The eolcmt versions
 * strip "to end of line" comments (e.g. "# this is a comment")
 * from IO elements.
 *
 * In addition, the user should 'unmake' an IO discipline once it
 * is no longer needed.  This can be achieved by using 
 * PDC_close, or by installing a new IO discipline using P_set_io_disc.
 * However, if an IO discipline is 'kept' around using, e.g., 
 * P_close_keep_io_disc, or P_set_io_disc_keep_old, then 
 * it can be re-used in a future P_open or P_set_io_disc call,
 * and the user may have to unmake it explicitly when it is no longer
 * needed, using:
 *
 *    P_io_disc_unmake(my_io_disc)
 *
 */

Perror_t P_io_disc_unmake(Pio_disc_t *io_disc);
/*
 * Unmake io_disc.  See discussion above about when this is necessary.
 */

Pio_disc_t * P_fwrec_make(size_t leader_len, size_t data_len, size_t trailer_len);
/* Instantiates an instance of fwrec, a discipline for fixed-width
 * records.  data_len specifies the number of data bytes per record,
 * while leader_len and trailer_len specifies the number of bytes that
 * occur before and after the data bytes within each record (either or
 * both can be zero).  Thus the total record size in bytes is the sum
 * of the 3 arguments.  
 */

Pio_disc_t * P_fwrec_noseek_make(size_t leader_len, size_t data_len, size_t trailer_len);
/* Instantiates an instance of fwrec_noseek, a version of norec
 * that does not require that the sfio stream is seekable.
 */

Pio_disc_t * P_ctrec_eolcmt_make(Pbyte termChar, Pbyte cmtChar, size_t block_size_hint);
/* Like P_ctrec_make below but adds a single byte "to-end-of-line" 
 * comment character and comments are stripped from IO elements.
 */

Pio_disc_t * P_ctrec_make(Pbyte termChar, size_t block_size_hint);
/* Instantiates an instance of ctrec, a discipline for
 * character-terminated variable-width records. termChar is the
 * character that marks the end of a record. block_size_hint is a
 * hint as to what block size to use, if the discipline chooses to do
 * fixed block-sized reads 'under the covers'.  It may be ignored by
 * the discipline.
 * 
 * For ASCII newline-terminated records use, '\n' or P_ASCII_NEWLINE
 * as the term character.  For EBCDIC newline-terminated records, use
 * P_EBCDIC_NEWLINE as the term character.
 */

Pio_disc_t * P_ctrec_noseek_eolcmt_make(Pbyte termChar, Pbyte cmtChar, size_t block_size_hint);
/* Like P_ctrec_noseek_make below but adds a single byte "to-end-of-line" 
 * comment character and comments are stripped from IO elements.
 */
   
Pio_disc_t * P_ctrec_noseek_make(Pbyte termChar, size_t block_size_hint);
/* Instantiates an instance of ctrec_noseek, a version of norec
 * that does not require that the sfio stream is seekable.
 */

Pio_disc_t * P_vlrec_make(int blocked, size_t avg_rlen_hint);
/* Instantiates an instance of vlrec, a discipline for IBM-style
 * variable-length records with record length specified at the start
 * of each record.  If blocked is set (!= 0) then the records are
 * grouped into blocks, where each block has a length given at the
 * start of each block.  avg_rlen_hint is a hint as to what the
 * average record length is, to help the discipline allocate memory.
 * It should include the 4 bytes at the start of each record used for
 * the record length.  It may be ignored by the discipline.
 */

Pio_disc_t * P_vlrec_noseek_make(int blocked, size_t avg_rlen_hint);
/* Instantiates an instance of vlrec_noseek, a version of vlrec
 * that does not require that the sfio stream is seekable.
 */

Pio_disc_t * P_norec_make(size_t block_size_hint);
/* Instantiates an instance of norec, a raw bytes discipline that
 * does not use records.  block_size_hint is a hint as to what block size
 * to use, if the discipline chooses to do fixed block-sized reads
 * 'under the covers'.  It may be ignored by the discipline.
 */

Pio_disc_t * P_norec_noseek_make(size_t block_size_hint);
/* Instantiates an instance of norec_noseek, a version of norec
 * that does not require that the sfio stream is seekable.
 */

/* Shorthands for calling corresponding ctrec make functions with '\n' as termChar: */
#define P_nlrec_make(block_size_hint)         		P_ctrec_make('\n', block_size_hint)
#define P_nlrec_noseek_make(block_size_hint)  		P_ctrec_noseek_make('\n', block_size_hint)
#define P_nlrec_noseek_eolcmt_make(block_size_hint)	P_ctrec_noseek_eolcmt_make('\n', '#', block_size_hint)

/* Pio_elt_t: used for list of input records managed by the io
 * discipline.  The io discipline maintains a doubly-linked list of
 * these records using the prev/next fields, where the head of the
 * list is always a 'dummy' record that is not used except as a
 * placeholder for managing the list.
 * 
 * XXX_TODOC: offset, begin, end, etc.
 *
 * There is an extra data field, disc_ptr, which is optionally used by
 * the io discipline and ignored by the main library code.
 */

/* type Pio_elt_t: */
struct Pio_elt_s {
  Pio_elt_t     *prev;
  Pio_elt_t     *next;
  Sfoff_t        offset;
  Pbyte         *begin;
  Pbyte         *end;
  size_t         len;
  int            bor;
  int            eor;
  int            eof;
  size_t         num;
  const char    *unit;
  void          *disc_ptr;
};

/* Function types needed for the IO discipline: */

typedef Perror_t     (*P_io_unmake_fn)    (Pio_disc_t* io_disc);
typedef Perror_t     (*P_io_sfopen_fn)    (P_t *pads, Pio_disc_t* io_disc, Sfio_t *sfio, Pio_elt_t *head);
typedef Perror_t     (*P_io_sfclose_fn)   (P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt, size_t remain);
typedef Perror_t     (*P_io_read_fn)      (P_t *pads, Pio_disc_t* io_disc, Pio_elt_t *io_cur_elt,
					   Pio_elt_t **next_elt_out);
typedef ssize_t      (*P_io_rec_close_buf_fn) (P_t *pads, Pio_disc_t* io_disc, Pbyte *buf,
					   Pbyte *rec_start, size_t num_bytes);
typedef ssize_t      (*P_io_rec_close_io_fn) (P_t *pads, Pio_disc_t* io_disc, Sfio_t *io);
typedef ssize_t      (*P_io_blk_close_fn) (P_t *pads, Pio_disc_t* io_disc, Pbyte *buf,
					   Pbyte *blk_start, size_t num_bytes, Puint32 num_recs);
typedef const char * (*P_io_read_unit_fn) (P_t *pads, Pio_disc_t* io_disc);

/* type Pio_disc_t: */
struct Pio_disc_s {
  /* state */
  const char         *name;          /* short IO discipline name */
  const char         *descr;         /* short IO discipline description */
  int                 rec_based;     /* discipline is record-based? */
  int                 has_rblks;     /* discipline supports blocks of records? */
  size_t              rec_obytes;    /* bytes used for record open marker (0 if not used) */
  size_t              rec_cbytes;    /* bytes used for record close marker (0 if not used) */
  size_t              blk_obytes;    /* bytes used for block open marker (0 if not used) */
  size_t              blk_cbytes;    /* bytes used for block close marker (0 if not used) */
  void               *data;          /* discipline-specific data */
  /* functions */
  P_io_unmake_fn      unmake_fn;     /* pairs with this discipline's make routine */
  P_io_sfopen_fn      sfopen_fn;     /* Sfio-based open */
  P_io_sfclose_fn     sfclose_fn;    /* Sfio-based close */
  P_io_read_fn        read_fn;       /* read */
  P_io_rec_close_buf_fn  rec_close_buf_fn;  /* fill in record markers for an output record */
  P_io_rec_close_io_fn   rec_close_io_fn;  /* fill in record markers for an output record */
  P_io_blk_close_fn   blk_close_fn;  /* fill in block markers for an output block */
  P_io_read_unit_fn   read_unit_fn;  /* return description of read unit */
};

/* ================================================================================ */

#ifdef IODISC_ALLOC_DEBUG
void IODISC_dbg_report(const char *context);
#define IODISC_DBG_REPORT(context) IODISC_dbg_report(context)
#else
#define IODISC_DBG_REPORT(context) do { } while (0)
#endif

/* ================================================================================ */

#endif /*  __P_IO_DISC_H__  */
