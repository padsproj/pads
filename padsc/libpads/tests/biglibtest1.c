/*
 *  libtest1: Test fixed width ascii read functions
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  /* int             ctr; */
  /* size_t          n; */
  /* unsigned char   c; */
  int             i;
  unsigned long   count = 0;
  Pint32       i1;
  P_t*          pads;
  Pio_disc_t*  io_disc;
  Pdisc_t      my_disc = Pdefault_disc;
  Pbase_m      m       = P_CheckAndSet;
  Pbase_pd     pd;
  size_t          bytes_skipped;

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
  my_disc.e_rep = PerrorRep_Min;

  if (argc != 2) {
    goto usage;
  }
  if (strcmp(argv[1], "fwrec") == 0) {
    io_disc = P_fwrec_make(0, 24, 1); /* 4 6-char ints, newline */ 
  } else if (strcmp(argv[1], "nlrec") == 0) {
    io_disc = P_nlrec_make(0);
  } else if (strcmp(argv[1], "norec") == 0) {
    io_disc = P_norec_make(0);
  } else if (strcmp(argv[1], "fwrec_noseek") == 0) {
    io_disc = P_fwrec_noseek_make(0, 24, 1); /* 4 6-char ints, newline */ 
  } else if (strcmp(argv[1], "nlrec_noseek") == 0) {
    io_disc = P_nlrec_noseek_make(0);
  } else if (strcmp(argv[1], "norec_noseek") == 0) {
    io_disc = P_norec_noseek_make(0);
  } else {
    goto usage;
  }
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline %s", argv[1]);
  } else {
    error(0, "\nInstalled IO discipline %s", argv[1]);
  }

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.biglibtest1")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * XXX Process the data here XXX
   */
  while (1) {
    count++;
    if (P_io_at_eof(pads)) {
      break;
    }
    /* try to read 4 fixed width integers (width 6) */
    for (i = 0; i < 4; i++) {
      Pa_int32_FW_read(pads, &m, 6, &pd, &i1);
    }
    if (strncmp(argv[1], "norec", 5) == 0) {
      if (P_ERR == Pa_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) {
	break;
      }
    } else {
      if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
	break;
      }
    }
  }

  error(0, "\n%lu\n\n", count);

  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    exit(-1);
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }
  return 0;

 usage:
  error(2, "\nUsage: %s <io-disc-name>\n\n\twhere <io-disc-name> is one of: fwrec, nlrec, norec, fwrec_noseek, nlrec_noseek, norec_noseek\n", argv[0]);
  return -1;
}
