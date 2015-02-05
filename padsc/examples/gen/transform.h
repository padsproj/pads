#ifndef __TRANSFORM__H__
#define __TRANSFORM__H__
#include "pads.h"

int hexCharToInt (char c);

char intToHexChar (Puint32 h);

void toInt32 (Pstring *src,Pbase_pd *src_pd,Puint32 *dest,Pbase_pd *dest_pd);

void toHexString (P_t *p,Puint32 size,Puint32 *src,Pbase_pd *src_pd,Pstring *dest,Pbase_pd *dest_pd);

void cnvMask (Pbase_m *phy,Pbase_m *log);
typedef Pbase_m hexint32_m;
typedef Pbase_pd hexint32_pd;
typedef Puint32 hexint32;

Perror_t hexint32_init (P_t *pads,hexint32 *rep);

Perror_t hexint32_pd_init (P_t *pads,hexint32_pd *pd);

Perror_t hexint32_cleanup (P_t *pads,hexint32 *rep);

Perror_t hexint32_pd_cleanup (P_t *pads,hexint32_pd *pd);

Perror_t hexint32_copy (P_t *pads,hexint32 *rep_dst,hexint32 *rep_src);

Perror_t hexint32_pd_copy (P_t *pads,hexint32_pd *pd_dst,hexint32_pd *pd_src);

void hexint32_m_init (P_t *pads,hexint32_m *mask,Pbase_m baseMask);

Perror_t hexint32_m_rec_init (P_t *pads,hexint32_m *mask,Pbase_m baseMask);

Perror_t hexint32_read (P_t *pads,hexint32_m *m,hexint32_pd *pd,hexint32 *rep,Puint32 size);

int hexint32_verify (P_t *pads,hexint32 *rep,Puint32 size);

int hexint32_genPD (P_t *pads,hexint32 *rep,hexint32_pd *pd,Puint32 size);
typedef Puint32_acc hexint32_acc;

Perror_t hexint32_acc_init (P_t *pads,hexint32_acc *acc);

Perror_t hexint32_acc_reset (P_t *pads,hexint32_acc *acc);

Perror_t hexint32_acc_cleanup (P_t *pads,hexint32_acc *acc);

Perror_t hexint32_acc_add (P_t *pads,hexint32_acc *acc,hexint32_pd *pd,hexint32 *rep);

Perror_t hexint32_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,hexint32_acc *acc);

Perror_t hexint32_acc_report (P_t *pads,char const *prefix,char const *what,int nst,hexint32_acc *acc);

Perror_t hexint32_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,hexint32_acc *acc);

ssize_t hexint32_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,hexint32_pd *pd,hexint32 *rep,Puint32 size);

ssize_t hexint32_write2io (P_t *pads,Sfio_t *io,hexint32_pd *pd,hexint32 *rep,Puint32 size);

ssize_t hexint32_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,hexint32_pd *pd,hexint32 *rep,char const *_tag,int indent,Puint32 size);

ssize_t hexint32_write_xml_2io (P_t *pads,Sfio_t *io,hexint32_pd *pd,hexint32 *rep,char const *_tag,int indent,Puint32 size);

ssize_t hexint32_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,hexint32_m *m,hexint32_pd *pd,hexint32 *rep,Puint32 size);

ssize_t hexint32_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,hexint32_m *m,hexint32_pd *pd,hexint32 *rep,Puint32 size);

ssize_t hexint32_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,hexint32_m *m,hexint32_pd *pd,hexint32 *rep,Puint32 size);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  hexint32_m f;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  hexint32_pd f;
};
struct entry_t_s {
  hexint32 f;
};

Perror_t entry_t_init (P_t *pads,entry_t *rep);

Perror_t entry_t_pd_init (P_t *pads,entry_t_pd *pd);

Perror_t entry_t_cleanup (P_t *pads,entry_t *rep);

Perror_t entry_t_pd_cleanup (P_t *pads,entry_t_pd *pd);

Perror_t entry_t_copy (P_t *pads,entry_t *rep_dst,entry_t *rep_src);

Perror_t entry_t_pd_copy (P_t *pads,entry_t_pd *pd_dst,entry_t_pd *pd_src);

void entry_t_m_init (P_t *pads,entry_t_m *mask,Pbase_m baseMask);

Perror_t entry_t_m_rec_init (P_t *pads,entry_t_m *mask,Pbase_m baseMask);

Perror_t entry_t_read (P_t *pads,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

int entry_t_verify (P_t *pads,entry_t *rep);

int entry_t_genPD (P_t *pads,entry_t *rep,entry_t_pd *pd);
typedef struct entry_t_acc_s entry_t_acc;
struct entry_t_acc_s {
  Puint32_acc nerr;
  hexint32_acc f;
};

Perror_t entry_t_acc_init (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_reset (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_cleanup (P_t *pads,entry_t_acc *acc);

Perror_t entry_t_acc_add (P_t *pads,entry_t_acc *acc,entry_t_pd *pd,entry_t *rep);

Perror_t entry_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entry_t_acc *acc);

Perror_t entry_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entry_t_acc *acc);

Perror_t entry_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,entry_t_acc *acc);

ssize_t entry_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_write2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep,char const *_tag,int indent);

ssize_t entry_t_write_xml_2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep,char const *_tag,int indent);

ssize_t entry_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

ssize_t entry_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep);

void P_lib_init ();

#endif /*  __TRANSFORM__H__  */
