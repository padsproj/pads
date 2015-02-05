#ifndef __NEWICK__H__
#define __NEWICK__H__
#include "pads.h"
typedef struct entry_s entry;
typedef struct entry_m_s entry_m;
typedef struct entry_pd_s entry_pd;
struct entry_m_s {
  Pbase_m compoundLevel;
  Pbase_m name;		/* nested constraints */
  Pbase_m dist;		/* nested constraints */
};
struct entry_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd name;
  Pbase_pd dist;
};
struct entry_s {
  Pstring name;
  Puint32 dist;
};

Perror_t entry_init (P_t *pads,entry *rep);

Perror_t entry_pd_init (P_t *pads,entry_pd *pd);

Perror_t entry_cleanup (P_t *pads,entry *rep);

Perror_t entry_pd_cleanup (P_t *pads,entry_pd *pd);

Perror_t entry_copy (P_t *pads,entry *rep_dst,entry *rep_src);

Perror_t entry_pd_copy (P_t *pads,entry_pd *pd_dst,entry_pd *pd_src);

void entry_m_init (P_t *pads,entry_m *mask,Pbase_m baseMask);

Perror_t entry_read (P_t *pads,entry_m *m,entry_pd *pd,entry *rep);

int entry_verify (entry *rep);

int entry_genPD (P_t *pads,entry *rep,entry_pd *pd);
typedef struct entry_acc_s entry_acc;
struct entry_acc_s {
  Puint32_acc nerr;
  Pstring_acc name;
  Puint32_acc dist;
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
struct tree_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  struct _tree_pd_s *val;
};
typedef struct _tree_s *tree;
typedef struct _tree_m_s *tree_m;
typedef struct tree_pd_s tree_pd;
typedef void *tree_acc;
extern Perror_t tree_init (P_t *,tree *);
extern Perror_t tree_pd_init (P_t *,tree_pd *);
extern Perror_t tree_cleanup (P_t *,tree *);
extern Perror_t tree_pd_cleanup (P_t *,tree_pd *);
extern Perror_t tree_copy (P_t *,tree *,tree *);
extern Perror_t tree_pd_copy (P_t *,tree_pd *,tree_pd *);
extern void tree_m_init (P_t *,tree_m *,Pbase_m);
extern Perror_t tree_read (P_t *,tree_m *,tree_pd *,tree *);
extern int tree_verify (tree *);
extern int tree_genPD (P_t *,tree *,tree_pd *);
extern Perror_t tree_acc_init (P_t *,tree_acc *);
extern Perror_t tree_acc_reset (P_t *,tree_acc *);
extern Perror_t tree_acc_cleanup (P_t *,tree_acc *);
extern Perror_t tree_acc_add (P_t *,tree_acc *,tree_pd *,tree *);
extern Perror_t tree_acc_report2io (P_t *,Sfio_t *,char const *,char const *,int,tree_acc *);
extern Perror_t tree_acc_report (P_t *,char const *,char const *,int,tree_acc *);
extern Perror_t tree_acc_report2xml_io (P_t *,Sfio_t *,int,tree_acc *);
extern ssize_t tree_write2buf (P_t *,Pbyte *,size_t,int *,tree_pd *,tree *);
extern ssize_t tree_write2io (P_t *,Sfio_t *,tree_pd *,tree *);
extern ssize_t tree_write_xml_2buf (P_t *,Pbyte *,size_t,int *,tree_pd *,tree *,char const *,int);
extern ssize_t tree_write_xml_2io (P_t *,Sfio_t *,tree_pd *,tree *,char const *,int);
extern ssize_t tree_fmt2buf_final (P_t *,Pbyte *,size_t,int *,int *,char const *,tree_m *,tree_pd *,tree *);
extern ssize_t tree_fmt2buf (P_t *,Pbyte *,size_t,int *,int *,char const *,tree_m *,tree_pd *,tree *);
extern ssize_t tree_fmt2io (P_t *,Sfio_t *,int *,char const *,tree_m *,tree_pd *,tree *);
typedef enum tip_t_tag_e tip_t_tag;
typedef union tip_t_u_u tip_t_u;
typedef struct tip_t_s tip_t;
typedef struct tip_t_m_s tip_t_m;
typedef union tip_t_pd_u_u tip_t_pd_u;
typedef struct tip_t_pd_s tip_t_pd;
enum tip_t_tag_e {
  tip_t_err=0,
  some_tip_t=1,
  none_tip_t=2
  };
union tip_t_pd_u_u {
  entry_pd some_tip_t;
  Pbase_pd none_tip_t;		/* value was not present. none_tip_t = 0 */
};
struct tip_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  tip_t_tag tag;
  tip_t_pd_u val;
};
union tip_t_u_u {
  entry some_tip_t;		/* value is present */
};
struct tip_t_s {
  tip_t_tag tag;
  tip_t_u val;
};
struct tip_t_m_s {
  Pbase_m compoundLevel;
  entry_m some_tip_t;		/* nested constraints */
  Pbase_m none_tip_t;		/* nested constraints */
};

