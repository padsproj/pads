/*
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PDATE_IMPL_H__
#define __PDATE_IMPL_H__

#ifndef __PADS_IMPL_H__
#error Pdate-impl.h is intended to be included from pads-impl.h, do not include it directly
#endif

/* ================================================================================
 * READ
 */

#if P_CONFIG_READ_FUNCTIONS > 0

Perror_t PDCI_timestamp_FW_read(P_t *pads,
				const Pbase_m *m,
				Pbase_pd *pd,
				Puint32 *d_out,
				Pcharset char_set,
				const char *whatfn,
				const char *format_descr,
				const char *tzone_descr,
				PerrCode_t errCode,
				int just_time,
				const char *format,
				Tm_zone_t *tzone,
				size_t width);

Perror_t PDCI_timestamp_read(P_t *pads,
			     const Pbase_m *m,
			     Pbase_pd *pd,
			     Puint32 *d_out,
			     Pcharset char_set, 
			     const char *whatfn,
			     const char *format_descr,
			     const char *tzone_descr,
			     PerrCode_t errCode,
			     int just_time,
			     const char *format,
			     Tm_zone_t *tzone,
			     Pchar stopChar);

Perror_t PDCI_timestamp_ME_read(P_t *pads,
				const Pbase_m *m,
				Pbase_pd *pd,
				Puint32 *d_out,
				Pcharset char_set,
				const char *whatfn,
				const char *format_descr,
				const char *tzone_descr,
				PerrCode_t errCode,
				int just_time,
				const char *format,
				Tm_zone_t *tzone,
				const char *matchRegexp);

Perror_t PDCI_timestamp_CME_read(P_t *pads,
				 const Pbase_m *m,
				 Pbase_pd *pd,
				 Puint32 *d_out,
				 Pcharset char_set,
				 const char *whatfn,
				 const char *format_descr,
				 const char *tzone_descr,
				 PerrCode_t errCode,
				 int just_time,
				 const char *format,
				 Tm_zone_t *tzone,
				 Pregexp_t *matchRegexp);

Perror_t PDCI_timestamp_SE_read(P_t *pads,
				const Pbase_m *m,
				Pbase_pd *pd,
				Puint32 *d_out,
				Pcharset char_set,
				const char *whatfn,
				const char *format_descr,
				const char *tzone_descr,
				PerrCode_t errCode,
				int just_time,
				const char *format,
				Tm_zone_t *tzone,
				const char *stopRegexp);

Perror_t PDCI_timestamp_CSE_read(P_t *pads,
				 const Pbase_m *m,
				 Pbase_pd *pd,
				 Puint32 *d_out,
				 Pcharset char_set,
				 const char *whatfn,
				 const char *format_descr,
				 const char *tzone_descr,
				 PerrCode_t errCode,
				 int just_time,
				 const char *format,
				 Tm_zone_t *tzone,
				 Pregexp_t *stopRegexp);

Perror_t PDCI_date_FW_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   size_t width);

Perror_t PDCI_date_read(P_t *pads,
			const Pbase_m *m,
			Pbase_pd *pd,
			Puint32 *d_out,
			Pcharset char_set, 
			const char *whatfn,
			const char *format_descr,
			const char *tzone_descr,
			PerrCode_t errCode,
			int just_time,
			const char *format,
			Tm_zone_t *tzone,
			Pchar stopChar);

Perror_t PDCI_date_ME_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   const char *matchRegexp);

Perror_t PDCI_date_CME_read(P_t *pads,
			    const Pbase_m *m,
			    Pbase_pd *pd,
			    Puint32 *d_out,
			    Pcharset char_set,
			    const char *whatfn,
			    const char *format_descr,
			    const char *tzone_descr,
			    PerrCode_t errCode,
			    int just_time,
			    const char *format,
			    Tm_zone_t *tzone,
			    Pregexp_t *matchRegexp);

Perror_t PDCI_date_SE_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   const char *stopRegexp);

Perror_t PDCI_date_CSE_read(P_t *pads,
			    const Pbase_m *m,
			    Pbase_pd *pd,
			    Puint32 *d_out,
			    Pcharset char_set,
			    const char *whatfn,
			    const char *format_descr,
			    const char *tzone_descr,
			    PerrCode_t errCode,
			    int just_time,
			    const char *format,
			    Tm_zone_t *tzone,
			    Pregexp_t *stopRegexp);

Perror_t PDCI_time_FW_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   size_t width);

Perror_t PDCI_time_read(P_t *pads,
			const Pbase_m *m,
			Pbase_pd *pd,
			Puint32 *d_out,
			Pcharset char_set, 
			const char *whatfn,
			const char *format_descr,
			const char *tzone_descr,
			PerrCode_t errCode,
			int just_time,
			const char *format,
			Tm_zone_t *tzone,
			Pchar stopChar);

Perror_t PDCI_time_ME_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   const char *matchRegexp);

Perror_t PDCI_time_CME_read(P_t *pads,
			    const Pbase_m *m,
			    Pbase_pd *pd,
			    Puint32 *d_out,
			    Pcharset char_set,
			    const char *whatfn,
			    const char *format_descr,
			    const char *tzone_descr,
			    PerrCode_t errCode,
			    int just_time,
			    const char *format,
			    Tm_zone_t *tzone,
			    Pregexp_t *matchRegexp);

Perror_t PDCI_time_SE_read(P_t *pads,
			   const Pbase_m *m,
			   Pbase_pd *pd,
			   Puint32 *d_out,
			   Pcharset char_set,
			   const char *whatfn,
			   const char *format_descr,
			   const char *tzone_descr,
			   PerrCode_t errCode,
			   int just_time,
			   const char *format,
			   Tm_zone_t *tzone,
			   const char *stopRegexp);

Perror_t PDCI_time_CSE_read(P_t *pads,
			    const Pbase_m *m,
			    Pbase_pd *pd,
			    Puint32 *d_out,
			    Pcharset char_set,
			    const char *whatfn,
			    const char *format_descr,
			    const char *tzone_descr,
			    PerrCode_t errCode,
			    int just_time,
			    const char *format,
			    Tm_zone_t *tzone,
			    Pregexp_t *stopRegexp);

/* Ptimestamp_explicit */

#define Ptimestamp_explicit_FW_read(pads, m, pd, d_out, width, format, tzone)	\
  PDCI_timestamp_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_FW_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
			 0, \
                         format, tzone, width)

#define Pa_timestamp_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_timestamp_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_FW_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
			 0, \
			 format, tzone, width)

#define Pe_timestamp_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_timestamp_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_FW_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
			 0, \
			 format, tzone, width)

#define Ptimestamp_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_timestamp_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_read", \
		      "format param", \
		      "tzone param", \
		      P_INVALID_TIMESTAMP, \
		      0, \
		      format, tzone, stopChar)

#define Pa_timestamp_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_timestamp_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_read", \
		      "format param", \
		      "tzone param", \
		      P_INVALID_TIMESTAMP, \
		      0, \
		      format, tzone, stopChar)

