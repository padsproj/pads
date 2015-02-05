#ifndef __REMOVE_ERR__H__
#define __REMOVE_ERR__H__
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
typedef Pstring hex_t;
typedef struct hex_t_m_s hex_t_m;
typedef Pbase_pd hex_t_pd;
struct hex_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t hex_t_init (P_t *pads,hex_t *rep);

Perror_t hex_t_pd_init (P_t *pads,hex_t_pd *pd);

Perror_t hex_t_cleanup (P_t *pads,hex_t *rep);

Perror_t hex_t_pd_cleanup (P_t *pads,hex_t_pd *pd);

Perror_t hex_t_copy (P_t *pads,hex_t *rep_dst,hex_t *rep_src);

Perror_t hex_t_pd_copy (P_t *pads,hex_t_pd *pd_dst,hex_t_pd *pd_src);

void hex_t_m_init (P_t *pads,hex_t_m *mask,Pbase_m baseMask);

Perror_t hex_t_m_rec_init (P_t *pads,hex_t_m *mask,Pbase_m baseMask);

Perror_t hex_t_read (P_t *pads,hex_t_m *m,hex_t_pd *pd,hex_t *rep);

int hex_t_verify (P_t *pads,hex_t *rep);

int hex_t_genPD (P_t *pads,hex_t *rep,hex_t_pd *pd);
typedef Pstring_acc hex_t_acc;

Perror_t hex_t_acc_init (P_t *pads,hex_t_acc *acc);

Perror_t hex_t_acc_reset (P_t *pads,hex_t_acc *acc);

Perror_t hex_t_acc_cleanup (P_t *pads,hex_t_acc *acc);

Perror_t hex_t_acc_add (P_t *pads,hex_t_acc *acc,hex_t_pd *pd,hex_t *rep);

Perror_t hex_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,hex_t_acc *acc);

Perror_t hex_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,hex_t_acc *acc);

Perror_t hex_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,hex_t_acc *acc);

ssize_t hex_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,hex_t_pd *pd,hex_t *rep);

ssize_t hex_t_write2io (P_t *pads,Sfio_t *io,hex_t_pd *pd,hex_t *rep);

ssize_t hex_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,hex_t_pd *pd,hex_t *rep,char const *_tag,int indent);

ssize_t hex_t_write_xml_2io (P_t *pads,Sfio_t *io,hex_t_pd *pd,hex_t *rep,char const *_tag,int indent);

ssize_t hex_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,hex_t_m *m,hex_t_pd *pd,hex_t *rep);

ssize_t hex_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,hex_t_m *m,hex_t_pd *pd,hex_t *rep);

ssize_t hex_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,hex_t_m *m,hex_t_pd *pd,hex_t *rep);
typedef struct record_t_s record_t;
typedef struct record_t_m_s record_t_m;
typedef struct record_t_pd_s record_t_pd;
struct record_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_rec_content;		/* nested constraints */
};
struct record_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_rec_content;
};
struct record_t_s {
  Pstring v_rec_content;
};

Perror_t record_t_init (P_t *pads,record_t *rep);

Perror_t record_t_pd_init (P_t *pads,record_t_pd *pd);

Perror_t record_t_cleanup (P_t *pads,record_t *rep);

Perror_t record_t_pd_cleanup (P_t *pads,record_t_pd *pd);

Perror_t record_t_copy (P_t *pads,record_t *rep_dst,record_t *rep_src);

Perror_t record_t_pd_copy (P_t *pads,record_t_pd *pd_dst,record_t_pd *pd_src);

void record_t_m_init (P_t *pads,record_t_m *mask,Pbase_m baseMask);

Perror_t record_t_m_rec_init (P_t *pads,record_t_m *mask,Pbase_m baseMask);

Perror_t record_t_read (P_t *pads,record_t_m *m,record_t_pd *pd,record_t *rep);

int record_t_verify (P_t *pads,record_t *rep);

int record_t_genPD (P_t *pads,record_t *rep,record_t_pd *pd);
typedef struct record_t_acc_s record_t_acc;
struct record_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc v_rec_content;
};

Perror_t record_t_acc_init (P_t *pads,record_t_acc *acc);

Perror_t record_t_acc_reset (P_t *pads,record_t_acc *acc);

Perror_t record_t_acc_cleanup (P_t *pads,record_t_acc *acc);

Perror_t record_t_acc_add (P_t *pads,record_t_acc *acc,record_t_pd *pd,record_t *rep);

Perror_t record_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,record_t_acc *acc);

Perror_t record_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,record_t_acc *acc);

Perror_t record_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,record_t_acc *acc);

ssize_t record_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,record_t_pd *pd,record_t *rep);

ssize_t record_t_write2io (P_t *pads,Sfio_t *io,record_t_pd *pd,record_t *rep);

ssize_t record_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,record_t_pd *pd,record_t *rep,char const *_tag,int indent);

ssize_t record_t_write_xml_2io (P_t *pads,Sfio_t *io,record_t_pd *pd,record_t *rep,char const *_tag,int indent);

ssize_t record_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,record_t_m *m,record_t_pd *pd,record_t *rep);

ssize_t record_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,record_t_m *m,record_t_pd *pd,record_t *rep);

ssize_t record_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,record_t_m *m,record_t_pd *pd,record_t *rep);
typedef struct list_t_s list_t;
typedef struct list_t_m_s list_t_m;
typedef struct list_t_pd_s list_t_pd;
struct list_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_rec_content;		/* nested constraints */
};
struct list_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_rec_content;
};
struct list_t_s {
  Pstring v_rec_content;
};

Perror_t list_t_init (P_t *pads,list_t *rep);

Perror_t list_t_pd_init (P_t *pads,list_t_pd *pd);

Perror_t list_t_cleanup (P_t *pads,list_t *rep);

Perror_t list_t_pd_cleanup (P_t *pads,list_t_pd *pd);

Perror_t list_t_copy (P_t *pads,list_t *rep_dst,list_t *rep_src);

Perror_t list_t_pd_copy (P_t *pads,list_t_pd *pd_dst,list_t_pd *pd_src);

void list_t_m_init (P_t *pads,list_t_m *mask,Pbase_m baseMask);

Perror_t list_t_m_rec_init (P_t *pads,list_t_m *mask,Pbase_m baseMask);

Perror_t list_t_read (P_t *pads,list_t_m *m,list_t_pd *pd,list_t *rep);

int list_t_verify (P_t *pads,list_t *rep);

int list_t_genPD (P_t *pads,list_t *rep,list_t_pd *pd);
typedef struct list_t_acc_s list_t_acc;
struct list_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc v_rec_content;
};

Perror_t list_t_acc_init (P_t *pads,list_t_acc *acc);

Perror_t list_t_acc_reset (P_t *pads,list_t_acc *acc);

Perror_t list_t_acc_cleanup (P_t *pads,list_t_acc *acc);

Perror_t list_t_acc_add (P_t *pads,list_t_acc *acc,list_t_pd *pd,list_t *rep);

Perror_t list_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,list_t_acc *acc);

Perror_t list_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,list_t_acc *acc);

Perror_t list_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,list_t_acc *acc);

ssize_t list_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,list_t_pd *pd,list_t *rep);

ssize_t list_t_write2io (P_t *pads,Sfio_t *io,list_t_pd *pd,list_t *rep);

ssize_t list_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,list_t_pd *pd,list_t *rep,char const *_tag,int indent);

ssize_t list_t_write_xml_2io (P_t *pads,Sfio_t *io,list_t_pd *pd,list_t *rep,char const *_tag,int indent);

ssize_t list_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,list_t_m *m,list_t_pd *pd,list_t *rep);

ssize_t list_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,list_t_m *m,list_t_pd *pd,list_t *rep);

ssize_t list_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,list_t_m *m,list_t_pd *pd,list_t *rep);
typedef enum elem_t_tag_e elem_t_tag;
typedef union elem_t_u_u elem_t_u;
typedef struct elem_t_s elem_t;
typedef struct elem_t_m_s elem_t_m;
typedef union elem_t_pd_u_u elem_t_pd_u;
typedef struct elem_t_pd_s elem_t_pd;
enum elem_t_tag_e {
  elem_t_err=0,
  v_quotes=1,
  v_slash=2,
  v_other_chars=3
  };
union elem_t_pd_u_u {
  Pbase_pd v_quotes;
  Pbase_pd v_slash;
  Pbase_pd v_other_chars;
};
struct elem_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  elem_t_tag tag;
  elem_t_pd_u val;
};
union elem_t_u_u {
  Pstring v_other_chars;
};
struct elem_t_s {
  elem_t_tag tag;
  elem_t_u val;
};
struct elem_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_other_chars;		/* nested constraints */
};

ssize_t elem_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,elem_t_pd *pd,elem_t *rep);

ssize_t elem_t_write2io (P_t *pads,Sfio_t *io,elem_t_pd *pd,elem_t *rep);

ssize_t elem_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,elem_t_pd *pd,elem_t *rep,char const *_tag,int indent);

ssize_t elem_t_write_xml_2io (P_t *pads,Sfio_t *io,elem_t_pd *pd,elem_t *rep,char const *_tag,int indent);

char const *elem_t_tag2str (elem_t_tag which);

Perror_t elem_t_init (P_t *pads,elem_t *rep);

Perror_t elem_t_pd_init (P_t *pads,elem_t_pd *pd);

Perror_t elem_t_cleanup (P_t *pads,elem_t *rep);

Perror_t elem_t_pd_cleanup (P_t *pads,elem_t_pd *pd);

Perror_t elem_t_copy (P_t *pads,elem_t *rep_dst,elem_t *rep_src);

Perror_t elem_t_pd_copy (P_t *pads,elem_t_pd *pd_dst,elem_t_pd *pd_src);

void elem_t_m_init (P_t *pads,elem_t_m *mask,Pbase_m baseMask);

Perror_t elem_t_m_rec_init (P_t *pads,elem_t_m *mask,Pbase_m baseMask);

Perror_t elem_t_read (P_t *pads,elem_t_m *m,elem_t_pd *pd,elem_t *rep);

int elem_t_verify (P_t *pads,elem_t *rep);

int elem_t_genPD (P_t *pads,elem_t *rep,elem_t_pd *pd);
typedef struct elem_t_acc_s elem_t_acc;
struct elem_t_acc_s {
  Pint32_acc tag;
  Pstring_acc v_other_chars;
};

Perror_t elem_t_acc_init (P_t *pads,elem_t_acc *acc);

Perror_t elem_t_acc_reset (P_t *pads,elem_t_acc *acc);

Perror_t elem_t_acc_cleanup (P_t *pads,elem_t_acc *acc);

Perror_t elem_t_acc_add (P_t *pads,elem_t_acc *acc,elem_t_pd *pd,elem_t *rep);

Perror_t elem_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,elem_t_acc *acc);

Perror_t elem_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,elem_t_acc *acc);

Perror_t elem_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,elem_t_acc *acc);

ssize_t elem_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,elem_t_m *m,elem_t_pd *pd,elem_t *rep);

ssize_t elem_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,elem_t_m *m,elem_t_pd *pd,elem_t *rep);

