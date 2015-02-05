/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCHAR_LIT_H__
#define __PCHAR_LIT_H__

#ifndef __PADS_H__
#error Pchar_lit.h is intended to be included from pads.h, do not include it directly
#endif

/* ================================================================================
 * DEFAULT                        ASCII                          EBCDIC
 * -----------------------------  -----------------------------  -----------------------------
 * Pchar_lit_read                 Pa_char_lit_read               Pe_char_lit_read
 * Pstr_lit_read                  Pa_str_lit_read                Pe_str_lit_read
 * Pcstr_lit_read                 Pa_cstr_lit_read               Pe_cstr_lit_read
 * 
 * These char and string literal read functions all take an char or string to be
 * read specified in ASCII.  The char or string is converted to EBCDIC if one of
 * the EBCDIC forms is used or if one of the DEFAULT forms is used and
 * pads->disc->def_charset is Pcharset_EBCDIC.
 *
 * Mask flags control the behavior, as follows:
 *
 *
 * P_Test_SynCheck(*m)                 P_Test_NoSynCheck(*m)
 * ---------------------------------   ------------------------------
 * If IO cursor points to specified    Always advance cursor by length
 * literal, advance cursor by length   of literal, regardless of what
 * of the literal and return P_OK,     cursor points to, and return
 * otherwise report error, do not      P_OK.
 * advance cursor, return P_ERR.
 * 
 * The error code used is either P_CHAR_LIT_NOT_FOUND or P_STR_LIT_NOT_FOUND.
 */

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

Perror_t Pa_char_lit_read(P_t *pads, const Pbase_m *m, Pchar c, Pbase_pd *pd,
                    Pchar *c_out
                    );

#endif

#if P_CONFIG_E_CHAR_STRING > 0

Perror_t Pe_char_lit_read(P_t *pads, const Pbase_m *m, Pchar c, Pbase_pd *pd,
                    Pchar *c_out
                    );

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

Perror_t Pchar_lit_read(P_t *pads, const Pbase_m *m, Pchar c, Pbase_pd *pd,
                    Pchar *c_out
                    );

#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/* ================================================================================
 * WRITE
 */

/* ================================================================================
 * LITERAL WRITE FUNCTIONS
 *   Literal write functions: write a char or string to an sfio stream or buffer.
 *   Typically used with a literal argument, as in 
 *      Pa_cstr_lit_write(pads, io, "hello");
 *   Note that these are similar to Pa_char and Pa_string write functions
 *   except there is no Pbase_pd argument since literals have no errors.
 *
 * XXX_TODOC
 */

#ifdef FOR_CKIT
#if P_CONFIG_WRITE_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

ssize_t Pa_char_lit_write2io(P_t *pads,Sfio_t *io,Pchar c);

ssize_t Pa_char_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pchar c
                    );

ssize_t Pa_char_lit_write_xml_2io(P_t *pads, Sfio_t *io, Pchar c, const char *tag,
                    int indent
                    );

ssize_t Pa_char_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pchar c, const char *tag, int indent
                    );

#endif

#if P_CONFIG_E_CHAR_STRING > 0

ssize_t Pe_char_lit_write2io(P_t *pads,Sfio_t *io,Pchar c);

ssize_t Pe_char_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pchar c
                    );

ssize_t Pe_char_lit_write_xml_2io(P_t *pads, Sfio_t *io, Pchar c, const char *tag,
                    int indent
                    );

ssize_t Pe_char_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pchar c, const char *tag, int indent
                    );

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

ssize_t Pchar_lit_write2io(P_t *pads,Sfio_t *io,Pchar c);

ssize_t Pchar_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pchar c
                    );

ssize_t Pchar_lit_write_xml_2io(P_t *pads, Sfio_t *io, Pchar c, const char *tag,
                    int indent
                    );

ssize_t Pchar_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pchar c, const char *tag, int indent
                    );

#endif

#endif /* P_CONFIG_WRITE_FUNCTIONS */
#endif /* FOR_CKIT */

#endif /*  __PCHAR_LIT_H__  */
