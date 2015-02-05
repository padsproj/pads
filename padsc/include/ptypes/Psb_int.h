/*@FILE Psb_int_app_1.tex Psb_int_app_2.tex Psb_int_app_3.tex Psb_int_app_4.tex Psb_int_app_5.tex Psb_int_app_6.tex Psb_int_app_7.tex Psb_int_app_8.tex Psb_int_app_9.tex Psb_int_app_10.tex Psb_int_app_11.tex Psb_int_app_12.tex Psb_int_app_13.tex Psb_int_app_14.tex Psb_int_app_15.tex Psb_int_app_16.tex Psb_int_app_17.tex Psb_int_app_18.tex Psb_int_app_19.tex Psb_int_app_20.tex Psb_int_app_21.tex Psb_int_app_22.tex Psb_int_app_23.tex Psb_int_app_24.tex Psb_int_app_25.tex Psb_int_app_26.tex Psb_int_app_27.tex Psb_int_app_28.tex Psb_int_app_29.tex Psb_int_app_30.tex Psb_int_app_31.tex Psb_int_app_32.tex Psb_int_app_33.tex Psb_int_app_34.tex Psb_int_app_35.tex Psb_int_app_36.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PSB_INT_H__
#define __PSB_INT_H__

#ifndef __PADS_H__
#error Psb_int.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Psb_int_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * SBL, and SBH ENCODINGS OF INTEGERS (VARIABLE NUMBER OF BYTES)
 *
 * These functions parse signed or unsigned SBL (sbl_) or SBH (sbh_)
 * encoded integers with a specified number of bytes.
 *
 * SBL (Serialized Binary, Low-Order Byte First) INTEGER ENCODING
 *   (Psbl_int_read / Psbl_uint_read):
 *
 *   For a K-byte SBL encoding, the first byte on disk is treated 
 *   as the low order byte of a K byte value.
 *
 * SBH (Serialized Binary, High-Order Byte First) INTEGER ENCODING
 *   (Psbh_int_read / Psbh_uint_read):
 *
 *   For a K-byte SBH encoding, the first byte on disk is treated 
 *   as the high order byte of a K byte value.
 */ 
/*@END Psb_int_app_1.tex*/
/*@BEGIN Psb_int_app_2.tex*/
/* For SBL and SBH, each byte is moved to the in-memory target integer
 * unchanged.  Whether the result is treated as a signed or unsigned
 * number depends on the target type.
 *
 * Note that SBL and SBH differ from the common width binary (B)
 * types in 3 ways: (1) SBL and SBH support any number of
 * bytes between 1 and 8, while B only supports 1, 2, 4, and 8; (2)
 * with SBL and SBH you specify the target type independently of the
 * num_bytes; (3) SBL and SBH explicitly state the byte ordering,
 * while B uses the pads->disc->d_endian setting to determine the byte
 * ordering of the data.
 *
 * The legal range of values for num_bytes
 * depends on target type:
 *    
 * Type        num_bytes Min/Max values
 * ----------- --------- ----------------------------
 * Pint8       1-1       P_MIN_INT8  / P_MAX_INT8
 * Puint8      1-1       0           / P_MAX_UINT8
 * Pint16      1-2       P_MIN_INT16 / P_MAX_INT16
 * Puint16     1-2       0           / P_MAX_UINT16
 * Pint32      1-4       P_MIN_INT32 / P_MAX_INT32
 * Puint32     1-4       0           / P_MAX_UINT32
 * Pint64      1-8       P_MIN_INT64 / P_MAX_INT64
 * Puint64     1-8       0           / P_MAX_UINT64
 */ 
/*@END Psb_int_app_2.tex*/
/*@BEGIN Psb_int_app_3.tex*/
/* If the specified number of bytes is NOT available:
 *    + pd->loc.b/e set to elt/char position of start/end of the 'too small' field
 *    + IO cursor is not advanced
 *    + if P_Test_NotIgnore(*m), pd->errCode set to P_WIDTH_NOT_AVAILABLE,
 *         pd->nerr set to 1, and an error is reported
 *
 * Otherwise, the IO cursor is always advanced.  The error cases that
 * can occur even though the IO cursor advances:
 *
 * If num_bytes is not a legal choice for the target type and
 * sign of the value:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if P_Test_NotIgnore(*m), pd->errCode set to P_BAD_PARAM,
 *         pd->nerr set to 1, and an error is reported
 *
 * If the specified bytes make up an integer that does not fit in the target type,
 * or if the actual value is not in the min/max range, then:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if P_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 */
/*@END Psb_int_app_3.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_SBL_INT > 0 || P_CONFIG_SBL_FPOINT > 0

/*@BEGIN Psb_int_app_4.tex*/
Perror_t Psbl_int8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_int16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_int32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_int64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_4.tex*/
/*@BEGIN Psb_int_app_5.tex*/

Perror_t Psbl_uint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_uint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint16 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_uint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbl_uint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint64 *res_out,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_5.tex*/

#endif

#if P_CONFIG_SBH_INT > 0 || P_CONFIG_SBH_FPOINT > 0

/*@BEGIN Psb_int_app_6.tex*/

Perror_t Psbh_int8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_int16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_int32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_int64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_6.tex*/
/*@BEGIN Psb_int_app_7.tex*/

