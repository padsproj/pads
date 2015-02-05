#ifndef __FORMAT_BUG2__H__
#define __FORMAT_BUG2__H__
#include "pads.h"
typedef enum Union_325_tag_e Union_325_tag;
typedef union Union_325_u_u Union_325_u;
typedef struct Union_325_s Union_325;
typedef struct Union_325_m_s Union_325_m;
typedef union Union_325_pd_u_u Union_325_pd_u;
typedef struct Union_325_pd_s Union_325_pd;
enum Union_325_tag_e {
  Union_325_err=0,
  var_327=1,
  i=2,
  Pdefault_0=3
  };
union Union_325_pd_u_u {
  Pbase_pd var_327;
  Pbase_pd i;
  Pbase_pd Pdefault_0;		/* Empty Field. Pdefault_0 = 0 */
};
struct Union_325_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Union_325_tag tag;
  Union_325_pd_u val;
};
union Union_325_u_u {
  Puint32 i;
};
struct Union_325_s {
  Union_325_tag tag;
  Union_325_u val;
};
struct Union_325_m_s {
  Pbase_m compoundLevel;
  Pbase_m i;		/* nested constraints */
  Pbase_m Pdefault_0;		/* nested constraints */
};

ssize_t Union_325_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Union_325_pd *pd,Union_325 *rep);

ssize_t Union_325_write2io (P_t *pads,Sfio_t *io,Union_325_pd *pd,Union_325 *rep);

ssize_t Union_325_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Union_325_pd *pd,Union_325 *rep,char const *_tag,int indent);

ssize_t Union_325_write_xml_2io (P_t *pads,Sfio_t *io,Union_325_pd *pd,Union_325 *rep,char const *_tag,int indent);

char const *Union_325_tag2str (Union_325_tag which);

Perror_t Union_325_init (P_t *pads,Union_325 *rep);

Perror_t Union_325_pd_init (P_t *pads,Union_325_pd *pd);

Perror_t Union_325_cleanup (P_t *pads,Union_325 *rep);

Perror_t Union_325_pd_cleanup (P_t *pads,Union_325_pd *pd);

Perror_t Union_325_copy (P_t *pads,Union_325 *rep_dst,Union_325 *rep_src);

Perror_t Union_325_pd_copy (P_t *pads,Union_325_pd *pd_dst,Union_325_pd *pd_src);

void Union_325_m_init (P_t *pads,Union_325_m *mask,Pbase_m baseMask);

Perror_t Union_325_m_rec_init (P_t *pads,Union_325_m *mask,Pbase_m baseMask);

Perror_t Union_325_read (P_t *pads,Union_325_m *m,Union_325_pd *pd,Union_325 *rep);

int Union_325_verify (P_t *pads,Union_325 *rep);

int Union_325_genPD (P_t *pads,Union_325 *rep,Union_325_pd *pd);
typedef struct Union_325_acc_s Union_325_acc;
struct Union_325_acc_s {
  Pint32_acc tag;
  Puint32_acc i;
};

Perror_t Union_325_acc_init (P_t *pads,Union_325_acc *acc);

Perror_t Union_325_acc_reset (P_t *pads,Union_325_acc *acc);

Perror_t Union_325_acc_cleanup (P_t *pads,Union_325_acc *acc);

Perror_t Union_325_acc_add (P_t *pads,Union_325_acc *acc,Union_325_pd *pd,Union_325 *rep);

Perror_t Union_325_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,Union_325_acc *acc);

Perror_t Union_325_acc_report (P_t *pads,char const *prefix,char const *what,int nst,Union_325_acc *acc);

Perror_t Union_325_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,Union_325_acc *acc);

ssize_t Union_325_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Union_325_m *m,Union_325_pd *pd,Union_325 *rep);

ssize_t Union_325_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Union_325_m *m,Union_325_pd *pd,Union_325 *rep);

ssize_t Union_325_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,Union_325_m *m,Union_325_pd *pd,Union_325 *rep);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  Union_325_m var_325;		/* nested constraints */
  Pbase_m var_335;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Union_325_pd var_325;
  Pbase_pd var_335;
};
struct entry_t_s {
  Union_325 var_325;
  Pstring var_335;
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
  Union_325_acc var_325;
  Pstring_acc var_335;
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

#endif /*  __FORMAT_BUG2__H__  */