#define Pe_timestamp_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_timestamp_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_read", \
		      "format param", \
		      "tzone param", \
		      P_INVALID_TIMESTAMP, \
		      0, \
		      format, tzone, stopChar)

#define Ptimestamp_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_ME_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, matchRegexp)

#define Pa_timestamp_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_ME_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, matchRegexp)

#define Pe_timestamp_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_ME_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, matchRegexp)

#define Ptimestamp_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CME_read", \
			  "format param", \
			  "tzone param", \
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, matchRegexp)

#define Pa_timestamp_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_CME_read", \
			  "format param", \
			  "tzone param", \
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, matchRegexp)

#define Pe_timestamp_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_timestamp_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_CME_read", \
			  "format param", \
			  "tzone param", \
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, matchRegexp)

#define Ptimestamp_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_SE_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, stopRegexp)

#define Pa_timestamp_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_SE_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, stopRegexp)

#define Pe_timestamp_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_SE_read", \
			 "format param", \
			 "tzone param", \
			 P_INVALID_TIMESTAMP, \
		         0, \
			 format, tzone, stopRegexp)

#define Ptimestamp_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CSE_read", \
			  "format param", \
			  "tzone param", \
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, stopRegexp)

#define Pa_timestamp_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_explicit_CSE_read", \
			  "format param", \
			  "tzone param",	\
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, stopRegexp)

#define Pe_timestamp_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_timestamp_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_timestamp_explicit_CSE_read", \
			  "format param", \
			  "tzone param",	\
			  P_INVALID_TIMESTAMP, \
		          0, \
			  format, tzone, stopRegexp)

/* Pdate_explicit */

#define Pdate_explicit_FW_read(pads, m, pd, d_out, width, format, tzone)	\
  PDCI_date_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, width)

#define Pa_date_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_date_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, width)

#define Pe_date_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_date_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, width)

#define Pdate_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_date_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_DATE,					\
		 0,							\
		 format, tzone, stopChar)

#define Pa_date_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_date_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_DATE,					\
		 0,							\
		 format, tzone, stopChar)

#define Pe_date_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_date_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_DATE,					\
		 0,							\
		 format, tzone, stopChar)

#define Pdate_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Pa_date_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Pe_date_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Pdate_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Pa_date_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Pe_date_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_date_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Pdate_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Pa_date_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Pe_date_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_DATE,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Pdate_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, stopRegexp)

#define Pa_date_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, stopRegexp)

#define Pe_date_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_date_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_date_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_DATE,					\
		     0,							\
		     format, tzone, stopRegexp)

/* Ptime_explicit */

#define Ptime_explicit_FW_read(pads, m, pd, d_out, width, format, tzone)	\
  PDCI_time_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, width)

#define Pa_time_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_time_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, width)

#define Pe_time_explicit_FW_read(pads, m, pd, d_out, width, format, tzone) \
  PDCI_time_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_explicit_FW_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, width)

#define Ptime_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_time_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_TIME,					\
		 0,							\
		 format, tzone, stopChar)

#define Pa_time_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_time_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_TIME,					\
		 0,							\
		 format, tzone, stopChar)

#define Pe_time_explicit_read(pads, m, pd, d_out, stopChar, format, tzone) \
  PDCI_time_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_explicit_read", \
		 "format param",					\
		 "tzone param",						\
		 P_INVALID_TIME,					\
		 0,							\
		 format, tzone, stopChar)

#define Ptime_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Pa_time_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Pe_time_explicit_ME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_explicit_ME_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, matchRegexp)

#define Ptime_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Pa_time_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Pe_time_explicit_CME_read(pads, m, pd, d_out, matchRegexp, format, tzone) \
  PDCI_time_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_explicit_CME_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, matchRegexp)

#define Ptime_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Pa_time_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Pe_time_explicit_SE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_explicit_SE_read", \
		    "format param",					\
		    "tzone param",					\
		    P_INVALID_TIME,					\
		    0,							\
		    format, tzone, stopRegexp)

#define Ptime_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, stopRegexp)

#define Pa_time_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, stopRegexp)

#define Pe_time_explicit_CSE_read(pads, m, pd, d_out, stopRegexp, format, tzone) \
  PDCI_time_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_time_explicit_CSE_read", \
		     "format param",					\
		     "tzone param",					\
		     P_INVALID_TIME,					\
		     0,							\
		     format, tzone, stopRegexp)

/* Ptimestamp */

#define Ptimestamp_FW_read(pads, m, pd, d_out, width)			\
  PDCI_timestamp_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_FW_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, width)

#define Pa_timestamp_FW_read(pads, m, pd, d_out, width)			\
  PDCI_timestamp_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_FW_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, width)

#define Pe_timestamp_FW_read(pads, m, pd, d_out, width)			\
  PDCI_timestamp_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_FW_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, width)

#define Ptimestamp_read(pads, m, pd, d_out, stopChar)			\
  PDCI_timestamp_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_read", \
		      "pads->disc->in_formats.timestamp",		\
		      "default input time zone",			\
		      P_INVALID_TIMESTAMP,				\
		      0, \
		      pads->disc->in_formats.timestamp, pads->in_zone, stopChar)

#define Pa_timestamp_read(pads, m, pd, d_out, stopChar)			\
  PDCI_timestamp_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_read", \
		      "pads->disc->in_formats.timestamp",		\
		      "default input time zone",			\
		      P_INVALID_TIMESTAMP,				\
		      0, \
		      pads->disc->in_formats.timestamp, pads->in_zone, stopChar)

#define Pe_timestamp_read(pads, m, pd, d_out, stopChar)			\
  PDCI_timestamp_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_read", \
		      "pads->disc->in_formats.timestamp",		\
		      "default input time zone",			\
		      P_INVALID_TIMESTAMP,				\
		      0, \
		      pads->disc->in_formats.timestamp, pads->in_zone, stopChar)

#define Ptimestamp_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_ME_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Pa_timestamp_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_ME_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Pe_timestamp_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_ME_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Ptimestamp_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_CME_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Pa_timestamp_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_CME_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Pe_timestamp_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_timestamp_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_CME_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, matchRegexp)

#define Ptimestamp_SE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_SE_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

#define Pa_timestamp_SE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_SE_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

#define Pe_timestamp_SE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_timestamp_SE_read", \
			 "pads->disc->in_formats.timestamp",		\
			 "default input time zone",			\
			 P_INVALID_TIMESTAMP,				\
		         0, \
			 pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

#define Ptimestamp_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptimestamp_CSE_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

#define Pa_timestamp_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_timestamp_CSE_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

#define Pe_timestamp_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_timestamp_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_timestamp_CSE_read", \
			  "pads->disc->in_formats.timestamp",		\
			  "default input time zone",			\
			  P_INVALID_TIMESTAMP,				\
		          0, \
			  pads->disc->in_formats.timestamp, pads->in_zone, stopRegexp)

/* Pdate */

#define Pdate_FW_read(pads, m, pd, d_out, width)			\
  PDCI_date_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_FW_read", width, \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, width)

