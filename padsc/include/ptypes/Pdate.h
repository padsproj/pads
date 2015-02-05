/*@FILE Pdate_app_1.tex Pdate_app_2.tex Pdate_app_3.tex Pdate_app_4.tex Pdate_app_5.tex Pdate_app_6.tex Pdate_app_7.tex Pdate_app_8.tex Pdate_app_9.tex Pdate_app_10.tex Pdate_app_11.tex Pdate_app_12.tex Pdate_app_13.tex Pdate_app_14.tex Pdate_app_15.tex Pdate_app_16.tex Pdate_app_17.tex Pdate_app_18.tex Pdate_app_19.tex Pdate_app_20.tex Pdate_app_21.tex Pdate_app_22.tex Pdate_app_23.tex Pdate_app_24.tex Pdate_app_25.tex Pdate_app_26.tex Pdate_app_27.tex Pdate_app_28.tex Pdate_app_29.tex Pdate_app_30.tex Pdate_app_31.tex Pdate_app_32.tex Pdate_app_33.tex Pdate_app_34.tex Pdate_app_35.tex Pdate_app_36.tex Pdate_app_37.tex Pdate_app_38.tex Pdate_app_39.tex Pdate_app_40.tex Pdate_app_41.tex Pdate_app_42.tex Pdate_app_43.tex Pdate_app_44.tex Pdate_app_45.tex Pdate_app_46.tex Pdate_app_47.tex Pdate_app_48.tex Pdate_app_49.tex Pdate_app_50.tex Pdate_app_51.tex Pdate_app_52.tex Pdate_app_53.tex Pdate_app_54.tex Pdate_app_55.tex Pdate_app_56.tex Pdate_app_57.tex Pdate_app_58.tex Pdate_app_59.tex Pdate_app_60.tex Pdate_app_61.tex Pdate_app_62.tex Pdate_app_63.tex Pdate_app_64.tex Pdate_app_65.tex Pdate_app_66.tex Pdate_app_67.tex Pdate_app_68.tex Pdate_app_69.tex Pdate_app_70.tex Pdate_app_71.tex Pdate_app_72.tex Pdate_app_73.tex Pdate_app_74.tex Pdate_app_75.tex Pdate_app_76.tex Pdate_app_77.tex Pdate_app_78.tex Pdate_app_79.tex Pdate_app_80.tex Pdate_app_81.tex Pdate_app_82.tex Pdate_app_83.tex Pdate_app_84.tex Pdate_app_85.tex Pdate_app_86.tex Pdate_app_87.tex Pdate_app_88.tex Pdate_app_89.tex Pdate_app_90.tex Pdate_app_91.tex Pdate_app_92.tex Pdate_app_93.tex Pdate_app_94.tex Pdate_app_95.tex Pdate_app_96.tex Pdate_app_97.tex Pdate_app_98.tex Pdate_app_99.tex Pdate_app_100.tex Pdate_app_101.tex Pdate_app_102.tex Pdate_app_103.tex Pdate_app_104.tex Pdate_app_105.tex Pdate_app_106.tex Pdate_app_107.tex Pdate_app_108.tex Pdate_app_109.tex Pdate_app_110.tex Pdate_app_111.tex Pdate_app_112.tex Pdate_app_113.tex Pdate_app_114.tex Pdate_app_115.tex Pdate_app_116.tex Pdate_app_117.tex Pdate_app_118.tex Pdate_app_119.tex Pdate_app_120.tex Pdate_app_121.tex Pdate_app_122.tex Pdate_app_123.tex Pdate_app_124.tex Pdate_app_125.tex Pdate_app_126.tex Pdate_app_127.tex Pdate_app_128.tex Pdate_app_129.tex Pdate_app_130.tex Pdate_app_131.tex Pdate_app_132.tex Pdate_app_133.tex Pdate_app_134.tex Pdate_app_135.tex Pdate_app_136.tex Pdate_app_137.tex Pdate_app_138.tex Pdate_app_139.tex Pdate_app_140.tex Pdate_app_141.tex Pdate_app_142.tex Pdate_app_143.tex Pdate_app_144.tex Pdate_app_145.tex Pdate_app_146.tex Pdate_app_147.tex Pdate_app_148.tex Pdate_app_149.tex*/

/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PDATE_H__
#define __PDATE_H__

#ifndef __PADS_H__
#error Pdate.h is intended to be included from pads.h, do not include it directly
#endif

