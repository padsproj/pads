#ifndef __LISTE__H__
#define __LISTE__H__
#include "pads.h"
typedef Pstring PPtime;
typedef struct PPtime_m_s PPtime_m;
typedef Pbase_pd PPtime_pd;
struct PPtime_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPtime_init (P_t *pads,PPtime *rep);

Perror_t PPtime_pd_init (P_t *pads,PPtime_pd *pd);

Perror_t PPtime_cleanup (P_t *pads,PPtime *rep);

Perror_t PPtime_pd_cleanup (P_t *pads,PPtime_pd *pd);

Perror_t PPtime_copy (P_t *pads,PPtime *rep_dst,PPtime *rep_src);

Perror_t PPtime_pd_copy (P_t *pads,PPtime_pd *pd_dst,PPtime_pd *pd_src);

void PPtime_m_init (P_t *pads,PPtime_m *mask,Pbase_m baseMask);

Perror_t PPtime_m_rec_init (P_t *pads,PPtime_m *mask,Pbase_m baseMask);

Perror_t PPtime_read (P_t *pads,PPtime_m *m,PPtime_pd *pd,PPtime *rep);

int PPtime_verify (P_t *pads,PPtime *rep);

int PPtime_genPD (P_t *pads,PPtime *rep,PPtime_pd *pd);
typedef Pstring_acc PPtime_acc;

Perror_t PPtime_acc_init (P_t *pads,PPtime_acc *acc);

Perror_t PPtime_acc_reset (P_t *pads,PPtime_acc *acc);

Perror_t PPtime_acc_cleanup (P_t *pads,PPtime_acc *acc);

Perror_t PPtime_acc_add (P_t *pads,PPtime_acc *acc,PPtime_pd *pd,PPtime *rep);

Perror_t PPtime_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPtime_acc *acc);

Perror_t PPtime_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPtime_acc *acc);

Perror_t PPtime_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPtime_acc *acc);

ssize_t PPtime_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPtime_pd *pd,PPtime *rep);

ssize_t PPtime_write2io (P_t *pads,Sfio_t *io,PPtime_pd *pd,PPtime *rep);

ssize_t PPtime_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPtime_pd *pd,PPtime *rep,char const *_tag,int indent);

ssize_t PPtime_write_xml_2io (P_t *pads,Sfio_t *io,PPtime_pd *pd,PPtime *rep,char const *_tag,int indent);

ssize_t PPtime_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPtime_m *m,PPtime_pd *pd,PPtime *rep);

ssize_t PPtime_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPtime_m *m,PPtime_pd *pd,PPtime *rep);

ssize_t PPtime_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPtime_m *m,PPtime_pd *pd,PPtime *rep);
typedef Pstring PPip;
typedef struct PPip_m_s PPip_m;
typedef Pbase_pd PPip_pd;
struct PPip_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPip_init (P_t *pads,PPip *rep);

Perror_t PPip_pd_init (P_t *pads,PPip_pd *pd);

Perror_t PPip_cleanup (P_t *pads,PPip *rep);

Perror_t PPip_pd_cleanup (P_t *pads,PPip_pd *pd);

Perror_t PPip_copy (P_t *pads,PPip *rep_dst,PPip *rep_src);

Perror_t PPip_pd_copy (P_t *pads,PPip_pd *pd_dst,PPip_pd *pd_src);

void PPip_m_init (P_t *pads,PPip_m *mask,Pbase_m baseMask);

Perror_t PPip_m_rec_init (P_t *pads,PPip_m *mask,Pbase_m baseMask);

Perror_t PPip_read (P_t *pads,PPip_m *m,PPip_pd *pd,PPip *rep);

int PPip_verify (P_t *pads,PPip *rep);

int PPip_genPD (P_t *pads,PPip *rep,PPip_pd *pd);
typedef Pstring_acc PPip_acc;

Perror_t PPip_acc_init (P_t *pads,PPip_acc *acc);

Perror_t PPip_acc_reset (P_t *pads,PPip_acc *acc);

Perror_t PPip_acc_cleanup (P_t *pads,PPip_acc *acc);

Perror_t PPip_acc_add (P_t *pads,PPip_acc *acc,PPip_pd *pd,PPip *rep);

Perror_t PPip_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPip_acc *acc);

Perror_t PPip_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPip_acc *acc);

Perror_t PPip_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPip_acc *acc);

ssize_t PPip_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPip_pd *pd,PPip *rep);

ssize_t PPip_write2io (P_t *pads,Sfio_t *io,PPip_pd *pd,PPip *rep);

ssize_t PPip_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPip_pd *pd,PPip *rep,char const *_tag,int indent);

ssize_t PPip_write_xml_2io (P_t *pads,Sfio_t *io,PPip_pd *pd,PPip *rep,char const *_tag,int indent);

ssize_t PPip_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPip_m *m,PPip_pd *pd,PPip *rep);

ssize_t PPip_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPip_m *m,PPip_pd *pd,PPip *rep);

ssize_t PPip_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPip_m *m,PPip_pd *pd,PPip *rep);
typedef Pstring PPemail;
typedef struct PPemail_m_s PPemail_m;
typedef Pbase_pd PPemail_pd;
struct PPemail_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPemail_init (P_t *pads,PPemail *rep);

Perror_t PPemail_pd_init (P_t *pads,PPemail_pd *pd);

Perror_t PPemail_cleanup (P_t *pads,PPemail *rep);

Perror_t PPemail_pd_cleanup (P_t *pads,PPemail_pd *pd);

Perror_t PPemail_copy (P_t *pads,PPemail *rep_dst,PPemail *rep_src);

Perror_t PPemail_pd_copy (P_t *pads,PPemail_pd *pd_dst,PPemail_pd *pd_src);

void PPemail_m_init (P_t *pads,PPemail_m *mask,Pbase_m baseMask);

Perror_t PPemail_m_rec_init (P_t *pads,PPemail_m *mask,Pbase_m baseMask);

Perror_t PPemail_read (P_t *pads,PPemail_m *m,PPemail_pd *pd,PPemail *rep);