ssize_t elem_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,elem_t_m *m,elem_t_pd *pd,elem_t *rep);
typedef struct v_rec_content_t_s v_rec_content_t;
typedef struct v_rec_content_t_m_s v_rec_content_t_m;
typedef struct v_rec_content_t_pd_s v_rec_content_t_pd;
typedef struct v_rec_content_t_ro_params_t_s v_rec_content_t_ro_params_t;
struct v_rec_content_t_m_s {
  elem_t_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct v_rec_content_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  elem_t_pd *elts;
  RBuf_t *_internal;
};
struct v_rec_content_t_s {
  Puint32 length;
  elem_t *elts;
  RBuf_t *_internal;
};
struct v_rec_content_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t v_rec_content_t_init (P_t *pads,v_rec_content_t *rep);

Perror_t v_rec_content_t_pd_init (P_t *pads,v_rec_content_t_pd *pd);

Perror_t v_rec_content_t_cleanup (P_t *pads,v_rec_content_t *rep);

Perror_t v_rec_content_t_pd_cleanup (P_t *pads,v_rec_content_t_pd *pd);

Perror_t v_rec_content_t_copy (P_t *pads,v_rec_content_t *rep_dst,v_rec_content_t *rep_src);

Perror_t v_rec_content_t_pd_copy (P_t *pads,v_rec_content_t_pd *pd_dst,v_rec_content_t_pd *pd_src);

void v_rec_content_t_m_init (P_t *pads,v_rec_content_t_m *mask,Pbase_m baseMask);

Perror_t v_rec_content_t_m_rec_init (P_t *pads,v_rec_content_t_m *mask,Pbase_m baseMask);

void v_rec_content_t_ro_params_init (v_rec_content_t_ro_params_t *params);

Pread_res_t v_rec_content_t_final_checks (P_t *pads,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t v_rec_content_t_read_one_init (P_t *pads,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep,Ploc_t *loc_ptr);

Pread_res_t v_rec_content_t_read_one (P_t *pads,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep,Ploc_t *loc_ptr,elem_t_pd *elt_pd,elem_t *elt_rep);

Perror_t v_rec_content_t_read (P_t *pads,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep);

Pread_res_t v_rec_content_t_reread_one (P_t *pads,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep,Ploc_t *loc_ptr,elem_t_pd *elt_pd,elem_t *elt_rep,int notFirstElt);

int v_rec_content_t_verify (P_t *pads,v_rec_content_t *rep);

int v_rec_content_t_genPD (P_t *pads,v_rec_content_t *rep,v_rec_content_t_pd *pd);
typedef struct v_rec_content_t_acc_s v_rec_content_t_acc;
struct v_rec_content_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  elem_t_acc compoundLevel;		/* Accumulator for all array elements */
  elem_t_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t v_rec_content_t_acc_init (P_t *pads,v_rec_content_t_acc *acc);

Perror_t v_rec_content_t_acc_reset (P_t *pads,v_rec_content_t_acc *acc);

Perror_t v_rec_content_t_acc_cleanup (P_t *pads,v_rec_content_t_acc *acc);

Perror_t v_rec_content_t_acc_add (P_t *pads,v_rec_content_t_acc *acc,v_rec_content_t_pd *pd,v_rec_content_t *rep);

Perror_t v_rec_content_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_rec_content_t_acc *acc);

Perror_t v_rec_content_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_rec_content_t_acc *acc);

Perror_t v_rec_content_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_rec_content_t_acc *acc);

ssize_t v_rec_content_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_rec_content_t_pd *pd,v_rec_content_t *rep);

ssize_t v_rec_content_t_write2io (P_t *pads,Sfio_t *io,v_rec_content_t_pd *pd,v_rec_content_t *rep);

ssize_t v_rec_content_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_rec_content_t_pd *pd,v_rec_content_t *rep,char const *_tag,int indent);

ssize_t v_rec_content_t_write_xml_2io (P_t *pads,Sfio_t *io,v_rec_content_t_pd *pd,v_rec_content_t *rep,char const *_tag,int indent);

ssize_t v_rec_content_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep);

ssize_t v_rec_content_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep);

ssize_t v_rec_content_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_rec_content_t_m *m,v_rec_content_t_pd *pd,v_rec_content_t *rep);
typedef enum v_dots_t_tag_e v_dots_t_tag;
typedef union v_dots_t_u_u v_dots_t_u;
typedef struct v_dots_t_s v_dots_t;
typedef struct v_dots_t_m_s v_dots_t_m;
typedef union v_dots_t_pd_u_u v_dots_t_pd_u;
typedef struct v_dots_t_pd_s v_dots_t_pd;
enum v_dots_t_tag_e {
  v_dots_t_err=0,
  some_v_dots_t=1,
  none_v_dots_t=2
  };
union v_dots_t_pd_u_u {
  Pbase_pd some_v_dots_t;
  Pbase_pd none_v_dots_t;		/* value was not present. none_v_dots_t = 0 */
};
struct v_dots_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_dots_t_tag tag;
  v_dots_t_pd_u val;
};
union v_dots_t_u_u {
  Pstring some_v_dots_t;		/* value is present */
};
struct v_dots_t_s {
  v_dots_t_tag tag;
  v_dots_t_u val;
};
struct v_dots_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m some_v_dots_t;		/* nested constraints */
  Pbase_m none_v_dots_t;		/* nested constraints */
};

ssize_t v_dots_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);

ssize_t v_dots_t_write2io (P_t *pads,Sfio_t *io,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);

ssize_t v_dots_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_dots_t_pd *pd,v_dots_t *rep,char const *_tag,int indent,v_rec_content_t *v_rec_content);

ssize_t v_dots_t_write_xml_2io (P_t *pads,Sfio_t *io,v_dots_t_pd *pd,v_dots_t *rep,char const *_tag,int indent,v_rec_content_t *v_rec_content);

char const *v_dots_t_tag2str (v_dots_t_tag which);

Perror_t v_dots_t_init (P_t *pads,v_dots_t *rep);

Perror_t v_dots_t_pd_init (P_t *pads,v_dots_t_pd *pd);

Perror_t v_dots_t_cleanup (P_t *pads,v_dots_t *rep);

Perror_t v_dots_t_pd_cleanup (P_t *pads,v_dots_t_pd *pd);

Perror_t v_dots_t_copy (P_t *pads,v_dots_t *rep_dst,v_dots_t *rep_src);

Perror_t v_dots_t_pd_copy (P_t *pads,v_dots_t_pd *pd_dst,v_dots_t_pd *pd_src);

void v_dots_t_m_init (P_t *pads,v_dots_t_m *mask,Pbase_m baseMask);

Perror_t v_dots_t_m_rec_init (P_t *pads,v_dots_t_m *mask,Pbase_m baseMask);

Perror_t v_dots_t_read (P_t *pads,v_dots_t_m *m,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);

int v_dots_t_verify (P_t *pads,v_dots_t *rep,v_rec_content_t *v_rec_content);

int v_dots_t_genPD (P_t *pads,v_dots_t *rep,v_dots_t_pd *pd,v_rec_content_t *v_rec_content);
typedef struct v_dots_t_acc_s v_dots_t_acc;
struct v_dots_t_acc_s {
  Pint32_acc tag;
  Pstring_acc some_v_dots_t;
};

Perror_t v_dots_t_acc_init (P_t *pads,v_dots_t_acc *acc);

Perror_t v_dots_t_acc_reset (P_t *pads,v_dots_t_acc *acc);

Perror_t v_dots_t_acc_cleanup (P_t *pads,v_dots_t_acc *acc);

Perror_t v_dots_t_acc_add (P_t *pads,v_dots_t_acc *acc,v_dots_t_pd *pd,v_dots_t *rep);

Perror_t v_dots_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_dots_t_acc *acc);

Perror_t v_dots_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_dots_t_acc *acc);

Perror_t v_dots_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_dots_t_acc *acc);

ssize_t v_dots_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_dots_t_m *m,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);

ssize_t v_dots_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_dots_t_m *m,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);

ssize_t v_dots_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_dots_t_m *m,v_dots_t_pd *pd,v_dots_t *rep,v_rec_content_t *v_rec_content);
typedef struct string_t_s string_t;
typedef struct string_t_m_s string_t_m;
typedef struct string_t_pd_s string_t_pd;
struct string_t_m_s {
  Pbase_m compoundLevel;
  v_rec_content_t_m v_rec_content;		/* nested constraints */
  v_dots_t_m v_dots;		/* nested constraints */
};
struct string_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_rec_content_t_pd v_rec_content;
  v_dots_t_pd v_dots;
};
struct string_t_s {
  v_rec_content_t v_rec_content;
  v_dots_t v_dots;
};

Perror_t string_t_init (P_t *pads,string_t *rep);

Perror_t string_t_pd_init (P_t *pads,string_t_pd *pd);

Perror_t string_t_cleanup (P_t *pads,string_t *rep);

Perror_t string_t_pd_cleanup (P_t *pads,string_t_pd *pd);

Perror_t string_t_copy (P_t *pads,string_t *rep_dst,string_t *rep_src);

Perror_t string_t_pd_copy (P_t *pads,string_t_pd *pd_dst,string_t_pd *pd_src);

void string_t_m_init (P_t *pads,string_t_m *mask,Pbase_m baseMask);

Perror_t string_t_m_rec_init (P_t *pads,string_t_m *mask,Pbase_m baseMask);

Perror_t string_t_read (P_t *pads,string_t_m *m,string_t_pd *pd,string_t *rep);

int string_t_verify (P_t *pads,string_t *rep);

int string_t_genPD (P_t *pads,string_t *rep,string_t_pd *pd);
typedef struct string_t_acc_s string_t_acc;
struct string_t_acc_s {
  Puint32_acc nerr;
  v_rec_content_t_acc v_rec_content;
  v_dots_t_acc v_dots;
};

Perror_t string_t_acc_init (P_t *pads,string_t_acc *acc);

Perror_t string_t_acc_reset (P_t *pads,string_t_acc *acc);

Perror_t string_t_acc_cleanup (P_t *pads,string_t_acc *acc);

Perror_t string_t_acc_add (P_t *pads,string_t_acc *acc,string_t_pd *pd,string_t *rep);

Perror_t string_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,string_t_acc *acc);

Perror_t string_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,string_t_acc *acc);

Perror_t string_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,string_t_acc *acc);

ssize_t string_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,string_t_pd *pd,string_t *rep);

ssize_t string_t_write2io (P_t *pads,Sfio_t *io,string_t_pd *pd,string_t *rep);

ssize_t string_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,string_t_pd *pd,string_t *rep,char const *_tag,int indent);

ssize_t string_t_write_xml_2io (P_t *pads,Sfio_t *io,string_t_pd *pd,string_t *rep,char const *_tag,int indent);

ssize_t string_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,string_t_m *m,string_t_pd *pd,string_t *rep);

ssize_t string_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,string_t_m *m,string_t_pd *pd,string_t *rep);

ssize_t string_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,string_t_m *m,string_t_pd *pd,string_t *rep);
typedef struct paren_t_s paren_t;
typedef struct paren_t_m_s paren_t_m;
typedef struct paren_t_pd_s paren_t_pd;
struct paren_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m arg;		/* nested constraints */
};
struct paren_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd arg;
};
struct paren_t_s {
  Pstring arg;
};

Perror_t paren_t_init (P_t *pads,paren_t *rep);

Perror_t paren_t_pd_init (P_t *pads,paren_t_pd *pd);

Perror_t paren_t_cleanup (P_t *pads,paren_t *rep);

Perror_t paren_t_pd_cleanup (P_t *pads,paren_t_pd *pd);

Perror_t paren_t_copy (P_t *pads,paren_t *rep_dst,paren_t *rep_src);

