/*@FILE Pchar_app_1.tex Pchar_app_2.tex Pchar_app_3.tex Pchar_app_4.tex Pchar_app_5.tex Pchar_app_6.tex Pchar_app_7.tex Pchar_app_8.tex Pchar_app_9.tex Pchar_app_10.tex Pchar_app_11.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCHAR_H__
#define __PCHAR_H__

#ifndef __PCHAR_H__
#error Pcharh is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pchar_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * CHAR READ FUNCTIONS
 * 
 * DEFAULT                   ASCII                     EBCDIC
 * ------------------------  ------------------------  ----------------------------
 * Pchar_read                Pa_char_read              Pe_char_read
 *
 * Cases:
 *  (1) A character is not available:
 *        + pd->loc set to the current IO position
 *        + if P_Test_NotIgnore(*m), pd->errCode is set to
 *            P_WIDTH_NOT_AVAILABLE, pd->nerr is set to 1,
 *            and an error is reported
 *        + the IO cursor is not advanced
 *        + P_ERR is returned
 *  (2) A character is available and P_Test_NotSet(*m)
 *        + the IO cursor is advanced by 1 byte
 *        + P_OK is returned
 *  (3) A character is available and P_Test_Set(*m)
 *        + (*c_out) is set to the ASCII equivalent of the character, where
 *             a conversion fom EBCDIC to ASCII occurs if the EBCDIC form is
 *             used or if the DEFAULT form is used and
 *             pads->disc->def_charset is Pcharset_EBCDIC.
 *        + the IO cursor is advanced by 1 byte
 *        + P_OK is returned
 */
/*@END Pchar_app_1.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0
/*@BEGIN Pchar_app_2.tex*/

Perror_t Pa_char_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pchar *c_out);

/*@END Pchar_app_2.tex*/
#endif

#if P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_3.tex*/

Perror_t Pe_char_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pchar *c_out);

/*@END Pchar_app_3.tex*/
#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_4.tex*/

Perror_t Pchar_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pchar *c_out);

/*@END Pchar_app_4.tex*/
#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/*@BEGIN Pchar_app_5.tex*/
/* ================================================================================
 * WRITE
 */

/* ================================================================================
 * CHAR WRITE FUNCTIONS
 * DEFAULT                     ASCII                        EBCDIC
 * --------------------------  ---------------------------  -----------------------
 * Pchar_write2io              Pa_char_write2io             Pe_char_write2io
 *
 * Pchar_write2buf             Pa_char_write2buf            Pe_char_write2buf
 */
/*@END Pchar_app_5.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0

#ifdef FOR_CKIT
#if P_CONFIG_A_CHAR_STRING > 0
/*@BEGIN Pchar_app_6.tex*/

ssize_t Pa_char_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pchar *c);

ssize_t Pa_char_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pchar *c
                    );

ssize_t Pa_char_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pchar *c,
                    const char *tag, int indent
                    );

ssize_t Pa_char_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Pchar *c, const char *tag,
                    int indent
                    );

/*@END Pchar_app_6.tex*/
#endif

#if P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_7.tex*/

ssize_t Pe_char_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pchar *c);

ssize_t Pe_char_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pchar *c
                    );

ssize_t Pe_char_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pchar *c,
                    const char *tag, int indent
                    );

ssize_t Pe_char_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pchar *c, const char *tag, int indent
                    );

/*@END Pchar_app_7.tex*/
#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_8.tex*/

ssize_t Pchar_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pchar *c);

ssize_t Pchar_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pchar *c
                    );

ssize_t Pchar_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pchar *c,
                    const char *tag, int indent
                    );

ssize_t Pchar_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pchar *c, const char *tag, int indent
                    );

/*@END Pchar_app_8.tex*/
#endif
#endif /* FOR_CKIT */

#if P_CONFIG_A_CHAR_STRING > 0
/*@BEGIN Pchar_app_9.tex*/

ssize_t Pa_char_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pa_char_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pa_char_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pchar *rep
                    );

/*@END Pchar_app_9.tex*/
#endif

#if P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_10.tex*/

ssize_t Pe_char_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pe_char_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pe_char_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pchar *rep
                    );

/*@END Pchar_app_10.tex*/
#endif

#if P_CONFIG_A_CHAR_STRING > 0 || P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pchar_app_11.tex*/

ssize_t Pchar_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pchar_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pchar *rep
                    );

ssize_t Pchar_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pchar *rep
                    );

/*@END Pchar_app_11.tex*/
#endif

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif /*  __PCHAR_H__  */