#define Pa_date_FW_read(pads, m, pd, d_out, width)			\
  PDCI_date_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_FW_read", width, \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, width)

#define Pe_date_FW_read(pads, m, pd, d_out, width)			\
  PDCI_date_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_FW_read", width, \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, width)

#define Pdate_read(pads, m, pd, d_out, stopChar)			\
  PDCI_date_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_read", \
		 "pads->disc->in_formats.date",				\
		 "default input time zone",				\
		 P_INVALID_DATE,					\
		 0,							\
		 pads->disc->in_formats.date, pads->in_zone, stopChar)

#define Pa_date_read(pads, m, pd, d_out, stopChar)			\
  PDCI_date_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_read", \
		 "pads->disc->in_formats.date",				\
		 "default input time zone",				\
		 P_INVALID_DATE,					\
		 0,							\
		 pads->disc->in_formats.date, pads->in_zone, stopChar)

#define Pe_date_read(pads, m, pd, d_out, stopChar)			\
  PDCI_date_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_read", \
		 "pads->disc->in_formats.date",				\
		 "default input time zone",				\
		 P_INVALID_DATE,					\
		 0,							\
		 pads->disc->in_formats.date, pads->in_zone, stopChar)

#define Pdate_ME_read(pads, m, pd, d_out, matchRegexp)			\
  PDCI_date_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_ME_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pa_date_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_date_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_ME_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pe_date_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_date_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_ME_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pdate_CME_read(pads, m, pd, d_out, matchRegexp)			\
  PDCI_date_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_CME_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pa_date_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_date_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_CME_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pe_date_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_date_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_CME_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, matchRegexp)

#define Pdate_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_date_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_SE_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, stopRegexp)

#define Pa_date_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_date_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_SE_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, stopRegexp)

#define Pe_date_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_date_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_date_SE_read", \
		    "pads->disc->in_formats.date",			\
		    "default input time zone",				\
		    P_INVALID_DATE,					\
		    0,							\
		    pads->disc->in_formats.date, pads->in_zone, stopRegexp)

#define Pdate_CSE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_date_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Pdate_CSE_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, stopRegexp)

#define Pa_date_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_date_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_date_CSE_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, stopRegexp)

#define Pe_date_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_date_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_date_CSE_read", \
		     "pads->disc->in_formats.date",			\
		     "default input time zone",				\
		     P_INVALID_DATE,					\
		     0,							\
		     pads->disc->in_formats.date, pads->in_zone, stopRegexp)

/* Ptime */

#define Ptime_FW_read(pads, m, pd, d_out, width)			\
  PDCI_time_FW_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_FW_read", width, \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, width)

#define Pa_time_FW_read(pads, m, pd, d_out, width)			\
  PDCI_time_FW_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_FW_read", width, \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, width)

#define Pe_time_FW_read(pads, m, pd, d_out, width)			\
  PDCI_time_FW_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_FW_read", width, \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, width)

#define Ptime_read(pads, m, pd, d_out, stopChar)			\
  PDCI_time_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_read", \
		 "pads->disc->in_formats.time",				\
		 "default input time zone",				\
		 P_INVALID_TIME,					\
		 1,							\
		 pads->disc->in_formats.time, pads->in_zone, stopChar)

#define Pa_time_read(pads, m, pd, d_out, stopChar)			\
  PDCI_time_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_read", \
		 "pads->disc->in_formats.time",				\
		 "default input time zone",				\
		 P_INVALID_TIME,					\
		 1,							\
		 pads->disc->in_formats.time, pads->in_zone, stopChar)

#define Pe_time_read(pads, m, pd, d_out, stopChar)			\
  PDCI_time_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_read", \
		 "pads->disc->in_formats.time",				\
		 "default input time zone",				\
		 P_INVALID_TIME,					\
		 1,							\
		 pads->disc->in_formats.time, pads->in_zone, stopChar)

#define Ptime_ME_read(pads, m, pd, d_out, matchRegexp)			\
  PDCI_time_ME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_ME_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Pa_time_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_time_ME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_ME_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Pe_time_ME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_time_ME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_ME_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Ptime_CME_read(pads, m, pd, d_out, matchRegexp)			\
  PDCI_time_CME_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_CME_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Pa_time_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_time_CME_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_CME_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Pe_time_CME_read(pads, m, pd, d_out, matchRegexp)		\
  PDCI_time_CME_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_CME_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, matchRegexp)

