/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCHAR_IMPL_H__
#define __PCHAR_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pchar-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_char_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pchar *c_out,
			Pcharset char_set, const char *whatfn);

#define Pchar_read(pads, m, pd, c_out) \
  PDCI_char_read(pads, m, pd, c_out, PDCI_DEF_CHARSET(pads), "Pchar_read")

#define Pa_char_read(pads, m, pd, c_out) \
  PDCI_char_read(pads, m, pd, c_out, Pcharset_ASCII, "Pa_char_read")

#define Pe_char_read(pads, m, pd, c_out) \
  PDCI_char_read(pads, m, pd, c_out, Pcharset_EBCDIC, "Pe_char_read")

#endif  /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_char_write2io (P_t *pads, Sfio_t *io, Pbase_pd *pd,
			    Pchar *c, Pcharset char_set, const char *whatfn);

ssize_t PDCI_char_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, Pbase_pd *pd,
			    Pchar *c, Pcharset char_set, const char *whatfn);

ssize_t PDCI_char_write_xml_2io (P_t *pads, Sfio_t *io, Pbase_pd *pd,
				 Pchar *c, const char* tag, int indent, const char *whatfn);

ssize_t PDCI_char_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full, Pbase_pd *pd,
				 Pchar *c, const char* tag, int indent, const char *whatfn);

#define Pchar_write2io(pads, io, pd, c) \
  PDCI_char_write2io(pads, io, pd, c, PDCI_DEF_CHARSET(pads), "Pchar_write2io")

#define Pa_char_write2io(pads, io, pd, c) \
  PDCI_char_write2io(pads, io, pd, c, Pcharset_ASCII, "Pa_char_write2io")

#define Pe_char_write2io(pads, io, pd, c) \
  PDCI_char_write2io(pads, io, pd, c, Pcharset_EBCDIC, "Pe_char_write2io")

#define Pchar_write2buf(pads, buf, buf_len, buf_full, pd, c) \
  PDCI_char_write2buf(pads, buf, buf_len, buf_full, pd, c, PDCI_DEF_CHARSET(pads), "Pchar_write2buf")

#define Pa_char_write2buf(pads, buf, buf_len, buf_full, pd, c) \
  PDCI_char_write2buf(pads, buf, buf_len, buf_full, pd, c, Pcharset_ASCII, "Pa_char_write2buf")

#define Pe_char_write2buf(pads, buf, buf_len, buf_full, pd, c) \
  PDCI_char_write2buf(pads, buf, buf_len, buf_full, pd, c, Pcharset_EBCDIC, "Pe_char_write2buf")

#define Pchar_write_xml_2io(pads, io, pd, c, tag, indent) \
  PDCI_char_write_xml_2io(pads, io, pd, c, tag, indent, "Pchar_write_xml_2io")

#define Pa_char_write_xml_2io(pads, io, pd, c, tag, indent) \
  PDCI_char_write_xml_2io(pads, io, pd, c, tag, indent, "Pa_char_write_xml_2io")

#define Pe_char_write_xml_2io(pads, io, pd, c, tag, indent) \
  PDCI_char_write_xml_2io(pads, io, pd, c, tag, indent, "Pe_char_write_xml_2io")

#define Pchar_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent) \
  PDCI_char_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent, "Pchar_write_xml_2buf")

#define Pa_char_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent) \
  PDCI_char_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent, "Pa_char_write_xml_2buf")

#define Pe_char_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent) \
  PDCI_char_write_xml_2buf(pads, buf, buf_len, buf_full, pd, c, tag, indent, "Pe_char_write_xml_2buf")

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PCHAR_IMPL_H__   */
