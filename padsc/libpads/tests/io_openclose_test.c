/*
 *  io_openclose_test: Test io open/close functionality
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  Sfio_t         *io;
  int             i;
  P_t*          pads;
  Pio_disc_t*  io_disc;
  Pint8        i1;
  Pbase_m      m    = P_CheckAndSet;
  Pbase_pd     pd;
  Pdisc_t      my_disc = Pdefault_disc;
  size_t          bytes_skipped;
  unsigned long   ultmp;
  const char     *fname = "../../data/ex_data.io_openclose_test.small";

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

  if ((argc != 2) && (argc != 3)) {
    goto usage;
  }
  if (argc == 3) {
    fname = argv[2];
    if (strcmp(fname, "large") == 0) {
      fname = "../../data/ex_data.io_openclose_test.large";
    }
    if (strcmp(fname, "-") == 0) {
      fname = "/dev/stdin";
    }
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
    error(ERROR_FATAL, "Failed to install IO discipline %s", argv[1]);
  } else {
    error(0, "Installed IO discipline %s", argv[1]);
  }

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(ERROR_FATAL, "*** P_libopen failed ***");
  }
  if (strcmp(fname, "/dev/stdin") == 0) {
    io = sfstdin;
  } else {
    if (!(io = sfopen(NiL, fname, "r"))) {
      error(ERROR_FATAL, "Failed to open file \"%s\"", fname);
    }
    if (sfset(io, 0, 0) & SF_PUBLIC) {
      error(0, "SF_PUBLIC is set");
    }
    if (sfset(io, 0, 0) & SF_SHARE) {
      error(0, "SF_SHARE is set");
    }
  }

  if (P_ERR == P_io_set(pads, io)) {
    error(ERROR_FATAL, "P_io_set failed");
  }

  /*
   * XXX Process the data here XXX
   */
  while (1) {
    /* uninstall then install io each time through the loop */
    if (P_ERR == P_io_close(pads)) {
      error(ERROR_FATAL, "P_io_close failed");
    }
    if (P_ERR == P_io_set(pads, io)) {
      error(ERROR_FATAL, "P_io_set failed");
    }
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }
    /* try to read 4 fixed width integers (width 6) */
    for (i = 0; i < 4; i++) {
      if (P_OK == Pa_int8_FW_read(pads, &m, &pd, &i1, 6)) {
	error(0, "Read ascii integer of width 6: %ld", i1);
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
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }

  return 0;

 usage:
  error(2, "\nUsage: %s <io-disc-name> [ <fname> ]\n\n\twhere <io-disc-name> is one of: "
	"fwrec, nlrec, norec, fwrec_noseek, nlrec_noseek, norec_noseek\n"
	"  Note: fname can also be /dev/stdin or alias 'large' for large data set", argv[0]);
  return -1;
}
