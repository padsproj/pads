/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PSTRING_IMPL_H__
#define __PSTRING_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pstring-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * SUPPORT
 */

/* P_STRING_FROM macros */

#define P_STRING_INIT_NULL(the_pads_string) do { \
  memset((void*)(&(the_pads_string)), 0, sizeof(the_pads_string)); \
} while (0)

#define P_STRING_INIT_LIT(the_pads_string, str_lit) do { \
  (the_pads_string).str     = (char*)(str_lit); \
  (the_pads_string).len     = sizeof(str_lit)-1; \
  (the_pads_string).rbuf    = 0; \
  (the_pads_string).sharing = 1; \
} while (0)

#define P_STRING_INIT_CSTR(the_pads_string, char_ptr_expr) do { \
  char *the_pads_string_tmp = (char*)(char_ptr_expr); \
  (the_pads_string).str     = the_pads_string_tmp; \
  (the_pads_string).len     = strlen(the_pads_string_tmp); \
  (the_pads_string).rbuf    = 0; \
  (the_pads_string).sharing = 1; \
} while (0)

#define P_STRING_INIT_CSTR_LEN(the_pads_string, char_ptr_expr, length_expr) do { \
  (the_pads_string).str     = (char*)(char_ptr_expr); \
  (the_pads_string).len     = (length_expr); \
  (the_pads_string).rbuf    = 0; \
  (the_pads_string).sharing = 1; \
} while (0)


/* STRING COMPARISON */

#define Pstring_eq(str1, str2) \
  ((str1)->len == (str2)->len && strncmp((str1)->str, (str2)->str, (str1)->len) == 0)

#define Pstring_eq_cstr(PDcstr, cstr) \
  ((PDcstr)->len == strlen(cstr) && (strncmp((PDcstr)->str, (cstr), (PDcstr)->len) == 0))

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_string_FW_read(P_t *pads, const Pbase_m *m,
			     Pbase_pd *pd, Pstring *s_out,
			     Pcharset char_set, const char *whatfn, size_t width);

Perror_t PDCI_string_read(P_t *pads, const Pbase_m *m,
			  Pbase_pd *pd, Pstring *s_out,
			  Pcharset char_set, const char *whatfn, Pchar stopChar);

Perror_t PDCI_string_ME_read(P_t *pads, const Pbase_m *m,
			     Pbase_pd *pd, Pstring *s_out,
			     Pcharset char_set, const char *whatfn, const char *matchRegexp);

Perror_t PDCI_string_CME_read(P_t *pads, const Pbase_m *m,
			      Pbase_pd *pd, Pstring *s_out,
			      Pcharset char_set, const char *whatfn, Pregexp_t *matchRegexp);

Perror_t PDCI_string_SE_read(P_t *pads, const Pbase_m *m,
			     Pbase_pd *pd, Pstring *s_out,
			     Pcharset char_set, const char *whatfn, const char *stopRegexp);

Perror_t PDCI_string_CSE_read(P_t *pads, const Pbase_m *m,
			      Pbase_pd *pd, Pstring *s_out,
			      Pcharset char_set, const char *whatfn, Pregexp_t *stopRegexp);

#define Pstring_FW_read(pads, m, pd, s_out, width) \
  PDCI_string_FW_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_FW_read", width)

#define Pa_string_FW_read(pads, m, pd, s_out, width) \
  PDCI_string_FW_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_FW_read", width)

#define Pe_string_FW_read(pads, m, pd, s_out, width) \
  PDCI_string_FW_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_FW_read", width)


#define Pstring_read(pads, m, pd, s_out, stopChar) \
  PDCI_string_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_read", stopChar)

#define Pa_string_read(pads, m, pd, s_out, stopChar) \
  PDCI_string_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_read", stopChar)

#define Pe_string_read(pads, m, pd, s_out, stopChar) \
  PDCI_string_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_read", stopChar)


#define Pstring_ME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_ME_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_ME_read", matchRegexp)

#define Pa_string_ME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_ME_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_ME_read", matchRegexp)

#define Pe_string_ME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_ME_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_ME_read", matchRegexp)


#define Pstring_CME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_CME_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_CME_read", matchRegexp)

#define Pa_string_CME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_CME_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_CME_read", matchRegexp)

#define Pe_string_CME_read(pads, m, pd, s_out, matchRegexp) \
  PDCI_string_CME_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_CME_read", matchRegexp)


#define Pstring_SE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_SE_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_SE_read", stopRegexp)

#define Pa_string_SE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_SE_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_SE_read", stopRegexp)

#define Pe_string_SE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_SE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_SE_read", stopRegexp)


#define Pstring_CSE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_CSE_read(pads, m, pd, s_out, PDCI_DEF_CHARSET(pads), "Pstring_CSE_read", stopRegexp)

#define Pa_string_CSE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_CSE_read(pads, m, pd, s_out, Pcharset_ASCII, "Pa_string_CSE_read", stopRegexp)

#define Pe_string_CSE_read(pads, m, pd, s_out, stopRegexp) \
  PDCI_string_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_string_CSE_read", stopRegexp)