Perror_t Psbh_uint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_uint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint16 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_uint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Puint32 num_bytes
                    );

Perror_t Psbh_uint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint64 *res_out,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_7.tex*/

#endif
#endif /* P_CONFIG_READ_FUNCTIONS */

/*@BEGIN Psb_int_app_8.tex*/
/* ================================================================================
 * WRITE
 */
/*@END Psb_int_app_8.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0
#if P_CONFIG_SBL_INT > 0 || P_CONFIG_SBL_FPOINT > 0

/*@BEGIN Psb_int_app_9.tex*/

ssize_t Psbl_int8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_9.tex*/
/*@BEGIN Psb_int_app_10.tex*/

ssize_t Psbl_uint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_10.tex*/
/*@BEGIN Psb_int_app_11.tex*/

ssize_t Psbl_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_11.tex*/
/*@BEGIN Psb_int_app_12.tex*/

ssize_t Psbl_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_12.tex*/
/*@BEGIN Psb_int_app_13.tex*/

ssize_t Psbl_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, Puint32 num_bytes
                    );

ssize_t Psbl_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, Puint32 num_bytes
                    );

ssize_t Psbl_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, Puint32 num_bytes
                    );

ssize_t Psbl_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, Puint32 num_bytes
                    );

/*@END Psb_int_app_13.tex*/
/*@BEGIN Psb_int_app_14.tex*/

ssize_t Psbl_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, Puint32 num_bytes
                    );

ssize_t Psbl_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, Puint32 num_bytes
                    );

ssize_t Psbl_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, Puint32 num_bytes
                    );

ssize_t Psbl_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, Puint32 num_bytes
                    );

/*@END Psb_int_app_14.tex*/
/*@BEGIN Psb_int_app_15.tex*/

ssize_t Psbl_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint16 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbl_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbl_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint64 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_15.tex*/
/*@BEGIN Psb_int_app_16.tex*/

ssize_t Psbl_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint8 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbl_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_16.tex*/
/*@BEGIN Psb_int_app_17.tex*/

ssize_t Psbl_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_17.tex*/
/*@BEGIN Psb_int_app_18.tex*/

ssize_t Psbl_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_18.tex*/
/*@BEGIN Psb_int_app_19.tex*/

ssize_t Psbl_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint16 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_19.tex*/
/*@BEGIN Psb_int_app_20.tex*/

ssize_t Psbl_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, Puint32 num_bytes
                    );

ssize_t Psbl_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint64 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_20.tex*/
/*@BEGIN Psb_int_app_21.tex*/

ssize_t Psbl_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint8 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_21.tex*/
/*@BEGIN Psb_int_app_22.tex*/

ssize_t Psbl_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbl_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_22.tex*/

#endif

#if P_CONFIG_SBH_INT > 0 || P_CONFIG_SBH_FPOINT > 0

/*@BEGIN Psb_int_app_23.tex*/

ssize_t Psbh_int8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_23.tex*/
/*@BEGIN Psb_int_app_24.tex*/

ssize_t Psbh_uint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_24.tex*/
/*@BEGIN Psb_int_app_25.tex*/

ssize_t Psbh_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_25.tex*/
/*@BEGIN Psb_int_app_26.tex*/

ssize_t Psbh_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_26.tex*/
/*@BEGIN Psb_int_app_27.tex*/

ssize_t Psbh_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, Puint32 num_bytes
                    );

ssize_t Psbh_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, Puint32 num_bytes
                    );

ssize_t Psbh_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, Puint32 num_bytes
                    );

ssize_t Psbh_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, Puint32 num_bytes
                    );

/*@END Psb_int_app_27.tex*/
/*@BEGIN Psb_int_app_28.tex*/

ssize_t Psbh_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, Puint32 num_bytes
                    );

ssize_t Psbh_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, Puint32 num_bytes
                    );

ssize_t Psbh_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, Puint32 num_bytes
                    );

ssize_t Psbh_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, Puint32 num_bytes
                    );

/*@END Psb_int_app_28.tex*/
/*@BEGIN Psb_int_app_29.tex*/

ssize_t Psbh_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint16 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbh_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbh_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint64 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_29.tex*/
/*@BEGIN Psb_int_app_30.tex*/

ssize_t Psbh_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint8 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

ssize_t Psbh_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, Puint32 num_bytes
                    );

/*@END Psb_int_app_30.tex*/
/*@BEGIN Psb_int_app_31.tex*/

ssize_t Psbh_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_31.tex*/
/*@BEGIN Psb_int_app_32.tex*/

ssize_t Psbh_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_32.tex*/
/*@BEGIN Psb_int_app_33.tex*/

ssize_t Psbh_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint16 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_33.tex*/
/*@BEGIN Psb_int_app_34.tex*/

ssize_t Psbh_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, Puint32 num_bytes
                    );

ssize_t Psbh_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint64 *rep, Puint32 num_bytes
                    );

/*@END Psb_int_app_34.tex*/
/*@BEGIN Psb_int_app_35.tex*/

ssize_t Psbh_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint8 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_35.tex*/
/*@BEGIN Psb_int_app_36.tex*/

ssize_t Psbh_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Puint32 num_bytes
                    );

ssize_t Psbh_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    Puint32 num_bytes
                    );

/*@END Psb_int_app_36.tex*/

#endif
#endif

#endif /*  __PSB_INT_H__  */

