#ifndef __PENDIAN__H__
#define __PENDIAN__H__
#include "pads.h"
typedef struct data_header_s data_header;
typedef struct data_header_m_s data_header_m;
typedef struct data_header_pd_s data_header_pd;
struct data_header_m_s {
  Pbase_m compoundLevel;
  Pbase_m recs;		/* nested constraints */
  Pbase_m recs_con;		/* struct constraints */
};
struct data_header_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd recs;
};
struct data_header_s {
  Pint32 recs;		/* recs < 1000&& */
};

Perror_t data_header_init (P_t *pads,data_header *rep);

Perror_t data_header_pd_init (P_t *pads,data_header_pd *pd);

Perror_t data_header_cleanup (P_t *pads,data_header *rep);

Perror_t data_header_pd_cleanup (P_t *pads,data_header_pd *pd);

Perror_t data_header_copy (P_t *pads,data_header *rep_dst,data_header *rep_src);

Perror_t data_header_pd_copy (P_t *pads,data_header_pd *pd_dst,data_header_pd *pd_src);

void data_header_m_init (P_t *pads,data_header_m *mask,Pbase_m baseMask);

Perror_t data_header_m_rec_init (P_t *pads,data_header_m *mask,Pbase_m baseMask);

Perror_t data_header_read (P_t *pads,data_header_m *m,data_header_pd *pd,data_header *rep);

int data_header_verify (P_t *pads,data_header *rep);

int data_header_genPD (P_t *pads,data_header *rep,data_header_pd *pd);
typedef struct data_header_acc_s data_header_acc;
struct data_header_acc_s {
  Puint32_acc nerr;
  Pint32_acc recs;		/* recs < 1000&& */
};

Perror_t data_header_acc_init (P_t *pads,data_header_acc *acc);

Perror_t data_header_acc_reset (P_t *pads,data_header_acc *acc);

Perror_t data_header_acc_cleanup (P_t *pads,data_header_acc *acc);

Perror_t data_header_acc_add (P_t *pads,data_header_acc *acc,data_header_pd *pd,data_header *rep);

Perror_t data_header_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,data_header_acc *acc);

Perror_t data_header_acc_report (P_t *pads,char const *prefix,char const *what,int nst,data_header_acc *acc);

Perror_t data_header_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,data_header_acc *acc);

ssize_t data_header_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_header_pd *pd,data_header *rep);

ssize_t data_header_write2io (P_t *pads,Sfio_t *io,data_header_pd *pd,data_header *rep);

ssize_t data_header_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_header_pd *pd,data_header *rep,char const *_tag,int indent);

ssize_t data_header_write_xml_2io (P_t *pads,Sfio_t *io,data_header_pd *pd,data_header *rep,char const *_tag,int indent);

ssize_t data_header_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_header_m *m,data_header_pd *pd,data_header *rep);

ssize_t data_header_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_header_m *m,data_header_pd *pd,data_header *rep);

ssize_t data_header_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,data_header_m *m,data_header_pd *pd,data_header *rep);
typedef struct data_elt_s data_elt;
typedef struct data_elt_m_s data_elt_m;
typedef struct data_elt_pd_s data_elt_pd;
struct data_elt_m_s {
  Pbase_m compoundLevel;
  Pbase_m x;		/* nested constraints */
};
struct data_elt_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd x;
};
struct data_elt_s {
  Pint32 x;
};

Perror_t data_elt_init (P_t *pads,data_elt *rep);

Perror_t data_elt_pd_init (P_t *pads,data_elt_pd *pd);

Perror_t data_elt_cleanup (P_t *pads,data_elt *rep);

Perror_t data_elt_pd_cleanup (P_t *pads,data_elt_pd *pd);

Perror_t data_elt_copy (P_t *pads,data_elt *rep_dst,data_elt *rep_src);

Perror_t data_elt_pd_copy (P_t *pads,data_elt_pd *pd_dst,data_elt_pd *pd_src);

void data_elt_m_init (P_t *pads,data_elt_m *mask,Pbase_m baseMask);

Perror_t data_elt_m_rec_init (P_t *pads,data_elt_m *mask,Pbase_m baseMask);

Perror_t data_elt_read (P_t *pads,data_elt_m *m,data_elt_pd *pd,data_elt *rep);

int data_elt_verify (P_t *pads,data_elt *rep);

