#ifndef __FORMAT7__H__
#define __FORMAT7__H__
#include "pads.h"
#include "pglx-internal.h"
typedef struct test_s test;
typedef struct test_m_s test_m;
typedef struct test_pd_s test_pd;
struct test_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct test_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  PDCI_id_t _id_;		/* Identifier tag for Galax */
  Pbase_pd id;
  Pbase_pd ts;
};
struct test_s {
  Pint32 id;		/*  identity. id < 100000&& */
  Pint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_init (P_t *pads,test *rep);

Perror_t test_pd_init (P_t *pads,test_pd *pd);

Perror_t test_cleanup (P_t *pads,test *rep);

Perror_t test_pd_cleanup (P_t *pads,test_pd *pd);

Perror_t test_copy (P_t *pads,test *rep_dst,test *rep_src);

Perror_t test_pd_copy (P_t *pads,test_pd *pd_dst,test_pd *pd_src);

void test_m_init (P_t *pads,test_m *mask,Pbase_m baseMask);

Perror_t test_read (P_t *pads,test_m *m,test_pd *pd,test *rep);

int test_verify (test *rep);

int test_genPD (P_t *pads,test *rep,test_pd *pd);
typedef struct test_acc_s test_acc;
struct test_acc_s {
  Puint32_acc nerr;
  Pint32_acc id;		/*  identity. id < 100000&& */
  Pint32_acc ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_acc_init (P_t *pads,test_acc *acc);

Perror_t test_acc_reset (P_t *pads,test_acc *acc);

Perror_t test_acc_cleanup (P_t *pads,test_acc *acc);

Perror_t test_acc_add (P_t *pads,test_acc *acc,test_pd *pd,test *rep);

Perror_t test_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test_acc *acc);

Perror_t test_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test_acc *acc);

ssize_t test_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep);

ssize_t test_write2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep);

ssize_t test_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_pd *pd,test *rep,char const *_tag,int indent);

ssize_t test_write_xml_2io (P_t *pads,Sfio_t *io,test_pd *pd,test *rep,char const *_tag,int indent);

ssize_t test_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

ssize_t test_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test_m *m,test_pd *pd,test *rep);

PDCI_node_t *test_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn);

PDCI_node_t *test_cachedNode_init (PDCI_node_t *self);

PDCI_node_t *test_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name);

PDCI_node_t *test_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx);

PDCI_node_t *test_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

Perror_t test_node_pathWalk (P_t *pads,test_m *m,test_pd *pd,test *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out);
extern PDCI_vtable_t const test_node_vtable;
extern PDCI_vtable_t const test_cachedNode_vtable;
extern PDCI_vtable_t const test_sndNode_vtable;
typedef struct test_not_rec_s test_not_rec;
typedef struct test_not_rec_m_s test_not_rec_m;
typedef struct test_not_rec_pd_s test_not_rec_pd;
struct test_not_rec_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct test_not_rec_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  PDCI_id_t _id_;		/* Identifier tag for Galax */
  Pbase_pd id;
  Pbase_pd ts;
};
struct test_not_rec_s {
  Pint32 id;		/*  identity. id < 100000&& */
  Pint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_not_rec_init (P_t *pads,test_not_rec *rep);

Perror_t test_not_rec_pd_init (P_t *pads,test_not_rec_pd *pd);

Perror_t test_not_rec_cleanup (P_t *pads,test_not_rec *rep);

Perror_t test_not_rec_pd_cleanup (P_t *pads,test_not_rec_pd *pd);

Perror_t test_not_rec_copy (P_t *pads,test_not_rec *rep_dst,test_not_rec *rep_src);

Perror_t test_not_rec_pd_copy (P_t *pads,test_not_rec_pd *pd_dst,test_not_rec_pd *pd_src);

void test_not_rec_m_init (P_t *pads,test_not_rec_m *mask,Pbase_m baseMask);

Perror_t test_not_rec_read (P_t *pads,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

int test_not_rec_verify (test_not_rec *rep);

int test_not_rec_genPD (P_t *pads,test_not_rec *rep,test_not_rec_pd *pd);
typedef struct test_not_rec_acc_s test_not_rec_acc;
struct test_not_rec_acc_s {
  Puint32_acc nerr;
  Pint32_acc id;		/*  identity. id < 100000&& */
  Pint32_acc ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_not_rec_acc_init (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_reset (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_cleanup (P_t *pads,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_add (P_t *pads,test_not_rec_acc *acc,test_not_rec_pd *pd,test_not_rec *rep);

Perror_t test_not_rec_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test_not_rec_acc *acc);

Perror_t test_not_rec_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test_not_rec_acc *acc);

ssize_t test_not_rec_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_write2io (P_t *pads,Sfio_t *io,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test_not_rec_pd *pd,test_not_rec *rep,char const *_tag,int indent);

ssize_t test_not_rec_write_xml_2io (P_t *pads,Sfio_t *io,test_not_rec_pd *pd,test_not_rec *rep,char const *_tag,int indent);

ssize_t test_not_rec_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

ssize_t test_not_rec_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep);

PDCI_node_t *test_not_rec_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn);

PDCI_node_t *test_not_rec_cachedNode_init (PDCI_node_t *self);

PDCI_node_t *test_not_rec_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test_not_rec_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name);

PDCI_node_t *test_not_rec_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test_not_rec_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx);

