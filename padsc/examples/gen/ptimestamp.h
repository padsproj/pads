#ifndef __PTIMESTAMP__H__
#define __PTIMESTAMP__H__
#include "pads.h"
typedef struct threetimestamps_s threetimestamps;
typedef struct threetimestamps_m_s threetimestamps_m;
typedef struct threetimestamps_pd_s threetimestamps_pd;
struct threetimestamps_m_s {
  Pbase_m compoundLevel;
  Pbase_m ts1;		/* nested constraints */
  Pbase_m ts2;		/* nested constraints */
  Pbase_m ts3;		/* nested constraints */
};
struct threetimestamps_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd ts1;
  Pbase_pd ts2;
  Pbase_pd ts3;
};
struct threetimestamps_s {
  Ptimestamp ts1;
  Ptimestamp ts2;
  Ptimestamp ts3;
};

Perror_t threetimestamps_init (P_t *pads,threetimestamps *rep);

Perror_t threetimestamps_pd_init (P_t *pads,threetimestamps_pd *pd);

Perror_t threetimestamps_cleanup (P_t *pads,threetimestamps *rep);

Perror_t threetimestamps_pd_cleanup (P_t *pads,threetimestamps_pd *pd);

Perror_t threetimestamps_copy (P_t *pads,threetimestamps *rep_dst,threetimestamps *rep_src);

Perror_t threetimestamps_pd_copy (P_t *pads,threetimestamps_pd *pd_dst,threetimestamps_pd *pd_src);

void threetimestamps_m_init (P_t *pads,threetimestamps_m *mask,Pbase_m baseMask);

Perror_t threetimestamps_m_rec_init (P_t *pads,threetimestamps_m *mask,Pbase_m baseMask);

Perror_t threetimestamps_read (P_t *pads,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

int threetimestamps_verify (P_t *pads,threetimestamps *rep);

int threetimestamps_genPD (P_t *pads,threetimestamps *rep,threetimestamps_pd *pd);
typedef struct threetimestamps_acc_s threetimestamps_acc;
struct threetimestamps_acc_s {
  Puint32_acc nerr;
  Ptimestamp_acc ts1;
  Ptimestamp_acc ts2;
  Ptimestamp_acc ts3;
};

Perror_t threetimestamps_acc_init (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_reset (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_cleanup (P_t *pads,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_add (P_t *pads,threetimestamps_acc *acc,threetimestamps_pd *pd,threetimestamps *rep);

Perror_t threetimestamps_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_report (P_t *pads,char const *prefix,char const *what,int nst,threetimestamps_acc *acc);

Perror_t threetimestamps_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,threetimestamps_acc *acc);

ssize_t threetimestamps_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_write2io (P_t *pads,Sfio_t *io,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threetimestamps_pd *pd,threetimestamps *rep,char const *_tag,int indent);

ssize_t threetimestamps_write_xml_2io (P_t *pads,Sfio_t *io,threetimestamps_pd *pd,threetimestamps *rep,char const *_tag,int indent);

ssize_t threetimestamps_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);

ssize_t threetimestamps_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,threetimestamps_m *m,threetimestamps_pd *pd,threetimestamps *rep);
typedef struct source_s source;
typedef struct source_m_s source_m;
typedef struct source_pd_s source_pd;
typedef struct source_ro_params_t_s source_ro_params_t;
struct source_m_s {
  threetimestamps_m element;		/* per-element */
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
  threetimestamps_pd *elts;
  RBuf_t *_internal;
};
struct source_s {
  Puint32 length;
  threetimestamps *elts;
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

Pread_res_t source_read_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,threetimestamps_pd *elt_pd,threetimestamps *elt_rep);

Perror_t source_read (P_t *pads,source_m *m,source_pd *pd,source *rep);

Pread_res_t source_reread_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,threetimestamps_pd *elt_pd,threetimestamps *elt_rep,int notFirstElt);

int source_verify (P_t *pads,source *rep);

int source_genPD (P_t *pads,source *rep,source_pd *pd);
typedef struct source_acc_s source_acc;
struct source_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  threetimestamps_acc compoundLevel;		/* Accumulator for all array elements */
  threetimestamps_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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

#endif /*  __PTIMESTAMP__H__  */