int data_elt_genPD (P_t *pads,data_elt *rep,data_elt_pd *pd);
typedef struct data_elt_acc_s data_elt_acc;
struct data_elt_acc_s {
  Puint32_acc nerr;
  Pint32_acc x;
};

Perror_t data_elt_acc_init (P_t *pads,data_elt_acc *acc);

Perror_t data_elt_acc_reset (P_t *pads,data_elt_acc *acc);

Perror_t data_elt_acc_cleanup (P_t *pads,data_elt_acc *acc);

Perror_t data_elt_acc_add (P_t *pads,data_elt_acc *acc,data_elt_pd *pd,data_elt *rep);

Perror_t data_elt_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,data_elt_acc *acc);

Perror_t data_elt_acc_report (P_t *pads,char const *prefix,char const *what,int nst,data_elt_acc *acc);

Perror_t data_elt_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,data_elt_acc *acc);

ssize_t data_elt_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_elt_pd *pd,data_elt *rep);

ssize_t data_elt_write2io (P_t *pads,Sfio_t *io,data_elt_pd *pd,data_elt *rep);

ssize_t data_elt_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_elt_pd *pd,data_elt *rep,char const *_tag,int indent);

ssize_t data_elt_write_xml_2io (P_t *pads,Sfio_t *io,data_elt_pd *pd,data_elt *rep,char const *_tag,int indent);

ssize_t data_elt_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_elt_m *m,data_elt_pd *pd,data_elt *rep);

ssize_t data_elt_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_elt_m *m,data_elt_pd *pd,data_elt *rep);

ssize_t data_elt_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,data_elt_m *m,data_elt_pd *pd,data_elt *rep);
typedef struct data_seq_s data_seq;
typedef struct data_seq_m_s data_seq_m;
typedef struct data_seq_pd_s data_seq_pd;
typedef struct data_seq_ro_params_t_s data_seq_ro_params_t;
struct data_seq_m_s {
  data_elt_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct data_seq_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  data_elt_pd *elts;
  RBuf_t *_internal;
};
struct data_seq_s {
  Puint32 length;
  data_elt *elts;
  RBuf_t *_internal;
};
struct data_seq_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  int recs;
};

Perror_t data_seq_init (P_t *pads,data_seq *rep);

Perror_t data_seq_pd_init (P_t *pads,data_seq_pd *pd);

Perror_t data_seq_cleanup (P_t *pads,data_seq *rep);

Perror_t data_seq_pd_cleanup (P_t *pads,data_seq_pd *pd);

Perror_t data_seq_copy (P_t *pads,data_seq *rep_dst,data_seq *rep_src);

Perror_t data_seq_pd_copy (P_t *pads,data_seq_pd *pd_dst,data_seq_pd *pd_src);

void data_seq_m_init (P_t *pads,data_seq_m *mask,Pbase_m baseMask);

Perror_t data_seq_m_rec_init (P_t *pads,data_seq_m *mask,Pbase_m baseMask);

void data_seq_ro_params_init (data_seq_ro_params_t *params,int recs);

Pread_res_t data_seq_final_checks (P_t *pads,data_seq_m *m,data_seq_pd *pd,data_seq *rep,Ploc_t *loc_ptr,int reachedLimit,int consume,int recs);

Pread_res_t data_seq_read_one_init (P_t *pads,data_seq_m *m,data_seq_pd *pd,data_seq *rep,Ploc_t *loc_ptr,int recs);

Pread_res_t data_seq_read_one (P_t *pads,data_seq_m *m,data_seq_pd *pd,data_seq *rep,Ploc_t *loc_ptr,data_elt_pd *elt_pd,data_elt *elt_rep,int recs);

Perror_t data_seq_read (P_t *pads,data_seq_m *m,data_seq_pd *pd,data_seq *rep,int recs);

Pread_res_t data_seq_reread_one (P_t *pads,data_seq_m *m,data_seq_pd *pd,data_seq *rep,Ploc_t *loc_ptr,data_elt_pd *elt_pd,data_elt *elt_rep,int notFirstElt,int recs);

int data_seq_verify (P_t *pads,data_seq *rep,int recs);

int data_seq_genPD (P_t *pads,data_seq *rep,data_seq_pd *pd,int recs);
typedef struct data_seq_acc_s data_seq_acc;
struct data_seq_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  data_elt_acc compoundLevel;		/* Accumulator for all array elements */
  data_elt_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t data_seq_acc_init (P_t *pads,data_seq_acc *acc);

