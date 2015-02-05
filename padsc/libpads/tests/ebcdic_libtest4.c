/*
 * ebcdic_libtest4: 
 *
 *    tests:
 *        io discipline ctrec_noseek(P_EBCDIC_NEWLINE)
 *        Pe_string_read
 *        Pe_char_lit_match
 *        Pe_string_CSE_read
 *        Pe_string_FW_read 
 *        Pe_string_SE_read
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  Pchar          cfound;
  Pstring        s;
  P_t*           pads;
  Pio_disc_t*    io_disc;
  Pdisc_t        my_disc = Pdefault_disc;
  Pbase_m        m       = P_CheckAndSet;
  Pbase_pd       pd;
  size_t         bytes_skipped;
  unsigned long  ultmp;
  P_REGEXP_DECL_NULL(my_regexp);

  error(0, "\nUsing PADSC IO discipline ctrec with cterm P_EBCDIC_NEWLINE\n\n");
  io_disc = P_ctrec_noseek_make(P_EBCDIC_NEWLINE, 0);

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.libtest4.ebcdic")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  if (P_ERR == Pregexp_compile_cstr(pads, "/[X]|$/", &my_regexp)) {
    error(2, "** unexpected regexp compile failure **");
    exit(-1);
  }

  Pstring_init(pads, &s);

  /*
   * XXX Process the data here XXX
   */
  while (1) {
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }
    /* try to read line with 2 strings term by vbar 1 string term by EOR */
    if (P_ERR == Pe_string_read(pads, &m, &pd, &s, '|')) {
      goto find_EOR1;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(&s), s.len);
    }
    if (P_ERR == Pe_char_lit_match(pads, '|', 1)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR1;
    }
    if (P_ERR == Pe_string_read(pads, &m, &pd, &s, '|')) {
      goto find_EOR1;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(&s), s.len);
    }
    if (P_ERR == Pe_char_lit_match(pads, '|', 1)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR1;
    }
    if (P_ERR == Pe_string_CSE_read(pads, &m, &pd, &s, &my_regexp)) {
      break;
    } else {
      error(0, "Read string term by EOR or X : %s (length %d)", P_fmt_str(&s), s.len);
    }
  find_EOR1:
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      error(2, "Could not find EOR (newline), ending program");
      goto done;
    }
    ultmp = bytes_skipped;
    error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }

    /* try to read line with 2 strings term by vbar 1 string term by EOR */
    if (P_ERR == Pe_string_FW_read(pads, &m, &pd, &s, 4)) {
      goto find_EOR2;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(&s), s.len);
    }
    if (P_ERR == Pe_char_lit_match(pads, '|', 1)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR2;
    }
    if (P_ERR == Pe_string_read(pads, &m, &pd, &s, '|')) {
      goto find_EOR2;
    } else {
      error(0, "Read string term by vbar: %s (length %d)", P_fmt_str(&s), s.len);
    }
    if (P_ERR == Pe_char_lit_read(pads, &m, '|', &pd, &cfound)) {
      PDCI_report_err (pads, 0, &pd.loc, pd.errCode, 0, 0);
      goto find_EOR2;
    }
    if (P_ERR == Pe_string_SE_read(pads, &m, &pd, &s, "/[X]|$/")) {
      break;
    } else {
      error(0, "Read string term by EOR or X : %s (length %d)", P_fmt_str(&s), s.len);
    }
  find_EOR2:
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      error(2, "Could not find EOR (newline), ending program");
      goto done;
    }
    ultmp = bytes_skipped;
    error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
  }

 done:
  Pstring_cleanup(pads, &s);
  Pregexp_cleanup(pads, &my_regexp);

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
