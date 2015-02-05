#ifndef __STRUCT1__H__
#define __STRUCT1__H__
#include "pads.h"
typedef struct test_s test;
typedef struct test_m_s test_m;
typedef struct test_pd_s test_pd;
struct test_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct test_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd id;
  Pbase_pd ts;
};
struct test_s {
  Puint32 id;		/*  identity. id < 100000&& */
  Puint32 ts;		/*  time stamp. ts == 11 * id&& */
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
  Puint32_acc id;		/*  identity. id < 100000&& */
  Puint32_acc ts;		/*  time stamp. ts == 11 * id&& */
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
typedef struct testtwo_s testtwo;
typedef struct testtwo_m_s testtwo_m;
typedef struct testtwo_pd_s testtwo_pd;
struct testtwo_m_s {
  Pbase_m compoundLevel;
  test_m header;		/* nested constraints */
  Pbase_m f;		/* nested constraints */
  Pbase_m f_con;		/* struct constraints */
};
struct testtwo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  test_pd header;
  Pbase_pd f;
};
struct testtwo_s {
  test header;
  Puint32 f;		/* f == header.ts&& */
};

Perror_t testtwo_init (P_t *pads,testtwo *rep);

Perror_t testtwo_pd_init (P_t *pads,testtwo_pd *pd);

Perror_t testtwo_cleanup (P_t *pads,testtwo *rep);

Perror_t testtwo_pd_cleanup (P_t *pads,testtwo_pd *pd);

Perror_t testtwo_copy (P_t *pads,testtwo *rep_dst,testtwo *rep_src);

Perror_t testtwo_pd_copy (P_t *pads,testtwo_pd *pd_dst,testtwo_pd *pd_src);

void testtwo_m_init (P_t *pads,testtwo_m *mask,Pbase_m baseMask);

Perror_t testtwo_m_rec_init (P_t *pads,testtwo_m *mask,Pbase_m baseMask);

Perror_t testtwo_read (P_t *pads,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

int testtwo_verify (P_t *pads,testtwo *rep);

int testtwo_genPD (P_t *pads,testtwo *rep,testtwo_pd *pd);
typedef struct testtwo_acc_s testtwo_acc;
struct testtwo_acc_s {
  Puint32_acc nerr;
  test_acc header;
  Puint32_acc f;		/* f == header.ts&& */
};

Perror_t testtwo_acc_init (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_reset (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_cleanup (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_add (P_t *pads,testtwo_acc *acc,testtwo_pd *pd,testtwo *rep);

Perror_t testtwo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,testtwo_acc *acc);

Perror_t testtwo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,testtwo_acc *acc);

Perror_t testtwo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,testtwo_acc *acc);

ssize_t testtwo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_write2io (P_t *pads,Sfio_t *io,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,testtwo_pd *pd,testtwo *rep,char const *_tag,int indent);

ssize_t testtwo_write_xml_2io (P_t *pads,Sfio_t *io,testtwo_pd *pd,testtwo *rep,char const *_tag,int indent);

ssize_t testtwo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);
typedef struct source_s source;
typedef struct source_m_s source_m;
typedef struct source_pd_s source_pd;
typedef struct source_ro_params_t_s source_ro_params_t;
struct source_m_s {
  testtwo_m element;		/* per-element */
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
  testtwo_pd *elts;
  RBuf_t *_internal;
};
struct source_s {
  Puint32 length;
  testtwo *elts;
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

Pread_res_t source_read_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,testtwo_pd *elt_pd,testtwo *elt_rep);

Perror_t source_read (P_t *pads,source_m *m,source_pd *pd,source *rep);

Pread_res_t source_reread_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,testtwo_pd *elt_pd,testtwo *elt_rep,int notFirstElt);

int source_verify (P_t *pads,source *rep);

int source_genPD (P_t *pads,source *rep,source_pd *pd);
typedef struct source_acc_s source_acc;
struct source_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  testtwo_acc compoundLevel;		/* Accumulator for all array elements */
  testtwo_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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

#endif /*  __STRUCT1__H__  */