Perror_t data_seq_acc_reset (P_t *pads,data_seq_acc *acc);

Perror_t data_seq_acc_cleanup (P_t *pads,data_seq_acc *acc);

Perror_t data_seq_acc_add (P_t *pads,data_seq_acc *acc,data_seq_pd *pd,data_seq *rep);

Perror_t data_seq_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,data_seq_acc *acc);

Perror_t data_seq_acc_report (P_t *pads,char const *prefix,char const *what,int nst,data_seq_acc *acc);

Perror_t data_seq_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,data_seq_acc *acc);

ssize_t data_seq_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_seq_pd *pd,data_seq *rep,int recs);

ssize_t data_seq_write2io (P_t *pads,Sfio_t *io,data_seq_pd *pd,data_seq *rep,int recs);

ssize_t data_seq_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_seq_pd *pd,data_seq *rep,char const *_tag,int indent,int recs);

ssize_t data_seq_write_xml_2io (P_t *pads,Sfio_t *io,data_seq_pd *pd,data_seq *rep,char const *_tag,int indent,int recs);

ssize_t data_seq_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_seq_m *m,data_seq_pd *pd,data_seq *rep,int recs);

ssize_t data_seq_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_seq_m *m,data_seq_pd *pd,data_seq *rep,int recs);

ssize_t data_seq_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,data_seq_m *m,data_seq_pd *pd,data_seq *rep,int recs);
typedef struct data_file_s data_file;
typedef struct data_file_m_s data_file_m;
typedef struct data_file_pd_s data_file_pd;
struct data_file_m_s {
  Pbase_m compoundLevel;
  data_header_m hdr;		/* nested constraints */
  data_seq_m seq;		/* nested constraints */
};
struct data_file_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  data_header_pd hdr;
  data_seq_pd seq;
};
struct data_file_s {
  data_header hdr;
  data_seq seq;
};

Perror_t data_file_init (P_t *pads,data_file *rep);

Perror_t data_file_pd_init (P_t *pads,data_file_pd *pd);

Perror_t data_file_cleanup (P_t *pads,data_file *rep);

Perror_t data_file_pd_cleanup (P_t *pads,data_file_pd *pd);

Perror_t data_file_copy (P_t *pads,data_file *rep_dst,data_file *rep_src);

Perror_t data_file_pd_copy (P_t *pads,data_file_pd *pd_dst,data_file_pd *pd_src);

void data_file_m_init (P_t *pads,data_file_m *mask,Pbase_m baseMask);

Perror_t data_file_m_rec_init (P_t *pads,data_file_m *mask,Pbase_m baseMask);

Perror_t data_file_read (P_t *pads,data_file_m *m,data_file_pd *pd,data_file *rep);

int data_file_verify (P_t *pads,data_file *rep);

int data_file_genPD (P_t *pads,data_file *rep,data_file_pd *pd);
typedef struct data_file_acc_s data_file_acc;
struct data_file_acc_s {
  Puint32_acc nerr;
  data_header_acc hdr;
  data_seq_acc seq;
};

Perror_t data_file_acc_init (P_t *pads,data_file_acc *acc);

Perror_t data_file_acc_reset (P_t *pads,data_file_acc *acc);

Perror_t data_file_acc_cleanup (P_t *pads,data_file_acc *acc);

Perror_t data_file_acc_add (P_t *pads,data_file_acc *acc,data_file_pd *pd,data_file *rep);

Perror_t data_file_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,data_file_acc *acc);

Perror_t data_file_acc_report (P_t *pads,char const *prefix,char const *what,int nst,data_file_acc *acc);

Perror_t data_file_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,data_file_acc *acc);

ssize_t data_file_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_file_pd *pd,data_file *rep);

ssize_t data_file_write2io (P_t *pads,Sfio_t *io,data_file_pd *pd,data_file *rep);

ssize_t data_file_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,data_file_pd *pd,data_file *rep,char const *_tag,int indent);

ssize_t data_file_write_xml_2io (P_t *pads,Sfio_t *io,data_file_pd *pd,data_file *rep,char const *_tag,int indent);

ssize_t data_file_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_file_m *m,data_file_pd *pd,data_file *rep);

ssize_t data_file_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,data_file_m *m,data_file_pd *pd,data_file *rep);

ssize_t data_file_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,data_file_m *m,data_file_pd *pd,data_file *rep);

void P_lib_init ();

#endif /*  __PENDIAN__H__  */