#define Ptime_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_time_SE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_SE_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#define Pa_time_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_time_SE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_SE_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#define Pe_time_SE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_time_SE_read(pads, m, pd, d_out, Pcharset_EBCDIC, "Pe_time_SE_read", \
		    "pads->disc->in_formats.time",			\
		    "default input time zone",				\
		    P_INVALID_TIME,					\
		    1,							\
		    pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#define Ptime_CSE_read(pads, m, pd, d_out, stopRegexp)			\
  PDCI_time_CSE_read(pads, m, pd, d_out, PDCI_DEF_CHARSET(pads), "Ptime_CSE_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#define Pa_time_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_time_CSE_read(pads, m, pd, d_out, Pcharset_ASCII, "Pa_time_CSE_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#define Pe_time_CSE_read(pads, m, pd, d_out, stopRegexp)		\
  PDCI_time_CSE_read(pads, m, pd, s_out, Pcharset_EBCDIC, "Pe_time_CSE_read", \
		     "pads->disc->in_formats.time",			\
		     "default input time zone",				\
		     P_INVALID_TIME,					\
		     1,							\
		     pads->disc->in_formats.time, pads->in_zone, stopRegexp)

#endif  /* P_CONFIG_READ_FUNCTIONS */

/* ================================================================================
 * WRITE
 */

#if P_CONFIG_WRITE_FUNCTIONS > 0

ssize_t PDCI_date_time_FW_write2io(P_t *pads,
				   Sfio_t *io,
				   Pbase_pd *pd,
				   Puint32 *d,
				   Pcharset char_set,
				   const char *inv_type,
				   const char *whatfn,
				   const char *format_descr,
				   const char *tzone_descr,
				   const char *format,
				   Tm_zone_t *tzone,
				   size_t width,
				   ...);  /* type args INCLUDING width */

ssize_t PDCI_date_time_FW_write2buf(P_t *pads,
				    Pbyte *buf,
				    size_t buf_len,
				    int *buf_full,
				    Pbase_pd *pd,
				    Puint32 *d,
				    Pcharset char_set,
				    const char *inv_type,
				    const char *whatfn,
				    const char *format_descr,
				    const char *tzone_descr,
				    const char *format,
				    Tm_zone_t *tzone,
				    size_t width,
				    ...);  /* type args INCLUDING width */

ssize_t PDCI_date_time_write2io(P_t *pads,
				Sfio_t *io,
				Pbase_pd *pd,
				Puint32 *d,
				Pcharset char_set,
				const char *inv_type,
				const char *whatfn,
				const char *format_descr,
				const char *tzone_descr,
				const char *format,
				Tm_zone_t *tzone,
				...); /* type args */

ssize_t PDCI_date_time_write2buf(P_t *pads,
				 Pbyte *buf,
				 size_t buf_len,
				 int *buf_full,
				 Pbase_pd *pd,
				 Puint32 *d,
				 Pcharset char_set,
				 const char *inv_type,
				 const char *whatfn,
				 const char *format_descr,
				 const char *tzone_descr,
				 const char *format,
				 Tm_zone_t *tzone,
				 ...); /* type args */

ssize_t PDCI_date_time_write_xml_2io(P_t *pads,
				     Sfio_t *io,
				     Pbase_pd *pd,
				     Puint32 *d,
				     const char* tag,
				     int indent,
				     const char *inv_type,
				     const char *whatfn,
				     const char *format_descr,
				     const char *tzone_descr,
				     const char *format,
				     Tm_zone_t *tzone,
				     ...); /* type args */

ssize_t PDCI_date_time_write_xml_2buf(P_t *pads,
				      Pbyte *buf,
				      size_t buf_len,
				      int *buf_full,
				      Pbase_pd *pd,
				      Puint32 *d,
				      const char* tag,
				      int indent,
				      const char *inv_type,
				      const char *whatfn,
				      const char *format_descr,
				      const char *tzone_descr,
				      const char *format,
				      Tm_zone_t *tzone,
				      ...); /* type args */

/* Ptimestamp_explicit */

#define Ptimestamp_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_FW", "Ptimestamp_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pa_timestamp_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_timestamp_explicit_FW", "Pa_timestamp_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pe_timestamp_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_timestamp_explicit_FW", "Pe_timestamp_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Ptimestamp_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_FW", "Ptimestamp_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pa_timestamp_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_timestamp_explicit_FW", "Pa_timestamp_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pe_timestamp_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_timestamp_explicit_FW", "Pe_timestamp_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Ptimestamp_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit", "Ptimestamp_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pa_timestamp_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_explicit", "Pa_timestamp_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pe_timestamp_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit", "Pe_timestamp_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Ptimestamp_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit", "Ptimestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pa_timestamp_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_explicit", "Pa_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pe_timestamp_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit", "Pe_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Ptimestamp_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_ME", "Ptimestamp_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_timestamp_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_ME", "Pa_timestamp_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_timestamp_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_ME", "Pe_timestamp_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Ptimestamp_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_ME", "P_ME_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_timestamp_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_ME", "Pa_timestamp_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_timestamp_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_ME", "Pe_timestamp_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Ptimestamp_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CME", "Ptimestamp_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_timestamp_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_CME", "Pa_timestamp_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_timestamp_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_CME", "Pe_timestamp_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Ptimestamp_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CME", "P_CME_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_timestamp_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_CME", "Pa_timestamp_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_timestamp_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_CME", "Pe_timestamp_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Ptimestamp_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_SE", "Ptimestamp_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_timestamp_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_SE", "Pa_timestamp_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_timestamp_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_SE", "Pe_timestamp_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Ptimestamp_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_SE", "P_SE_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_timestamp_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_SE", "Pa_timestamp_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_timestamp_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_SE", "Pe_timestamp_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Ptimestamp_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CSE", "Ptimestamp_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_timestamp_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_CSE", "Pa_timestamp_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_timestamp_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_CSE", "Pe_timestamp_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Ptimestamp_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_explicit_CSE", "P_CSE_timestamp_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_timestamp_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_explicit_CSE", "Pa_timestamp_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_timestamp_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_explicit_CSE", "Pe_timestamp_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Ptimestamp_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_FW", "Ptimestamp_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pa_timestamp_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_timestamp_explicit_FW", "Pa_timestamp_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pe_timestamp_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_timestamp_explicit_FW", "Pe_timestamp_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       width, format, tzone)

#define Ptimestamp_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_FW", "Ptimestamp_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				width, format, tzone)

#define Pa_timestamp_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_timestamp_explicit_FW", "Pa_timestamp_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				width, format, tzone)

#define Pe_timestamp_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_timestamp_explicit_FW", "Pe_timestamp_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				width, format, tzone)

#define Ptimestamp_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit", "Ptimestamp_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pa_timestamp_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit", "Pa_timestamp_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pe_timestamp_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit", "Pe_timestamp_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Ptimestamp_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit", "Ptimestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pa_timestamp_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit", "Pa_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pe_timestamp_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit", "Pe_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Ptimestamp_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_ME", "Ptimestamp_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_timestamp_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_ME", "Pa_timestamp_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_timestamp_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_ME", "Pe_timestamp_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Ptimestamp_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_ME", "P_ME_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_timestamp_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_ME", "Pa_timestamp_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_timestamp_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_ME", "Pe_timestamp_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Ptimestamp_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CME", "Ptimestamp_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_timestamp_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CME", "Pa_timestamp_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_timestamp_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CME", "Pe_timestamp_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Ptimestamp_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CME", "P_CME_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_timestamp_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CME", "Pa_timestamp_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_timestamp_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CME", "Pe_timestamp_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Ptimestamp_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_SE", "Ptimestamp_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_timestamp_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_SE", "Pa_timestamp_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_timestamp_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_SE", "Pe_timestamp_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Ptimestamp_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_SE", "P_SE_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_timestamp_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_SE", "Pa_timestamp_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_timestamp_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_SE", "Pe_timestamp_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Ptimestamp_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "Ptimestamp_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_timestamp_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "Pa_timestamp_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_timestamp_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "Pe_timestamp_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Ptimestamp_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "P_CSE_timestamp_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_timestamp_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "Pa_timestamp_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_timestamp_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_explicit_CSE", "Pe_timestamp_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.timestamp_explicit, pads->out_zone, \
				stopRegexp, format, tzone)
/* Pdate_explicit */

#define Pdate_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_FW", "Pdate_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.date_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pa_date_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_date_explicit_FW", "Pa_date_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.date_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pe_date_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_date_explicit_FW", "Pe_date_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.date_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pdate_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_FW", "Pdate_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.date_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pa_date_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_date_explicit_FW", "Pa_date_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.date_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pe_date_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_date_explicit_FW", "Pe_date_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.date_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pdate_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit", "Pdate_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pa_date_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_explicit", "Pa_date_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pe_date_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_explicit", "Pe_date_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pdate_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit", "Pdate_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pa_date_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_explicit", "Pa_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pe_date_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_explicit", "Pe_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pdate_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_ME", "Pdate_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_date_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_explicit_ME", "Pa_date_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_date_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_explicit_ME", "Pe_date_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pdate_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_ME", "P_ME_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_date_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_explicit_ME", "Pa_date_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_date_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_explicit_ME", "Pe_date_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pdate_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CME", "Pdate_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_date_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_explicit_CME", "Pa_date_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_date_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_explicit_CME", "Pe_date_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pdate_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CME", "P_CME_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_date_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_explicit_CME", "Pa_date_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_date_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_explicit_CME", "Pe_date_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pdate_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_SE", "Pdate_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_date_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_explicit_SE", "Pa_date_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_date_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_explicit_SE", "Pe_date_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pdate_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_SE", "P_SE_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_date_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_explicit_SE", "Pa_date_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_date_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_explicit_SE", "Pe_date_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pdate_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CSE", "Pdate_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_date_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_explicit_CSE", "Pa_date_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_date_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_explicit_CSE", "Pe_date_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.date_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pdate_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_explicit_CSE", "P_CSE_date_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_date_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_explicit_CSE", "Pa_date_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_date_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_explicit_CSE", "Pe_date_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.date_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pdate_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_FW", "Pdate_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pa_date_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_date_explicit_FW", "Pa_date_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pe_date_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_date_explicit_FW", "Pe_date_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pdate_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_FW", "Pdate_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				width, format, tzone)

