/*@FILE Pip_app_1.tex Pip_app_2.tex Pip_app_3.tex Pip_app_4.tex Pip_app_5.tex Pip_app_6.tex Pip_app_7.tex Pip_app_8.tex Pip_app_9.tex Pip_app_10.tex Pip_app_11.tex Pip_app_12.tex Pip_app_13.tex Pip_app_14.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PIP_H__
#define __PIP_H__

#ifndef __PADS_H__
#error Pip.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pip_app_1.tex*/
/* ================================================================================
 * IP ADDRESS READ FUNCTIONS
 *
 * DEFAULT                        ASCII                          EBCDIC
 * -----------------------------  -----------------------------  -----------------------------
 * Pip_read                       Pa_ip_read                     Pe_ip_read
 *
 * Attempts to read a numeric IP address string, i.e., an IP address
 * form consisting of four numeric parts with values 0-255,
 * separated by ".", with an optional trailing dot.  
 */
/*@END Pip_app_1.tex*/
/*@BEGIN Pip_app_2.tex*/
/* The result is a single Puint32 value with each part encoded in one
 * of the four bytes.  part1 is stored in the high-order byte, part4
 * in the low-order byte.  You can obtain each part using the macro
 *
 *   P_IP_PART(addr, part)
 *
 * where part must be from 1 to 4.
 *
 * The digit chars and "." char are read as EBCDIC chars if the EBCDIC
 * form is used or if the DEFAULT form is used and
 * pads->disc->def_charset is Pcharset_EBCDIC.  Otherwise the data is
 * read as ASCII chars.
 */
/*@END Pip_app_2.tex*/
/*@BEGIN Pip_app_3.tex*/
/* If the current IO cursor position points to a valid IP address string:
 *   + Sets (*res_out) to the resulting Puint32
 *   + advances the IO cursor position to just after the last legal
 *      character in the IP address string
 *   + returns P_OK
 * Otherwise:
 *   + pd->loc.b/e set to the IO cursor position
 *   + IO cursor is not advanced
 *   + if P_Test_NotIgnore(*m), pd->errCode set to P_INVALID_IP,
 *         pd->nerr set to 1, and an error is reported
 *   + returns P_ERR
 */
/*@END Pip_app_3.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pip_app_4.tex*/

Perror_t Pa_ip_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

/*@END Pip_app_4.tex*/

#endif

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_5.tex*/

Perror_t Pe_ip_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

/*@END Pip_app_5.tex*/

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_6.tex*/

Perror_t Pip_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

/*@END Pip_app_6.tex*/

#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/*@BEGIN Pip_app_7.tex*/
/* The helper macro P_IP_PART(addr, part) takes a Puint32 addr
 * and a part number from 1 to 4, and produces the specified part.
 */
/*@END Pip_app_7.tex*/

#define P_IP_PART(addr, part) \
  ((addr >> (8*(4-part))) & 0xFF)

/*@BEGIN Pip_app_8.tex*/
/* ================================================================================
 * IP WRITE FUNCTIONS
 * DEFAULT                        ASCII                          EBCDIC
 * -----------------------------  -----------------------------  -----------------------------
 * Pip_write2io                   Pa_ip_write2io                 Pe_ip_write2io 
 *
 * Pip_write2buf                  Pa_ip_write2buf                Pe_ip_write2buf
 */
/*@END Pip_app_8.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_WRITE_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pip_app_9.tex*/

ssize_t Pa_ip_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d);

ssize_t Pa_ip_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d
                    );

ssize_t Pa_ip_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent
                    );

ssize_t Pa_ip_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent
                    );

/*@END Pip_app_9.tex*/

#endif

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_10.tex*/

ssize_t Pe_ip_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d);

ssize_t Pe_ip_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d
                    );

ssize_t Pe_ip_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent
                    );

ssize_t Pe_ip_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent
                    );

/*@END Pip_app_10.tex*/

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_11.tex*/

ssize_t Pip_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d);

ssize_t Pip_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d
                    );

ssize_t Pip_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent
                    );

ssize_t Pip_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent
                    );

/*@END Pip_app_11.tex*/

#endif

#endif /* P_CONFIG_WRITE_FUNCTIONS */
#endif /* FOR_CKIT */

#if P_CONFIG_A_CHAR_STRING > 0

/*@BEGIN Pip_app_12.tex*/

ssize_t Pa_ip_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pa_ip_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pa_ip_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

/*@END Pip_app_12.tex*/

#endif

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_13.tex*/

ssize_t Pe_ip_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pe_ip_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pe_ip_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

/*@END Pip_app_13.tex*/

#endif

#if P_CONFIG_A_CHAR_STRING > 0 || P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pip_app_14.tex*/

ssize_t Pip_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep);

ssize_t Pip_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pip_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep);


/*@END Pip_app_14.tex*/

#endif

#endif /*  __PIP_H__  */