ssize_t tip_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,tip_t_pd *pd,tip_t *rep);

ssize_t tip_t_write2io (P_t *pads,Sfio_t *io,tip_t_pd *pd,tip_t *rep);

ssize_t tip_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,tip_t_pd *pd,tip_t *rep,char const *_tag,int indent);

ssize_t tip_t_write_xml_2io (P_t *pads,Sfio_t *io,tip_t_pd *pd,tip_t *rep,char const *_tag,int indent);

char const *tip_t_tag2str (tip_t_tag which);

Perror_t tip_t_init (P_t *pads,tip_t *rep);

Perror_t tip_t_pd_init (P_t *pads,tip_t_pd *pd);

Perror_t tip_t_cleanup (P_t *pads,tip_t *rep);

Perror_t tip_t_pd_cleanup (P_t *pads,tip_t_pd *pd);

Perror_t tip_t_copy (P_t *pads,tip_t *rep_dst,tip_t *rep_src);

Perror_t tip_t_pd_copy (P_t *pads,tip_t_pd *pd_dst,tip_t_pd *pd_src);

void tip_t_m_init (P_t *pads,tip_t_m *mask,Pbase_m baseMask);

Perror_t tip_t_read (P_t *pads,tip_t_m *m,tip_t_pd *pd,tip_t *rep);

int tip_t_verify (tip_t *rep);

int tip_t_genPD (P_t *pads,tip_t *rep,tip_t_pd *pd);
typedef struct tip_t_acc_s tip_t_acc;
struct tip_t_acc_s {
  Pint32_acc tag;
  entry_acc some_tip_t;
};

Perror_t tip_t_acc_init (P_t *pads,tip_t_acc *acc);

Perror_t tip_t_acc_reset (P_t *pads,tip_t_acc *acc);

Perror_t tip_t_acc_cleanup (P_t *pads,tip_t_acc *acc);

Perror_t tip_t_acc_add (P_t *pads,tip_t_acc *acc,tip_t_pd *pd,tip_t *rep);

Perror_t tip_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,tip_t_acc *acc);

Perror_t tip_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,tip_t_acc *acc);

Perror_t tip_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,tip_t_acc *acc);

ssize_t tip_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,tip_t_m *m,tip_t_pd *pd,tip_t *rep);

ssize_t tip_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,tip_t_m *m,tip_t_pd *pd,tip_t *rep);

ssize_t tip_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,tip_t_m *m,tip_t_pd *pd,tip_t *rep);
typedef enum inode_tag_e inode_tag;
typedef union inode_u_u inode_u;
typedef struct inode_s inode;
typedef struct inode_m_s inode_m;
typedef union inode_pd_u_u inode_pd_u;
typedef struct inode_pd_s inode_pd;
enum inode_tag_e {
  inode_err=0,
  interior=1,
  tip=2
  };
union inode_pd_u_u {
  tree_pd interior;
  tip_t_pd tip;
};
struct inode_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  inode_tag tag;
  inode_pd_u val;
};
union inode_u_u {
  tree interior;
  tip_t tip;
};
struct inode_s {
  inode_tag tag;
  inode_u val;
};
struct inode_m_s {
  Pbase_m compoundLevel;
  tree_m interior;		/* nested constraints */
  tip_t_m tip;		/* nested constraints */
};

ssize_t inode_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,inode_pd *pd,inode *rep);

ssize_t inode_write2io (P_t *pads,Sfio_t *io,inode_pd *pd,inode *rep);

ssize_t inode_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,inode_pd *pd,inode *rep,char const *_tag,int indent);

ssize_t inode_write_xml_2io (P_t *pads,Sfio_t *io,inode_pd *pd,inode *rep,char const *_tag,int indent);

char const *inode_tag2str (inode_tag which);

Perror_t inode_init (P_t *pads,inode *rep);

Perror_t inode_pd_init (P_t *pads,inode_pd *pd);

Perror_t inode_cleanup (P_t *pads,inode *rep);

Perror_t inode_pd_cleanup (P_t *pads,inode_pd *pd);

Perror_t inode_copy (P_t *pads,inode *rep_dst,inode *rep_src);

Perror_t inode_pd_copy (P_t *pads,inode_pd *pd_dst,inode_pd *pd_src);

void inode_m_init (P_t *pads,inode_m *mask,Pbase_m baseMask);

Perror_t inode_read (P_t *pads,inode_m *m,inode_pd *pd,inode *rep);

int inode_verify (inode *rep);

