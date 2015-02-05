#ifndef __TRY__H__
#define __TRY__H__
#include "pads.h"
typedef Pbase_m foo_m;
typedef Pbase_pd foo_pd;
typedef Pstring foo;

Perror_t foo_init (P_t *pads,foo *rep);

Perror_t foo_pd_init (P_t *pads,foo_pd *pd);

Perror_t foo_cleanup (P_t *pads,foo *rep);

Perror_t foo_pd_cleanup (P_t *pads,foo_pd *pd);

Perror_t foo_copy (P_t *pads,foo *rep_dst,foo *rep_src);

Perror_t foo_pd_copy (P_t *pads,foo_pd *pd_dst,foo_pd *pd_src);

void foo_m_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_m_rec_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_read (P_t *pads,foo_m *m,foo_pd *pd,foo *rep,Pchar stop);

int foo_verify (P_t *pads,foo *rep,Pchar stop);

int foo_genPD (P_t *pads,foo *rep,foo_pd *pd,Pchar stop);
typedef Pstring_acc foo_acc;

Perror_t foo_acc_init (P_t *pads,foo_acc *acc);

Perror_t foo_acc_reset (P_t *pads,foo_acc *acc);

Perror_t foo_acc_cleanup (P_t *pads,foo_acc *acc);

Perror_t foo_acc_add (P_t *pads,foo_acc *acc,foo_pd *pd,foo *rep);

Perror_t foo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_acc *acc);

ssize_t foo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,Pchar stop);

ssize_t foo_write2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,Pchar stop);

ssize_t foo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,char const *_tag,int indent,Pchar stop);

ssize_t foo_write_xml_2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,char const *_tag,int indent,Pchar stop);

ssize_t foo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar stop);

ssize_t foo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar stop);

ssize_t foo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar stop);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  foo_m first;		/* nested constraints */
  Pbase_m second;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  foo_pd first;
  Pbase_pd second;
};
struct entry_t_s {
  foo first;
  Pstring second;
};

Perror_t entry_t_init (P_t *pads,entry_t *rep);

Perror_t entry_t_pd_init (P_t *pads,entry_t_pd *pd);

Perror_t entry_t_cleanup (P_t *pads,entry_t *rep);

Perror_t entry_t_pd_cleanup (P_t *pads,entry_t_pd *pd);

Perror_t entry_t_copy (P_t *pads,entry_t *rep_dst,entry_t *rep_src);

Perror_t entry_t_pd_copy (P_t *pads,entry_t_pd *pd_dst,entry_t_pd *pd_src);

void entry_t_m_init (P_t *pads,entry_t_m *mask,Pbase_m baseMask);

Perror_t entry_t_m_rec_init (P_t *pads,entry_t_m *mask,Pbase_m baseMask);

Perror_t entry_t_read (P_t *pads,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

int entry_t_verify (P_t *pads,entry_t *rep);

int entry_t_genPD (P_t *pads,entry_t *rep,entry_t_pd *pd);
typedef struct entry_t_acc_s entry_t_acc;
struct entry_t_acc_s {
  Puint32_acc nerr;
  foo_acc first;
  Pstring_acc second;
};

Perror_t entry_t_acc_init (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_reset (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_cleanup (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_add (P_t *pads,entry_t_acc *acc,entry_t_pd *pd,entry_t *rep);

Perror_t entry_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entry_t_acc *acc);

Perror_t entry_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entry_t_acc *acc);

Perror_t entry_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,entry_t_acc *acc);

ssize_t entry_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_write2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep,char const *_tag,int indent);

ssize_t entry_t_write_xml_2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep,char const *_tag,int indent);

ssize_t entry_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

void P_lib_init ();

#endif /*  __TRY__H__  */
