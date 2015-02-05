/*
 * Map from type name to read and write functions for cmonster.
 * This file is included directly by cmonster.h
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "cmonster.h"

/* Declare all of the rw_fn: */

CM_RW_FN_DECL(int8_FW);
CM_RW_FN_DECL(int16_FW);
CM_RW_FN_DECL(int32_FW);
CM_RW_FN_DECL(int64_FW);
CM_RW_FN_DECL(uint8_FW);
CM_RW_FN_DECL(uint16_FW);
CM_RW_FN_DECL(uint32_FW);
CM_RW_FN_DECL(uint64_FW);

CM_RW_FN_DECL(a_int8_FW);
CM_RW_FN_DECL(a_int16_FW);
CM_RW_FN_DECL(a_int32_FW);
CM_RW_FN_DECL(a_int64_FW);
CM_RW_FN_DECL(a_uint8_FW);
CM_RW_FN_DECL(a_uint16_FW);
CM_RW_FN_DECL(a_uint32_FW);
CM_RW_FN_DECL(a_uint64_FW);

CM_RW_FN_DECL(e_int8_FW);
CM_RW_FN_DECL(e_int16_FW);
CM_RW_FN_DECL(e_int32_FW);
CM_RW_FN_DECL(e_int64_FW);
CM_RW_FN_DECL(e_uint8_FW);
CM_RW_FN_DECL(e_uint16_FW);
CM_RW_FN_DECL(e_uint32_FW);
CM_RW_FN_DECL(e_uint64_FW);

CM_RW_FN_DECL(b_int8);
CM_RW_FN_DECL(b_int16);
CM_RW_FN_DECL(b_int32);
CM_RW_FN_DECL(b_int64);
CM_RW_FN_DECL(b_uint8);
CM_RW_FN_DECL(b_uint16);
CM_RW_FN_DECL(b_uint32);
CM_RW_FN_DECL(b_uint64);

CM_RW_FN_DECL(ebc_int8);
CM_RW_FN_DECL(ebc_int16);
CM_RW_FN_DECL(ebc_int32);
CM_RW_FN_DECL(ebc_int64);
CM_RW_FN_DECL(ebc_uint8);
CM_RW_FN_DECL(ebc_uint16);
CM_RW_FN_DECL(ebc_uint32);
CM_RW_FN_DECL(ebc_uint64);

CM_RW_FN_DECL(bcd_int8);
CM_RW_FN_DECL(bcd_int16);
CM_RW_FN_DECL(bcd_int32);
CM_RW_FN_DECL(bcd_int64);
CM_RW_FN_DECL(bcd_uint8);
CM_RW_FN_DECL(bcd_uint16);
CM_RW_FN_DECL(bcd_uint32);
CM_RW_FN_DECL(bcd_uint64);

CM_RW_FN_DECL(sbl_int8);
CM_RW_FN_DECL(sbl_int16);
CM_RW_FN_DECL(sbl_int32);
CM_RW_FN_DECL(sbl_int64);
CM_RW_FN_DECL(sbl_uint8);
CM_RW_FN_DECL(sbl_uint16);
CM_RW_FN_DECL(sbl_uint32);
CM_RW_FN_DECL(sbl_uint64);

CM_RW_FN_DECL(sbh_int8);
CM_RW_FN_DECL(sbh_int16);
CM_RW_FN_DECL(sbh_int32);
CM_RW_FN_DECL(sbh_int64);
CM_RW_FN_DECL(sbh_uint8);
CM_RW_FN_DECL(sbh_uint16);
CM_RW_FN_DECL(sbh_uint32);
CM_RW_FN_DECL(sbh_uint64);

CM_RW_FN_DECL(ebc_fpoint8);
CM_RW_FN_DECL(ebc_fpoint16);
CM_RW_FN_DECL(ebc_fpoint32);
CM_RW_FN_DECL(ebc_fpoint64);
CM_RW_FN_DECL(ebc_ufpoint8);
CM_RW_FN_DECL(ebc_ufpoint16);
CM_RW_FN_DECL(ebc_ufpoint32);
CM_RW_FN_DECL(ebc_ufpoint64);

CM_RW_FN_DECL(bcd_fpoint8);
CM_RW_FN_DECL(bcd_fpoint16);
CM_RW_FN_DECL(bcd_fpoint32);
CM_RW_FN_DECL(bcd_fpoint64);
CM_RW_FN_DECL(bcd_ufpoint8);
CM_RW_FN_DECL(bcd_ufpoint16);
CM_RW_FN_DECL(bcd_ufpoint32);
CM_RW_FN_DECL(bcd_ufpoint64);