int PPemail_verify (P_t *pads,PPemail *rep);

int PPemail_genPD (P_t *pads,PPemail *rep,PPemail_pd *pd);
typedef Pstring_acc PPemail_acc;

Perror_t PPemail_acc_init (P_t *pads,PPemail_acc *acc);

Perror_t PPemail_acc_reset (P_t *pads,PPemail_acc *acc);

Perror_t PPemail_acc_cleanup (P_t *pads,PPemail_acc *acc);

Perror_t PPemail_acc_add (P_t *pads,PPemail_acc *acc,PPemail_pd *pd,PPemail *rep);

Perror_t PPemail_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPemail_acc *acc);

Perror_t PPemail_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPemail_acc *acc);

Perror_t PPemail_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPemail_acc *acc);

ssize_t PPemail_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPemail_pd *pd,PPemail *rep);

ssize_t PPemail_write2io (P_t *pads,Sfio_t *io,PPemail_pd *pd,PPemail *rep);

ssize_t PPemail_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPemail_pd *pd,PPemail *rep,char const *_tag,int indent);

ssize_t PPemail_write_xml_2io (P_t *pads,Sfio_t *io,PPemail_pd *pd,PPemail *rep,char const *_tag,int indent);

ssize_t PPemail_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPemail_m *m,PPemail_pd *pd,PPemail *rep);

ssize_t PPemail_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPemail_m *m,PPemail_pd *pd,PPemail *rep);

ssize_t PPemail_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPemail_m *m,PPemail_pd *pd,PPemail *rep);
typedef Pstring PPmac;
typedef struct PPmac_m_s PPmac_m;
typedef Pbase_pd PPmac_pd;
struct PPmac_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPmac_init (P_t *pads,PPmac *rep);

Perror_t PPmac_pd_init (P_t *pads,PPmac_pd *pd);

Perror_t PPmac_cleanup (P_t *pads,PPmac *rep);

Perror_t PPmac_pd_cleanup (P_t *pads,PPmac_pd *pd);

Perror_t PPmac_copy (P_t *pads,PPmac *rep_dst,PPmac *rep_src);

Perror_t PPmac_pd_copy (P_t *pads,PPmac_pd *pd_dst,PPmac_pd *pd_src);

void PPmac_m_init (P_t *pads,PPmac_m *mask,Pbase_m baseMask);

Perror_t PPmac_m_rec_init (P_t *pads,PPmac_m *mask,Pbase_m baseMask);

Perror_t PPmac_read (P_t *pads,PPmac_m *m,PPmac_pd *pd,PPmac *rep);

int PPmac_verify (P_t *pads,PPmac *rep);

int PPmac_genPD (P_t *pads,PPmac *rep,PPmac_pd *pd);
typedef Pstring_acc PPmac_acc;

Perror_t PPmac_acc_init (P_t *pads,PPmac_acc *acc);

Perror_t PPmac_acc_reset (P_t *pads,PPmac_acc *acc);

Perror_t PPmac_acc_cleanup (P_t *pads,PPmac_acc *acc);

Perror_t PPmac_acc_add (P_t *pads,PPmac_acc *acc,PPmac_pd *pd,PPmac *rep);

Perror_t PPmac_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPmac_acc *acc);

Perror_t PPmac_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPmac_acc *acc);

Perror_t PPmac_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPmac_acc *acc);

ssize_t PPmac_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPmac_pd *pd,PPmac *rep);

ssize_t PPmac_write2io (P_t *pads,Sfio_t *io,PPmac_pd *pd,PPmac *rep);

ssize_t PPmac_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPmac_pd *pd,PPmac *rep,char const *_tag,int indent);

ssize_t PPmac_write_xml_2io (P_t *pads,Sfio_t *io,PPmac_pd *pd,PPmac *rep,char const *_tag,int indent);

ssize_t PPmac_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPmac_m *m,PPmac_pd *pd,PPmac *rep);

ssize_t PPmac_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPmac_m *m,PPmac_pd *pd,PPmac *rep);

ssize_t PPmac_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPmac_m *m,PPmac_pd *pd,PPmac *rep);
typedef Pstring PPdate;
typedef struct PPdate_m_s PPdate_m;
typedef Pbase_pd PPdate_pd;
struct PPdate_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPdate_init (P_t *pads,PPdate *rep);

Perror_t PPdate_pd_init (P_t *pads,PPdate_pd *pd);

Perror_t PPdate_cleanup (P_t *pads,PPdate *rep);

Perror_t PPdate_pd_cleanup (P_t *pads,PPdate_pd *pd);

Perror_t PPdate_copy (P_t *pads,PPdate *rep_dst,PPdate *rep_src);

Perror_t PPdate_pd_copy (P_t *pads,PPdate_pd *pd_dst,PPdate_pd *pd_src);

void PPdate_m_init (P_t *pads,PPdate_m *mask,Pbase_m baseMask);

Perror_t PPdate_m_rec_init (P_t *pads,PPdate_m *mask,Pbase_m baseMask);

Perror_t PPdate_read (P_t *pads,PPdate_m *m,PPdate_pd *pd,PPdate *rep);

int PPdate_verify (P_t *pads,PPdate *rep);

int PPdate_genPD (P_t *pads,PPdate *rep,PPdate_pd *pd);
typedef Pstring_acc PPdate_acc;

Perror_t PPdate_acc_init (P_t *pads,PPdate_acc *acc);

Perror_t PPdate_acc_reset (P_t *pads,PPdate_acc *acc);

Perror_t PPdate_acc_cleanup (P_t *pads,PPdate_acc *acc);

Perror_t PPdate_acc_add (P_t *pads,PPdate_acc *acc,PPdate_pd *pd,PPdate *rep);

Perror_t PPdate_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPdate_acc *acc);

Perror_t PPdate_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPdate_acc *acc);

Perror_t PPdate_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPdate_acc *acc);

ssize_t PPdate_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPdate_pd *pd,PPdate *rep);

