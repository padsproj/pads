#ifndef __ARRAY_ENDED__H__
#define __ARRAY_ENDED__H__
#include "pads.h"
typedef Pint32 even;
typedef struct even_m_s even_m;
typedef Pbase_pd even_pd;
struct even_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t even_init (P_t *pads,even *rep);

Perror_t even_pd_init (P_t *pads,even_pd *pd);

Perror_t even_cleanup (P_t *pads,even *rep);

Perror_t even_pd_cleanup (P_t *pads,even_pd *pd);

Perror_t even_copy (P_t *pads,even *rep_dst,even *rep_src);

Perror_t even_pd_copy (P_t *pads,even_pd *pd_dst,even_pd *pd_src);

void even_m_init (P_t *pads,even_m *mask,Pbase_m baseMask);

Perror_t even_m_rec_init (P_t *pads,even_m *mask,Pbase_m baseMask);

Perror_t even_read (P_t *pads,even_m *m,even_pd *pd,even *rep);

int even_verify (P_t *pads,even *rep);

int even_genPD (P_t *pads,even *rep,even_pd *pd);
typedef Pint32_acc even_acc;

Perror_t even_acc_init (P_t *pads,even_acc *acc);

Perror_t even_acc_reset (P_t *pads,even_acc *acc);

Perror_t even_acc_cleanup (P_t *pads,even_acc *acc);

Perror_t even_acc_add (P_t *pads,even_acc *acc,even_pd *pd,even *rep);

Perror_t even_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,even_acc *acc);

Perror_t even_acc_report (P_t *pads,char const *prefix,char const *what,int nst,even_acc *acc);

Perror_t even_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,even_acc *acc);

ssize_t even_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,even_pd *pd,even *rep);

ssize_t even_write2io (P_t *pads,Sfio_t *io,even_pd *pd,even *rep);

ssize_t even_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,even_pd *pd,even *rep,char const *_tag,int indent);

ssize_t even_write_xml_2io (P_t *pads,Sfio_t *io,even_pd *pd,even *rep,char const *_tag,int indent);

ssize_t even_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,even_m *m,even_pd *pd,even *rep);

ssize_t even_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,even_m *m,even_pd *pd,even *rep);

ssize_t even_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,even_m *m,even_pd *pd,even *rep);
typedef Pint32 odd;
typedef struct odd_m_s odd_m;
typedef Pbase_pd odd_pd;
struct odd_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t odd_init (P_t *pads,odd *rep);

Perror_t odd_pd_init (P_t *pads,odd_pd *pd);

Perror_t odd_cleanup (P_t *pads,odd *rep);

Perror_t odd_pd_cleanup (P_t *pads,odd_pd *pd);

Perror_t odd_copy (P_t *pads,odd *rep_dst,odd *rep_src);

Perror_t odd_pd_copy (P_t *pads,odd_pd *pd_dst,odd_pd *pd_src);

void odd_m_init (P_t *pads,odd_m *mask,Pbase_m baseMask);

Perror_t odd_m_rec_init (P_t *pads,odd_m *mask,Pbase_m baseMask);

Perror_t odd_read (P_t *pads,odd_m *m,odd_pd *pd,odd *rep);

int odd_verify (P_t *pads,odd *rep);

int odd_genPD (P_t *pads,odd *rep,odd_pd *pd);
typedef Pint32_acc odd_acc;

Perror_t odd_acc_init (P_t *pads,odd_acc *acc);

Perror_t odd_acc_reset (P_t *pads,odd_acc *acc);

Perror_t odd_acc_cleanup (P_t *pads,odd_acc *acc);

Perror_t odd_acc_add (P_t *pads,odd_acc *acc,odd_pd *pd,odd *rep);

Perror_t odd_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,odd_acc *acc);

Perror_t odd_acc_report (P_t *pads,char const *prefix,char const *what,int nst,odd_acc *acc);

Perror_t odd_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,odd_acc *acc);

ssize_t odd_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,odd_pd *pd,odd *rep);

ssize_t odd_write2io (P_t *pads,Sfio_t *io,odd_pd *pd,odd *rep);

ssize_t odd_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,odd_pd *pd,odd *rep,char const *_tag,int indent);