CM_RW_FN_DECL(sbl_fpoint8);
CM_RW_FN_DECL(sbl_fpoint16);
CM_RW_FN_DECL(sbl_fpoint32);
CM_RW_FN_DECL(sbl_fpoint64);
CM_RW_FN_DECL(sbl_ufpoint8);
CM_RW_FN_DECL(sbl_ufpoint16);
CM_RW_FN_DECL(sbl_ufpoint32);
CM_RW_FN_DECL(sbl_ufpoint64);

CM_RW_FN_DECL(sbh_fpoint8);
CM_RW_FN_DECL(sbh_fpoint16);
CM_RW_FN_DECL(sbh_fpoint32);
CM_RW_FN_DECL(sbh_fpoint64);
CM_RW_FN_DECL(sbh_ufpoint8);
CM_RW_FN_DECL(sbh_ufpoint16);
CM_RW_FN_DECL(sbh_ufpoint32);
CM_RW_FN_DECL(sbh_ufpoint64);

CM_RW_FN_DECL(char);
CM_RW_FN_DECL(string_FW);

CM_RW_FN_DECL(a_char);
CM_RW_FN_DECL(a_string_FW);

CM_RW_FN_DECL(e_char);
CM_RW_FN_DECL(e_string_FW);

/* Declare all of the sval_fn: */

CM_SVAL_FN_DECL(int32_FW);
CM_SVAL_FN_DECL(a_int32_FW);
CM_SVAL_FN_DECL(e_int32_FW);
CM_SVAL_FN_DECL(b_int32);
CM_SVAL_FN_DECL(ebc_int32);
CM_SVAL_FN_DECL(bcd_int32);
CM_SVAL_FN_DECL(sbl_int32);
CM_SVAL_FN_DECL(sbh_int32);

CM_SVAL_FN_DECL(char);
CM_SVAL_FN_DECL(a_char);
CM_SVAL_FN_DECL(e_char);

/* Declare the in_sz and out_sz functions that we need */

size_t CM_sz_1(CM_query *qy);
size_t CM_sz_2(CM_query *qy);
size_t CM_sz_4(CM_query *qy);
size_t CM_sz_8(CM_query *qy);
size_t CM_sz_p1(CM_query *qy);
size_t CM_sz_p1plus1div2(CM_query *qy);

/* fill in tmap */