Perror_t paren_t_pd_copy (P_t *pads,paren_t_pd *pd_dst,paren_t_pd *pd_src);

void paren_t_m_init (P_t *pads,paren_t_m *mask,Pbase_m baseMask);

Perror_t paren_t_m_rec_init (P_t *pads,paren_t_m *mask,Pbase_m baseMask);

Perror_t paren_t_read (P_t *pads,paren_t_m *m,paren_t_pd *pd,paren_t *rep);

int paren_t_verify (P_t *pads,paren_t *rep);

int paren_t_genPD (P_t *pads,paren_t *rep,paren_t_pd *pd);
typedef struct paren_t_acc_s paren_t_acc;
struct paren_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc arg;
};

Perror_t paren_t_acc_init (P_t *pads,paren_t_acc *acc);

Perror_t paren_t_acc_reset (P_t *pads,paren_t_acc *acc);

Perror_t paren_t_acc_cleanup (P_t *pads,paren_t_acc *acc);

Perror_t paren_t_acc_add (P_t *pads,paren_t_acc *acc,paren_t_pd *pd,paren_t *rep);

Perror_t paren_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,paren_t_acc *acc);

Perror_t paren_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,paren_t_acc *acc);

Perror_t paren_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,paren_t_acc *acc);

ssize_t paren_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,paren_t_pd *pd,paren_t *rep);

ssize_t paren_t_write2io (P_t *pads,Sfio_t *io,paren_t_pd *pd,paren_t *rep);

ssize_t paren_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,paren_t_pd *pd,paren_t *rep,char const *_tag,int indent);

ssize_t paren_t_write_xml_2io (P_t *pads,Sfio_t *io,paren_t_pd *pd,paren_t *rep,char const *_tag,int indent);

ssize_t paren_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,paren_t_m *m,paren_t_pd *pd,paren_t *rep);

ssize_t paren_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,paren_t_m *m,paren_t_pd *pd,paren_t *rep);

ssize_t paren_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,paren_t_m *m,paren_t_pd *pd,paren_t *rep);
typedef enum param_t_tag_e param_t_tag;
typedef union param_t_u_u param_t_u;
typedef struct param_t_s param_t;
typedef struct param_t_m_s param_t_m;
typedef union param_t_pd_u_u param_t_pd_u;
typedef struct param_t_pd_s param_t_pd;
enum param_t_tag_e {
  param_t_err=0,
  v_record=1,
  v_list=2,
  v_hex_val=3,
  v_string=4,
  v_other_param=5
  };
union param_t_pd_u_u {
  record_t_pd v_record;
  list_t_pd v_list;
  hex_t_pd v_hex_val;
  string_t_pd v_string;
  Pbase_pd v_other_param;
};
struct param_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  param_t_tag tag;
  param_t_pd_u val;
};
union param_t_u_u {
  record_t v_record;
  list_t v_list;
  hex_t v_hex_val;
  string_t v_string;
  Pstring v_other_param;
};
struct param_t_s {
  param_t_tag tag;
  param_t_u val;
};
struct param_t_m_s {
  Pbase_m compoundLevel;
  record_t_m v_record;		/* nested constraints */
  list_t_m v_list;		/* nested constraints */
  hex_t_m v_hex_val;		/* nested constraints */
  string_t_m v_string;		/* nested constraints */
  Pbase_m v_other_param;		/* nested constraints */
};

ssize_t param_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,param_t_pd *pd,param_t *rep);

ssize_t param_t_write2io (P_t *pads,Sfio_t *io,param_t_pd *pd,param_t *rep);

ssize_t param_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,param_t_pd *pd,param_t *rep,char const *_tag,int indent);

ssize_t param_t_write_xml_2io (P_t *pads,Sfio_t *io,param_t_pd *pd,param_t *rep,char const *_tag,int indent);

char const *param_t_tag2str (param_t_tag which);

Perror_t param_t_init (P_t *pads,param_t *rep);

Perror_t param_t_pd_init (P_t *pads,param_t_pd *pd);

Perror_t param_t_cleanup (P_t *pads,param_t *rep);

Perror_t param_t_pd_cleanup (P_t *pads,param_t_pd *pd);

Perror_t param_t_copy (P_t *pads,param_t *rep_dst,param_t *rep_src);

Perror_t param_t_pd_copy (P_t *pads,param_t_pd *pd_dst,param_t_pd *pd_src);

void param_t_m_init (P_t *pads,param_t_m *mask,Pbase_m baseMask);

Perror_t param_t_m_rec_init (P_t *pads,param_t_m *mask,Pbase_m baseMask);

Perror_t param_t_read (P_t *pads,param_t_m *m,param_t_pd *pd,param_t *rep);

int param_t_verify (P_t *pads,param_t *rep);

int param_t_genPD (P_t *pads,param_t *rep,param_t_pd *pd);
typedef struct param_t_acc_s param_t_acc;
struct param_t_acc_s {
  Pint32_acc tag;
  record_t_acc v_record;
  list_t_acc v_list;
  hex_t_acc v_hex_val;
  string_t_acc v_string;
  Pstring_acc v_other_param;
};

Perror_t param_t_acc_init (P_t *pads,param_t_acc *acc);

Perror_t param_t_acc_reset (P_t *pads,param_t_acc *acc);

Perror_t param_t_acc_cleanup (P_t *pads,param_t_acc *acc);

Perror_t param_t_acc_add (P_t *pads,param_t_acc *acc,param_t_pd *pd,param_t *rep);

Perror_t param_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,param_t_acc *acc);

Perror_t param_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,param_t_acc *acc);

Perror_t param_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,param_t_acc *acc);

ssize_t param_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,param_t_m *m,param_t_pd *pd,param_t *rep);

ssize_t param_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,param_t_m *m,param_t_pd *pd,param_t *rep);

ssize_t param_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,param_t_m *m,param_t_pd *pd,param_t *rep);
typedef struct params_array_t_s params_array_t;
typedef struct params_array_t_m_s params_array_t_m;
typedef struct params_array_t_pd_s params_array_t_pd;
typedef struct params_array_t_ro_params_t_s params_array_t_ro_params_t;
struct params_array_t_m_s {
  param_t_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct params_array_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  param_t_pd *elts;
  RBuf_t *_internal;
};
struct params_array_t_s {
  Puint32 length;
  param_t *elts;
  RBuf_t *_internal;
};
struct params_array_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
  char *terminator_str;
};

Perror_t params_array_t_init (P_t *pads,params_array_t *rep);

Perror_t params_array_t_pd_init (P_t *pads,params_array_t_pd *pd);

Perror_t params_array_t_cleanup (P_t *pads,params_array_t *rep);

Perror_t params_array_t_pd_cleanup (P_t *pads,params_array_t_pd *pd);

Perror_t params_array_t_copy (P_t *pads,params_array_t *rep_dst,params_array_t *rep_src);

Perror_t params_array_t_pd_copy (P_t *pads,params_array_t_pd *pd_dst,params_array_t_pd *pd_src);

void params_array_t_m_init (P_t *pads,params_array_t_m *mask,Pbase_m baseMask);

Perror_t params_array_t_m_rec_init (P_t *pads,params_array_t_m *mask,Pbase_m baseMask);

void params_array_t_ro_params_init (params_array_t_ro_params_t *params);

Pread_res_t params_array_t_final_checks (P_t *pads,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep,Ploc_t *loc_ptr,char *terminator_str,int foundTerm,int consume);

Pread_res_t params_array_t_read_one_init (P_t *pads,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep,Ploc_t *loc_ptr,char *terminator_str);

Pread_res_t params_array_t_read_one (P_t *pads,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep,Ploc_t *loc_ptr,param_t_pd *elt_pd,param_t *elt_rep,char *terminator_str);

Perror_t params_array_t_read (P_t *pads,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep);

Pread_res_t params_array_t_reread_one (char *terminator_str,P_t *pads,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep,Ploc_t *loc_ptr,param_t_pd *elt_pd,param_t *elt_rep,int notFirstElt);

int params_array_t_verify (P_t *pads,params_array_t *rep);

int params_array_t_genPD (P_t *pads,params_array_t *rep,params_array_t_pd *pd);
typedef struct params_array_t_acc_s params_array_t_acc;
struct params_array_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  param_t_acc compoundLevel;		/* Accumulator for all array elements */
  param_t_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t params_array_t_acc_init (P_t *pads,params_array_t_acc *acc);

Perror_t params_array_t_acc_reset (P_t *pads,params_array_t_acc *acc);

Perror_t params_array_t_acc_cleanup (P_t *pads,params_array_t_acc *acc);

Perror_t params_array_t_acc_add (P_t *pads,params_array_t_acc *acc,params_array_t_pd *pd,params_array_t *rep);

Perror_t params_array_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,params_array_t_acc *acc);

Perror_t params_array_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,params_array_t_acc *acc);

Perror_t params_array_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,params_array_t_acc *acc);

ssize_t params_array_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,params_array_t_pd *pd,params_array_t *rep);

ssize_t params_array_t_write2io (P_t *pads,Sfio_t *io,params_array_t_pd *pd,params_array_t *rep);

ssize_t params_array_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,params_array_t_pd *pd,params_array_t *rep,char const *_tag,int indent);

ssize_t params_array_t_write_xml_2io (P_t *pads,Sfio_t *io,params_array_t_pd *pd,params_array_t *rep,char const *_tag,int indent);

ssize_t params_array_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep);

ssize_t params_array_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep);

ssize_t params_array_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,params_array_t_m *m,params_array_t_pd *pd,params_array_t *rep);
typedef enum params_t_tag_e params_t_tag;
typedef union params_t_u_u params_t_u;
typedef struct params_t_s params_t;
typedef struct params_t_m_s params_t_m;
typedef union params_t_pd_u_u params_t_pd_u;
typedef struct params_t_pd_s params_t_pd;
enum params_t_tag_e {
  params_t_err=0,
  v_params_a=1,
  v_params_def=2
  };
union params_t_pd_u_u {
  params_array_t_pd v_params_a;
  Pbase_pd v_params_def;
};
struct params_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  params_t_tag tag;
  params_t_pd_u val;
};
union params_t_u_u {
  params_array_t v_params_a;
  Pstring v_params_def;
};
struct params_t_s {
  params_t_tag tag;
  params_t_u val;
};
struct params_t_m_s {
  Pbase_m compoundLevel;
  params_array_t_m v_params_a;		/* nested constraints */
  Pbase_m v_params_def;		/* nested constraints */
};

ssize_t params_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,params_t_pd *pd,params_t *rep);

ssize_t params_t_write2io (P_t *pads,Sfio_t *io,params_t_pd *pd,params_t *rep);

ssize_t params_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,params_t_pd *pd,params_t *rep,char const *_tag,int indent);

ssize_t params_t_write_xml_2io (P_t *pads,Sfio_t *io,params_t_pd *pd,params_t *rep,char const *_tag,int indent);

char const *params_t_tag2str (params_t_tag which);

Perror_t params_t_init (P_t *pads,params_t *rep);

Perror_t params_t_pd_init (P_t *pads,params_t_pd *pd);

Perror_t params_t_cleanup (P_t *pads,params_t *rep);

Perror_t params_t_pd_cleanup (P_t *pads,params_t_pd *pd);

Perror_t params_t_copy (P_t *pads,params_t *rep_dst,params_t *rep_src);

