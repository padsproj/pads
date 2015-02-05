/*@FILE Pstring_app_1.tex Pstring_app_2.tex Pstring_app_3.tex Pstring_app_4.tex Pstring_app_5.tex Pstring_app_6.tex Pstring_app_7.tex Pstring_app_8.tex Pstring_app_9.tex Pstring_app_10.tex Pstring_app_11.tex Pstring_app_12.tex Pstring_app_13.tex Pstring_app_14.tex Pstring_app_15.tex Pstring_app_16.tex Pstring_app_17.tex Pstring_app_18.tex Pstring_app_19.tex Pstring_app_20.tex Pstring_app_21.tex Pstring_app_22.tex Pstring_app_23.tex Pstring_app_24.tex Pstring_app_25.tex Pstring_app_26.tex Pstring_app_27.tex Pstring_app_28.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PSTRING_H__
#define __PSTRING_H__

#ifndef __PADS_H__
#error Pstring.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pstring_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * STRING READ FUNCTIONS
 *
 * DEFAULT                      ASCII                          EBCDIC
 * --------------------------  -----------------------------  -------------------
 * Pstring_FW_read             Pa_string_FW_read              Pe_string_FW_read
 * Pstring_read                Pa_string_read                 Pe_string_read
 * Pstring_ME_read             Pa_string_ME_read              Pe_string_ME_read
 * Pstring_CME_read            Pa_string_CME_read             Pe_string_CME_read
 * Pstring_SE_read             Pa_string_SE_read              Pe_string_SE_read
 * Pstring_CSE_read            Pa_string_CSE_read             Pe_string_CSE_read
 *
 * The string read functions each has a different way of specifying
 * the extent of the string:
 *   + all string_FW_read functions specify a fixed width.
 *     N.B.: width zero is allowed: the result is an empty string
 *       (and the IO cursor does not move)
 *   + all string_read functions specify a single stop character.
 *       if 0 (NULL) is used, then this will match a NULL in the data,
 *       and eor/eof will ALSO successfully terminate the string 
 *   + all string_ME_read and string_CME_read functions specify a
 *       Match Expression (string includes all chars that match)
 *   + all string_SE_read and string_CSE_read specify a Stop Expression
 *       (string terminated by encountering 'stop chars' that match)
 */
/*@END Pstring_app_1.tex*/
/*@BEGIN Pstring_app_2.tex*/
/*
 * The ME/SE functions take a string containing a regular expression,
 * while the CME/CSE functions take a compiled form of regular
 * expression (see Pregexp_compile).
 *
 * stop chars and regular expressions are specified using ASCII, but
 * reading/matching occurs using converted EBCDIC forms if an EBCDIC
 * form is used or if a DEFAULT form is used and
 * pads->disc->def_charset is Pcharset_EBCDIC.
 * 
 * For all stop cases, the stop char/chars are not included in the
 * resulting string.  Note that if the IO cursor is already at a stop
 * condition, then a string of length zero results.
 *
 * If an expected stop char/pattern/width is found, P_OK is returned.
 * If P_TestSet(*m) then:

 *   + (*s_out) is set to contain an in-memory string.  If the
 *     original data is ASCII, then s_out will either share the string
 *     or contain a copy of the string, depending on
 *     pads->disc->copy_strings.  If the original data is EBCDIC, s_out
 *     always contains a copy of the string that has been converted to
 *     ASCII.  N.B. : (*s_out) should have been initialized at some
 *     point prior using Pstring_init or one of the initializing
 *     P_STRING macros.  (It can be initialized once and re-used in
 *     string read calls many times.)
 */ 
/*@END Pstring_app_2.tex*/
/*@BEGIN Pstring_app_3.tex*/
/* Cleanup note: If pads->disc->copy_strings is non-zero, the memory
 * allocated in (*s_out) should ultimately be freed using
 * Pstring_cleanup.
 *
 * If an expected stop condition is not encountered, the
 * IO cursor position is unchanged.  Error codes used:
 *     P_WIDTH_NOT_AVAILABLE
 *     P_STOPCHAR_NOT_FOUND
 *     P_STOPREGEXP_NOT_FOUND
 *     P_INVALID_REGEXP
 * 
 * EBCDIC Example: passing '|' (vertical bar, which is code 124 in
 * ASCII) to Pe_string_read as the stop char will result in a search
 * for the EBCDIC encoding of vertical bar (code 79 in EBCDIC), and
 * (*s_out) will be a string containing all chars between the IO
 * cursor and the EBCDIC vertical bar, with each EBCDIC char converted
 * to ASCII.
 */
/*@END Pstring_app_3.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pstring_app_4.tex*/

Perror_t Pa_string_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    size_t width
                    );

