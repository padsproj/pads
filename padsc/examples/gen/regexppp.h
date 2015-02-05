#ifndef __REGEXPPP__H__
#define __REGEXPPP__H__
#include "pads.h"
typedef struct Array_4747_s Array_4747;
typedef struct Array_4747_m_s Array_4747_m;
typedef struct Array_4747_pd_s Array_4747_pd;
typedef struct Array_4747_ro_params_t_s Array_4747_ro_params_t;
struct Array_4747_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct Array_4747_pd_s {
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
struct Array_4747_s {
  Puint32 length;
  Pint32 *elts;
  RBuf_t *_internal;
};
struct Array_4747_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Pregexp_t separator_regexp;
  Pregexp_t *separator_regexp_ptr;		/* pointer to separator_regexp */
};

Perror_t Array_4747_init (P_t *pads,Array_4747 *rep);

Perror_t Array_4747_pd_init (P_t *pads,Array_4747_pd *pd);

Perror_t Array_4747_cleanup (P_t *pads,Array_4747 *rep);

Perror_t Array_4747_pd_cleanup (P_t *pads,Array_4747_pd *pd);

Perror_t Array_4747_copy (P_t *pads,Array_4747 *rep_dst,Array_4747 *rep_src);

Perror_t Array_4747_pd_copy (P_t *pads,Array_4747_pd *pd_dst,Array_4747_pd *pd_src);

void Array_4747_m_init (P_t *pads,Array_4747_m *mask,Pbase_m baseMask);

Perror_t Array_4747_m_rec_init (P_t *pads,Array_4747_m *mask,Pbase_m baseMask);

void Array_4747_ro_params_init (Array_4747_ro_params_t *params);

Pread_res_t Array_4747_final_checks (P_t *pads,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,int consume);

Pread_res_t Array_4747_read_one_init (P_t *pads,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr);

Pread_res_t Array_4747_read_one (P_t *pads,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,Pregexp_t *separator_regexp_ptr);

Perror_t Array_4747_read (P_t *pads,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep);

Pread_res_t Array_4747_reread_one (Pregexp_t *separator_regexp_ptr,P_t *pads,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,int notFirstElt);

int Array_4747_verify (P_t *pads,Array_4747 *rep);

int Array_4747_genPD (P_t *pads,Array_4747 *rep,Array_4747_pd *pd);
typedef struct Array_4747_acc_s Array_4747_acc;
struct Array_4747_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Pint32_acc compoundLevel;		/* Accumulator for all array elements */
  Pint32_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t Array_4747_acc_init (P_t *pads,Array_4747_acc *acc);

Perror_t Array_4747_acc_reset (P_t *pads,Array_4747_acc *acc);

Perror_t Array_4747_acc_cleanup (P_t *pads,Array_4747_acc *acc);

Perror_t Array_4747_acc_add (P_t *pads,Array_4747_acc *acc,Array_4747_pd *pd,Array_4747 *rep);

Perror_t Array_4747_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,Array_4747_acc *acc);

Perror_t Array_4747_acc_report (P_t *pads,char const *prefix,char const *what,int nst,Array_4747_acc *acc);

Perror_t Array_4747_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,Array_4747_acc *acc);

ssize_t Array_4747_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Array_4747_pd *pd,Array_4747 *rep);

ssize_t Array_4747_write2io (P_t *pads,Sfio_t *io,Array_4747_pd *pd,Array_4747 *rep);

ssize_t Array_4747_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Array_4747_pd *pd,Array_4747 *rep,char const *_tag,int indent);

ssize_t Array_4747_write_xml_2io (P_t *pads,Sfio_t *io,Array_4747_pd *pd,Array_4747 *rep,char const *_tag,int indent);

ssize_t Array_4747_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep);

ssize_t Array_4747_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep);

ssize_t Array_4747_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,Array_4747_m *m,Array_4747_pd *pd,Array_4747 *rep);

void P_lib_init ();

#endif /*  __REGEXPPP__H__  */
