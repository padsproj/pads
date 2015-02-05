#ifndef __ARRAY_ENDED2__H__
#define __ARRAY_ENDED2__H__
#include "pads.h"

int isDone (Pint32 value,Pbase_pd p,int *consume);
typedef struct fseq_t_s fseq_t;
typedef struct fseq_t_m_s fseq_t_m;
typedef struct fseq_t_pd_s fseq_t_pd;
typedef struct fseq_t_ro_params_t_s fseq_t_ro_params_t;
struct fseq_t_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct fseq_t_pd_s {
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
struct fseq_t_s {
  Puint32 length;
  Pint32 *elts;
  RBuf_t *_internal;
};
struct fseq_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Pregexp_t separator_regexp;
  Pregexp_t *separator_regexp_ptr;		/* pointer to separator_regexp */
};

Perror_t fseq_t_init (P_t *pads,fseq_t *rep);

Perror_t fseq_t_pd_init (P_t *pads,fseq_t_pd *pd);

Perror_t fseq_t_cleanup (P_t *pads,fseq_t *rep);

Perror_t fseq_t_pd_cleanup (P_t *pads,fseq_t_pd *pd);

Perror_t fseq_t_copy (P_t *pads,fseq_t *rep_dst,fseq_t *rep_src);

Perror_t fseq_t_pd_copy (P_t *pads,fseq_t_pd *pd_dst,fseq_t_pd *pd_src);

void fseq_t_m_init (P_t *pads,fseq_t_m *mask,Pbase_m baseMask);

Perror_t fseq_t_m_rec_init (P_t *pads,fseq_t_m *mask,Pbase_m baseMask);

void fseq_t_ro_params_init (fseq_t_ro_params_t *params);

Pread_res_t fseq_t_final_checks (P_t *pads,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,int consume);

Pread_res_t fseq_t_read_one_init (P_t *pads,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr);

Pread_res_t fseq_t_read_one (P_t *pads,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,Pregexp_t *separator_regexp_ptr);

Perror_t fseq_t_read (P_t *pads,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep);

Pread_res_t fseq_t_reread_one (Pregexp_t *separator_regexp_ptr,P_t *pads,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,int notFirstElt);

int fseq_t_verify (P_t *pads,fseq_t *rep);

int fseq_t_genPD (P_t *pads,fseq_t *rep,fseq_t_pd *pd);
typedef struct fseq_t_acc_s fseq_t_acc;
struct fseq_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Pint32_acc compoundLevel;		/* Accumulator for all array elements */
  Pint32_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t fseq_t_acc_init (P_t *pads,fseq_t_acc *acc);

Perror_t fseq_t_acc_reset (P_t *pads,fseq_t_acc *acc);

Perror_t fseq_t_acc_cleanup (P_t *pads,fseq_t_acc *acc);

Perror_t fseq_t_acc_add (P_t *pads,fseq_t_acc *acc,fseq_t_pd *pd,fseq_t *rep);

Perror_t fseq_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,fseq_t_acc *acc);

Perror_t fseq_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,fseq_t_acc *acc);

Perror_t fseq_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,fseq_t_acc *acc);

ssize_t fseq_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,fseq_t_pd *pd,fseq_t *rep);

ssize_t fseq_t_write2io (P_t *pads,Sfio_t *io,fseq_t_pd *pd,fseq_t *rep);

ssize_t fseq_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,fseq_t_pd *pd,fseq_t *rep,char const *_tag,int indent);

ssize_t fseq_t_write_xml_2io (P_t *pads,Sfio_t *io,fseq_t_pd *pd,fseq_t *rep,char const *_tag,int indent);

ssize_t fseq_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep);

ssize_t fseq_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep);