/*@BEGIN Pdate_app_1.tex*/
/* ================================================================================
 * READ FUNCTIONS
 *
 * DEFAULT                      ASCII                          EBCDIC
 * ---------------------------- -----------------------------  -----------------------------
 * Ptimestamp_explicit_FW_read  Pa_timestamp_explicit_FW_read  Pe_timestamp_explicit_FW_read
 * Ptimestamp_explicit_read     Pa_timestamp_explicit_read     Pe_timestamp_explicit_read
 * Ptimestamp_explicit_ME_read  Pa_timestamp_explicit_ME_read  Pe_timestamp_explicit_ME_read
 * Ptimestamp_explicit_CME_read Pa_timestamp_explicit_CME_read Pe_timestamp_explicit_CME_read
 * Ptimestamp_explicit_SE_read  Pa_timestamp_explicit_SE_read  Pe_timestamp_explicit_SE_read
 * Ptimestamp_explicit_CSE_read Pa_timestamp_explicit_CSE_read Pe_timestamp_explicit_CSE_read
 *
 * Pdate_explicit_FW_read       Pa_date_explicit_FW_read       Pe_date_explicit_FW_read
 * Pdate_explicit_read          Pa_date_explicit_read          Pe_date_explicit_read
 * Pdate_explicit_ME_read       Pa_date_explicit_ME_read       Pe_date_explicit_ME_read
 * Pdate_explicit_CME_read      Pa_date_explicit_CME_read      Pe_date_explicit_CME_read
 * Pdate_explicit_SE_read       Pa_date_explicit_SE_read       Pe_date_explicit_SE_read
 * Pdate_explicit_CSE_read      Pa_date_explicit_CSE_read      Pe_date_explicit_CSE_read
 *
 * Ptime_explicit_FW_read       Pa_time_explicit_FW_read       Pe_time_explicit_FW_read
 * Ptime_explicit_read          Pa_time_explicit_read          Pe_time_explicit_read
 * Ptime_explicit_ME_read       Pa_time_explicit_ME_read       Pe_time_explicit_ME_read
 * Ptime_explicit_CME_read      Pa_time_explicit_CME_read      Pe_time_explicit_CME_read
 * Ptime_explicit_SE_read       Pa_time_explicit_SE_read       Pe_time_explicit_SE_read
 * Ptime_explicit_CSE_read      Pa_time_explicit_CSE_read      Pe_time_explicit_CSE_read
 */
/*@END Pdate_app_1.tex*/
/*@BEGIN Pdate_app_2.tex*/
/*
 * Ptimestamp_FW_read           Pa_timestamp_FW_read           Pe_timestamp_FW_read
 * Ptimestamp_read              Pa_timestamp_read              Pe_timestamp_read
 * Ptimestamp_ME_read           Pa_timestamp_ME_read           Pe_timestamp_ME_read
 * Ptimestamp_CME_read          Pa_timestamp_CME_read          Pe_timestamp_CME_read
 * Ptimestamp_SE_read           Pa_timestamp_SE_read           Pe_timestamp_SE_read
 * Ptimestamp_CSE_read          Pa_timestamp_CSE_read          Pe_timestamp_CSE_read
 *
 * Pdate_FW_read                Pa_date_FW_read                Pe_date_FW_read
 * Pdate_read                   Pa_date_read                   Pe_date_read
 * Pdate_ME_read                Pa_date_ME_read                Pe_date_ME_read
 * Pdate_CME_read               Pa_date_CME_read               Pe_date_CME_read
 * Pdate_SE_read                Pa_date_SE_read                Pe_date_SE_read
 * Pdate_CSE_read               Pa_date_CSE_read               Pe_date_CSE_read
 *
 * Ptime_FW_read                Pa_time_FW_read                Pe_time_FW_read
 * Ptime_read                   Pa_time_read                   Pe_time_read
 * Ptime_ME_read                Pa_time_ME_read                Pe_time_ME_read
 * Ptime_CME_read               Pa_time_CME_read               Pe_time_CME_read
 * Ptime_SE_read                Pa_time_SE_read                Pe_time_SE_read
 * Ptime_CSE_read               Pa_time_CSE_read               Pe_time_CSE_read
 */
/*@END Pdate_app_2.tex*/
/*@BEGIN Pdate_app_3.tex*/
/*
 * Ptimestamp_explicit variants: 
 *
 *    Converts ASCII/EBCDIC char date/time description into seconds
 *    since Midnight Jan 1, 1970.  Format-based parsing is based on
 *    libast's tmdate function.  Input format and input time zone are
 *    specified explicitly.  The format used controls whether input is
 *    date and time, just date, or just time.  Default output format
 *    is set via disc->out_formats.timestamp_explicit
 *
 * Pdate_explicit variants:
 *
 *    Like Ptimestamp_explicit, with explicit format and time zone
 *    argument.  INTENDED to be used for just date, but format
 *    determines which strings are accepted. If treated as a full timestamp
 *    (time in seconds since Midnight Jan 1, 1970), the result has a
 *    'time of day' component of 0 hours, 0 minutes, 0 seconds.
 *    Default output format is set via disc->out_formats.date_explicit
 *
 * Ptime_explicit variants:
 *
 *    Like Ptimestamp_explicit, with explicit format and time zone
 *    argument.  INTENDED to be used for just time, but format
 *    determines which strings are accepted.  The resulting
 *    time in seconds is just the contribution of the specified time of day,
 *    thus if treated as a full timestamp, the time would fall on Jan 1, 1970.
 *    Default output format is set via disc->out_formats.time_explicit
 */