ssize_t PPdate_write2io (P_t *pads,Sfio_t *io,PPdate_pd *pd,PPdate *rep);

ssize_t PPdate_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPdate_pd *pd,PPdate *rep,char const *_tag,int indent);

ssize_t PPdate_write_xml_2io (P_t *pads,Sfio_t *io,PPdate_pd *pd,PPdate *rep,char const *_tag,int indent);

ssize_t PPdate_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPdate_m *m,PPdate_pd *pd,PPdate *rep);

ssize_t PPdate_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPdate_m *m,PPdate_pd *pd,PPdate *rep);

ssize_t PPdate_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPdate_m *m,PPdate_pd *pd,PPdate *rep);
typedef Pstring PPpath;
typedef struct PPpath_m_s PPpath_m;
typedef Pbase_pd PPpath_pd;
struct PPpath_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPpath_init (P_t *pads,PPpath *rep);

Perror_t PPpath_pd_init (P_t *pads,PPpath_pd *pd);

Perror_t PPpath_cleanup (P_t *pads,PPpath *rep);

Perror_t PPpath_pd_cleanup (P_t *pads,PPpath_pd *pd);

Perror_t PPpath_copy (P_t *pads,PPpath *rep_dst,PPpath *rep_src);

Perror_t PPpath_pd_copy (P_t *pads,PPpath_pd *pd_dst,PPpath_pd *pd_src);

void PPpath_m_init (P_t *pads,PPpath_m *mask,Pbase_m baseMask);

Perror_t PPpath_m_rec_init (P_t *pads,PPpath_m *mask,Pbase_m baseMask);

Perror_t PPpath_read (P_t *pads,PPpath_m *m,PPpath_pd *pd,PPpath *rep);

int PPpath_verify (P_t *pads,PPpath *rep);

int PPpath_genPD (P_t *pads,PPpath *rep,PPpath_pd *pd);
typedef Pstring_acc PPpath_acc;

Perror_t PPpath_acc_init (P_t *pads,PPpath_acc *acc);

Perror_t PPpath_acc_reset (P_t *pads,PPpath_acc *acc);

Perror_t PPpath_acc_cleanup (P_t *pads,PPpath_acc *acc);

Perror_t PPpath_acc_add (P_t *pads,PPpath_acc *acc,PPpath_pd *pd,PPpath *rep);

Perror_t PPpath_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPpath_acc *acc);

Perror_t PPpath_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPpath_acc *acc);

Perror_t PPpath_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPpath_acc *acc);

ssize_t PPpath_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPpath_pd *pd,PPpath *rep);

ssize_t PPpath_write2io (P_t *pads,Sfio_t *io,PPpath_pd *pd,PPpath *rep);

ssize_t PPpath_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPpath_pd *pd,PPpath *rep,char const *_tag,int indent);

ssize_t PPpath_write_xml_2io (P_t *pads,Sfio_t *io,PPpath_pd *pd,PPpath *rep,char const *_tag,int indent);

ssize_t PPpath_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPpath_m *m,PPpath_pd *pd,PPpath *rep);

ssize_t PPpath_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPpath_m *m,PPpath_pd *pd,PPpath *rep);

ssize_t PPpath_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPpath_m *m,PPpath_pd *pd,PPpath *rep);
typedef Pstring PPhostname;
typedef struct PPhostname_m_s PPhostname_m;
typedef Pbase_pd PPhostname_pd;
struct PPhostname_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPhostname_init (P_t *pads,PPhostname *rep);

Perror_t PPhostname_pd_init (P_t *pads,PPhostname_pd *pd);

Perror_t PPhostname_cleanup (P_t *pads,PPhostname *rep);

Perror_t PPhostname_pd_cleanup (P_t *pads,PPhostname_pd *pd);

Perror_t PPhostname_copy (P_t *pads,PPhostname *rep_dst,PPhostname *rep_src);

Perror_t PPhostname_pd_copy (P_t *pads,PPhostname_pd *pd_dst,PPhostname_pd *pd_src);

void PPhostname_m_init (P_t *pads,PPhostname_m *mask,Pbase_m baseMask);

Perror_t PPhostname_m_rec_init (P_t *pads,PPhostname_m *mask,Pbase_m baseMask);

Perror_t PPhostname_read (P_t *pads,PPhostname_m *m,PPhostname_pd *pd,PPhostname *rep);

int PPhostname_verify (P_t *pads,PPhostname *rep);

int PPhostname_genPD (P_t *pads,PPhostname *rep,PPhostname_pd *pd);
typedef Pstring_acc PPhostname_acc;

Perror_t PPhostname_acc_init (P_t *pads,PPhostname_acc *acc);

Perror_t PPhostname_acc_reset (P_t *pads,PPhostname_acc *acc);

Perror_t PPhostname_acc_cleanup (P_t *pads,PPhostname_acc *acc);

Perror_t PPhostname_acc_add (P_t *pads,PPhostname_acc *acc,PPhostname_pd *pd,PPhostname *rep);

Perror_t PPhostname_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPhostname_acc *acc);

Perror_t PPhostname_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPhostname_acc *acc);

Perror_t PPhostname_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPhostname_acc *acc);

ssize_t PPhostname_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPhostname_pd *pd,PPhostname *rep);

ssize_t PPhostname_write2io (P_t *pads,Sfio_t *io,PPhostname_pd *pd,PPhostname *rep);

ssize_t PPhostname_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPhostname_pd *pd,PPhostname *rep,char const *_tag,int indent);

ssize_t PPhostname_write_xml_2io (P_t *pads,Sfio_t *io,PPhostname_pd *pd,PPhostname *rep,char const *_tag,int indent);

ssize_t PPhostname_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPhostname_m *m,PPhostname_pd *pd,PPhostname *rep);

ssize_t PPhostname_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPhostname_m *m,PPhostname_pd *pd,PPhostname *rep);

ssize_t PPhostname_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPhostname_m *m,PPhostname_pd *pd,PPhostname *rep);
typedef Pstring PPbXML;
typedef struct PPbXML_m_s PPbXML_m;
typedef Pbase_pd PPbXML_pd;
struct PPbXML_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPbXML_init (P_t *pads,PPbXML *rep);

