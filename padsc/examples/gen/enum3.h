#ifndef __ENUM3__H__
#define __ENUM3__H__
#include "pads.h"
typedef enum FixityDirection_e FixityDirection;
typedef Pbase_m FixityDirection_m;
typedef Pbase_pd FixityDirection_pd;
enum FixityDirection_e {
  InfixL=76,
  InfixR=82,
  InfixN=78
  };

char const *FixityDirection2str (FixityDirection which);

Perror_t FixityDirection_init (P_t *pads,FixityDirection *rep);

Perror_t FixityDirection_pd_init (P_t *pads,FixityDirection_pd *pd);

Perror_t FixityDirection_cleanup (P_t *pads,FixityDirection *rep);

Perror_t FixityDirection_pd_cleanup (P_t *pads,FixityDirection_pd *pd);

Perror_t FixityDirection_copy (P_t *pads,FixityDirection *rep_dst,FixityDirection *rep_src);

Perror_t FixityDirection_pd_copy (P_t *pads,FixityDirection_pd *pd_dst,FixityDirection_pd *pd_src);

void FixityDirection_m_init (P_t *pads,FixityDirection_m *mask,Pbase_m baseMask);

Perror_t FixityDirection_m_rec_init (P_t *pads,FixityDirection_m *mask,Pbase_m baseMask);

Perror_t FixityDirection_read (P_t *pads,FixityDirection_m *m,FixityDirection_pd *pd,FixityDirection *rep);

int FixityDirection_verify (P_t *pads,FixityDirection *rep);

int FixityDirection_genPD (P_t *pads,FixityDirection *rep,FixityDirection_pd *pd);
typedef Pint32_acc FixityDirection_acc;

Perror_t FixityDirection_acc_init (P_t *pads,FixityDirection_acc *acc);

Perror_t FixityDirection_acc_reset (P_t *pads,FixityDirection_acc *acc);

Perror_t FixityDirection_acc_cleanup (P_t *pads,FixityDirection_acc *acc);

Perror_t FixityDirection_acc_add (P_t *pads,FixityDirection_acc *acc,FixityDirection_pd *pd,FixityDirection *rep);

Perror_t FixityDirection_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,FixityDirection_acc *acc);

Perror_t FixityDirection_acc_report (P_t *pads,char const *prefix,char const *what,int nst,FixityDirection_acc *acc);

Perror_t FixityDirection_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,FixityDirection_acc *acc);

ssize_t FixityDirection_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,FixityDirection_pd *pd,FixityDirection *rep);

ssize_t FixityDirection_write2io (P_t *pads,Sfio_t *io,FixityDirection_pd *pd,FixityDirection *rep);

ssize_t FixityDirection_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,FixityDirection_pd *pd,FixityDirection *rep,char const *_tag,int indent);

ssize_t FixityDirection_write_xml_2io (P_t *pads,Sfio_t *io,FixityDirection_pd *pd,FixityDirection *rep,char const *_tag,int indent);

ssize_t FixityDirection_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,FixityDirection_m *m,FixityDirection_pd *pd,FixityDirection *rep);

ssize_t FixityDirection_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,FixityDirection_m *m,FixityDirection_pd *pd,FixityDirection *rep);

ssize_t FixityDirection_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,FixityDirection_m *m,FixityDirection_pd *pd,FixityDirection *rep);

void P_lib_init ();

#endif /*  __ENUM3__H__  */
