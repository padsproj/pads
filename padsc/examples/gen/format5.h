#ifndef __FORMAT5__H__
#define __FORMAT5__H__
#include "pads.h"
typedef enum dibblerPN_tag_e dibblerPN_tag;
typedef union dibblerPN_u_u dibblerPN_u;
typedef struct dibblerPN_s dibblerPN;
typedef struct dibblerPN_m_s dibblerPN_m;
typedef union dibblerPN_pd_u_u dibblerPN_pd_u;
typedef struct dibblerPN_pd_s dibblerPN_pd;
enum dibblerPN_tag_e {
  dibblerPN_err=0,
  code=1,
  pn=2
  };
union dibblerPN_pd_u_u {
  Pbase_pd code;
  Pbase_pd pn;
};
struct dibblerPN_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  dibblerPN_tag tag;
  dibblerPN_pd_u val;
};
union dibblerPN_u_u {
  Puint32 code;		/* (code % x) == 0&& */
  Puint32 pn;		/*  phone number */
};
struct dibblerPN_s {
  dibblerPN_tag tag;
  dibblerPN_u val;
};
struct dibblerPN_m_s {
  Pbase_m compoundLevel;
  Pbase_m code;		/* nested constraints */
  Pbase_m code_con;		/* union constraints */
  Pbase_m pn;		/* nested constraints */
};

ssize_t dibblerPN_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,dibblerPN_pd *pd,dibblerPN *rep,int x);

ssize_t dibblerPN_write2io (P_t *pads,Sfio_t *io,dibblerPN_pd *pd,dibblerPN *rep,int x);

ssize_t dibblerPN_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,dibblerPN_pd *pd,dibblerPN *rep,char const *_tag,int indent,int x);

ssize_t dibblerPN_write_xml_2io (P_t *pads,Sfio_t *io,dibblerPN_pd *pd,dibblerPN *rep,char const *_tag,int indent,int x);

char const *dibblerPN_tag2str (dibblerPN_tag which);

Perror_t dibblerPN_init (P_t *pads,dibblerPN *rep);

Perror_t dibblerPN_pd_init (P_t *pads,dibblerPN_pd *pd);

Perror_t dibblerPN_cleanup (P_t *pads,dibblerPN *rep);

Perror_t dibblerPN_pd_cleanup (P_t *pads,dibblerPN_pd *pd);

Perror_t dibblerPN_copy (P_t *pads,dibblerPN *rep_dst,dibblerPN *rep_src);

Perror_t dibblerPN_pd_copy (P_t *pads,dibblerPN_pd *pd_dst,dibblerPN_pd *pd_src);

void dibblerPN_m_init (P_t *pads,dibblerPN_m *mask,Pbase_m baseMask);

Perror_t dibblerPN_m_rec_init (P_t *pads,dibblerPN_m *mask,Pbase_m baseMask);

Perror_t dibblerPN_read (P_t *pads,dibblerPN_m *m,dibblerPN_pd *pd,dibblerPN *rep,int x);

int dibblerPN_verify (P_t *pads,dibblerPN *rep,int x);

int dibblerPN_genPD (P_t *pads,dibblerPN *rep,dibblerPN_pd *pd,int x);
typedef struct dibblerPN_acc_s dibblerPN_acc;
struct dibblerPN_acc_s {
  Pint32_acc tag;
  Puint32_acc code;
  Puint32_acc pn;
};

Perror_t dibblerPN_acc_init (P_t *pads,dibblerPN_acc *acc);

Perror_t dibblerPN_acc_reset (P_t *pads,dibblerPN_acc *acc);

Perror_t dibblerPN_acc_cleanup (P_t *pads,dibblerPN_acc *acc);

Perror_t dibblerPN_acc_add (P_t *pads,dibblerPN_acc *acc,dibblerPN_pd *pd,dibblerPN *rep);

Perror_t dibblerPN_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,dibblerPN_acc *acc);

Perror_t dibblerPN_acc_report (P_t *pads,char const *prefix,char const *what,int nst,dibblerPN_acc *acc);

Perror_t dibblerPN_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,dibblerPN_acc *acc);

ssize_t dibblerPN_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,dibblerPN_m *m,dibblerPN_pd *pd,dibblerPN *rep,int x);

ssize_t dibblerPN_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,dibblerPN_m *m,dibblerPN_pd *pd,dibblerPN *rep,int x);

ssize_t dibblerPN_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,dibblerPN_m *m,dibblerPN_pd *pd,dibblerPN *rep,int x);
typedef struct int32record_s int32record;
typedef struct int32record_m_s int32record_m;
typedef struct int32record_pd_s int32record_pd;
struct int32record_m_s {
  Pbase_m compoundLevel;
  Pbase_m x;		/* nested constraints */
};
struct int32record_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd x;
};
struct int32record_s {
  Puint32 x;
};

Perror_t int32record_init (P_t *pads,int32record *rep);

Perror_t int32record_pd_init (P_t *pads,int32record_pd *pd);

