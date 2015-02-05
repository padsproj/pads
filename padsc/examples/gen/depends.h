#ifndef __DEPENDS__H__
#define __DEPENDS__H__
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
  Pint32 *elts;
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

Pread_res_t intList_final_checks (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,int foundTerm,int consume);

Pread_res_t intList_read_one_init (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr);

Pread_res_t intList_read_one (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep);

Perror_t intList_read (P_t *pads,intList_m *m,intList_pd *pd,intList *rep);

Pread_res_t intList_reread_one (P_t *pads,intList_m *m,intList_pd *pd,intList *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pint32 *elt_rep,int notFirstElt);

int intList_verify (P_t *pads,intList *rep);

int intList_genPD (P_t *pads,intList *rep,intList_pd *pd);
typedef struct intList_acc_s intList_acc;
struct intList_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Pint32_acc compoundLevel;		/* Accumulator for all array elements */
  Pint32_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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
typedef enum auth_id_t_tag_e auth_id_t_tag;
typedef union auth_id_t_u_u auth_id_t_u;
typedef struct auth_id_t_s auth_id_t;
typedef struct auth_id_t_m_s auth_id_t_m;
typedef union auth_id_t_pd_u_u auth_id_t_pd_u;
typedef struct auth_id_t_pd_s auth_id_t_pd;
enum auth_id_t_tag_e {
  auth_id_t_err=0,
  unauthorized=1,
  id=2
  };
union auth_id_t_pd_u_u {
  Pbase_pd unauthorized;
  Pbase_pd id;
};
struct auth_id_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  auth_id_t_tag tag;
  auth_id_t_pd_u val;
};
union auth_id_t_u_u {
  Pchar unauthorized;		/*  non-authenticated http session. unauthorized == -&& */
  Pstring id;		/*  login supplied during authentication */
};
struct auth_id_t_s {
  auth_id_t_tag tag;
  auth_id_t_u val;
};
struct auth_id_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m unauthorized;		/* nested constraints */
  Pbase_m unauthorized_con;		/* union constraints */
  Pbase_m id;		/* nested constraints */
};

ssize_t auth_id_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,auth_id_t_pd *pd,auth_id_t *rep);

ssize_t auth_id_t_write2io (P_t *pads,Sfio_t *io,auth_id_t_pd *pd,auth_id_t *rep);

ssize_t auth_id_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,auth_id_t_pd *pd,auth_id_t *rep,char const *_tag,int indent);

ssize_t auth_id_t_write_xml_2io (P_t *pads,Sfio_t *io,auth_id_t_pd *pd,auth_id_t *rep,char const *_tag,int indent);

char const *auth_id_t_tag2str (auth_id_t_tag which);

Perror_t auth_id_t_init (P_t *pads,auth_id_t *rep);

Perror_t auth_id_t_pd_init (P_t *pads,auth_id_t_pd *pd);

Perror_t auth_id_t_cleanup (P_t *pads,auth_id_t *rep);

Perror_t auth_id_t_pd_cleanup (P_t *pads,auth_id_t_pd *pd);

Perror_t auth_id_t_copy (P_t *pads,auth_id_t *rep_dst,auth_id_t *rep_src);

Perror_t auth_id_t_pd_copy (P_t *pads,auth_id_t_pd *pd_dst,auth_id_t_pd *pd_src);

void auth_id_t_m_init (P_t *pads,auth_id_t_m *mask,Pbase_m baseMask);

Perror_t auth_id_t_m_rec_init (P_t *pads,auth_id_t_m *mask,Pbase_m baseMask);

Perror_t auth_id_t_read (P_t *pads,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep);

int auth_id_t_verify (P_t *pads,auth_id_t *rep);

int auth_id_t_genPD (P_t *pads,auth_id_t *rep,auth_id_t_pd *pd);
typedef struct auth_id_t_acc_s auth_id_t_acc;
struct auth_id_t_acc_s {
  Pint32_acc tag;
  Pchar_acc unauthorized;
  Pstring_acc id;
};

Perror_t auth_id_t_acc_init (P_t *pads,auth_id_t_acc *acc);

Perror_t auth_id_t_acc_reset (P_t *pads,auth_id_t_acc *acc);

Perror_t auth_id_t_acc_cleanup (P_t *pads,auth_id_t_acc *acc);

Perror_t auth_id_t_acc_add (P_t *pads,auth_id_t_acc *acc,auth_id_t_pd *pd,auth_id_t *rep);

