/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PIP_IMPL_H__
#define __PIP_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pip-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_ip_read(P_t *pads, const Pbase_m *m,
		      Pbase_pd *pd, Puint32 *res_out,
		      Pcharset char_set, const char *whatfn);

#define Pip_read(pads, m, pd, res_out) \
  PDCI_ip_read(pads, m, pd, res_out, PDCI_DEF_CHARSET(pads), "Pip_read")

#define Pa_ip_read(pads, m, pd, res_out) \
  PDCI_ip_read(pads, m, pd, res_out, Pcharset_ASCII, "Pa_ip_read")

#define Pe_ip_read(pads, m, pd, res_out) \
  PDCI_ip_read(pads, m, pd, res_out, Pcharset_EBCDIC, "Pe_ip_read")

#endif  /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_ip_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
			 Puint32 *d, Pcharset char_set, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_ip_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
			  Pbase_pd *pd, Puint32 *d,
			  Pcharset char_set, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_ip_write_xml_2io(P_t *pads, Sfio_t *io,  Pbase_pd *pd,
			      Puint32 *d, const char* tag, int indent, const char *inv_type, const char *whatfn, ...);

ssize_t PDCI_ip_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
			       Pbase_pd *pd, Puint32 *d,
			       const char* tag, int indent, const char *inv_type, const char *whatfn, ...);

#define Pip_write2io(pads, io, pd, d) \
  PDCI_ip_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pip", "Pip_write2io")

#define Pa_ip_write2io(pads, io, pd, d) \
  PDCI_ip_write2io(pads, io, pd, d, Pcharset_ASCII, "Pip", "Pa_ip_write2io")

#define Pe_ip_write2io(pads, io, pd, d) \
  PDCI_ip_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pip", "Pe_ip_write2io")

#define Pip_write2buf(pads, buf, buf_len, buf_full, pd, d) \
  PDCI_ip_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pip", "Pip_write2buf")

#define Pa_ip_write2buf(pads, buf, buf_len, buf_full, pd, d) \
  PDCI_ip_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pip", "Pa_ip_write2buf")

#define Pe_ip_write2buf(pads, buf, buf_len, buf_full, pd, d) \
  PDCI_ip_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pip", "Pe_ip_write2buf")

#define Pip_write_xml_2io(pads, io, pd, d, tag, indent) \
  PDCI_ip_write_xml_2io(pads, io, pd, d, tag, indent, "Pip", "Pip_write_xml_2io")

#define Pa_ip_write_xml_2io(pads, io, pd, d, tag, indent) \
  PDCI_ip_write_xml_2io(pads, io, pd, d, tag, indent, "Pip", "Pa_ip_write_xml_2io")

#define Pe_ip_write_xml_2io(pads, io, pd, d, tag, indent) \
  PDCI_ip_write_xml_2io(pads, io, pd, d, tag, indent, "Pip", "Pe_ip_write_xml_2io")

#define Pip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent) \
  PDCI_ip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pip", "Pip_write_xml_2buf")

#define Pa_ip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent) \
  PDCI_ip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pip", "Pa_ip_write_xml_2buf")

#define Pe_ip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent) \
  PDCI_ip_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pip", "Pe_ip_write_xml_2buf")

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PIP_IMPL_H__   */
