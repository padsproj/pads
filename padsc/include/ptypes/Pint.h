/*@FILE Pint_app_1.tex Pint_app_2.tex Pint_app_3.tex Pint_app_4.tex Pint_app_5.tex Pint_app_6.tex Pint_app_7.tex Pint_app_8.tex Pint_app_9.tex Pint_app_10.tex Pint_app_11.tex Pint_app_12.tex Pint_app_13.tex Pint_app_14.tex Pint_app_15.tex Pint_app_16.tex Pint_app_17.tex Pint_app_18.tex Pint_app_19.tex Pint_app_20.tex Pint_app_21.tex Pint_app_22.tex Pint_app_23.tex Pint_app_24.tex Pint_app_25.tex Pint_app_26.tex Pint_app_27.tex Pint_app_28.tex Pint_app_29.tex Pint_app_30.tex Pint_app_31.tex Pint_app_32.tex Pint_app_33.tex Pint_app_34.tex Pint_app_35.tex Pint_app_36.tex Pint_app_37.tex Pint_app_38.tex Pint_app_39.tex Pint_app_40.tex Pint_app_41.tex Pint_app_42.tex Pint_app_43.tex Pint_app_44.tex Pint_app_45.tex Pint_app_46.tex Pint_app_47.tex Pint_app_48.tex Pint_app_49.tex Pint_app_50.tex Pint_app_51.tex Pint_app_52.tex Pint_app_53.tex Pint_app_54.tex Pint_app_55.tex Pint_app_56.tex Pint_app_57.tex Pint_app_58.tex Pint_app_59.tex Pint_app_60.tex Pint_app_61.tex Pint_app_62.tex Pint_app_63.tex Pint_app_64.tex Pint_app_65.tex Pint_app_66.tex Pint_app_67.tex Pint_app_68.tex Pint_app_69.tex Pint_app_70.tex Pint_app_71.tex Pint_app_72.tex Pint_app_73.tex Pint_app_74.tex Pint_app_75.tex Pint_app_76.tex Pint_app_77.tex Pint_app_78.tex Pint_app_79.tex Pint_app_80.tex Pint_app_81.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PINT_H__
#define __PINT_H__

#ifndef __PADS_H__
#error Pint.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pint_app_1.tex*/
/* ================================================================================
 * ASCII STRING TO INTEGER READ FUNCTIONS
 *
 * An ASCII representation of an integer value (a string of digits in
 * [0-9]) is assumed to be at the current cursor position, where if
 * the target type is a signed type a leading - or + is allowed and if
 * unsigned a leading + is allowed.  If (pads->disc->flags &
 * P_WSPACE_OK), leading white space is skipped, otherwise leading
 * white space causes an error.  Thus, the string to be converted
 * consists of: optional white space, optional +/-, and all
 * consecutive digits (first nondigit marks end).
 *
 * RETURN VALUE: Perror_t
 *
 * Upon success, P_OK returned: 
 *   + the IO cursor is advanced to just beyond the last digit
 *   + if P_Test_NotIngore(*m), the out param is assigned a value
 *
 * P_ERR is returned on error.
 * Cursor advancement/err settings for different error cases:
 */
/*@END Pint_app_1.tex*/
/*@BEGIN Pint_app_2.tex*/
/* (1) If IO cursor is at EOF
 *     + pd->loc.b/e set to EOF 'location'
 *     + IO cursor remains at EOF
 *     + if P_Test_NotIgnore(*), pd->errCode set to P_AT_EOF,
 *         pd->nerr set to 1, and an error is reported
 * (2a) There is leading white space and
 *        (pads->disc->flags & P_WSPACE_OK) is not set
 * (2b) The target is unsigned and the first char is a -
 * (2c) The first character is not a +, -, or in [0-9]
 * (2d) First character is allowable + or -, following by a char that
 *        is not a digit
 * For the above 4 cases:
 *     + pd->loc.b/e set to the IO cursor position.
 *     + IO cursor is not advanced
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_INVALID_A_NUM,
 *         pd->nerr set to 1, and an error is reported
 * (3) A valid ASCII integer string is found, but it describes
 *     an integer that does not fit in the specified target type
 *     + pd->loc.b/e set to elt/char position of start and
 *        end of the ASCII integer
 *     + IO cursor is advanced just beyond the last digit
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_RANGE,
 *         pd->nerr set to 1, and an error is reported
 */
