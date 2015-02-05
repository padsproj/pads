#ifndef __PTIMESTAMP_EXPLICIT__H__
#define __PTIMESTAMP_EXPLICIT__H__
#include "pads.h"
typedef struct threetimestamps_s threetimestamps;
typedef struct threetimestamps_m_s threetimestamps_m;
typedef struct threetimestamps_pd_s threetimestamps_pd;
struct threetimestamps_m_s {
  Pbase_m compoundLevel;
  Pbase_m ts1;		/* nested constraints */
  Pbase_m ts2;		/* nested constraints */
  Pbase_m ts3;		/* nested constraints */
};
struct threetimestamps_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd ts1;
  Pbase_pd ts2;
  Pbase_pd ts3;
};
struct threetimestamps_s {
  Ptimestamp ts1;
  Ptimestamp ts2;
  Ptimestamp ts3;
};

Perror_t threetimestamps_init (P_t *pads,threetimestamps *rep);

Perror_t threetimestamps_pd_init (P_t *pads,threetimestamps_pd *pd);

Perror_t threetimestamps_cleanup (P_t *pads,threetimestamps *rep);

Perror_t threetimestamps_pd_cleanup (P_t *pads,threetimestamps_pd *pd);

Perror_t threetimestamps_copy (P_t *pads,threetimestamps *rep_dst,threetimestamps *rep_src);

Perror_t threetimestamps_pd_copy (P_t *pads,threetimestamps_pd *pd_dst,threetimestamps_pd *pd_src);

void threetimestamps_m_init (P_t *pads,threetimestamps_m *mask,Pbase_m baseMask);

Perror_t threetimestamps_m_rec_init (P_t *pads,threetimestamps_m *mask,Pbase_m baseMask);

Perror_t threetimestamps_read (P_t *pads,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

int threetimestamps_verify (P_t *pads,threetimestamps *rep);

int threetimestamps_genPD (P_t *pads,threetimestamps *rep,threetimestamps_pd *pd);
typedef struct threetimestamps_acc_s threetimestamps_acc;
struct threetimestamps_acc_s {
  Puint32_acc nerr;
  Ptimestamp_acc ts1;
  Ptimestamp_explicit_acc ts2;
  Ptimestamp_explicit_acc ts3;
};

Perror_t threetimestamps_acc_init (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_reset (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_cleanup (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_add (P_t *pads,threetimestamps_acc *acc,threetimestamps_pd *pd,threetimestamps *rep);

Perror_t threetimestamps_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_report (P_t *pads,char const *prefix,char const *what,int nst,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,threetimestamps_acc *acc);

ssize_t threetimestamps_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_write2io (P_t *pads,Sfio_t *io,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimestamps_pd *pd,threetimestamps *rep,char const *_tag,int indent);

ssize_t threetimestamps_write_xml_2io (P_t *pads,Sfio_t *io,threetimestamps_pd *pd,threetimestamps *rep,char const *_tag,int indent);

ssize_t threetimestamps_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

void P_lib_init ();

#endif /*  __PTIMESTAMP_EXPLICIT__H__  */
