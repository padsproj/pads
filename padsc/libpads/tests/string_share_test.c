/*
 *  libtest1: Test fixed width ascii read functions
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  Pstring         s1, s2, s3, s4, s5, s6;
  Pstring        *str1, *str2, *str3;
  P_t*            pads;
  Pio_disc_t*     io_disc;
  Pbase_m         m = P_CheckAndSet;
  Pbase_pd        pd;
  size_t          bytes_skipped;
  unsigned long   ultmp;
  Pregexp_t      *my_regexp;
  int             ctr = 0;
  int             norec = 0; 
  Pchar           lit;

  if (argc != 2) {
    goto usage;
  }

  if (strcmp(argv[1], "fwrec") == 0) {
    io_disc = P_fwrec_make(0, 20, 1);
  } else if (strcmp(argv[1], "nlrec") == 0) {
    io_disc = P_nlrec_make(21);
  } else if (strcmp(argv[1], "norec") == 0) {
    io_disc = P_norec_make(21);
    norec = 1;
  } else if (strcmp(argv[1], "fwrec_noseek") == 0) {
    io_disc = P_fwrec_noseek_make(0, 20, 1); /* 4 6-char ints, newline */ 
  } else if (strcmp(argv[1], "nlrec_noseek") == 0) {
    io_disc = P_nlrec_noseek_make(21);
  } else if (strcmp(argv[1], "norec_noseek") == 0) {
    io_disc = P_norec_noseek_make(21);
    norec = 1;
  } else {
    goto usage;
  }
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline %s", argv[1]);
  } else {
    error(0, "\nInstalled IO discipline %s block size 21", argv[1]);
  }

  if (P_ERR == P_libopen(&pads, 0, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.string_share_test")) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  if (norec) {
    if (P_ERR == Pregexp_compile(pads, "/[X\n]/", &my_regexp)) {
      error(2, "** unexpected regexp compile failure **");
      return -1;
    }
  } else {
    if (P_ERR == Pregexp_compile(pads, "/[X]|$/", &my_regexp)) {
      error(2, "** unexpected regexp compile failure **");
      return -1;
    }
  }

  Pstring_init(pads, &s1);
  Pstring_init(pads, &s2);
  Pstring_init(pads, &s3);
  Pstring_init(pads, &s4);
  Pstring_init(pads, &s5);
  Pstring_init(pads, &s6);

  /*
   * XXX Process the data here XXX
   */

  /* XXX_REMOVE */   /* P_io_checkpoint(pads, 0);   */
  /* XXX_REMOVE */   /* pads->disc->copy_strings = 1; */
  while (1) {
    if (ctr % 10 == 0) {
      str1 = &s1;
      str2 = &s2;
      str3 = &s3;
    } else {
      str1 = &s4;
      str2 = &s5;
      str3 = &s6;
    }
    ctr++;
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }
    /* try to read line with 2 strings term by vbar 1 string term by EOR */
    if (P_ERR == Pa_string_read(pads, &m, '|', &pd, str1)) {
      goto find_EOR;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(str1), str1->len);
    }
    if (P_ERR == Pa_char_lit_read(pads, &m, '|', &pd, &lit)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR;
    }
    if (P_ERR == Pa_string_read(pads, &m, '|', &pd, str2)) {
      goto find_EOR;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(str2), str2->len);
    }
    if (P_ERR == Pa_char_lit_read(pads, &m, '|', &pd, lit)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR;
    }
    if (P_ERR == Pa_string_CSE_read(pads, &m, my_regexp, &pd, str3)) {
      break;
    } else {
      error(0, "Read string term by EOR(newline) or X : %s (length %d)", P_fmt_str(str3), str3->len);
    }
  find_EOR:
    if (norec) {
      if (P_ERR == Pa_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) {
	error(2, "Could not find EOR (newline), ending program");
	goto done;
      }
    } else {
      if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
	error(2, "Could not find EOR (newline), ending program");
	goto done;
      }
    }
    ultmp = bytes_skipped;
    error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
  }
  /* XXX_REMOVE */ /* P_io_commit(pads); */

 done:
  Pstring_cleanup(pads, &s1);
  Pstring_cleanup(pads, &s2);
  Pstring_cleanup(pads, &s3);

  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    return -1;
  }

  Pstring_cleanup(pads, &s4);
  Pstring_cleanup(pads, &s5);
  Pstring_cleanup(pads, &s6);

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    return -1;
  }

  return 0;

 usage:
  error(2, "\nUsage: %s <io-disc-name>\n\n\twhere <io-disc-name> is one of: fwrec, nlrec, norec, fwrec_noseek, nlrec_noseek, norec_noseek\n", argv[0]);
  return -1;
}
