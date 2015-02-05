#ifndef __OPT__H__
#define __OPT__H__
#include "pads.h"
typedef enum foo_tag_e foo_tag;
typedef union foo_u_u foo_u;
typedef struct foo_s foo;
typedef struct foo_m_s foo_m;
typedef union foo_pd_u_u foo_pd_u;
typedef struct foo_pd_s foo_pd;
enum foo_tag_e {
  foo_err=0,
  some_foo=1,
  none_foo=2
  };
union foo_pd_u_u {
  Pbase_pd some_foo;
  Pbase_pd none_foo;		/* value was not present. none_foo = 0 */
};
struct foo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  foo_tag tag;
  foo_pd_u val;
};
union foo_u_u {
  Pstring some_foo;		/* value is present */
};
struct foo_s {
  foo_tag tag;
  foo_u val;
};
struct foo_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_foo;		/* nested constraints */
  Pbase_m none_foo;		/* nested constraints */
};

ssize_t foo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,Pchar x);

ssize_t foo_write2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,Pchar x);

ssize_t foo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_pd *pd,foo *rep,char const *_tag,int indent,Pchar x);

ssize_t foo_write_xml_2io (P_t *pads,Sfio_t *io,foo_pd *pd,foo *rep,char const *_tag,int indent,Pchar x);

char const *foo_tag2str (foo_tag which);

Perror_t foo_init (P_t *pads,foo *rep);

Perror_t foo_pd_init (P_t *pads,foo_pd *pd);

Perror_t foo_cleanup (P_t *pads,foo *rep);

Perror_t foo_pd_cleanup (P_t *pads,foo_pd *pd);

Perror_t foo_copy (P_t *pads,foo *rep_dst,foo *rep_src);

Perror_t foo_pd_copy (P_t *pads,foo_pd *pd_dst,foo_pd *pd_src);

void foo_m_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_m_rec_init (P_t *pads,foo_m *mask,Pbase_m baseMask);

Perror_t foo_read (P_t *pads,foo_m *m,foo_pd *pd,foo *rep,Pchar x);

int foo_verify (P_t *pads,foo *rep,Pchar x);

int foo_genPD (P_t *pads,foo *rep,foo_pd *pd,Pchar x);
typedef struct foo_acc_s foo_acc;
struct foo_acc_s {
  Pint32_acc tag;
  Pstring_acc some_foo;
};

Perror_t foo_acc_init (P_t *pads,foo_acc *acc);

Perror_t foo_acc_reset (P_t *pads,foo_acc *acc);

Perror_t foo_acc_cleanup (P_t *pads,foo_acc *acc);

Perror_t foo_acc_add (P_t *pads,foo_acc *acc,foo_pd *pd,foo *rep);

Perror_t foo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_acc *acc);

Perror_t foo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_acc *acc);

ssize_t foo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar x);

ssize_t foo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar x);

ssize_t foo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_m *m,foo_pd *pd,foo *rep,Pchar x);
typedef enum baz_tag_e baz_tag;
typedef union baz_u_u baz_u;
typedef struct baz_s baz;
typedef struct baz_m_s baz_m;
typedef union baz_pd_u_u baz_pd_u;
typedef struct baz_pd_s baz_pd;
enum baz_tag_e {
  baz_err=0,
  some_baz=1,
  none_baz=2
  };
union baz_pd_u_u {
  Pbase_pd some_baz;
  Pbase_pd none_baz;		/* value was not present. none_baz = 0 */
};
struct baz_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  baz_tag tag;
  baz_pd_u val;
};
union baz_u_u {
  Puint32 some_baz;		/* value is present. (some_baz % 2) == 0&& */
};
struct baz_s {
  baz_tag tag;
  baz_u val;
};
struct baz_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_baz;		/* nested constraints */
  Pbase_m some_baz_con;		/* union constraints */
  Pbase_m none_baz;		/* nested constraints */
};

ssize_t baz_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,baz_pd *pd,baz *rep);

