#ifndef __ALT1__H__
#define __ALT1__H__
#include "pads.h"
typedef struct foo_s foo;
typedef struct foo_m_s foo_m;
typedef struct foo_pd_s foo_pd;
struct foo_m_s {
  Pbase_m compoundLevel;
  Pbase_m s1;		/* nested constraints */
  Pbase_m s2;		/* nested constraints */
  Pbase_m i1;		/* nested constraints */
};
struct foo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd s1;
  Pbase_pd s2;
  Pbase_pd i1;
};
struct foo_s {
  Pstring s1;
  Pstring s2;
  Pint32 i1;
};

Perror_t foo_init (P_t *pads,foo *rep);

Perror_t foo_pd_init (P_t *pads,foo_pd *pd);

Perror_t foo_cleanup (P_t *pads,foo *rep);

Perror_t foo_pd_cleanup (P_t *pads,foo_pd *pd);

Perror_t foo_copy (P_t *pads,foo *rep_dst,foo *rep_src);

Perror_t foo_pd_copy (P_t *pads,foo_pd *pd_dst,foo_pd *pd_src);

void foo_m_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_m_rec_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_read (P_t *pads,foo_m *m,foo_pd *pd,foo *rep);

int foo_verify (P_t *pads,foo *rep);

int foo_genPD (P_t *pads,foo *rep,foo_pd *pd);
typedef struct foo_acc_s foo_acc;
struct foo_acc_s {
  Puint32_acc nerr;
  Pstring_acc s1;
  Pstring_acc s2;
  Pint32_acc i1;
};

Perror_t foo_acc_init (P_t *pads,foo_acc *acc);

Perror_t foo_acc_reset (P_t *pads,foo_acc *acc);

Perror_t foo_acc_cleanup (P_t *pads,foo_acc *acc);

Perror_t foo_acc_add (P_t *pads,foo_acc *acc,foo_pd *pd,foo *rep);

Perror_t foo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_acc *acc);

ssize_t foo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep);

ssize_t foo_write2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep);

ssize_t foo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,char const *_tag,int indent);

ssize_t foo_write_xml_2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,char const *_tag,int indent);

ssize_t foo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep);

ssize_t foo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep);

ssize_t foo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep);

void P_lib_init ();

#endif /*  __ALT1__H__  */
