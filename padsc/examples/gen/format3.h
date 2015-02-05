#ifndef __FORMAT3__H__
#define __FORMAT3__H__
#include "pads.h"
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
  Pbase_pd id;
  Pbase_pd ts;
};
struct test_s {
  Puint32 id;		/*  identity. id < 100000&& */
  Puint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t test_init (P_t *pads,test *rep);

Perror_t test_pd_init (P_t *pads,test_pd *pd);

Perror_t test_cleanup (P_t *pads,test *rep);

Perror_t test_pd_cleanup (P_t *pads,test_pd *pd);

Perror_t test_copy (P_t *pads,test *rep_dst,test *rep_src);

Perror_t test_pd_copy (P_t *pads,test_pd *pd_dst,test_pd *pd_src);

void test_m_init (P_t *pads,test_m *mask,Pbase_m baseMask);

Perror_t test_m_rec_init (P_t *pads,test_m *mask,Pbase_m baseMask);

Perror_t test_read (P_t *pads,test_m *m,test_pd *pd,test *rep);

int test_verify (P_t *pads,test *rep);

int test_genPD (P_t *pads,test *rep,test_pd *pd);
typedef struct test_acc_s test_acc;
struct test_acc_s {
  Puint32_acc nerr;
  Puint32_acc id;		/*  identity. id < 100000&& */
  Puint32_acc ts;		/*  time stamp. ts == 11 * id&& */
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
typedef struct recList_s recList;
typedef struct recList_m_s recList_m;
typedef struct recList_pd_s recList_pd;
typedef struct recList_ro_params_t_s recList_ro_params_t;
struct recList_m_s {
  test_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct recList_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  test_pd *elts;
  RBuf_t *_internal;
};
struct recList_s {
  Puint32 length;
  test *elts;
  RBuf_t *_internal;
};
struct recList_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t recList_init (P_t *pads,recList *rep);

Perror_t recList_pd_init (P_t *pads,recList_pd *pd);

Perror_t recList_cleanup (P_t *pads,recList *rep);

Perror_t recList_pd_cleanup (P_t *pads,recList_pd *pd);

Perror_t recList_copy (P_t *pads,recList *rep_dst,recList *rep_src);

Perror_t recList_pd_copy (P_t *pads,recList_pd *pd_dst,recList_pd *pd_src);

void recList_m_init (P_t *pads,recList_m *mask,Pbase_m baseMask);

Perror_t recList_m_rec_init (P_t *pads,recList_m *mask,Pbase_m baseMask);

void recList_ro_params_init (recList_ro_params_t *params);

Pread_res_t recList_final_checks (P_t *pads,recList_m *m,recList_pd *pd,recList *rep,Ploc_t *loc_ptr,int reachedLimit,int consume);

Pread_res_t recList_read_one_init (P_t *pads,recList_m *m,recList_pd *pd,recList *rep,Ploc_t *loc_ptr);

Pread_res_t recList_read_one (P_t *pads,recList_m *m,recList_pd *pd,recList *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep);

Perror_t recList_read (P_t *pads,recList_m *m,recList_pd *pd,recList *rep);

Pread_res_t recList_reread_one (P_t *pads,recList_m *m,recList_pd *pd,recList *rep,Ploc_t *loc_ptr,test_pd *elt_pd,test *elt_rep,int notFirstElt);

int recList_verify (P_t *pads,recList *rep);

int recList_genPD (P_t *pads,recList *rep,recList_pd *pd);
typedef struct recList_acc_s recList_acc;
struct recList_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  test_acc compoundLevel;		/* Accumulator for all array elements */
  test_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t recList_acc_init (P_t *pads,recList_acc *acc);

Perror_t recList_acc_reset (P_t *pads,recList_acc *acc);

Perror_t recList_acc_cleanup (P_t *pads,recList_acc *acc);

Perror_t recList_acc_add (P_t *pads,recList_acc *acc,recList_pd *pd,recList *rep);

Perror_t recList_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,recList_acc *acc);

Perror_t recList_acc_report (P_t *pads,char const *prefix,char const *what,int nst,recList_acc *acc);

Perror_t recList_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,recList_acc *acc);