Perror_t params_t_pd_copy (P_t *pads,params_t_pd *pd_dst,params_t_pd *pd_src);

void params_t_m_init (P_t *pads,params_t_m *mask,Pbase_m baseMask);

Perror_t params_t_m_rec_init (P_t *pads,params_t_m *mask,Pbase_m baseMask);

Perror_t params_t_read (P_t *pads,params_t_m *m,params_t_pd *pd,params_t *rep);

int params_t_verify (P_t *pads,params_t *rep);

int params_t_genPD (P_t *pads,params_t *rep,params_t_pd *pd);
typedef struct params_t_acc_s params_t_acc;
struct params_t_acc_s {
  Pint32_acc tag;
  params_array_t_acc v_params_a;
  Pstring_acc v_params_def;
};

Perror_t params_t_acc_init (P_t *pads,params_t_acc *acc);

Perror_t params_t_acc_reset (P_t *pads,params_t_acc *acc);

Perror_t params_t_acc_cleanup (P_t *pads,params_t_acc *acc);

Perror_t params_t_acc_add (P_t *pads,params_t_acc *acc,params_t_pd *pd,params_t *rep);

Perror_t params_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,params_t_acc *acc);

Perror_t params_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,params_t_acc *acc);

Perror_t params_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,params_t_acc *acc);

ssize_t params_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,params_t_m *m,params_t_pd *pd,params_t *rep);

ssize_t params_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,params_t_m *m,params_t_pd *pd,params_t *rep);

ssize_t params_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,params_t_m *m,params_t_pd *pd,params_t *rep);
typedef enum val_t_tag_e val_t_tag;
typedef union val_t_u_u val_t_u;
typedef struct val_t_s val_t;
typedef struct val_t_m_s val_t_m;
typedef union val_t_pd_u_u val_t_pd_u;
typedef struct val_t_pd_s val_t_pd;
enum val_t_tag_e {
  val_t_err=0,
  v_hex=1,
  v_int=2,
  v_que=3
  };
union val_t_pd_u_u {
  hex_t_pd v_hex;
  Pbase_pd v_int;
  Pbase_pd v_que;
};
struct val_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  val_t_tag tag;
  val_t_pd_u val;
};
union val_t_u_u {
  hex_t v_hex;
  Pint32 v_int;
};
struct val_t_s {
  val_t_tag tag;
  val_t_u val;
};
struct val_t_m_s {
  Pbase_m compoundLevel;
  hex_t_m v_hex;		/* nested constraints */
  Pbase_m v_int;		/* nested constraints */
};

ssize_t val_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,val_t_pd *pd,val_t *rep);

ssize_t val_t_write2io (P_t *pads,Sfio_t *io,val_t_pd *pd,val_t *rep);

ssize_t val_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,val_t_pd *pd,val_t *rep,char const *_tag,int indent);

ssize_t val_t_write_xml_2io (P_t *pads,Sfio_t *io,val_t_pd *pd,val_t *rep,char const *_tag,int indent);

char const *val_t_tag2str (val_t_tag which);

Perror_t val_t_init (P_t *pads,val_t *rep);

Perror_t val_t_pd_init (P_t *pads,val_t_pd *pd);

Perror_t val_t_cleanup (P_t *pads,val_t *rep);

Perror_t val_t_pd_cleanup (P_t *pads,val_t_pd *pd);

Perror_t val_t_copy (P_t *pads,val_t *rep_dst,val_t *rep_src);

Perror_t val_t_pd_copy (P_t *pads,val_t_pd *pd_dst,val_t_pd *pd_src);

void val_t_m_init (P_t *pads,val_t_m *mask,Pbase_m baseMask);

Perror_t val_t_m_rec_init (P_t *pads,val_t_m *mask,Pbase_m baseMask);

Perror_t val_t_read (P_t *pads,val_t_m *m,val_t_pd *pd,val_t *rep);

int val_t_verify (P_t *pads,val_t *rep);

int val_t_genPD (P_t *pads,val_t *rep,val_t_pd *pd);
typedef struct val_t_acc_s val_t_acc;
struct val_t_acc_s {
  Pint32_acc tag;
  hex_t_acc v_hex;
  Pint32_acc v_int;
};

Perror_t val_t_acc_init (P_t *pads,val_t_acc *acc);

Perror_t val_t_acc_reset (P_t *pads,val_t_acc *acc);

Perror_t val_t_acc_cleanup (P_t *pads,val_t_acc *acc);

Perror_t val_t_acc_add (P_t *pads,val_t_acc *acc,val_t_pd *pd,val_t *rep);

Perror_t val_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,val_t_acc *acc);

Perror_t val_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,val_t_acc *acc);

Perror_t val_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,val_t_acc *acc);

ssize_t val_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,val_t_m *m,val_t_pd *pd,val_t *rep);

ssize_t val_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,val_t_m *m,val_t_pd *pd,val_t *rep);

ssize_t val_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,val_t_m *m,val_t_pd *pd,val_t *rep);
typedef struct err_t_s err_t;
typedef struct err_t_m_s err_t_m;
typedef struct err_t_pd_s err_t_pd;
struct err_t_m_s {
  Pbase_m compoundLevel;
  PPwhite_m v_space1;		/* nested constraints */
  PPstring_m v_err_code;		/* nested constraints */
};
struct err_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  PPwhite_pd v_space1;
  PPstring_pd v_err_code;
};
struct err_t_s {
  PPwhite v_space1;
  PPstring v_err_code;
};

Perror_t err_t_init (P_t *pads,err_t *rep);

Perror_t err_t_pd_init (P_t *pads,err_t_pd *pd);

Perror_t err_t_cleanup (P_t *pads,err_t *rep);

Perror_t err_t_pd_cleanup (P_t *pads,err_t_pd *pd);

Perror_t err_t_copy (P_t *pads,err_t *rep_dst,err_t *rep_src);

Perror_t err_t_pd_copy (P_t *pads,err_t_pd *pd_dst,err_t_pd *pd_src);

void err_t_m_init (P_t *pads,err_t_m *mask,Pbase_m baseMask);

Perror_t err_t_m_rec_init (P_t *pads,err_t_m *mask,Pbase_m baseMask);

Perror_t err_t_read (P_t *pads,err_t_m *m,err_t_pd *pd,err_t *rep);

int err_t_verify (P_t *pads,err_t *rep);

int err_t_genPD (P_t *pads,err_t *rep,err_t_pd *pd);
typedef struct err_t_acc_s err_t_acc;
struct err_t_acc_s {
  Puint32_acc nerr;
  PPwhite_acc v_space1;
  PPstring_acc v_err_code;
};

Perror_t err_t_acc_init (P_t *pads,err_t_acc *acc);

Perror_t err_t_acc_reset (P_t *pads,err_t_acc *acc);

Perror_t err_t_acc_cleanup (P_t *pads,err_t_acc *acc);

Perror_t err_t_acc_add (P_t *pads,err_t_acc *acc,err_t_pd *pd,err_t *rep);

Perror_t err_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,err_t_acc *acc);

Perror_t err_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,err_t_acc *acc);

Perror_t err_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,err_t_acc *acc);

ssize_t err_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,err_t_pd *pd,err_t *rep);

ssize_t err_t_write2io (P_t *pads,Sfio_t *io,err_t_pd *pd,err_t *rep);

ssize_t err_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,err_t_pd *pd,err_t *rep,char const *_tag,int indent);

ssize_t err_t_write_xml_2io (P_t *pads,Sfio_t *io,err_t_pd *pd,err_t *rep,char const *_tag,int indent);

ssize_t err_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,err_t_m *m,err_t_pd *pd,err_t *rep);

ssize_t err_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,err_t_m *m,err_t_pd *pd,err_t *rep);

ssize_t err_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,err_t_m *m,err_t_pd *pd,err_t *rep);
typedef struct err_msg_t_s err_msg_t;
typedef struct err_msg_t_m_s err_msg_t_m;
typedef struct err_msg_t_pd_s err_msg_t_pd;
struct err_msg_t_m_s {
  Pbase_m compoundLevel;
  PPwhite_m v_space2;		/* nested constraints */
  Pbase_m v_err_msg;		/* nested constraints */
};
struct err_msg_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  PPwhite_pd v_space2;
  Pbase_pd v_err_msg;
};
struct err_msg_t_s {
  PPwhite v_space2;
  Pstring v_err_msg;
};

Perror_t err_msg_t_init (P_t *pads,err_msg_t *rep);

Perror_t err_msg_t_pd_init (P_t *pads,err_msg_t_pd *pd);

Perror_t err_msg_t_cleanup (P_t *pads,err_msg_t *rep);

Perror_t err_msg_t_pd_cleanup (P_t *pads,err_msg_t_pd *pd);

Perror_t err_msg_t_copy (P_t *pads,err_msg_t *rep_dst,err_msg_t *rep_src);

Perror_t err_msg_t_pd_copy (P_t *pads,err_msg_t_pd *pd_dst,err_msg_t_pd *pd_src);

void err_msg_t_m_init (P_t *pads,err_msg_t_m *mask,Pbase_m baseMask);

Perror_t err_msg_t_m_rec_init (P_t *pads,err_msg_t_m *mask,Pbase_m baseMask);

Perror_t err_msg_t_read (P_t *pads,err_msg_t_m *m,err_msg_t_pd *pd,err_msg_t *rep);

int err_msg_t_verify (P_t *pads,err_msg_t *rep);

int err_msg_t_genPD (P_t *pads,err_msg_t *rep,err_msg_t_pd *pd);
typedef struct err_msg_t_acc_s err_msg_t_acc;
struct err_msg_t_acc_s {
  Puint32_acc nerr;
  PPwhite_acc v_space2;
  Pstring_acc v_err_msg;
};

Perror_t err_msg_t_acc_init (P_t *pads,err_msg_t_acc *acc);

Perror_t err_msg_t_acc_reset (P_t *pads,err_msg_t_acc *acc);

Perror_t err_msg_t_acc_cleanup (P_t *pads,err_msg_t_acc *acc);

Perror_t err_msg_t_acc_add (P_t *pads,err_msg_t_acc *acc,err_msg_t_pd *pd,err_msg_t *rep);

Perror_t err_msg_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,err_msg_t_acc *acc);

Perror_t err_msg_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,err_msg_t_acc *acc);

Perror_t err_msg_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,err_msg_t_acc *acc);

ssize_t err_msg_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,err_msg_t_pd *pd,err_msg_t *rep);

ssize_t err_msg_t_write2io (P_t *pads,Sfio_t *io,err_msg_t_pd *pd,err_msg_t *rep);

ssize_t err_msg_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,err_msg_t_pd *pd,err_msg_t *rep,char const *_tag,int indent);

ssize_t err_msg_t_write_xml_2io (P_t *pads,Sfio_t *io,err_msg_t_pd *pd,err_msg_t *rep,char const *_tag,int indent);

ssize_t err_msg_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,err_msg_t_m *m,err_msg_t_pd *pd,err_msg_t *rep);

ssize_t err_msg_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,err_msg_t_m *m,err_msg_t_pd *pd,err_msg_t *rep);

ssize_t err_msg_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,err_msg_t_m *m,err_msg_t_pd *pd,err_msg_t *rep);
typedef enum v_err_code_t_tag_e v_err_code_t_tag;
typedef union v_err_code_t_u_u v_err_code_t_u;
typedef struct v_err_code_t_s v_err_code_t;
typedef struct v_err_code_t_m_s v_err_code_t_m;
typedef union v_err_code_t_pd_u_u v_err_code_t_pd_u;
typedef struct v_err_code_t_pd_s v_err_code_t_pd;
enum v_err_code_t_tag_e {
  v_err_code_t_err=0,
  some_v_err_code_t=1,
  none_v_err_code_t=2
  };
