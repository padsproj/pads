/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PINT_IMPL_H__
#define __PINT_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pint-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

#define Pint8_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, int8_read, (pads, m, pd, res_out))

#define Pint16_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, int16_read, (pads, m, pd, res_out))

#define Pint32_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, int32_read, (pads, m, pd, res_out))

#define Pint64_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, int64_read, (pads, m, pd, res_out))

#define Puint8_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_read, (pads, m, pd, res_out))

#define Puint16_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_read, (pads, m, pd, res_out))

#define Puint32_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_read, (pads, m, pd, res_out))

#define Puint64_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_read, (pads, m, pd, res_out))

#define Pint8_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, int8_FW_read, (pads, m, pd, res_out, width))

#define Pint16_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, int16_FW_read, (pads, m, pd, res_out, width))

#define Pint32_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, int32_FW_read, (pads, m, pd, res_out, width))

#define Pint64_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, int64_FW_read, (pads, m, pd, res_out, width))

#define Puint8_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_FW_read, (pads, m, pd, res_out, width))

#define Puint16_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_FW_read, (pads, m, pd, res_out, width))

#define Puint32_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_FW_read, (pads, m, pd, res_out, width))

#define Puint64_FW_read(pads, m, pd, res_out, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_FW_read, (pads, m, pd, res_out, width))

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

#define Pint8_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int8_FW_write2io, (pads, io, pd, val, width))

#define Pint16_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int16_FW_write2io, (pads, io, pd, val, width))

#define Pint32_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int32_FW_write2io, (pads, io, pd, val, width))

#define Pint64_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int64_FW_write2io, (pads, io, pd, val, width))

#define Puint8_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_FW_write2io, (pads, io, pd, val, width))

#define Puint16_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_FW_write2io, (pads, io, pd, val, width))

#define Puint32_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_FW_write2io, (pads, io, pd, val, width))

#define Puint64_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_FW_write2io, (pads, io, pd, val, width))

#define Pint8_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int8_write2io, (pads, io, pd, val))

#define Pint16_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int16_write2io, (pads, io, pd, val))

#define Pint32_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int32_write2io, (pads, io, pd, val))

#define Pint64_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int64_write2io, (pads, io, pd, val))

#define Puint8_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_write2io, (pads, io, pd, val))

#define Puint16_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_write2io, (pads, io, pd, val))

#define Puint32_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_write2io, (pads, io, pd, val))

#define Puint64_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_write2io, (pads, io, pd, val))

#define Pint8_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int8_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pint16_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int16_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pint32_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int32_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pint64_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, int64_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Puint8_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Puint16_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Puint32_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Puint64_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pint8_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int8_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pint16_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int16_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pint32_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int32_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pint64_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, int64_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Puint8_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Puint16_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Puint32_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Puint64_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pint8_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int8_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pint16_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int16_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pint32_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int32_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pint64_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int64_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Puint8_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Puint16_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Puint32_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Puint64_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pint8_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int8_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pint16_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int16_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pint32_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int32_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pint64_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int64_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Puint8_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Puint16_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Puint32_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Puint64_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pint8_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int8_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pint16_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int16_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pint32_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int32_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pint64_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, int64_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Puint8_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Puint16_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Puint32_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Puint64_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pint8_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int8_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Pint16_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int16_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Pint32_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int32_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Pint64_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, int64_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Puint8_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint8_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Puint16_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint16_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Puint32_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint32_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Puint64_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, uint64_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PINT_IMPL_H__   */