/*@END Pdate_app_3.tex*/
/*@BEGIN Pdate_app_4.tex*/
/*
 * Ptimestamp variants:
 *
 *    Like Ptimestamp_explicit, but input format and input time zone
 *    are taken from disc->in_formats.timestamp and
 *    disc->in_time_zone.  INTENDED to be used for both a date and
 *    time, but format determines actual use.  Default output format
 *    is set via disc->out_formats.timestamp
 *
 * Pdate variants:
 *
 *    Like Pdate_explicit, but input format and input time zone are
 *    taken from disc->in_formats.date and disc->in_time_zone.
 *    INTENDED to be used for just date, but format determines which
 *    strings are accepted. If treated as a full timestamp (time in seconds
 *    since Midnight Jan 1, 1970), the result has a 'time of day' component
 *    of 0 hours, 0 minutes, 0 seconds.  Default output format is set
 *    via disc->out_formats.date
 *
 * Ptime variants:
 *
 *    Like Ptime_explicit, but input format and input time zone are
 *    taken from disc->in_formats.time and disc->in_time_zone.
 *    INTENDED to be used for just time, but format determines which
 *    strings are accepted.  The resulting time in seconds is just the
 *    contribution of the specified time of day, thus if treated as a
 *    full timestamp, the time would fall on Jan 1, 1970.
 *    Default output format is set via disc->out_formats.time
 *
 * Each of the types above corresponds to one of the Pstring variants.
 * In each case one specifies the extent of a 'string' in the input
 * that is to be converted to a Puint32 representing the date in
 * seconds since the epoch.  For the different date formats that are
 * supported, see the discussion of disc->in_formats in pads.h.
 *
 * If the current IO cursor position points to a valid date string:
 *   + Sets (*res_out) to the resulting date in seconds since the epoch
 *   + advances the IO cursor position to just after the last
 *     legal character in the date string
 *   + returns P_OK
 * Otherwise:
 *   + does not advance the IO cursor pos
 *   + returns P_ERR
 */
/*@END Pdate_app_4.tex*/

#ifdef FOR_CKIT
#if P_CONFIG_READ_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0
/*@BEGIN Pdate_app_5.tex*/

Perror_t Pa_timestamp_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_timestamp_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_timestamp_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_timestamp_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_timestamp_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_timestamp_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_5.tex*/
/*@BEGIN Pdate_app_6.tex*/

Perror_t Pa_date_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_date_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_date_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_date_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_date_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_date_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_6.tex*/
/*@BEGIN Pdate_app_7.tex*/

Perror_t Pa_time_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_time_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_time_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_time_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_time_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pa_time_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_7.tex*/
/*@BEGIN Pdate_app_8.tex*/

Perror_t Pa_timestamp_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width
                    );

Perror_t Pa_timestamp_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar
                    );

Perror_t Pa_timestamp_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp
                    );

Perror_t Pa_timestamp_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp
                    );

Perror_t Pa_timestamp_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp
                    );

Perror_t Pa_timestamp_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_8.tex*/
/*@BEGIN Pdate_app_9.tex*/

Perror_t Pa_date_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Pa_date_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar
                    );

Perror_t Pa_date_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Pa_date_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pa_date_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Pa_date_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_9.tex*/
/*@BEGIN Pdate_app_10.tex*/

Perror_t Pa_time_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Pa_time_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar
                    );

Perror_t Pa_time_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Pa_time_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pa_time_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Pa_time_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_10.tex*/

#endif

#if P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pdate_app_11.tex*/

Perror_t Pe_timestamp_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_timestamp_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_timestamp_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_timestamp_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_timestamp_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_timestamp_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_11.tex*/
/*@BEGIN Pdate_app_12.tex*/

Perror_t Pe_date_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_date_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_date_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_date_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_date_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_date_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_12.tex*/
/*@BEGIN Pdate_app_13.tex*/

Perror_t Pe_time_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_time_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_time_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_time_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_time_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pe_time_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_13.tex*/
/*@BEGIN Pdate_app_14.tex*/

Perror_t Pe_timestamp_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width
                    );

Perror_t Pe_timestamp_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar
                    );

Perror_t Pe_timestamp_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp
                    );

Perror_t Pe_timestamp_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp
                    );

Perror_t Pe_timestamp_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp
                    );

Perror_t Pe_timestamp_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_14.tex*/
/*@BEGIN Pdate_app_15.tex*/

Perror_t Pe_date_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Pe_date_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar
                    );

Perror_t Pe_date_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Pe_date_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pe_date_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Pe_date_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_15.tex*/
/*@BEGIN Pdate_app_16.tex*/

Perror_t Pe_time_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Pe_time_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar
                    );

Perror_t Pe_time_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Pe_time_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pe_time_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Pe_time_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_16.tex*/

#endif

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0

/*@BEGIN Pdate_app_17.tex*/

