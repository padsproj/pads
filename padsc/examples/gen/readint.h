#ifndef __READINT__H__
#define __READINT__H__
#include "pads.h"
typedef struct line_s line;
typedef struct line_m_s line_m;
typedef struct line_pd_s line_pd;
struct line_m_s {
  Pbase_m compoundLevel;
  Pbase_m i8;		/* nested constraints */
  Pbase_m i16;		/* nested constraints */
  Pbase_m i32;		/* nested constraints */
  Pbase_m i64;		/* nested constraints */
  Pbase_m ui8;		/* nested constraints */
  Pbase_m ui16;		/* nested constraints */
  Pbase_m ui32;		/* nested constraints */
  Pbase_m ui64;		/* nested constraints */
};
struct line_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd i8;
  Pbase_pd i16;
  Pbase_pd i32;
  Pbase_pd i64;
  Pbase_pd ui8;
  Pbase_pd ui16;
  Pbase_pd ui32;
  Pbase_pd ui64;
};
struct line_s {
  Pint8 i8;
  Pint16 i16;
  Pint32 i32;
  Pint64 i64;
  Puint8 ui8;
  Puint16 ui16;
  Puint32 ui32;
  Puint64 ui64;
};

Perror_t line_init (P_t *pads,line *rep);

Perror_t line_pd_init (P_t *pads,line_pd *pd);

Perror_t line_cleanup (P_t *pads,line *rep);

Perror_t line_pd_cleanup (P_t *pads,line_pd *pd);

Perror_t line_copy (P_t *pads,line *rep_dst,line *rep_src);

Perror_t line_pd_copy (P_t *pads,line_pd *pd_dst,line_pd *pd_src);

void line_m_init (P_t *pads,line_m *mask,Pbase_m baseMask);

Perror_t line_m_rec_init (P_t *pads,line_m *mask,Pbase_m baseMask);

Perror_t line_read (P_t *pads,line_m *m,line_pd *pd,line *rep);

int line_verify (P_t *pads,line *rep);

int line_genPD (P_t *pads,line *rep,line_pd *pd);
typedef struct line_acc_s line_acc;
struct line_acc_s {
  Puint32_acc nerr;
  Pint8_acc i8;
  Pint16_acc i16;
  Pint32_acc i32;
  Pint64_acc i64;
  Puint8_acc ui8;
  Puint16_acc ui16;
  Puint32_acc ui32;
  Puint64_acc ui64;
};

Perror_t line_acc_init (P_t *pads,line_acc *acc);

Perror_t line_acc_reset (P_t *pads,line_acc *acc);

Perror_t line_acc_cleanup (P_t *pads,line_acc *acc);

Perror_t line_acc_add (P_t *pads,line_acc *acc,line_pd *pd,line *rep);

Perror_t line_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,line_acc *acc);

Perror_t line_acc_report (P_t *pads,char const *prefix,char const *what,int nst,line_acc *acc);

Perror_t line_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,line_acc *acc);

ssize_t line_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,line_pd *pd,line *rep);

ssize_t line_write2io (P_t *pads,Sfio_t *io,line_pd *pd,line *rep);

ssize_t line_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,line_pd *pd,line *rep,char const *_tag,int indent);

ssize_t line_write_xml_2io (P_t *pads,Sfio_t *io,line_pd *pd,line *rep,char const *_tag,int indent);

ssize_t line_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);

ssize_t line_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);

ssize_t line_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);
typedef struct rec_s rec;
typedef struct rec_m_s rec_m;
typedef struct rec_pd_s rec_pd;
struct rec_m_s {
  Pbase_m compoundLevel;
  line_m l;		/* nested constraints */
};
struct rec_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  line_pd l;
};
struct rec_s {
  line l;
};

Perror_t rec_init (P_t *pads,rec *rep);

Perror_t rec_pd_init (P_t *pads,rec_pd *pd);

Perror_t rec_cleanup (P_t *pads,rec *rep);

Perror_t rec_pd_cleanup (P_t *pads,rec_pd *pd);

Perror_t rec_copy (P_t *pads,rec *rep_dst,rec *rep_src);

Perror_t rec_pd_copy (P_t *pads,rec_pd *pd_dst,rec_pd *pd_src);

void rec_m_init (P_t *pads,rec_m *mask,Pbase_m baseMask);

Perror_t rec_m_rec_init (P_t *pads,rec_m *mask,Pbase_m baseMask);

Perror_t rec_read (P_t *pads,rec_m *m,rec_pd *pd,rec *rep);

int rec_verify (P_t *pads,rec *rep);

int rec_genPD (P_t *pads,rec *rep,rec_pd *pd);
typedef struct rec_acc_s rec_acc;
struct rec_acc_s {
  Puint32_acc nerr;
  line_acc l;
};

Perror_t rec_acc_init (P_t *pads,rec_acc *acc);

Perror_t rec_acc_reset (P_t *pads,rec_acc *acc);

Perror_t rec_acc_cleanup (P_t *pads,rec_acc *acc);

Perror_t rec_acc_add (P_t *pads,rec_acc *acc,rec_pd *pd,rec *rep);

Perror_t rec_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,rec_acc *acc);

Perror_t rec_acc_report (P_t *pads,char const *prefix,char const *what,int nst,rec_acc *acc);

Perror_t rec_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,rec_acc *acc);

ssize_t rec_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,rec_pd *pd,rec *rep);

ssize_t rec_write2io (P_t *pads,Sfio_t *io,rec_pd *pd,rec *rep);

ssize_t rec_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,rec_pd *pd,rec *rep,char const *_tag,int indent);

ssize_t rec_write_xml_2io (P_t *pads,Sfio_t *io,rec_pd *pd,rec *rep,char const *_tag,int indent);

ssize_t rec_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,rec_m *m,rec_pd *pd,rec *rep);

ssize_t rec_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,rec_m *m,rec_pd *pd,rec *rep);

ssize_t rec_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,rec_m *m,rec_pd *pd,rec *rep);

void P_lib_init ();

#endif /*  __READINT__H__  */