#define CM_STD_TMAP_ENTRY(ty, in_sz_suf, out_sz_suf, num_params) \
  { "P" PDCI_MacroArg2String(ty) , CM_RW_FN_NM(ty), 0,                 CM_sz_ ## in_sz_suf, CM_sz_ ## out_sz_suf, num_params }

#define CM_SVAL_TMAP_ENTRY(ty, in_sz_suf, out_sz_suf, num_params) \
  { "P" PDCI_MacroArg2String(ty) , CM_RW_FN_NM(ty), CM_SVAL_FN_NM(ty), CM_sz_ ## in_sz_suf, CM_sz_ ## out_sz_suf, num_params }

CM_tmentry_t tmap[] = {

  CM_STD_TMAP_ENTRY(int8_FW,         p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(int16_FW,        p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(int32_FW,       p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(int64_FW,        p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(uint8_FW,        p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(uint16_FW,       p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(uint32_FW,       p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(uint64_FW,       p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(a_int8_FW,       p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(a_int16_FW,      p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(a_int32_FW,     p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(a_int64_FW,      p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(a_uint8_FW,      p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(a_uint16_FW,     p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(a_uint32_FW,     p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(a_uint64_FW,     p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(e_int8_FW,       p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(e_int16_FW,      p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(e_int32_FW,     p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(e_int64_FW,      p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(e_uint8_FW,      p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(e_uint16_FW,     p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(e_uint32_FW,     p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(e_uint64_FW,     p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(b_int8,          1,            1,   0 ),
  CM_STD_TMAP_ENTRY(b_int16,         2,            2,   0 ),
  CM_SVAL_TMAP_ENTRY(b_int32,        4,            4,   0 ),
  CM_STD_TMAP_ENTRY(b_int64,         8,            8,   0 ),
  CM_STD_TMAP_ENTRY(b_uint8,         1,            1,   0 ),
  CM_STD_TMAP_ENTRY(b_uint16,        2,            2,   0 ),
  CM_STD_TMAP_ENTRY(b_uint32,        4,            4,   0 ),
  CM_STD_TMAP_ENTRY(b_uint64,        8,            8,   0 ),

  CM_STD_TMAP_ENTRY(ebc_int8,        p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(ebc_int16,       p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(ebc_int32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(ebc_int64,       p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(ebc_uint8,       p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(ebc_uint16,      p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(ebc_uint32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(ebc_uint64,      p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(bcd_int8,        p1plus1div2,  1,   1 ),
  CM_STD_TMAP_ENTRY(bcd_int16,       p1plus1div2,  2,   1 ),
  CM_SVAL_TMAP_ENTRY(bcd_int32,      p1plus1div2,  4,   1 ),
  CM_STD_TMAP_ENTRY(bcd_int64,       p1plus1div2,  8,   1 ),
  CM_STD_TMAP_ENTRY(bcd_uint8,       p1plus1div2,  1,   1 ),
  CM_STD_TMAP_ENTRY(bcd_uint16,      p1plus1div2,  2,   1 ),
  CM_STD_TMAP_ENTRY(bcd_uint32,      p1plus1div2,  4,   1 ),
  CM_STD_TMAP_ENTRY(bcd_uint64,      p1plus1div2,  8,   1 ),

  CM_STD_TMAP_ENTRY(sbl_int8,        p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(sbl_int16,       p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(sbl_int32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(sbl_int64,       p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(sbl_uint8,       p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(sbl_uint16,      p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(sbl_uint32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(sbl_uint64,      p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(sbh_int8,        p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(sbh_int16,       p1,           2,   1 ),
  CM_SVAL_TMAP_ENTRY(sbh_int32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(sbh_int64,       p1,           8,   1 ),
  CM_STD_TMAP_ENTRY(sbh_uint8,       p1,           1,   1 ),
  CM_STD_TMAP_ENTRY(sbh_uint16,      p1,           2,   1 ),
  CM_STD_TMAP_ENTRY(sbh_uint32,      p1,           4,   1 ),
  CM_STD_TMAP_ENTRY(sbh_uint64,      p1,           8,   1 ),

  CM_STD_TMAP_ENTRY(ebc_fpoint8,     p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(ebc_fpoint16,    p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(ebc_fpoint32,    p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(ebc_fpoint64,    p1,           8,   2 ),
  CM_STD_TMAP_ENTRY(ebc_ufpoint8,    p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(ebc_ufpoint16,   p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(ebc_ufpoint32,   p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(ebc_ufpoint64,   p1,           8,   2 ),

  CM_STD_TMAP_ENTRY(bcd_fpoint8,     p1plus1div2,  1,   2 ),
  CM_STD_TMAP_ENTRY(bcd_fpoint16,    p1plus1div2,  2,   2 ),
  CM_STD_TMAP_ENTRY(bcd_fpoint32,    p1plus1div2,  4,   2 ),
  CM_STD_TMAP_ENTRY(bcd_fpoint64,    p1plus1div2,  8,   2 ),
  CM_STD_TMAP_ENTRY(bcd_ufpoint8,    p1plus1div2,  1,   2 ),
  CM_STD_TMAP_ENTRY(bcd_ufpoint16,   p1plus1div2,  2,   2 ),
  CM_STD_TMAP_ENTRY(bcd_ufpoint32,   p1plus1div2,  4,   2 ),
  CM_STD_TMAP_ENTRY(bcd_ufpoint64,   p1plus1div2,  8,   2 ),

  CM_STD_TMAP_ENTRY(sbl_fpoint8,     p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(sbl_fpoint16,    p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(sbl_fpoint32,    p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(sbl_fpoint64,    p1,           8,   2 ),
  CM_STD_TMAP_ENTRY(sbl_ufpoint8,    p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(sbl_ufpoint16,   p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(sbl_ufpoint32,   p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(sbl_ufpoint64,   p1,           8,   2 ),

  CM_STD_TMAP_ENTRY(sbh_fpoint8,     p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(sbh_fpoint16,    p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(sbh_fpoint32,    p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(sbh_fpoint64,    p1,           8,   2 ),
  CM_STD_TMAP_ENTRY(sbh_ufpoint8,    p1,           1,   2 ),
  CM_STD_TMAP_ENTRY(sbh_ufpoint16,   p1,           2,   2 ),
  CM_STD_TMAP_ENTRY(sbh_ufpoint32,   p1,           4,   2 ),
  CM_STD_TMAP_ENTRY(sbh_ufpoint64,   p1,           8,   2 ),

  CM_SVAL_TMAP_ENTRY(char,           1,            1,   0 ),
  CM_STD_TMAP_ENTRY(string_FW,       p1,           p1,  1 ),

  CM_SVAL_TMAP_ENTRY(a_char,         1,            1,   0 ),
  CM_STD_TMAP_ENTRY(a_string_FW,     p1,           p1,  1 ),

  CM_SVAL_TMAP_ENTRY(e_char,         1,            1,   0 ),
  CM_STD_TMAP_ENTRY(e_string_FW,     p1,           p1,  1 ),

  /* END MARKER */
  { 0, 0, 0, 0, 0 }
};