Perror_t Ptimestamp_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptimestamp_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptimestamp_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptimestamp_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptimestamp_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptimestamp_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_17.tex*/
/*@BEGIN Pdate_app_18.tex*/

Perror_t Pdate_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pdate_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pdate_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pdate_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pdate_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Pdate_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_18.tex*/
/*@BEGIN Pdate_app_19.tex*/

Perror_t Ptime_explicit_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptime_explicit_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptime_explicit_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptime_explicit_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptime_explicit_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

Perror_t Ptime_explicit_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_19.tex*/
/*@BEGIN Pdate_app_20.tex*/

Perror_t Ptimestamp_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, size_t width
                    );

Perror_t Ptimestamp_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar
                    );

Perror_t Ptimestamp_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *matchRegexp
                    );

Perror_t Ptimestamp_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *matchRegexp
                    );

Perror_t Ptimestamp_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, const char *stopRegexp
                    );

Perror_t Ptimestamp_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd,
                    Puint32 *res_out, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_20.tex*/
/*@BEGIN Pdate_app_21.tex*/

Perror_t Pdate_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Pdate_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar);

Perror_t Pdate_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Pdate_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Pdate_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Pdate_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_21.tex*/
/*@BEGIN Pdate_app_22.tex*/

Perror_t Ptime_FW_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    size_t width
                    );

Perror_t Ptime_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pchar stopChar);

Perror_t Ptime_ME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *matchRegexp
                    );

Perror_t Ptime_CME_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *matchRegexp
                    );

Perror_t Ptime_SE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    const char *stopRegexp
                    );