int inode_genPD (P_t *pads,inode *rep,inode_pd *pd);
typedef struct inode_acc_s inode_acc;
struct inode_acc_s {
  Pint32_acc tag;
  tree_acc interior;
  tip_t_acc tip;
};

Perror_t inode_acc_init (P_t *pads,inode_acc *acc);

Perror_t inode_acc_reset (P_t *pads,inode_acc *acc);

Perror_t inode_acc_cleanup (P_t *pads,inode_acc *acc);

Perror_t inode_acc_add (P_t *pads,inode_acc *acc,inode_pd *pd,inode *rep);

Perror_t inode_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,inode_acc *acc);

Perror_t inode_acc_report (P_t *pads,char const *prefix,char const *what,int nst,inode_acc *acc);

Perror_t inode_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,inode_acc *acc);

ssize_t inode_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,inode_m *m,inode_pd *pd,inode *rep);

ssize_t inode_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,inode_m *m,inode_pd *pd,inode *rep);

ssize_t inode_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,inode_m *m,inode_pd *pd,inode *rep);
typedef struct branches_t_s branches_t;
typedef struct branches_t_m_s branches_t_m;
typedef struct branches_t_pd_s branches_t_pd;
typedef struct branches_t_ro_params_t_s branches_t_ro_params_t;
struct branches_t_m_s {
  inode_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct branches_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  inode_pd *elts;
  RBuf_t *_internal;
};
struct branches_t_s {
  Puint32 length;
  inode *elts;
  RBuf_t *_internal;
};
struct branches_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t branches_t_init (P_t *pads,branches_t *rep);

Perror_t branches_t_pd_init (P_t *pads,branches_t_pd *pd);

Perror_t branches_t_cleanup (P_t *pads,branches_t *rep);

Perror_t branches_t_pd_cleanup (P_t *pads,branches_t_pd *pd);

Perror_t branches_t_copy (P_t *pads,branches_t *rep_dst,branches_t *rep_src);

Perror_t branches_t_pd_copy (P_t *pads,branches_t_pd *pd_dst,branches_t_pd *pd_src);

void branches_t_m_init (P_t *pads,branches_t_m *mask,Pbase_m baseMask);

void branches_t_ro_params_init (branches_t_ro_params_t *params);

Pread_res_t branches_t_final_checks (P_t *pads,branches_t_m *m,branches_t_pd *pd,branches_t *rep,Ploc_t *loc_ptr,int foundTerm,int consume);

Pread_res_t branches_t_read_one_init (P_t *pads,branches_t_m *m,branches_t_pd *pd,branches_t *rep,Ploc_t *loc_ptr);

Pread_res_t branches_t_read_one (P_t *pads,branches_t_m *m,branches_t_pd *pd,branches_t *rep,Ploc_t *loc_ptr,inode_pd *elt_pd,inode *elt_rep);

Perror_t branches_t_read (P_t *pads,branches_t_m *m,branches_t_pd *pd,branches_t *rep);

Pread_res_t branches_t_reread_one (P_t *pads,branches_t_m *m,branches_t_pd *pd,branches_t *rep,Ploc_t *loc_ptr,inode_pd *elt_pd,inode *elt_rep,int notFirstElt);

int branches_t_verify (branches_t *rep);

int branches_t_genPD (P_t *pads,branches_t *rep,branches_t_pd *pd);
typedef struct branches_t_acc_s branches_t_acc;
struct branches_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  inode_acc compoundLevel;		/* Accumulator for all array elements */
  inode_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t branches_t_acc_init (P_t *pads,branches_t_acc *acc);

Perror_t branches_t_acc_reset (P_t *pads,branches_t_acc *acc);

Perror_t branches_t_acc_cleanup (P_t *pads,branches_t_acc *acc);

Perror_t branches_t_acc_add (P_t *pads,branches_t_acc *acc,branches_t_pd *pd,branches_t *rep);

Perror_t branches_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,branches_t_acc *acc);

Perror_t branches_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,branches_t_acc *acc);

Perror_t branches_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,branches_t_acc *acc);

ssize_t branches_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,branches_t_pd *pd,branches_t *rep);

ssize_t branches_t_write2io (P_t *pads,Sfio_t *io,branches_t_pd *pd,branches_t *rep);

ssize_t branches_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,branches_t_pd *pd,branches_t *rep,char const *_tag,int indent);

ssize_t branches_t_write_xml_2io (P_t *pads,Sfio_t *io,branches_t_pd *pd,branches_t *rep,char const *_tag,int indent);

ssize_t branches_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,branches_t_m *m,branches_t_pd *pd,branches_t *rep);

ssize_t branches_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,branches_t_m *m,branches_t_pd *pd,branches_t *rep);

