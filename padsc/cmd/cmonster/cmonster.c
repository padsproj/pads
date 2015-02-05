/*
 * cmonster or 'cookie monster' command
 *
 * Usage: see helpers.h
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "cmonster.h"
#include "helpers.h"
#include <unistd.h>

/* normally this would be cm.outbuf_sz.  adding 1 for debugging */
#define SFWRITE_SIZE (cm.outbuf_sz+1)

CM_t *error_cm = 0; /* cm handle for parser routines to use for error reporting */

int main(int argc, char **argv)
{
  CM_t                    cm;

  P_t                  *pads;
  Pdisc_t              my_disc;
  Pio_disc_t          *io_disc;

  CM_dspec                dspec;
  CM_dspec_m              dspec_m;
  CM_dspec_pd             dspec_pd;

  CM_cspec                cspec;
  CM_cspec_m              cspec_m;
  CM_cspec_pd             cspec_pd;

  Sfio_t                 *mem_io;
  size_t                  skipped_bytes = 0, rec_len;
  int                     c, eor = 0, eof = 0, skip_rec = 0, buf_full = 0;
  Pbyte               *begin = 0, *end = 0;

  Puint32              cmon;
  Pbase_pd             dummy_pd;

  const char             *cspec_str = 0, *dspec_str = 0; /* required */
  const char             *inf_str = 0, *outf_str = 0, *errf_str = 0, *padslf_str = 0; /* optional */

  cm.inf    = sfstdin;
  cm.outf   = sfstdout;
  cm.errf   = sfstderr;
  cm.padslf = 0; 

  error_cm  = &cm;

  /* for some reason we need to do this early in main.c or weird things happened */
  if (!(cm.vm = vmopen(Vmdcheap, Vmbest, 0))) {
    sfprintf(cm.errf, "\n*** FATAL: vmopen failed\n\n");
    return -1;
  }

  /* Parse command line */
  while ((c = getopt(argc, argv, "hc:d:e:i:o:p:")) != -1) {
    switch (c) {
    case '?':
      goto usage;
    case 'h':
      goto detailed_usage;
    case 'c':
      cspec_str = optarg;
      continue;
    case 'd':
      dspec_str = optarg;
      continue;
    case 'i':
      if (inf_str) {
	sfprintf(cm.errf, "\n*** Only one -i option allowed\n");
	goto usage;
      }
      inf_str = optarg;
      if (strcmp(inf_str, "/dev/stdin")) {
	/* something other than stdin */
	if (strcmp(inf_str, "/dev/stdout") == 0) {
	  sfprintf(cm.errf, "\n*** Cannot use /dev/stdout for -i input argument\n");
	  goto usage;
	}
	if (strcmp(inf_str, "/dev/stderr") == 0) {
	  sfprintf(cm.errf, "\n*** Cannot use /dev/stderr for -i input argument\n");
	  goto usage;
	}
	if (!(cm.inf = sfopen(NiL, inf_str, "r"))) {
	  sfprintf(cm.errf, "\n*** FATAL: Failed to open input file \"%s\" for reading\n\n", inf_str);
	  return -1;
	}
      }
      continue;
    case 'e':
      if (errf_str) {
	sfprintf(cm.errf, "\n*** Only one -e option allowed\n");
	goto usage;
      }
      errf_str = optarg;
      if (strcmp(errf_str, "/dev/stderr")) {
	/* something other than stderr */
	if (strcmp(errf_str, "/dev/stdin") == 0) {
	  sfprintf(cm.errf, "\n*** FATAL: Cannot use /dev/stdin for -e error output argument\n\n");
	  return -1;
	}
	if (strcmp(errf_str, "/dev/stdout") == 0) {
	  cm.errf = sfstdout;
	} else if (!(cm.errf = sfopen(NiL, errf_str, "w"))) {
	  sfprintf(cm.errf, "\n ***FATAL: Failed to open error out file \"%s\" for write\n\n", errf_str);
	  return -1;
	}
      }
      continue;
    case 'o':
      if (outf_str) {
	sfprintf(cm.errf, "\n*** Only one -o option allowed\n");
	goto usage;
      }
      outf_str = optarg;
      if (strcmp(outf_str, "/dev/stdout")) {
	/* something other than stdout */
	if (strcmp(outf_str, "/dev/stdin") == 0) {
	  sfprintf(cm.errf, "\n*** FATAL: Cannot use /dev/stdin for -o data output argument\n\n");
	  return -1;
	}
	if (strcmp(outf_str, "/dev/stderr") == 0) {
	  cm.outf = sfstderr;
	} else if (!(cm.outf = sfopen(NiL, outf_str, "w"))) {
	  sfprintf(cm.errf, "\n ***FATAL: Failed to open data out file \"%s\" for writing\n\n", outf_str);
	  return -1;
	}
      }
      continue;
    case 'p':
      if (padslf_str) {
	sfprintf(cm.errf, "\n*** Only one -p option allowed\n");
	goto usage;
      }
      padslf_str = optarg;
      if (strcmp(padslf_str, "/dev/stdin") == 0) {
	sfprintf(cm.errf, "\n*** FATAL: Cannot use /dev/stdin for -p PADSL output argument\n\n");
	return -1;
      }
      if (strcmp(padslf_str, "/dev/stdout") == 0) {
	cm.padslf = sfstdout;
      } else if (strcmp(padslf_str, "/dev/stderr") == 0) {
	cm.padslf = sfstderr;
      } else if (!(cm.padslf = sfopen(NiL, padslf_str, "w"))) {
	sfprintf(cm.errf, "\n ***FATAL: Failed to open PADSL out file \"%s\" for writing\n\n", padslf_str);
	return -1;
      }
      continue;
    }
  }
  if (!cspec_str || !dspec_str) goto usage;
  if (argc != optind) {
    sfprintf(cm.errf, "\nUnexpected trailing command line arguments.\n");
    goto usage;
  }

  io_disc = P_norec_make(0);
  if (!io_disc) {
    sfprintf(cm.errf, "\n*** FATAL: Failed to install IO discipline to parse command line\n\n");
    return -1;
  }

  my_disc = Pdefault_disc;
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    sfprintf(cm.errf, "\n*** FATAL: P_open failed\n\n");
    return -1;
  }

  CM_dspec_init(pads, &dspec);
  CM_dspec_pd_init(pads, &dspec_pd);
  CM_dspec_m_init(pads, &dspec_m, P_CheckAndSet);

  CM_cspec_init(pads, &cspec);
  CM_cspec_pd_init(pads, &cspec_pd);
  CM_cspec_m_init(pads, &cspec_m, P_CheckAndSet);

  if (!(mem_io = sfopen(NULL, dspec_str, "s"))) {
    sfprintf(cm.errf, "\n*** FATAL: Unexpected: sfopen(NULL, dspec_str, \"s\") failed\n\n");
    return -1;
  }
  if (P_ERR == P_io_set(pads, mem_io)) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_set failed\n\n");
    return -1;
  }
  if (P_ERR == CM_dspec_read(pads, &dspec_m, &dspec_pd, &dspec)) {
    sfprintf(cm.errf, "\nCould not parse -d dspec argument\n");
    goto usage;
  }
  if (P_ERR == P_io_close(pads)) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_close failed\n\n");
    return -1;
  }
  sfclose(mem_io);

  if (!(mem_io = sfopen(NULL, cspec_str, "s"))) {
    sfprintf(cm.errf, "\n*** FATAL: Unexpected: sfopen(NULL, cspec_str, \"s\") failed\n\n");
    return -1;
  }
  if (P_ERR == P_io_set(pads, mem_io)) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_set failed\n\n");
    return -1;
  }
  if (P_ERR == CM_cspec_read(pads, &cspec_m, &cspec_pd, &cspec)) {
    sfprintf(cm.errf, "\nCould not parse -c cspec argument\n");
    goto usage;
  }
  if (P_ERR == P_io_close(pads)) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_close failed\n\n");
    return -1;
  }
  sfclose(mem_io);
  if (P_ERR == P_close(pads)) {
    sfprintf(cm.errf, "\n*** FATAL: P_close failed\n\n");
    return -1;
  }
  sfprintf(cm.errf, "XXX_REMOVE description of cookie\n");
  describe_cookie(cm.errf, &cspec);

  if (-1 == CM_open_iodisc(&cm, &dspec, &io_disc)) goto usage;

  if (!io_disc) {
    sfprintf(cm.errf, "\n*** FATAL: Failed to install IO discipline %s\n\n", dspec_str);
    return -1;
  } else {
    sfprintf(cm.errf, "\nXXX_REMOVE Installed IO discipline %s\n", dspec_str);
  }

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    sfprintf(cm.errf, "\n*** FATAL: P_open failed\n\n");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, "/dev/stdin")) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_fopen failed\n\n");
    return -1;
  }

  /* initialize cm */
  cm.pads = pads;
  Pstring_init(pads, &(cm.tmp1));
  cm.outbuf_sz = out_sz_cookie(&cspec);
  if (cm.outbuf_sz < 4) {
    cm.outbuf_sz = 4;
  }
  if (!(cm.outbuf = vmoldof(cm.vm, 0, Pbyte, cm.outbuf_sz, 1))) { /* alloc added space for newline */
    sfprintf(cm.errf, "\n*** FATAL: Memory alloc failed\n\n");
    return -1;
  }
  cm.outbuf_end = cm.outbuf + cm.outbuf_sz;
  *(cm.outbuf_end) = '\n'; /* for debugging purposes, newline-terminate each output record */

  /*
   * Construct and emit 2 special header records of size cm.outbuf_sz
   * (all records have this size)
   *
   * rec1: first 4 bytes contain cm.outbuf_sz encoded in SBL
   *       this size is always >= 4.
   *      
   * rec2: first 4 bytes contain the cookie monster 'cmon' magic value
   *          = ('c' << 24) + ('m' << 16) + ('o' << 8) + 'n'
   *          = 1668116334
   *      encoded in SBL
   *
   * In each case any bytes after byte 4 is zero.
   */

  Pbase_pd_init(&dummy_pd);
  /* zero the output record before filling it in */
  memset(cm.outbuf, 0, cm.outbuf_sz);
  /* fill in cm.outbuf_sz */
  if (4 != Psbl_uint32_write2buf(pads, cm.outbuf, cm.outbuf_sz, &buf_full, 4, &dummy_pd, &cm.outbuf_sz)) {
    sfprintf(cm.errf, "\n*** FATAL: Unexpected error calling Psbl_uint32_write2buf\n\n");
    return -1;
  }
  if (SFWRITE_SIZE != sfwrite(cm.outf, cm.outbuf, SFWRITE_SIZE)) {
    sfprintf(cm.errf, "\n*** FATAL: sfwrite error, failed to write %lu bytes\n\n", (unsigned long)SFWRITE_SIZE);
    return -1;
  }

  /* zero the output record before filling it in */
  memset(cm.outbuf, 0, cm.outbuf_sz);
  /* fill in special cmon value */
  cmon = ('c' << 24) + ('m' << 16) + ('o' << 8) + 'n';
  sfprintf(cm.errf, "XXX_REMOVE cmon = %lu\n", (unsigned long)cmon);
  if (4 != Psbl_uint32_write2buf(pads, cm.outbuf, cm.outbuf_sz, &buf_full, 4, &dummy_pd, &cmon)) {
    sfprintf(cm.errf, "\n*** FATAL: Unexpected error calling Psbl_uint32_write2buf\n\n");
    return -1;
  }
  if (SFWRITE_SIZE != sfwrite(cm.outf, cm.outbuf, SFWRITE_SIZE)) {
    sfprintf(cm.errf, "\n*** FATAL: sfwrite error, failed to write %lu bytes\n\n", (unsigned long)SFWRITE_SIZE);
    return -1;
  }

  /* read all input records, generate output records */
  while (1) {
    if (P_ERR == PDCI_io_need_rec_bytes(pads, skip_rec, &begin, &end, &eor, &eof, &skipped_bytes)) {
      sfprintf(cm.errf, "\nXXX_REMOVE need_rec_bytes returned P_ERR, break from while loop\n");
      break;
    }
    skip_rec = 1;
    rec_len = end - begin;
    sfprintf(cm.errf, "\nXXX_REMOVE rec_len = %ld  skipped_bytes = %ld, eor = %d, eof = %d, bytes = [%.*s]\n",
	  (long)rec_len, (long)skipped_bytes, eor, eof, rec_len, begin);
    if (rec_len) {
      /* zero the next output record before filling it in */
      memset(cm.outbuf, 0, cm.outbuf_sz);
      /* init outbuf_cursor */
      cm.outbuf_cursor = cm.outbuf;
      /* fill in outbuf using cspec */
      switch (cspec.cookie.tag) {
      case CM_c_or_s_err:
	/* never happens */
	continue; /* skip to next record without writing */
      case c_cookie:
	if (P_ERR == rw_c_cookie(&cm, &(cspec.cookie.val.c_cookie), begin, end)) {
	  /* already reported error */
	  continue; /* skip to next record without writing */
	}
	break;
      case s_cookie:
	if (P_ERR == rw_s_cookie(&cm, &(cspec.cookie.val.s_cookie), begin, end)) {
	  /* already reported error */
	  continue; /* skip to next record without writing */
	}
	break;
      }
      /* write outbuf */
      if (SFWRITE_SIZE != sfwrite(cm.outf, cm.outbuf, SFWRITE_SIZE)) {
	sfprintf(cm.errf, "\n*** FATAL: sfwrite error, failed to write %lu bytes\n\n", (unsigned long)SFWRITE_SIZE);
	return -1;
      }
    }
    if (eof) {
      sfprintf(cm.errf, "\nXXX_REMOVE need_rec_bytes returned P_ERR, break from while loop\n");
      break;
    }
  }
  /* done */

  /* cleanup cm */
  Pstring_cleanup(pads, &(cm.tmp1));
  if (cm.vm) {
    vmclose(cm.vm); /* frees everything alloc'd using cm.vm */
  }

  if (P_ERR == P_io_close(pads)) {
    sfprintf(cm.errf, "\n*** FATAL: P_io_close failed\n\n");
    return -1;
  }

  if (P_ERR == P_close(pads)) {
    sfprintf(cm.errf, "\n*** FATAL: P_close failed\n\n");
    return -1;
  }

  return 0;

 usage:
  sfprintf(cm.errf, USAGE);
  return -1;

 detailed_usage:
  sfprintf(cm.outf, DETAILED_USAGE);
  return 0;
}