#define Pa_date_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_date_explicit_FW", "Pa_date_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				width, format, tzone)

#define Pe_date_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_date_explicit_FW", "Pe_date_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				width, format, tzone)

#define Pdate_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit", "Pdate_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pa_date_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit", "Pa_date_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pe_date_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit", "Pe_date_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pdate_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit", "Pdate_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pa_date_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit", "Pa_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pe_date_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit", "Pe_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pdate_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_ME", "Pdate_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_date_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_ME", "Pa_date_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_date_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_ME", "Pe_date_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pdate_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_ME", "P_ME_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_date_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_ME", "Pa_date_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_date_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_ME", "Pe_date_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pdate_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CME", "Pdate_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_date_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CME", "Pa_date_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_date_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CME", "Pe_date_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pdate_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CME", "P_CME_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_date_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CME", "Pa_date_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_date_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CME", "Pe_date_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pdate_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_SE", "Pdate_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_date_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_SE", "Pa_date_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_date_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_SE", "Pe_date_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pdate_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_SE", "P_SE_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_date_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_SE", "Pa_date_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_date_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_SE", "Pe_date_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pdate_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CSE", "Pdate_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_date_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CSE", "Pa_date_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_date_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_explicit_CSE", "Pe_date_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.date_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pdate_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CSE", "P_CSE_date_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_date_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CSE", "Pa_date_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_date_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_explicit_CSE", "Pe_date_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.date_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

/* Ptime_explicit */

#define Ptime_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_FW", "Ptime_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.time_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pa_time_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_time_explicit_FW", "Pa_time_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.time_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Pe_time_explicit_FW_write2io(pads, io, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_time_explicit_FW", "Pe_time_explicit_FW_write2io", \
			     "format param", "tzone param", \
			     pads->disc->out_formats.time_explicit, pads->out_zone, \
			     width, \
			     width, format, tzone)

#define Ptime_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_FW", "Ptime_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.time_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pa_time_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_time_explicit_FW", "Pa_time_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.time_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Pe_time_explicit_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width, format, tzone) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_time_explicit_FW", "Pe_time_explicit_FW_write2buf", \
			      "format param", "tzone param", \
			      pads->disc->out_formats.time_explicit, pads->out_zone, \
			      width, \
			      width, format, tzone)

#define Ptime_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit", "Ptime_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pa_time_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_explicit", "Pa_time_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Pe_time_explicit_write2io(pads, io, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_explicit", "Pe_time_explicit_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopChar, format, tzone)

#define Ptime_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit", "Ptime_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pa_time_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_explicit", "Pa_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Pe_time_explicit_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_explicit", "Pe_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopChar, format, tzone)

#define Ptime_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_ME", "Ptime_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_time_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_explicit_ME", "Pa_time_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_time_explicit_ME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_explicit_ME", "Pe_time_explicit_ME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Ptime_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_ME", "P_ME_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_time_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_explicit_ME", "Pa_time_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_time_explicit_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_explicit_ME", "Pe_time_explicit_ME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Ptime_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CME", "Ptime_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pa_time_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_explicit_CME", "Pa_time_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Pe_time_explicit_CME_write2io(pads, io, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_explicit_CME", "Pe_time_explicit_CME_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  matchRegexp, format, tzone)

#define Ptime_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CME", "P_CME_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pa_time_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_explicit_CME", "Pa_time_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Pe_time_explicit_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_explicit_CME", "Pe_time_explicit_CME_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   matchRegexp, format, tzone)

#define Ptime_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_SE", "Ptime_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_time_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_explicit_SE", "Pa_time_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_time_explicit_SE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_explicit_SE", "Pe_time_explicit_SE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Ptime_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_SE", "P_SE_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_time_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_explicit_SE", "Pa_time_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_time_explicit_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_explicit_SE", "Pe_time_explicit_SE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Ptime_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CSE", "Ptime_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pa_time_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_explicit_CSE", "Pa_time_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Pe_time_explicit_CSE_write2io(pads, io, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_explicit_CSE", "Pe_time_explicit_CSE_write2io", \
			  "format param", "tzone param", \
			  pads->disc->out_formats.time_explicit, pads->out_zone, \
			  stopRegexp, format, tzone)

#define Ptime_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_explicit_CSE", "P_CSE_time_explicit_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pa_time_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_explicit_CSE", "Pa_time_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Pe_time_explicit_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp, format, tzone) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_explicit_CSE", "Pe_time_explicit_CSE_write2buf", \
			   "format param", "tzone param", \
			   pads->disc->out_formats.time_explicit, pads->out_zone, \
			   stopRegexp, format, tzone)

#define Ptime_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_FW", "Ptime_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pa_time_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_time_explicit_FW", "Pa_time_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       width, format, tzone)

#define Pe_time_explicit_FW_write_xml_2io(pads, io, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_time_explicit_FW", "Pe_time_explicit_FW_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       width, format, tzone)

#define Ptime_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_FW", "Ptime_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				width, format, tzone)

#define Pa_time_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_time_explicit_FW", "Pa_time_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				width, format, tzone)

#define Pe_time_explicit_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_time_explicit_FW", "Pe_time_explicit_FW_write_xml_2buf", \
				"format param", "tzone param",		\
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				width, format, tzone)

#define Ptime_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit", "Ptime_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pa_time_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit", "Pa_time_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Pe_time_explicit_write_xml_2io(pads, io, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit", "Pe_time_explicit_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopChar, format, tzone)

#define Ptime_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit", "Ptime_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pa_time_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit", "Pa_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Pe_time_explicit_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit", "Pe_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopChar, format, tzone)

#define Ptime_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_ME", "Ptime_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_time_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_ME", "Pa_time_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_time_explicit_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_ME", "Pe_time_explicit_ME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Ptime_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_ME", "P_ME_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_time_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_ME", "Pa_time_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_time_explicit_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_ME", "Pe_time_explicit_ME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Ptime_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CME", "Ptime_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pa_time_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CME", "Pa_time_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Pe_time_explicit_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CME", "Pe_time_explicit_CME_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       matchRegexp, format, tzone)

#define Ptime_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CME", "P_CME_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pa_time_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CME", "Pa_time_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Pe_time_explicit_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CME", "Pe_time_explicit_CME_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				matchRegexp, format, tzone)

