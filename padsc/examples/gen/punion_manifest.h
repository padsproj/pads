#ifndef __PUNION_MANIFEST__H__
#define __PUNION_MANIFEST__H__
#include "pads.h"
typedef struct str1_s str1;
typedef struct str1_m_s str1_m;
typedef struct str1_pd_s str1_pd;
struct str1_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct str1_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd id;
  Pbase_pd ts;
};
struct str1_s {
  Pint32 id;		/*  identity. id < 100000&& */
  Pint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t str1_init (P_t *pads,str1 *rep);

Perror_t str1_pd_init (P_t *pads,str1_pd *pd);

Perror_t str1_cleanup (P_t *pads,str1 *rep);

Perror_t str1_pd_cleanup (P_t *pads,str1_pd *pd);

Perror_t str1_copy (P_t *pads,str1 *rep_dst,str1 *rep_src);

Perror_t str1_pd_copy (P_t *pads,str1_pd *pd_dst,str1_pd *pd_src);

void str1_m_init (P_t *pads,str1_m *mask,Pbase_m baseMask);

Perror_t str1_m_rec_init (P_t *pads,str1_m *mask,Pbase_m baseMask);

Perror_t str1_read (P_t *pads,str1_m *m,str1_pd *pd,str1 *rep);

int str1_verify (P_t *pads,str1 *rep);

int str1_genPD (P_t *pads,str1 *rep,str1_pd *pd);
typedef struct str1_acc_s str1_acc;
struct str1_acc_s {
  Puint32_acc nerr;
  Pint32_acc id;		/*  identity. id < 100000&& */
  Pint32_acc ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t str1_acc_init (P_t *pads,str1_acc *acc);

Perror_t str1_acc_reset (P_t *pads,str1_acc *acc);

Perror_t str1_acc_cleanup (P_t *pads,str1_acc *acc);

Perror_t str1_acc_add (P_t *pads,str1_acc *acc,str1_pd *pd,str1 *rep);

Perror_t str1_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,str1_acc *acc);

Perror_t str1_acc_report (P_t *pads,char const *prefix,char const *what,int nst,str1_acc *acc);

Perror_t str1_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,str1_acc *acc);

ssize_t str1_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,str1_pd *pd,str1 *rep);

ssize_t str1_write2io (P_t *pads,Sfio_t *io,str1_pd *pd,str1 *rep);

ssize_t str1_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,str1_pd *pd,str1 *rep,char const *_tag,int indent);

ssize_t str1_write_xml_2io (P_t *pads,Sfio_t *io,str1_pd *pd,str1 *rep,char const *_tag,int indent);

ssize_t str1_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,str1_m *m,str1_pd *pd,str1 *rep);

ssize_t str1_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,str1_m *m,str1_pd *pd,str1 *rep);

ssize_t str1_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,str1_m *m,str1_pd *pd,str1 *rep);
typedef enum choice_tag_e choice_tag;
typedef union choice_u_u choice_u;
typedef struct choice_s choice;
typedef struct choice_m_s choice_m;
typedef union choice_pd_u_u choice_pd_u;
typedef struct choice_pd_s choice_pd;
enum choice_tag_e {
  choice_err=0,
  bigger=1,
  first=2,
  two=3
  };
union choice_pd_u_u {
  str1_pd bigger;
  Pbase_pd first;		/*  default value. first = 12 */
  Pbase_pd two;
};
struct choice_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  choice_tag tag;
  choice_pd_u val;
};
union choice_u_u {
  str1 bigger;
  Pint32 first;		/*  default value. first = 12 */
  Pint32 two;
};
struct choice_s {
  choice_tag tag;
  choice_u val;
};
struct choice_m_s {
  Pbase_m compoundLevel;
  str1_m bigger;		/* nested constraints */
  Pbase_m first;		/* nested constraints */
  Pbase_m two;		/* nested constraints */
};

ssize_t choice_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choice_pd *pd,choice *rep);

ssize_t choice_write2io (P_t *pads,Sfio_t *io,choice_pd *pd,choice *rep);

ssize_t choice_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,choice_pd *pd,choice *rep,char const *_tag,int indent);

