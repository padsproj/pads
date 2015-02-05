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
  P_t*            pads;
  Pio_disc_t*     io_disc;
  Pint8           i1;
  Pbase_m         m    = P_CheckAndSet;
  Pbase_pd        pd;
  Pdisc_t         my_disc = Pdefault_disc;
  size_t          bytes_skipped;
  unsigned long   ultmp;

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

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
  if (pads->path) error(ERROR_FATAL, "pads->path should be NULL");
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.libtest1")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * XXX Process the data here XXX
   */
  while (1) {
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }
    /* try to read 4 fixed width integers (width 6) */
    for (i = 0; i < 4; i++) {
      if (P_OK == Pa_int8_FW_read(pads, &m, &pd, &i1, 6)) {
	error(0, "Read ascii integer of width 6: %ld", (long)i1);
      }
    }
    if (strncmp(argv[1], "norec", 5) == 0) {
      if (P_ERR == Pa_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) {
	error(2, "Could not find EOR (newline), ending program");
	break;
      }
    } else {
      if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
	error(2, "Could not find EOR (newline), ending program");
	break;
      }
    }
    ultmp = bytes_skipped;
    error(0, "next_rec returned bytes_skipped = %ld", ultmp);
  }

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
