/*@FILE Pfloat_app_1.tex Pfloat_app_2.tex Pfloat_app_3.tex Pfloat_app_4.tex Pfloat_app_5.tex Pfloat_app_6.tex Pfloat_app_7.tex Pfloat_app_8.tex Pfloat_app_9.tex Pfloat_app_10.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PFLOAT_H__
#define __PFLOAT_H__

#ifndef __PADS_H__
#error Pfloat.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pfloat_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * CHARACTER-BASED FLOAT READ FUNCTIONS
 * 
 * DEFAULT                        ASCII                          EBCDIC
 * -----------------------------  -----------------------------  -----------------------------
 * Pfloat32_read                  Pa_float32_read                Pe_float32_read
 * Pfloat64_read                  Pa_float64_read                Pe_float64_read
 *
 * These types describe ASCII or EBCDIC character-based encodings of
 * floating point numbers.  The input representation must have this
 * form:
 *
 *   [+|-]DIGITS[.][DIGITS][(e|E)[+|-]DIGITS]
 *
 * Where DIGITS is a sequence of one or more
 * digit characters, (e|E) indicates either a lower- or
 * upper-case letter 'E', and elements in square brackets are
 * optional.  Note that there must be at least one digit before the
 * decimal point.
 *
 * If the input has a valid sequence of input characters that make up
 * a float, then the float is converted to a Pfloat32 or
 * Pfloat64, according to the type.  For example, if you specify
 * a Pa_float32 then ASCII characters making up a float will be read
 * from the input and converted to an in-memory Pfloat32.
 *
 * RETURN VALUE: Perror_t
 */
/*@END Pfloat_app_1.tex*/
/*@BEGIN Pfloat_app_2.tex*/
/*
 * Upon success, P_OK returned: 
 *   + the IO cursor is advanced to just beyond the last digit
 *   + if P_Test_NotIngore(*m), the out param is assigned a value
 *
 * P_ERR is returned on error.
 * Cursor advancement/err settings for different error cases:
 *
 * (1) If IO cursor is at EOF
 *     + pd->loc.b/e set to EOF 'location'
 *     + IO cursor remains at EOF
 *     + if P_Test_NotIgnore(*), pd->errCode set to P_AT_EOF,
 *         pd->nerr set to 1, and an error is reported
 * (2a) There is leading white space and not (pads->disc->flags & P_WSPACE_OK)
 * (2b) The target is unsigned and the first char is a -
 * (2c) The first character is not a +, -, or in [0-9]
 * (2d) First character is allowable + or -, following by a char that is not a digit
 * For the above 4 cases:
 *     + pd->loc.b/e set to the IO cursor position.
 *     + IO cursor is not advanced
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_INVALID_A_NUM/P_INVALID_E_NUM,
 *         pd->nerr set to 1, and an error is reported
 * (3) A valid ASCII/EBCDIC float is found, but it describes
 *     a float that does not fit in the specified target type
 *     + pd->loc.b/e set to elt/char position of start and end of the float
 *     + IO cursor is advanced just beyond the last digit
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 */

#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_FLOAT > 0

/*@BEGIN Pfloat_app_2.tex*/

Perror_t Pa_float32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat32 *res_out);

Perror_t Pa_float64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat64 *res_out);

/*@END Pfloat_app_2.tex*/

#endif

#if P_CONFIG_E_FLOAT > 0

/*@BEGIN Pfloat_app_3.tex*/

Perror_t Pe_float32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat32 *res_out);

Perror_t Pe_float64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat64 *res_out);

/*@END Pfloat_app_3.tex*/

#endif

#ifdef FOR_CKIT
#if P_CONFIG_A_FLOAT > 0 && P_CONFIG_E_FLOAT > 0

/*@BEGIN Pfloat_app_4.tex*/

Perror_t Pfloat32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat32 *res_out);

Perror_t Pfloat64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pfloat64 *res_out);

/*@END Pfloat_app_4.tex*/

#endif
#endif

#endif /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

#if P_CONFIG_A_FLOAT > 0

/*@BEGIN Pfloat_app_5.tex*/

ssize_t Pa_float32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat32 *val
                    );

ssize_t Pa_float64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat64 *val
                    );

ssize_t Pa_float32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat32 *val
                    );

ssize_t Pa_float64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat64 *val
                    );

ssize_t Pa_float32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfloat32 *val, const char *tag,
                    int indent
                    );

ssize_t Pa_float64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfloat64 *val, const char *tag,
                    int indent
                    );

ssize_t Pa_float32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat32 *val, 
                    const char *tag, int indent
                    );

ssize_t Pa_float64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat64 *val, 
                    const char *tag, int indent
                    );

ssize_t Pa_float32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

ssize_t Pa_float32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

/*@END Pfloat_app_5.tex*/
/*@BEGIN Pfloat_app_6.tex*/

ssize_t Pa_float64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pa_float64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pa_float32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pfloat32 *rep
                    );

ssize_t Pa_float64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pfloat64 *rep
                    );

/*@END Pfloat_app_6.tex*/

#endif

#if P_CONFIG_E_FLOAT > 0

/*@BEGIN Pfloat_app_7.tex*/

ssize_t Pe_float32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat32 *val
                    );

ssize_t Pe_float64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat64 *val
                    );

ssize_t Pe_float32_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat32 *val
                    );

ssize_t Pe_float64_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat64 *val
                    );

ssize_t Pe_float32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfloat32 *val, const char *tag,
                    int indent
                    );

ssize_t Pe_float64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pfloat64 *val, const char *tag,
                    int indent
                    );

ssize_t Pe_float32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat32 *val, 
                    const char *tag, int indent
                    );

ssize_t Pe_float64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat64 *val, 
                    const char *tag, int indent
                    );

ssize_t Pe_float32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

ssize_t Pe_float32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

/*@END Pfloat_app_7.tex*/
/*@BEGIN Pfloat_app_8.tex*/

ssize_t Pe_float64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pe_float64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pe_float32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pfloat32 *rep
                    );

ssize_t Pe_float64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pfloat64 *rep
                    );

/*@END Pfloat_app_8.tex*/

#endif

#ifdef FOR_CKIT
#if P_CONFIG_A_FLOAT > 0 || P_CONFIG_E_FLOAT > 0

/*@BEGIN Pfloat_app_9.tex*/

ssize_t Pfloat32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pfloat32 *val);


ssize_t Pfloat64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pfloat64 *val);


ssize_t Pfloat32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat32 *val
                    );

ssize_t Pfloat64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat64 *val
                    );

ssize_t Pfloat32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat32 *val,
                    const char *tag, int indent
                    );

ssize_t Pfloat64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pfloat64 *val,
                    const char *tag, int indent
                    );

ssize_t Pfloat32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat32 *val, const char *tag, int indent
                    );

ssize_t Pfloat64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pfloat64 *val, const char *tag, int indent
                    );

/*@END Pfloat_app_9.tex*/

#endif
#endif

#if P_CONFIG_A_FLOAT > 0 || P_CONFIG_E_FLOAT > 0

/*@BEGIN Pfloat_app_10.tex*/

ssize_t Pfloat32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

ssize_t Pfloat32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat32 *rep
                    );

ssize_t Pfloat64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pfloat64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pfloat64 *rep
                    );

ssize_t Pfloat32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pfloat32 *rep
                    );

ssize_t Pfloat64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pfloat64 *rep
                    );

/*@END Pfloat_app_10.tex*/

#endif

#endif  /*  P_CONFIG_WRITE_FUNCTIONS > 0  */

#endif /*  __PFLOAT_H__  */

