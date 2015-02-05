#include "pads.h"
#include "format7.h"

int main(int argc, char** argv) {
  P_t*          pads;
  myfile          rep;
  myfile_pd       pd ;
  myfile_m        m;

  P_ERR == P_open(&pads, 0, 0);

  if (P_ERR == P_io_fopen(pads, "../../data/format7")) {
    error(ERROR_FATAL, "*** Could not open data file %s", "../../data/format7");
  }

  /* init -- must do this! */
  P_INIT_ALL(pads, myfile, rep, m, pd, P_CheckAndSet);

  /* Try to read entire file */
  error(0, "\ncalling myfile_read");
  if (P_OK == myfile_read(pads, &m, &pd, &rep)) {
    error(0, "myfile_read worked");
  } else {
    error(0, "myfile_read returned: error");
  }

  P_CLEANUP_ALL(pads, myfile, rep, pd);
  P_io_close(pads);
  P_close(pads);
  return 0;
}
