/*@FILE Psb_fpoint_app_1.tex Psb_fpoint_app_2.tex Psb_fpoint_app_3.tex Psb_fpoint_app_4.tex Psb_fpoint_app_5.tex Psb_fpoint_app_6.tex Psb_fpoint_app_7.tex Psb_fpoint_app_8.tex Psb_fpoint_app_9.tex Psb_fpoint_app_10.tex Psb_fpoint_app_11.tex Psb_fpoint_app_12.tex Psb_fpoint_app_13.tex Psb_fpoint_app_14.tex Psb_fpoint_app_15.tex Psb_fpoint_app_16.tex Psb_fpoint_app_17.tex Psb_fpoint_app_18.tex Psb_fpoint_app_19.tex Psb_fpoint_app_20.tex Psb_fpoint_app_21.tex Psb_fpoint_app_22.tex Psb_fpoint_app_23.tex Psb_fpoint_app_24.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PSB_FPOINT_H__
#define __PSB_FPOINT_H__

#ifndef __PADS_H__
#error Psb_fpoint.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Psb_fpoint_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * FIXED POINT READ FUNCTIONS
 * SBL (sbl_), and SBH (sbh_) ENCODINGS
 *
 * An in-memory fpoint or ufpoint number is a signed or unsigned
 * fixed-point rational number with a numerator and denominator that
 * both have the same size.  For signed fpoint types, the numerator
 * carries the sign, while the denominator is always unsigned.  For
 * example, type Pfpoint16 has a signed Pint16 numerator and an
 * unsigned Puint16 denominator.
 *
 * For the SBL and SBH fpoint read functions, num_bytes is the number
 * of bytes on disk used to encode the numerator, the encoding being
 * the same as for the SBL and SBH integer read functions,
 * respectively.
 */
/*@END Psb_fpoint_app_1.tex*/
/*@BEGIN Psb_fpoint_app_2.tex*/
/* For all fpoint types, d_exp determines the denominator value,
 * which is implicitly 10^d_exp and is not encoded on disk.
 * The legal range of values for d_exp depends on the type:
 *
 * Type                     d_exp     Max denominator (min is 1)
 * -----------------------  --------  --------------------------
 * Pfpoint8  /  ufpoint8  0-2                             100
 * Pfpoint16 / ufpoint16  0-4                          10,000
 * Pfpoint32 / ufpoint32  0-9                   1,000,000,000
 * Pfpoint64 / ufpoint64  0-19     10,000,000,000,000,000,000
 *
 * The legal range of values for num_bytes
 * depends on target type, and is the same as specified for the
 * SBL/SBH integer read functions.
 */
/*@END Psb_fpoint_app_2.tex*/
/*@BEGIN Psb_fpoint_app_3.tex*/
/* If the specified number of bytes are NOT available:
 *    + pd->loc.b/e set to elt/char position of start/end of the 'too small' field
 *    + IO cursor not advanced
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_WIDTH_NOT_AVAILABLE,
 *         pd->nerr set to 1, and an error is reported
 *
 * Otherwise, the IO cursor is always advanced.  The error cases that
 * can occur even though the IO cursor advances:
 *
 * If num_bytes or d_exp is not in a legal choice for the target type
 * and sign of the value:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_BAD_PARAM,
 *         pd->nerr set to 1, and an error is reported
 *
 * If the actual numerator is not in the min/max numerator range, then:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 */
/*@END Psb_fpoint_app_3.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_SBL_FPOINT > 0

/*@BEGIN Psb_fpoint_app_4.tex*/
Perror_t Psbl_fpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint8 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_fpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint16 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_fpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint32 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_fpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint64 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_4.tex*/
/*@BEGIN Psb_fpoint_app_5.tex*/

Perror_t Psbl_ufpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint8 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_ufpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint16 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_ufpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint32 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbl_ufpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint64 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_5.tex*/

#endif

#if P_CONFIG_SBH_FPOINT > 0