ssize_t recList_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,recList_pd *pd,recList *rep);

ssize_t recList_write2io (P_t *pads,Sfio_t *io,recList_pd *pd,recList *rep);

ssize_t recList_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,recList_pd *pd,recList *rep,char const *_tag,int indent);

ssize_t recList_write_xml_2io (P_t *pads,Sfio_t *io,recList_pd *pd,recList *rep,char const *_tag,int indent);

ssize_t recList_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,recList_m *m,recList_pd *pd,recList *rep);

ssize_t recList_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,recList_m *m,recList_pd *pd,recList *rep);

ssize_t recList_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,recList_m *m,recList_pd *pd,recList *rep);
typedef struct testtwo_s testtwo;
typedef struct testtwo_m_s testtwo_m;
typedef struct testtwo_pd_s testtwo_pd;
struct testtwo_m_s {
  Pbase_m compoundLevel;
  Pbase_m id;		/* nested constraints */
  Pbase_m id_con;		/* struct constraints */
  Pbase_m ts;		/* nested constraints */
  Pbase_m ts_con;		/* struct constraints */
};
struct testtwo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd id;
  Pbase_pd ts;
};
struct testtwo_s {
  Puint32 id;		/*  identity. id < 100000&& */
  Puint32 ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t testtwo_init (P_t *pads,testtwo *rep);

Perror_t testtwo_pd_init (P_t *pads,testtwo_pd *pd);

Perror_t testtwo_cleanup (P_t *pads,testtwo *rep);

Perror_t testtwo_pd_cleanup (P_t *pads,testtwo_pd *pd);

Perror_t testtwo_copy (P_t *pads,testtwo *rep_dst,testtwo *rep_src);

Perror_t testtwo_pd_copy (P_t *pads,testtwo_pd *pd_dst,testtwo_pd *pd_src);

void testtwo_m_init (P_t *pads,testtwo_m *mask,Pbase_m baseMask);

Perror_t testtwo_m_rec_init (P_t *pads,testtwo_m *mask,Pbase_m baseMask);

Perror_t testtwo_read (P_t *pads,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

int testtwo_verify (P_t *pads,testtwo *rep);

int testtwo_genPD (P_t *pads,testtwo *rep,testtwo_pd *pd);
typedef struct testtwo_acc_s testtwo_acc;
struct testtwo_acc_s {
  Puint32_acc nerr;
  Puint32_acc id;		/*  identity. id < 100000&& */
  Puint32_acc ts;		/*  time stamp. ts == 11 * id&& */
};

Perror_t testtwo_acc_init (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_reset (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_cleanup (P_t *pads,testtwo_acc *acc);

Perror_t testtwo_acc_add (P_t *pads,testtwo_acc *acc,testtwo_pd *pd,testtwo *rep);

Perror_t testtwo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,testtwo_acc *acc);

Perror_t testtwo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,testtwo_acc *acc);

Perror_t testtwo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,testtwo_acc *acc);

ssize_t testtwo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_write2io (P_t *pads,Sfio_t *io,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,testtwo_pd *pd,testtwo *rep,char const *_tag,int indent);

ssize_t testtwo_write_xml_2io (P_t *pads,Sfio_t *io,testtwo_pd *pd,testtwo *rep,char const *_tag,int indent);

ssize_t testtwo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);