Perror_t Pa_string_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pchar stopChar
                    );

Perror_t Pa_string_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *matchRegexp
                    );

Perror_t Pa_string_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pa_string_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *stopRegexp
                    );

Perror_t Pa_string_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_4.tex*/

#endif

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_5.tex*/

Perror_t Pe_string_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    size_t width
                    );

Perror_t Pe_string_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pchar stopChar
                    );

Perror_t Pe_string_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *matchRegexp
                    );

Perror_t Pe_string_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pe_string_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *stopRegexp
                    );

Perror_t Pe_string_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_5.tex*/

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_6.tex*/

Perror_t Pstring_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    size_t width
                    );

Perror_t Pstring_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pchar stopChar
                    );

Perror_t Pstring_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *matchRegexp
                    );

Perror_t Pstring_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pstring_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    const char *stopRegexp
                    );

Perror_t Pstring_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pstring *s_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_6.tex*/

#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/*@BEGIN Pstring_app_7.tex*/
/* ================================================================================
 * WRITE
 */

/* ================================================================================
 * STRING WRITE FUNCTIONS
 * DEFAULT                      ASCII                          EBCDIC
 * -------------------------  -----------------------------  ----------------------
 * Pstring_FW_write2io        Pa_string_FW_write2io          Pe_string_FW_write2io
 * Pstring_write2io           Pa_string_write2io             Pe_string_write2io
 * Pstring_ME_write2io        Pa_string_ME_write2io          Pe_string_ME_write2io
 * Pstring_CME_write2io       Pa_string_CME_write2io         Pe_string_CME_write2io
 * Pstring_SE_write2io        Pa_string_SE_write2io          Pe_string_SE_write2io
 * Pstring_CSE_write2io       Pa_string_CSE_write2io         Pe_string_CSE_write2io
 *
 * Pstring_FW_write2buf       Pa_string_FW_write2buf         Pe_string_FW_write2buf
 * Pstring_write2buf          Pa_string_write2buf            Pe_string_write2buf
 * Pstring_ME_write2buf       Pa_string_ME_write2buf         Pe_string_ME_write2buf
 * Pstring_CME_write2buf      Pa_string_CME_write2buf        Pe_string_CME_write2buf
 * Pstring_SE_write2buf       Pa_string_SE_write2buf         Pe_string_SE_write2buf
 * Pstring_CSE_write2buf      Pa_string_CSE_write2buf        Pe_string_CSE_write2buf
 */
/*@END Pstring_app_7.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0

#ifdef FOR_CKIT
#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pstring_app_8.tex*/

ssize_t Pa_string_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    size_t width
                    );

ssize_t Pa_string_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, size_t width
                    );

ssize_t Pa_string_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pchar stopChar
                    );

ssize_t Pa_string_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pchar stopChar
                    );

ssize_t Pa_string_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *matchRegexp
                    );

ssize_t Pa_string_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *matchRegexp
                    );

/*@END Pstring_app_8.tex*/
/*@BEGIN Pstring_app_9.tex*/

ssize_t Pa_string_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *stopRegexp
                    );

ssize_t Pa_string_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *stopRegexp
                    );

ssize_t Pa_string_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pa_string_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_9.tex*/
/*@BEGIN Pstring_app_10.tex*/

ssize_t Pa_string_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_string_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_string_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pa_string_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pa_string_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pa_string_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pstring_app_10.tex*/
/*@BEGIN Pstring_app_11.tex*/

ssize_t Pa_string_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pa_string_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pa_string_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pa_string_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_11.tex*/

#endif /* P_CONFIG_A_CHAR_STRING > 0 */
#endif /* FOR_CKIT */

#ifdef FOR_CKIT
#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_12.tex*/

ssize_t Pe_string_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    size_t width
                    );

ssize_t Pe_string_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, size_t width
                    );

ssize_t Pe_string_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pchar stopChar
                    );

ssize_t Pe_string_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pchar stopChar
                    );

ssize_t Pe_string_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *matchRegexp
                    );

ssize_t Pe_string_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *matchRegexp
                    );

/*@END Pstring_app_12.tex*/
/*@BEGIN Pstring_app_13.tex*/

ssize_t Pe_string_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *stopRegexp
                    );

ssize_t Pe_string_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *stopRegexp
                    );

ssize_t Pe_string_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pe_string_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_13.tex*/
/*@BEGIN Pstring_app_14.tex*/

ssize_t Pe_string_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_string_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_string_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pe_string_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pe_string_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pe_string_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pstring_app_14.tex*/
/*@BEGIN Pstring_app_15.tex*/

ssize_t Pe_string_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pe_string_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pe_string_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pe_string_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_15.tex*/

