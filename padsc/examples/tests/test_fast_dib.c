#include "dibbler2.h"

#define FASTEST 1

typedef enum behave_e { count_first21, out_first21 } behave;

const char * behave_descr[] = {
  "count_first21",
  "out_first21"
 };

int main(int argc, char** argv) {
  P_t                    *pads;
  Pio_disc_t            *io_disc;
  out_sum_header           header;
  out_sum_fixed1           f1;
  out_sum_fixed1_pd        f1_pd;
  event                    ev;
  event_pd                 ev_pd;
  size_t                   bytes_skipped;
  char                     *fname          = "../../data/dibbler1";
  behave                   b               = count_first21;
  unsigned long            good_21         = 0, good = 0, bad = 0;
  /* out_sum_fixed1_m         f1_m           = { 0 }; */
  out_sum_fixed1_m         f1_m            = {P_Ignore,{P_Ignore,P_Ignore},{P_Ignore,P_Ignore},{{P_Ignore,P_Ignore},{P_Ignore,P_Ignore}},{{P_Ignore,P_Ignore},{P_Ignore,P_Ignore}},{P_Ignore,P_Ignore},{{P_Ignore,P_Ignore},{P_Ignore,P_Ignore}},{{P_Ignore,P_Ignore},{P_Ignore,P_Ignore}}};

  if (argc > 3) {
    goto usage;
  }
  if (argc >= 2 ) {
    fname = argv[1];
  }
#ifndef FASTEST
  if (argc == 3 ) {
    if (strcmp(argv[2], "count_first21") == 0) {
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
    case count_first21: {
      while (!P_io_at_eof(pads)) {
	if (P_OK == out_sum_fixed1_read(pads, &f1_m, &f1_pd, &f1)) {
	  if (P_OK == event_read(pads, 0, &ev_pd, &ev)) {
	    good++;
	    if (Pstring_eq_cstr(&(ev.state), "21")) {
	      good_21++;
	    } else {
	      /*	      error(0, "first state = %.*s", ev.state.len, ev.state.str); */
	    }
	  } else {
	    bad++;
	  }
	} else {
	  /*	  error(2, "data line read returned: error"); */
	  bad++;
	}
	if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
#ifndef FASTEST
	  error(2, "Could not find EOR (newline), ending program");
#endif
	  break;
	}
      }
      error(0, "\ntest_fast_dib: good_21: %lu  tot_good: %lu  tot_bad: %lu", good_21, good, bad);
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
  error(0, "\nUsage: %s <data-file> <behavior>\n\twhere behavior is one of: count_first21, out_first21\n", argv[0]);
  return -1;
}