Perror_t PPbXML_pd_init (P_t *pads,PPbXML_pd *pd);

Perror_t PPbXML_cleanup (P_t *pads,PPbXML *rep);

Perror_t PPbXML_pd_cleanup (P_t *pads,PPbXML_pd *pd);

Perror_t PPbXML_copy (P_t *pads,PPbXML *rep_dst,PPbXML *rep_src);

Perror_t PPbXML_pd_copy (P_t *pads,PPbXML_pd *pd_dst,PPbXML_pd *pd_src);

void PPbXML_m_init (P_t *pads,PPbXML_m *mask,Pbase_m baseMask);

Perror_t PPbXML_m_rec_init (P_t *pads,PPbXML_m *mask,Pbase_m baseMask);

Perror_t PPbXML_read (P_t *pads,PPbXML_m *m,PPbXML_pd *pd,PPbXML *rep);

int PPbXML_verify (P_t *pads,PPbXML *rep);

int PPbXML_genPD (P_t *pads,PPbXML *rep,PPbXML_pd *pd);
typedef Pstring_acc PPbXML_acc;

Perror_t PPbXML_acc_init (P_t *pads,PPbXML_acc *acc);

Perror_t PPbXML_acc_reset (P_t *pads,PPbXML_acc *acc);

Perror_t PPbXML_acc_cleanup (P_t *pads,PPbXML_acc *acc);

Perror_t PPbXML_acc_add (P_t *pads,PPbXML_acc *acc,PPbXML_pd *pd,PPbXML *rep);

Perror_t PPbXML_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPbXML_acc *acc);

Perror_t PPbXML_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPbXML_acc *acc);

Perror_t PPbXML_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPbXML_acc *acc);

ssize_t PPbXML_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPbXML_pd *pd,PPbXML *rep);

ssize_t PPbXML_write2io (P_t *pads,Sfio_t *io,PPbXML_pd *pd,PPbXML *rep);

ssize_t PPbXML_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPbXML_pd *pd,PPbXML *rep,char const *_tag,int indent);

ssize_t PPbXML_write_xml_2io (P_t *pads,Sfio_t *io,PPbXML_pd *pd,PPbXML *rep,char const *_tag,int indent);

ssize_t PPbXML_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPbXML_m *m,PPbXML_pd *pd,PPbXML *rep);

ssize_t PPbXML_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPbXML_m *m,PPbXML_pd *pd,PPbXML *rep);

ssize_t PPbXML_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPbXML_m *m,PPbXML_pd *pd,PPbXML *rep);
typedef Pstring PPeXML;
typedef struct PPeXML_m_s PPeXML_m;
typedef Pbase_pd PPeXML_pd;
struct PPeXML_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPeXML_init (P_t *pads,PPeXML *rep);

Perror_t PPeXML_pd_init (P_t *pads,PPeXML_pd *pd);

Perror_t PPeXML_cleanup (P_t *pads,PPeXML *rep);

Perror_t PPeXML_pd_cleanup (P_t *pads,PPeXML_pd *pd);

Perror_t PPeXML_copy (P_t *pads,PPeXML *rep_dst,PPeXML *rep_src);

Perror_t PPeXML_pd_copy (P_t *pads,PPeXML_pd *pd_dst,PPeXML_pd *pd_src);

void PPeXML_m_init (P_t *pads,PPeXML_m *mask,Pbase_m baseMask);

Perror_t PPeXML_m_rec_init (P_t *pads,PPeXML_m *mask,Pbase_m baseMask);

Perror_t PPeXML_read (P_t *pads,PPeXML_m *m,PPeXML_pd *pd,PPeXML *rep);

int PPeXML_verify (P_t *pads,PPeXML *rep);

int PPeXML_genPD (P_t *pads,PPeXML *rep,PPeXML_pd *pd);
typedef Pstring_acc PPeXML_acc;

Perror_t PPeXML_acc_init (P_t *pads,PPeXML_acc *acc);

Perror_t PPeXML_acc_reset (P_t *pads,PPeXML_acc *acc);

Perror_t PPeXML_acc_cleanup (P_t *pads,PPeXML_acc *acc);

Perror_t PPeXML_acc_add (P_t *pads,PPeXML_acc *acc,PPeXML_pd *pd,PPeXML *rep);

Perror_t PPeXML_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPeXML_acc *acc);

Perror_t PPeXML_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPeXML_acc *acc);

Perror_t PPeXML_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPeXML_acc *acc);

ssize_t PPeXML_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPeXML_pd *pd,PPeXML *rep);

ssize_t PPeXML_write2io (P_t *pads,Sfio_t *io,PPeXML_pd *pd,PPeXML *rep);

ssize_t PPeXML_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPeXML_pd *pd,PPeXML *rep,char const *_tag,int indent);

ssize_t PPeXML_write_xml_2io (P_t *pads,Sfio_t *io,PPeXML_pd *pd,PPeXML *rep,char const *_tag,int indent);

ssize_t PPeXML_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPeXML_m *m,PPeXML_pd *pd,PPeXML *rep);

ssize_t PPeXML_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPeXML_m *m,PPeXML_pd *pd,PPeXML *rep);

ssize_t PPeXML_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPeXML_m *m,PPeXML_pd *pd,PPeXML *rep);
typedef Pstring PPwhite;
typedef struct PPwhite_m_s PPwhite_m;
typedef Pbase_pd PPwhite_pd;
struct PPwhite_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPwhite_init (P_t *pads,PPwhite *rep);

Perror_t PPwhite_pd_init (P_t *pads,PPwhite_pd *pd);

Perror_t PPwhite_cleanup (P_t *pads,PPwhite *rep);

Perror_t PPwhite_pd_cleanup (P_t *pads,PPwhite_pd *pd);

Perror_t PPwhite_copy (P_t *pads,PPwhite *rep_dst,PPwhite *rep_src);

Perror_t PPwhite_pd_copy (P_t *pads,PPwhite_pd *pd_dst,PPwhite_pd *pd_src);