/*@END Pint_app_2.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_A_INT > 0

/*@BEGIN Pint_app_3.tex*/

Perror_t Pa_int8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint8 *res_out);

Perror_t Pa_int16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint16 *res_out);

Perror_t Pa_int32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint32 *res_out);

Perror_t Pa_int64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint64 *res_out);

Perror_t Pa_uint8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint8 *res_out);

Perror_t Pa_uint16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint16 *res_out);

Perror_t Pa_uint32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

Perror_t Pa_uint64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint64 *res_out);

/*@END Pint_app_3.tex*/

#endif
#endif /* P_CONFIG_READ_FUNCTIONS */

/*@BEGIN Pint_app_4.tex*/
/*
 * Fixed-width ASCII integer read functions:
 *    Like the above, only a fixed width in input characters is
 *    specified, and only those characters are examined.  E.g., input
 *    '11112222' could be used to read two fixed-width ASCII integers
 *    of width 4.
 *
 * N.B. The APIs require width > 0.  If width <= 0 is given, an
 * immediate error return occurs, without setting pd's location or
 * error code.
 */
/*@END Pint_app_4.tex*/
/*@BEGIN Pint_app_5.tex*/
/* Other differences from the variable-width read functions:
 *
 * 1. It is an error if the entire specified width is not an integer,
 *    e.g., for fixed width 4, input '111|' is an error
 *
 * 2. (pads->disc->flags & P_WSPACE_OK) indicates whether leading OR
 *    trailing spaces are OK, e.g., for fixed width 4, input ' 1 ' is not
 *    an error is wpace_ok is 1 (trailing white space is not an issue for
 *    variable-width routines)
 *
 * 3. If the specified width is available, it is always consumed, even
 *    if there is an error.  In this case
 *      + pd->loc.b/e is set to the first/last char of the fixed-width field
 *      + if P_Test_NotIgnore(*m), an error code is set,
 *         pd->nerr set to 1, and an error is reported
 *
 *    If the specified width is *not* available (EOR/EOF hit):
 *      + pd->loc.b/e set to elt/char position of start/end of 
 *          the 'too small' field
 *      + IO cursor is not advanced
 *      + if P_Test_NotIgnore(*m), pd->errCode set to P_WIDTH_NOT_AVAILABLE,
 *         pd->nerr set to 1, and an error is reported
 */
/*@END Pint_app_5.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_A_INT_FW > 0

/*@BEGIN Pint_app_6.tex*/

Perror_t Pa_int8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    size_t width
                    );

Perror_t Pa_int16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    size_t width
                    );

Perror_t Pa_int32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    size_t width
                    );

Perror_t Pa_int64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    size_t width
                    );

/*@END Pint_app_6.tex*/
/*@BEGIN Pint_app_7.tex*/

Perror_t Pa_uint8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    size_t width
                    );

Perror_t Pa_uint16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint16 *res_out, size_t width
                    );

Perror_t Pa_uint32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width
                    );

Perror_t Pa_uint64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint64 *res_out, size_t width
                    );

/*@END Pint_app_7.tex*/

#endif
#endif /* P_CONFIG_READ_FUNCTIONS */

/*@BEGIN Pint_app_8.tex*/
/* ================================================================================
 * EBCDIC STRING TO INTEGER READ FUNCTIONS
 *
 * These functions are just like their ASCII counterparts; the only
 * difference is the integers are encoding using EBCDIC string data.
 * The error codes used are also the same,
 * except that error code P_INVALID_E_NUM is used rather 
 * than P_INVALID_A_NUM
 */
/*@END Pint_app_8.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_9.tex*/

Perror_t Pe_int8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint8 *res_out);

Perror_t Pe_int16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint16 *res_out);

Perror_t Pe_int32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint32 *res_out);

Perror_t Pe_int64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint64 *res_out);

