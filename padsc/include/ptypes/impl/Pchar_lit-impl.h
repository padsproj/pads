/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCHAR_LIT_IMPL_H__
#define __PCHAR_LIT_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pchar_lit-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_char_lit_scan1(P_t *pads, Pchar f, int eat_f, int panic,
			     size_t *offset_out, Pcharset char_set,
			     const char *whatfn);

Perror_t PDCI_char_lit_scan2(P_t *pads, Pchar f, Pchar s, int eat_f, int eat_s, int panic,
			     int *f_found_out, size_t *offset_out, Pcharset char_set,
			     const char *whatfn);

Perror_t PDCI_char_lit_match(P_t *pads, Pchar f, int eat_f, Pcharset char_set, const char *whatfn);


Perror_t PDCI_char_lit_read(P_t *pads, const Pbase_m *m, Pchar c, Pbase_pd *pd, Pchar *c_out,
			    Pcharset char_set, const char* whatfn);

#define Pchar_lit_scan1(pads, c, eat_c, panic, offset_out) \
  PDCI_char_lit_scan1(pads, c, eat_c, panic, offset_out, PDCI_DEF_CHARSET(pads), "Pchar_lit_scan1")

#define Pa_char_lit_scan1(pads, c, eat_c, panic, offset_out) \
  PDCI_char_lit_scan1(pads, c, eat_c, panic, offset_out, Pcharset_ASCII, "Pa_char_lit_scan1")

#define Pe_char_lit_scan1(pads, c, eat_c, panic, offset_out) \
  PDCI_char_lit_scan1(pads, c, eat_c, panic, offset_out, Pcharset_EBCDIC, "Pe_char_lit_scan1")

#define Pchar_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out) \
  PDCI_char_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out, PDCI_DEF_CHARSET(pads), "Pchar_lit_scan2")

#define Pa_char_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out) \
  PDCI_char_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out, Pcharset_ASCII, "Pa_char_lit_scan2")

#define Pe_char_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out) \
  PDCI_char_lit_scan2(pads, c, s, eat_c, eat_s, panic, f_found_out, offset_out, Pcharset_EBCDIC, "Pe_char_lit_scan2")

#define Pchar_lit_match(pads, c, eat_c) \
  PDCI_char_lit_match(pads, c, eat_c, PDCI_DEF_CHARSET(pads), "Pchar_lit_match")

#define Pa_char_lit_match(pads, c, eat_c) \
  PDCI_char_lit_match(pads, c, eat_c, Pcharset_ASCII, "Pa_char_lit_match")

#define Pe_char_lit_match(pads, c, eat_c) \
  PDCI_char_lit_match(pads, c, eat_c, Pcharset_EBCDIC, "Pe_char_lit_match")

#define Pchar_lit_read(pads, m, c, pd, c_out) \
  PDCI_char_lit_read(pads, m, c, pd, c_out, PDCI_DEF_CHARSET(pads), "Pchar_lit_read")

#define Pa_char_lit_read(pads, m, c, pd, c_out) \
  PDCI_char_lit_read(pads, m, c, pd, c_out, Pcharset_ASCII, "Pa_char_lit_read")

#define Pe_char_lit_read(pads, m, c, pd, c_out) \
  PDCI_char_lit_read(pads, m, c, pd, c_out, Pcharset_EBCDIC, "Pe_char_lit_read")

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

#endif /* P_CONFIG_WRITE_FUNCTIONS */

ssize_t PDCI_char_lit_write2io(P_t *pads, Sfio_t *io, Pchar c,
			       Pcharset char_set, const char *whatfn);

ssize_t PDCI_char_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, Pchar c,
				Pcharset char_set, const char *whatfn);

ssize_t PDCI_char_lit_write_xml_2io(P_t *pads, Sfio_t *io, Pchar c,
				    const char *tag, int indent, const char *whatfn);

ssize_t PDCI_char_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, Pchar c,
				     const char *tag, int indent, const char *whatfn);

#define Pa_char_lit_write2io(pads, io, c) \
  PDCI_char_lit_write2io(pads, io, c, Pcharset_ASCII, "Pa_char_lit_write2io")

#define Pe_char_lit_write2io(pads, io, c) \
  PDCI_char_lit_write2io(pads, io, c, Pcharset_EBCDIC, "Pe_char_lit_write2io")

#define Pchar_lit_write2io(pads, io, c) \
  PDCI_char_lit_write2io(pads, io, c, PDCI_DEF_CHARSET(pads), "Pchar_lit_write2io")

#define Pa_char_lit_write2buf(pads, buf, buf_len, buf_full, c) \
  PDCI_char_lit_write2buf(pads, buf, buf_len, buf_full, c, Pcharset_ASCII, "Pa_char_lit_write2buf")

#define Pe_char_lit_write2buf(pads, buf, buf_len, buf_full, c) \
  PDCI_char_lit_write2buf(pads, buf, buf_len, buf_full, c, Pcharset_EBCDIC, "Pe_char_lit_write2buf")

#define Pchar_lit_write2buf(pads, buf, buf_len, buf_full, c) \
  PDCI_char_lit_write2buf(pads, buf, buf_len, buf_full, c, PDCI_DEF_CHARSET(pads), "Pchar_lit_write2buf")

#define Pa_char_lit_write_xml_2io(pads, io, c, tag, indent) \
  PDCI_char_lit_write_xml_2io(pads, io, c, tag, indent, "Pa_char_lit_write_xml_2io")

#define Pe_char_lit_write_xml_2io(pads, io, c, tag, indent) \
  PDCI_char_lit_write_xml_2io(pads, io, c, tag, indent, "Pe_char_lit_write_xml_2io")

#define Pchar_lit_write_xml_2io(pads, io, c, tag, indent) \
  PDCI_char_lit_write_xml_2io(pads, io, c, tag, indent, "Pchar_lit_write_xml_2io")

#define Pa_char_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent) \
  PDCI_char_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent, "Pa_char_lit_write_xml_2buf")

#define Pe_char_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent) \
  PDCI_char_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent, "Pe_char_lit_write_xml_2buf")

#define Pchar_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent) \
  PDCI_char_lit_write_xml_2buf(pads, buf, buf_len, buf_full, c, tag, indent, "Pchar_lit_write_xml_2buf")

#endif  /*  __PCHAR_LIT_IMPL_H__   */