ssize_t fseq_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,fseq_t_m *m,fseq_t_pd *pd,fseq_t *rep);
typedef struct sseq_t_s sseq_t;
typedef struct sseq_t_m_s sseq_t_m;
typedef struct sseq_t_pd_s sseq_t_pd;
typedef struct sseq_t_ro_params_t_s sseq_t_ro_params_t;
struct sseq_t_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct sseq_t_pd_s {
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
struct sseq_t_s {
  Puint32 length;
  Pint32 *elts;
  RBuf_t *_internal;
};
struct sseq_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Pregexp_t separator_regexp;
  Pregexp_t *separator_regexp_ptr;		/* pointer to separator_regexp */
  Pregexp_t terminator_regexp;
  Pregexp_t *terminator_regexp_ptr;		/* pointer to terminator_regexp */
};

Perror_t sseq_t_init (P_t *pads,sseq_t *rep);

Perror_t sseq_t_pd_init (P_t *pads,sseq_t_pd *pd);

Perror_t sseq_t_cleanup (P_t *pads,sseq_t *rep);

Perror_t sseq_t_pd_cleanup (P_t *pads,sseq_t_pd *pd);

Perror_t sseq_t_copy (P_t *pads,sseq_t *rep_dst,sseq_t *rep_src);

Perror_t sseq_t_pd_copy (P_t *pads,sseq_t_pd *pd_dst,sseq_t_pd *pd_src);

void sseq_t_m_init (P_t *pads,sseq_t_m *mask,Pbase_m baseMask);

Perror_t sseq_t_m_rec_init (P_t *pads,sseq_t_m *mask,Pbase_m baseMask);

void sseq_t_ro_params_init (sseq_t_ro_params_t *params);

Pread_res_t sseq_t_final_checks (P_t *pads,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr,int foundTerm,int consume);

Pread_res_t sseq_t_read_one_init (P_t *pads,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr);

Pread_res_t sseq_t_read_one (P_t *pads,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr);

Perror_t sseq_t_read (P_t *pads,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep);

Pread_res_t sseq_t_reread_one (Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr,P_t *pads,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,int notFirstElt);

int sseq_t_verify (P_t *pads,sseq_t *rep);

int sseq_t_genPD (P_t *pads,sseq_t *rep,sseq_t_pd *pd);
typedef struct sseq_t_acc_s sseq_t_acc;
struct sseq_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Pint32_acc compoundLevel;		/* Accumulator for all array elements */
  Pint32_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t sseq_t_acc_init (P_t *pads,sseq_t_acc *acc);

Perror_t sseq_t_acc_reset (P_t *pads,sseq_t_acc *acc);

Perror_t sseq_t_acc_cleanup (P_t *pads,sseq_t_acc *acc);

Perror_t sseq_t_acc_add (P_t *pads,sseq_t_acc *acc,sseq_t_pd *pd,sseq_t *rep);

Perror_t sseq_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,sseq_t_acc *acc);

Perror_t sseq_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,sseq_t_acc *acc);

Perror_t sseq_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,sseq_t_acc *acc);

ssize_t sseq_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sseq_t_pd *pd,sseq_t *rep);

ssize_t sseq_t_write2io (P_t *pads,Sfio_t *io,sseq_t_pd *pd,sseq_t *rep);

ssize_t sseq_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sseq_t_pd *pd,sseq_t *rep,char const *_tag,int indent);

ssize_t sseq_t_write_xml_2io (P_t *pads,Sfio_t *io,sseq_t_pd *pd,sseq_t *rep,char const *_tag,int indent);

ssize_t sseq_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep);

ssize_t sseq_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep);

ssize_t sseq_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,sseq_t_m *m,sseq_t_pd *pd,sseq_t *rep);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  fseq_t_m first;		/* nested constraints */
  sseq_t_m second;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  fseq_t_pd first;
  sseq_t_pd second;
};
struct entry_s {
  fseq_t first;
  sseq_t second;
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
  fseq_t_acc first;
  sseq_t_acc second;
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

#endif /*  __ARRAY_ENDED2__H__  */
