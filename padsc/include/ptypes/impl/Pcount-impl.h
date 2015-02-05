/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCOUNT_IMPL_H__
#define __PCOUNT_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pcount-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_countX_read(P_t *pads, const Pbase_m *m,
			  Pbase_pd *pd, Pint32 *res_out,
			  Pcharset char_set, const char *whatfn,
			  Puint8 x, int eor_required, size_t count_max);


Perror_t PDCI_countXtoY_read(P_t *pads, const Pbase_m *m,
			     Pbase_pd *pd, Pint32 *res_out,
			     Pcharset char_set, const char *whatfn,
			     Puint8 x, Puint8 y, size_t count_max);


#define PcountX_read(pads, m, pd, res_out, x, eor_required, count_max) \
  PDCI_countX_read(pads, m, pd, res_out, PDCI_DEF_CHARSET(pads), "PcountX_read", x, eor_required, count_max)

#define Pa_countX_read(pads, m, pd, res_out, x, eor_required, count_max) \
  PDCI_countX_read(pads, m, pd, res_out, Pcharset_ASCII, "Pa_countX_read", x, eor_required, count_max)

#define Pe_countX_read(pads, m, x, eor_required, count_max, pd, res_out) \
  PDCI_countX_read(pads, m, x, eor_required, count_max, pd, res_out, Pcharset_EBCDIC, "Pe_countX_read")

#define PcountXtoY_read(pads, m, pd, res_out, x, y, count_max) \
  PDCI_countXtoY_read(pads, m, pd, res_out, PDCI_DEF_CHARSET(pads), "PcountXtoY_read", x, y, count_max)

#define Pa_countXtoY_read(pads, m, pd, res_out, x, y, count_max) \
  PDCI_countXtoY_read(pads, m, pd, res_out, Pcharset_ASCII, "Pa_countXtoY_read", x, y, count_max)

#define Pe_countXtoY_read(pads, m, pd, res_out, x, y, count_max) \
  PDCI_countXtoY_read(pads, m, pd, res_out, Pcharset_EBCDIC, "Pe_countXtoY_read", x, y, count_max)

#endif  /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_countX_write2io(P_t *pads, Sfio_t *io,
			     Pbase_pd *pd, Pint32  *val, Pcharset char_set, const char *whatfn,
			     Puint8 x, int eor_required, size_t count_max);
ssize_t PDCI_countX_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
			      Pbase_pd *pd, Pint32  *val, Pcharset char_set, const char *whatfn,
			      Puint8 x, int eor_required, size_t countx);
ssize_t PDCI_countXtoY_write2io(P_t *pads, Sfio_t *io,
				Pbase_pd *pd, Pint32  *val, Pcharset char_set, const char *whatfn,
				Puint8 x, Puint8 y, size_t count_max);
ssize_t PDCI_countXtoY_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				 Pbase_pd *pd, Pint32  *val, Pcharset char_set, const char *whatfn,
				 Puint8 x, Puint8 y, size_t count_max);

ssize_t PDCI_countX_write_xml_2io(P_t *pads, Sfio_t *io,
				  Pbase_pd *pd, Pint32  *val, const char* tag, int indent, const char *whatfn,
				  Puint8 x, int eor_required, size_t count_max);
ssize_t PDCI_countX_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				   Pbase_pd *pd, Pint32  *val, const char* tag, int indent, const char *whatfn,
				   Puint8 x, int eor_required, size_t countx);
ssize_t PDCI_countXtoY_write_xml_2io(P_t *pads, Sfio_t *io,
				     Pbase_pd *pd, Pint32  *val, const char* tag, int indent, const char *whatfn,
				     Puint8 x, Puint8 y, size_t count_max);
ssize_t PDCI_countXtoY_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
				      Pbase_pd *pd, Pint32  *val, const char* tag, int indent, const char *whatfn,
				      Puint8 x, Puint8 y, size_t count_max);

#define PcountX_write2io(pads, io, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2io(pads, io, pd, val, PDCI_DEF_CHARSET(pads), "PcountX_write2io", x, eor_required, count_max)

