/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PRE_IMPL_H__
#define __PRE_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pre-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * SUPPORT
 */

#define P_REGEXP_DECL_NULL(my_regexp) \
  Pregexp_t my_regexp = { 0 }

#define P_RE_STRING_FROM_CHAR(pads, char_expr) \
  ( PDCI_sfstr_seek2zero((pads)->tmp2),	   \
    sfprintf((pads)->tmp2, "/[%c]/", (char_expr)), \
    PDCI_sfstr_use((pads)->tmp2) )

#define P_RE_STRING_FROM_STR(pads, str_expr) \
  ( (pads)->tmp2_pstr = (str_expr), 		\
    PDCI_sfstr_seek2zero((pads)->tmp2),	\
    sfprintf((pads)->tmp2, "/%.*s/l", (pads)->tmp2_pstr->len, (pads)->tmp2_pstr->str), \
    PDCI_sfstr_use((pads)->tmp2) )

#define P_RE_STRING_FROM_CSTR(pads, str_expr) \
  ( PDCI_sfstr_seek2zero((pads)->tmp2),	 \
    sfprintf((pads)->tmp2, "/%s/l", (str_expr)), \
    PDCI_sfstr_use((pads)->tmp2) )

#define PDCI_REGEXP_FROM_CHAR(pads, my_regexp, char_expr, err_prefix, whatfn) \
  PDCI_regexp_compile_cstr(pads, P_RE_STRING_FROM_CHAR(pads, char_expr), &(my_regexp), err_prefix, whatfn)

#define PDCI_REGEXP_FROM_STR(pads, my_regexp, str_expr, err_prefix, whatfn) \
  PDCI_regexp_compile_cstr(pads, P_RE_STRING_FROM_STR(pads, str_expr), &(my_regexp), err_prefix, whatfn)

#define PDCI_REGEXP_FROM_CSTR(pads, my_regexp, str_expr, err_prefix, whatfn) \
  PDCI_regexp_compile_cstr(pads, P_RE_STRING_FROM_CSTR(pads, str_expr), &(my_regexp), err_prefix, whatfn)

#define P_REGEXP_FROM_CHAR(pads, my_regexp, char_expr) \
  PDCI_REGEXP_FROM_CHAR(pads, my_regexp, char_expr, "", "P_REGEXP_FROM_CHAR")

#define P_REGEXP_FROM_STR(pads, my_regexp, str_expr) \
  PDCI_REGEXP_FROM_STR(pads, my_regexp, str_expr, "", "P_REGEXP_FROM_STR")

#define P_REGEXP_FROM_CSTR(pads, my_regexp, str_expr) \
  PDCI_REGEXP_FROM_CSTR(pads, my_regexp, str_expr, "", "P_REGEXP_FROM_CSTR")

#define Pregexp_compile(pads, regexp_str, regexp) \
  PDCI_regexp_compile(pads, regexp_str, regexp, "", "Pregexp_compile")

#define Pregexp_compile_cstr(pads, regexp_str, regexp) \
  PDCI_regexp_compile_cstr(pads, regexp_str, regexp, "", "Pregexp_compile_cstr")

#define Pregexp_cleanup(pads, regexp) \
  PDCI_regexp_cleanup(pads, regexp, "Pregexp_cleanup")


/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_re_scan1(P_t *pads, Pregexp_t *f,
		       int eat_f, int panic,
		       size_t *offset_out, Pcharset char_set,
		       const char *whatfn);

Perror_t PDCI_re_scan2(P_t *pads, Pregexp_t *f, Pregexp_t *s,
		       int eat_f, int eat_s, int panic,
		       int *f_found_out, size_t *offset_out, Pcharset char_set,
		       const char *whatfn);

Perror_t PDCI_re_match(P_t *pads, Pregexp_t *f, int eat_f, Pcharset char_set, const char *whatfn);

Perror_t PDCI_cstr_re_match(P_t *pads, const char *f, int eat_f, Pcharset char_set, const char *whatfn);

#define Pre_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_re_scan1(pads, f, eat_f, panic, offset_out, PDCI_DEF_CHARSET(pads), "Pre_scan1")

#define Pa_re_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_re_scan1(pads, f, eat_f, panic, offset_out, Pcharset_ASCII, "Pa_re_scan1")

#define Pe_re_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_re_scan1(pads, f, eat_f, panic, offset_out, Pcharset_EBCDIC, "Pe_re_scan1")


#define Pre_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_re_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, PDCI_DEF_CHARSET(pads), "Pre_scan2")

#define Pa_re_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_re_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, Pcharset_ASCII, "Pa_re_scan2")

#define Pe_re_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_re_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, Pcharset_EBCDIC, "Pe_re_scan2")

#define Pre_match(pads, f, eat_f) \
  PDCI_re_match(pads, f, eat_f, PDCI_DEF_CHARSET(pads), "Pre_match")

#define Pa_re_match(pads, f, eat_f) \
  PDCI_re_match(pads, f, eat_f, Pcharset_ASCII, "Pa_re_match")

#define Pe_re_match(pads, f, eat_f) \
  PDCI_re_match(pads, f, eat_f, Pcharset_EBCDIC, "Pe_re_match")

#define Pcstr_re_match(pads, f, eat_f) \
  PDCI_cstr_re_match(pads, f, eat_f, PDCI_DEF_CHARSET(pads), "Pre_match")

#define Pa_cstr_re_match(pads, f, eat_f) \
  PDCI_cstr_re_match(pads, f, eat_f, Pcharset_ASCII, "Pa_re_match")

#define Pe_cstr_re_match(pads, f, eat_f) \
  PDCI_cstr_re_match(pads, f, eat_f, Pcharset_EBCDIC, "Pe_re_match")

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PRE_IMPL_H__   */