#endif  /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_string_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
				Pstring *s, Pcharset char_set, const char *whatfn, size_t width);

ssize_t PDCI_string_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				 Pbase_pd *pd,
				 Pstring *s, Pcharset char_set, const char *whatfn, size_t width);

ssize_t PDCI_string_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
			     Pstring *s, Pcharset char_set, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_string_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
			      Pbase_pd *pd, Pstring *s,
			      Pcharset char_set, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_string_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
				     Pstring *s, const char* tag, int indent, const char *whatfn, size_t width);

ssize_t PDCI_string_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				      Pbase_pd *pd, Pstring *s, const char* tag,
				      int indent, const char *whatfn, size_t width);

ssize_t PDCI_string_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
				  Pstring *s, const char* tag, int indent, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_string_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				   Pbase_pd *pd, Pstring *s,
				   const char* tag, int indent, const char *inv_type, const char *whatfn, ...);

#define Pstring_FW_write2io(pads, io, pd, s, width) \
  PDCI_string_FW_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_FW_write2io", width)

#define Pa_string_FW_write2io(pads, io, pd, s, width) \
  PDCI_string_FW_write2io(pads, io, pd, s, Pcharset_ASCII, "Pa_string_FW_write2io", width)

#define Pe_string_FW_write2io(pads, io, pd, s, width) \
  PDCI_string_FW_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pe_string_FW_write2io", width)

#define Pstring_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, width) \
  PDCI_string_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_FW_write2buf", width)

#define Pa_string_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, width) \
  PDCI_string_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pa_string_FW_write2buf", width)

#define Pe_string_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, width) \
  PDCI_string_FW_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pe_string_FW_write2buf", width)

#define Pstring_write2io(pads, io, pd, s, stopChar) \
  PDCI_string_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring", "Pstring_write2io", stopChar)

#define Pa_string_write2io(pads, io, pd, s, stopChar) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_ASCII, "Pstring", "Pa_string_write2io", stopChar)

#define Pe_string_write2io(pads, io, pd, s, stopChar) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pstring", "Pe_string_write2io", stopChar)

#define Pstring_write2buf(pads, buf, buf_len, buf_full, pd, s, stopChar) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring", "Pstring_write2buf", stopChar)

#define Pa_string_write2buf(pads, buf, buf_len, buf_full, pd, s, stopChar) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pstring", "Pa_string_write2buf", stopChar)

#define Pe_string_write2buf(pads, buf, buf_len, buf_full, pd, s, stopChar) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pstring", "Pe_string_write2buf", stopChar)

#define Pstring_ME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_ME", "Pstring_ME_write2io", matchRegexp)

#define Pa_string_ME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_ASCII, "Pstring_ME", "Pa_string_ME_write2io", matchRegexp)

#define Pe_string_ME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pstring_ME", "Pe_string_ME_write2io", matchRegexp)

#define Pstring_ME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_ME", "P_ME_string_write2buf", matchRegexp)

#define Pa_string_ME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pstring_ME", "Pa_string_ME_write2buf", matchRegexp)

#define Pe_string_ME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pstring_ME", "Pe_string_ME_write2buf", matchRegexp)

#define Pstring_CME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_CME", "Pstring_CME_write2io", matchRegexp)

#define Pa_string_CME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_ASCII, "Pstring_CME", "Pa_string_CME_write2io", matchRegexp)

#define Pe_string_CME_write2io(pads, io, pd, s, matchRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pstring_CME", "Pe_string_CME_write2io", matchRegexp)

#define Pstring_CME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_CME", "P_CME_string_write2buf", matchRegexp)

#define Pa_string_CME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pstring_CME", "Pa_string_CME_write2buf", matchRegexp)

#define Pe_string_CME_write2buf(pads, buf, buf_len, buf_full, pd, s, matchRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pstring_CME", "Pe_string_CME_write2buf", matchRegexp)

#define Pstring_SE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_SE", "Pstring_SE_write2io", stopRegexp)

#define Pa_string_SE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_ASCII, "Pstring_SE", "Pa_string_SE_write2io", stopRegexp)

#define Pe_string_SE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pstring_SE", "Pe_string_SE_write2io", stopRegexp)

#define Pstring_SE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_SE", "P_SE_string_write2buf", stopRegexp)

#define Pa_string_SE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pstring_SE", "Pa_string_SE_write2buf", stopRegexp)

#define Pe_string_SE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pstring_SE", "Pe_string_SE_write2buf", stopRegexp)

#define Pstring_CSE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_CSE", "Pstring_CSE_write2io", stopRegexp)

#define Pa_string_CSE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_ASCII, "Pstring_CSE", "Pa_string_CSE_write2io", stopRegexp)

#define Pe_string_CSE_write2io(pads, io, pd, s, stopRegexp) \
  PDCI_string_write2io(pads, io, pd, s, Pcharset_EBCDIC, "Pstring_CSE", "Pe_string_CSE_write2io", stopRegexp)

