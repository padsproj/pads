#ifndef __PUNION_LITERAL2__H__
#define __PUNION_LITERAL2__H__
#include "pads.h"
typedef enum test_tag_e test_tag;
typedef union test_u_u test_u;
typedef struct test_s test;
typedef struct test_m_s test_m;
typedef union test_pd_u_u test_pd_u;
typedef struct test_pd_s test_pd;
enum test_tag_e {
  test_err=0,
  baz=1,
  c=2,
  star=3,
  as=4,
  f=5
  };
union test_pd_u_u {
  Pbase_pd baz;
  Pbase_pd c;
  Pbase_pd star;
  Pbase_pd as;
  Pbase_pd f;
};
struct test_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  test_tag tag;
  test_pd_u val;
};
union test_u_u {
  Pint32 f;
};
struct test_s {
  test_tag tag;
  test_u val;
};
struct test_m_s {
  Pbase_m compoundLevel;
  Pbase_m f;		/* nested constraints */
};

ssize_t test_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep);

ssize_t test_write2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep);

ssize_t test_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep,char const *_tag,int indent);

ssize_t test_write_xml_2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep,char const *_tag,int indent);

char const *test_tag2str (test_tag which);

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
  Pint32_acc tag;
  Pint32_acc f;
};

Perror_t test_acc_init (P_t *pads,test_acc *acc);

Perror_t test_acc_reset (P_t *pads,test_acc *acc);

Perror_t test_acc_cleanup (P_t *pads,test_acc *acc);

Perror_t test_acc_add (P_t *pads,test_acc *acc,test_pd *pd,test *rep);

Perror_t test_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test_acc *acc);

ssize_t test_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

void P_lib_init ();

#endif /*  __PUNION_LITERAL2__H__  */