#define Ptime_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_SE", "Ptime_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_time_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_SE", "Pa_time_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_time_explicit_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_SE", "Pe_time_explicit_SE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Ptime_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_SE", "P_SE_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_time_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_SE", "Pa_time_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_time_explicit_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_SE", "Pe_time_explicit_SE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Ptime_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CSE", "Ptime_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pa_time_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CSE", "Pa_time_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Pe_time_explicit_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_explicit_CSE", "Pe_time_explicit_CSE_write_xml_2io", \
			       "format param", "tzone param", \
			       pads->disc->out_formats.time_explicit, pads->out_zone, \
			       stopRegexp, format, tzone)

#define Ptime_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CSE", "P_CSE_time_explicit_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pa_time_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CSE", "Pa_time_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

#define Pe_time_explicit_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp, format, tzone) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_explicit_CSE", "Pe_time_explicit_CSE_write_xml_2buf", \
				"format param", "tzone param", \
				pads->disc->out_formats.time_explicit, pads->out_zone, \
				stopRegexp, format, tzone)

/* Ptimestamp */

#define Ptimestamp_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_FW", "Ptimestamp_FW_write2io", \
			     "pads->disc->out_formats.timestamp", "default output time zone", \
			     pads->disc->out_formats.timestamp, pads->out_zone, \
			     width, \
			     width)

#define Pa_timestamp_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_timestamp_FW", "Pa_timestamp_FW_write2io", \
			     "pads->disc->out_formats.timestamp", "default output time zone", \
			     pads->disc->out_formats.timestamp, pads->out_zone, \
			     width, \
			     width)

#define Pe_timestamp_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_timestamp_FW", "Pe_timestamp_FW_write2io", \
			     "pads->disc->out_formats.timestamp", "default output time zone", \
			     pads->disc->out_formats.timestamp, pads->out_zone, \
			     width, \
			     width)

#define Ptimestamp_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_FW", "Ptimestamp_FW_write2buf", \
			      "pads->disc->out_formats.timestamp", "default output time zone", \
			      pads->disc->out_formats.timestamp, pads->out_zone, \
			      width, \
			      width)

#define Pa_timestamp_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_timestamp_FW", "Pa_timestamp_FW_write2buf", \
			      "pads->disc->out_formats.timestamp", "default output time zone", \
			      pads->disc->out_formats.timestamp, pads->out_zone, \
			      width, \
			      width)

#define Pe_timestamp_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_timestamp_FW", "Pe_timestamp_FW_write2buf", \
			      "pads->disc->out_formats.timestamp", "default output time zone", \
			      pads->disc->out_formats.timestamp, pads->out_zone, \
			      width, \
			      width)

#define Ptimestamp_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp", "Ptimestamp_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopChar)

#define Pa_timestamp_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp", "Pa_timestamp_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopChar)

#define Pe_timestamp_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp", "Pe_timestamp_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopChar)

#define Ptimestamp_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp", "Ptimestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopChar)

#define Pa_timestamp_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp", "Pa_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopChar)

#define Pe_timestamp_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp", "Pe_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopChar)

#define Ptimestamp_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_ME", "Ptimestamp_ME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Pa_timestamp_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_ME", "Pa_timestamp_ME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Pe_timestamp_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_ME", "Pe_timestamp_ME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Ptimestamp_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_ME", "P_ME_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Pa_timestamp_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_ME", "Pa_timestamp_ME_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Pe_timestamp_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_ME", "Pe_timestamp_ME_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Ptimestamp_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_CME", "Ptimestamp_CME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Pa_timestamp_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_CME", "Pa_timestamp_CME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Pe_timestamp_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_CME", "Pe_timestamp_CME_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  matchRegexp)

#define Ptimestamp_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_CME", "P_CME_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Pa_timestamp_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_CME", "Pa_timestamp_CME_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Pe_timestamp_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_CME", "Pe_timestamp_CME_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   matchRegexp)

#define Ptimestamp_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_SE", "Ptimestamp_SE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Pa_timestamp_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_SE", "Pa_timestamp_SE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Pe_timestamp_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_SE", "Pe_timestamp_SE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Ptimestamp_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_SE", "P_SE_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Pa_timestamp_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_SE", "Pa_timestamp_SE_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Pe_timestamp_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_SE", "Pe_timestamp_SE_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Ptimestamp_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_CSE", "Ptimestamp_CSE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Pa_timestamp_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptimestamp_CSE", "Pa_timestamp_CSE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Pe_timestamp_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptimestamp_CSE", "Pe_timestamp_CSE_write2io", \
			  "pads->disc->out_formats.timestamp", "default output time zone", \
			  pads->disc->out_formats.timestamp, pads->out_zone, \
			  stopRegexp)

#define Ptimestamp_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptimestamp_CSE", "P_CSE_timestamp_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Pa_timestamp_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptimestamp_CSE", "Pa_timestamp_CSE_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Pe_timestamp_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptimestamp_CSE", "Pe_timestamp_CSE_write2buf", \
			   "pads->disc->out_formats.timestamp", "default output time zone", \
			   pads->disc->out_formats.timestamp, pads->out_zone, \
			   stopRegexp)

#define Ptimestamp_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_FW", "Ptimestamp_FW_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Pa_timestamp_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_timestamp_FW", "Pa_timestamp_FW_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Pe_timestamp_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_timestamp_FW", "Pe_timestamp_FW_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Ptimestamp_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_FW", "Ptimestamp_FW_write_xml_2buf", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Pa_timestamp_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_timestamp_FW", "Pa_timestamp_FW_write_xml_2buf", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Pe_timestamp_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_timestamp_FW", "Pe_timestamp_FW_write_xml_2buf", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       width)

#define Ptimestamp_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp", "Ptimestamp_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopChar)

#define Pa_timestamp_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp", "Pa_timestamp_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopChar)

#define Pe_timestamp_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp", "Pe_timestamp_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopChar)

#define Ptimestamp_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp", "Ptimestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopChar)

#define Pa_timestamp_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp", "Pa_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopChar)

#define Pe_timestamp_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp", "Pe_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopChar)

#define Ptimestamp_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_ME", "Ptimestamp_ME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Pa_timestamp_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_ME", "Pa_timestamp_ME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Pe_timestamp_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_ME", "Pe_timestamp_ME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Ptimestamp_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_ME", "P_ME_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Pa_timestamp_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_ME", "Pa_timestamp_ME_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Pe_timestamp_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_ME", "Pe_timestamp_ME_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Ptimestamp_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CME", "Ptimestamp_CME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Pa_timestamp_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CME", "Pa_timestamp_CME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Pe_timestamp_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CME", "Pe_timestamp_CME_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       matchRegexp)

#define Ptimestamp_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CME", "P_CME_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Pa_timestamp_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CME", "Pa_timestamp_CME_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Pe_timestamp_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CME", "Pe_timestamp_CME_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				matchRegexp)

#define Ptimestamp_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_SE", "Ptimestamp_SE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Pa_timestamp_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_SE", "Pa_timestamp_SE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Pe_timestamp_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_SE", "Pe_timestamp_SE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Ptimestamp_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_SE", "P_SE_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

#define Pa_timestamp_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_SE", "Pa_timestamp_SE_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