ssize_t odd_write_xml_2io (P_t *pads,Sfio_t *io,odd_pd *pd,odd *rep,char const *_tag,int indent);

ssize_t odd_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,odd_m *m,odd_pd *pd,odd *rep);

ssize_t odd_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,odd_m *m,odd_pd *pd,odd *rep);

ssize_t odd_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,odd_m *m,odd_pd *pd,odd *rep);
typedef struct eseq_t_s eseq_t;
typedef struct eseq_t_m_s eseq_t_m;
typedef struct eseq_t_pd_s eseq_t_pd;
typedef struct eseq_t_ro_params_t_s eseq_t_ro_params_t;
struct eseq_t_m_s {
  even_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct eseq_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  even_pd *elts;
  RBuf_t *_internal;
};
struct eseq_t_s {
  Puint32 length;
  even *elts;
  RBuf_t *_internal;
};
struct eseq_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Pregexp_t separator_regexp;
  Pregexp_t *separator_regexp_ptr;		/* pointer to separator_regexp */
};

Perror_t eseq_t_init (P_t *pads,eseq_t *rep);

Perror_t eseq_t_pd_init (P_t *pads,eseq_t_pd *pd);

Perror_t eseq_t_cleanup (P_t *pads,eseq_t *rep);

Perror_t eseq_t_pd_cleanup (P_t *pads,eseq_t_pd *pd);

Perror_t eseq_t_copy (P_t *pads,eseq_t *rep_dst,eseq_t *rep_src);

Perror_t eseq_t_pd_copy (P_t *pads,eseq_t_pd *pd_dst,eseq_t_pd *pd_src);

void eseq_t_m_init (P_t *pads,eseq_t_m *mask,Pbase_m baseMask);

Perror_t eseq_t_m_rec_init (P_t *pads,eseq_t_m *mask,Pbase_m baseMask);

void eseq_t_ro_params_init (eseq_t_ro_params_t *params);

Pread_res_t eseq_t_final_checks (P_t *pads,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,int consume);

Pread_res_t eseq_t_read_one_init (P_t *pads,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr);

Pread_res_t eseq_t_read_one (P_t *pads,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep,Ploc_t *loc_ptr,even_pd *elt_pd,even *elt_rep,Pregexp_t *separator_regexp_ptr);

Perror_t eseq_t_read (P_t *pads,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep);

Pread_res_t eseq_t_reread_one (Pregexp_t *separator_regexp_ptr,P_t *pads,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep,Ploc_t *loc_ptr,even_pd *elt_pd,even *elt_rep,int notFirstElt);

int eseq_t_verify (P_t *pads,eseq_t *rep);

int eseq_t_genPD (P_t *pads,eseq_t *rep,eseq_t_pd *pd);
typedef struct eseq_t_acc_s eseq_t_acc;
struct eseq_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  even_acc compoundLevel;		/* Accumulator for all array elements */
  even_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t eseq_t_acc_init (P_t *pads,eseq_t_acc *acc);

Perror_t eseq_t_acc_reset (P_t *pads,eseq_t_acc *acc);

Perror_t eseq_t_acc_cleanup (P_t *pads,eseq_t_acc *acc);

Perror_t eseq_t_acc_add (P_t *pads,eseq_t_acc *acc,eseq_t_pd *pd,eseq_t *rep);

Perror_t eseq_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,eseq_t_acc *acc);

Perror_t eseq_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,eseq_t_acc *acc);

Perror_t eseq_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,eseq_t_acc *acc);

ssize_t eseq_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,eseq_t_pd *pd,eseq_t *rep);

ssize_t eseq_t_write2io (P_t *pads,Sfio_t *io,eseq_t_pd *pd,eseq_t *rep);

ssize_t eseq_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,eseq_t_pd *pd,eseq_t *rep,char const *_tag,int indent);

ssize_t eseq_t_write_xml_2io (P_t *pads,Sfio_t *io,eseq_t_pd *pd,eseq_t *rep,char const *_tag,int indent);

ssize_t eseq_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep);

ssize_t eseq_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep);

