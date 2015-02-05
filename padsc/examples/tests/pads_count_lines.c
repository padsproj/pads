#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  P_t*          pads;
  Pio_disc_t*   io_disc;
  Pdisc_t       my_disc = Pdefault_disc;
  size_t        bytes_skipped;

  io_disc = P_nlrec_make(0);

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(ERROR_FATAL, "*** P_libopen failed ***");
  }
  if (P_ERR == P_io_fopen(pads, argv[1])) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  int lines = 0;
  while (P_ERR != P_io_next_rec(pads, &bytes_skipped)) {
    lines++;
  }
  error(0, "DONE  lines = %d", lines);

  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
    return -1;
  }
  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    return -1;
  }
  return 0;
}
