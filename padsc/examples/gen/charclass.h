#ifndef __CHARCLASS__H__
#define __CHARCLASS__H__
#include "pads.h"
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  Pbase_m c;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd c;
};
struct entry_s {
  Pchar c;
};

Perror_t entry_init (P_t *pads,entry *rep);

Perror_t entry_pd_init (P_t *pads,entry_pd *pd);

Perror_t entry_cleanup (P_t *pads,entry *rep);

Perror_t entry_pd_cleanup (P_t *pads,entry_pd *pd);

Perror_t entry_copy (P_t *pads,entry *rep_dst,entry *rep_src);

Perror_t entry_pd_copy (P_t *pads,entry_pd *pd_dst,entry_pd *pd_src);

void entry_m_init (P_t *pads,entry_m *mask,Pbase_m baseMask);

Perror_t entry_m_rec_init (P_t *pads,entry_m *mask,Pbase_m baseMask);

Perror_t entry_read (P_t *pads,entry_m *m,entry_pd *pd,entry *rep);

int entry_verify (P_t *pads,entry *rep);

int entry_genPD (P_t *pads,entry *rep,entry_pd *pd);
typedef struct entry_acc_s entry_acc;
struct entry_acc_s {
  Puint32_acc nerr;
  Pchar_acc c;
};

Perror_t entry_acc_init (P_t *pads,entry_acc *acc);

Perror_t entry_acc_reset (P_t *pads,entry_acc *acc);

Perror_t entry_acc_cleanup (P_t *pads,entry_acc *acc);

Perror_t entry_acc_add (P_t *pads,entry_acc *acc,entry_pd *pd,entry *rep);

Perror_t entry_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entry_acc *acc);

Perror_t entry_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entry_acc *acc);

Perror_t entry_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,entry_acc *acc);

ssize_t entry_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_pd *pd,entry *rep);

ssize_t entry_write2io (P_t *pads,Sfio_t *io,entry_pd *pd,entry *rep);

ssize_t entry_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_pd *pd,entry *rep,char const *_tag,int indent);

ssize_t entry_write_xml_2io (P_t *pads,Sfio_t *io,entry_pd *pd,entry *rep,char const *_tag,int indent);

ssize_t entry_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

ssize_t entry_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

ssize_t entry_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

void P_lib_init ();

#endif /*  __CHARCLASS__H__  */
