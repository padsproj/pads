#include "pads-internal.h" /* for testing - normally do not include internal */

#if 0
#include "pads.h"
#include "format2.h"
#endif

int main(int argc, char** argv) {
  Pio_disc_t   *io_disc;
  int             ctr;
  size_t          n;
  int             f_found;
  P_t*            pads;
  Pdisc_t         my_disc = Pdefault_disc;

  if (!(io_disc = P_norec_make(0))) {
    error(2, "*** P_norec_make failed ***");
    return -1;
  } 

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(2, "*** P_open failed ***");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, "../../data/format2")) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  /*
   * XXX Process the data here XXX
   */
  ctr = 0;
  while (!P_io_at_eof(pads)) {
    if (P_OK == Pa_char_lit_scan2(pads, '|', '\n', 1, 1, 0, &f_found, &n)) {
      if (f_found) { 
	ctr++;
	P_io_checkpoint(pads, 1);
	if (P_OK == Pa_char_lit_match(pads, 'a', 1)) {
	  error(2, "found an 'a' after a vbar");
	}
	P_io_commit(pads);
      } else { /* found newline */
	error(2, "Found %d vertical bars on line", ctr);
	ctr = 0;
      }
      continue;
    }
    break;    /* found neither vbar or nl */
  }

  if (ctr) {
    error(2, "Found %d vertical bars on line", ctr);
  }
  error(2, "Could not find newline, ending program");

  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    return -1;
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    return -1;
  }

  return 0;
}