union v_err_code_t_pd_u_u {
  err_t_pd some_v_err_code_t;
  Pbase_pd none_v_err_code_t;		/* value was not present. none_v_err_code_t = 0 */
};
struct v_err_code_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_err_code_t_tag tag;
  v_err_code_t_pd_u val;
};
union v_err_code_t_u_u {
  err_t some_v_err_code_t;		/* value is present */
};
struct v_err_code_t_s {
  v_err_code_t_tag tag;
  v_err_code_t_u val;
};
struct v_err_code_t_m_s {
  Pbase_m compoundLevel;
  err_t_m some_v_err_code_t;		/* nested constraints */
  Pbase_m none_v_err_code_t;		/* nested constraints */
};

ssize_t v_err_code_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);

ssize_t v_err_code_t_write2io (P_t *pads,Sfio_t *io,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);

ssize_t v_err_code_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_err_code_t_pd *pd,v_err_code_t *rep,char const *_tag,int indent,val_t *v_val);

ssize_t v_err_code_t_write_xml_2io (P_t *pads,Sfio_t *io,v_err_code_t_pd *pd,v_err_code_t *rep,char const *_tag,int indent,val_t *v_val);

char const *v_err_code_t_tag2str (v_err_code_t_tag which);

Perror_t v_err_code_t_init (P_t *pads,v_err_code_t *rep);

Perror_t v_err_code_t_pd_init (P_t *pads,v_err_code_t_pd *pd);

Perror_t v_err_code_t_cleanup (P_t *pads,v_err_code_t *rep);

Perror_t v_err_code_t_pd_cleanup (P_t *pads,v_err_code_t_pd *pd);

Perror_t v_err_code_t_copy (P_t *pads,v_err_code_t *rep_dst,v_err_code_t *rep_src);

Perror_t v_err_code_t_pd_copy (P_t *pads,v_err_code_t_pd *pd_dst,v_err_code_t_pd *pd_src);

void v_err_code_t_m_init (P_t *pads,v_err_code_t_m *mask,Pbase_m baseMask);

Perror_t v_err_code_t_m_rec_init (P_t *pads,v_err_code_t_m *mask,Pbase_m baseMask);

Perror_t v_err_code_t_read (P_t *pads,v_err_code_t_m *m,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);

int v_err_code_t_verify (P_t *pads,v_err_code_t *rep,val_t *v_val);

int v_err_code_t_genPD (P_t *pads,v_err_code_t *rep,v_err_code_t_pd *pd,val_t *v_val);
typedef struct v_err_code_t_acc_s v_err_code_t_acc;
struct v_err_code_t_acc_s {
  Pint32_acc tag;
  err_t_acc some_v_err_code_t;
};

Perror_t v_err_code_t_acc_init (P_t *pads,v_err_code_t_acc *acc);

Perror_t v_err_code_t_acc_reset (P_t *pads,v_err_code_t_acc *acc);

Perror_t v_err_code_t_acc_cleanup (P_t *pads,v_err_code_t_acc *acc);

Perror_t v_err_code_t_acc_add (P_t *pads,v_err_code_t_acc *acc,v_err_code_t_pd *pd,v_err_code_t *rep);

Perror_t v_err_code_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_err_code_t_acc *acc);

Perror_t v_err_code_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_err_code_t_acc *acc);

Perror_t v_err_code_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_err_code_t_acc *acc);

ssize_t v_err_code_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_err_code_t_m *m,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);

ssize_t v_err_code_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_err_code_t_m *m,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);

ssize_t v_err_code_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_err_code_t_m *m,v_err_code_t_pd *pd,v_err_code_t *rep,val_t *v_val);
typedef enum v_msg_t_tag_e v_msg_t_tag;
typedef union v_msg_t_u_u v_msg_t_u;
typedef struct v_msg_t_s v_msg_t;
typedef struct v_msg_t_m_s v_msg_t_m;
typedef union v_msg_t_pd_u_u v_msg_t_pd_u;
typedef struct v_msg_t_pd_s v_msg_t_pd;
enum v_msg_t_tag_e {
  v_msg_t_err=0,
  some_v_msg_t=1,
  none_v_msg_t=2
  };
union v_msg_t_pd_u_u {
  err_msg_t_pd some_v_msg_t;
  Pbase_pd none_v_msg_t;		/* value was not present. none_v_msg_t = 0 */
};
struct v_msg_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_msg_t_tag tag;
  v_msg_t_pd_u val;
};
union v_msg_t_u_u {
  err_msg_t some_v_msg_t;		/* value is present */
};
struct v_msg_t_s {
  v_msg_t_tag tag;
  v_msg_t_u val;
};
struct v_msg_t_m_s {
  Pbase_m compoundLevel;
  err_msg_t_m some_v_msg_t;		/* nested constraints */
  Pbase_m none_v_msg_t;		/* nested constraints */
};

ssize_t v_msg_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

ssize_t v_msg_t_write2io (P_t *pads,Sfio_t *io,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

ssize_t v_msg_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_msg_t_pd *pd,v_msg_t *rep,char const *_tag,int indent,val_t *v_val,v_err_code_t *v_err_code);

ssize_t v_msg_t_write_xml_2io (P_t *pads,Sfio_t *io,v_msg_t_pd *pd,v_msg_t *rep,char const *_tag,int indent,val_t *v_val,v_err_code_t *v_err_code);

char const *v_msg_t_tag2str (v_msg_t_tag which);

Perror_t v_msg_t_init (P_t *pads,v_msg_t *rep);

Perror_t v_msg_t_pd_init (P_t *pads,v_msg_t_pd *pd);

Perror_t v_msg_t_cleanup (P_t *pads,v_msg_t *rep);

Perror_t v_msg_t_pd_cleanup (P_t *pads,v_msg_t_pd *pd);

Perror_t v_msg_t_copy (P_t *pads,v_msg_t *rep_dst,v_msg_t *rep_src);

Perror_t v_msg_t_pd_copy (P_t *pads,v_msg_t_pd *pd_dst,v_msg_t_pd *pd_src);

void v_msg_t_m_init (P_t *pads,v_msg_t_m *mask,Pbase_m baseMask);

Perror_t v_msg_t_m_rec_init (P_t *pads,v_msg_t_m *mask,Pbase_m baseMask);

Perror_t v_msg_t_read (P_t *pads,v_msg_t_m *m,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

int v_msg_t_verify (P_t *pads,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

int v_msg_t_genPD (P_t *pads,v_msg_t *rep,v_msg_t_pd *pd,val_t *v_val,v_err_code_t *v_err_code);
typedef struct v_msg_t_acc_s v_msg_t_acc;
struct v_msg_t_acc_s {
  Pint32_acc tag;
  err_msg_t_acc some_v_msg_t;
};

Perror_t v_msg_t_acc_init (P_t *pads,v_msg_t_acc *acc);

Perror_t v_msg_t_acc_reset (P_t *pads,v_msg_t_acc *acc);

Perror_t v_msg_t_acc_cleanup (P_t *pads,v_msg_t_acc *acc);

Perror_t v_msg_t_acc_add (P_t *pads,v_msg_t_acc *acc,v_msg_t_pd *pd,v_msg_t *rep);

Perror_t v_msg_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_msg_t_acc *acc);

Perror_t v_msg_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_msg_t_acc *acc);

Perror_t v_msg_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_msg_t_acc *acc);

ssize_t v_msg_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_msg_t_m *m,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

ssize_t v_msg_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_msg_t_m *m,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);

ssize_t v_msg_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_msg_t_m *m,v_msg_t_pd *pd,v_msg_t *rep,val_t *v_val,v_err_code_t *v_err_code);
typedef struct return_t_s return_t;
typedef struct return_t_m_s return_t_m;
typedef struct return_t_pd_s return_t_pd;
struct return_t_m_s {
  Pbase_m compoundLevel;
  val_t_m v_val;		/* nested constraints */
  v_err_code_t_m v_err_code;		/* nested constraints */
  v_msg_t_m v_msg;		/* nested constraints */
};
struct return_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  val_t_pd v_val;
  v_err_code_t_pd v_err_code;
  v_msg_t_pd v_msg;
};
struct return_t_s {
  val_t v_val;
  v_err_code_t v_err_code;
  v_msg_t v_msg;
};

Perror_t return_t_init (P_t *pads,return_t *rep);

Perror_t return_t_pd_init (P_t *pads,return_t_pd *pd);

Perror_t return_t_cleanup (P_t *pads,return_t *rep);

Perror_t return_t_pd_cleanup (P_t *pads,return_t_pd *pd);

Perror_t return_t_copy (P_t *pads,return_t *rep_dst,return_t *rep_src);

Perror_t return_t_pd_copy (P_t *pads,return_t_pd *pd_dst,return_t_pd *pd_src);

void return_t_m_init (P_t *pads,return_t_m *mask,Pbase_m baseMask);

Perror_t return_t_m_rec_init (P_t *pads,return_t_m *mask,Pbase_m baseMask);

Perror_t return_t_read (P_t *pads,return_t_m *m,return_t_pd *pd,return_t *rep);

int return_t_verify (P_t *pads,return_t *rep);

int return_t_genPD (P_t *pads,return_t *rep,return_t_pd *pd);
typedef struct return_t_acc_s return_t_acc;
struct return_t_acc_s {
  Puint32_acc nerr;
  val_t_acc v_val;
  v_err_code_t_acc v_err_code;
  v_msg_t_acc v_msg;
};

Perror_t return_t_acc_init (P_t *pads,return_t_acc *acc);

Perror_t return_t_acc_reset (P_t *pads,return_t_acc *acc);

Perror_t return_t_acc_cleanup (P_t *pads,return_t_acc *acc);

Perror_t return_t_acc_add (P_t *pads,return_t_acc *acc,return_t_pd *pd,return_t *rep);

Perror_t return_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,return_t_acc *acc);

Perror_t return_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,return_t_acc *acc);

Perror_t return_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,return_t_acc *acc);

ssize_t return_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,return_t_pd *pd,return_t *rep);

ssize_t return_t_write2io (P_t *pads,Sfio_t *io,return_t_pd *pd,return_t *rep);

ssize_t return_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,return_t_pd *pd,return_t *rep,char const *_tag,int indent);

ssize_t return_t_write_xml_2io (P_t *pads,Sfio_t *io,return_t_pd *pd,return_t *rep,char const *_tag,int indent);

ssize_t return_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,return_t_m *m,return_t_pd *pd,return_t *rep);

ssize_t return_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,return_t_m *m,return_t_pd *pd,return_t *rep);

ssize_t return_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,return_t_m *m,return_t_pd *pd,return_t *rep);
typedef struct timing_t_s timing_t;
typedef struct timing_t_m_s timing_t_m;
typedef struct timing_t_pd_s timing_t_pd;
struct timing_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_timing;		/* nested constraints */
};
struct timing_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_timing;
};
struct timing_t_s {
  Pfloat64 v_timing;
};

Perror_t timing_t_init (P_t *pads,timing_t *rep);

Perror_t timing_t_pd_init (P_t *pads,timing_t_pd *pd);