ssize_t baz_write2io (P_t *pads,Sfio_t *io,baz_pd *pd,baz *rep);

ssize_t baz_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,baz_pd *pd,baz *rep,char const *_tag,int indent);

ssize_t baz_write_xml_2io (P_t *pads,Sfio_t *io,baz_pd *pd,baz *rep,char const *_tag,int indent);

char const *baz_tag2str (baz_tag which);

Perror_t baz_init (P_t *pads,baz *rep);

Perror_t baz_pd_init (P_t *pads,baz_pd *pd);

Perror_t baz_cleanup (P_t *pads,baz *rep);

Perror_t baz_pd_cleanup (P_t *pads,baz_pd *pd);

Perror_t baz_copy (P_t *pads,baz *rep_dst,baz *rep_src);

Perror_t baz_pd_copy (P_t *pads,baz_pd *pd_dst,baz_pd *pd_src);

void baz_m_init (P_t *pads,baz_m *mask,Pbase_m baseMask);

Perror_t baz_m_rec_init (P_t *pads,baz_m *mask,Pbase_m baseMask);

Perror_t baz_read (P_t *pads,baz_m *m,baz_pd *pd,baz *rep);

int baz_verify (P_t *pads,baz *rep);

int baz_genPD (P_t *pads,baz *rep,baz_pd *pd);
typedef struct baz_acc_s baz_acc;
struct baz_acc_s {
  Pint32_acc tag;
  Puint32_acc some_baz;
};

Perror_t baz_acc_init (P_t *pads,baz_acc *acc);

Perror_t baz_acc_reset (P_t *pads,baz_acc *acc);

Perror_t baz_acc_cleanup (P_t *pads,baz_acc *acc);

Perror_t baz_acc_add (P_t *pads,baz_acc *acc,baz_pd *pd,baz *rep);

Perror_t baz_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,baz_acc *acc);

Perror_t baz_acc_report (P_t *pads,char const *prefix,char const *what,int nst,baz_acc *acc);

Perror_t baz_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,baz_acc *acc);

ssize_t baz_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,baz_m *m,baz_pd *pd,baz *rep);

ssize_t baz_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,baz_m *m,baz_pd *pd,baz *rep);

ssize_t baz_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,baz_m *m,baz_pd *pd,baz *rep);
typedef enum biz_t_tag_e biz_t_tag;
typedef union biz_t_u_u biz_t_u;
typedef struct biz_t_s biz_t;
typedef struct biz_t_m_s biz_t_m;
typedef union biz_t_pd_u_u biz_t_pd_u;
typedef struct biz_t_pd_s biz_t_pd;
enum biz_t_tag_e {
  biz_t_err=0,
  some_biz_t=1,
  none_biz_t=2
  };
union biz_t_pd_u_u {
  Pbase_pd some_biz_t;
  Pbase_pd none_biz_t;		/* value was not present. none_biz_t = 0 */
};
struct biz_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  biz_t_tag tag;
  biz_t_pd_u val;
};
union biz_t_u_u {
  Puint32 some_biz_t;		/* value is present. (some_biz_t % 2) != 0&& */
};
struct biz_t_s {
  biz_t_tag tag;
  biz_t_u val;
};
struct biz_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_biz_t;		/* nested constraints */
  Pbase_m some_biz_t_con;		/* union constraints */
  Pbase_m none_biz_t;		/* nested constraints */
};

ssize_t biz_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);

ssize_t biz_t_write2io (P_t *pads,Sfio_t *io,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);

ssize_t biz_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,biz_t_pd *pd,biz_t *rep,char const *_tag,int indent,foo *x,baz *f);

ssize_t biz_t_write_xml_2io (P_t *pads,Sfio_t *io,biz_t_pd *pd,biz_t *rep,char const *_tag,int indent,foo *x,baz *f);

char const *biz_t_tag2str (biz_t_tag which);

Perror_t biz_t_init (P_t *pads,biz_t *rep);