#define Pe_timestamp_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_SE", "Pe_timestamp_SE_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

#define Ptimestamp_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CSE", "Ptimestamp_CSE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Pa_timestamp_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CSE", "Pa_timestamp_CSE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Pe_timestamp_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptimestamp_CSE", "Pe_timestamp_CSE_write_xml_2io", \
			       "pads->disc->out_formats.timestamp", "default output time zone", \
			       pads->disc->out_formats.timestamp, pads->out_zone, \
			       stopRegexp)

#define Ptimestamp_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CSE", "P_CSE_timestamp_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

#define Pa_timestamp_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CSE", "Pa_timestamp_CSE_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

#define Pe_timestamp_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptimestamp_CSE", "Pe_timestamp_CSE_write_xml_2buf", \
				"pads->disc->out_formats.timestamp", "default output time zone", \
				pads->disc->out_formats.timestamp, pads->out_zone, \
				stopRegexp)

/* Pdate */

#define Pdate_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_FW", "Pdate_FW_write2io", \
			     "pads->disc->out_formats.date", "default output time zone", \
			     pads->disc->out_formats.date, pads->out_zone, \
			     width, \
			     width)

#define Pa_date_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_date_FW", "Pa_date_FW_write2io", \
			     "pads->disc->out_formats.date", "default output time zone", \
			     pads->disc->out_formats.date, pads->out_zone, \
			     width, \
			     width)

#define Pe_date_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_date_FW", "Pe_date_FW_write2io", \
			     "pads->disc->out_formats.date", "default output time zone", \
			     pads->disc->out_formats.date, pads->out_zone, \
			     width, \
			     width)

#define Pdate_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_FW", "Pdate_FW_write2buf", \
			      "pads->disc->out_formats.date", "default output time zone", \
			      pads->disc->out_formats.date, pads->out_zone, \
			      width, \
			      width)

#define Pa_date_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_date_FW", "Pa_date_FW_write2buf", \
			      "pads->disc->out_formats.date", "default output time zone", \
			      pads->disc->out_formats.date, pads->out_zone, \
			      width, \
			      width)

#define Pe_date_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_date_FW", "Pe_date_FW_write2buf", \
			      "pads->disc->out_formats.date", "default output time zone", \
			      pads->disc->out_formats.date, pads->out_zone, \
			      width, \
			      width)

#define Pdate_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate", "Pdate_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopChar)

#define Pa_date_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate", "Pa_date_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopChar)

#define Pe_date_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate", "Pe_date_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopChar)

#define Pdate_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate", "Pdate_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopChar)

#define Pa_date_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate", "Pa_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopChar)

#define Pe_date_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate", "Pe_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopChar)

#define Pdate_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_ME", "Pdate_ME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pa_date_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_ME", "Pa_date_ME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pe_date_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_ME", "Pe_date_ME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pdate_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_ME", "P_ME_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pa_date_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_ME", "Pa_date_ME_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pe_date_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_ME", "Pe_date_ME_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pdate_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_CME", "Pdate_CME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pa_date_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_CME", "Pa_date_CME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pe_date_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_CME", "Pe_date_CME_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  matchRegexp)

#define Pdate_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_CME", "P_CME_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pa_date_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_CME", "Pa_date_CME_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pe_date_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_CME", "Pe_date_CME_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   matchRegexp)

#define Pdate_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_SE", "Pdate_SE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pa_date_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_SE", "Pa_date_SE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pe_date_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_SE", "Pe_date_SE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pdate_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_SE", "P_SE_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pa_date_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_SE", "Pa_date_SE_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pe_date_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_SE", "Pe_date_SE_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pdate_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_CSE", "Pdate_CSE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pa_date_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Pdate_CSE", "Pa_date_CSE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pe_date_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pdate_CSE", "Pe_date_CSE_write2io", \
			  "pads->disc->out_formats.date", "default output time zone", \
			  pads->disc->out_formats.date, pads->out_zone, \
			  stopRegexp)

#define Pdate_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Pdate_CSE", "P_CSE_date_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pa_date_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pdate_CSE", "Pa_date_CSE_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pe_date_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pdate_CSE", "Pe_date_CSE_write2buf", \
			   "pads->disc->out_formats.date", "default output time zone", \
			   pads->disc->out_formats.date, pads->out_zone, \
			   stopRegexp)

#define Pdate_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_FW", "Pdate_FW_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pa_date_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_date_FW", "Pa_date_FW_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pe_date_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_date_FW", "Pe_date_FW_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pdate_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_FW", "Pdate_FW_write_xml_2buf", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pa_date_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_date_FW", "Pa_date_FW_write_xml_2buf", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pe_date_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_date_FW", "Pe_date_FW_write_xml_2buf", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       width)

#define Pdate_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate", "Pdate_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopChar)

#define Pa_date_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate", "Pa_date_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopChar)

#define Pe_date_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate", "Pe_date_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopChar)

#define Pdate_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate", "Pdate_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopChar)

#define Pa_date_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate", "Pa_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopChar)

#define Pe_date_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate", "Pe_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopChar)

#define Pdate_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_ME", "Pdate_ME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pa_date_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_ME", "Pa_date_ME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pe_date_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_ME", "Pe_date_ME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pdate_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_ME", "P_ME_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pa_date_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_ME", "Pa_date_ME_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pe_date_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_ME", "Pe_date_ME_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pdate_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CME", "Pdate_CME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pa_date_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CME", "Pa_date_CME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pe_date_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CME", "Pe_date_CME_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       matchRegexp)

#define Pdate_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CME", "P_CME_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pa_date_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CME", "Pa_date_CME_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pe_date_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CME", "Pe_date_CME_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				matchRegexp)

#define Pdate_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_SE", "Pdate_SE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pa_date_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_SE", "Pa_date_SE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pe_date_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_SE", "Pe_date_SE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pdate_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_SE", "P_SE_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

#define Pa_date_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_SE", "Pa_date_SE_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

#define Pe_date_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_SE", "Pe_date_SE_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

#define Pdate_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CSE", "Pdate_CSE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pa_date_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CSE", "Pa_date_CSE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pe_date_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pdate_CSE", "Pe_date_CSE_write_xml_2io", \
			       "pads->disc->out_formats.date", "default output time zone", \
			       pads->disc->out_formats.date, pads->out_zone, \
			       stopRegexp)

#define Pdate_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CSE", "P_CSE_date_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

#define Pa_date_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CSE", "Pa_date_CSE_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

#define Pe_date_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pdate_CSE", "Pe_date_CSE_write_xml_2buf", \
				"pads->disc->out_formats.date", "default output time zone", \
				pads->disc->out_formats.date, pads->out_zone, \
				stopRegexp)

/* Ptime */

#define Ptime_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_FW", "Ptime_FW_write2io", \
			     "pads->disc->out_formats.time", "default output time zone", \
			     pads->disc->out_formats.time, pads->out_zone, \
			     width, \
			     width)