void PPwhite_m_init (P_t *pads,PPwhite_m *mask,Pbase_m baseMask);

Perror_t PPwhite_m_rec_init (P_t *pads,PPwhite_m *mask,Pbase_m baseMask);

Perror_t PPwhite_read (P_t *pads,PPwhite_m *m,PPwhite_pd *pd,PPwhite *rep);

int PPwhite_verify (P_t *pads,PPwhite *rep);

int PPwhite_genPD (P_t *pads,PPwhite *rep,PPwhite_pd *pd);
typedef Pstring_acc PPwhite_acc;

Perror_t PPwhite_acc_init (P_t *pads,PPwhite_acc *acc);

Perror_t PPwhite_acc_reset (P_t *pads,PPwhite_acc *acc);

Perror_t PPwhite_acc_cleanup (P_t *pads,PPwhite_acc *acc);

Perror_t PPwhite_acc_add (P_t *pads,PPwhite_acc *acc,PPwhite_pd *pd,PPwhite *rep);

Perror_t PPwhite_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPwhite_acc *acc);

Perror_t PPwhite_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPwhite_acc *acc);

Perror_t PPwhite_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPwhite_acc *acc);

ssize_t PPwhite_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPwhite_pd *pd,PPwhite *rep);

ssize_t PPwhite_write2io (P_t *pads,Sfio_t *io,PPwhite_pd *pd,PPwhite *rep);

ssize_t PPwhite_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPwhite_pd *pd,PPwhite *rep,char const *_tag,int indent);

ssize_t PPwhite_write_xml_2io (P_t *pads,Sfio_t *io,PPwhite_pd *pd,PPwhite *rep,char const *_tag,int indent);

ssize_t PPwhite_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPwhite_m *m,PPwhite_pd *pd,PPwhite *rep);

ssize_t PPwhite_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPwhite_m *m,PPwhite_pd *pd,PPwhite *rep);

ssize_t PPwhite_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPwhite_m *m,PPwhite_pd *pd,PPwhite *rep);
typedef Pstring PPint;
typedef struct PPint_m_s PPint_m;
typedef Pbase_pd PPint_pd;
struct PPint_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPint_init (P_t *pads,PPint *rep);

Perror_t PPint_pd_init (P_t *pads,PPint_pd *pd);

Perror_t PPint_cleanup (P_t *pads,PPint *rep);

Perror_t PPint_pd_cleanup (P_t *pads,PPint_pd *pd);

Perror_t PPint_copy (P_t *pads,PPint *rep_dst,PPint *rep_src);

Perror_t PPint_pd_copy (P_t *pads,PPint_pd *pd_dst,PPint_pd *pd_src);

void PPint_m_init (P_t *pads,PPint_m *mask,Pbase_m baseMask);

Perror_t PPint_m_rec_init (P_t *pads,PPint_m *mask,Pbase_m baseMask);

Perror_t PPint_read (P_t *pads,PPint_m *m,PPint_pd *pd,PPint *rep);

int PPint_verify (P_t *pads,PPint *rep);

int PPint_genPD (P_t *pads,PPint *rep,PPint_pd *pd);
typedef Pstring_acc PPint_acc;

Perror_t PPint_acc_init (P_t *pads,PPint_acc *acc);

Perror_t PPint_acc_reset (P_t *pads,PPint_acc *acc);

Perror_t PPint_acc_cleanup (P_t *pads,PPint_acc *acc);

Perror_t PPint_acc_add (P_t *pads,PPint_acc *acc,PPint_pd *pd,PPint *rep);

Perror_t PPint_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPint_acc *acc);

Perror_t PPint_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPint_acc *acc);

Perror_t PPint_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPint_acc *acc);

ssize_t PPint_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPint_pd *pd,PPint *rep);

ssize_t PPint_write2io (P_t *pads,Sfio_t *io,PPint_pd *pd,PPint *rep);

ssize_t PPint_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPint_pd *pd,PPint *rep,char const *_tag,int indent);

ssize_t PPint_write_xml_2io (P_t *pads,Sfio_t *io,PPint_pd *pd,PPint *rep,char const *_tag,int indent);

ssize_t PPint_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPint_m *m,PPint_pd *pd,PPint *rep);

ssize_t PPint_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPint_m *m,PPint_pd *pd,PPint *rep);

ssize_t PPint_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPint_m *m,PPint_pd *pd,PPint *rep);
typedef Pstring PPstring;
typedef struct PPstring_m_s PPstring_m;
typedef Pbase_pd PPstring_pd;
struct PPstring_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPstring_init (P_t *pads,PPstring *rep);

Perror_t PPstring_pd_init (P_t *pads,PPstring_pd *pd);

Perror_t PPstring_cleanup (P_t *pads,PPstring *rep);

Perror_t PPstring_pd_cleanup (P_t *pads,PPstring_pd *pd);

Perror_t PPstring_copy (P_t *pads,PPstring *rep_dst,PPstring *rep_src);

Perror_t PPstring_pd_copy (P_t *pads,PPstring_pd *pd_dst,PPstring_pd *pd_src);

void PPstring_m_init (P_t *pads,PPstring_m *mask,Pbase_m baseMask);

Perror_t PPstring_m_rec_init (P_t *pads,PPstring_m *mask,Pbase_m baseMask);

Perror_t PPstring_read (P_t *pads,PPstring_m *m,PPstring_pd *pd,PPstring *rep);

int PPstring_verify (P_t *pads,PPstring *rep);

int PPstring_genPD (P_t *pads,PPstring *rep,PPstring_pd *pd);
typedef Pstring_acc PPstring_acc;

Perror_t PPstring_acc_init (P_t *pads,PPstring_acc *acc);

Perror_t PPstring_acc_reset (P_t *pads,PPstring_acc *acc);

Perror_t PPstring_acc_cleanup (P_t *pads,PPstring_acc *acc);

Perror_t PPstring_acc_add (P_t *pads,PPstring_acc *acc,PPstring_pd *pd,PPstring *rep);

