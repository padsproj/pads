#ifndef __PADS_COMP__H__
#define __PADS_COMP__H__
#include "pads.h"
typedef struct header_s header;
typedef struct header_m_s header_m;
typedef struct header_pd_s header_pd;
struct header_m_s {
  Pbase_m compoundLevel;
  Pbase_m foo;		/* nested constraints */
  Pbase_m bar;		/* nested constraints */
  Pbase_m x;		/* nested constraints */
};
struct header_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd foo;
  Pbase_pd bar;		/* bar = foo */
  Pbase_pd x;
};
struct header_s {
  Pstring foo;
  Pstring bar;		/* bar = foo */
  Puint32 x;
};

Perror_t header_init (P_t *pads,header *rep);

Perror_t header_pd_init (P_t *pads,header_pd *pd);

Perror_t header_cleanup (P_t *pads,header *rep);

Perror_t header_pd_cleanup (P_t *pads,header_pd *pd);

Perror_t header_copy (P_t *pads,header *rep_dst,header *rep_src);

Perror_t header_pd_copy (P_t *pads,header_pd *pd_dst,header_pd *pd_src);

void header_m_init (P_t *pads,header_m *mask,Pbase_m baseMask);

Perror_t header_m_rec_init (P_t *pads,header_m *mask,Pbase_m baseMask);

Perror_t header_read (P_t *pads,header_m *m,header_pd *pd,header *rep);

int header_verify (P_t *pads,header *rep);

int header_genPD (P_t *pads,header *rep,header_pd *pd);
typedef struct header_acc_s header_acc;
struct header_acc_s {
  Puint32_acc nerr;
  Pstring_acc foo;
  Pstring_acc bar;		/* bar = foo */
  Puint32_acc x;
};

Perror_t header_acc_init (P_t *pads,header_acc *acc);

Perror_t header_acc_reset (P_t *pads,header_acc *acc);

Perror_t header_acc_cleanup (P_t *pads,header_acc *acc);

Perror_t header_acc_add (P_t *pads,header_acc *acc,header_pd *pd,header *rep);

Perror_t header_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,header_acc *acc);

Perror_t header_acc_report (P_t *pads,char const *prefix,char const *what,int nst,header_acc *acc);

Perror_t header_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,header_acc *acc);

ssize_t header_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,header_pd *pd,header *rep);

ssize_t header_write2io (P_t *pads,Sfio_t *io,header_pd *pd,header *rep);

ssize_t header_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,header_pd *pd,header *rep,char const *_tag,int indent);

ssize_t header_write_xml_2io (P_t *pads,Sfio_t *io,header_pd *pd,header *rep,char const *_tag,int indent);

ssize_t header_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,header_m *m,header_pd *pd,header *rep);

ssize_t header_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,header_m *m,header_pd *pd,header *rep);

ssize_t header_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,header_m *m,header_pd *pd,header *rep);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  header_m h;		/* nested constraints */
  header_m b;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  header_pd h;
  header_pd b;		/* b = h */
};
struct entry_s {
  header h;
  header b;		/* b = h */
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
  header_acc h;
  header_acc b;		/* b = h */
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

#endif /*  __PADS_COMP__H__  */
