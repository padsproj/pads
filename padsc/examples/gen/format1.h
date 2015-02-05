#ifndef __FORMAT1__H__
#define __FORMAT1__H__
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
  Pint32 id;		/*  identity. id < 100000&& */
  Pint32 ts;		/*  time stamp. ts == 11 * id&& */
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
  Pint32_acc id;		/*  identity. id < 100000&& */
  Pint32_acc ts;		/*  time stamp. ts == 11 * id&& */
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
typedef struct test_not_rec_s test_not_rec;
typedef struct test_not_rec_m_s test_not_rec_m;
typedef struct test_not_rec_pd_s test_not_rec_pd;
struct test_not_rec_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct test_not_rec_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd id;
  Pbase_pd ts;
};
struct test_not_rec_s {
  Pint32 id;		/*  identity. id < 100000&& */
  Pint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_not_rec_init (P_t *pads,test_not_rec *rep);

Perror_t test_not_rec_pd_init (P_t *pads,test_not_rec_pd *pd);

Perror_t test_not_rec_cleanup (P_t *pads,test_not_rec *rep);

Perror_t test_not_rec_pd_cleanup (P_t *pads,test_not_rec_pd *pd);

Perror_t test_not_rec_copy (P_t *pads,test_not_rec *rep_dst,test_not_rec *rep_src);

Perror_t test_not_rec_pd_copy (P_t *pads,test_not_rec_pd *pd_dst,test_not_rec_pd *pd_src);

void test_not_rec_m_init (P_t *pads,test_not_rec_m *mask,Pbase_m baseMask);

Perror_t test_not_rec_m_rec_init (P_t *pads,test_not_rec_m *mask,Pbase_m baseMask);

Perror_t test_not_rec_read (P_t *pads,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

int test_not_rec_verify (P_t *pads,test_not_rec *rep);

int test_not_rec_genPD (P_t *pads,test_not_rec *rep,test_not_rec_pd *pd);
typedef struct test_not_rec_acc_s test_not_rec_acc;
struct test_not_rec_acc_s {
  Puint32_acc nerr;
  Pint32_acc id;		/*  identity. id < 100000&& */
  Pint32_acc ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_not_rec_acc_init (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_reset (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_cleanup (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_add (P_t *pads,test_not_rec_acc *acc,test_not_rec_pd *pd,test_not_rec *rep);

Perror_t test_not_rec_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test_not_rec_acc *acc);

ssize_t test_not_rec_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_write2io (P_t *pads,Sfio_t *io,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_not_rec_pd *pd,test_not_rec *rep,char const *_tag,int indent);

ssize_t test_not_rec_write_xml_2io (P_t *pads,Sfio_t *io,test_not_rec_pd *pd,test_not_rec *rep,char const *_tag,int indent);

ssize_t test_not_rec_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);
typedef struct test2_s test2;
typedef struct test2_m_s test2_m;
typedef struct test2_pd_s test2_pd;
struct test2_m_s {
  Pbase_m compoundLevel;
  test_not_rec_m bigger;		/* nested constraints */
  Pbase_m two;		/* nested constraints */
};
struct test2_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  test_not_rec_pd bigger;
  Pbase_pd two;
};
struct test2_s {
  test_not_rec bigger;
  Pint32 two;
};

Perror_t test2_init (P_t *pads,test2 *rep);

Perror_t test2_pd_init (P_t *pads,test2_pd *pd);

Perror_t test2_cleanup (P_t *pads,test2 *rep);

Perror_t test2_pd_cleanup (P_t *pads,test2_pd *pd);

Perror_t test2_copy (P_t *pads,test2 *rep_dst,test2 *rep_src);

Perror_t test2_pd_copy (P_t *pads,test2_pd *pd_dst,test2_pd *pd_src);

void test2_m_init (P_t *pads,test2_m *mask,Pbase_m baseMask);

Perror_t test2_m_rec_init (P_t *pads,test2_m *mask,Pbase_m baseMask);

Perror_t test2_read (P_t *pads,test2_m *m,test2_pd *pd,test2 *rep);

int test2_verify (P_t *pads,test2 *rep);

int test2_genPD (P_t *pads,test2 *rep,test2_pd *pd);
typedef struct test2_acc_s test2_acc;
struct test2_acc_s {
  Puint32_acc nerr;
  test_not_rec_acc bigger;
  Pint32_acc two;
};

Perror_t test2_acc_init (P_t *pads,test2_acc *acc);

Perror_t test2_acc_reset (P_t *pads,test2_acc *acc);

Perror_t test2_acc_cleanup (P_t *pads,test2_acc *acc);

Perror_t test2_acc_add (P_t *pads,test2_acc *acc,test2_pd *pd,test2 *rep);

Perror_t test2_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test2_acc *acc);

Perror_t test2_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test2_acc *acc);

Perror_t test2_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test2_acc *acc);

ssize_t test2_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test2_pd *pd,test2 *rep);

ssize_t test2_write2io (P_t *pads,Sfio_t *io,test2_pd *pd,test2 *rep);

ssize_t test2_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test2_pd *pd,test2 *rep,char const *_tag,int indent);

ssize_t test2_write_xml_2io (P_t *pads,Sfio_t *io,test2_pd *pd,test2 *rep,char const *_tag,int indent);

ssize_t test2_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

ssize_t test2_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

ssize_t test2_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

void P_lib_init ();

#endif /*  __FORMAT1__H__  */
