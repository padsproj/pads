#ifndef __ME__H__
#define __ME__H__
#include "pads.h"
typedef struct T1_s T1;
typedef struct T1_m_s T1_m;
typedef struct T1_pd_s T1_pd;
struct T1_m_s {
  Pbase_m compoundLevel;
  Pbase_m id1;		/* nested constraints */
  Pbase_m id2;		/* nested constraints */
  Pbase_m id3;		/* nested constraints */
  Pbase_m id_omit;		/* nested constraints */
};
struct T1_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd id1;
  Pbase_pd id2;
  Pbase_pd id3;
  Pbase_pd id_omit;
};
struct T1_s {
  Pstring id1;
  Pstring id2;
  Pstring id3;
};

Perror_t T1_init (P_t *pads,T1 *rep);

Perror_t T1_pd_init (P_t *pads,T1_pd *pd);

Perror_t T1_cleanup (P_t *pads,T1 *rep);

Perror_t T1_pd_cleanup (P_t *pads,T1_pd *pd);

Perror_t T1_copy (P_t *pads,T1 *rep_dst,T1 *rep_src);

Perror_t T1_pd_copy (P_t *pads,T1_pd *pd_dst,T1_pd *pd_src);

void T1_m_init (P_t *pads,T1_m *mask,Pbase_m baseMask);

Perror_t T1_m_rec_init (P_t *pads,T1_m *mask,Pbase_m baseMask);

Perror_t T1_read (P_t *pads,T1_m *m,T1_pd *pd,T1 *rep);

int T1_verify (P_t *pads,T1 *rep);

int T1_genPD (P_t *pads,T1 *rep,T1_pd *pd);
typedef struct T1_acc_s T1_acc;
struct T1_acc_s {
  Puint32_acc nerr;
  Pstring_acc id1;
  Pstring_acc id2;
  Pstring_acc id3;
};

Perror_t T1_acc_init (P_t *pads,T1_acc *acc);

Perror_t T1_acc_reset (P_t *pads,T1_acc *acc);

Perror_t T1_acc_cleanup (P_t *pads,T1_acc *acc);

Perror_t T1_acc_add (P_t *pads,T1_acc *acc,T1_pd *pd,T1 *rep);

Perror_t T1_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,T1_acc *acc);

Perror_t T1_acc_report (P_t *pads,char const *prefix,char const *what,int nst,T1_acc *acc);

Perror_t T1_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,T1_acc *acc);

ssize_t T1_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,T1_pd *pd,T1 *rep);

ssize_t T1_write2io (P_t *pads,Sfio_t *io,T1_pd *pd,T1 *rep);

ssize_t T1_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,T1_pd *pd,T1 *rep,char const *_tag,int indent);

ssize_t T1_write_xml_2io (P_t *pads,Sfio_t *io,T1_pd *pd,T1 *rep,char const *_tag,int indent);

ssize_t T1_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,T1_m *m,T1_pd *pd,T1 *rep);

ssize_t T1_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,T1_m *m,T1_pd *pd,T1 *rep);

ssize_t T1_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,T1_m *m,T1_pd *pd,T1 *rep);

void P_lib_init ();

#endif /*  __ME__H__  */