Perror_t Ptime_CSE_read(P_t *pads, const Pbase_m *m, Pbase_pd *pd, Puint32 *res_out,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_22.tex*/

#endif

#endif /* P_CONFIG_READ_FUNCTIONS */
#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_23.tex*/

/* ================================================================================
 * WRITE FUNCTIONS
 * DEFAULT                     ASCII                        EBCDIC
 * --------------------------  ---------------------------  -----------------------
 * Pdate_FW_write2io           Pa_date_FW_write2io          Pe_date_FW_write2io
 * Pdate_write2io              Pa_date_write2io             Pe_date_write2io
 * Pdate_ME_write2io           Pa_date_ME_write2io          Pe_date_ME_write2io
 * Pdate_CME_write2io          Pa_date_CME_write2io         Pe_date_CME_write2io
 * Pdate_SE_write2io           Pa_date_SE_write2io          Pe_date_SE_write2io
 * Pdate_CSE_write2io          Pa_date_CSE_write2io         Pe_date_CSE_write2io
 *
 * Pdate_FW_write2buf          Pa_date_FW_write2buf         Pe_date_FW_write2buf
 * Pdate_write2buf             Pa_date_write2buf            Pe_date_write2buf
 * Pdate_ME_write2buf          Pa_date_ME_write2buf         Pe_date_ME_write2buf
 * Pdate_CME_write2buf         Pa_date_CME_write2buf        Pe_date_CME_write2buf
 * Pdate_SE_write2buf          Pa_date_SE_write2buf         Pe_date_SE_write2buf
 * Pdate_CSE_write2buf         Pa_date_CSE_write2buf        Pe_date_CSE_write2buf
 */
/*@END Pdate_app_23.tex*/

#if P_CONFIG_WRITE_FUNCTIONS > 0

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_24.tex*/

/* Ptimestamp_explicit */

ssize_t Pa_timestamp_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_24.tex*/
/*@BEGIN Pdate_app_25.tex*/

ssize_t Pa_timestamp_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_25.tex*/
/*@BEGIN Pdate_app_26.tex*/

ssize_t Pa_timestamp_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_26.tex*/
/*@BEGIN Pdate_app_27.tex*/

ssize_t Pa_timestamp_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf,
                    size_t buf_len, int *buf_full, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf,
                    size_t buf_len, int *buf_full, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_27.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_28.tex*/

ssize_t Pa_timestamp_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_28.tex*/
/*@BEGIN Pdate_app_29.tex*/

ssize_t Pa_timestamp_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_29.tex*/
/*@BEGIN Pdate_app_30.tex*/

ssize_t Pa_timestamp_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_timestamp_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_30.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_31.tex*/

ssize_t Pe_timestamp_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_31.tex*/
/*@BEGIN Pdate_app_32.tex*/

ssize_t Pe_timestamp_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_32.tex*/
/*@BEGIN Pdate_app_33.tex*/

ssize_t Pe_timestamp_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_33.tex*/
/*@BEGIN Pdate_app_34.tex*/

ssize_t Pe_timestamp_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf,
                    size_t buf_len, int *buf_full, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf,
                    size_t buf_len, int *buf_full, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_34.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_35.tex*/

ssize_t Pe_timestamp_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_35.tex*/
/*@BEGIN Pdate_app_36.tex*/

ssize_t Pe_timestamp_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_36.tex*/
/*@BEGIN Pdate_app_37.tex*/

ssize_t Pe_timestamp_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_timestamp_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_37.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_38.tex*/

ssize_t Ptimestamp_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_38.tex*/
/*@BEGIN Pdate_app_39.tex*/

ssize_t Ptimestamp_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_39.tex*/
/*@BEGIN Pdate_app_40.tex*/

ssize_t Ptimestamp_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_40.tex*/
/*@BEGIN Pdate_app_41.tex*/

ssize_t Ptimestamp_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_41.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_42.tex*/

ssize_t Ptimestamp_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_42.tex*/
/*@BEGIN Pdate_app_43.tex*/

ssize_t Ptimestamp_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_43.tex*/
/*@BEGIN Pdate_app_44.tex*/

ssize_t Ptimestamp_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptimestamp_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_44.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_45.tex*/

/* Pdate_explicit */

ssize_t Pa_date_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_45.tex*/
/*@BEGIN Pdate_app_46.tex*/

ssize_t Pa_date_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_46.tex*/
/*@BEGIN Pdate_app_47.tex*/

ssize_t Pa_date_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_47.tex*/
/*@BEGIN Pdate_app_48.tex*/

ssize_t Pa_date_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_48.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_49.tex*/

ssize_t Pa_date_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_49.tex*/
/*@BEGIN Pdate_app_50.tex*/

ssize_t Pa_date_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_50.tex*/
/*@BEGIN Pdate_app_51.tex*/

ssize_t Pa_date_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_date_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_51.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_52.tex*/

ssize_t Pe_date_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_52.tex*/
/*@BEGIN Pdate_app_53.tex*/

ssize_t Pe_date_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_53.tex*/
/*@BEGIN Pdate_app_54.tex*/

ssize_t Pe_date_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_54.tex*/
/*@BEGIN Pdate_app_55.tex*/

ssize_t Pe_date_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_55.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_56.tex*/

ssize_t Pe_date_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_56.tex*/
/*@BEGIN Pdate_app_57.tex*/

ssize_t Pe_date_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_57.tex*/
/*@BEGIN Pdate_app_58.tex*/

ssize_t Pe_date_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_date_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_58.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_59.tex*/

ssize_t Pdate_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_59.tex*/
/*@BEGIN Pdate_app_60.tex*/

ssize_t Pdate_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_60.tex*/
/*@BEGIN Pdate_app_61.tex*/

ssize_t Pdate_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_61.tex*/
/*@BEGIN Pdate_app_62.tex*/

ssize_t Pdate_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_62.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_63.tex*/

ssize_t Pdate_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_63.tex*/
/*@BEGIN Pdate_app_64.tex*/

ssize_t Pdate_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_64.tex*/
/*@BEGIN Pdate_app_65.tex*/

ssize_t Pdate_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pdate_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_65.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_66.tex*/

/* Ptime_explicit */

ssize_t Pa_time_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_66.tex*/
/*@BEGIN Pdate_app_67.tex*/

ssize_t Pa_time_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_67.tex*/
/*@BEGIN Pdate_app_68.tex*/

ssize_t Pa_time_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_68.tex*/
/*@BEGIN Pdate_app_69.tex*/

ssize_t Pa_time_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_69.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_70.tex*/

ssize_t Pa_time_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_70.tex*/
/*@BEGIN Pdate_app_71.tex*/

ssize_t Pa_time_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_71.tex*/
/*@BEGIN Pdate_app_72.tex*/

ssize_t Pa_time_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pa_time_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_72.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_73.tex*/

ssize_t Pe_time_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_73.tex*/
/*@BEGIN Pdate_app_74.tex*/

ssize_t Pe_time_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_74.tex*/
/*@BEGIN Pdate_app_75.tex*/

ssize_t Pe_time_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pchar stopChar,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_75.tex*/
/*@BEGIN Pdate_app_76.tex*/

ssize_t Pe_time_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_76.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_77.tex*/

ssize_t Pe_time_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_77.tex*/
/*@BEGIN Pdate_app_78.tex*/

ssize_t Pe_time_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_78.tex*/
/*@BEGIN Pdate_app_79.tex*/

ssize_t Pe_time_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Pe_time_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_79.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_80.tex*/

ssize_t Ptime_explicit_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_80.tex*/
/*@BEGIN Pdate_app_81.tex*/

ssize_t Ptime_explicit_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_81.tex*/
/*@BEGIN Pdate_app_82.tex*/

ssize_t Ptime_explicit_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, size_t width,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_82.tex*/
/*@BEGIN Pdate_app_83.tex*/

ssize_t Ptime_explicit_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp, const char *format,
                    Tm_zone_t *tzone
                    );

/*@END Pdate_app_83.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_84.tex*/

ssize_t Ptime_explicit_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar, const char *format,
                    Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_84.tex*/
/*@BEGIN Pdate_app_85.tex*/

ssize_t Ptime_explicit_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp,
                    const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_85.tex*/
