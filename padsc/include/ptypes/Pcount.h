/*@FILE Pcount_app_1.tex Pcount_app_2.tex Pcount_app_3.tex Pcount_app_4.tex Pcount_app_5.tex Pcount_app_6.tex Pcount_app_7.tex Pcount_app_8.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PCOUNT_H__
#define __PCOUNT_H__

#ifndef __PADS_H__
#error Pcount.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pcount_app_1.tex*/
/* ================================================================================
 * CHAR COUNTING FUNCTIONS
 *
 * DEFAULT                     ASCII                       EBCDIC
 * --------------------------  --------------------------  ------------------------
 * PcountX_read                Pa_countX_read              Pe_countX_read
 * PcountXtoY                  Pa_countXtoY_read           Pe_countXtoY_read
 *
 * countX counts occurrences of char x between the current IO cursor
 * and the first EOR or EOF, while countXtoY counts occurrences of x
 * between the current IO cursor and the first occurrence of char y.
 * x and y are always specified as ASCII chars.  They are converted to
 * EBCDIC if the EBCDIC form is used or if the DEFAULT form is used
 * and pads->disc->def->charset is Pcharset_EBCDIC.
 *
 * If parameter count_max is non-zero, then the count functions also
 * stop counting after scanning count_max characters, in which case an
 * error is returned.  If the IO discipline is not record-based and
 * count_max is zero, an error is returned immediately: you *must*
 * specify a count_max > 0 when using an IO discipline that has no
 * records.
 */
/*@END Pcount_app_1.tex*/
/*@BEGIN Pcount_app_2.tex*/
/*
 * For countX, if param eor_required is non-zero, then encountering EOF
 * before EOR produces an error.
 *
 * These functions do not change the IO cursor position.
 *
 * countX outcomes:
 *   1. IO cursor is already at EOF and eor_required is non-zero:
 *     + pd->loc.b/e set to EOF 'location'
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_AT_EOF,
 *         pd->nerr set to 1, and an error is reported
 *     + P_ERR returned   
 *   2. EOF is encountered before EOR and eor_required is non-zero:
 *     + pd->loc.b/e set to current IO cursor location
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_EOF_BEFORE_EOR,
 *         pd->nerr set to 1, and an error is reported
 *     + P_ERR returned
 *   3. count_max is > 0 and count_max limit is reached before x
 *       or EOR or EOF:
 *     + pd->loc.b/e set to current IO cursor location
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_COUNT_MAX_LIMIT,
 *         pd->nerr set to 1, and an error is reported
 *     + P_ERR returned
 *   4. EOR is encountered, or EOF is encounterd and eor_required is zero:
 *     + (*res_out) is set to the number of occurrences of x from the
 *        IO cursor to EOR/EOF
 *     + P_OK returned
 */
/*@END Pcount_app_2.tex*/
/*@BEGIN Pcount_app_3.tex*/
/*
 * countXtoY outcomes:
 *   1. IO cursor is already at EOF
 *     + pd->loc.b/e set to EOF 'location'
 *     + if P_Test_NotIgnore(*m), pd->errCode set to P_AT_EOF,
 *         pd->nerr set to 1, and an error is reported
 *     + P_ERR returned   
 *   2. y is not found before EOR or EOF is hit
 *     + pd->loc.b/e set to current IO cursor location
 *     + if P_Test_NotIgnore(*m), pd->errCode set to
 *         P_CHAR_LIT_NOT_FOUND, pd->nerr set to 1,
 *         and an error is reported
 *     + P_ERR returned
 *   3. y is not found and count_max > 0 and count_max limit is hit 
 *     + pd->loc.b/e set to current IO cursor location
 *     + if P_Test_NotIgnore(*), pd->errCode set to P_COUNT_MAX_LIMIT,
 *         pd->nerr set to 1, and an error is reported
 *     P_ERR returned
 *   4. Char y is found
 *     + (*res_out) is set to the number of occurrences of x
 *       from the IO cursor to first y
 *     + P_OK returned
 */
/*@END Pcount_app_3.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0
/*@BEGIN Pcount_app_4.tex*/

Perror_t Pa_countX_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, int eor_required, size_t count_max
                    );

Perror_t Pa_countXtoY_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, Puint8 y, size_t count_max
                    );

/*@END Pcount_app_4.tex*/
#endif

#if P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pcount_app_5.tex*/

Perror_t Pe_countX_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, int eor_required, size_t count_max
                    );

Perror_t Pe_countXtoY_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, Puint8 y, size_t count_max
                    );

/*@END Pcount_app_5.tex*/
#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
/*@BEGIN Pcount_app_6.tex*/

Perror_t PcountX_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, int eor_required, size_t count_max
                    );

Perror_t PcountXtoY_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Pint32 *res_out,
                    Puint8 x, Puint8 y, size_t count_max
                    );

/*@END Pcount_app_6.tex*/
#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0
/*@BEGIN Pcount_app_7.tex*/

ssize_t PcountX_write2io(P_t *pads, Sfio_t *io, Puint8 x, int eor_required,
                    size_t count_max, Pbase_pd *pd, Pint32 *val
                    );

ssize_t PcountX_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Puint8 x, int eor_required, size_t count_max, Pbase_pd *pd,
                    Pint32 *val
                    );

ssize_t PcountXtoY_write2io(P_t *pads, Sfio_t *io, Puint8 x, Puint8 y,
                    size_t count_max, Pbase_pd *pd, Pint32 *val
                    );

ssize_t PcountXtoY_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Puint8 x, Puint8 y, size_t count_max, Pbase_pd *pd, Pint32 *val
                    );

/*@END Pcount_app_7.tex*/

/*@BEGIN Pcount_app_8.tex*/

ssize_t PcountX_write_xml_2io(P_t *pads, Sfio_t *io, Puint8 x, int eor_required,
                    size_t count_max, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent
                    );

ssize_t PcountX_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Puint8 x, int eor_required, size_t count_max, Pbase_pd *pd,
                    Pint32 *val, const char *tag, int indent
                    );

ssize_t PcountXtoY_write_xml_2io(P_t *pads, Sfio_t *io, Puint8 x, Puint8 y,
                    size_t count_max, Pbase_pd *pd, Pint32 *val, const char *tag,
                    int indent
                    );

ssize_t PcountXtoY_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Puint8 x, Puint8 y, size_t count_max, Pbase_pd *pd,
                    Pint32 *val, const char *tag, int indent
                    );

/*@END Pcount_app_8.tex*/
#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif /*  __PCOUNT_H__  */

