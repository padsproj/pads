#ifndef __PSWITCH__H__
#define __PSWITCH__H__
#include "pads.h"
typedef enum branches_tag_e branches_tag;
typedef union branches_u_u branches_u;
typedef struct branches_s branches;
typedef struct branches_m_s branches_m;
typedef union branches_pd_u_u branches_pd_u;
typedef struct branches_pd_s branches_pd;
enum branches_tag_e {
  branches_err=0,
  number=1,
  name=2,
  def=3
  };
union branches_pd_u_u {
  Pbase_pd number;
  Pbase_pd name;
  Pbase_pd def;		/* def = 3 */
};
struct branches_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  branches_tag tag;
  branches_pd_u val;
};
union branches_u_u {
  Pint32 number;		/* (number % 2) == 0&& */
  Pstring name;
  Puint32 def;		/* def = 3 */
};
struct branches_s {
  branches_tag tag;
  branches_u val;
};
struct branches_m_s {
  Pbase_m compoundLevel;
  Pbase_m number;		/* nested constraints */
  Pbase_m number_con;		/* union constraints */
  Pbase_m name;		/* nested constraints */
  Pbase_m def;		/* nested constraints */
};

ssize_t branches_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,branches_pd *pd,branches *rep,Puint32 a);

ssize_t branches_write2io (P_t *pads,Sfio_t *io,branches_pd *pd,branches *rep,Puint32 a);

ssize_t branches_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,branches_pd *pd,branches *rep,char const *_tag,int indent,Puint32 a);

ssize_t branches_write_xml_2io (P_t *pads,Sfio_t *io,branches_pd *pd,branches *rep,char const *_tag,int indent,Puint32 a);

char const *branches_tag2str (branches_tag which);

Perror_t branches_init (P_t *pads,branches *rep);

Perror_t branches_pd_init (P_t *pads,branches_pd *pd);

Perror_t branches_cleanup (P_t *pads,branches *rep);

Perror_t branches_pd_cleanup (P_t *pads,branches_pd *pd);

Perror_t branches_copy (P_t *pads,branches *rep_dst,branches *rep_src);

Perror_t branches_pd_copy (P_t *pads,branches_pd *pd_dst,branches_pd *pd_src);

void branches_m_init (P_t *pads,branches_m *mask,Pbase_m baseMask);

Perror_t branches_m_rec_init (P_t *pads,branches_m *mask,Pbase_m baseMask);

Perror_t branches_read (P_t *pads,branches_m *m,branches_pd *pd,branches *rep,Puint32 a);

int branches_verify (P_t *pads,branches *rep,Puint32 a);

int branches_genPD (P_t *pads,branches *rep,branches_pd *pd,Puint32 a);
typedef struct branches_acc_s branches_acc;
struct branches_acc_s {
  Pint32_acc tag;
  Pint32_acc number;
  Pstring_acc name;
  Puint32_acc def;		/* def = 3 */
};

Perror_t branches_acc_init (P_t *pads,branches_acc *acc);

Perror_t branches_acc_reset (P_t *pads,branches_acc *acc);

Perror_t branches_acc_cleanup (P_t *pads,branches_acc *acc);

Perror_t branches_acc_add (P_t *pads,branches_acc *acc,branches_pd *pd,branches *rep);

Perror_t branches_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,branches_acc *acc);

Perror_t branches_acc_report (P_t *pads,char const *prefix,char const *what,int nst,branches_acc *acc);

Perror_t branches_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,branches_acc *acc);

ssize_t branches_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,branches_m *m,branches_pd *pd,branches *rep,Puint32 a);

ssize_t branches_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,branches_m *m,branches_pd *pd,branches *rep,Puint32 a);

ssize_t branches_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,branches_m *m,branches_pd *pd,branches *rep,Puint32 a);
typedef struct choice_s choice;
typedef struct choice_m_s choice_m;
typedef struct choice_pd_s choice_pd;
struct choice_m_s {
  Pbase_m compoundLevel;
  Pbase_m a;		/* nested constraints */
  branches_m b;		/* nested constraints */
};
struct choice_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd a;
  branches_pd b;
};
struct choice_s {
  Puint32 a;
  branches b;
};

Perror_t choice_init (P_t *pads,choice *rep);

Perror_t choice_pd_init (P_t *pads,choice_pd *pd);

Perror_t choice_cleanup (P_t *pads,choice *rep);

Perror_t choice_pd_cleanup (P_t *pads,choice_pd *pd);

Perror_t choice_copy (P_t *pads,choice *rep_dst,choice *rep_src);

Perror_t choice_pd_copy (P_t *pads,choice_pd *pd_dst,choice_pd *pd_src);

void choice_m_init (P_t *pads,choice_m *mask,Pbase_m baseMask);

Perror_t choice_m_rec_init (P_t *pads,choice_m *mask,Pbase_m baseMask);

Perror_t choice_read (P_t *pads,choice_m *m,choice_pd *pd,choice *rep);

int choice_verify (P_t *pads,choice *rep);

int choice_genPD (P_t *pads,choice *rep,choice_pd *pd);
typedef struct choice_acc_s choice_acc;
struct choice_acc_s {
  Puint32_acc nerr;
  Puint32_acc a;
  branches_acc b;
};

Perror_t choice_acc_init (P_t *pads,choice_acc *acc);

Perror_t choice_acc_reset (P_t *pads,choice_acc *acc);

Perror_t choice_acc_cleanup (P_t *pads,choice_acc *acc);

Perror_t choice_acc_add (P_t *pads,choice_acc *acc,choice_pd *pd,choice *rep);

Perror_t choice_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,choice_acc *acc);

Perror_t choice_acc_report (P_t *pads,char const *prefix,char const *what,int nst,choice_acc *acc);

Perror_t choice_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,choice_acc *acc);

ssize_t choice_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choice_pd *pd,choice *rep);

ssize_t choice_write2io (P_t *pads,Sfio_t *io,choice_pd *pd,choice *rep);

ssize_t choice_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choice_pd *pd,choice *rep,char const *_tag,int indent);

ssize_t choice_write_xml_2io (P_t *pads,Sfio_t *io,choice_pd *pd,choice *rep,char const *_tag,int indent);

ssize_t choice_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);

ssize_t choice_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);

ssize_t choice_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);

void P_lib_init ();

#endif /*  __PSWITCH__H__  */