Perror_t Pe_uint8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint8 *res_out);

Perror_t Pe_uint16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint16 *res_out);

Perror_t Pe_uint32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

Perror_t Pe_uint64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint64 *res_out);

/*@END Pint_app_9.tex*/

#endif

#if P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_10.tex*/

Perror_t Pe_int8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    size_t width
                    );

Perror_t Pe_int16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    size_t width
                    );

Perror_t Pe_int32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    size_t width
                    );

Perror_t Pe_int64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    size_t width
                    );

/*@END Pint_app_10.tex*/
/*@BEGIN Pint_app_11.tex*/

Perror_t Pe_uint8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    size_t width
                    );

Perror_t Pe_uint16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint16 *res_out, size_t width
                    );

Perror_t Pe_uint32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width
                    );

Perror_t Pe_uint64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint64 *res_out, size_t width
                    );

/*@END Pint_app_11.tex*/

#endif
#endif /* P_CONFIG_READ_FUNCTIONS */

/*@BEGIN Pint_app_12.tex*/
/* ================================================================================
 * DEFAULT STRING TO INTEGER READ FUNCTIONS
 *
 * These functions select the appropriate ASCII or EBCDIC string to integer
 * function based on pads->disc->def_charset.
 *
 * Example: the call 
 *
 *     Pint8_read(pads, &m, &ed, *res)
 *
 * is converted to one of these forms:
 *
 *     Pa_int8_read(pads, &m, &ed, *res)
 *     Pe_int8_read(pads, &m, &ed, *res)
 *     etc.
 */
/*@END Pint_app_12.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0
#if P_CONFIG_A_INT > 0 && P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_13.tex*/

Perror_t Pint8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint8 *res_out);

Perror_t Pint16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint16 *res_out);

Perror_t Pint32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint32 *res_out);

Perror_t Pint64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint64 *res_out);

Perror_t Puint8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint8 *res_out);

Perror_t Puint16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint16 *res_out);

Perror_t Puint32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

Perror_t Puint64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint64 *res_out);

/*@END Pint_app_13.tex*/

#endif /* P_CONFIG_A_INT > 0 && P_CONFIG_E_INT > 0 */

#if P_CONFIG_A_INT_FW > 0 && P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_14.tex*/

Perror_t Pint8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint8 *res_out,
                    size_t width
                    );

Perror_t Pint16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint16 *res_out,
                    size_t width
                    );

Perror_t Pint32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    size_t width
                    );

Perror_t Pint64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint64 *res_out,
                    size_t width
                    );

/*@END Pint_app_14.tex*/
/*@BEGIN Pint_app_15.tex*/

Perror_t Puint8_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint8 *res_out,
                    size_t width
                    );

Perror_t Puint16_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint16 *res_out,
                    size_t width
                    );

Perror_t Puint32_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Puint64_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint64 *res_out,
                    size_t width
                    );

/*@END Pint_app_15.tex*/

#endif /* P_CONFIG_A_INT_FW > 0 && P_CONFIG_E_INT_FW > 0 */
#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/*@BEGIN Pint_app_16.tex*/
/* ================================================================================
 * WRITE
 */

/* ================================================================================
 * INTEGER/FPOINT WRITE FUNCTIONS
 * 
 * For each integer or fpoint read function there is a corresponding write2io
 * function and a corresponding write2buf function which output the specified
 * value in a format that will allow the corresponding read function to 
 * successfully read the value.
 *
 * For example, if a Pint8 is written using Pe_int8_write2io, the bytes
 * that were output can be read back into a Pint8 using Pe_int8_read.
 *
 * All write functions take an Sfio_t* stream pointer (the stream to write to),
 * a parse descriptor pd, and a pointer to the value to be written.  Some also take
 * additional arguments, such as num_digits.  All return an integer.
 *
 * If pd->errCode is either P_NO_ERR or P_USER_CONSTRAINT_VIOLATIONS then
 * the value is assumed to have been filled in, and it is the value written.
 * For other error codes, the value is assumed to *not* have been filled in,
 * and an error value is written.  See the Default Error Value discussion above
 * for the set of default error values and details on how to override them.
 *
 * If the write succeeds, the return value is the number of bytes written.
 * If it fails, -1 is returned, and no bytes are written to the stream.
 */
