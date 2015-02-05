#ifndef __IN_PLACE__H__
#define __IN_PLACE__H__
#include "pads.h"
typedef struct ip_t_s ip_t;
typedef struct ip_t_m_s ip_t_m;
typedef struct ip_t_pd_s ip_t_pd;
typedef struct ip_t_ro_params_t_s ip_t_ro_params_t;
struct ip_t_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct ip_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  Pbase_pd *elts;
  RBuf_t *_internal;
};
struct ip_t_s {
  Puint32 length;
  Puint8 *elts;
  RBuf_t *_internal;
};
struct ip_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Puint32 l;
  Puint8 *c;
  int *f;
};

Perror_t ip_t_init (P_t *pads,ip_t *rep);

Perror_t ip_t_pd_init (P_t *pads,ip_t_pd *pd);

Perror_t ip_t_cleanup (P_t *pads,ip_t *rep);

Perror_t ip_t_pd_cleanup (P_t *pads,ip_t_pd *pd);

Perror_t ip_t_copy (P_t *pads,ip_t *rep_dst,ip_t *rep_src);

Perror_t ip_t_pd_copy (P_t *pads,ip_t_pd *pd_dst,ip_t_pd *pd_src);

void ip_t_m_init (P_t *pads,ip_t_m *mask,Pbase_m baseMask);

Perror_t ip_t_m_rec_init (P_t *pads,ip_t_m *mask,Pbase_m baseMask);

void ip_t_ro_params_init (ip_t_ro_params_t *params,Puint32 l,Puint8 *c,int *f);

Pread_res_t ip_t_final_checks (P_t *pads,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Ploc_t *loc_ptr,int reachedLimit,int consume,Puint32 l,Puint8 *c,int *f);

Pread_res_t ip_t_read_one_init (P_t *pads,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Ploc_t *loc_ptr,Puint32 l,Puint8 *c,int *f);

Pread_res_t ip_t_read_one (P_t *pads,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep,Puint32 l,Puint8 *c,int *f);

Perror_t ip_t_read (P_t *pads,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);

Pread_res_t ip_t_reread_one (P_t *pads,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep,int notFirstElt,Puint32 l,Puint8 *c,int *f);

int ip_t_verify (P_t *pads,ip_t *rep,Puint32 l,Puint8 *c,int *f);

int ip_t_genPD (P_t *pads,ip_t *rep,ip_t_pd *pd,Puint32 l,Puint8 *c,int *f);
typedef struct ip_t_acc_s ip_t_acc;
struct ip_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Puint8_acc compoundLevel;		/* Accumulator for all array elements */
  Puint8_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t ip_t_acc_init (P_t *pads,ip_t_acc *acc);

Perror_t ip_t_acc_reset (P_t *pads,ip_t_acc *acc);

Perror_t ip_t_acc_cleanup (P_t *pads,ip_t_acc *acc);

Perror_t ip_t_acc_add (P_t *pads,ip_t_acc *acc,ip_t_pd *pd,ip_t *rep);

Perror_t ip_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,ip_t_acc *acc);

Perror_t ip_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,ip_t_acc *acc);

Perror_t ip_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,ip_t_acc *acc);

ssize_t ip_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_write2io (P_t *pads,Sfio_t *io,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,ip_t_pd *pd,ip_t *rep,char const *_tag,int indent,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_write_xml_2io (P_t *pads,Sfio_t *io,ip_t_pd *pd,ip_t *rep,char const *_tag,int indent,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);

ssize_t ip_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,ip_t_m *m,ip_t_pd *pd,ip_t *rep,Puint32 l,Puint8 *c,int *f);
typedef struct foo_s foo;
typedef struct foo_m_s foo_m;
typedef struct foo_pd_s foo_pd;
struct foo_m_s {
  Pbase_m compoundLevel;
  Pbase_m c;		/* nested constraints */
  ip_t_m ip;		/* nested constraints */
  Pbase_m d;		/* nested constraints */
};
struct foo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd c;
  Pbase_pd f;		/* f = l + 1 */
  ip_t_pd ip;
  Pbase_pd d;
};
struct foo_s {
  Puint8 c;
  int f;		/* f = l + 1 */
  ip_t ip;		/*  resolved ip address */
  Pchar d;
};

Perror_t foo_init (P_t *pads,foo *rep);

