#include "dibbler.h"

#define FASTEST 1

typedef enum behave_e { count_all, out_all, accum_all, count_first21, out_first21 } behave;

const char * behave_descr[] = {
  "count_all",
  "out_all",
  "accum_all",
  "count_first21",
  "out_first21"
 };

int main(int argc, char** argv) {
  P_t                    *pads;
  Pio_disc_t            *io_disc;
  out_sum_header           header;
  out_sum_data_line        dline;
  out_sum_data_line_pd     dline_pd;
  out_sum_data_line_acc    acc;
  char                     *fname = "../../data/dibbler1";
  behave                   b = count_first21;
  unsigned long            good_21 = 0, good = 0, bad = 0;

  if (argc > 3) {
    goto usage;
  }
  if (argc >= 2 ) {
    fname = argv[1];
  }
#ifndef FASTEST
  if (argc == 3 ) {
    if (strcmp(argv[2], "count_all") == 0) {
      b = count_all;
    } else if (strcmp(argv[2], "out_all") == 0) {
      b = out_all;
    } else if (strcmp(argv[2], "accum_all") == 0) {
      b = accum_all;
    } else if (strcmp(argv[2], "count_first21") == 0) {
      b = count_first21;
    } else if (strcmp(argv[2], "out_first21") == 0) {
      b = out_first21;
    } else {
      goto usage;
    }
  }

  error(0, "\nUsing input file %s", fname);
  error(0, "\nUsing behavior %s", behave_descr[b]);
#endif

  io_disc = P_nlrec_noseek_make(0);
#ifndef FASTEST
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline nlrec_noseek");
  } else {
    error(0, "\nInstalled IO discipline nlrec_noseek");
  }
#endif

  if (P_ERR == P_open(&pads, 0, io_disc)) {
    error(2, "*** P_open failed ***");
    return -1;
  }
#ifdef FASTEST
  pads->disc->errorf = 0;
#endif

  /* INIT dline -- must do this for all variable data types */
  out_sum_data_line_init(pads, &dline);
  out_sum_data_line_pd_init(pads, &dline_pd);
  if (b == accum_all) {
    out_sum_data_line_acc_init(pads, &acc);
  }

  if (P_ERR == P_io_fopen(pads, fname)) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  /*
   * Try to read header
   */

  if (P_OK == out_sum_header_read(pads, 0, 0, &header)) {
#ifndef FASTEST
    error(0, "reading header returned: OK");
#endif
  } else {
    error(2, "reading header returned: error");
  }

  /*
   * Try to read each line of data
   */
  switch (b) {
    case count_all: {
      while (!P_io_at_eof(pads)) {
	if (P_OK == out_sum_data_line_read(pads, 0, &dline_pd, &dline)) {
	  good++;
	} else {
	  bad++;
	}
	error(0, "\ngood: %lu bad: %lu", good, bad);
      }
    } break;

    case accum_all: {
      while (!P_io_at_eof(pads)) {
	out_sum_data_line_read(pads, 0, &dline_pd, &dline);
	out_sum_data_line_acc_add(pads, &acc, &dline_pd, &dline);
      }
      out_sum_data_line_acc_report(pads, "dline", 0, 0, &acc);
    } break;

    case out_all: {
      error(0, "\nout_all not implemented");
    } break;

    case count_first21: {
      while (!P_io_at_eof(pads)) {
	if (P_OK == out_sum_data_line_read(pads, 0, &dline_pd, &dline)) {
	  /* do something with the data */
	  /* 	  error(0, "data line read returned OK, number of events = %d", dline.events.length); */
	  good++;
	  if (dline.events.length && Pstring_eq_cstr(&(dline.events.eventSeq[0].state), "21")) {
	    good_21++;
	  }
	} else {
	  /*	  error(2, "data line read returned: error"); */
	  bad++;
	}
      }
      error(0, "\ntest_dibbler1: good_21: %lu  tot_good: %lu  tot_bad: %lu", good_21, good, bad);
    } break;

    case out_first21: {
      error(0, "\nout_first21 not implemented");
    } break;
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

 usage:
  error(0, "\nUsage: %s <data-file> <behavior>\n\twhere behavior is one of: count_all, out_all, accum_all, count_first21, out_first21\n", argv[0]);
  return -1;
}