Perror_t int32record_cleanup (P_t *pads,int32record *rep);

Perror_t int32record_pd_cleanup (P_t *pads,int32record_pd *pd);

Perror_t int32record_copy (P_t *pads,int32record *rep_dst,int32record *rep_src);

Perror_t int32record_pd_copy (P_t *pads,int32record_pd *pd_dst,int32record_pd *pd_src);

void int32record_m_init (P_t *pads,int32record_m *mask,Pbase_m baseMask);

Perror_t int32record_m_rec_init (P_t *pads,int32record_m *mask,Pbase_m baseMask);

Perror_t int32record_read (P_t *pads,int32record_m *m,int32record_pd *pd,int32record *rep);

int int32record_verify (P_t *pads,int32record *rep);

int int32record_genPD (P_t *pads,int32record *rep,int32record_pd *pd);
typedef struct int32record_acc_s int32record_acc;
struct int32record_acc_s {
  Puint32_acc nerr;
  Puint32_acc x;
};

Perror_t int32record_acc_init (P_t *pads,int32record_acc *acc);

Perror_t int32record_acc_reset (P_t *pads,int32record_acc *acc);

Perror_t int32record_acc_cleanup (P_t *pads,int32record_acc *acc);

Perror_t int32record_acc_add (P_t *pads,int32record_acc *acc,int32record_pd *pd,int32record *rep);

Perror_t int32record_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,int32record_acc *acc);

Perror_t int32record_acc_report (P_t *pads,char const *prefix,char const *what,int nst,int32record_acc *acc);

Perror_t int32record_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,int32record_acc *acc);

ssize_t int32record_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int32record_pd *pd,int32record *rep);

ssize_t int32record_write2io (P_t *pads,Sfio_t *io,int32record_pd *pd,int32record *rep);

ssize_t int32record_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int32record_pd *pd,int32record *rep,char const *_tag,int indent);

ssize_t int32record_write_xml_2io (P_t *pads,Sfio_t *io,int32record_pd *pd,int32record *rep,char const *_tag,int indent);

ssize_t int32record_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,int32record_m *m,int32record_pd *pd,int32record *rep);

ssize_t int32record_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,int32record_m *m,int32record_pd *pd,int32record *rep);

ssize_t int32record_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,int32record_m *m,int32record_pd *pd,int32record *rep);
typedef struct call_s call;
typedef struct call_m_s call_m;
typedef struct call_pd_s call_pd;
struct call_m_s {
  Pbase_m compoundLevel;
  int32record_m x;		/* nested constraints */
  dibblerPN_m pn;		/* nested constraints */
};
struct call_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  int32record_pd x;
  dibblerPN_pd pn;
};
struct call_s {
  int32record x;
  dibblerPN pn;
};

Perror_t call_init (P_t *pads,call *rep);

Perror_t call_pd_init (P_t *pads,call_pd *pd);

Perror_t call_cleanup (P_t *pads,call *rep);

Perror_t call_pd_cleanup (P_t *pads,call_pd *pd);

Perror_t call_copy (P_t *pads,call *rep_dst,call *rep_src);

Perror_t call_pd_copy (P_t *pads,call_pd *pd_dst,call_pd *pd_src);

void call_m_init (P_t *pads,call_m *mask,Pbase_m baseMask);

Perror_t call_m_rec_init (P_t *pads,call_m *mask,Pbase_m baseMask);

Perror_t call_read (P_t *pads,call_m *m,call_pd *pd,call *rep);

int call_verify (P_t *pads,call *rep);

int call_genPD (P_t *pads,call *rep,call_pd *pd);
typedef struct call_acc_s call_acc;
struct call_acc_s {
  Puint32_acc nerr;
  int32record_acc x;
  dibblerPN_acc pn;
};

Perror_t call_acc_init (P_t *pads,call_acc *acc);

Perror_t call_acc_reset (P_t *pads,call_acc *acc);

Perror_t call_acc_cleanup (P_t *pads,call_acc *acc);

Perror_t call_acc_add (P_t *pads,call_acc *acc,call_pd *pd,call *rep);

Perror_t call_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,call_acc *acc);

Perror_t call_acc_report (P_t *pads,char const *prefix,char const *what,int nst,call_acc *acc);

Perror_t call_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,call_acc *acc);

ssize_t call_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,call_pd *pd,call *rep);

ssize_t call_write2io (P_t *pads,Sfio_t *io,call_pd *pd,call *rep);

ssize_t call_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,call_pd *pd,call *rep,char const *_tag,int indent);

ssize_t call_write_xml_2io (P_t *pads,Sfio_t *io,call_pd *pd,call *rep,char const *_tag,int indent);

ssize_t call_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,call_m *m,call_pd *pd,call *rep);

ssize_t call_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,call_m *m,call_pd *pd,call *rep);

ssize_t call_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,call_m *m,call_pd *pd,call *rep);

void P_lib_init ();

#endif /*  __FORMAT5__H__  */