ssize_t testtwo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,testtwo_m *m,testtwo_pd *pd,testtwo *rep);
typedef struct recListtwo_s recListtwo;
typedef struct recListtwo_m_s recListtwo_m;
typedef struct recListtwo_pd_s recListtwo_pd;
typedef struct recListtwo_ro_params_t_s recListtwo_ro_params_t;
struct recListtwo_m_s {
  testtwo_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct recListtwo_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  testtwo_pd *elts;
  RBuf_t *_internal;
};
struct recListtwo_s {
  Puint32 length;
  testtwo *elts;
  RBuf_t *_internal;
};
struct recListtwo_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t recListtwo_init (P_t *pads,recListtwo *rep);

Perror_t recListtwo_pd_init (P_t *pads,recListtwo_pd *pd);

Perror_t recListtwo_cleanup (P_t *pads,recListtwo *rep);

Perror_t recListtwo_pd_cleanup (P_t *pads,recListtwo_pd *pd);

Perror_t recListtwo_copy (P_t *pads,recListtwo *rep_dst,recListtwo *rep_src);

Perror_t recListtwo_pd_copy (P_t *pads,recListtwo_pd *pd_dst,recListtwo_pd *pd_src);

void recListtwo_m_init (P_t *pads,recListtwo_m *mask,Pbase_m baseMask);

Perror_t recListtwo_m_rec_init (P_t *pads,recListtwo_m *mask,Pbase_m baseMask);

void recListtwo_ro_params_init (recListtwo_ro_params_t *params);

Pread_res_t recListtwo_final_checks (P_t *pads,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t recListtwo_read_one_init (P_t *pads,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep,Ploc_t *loc_ptr);

Pread_res_t recListtwo_read_one (P_t *pads,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep,Ploc_t *loc_ptr,testtwo_pd *elt_pd,testtwo *elt_rep);

Perror_t recListtwo_read (P_t *pads,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep);

Pread_res_t recListtwo_reread_one (P_t *pads,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep,Ploc_t *loc_ptr,testtwo_pd *elt_pd,testtwo *elt_rep,int notFirstElt);

int recListtwo_verify (P_t *pads,recListtwo *rep);

int recListtwo_genPD (P_t *pads,recListtwo *rep,recListtwo_pd *pd);
typedef struct recListtwo_acc_s recListtwo_acc;
struct recListtwo_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  testtwo_acc compoundLevel;		/* Accumulator for all array elements */
  testtwo_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t recListtwo_acc_init (P_t *pads,recListtwo_acc *acc);

Perror_t recListtwo_acc_reset (P_t *pads,recListtwo_acc *acc);

Perror_t recListtwo_acc_cleanup (P_t *pads,recListtwo_acc *acc);

Perror_t recListtwo_acc_add (P_t *pads,recListtwo_acc *acc,recListtwo_pd *pd,recListtwo *rep);

Perror_t recListtwo_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,recListtwo_acc *acc);

Perror_t recListtwo_acc_report (P_t *pads,char const *prefix,char const *what,int nst,recListtwo_acc *acc);

Perror_t recListtwo_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,recListtwo_acc *acc);

ssize_t recListtwo_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,recListtwo_pd *pd,recListtwo *rep);

ssize_t recListtwo_write2io (P_t *pads,Sfio_t *io,recListtwo_pd *pd,recListtwo *rep);

ssize_t recListtwo_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,recListtwo_pd *pd,recListtwo *rep,char const *_tag,int indent);

ssize_t recListtwo_write_xml_2io (P_t *pads,Sfio_t *io,recListtwo_pd *pd,recListtwo *rep,char const *_tag,int indent);

ssize_t recListtwo_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep);

ssize_t recListtwo_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep);

ssize_t recListtwo_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,recListtwo_m *m,recListtwo_pd *pd,recListtwo *rep);
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

Pread_res_t intList_final_checks (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,int foundTerm,int reachedLimit,int consume);

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
  Puint32_acc arrayDetail[5];		/* Accumulator for first 5 array elements */
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
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  intList_m i;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  intList_pd i;
};
struct entry_s {
  intList i;
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
  intList_acc i;
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

#endif /*  __FORMAT3__H__  */