#endif /* P_CONFIG_E_CHAR_STRING > 0 */
#endif /* FOR_CKIT */

#ifdef FOR_CKIT
#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_16.tex*/

ssize_t Pstring_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    size_t width
                    );

ssize_t Pstring_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, size_t width
                    );

ssize_t Pstring_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pchar stopChar
                    );

ssize_t Pstring_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pchar stopChar
                    );

ssize_t Pstring_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *matchRegexp
                    );

ssize_t Pstring_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *matchRegexp
                    );

/*@END Pstring_app_16.tex*/
/*@BEGIN Pstring_app_17.tex*/

ssize_t Pstring_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pstring_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *matchRegexp
                    );

ssize_t Pstring_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *stopRegexp
                    );

ssize_t Pstring_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *stopRegexp
                    );

ssize_t Pstring_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pstring_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_17.tex*/
/*@BEGIN Pstring_app_18.tex*/

ssize_t Pstring_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pstring_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pstring_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pstring_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pstring *s, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pstring_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pstring_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pstring_app_18.tex*/
/*@BEGIN Pstring_app_19.tex*/

ssize_t Pstring_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pstring_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pstring_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pstring_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pstring_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pstring *s,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pstring_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pstring *s, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_19.tex*/

#endif /* P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0 */
#endif /* FOR_CKIT */

#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pstring_app_20.tex*/

ssize_t Pa_string_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, size_t width
                    );

ssize_t Pa_string_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, size_t width
                    );

ssize_t Pa_string_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pa_string_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pa_string_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *matchRegexp
                    );

ssize_t Pa_string_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, const char *matchRegexp
                    );

/*@END Pstring_app_20.tex*/
/*@BEGIN Pstring_app_21.tex*/

ssize_t Pa_string_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *stopRegexp
                    );

ssize_t Pa_string_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, const char *stopRegexp
                    );

ssize_t Pa_string_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pa_string_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_21.tex*/
/*@BEGIN Pstring_app_22.tex*/

ssize_t Pa_string_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    size_t width
                    );

ssize_t Pa_string_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pchar stopChar
                    );

ssize_t Pa_string_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *matchRegexp
                    );

ssize_t Pa_string_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_string_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *stopRegexp
                    );

ssize_t Pa_string_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_22.tex*/

#endif /* P_CONFIG_A_CHAR_STRING > 0 */

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_23.tex*/

ssize_t Pe_string_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, size_t width
                    );

ssize_t Pe_string_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, size_t width
                    );

ssize_t Pe_string_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pe_string_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pe_string_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *matchRegexp
                    );

ssize_t Pe_string_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, const char *matchRegexp
                    );

/*@END Pstring_app_23.tex*/
/*@BEGIN Pstring_app_24.tex*/

ssize_t Pe_string_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *stopRegexp
                    );

ssize_t Pe_string_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, const char *stopRegexp
                    );

ssize_t Pe_string_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pe_string_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_24.tex*/
/*@BEGIN Pstring_app_25.tex*/

ssize_t Pe_string_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    size_t width
                    );

ssize_t Pe_string_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pchar stopChar
                    );

ssize_t Pe_string_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *matchRegexp
                    );

ssize_t Pe_string_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_string_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *stopRegexp
                    );

ssize_t Pe_string_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_25.tex*/

#endif /* P_CONFIG_E_CHAR_STRING > 0 */

#if P_CONFIG_A_CHAR_STRING > 0 || P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pstring_app_26.tex*/

ssize_t Pstring_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, size_t width
                    );

ssize_t Pstring_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, size_t width
                    );

ssize_t Pstring_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pstring_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pchar stopChar
                    );

ssize_t Pstring_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *matchRegexp
                    );

ssize_t Pstring_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *matchRegexp
                    );

/*@END Pstring_app_26.tex*/
/*@BEGIN Pstring_app_27.tex*/

ssize_t Pstring_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pstring_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pstring_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *stopRegexp
                    );

ssize_t Pstring_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, const char *stopRegexp
                    );

ssize_t Pstring_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pstring *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pstring_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Pstring *rep, Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_27.tex*/
/*@BEGIN Pstring_app_28.tex*/

ssize_t Pstring_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    size_t width
                    );

ssize_t Pstring_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pstring *rep, Pchar stopChar
                    );

ssize_t Pstring_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *matchRegexp
                    );

ssize_t Pstring_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pstring_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    const char *stopRegexp
                    );

ssize_t Pstring_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Pstring *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pstring_app_28.tex*/

#endif /* P_CONFIG_A_CHAR_STRING > 0 || P_CONFIG_E_CHAR_STRING > 0 */

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif /*  __PSTRING_H__  */