Perror_t biz_t_pd_init (P_t *pads,biz_t_pd *pd);

Perror_t biz_t_cleanup (P_t *pads,biz_t *rep);

Perror_t biz_t_pd_cleanup (P_t *pads,biz_t_pd *pd);

Perror_t biz_t_copy (P_t *pads,biz_t *rep_dst,biz_t *rep_src);

Perror_t biz_t_pd_copy (P_t *pads,biz_t_pd *pd_dst,biz_t_pd *pd_src);

void biz_t_m_init (P_t *pads,biz_t_m *mask,Pbase_m baseMask);

Perror_t biz_t_m_rec_init (P_t *pads,biz_t_m *mask,Pbase_m baseMask);

Perror_t biz_t_read (P_t *pads,biz_t_m *m,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);

int biz_t_verify (P_t *pads,biz_t *rep,foo *x,baz *f);

int biz_t_genPD (P_t *pads,biz_t *rep,biz_t_pd *pd,foo *x,baz *f);
typedef struct biz_t_acc_s biz_t_acc;
struct biz_t_acc_s {
  Pint32_acc tag;
  Puint32_acc some_biz_t;
};

Perror_t biz_t_acc_init (P_t *pads,biz_t_acc *acc);

Perror_t biz_t_acc_reset (P_t *pads,biz_t_acc *acc);

Perror_t biz_t_acc_cleanup (P_t *pads,biz_t_acc *acc);

Perror_t biz_t_acc_add (P_t *pads,biz_t_acc *acc,biz_t_pd *pd,biz_t *rep);

Perror_t biz_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,biz_t_acc *acc);

Perror_t biz_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,biz_t_acc *acc);

Perror_t biz_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,biz_t_acc *acc);

ssize_t biz_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,biz_t_m *m,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);

ssize_t biz_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,biz_t_m *m,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);

ssize_t biz_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,biz_t_m *m,biz_t_pd *pd,biz_t *rep,foo *x,baz *f);
typedef enum zot_t_tag_e zot_t_tag;
typedef union zot_t_u_u zot_t_u;
typedef struct zot_t_s zot_t;
typedef struct zot_t_m_s zot_t_m;
typedef union zot_t_pd_u_u zot_t_pd_u;
typedef struct zot_t_pd_s zot_t_pd;
enum zot_t_tag_e {
  zot_t_err=0,
  some_zot_t=1,
  none_zot_t=2
  };
union zot_t_pd_u_u {
  Pbase_pd some_zot_t;
  Pbase_pd none_zot_t;		/* value was not present. none_zot_t = 0 */
};
struct zot_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  zot_t_tag tag;
  zot_t_pd_u val;
};
union zot_t_u_u {
  Puint32 some_zot_t;		/* value is present */
};
struct zot_t_s {
  zot_t_tag tag;
  zot_t_u val;
};
struct zot_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_zot_t;		/* nested constraints */
  Pbase_m none_zot_t;		/* nested constraints */
};

ssize_t zot_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);

ssize_t zot_t_write2io (P_t *pads,Sfio_t *io,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);

ssize_t zot_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zot_t_pd *pd,zot_t *rep,char const *_tag,int indent,foo *x,baz *f,biz_t *biz);

ssize_t zot_t_write_xml_2io (P_t *pads,Sfio_t *io,zot_t_pd *pd,zot_t *rep,char const *_tag,int indent,foo *x,baz *f,biz_t *biz);

char const *zot_t_tag2str (zot_t_tag which);

Perror_t zot_t_init (P_t *pads,zot_t *rep);

Perror_t zot_t_pd_init (P_t *pads,zot_t_pd *pd);

Perror_t zot_t_cleanup (P_t *pads,zot_t *rep);

Perror_t zot_t_pd_cleanup (P_t *pads,zot_t_pd *pd);

Perror_t zot_t_copy (P_t *pads,zot_t *rep_dst,zot_t *rep_src);

Perror_t zot_t_pd_copy (P_t *pads,zot_t_pd *pd_dst,zot_t_pd *pd_src);

