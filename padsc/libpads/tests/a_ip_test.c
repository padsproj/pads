/*
 *  a_ip_test: Test Pa_ip_read
 */

#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  P_t*            pads;
  Pio_disc_t*     io_disc;
  Pbase_m         m = P_CheckAndSet;
  Pbase_pd        pd;
  size_t          bytes_skipped;
  unsigned long   ultmp;
  Puint32         addr;
  int             i;
  Pchar           lit;

  error(0, "\nUsing PADSC IO discipline nlrec\n\n");
  io_disc = P_nlrec_make(0);

  if (P_ERR == P_libopen(&pads, 0, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.a_ip_test")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * XXX Process the data here XXX
   */
  while (1) {
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }
    /* try to read line with 1 ip address term by vbar, 1 ip address term by EOR */
    if (P_ERR == Pa_ip_read(pads, &m, &pd, &addr)) {
      if (pd.errCode != P_INVALID_DATE) {
	goto find_EOR;
      }
    } else {
      error(ERROR_PROMPT, "Read IP address term by vbar: ");
      for (i = 1; i <= 4; i++) {
	error(ERROR_PROMPT, "%d.", P_IP_PART(addr, i));
      }
      error(0, " (Puint32 = %u)", addr);
    }
    if (P_ERR == Pa_char_lit_read(pads, &m, '|', &pd, &lit)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR;
    }
    if (P_ERR == Pa_ip_read(pads, &m, &pd, &addr)) {
      if (pd.errCode != P_INVALID_DATE) {
	goto find_EOR;
      }
    } else {
      error(ERROR_PROMPT, "Read date term by NULL: ");
      for (i = 1; i <= 4; i++) {
	error(ERROR_PROMPT, "%d.", P_IP_PART(addr, i));
      }
      error(0, " (Puint32 = %u)", addr);
    }
  find_EOR:
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      error(2, "Could not find EOR (newline), ending program");
      goto done;
    }
    ultmp = bytes_skipped;
    error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
  }

 done:

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
