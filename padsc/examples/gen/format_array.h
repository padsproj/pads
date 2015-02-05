#ifndef __FORMAT_ARRAY__H__
#define __FORMAT_ARRAY__H__
#include "pads.h"
typedef struct foo_t_s foo_t;
typedef struct foo_t_m_s foo_t_m;
typedef struct foo_t_pd_s foo_t_pd;
typedef struct foo_t_ro_params_t_s foo_t_ro_params_t;
struct foo_t_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct foo_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  Pbase_pd *elts;
  RBuf_t *_internal;
};
struct foo_t_s {
  Puint32 length;
  Puint8 *elts;
  RBuf_t *_internal;
};
struct foo_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t foo_t_init (P_t *pads,foo_t *rep);

Perror_t foo_t_pd_init (P_t *pads,foo_t_pd *pd);

Perror_t foo_t_cleanup (P_t *pads,foo_t *rep);

Perror_t foo_t_pd_cleanup (P_t *pads,foo_t_pd *pd);

Perror_t foo_t_copy (P_t *pads,foo_t *rep_dst,foo_t *rep_src);

Perror_t foo_t_pd_copy (P_t *pads,foo_t_pd *pd_dst,foo_t_pd *pd_src);

void foo_t_m_init (P_t *pads,foo_t_m *mask,Pbase_m baseMask);

Perror_t foo_t_m_rec_init (P_t *pads,foo_t_m *mask,Pbase_m baseMask);

void foo_t_ro_params_init (foo_t_ro_params_t *params);

Pread_res_t foo_t_final_checks (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep,Ploc_t *loc_ptr,int foundTerm,int consume);

Pread_res_t foo_t_read_one_init (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep,Ploc_t *loc_ptr);

Pread_res_t foo_t_read_one (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep);

Perror_t foo_t_read (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

Pread_res_t foo_t_reread_one (P_t *pads,foo_t_m *m,foo_t_pd *pd,foo_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep,int notFirstElt);

int foo_t_verify (P_t *pads,foo_t *rep);

int foo_t_genPD (P_t *pads,foo_t *rep,foo_t_pd *pd);
typedef struct foo_t_acc_s foo_t_acc;
struct foo_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Puint8_acc compoundLevel;		/* Accumulator for all array elements */
  Puint8_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t foo_t_acc_init (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_reset (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_cleanup (P_t *pads,foo_t_acc *acc);

Perror_t foo_t_acc_add (P_t *pads,foo_t_acc *acc,foo_t_pd *pd,foo_t *rep);

Perror_t foo_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,foo_t_acc *acc);

Perror_t foo_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,foo_t_acc *acc);

Perror_t foo_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,foo_t_acc *acc);

ssize_t foo_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_write2io (P_t *pads,Sfio_t *io,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,foo_t_pd *pd,foo_t *rep,char const *_tag,int indent);

ssize_t foo_t_write_xml_2io (P_t *pads,Sfio_t *io,foo_t_pd *pd,foo_t *rep,char const *_tag,int indent);

ssize_t foo_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);

ssize_t foo_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,foo_t_m *m,foo_t_pd *pd,foo_t *rep);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m i;		/* nested constraints */
  foo_t_m v_array_7;		/* nested constraints */
  Pbase_m slurp;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd i;
  foo_t_pd v_array_7;
  Pbase_pd slurp;
};
struct entry_t_s {
  Puint8 i;
  foo_t v_array_7;
  Pstring slurp;
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
  foo_t_acc v_array_7;
  Pstring_acc slurp;
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

#endif /*  __FORMAT_ARRAY__H__  */