ssize_t branches_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,branches_t_m *m,branches_t_pd *pd,branches_t *rep);
typedef struct _tree_s _tree;
typedef struct _tree_m_s _tree_m;
typedef struct _tree_pd_s _tree_pd;
struct _tree_m_s {
  Pbase_m compoundLevel;
  branches_t_m branches;		/* nested constraints */
};
struct _tree_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  branches_t_pd branches;
};
struct _tree_s {
  branches_t branches;
};

Perror_t _tree_init (P_t *pads,_tree *rep);

Perror_t _tree_pd_init (P_t *pads,_tree_pd *pd);

Perror_t _tree_cleanup (P_t *pads,_tree *rep);

Perror_t _tree_pd_cleanup (P_t *pads,_tree_pd *pd);

Perror_t _tree_copy (P_t *pads,_tree *rep_dst,_tree *rep_src);

Perror_t _tree_pd_copy (P_t *pads,_tree_pd *pd_dst,_tree_pd *pd_src);

void _tree_m_init (P_t *pads,_tree_m *mask,Pbase_m baseMask);

Perror_t _tree_read (P_t *pads,_tree_m *m,_tree_pd *pd,_tree *rep);

int _tree_verify (_tree *rep);

int _tree_genPD (P_t *pads,_tree *rep,_tree_pd *pd);
typedef struct _tree_acc_s _tree_acc;
struct _tree_acc_s {
  Puint32_acc nerr;
  branches_t_acc branches;
};

Perror_t _tree_acc_init (P_t *pads,_tree_acc *acc);

Perror_t _tree_acc_reset (P_t *pads,_tree_acc *acc);

Perror_t _tree_acc_cleanup (P_t *pads,_tree_acc *acc);

Perror_t _tree_acc_add (P_t *pads,_tree_acc *acc,_tree_pd *pd,_tree *rep);

Perror_t _tree_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_tree_acc *acc);

Perror_t _tree_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_tree_acc *acc);

Perror_t _tree_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_tree_acc *acc);

ssize_t _tree_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_tree_pd *pd,_tree *rep);

ssize_t _tree_write2io (P_t *pads,Sfio_t *io,_tree_pd *pd,_tree *rep);

ssize_t _tree_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_tree_pd *pd,_tree *rep,char const *_tag,int indent);

ssize_t _tree_write_xml_2io (P_t *pads,Sfio_t *io,_tree_pd *pd,_tree *rep,char const *_tag,int indent);

ssize_t _tree_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_tree_m *m,_tree_pd *pd,_tree *rep);

ssize_t _tree_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_tree_m *m,_tree_pd *pd,_tree *rep);

ssize_t _tree_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_tree_m *m,_tree_pd *pd,_tree *rep);

Perror_t tree_init (P_t *pads,tree *rep);

Perror_t tree_pd_init (P_t *pads,tree_pd *pd);

Perror_t tree_cleanup (P_t *pads,tree *rep);

Perror_t tree_pd_cleanup (P_t *pads,tree_pd *pd);

Perror_t tree_copy (P_t *pads,tree *rep_dst,tree *rep_src);

Perror_t tree_pd_copy (P_t *pads,tree_pd *pd_dst,tree_pd *pd_src);

void tree_m_init (P_t *pads,tree_m *mask,Pbase_m baseMask);

Perror_t tree_read (P_t *pads,tree_m *m,tree_pd *pd,tree *rep);

int tree_verify (tree *rep);

int tree_genPD (P_t *pads,tree *rep,tree_pd *pd);

Perror_t tree_acc_init (P_t *pads,tree_acc *acc);

Perror_t tree_acc_reset (P_t *pads,tree_acc *acc);

Perror_t tree_acc_cleanup (P_t *pads,tree_acc *acc);

Perror_t tree_acc_add (P_t *pads,tree_acc *acc,tree_pd *pd,tree *rep);

Perror_t tree_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,tree_acc *acc);

Perror_t tree_acc_report (P_t *pads,char const *prefix,char const *what,int nst,tree_acc *acc);

Perror_t tree_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,tree_acc *acc);

ssize_t tree_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,tree_pd *pd,tree *rep);

ssize_t tree_write2io (P_t *pads,Sfio_t *io,tree_pd *pd,tree *rep);

ssize_t tree_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,tree_pd *pd,tree *rep,char const *_tag,int indent);

ssize_t tree_write_xml_2io (P_t *pads,Sfio_t *io,tree_pd *pd,tree *rep,char const *_tag,int indent);

ssize_t tree_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,tree_m *m,tree_pd *pd,tree *rep);

ssize_t tree_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,tree_m *m,tree_pd *pd,tree *rep);

ssize_t tree_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,tree_m *m,tree_pd *pd,tree *rep);

void P_lib_init ();

#endif /*  __NEWICK__H__  */