void zot_t_m_init (P_t *pads,zot_t_m *mask,Pbase_m baseMask);

Perror_t zot_t_m_rec_init (P_t *pads,zot_t_m *mask,Pbase_m baseMask);

Perror_t zot_t_read (P_t *pads,zot_t_m *m,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);

int zot_t_verify (P_t *pads,zot_t *rep,foo *x,baz *f,biz_t *biz);

int zot_t_genPD (P_t *pads,zot_t *rep,zot_t_pd *pd,foo *x,baz *f,biz_t *biz);
typedef struct zot_t_acc_s zot_t_acc;
struct zot_t_acc_s {
  Pint32_acc tag;
  Puint32_acc some_zot_t;
};

Perror_t zot_t_acc_init (P_t *pads,zot_t_acc *acc);

Perror_t zot_t_acc_reset (P_t *pads,zot_t_acc *acc);

Perror_t zot_t_acc_cleanup (P_t *pads,zot_t_acc *acc);

Perror_t zot_t_acc_add (P_t *pads,zot_t_acc *acc,zot_t_pd *pd,zot_t *rep);

Perror_t zot_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,zot_t_acc *acc);

Perror_t zot_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,zot_t_acc *acc);

Perror_t zot_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,zot_t_acc *acc);

ssize_t zot_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zot_t_m *m,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);

ssize_t zot_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zot_t_m *m,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);

ssize_t zot_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,zot_t_m *m,zot_t_pd *pd,zot_t *rep,foo *x,baz *f,biz_t *biz);
typedef enum zig_t_tag_e zig_t_tag;
typedef union zig_t_u_u zig_t_u;
typedef struct zig_t_s zig_t;
typedef struct zig_t_m_s zig_t_m;
typedef union zig_t_pd_u_u zig_t_pd_u;
typedef struct zig_t_pd_s zig_t_pd;
enum zig_t_tag_e {
  zig_t_err=0,
  some_zig_t=1,
  none_zig_t=2
  };
union zig_t_pd_u_u {
  Pbase_pd some_zig_t;
  Pbase_pd none_zig_t;		/* value was not present. none_zig_t = 0 */
};
struct zig_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  zig_t_tag tag;
  zig_t_pd_u val;
};
union zig_t_u_u {
  Puint32 some_zig_t;		/* value is present */
};
struct zig_t_s {
  zig_t_tag tag;
  zig_t_u val;
};
struct zig_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_zig_t;		/* nested constraints */
  Pbase_m none_zig_t;		/* nested constraints */
};

ssize_t zig_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

ssize_t zig_t_write2io (P_t *pads,Sfio_t *io,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

ssize_t zig_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zig_t_pd *pd,zig_t *rep,char const *_tag,int indent,foo *x,baz *f,biz_t *biz,zot_t *zot);

ssize_t zig_t_write_xml_2io (P_t *pads,Sfio_t *io,zig_t_pd *pd,zig_t *rep,char const *_tag,int indent,foo *x,baz *f,biz_t *biz,zot_t *zot);

char const *zig_t_tag2str (zig_t_tag which);

Perror_t zig_t_init (P_t *pads,zig_t *rep);

Perror_t zig_t_pd_init (P_t *pads,zig_t_pd *pd);

Perror_t zig_t_cleanup (P_t *pads,zig_t *rep);

Perror_t zig_t_pd_cleanup (P_t *pads,zig_t_pd *pd);

Perror_t zig_t_copy (P_t *pads,zig_t *rep_dst,zig_t *rep_src);

Perror_t zig_t_pd_copy (P_t *pads,zig_t_pd *pd_dst,zig_t_pd *pd_src);

void zig_t_m_init (P_t *pads,zig_t_m *mask,Pbase_m baseMask);

Perror_t zig_t_m_rec_init (P_t *pads,zig_t_m *mask,Pbase_m baseMask);

