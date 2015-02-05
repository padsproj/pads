#include "pads-internal.h"

P_NOGEN

int main(int argc, char** argv) {
  P_t*             pads;
  Pio_disc_t*      io_disc;
  Pdisc_t          my_disc = Pdefault_disc;
  size_t           bytes_skipped;
  const char      *fname;
  int              blocked;
  int              verbose = 0;
  Puint64          num_recs = 0;


  /* fname = "../../data/ND01.HP57WD1.OAK.5247135.20010513134851"; */
  /*   fname = "/tmp/foo/ND01.HP57WD1.OAK.5247135.20010513134851.stripped"; */
  fname = "/tmp/foo/ONE1.HP568T1A.G0155V00.70312937.20020412111044";
  blocked = 1;

  if (argc > 4) goto usage;
  if (argc >= 2) {
    fname = argv[1];
  }
  if (argc >= 3) {
    if (strcmp(argv[2], "0")==0) {
      blocked = 0;
    } else if (strcmp(argv[2], "1")==0) {
      blocked = 1;
    } else goto usage;
  }
  if (argc >= 4) {
    verbose = atoi(argv[3]);
  }

  io_disc = P_vlrec_noseek_make(blocked, 0); /* no avg rlen hint */
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline vlrec_noseek");
  } else {
    error(0, "\nInstalled IO discipline vlrec_noseek");
  }

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, (char*)fname)) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  while (1) {
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      error(2, "no next record, ending program");
      goto done;
    }
    num_recs++;
    if (verbose) {
      error(0, "Record %llu : %lu bytes",
	    (unsigned long long)num_recs,
	    (unsigned long)bytes_skipped);
    }
  }

 done:
  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    return -1;
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    return -1;
  }

  return 0;

 usage:
  error(2, "\nUsage: %s [ <fname> ] [ <blocked> ] \n\n\twhere <fname> is a data file and <blocked> is either 0 or 1\n",
	argv[0]);
  return -1;
}