/*@END Pint_app_16.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0
#if P_CONFIG_A_INT > 0

/*@BEGIN Pint_app_17.tex*/
ssize_t Pa_int8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint8 *val);

ssize_t Pa_int16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint16 *val);

ssize_t Pa_int32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint32 *val);

ssize_t Pa_int64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint64 *val);

/*@END Pint_app_17.tex*/
/*@BEGIN Pint_app_18.tex*/

ssize_t Pa_uint8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint8 *val);

ssize_t Pa_uint16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint16 *val);

ssize_t Pa_uint32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *val);

ssize_t Pa_uint64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint64 *val);

/*@END Pint_app_18.tex*/
/*@BEGIN Pint_app_19.tex*/

ssize_t Pa_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_19.tex*/
/*@BEGIN Pint_app_20.tex*/

ssize_t Pa_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pa_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_20.tex*/
#endif

#if P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_21.tex*/

ssize_t Pe_int8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint8 *val);

ssize_t Pe_int16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint16 *val);

ssize_t Pe_int32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint32 *val);

ssize_t Pe_int64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint64 *val);

/*@END Pint_app_21.tex*/
/*@BEGIN Pint_app_22.tex*/

ssize_t Pe_uint8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint8 *val);

ssize_t Pe_uint16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint16 *val);

ssize_t Pe_uint32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *val);

ssize_t Pe_uint64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint64 *val);

/*@END Pint_app_22.tex*/
/*@BEGIN Pint_app_23.tex*/

ssize_t Pe_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_23.tex*/
/*@BEGIN Pint_app_24.tex*/

ssize_t Pe_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pe_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_24.tex*/

#endif

#if P_CONFIG_A_INT_FW > 0

/*@BEGIN Pint_app_25.tex*/

ssize_t Pa_int8_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    size_t width
                    );

ssize_t Pa_int16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    size_t width
                    );

ssize_t Pa_int32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    size_t width
                    );

ssize_t Pa_int64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    size_t width
                    );

/*@END Pint_app_25.tex*/
/*@BEGIN Pint_app_26.tex*/

ssize_t Pa_uint8_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    size_t width
                    );

ssize_t Pa_uint16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    size_t width
                    );

ssize_t Pa_uint32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    size_t width
                    );

ssize_t Pa_uint64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    size_t width
                    );

/*@END Pint_app_26.tex*/
/*@BEGIN Pint_app_27.tex*/

ssize_t Pa_int8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_int16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_int32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_int64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_27.tex*/
/*@BEGIN Pint_app_28.tex*/

ssize_t Pa_uint8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_uint16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_uint32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_uint64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_28.tex*/

#endif

#if P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_29.tex*/

ssize_t Pe_int8_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    size_t width
                    );

ssize_t Pe_int16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    size_t width
                    );

ssize_t Pe_int32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    size_t width
                    );

ssize_t Pe_int64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    size_t width
                    );

/*@END Pint_app_29.tex*/
/*@BEGIN Pint_app_30.tex*/

ssize_t Pe_uint8_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    size_t width
                    );

ssize_t Pe_uint16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    size_t width
                    );

ssize_t Pe_uint32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    size_t width
                    );

ssize_t Pe_uint64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    size_t width
                    );

/*@END Pint_app_30.tex*/
/*@BEGIN Pint_app_31.tex*/

ssize_t Pe_int8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_int16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_int32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_int64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_31.tex*/
/*@BEGIN Pint_app_32.tex*/

ssize_t Pe_uint8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_uint16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_uint32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_uint64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_32.tex*/

#endif

#if P_CONFIG_A_INT > 0

/*@BEGIN Pint_app_33.tex*/

ssize_t Pa_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val
                    );

ssize_t Pa_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val
                    );

ssize_t Pa_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val
                    );

ssize_t Pa_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val
                    );

/*@END Pint_app_33.tex*/
/*@BEGIN Pint_app_34.tex*/

ssize_t Pa_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val
                    );

ssize_t Pa_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val
                    );

