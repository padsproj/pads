#ifndef __UNION_EMPTY__H__
#define __UNION_EMPTY__H__
#include "pads.h"
typedef enum body_t_tag_e body_t_tag;
typedef union body_t_u_u body_t_u;
typedef struct body_t_s body_t;
typedef struct body_t_m_s body_t_m;
typedef union body_t_pd_u_u body_t_pd_u;
typedef struct body_t_pd_s body_t_pd;
enum body_t_tag_e {
  body_t_err=0,
  i=1,
  c=2,
  Pdefault_0=3
  };
union body_t_pd_u_u {
  Pbase_pd i;
  Pbase_pd c;
  Pbase_pd Pdefault_0;		/* Empty Field. Pdefault_0 = 0 */
};
struct body_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  body_t_tag tag;
  body_t_pd_u val;
};
union body_t_u_u {
  Puint32 i;
  Pchar c;
};
struct body_t_s {
  body_t_tag tag;
  body_t_u val;
};
struct body_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m i;		/* nested constraints */
  Pbase_m c;		/* nested constraints */
  Pbase_m Pdefault_0;		/* nested constraints */
};

ssize_t body_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,body_t_pd *pd,body_t *rep,Puint8 j);

ssize_t body_t_write2io (P_t *pads,Sfio_t *io,body_t_pd *pd,body_t *rep,Puint8 j);

ssize_t body_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,body_t_pd *pd,body_t *rep,char const *_tag,int indent,Puint8 j);

ssize_t body_t_write_xml_2io (P_t *pads,Sfio_t *io,body_t_pd *pd,body_t *rep,char const *_tag,int indent,Puint8 j);

char const *body_t_tag2str (body_t_tag which);

Perror_t body_t_init (P_t *pads,body_t *rep);

Perror_t body_t_pd_init (P_t *pads,body_t_pd *pd);

Perror_t body_t_cleanup (P_t *pads,body_t *rep);

Perror_t body_t_pd_cleanup (P_t *pads,body_t_pd *pd);

Perror_t body_t_copy (P_t *pads,body_t *rep_dst,body_t *rep_src);

Perror_t body_t_pd_copy (P_t *pads,body_t_pd *pd_dst,body_t_pd *pd_src);

void body_t_m_init (P_t *pads,body_t_m *mask,Pbase_m baseMask);

Perror_t body_t_m_rec_init (P_t *pads,body_t_m *mask,Pbase_m baseMask);

Perror_t body_t_read (P_t *pads,body_t_m *m,body_t_pd *pd,body_t *rep,Puint8 j);

int body_t_verify (P_t *pads,body_t *rep,Puint8 j);

int body_t_genPD (P_t *pads,body_t *rep,body_t_pd *pd,Puint8 j);
typedef struct body_t_acc_s body_t_acc;
struct body_t_acc_s {
  Pint32_acc tag;
  Puint32_acc i;
  Pchar_acc c;
};

Perror_t body_t_acc_init (P_t *pads,body_t_acc *acc);

Perror_t body_t_acc_reset (P_t *pads,body_t_acc *acc);

Perror_t body_t_acc_cleanup (P_t *pads,body_t_acc *acc);

Perror_t body_t_acc_add (P_t *pads,body_t_acc *acc,body_t_pd *pd,body_t *rep);

Perror_t body_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,body_t_acc *acc);

Perror_t body_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,body_t_acc *acc);

Perror_t body_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,body_t_acc *acc);

ssize_t body_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,body_t_m *m,body_t_pd *pd,body_t *rep,Puint8 j);

ssize_t body_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,body_t_m *m,body_t_pd *pd,body_t *rep,Puint8 j);

ssize_t body_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,body_t_m *m,body_t_pd *pd,body_t *rep,Puint8 j);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m i;		/* nested constraints */
  body_t_m body;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd i;
  body_t_pd body;
};
struct entry_t_s {
  Puint8 i;
  body_t body;
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
  Puint8_acc i;
  body_t_acc body;
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

#endif /*  __UNION_EMPTY__H__  */
