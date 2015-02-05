/*@FILE Pb_int_app_1.tex Pb_int_app_2.tex Pb_int_app_3.tex Pb_int_app_4.tex Pb_int_app_5.tex Pb_int_app_6.tex Pb_int_app_7.tex Pb_int_app_8.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PB_INT_H__
#define __PB_INT_H__

#ifndef __PADS_H__
#error Pb_int.h is intended to be included from pads.h, do not include it directly
#endif

#if P_CONFIG_B_INT > 0

/*@BEGIN Pb_int_app_1.tex*/
/* ================================================================================
 * READ
 */

/* ================================================================================
 * COMMON WIDTH BINARY INTEGER READ FUNCTIONS
 *
 * These functions parse signed or unsigned binary integers of common
 * bit widths (8, 16, 32, and 64 bit widths).  Whether bytes are
 * reversed is controlled by the endian-ness of the machine
 * (determined automatically) and pads->disc->d_endian. If they
 * differ, byte order is reversed in the in-memory representation,
 * otherwise it is not.
 *
 * A good way to set the d_endian value in a machine-independent way
 * is to use the Pendian annotation with the first multi-byte binary
 * integer field that appears in the data.  For example, this header
 * definition:
 *
 * Pstruct header {
 *    Pendian Pb_uint16 version : version < 10;
 *    ..etc..
 * };
 *
 * indicates the first value is a 2-byte unsigned binary integer,
 * version, whose value should be less than 10.  The Pendian
 * annotation indicates that there should be two attempts at reading
 * the version field: once with the current pads->disc->d_endian
 * setting, and (if the read fails) once with the opposite
 * pads->disc->d_endian setting.  If the second read succeeds, then
 * the new pads->disc->d_endian setting is retained, otherwise the
 * original pads->disc->d_endian setting is retained.
 */
/*@END Pb_int_app_1.tex*/
/*@BEGIN Pb_int_app_2.tex*/
/*
 * 
 * N.B. The Pendian annotatoin is only able to determine the correct
 * endian choice for a field that has an attached constraint, where
 * the wrong choice of endian setting will always cause the constraint
 * to fail.  (In the above example, if a value < 10 is read with the
 * wrong d_endian setting, the result is a value that is much greater
 * than 10.)
 *
 * For all cases, if the specified number of bytes is available, it is
 * always read.  If the width is not available:
 *    + pd->loc.b/e set to elt/char position of start/end of the
 *       'too small' field
 *    + IO cursor is not advanced
 *    + If P_Test_NotIgnore(*m), pd->errCode set to
 *       P_WIDTH_NOT_AVAILABLE, pd->nerr set to 1,
 *       and an error is reported
 */
/*@END Pb_int_app_2.tex*/

#if P_CONFIG_READ_FUNCTIONS > 0
/*@BEGIN Pb_int_app_3.tex*/

Perror_t Pb_int8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint8 *res_out);

Perror_t Pb_int16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint16 *res_out);

Perror_t Pb_int32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint32 *res_out);

Perror_t Pb_int64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Pint64 *res_out);

Perror_t Pb_uint8_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint8 *res_out);

Perror_t Pb_uint16_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint16 *res_out);

Perror_t Pb_uint32_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint32 *res_out);

Perror_t Pb_uint64_read(P_t *pads,const Pbase_m *m,Pbase_pd *pd,Puint64 *res_out);

/*@END Pb_int_app_3.tex*/
#endif /* P_CONFIG_READ_FUNCTIONS */

#if P_CONFIG_WRITE_FUNCTIONS > 0
/*@BEGIN Pb_int_app_4.tex*/
/* ================================================================================
 * WRITE
 */

ssize_t Pb_int8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint8 *val);

ssize_t Pb_int16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint16 *val);

ssize_t Pb_int32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint32 *val);

ssize_t Pb_int64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Pint64 *val);

ssize_t Pb_uint8_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint8 *val);

ssize_t Pb_uint16_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint16 *val);

ssize_t Pb_uint32_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *val);

ssize_t Pb_uint64_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint64 *val);

ssize_t Pb_int8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_int16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_int32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_int64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Pint64 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_uint8_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint8 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_uint16_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint16 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_uint32_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *val,
                    const char *tag, int indent
                    );

ssize_t Pb_uint64_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint64 *val,
                    const char *tag, int indent
                    );

/*@END Pb_int_app_4.tex*/

/*@BEGIN Pb_int_app_5.tex*/

ssize_t Pb_int8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val
                    );

ssize_t Pb_int16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val
                    );

ssize_t Pb_int32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val
                    );

ssize_t Pb_int64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val
                    );

ssize_t Pb_uint8_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val
                    );

ssize_t Pb_uint16_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val
                    );

ssize_t Pb_uint32_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val
                    );

ssize_t Pb_uint64_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val
                    );

ssize_t Pb_int8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint8 *val, const char *tag, int indent
                    );

ssize_t Pb_int16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint16 *val, const char *tag, int indent
                    );

ssize_t Pb_int32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint32 *val, const char *tag, int indent
                    );

ssize_t Pb_int64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Pint64 *val, const char *tag, int indent
                    );

ssize_t Pb_uint8_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint8 *val, const char *tag, int indent
                    );

ssize_t Pb_uint16_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint16 *val, const char *tag, int indent
                    );

ssize_t Pb_uint32_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *val, const char *tag, int indent
                    );

ssize_t Pb_uint64_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint64 *val, const char *tag, int indent
                    );

/*@END Pb_int_app_5.tex*/

/*@BEGIN Pb_int_app_6.tex*/

ssize_t Pb_int8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pb_int8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint8 *rep
                    );

ssize_t Pb_int16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pb_int16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint16 *rep
                    );

ssize_t Pb_int32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pb_int32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint32 *rep
                    );

ssize_t Pb_int64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

ssize_t Pb_int64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Pint64 *rep
                    );

/*@END Pb_int_app_6.tex*/

/*@BEGIN Pb_int_app_7.tex*/

ssize_t Pb_uint8_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pb_uint8_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint8 *rep
                    );

ssize_t Pb_uint16_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pb_uint16_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint16 *rep
                    );

ssize_t Pb_uint32_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pb_uint32_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep
                    );

ssize_t Pb_uint64_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

ssize_t Pb_uint64_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint64 *rep
                    );

/*@END Pb_int_app_7.tex*/

/*@BEGIN Pb_int_app_8.tex*/

ssize_t Pb_int8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint8 *rep
                    );

ssize_t Pb_int16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint16 *rep
                    );

ssize_t Pb_int32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint32 *rep
                    );

ssize_t Pb_int64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Pint64 *rep
                    );

ssize_t Pb_uint8_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint8 *rep
                    );

ssize_t Pb_uint16_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint16 *rep
                    );

ssize_t Pb_uint32_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep
                    );

ssize_t Pb_uint64_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint64 *rep
                    );

/*@END Pb_int_app_8.tex*/
#endif /* P_CONFIG_WRITE_FUNCTIONS > 0 */

#endif /* P_CONFIG_B_INT > 0 */
#endif /*  __PB_INT_H__  */