ssize_t Pa_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val
                    );

ssize_t Pa_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val
                    );

/*@END Pint_app_34.tex*/
/*@BEGIN Pint_app_35.tex*/

ssize_t Pa_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent
                    );

ssize_t Pa_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, const char *tag, int indent
                    );

ssize_t Pa_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, const char *tag, int indent
                    );

ssize_t Pa_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_35.tex*/
/*@BEGIN Pint_app_36.tex*/

ssize_t Pa_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, const char *tag, int indent
                    );

ssize_t Pa_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, const char *tag, int indent
                    );

ssize_t Pa_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, const char *tag, int indent
                    );

ssize_t Pa_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_36.tex*/

#endif

#if P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_37.tex*/

ssize_t Pe_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val
                    );

ssize_t Pe_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val
                    );

ssize_t Pe_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val
                    );

ssize_t Pe_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val
                    );

/*@END Pint_app_37.tex*/
/*@BEGIN Pint_app_38.tex*/

ssize_t Pe_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val
                    );

ssize_t Pe_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val
                    );

ssize_t Pe_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val
                    );

ssize_t Pe_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val
                    );

/*@END Pint_app_38.tex*/
/*@BEGIN Pint_app_39.tex*/

ssize_t Pe_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent
                    );

ssize_t Pe_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, const char *tag, int indent
                    );

ssize_t Pe_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, const char *tag, int indent
                    );

ssize_t Pe_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_39.tex*/
/*@BEGIN Pint_app_40.tex*/

ssize_t Pe_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, const char *tag, int indent
                    );

ssize_t Pe_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, const char *tag, int indent
                    );

ssize_t Pe_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, const char *tag, int indent
                    );

ssize_t Pe_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_40.tex*/

#endif

#if P_CONFIG_A_INT_FW > 0

/*@BEGIN Pint_app_41.tex*/

ssize_t Pa_int8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, size_t width
                    );

ssize_t Pa_int16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, size_t width
                    );

ssize_t Pa_int32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, size_t width
                    );

ssize_t Pa_int64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, size_t width
                    );

/*@END Pint_app_41.tex*/
/*@BEGIN Pint_app_42.tex*/

ssize_t Pa_uint8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, size_t width
                    );

ssize_t Pa_uint16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, size_t width
                    );

ssize_t Pa_uint32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, size_t width
                    );

ssize_t Pa_uint64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, size_t width
                    );

/*@END Pint_app_42.tex*/
/*@BEGIN Pint_app_43.tex*/

ssize_t Pa_int8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint8 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_int16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint16 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_int32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_int64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint64 *val, const char *tag,
                    int indent, size_t width
                    );

/*@END Pint_app_43.tex*/
/*@BEGIN Pint_app_44.tex*/

ssize_t Pa_uint8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint8 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_uint16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_uint32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_uint64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, size_t width
                    );

/*@END Pint_app_44.tex*/

#endif

#if P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_45.tex*/

ssize_t Pe_int8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, size_t width
                    );

ssize_t Pe_int16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, size_t width
                    );

ssize_t Pe_int32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, size_t width
                    );

ssize_t Pe_int64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, size_t width
                    );

/*@END Pint_app_45.tex*/
/*@BEGIN Pint_app_46.tex*/

ssize_t Pe_uint8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, size_t width
                    );

ssize_t Pe_uint16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, size_t width
                    );

ssize_t Pe_uint32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, size_t width
                    );

ssize_t Pe_uint64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, size_t width
                    );

/*@END Pint_app_46.tex*/
/*@BEGIN Pint_app_47.tex*/

ssize_t Pe_int8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint8 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_int16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint16 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_int32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_int64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pint64 *val, const char *tag,
                    int indent, size_t width
                    );

/*@END Pint_app_47.tex*/
/*@BEGIN Pint_app_48.tex*/

ssize_t Pe_uint8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint8 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_uint16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_uint32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_uint64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, size_t width
                    );

/*@END Pint_app_48.tex*/

#endif

#if P_CONFIG_A_INT > 0

/*@BEGIN Pint_app_49.tex*/