Perror_t zig_t_read (P_t *pads,zig_t_m *m,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

int zig_t_verify (P_t *pads,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

int zig_t_genPD (P_t *pads,zig_t *rep,zig_t_pd *pd,foo *x,baz *f,biz_t *biz,zot_t *zot);
typedef struct zig_t_acc_s zig_t_acc;
struct zig_t_acc_s {
  Pint32_acc tag;
  Puint32_acc some_zig_t;
};

Perror_t zig_t_acc_init (P_t *pads,zig_t_acc *acc);

Perror_t zig_t_acc_reset (P_t *pads,zig_t_acc *acc);

Perror_t zig_t_acc_cleanup (P_t *pads,zig_t_acc *acc);

Perror_t zig_t_acc_add (P_t *pads,zig_t_acc *acc,zig_t_pd *pd,zig_t *rep);

Perror_t zig_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,zig_t_acc *acc);

Perror_t zig_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,zig_t_acc *acc);

Perror_t zig_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,zig_t_acc *acc);

ssize_t zig_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zig_t_m *m,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

ssize_t zig_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zig_t_m *m,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);

ssize_t zig_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,zig_t_m *m,zig_t_pd *pd,zig_t *rep,foo *x,baz *f,biz_t *biz,zot_t *zot);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  foo_m x;		/* nested constraints */
  baz_m f;		/* nested constraints */
  biz_t_m biz;		/* nested constraints */
  zot_t_m zot;		/* nested constraints */
  zig_t_m zig;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  foo_pd x;
  baz_pd f;
  biz_t_pd biz;
  zot_t_pd zot;
  zig_t_pd zig;
};
struct entry_s {
  foo x;
  baz f;
  biz_t biz;
  zot_t zot;
  zig_t zig;
};

Perror_t entry_init (P_t *pads,entry *rep);

Perror_t entry_pd_init (P_t *pads,entry_pd *pd);

Perror_t entry_cleanup (P_t *pads,entry *rep);

Perror_t entry_pd_cleanup (P_t *pads,entry_pd *pd);

Perror_t entry_copy (P_t *pads,entry *rep_dst,entry *rep_src);

Perror_t entry_pd_copy (P_t *pads,entry_pd *pd_dst,entry_pd *pd_src);

void entry_m_init (P_t *pads,entry_m *mask,Pbase_m baseMask);

Perror_t entry_m_rec_init (P_t *pads,entry_m *mask,Pbase_m baseMask);

Perror_t entry_read (P_t *pads,entry_m *m,entry_pd *pd,entry *rep);

int entry_verify (P_t *pads,entry *rep);

int entry_genPD (P_t *pads,entry *rep,entry_pd *pd);
typedef struct entry_acc_s entry_acc;
struct entry_acc_s {
  Puint32_acc nerr;
  foo_acc x;
  baz_acc f;
  biz_t_acc biz;
  zot_t_acc zot;
  zig_t_acc zig;
};

Perror_t entry_acc_init (P_t *pads,entry_acc *acc);

Perror_t entry_acc_reset (P_t *pads,entry_acc *acc);

Perror_t entry_acc_cleanup (P_t *pads,entry_acc *acc);

Perror_t entry_acc_add (P_t *pads,entry_acc *acc,entry_pd *pd,entry *rep);

Perror_t entry_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entry_acc *acc);

Perror_t entry_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entry_acc *acc);

Perror_t entry_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,entry_acc *acc);

ssize_t entry_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_pd *pd,entry *rep);

ssize_t entry_write2io (P_t *pads,Sfio_t *io,entry_pd *pd,entry *rep);

ssize_t entry_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_pd *pd,entry *rep,char const *_tag,int indent);

ssize_t entry_write_xml_2io (P_t *pads,Sfio_t *io,entry_pd *pd,entry *rep,char const *_tag,int indent);

ssize_t entry_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

ssize_t entry_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

ssize_t entry_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entry_m *m,entry_pd *pd,entry *rep);

void P_lib_init ();

#endif /*  __OPT__H__  */
