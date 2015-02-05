/*
 * Write to stdout a data file with vlrec format.
 * Data is read from stdin using io_disc nlrec
 * and the format described in rec1.p (in_rec) and it
 * is written out using the format described in
 * rec1.p (out_rec).
 */

#include "rec1.h"

int main(int argc, char** argv) {
  P_t                  *pads;
  Pdisc_t              my_disc;
  Pio_disc_t          *in_io_disc, *out_io_disc;

  in_file                 rep;
  in_file_m               m;
  in_file_pd              pd;

  in_file                *in_rep  = &rep;
  in_file_m              *in_m    = &m;
  in_file_pd             *in_pd   = &pd;

  out_file               *out_rep = (out_file*)   &rep;
  out_file_pd            *out_pd  = (out_file_pd*)&pd;

  in_io_disc = P_nlrec_make(0);
  if (!in_io_disc) {
    error(ERROR_FATAL, "\nFailed to make IO discipline nlrec");
  }
  out_io_disc = P_vlrec_make(0, 0);
  if (!out_io_disc) {
    error(ERROR_FATAL, "\nFailed to make IO discipline vlrec");
  }

  my_disc = Pdefault_disc;
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
  my_disc.copy_strings = 1; /* required because we read more than one record before processing them */

  if (P_ERR == P_open(&pads, &my_disc, in_io_disc)) {
    error(ERROR_FATAL, "\n*** P_open failed ***");
  }

  in_file_init(pads, in_rep);
  in_file_m_init(pads, in_m, P_CheckAndSet);
  in_file_pd_init(pads, in_pd);

  if (P_ERR == P_io_fopen(pads, "/dev/stdin")) {
    error(ERROR_FATAL, "\n*** P_io_fopen failed ***");
  }

  if (P_ERR == in_file_read(pads, in_m, in_pd, in_rep)) {
    error(ERROR_FATAL, "\n*** in_file_read failed ***");
  }

  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "\n*** P_io_close failed ***");
  }

  if (P_ERR == P_set_io_disc(pads, out_io_disc)) {
    error(ERROR_FATAL, "\n*** P_set_io_disc failed ***");
  }

  out_file_write2io(pads, sfstdout, out_pd, out_rep);

  /* done */

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "\n*** P_close failed ***");
  }

  return 0;
};