ssize_t Pa_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pa_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pa_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pa_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pa_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pa_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pa_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

ssize_t Pa_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

/*@END Pint_app_49.tex*/
/*@BEGIN Pint_app_50.tex*/

ssize_t Pa_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pa_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pa_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pa_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pa_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pa_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pa_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

ssize_t Pa_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

/*@END Pint_app_50.tex*/
/*@BEGIN Pint_app_51.tex*/

ssize_t Pa_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint8 *rep
                    );

ssize_t Pa_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint16 *rep
                    );

ssize_t Pa_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint32 *rep
                    );

ssize_t Pa_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint64 *rep
                    );

ssize_t Pa_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint8 *rep
                    );

ssize_t Pa_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep
                    );

ssize_t Pa_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

ssize_t Pa_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep
                    );

/*@END Pint_app_51.tex*/

#endif

#if P_CONFIG_A_INT_FW > 0

/*@BEGIN Pint_app_52.tex*/

ssize_t Pa_int8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pa_int8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pa_int16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, size_t width
                    );

ssize_t Pa_int16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint16 *rep, size_t width
                    );

ssize_t Pa_int32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, size_t width
                    );

ssize_t Pa_int32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint32 *rep, size_t width
                    );

ssize_t Pa_int64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, size_t width
                    );

ssize_t Pa_int64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint64 *rep, size_t width
                    );

/*@END Pint_app_52.tex*/
/*@BEGIN Pint_app_53.tex*/

ssize_t Pa_uint8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, size_t width
                    );

ssize_t Pa_uint8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint8 *rep, size_t width
                    );

ssize_t Pa_uint16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, size_t width
                    );

ssize_t Pa_uint16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint16 *rep, size_t width
                    );

ssize_t Pa_uint32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_uint32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Pa_uint64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, size_t width
                    );

ssize_t Pa_uint64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint64 *rep, size_t width
                    );

/*@END Pint_app_53.tex*/
/*@BEGIN Pint_app_54.tex*/

ssize_t Pa_int8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint8 *rep,
                    size_t width
                    );

ssize_t Pa_int16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    size_t width
                    );

ssize_t Pa_int32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    size_t width
                    );

ssize_t Pa_int64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    size_t width
                    );

ssize_t Pa_uint8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    size_t width
                    );

ssize_t Pa_uint16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    size_t width
                    );

ssize_t Pa_uint32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pa_uint64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    size_t width
                    );

/*@END Pint_app_54.tex*/

#endif

#if P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_55.tex*/

ssize_t Pe_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pe_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pe_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pe_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pe_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pe_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pe_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

ssize_t Pe_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

/*@END Pint_app_55.tex*/
/*@BEGIN Pint_app_56.tex*/

ssize_t Pe_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pe_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pe_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pe_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pe_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pe_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pe_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

ssize_t Pe_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

/*@END Pint_app_56.tex*/
/*@BEGIN Pint_app_57.tex*/

ssize_t Pe_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint8 *rep
                    );

ssize_t Pe_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint16 *rep
                    );

ssize_t Pe_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint32 *rep
                    );

ssize_t Pe_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint64 *rep
                    );

ssize_t Pe_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint8 *rep
                    );

ssize_t Pe_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep
                    );

ssize_t Pe_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

ssize_t Pe_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep
                    );

/*@END Pint_app_57.tex*/

#endif

#if P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_58.tex*/

ssize_t Pe_int8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pe_int8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pe_int16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, size_t width
                    );

ssize_t Pe_int16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint16 *rep, size_t width
                    );

ssize_t Pe_int32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, size_t width
                    );

ssize_t Pe_int32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint32 *rep, size_t width
                    );

ssize_t Pe_int64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, size_t width
                    );

ssize_t Pe_int64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pint64 *rep, size_t width
                    );

/*@END Pint_app_58.tex*/
/*@BEGIN Pint_app_59.tex*/

ssize_t Pe_uint8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, size_t width
                    );

ssize_t Pe_uint8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint8 *rep, size_t width
                    );

ssize_t Pe_uint16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, size_t width
                    );

ssize_t Pe_uint16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint16 *rep, size_t width
                    );

