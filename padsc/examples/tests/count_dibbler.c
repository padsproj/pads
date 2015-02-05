#include "dibbler-notrailer.h"


int main(int argc, char** argv) {
  P_t                    *pads;
  Pio_disc_t            *io_disc;
  out_sum_header           header;
  out_sum_data_line        dline;
  out_sum_data_line_pd     dline_pd;
  out_sum_data_line_m      dline_m;
  out_sum_data_line_acc    acc;
  char                     *fname = "../../data/jun9.out_sum.stream";

  if (argc >= 2 ) {
    fname = argv[1];
  }
  error(0, "\nUsing input file %s", fname);

  io_disc = P_nlrec_noseek_make(0);
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline nlrec_noseek");
  } else {
    error(0, "\nInstalled IO discipline nlrec_noseek");
  }

  if (P_ERR == P_open(&pads, 0, io_disc)) {
    error(2, "*** P_open failed ***");
    return -1;
  }

  /* INIT dline -- must do this for all variable data types */
  out_sum_data_line_init(pads, &dline);
  out_sum_data_line_pd_init(pads, &dline_pd);
  out_sum_data_line_acc_init(pads, &acc);
  out_sum_data_line_m_init(pads, &dline_m, P_CheckAndSet);
  if (P_ERR == P_io_fopen(pads, fname)) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  /*
   * Try to read header
   */

  if (P_OK == out_sum_header_read(pads, 0, 0, &header)) {
    error(0, "reading header returned: OK");
  } else {
    error(2, "reading header returned: error");
  }

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    out_sum_data_line_read(pads, &dline_m, &dline_pd, &dline);
    out_sum_data_line_acc_add(pads, &acc, &dline_pd, &dline);
  }
      
  out_sum_data_line_acc_report(pads, "dline", 0, 0, &acc);

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
