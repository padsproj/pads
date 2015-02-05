#ifndef __PFLOAT__H__
#define __PFLOAT__H__
#include "pads.h"

int within_epsilon (Pfloat64 a,Pfloat64 b);
typedef struct test_s test;
typedef struct test_m_s test_m;
typedef struct test_pd_s test_pd;
struct test_m_s {
  Pbase_m compoundLevel;
  Pbase_m x;		/* nested constraints */
  Pbase_m y;		/* nested constraints */
  Pbase_m y_con;		/* struct constraints */
};
struct test_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd x;
  Pbase_pd y;
};
struct test_s {
  Pfloat32 x;
  Pfloat64 y;		/* within_epsilon(x * 25, y)&& */
};

Perror_t test_init (P_t *pads,test *rep);

Perror_t test_pd_init (P_t *pads,test_pd *pd);

Perror_t test_cleanup (P_t *pads,test *rep);

Perror_t test_pd_cleanup (P_t *pads,test_pd *pd);

Perror_t test_copy (P_t *pads,test *rep_dst,test *rep_src);

Perror_t test_pd_copy (P_t *pads,test_pd *pd_dst,test_pd *pd_src);

void test_m_init (P_t *pads,test_m *mask,Pbase_m baseMask);

Perror_t test_m_rec_init (P_t *pads,test_m *mask,Pbase_m baseMask);

Perror_t test_read (P_t *pads,test_m *m,test_pd *pd,test *rep);

int test_verify (P_t *pads,test *rep);

int test_genPD (P_t *pads,test *rep,test_pd *pd);
typedef struct test_acc_s test_acc;
struct test_acc_s {
  Puint32_acc nerr;
  Pfloat32_acc x;
  Pfloat64_acc y;		/* within_epsilon(x * 25, y)&& */
};

Perror_t test_acc_init (P_t *pads,test_acc *acc);

Perror_t test_acc_reset (P_t *pads,test_acc *acc);

Perror_t test_acc_cleanup (P_t *pads,test_acc *acc);

Perror_t test_acc_add (P_t *pads,test_acc *acc,test_pd *pd,test *rep);

Perror_t test_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test_acc *acc);

ssize_t test_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep);

ssize_t test_write2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep);

ssize_t test_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep,char const *_tag,int indent);

ssize_t test_write_xml_2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep,char const *_tag,int indent);

ssize_t test_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);
typedef struct source_s source;
typedef struct source_m_s source_m;
typedef struct source_pd_s source_pd;
typedef struct source_ro_params_t_s source_ro_params_t;
struct source_m_s {
  test_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct source_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  test_pd *elts;
  RBuf_t *_internal;
};
struct source_s {
  Puint32 length;
  test *elts;
  RBuf_t *_internal;
};
struct source_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t source_init (P_t *pads,source *rep);

Perror_t source_pd_init (P_t *pads,source_pd *pd);

Perror_t source_cleanup (P_t *pads,source *rep);

Perror_t source_pd_cleanup (P_t *pads,source_pd *pd);

Perror_t source_copy (P_t *pads,source *rep_dst,source *rep_src);

Perror_t source_pd_copy (P_t *pads,source_pd *pd_dst,source_pd *pd_src);

void source_m_init (P_t *pads,source_m *mask,Pbase_m baseMask);

Perror_t source_m_rec_init (P_t *pads,source_m *mask,Pbase_m baseMask);

void source_ro_params_init (source_ro_params_t *params);

Pread_res_t source_final_checks (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t source_read_one_init (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr);

Pread_res_t source_read_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep);

Perror_t source_read (P_t *pads,source_m *m,source_pd *pd,source *rep);

Pread_res_t source_reread_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep,int notFirstElt);

int source_verify (P_t *pads,source *rep);

int source_genPD (P_t *pads,source *rep,source_pd *pd);
typedef struct source_acc_s source_acc;
struct source_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  test_acc compoundLevel;		/* Accumulator for all array elements */
  test_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t source_acc_init (P_t *pads,source_acc *acc);

Perror_t source_acc_reset (P_t *pads,source_acc *acc);

Perror_t source_acc_cleanup (P_t *pads,source_acc *acc);

Perror_t source_acc_add (P_t *pads,source_acc *acc,source_pd *pd,source *rep);

Perror_t source_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,source_acc *acc);

Perror_t source_acc_report (P_t *pads,char const *prefix,char const *what,int nst,source_acc *acc);

Perror_t source_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,source_acc *acc);

ssize_t source_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,source_pd *pd,source *rep);

ssize_t source_write2io (P_t *pads,Sfio_t *io,source_pd *pd,source *rep);

ssize_t source_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,source_pd *pd,source *rep,char const *_tag,int indent);

ssize_t source_write_xml_2io (P_t *pads,Sfio_t *io,source_pd *pd,source *rep,char const *_tag,int indent);

ssize_t source_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,source_m *m,source_pd *pd,source *rep);

ssize_t source_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,source_m *m,source_pd *pd,source *rep);

ssize_t source_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,source_m *m,source_pd *pd,source *rep);

void P_lib_init ();

#endif /*  __PFLOAT__H__  */