ssize_t Pe_uint32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_uint32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Pe_uint64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, size_t width
                    );

ssize_t Pe_uint64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint64 *rep, size_t width
                    );

/*@END Pint_app_59.tex*/
/*@BEGIN Pint_app_60.tex*/

ssize_t Pe_int8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint8 *rep,
                    size_t width
                    );

ssize_t Pe_int16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    size_t width
                    );

ssize_t Pe_int32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    size_t width
                    );

ssize_t Pe_int64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    size_t width
                    );

ssize_t Pe_uint8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    size_t width
                    );

ssize_t Pe_uint16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    size_t width
                    );

ssize_t Pe_uint32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pe_uint64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    size_t width
                    );

/*@END Pint_app_60.tex*/

#endif

#if P_CONFIG_A_INT > 0 || P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_61.tex*/

ssize_t Pint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

ssize_t Pint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

/*@END Pint_app_61.tex*/
/*@BEGIN Pint_app_62.tex*/

ssize_t Puint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Puint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Puint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Puint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Puint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Puint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Puint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

ssize_t Puint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

/*@END Pint_app_62.tex*/
/*@BEGIN Pint_app_63.tex*/

ssize_t Pint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint8 *rep
                    );

ssize_t Pint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint16 *rep
                    );

ssize_t Pint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint32 *rep
                    );

ssize_t Pint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint64 *rep
                    );

ssize_t Puint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint8 *rep
                    );

ssize_t Puint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint16 *rep
                    );

ssize_t Puint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

ssize_t Puint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint64 *rep
                    );

/*@END Pint_app_63.tex*/

#endif

#if P_CONFIG_A_INT_FW > 0 || P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_64.tex*/

ssize_t Pint8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pint8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep, size_t width
                    );

ssize_t Pint16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, size_t width
                    );

ssize_t Pint16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep, size_t width
                    );

ssize_t Pint32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, size_t width
                    );

ssize_t Pint32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep, size_t width
                    );

ssize_t Pint64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, size_t width
                    );

ssize_t Pint64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep, size_t width
                    );

/*@END Pint_app_64.tex*/
/*@BEGIN Pint_app_65.tex*/

ssize_t Puint8_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, size_t width
                    );

ssize_t Puint8_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep, size_t width
                    );

ssize_t Puint16_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, size_t width
                    );

ssize_t Puint16_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep, size_t width
                    );

ssize_t Puint32_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Puint32_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Puint64_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, size_t width
                    );

ssize_t Puint64_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep, size_t width
                    );

/*@END Pint_app_65.tex*/
/*@BEGIN Pint_app_66.tex*/

ssize_t Pint8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint8 *rep, size_t width
                    );

ssize_t Pint16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint16 *rep,
                    size_t width
                    );

ssize_t Pint32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint32 *rep,
                    size_t width
                    );

ssize_t Pint64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pint64 *rep,
                    size_t width
                    );

ssize_t Puint8_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint8 *rep,
                    size_t width
                    );

ssize_t Puint16_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep,
                    size_t width
                    );

ssize_t Puint32_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Puint64_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep,
                    size_t width
                    );

/*@END Pint_app_66.tex*/

#endif

/*
 * The following default versions simply call the appropriate ASCII or EBCDIC version,
 * depending on pads->disc->def_charset.
 */

#ifdef FOR_CKIT
#if P_CONFIG_A_INT_FW > 0 && P_CONFIG_E_INT_FW > 0

/*@BEGIN Pint_app_67.tex*/

ssize_t Pint8_FW_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint8 *val,size_t width);

ssize_t Pint16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    size_t width
                    );

ssize_t Pint32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    size_t width
                    );

ssize_t Pint64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    size_t width
                    );

ssize_t Puint8_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    size_t width
                    );

ssize_t Puint16_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    size_t width
                    );

ssize_t Puint32_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    size_t width
                    );

ssize_t Puint64_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    size_t width
                    );

/*@END Pint_app_67.tex*/
/*@BEGIN Pint_app_68.tex*/

ssize_t Pint8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, size_t width
                    );