Perror_t timing_t_cleanup (P_t *pads,timing_t *rep);

Perror_t timing_t_pd_cleanup (P_t *pads,timing_t_pd *pd);

Perror_t timing_t_copy (P_t *pads,timing_t *rep_dst,timing_t *rep_src);

Perror_t timing_t_pd_copy (P_t *pads,timing_t_pd *pd_dst,timing_t_pd *pd_src);

void timing_t_m_init (P_t *pads,timing_t_m *mask,Pbase_m baseMask);

Perror_t timing_t_m_rec_init (P_t *pads,timing_t_m *mask,Pbase_m baseMask);

Perror_t timing_t_read (P_t *pads,timing_t_m *m,timing_t_pd *pd,timing_t *rep);

int timing_t_verify (P_t *pads,timing_t *rep);

int timing_t_genPD (P_t *pads,timing_t *rep,timing_t_pd *pd);
typedef struct timing_t_acc_s timing_t_acc;
struct timing_t_acc_s {
  Puint32_acc nerr;
  Pfloat64_acc v_timing;
};

Perror_t timing_t_acc_init (P_t *pads,timing_t_acc *acc);

Perror_t timing_t_acc_reset (P_t *pads,timing_t_acc *acc);

Perror_t timing_t_acc_cleanup (P_t *pads,timing_t_acc *acc);

Perror_t timing_t_acc_add (P_t *pads,timing_t_acc *acc,timing_t_pd *pd,timing_t *rep);

Perror_t timing_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,timing_t_acc *acc);

Perror_t timing_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,timing_t_acc *acc);

Perror_t timing_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,timing_t_acc *acc);

ssize_t timing_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,timing_t_pd *pd,timing_t *rep);

ssize_t timing_t_write2io (P_t *pads,Sfio_t *io,timing_t_pd *pd,timing_t *rep);

ssize_t timing_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,timing_t_pd *pd,timing_t *rep,char const *_tag,int indent);

ssize_t timing_t_write_xml_2io (P_t *pads,Sfio_t *io,timing_t_pd *pd,timing_t *rep,char const *_tag,int indent);

ssize_t timing_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,timing_t_m *m,timing_t_pd *pd,timing_t *rep);

ssize_t timing_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,timing_t_m *m,timing_t_pd *pd,timing_t *rep);

ssize_t timing_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,timing_t_m *m,timing_t_pd *pd,timing_t *rep);
typedef struct unfinished_t_s unfinished_t;
typedef struct unfinished_t_m_s unfinished_t_m;
typedef struct unfinished_t_pd_s unfinished_t_pd;
struct unfinished_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_func_name;		/* nested constraints */
  Pbase_m v_unfinished;		/* nested constraints */
};
struct unfinished_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_func_name;
  Pbase_pd v_unfinished;
};
struct unfinished_t_s {
  Pstring v_func_name;
  Pstring v_unfinished;
};

Perror_t unfinished_t_init (P_t *pads,unfinished_t *rep);

Perror_t unfinished_t_pd_init (P_t *pads,unfinished_t_pd *pd);

Perror_t unfinished_t_cleanup (P_t *pads,unfinished_t *rep);

Perror_t unfinished_t_pd_cleanup (P_t *pads,unfinished_t_pd *pd);

Perror_t unfinished_t_copy (P_t *pads,unfinished_t *rep_dst,unfinished_t *rep_src);

Perror_t unfinished_t_pd_copy (P_t *pads,unfinished_t_pd *pd_dst,unfinished_t_pd *pd_src);

void unfinished_t_m_init (P_t *pads,unfinished_t_m *mask,Pbase_m baseMask);

Perror_t unfinished_t_m_rec_init (P_t *pads,unfinished_t_m *mask,Pbase_m baseMask);

Perror_t unfinished_t_read (P_t *pads,unfinished_t_m *m,unfinished_t_pd *pd,unfinished_t *rep);

int unfinished_t_verify (P_t *pads,unfinished_t *rep);

int unfinished_t_genPD (P_t *pads,unfinished_t *rep,unfinished_t_pd *pd);
typedef struct unfinished_t_acc_s unfinished_t_acc;
struct unfinished_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc v_func_name;
  Pstring_acc v_unfinished;
};

Perror_t unfinished_t_acc_init (P_t *pads,unfinished_t_acc *acc);

Perror_t unfinished_t_acc_reset (P_t *pads,unfinished_t_acc *acc);

Perror_t unfinished_t_acc_cleanup (P_t *pads,unfinished_t_acc *acc);

Perror_t unfinished_t_acc_add (P_t *pads,unfinished_t_acc *acc,unfinished_t_pd *pd,unfinished_t *rep);

Perror_t unfinished_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,unfinished_t_acc *acc);

Perror_t unfinished_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,unfinished_t_acc *acc);

Perror_t unfinished_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,unfinished_t_acc *acc);

ssize_t unfinished_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,unfinished_t_pd *pd,unfinished_t *rep);

ssize_t unfinished_t_write2io (P_t *pads,Sfio_t *io,unfinished_t_pd *pd,unfinished_t *rep);

ssize_t unfinished_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,unfinished_t_pd *pd,unfinished_t *rep,char const *_tag,int indent);

ssize_t unfinished_t_write_xml_2io (P_t *pads,Sfio_t *io,unfinished_t_pd *pd,unfinished_t *rep,char const *_tag,int indent);

ssize_t unfinished_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,unfinished_t_m *m,unfinished_t_pd *pd,unfinished_t *rep);

ssize_t unfinished_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,unfinished_t_m *m,unfinished_t_pd *pd,unfinished_t *rep);

ssize_t unfinished_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,unfinished_t_m *m,unfinished_t_pd *pd,unfinished_t *rep);
typedef enum v_space3_t_tag_e v_space3_t_tag;
typedef union v_space3_t_u_u v_space3_t_u;
typedef struct v_space3_t_s v_space3_t;
typedef struct v_space3_t_m_s v_space3_t_m;
typedef union v_space3_t_pd_u_u v_space3_t_pd_u;
typedef struct v_space3_t_pd_s v_space3_t_pd;
enum v_space3_t_tag_e {
  v_space3_t_err=0,
  some_v_space3_t=1,
  none_v_space3_t=2
  };
union v_space3_t_pd_u_u {
  PPwhite_pd some_v_space3_t;
  Pbase_pd none_v_space3_t;		/* value was not present. none_v_space3_t = 0 */
};
struct v_space3_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_space3_t_tag tag;
  v_space3_t_pd_u val;
};
union v_space3_t_u_u {
  PPwhite some_v_space3_t;		/* value is present */
};
struct v_space3_t_s {
  v_space3_t_tag tag;
  v_space3_t_u val;
};
struct v_space3_t_m_s {
  Pbase_m compoundLevel;
  PPwhite_m some_v_space3_t;		/* nested constraints */
  Pbase_m none_v_space3_t;		/* nested constraints */
};

ssize_t v_space3_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

ssize_t v_space3_t_write2io (P_t *pads,Sfio_t *io,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

ssize_t v_space3_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_space3_t_pd *pd,v_space3_t *rep,char const *_tag,int indent,Pstring *v_resumed,return_t *v_result);

ssize_t v_space3_t_write_xml_2io (P_t *pads,Sfio_t *io,v_space3_t_pd *pd,v_space3_t *rep,char const *_tag,int indent,Pstring *v_resumed,return_t *v_result);

char const *v_space3_t_tag2str (v_space3_t_tag which);

Perror_t v_space3_t_init (P_t *pads,v_space3_t *rep);

Perror_t v_space3_t_pd_init (P_t *pads,v_space3_t_pd *pd);

Perror_t v_space3_t_cleanup (P_t *pads,v_space3_t *rep);

Perror_t v_space3_t_pd_cleanup (P_t *pads,v_space3_t_pd *pd);

Perror_t v_space3_t_copy (P_t *pads,v_space3_t *rep_dst,v_space3_t *rep_src);

Perror_t v_space3_t_pd_copy (P_t *pads,v_space3_t_pd *pd_dst,v_space3_t_pd *pd_src);

void v_space3_t_m_init (P_t *pads,v_space3_t_m *mask,Pbase_m baseMask);

Perror_t v_space3_t_m_rec_init (P_t *pads,v_space3_t_m *mask,Pbase_m baseMask);

Perror_t v_space3_t_read (P_t *pads,v_space3_t_m *m,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

int v_space3_t_verify (P_t *pads,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

int v_space3_t_genPD (P_t *pads,v_space3_t *rep,v_space3_t_pd *pd,Pstring *v_resumed,return_t *v_result);
typedef struct v_space3_t_acc_s v_space3_t_acc;
struct v_space3_t_acc_s {
  Pint32_acc tag;
  PPwhite_acc some_v_space3_t;
};

Perror_t v_space3_t_acc_init (P_t *pads,v_space3_t_acc *acc);

Perror_t v_space3_t_acc_reset (P_t *pads,v_space3_t_acc *acc);

Perror_t v_space3_t_acc_cleanup (P_t *pads,v_space3_t_acc *acc);

Perror_t v_space3_t_acc_add (P_t *pads,v_space3_t_acc *acc,v_space3_t_pd *pd,v_space3_t *rep);

Perror_t v_space3_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_space3_t_acc *acc);

Perror_t v_space3_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_space3_t_acc *acc);

Perror_t v_space3_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_space3_t_acc *acc);

ssize_t v_space3_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_space3_t_m *m,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

ssize_t v_space3_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_space3_t_m *m,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);

ssize_t v_space3_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_space3_t_m *m,v_space3_t_pd *pd,v_space3_t *rep,Pstring *v_resumed,return_t *v_result);
typedef enum v_time_t_tag_e v_time_t_tag;
typedef union v_time_t_u_u v_time_t_u;
typedef struct v_time_t_s v_time_t;
typedef struct v_time_t_m_s v_time_t_m;
typedef union v_time_t_pd_u_u v_time_t_pd_u;
typedef struct v_time_t_pd_s v_time_t_pd;
enum v_time_t_tag_e {
  v_time_t_err=0,
  some_v_time_t=1,
  none_v_time_t=2
  };
union v_time_t_pd_u_u {
  timing_t_pd some_v_time_t;
  Pbase_pd none_v_time_t;		/* value was not present. none_v_time_t = 0 */
};
struct v_time_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_time_t_tag tag;
  v_time_t_pd_u val;
};
union v_time_t_u_u {
  timing_t some_v_time_t;		/* value is present */
};
struct v_time_t_s {
  v_time_t_tag tag;
  v_time_t_u val;
};
struct v_time_t_m_s {
  Pbase_m compoundLevel;
  timing_t_m some_v_time_t;		/* nested constraints */
  Pbase_m none_v_time_t;		/* nested constraints */
};

ssize_t v_time_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