#define Pa_countX_write2io(pads, io, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2io(pads, io, pd, val, Pcharset_ASCII, "Pa_countX_write2io", x, eor_required, count_max)

#define Pe_countX_write2io(pads, io, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2io(pads, io, pd, val, Pcharset_EBCDIC, "Pe_countX_write2io", x, eor_required, count_max)

#define PcountX_write2buf(pads, buf, len, buf_full, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2buf(pads, buf, len, buf_full, pd, val, PDCI_DEF_CHARSET(pads), "PcountX_write2buf", x, eor_required, count_max)

#define Pa_countX_write2buf(pads, buf, len, buf_full, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2buf(pads, buf, len, buf_full, pd, val, Pcharset_ASCII, "Pa_countX_write2buf", x, eor_required, count_max)

#define Pe_countX_write2buf(pads, buf, len, buf_full, pd, val, x, eor_required, count_max) \
  PDCI_countX_write2buf(pads, buf, len, buf_full, pd, val, Pcharset_EBCDIC, "Pe_countX_write2buf", x, eor_required, count_max)

#define PcountXtoY_write2io(pads, io, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2io(pads, io, pd, val, PDCI_DEF_CHARSET(pads), "PcountXtoY_write2io", x, y, count_max)

#define Pa_countXtoY_write2io(pads, io, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2io(pads, io, pd, val, Pcharset_ASCII, "Pa_countXtoY_write2io", x, y, count_max)

#define Pe_countXtoY_write2io(pads, io, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2io(pads, io, pd, val, Pcharset_EBCDIC, "Pe_countXtoY_write2io", x, y, count_max)

#define PcountXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, PDCI_DEF_CHARSET(pads), "PcountXtoY_write2buf", x, y, count_max)

#define Pa_countXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, Pcharset_ASCII, "Pa_countXtoY_write2buf", x, y, count_max)

#define Pe_countXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, x, y, count_max) \
  PDCI_countXtoY_write2buf(pads, buf, buf_len, buf_full, pd, val, Pcharset_EBCDIC, "Pe_countXtoY_write2buf", x, y, count_max)

#define PcountX_write_xml_2io(pads, io, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2io(pads, io, pd, val, tag, indent, "PcountX_write_xml_2io", x, eor_required, count_max)

#define Pa_countX_write_xml_2io(pads, io, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2io(pads, io, pd, val, tag, indent, "Pa_countX_write_xml_2io", x, eor_required, count_max)

#define Pe_countX_write_xml_2io(pads, io, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2io(pads, io, pd, val, tag, indent, "Pe_countX_write_xml_2io", x, eor_required, count_max)

#define PcountX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, "PcountX_write_xml_2buf", x, eor_required, count_max)

#define Pa_countX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, "Pa_countX_write_xml_2buf", x, eor_required, count_max)

#define Pe_countX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, x, eor_required, count_max) \
  PDCI_countX_write_xml_2buf(pads, buf, len, buf_full, pd, val, tag, indent, "Pe_countX_write_xml_2buf", x, eor_required, count_max)

#define PcountXtoY_write_xml_2io(pads, io, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2io(pads, io, pd, val, tag, indent, "PcountXtoY_write_xml_2io", x, y, count_max)

#define Pa_countXtoY_write_xml_2io(pads, io, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2io(pads, io, pd, val, tag, indent, "Pa_countXtoY_write_xml_2io", x, y, count_max)

#define Pe_countXtoY_write_xml_2io(pads, io, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2io(pads, io, pd, val, tag, indent, "Pe_countXtoY_write_xml_2io", x, y, count_max)

#define PcountXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, "PcountXtoY_write_xml_2buf", x, y, count_max)

#define Pa_countXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, "Pa_countXtoY_write_xml_2buf", x, y, count_max)

#define Pe_countXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, x, y, count_max) \
  PDCI_countXtoY_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, "Pe_countXtoY_write_xml_2buf", x, y, count_max)

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PCOUNT_IMPL_H__   */