Perror_t PPstring_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPstring_acc *acc);

Perror_t PPstring_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPstring_acc *acc);

Perror_t PPstring_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPstring_acc *acc);

ssize_t PPstring_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPstring_pd *pd,PPstring *rep);

ssize_t PPstring_write2io (P_t *pads,Sfio_t *io,PPstring_pd *pd,PPstring *rep);

ssize_t PPstring_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPstring_pd *pd,PPstring *rep,char const *_tag,int indent);

ssize_t PPstring_write_xml_2io (P_t *pads,Sfio_t *io,PPstring_pd *pd,PPstring *rep,char const *_tag,int indent);

ssize_t PPstring_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPstring_m *m,PPstring_pd *pd,PPstring *rep);

ssize_t PPstring_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPstring_m *m,PPstring_pd *pd,PPstring *rep);

ssize_t PPstring_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPstring_m *m,PPstring_pd *pd,PPstring *rep);
typedef Pstring PPchar;
typedef struct PPchar_m_s PPchar_m;
typedef Pbase_pd PPchar_pd;
struct PPchar_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t PPchar_init (P_t *pads,PPchar *rep);

Perror_t PPchar_pd_init (P_t *pads,PPchar_pd *pd);

Perror_t PPchar_cleanup (P_t *pads,PPchar *rep);

Perror_t PPchar_pd_cleanup (P_t *pads,PPchar_pd *pd);

Perror_t PPchar_copy (P_t *pads,PPchar *rep_dst,PPchar *rep_src);

Perror_t PPchar_pd_copy (P_t *pads,PPchar_pd *pd_dst,PPchar_pd *pd_src);

void PPchar_m_init (P_t *pads,PPchar_m *mask,Pbase_m baseMask);

Perror_t PPchar_m_rec_init (P_t *pads,PPchar_m *mask,Pbase_m baseMask);

Perror_t PPchar_read (P_t *pads,PPchar_m *m,PPchar_pd *pd,PPchar *rep);

int PPchar_verify (P_t *pads,PPchar *rep);

int PPchar_genPD (P_t *pads,PPchar *rep,PPchar_pd *pd);
typedef Pstring_acc PPchar_acc;

Perror_t PPchar_acc_init (P_t *pads,PPchar_acc *acc);

Perror_t PPchar_acc_reset (P_t *pads,PPchar_acc *acc);

Perror_t PPchar_acc_cleanup (P_t *pads,PPchar_acc *acc);

Perror_t PPchar_acc_add (P_t *pads,PPchar_acc *acc,PPchar_pd *pd,PPchar *rep);

Perror_t PPchar_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,PPchar_acc *acc);

Perror_t PPchar_acc_report (P_t *pads,char const *prefix,char const *what,int nst,PPchar_acc *acc);

Perror_t PPchar_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,PPchar_acc *acc);

ssize_t PPchar_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPchar_pd *pd,PPchar *rep);

ssize_t PPchar_write2io (P_t *pads,Sfio_t *io,PPchar_pd *pd,PPchar *rep);

ssize_t PPchar_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,PPchar_pd *pd,PPchar *rep,char const *_tag,int indent);

ssize_t PPchar_write_xml_2io (P_t *pads,Sfio_t *io,PPchar_pd *pd,PPchar *rep,char const *_tag,int indent);

ssize_t PPchar_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPchar_m *m,PPchar_pd *pd,PPchar *rep);

ssize_t PPchar_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,PPchar_m *m,PPchar_pd *pd,PPchar *rep);

ssize_t PPchar_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,PPchar_m *m,PPchar_pd *pd,PPchar *rep);
typedef enum Union_1_tag_e Union_1_tag;
typedef union Union_1_u_u Union_1_u;
typedef struct Union_1_s Union_1;
typedef struct Union_1_m_s Union_1_m;
typedef union Union_1_pd_u_u Union_1_pd_u;
typedef struct Union_1_pd_s Union_1_pd;
enum Union_1_tag_e {
  Union_1_err=0,
  v_str_1=1,
  v_int_1=2,
  Pdefault_0=3
  };
union Union_1_pd_u_u {
  PPstring_pd v_str_1;
  Pbase_pd v_int_1;
  Pbase_pd Pdefault_0;		/* Empty Field. Pdefault_0 = 0 */
};
struct Union_1_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Union_1_tag tag;
  Union_1_pd_u val;
};
union Union_1_u_u {
  PPstring v_str_1;
  Puint32 v_int_1;
};
struct Union_1_s {
  Union_1_tag tag;
  Union_1_u val;
};
struct Union_1_m_s {
  Pbase_m compoundLevel;
  PPstring_m v_str_1;		/* nested constraints */
  Pbase_m v_int_1;		/* nested constraints */
  Pbase_m Pdefault_0;		/* nested constraints */
};

ssize_t Union_1_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Union_1_pd *pd,Union_1 *rep);

ssize_t Union_1_write2io (P_t *pads,Sfio_t *io,Union_1_pd *pd,Union_1 *rep);

ssize_t Union_1_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Union_1_pd *pd,Union_1 *rep,char const *_tag,int indent);

ssize_t Union_1_write_xml_2io (P_t *pads,Sfio_t *io,Union_1_pd *pd,Union_1 *rep,char const *_tag,int indent);

char const *Union_1_tag2str (Union_1_tag which);

Perror_t Union_1_init (P_t *pads,Union_1 *rep);

Perror_t Union_1_pd_init (P_t *pads,Union_1_pd *pd);

Perror_t Union_1_cleanup (P_t *pads,Union_1 *rep);

Perror_t Union_1_pd_cleanup (P_t *pads,Union_1_pd *pd);

Perror_t Union_1_copy (P_t *pads,Union_1 *rep_dst,Union_1 *rep_src);

Perror_t Union_1_pd_copy (P_t *pads,Union_1_pd *pd_dst,Union_1_pd *pd_src);

void Union_1_m_init (P_t *pads,Union_1_m *mask,Pbase_m baseMask);