Perror_t auth_id_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,auth_id_t_acc *acc);

Perror_t auth_id_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,auth_id_t_acc *acc);

Perror_t auth_id_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,auth_id_t_acc *acc);

ssize_t auth_id_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep);

ssize_t auth_id_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep);

ssize_t auth_id_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep);

int check (Pint32 t,auth_id_t user);
typedef struct line_s line;
typedef struct line_m_s line_m;
typedef struct line_pd_s line_pd;
struct line_m_s {
  Pbase_m compoundLevel;
  intList_m f;		/* nested constraints */
  Pbase_m a;		/* nested constraints */
  Pbase_m a_con;		/* struct constraints */
  auth_id_t_m user;		/* nested constraints */
  Pbase_m t;		/* nested constraints */
  Pbase_m t_con;		/* struct constraints */
};
struct line_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  intList_pd f;
  Pbase_pd a;
  auth_id_t_pd user;
  Pbase_pd t;
};
struct line_s {
  intList f;
  Pint32 a;		/* a == f.length&& */
  auth_id_t user;
  Pint32 t;		/* check(t, user)&& */
};

Perror_t line_init (P_t *pads,line *rep);

Perror_t line_pd_init (P_t *pads,line_pd *pd);

Perror_t line_cleanup (P_t *pads,line *rep);

Perror_t line_pd_cleanup (P_t *pads,line_pd *pd);

Perror_t line_copy (P_t *pads,line *rep_dst,line *rep_src);

Perror_t line_pd_copy (P_t *pads,line_pd *pd_dst,line_pd *pd_src);

void line_m_init (P_t *pads,line_m *mask,Pbase_m baseMask);

Perror_t line_m_rec_init (P_t *pads,line_m *mask,Pbase_m baseMask);

Perror_t line_read (P_t *pads,line_m *m,line_pd *pd,line *rep);

int line_verify (P_t *pads,line *rep);

int line_genPD (P_t *pads,line *rep,line_pd *pd);
typedef struct line_acc_s line_acc;
struct line_acc_s {
  Puint32_acc nerr;
  intList_acc f;
  Pint32_acc a;		/* a == f.length&& */
  auth_id_t_acc user;
  Pint32_acc t;		/* check(t, user)&& */
};

Perror_t line_acc_init (P_t *pads,line_acc *acc);

Perror_t line_acc_reset (P_t *pads,line_acc *acc);

Perror_t line_acc_cleanup (P_t *pads,line_acc *acc);

Perror_t line_acc_add (P_t *pads,line_acc *acc,line_pd *pd,line *rep);

Perror_t line_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,line_acc *acc);

Perror_t line_acc_report (P_t *pads,char const *prefix,char const *what,int nst,line_acc *acc);

Perror_t line_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,line_acc *acc);

ssize_t line_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,line_pd *pd,line *rep);

ssize_t line_write2io (P_t *pads,Sfio_t *io,line_pd *pd,line *rep);

ssize_t line_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,line_pd *pd,line *rep,char const *_tag,int indent);

ssize_t line_write_xml_2io (P_t *pads,Sfio_t *io,line_pd *pd,line *rep,char const *_tag,int indent);

ssize_t line_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);

ssize_t line_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);

ssize_t line_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,line_m *m,line_pd *pd,line *rep);
typedef struct source_s source;
typedef struct source_m_s source_m;
typedef struct source_pd_s source_pd;
typedef struct source_ro_params_t_s source_ro_params_t;
struct source_m_s {
  line_m element;		/* per-element */
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
  line_pd *elts;
  RBuf_t *_internal;
};
struct source_s {
  Puint32 length;
  line *elts;
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

Pread_res_t source_read_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,line_pd *elt_pd,line *elt_rep);

Perror_t source_read (P_t *pads,source_m *m,source_pd *pd,source *rep);

Pread_res_t source_reread_one (P_t *pads,source_m *m,source_pd *pd,source *rep,Ploc_t *loc_ptr,line_pd *elt_pd,line *elt_rep,int notFirstElt);

int source_verify (P_t *pads,source *rep);

int source_genPD (P_t *pads,source *rep,source_pd *pd);
typedef struct source_acc_s source_acc;
struct source_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  line_acc compoundLevel;		/* Accumulator for all array elements */
  line_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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

#endif /*  __DEPENDS__H__  */