ssize_t choice_write_xml_2io (P_t *pads,Sfio_t *io,choice_pd *pd,choice *rep,char const *_tag,int indent);

char const *choice_tag2str (choice_tag which);

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
  Pint32_acc tag;
  str1_acc bigger;
  Pint32_acc first;		/*  default value. first = 12 */
  Pint32_acc two;
};

Perror_t choice_acc_init (P_t *pads,choice_acc *acc);

Perror_t choice_acc_reset (P_t *pads,choice_acc *acc);

Perror_t choice_acc_cleanup (P_t *pads,choice_acc *acc);

Perror_t choice_acc_add (P_t *pads,choice_acc *acc,choice_pd *pd,choice *rep);

Perror_t choice_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,choice_acc *acc);

Perror_t choice_acc_report (P_t *pads,char const *prefix,char const *what,int nst,choice_acc *acc);

Perror_t choice_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,choice_acc *acc);

ssize_t choice_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);

ssize_t choice_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);

ssize_t choice_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,choice_m *m,choice_pd *pd,choice *rep);
typedef struct str2_s str2;
typedef struct str2_m_s str2_m;
typedef struct str2_pd_s str2_pd;
struct str2_m_s {
  Pbase_m compoundLevel;
  choice_m c;		/* nested constraints */
  Pbase_m t;		/* nested constraints */
  Pbase_m v;		/* nested constraints */
};
struct str2_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  choice_pd c;
  Pbase_pd t;
  Pbase_pd v;		/*  struct manifest field. v = 11 */
};
struct str2_s {
  choice c;
  Pint32 t;
  Pint32 v;		/*  struct manifest field. v = 11 */
};

Perror_t str2_init (P_t *pads,str2 *rep);

Perror_t str2_pd_init (P_t *pads,str2_pd *pd);

Perror_t str2_cleanup (P_t *pads,str2 *rep);

Perror_t str2_pd_cleanup (P_t *pads,str2_pd *pd);

Perror_t str2_copy (P_t *pads,str2 *rep_dst,str2 *rep_src);

Perror_t str2_pd_copy (P_t *pads,str2_pd *pd_dst,str2_pd *pd_src);

void str2_m_init (P_t *pads,str2_m *mask,Pbase_m baseMask);

Perror_t str2_m_rec_init (P_t *pads,str2_m *mask,Pbase_m baseMask);

Perror_t str2_read (P_t *pads,str2_m *m,str2_pd *pd,str2 *rep);

int str2_verify (P_t *pads,str2 *rep);

int str2_genPD (P_t *pads,str2 *rep,str2_pd *pd);
typedef struct str2_acc_s str2_acc;
struct str2_acc_s {
  Puint32_acc nerr;
  choice_acc c;
  Pint32_acc t;
  Pint32_acc v;		/*  struct manifest field. v = 11 */
};

Perror_t str2_acc_init (P_t *pads,str2_acc *acc);

Perror_t str2_acc_reset (P_t *pads,str2_acc *acc);

Perror_t str2_acc_cleanup (P_t *pads,str2_acc *acc);

Perror_t str2_acc_add (P_t *pads,str2_acc *acc,str2_pd *pd,str2 *rep);

Perror_t str2_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,str2_acc *acc);

Perror_t str2_acc_report (P_t *pads,char const *prefix,char const *what,int nst,str2_acc *acc);

Perror_t str2_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,str2_acc *acc);

ssize_t str2_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,str2_pd *pd,str2 *rep);

ssize_t str2_write2io (P_t *pads,Sfio_t *io,str2_pd *pd,str2 *rep);

ssize_t str2_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,str2_pd *pd,str2 *rep,char const *_tag,int indent);

ssize_t str2_write_xml_2io (P_t *pads,Sfio_t *io,str2_pd *pd,str2 *rep,char const *_tag,int indent);

ssize_t str2_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,str2_m *m,str2_pd *pd,str2 *rep);

ssize_t str2_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,str2_m *m,str2_pd *pd,str2 *rep);

ssize_t str2_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,str2_m *m,str2_pd *pd,str2 *rep);

void P_lib_init ();

#endif /*  __PUNION_MANIFEST__H__  */
