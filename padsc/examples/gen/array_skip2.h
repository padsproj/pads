#ifndef __ARRAY_SKIP2__H__
#define __ARRAY_SKIP2__H__
#include "pads.h"
typedef struct seq_t_s seq_t;
typedef struct seq_t_m_s seq_t_m;
typedef struct seq_t_pd_s seq_t_pd;
typedef struct seq_t_ro_params_t_s seq_t_ro_params_t;
struct seq_t_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct seq_t_pd_s {
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
struct seq_t_s {
  Puint32 length;
  Pint32 *elts;
  RBuf_t *_internal;
};
struct seq_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t seq_t_init (P_t *pads,seq_t *rep);

Perror_t seq_t_pd_init (P_t *pads,seq_t_pd *pd);

Perror_t seq_t_cleanup (P_t *pads,seq_t *rep);

Perror_t seq_t_pd_cleanup (P_t *pads,seq_t_pd *pd);

Perror_t seq_t_copy (P_t *pads,seq_t *rep_dst,seq_t *rep_src);

Perror_t seq_t_pd_copy (P_t *pads,seq_t_pd *pd_dst,seq_t_pd *pd_src);

void seq_t_m_init (P_t *pads,seq_t_m *mask,Pbase_m baseMask);

Perror_t seq_t_m_rec_init (P_t *pads,seq_t_m *mask,Pbase_m baseMask);

void seq_t_ro_params_init (seq_t_ro_params_t *params);

Pread_res_t seq_t_final_checks (P_t *pads,seq_t_m *m,seq_t_pd *pd,seq_t *rep,Ploc_t *loc_ptr,int foundTerm,int consume);

Pread_res_t seq_t_read_one_init (P_t *pads,seq_t_m *m,seq_t_pd *pd,seq_t *rep,Ploc_t *loc_ptr);

Pread_res_t seq_t_read_one (P_t *pads,seq_t_m *m,seq_t_pd *pd,seq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep);

Perror_t seq_t_read (P_t *pads,seq_t_m *m,seq_t_pd *pd,seq_t *rep);

Pread_res_t seq_t_reread_one (P_t *pads,seq_t_m *m,seq_t_pd *pd,seq_t *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,int notFirstElt);

int seq_t_verify (P_t *pads,seq_t *rep);

int seq_t_genPD (P_t *pads,seq_t *rep,seq_t_pd *pd);
typedef struct seq_t_acc_s seq_t_acc;
struct seq_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Pint32_acc compoundLevel;		/* Accumulator for all array elements */
  Pint32_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t seq_t_acc_init (P_t *pads,seq_t_acc *acc);

Perror_t seq_t_acc_reset (P_t *pads,seq_t_acc *acc);

Perror_t seq_t_acc_cleanup (P_t *pads,seq_t_acc *acc);

Perror_t seq_t_acc_add (P_t *pads,seq_t_acc *acc,seq_t_pd *pd,seq_t *rep);

Perror_t seq_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,seq_t_acc *acc);

Perror_t seq_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,seq_t_acc *acc);

Perror_t seq_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,seq_t_acc *acc);

ssize_t seq_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,seq_t_pd *pd,seq_t *rep);

ssize_t seq_t_write2io (P_t *pads,Sfio_t *io,seq_t_pd *pd,seq_t *rep);

ssize_t seq_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,seq_t_pd *pd,seq_t *rep,char const *_tag,int indent);

ssize_t seq_t_write_xml_2io (P_t *pads,Sfio_t *io,seq_t_pd *pd,seq_t *rep,char const *_tag,int indent);

ssize_t seq_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,seq_t_m *m,seq_t_pd *pd,seq_t *rep);

ssize_t seq_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,seq_t_m *m,seq_t_pd *pd,seq_t *rep);

ssize_t seq_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,seq_t_m *m,seq_t_pd *pd,seq_t *rep);
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  seq_t_m seq;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  seq_t_pd seq;
};
struct entry_s {
  seq_t seq;
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
  seq_t_acc seq;
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

#endif /*  __ARRAY_SKIP2__H__  */
