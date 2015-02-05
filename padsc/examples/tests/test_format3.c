#include "pads.h"
#include "format3.h"

int main(int argc, char** argv) {
  P_t           *pads;
  Pio_disc_t   *io_disc;
  Pdisc_t       my_disc = Pdefault_disc;
  entry            f3data;
  entry_pd         f3pd;
  entry_m          f3m;

  io_disc = P_norec_make(0);
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline norec");
  } else {
    error(0, "\nInstalled IO discipline norec");
  }

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  /* INIT f3data, f3pd -- must do this for all variable data types */
  entry_init   (pads, &f3data);
  entry_pd_init(pads, &f3pd);

  /* INIT mask -- must do this! */
  entry_m_init(pads, &f3m, P_CheckAndSet);

  if (P_ERR == P_io_fopen(pads, "../../data/format3")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    Perror_t res;
    int i;
    error(0, "\nCalling entry_read");
    res= entry_read(pads, &f3m, &f3pd, &f3data);

    if (res == P_OK) {
      error(0|ERROR_PROMPT, "Record okay:\t");
      for (i = 0; i < f3data.i.length; i++){
	error(0|ERROR_PROMPT, "%d", f3data.i.elts[i]);
	if (i != f3data.i.length-1) {
	  error(0|ERROR_PROMPT, "|");
	}  else {
	  error(0, "");
	}
      }
    } else if (f3data.i.length) {
      error(0, "Record not okay");
    }
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
}