/*@BEGIN Pdate_app_86.tex*/

ssize_t Ptime_explicit_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

ssize_t Ptime_explicit_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp, const char *format, Tm_zone_t *tzone
                    );

/*@END Pdate_app_86.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_87.tex*/

/* Ptimestamp */

ssize_t Pa_timestamp_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pa_timestamp_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pa_timestamp_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pa_timestamp_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pa_timestamp_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pa_timestamp_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_87.tex*/
/*@BEGIN Pdate_app_88.tex*/

ssize_t Pa_timestamp_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pa_timestamp_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_88.tex*/
/*@BEGIN Pdate_app_89.tex*/

ssize_t Pa_timestamp_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_timestamp_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_timestamp_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pa_timestamp_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar
                    );

ssize_t Pa_timestamp_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pa_timestamp_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_89.tex*/
/*@BEGIN Pdate_app_90.tex*/

ssize_t Pa_timestamp_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pa_timestamp_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_90.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_91.tex*/

ssize_t Pa_timestamp_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_timestamp_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Pa_timestamp_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_timestamp_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_timestamp_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pa_timestamp_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_91.tex*/
/*@BEGIN Pdate_app_92.tex*/

ssize_t Pa_timestamp_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_timestamp_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_92.tex*/
/*@BEGIN Pdate_app_93.tex*/

ssize_t Pa_timestamp_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pa_timestamp_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar
                    );

ssize_t Pa_timestamp_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pa_timestamp_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_timestamp_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pa_timestamp_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_93.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_94.tex*/

ssize_t Pe_timestamp_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pe_timestamp_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pe_timestamp_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pe_timestamp_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pe_timestamp_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pe_timestamp_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_94.tex*/
/*@BEGIN Pdate_app_95.tex*/

ssize_t Pe_timestamp_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pe_timestamp_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_95.tex*/
/*@BEGIN Pdate_app_96.tex*/

ssize_t Pe_timestamp_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_timestamp_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_timestamp_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pe_timestamp_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar
                    );

ssize_t Pe_timestamp_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pe_timestamp_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_96.tex*/
/*@BEGIN Pdate_app_97.tex*/

ssize_t Pe_timestamp_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pe_timestamp_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd,
                    Puint32 *d, const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_97.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_98.tex*/

ssize_t Pe_timestamp_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_timestamp_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Pe_timestamp_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_timestamp_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_timestamp_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pe_timestamp_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_98.tex*/
/*@BEGIN Pdate_app_99.tex*/

ssize_t Pe_timestamp_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_timestamp_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_99.tex*/
/*@BEGIN Pdate_app_100.tex*/

ssize_t Pe_timestamp_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pe_timestamp_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar
                    );

ssize_t Pe_timestamp_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pe_timestamp_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_timestamp_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pe_timestamp_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_100.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_101.tex*/

ssize_t Ptimestamp_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Ptimestamp_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Ptimestamp_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Ptimestamp_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Ptimestamp_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Ptimestamp_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_101.tex*/
/*@BEGIN Pdate_app_102.tex*/

ssize_t Ptimestamp_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Ptimestamp_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Ptimestamp_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Ptimestamp_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_102.tex*/
/*@BEGIN Pdate_app_103.tex*/

ssize_t Ptimestamp_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Ptimestamp_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Ptimestamp_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Ptimestamp_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pchar stopChar
                    );

ssize_t Ptimestamp_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Ptimestamp_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_103.tex*/
/*@BEGIN Pdate_app_104.tex*/

ssize_t Ptimestamp_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Ptimestamp_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Ptimestamp_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Ptimestamp_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_104.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_105.tex*/

ssize_t Ptimestamp_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Ptimestamp_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Ptimestamp_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Ptimestamp_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Ptimestamp_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Ptimestamp_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_105.tex*/
/*@BEGIN Pdate_app_106.tex*/

ssize_t Ptimestamp_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Ptimestamp_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, const char *stopRegexp
                    );

ssize_t Ptimestamp_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Ptimestamp_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_106.tex*/
/*@BEGIN Pdate_app_107.tex*/

ssize_t Ptimestamp_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Ptimestamp_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pchar stopChar
                    );

ssize_t Ptimestamp_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Ptimestamp_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Ptimestamp_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Ptimestamp_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_107.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_108.tex*/

/* Pdate */

ssize_t Pa_date_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pa_date_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pa_date_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pa_date_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pa_date_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pa_date_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_108.tex*/
/*@BEGIN Pdate_app_109.tex*/

ssize_t Pa_date_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pa_date_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pa_date_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pa_date_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_109.tex*/
/*@BEGIN Pdate_app_110.tex*/

ssize_t Pa_date_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_date_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_date_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pa_date_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pa_date_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pa_date_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_110.tex*/
/*@BEGIN Pdate_app_111.tex*/

ssize_t Pa_date_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pa_date_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pa_date_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pa_date_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_111.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_112.tex*/

