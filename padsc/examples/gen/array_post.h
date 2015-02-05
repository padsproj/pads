#ifndef __ARRAY_POST__H__
#define __ARRAY_POST__H__
#include "pads.h"
typedef struct intList_s intList;
typedef struct intList_m_s intList_m;
typedef struct intList_pd_s intList_pd;
typedef struct intList_ro_params_t_s intList_ro_params_t;
struct intList_m_s {
  Pbase_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct intList_pd_s {
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
struct intList_s {
  Puint32 length;
  Puint32 *elts;
  RBuf_t *_internal;
};
struct intList_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t intList_init (P_t *pads,intList *rep);

Perror_t intList_pd_init (P_t *pads,intList_pd *pd);

Perror_t intList_cleanup (P_t *pads,intList *rep);

Perror_t intList_pd_cleanup (P_t *pads,intList_pd *pd);

Perror_t intList_copy (P_t *pads,intList *rep_dst,intList *rep_src);

Perror_t intList_pd_copy (P_t *pads,intList_pd *pd_dst,intList_pd *pd_src);

void intList_m_init (P_t *pads,intList_m *mask,Pbase_m baseMask);

Perror_t intList_m_rec_init (P_t *pads,intList_m *mask,Pbase_m baseMask);

void intList_ro_params_init (intList_ro_params_t *params);

Pread_res_t intList_final_checks (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,int reachedLimit,int consume);

Pread_res_t intList_read_one_init (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr);

Pread_res_t intList_read_one (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint32 *elt_rep);

Perror_t intList_read (P_t *pads,intList_m *m,intList_pd *pd,intList *rep);

Pread_res_t intList_reread_one (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint32 *elt_rep,int notFirstElt);

int intList_verify (P_t *pads,intList *rep);

int intList_genPD (P_t *pads,intList *rep,intList_pd *pd);
typedef struct intList_acc_s intList_acc;
struct intList_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Puint32_acc compoundLevel;		/* Accumulator for all array elements */
  Puint32_acc arrayDetail[4];		/* Accumulator for first 4 array elements */
};

Perror_t intList_acc_init (P_t *pads,intList_acc *acc);

Perror_t intList_acc_reset (P_t *pads,intList_acc *acc);

Perror_t intList_acc_cleanup (P_t *pads,intList_acc *acc);

Perror_t intList_acc_add (P_t *pads,intList_acc *acc,intList_pd *pd,intList *rep);

Perror_t intList_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,intList_acc *acc);

Perror_t intList_acc_report (P_t *pads,char const *prefix,char const *what,int nst,intList_acc *acc);

Perror_t intList_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,intList_acc *acc);

ssize_t intList_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,intList_pd *pd,intList *rep);

ssize_t intList_write2io (P_t *pads,Sfio_t *io,intList_pd *pd,intList *rep);

ssize_t intList_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,intList_pd *pd,intList *rep,char const *_tag,int indent);

ssize_t intList_write_xml_2io (P_t *pads,Sfio_t *io,intList_pd *pd,intList *rep,char const *_tag,int indent);

ssize_t intList_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,intList_m *m,intList_pd *pd,intList *rep);

ssize_t intList_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,intList_m *m,intList_pd *pd,intList *rep);

ssize_t intList_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,intList_m *m,intList_pd *pd,intList *rep);

void P_lib_init ();

#endif /*  __ARRAY_POST__H__  */