ssize_t eseq_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,eseq_t_m *m,eseq_t_pd *pd,eseq_t *rep);
typedef struct oseq_t_s oseq_t;
typedef struct oseq_t_m_s oseq_t_m;
typedef struct oseq_t_pd_s oseq_t_pd;
typedef struct oseq_t_ro_params_t_s oseq_t_ro_params_t;
struct oseq_t_m_s {
  odd_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct oseq_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  odd_pd *elts;
  RBuf_t *_internal;
};
struct oseq_t_s {
  Puint32 length;
  odd *elts;
  RBuf_t *_internal;
};
struct oseq_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  Pregexp_t separator_regexp;
  Pregexp_t *separator_regexp_ptr;		/* pointer to separator_regexp */
  Pregexp_t terminator_regexp;
  Pregexp_t *terminator_regexp_ptr;		/* pointer to terminator_regexp */
};

Perror_t oseq_t_init (P_t *pads,oseq_t *rep);

Perror_t oseq_t_pd_init (P_t *pads,oseq_t_pd *pd);

Perror_t oseq_t_cleanup (P_t *pads,oseq_t *rep);

Perror_t oseq_t_pd_cleanup (P_t *pads,oseq_t_pd *pd);

Perror_t oseq_t_copy (P_t *pads,oseq_t *rep_dst,oseq_t *rep_src);

Perror_t oseq_t_pd_copy (P_t *pads,oseq_t_pd *pd_dst,oseq_t_pd *pd_src);

void oseq_t_m_init (P_t *pads,oseq_t_m *mask,Pbase_m baseMask);

Perror_t oseq_t_m_rec_init (P_t *pads,oseq_t_m *mask,Pbase_m baseMask);

void oseq_t_ro_params_init (oseq_t_ro_params_t *params);

Pread_res_t oseq_t_final_checks (P_t *pads,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr,int foundTerm,int consume);

Pread_res_t oseq_t_read_one_init (P_t *pads,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep,Ploc_t *loc_ptr,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr);

Pread_res_t oseq_t_read_one (P_t *pads,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep,Ploc_t *loc_ptr,odd_pd *elt_pd,odd *elt_rep,Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr);

Perror_t oseq_t_read (P_t *pads,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep);

Pread_res_t oseq_t_reread_one (Pregexp_t *separator_regexp_ptr,Pregexp_t *terminator_regexp_ptr,P_t *pads,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep,Ploc_t *loc_ptr,odd_pd *elt_pd,odd *elt_rep,int notFirstElt);

int oseq_t_verify (P_t *pads,oseq_t *rep);

int oseq_t_genPD (P_t *pads,oseq_t *rep,oseq_t_pd *pd);
typedef struct oseq_t_acc_s oseq_t_acc;
struct oseq_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  odd_acc compoundLevel;		/* Accumulator for all array elements */
  odd_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t oseq_t_acc_init (P_t *pads,oseq_t_acc *acc);

Perror_t oseq_t_acc_reset (P_t *pads,oseq_t_acc *acc);

Perror_t oseq_t_acc_cleanup (P_t *pads,oseq_t_acc *acc);

Perror_t oseq_t_acc_add (P_t *pads,oseq_t_acc *acc,oseq_t_pd *pd,oseq_t *rep);

Perror_t oseq_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,oseq_t_acc *acc);

Perror_t oseq_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,oseq_t_acc *acc);

Perror_t oseq_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,oseq_t_acc *acc);

ssize_t oseq_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,oseq_t_pd *pd,oseq_t *rep);

ssize_t oseq_t_write2io (P_t *pads,Sfio_t *io,oseq_t_pd *pd,oseq_t *rep);

ssize_t oseq_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,oseq_t_pd *pd,oseq_t *rep,char const *_tag,int indent);

ssize_t oseq_t_write_xml_2io (P_t *pads,Sfio_t *io,oseq_t_pd *pd,oseq_t *rep,char const *_tag,int indent);

ssize_t oseq_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep);

ssize_t oseq_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep);

ssize_t oseq_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,oseq_t_m *m,oseq_t_pd *pd,oseq_t *rep);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  eseq_t_m evens;		/* nested constraints */
  oseq_t_m odds;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  eseq_t_pd evens;
  oseq_t_pd odds;
};
struct entry_s {
  eseq_t evens;
  oseq_t odds;
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
  eseq_t_acc evens;
  oseq_t_acc odds;
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

#endif /*  __ARRAY_ENDED__H__  */