ssize_t Pa_date_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_date_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_date_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_date_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_date_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pa_date_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_112.tex*/
/*@BEGIN Pdate_app_113.tex*/

ssize_t Pa_date_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_date_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_date_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pa_date_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_113.tex*/
/*@BEGIN Pdate_app_114.tex*/

ssize_t Pa_date_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pa_date_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_date_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pa_date_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_date_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pa_date_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_114.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_115.tex*/

ssize_t Pe_date_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pe_date_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pe_date_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pe_date_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pe_date_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pe_date_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_115.tex*/
/*@BEGIN Pdate_app_116.tex*/

ssize_t Pe_date_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pe_date_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pe_date_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pe_date_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_116.tex*/
/*@BEGIN Pdate_app_117.tex*/

ssize_t Pe_date_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_date_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_date_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pe_date_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pe_date_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pe_date_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_117.tex*/
/*@BEGIN Pdate_app_118.tex*/

ssize_t Pe_date_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pe_date_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pe_date_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pe_date_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_118.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_119.tex*/

ssize_t Pe_date_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_date_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_date_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_date_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_date_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pe_date_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_119.tex*/
/*@BEGIN Pdate_app_120.tex*/

ssize_t Pe_date_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_date_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_date_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pe_date_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_120.tex*/
/*@BEGIN Pdate_app_121.tex*/

ssize_t Pe_date_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pe_date_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_date_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pe_date_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_date_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pe_date_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_121.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_122.tex*/

ssize_t Pdate_FW_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d,size_t width);

ssize_t Pdate_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pdate_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d,Pchar stopChar);

ssize_t Pdate_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pdate_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pdate_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_122.tex*/
/*@BEGIN Pdate_app_123.tex*/

ssize_t Pdate_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pdate_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pdate_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pdate_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pdate_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pdate_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_123.tex*/
/*@BEGIN Pdate_app_124.tex*/

ssize_t Pdate_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pdate_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    size_t width
                    );

ssize_t Pdate_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pdate_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pdate_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pdate_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    const char *matchRegexp
                    );

/*@END Pdate_app_124.tex*/
/*@BEGIN Pdate_app_125.tex*/

ssize_t Pdate_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pdate_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pdate_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pdate_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    const char *stopRegexp
                    );

ssize_t Pdate_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pdate_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_125.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_126.tex*/

ssize_t Pdate_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pdate_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pdate_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pdate_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pdate_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pdate_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_126.tex*/
/*@BEGIN Pdate_app_127.tex*/

ssize_t Pdate_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pdate_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pdate_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pdate_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pdate_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pdate_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_127.tex*/
/*@BEGIN Pdate_app_128.tex*/

ssize_t Pdate_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Pdate_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pdate_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pdate_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pdate_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pdate_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_128.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_129.tex*/

/* Ptime */

ssize_t Pa_time_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pa_time_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pa_time_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pa_time_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pa_time_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pa_time_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_129.tex*/
/*@BEGIN Pdate_app_130.tex*/

ssize_t Pa_time_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pa_time_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pa_time_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pa_time_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_130.tex*/
/*@BEGIN Pdate_app_131.tex*/

ssize_t Pa_time_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pa_time_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pa_time_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pa_time_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pa_time_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pa_time_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_131.tex*/
/*@BEGIN Pdate_app_132.tex*/

ssize_t Pa_time_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pa_time_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pa_time_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pa_time_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_132.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_133.tex*/

ssize_t Pa_time_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_time_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pa_time_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_time_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_time_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pa_time_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_133.tex*/
/*@BEGIN Pdate_app_134.tex*/

ssize_t Pa_time_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_time_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pa_time_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pa_time_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_134.tex*/
/*@BEGIN Pdate_app_135.tex*/

ssize_t Pa_time_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pa_time_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pa_time_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pa_time_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pa_time_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pa_time_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_135.tex*/

#endif   /*  P_CONFIG_A_CHAR_STRING > 0  */

#if P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_136.tex*/

ssize_t Pe_time_FW_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    size_t width
                    );

ssize_t Pe_time_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Pe_time_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pchar stopChar
                    );

ssize_t Pe_time_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Pe_time_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Pe_time_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_136.tex*/
/*@BEGIN Pdate_app_137.tex*/

ssize_t Pe_time_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Pe_time_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Pe_time_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Pe_time_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_137.tex*/
/*@BEGIN Pdate_app_138.tex*/

ssize_t Pe_time_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Pe_time_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, size_t width
                    );

ssize_t Pe_time_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Pe_time_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Pe_time_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Pe_time_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *matchRegexp
                    );

/*@END Pdate_app_138.tex*/
/*@BEGIN Pdate_app_139.tex*/

ssize_t Pe_time_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Pe_time_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, const char *stopRegexp
                    );

ssize_t Pe_time_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Pe_time_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, Pbase_pd *pd, Puint32 *d, const char *tag,
                    int indent, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_139.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_140.tex*/