Perror_t Union_1_m_rec_init (P_t *pads,Union_1_m *mask,Pbase_m baseMask);

Perror_t Union_1_read (P_t *pads,Union_1_m *m,Union_1_pd *pd,Union_1 *rep);

int Union_1_verify (P_t *pads,Union_1 *rep);

int Union_1_genPD (P_t *pads,Union_1 *rep,Union_1_pd *pd);
typedef struct Union_1_acc_s Union_1_acc;
struct Union_1_acc_s {
  Pint32_acc tag;
  PPstring_acc v_str_1;
  Puint32_acc v_int_1;
};

Perror_t Union_1_acc_init (P_t *pads,Union_1_acc *acc);

Perror_t Union_1_acc_reset (P_t *pads,Union_1_acc *acc);

Perror_t Union_1_acc_cleanup (P_t *pads,Union_1_acc *acc);

Perror_t Union_1_acc_add (P_t *pads,Union_1_acc *acc,Union_1_pd *pd,Union_1 *rep);

Perror_t Union_1_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,Union_1_acc *acc);

Perror_t Union_1_acc_report (P_t *pads,char const *prefix,char const *what,int nst,Union_1_acc *acc);

Perror_t Union_1_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,Union_1_acc *acc);

ssize_t Union_1_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Union_1_m *m,Union_1_pd *pd,Union_1 *rep);

ssize_t Union_1_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Union_1_m *m,Union_1_pd *pd,Union_1 *rep);

ssize_t Union_1_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,Union_1_m *m,Union_1_pd *pd,Union_1 *rep);
typedef struct Array_1_s Array_1;
typedef struct Array_1_m_s Array_1_m;
typedef struct Array_1_pd_s Array_1_pd;
typedef struct Array_1_ro_params_t_s Array_1_ro_params_t;
struct Array_1_m_s {
  Union_1_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct Array_1_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  Union_1_pd *elts;
  RBuf_t *_internal;
};
struct Array_1_s {
  Puint32 length;
  Union_1 *elts;
  RBuf_t *_internal;
};
struct Array_1_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t Array_1_init (P_t *pads,Array_1 *rep);

Perror_t Array_1_pd_init (P_t *pads,Array_1_pd *pd);

Perror_t Array_1_cleanup (P_t *pads,Array_1 *rep);

Perror_t Array_1_pd_cleanup (P_t *pads,Array_1_pd *pd);

Perror_t Array_1_copy (P_t *pads,Array_1 *rep_dst,Array_1 *rep_src);

Perror_t Array_1_pd_copy (P_t *pads,Array_1_pd *pd_dst,Array_1_pd *pd_src);

void Array_1_m_init (P_t *pads,Array_1_m *mask,Pbase_m baseMask);

Perror_t Array_1_m_rec_init (P_t *pads,Array_1_m *mask,Pbase_m baseMask);

void Array_1_ro_params_init (Array_1_ro_params_t *params);

Pread_res_t Array_1_final_checks (P_t *pads,Array_1_m *m,Array_1_pd *pd,Array_1 *rep,Ploc_t *loc_ptr,int foundTerm,int consume);

Pread_res_t Array_1_read_one_init (P_t *pads,Array_1_m *m,Array_1_pd *pd,Array_1 *rep,Ploc_t *loc_ptr);

Pread_res_t Array_1_read_one (P_t *pads,Array_1_m *m,Array_1_pd *pd,Array_1 *rep,Ploc_t *loc_ptr,Union_1_pd *elt_pd,Union_1 *elt_rep);

Perror_t Array_1_read (P_t *pads,Array_1_m *m,Array_1_pd *pd,Array_1 *rep);

Pread_res_t Array_1_reread_one (P_t *pads,Array_1_m *m,Array_1_pd *pd,Array_1 *rep,Ploc_t *loc_ptr,Union_1_pd *elt_pd,Union_1 *elt_rep,int notFirstElt);

int Array_1_verify (P_t *pads,Array_1 *rep);

int Array_1_genPD (P_t *pads,Array_1 *rep,Array_1_pd *pd);
typedef struct Array_1_acc_s Array_1_acc;
struct Array_1_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Union_1_acc compoundLevel;		/* Accumulator for all array elements */
  Union_1_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t Array_1_acc_init (P_t *pads,Array_1_acc *acc);

Perror_t Array_1_acc_reset (P_t *pads,Array_1_acc *acc);

Perror_t Array_1_acc_cleanup (P_t *pads,Array_1_acc *acc);

Perror_t Array_1_acc_add (P_t *pads,Array_1_acc *acc,Array_1_pd *pd,Array_1 *rep);

Perror_t Array_1_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,Array_1_acc *acc);

Perror_t Array_1_acc_report (P_t *pads,char const *prefix,char const *what,int nst,Array_1_acc *acc);

Perror_t Array_1_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,Array_1_acc *acc);

ssize_t Array_1_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Array_1_pd *pd,Array_1 *rep);

ssize_t Array_1_write2io (P_t *pads,Sfio_t *io,Array_1_pd *pd,Array_1 *rep);

ssize_t Array_1_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Array_1_pd *pd,Array_1 *rep,char const *_tag,int indent);

ssize_t Array_1_write_xml_2io (P_t *pads,Sfio_t *io,Array_1_pd *pd,Array_1 *rep,char const *_tag,int indent);

ssize_t Array_1_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Array_1_m *m,Array_1_pd *pd,Array_1 *rep);

ssize_t Array_1_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Array_1_m *m,Array_1_pd *pd,Array_1 *rep);

ssize_t Array_1_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,Array_1_m *m,Array_1_pd *pd,Array_1 *rep);
typedef struct sentry_t_s sentry_t;
typedef struct sentry_t_m_s sentry_t_m;
typedef struct sentry_t_pd_s sentry_t_pd;
struct sentry_t_m_s {
  Pbase_m compoundLevel;
  Union_1_m f1;		/* nested constraints */
  Union_1_m f2;		/* nested constraints */
};
struct sentry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Union_1_pd f1;
  Union_1_pd f2;
};
struct sentry_t_s {
  Union_1 f1;
  Union_1 f2;
};

