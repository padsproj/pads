#ifndef __FORMAT6__H__
#define __FORMAT6__H__
#include "pads.h"
typedef Puint64 pn_t;
typedef struct pn_t_m_s pn_t_m;
typedef Pbase_pd pn_t_pd;
struct pn_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t pn_t_init (P_t *pads,pn_t *rep);

Perror_t pn_t_pd_init (P_t *pads,pn_t_pd *pd);

Perror_t pn_t_cleanup (P_t *pads,pn_t *rep);

Perror_t pn_t_pd_cleanup (P_t *pads,pn_t_pd *pd);

Perror_t pn_t_copy (P_t *pads,pn_t *rep_dst,pn_t *rep_src);

Perror_t pn_t_pd_copy (P_t *pads,pn_t_pd *pd_dst,pn_t_pd *pd_src);

void pn_t_m_init (P_t *pads,pn_t_m *mask,Pbase_m baseMask);

Perror_t pn_t_m_rec_init (P_t *pads,pn_t_m *mask,Pbase_m baseMask);

Perror_t pn_t_read (P_t *pads,pn_t_m *m,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);

int pn_t_verify (P_t *pads,pn_t *rep,Puint64 lo,Puint64 hi);

int pn_t_genPD (P_t *pads,pn_t *rep,pn_t_pd *pd,Puint64 lo,Puint64 hi);
typedef Puint64_acc pn_t_acc;

Perror_t pn_t_acc_init (P_t *pads,pn_t_acc *acc);

Perror_t pn_t_acc_reset (P_t *pads,pn_t_acc *acc);

Perror_t pn_t_acc_cleanup (P_t *pads,pn_t_acc *acc);

Perror_t pn_t_acc_add (P_t *pads,pn_t_acc *acc,pn_t_pd *pd,pn_t *rep);

Perror_t pn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,pn_t_acc *acc);

Perror_t pn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,pn_t_acc *acc);

Perror_t pn_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,pn_t_acc *acc);

ssize_t pn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);

ssize_t pn_t_write2io (P_t *pads,Sfio_t *io,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);

ssize_t pn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,pn_t_pd *pd,pn_t *rep,char const *_tag,int indent,Puint64 lo,Puint64 hi);

ssize_t pn_t_write_xml_2io (P_t *pads,Sfio_t *io,pn_t_pd *pd,pn_t *rep,char const *_tag,int indent,Puint64 lo,Puint64 hi);

ssize_t pn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);

ssize_t pn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);

ssize_t pn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep,Puint64 lo,Puint64 hi);
typedef struct defPN_s defPN;
typedef struct defPN_m_s defPN_m;
typedef struct defPN_pd_s defPN_pd;
struct defPN_m_s {
  Pbase_m compoundLevel;
  pn_t_m id;		/* nested constraints */
};
struct defPN_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  pn_t_pd id;
};
struct defPN_s {
  pn_t id;
};

Perror_t defPN_init (P_t *pads,defPN *rep);

Perror_t defPN_pd_init (P_t *pads,defPN_pd *pd);

Perror_t defPN_cleanup (P_t *pads,defPN *rep);

Perror_t defPN_pd_cleanup (P_t *pads,defPN_pd *pd);

Perror_t defPN_copy (P_t *pads,defPN *rep_dst,defPN *rep_src);

Perror_t defPN_pd_copy (P_t *pads,defPN_pd *pd_dst,defPN_pd *pd_src);

void defPN_m_init (P_t *pads,defPN_m *mask,Pbase_m baseMask);

Perror_t defPN_m_rec_init (P_t *pads,defPN_m *mask,Pbase_m baseMask);

Perror_t defPN_read (P_t *pads,defPN_m *m,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

int defPN_verify (P_t *pads,defPN *rep,Puint64 lo,Puint64 hi);

int defPN_genPD (P_t *pads,defPN *rep,defPN_pd *pd,Puint64 lo,Puint64 hi);
typedef struct defPN_acc_s defPN_acc;
struct defPN_acc_s {
  Puint32_acc nerr;
  pn_t_acc id;
};

Perror_t defPN_acc_init (P_t *pads,defPN_acc *acc);

Perror_t defPN_acc_reset (P_t *pads,defPN_acc *acc);

Perror_t defPN_acc_cleanup (P_t *pads,defPN_acc *acc);

Perror_t defPN_acc_add (P_t *pads,defPN_acc *acc,defPN_pd *pd,defPN *rep);

Perror_t defPN_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,defPN_acc *acc);

Perror_t defPN_acc_report (P_t *pads,char const *prefix,char const *what,int nst,defPN_acc *acc);

Perror_t defPN_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,defPN_acc *acc);

ssize_t defPN_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

ssize_t defPN_write2io (P_t *pads,Sfio_t *io,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

ssize_t defPN_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,defPN_pd *pd,defPN *rep,char const *_tag,int indent,Puint64 lo,Puint64 hi);

ssize_t defPN_write_xml_2io (P_t *pads,Sfio_t *io,defPN_pd *pd,defPN *rep,char const *_tag,int indent,Puint64 lo,Puint64 hi);

ssize_t defPN_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,defPN_m *m,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

ssize_t defPN_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,defPN_m *m,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

ssize_t defPN_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,defPN_m *m,defPN_pd *pd,defPN *rep,Puint64 lo,Puint64 hi);

void P_lib_init ();

#endif /*  __FORMAT6__H__  */