/*@BEGIN Psb_fpoint_app_6.tex*/
Perror_t Psbh_fpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint8 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_fpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint16 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_fpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint32 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_fpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint64 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_6.tex*/
/*@BEGIN Psb_fpoint_app_7.tex*/

Perror_t Psbh_ufpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint8 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_ufpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint16 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_ufpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint32 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

Perror_t Psbh_ufpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint64 *res_out, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_7.tex*/
#endif
#endif

/*@BEGIN Psb_fpoint_app_8.tex*/
/* ================================================================================
 * WRITE
 */
/*@END Psb_fpoint_app_8.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0
#if P_CONFIG_SBL_FPOINT > 0

/*@BEGIN Psb_fpoint_app_9.tex*/

ssize_t Psbl_fpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint16 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint32 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint64 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_9.tex*/
/*@BEGIN Psb_fpoint_app_10.tex*/

ssize_t Psbl_ufpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint8 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint16 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint32 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint64 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_10.tex*/
/*@BEGIN Psb_fpoint_app_11.tex*/

ssize_t Psbl_fpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    const char *tag, int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint16 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbl_fpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint32 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbl_fpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint64 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

/*@END Psb_fpoint_app_11.tex*/
/*@BEGIN Psb_fpoint_app_12.tex*/

ssize_t Psbl_ufpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint8 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbl_ufpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint16 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbl_ufpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint32 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbl_ufpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint64 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

/*@END Psb_fpoint_app_12.tex*/
/*@BEGIN Psb_fpoint_app_13.tex*/

ssize_t Psbl_fpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint8 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint16 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint32 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint64 *val, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_13.tex*/
/*@BEGIN Psb_fpoint_app_14.tex*/

ssize_t Psbl_ufpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint8 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint16 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint32 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint64 *val, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_14.tex*/
/*@BEGIN Psb_fpoint_app_15.tex*/

ssize_t Psbl_fpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint8 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint16 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint32 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_fpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint64 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_15.tex*/
/*@BEGIN Psb_fpoint_app_16.tex*/

ssize_t Psbl_ufpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint8 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint16 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint32 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbl_ufpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint64 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_16.tex*/
#endif

#if P_CONFIG_SBH_FPOINT > 0

/*@BEGIN Psb_fpoint_app_17.tex*/

ssize_t Psbh_fpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint16 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint32 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint64 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_17.tex*/
/*@BEGIN Psb_fpoint_app_18.tex*/

ssize_t Psbh_ufpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint8 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint16 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint32 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint64 *val,
                    Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_18.tex*/
/*@BEGIN Psb_fpoint_app_19.tex*/

ssize_t Psbh_fpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    const char *tag, int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint16 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbh_fpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint32 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbh_fpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint64 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

/*@END Psb_fpoint_app_19.tex*/
/*@BEGIN Psb_fpoint_app_20.tex*/

ssize_t Psbh_ufpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint8 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbh_ufpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint16 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbh_ufpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint32 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

ssize_t Psbh_ufpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint64 *val, const char *tag, int indent, Puint32 num_bytes,
                    Puint32 d_exp
                    );

/*@END Psb_fpoint_app_20.tex*/
/*@BEGIN Psb_fpoint_app_21.tex*/

ssize_t Psbh_fpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint8 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint16 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint32 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint64 *val, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_21.tex*/
/*@BEGIN Psb_fpoint_app_22.tex*/

ssize_t Psbh_ufpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint8 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint16 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint32 *val, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint64 *val, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_22.tex*/
/*@BEGIN Psb_fpoint_app_23.tex*/

ssize_t Psbh_fpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint8 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint16 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint32 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_fpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint64 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_23.tex*/
/*@BEGIN Psb_fpoint_app_24.tex*/

ssize_t Psbh_ufpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint8 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint16 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint32 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

ssize_t Psbh_ufpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint64 *val, const char *tag,
                    int indent, Puint32 num_bytes, Puint32 d_exp
                    );

/*@END Psb_fpoint_app_24.tex*/

#endif
#endif

#endif /*  __PSB_FPOINT_H__  */

