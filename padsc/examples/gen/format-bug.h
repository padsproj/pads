#ifndef __FORMAT_BUG__H__
#define __FORMAT_BUG__H__
#include "pads.h"
typedef enum choices_t_e choices_t;
typedef Pbase_m choices_t_m;
typedef Pbase_pd choices_t_pd;
enum choices_t_e {
  started139=0,
  reply139=1
  };

char const *choices_t2str (choices_t which);

Perror_t choices_t_init (P_t *pads,choices_t *rep);

Perror_t choices_t_pd_init (P_t *pads,choices_t_pd *pd);

Perror_t choices_t_cleanup (P_t *pads,choices_t *rep);

Perror_t choices_t_pd_cleanup (P_t *pads,choices_t_pd *pd);

Perror_t choices_t_copy (P_t *pads,choices_t *rep_dst,choices_t *rep_src);

Perror_t choices_t_pd_copy (P_t *pads,choices_t_pd *pd_dst,choices_t_pd *pd_src);

void choices_t_m_init (P_t *pads,choices_t_m *mask,Pbase_m baseMask);

Perror_t choices_t_m_rec_init (P_t *pads,choices_t_m *mask,Pbase_m baseMask);

Perror_t choices_t_read (P_t *pads,choices_t_m *m,choices_t_pd *pd,choices_t *rep);

int choices_t_verify (P_t *pads,choices_t *rep);

int choices_t_genPD (P_t *pads,choices_t *rep,choices_t_pd *pd);
typedef Pint32_acc choices_t_acc;

Perror_t choices_t_acc_init (P_t *pads,choices_t_acc *acc);

Perror_t choices_t_acc_reset (P_t *pads,choices_t_acc *acc);

Perror_t choices_t_acc_cleanup (P_t *pads,choices_t_acc *acc);

Perror_t choices_t_acc_add (P_t *pads,choices_t_acc *acc,choices_t_pd *pd,choices_t *rep);

Perror_t choices_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,choices_t_acc *acc);

Perror_t choices_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,choices_t_acc *acc);

Perror_t choices_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,choices_t_acc *acc);

ssize_t choices_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choices_t_pd *pd,choices_t *rep);

ssize_t choices_t_write2io (P_t *pads,Sfio_t *io,choices_t_pd *pd,choices_t *rep);

ssize_t choices_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choices_t_pd *pd,choices_t *rep,char const *_tag,int indent);

ssize_t choices_t_write_xml_2io (P_t *pads,Sfio_t *io,choices_t_pd *pd,choices_t *rep,char const *_tag,int indent);

ssize_t choices_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choices_t_m *m,choices_t_pd *pd,choices_t *rep);

ssize_t choices_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choices_t_m *m,choices_t_pd *pd,choices_t *rep);

ssize_t choices_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,choices_t_m *m,choices_t_pd *pd,choices_t *rep);
typedef enum i_t_tag_e i_t_tag;
typedef union i_t_u_u i_t_u;
typedef struct i_t_s i_t;
typedef struct i_t_m_s i_t_m;
typedef union i_t_pd_u_u i_t_pd_u;
typedef struct i_t_pd_s i_t_pd;
enum i_t_tag_e {
  i_t_err=0,
  some_i_t=1,
  none_i_t=2
  };
union i_t_pd_u_u {
  Pbase_pd some_i_t;
  Pbase_pd none_i_t;		/* value was not present. none_i_t = 0 */
};
struct i_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  i_t_tag tag;
  i_t_pd_u val;
};
union i_t_u_u {
  Puint32 some_i_t;		/* value is present */
};
struct i_t_s {
  i_t_tag tag;
  i_t_u val;
};
struct i_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_i_t;		/* nested constraints */
  Pbase_m none_i_t;		/* nested constraints */
};

ssize_t i_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,i_t_pd *pd,i_t *rep,choices_t *foo);

ssize_t i_t_write2io (P_t *pads,Sfio_t *io,i_t_pd *pd,i_t *rep,choices_t *foo);

ssize_t i_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,i_t_pd *pd,i_t *rep,char const *_tag,int indent,choices_t *foo);

ssize_t i_t_write_xml_2io (P_t *pads,Sfio_t *io,i_t_pd *pd,i_t *rep,char const *_tag,int indent,choices_t *foo);

char const *i_t_tag2str (i_t_tag which);

Perror_t i_t_init (P_t *pads,i_t *rep);

Perror_t i_t_pd_init (P_t *pads,i_t_pd *pd);

Perror_t i_t_cleanup (P_t *pads,i_t *rep);

Perror_t i_t_pd_cleanup (P_t *pads,i_t_pd *pd);

Perror_t i_t_copy (P_t *pads,i_t *rep_dst,i_t *rep_src);

Perror_t i_t_pd_copy (P_t *pads,i_t_pd *pd_dst,i_t_pd *pd_src);

void i_t_m_init (P_t *pads,i_t_m *mask,Pbase_m baseMask);

Perror_t i_t_m_rec_init (P_t *pads,i_t_m *mask,Pbase_m baseMask);

Perror_t i_t_read (P_t *pads,i_t_m *m,i_t_pd *pd,i_t *rep,choices_t *foo);

int i_t_verify (P_t *pads,i_t *rep,choices_t *foo);

int i_t_genPD (P_t *pads,i_t *rep,i_t_pd *pd,choices_t *foo);
typedef struct i_t_acc_s i_t_acc;
struct i_t_acc_s {
  Pint32_acc tag;
  Puint32_acc some_i_t;
};

Perror_t i_t_acc_init (P_t *pads,i_t_acc *acc);

Perror_t i_t_acc_reset (P_t *pads,i_t_acc *acc);

Perror_t i_t_acc_cleanup (P_t *pads,i_t_acc *acc);

Perror_t i_t_acc_add (P_t *pads,i_t_acc *acc,i_t_pd *pd,i_t *rep);

Perror_t i_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,i_t_acc *acc);

Perror_t i_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,i_t_acc *acc);

Perror_t i_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,i_t_acc *acc);

ssize_t i_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,i_t_m *m,i_t_pd *pd,i_t *rep,choices_t *foo);

ssize_t i_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,i_t_m *m,i_t_pd *pd,i_t *rep,choices_t *foo);

ssize_t i_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,i_t_m *m,i_t_pd *pd,i_t *rep,choices_t *foo);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  choices_t_m foo;		/* nested constraints */
  i_t_m i;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  choices_t_pd foo;
  i_t_pd i;
};
struct entry_t_s {
  choices_t foo;
  i_t i;
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
  choices_t_acc foo;
  i_t_acc i;
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

#endif /*  __FORMAT_BUG__H__  */
