#ifndef __PTIME__H__
#define __PTIME__H__
#include "pads.h"
typedef struct threetimes_s threetimes;
typedef struct threetimes_m_s threetimes_m;
typedef struct threetimes_pd_s threetimes_pd;
struct threetimes_m_s {
  Pbase_m compoundLevel;
  Pbase_m time1;		/* nested constraints */
  Pbase_m time2;		/* nested constraints */
  Pbase_m time3;		/* nested constraints */
};
struct threetimes_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd time1;
  Pbase_pd time2;
  Pbase_pd time3;
};
struct threetimes_s {
  Ptime time1;
  Ptime time2;
  Ptime time3;
};

Perror_t threetimes_init (P_t *pads,threetimes *rep);

Perror_t threetimes_pd_init (P_t *pads,threetimes_pd *pd);

Perror_t threetimes_cleanup (P_t *pads,threetimes *rep);

Perror_t threetimes_pd_cleanup (P_t *pads,threetimes_pd *pd);

Perror_t threetimes_copy (P_t *pads,threetimes *rep_dst,threetimes *rep_src);

Perror_t threetimes_pd_copy (P_t *pads,threetimes_pd *pd_dst,threetimes_pd *pd_src);

void threetimes_m_init (P_t *pads,threetimes_m *mask,Pbase_m baseMask);

Perror_t threetimes_m_rec_init (P_t *pads,threetimes_m *mask,Pbase_m baseMask);

Perror_t threetimes_read (P_t *pads,threetimes_m *m,threetimes_pd *pd,threetimes *rep);

int threetimes_verify (P_t *pads,threetimes *rep);

int threetimes_genPD (P_t *pads,threetimes *rep,threetimes_pd *pd);
typedef struct threetimes_acc_s threetimes_acc;
struct threetimes_acc_s {
  Puint32_acc nerr;
  Ptime_acc time1;
  Ptime_acc time2;
  Ptime_acc time3;
};

Perror_t threetimes_acc_init (P_t *pads,threetimes_acc *acc);

Perror_t threetimes_acc_reset (P_t *pads,threetimes_acc *acc);

Perror_t threetimes_acc_cleanup (P_t *pads,threetimes_acc *acc);

Perror_t threetimes_acc_add (P_t *pads,threetimes_acc *acc,threetimes_pd *pd,threetimes *rep);

Perror_t threetimes_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,threetimes_acc *acc);

Perror_t threetimes_acc_report (P_t *pads,char const *prefix,char const *what,int nst,threetimes_acc *acc);

Perror_t threetimes_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,threetimes_acc *acc);

ssize_t threetimes_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimes_pd *pd,threetimes *rep);

ssize_t threetimes_write2io (P_t *pads,Sfio_t *io,threetimes_pd *pd,threetimes *rep);

ssize_t threetimes_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimes_pd *pd,threetimes *rep,char const *_tag,int indent);

ssize_t threetimes_write_xml_2io (P_t *pads,Sfio_t *io,threetimes_pd *pd,threetimes *rep,char const *_tag,int indent);

ssize_t threetimes_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimes_m *m,threetimes_pd *pd,threetimes *rep);

ssize_t threetimes_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimes_m *m,threetimes_pd *pd,threetimes *rep);

ssize_t threetimes_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,threetimes_m *m,threetimes_pd *pd,threetimes *rep);

void P_lib_init ();

#endif /*  __PTIME__H__  */