ssize_t v_time_t_write2io (P_t *pads,Sfio_t *io,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

ssize_t v_time_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_time_t_pd *pd,v_time_t *rep,char const *_tag,int indent,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

ssize_t v_time_t_write_xml_2io (P_t *pads,Sfio_t *io,v_time_t_pd *pd,v_time_t *rep,char const *_tag,int indent,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

char const *v_time_t_tag2str (v_time_t_tag which);

Perror_t v_time_t_init (P_t *pads,v_time_t *rep);

Perror_t v_time_t_pd_init (P_t *pads,v_time_t_pd *pd);

Perror_t v_time_t_cleanup (P_t *pads,v_time_t *rep);

Perror_t v_time_t_pd_cleanup (P_t *pads,v_time_t_pd *pd);

Perror_t v_time_t_copy (P_t *pads,v_time_t *rep_dst,v_time_t *rep_src);

Perror_t v_time_t_pd_copy (P_t *pads,v_time_t_pd *pd_dst,v_time_t_pd *pd_src);

void v_time_t_m_init (P_t *pads,v_time_t_m *mask,Pbase_m baseMask);

Perror_t v_time_t_m_rec_init (P_t *pads,v_time_t_m *mask,Pbase_m baseMask);

Perror_t v_time_t_read (P_t *pads,v_time_t_m *m,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

int v_time_t_verify (P_t *pads,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

int v_time_t_genPD (P_t *pads,v_time_t *rep,v_time_t_pd *pd,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);
typedef struct v_time_t_acc_s v_time_t_acc;
struct v_time_t_acc_s {
  Pint32_acc tag;
  timing_t_acc some_v_time_t;
};

Perror_t v_time_t_acc_init (P_t *pads,v_time_t_acc *acc);

Perror_t v_time_t_acc_reset (P_t *pads,v_time_t_acc *acc);

Perror_t v_time_t_acc_cleanup (P_t *pads,v_time_t_acc *acc);

Perror_t v_time_t_acc_add (P_t *pads,v_time_t_acc *acc,v_time_t_pd *pd,v_time_t *rep);

Perror_t v_time_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_time_t_acc *acc);

Perror_t v_time_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_time_t_acc *acc);

Perror_t v_time_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_time_t_acc *acc);

ssize_t v_time_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_time_t_m *m,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

ssize_t v_time_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_time_t_m *m,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);

ssize_t v_time_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_time_t_m *m,v_time_t_pd *pd,v_time_t *rep,Pstring *v_resumed,return_t *v_result,v_space3_t *v_space3);
typedef struct resumed_t_s resumed_t;
typedef struct resumed_t_m_s resumed_t_m;
typedef struct resumed_t_pd_s resumed_t_pd;
struct resumed_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_resumed;		/* nested constraints */
  return_t_m v_result;		/* nested constraints */
  v_space3_t_m v_space3;		/* nested constraints */
  v_time_t_m v_time;		/* nested constraints */
};
struct resumed_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_resumed;
  return_t_pd v_result;
  v_space3_t_pd v_space3;
  v_time_t_pd v_time;
};
struct resumed_t_s {
  Pstring v_resumed;
  return_t v_result;
  v_space3_t v_space3;
  v_time_t v_time;
};

Perror_t resumed_t_init (P_t *pads,resumed_t *rep);

Perror_t resumed_t_pd_init (P_t *pads,resumed_t_pd *pd);

Perror_t resumed_t_cleanup (P_t *pads,resumed_t *rep);

Perror_t resumed_t_pd_cleanup (P_t *pads,resumed_t_pd *pd);

Perror_t resumed_t_copy (P_t *pads,resumed_t *rep_dst,resumed_t *rep_src);

Perror_t resumed_t_pd_copy (P_t *pads,resumed_t_pd *pd_dst,resumed_t_pd *pd_src);

void resumed_t_m_init (P_t *pads,resumed_t_m *mask,Pbase_m baseMask);

Perror_t resumed_t_m_rec_init (P_t *pads,resumed_t_m *mask,Pbase_m baseMask);

Perror_t resumed_t_read (P_t *pads,resumed_t_m *m,resumed_t_pd *pd,resumed_t *rep);

int resumed_t_verify (P_t *pads,resumed_t *rep);

int resumed_t_genPD (P_t *pads,resumed_t *rep,resumed_t_pd *pd);
typedef struct resumed_t_acc_s resumed_t_acc;
struct resumed_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc v_resumed;
  return_t_acc v_result;
  v_space3_t_acc v_space3;
  v_time_t_acc v_time;
};

Perror_t resumed_t_acc_init (P_t *pads,resumed_t_acc *acc);

Perror_t resumed_t_acc_reset (P_t *pads,resumed_t_acc *acc);

Perror_t resumed_t_acc_cleanup (P_t *pads,resumed_t_acc *acc);

Perror_t resumed_t_acc_add (P_t *pads,resumed_t_acc *acc,resumed_t_pd *pd,resumed_t *rep);

Perror_t resumed_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,resumed_t_acc *acc);

Perror_t resumed_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,resumed_t_acc *acc);

Perror_t resumed_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,resumed_t_acc *acc);

ssize_t resumed_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,resumed_t_pd *pd,resumed_t *rep);

ssize_t resumed_t_write2io (P_t *pads,Sfio_t *io,resumed_t_pd *pd,resumed_t *rep);

ssize_t resumed_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,resumed_t_pd *pd,resumed_t *rep,char const *_tag,int indent);

ssize_t resumed_t_write_xml_2io (P_t *pads,Sfio_t *io,resumed_t_pd *pd,resumed_t *rep,char const *_tag,int indent);

ssize_t resumed_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,resumed_t_m *m,resumed_t_pd *pd,resumed_t *rep);

ssize_t resumed_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,resumed_t_m *m,resumed_t_pd *pd,resumed_t *rep);

ssize_t resumed_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,resumed_t_m *m,resumed_t_pd *pd,resumed_t *rep);
typedef enum v_space3_0_t_tag_e v_space3_0_t_tag;
typedef union v_space3_0_t_u_u v_space3_0_t_u;
typedef struct v_space3_0_t_s v_space3_0_t;
typedef struct v_space3_0_t_m_s v_space3_0_t_m;
typedef union v_space3_0_t_pd_u_u v_space3_0_t_pd_u;
typedef struct v_space3_0_t_pd_s v_space3_0_t_pd;
enum v_space3_0_t_tag_e {
  v_space3_0_t_err=0,
  some_v_space3_0_t=1,
  none_v_space3_0_t=2
  };
union v_space3_0_t_pd_u_u {
  PPwhite_pd some_v_space3_0_t;
  Pbase_pd none_v_space3_0_t;		/* value was not present. none_v_space3_0_t = 0 */
};
struct v_space3_0_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_space3_0_t_tag tag;
  v_space3_0_t_pd_u val;
};
union v_space3_0_t_u_u {
  PPwhite some_v_space3_0_t;		/* value is present */
};
struct v_space3_0_t_s {
  v_space3_0_t_tag tag;
  v_space3_0_t_u val;
};
struct v_space3_0_t_m_s {
  Pbase_m compoundLevel;
  PPwhite_m some_v_space3_0_t;		/* nested constraints */
  Pbase_m none_v_space3_0_t;		/* nested constraints */
};

ssize_t v_space3_0_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

ssize_t v_space3_0_t_write2io (P_t *pads,Sfio_t *io,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

ssize_t v_space3_0_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_space3_0_t_pd *pd,v_space3_0_t *rep,char const *_tag,int indent,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

ssize_t v_space3_0_t_write_xml_2io (P_t *pads,Sfio_t *io,v_space3_0_t_pd *pd,v_space3_0_t *rep,char const *_tag,int indent,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

char const *v_space3_0_t_tag2str (v_space3_0_t_tag which);

Perror_t v_space3_0_t_init (P_t *pads,v_space3_0_t *rep);

Perror_t v_space3_0_t_pd_init (P_t *pads,v_space3_0_t_pd *pd);

Perror_t v_space3_0_t_cleanup (P_t *pads,v_space3_0_t *rep);

Perror_t v_space3_0_t_pd_cleanup (P_t *pads,v_space3_0_t_pd *pd);

Perror_t v_space3_0_t_copy (P_t *pads,v_space3_0_t *rep_dst,v_space3_0_t *rep_src);

Perror_t v_space3_0_t_pd_copy (P_t *pads,v_space3_0_t_pd *pd_dst,v_space3_0_t_pd *pd_src);

void v_space3_0_t_m_init (P_t *pads,v_space3_0_t_m *mask,Pbase_m baseMask);

Perror_t v_space3_0_t_m_rec_init (P_t *pads,v_space3_0_t_m *mask,Pbase_m baseMask);

Perror_t v_space3_0_t_read (P_t *pads,v_space3_0_t_m *m,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

int v_space3_0_t_verify (P_t *pads,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

int v_space3_0_t_genPD (P_t *pads,v_space3_0_t *rep,v_space3_0_t_pd *pd,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);
typedef struct v_space3_0_t_acc_s v_space3_0_t_acc;
struct v_space3_0_t_acc_s {
  Pint32_acc tag;
  PPwhite_acc some_v_space3_0_t;
};

Perror_t v_space3_0_t_acc_init (P_t *pads,v_space3_0_t_acc *acc);

Perror_t v_space3_0_t_acc_reset (P_t *pads,v_space3_0_t_acc *acc);

Perror_t v_space3_0_t_acc_cleanup (P_t *pads,v_space3_0_t_acc *acc);

Perror_t v_space3_0_t_acc_add (P_t *pads,v_space3_0_t_acc *acc,v_space3_0_t_pd *pd,v_space3_0_t *rep);

Perror_t v_space3_0_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_space3_0_t_acc *acc);

Perror_t v_space3_0_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_space3_0_t_acc *acc);

Perror_t v_space3_0_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_space3_0_t_acc *acc);

ssize_t v_space3_0_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_space3_0_t_m *m,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

ssize_t v_space3_0_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_space3_0_t_m *m,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);

ssize_t v_space3_0_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_space3_0_t_m *m,v_space3_0_t_pd *pd,v_space3_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result);
typedef enum v_time_0_t_tag_e v_time_0_t_tag;
typedef union v_time_0_t_u_u v_time_0_t_u;
typedef struct v_time_0_t_s v_time_0_t;
typedef struct v_time_0_t_m_s v_time_0_t_m;
typedef union v_time_0_t_pd_u_u v_time_0_t_pd_u;
typedef struct v_time_0_t_pd_s v_time_0_t_pd;
enum v_time_0_t_tag_e {
  v_time_0_t_err=0,
  some_v_time_0_t=1,
  none_v_time_0_t=2
  };
union v_time_0_t_pd_u_u {
  timing_t_pd some_v_time_0_t;
  Pbase_pd none_v_time_0_t;		/* value was not present. none_v_time_0_t = 0 */
};
struct v_time_0_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  v_time_0_t_tag tag;
  v_time_0_t_pd_u val;
};
union v_time_0_t_u_u {
  timing_t some_v_time_0_t;		/* value is present */
};
struct v_time_0_t_s {
  v_time_0_t_tag tag;
  v_time_0_t_u val;
};
struct v_time_0_t_m_s {
  Pbase_m compoundLevel;
  timing_t_m some_v_time_0_t;		/* nested constraints */
  Pbase_m none_v_time_0_t;		/* nested constraints */
};

ssize_t v_time_0_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

