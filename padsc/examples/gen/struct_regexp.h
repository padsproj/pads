#ifndef __STRUCT_REGEXP__H__
#define __STRUCT_REGEXP__H__
#include "pads.h"
typedef struct line_s line;
typedef struct line_m_s line_m;
typedef struct line_pd_s line_pd;
struct line_m_s {
  Pbase_m compoundLevel;
  Pbase_m f;		/* nested constraints */
  Pbase_m g;		/* nested constraints */
  Pbase_m h;		/* nested constraints */
  Pbase_m i;		/* nested constraints */
};
struct line_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd f;
  Pbase_pd g;
  Pbase_pd h;
  Pbase_pd i;
};
struct line_s {
  Pint32 f;
  Pint32 g;
  Pint32 h;
  Pint32 i;
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
  Pint32_acc f;
  Pint32_acc g;
  Pint32_acc h;
  Pint32_acc i;
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

void P_lib_init ();

#endif /*  __STRUCT_REGEXP__H__  */