PDCI_node_t *test_not_rec_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

Perror_t test_not_rec_node_pathWalk (P_t *pads,test_not_rec_m *m,test_not_rec_pd *pd,test_not_rec *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out);
extern PDCI_vtable_t const test_not_rec_node_vtable;
extern PDCI_vtable_t const test_not_rec_cachedNode_vtable;
extern PDCI_vtable_t const test_not_rec_sndNode_vtable;
typedef struct test2_s test2;
typedef struct test2_m_s test2_m;
typedef struct test2_pd_s test2_pd;
struct test2_m_s {
  Pbase_m compoundLevel;
  test_not_rec_m bigger;		/* nested constraints */
  Pbase_m two;		/* nested constraints */
};
struct test2_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  PDCI_id_t _id_;		/* Identifier tag for Galax */
  test_not_rec_pd bigger;
  Pbase_pd two;
};
struct test2_s {
  test_not_rec bigger;
  Pint32 two;
};

Perror_t test2_init (P_t *pads,test2 *rep);

Perror_t test2_pd_init (P_t *pads,test2_pd *pd);

Perror_t test2_cleanup (P_t *pads,test2 *rep);

Perror_t test2_pd_cleanup (P_t *pads,test2_pd *pd);

Perror_t test2_copy (P_t *pads,test2 *rep_dst,test2 *rep_src);

Perror_t test2_pd_copy (P_t *pads,test2_pd *pd_dst,test2_pd *pd_src);

void test2_m_init (P_t *pads,test2_m *mask,Pbase_m baseMask);

Perror_t test2_read (P_t *pads,test2_m *m,test2_pd *pd,test2 *rep);

int test2_verify (test2 *rep);

int test2_genPD (P_t *pads,test2 *rep,test2_pd *pd);
typedef struct test2_acc_s test2_acc;
struct test2_acc_s {
  Puint32_acc nerr;
  test_not_rec_acc bigger;
  Pint32_acc two;
};

Perror_t test2_acc_init (P_t *pads,test2_acc *acc);

Perror_t test2_acc_reset (P_t *pads,test2_acc *acc);

Perror_t test2_acc_cleanup (P_t *pads,test2_acc *acc);

Perror_t test2_acc_add (P_t *pads,test2_acc *acc,test2_pd *pd,test2 *rep);

Perror_t test2_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,test2_acc *acc);

Perror_t test2_acc_report (P_t *pads,char const *prefix,char const *what,int nst,test2_acc *acc);

Perror_t test2_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,test2_acc *acc);

ssize_t test2_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test2_pd *pd,test2 *rep);

ssize_t test2_write2io (P_t *pads,Sfio_t *io,test2_pd *pd,test2 *rep);

ssize_t test2_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,test2_pd *pd,test2 *rep,char const *_tag,int indent);

ssize_t test2_write_xml_2io (P_t *pads,Sfio_t *io,test2_pd *pd,test2 *rep,char const *_tag,int indent);

ssize_t test2_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

ssize_t test2_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

ssize_t test2_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,test2_m *m,test2_pd *pd,test2 *rep);

PDCI_node_t *test2_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn);

PDCI_node_t *test2_cachedNode_init (PDCI_node_t *self);

PDCI_node_t *test2_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test2_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name);

PDCI_node_t *test2_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *test2_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx);

PDCI_node_t *test2_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

Perror_t test2_node_pathWalk (P_t *pads,test2_m *m,test2_pd *pd,test2 *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out);
extern PDCI_vtable_t const test2_node_vtable;
extern PDCI_vtable_t const test2_cachedNode_vtable;
extern PDCI_vtable_t const test2_sndNode_vtable;
typedef struct myfile_s myfile;
typedef struct myfile_m_s myfile_m;
typedef struct myfile_pd_s myfile_pd;
typedef struct myfile_ro_params_t_s myfile_ro_params_t;
typedef struct myfile_array_info_t_s myfile_array_info_t;
struct myfile_m_s {
  test_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct myfile_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  PDCI_id_t _id_;		/* Identifier tag for Galax */
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  test_pd *elts;
  RBuf_t *_internal;
};
struct myfile_s {
  Puint32 length;
  test *elts;
  RBuf_t *_internal;
};
struct myfile_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};
struct myfile_array_info_t_s {
  PDCI_smart_array_info_t base;
  myfile_ro_params_t params;		/* Type-specific parameters to read related funcitons. */
};

