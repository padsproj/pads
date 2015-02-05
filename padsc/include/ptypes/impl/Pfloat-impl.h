/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PFLOAT_IMPL_H__
#define __PFLOAT_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pfloat-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

#define Pfloat32_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, float32_read, (pads, m, pd, res_out))

#define Pfloat64_read(pads, m, pd, res_out) \
  PDCI_CHARSET_SWITCH(pads, P, float64_read, (pads, m, pd, res_out))

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

#define Pfloat32_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, float32_FW_write2io, (pads, io, pd, val, width))

#define Pfloat64_FW_write2io(pads, io, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, float64_FW_write2io, (pads, io, pd, val, width))

#define Pfloat32_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, float32_write2io, (pads, io, pd, val))

#define Pfloat64_write2io(pads, io, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, float64_write2io, (pads, io, pd, val))

#define Pfloat32_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, float32_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pfloat64_FW_write2buf(pads, buf, buf_len, buf_full, pd, val, width) \
  PDCI_CHARSET_SWITCH(pads, P, float64_FW_write2buf, (pads, buf, buf_len, buf_full, pd, val, width))

#define Pfloat32_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, float32_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pfloat64_write2buf(pads, buf, buf_len, buf_full, pd, val) \
  PDCI_CHARSET_SWITCH(pads, P, float64_write2buf, (pads, buf, buf_len, buf_full, pd, val))

#define Pfloat32_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, float32_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pfloat64_FW_write_xml_2io(pads, io, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, float64_FW_write_xml_2io, (pads, io, pd, val, tag, indent, width))

#define Pfloat32_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, float32_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pfloat64_write_xml_2io(pads, io, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, float64_write_xml_2io, (pads, io, pd, val, tag, indent))

#define Pfloat32_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, float32_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pfloat64_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent, width) \
  PDCI_CHARSET_SWITCH(pads, P, float64_FW_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent, width))

#define Pfloat32_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, float32_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#define Pfloat64_write_xml_2buf(pads, buf, buf_len, buf_full, pd, val, tag, indent) \
  PDCI_CHARSET_SWITCH(pads, P, float64_write_xml_2buf, (pads, buf, buf_len, buf_full, pd, val, tag, indent))

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PFLOAT_IMPL_H__   */