ssize_t Pe_time_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_time_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Pe_time_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_time_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_time_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Pe_time_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_140.tex*/
/*@BEGIN Pdate_app_141.tex*/

ssize_t Pe_time_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_time_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Pe_time_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Pe_time_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len,
                    int *buf_full, int *requested_out, const char *delims, Pbase_m *m,
                    Pbase_pd *pd, Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_141.tex*/
/*@BEGIN Pdate_app_142.tex*/

ssize_t Pe_time_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    size_t width
                    );

ssize_t Pe_time_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Pe_time_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *matchRegexp
                    );

ssize_t Pe_time_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Pe_time_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    const char *stopRegexp
                    );

ssize_t Pe_time_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_142.tex*/

#endif  /*  P_CONFIG_E_CHAR_STRING > 0  */

#if P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0
#ifdef FOR_CKIT

/*@BEGIN Pdate_app_143.tex*/

ssize_t Ptime_FW_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d,size_t width);

ssize_t Ptime_FW_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, size_t width
                    );

ssize_t Ptime_write2io(P_t *pads,Sfio_t *io,Pbase_pd *pd,Puint32 *d,Pchar stopChar);

ssize_t Ptime_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pchar stopChar
                    );

ssize_t Ptime_ME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *matchRegexp
                    );

ssize_t Ptime_ME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *matchRegexp
                    );

/*@END Pdate_app_143.tex*/
/*@BEGIN Pdate_app_144.tex*/

ssize_t Ptime_CME_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *matchRegexp
                    );

ssize_t Ptime_CME_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *matchRegexp
                    );

ssize_t Ptime_SE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *stopRegexp
                    );

ssize_t Ptime_SE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *stopRegexp
                    );

ssize_t Ptime_CSE_write2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    Pregexp_t *stopRegexp
                    );

ssize_t Ptime_CSE_write2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_144.tex*/
/*@BEGIN Pdate_app_145.tex*/

ssize_t Ptime_FW_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, size_t width
                    );

ssize_t Ptime_FW_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    size_t width
                    );

ssize_t Ptime_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pchar stopChar
                    );

ssize_t Ptime_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pchar stopChar
                    );

ssize_t Ptime_ME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *matchRegexp
                    );

ssize_t Ptime_ME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    const char *matchRegexp
                    );

/*@END Pdate_app_145.tex*/
/*@BEGIN Pdate_app_146.tex*/

ssize_t Ptime_CME_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *matchRegexp
                    );

ssize_t Ptime_CME_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pregexp_t *matchRegexp
                    );

ssize_t Ptime_SE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, const char *stopRegexp
                    );

ssize_t Ptime_SE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    const char *stopRegexp
                    );

ssize_t Ptime_CSE_write_xml_2io(P_t *pads, Sfio_t *io, Pbase_pd *pd, Puint32 *d,
                    const char *tag, int indent, Pregexp_t *stopRegexp
                    );

ssize_t Ptime_CSE_write_xml_2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    Pbase_pd *pd, Puint32 *d, const char *tag, int indent,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_146.tex*/

#endif /* FOR_CKIT */

/*@BEGIN Pdate_app_147.tex*/

ssize_t Ptime_FW_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Ptime_FW_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, size_t width
                    );

ssize_t Ptime_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Ptime_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pchar stopChar
                    );

ssize_t Ptime_ME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

ssize_t Ptime_ME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *matchRegexp
                    );

/*@END Pdate_app_147.tex*/
/*@BEGIN Pdate_app_148.tex*/

ssize_t Ptime_CME_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Ptime_CME_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *matchRegexp
                    );

ssize_t Ptime_SE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Ptime_SE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, const char *stopRegexp
                    );

ssize_t Ptime_CSE_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

ssize_t Ptime_CSE_fmt2buf_final(P_t *pads, Pbyte *buf, size_t buf_len, int *buf_full,
                    int *requested_out, const char *delims, Pbase_m *m, Pbase_pd *pd,
                    Puint32 *rep, Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_148.tex*/
/*@BEGIN Pdate_app_149.tex*/

ssize_t Ptime_FW_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, size_t width
                    );

ssize_t Ptime_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, Pchar stopChar
                    );

ssize_t Ptime_ME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, const char *matchRegexp
                    );

ssize_t Ptime_CME_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *matchRegexp
                    );

ssize_t Ptime_SE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out, const char *delims,
                    Pbase_m *m, Pbase_pd *pd, Puint32 *rep, const char *stopRegexp
                    );

ssize_t Ptime_CSE_fmt2io(P_t *pads, Sfio_t *io, int *requested_out,
                    const char *delims, Pbase_m *m, Pbase_pd *pd, Puint32 *rep,
                    Pregexp_t *stopRegexp
                    );

/*@END Pdate_app_149.tex*/

#endif /*  P_CONFIG_A_CHAR_STRING > 0 && P_CONFIG_E_CHAR_STRING > 0  */

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PDATE_H__   */
