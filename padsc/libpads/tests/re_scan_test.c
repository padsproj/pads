/*
 *  re_scan_test: Test  Pre_scan2 
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  P_STRING_DECL_NULL(stmp);
  P_t*          pads;
  Pio_disc_t*  io_disc;
  Pdisc_t      my_disc = Pdefault_disc;
  size_t          offset, bytes_skipped;
  int             line, f_found, try;
  unsigned long   ultmp;
  P_REGEXP_DECL_NULL(my_regexp_f);
  P_REGEXP_DECL_NULL(my_regexp_s);

  error(0, "\nUsing PADSC IO discipline nlrec\n\n");
  io_disc = P_nlrec_make(0);

  for (try = 0; try < 2; try++) {
    error(0, "\nTry using scan%d\n", try+1);

    if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
      error(ERROR_FATAL, "*** P_libopen failed ***");
    }

    if (P_ERR == P_io_fopen(pads, "../../data/re_scan_test.dat")) {
      error(ERROR_FATAL, "*** P_io_fopen failed ***");
    }

#if 0
    error(0, "XXX Changed char a into %s", P_fmt_cstr(P_RE_STRING_FROM_CHAR(pads, 'a')));
    error(0, "XXX Changed char 001 into %s", P_fmt_cstr(P_RE_STRING_FROM_CHAR(pads, '\001')));
    error(0, "XXX Changed string abc into %s", P_fmt_cstr(P_RE_STRING_FROM_CSTR(pads, "abc")));
    error(0, "XXX Changed string a001c into %s", P_fmt_cstr(P_RE_STRING_FROM_CSTR(pads, "a\001c")));

    P_STRING_INIT_LIT(stmp, "a\001c");
    error(0, "XXX length of stmp is %d", stmp.len);
    error(0, "XXX Changed string %s into %s", P_fmt_str(&stmp), P_fmt_cstr(P_RE_STRING_FROM_STR(pads, &stmp)));

    P_REGEXP_FROM_STR(pads, my_regexp_f, &stmp);
    if (!my_regexp_f.valid) { error(ERROR_FATAL, "not valid 1"); }
    P_REGEXP_FROM_CHAR(pads, my_regexp_f, 'a');
    if (!my_regexp_f.valid) { error(ERROR_FATAL, "not valid 2"); }
    P_REGEXP_FROM_CSTR(pads, my_regexp_f, "a\001c");
    if (!my_regexp_f.valid) { error(ERROR_FATAL, "not valid 2"); }
#endif

    if (P_ERR == Pregexp_compile_cstr(pads, "/[|]+/", &my_regexp_f)) {
      error(ERROR_FATAL, "** unexpected regexp compile failure **");
    }
    if (P_ERR == Pregexp_compile_cstr(pads, "/([X]+)?$/", &my_regexp_s)) {
      error(ERROR_FATAL, "** unexpected regexp compile failure **");
    }


  /*
   * XXX Process the data here XXX
   */
    for (line = 0; 1; line++) {
      if (P_io_at_eof(pads)) {
	error(0, "Main program found eof");
	break;
      }
      /* try to scan line with 2 strings term by vbar 1 string term by EOR */
      if (try == 0) {

	/* try using scan1 */

	if (P_ERR == Pre_scan1(pads, &my_regexp_f, 1, 0, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan1 did not find vbars", line);
	  goto next_line;
	}
	error(0, "line %d: scan1 found vbars at offset %d", line, offset);
	if (P_ERR == Pre_scan1(pads, &my_regexp_f, 1, 0, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan1 did not find vbars", line);
	  goto next_line;
	}
	error(0, "line %d: scan1 found vbars at offset %d", line, offset);
	if (P_ERR == Pre_scan1(pads, &my_regexp_s, 0, 0, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan1 did not find term", line);
	  goto next_line;
	}
	error(0, "line %d: scan1 found term at offset %d", line, offset);

      } else {

	/* try using scan2 */

	if (P_ERR == Pre_scan2(pads, &my_regexp_f, &my_regexp_s, 1, 0, 0, &f_found, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan2 did not find sep or term", line);
	  goto next_line;
	}
	if (f_found) {
	  error(0, "line %d: scan2 found vbars at offset %d", line, offset);
	} else {
	  error(0, "line %d: UNEXPECTED, scan2 found term at offset %d", line, offset);
	  goto next_line;
	}
	if (P_ERR == Pre_scan2(pads, &my_regexp_f, &my_regexp_s, 1, 0, 0, &f_found, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan2 did not find sep or term", line);
	  goto next_line;
	}
	if (f_found) {
	  error(0, "line %d: scan2 found vbars at offset %d", line, offset);
	} else {
	  error(0, "line %d: UNEXPECTED, scan2 found term at offset %d", line, offset);
	  goto next_line;
	}
	if (P_ERR == Pre_scan2(pads, &my_regexp_f, &my_regexp_s, 1, 0, 0, &f_found, &offset)) {
	  error(0, "line %d: UNEXPECTED, scan2 did not find sep or term", line);
	  goto next_line;
	}
	if (f_found) {
	  error(0, "line %d: UNEXPECTED scan2 found extra vbars at offset %d", line, offset);
	} else {
	  error(0, "line %d: scan2 found term at offset %d", line, offset);
	}
      }

    next_line:
      if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
	error(2, "Could not find EOR (newline), ending program");
	goto done;
      }
      ultmp = bytes_skipped;
      error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
    }

  done:
    Pstring_cleanup(pads, &stmp);
    Pregexp_cleanup(pads, &my_regexp_f);
    Pregexp_cleanup(pads, &my_regexp_s);

    if (P_ERR == P_io_close(pads)) {
      error(ERROR_FATAL, "*** P_io_close failed ***");
    }
    if (P_ERR == P_close_keep_io_disc(pads, 1)) {
      error(ERROR_FATAL, "*** P_close failed ***");
    }
  }

  P_io_disc_unmake(io_disc);

  return 0;
}