#define Pstring_CSE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, PDCI_DEF_CHARSET(pads), "Pstring_CSE", "P_CSE_string_write2buf", stopRegexp)

#define Pa_string_CSE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_ASCII, "Pstring_CSE", "Pa_string_CSE_write2buf", stopRegexp)

#define Pe_string_CSE_write2buf(pads, buf, buf_len, buf_full, pd, s, stopRegexp) \
  PDCI_string_write2buf(pads, buf, buf_len, buf_full, pd, s, Pcharset_EBCDIC, "Pstring_CSE", "Pe_string_CSE_write2buf", stopRegexp)

#define Pstring_FW_write_xml_2io(pads, io, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring_FW_write_xml_2io", width)

#define Pa_string_FW_write_xml_2io(pads, io, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2io(pads, io, pd, s, tag, indent, "Pa_string_FW_write_xml_2io", width)

#define Pe_string_FW_write_xml_2io(pads, io, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2io(pads, io, pd, s, tag, indent, "Pe_string_FW_write_xml_2io", width)

#define Pstring_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_FW_write_xml_2buf", width)

#define Pa_string_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pa_string_FW_write_xml_2buf", width)

#define Pe_string_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, width) \
  PDCI_string_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pe_string_FW_write_xml_2buf", width)

#define Pstring_write_xml_2io(pads, io, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring", "Pstring_write_xml_2io", stopChar)

#define Pa_string_write_xml_2io(pads, io, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring", "Pa_string_write_xml_2io", stopChar)

#define Pe_string_write_xml_2io(pads, io, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring", "Pe_string_write_xml_2io", stopChar)

#define Pstring_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring", "Pstring_write_xml_2buf", stopChar)

#define Pa_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring", "Pa_string_write_xml_2buf", stopChar)

#define Pe_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopChar) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring", "Pe_string_write_xml_2buf", stopChar)

#define Pstring_ME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring_ME", "Pstring_ME_write_xml_2io", matchRegexp)

#define Pa_string_ME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_ASCII, tag, indent, "Pstring_ME", "Pa_string_ME_write_xml_2io", matchRegexp)

#define Pe_string_ME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_EBCDIC, tag, indent, "Pstring_ME", "Pe_string_ME_write_xml_2io", matchRegexp)

#define Pstring_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_ME", "P_ME_string_write_xml_2buf", matchRegexp)

#define Pa_string_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_ME", "Pa_string_ME_write_xml_2buf", matchRegexp)

#define Pe_string_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_ME", "Pe_string_ME_write_xml_2buf", matchRegexp)

#define Pstring_CME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring_CME", "Pstring_CME_write_xml_2io", matchRegexp)

#define Pa_string_CME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_ASCII, tag, indent, "Pstring_CME", "Pa_string_CME_write_xml_2io", matchRegexp)

#define Pe_string_CME_write_xml_2io(pads, io, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_EBCDIC, tag, indent, "Pstring_CME", "Pe_string_CME_write_xml_2io", matchRegexp)

#define Pstring_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CME", "P_CME_string_write_xml_2buf", matchRegexp)

#define Pa_string_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CME", "Pa_string_CME_write_xml_2buf", matchRegexp)

#define Pe_string_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, matchRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CME", "Pe_string_CME_write_xml_2buf", matchRegexp)

#define Pstring_SE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring_SE", "Pstring_SE_write_xml_2io", stopRegexp)

#define Pa_string_SE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_ASCII, tag, indent, "Pstring_SE", "Pa_string_SE_write_xml_2io", stopRegexp)

#define Pe_string_SE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_EBCDIC, tag, indent, "Pstring_SE", "Pe_string_SE_write_xml_2io", stopRegexp)

#define Pstring_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_SE", "P_SE_string_write_xml_2buf", stopRegexp)

#define Pa_string_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_SE", "Pa_string_SE_write_xml_2buf", stopRegexp)

#define Pe_string_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_SE", "Pe_string_SE_write_xml_2buf", stopRegexp)

#define Pstring_CSE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, tag, indent, "Pstring_CSE", "Pstring_CSE_write_xml_2io", stopRegexp)

#define Pa_string_CSE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_ASCII, tag, indent, "Pstring_CSE", "Pa_string_CSE_write_xml_2io", stopRegexp)

#define Pe_string_CSE_write_xml_2io(pads, io, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2io(pads, io, pd, s, Pcharset_EBCDIC, tag, indent, "Pstring_CSE", "Pe_string_CSE_write_xml_2io", stopRegexp)

#define Pstring_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CSE", "P_CSE_string_write_xml_2buf", stopRegexp)

#define Pa_string_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CSE", "Pa_string_CSE_write_xml_2buf", stopRegexp)

#define Pe_string_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, stopRegexp) \
  PDCI_string_write_xml_2buf(pads, buf, buf_len, buf_full, pd, s, tag, indent, "Pstring_CSE", "Pe_string_CSE_write_xml_2buf", stopRegexp)

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PSTRING_IMPL_H__   */
