#ifndef __PDATE_EXPLICIT__H__
#define __PDATE_EXPLICIT__H__
#include "pads.h"
typedef struct threedates_s threedates;
typedef struct threedates_m_s threedates_m;
typedef struct threedates_pd_s threedates_pd;
struct threedates_m_s {
  Pbase_m compoundLevel;
  Pbase_m date1;		/* nested constraints */
  Pbase_m date2;		/* nested constraints */
  Pbase_m date3;		/* nested constraints */
};
struct threedates_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd date1;
  Pbase_pd date2;
  Pbase_pd date3;
};
struct threedates_s {
  Pdate date1;
  Pdate date2;
  Pdate date3;
};

Perror_t threedates_init (P_t *pads,threedates *rep);

Perror_t threedates_pd_init (P_t *pads,threedates_pd *pd);

Perror_t threedates_cleanup (P_t *pads,threedates *rep);

Perror_t threedates_pd_cleanup (P_t *pads,threedates_pd *pd);

Perror_t threedates_copy (P_t *pads,threedates *rep_dst,threedates *rep_src);

Perror_t threedates_pd_copy (P_t *pads,threedates_pd *pd_dst,threedates_pd *pd_src);

void threedates_m_init (P_t *pads,threedates_m *mask,Pbase_m baseMask);

Perror_t threedates_m_rec_init (P_t *pads,threedates_m *mask,Pbase_m baseMask);

Perror_t threedates_read (P_t *pads,threedates_m *m,threedates_pd *pd,threedates *rep);

int threedates_verify (P_t *pads,threedates *rep);

int threedates_genPD (P_t *pads,threedates *rep,threedates_pd *pd);
typedef struct threedates_acc_s threedates_acc;
struct threedates_acc_s {
  Puint32_acc nerr;
  Pdate_acc date1;
  Pdate_explicit_acc date2;
  Pdate_explicit_acc date3;
};

Perror_t threedates_acc_init (P_t *pads,threedates_acc *acc);

Perror_t threedates_acc_reset (P_t *pads,threedates_acc *acc);

Perror_t threedates_acc_cleanup (P_t *pads,threedates_acc *acc);

Perror_t threedates_acc_add (P_t *pads,threedates_acc *acc,threedates_pd *pd,threedates *rep);

Perror_t threedates_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,threedates_acc *acc);

Perror_t threedates_acc_report (P_t *pads,char const *prefix,char const *what,int nst,threedates_acc *acc);

Perror_t threedates_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,threedates_acc *acc);

ssize_t threedates_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threedates_pd *pd,threedates *rep);

ssize_t threedates_write2io (P_t *pads,Sfio_t *io,threedates_pd *pd,threedates *rep);

ssize_t threedates_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,threedates_pd *pd,threedates *rep,char const *_tag,int indent);

ssize_t threedates_write_xml_2io (P_t *pads,Sfio_t *io,threedates_pd *pd,threedates *rep,char const *_tag,int indent);

ssize_t threedates_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threedates_m *m,threedates_pd *pd,threedates *rep);

ssize_t threedates_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,threedates_m *m,threedates_pd *pd,threedates *rep);

ssize_t threedates_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,threedates_m *m,threedates_pd *pd,threedates *rep);

void P_lib_init ();

#endif /*  __PDATE_EXPLICIT__H__  */
