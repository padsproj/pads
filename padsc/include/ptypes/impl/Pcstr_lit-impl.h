/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCSTR_LIT_IMPL_H__
#define __PCSTR_LIT_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pcstr_lit-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_cstr_lit_scan1(P_t *pads, const char *f,
			     int eat_f, int panic,
			     size_t *offset_out, Pcharset char_set,
			     const char *whatfn);

Perror_t PDCI_cstr_lit_scan2(P_t *pads, const char *f, const char *s,
			     int eat_f, int eat_s, int panic,
			     int *f_found_out, size_t *offset_out, Pcharset char_set,
			     const char *whatfn);

Perror_t PDCI_cstr_lit_match(P_t *pads, const char *f, int eat_f, Pcharset char_set, const char *whatfn);

Perror_t PDCI_cstr_lit_read(P_t *pads, const Pbase_m *m, const char *s, Pbase_pd *pd, Pstring *s_out,
			    Pcharset char_set, const char *whatfn);

#define Pcstr_lit_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_cstr_lit_scan1(pads, f, eat_f, panic, offset_out, PDCI_DEF_CHARSET(pads), "Pcstr_lit_scan1")

#define Pa_cstr_lit_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_cstr_lit_scan1(pads, f, eat_f, panic, offset_out, Pcharset_ASCII, "Pa_cstr_lit_scan1")

#define Pe_cstr_lit_scan1(pads, f, eat_f, panic, offset_out) \
  PDCI_cstr_lit_scan1(pads, f, eat_f, panic, offset_out, Pcharset_EBCDIC, "Pe_cstr_lit_scan1")

#define Pcstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_cstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, PDCI_DEF_CHARSET(pads), "Pcstr_lit_scan2")

#define Pa_cstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_cstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, Pcharset_ASCII, "Pa_cstr_lit_scan2")

#define Pe_cstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out) \
  PDCI_cstr_lit_scan2(pads, f, s, eat_f, eat_s, panic, f_found_out, offset_out, Pcharset_EBCDIC, "Pe_cstr_lit_scan2")

#define Pcstr_lit_match(pads, f, eat_f) \
  PDCI_cstr_lit_match(pads, f, eat_f, PDCI_DEF_CHARSET(pads), "Pcstr_lit_match")

#define Pa_cstr_lit_match(pads, f, eat_f) \
  PDCI_cstr_lit_match(pads, f, eat_f, Pcharset_ASCII, "Pa_cstr_lit_match")

#define Pe_cstr_lit_match(pads, f, eat_f) \
  PDCI_cstr_lit_match(pads, f, eat_f, Pcharset_EBCDIC, "Pe_cstr_lit_match")

#define Pcstr_lit_read(pads, m, s, pd, s_out) \
  PDCI_cstr_lit_read(pads, m, s, pd, s_out, PDCI_DEF_CHARSET(pads), "Pcstr_lit_read")

#define Pa_cstr_lit_read(pads, m, s, pd, s_out) \
  PDCI_cstr_lit_read(pads, m, s, pd, s_out, Pcharset_ASCII, "Pa_cstr_lit_read")

#define Pe_cstr_lit_read(pads, m, s, pd, s_out) \
  PDCI_cstr_lit_read(pads, m, s, pd, s_out, Pcharset_EBCDIC, "Pe_cstr_lit_read")

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_cstr_lit_write2io(P_t *pads, Sfio_t *io, const char *s,
			       Pcharset char_set, const char *whatfn);

ssize_t PDCI_cstr_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, const char *s,
				Pcharset char_set, const char *whatfn);

ssize_t PDCI_cstr_lit_write_xml_2io(P_t *pads, Sfio_t *io, const char *s,
				    const char *tag, int indent, const char *whatfn);

ssize_t PDCI_cstr_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, const char *s,
				     const char *tag, int indent, const char *whatfn);

#define Pa_cstr_lit_write2io(pads, io, s) \
  PDCI_cstr_lit_write2io(pads, io, s, Pcharset_ASCII, "Pa_cstr_lit_write2io")

#define Pe_cstr_lit_write2io(pads, io, s) \
  PDCI_cstr_lit_write2io(pads, io, s, Pcharset_EBCDIC, "Pe_cstr_lit_write2io")

#define Pcstr_lit_write2io(pads, io, s) \
  PDCI_cstr_lit_write2io(pads, io, s, PDCI_DEF_CHARSET(pads), "Pcstr_lit_write2io")

#define Pa_cstr_lit_write2buf(pads, buf, buf_len, buf_full, s) \
  PDCI_cstr_lit_write2buf(pads, buf, buf_len, buf_full, s, Pcharset_ASCII, "Pa_cstr_lit_write2buf")

#define Pe_cstr_lit_write2buf(pads, buf, buf_len, buf_full, s) \
  PDCI_cstr_lit_write2buf(pads, buf, buf_len, buf_full, s, Pcharset_EBCDIC, "Pe_cstr_lit_write2buf")

#define Pcstr_lit_write2buf(pads, buf, buf_len, buf_full, s) \
  PDCI_cstr_lit_write2buf(pads, buf, buf_len, buf_full, s, PDCI_DEF_CHARSET(pads), "Pcstr_lit_write2buf")

#define Pa_cstr_lit_write_xml_2io(pads, io, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2io(pads, io, s, tag, indent, "Pa_cstr_lit_write_xml_2io")

#define Pe_cstr_lit_write_xml_2io(pads, io, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2io(pads, io, s, tag, indent, "Pe_cstr_lit_write_xml_2io")

#define Pcstr_lit_write_xml_2io(pads, io, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2io(pads, io, s, tag, indent, "Pcstr_lit_write_xml_2io")

#define Pa_cstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent, "Pa_cstr_lit_write_xml_2buf")

#define Pe_cstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent, "Pe_cstr_lit_write_xml_2buf")

#define Pcstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent) \
  PDCI_cstr_lit_write_xml_2buf(pads, buf, buf_len, buf_full, s, tag, indent, "Pcstr_lit_write_xml_2buf")

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PCSTR_LIT_IMPL_H__   */
