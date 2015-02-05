/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCSTR_LIT_H__
#define __PCSTR_LIT_H__

#ifndef __PADS_H__
#error Pcstr_lit.h is intended to be included from pads.h, do not include it directly
#endif

/* ================================================================================
 * DEFAULT                        ASCII                          EBCDIC
 * -----------------------------  -----------------------------  -----------------------------
 * Pcstr_lit_read                 Pa_cstr_lit_read               Pe_cstr_lit_read
 * 
 * These literal read functions take a string to be read specified in
 * ASCII.  The string is converted to EBCDIC if the EBCDIC form is
 * used or if the DEFAULT forms is used and pads->disc->def_charset is
 * Pcharset_EBCDIC.
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
 * The error code is P_STR_LIT_NOT_FOUND.
 */

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

Perror_t Pa_cstr_lit_read(P_t *pads, const Pbase_m *m, const char *s, Pbase_pd *pd,
                    Pstring *s_out
                    );

#endif

#if P_CONFIG_E_CHAR_STRING > 0

Perror_t Pe_cstr_lit_read(P_t *pads, const Pbase_m *m, const char *s, Pbase_pd *pd,
                    Pstring *s_out
                    );

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

Perror_t Pcstr_lit_read(P_t *pads, const Pbase_m *m, const char *s, Pbase_pd *pd,
                    Pstring *s_out
                    );

#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/* ================================================================================
 * WRITE
 */

#ifdef FOR_CKIT
#if P_CONFIG_WRITE_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

ssize_t Pa_cstr_lit_write2io(P_t *pads,Sfio_t *io,const char *s);

ssize_t Pa_cstr_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    const char *s
                    );

ssize_t Pa_cstr_lit_write_xml_2io(P_t *pads, Sfio_t *io, const char *s,
                    const char *tag, int indent
                    );

ssize_t Pa_cstr_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, const char *s, const char *tag, int indent
                    );

#endif

#if P_CONFIG_E_CHAR_STRING > 0

ssize_t Pe_cstr_lit_write2io(P_t *pads,Sfio_t *io,const char *s);

ssize_t Pe_cstr_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    const char *s
                    );

ssize_t Pe_cstr_lit_write_xml_2io(P_t *pads, Sfio_t *io, const char *s,
                    const char *tag, int indent
                    );

ssize_t Pe_cstr_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, const char *s, const char *tag, int indent
                    );

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

ssize_t Pcstr_lit_write2io(P_t *pads,Sfio_t *io,const char *s);

ssize_t Pcstr_lit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    const char *s
                    );

ssize_t Pcstr_lit_write_xml_2io(P_t *pads, Sfio_t *io, const char *s, const char *tag,
                    int indent
                    );

ssize_t Pcstr_lit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    const char *s, const char *tag, int indent
                    );

#endif

#endif /* P_CONFIG_WRITE_FUNCTIONS */
#endif /* FOR_CKIT */

#endif /*  __PSTR_LIT_H__  */