Perror_t myfile_init (P_t *pads,myfile *rep);

Perror_t myfile_pd_init (P_t *pads,myfile_pd *pd);

Perror_t myfile_cleanup (P_t *pads,myfile *rep);

Perror_t myfile_pd_cleanup (P_t *pads,myfile_pd *pd);

Perror_t myfile_copy (P_t *pads,myfile *rep_dst,myfile *rep_src);

Perror_t myfile_pd_copy (P_t *pads,myfile_pd *pd_dst,myfile_pd *pd_src);

void myfile_m_init (P_t *pads,myfile_m *mask,Pbase_m baseMask);

void myfile_ro_params_init (myfile_ro_params_t *params);

Pread_res_t myfile_final_checks (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t myfile_read_one_init (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep,Ploc_t *loc_ptr);

Pread_res_t myfile_read_one (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep);

Perror_t myfile_read (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep);

Pread_res_t myfile_reread_one (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep,int notFirstElt);

int myfile_verify (myfile *rep);

int myfile_genPD (P_t *pads,myfile *rep,myfile_pd *pd);
typedef struct myfile_acc_s myfile_acc;
struct myfile_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  test_acc compoundLevel;		/* Accumulator for all array elements */
  test_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t myfile_acc_init (P_t *pads,myfile_acc *acc);

Perror_t myfile_acc_reset (P_t *pads,myfile_acc *acc);

Perror_t myfile_acc_cleanup (P_t *pads,myfile_acc *acc);

Perror_t myfile_acc_add (P_t *pads,myfile_acc *acc,myfile_pd *pd,myfile *rep);

Perror_t myfile_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,myfile_acc *acc);

Perror_t myfile_acc_report (P_t *pads,char const *prefix,char const *what,int nst,myfile_acc *acc);

Perror_t myfile_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,myfile_acc *acc);

ssize_t myfile_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,myfile_pd *pd,myfile *rep);

ssize_t myfile_write2io (P_t *pads,Sfio_t *io,myfile_pd *pd,myfile *rep);

ssize_t myfile_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,myfile_pd *pd,myfile *rep,char const *_tag,int indent);

ssize_t myfile_write_xml_2io (P_t *pads,Sfio_t *io,myfile_pd *pd,myfile *rep,char const *_tag,int indent);

ssize_t myfile_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,myfile_m *m,myfile_pd *pd,myfile *rep);

ssize_t myfile_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,myfile_m *m,myfile_pd *pd,myfile *rep);

ssize_t myfile_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,myfile_m *m,myfile_pd *pd,myfile *rep);

PDCI_node_t *myfile_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn);

PDCI_node_t *myfile_cachedNode_init (PDCI_node_t *self);

PDCI_node_t *myfile_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *myfile_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name);

PDCI_node_t *myfile_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *myfile_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx);

PDCI_node_t *myfile_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

Perror_t myfile_node_pathWalk (P_t *pads,myfile_m *m,myfile_pd *pd,myfile *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out);
extern PDCI_vtable_t const myfile_node_vtable;
extern PDCI_vtable_t const myfile_cachedNode_vtable;
extern PDCI_vtable_t const myfile_sndNode_vtable;

Perror_t myfile_smartNode_eltAlloc (PDCI_node_t *smartNode,P_t *pads,void **elt_pd,void **elt_rep);

Pread_res_t myfile_smartNode_eltRead (PDCI_node_t *smartNode,P_t *pads,PDCI_smart_elt_info_t *info);

Perror_t myfile_smartNode_eltFree (P_t *pads,PDCI_smart_elt_info_t *info);

Perror_t myfile_smartNode_eltPathWalk (P_t *pads,void *m,void *pd,void *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out);

PDCI_smart_array_info_t *myfile_array_info_init (P_t *pads,unsigned int max_elts);

PDCI_node_t *myfile_smartNode_init (PDCI_node_t *self,unsigned int max_elts);

PDCI_node_t *myfile_smartNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx);

PDCI_node_t *myfile_smartNode_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name);
extern PDCI_vtable_t const myfile_smartNode_vtable;

void P_lib_init ();

#endif /*  __FORMAT7__H__  */
