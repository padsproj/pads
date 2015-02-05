#ifndef __ENUM__H__
#define __ENUM__H__
#include "pads.h"
typedef enum orderStates_e orderStates;
typedef Pbase_m orderStates_m;
typedef Pbase_pd orderStates_pd;
enum orderStates_e {
  S_init=0,
  S_lec=2,
  S_care=3,
  S_for=10,
  S_if=11,
  S_tpv=5
  };

char const *orderStates2str (orderStates which);

Perror_t orderStates_init (P_t *pads,orderStates *rep);

Perror_t orderStates_pd_init (P_t *pads,orderStates_pd *pd);

Perror_t orderStates_cleanup (P_t *pads,orderStates *rep);

Perror_t orderStates_pd_cleanup (P_t *pads,orderStates_pd *pd);

Perror_t orderStates_copy (P_t *pads,orderStates *rep_dst,orderStates *rep_src);

Perror_t orderStates_pd_copy (P_t *pads,orderStates_pd *pd_dst,orderStates_pd *pd_src);

void orderStates_m_init (P_t *pads,orderStates_m *mask,Pbase_m baseMask);

Perror_t orderStates_m_rec_init (P_t *pads,orderStates_m *mask,Pbase_m baseMask);

Perror_t orderStates_read (P_t *pads,orderStates_m *m,orderStates_pd *pd,orderStates *rep);

int orderStates_verify (P_t *pads,orderStates *rep);

int orderStates_genPD (P_t *pads,orderStates *rep,orderStates_pd *pd);
typedef Pint32_acc orderStates_acc;

Perror_t orderStates_acc_init (P_t *pads,orderStates_acc *acc);

Perror_t orderStates_acc_reset (P_t *pads,orderStates_acc *acc);

Perror_t orderStates_acc_cleanup (P_t *pads,orderStates_acc *acc);

Perror_t orderStates_acc_add (P_t *pads,orderStates_acc *acc,orderStates_pd *pd,orderStates *rep);

Perror_t orderStates_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,orderStates_acc *acc);

Perror_t orderStates_acc_report (P_t *pads,char const *prefix,char const *what,int nst,orderStates_acc *acc);

Perror_t orderStates_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,orderStates_acc *acc);

ssize_t orderStates_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,orderStates_pd *pd,orderStates *rep);

ssize_t orderStates_write2io (P_t *pads,Sfio_t *io,orderStates_pd *pd,orderStates *rep);

ssize_t orderStates_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,orderStates_pd *pd,orderStates *rep,char const *_tag,int indent);

ssize_t orderStates_write_xml_2io (P_t *pads,Sfio_t *io,orderStates_pd *pd,orderStates *rep,char const *_tag,int indent);

ssize_t orderStates_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,orderStates_m *m,orderStates_pd *pd,orderStates *rep);

ssize_t orderStates_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,orderStates_m *m,orderStates_pd *pd,orderStates *rep);

ssize_t orderStates_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,orderStates_m *m,orderStates_pd *pd,orderStates *rep);
typedef struct enums_s enums;
typedef struct enums_m_s enums_m;
typedef struct enums_pd_s enums_pd;
typedef struct enums_ro_params_t_s enums_ro_params_t;
struct enums_m_s {
  orderStates_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct enums_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  orderStates_pd *elts;
  RBuf_t *_internal;
};
struct enums_s {
  Puint32 length;
  orderStates *elts;
  RBuf_t *_internal;
};
struct enums_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t enums_init (P_t *pads,enums *rep);

Perror_t enums_pd_init (P_t *pads,enums_pd *pd);

Perror_t enums_cleanup (P_t *pads,enums *rep);

Perror_t enums_pd_cleanup (P_t *pads,enums_pd *pd);

Perror_t enums_copy (P_t *pads,enums *rep_dst,enums *rep_src);

Perror_t enums_pd_copy (P_t *pads,enums_pd *pd_dst,enums_pd *pd_src);

void enums_m_init (P_t *pads,enums_m *mask,Pbase_m baseMask);

Perror_t enums_m_rec_init (P_t *pads,enums_m *mask,Pbase_m baseMask);

void enums_ro_params_init (enums_ro_params_t *params);

Pread_res_t enums_final_checks (P_t *pads,enums_m *m,enums_pd *pd,enums *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t enums_read_one_init (P_t *pads,enums_m *m,enums_pd *pd,enums *rep,Ploc_t *loc_ptr);

Pread_res_t enums_read_one (P_t *pads,enums_m *m,enums_pd *pd,enums *rep,Ploc_t *loc_ptr,orderStates_pd *elt_pd,orderStates *elt_rep);

Perror_t enums_read (P_t *pads,enums_m *m,enums_pd *pd,enums *rep);

Pread_res_t enums_reread_one (P_t *pads,enums_m *m,enums_pd *pd,enums *rep,Ploc_t *loc_ptr,orderStates_pd *elt_pd,orderStates *elt_rep,int notFirstElt);

int enums_verify (P_t *pads,enums *rep);

int enums_genPD (P_t *pads,enums *rep,enums_pd *pd);
typedef struct enums_acc_s enums_acc;
struct enums_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  orderStates_acc compoundLevel;		/* Accumulator for all array elements */
  orderStates_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t enums_acc_init (P_t *pads,enums_acc *acc);

Perror_t enums_acc_reset (P_t *pads,enums_acc *acc);

Perror_t enums_acc_cleanup (P_t *pads,enums_acc *acc);

Perror_t enums_acc_add (P_t *pads,enums_acc *acc,enums_pd *pd,enums *rep);

Perror_t enums_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,enums_acc *acc);

Perror_t enums_acc_report (P_t *pads,char const *prefix,char const *what,int nst,enums_acc *acc);

Perror_t enums_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,enums_acc *acc);

ssize_t enums_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,enums_pd *pd,enums *rep);

ssize_t enums_write2io (P_t *pads,Sfio_t *io,enums_pd *pd,enums *rep);

ssize_t enums_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,enums_pd *pd,enums *rep,char const *_tag,int indent);

ssize_t enums_write_xml_2io (P_t *pads,Sfio_t *io,enums_pd *pd,enums *rep,char const *_tag,int indent);

ssize_t enums_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,enums_m *m,enums_pd *pd,enums *rep);

ssize_t enums_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,enums_m *m,enums_pd *pd,enums *rep);

ssize_t enums_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,enums_m *m,enums_pd *pd,enums *rep);

void P_lib_init ();

#endif /*  __ENUM__H__  */