#define Pa_time_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_ASCII, "Pa_time_FW", "Pa_time_FW_write2io", \
			     "pads->disc->out_formats.time", "default output time zone", \
			     pads->disc->out_formats.time, pads->out_zone, \
			     width, \
			     width)

#define Pe_time_FW_write2io(pads, io, pd, d, width) \
  PDCI_date_time_FW_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Pe_time_FW", "Pe_time_FW_write2io", \
			     "pads->disc->out_formats.time", "default output time zone", \
			     pads->disc->out_formats.time, pads->out_zone, \
			     width, \
			     width)

#define Ptime_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_FW", "Ptime_FW_write2buf", \
			      "pads->disc->out_formats.time", "default output time zone", \
			      pads->disc->out_formats.time, pads->out_zone, \
			      width, \
			      width)

#define Pa_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Pa_time_FW", "Pa_time_FW_write2buf", \
			      "pads->disc->out_formats.time", "default output time zone", \
			      pads->disc->out_formats.time, pads->out_zone, \
			      width, \
			      width)

#define Pe_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, width) \
  PDCI_date_time_FW_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Pe_time_FW", "Pe_time_FW_write2buf", \
			      "pads->disc->out_formats.time", "default output time zone", \
			      pads->disc->out_formats.time, pads->out_zone, \
			      width, \
			      width)

#define Ptime_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime", "Ptime_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopChar)

#define Pa_time_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime", "Pa_time_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopChar)

#define Pe_time_write2io(pads, io, pd, d, stopChar) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime", "Pe_time_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopChar)

#define Ptime_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime", "Ptime_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopChar)

#define Pa_time_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime", "Pa_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopChar)

#define Pe_time_write2buf(pads, buf, buf_len, buf_full, pd, d, stopChar) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime", "Pe_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopChar)

#define Ptime_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_ME", "Ptime_ME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Pa_time_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_ME", "Pa_time_ME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Pe_time_ME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_ME", "Pe_time_ME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Ptime_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_ME", "P_ME_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Pa_time_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_ME", "Pa_time_ME_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Pe_time_ME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_ME", "Pe_time_ME_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Ptime_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_CME", "Ptime_CME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Pa_time_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_CME", "Pa_time_CME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Pe_time_CME_write2io(pads, io, pd, d, matchRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_CME", "Pe_time_CME_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  matchRegexp)

#define Ptime_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_CME", "P_CME_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Pa_time_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_CME", "Pa_time_CME_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Pe_time_CME_write2buf(pads, buf, buf_len, buf_full, pd, d, matchRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_CME", "Pe_time_CME_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   matchRegexp)

#define Ptime_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_SE", "Ptime_SE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Pa_time_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_SE", "Pa_time_SE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Pe_time_SE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_SE", "Pe_time_SE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Ptime_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_SE", "P_SE_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Pa_time_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_SE", "Pa_time_SE_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Pe_time_SE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_SE", "Pe_time_SE_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Ptime_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_CSE", "Ptime_CSE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Pa_time_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_ASCII, "Ptime_CSE", "Pa_time_CSE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Pe_time_CSE_write2io(pads, io, pd, d, stopRegexp) \
  PDCI_date_time_write2io(pads, io, pd, d, Pcharset_EBCDIC, "Ptime_CSE", "Pe_time_CSE_write2io", \
			  "pads->disc->out_formats.time", "default output time zone", \
			  pads->disc->out_formats.time, pads->out_zone, \
			  stopRegexp)

#define Ptime_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, PDCI_DEF_CHARSET(pads), "Ptime_CSE", "P_CSE_time_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Pa_time_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_ASCII, "Ptime_CSE", "Pa_time_CSE_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Pe_time_CSE_write2buf(pads, buf, buf_len, buf_full, pd, d, stopRegexp) \
  PDCI_date_time_write2buf(pads, buf, buf_len, buf_full, pd, d, Pcharset_EBCDIC, "Ptime_CSE", "Pe_time_CSE_write2buf", \
			   "pads->disc->out_formats.time", "default output time zone", \
			   pads->disc->out_formats.time, pads->out_zone, \
			   stopRegexp)

#define Ptime_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_FW", "Ptime_FW_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Pa_time_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pa_time_FW", "Pa_time_FW_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Pe_time_FW_write_xml_2io(pads, io, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Pe_time_FW", "Pe_time_FW_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Ptime_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_FW", "Ptime_FW_write_xml_2buf", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Pa_time_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pa_time_FW", "Pa_time_FW_write_xml_2buf", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Pe_time_FW_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, width) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Pe_time_FW", "Pe_time_FW_write_xml_2buf", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       width)

#define Ptime_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime", "Ptime_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopChar)

#define Pa_time_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime", "Pa_time_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopChar)

#define Pe_time_write_xml_2io(pads, io, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime", "Pe_time_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopChar)

#define Ptime_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime", "Ptime_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopChar)

#define Pa_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime", "Pa_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopChar)

#define Pe_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopChar) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime", "Pe_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopChar)

#define Ptime_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_ME", "Ptime_ME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Pa_time_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_ME", "Pa_time_ME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Pe_time_ME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_ME", "Pe_time_ME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Ptime_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_ME", "P_ME_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Pa_time_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_ME", "Pa_time_ME_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Pe_time_ME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_ME", "Pe_time_ME_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Ptime_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CME", "Ptime_CME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Pa_time_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CME", "Pa_time_CME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Pe_time_CME_write_xml_2io(pads, io, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CME", "Pe_time_CME_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       matchRegexp)

#define Ptime_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CME", "P_CME_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Pa_time_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CME", "Pa_time_CME_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Pe_time_CME_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, matchRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CME", "Pe_time_CME_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				matchRegexp)

#define Ptime_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_SE", "Ptime_SE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Pa_time_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_SE", "Pa_time_SE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Pe_time_SE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_SE", "Pe_time_SE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Ptime_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_SE", "P_SE_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#define Pa_time_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_SE", "Pa_time_SE_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#define Pe_time_SE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_SE", "Pe_time_SE_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#define Ptime_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CSE", "Ptime_CSE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Pa_time_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CSE", "Pa_time_CSE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Pe_time_CSE_write_xml_2io(pads, io, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2io(pads, io, pd, d, tag, indent, "Ptime_CSE", "Pe_time_CSE_write_xml_2io", \
			       "pads->disc->out_formats.time", "default output time zone", \
			       pads->disc->out_formats.time, pads->out_zone, \
			       stopRegexp)

#define Ptime_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CSE", "P_CSE_time_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#define Pa_time_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CSE", "Pa_time_CSE_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#define Pe_time_CSE_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, stopRegexp) \
  PDCI_date_time_write_xml_2buf(pads, buf, buf_len, buf_full, pd, d, tag, indent, "Ptime_CSE", "Pe_time_CSE_write_xml_2buf", \
				"pads->disc->out_formats.time", "default output time zone", \
				pads->disc->out_formats.time, pads->out_zone, \
				stopRegexp)

#endif /* P_CONFIG_WRITE_FUNCTIONS */

#endif  /*  __PDATE_IMPL_H__   */
