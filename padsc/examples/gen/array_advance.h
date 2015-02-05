#ifndef __ARRAY_ADVANCE__H__
#define __ARRAY_ADVANCE__H__
#include "pads.h"
typedef enum foo_t_tag_e foo_t_tag;
typedef union foo_t_u_u foo_t_u;
typedef struct foo_t_s foo_t;
typedef struct foo_t_m_s foo_t_m;
typedef union foo_t_pd_u_u foo_t_pd_u;
typedef struct foo_t_pd_s foo_t_pd;
enum foo_t_tag_e {
  foo_t_err=0,
  some_foo_t=1,
  none_foo_t=2
  };
union foo_t_pd_u_u {
  Pbase_pd some_foo_t;
  Pbase_pd none_foo_t;		/* value was not present. none_foo_t = 0 */
};
struct foo_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  foo_t_tag tag;
  foo_t_pd_u val;
};
union foo_t_u_u {
  Pchar some_foo_t;		/* value is present. some_foo_t == a&& */
};
struct foo_t_s {
  foo_t_tag tag;
  foo_t_u val;
};
struct foo_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_foo_t;		/* nested constraints */
  Pbase_m some_foo_t_con;		/* union constraints */
  Pbase_m none_foo_t;		/* nested constraints */
};

ssize_t foo_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_write2io (P_t *pads,Sfio_t *io,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_t_pd *pd,foo_t *rep,char const *_tag,int indent);

ssize_t foo_t_write_xml_2io (P_t *pads,Sfio_t *io,foo_t_pd *pd,foo_t *rep,char const *_tag,int indent);

char const *foo_t_tag2str (foo_t_tag which);

Perror_t foo_t_init (P_t *pads,foo_t *rep);

Perror_t foo_t_pd_init (P_t *pads,foo_t_pd *pd);

Perror_t foo_t_cleanup (P_t *pads,foo_t *rep);

Perror_t foo_t_pd_cleanup (P_t *pads,foo_t_pd *pd);

Perror_t foo_t_copy (P_t *pads,foo_t *rep_dst,foo_t *rep_src);

Perror_t foo_t_pd_copy (P_t *pads,foo_t_pd *pd_dst,foo_t_pd *pd_src);

void foo_t_m_init (P_t *pads,foo_t_m *mask,Pbase_m baseMask);

Perror_t foo_t_m_rec_init (P_t *pads,foo_t_m *mask,Pbase_m baseMask);

Perror_t foo_t_read (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

int foo_t_verify (P_t *pads,foo_t *rep);

int foo_t_genPD (P_t *pads,foo_t *rep,foo_t_pd *pd);
typedef struct foo_t_acc_s foo_t_acc;
struct foo_t_acc_s {
  Pint32_acc tag;
  Pchar_acc some_foo_t;
};

Perror_t foo_t_acc_init (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_reset (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_cleanup (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_add (P_t *pads,foo_t_acc *acc,foo_t_pd *pd,foo_t *rep);

Perror_t foo_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_t_acc *acc);

Perror_t foo_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_t_acc *acc);

Perror_t foo_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_t_acc *acc);

ssize_t foo_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);
typedef struct bar_s bar;
typedef struct bar_m_s bar_m;
typedef struct bar_pd_s bar_pd;
typedef struct bar_ro_params_t_s bar_ro_params_t;
struct bar_m_s {
  foo_t_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct bar_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  foo_t_pd *elts;
  RBuf_t *_internal;
};
struct bar_s {
  Puint32 length;
  foo_t *elts;
  RBuf_t *_internal;
};
struct bar_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t bar_init (P_t *pads,bar *rep);

Perror_t bar_pd_init (P_t *pads,bar_pd *pd);

Perror_t bar_cleanup (P_t *pads,bar *rep);

Perror_t bar_pd_cleanup (P_t *pads,bar_pd *pd);

Perror_t bar_copy (P_t *pads,bar *rep_dst,bar *rep_src);

Perror_t bar_pd_copy (P_t *pads,bar_pd *pd_dst,bar_pd *pd_src);

void bar_m_init (P_t *pads,bar_m *mask,Pbase_m baseMask);

Perror_t bar_m_rec_init (P_t *pads,bar_m *mask,Pbase_m baseMask);

void bar_ro_params_init (bar_ro_params_t *params);

Pread_res_t bar_final_checks (P_t *pads,bar_m *m,bar_pd *pd,bar *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t bar_read_one_init (P_t *pads,bar_m *m,bar_pd *pd,bar *rep,Ploc_t *loc_ptr);

Pread_res_t bar_read_one (P_t *pads,bar_m *m,bar_pd *pd,bar *rep,Ploc_t *loc_ptr,foo_t_pd *elt_pd,foo_t *elt_rep);

Perror_t bar_read (P_t *pads,bar_m *m,bar_pd *pd,bar *rep);

Pread_res_t bar_reread_one (P_t *pads,bar_m *m,bar_pd *pd,bar *rep,Ploc_t *loc_ptr,foo_t_pd *elt_pd,foo_t *elt_rep,int notFirstElt);

int bar_verify (P_t *pads,bar *rep);

int bar_genPD (P_t *pads,bar *rep,bar_pd *pd);
typedef struct bar_acc_s bar_acc;
struct bar_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  foo_t_acc compoundLevel;		/* Accumulator for all array elements */
  foo_t_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t bar_acc_init (P_t *pads,bar_acc *acc);

Perror_t bar_acc_reset (P_t *pads,bar_acc *acc);

Perror_t bar_acc_cleanup (P_t *pads,bar_acc *acc);

Perror_t bar_acc_add (P_t *pads,bar_acc *acc,bar_pd *pd,bar *rep);

Perror_t bar_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,bar_acc *acc);

Perror_t bar_acc_report (P_t *pads,char const *prefix,char const *what,int nst,bar_acc *acc);

Perror_t bar_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,bar_acc *acc);

ssize_t bar_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,bar_pd *pd,bar *rep);

ssize_t bar_write2io (P_t *pads,Sfio_t *io,bar_pd *pd,bar *rep);

ssize_t bar_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,bar_pd *pd,bar *rep,char const *_tag,int indent);

ssize_t bar_write_xml_2io (P_t *pads,Sfio_t *io,bar_pd *pd,bar *rep,char const *_tag,int indent);

ssize_t bar_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);

ssize_t bar_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);

ssize_t bar_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,bar_m *m,bar_pd *pd,bar *rep);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  bar_m b;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  bar_pd b;
};
struct entry_s {
  bar b;
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
  bar_acc b;
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
typedef struct source_s source;
typedef struct source_m_s source_m;
typedef struct source_pd_s source_pd;
typedef struct source_ro_params_t_s source_ro_params_t;
struct source_m_s {
  entry_m element;		/* per-element */
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
  entry_pd *elts;
  RBuf_t *_internal;
};
struct source_s {
  Puint32 length;
  entry *elts;
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

Pread_res_t source_read_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,entry_pd *elt_pd,entry *elt_rep);

Perror_t source_read (P_t *pads,source_m *m,source_pd *pd,source *rep);

Pread_res_t source_reread_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,entry_pd *elt_pd,entry *elt_rep,int notFirstElt);

int source_verify (P_t *pads,source *rep);

int source_genPD (P_t *pads,source *rep,source_pd *pd);
typedef struct source_acc_s source_acc;
struct source_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  entry_acc compoundLevel;		/* Accumulator for all array elements */
  entry_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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

#endif /*  __ARRAY_ADVANCE__H__  */