ssize_t v_time_0_t_write2io (P_t *pads,Sfio_t *io,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

ssize_t v_time_0_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,v_time_0_t_pd *pd,v_time_0_t *rep,char const *_tag,int indent,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

ssize_t v_time_0_t_write_xml_2io (P_t *pads,Sfio_t *io,v_time_0_t_pd *pd,v_time_0_t *rep,char const *_tag,int indent,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

char const *v_time_0_t_tag2str (v_time_0_t_tag which);

Perror_t v_time_0_t_init (P_t *pads,v_time_0_t *rep);

Perror_t v_time_0_t_pd_init (P_t *pads,v_time_0_t_pd *pd);

Perror_t v_time_0_t_cleanup (P_t *pads,v_time_0_t *rep);

Perror_t v_time_0_t_pd_cleanup (P_t *pads,v_time_0_t_pd *pd);

Perror_t v_time_0_t_copy (P_t *pads,v_time_0_t *rep_dst,v_time_0_t *rep_src);

Perror_t v_time_0_t_pd_copy (P_t *pads,v_time_0_t_pd *pd_dst,v_time_0_t_pd *pd_src);

void v_time_0_t_m_init (P_t *pads,v_time_0_t_m *mask,Pbase_m baseMask);

Perror_t v_time_0_t_m_rec_init (P_t *pads,v_time_0_t_m *mask,Pbase_m baseMask);

Perror_t v_time_0_t_read (P_t *pads,v_time_0_t_m *m,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

int v_time_0_t_verify (P_t *pads,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

int v_time_0_t_genPD (P_t *pads,v_time_0_t *rep,v_time_0_t_pd *pd,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);
typedef struct v_time_0_t_acc_s v_time_0_t_acc;
struct v_time_0_t_acc_s {
  Pint32_acc tag;
  timing_t_acc some_v_time_0_t;
};

Perror_t v_time_0_t_acc_init (P_t *pads,v_time_0_t_acc *acc);

Perror_t v_time_0_t_acc_reset (P_t *pads,v_time_0_t_acc *acc);

Perror_t v_time_0_t_acc_cleanup (P_t *pads,v_time_0_t_acc *acc);

Perror_t v_time_0_t_acc_add (P_t *pads,v_time_0_t_acc *acc,v_time_0_t_pd *pd,v_time_0_t *rep);

Perror_t v_time_0_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,v_time_0_t_acc *acc);

Perror_t v_time_0_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,v_time_0_t_acc *acc);

Perror_t v_time_0_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,v_time_0_t_acc *acc);

ssize_t v_time_0_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_time_0_t_m *m,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

ssize_t v_time_0_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,v_time_0_t_m *m,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);

ssize_t v_time_0_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,v_time_0_t_m *m,v_time_0_t_pd *pd,v_time_0_t *rep,Pstring *v_func_name,params_t *v_params,PPwhite *v_space1,PPwhite *v_space2,return_t *v_result,v_space3_0_t *v_space3);
typedef struct norm_func_t_s norm_func_t;
typedef struct norm_func_t_m_s norm_func_t_m;
typedef struct norm_func_t_pd_s norm_func_t_pd;
struct norm_func_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_func_name;		/* nested constraints */
  params_t_m v_params;		/* nested constraints */
  PPwhite_m v_space1;		/* nested constraints */
  PPwhite_m v_space2;		/* nested constraints */
  return_t_m v_result;		/* nested constraints */
  v_space3_0_t_m v_space3;		/* nested constraints */
  v_time_0_t_m v_time;		/* nested constraints */
};
struct norm_func_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_func_name;
  params_t_pd v_params;
  PPwhite_pd v_space1;
  PPwhite_pd v_space2;
  return_t_pd v_result;
  v_space3_0_t_pd v_space3;
  v_time_0_t_pd v_time;
};
struct norm_func_t_s {
  Pstring v_func_name;
  params_t v_params;
  PPwhite v_space1;
  PPwhite v_space2;
  return_t v_result;
  v_space3_0_t v_space3;
  v_time_0_t v_time;
};

Perror_t norm_func_t_init (P_t *pads,norm_func_t *rep);

Perror_t norm_func_t_pd_init (P_t *pads,norm_func_t_pd *pd);

Perror_t norm_func_t_cleanup (P_t *pads,norm_func_t *rep);

Perror_t norm_func_t_pd_cleanup (P_t *pads,norm_func_t_pd *pd);

Perror_t norm_func_t_copy (P_t *pads,norm_func_t *rep_dst,norm_func_t *rep_src);

Perror_t norm_func_t_pd_copy (P_t *pads,norm_func_t_pd *pd_dst,norm_func_t_pd *pd_src);

void norm_func_t_m_init (P_t *pads,norm_func_t_m *mask,Pbase_m baseMask);

Perror_t norm_func_t_m_rec_init (P_t *pads,norm_func_t_m *mask,Pbase_m baseMask);

Perror_t norm_func_t_read (P_t *pads,norm_func_t_m *m,norm_func_t_pd *pd,norm_func_t *rep);

int norm_func_t_verify (P_t *pads,norm_func_t *rep);

int norm_func_t_genPD (P_t *pads,norm_func_t *rep,norm_func_t_pd *pd);
typedef struct norm_func_t_acc_s norm_func_t_acc;
struct norm_func_t_acc_s {
  Puint32_acc nerr;
  Pstring_acc v_func_name;
  params_t_acc v_params;
  PPwhite_acc v_space1;
  PPwhite_acc v_space2;
  return_t_acc v_result;
  v_space3_0_t_acc v_space3;
  v_time_0_t_acc v_time;
};

Perror_t norm_func_t_acc_init (P_t *pads,norm_func_t_acc *acc);

Perror_t norm_func_t_acc_reset (P_t *pads,norm_func_t_acc *acc);

Perror_t norm_func_t_acc_cleanup (P_t *pads,norm_func_t_acc *acc);

Perror_t norm_func_t_acc_add (P_t *pads,norm_func_t_acc *acc,norm_func_t_pd *pd,norm_func_t *rep);

Perror_t norm_func_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,norm_func_t_acc *acc);

Perror_t norm_func_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,norm_func_t_acc *acc);

Perror_t norm_func_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,norm_func_t_acc *acc);

ssize_t norm_func_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,norm_func_t_pd *pd,norm_func_t *rep);

ssize_t norm_func_t_write2io (P_t *pads,Sfio_t *io,norm_func_t_pd *pd,norm_func_t *rep);

ssize_t norm_func_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,norm_func_t_pd *pd,norm_func_t *rep,char const *_tag,int indent);

ssize_t norm_func_t_write_xml_2io (P_t *pads,Sfio_t *io,norm_func_t_pd *pd,norm_func_t *rep,char const *_tag,int indent);

ssize_t norm_func_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,norm_func_t_m *m,norm_func_t_pd *pd,norm_func_t *rep);

ssize_t norm_func_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,norm_func_t_m *m,norm_func_t_pd *pd,norm_func_t *rep);

ssize_t norm_func_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,norm_func_t_m *m,norm_func_t_pd *pd,norm_func_t *rep);
typedef enum message_t_tag_e message_t_tag;
typedef union message_t_u_u message_t_u;
typedef struct message_t_s message_t;
typedef struct message_t_m_s message_t_m;
typedef union message_t_pd_u_u message_t_pd_u;
typedef struct message_t_pd_s message_t_pd;
enum message_t_tag_e {
  message_t_err=0,
  v_normal_fun=1
  };
union message_t_pd_u_u {
  norm_func_t_pd v_normal_fun;
};
struct message_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  message_t_tag tag;
  message_t_pd_u val;
};
union message_t_u_u {
  norm_func_t v_normal_fun;
};
struct message_t_s {
  message_t_tag tag;
  message_t_u val;
};
struct message_t_m_s {
  Pbase_m compoundLevel;
  norm_func_t_m v_normal_fun;		/* nested constraints */
};

ssize_t message_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,message_t_pd *pd,message_t *rep);

ssize_t message_t_write2io (P_t *pads,Sfio_t *io,message_t_pd *pd,message_t *rep);

ssize_t message_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,message_t_pd *pd,message_t *rep,char const *_tag,int indent);

ssize_t message_t_write_xml_2io (P_t *pads,Sfio_t *io,message_t_pd *pd,message_t *rep,char const *_tag,int indent);

char const *message_t_tag2str (message_t_tag which);

Perror_t message_t_init (P_t *pads,message_t *rep);

Perror_t message_t_pd_init (P_t *pads,message_t_pd *pd);

Perror_t message_t_cleanup (P_t *pads,message_t *rep);

Perror_t message_t_pd_cleanup (P_t *pads,message_t_pd *pd);

Perror_t message_t_copy (P_t *pads,message_t *rep_dst,message_t *rep_src);

Perror_t message_t_pd_copy (P_t *pads,message_t_pd *pd_dst,message_t_pd *pd_src);

void message_t_m_init (P_t *pads,message_t_m *mask,Pbase_m baseMask);

Perror_t message_t_m_rec_init (P_t *pads,message_t_m *mask,Pbase_m baseMask);

Perror_t message_t_read (P_t *pads,message_t_m *m,message_t_pd *pd,message_t *rep);

int message_t_verify (P_t *pads,message_t *rep);

int message_t_genPD (P_t *pads,message_t *rep,message_t_pd *pd);
typedef struct message_t_acc_s message_t_acc;
struct message_t_acc_s {
  Pint32_acc tag;
  norm_func_t_acc v_normal_fun;
};

Perror_t message_t_acc_init (P_t *pads,message_t_acc *acc);

Perror_t message_t_acc_reset (P_t *pads,message_t_acc *acc);

Perror_t message_t_acc_cleanup (P_t *pads,message_t_acc *acc);

Perror_t message_t_acc_add (P_t *pads,message_t_acc *acc,message_t_pd *pd,message_t *rep);

Perror_t message_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,message_t_acc *acc);

Perror_t message_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,message_t_acc *acc);

Perror_t message_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,message_t_acc *acc);

ssize_t message_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,message_t_m *m,message_t_pd *pd,message_t *rep);

ssize_t message_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,message_t_m *m,message_t_pd *pd,message_t *rep);

ssize_t message_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,message_t_m *m,message_t_pd *pd,message_t *rep);
typedef struct entry_t_s entry_t;
typedef struct entry_t_m_s entry_t_m;
typedef struct entry_t_pd_s entry_t_pd;
struct entry_t_m_s {
  Pbase_m compoundLevel;
  Pbase_m v_proc_id;		/* nested constraints */
  PPwhite_m v_space;		/* nested constraints */
  Pbase_m v_int1;		/* nested constraints */
  Pbase_m v_int2;		/* nested constraints */
  message_t_m v_msg;		/* nested constraints */
};
struct entry_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  Pbase_pd v_proc_id;
  PPwhite_pd v_space;
  Pbase_pd v_int1;
  Pbase_pd v_int2;
  message_t_pd v_msg;
};
struct entry_t_s {
  Puint16 v_proc_id;
  PPwhite v_space;
  Puint32 v_int1;
  Puint32 v_int2;
  message_t v_msg;
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
  Puint16_acc v_proc_id;
  PPwhite_acc v_space;
  Puint32_acc v_int1;
  Puint32_acc v_int2;
  message_t_acc v_msg;
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
  entry_t_m element;		/* per-element */
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
  entry_t_pd *elts;
  RBuf_t *_internal;
};
struct entries_t_s {
  Puint32 length;
  entry_t *elts;
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

Pread_res_t entries_t_read_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,entry_t_pd *elt_pd,entry_t *elt_rep);

Perror_t entries_t_read (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep);

Pread_res_t entries_t_reread_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,entry_t_pd *elt_pd,entry_t *elt_rep,int notFirstElt);

int entries_t_verify (P_t *pads,entries_t *rep);

int entries_t_genPD (P_t *pads,entries_t *rep,entries_t_pd *pd);
typedef struct entries_t_acc_s entries_t_acc;
struct entries_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  entry_t_acc compoundLevel;		/* Accumulator for all array elements */
  entry_t_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
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

#endif /*  __REMOVE_ERR__H__  */