Perror_t sentry_t_init (P_t *pads,sentry_t *rep);

Perror_t sentry_t_pd_init (P_t *pads,sentry_t_pd *pd);

Perror_t sentry_t_cleanup (P_t *pads,sentry_t *rep);

Perror_t sentry_t_pd_cleanup (P_t *pads,sentry_t_pd *pd);

Perror_t sentry_t_copy (P_t *pads,sentry_t *rep_dst,sentry_t *rep_src);

Perror_t sentry_t_pd_copy (P_t *pads,sentry_t_pd *pd_dst,sentry_t_pd *pd_src);

void sentry_t_m_init (P_t *pads,sentry_t_m *mask,Pbase_m baseMask);

Perror_t sentry_t_m_rec_init (P_t *pads,sentry_t_m *mask,Pbase_m baseMask);

Perror_t sentry_t_read (P_t *pads,sentry_t_m *m,sentry_t_pd *pd,sentry_t *rep);

int sentry_t_verify (P_t *pads,sentry_t *rep);

int sentry_t_genPD (P_t *pads,sentry_t *rep,sentry_t_pd *pd);
typedef struct sentry_t_acc_s sentry_t_acc;
struct sentry_t_acc_s {
  Puint32_acc nerr;
  Union_1_acc f1;
  Union_1_acc f2;
};

Perror_t sentry_t_acc_init (P_t *pads,sentry_t_acc *acc);

Perror_t sentry_t_acc_reset (P_t *pads,sentry_t_acc *acc);

Perror_t sentry_t_acc_cleanup (P_t *pads,sentry_t_acc *acc);

Perror_t sentry_t_acc_add (P_t *pads,sentry_t_acc *acc,sentry_t_pd *pd,sentry_t *rep);

Perror_t sentry_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,sentry_t_acc *acc);

Perror_t sentry_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,sentry_t_acc *acc);

Perror_t sentry_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,sentry_t_acc *acc);

ssize_t sentry_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sentry_t_pd *pd,sentry_t *rep);

ssize_t sentry_t_write2io (P_t *pads,Sfio_t *io,sentry_t_pd *pd,sentry_t *rep);

ssize_t sentry_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sentry_t_pd *pd,sentry_t *rep,char const *_tag,int indent);

ssize_t sentry_t_write_xml_2io (P_t *pads,Sfio_t *io,sentry_t_pd *pd,sentry_t *rep,char const *_tag,int indent);

ssize_t sentry_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sentry_t_m *m,sentry_t_pd *pd,sentry_t *rep);

ssize_t sentry_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sentry_t_m *m,sentry_t_pd *pd,sentry_t *rep);

ssize_t sentry_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,sentry_t_m *m,sentry_t_pd *pd,sentry_t *rep);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  Array_1_m data;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Array_1_pd data;
};
struct entry_t_s {
  Array_1 data;
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
  Array_1_acc data;
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
typedef struct entries_t_s entries_t;
typedef struct entries_t_m_s entries_t_m;
typedef struct entries_t_pd_s entries_t_pd;
typedef struct entries_t_ro_params_t_s entries_t_ro_params_t;
struct entries_t_m_s {
  Array_1_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct entries_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  Array_1_pd *elts;
  RBuf_t *_internal;
};
struct entries_t_s {
  Puint32 length;
  Array_1 *elts;
  RBuf_t *_internal;
};
struct entries_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t entries_t_init (P_t *pads,entries_t *rep);

Perror_t entries_t_pd_init (P_t *pads,entries_t_pd *pd);

Perror_t entries_t_cleanup (P_t *pads,entries_t *rep);

Perror_t entries_t_pd_cleanup (P_t *pads,entries_t_pd *pd);

Perror_t entries_t_copy (P_t *pads,entries_t *rep_dst,entries_t *rep_src);

Perror_t entries_t_pd_copy (P_t *pads,entries_t_pd *pd_dst,entries_t_pd *pd_src);

void entries_t_m_init (P_t *pads,entries_t_m *mask,Pbase_m baseMask);

Perror_t entries_t_m_rec_init (P_t *pads,entries_t_m *mask,Pbase_m baseMask);

void entries_t_ro_params_init (entries_t_ro_params_t *params);

Pread_res_t entries_t_final_checks (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t entries_t_read_one_init (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr);

Pread_res_t entries_t_read_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,Array_1_pd *elt_pd,Array_1 *elt_rep);

Perror_t entries_t_read (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep);

Pread_res_t entries_t_reread_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,Array_1_pd *elt_pd,Array_1 *elt_rep,int notFirstElt);

int entries_t_verify (P_t *pads,entries_t *rep);

int entries_t_genPD (P_t *pads,entries_t *rep,entries_t_pd *pd);
typedef struct entries_t_acc_s entries_t_acc;
struct entries_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  Array_1_acc compoundLevel;		/* Accumulator for all array elements */
  Array_1_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t entries_t_acc_init (P_t *pads,entries_t_acc *acc);

Perror_t entries_t_acc_reset (P_t *pads,entries_t_acc *acc);

Perror_t entries_t_acc_cleanup (P_t *pads,entries_t_acc *acc);

Perror_t entries_t_acc_add (P_t *pads,entries_t_acc *acc,entries_t_pd *pd,entries_t *rep);

Perror_t entries_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entries_t_acc *acc);

Perror_t entries_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entries_t_acc *acc);

Perror_t entries_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,entries_t_acc *acc);

ssize_t entries_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entries_t_pd *pd,entries_t *rep);

ssize_t entries_t_write2io (P_t *pads,Sfio_t *io,entries_t_pd *pd,entries_t *rep);

ssize_t entries_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entries_t_pd *pd,entries_t *rep,char const *_tag,int indent);

ssize_t entries_t_write_xml_2io (P_t *pads,Sfio_t *io,entries_t_pd *pd,entries_t *rep,char const *_tag,int indent);

ssize_t entries_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep);

ssize_t entries_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep);

ssize_t entries_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep);

void P_lib_init ();

#endif /*  __LISTE__H__  */
