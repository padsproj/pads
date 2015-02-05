/*@FILE Pebc_int_app_1.tex Pebc_int_app_2.tex Pebc_int_app_3.tex Pebc_int_app_4.tex Pebc_int_app_5.tex Pebc_int_app_6.tex Pebc_int_app_7.tex Pebc_int_app_8.tex Pebc_int_app_9.tex Pebc_int_app_10.tex Pebc_int_app_11.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PEBC_INT_H__
#define __PEBC_INT_H__

#ifndef __PADS_H__
#error Pebc_int.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pebc_int_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * EBC ENCODING OF INTEGERS (VARIABLE NUMBER OF DIGITS)
 *
 * These functions parse signed or unsigned EBCDIC numeric (ebc_)
 * encoded integers with a specified number of digits.
 *
 * Each byte on disk encodes one digit (in low 4 bits).  For signed
 * values, the final byte encodes the sign (high 4 bits == 0xD for negative).
 * A signed or unsigned 5 digit value is encoded in 5 bytes.
 *
 * The legal range of values for num_digits
 * depends on target type:
 *    
 * Type        num_digits    Min/Max values
 * ----------- ----------    ----------------------------
 * Pint8       1-3           P_MIN_INT8  / P_MAX_INT8
 * Puint8      1-3           0           / P_MAX_UINT8
 * Pint16      1-5           P_MIN_INT16 / P_MAX_INT16
 * Puint16     1-5           0           / P_MAX_UINT16
 * Pint32      1-10          P_MIN_INT32 / P_MAX_INT32
 * Puint32     1-10          0           / P_MAX_UINT32
 * Pint64      1-19          P_MIN_INT64 / P_MAX_INT64
 * Puint64     1-20          0           / P_MAX_UINT64
 * 
 * N.B.: num_digits must be odd if the value on disk can be negative.
 */
/*@END Pebc_int_app_1.tex*/
/*@BEGIN Pebc_int_app_2.tex*/
/*
 * If the required number of bytes is NOT available:
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
 * If the specified digits make up an integer that does not fit in the target type,
 * or if the actual value is not in the min/max range, then:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if P_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 *
 * If the specified bytes are not legal EBC integer bytes, then
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if P_Test_NotIgnore(*m), pd->errCode set to P_INVALID_EBC_NUM
 *         pd->nerr set to 1, and an error is reported
 */
/*@END Pebc_int_app_2.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_EBC_INT > 0  || P_CONFIG_EBC_FPOINT > 0

/*@BEGIN Pebc_int_app_3.tex*/
Perror_t Pebc_int8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_int16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_int32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_int64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_uint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_uint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint16 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_uint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Puint32 num_digits
                    );

Perror_t Pebc_uint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint64 *res_out,
                    Puint32 num_digits
                    );
/*@END Pebc_int_app_3.tex*/

#endif
#endif

/*@BEGIN Pebc_int_app_4.tex*/
/* ================================================================================
 * WRITE
 */
/*@END Pebc_int_app_4.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0
#if P_CONFIG_EBC_INT > 0 || P_CONFIG_EBC_FPOINT > 0

/*@BEGIN Pebc_int_app_5.tex*/

ssize_t Pebc_int8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_int16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_int32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_int64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    Puint32 num_digits
                    );

/*@END Pebc_int_app_5.tex*/
/*@BEGIN Pebc_int_app_6.tex*/

ssize_t Pebc_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, Puint32 num_digits
                    );

/*@END Pebc_int_app_6.tex*/
/*@BEGIN Pebc_int_app_7.tex*/

ssize_t Pebc_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, Puint32 num_digits
                    );

ssize_t Pebc_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, Puint32 num_digits
                    );

ssize_t Pebc_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, Puint32 num_digits
                    );

ssize_t Pebc_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, Puint32 num_digits
                    );

ssize_t Pebc_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, Puint32 num_digits
                    );

ssize_t Pebc_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, Puint32 num_digits
                    );

ssize_t Pebc_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, Puint32 num_digits
                    );

ssize_t Pebc_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, Puint32 num_digits
                    );

/*@END Pebc_int_app_7.tex*/
/*@BEGIN Pebc_int_app_8.tex*/

ssize_t Pebc_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent,
                    Puint32 num_digits
                    );

ssize_t Pebc_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint16 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint64 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint8 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

ssize_t Pebc_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, Puint32 num_digits
                    );

/*@END Pebc_int_app_8.tex*/
/*@BEGIN Pebc_int_app_9.tex*/

ssize_t Pebc_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_digits
                    );

ssize_t Pebc_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, Puint32 num_digits
                    );

/*@END Pebc_int_app_9.tex*/
/*@BEGIN Pebc_int_app_10.tex*/

ssize_t Pebc_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint16 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, Puint32 num_digits
                    );

ssize_t Pebc_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint64 *rep, Puint32 num_digits
                    );

/*@END Pebc_int_app_10.tex*/
/*@BEGIN Pebc_int_app_11.tex*/

ssize_t Pebc_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint8 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Puint32 num_digits
                    );

ssize_t Pebc_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    Puint32 num_digits
                    );

/*@END Pebc_int_app_11.tex*/

#endif
#endif  /*  P_CONFIG_WRITE_FUNCTIONS > 0  */

#endif /*  __PEBC_INT_H__  */