Perror_t foo_pd_init (P_t *pads,foo_pd *pd);

Perror_t foo_cleanup (P_t *pads,foo *rep);

Perror_t foo_pd_cleanup (P_t *pads,foo_pd *pd);

Perror_t foo_copy (P_t *pads,foo *rep_dst,foo *rep_src);

Perror_t foo_pd_copy (P_t *pads,foo_pd *pd_dst,foo_pd *pd_src);

void foo_m_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_m_rec_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_read (P_t *pads,foo_m *m,foo_pd *pd,foo *rep,Puint32 l);

int foo_verify (P_t *pads,foo *rep,Puint32 l);

int foo_genPD (P_t *pads,foo *rep,foo_pd *pd,Puint32 l);
typedef struct foo_acc_s foo_acc;
struct foo_acc_s {
  Puint32_acc nerr;
  Puint8_acc c;
  ip_t_acc ip;		/*  resolved ip address */
  Pchar_acc d;
};

Perror_t foo_acc_init (P_t *pads,foo_acc *acc);

Perror_t foo_acc_reset (P_t *pads,foo_acc *acc);

Perror_t foo_acc_cleanup (P_t *pads,foo_acc *acc);

Perror_t foo_acc_add (P_t *pads,foo_acc *acc,foo_pd *pd,foo *rep);

Perror_t foo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_acc *acc);

ssize_t foo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,Puint32 l);

ssize_t foo_write2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,Puint32 l);

ssize_t foo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,char const *_tag,int indent,Puint32 l);

ssize_t foo_write_xml_2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,char const *_tag,int indent,Puint32 l);

ssize_t foo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Puint32 l);

ssize_t foo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Puint32 l);

ssize_t foo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Puint32 l);
typedef struct bar_s bar;
typedef struct bar_m_s bar_m;
typedef struct bar_pd_s bar_pd;
struct bar_m_s {
  Pbase_m compoundLevel;
  Pbase_m x;		/* nested constraints */
  foo_m b;		/* nested constraints */
};
struct bar_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd x;
  foo_pd b;
};
struct bar_s {
  Puint32 x;
  foo b;
};

Perror_t bar_init (P_t *pads,bar *rep);

Perror_t bar_pd_init (P_t *pads,bar_pd *pd);

Perror_t bar_cleanup (P_t *pads,bar *rep);

Perror_t bar_pd_cleanup (P_t *pads,bar_pd *pd);

Perror_t bar_copy (P_t *pads,bar *rep_dst,bar *rep_src);

Perror_t bar_pd_copy (P_t *pads,bar_pd *pd_dst,bar_pd *pd_src);

void bar_m_init (P_t *pads,bar_m *mask,Pbase_m baseMask);

Perror_t bar_m_rec_init (P_t *pads,bar_m *mask,Pbase_m baseMask);

Perror_t bar_read (P_t *pads,bar_m *m,bar_pd *pd,bar *rep);

int bar_verify (P_t *pads,bar *rep);

int bar_genPD (P_t *pads,bar *rep,bar_pd *pd);
typedef struct bar_acc_s bar_acc;
struct bar_acc_s {
  Puint32_acc nerr;
  Puint32_acc x;
  foo_acc b;
};

Perror_t bar_acc_init (P_t *pads,bar_acc *acc);

Perror_t bar_acc_reset (P_t *pads,bar_acc *acc);

Perror_t bar_acc_cleanup (P_t *pads,bar_acc *acc);

Perror_t bar_acc_add (P_t *pads,bar_acc *acc,bar_pd *pd,bar *rep);

Perror_t bar_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,bar_acc *acc);

Perror_t bar_acc_report (P_t *pads,char const *prefix,char const *what,int nst,bar_acc *acc);

Perror_t bar_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,bar_acc *acc);

ssize_t bar_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,bar_pd *pd,bar *rep);

ssize_t bar_write2io (P_t *pads,Sfio_t *io,bar_pd *pd,bar *rep);

ssize_t bar_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,bar_pd *pd,bar *rep,char const *_tag,int indent);

ssize_t bar_write_xml_2io (P_t *pads,Sfio_t *io,bar_pd *pd,bar *rep,char const *_tag,int indent);

ssize_t bar_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);

ssize_t bar_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);

ssize_t bar_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);

void P_lib_init ();

#endif /*  __IN_PLACE__H__  */