ssize_t Pint16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, size_t width
                    );

ssize_t Pint32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, size_t width
                    );

ssize_t Pint64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, size_t width
                    );

/*@END Pint_app_68.tex*/
/*@BEGIN Pint_app_69.tex*/

ssize_t Puint8_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, size_t width
                    );

ssize_t Puint16_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, size_t width
                    );

ssize_t Puint32_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, size_t width
                    );

ssize_t Puint64_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, size_t width
                    );

/*@END Pint_app_69.tex*/
/*@BEGIN Pint_app_70.tex*/

ssize_t Pint8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pint16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pint32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pint64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_70.tex*/
/*@BEGIN Pint_app_71.tex*/

ssize_t Puint8_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Puint16_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Puint32_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent, size_t width
                    );

ssize_t Puint64_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent, size_t width
                    );

/*@END Pint_app_71.tex*/
/*@BEGIN Pint_app_72.tex*/

ssize_t Pint8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent,
                    size_t width
                    );

ssize_t Pint16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, const char *tag, int indent,
                    size_t width
                    );

ssize_t Pint32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, const char *tag, int indent,
                    size_t width
                    );

ssize_t Pint64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, const char *tag, int indent,
                    size_t width
                    );

/*@END Pint_app_72.tex*/
/*@BEGIN Pint_app_73.tex*/

ssize_t Puint8_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, const char *tag, int indent,
                    size_t width
                    );

ssize_t Puint16_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint16 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Puint32_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *val, const char *tag,
                    int indent, size_t width
                    );

ssize_t Puint64_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint64 *val, const char *tag,
                    int indent, size_t width
                    );

/*@END Pint_app_73.tex*/

#endif /*  P_CONFIG_A_INT_FW > 0 && P_CONFIG_E_INT_FW > 0  */
#endif /* FOR_CKIT */

#ifdef FOR_CKIT
#if P_CONFIG_A_INT > 0 && P_CONFIG_E_INT > 0

/*@BEGIN Pint_app_74.tex*/

ssize_t Pint8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint8 *val);

ssize_t Pint16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint16 *val);

ssize_t Pint32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint32 *val);

ssize_t Pint64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint64 *val);

/*@END Pint_app_74.tex*/
/*@BEGIN Pint_app_75.tex*/

ssize_t Puint8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint8 *val);

ssize_t Puint16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint16 *val);

ssize_t Puint32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *val);

ssize_t Puint64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint64 *val);

/*@END Pint_app_75.tex*/
/*@BEGIN Pint_app_76.tex*/

ssize_t Pint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val
                    );

ssize_t Pint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val
                    );

ssize_t Pint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val
                    );

ssize_t Pint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val
                    );

/*@END Pint_app_76.tex*/
/*@BEGIN Pint_app_77.tex*/

ssize_t Puint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val
                    );

ssize_t Puint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val
                    );

ssize_t Puint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val
                    );

ssize_t Puint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val
                    );

/*@END Pint_app_77.tex*/
/*@BEGIN Pint_app_78.tex*/

ssize_t Pint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_78.tex*/
/*@BEGIN Pint_app_79.tex*/

ssize_t Puint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent
                    );

ssize_t Puint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent
                    );

ssize_t Puint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent
                    );

ssize_t Puint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent
                    );

/*@END Pint_app_79.tex*/
/*@BEGIN Pint_app_80.tex*/

ssize_t Pint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent
                    );

ssize_t Pint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, const char *tag, int indent
                    );

ssize_t Pint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, const char *tag, int indent
                    );

ssize_t Pint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_80.tex*/
/*@BEGIN Pint_app_81.tex*/

ssize_t Puint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, const char *tag, int indent
                    );

ssize_t Puint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, const char *tag, int indent
                    );

ssize_t Puint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, const char *tag, int indent
                    );

ssize_t Puint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, const char *tag, int indent
                    );

/*@END Pint_app_81.tex*/

#endif /*  P_CONFIG_A_INT > 0 && P_CONFIG_E_INT > 0  */
#endif /* FOR_CKIT */

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif /*  __PINT_H__  */

