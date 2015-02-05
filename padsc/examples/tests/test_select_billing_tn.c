#include "dibbler.h"

#define TEST_VAL 9733608667ULL

int main(int argc, char** argv) {
  P_t                    *pads;
  Pdisc_t               *disc;
  Pio_disc_t            *io_disc;
  out_sum_header           header;
  out_sum_header_pd        header_pd;
  out_sum_header_m         header_m = { 0 };
  out_sum_data_line        dline;
  out_sum_data_line_pd     dline_pd;
  out_sum_data_line_m      dline_m = { 0 };
  char                    *fname = "../../data/dibbler1";
  int                      commit;

  error(0, "\nUsing input file %s", fname);

  disc = &Pdefault_disc;
  io_disc = P_nlrec_noseek_make(0);

  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline nlrec_noseek");
  } else {
    error(0, "\nInstalled IO discipline nlrec_noseek");
  }

  if (P_ERR == P_open(&pads, disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }
  if (P_ERR == P_io_fopen(pads, fname)) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  /* INIT all data and pd types */
  out_sum_header_init(pads, &header);
  out_sum_header_pd_init(pads, &header_pd);
  out_sum_data_line_init(pads, &dline);
  out_sum_data_line_pd_init(pads, &dline_pd);

  /*
   * Try to read header
   */

  if (P_OK == out_sum_header_read(pads, &header_m, &header_pd, &header)) {
    error(0, "reading header returned: OK");
  } else {
    error(2, "reading header returned: error");
  }

  /* Init list */
  /* could init a list here (list of pointer to TARGET_TYPE) */

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    P_io_checkpoint(pads, 0);
    commit = 1;
    out_sum_data_line_read(pads, &dline_m, &dline_pd, &dline);
    /* Fields that contribute to the query expression must be error free, 
       even though entire order need not be error free.
       What does it mean if you say nothing about errors at all */
    if (dline_pd.billing_tn.nerr == 0) {
      if (dline.billing_tn.tag == yesPN) { /* should be dib_pn_vbar_yesPN ??? */
	if (dline.billing_tn.val.yesPN.val == TEST_VAL) {
	  /* could call a copy method here and add to list */
	  /* P_io_commit_dump(pads, sfstdout); */
	  P_io_commit(pads);
	  commit = 0;
	}
      }
    } else {
      /* skip it b/c billing_tn is invalid */
    }
    if (commit) P_io_commit(pads);
  }
  
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
