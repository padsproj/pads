/*@FILE Pebc_fpoint_app_1.tex Pebc_fpoint_app_2.tex Pebc_fpoint_app_3.tex Pebc_fpoint_app_4.tex Pebc_fpoint_app_5.tex Pebc_fpoint_app_6.tex Pebc_fpoint_app_7.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PEBC_FPOINT_H__
#define __PEBC_FPOINT_H__

#ifndef __PADS_H__
#error Pebc_fpoint.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pebc_fpoint_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * FIXED POINT READ FUNCTIONS
 * FOR EBC (ebc_) ENCODING
 *
 * An in-memory fpoint or ufpoint number is a signed or unsigned
 * fixed-point rational number with a numerator and denominator that
 * both have the same size.  For signed fpoint types, the numerator
 * carries the sign, while the denominator is always unsigned.  For
 * example, type Pfpoint16 has a signed Pint16 numerator and an
 * unsigned Puint16 denominator.
 *
 * For the EBC fpoint read functions, num_digits is the
 * number of digits used to encode the numerator (on disk). The number
 * of bytes implied by num_digits is the same as specified for the
 * EBC integer read functions.
 *
 * For all fpoint types, d_exp determines the denominator value,
 * which is implicitly 10^d_exp and is not encoded on disk.
 * The legal range of values for d_exp depends on the type:
 *
 * Type                     d_exp     Max denominator (min is 1)
 * -----------------------  --------  --------------------------
 * Pfpoint8  /  ufpoint8  0-2                             100
 * Pfpoint16 / ufpoint16  0-4                          10,000
 * Pfpoint32 / ufpoint32  0-9                   1,000,000,000
 * Pfpoint64 / ufpoint64  0-19     10,000,000,000,000,000,000
 */
/*@END Pebc_fpoint_app_1.tex*/
/*@BEGIN Pebc_fpoint_app_2.tex*/
/*
 * The legal range of values for num_digits
 * depends on target type, and is the same as specified for the
 * EBC integer read functions.
 *    
 * If the specified number of bytes are NOT available:
 *    + pd->loc.b/e set to elt/char position of start/end of the 'too small' field
 *    + IO cursor not advanced
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_WIDTH_NOT_AVAILABLE,
 *         pd->nerr set to 1, and an error is reported
 *
 * Otherwise, the IO cursor is always advanced.  The error cases that
 * can occur even though the IO cursor advances:
 *
 * If num_digits or d_exp is not in a legal choice for the target type
 * and sign of the value:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_BAD_PARAM,
 *         pd->nerr set to 1, and an error is reported
 *
 * If the actual numerator is not in the min/max numerator range, then:
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 *
 * If the specified bytes are not legal EBC integer bytes, then 
 *    + pd->loc.b/e set to elt/char position at the start/end of the field
 *    + if PD_Test_NotIgnore(*m), pd->errCode set to P_INVALID_EBC_NUM
 *         pd->nerr set to 1, and an error is reported
 *
 */
/*@END Pebc_fpoint_app_2.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_EBC_FPOINT > 0

/*@BEGIN Pebc_fpoint_app_3.tex*/
Perror_t Pebc_fpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint8 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_fpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint16 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_fpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint32 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_fpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pfpoint64 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_ufpoint8_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint8 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_ufpoint16_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint16 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_ufpoint32_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint32 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

Perror_t Pebc_ufpoint64_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Pufpoint64 *res_out, Puint32 num_digits, Puint32 d_exp
                    );

/*@END Pebc_fpoint_app_3.tex*/

#endif
#endif

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0
#if P_CONFIG_EBC_FPOINT > 0

/*@BEGIN Pebc_fpoint_app_4.tex*/

ssize_t Pebc_fpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint16 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint32 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint64 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint8_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint8 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint16_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint16 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint32 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pufpoint64 *val,
                    Puint32 num_digits, Puint32 d_exp
                    );

/*@END Pebc_fpoint_app_4.tex*/
/*@BEGIN Pebc_fpoint_app_5.tex*/

ssize_t Pebc_fpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfpoint8 *val,
                    const char *tag, int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint16 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_fpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint32 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_fpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pfpoint64 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_ufpoint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint8 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_ufpoint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint16 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_ufpoint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint32 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

ssize_t Pebc_ufpoint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Pufpoint64 *val, const char *tag, int indent, Puint32 num_digits,
                    Puint32 d_exp
                    );

/*@END Pebc_fpoint_app_5.tex*/
/*@BEGIN Pebc_fpoint_app_6.tex*/

ssize_t Pebc_fpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint8 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint16 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint32 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfpoint64 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint8 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint16 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint32 *val, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pufpoint64 *val, Puint32 num_digits, Puint32 d_exp
                    );

/*@END Pebc_fpoint_app_6.tex*/
/*@BEGIN Pebc_fpoint_app_7.tex*/

ssize_t Pebc_fpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint8 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint16 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint32 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_fpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfpoint64 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint8 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint16 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint32 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

ssize_t Pebc_ufpoint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pufpoint64 *val, const char *tag,
                    int indent, Puint32 num_digits, Puint32 d_exp
                    );

/*@END Pebc_fpoint_app_7.tex*/

#endif
#endif

#endif /*  __PEBC_FPOINT_H__  */

