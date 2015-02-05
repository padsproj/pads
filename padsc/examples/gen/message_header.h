#ifndef __MESSAGE_HEADER__H__
#define __MESSAGE_HEADER__H__
#include "pads.h"

int is_CR (Pchar x);
typedef Pchar CR_t;
typedef struct CR_t_m_s CR_t_m;
typedef Pbase_pd CR_t_pd;
struct CR_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t CR_t_init (P_t *pads,CR_t *rep);

Perror_t CR_t_pd_init (P_t *pads,CR_t_pd *pd);

Perror_t CR_t_cleanup (P_t *pads,CR_t *rep);

Perror_t CR_t_pd_cleanup (P_t *pads,CR_t_pd *pd);

Perror_t CR_t_copy (P_t *pads,CR_t *rep_dst,CR_t *rep_src);

Perror_t CR_t_pd_copy (P_t *pads,CR_t_pd *pd_dst,CR_t_pd *pd_src);

void CR_t_m_init (P_t *pads,CR_t_m *mask,Pbase_m baseMask);

Perror_t CR_t_m_rec_init (P_t *pads,CR_t_m *mask,Pbase_m baseMask);

Perror_t CR_t_read (P_t *pads,CR_t_m *m,CR_t_pd *pd,CR_t *rep);

int CR_t_verify (P_t *pads,CR_t *rep);

int CR_t_genPD (P_t *pads,CR_t *rep,CR_t_pd *pd);
typedef Pchar_acc CR_t_acc;

Perror_t CR_t_acc_init (P_t *pads,CR_t_acc *acc);

Perror_t CR_t_acc_reset (P_t *pads,CR_t_acc *acc);

Perror_t CR_t_acc_cleanup (P_t *pads,CR_t_acc *acc);

Perror_t CR_t_acc_add (P_t *pads,CR_t_acc *acc,CR_t_pd *pd,CR_t *rep);

Perror_t CR_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,CR_t_acc *acc);

Perror_t CR_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,CR_t_acc *acc);

Perror_t CR_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,CR_t_acc *acc);

ssize_t CR_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CR_t_pd *pd,CR_t *rep);

ssize_t CR_t_write2io (P_t *pads,Sfio_t *io,CR_t_pd *pd,CR_t *rep);

ssize_t CR_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CR_t_pd *pd,CR_t *rep,char const *_tag,int indent);

ssize_t CR_t_write_xml_2io (P_t *pads,Sfio_t *io,CR_t_pd *pd,CR_t *rep,char const *_tag,int indent);

ssize_t CR_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CR_t_m *m,CR_t_pd *pd,CR_t *rep);

ssize_t CR_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CR_t_m *m,CR_t_pd *pd,CR_t *rep);

ssize_t CR_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,CR_t_m *m,CR_t_pd *pd,CR_t *rep);

int CR_verify_0 (int i);

int is_DQUOTE (Pchar x);
typedef Pchar DQUOTE_t;
typedef struct DQUOTE_t_m_s DQUOTE_t_m;
typedef Pbase_pd DQUOTE_t_pd;
struct DQUOTE_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t DQUOTE_t_init (P_t *pads,DQUOTE_t *rep);

Perror_t DQUOTE_t_pd_init (P_t *pads,DQUOTE_t_pd *pd);

Perror_t DQUOTE_t_cleanup (P_t *pads,DQUOTE_t *rep);

Perror_t DQUOTE_t_pd_cleanup (P_t *pads,DQUOTE_t_pd *pd);

Perror_t DQUOTE_t_copy (P_t *pads,DQUOTE_t *rep_dst,DQUOTE_t *rep_src);

Perror_t DQUOTE_t_pd_copy (P_t *pads,DQUOTE_t_pd *pd_dst,DQUOTE_t_pd *pd_src);

void DQUOTE_t_m_init (P_t *pads,DQUOTE_t_m *mask,Pbase_m baseMask);

Perror_t DQUOTE_t_m_rec_init (P_t *pads,DQUOTE_t_m *mask,Pbase_m baseMask);

Perror_t DQUOTE_t_read (P_t *pads,DQUOTE_t_m *m,DQUOTE_t_pd *pd,DQUOTE_t *rep);

int DQUOTE_t_verify (P_t *pads,DQUOTE_t *rep);

int DQUOTE_t_genPD (P_t *pads,DQUOTE_t *rep,DQUOTE_t_pd *pd);
typedef Pchar_acc DQUOTE_t_acc;

Perror_t DQUOTE_t_acc_init (P_t *pads,DQUOTE_t_acc *acc);

Perror_t DQUOTE_t_acc_reset (P_t *pads,DQUOTE_t_acc *acc);

Perror_t DQUOTE_t_acc_cleanup (P_t *pads,DQUOTE_t_acc *acc);

Perror_t DQUOTE_t_acc_add (P_t *pads,DQUOTE_t_acc *acc,DQUOTE_t_pd *pd,DQUOTE_t *rep);

Perror_t DQUOTE_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,DQUOTE_t_acc *acc);

Perror_t DQUOTE_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,DQUOTE_t_acc *acc);

Perror_t DQUOTE_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,DQUOTE_t_acc *acc);

ssize_t DQUOTE_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,DQUOTE_t_pd *pd,DQUOTE_t *rep);

ssize_t DQUOTE_t_write2io (P_t *pads,Sfio_t *io,DQUOTE_t_pd *pd,DQUOTE_t *rep);

ssize_t DQUOTE_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,DQUOTE_t_pd *pd,DQUOTE_t *rep,char const *_tag,int indent);

ssize_t DQUOTE_t_write_xml_2io (P_t *pads,Sfio_t *io,DQUOTE_t_pd *pd,DQUOTE_t *rep,char const *_tag,int indent);

ssize_t DQUOTE_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,DQUOTE_t_m *m,DQUOTE_t_pd *pd,DQUOTE_t *rep);

ssize_t DQUOTE_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,DQUOTE_t_m *m,DQUOTE_t_pd *pd,DQUOTE_t *rep);

ssize_t DQUOTE_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,DQUOTE_t_m *m,DQUOTE_t_pd *pd,DQUOTE_t *rep);

int DQUOTE_verify_1 (int i);

int is_HT (Pchar x);
typedef Pchar HT_t;
typedef struct HT_t_m_s HT_t_m;
typedef Pbase_pd HT_t_pd;
struct HT_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t HT_t_init (P_t *pads,HT_t *rep);

Perror_t HT_t_pd_init (P_t *pads,HT_t_pd *pd);

Perror_t HT_t_cleanup (P_t *pads,HT_t *rep);

Perror_t HT_t_pd_cleanup (P_t *pads,HT_t_pd *pd);

Perror_t HT_t_copy (P_t *pads,HT_t *rep_dst,HT_t *rep_src);

Perror_t HT_t_pd_copy (P_t *pads,HT_t_pd *pd_dst,HT_t_pd *pd_src);

void HT_t_m_init (P_t *pads,HT_t_m *mask,Pbase_m baseMask);

Perror_t HT_t_m_rec_init (P_t *pads,HT_t_m *mask,Pbase_m baseMask);

Perror_t HT_t_read (P_t *pads,HT_t_m *m,HT_t_pd *pd,HT_t *rep);

int HT_t_verify (P_t *pads,HT_t *rep);

int HT_t_genPD (P_t *pads,HT_t *rep,HT_t_pd *pd);
typedef Pchar_acc HT_t_acc;

Perror_t HT_t_acc_init (P_t *pads,HT_t_acc *acc);

Perror_t HT_t_acc_reset (P_t *pads,HT_t_acc *acc);

Perror_t HT_t_acc_cleanup (P_t *pads,HT_t_acc *acc);

Perror_t HT_t_acc_add (P_t *pads,HT_t_acc *acc,HT_t_pd *pd,HT_t *rep);

Perror_t HT_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,HT_t_acc *acc);

Perror_t HT_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,HT_t_acc *acc);

Perror_t HT_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,HT_t_acc *acc);

ssize_t HT_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,HT_t_pd *pd,HT_t *rep);

ssize_t HT_t_write2io (P_t *pads,Sfio_t *io,HT_t_pd *pd,HT_t *rep);

ssize_t HT_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,HT_t_pd *pd,HT_t *rep,char const *_tag,int indent);

ssize_t HT_t_write_xml_2io (P_t *pads,Sfio_t *io,HT_t_pd *pd,HT_t *rep,char const *_tag,int indent);

ssize_t HT_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,HT_t_m *m,HT_t_pd *pd,HT_t *rep);

ssize_t HT_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,HT_t_m *m,HT_t_pd *pd,HT_t *rep);

ssize_t HT_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,HT_t_m *m,HT_t_pd *pd,HT_t *rep);

int HT_verify_2 (int i);

int is_LF (Pchar x);
typedef Pchar LF_t;
typedef struct LF_t_m_s LF_t_m;
typedef Pbase_pd LF_t_pd;
struct LF_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t LF_t_init (P_t *pads,LF_t *rep);

Perror_t LF_t_pd_init (P_t *pads,LF_t_pd *pd);

Perror_t LF_t_cleanup (P_t *pads,LF_t *rep);

Perror_t LF_t_pd_cleanup (P_t *pads,LF_t_pd *pd);

Perror_t LF_t_copy (P_t *pads,LF_t *rep_dst,LF_t *rep_src);

Perror_t LF_t_pd_copy (P_t *pads,LF_t_pd *pd_dst,LF_t_pd *pd_src);

void LF_t_m_init (P_t *pads,LF_t_m *mask,Pbase_m baseMask);

Perror_t LF_t_m_rec_init (P_t *pads,LF_t_m *mask,Pbase_m baseMask);

Perror_t LF_t_read (P_t *pads,LF_t_m *m,LF_t_pd *pd,LF_t *rep);

int LF_t_verify (P_t *pads,LF_t *rep);

int LF_t_genPD (P_t *pads,LF_t *rep,LF_t_pd *pd);
typedef Pchar_acc LF_t_acc;

Perror_t LF_t_acc_init (P_t *pads,LF_t_acc *acc);

Perror_t LF_t_acc_reset (P_t *pads,LF_t_acc *acc);

Perror_t LF_t_acc_cleanup (P_t *pads,LF_t_acc *acc);

Perror_t LF_t_acc_add (P_t *pads,LF_t_acc *acc,LF_t_pd *pd,LF_t *rep);

Perror_t LF_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,LF_t_acc *acc);

Perror_t LF_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,LF_t_acc *acc);

Perror_t LF_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,LF_t_acc *acc);

ssize_t LF_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,LF_t_pd *pd,LF_t *rep);

ssize_t LF_t_write2io (P_t *pads,Sfio_t *io,LF_t_pd *pd,LF_t *rep);

ssize_t LF_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,LF_t_pd *pd,LF_t *rep,char const *_tag,int indent);

ssize_t LF_t_write_xml_2io (P_t *pads,Sfio_t *io,LF_t_pd *pd,LF_t *rep,char const *_tag,int indent);

ssize_t LF_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,LF_t_m *m,LF_t_pd *pd,LF_t *rep);

ssize_t LF_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,LF_t_m *m,LF_t_pd *pd,LF_t *rep);

ssize_t LF_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,LF_t_m *m,LF_t_pd *pd,LF_t *rep);

int LF_verify_3 (int i);
typedef Pstring CRLF_t;
typedef struct CRLF_t_m_s CRLF_t_m;
typedef Pbase_pd CRLF_t_pd;
struct CRLF_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t CRLF_t_init (P_t *pads,CRLF_t *rep);

Perror_t CRLF_t_pd_init (P_t *pads,CRLF_t_pd *pd);

Perror_t CRLF_t_cleanup (P_t *pads,CRLF_t *rep);

Perror_t CRLF_t_pd_cleanup (P_t *pads,CRLF_t_pd *pd);

Perror_t CRLF_t_copy (P_t *pads,CRLF_t *rep_dst,CRLF_t *rep_src);

Perror_t CRLF_t_pd_copy (P_t *pads,CRLF_t_pd *pd_dst,CRLF_t_pd *pd_src);

void CRLF_t_m_init (P_t *pads,CRLF_t_m *mask,Pbase_m baseMask);

Perror_t CRLF_t_m_rec_init (P_t *pads,CRLF_t_m *mask,Pbase_m baseMask);

Perror_t CRLF_t_read (P_t *pads,CRLF_t_m *m,CRLF_t_pd *pd,CRLF_t *rep);

int CRLF_t_verify (P_t *pads,CRLF_t *rep);

int CRLF_t_genPD (P_t *pads,CRLF_t *rep,CRLF_t_pd *pd);
typedef Pstring_acc CRLF_t_acc;

Perror_t CRLF_t_acc_init (P_t *pads,CRLF_t_acc *acc);

Perror_t CRLF_t_acc_reset (P_t *pads,CRLF_t_acc *acc);

Perror_t CRLF_t_acc_cleanup (P_t *pads,CRLF_t_acc *acc);

Perror_t CRLF_t_acc_add (P_t *pads,CRLF_t_acc *acc,CRLF_t_pd *pd,CRLF_t *rep);

Perror_t CRLF_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,CRLF_t_acc *acc);

Perror_t CRLF_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,CRLF_t_acc *acc);

Perror_t CRLF_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,CRLF_t_acc *acc);

ssize_t CRLF_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CRLF_t_pd *pd,CRLF_t *rep);

ssize_t CRLF_t_write2io (P_t *pads,Sfio_t *io,CRLF_t_pd *pd,CRLF_t *rep);

ssize_t CRLF_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CRLF_t_pd *pd,CRLF_t *rep,char const *_tag,int indent);

ssize_t CRLF_t_write_xml_2io (P_t *pads,Sfio_t *io,CRLF_t_pd *pd,CRLF_t *rep,char const *_tag,int indent);

ssize_t CRLF_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CRLF_t_m *m,CRLF_t_pd *pd,CRLF_t *rep);

ssize_t CRLF_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CRLF_t_m *m,CRLF_t_pd *pd,CRLF_t *rep);

ssize_t CRLF_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,CRLF_t_m *m,CRLF_t_pd *pd,CRLF_t *rep);

int is_NO_WS_CTL (Pchar x);
typedef Pchar NO_WS_CTL_t;
typedef struct NO_WS_CTL_t_m_s NO_WS_CTL_t_m;
typedef Pbase_pd NO_WS_CTL_t_pd;
struct NO_WS_CTL_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t NO_WS_CTL_t_init (P_t *pads,NO_WS_CTL_t *rep);

Perror_t NO_WS_CTL_t_pd_init (P_t *pads,NO_WS_CTL_t_pd *pd);

Perror_t NO_WS_CTL_t_cleanup (P_t *pads,NO_WS_CTL_t *rep);

Perror_t NO_WS_CTL_t_pd_cleanup (P_t *pads,NO_WS_CTL_t_pd *pd);

Perror_t NO_WS_CTL_t_copy (P_t *pads,NO_WS_CTL_t *rep_dst,NO_WS_CTL_t *rep_src);

Perror_t NO_WS_CTL_t_pd_copy (P_t *pads,NO_WS_CTL_t_pd *pd_dst,NO_WS_CTL_t_pd *pd_src);

void NO_WS_CTL_t_m_init (P_t *pads,NO_WS_CTL_t_m *mask,Pbase_m baseMask);

Perror_t NO_WS_CTL_t_m_rec_init (P_t *pads,NO_WS_CTL_t_m *mask,Pbase_m baseMask);

Perror_t NO_WS_CTL_t_read (P_t *pads,NO_WS_CTL_t_m *m,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

int NO_WS_CTL_t_verify (P_t *pads,NO_WS_CTL_t *rep);

int NO_WS_CTL_t_genPD (P_t *pads,NO_WS_CTL_t *rep,NO_WS_CTL_t_pd *pd);
typedef Pchar_acc NO_WS_CTL_t_acc;

Perror_t NO_WS_CTL_t_acc_init (P_t *pads,NO_WS_CTL_t_acc *acc);

Perror_t NO_WS_CTL_t_acc_reset (P_t *pads,NO_WS_CTL_t_acc *acc);

Perror_t NO_WS_CTL_t_acc_cleanup (P_t *pads,NO_WS_CTL_t_acc *acc);

Perror_t NO_WS_CTL_t_acc_add (P_t *pads,NO_WS_CTL_t_acc *acc,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

Perror_t NO_WS_CTL_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,NO_WS_CTL_t_acc *acc);

Perror_t NO_WS_CTL_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,NO_WS_CTL_t_acc *acc);

Perror_t NO_WS_CTL_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,NO_WS_CTL_t_acc *acc);

ssize_t NO_WS_CTL_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

ssize_t NO_WS_CTL_t_write2io (P_t *pads,Sfio_t *io,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

ssize_t NO_WS_CTL_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep,char const *_tag,int indent);

ssize_t NO_WS_CTL_t_write_xml_2io (P_t *pads,Sfio_t *io,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep,char const *_tag,int indent);

ssize_t NO_WS_CTL_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,NO_WS_CTL_t_m *m,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

ssize_t NO_WS_CTL_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,NO_WS_CTL_t_m *m,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

ssize_t NO_WS_CTL_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,NO_WS_CTL_t_m *m,NO_WS_CTL_t_pd *pd,NO_WS_CTL_t *rep);

int NO_WS_CTL_verify_4 (int i);

int is_SP (Pchar x);
typedef Pchar SP_t;
typedef struct SP_t_m_s SP_t_m;
typedef Pbase_pd SP_t_pd;
struct SP_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t SP_t_init (P_t *pads,SP_t *rep);

Perror_t SP_t_pd_init (P_t *pads,SP_t_pd *pd);

Perror_t SP_t_cleanup (P_t *pads,SP_t *rep);

Perror_t SP_t_pd_cleanup (P_t *pads,SP_t_pd *pd);

Perror_t SP_t_copy (P_t *pads,SP_t *rep_dst,SP_t *rep_src);

Perror_t SP_t_pd_copy (P_t *pads,SP_t_pd *pd_dst,SP_t_pd *pd_src);

void SP_t_m_init (P_t *pads,SP_t_m *mask,Pbase_m baseMask);

Perror_t SP_t_m_rec_init (P_t *pads,SP_t_m *mask,Pbase_m baseMask);

Perror_t SP_t_read (P_t *pads,SP_t_m *m,SP_t_pd *pd,SP_t *rep);

int SP_t_verify (P_t *pads,SP_t *rep);

int SP_t_genPD (P_t *pads,SP_t *rep,SP_t_pd *pd);
typedef Pchar_acc SP_t_acc;

Perror_t SP_t_acc_init (P_t *pads,SP_t_acc *acc);

Perror_t SP_t_acc_reset (P_t *pads,SP_t_acc *acc);

Perror_t SP_t_acc_cleanup (P_t *pads,SP_t_acc *acc);

Perror_t SP_t_acc_add (P_t *pads,SP_t_acc *acc,SP_t_pd *pd,SP_t *rep);

Perror_t SP_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,SP_t_acc *acc);

Perror_t SP_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,SP_t_acc *acc);

Perror_t SP_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,SP_t_acc *acc);

ssize_t SP_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,SP_t_pd *pd,SP_t *rep);

ssize_t SP_t_write2io (P_t *pads,Sfio_t *io,SP_t_pd *pd,SP_t *rep);

ssize_t SP_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,SP_t_pd *pd,SP_t *rep,char const *_tag,int indent);

ssize_t SP_t_write_xml_2io (P_t *pads,Sfio_t *io,SP_t_pd *pd,SP_t *rep,char const *_tag,int indent);

ssize_t SP_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,SP_t_m *m,SP_t_pd *pd,SP_t *rep);

ssize_t SP_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,SP_t_m *m,SP_t_pd *pd,SP_t *rep);

ssize_t SP_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,SP_t_m *m,SP_t_pd *pd,SP_t *rep);

int SP_verify_5 (int i);
typedef Pstring LWS_t;
typedef struct LWS_t_m_s LWS_t_m;
typedef Pbase_pd LWS_t_pd;
struct LWS_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t LWS_t_init (P_t *pads,LWS_t *rep);

Perror_t LWS_t_pd_init (P_t *pads,LWS_t_pd *pd);

Perror_t LWS_t_cleanup (P_t *pads,LWS_t *rep);

Perror_t LWS_t_pd_cleanup (P_t *pads,LWS_t_pd *pd);

Perror_t LWS_t_copy (P_t *pads,LWS_t *rep_dst,LWS_t *rep_src);

Perror_t LWS_t_pd_copy (P_t *pads,LWS_t_pd *pd_dst,LWS_t_pd *pd_src);

void LWS_t_m_init (P_t *pads,LWS_t_m *mask,Pbase_m baseMask);

Perror_t LWS_t_m_rec_init (P_t *pads,LWS_t_m *mask,Pbase_m baseMask);

Perror_t LWS_t_read (P_t *pads,LWS_t_m *m,LWS_t_pd *pd,LWS_t *rep);

int LWS_t_verify (P_t *pads,LWS_t *rep);

int LWS_t_genPD (P_t *pads,LWS_t *rep,LWS_t_pd *pd);
typedef Pstring_acc LWS_t_acc;

Perror_t LWS_t_acc_init (P_t *pads,LWS_t_acc *acc);

Perror_t LWS_t_acc_reset (P_t *pads,LWS_t_acc *acc);

Perror_t LWS_t_acc_cleanup (P_t *pads,LWS_t_acc *acc);

Perror_t LWS_t_acc_add (P_t *pads,LWS_t_acc *acc,LWS_t_pd *pd,LWS_t *rep);

Perror_t LWS_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,LWS_t_acc *acc);

Perror_t LWS_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,LWS_t_acc *acc);

Perror_t LWS_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,LWS_t_acc *acc);

ssize_t LWS_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,LWS_t_pd *pd,LWS_t *rep);

ssize_t LWS_t_write2io (P_t *pads,Sfio_t *io,LWS_t_pd *pd,LWS_t *rep);

ssize_t LWS_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,LWS_t_pd *pd,LWS_t *rep,char const *_tag,int indent);

ssize_t LWS_t_write_xml_2io (P_t *pads,Sfio_t *io,LWS_t_pd *pd,LWS_t *rep,char const *_tag,int indent);

ssize_t LWS_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,LWS_t_m *m,LWS_t_pd *pd,LWS_t *rep);

ssize_t LWS_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,LWS_t_m *m,LWS_t_pd *pd,LWS_t *rep);

ssize_t LWS_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,LWS_t_m *m,LWS_t_pd *pd,LWS_t *rep);

int is_TEXT (Pchar x);
typedef Pchar TEXT_t;
typedef struct TEXT_t_m_s TEXT_t_m;
typedef Pbase_pd TEXT_t_pd;
struct TEXT_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t TEXT_t_init (P_t *pads,TEXT_t *rep);

Perror_t TEXT_t_pd_init (P_t *pads,TEXT_t_pd *pd);

Perror_t TEXT_t_cleanup (P_t *pads,TEXT_t *rep);

Perror_t TEXT_t_pd_cleanup (P_t *pads,TEXT_t_pd *pd);

Perror_t TEXT_t_copy (P_t *pads,TEXT_t *rep_dst,TEXT_t *rep_src);

Perror_t TEXT_t_pd_copy (P_t *pads,TEXT_t_pd *pd_dst,TEXT_t_pd *pd_src);

void TEXT_t_m_init (P_t *pads,TEXT_t_m *mask,Pbase_m baseMask);

Perror_t TEXT_t_m_rec_init (P_t *pads,TEXT_t_m *mask,Pbase_m baseMask);

Perror_t TEXT_t_read (P_t *pads,TEXT_t_m *m,TEXT_t_pd *pd,TEXT_t *rep);

int TEXT_t_verify (P_t *pads,TEXT_t *rep);

int TEXT_t_genPD (P_t *pads,TEXT_t *rep,TEXT_t_pd *pd);
typedef Pchar_acc TEXT_t_acc;

Perror_t TEXT_t_acc_init (P_t *pads,TEXT_t_acc *acc);

Perror_t TEXT_t_acc_reset (P_t *pads,TEXT_t_acc *acc);

Perror_t TEXT_t_acc_cleanup (P_t *pads,TEXT_t_acc *acc);

Perror_t TEXT_t_acc_add (P_t *pads,TEXT_t_acc *acc,TEXT_t_pd *pd,TEXT_t *rep);

Perror_t TEXT_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,TEXT_t_acc *acc);

Perror_t TEXT_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,TEXT_t_acc *acc);

Perror_t TEXT_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,TEXT_t_acc *acc);

ssize_t TEXT_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,TEXT_t_pd *pd,TEXT_t *rep);

ssize_t TEXT_t_write2io (P_t *pads,Sfio_t *io,TEXT_t_pd *pd,TEXT_t *rep);

ssize_t TEXT_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,TEXT_t_pd *pd,TEXT_t *rep,char const *_tag,int indent);

ssize_t TEXT_t_write_xml_2io (P_t *pads,Sfio_t *io,TEXT_t_pd *pd,TEXT_t *rep,char const *_tag,int indent);

ssize_t TEXT_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,TEXT_t_m *m,TEXT_t_pd *pd,TEXT_t *rep);

ssize_t TEXT_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,TEXT_t_m *m,TEXT_t_pd *pd,TEXT_t *rep);

ssize_t TEXT_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,TEXT_t_m *m,TEXT_t_pd *pd,TEXT_t *rep);

int TEXT_verify_6 (int i);

int is_WSP (Pchar x);
typedef Pchar WSP_t;
typedef struct WSP_t_m_s WSP_t_m;
typedef Pbase_pd WSP_t_pd;
struct WSP_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t WSP_t_init (P_t *pads,WSP_t *rep);

Perror_t WSP_t_pd_init (P_t *pads,WSP_t_pd *pd);

Perror_t WSP_t_cleanup (P_t *pads,WSP_t *rep);

Perror_t WSP_t_pd_cleanup (P_t *pads,WSP_t_pd *pd);

Perror_t WSP_t_copy (P_t *pads,WSP_t *rep_dst,WSP_t *rep_src);

Perror_t WSP_t_pd_copy (P_t *pads,WSP_t_pd *pd_dst,WSP_t_pd *pd_src);

void WSP_t_m_init (P_t *pads,WSP_t_m *mask,Pbase_m baseMask);

Perror_t WSP_t_m_rec_init (P_t *pads,WSP_t_m *mask,Pbase_m baseMask);

Perror_t WSP_t_read (P_t *pads,WSP_t_m *m,WSP_t_pd *pd,WSP_t *rep);

int WSP_t_verify (P_t *pads,WSP_t *rep);

int WSP_t_genPD (P_t *pads,WSP_t *rep,WSP_t_pd *pd);
typedef Pchar_acc WSP_t_acc;

Perror_t WSP_t_acc_init (P_t *pads,WSP_t_acc *acc);

Perror_t WSP_t_acc_reset (P_t *pads,WSP_t_acc *acc);

Perror_t WSP_t_acc_cleanup (P_t *pads,WSP_t_acc *acc);

Perror_t WSP_t_acc_add (P_t *pads,WSP_t_acc *acc,WSP_t_pd *pd,WSP_t *rep);

Perror_t WSP_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,WSP_t_acc *acc);

Perror_t WSP_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,WSP_t_acc *acc);

Perror_t WSP_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,WSP_t_acc *acc);

ssize_t WSP_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,WSP_t_pd *pd,WSP_t *rep);

ssize_t WSP_t_write2io (P_t *pads,Sfio_t *io,WSP_t_pd *pd,WSP_t *rep);

ssize_t WSP_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,WSP_t_pd *pd,WSP_t *rep,char const *_tag,int indent);

ssize_t WSP_t_write_xml_2io (P_t *pads,Sfio_t *io,WSP_t_pd *pd,WSP_t *rep,char const *_tag,int indent);

ssize_t WSP_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,WSP_t_m *m,WSP_t_pd *pd,WSP_t *rep);

ssize_t WSP_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,WSP_t_m *m,WSP_t_pd *pd,WSP_t *rep);

ssize_t WSP_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,WSP_t_m *m,WSP_t_pd *pd,WSP_t *rep);

int WSP_verify_7 (int i);
typedef Pstring comment_mailbox_t;
typedef struct comment_mailbox_t_m_s comment_mailbox_t_m;
typedef Pbase_pd comment_mailbox_t_pd;
struct comment_mailbox_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t comment_mailbox_t_init (P_t *pads,comment_mailbox_t *rep);

Perror_t comment_mailbox_t_pd_init (P_t *pads,comment_mailbox_t_pd *pd);

Perror_t comment_mailbox_t_cleanup (P_t *pads,comment_mailbox_t *rep);

Perror_t comment_mailbox_t_pd_cleanup (P_t *pads,comment_mailbox_t_pd *pd);

Perror_t comment_mailbox_t_copy (P_t *pads,comment_mailbox_t *rep_dst,comment_mailbox_t *rep_src);

Perror_t comment_mailbox_t_pd_copy (P_t *pads,comment_mailbox_t_pd *pd_dst,comment_mailbox_t_pd *pd_src);

void comment_mailbox_t_m_init (P_t *pads,comment_mailbox_t_m *mask,Pbase_m baseMask);

Perror_t comment_mailbox_t_m_rec_init (P_t *pads,comment_mailbox_t_m *mask,Pbase_m baseMask);

Perror_t comment_mailbox_t_read (P_t *pads,comment_mailbox_t_m *m,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

int comment_mailbox_t_verify (P_t *pads,comment_mailbox_t *rep);

int comment_mailbox_t_genPD (P_t *pads,comment_mailbox_t *rep,comment_mailbox_t_pd *pd);
typedef Pstring_acc comment_mailbox_t_acc;

Perror_t comment_mailbox_t_acc_init (P_t *pads,comment_mailbox_t_acc *acc);

Perror_t comment_mailbox_t_acc_reset (P_t *pads,comment_mailbox_t_acc *acc);

Perror_t comment_mailbox_t_acc_cleanup (P_t *pads,comment_mailbox_t_acc *acc);

Perror_t comment_mailbox_t_acc_add (P_t *pads,comment_mailbox_t_acc *acc,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

Perror_t comment_mailbox_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,comment_mailbox_t_acc *acc);

Perror_t comment_mailbox_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,comment_mailbox_t_acc *acc);

Perror_t comment_mailbox_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,comment_mailbox_t_acc *acc);

ssize_t comment_mailbox_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

ssize_t comment_mailbox_t_write2io (P_t *pads,Sfio_t *io,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

ssize_t comment_mailbox_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,comment_mailbox_t_pd *pd,comment_mailbox_t *rep,char const *_tag,int indent);

ssize_t comment_mailbox_t_write_xml_2io (P_t *pads,Sfio_t *io,comment_mailbox_t_pd *pd,comment_mailbox_t *rep,char const *_tag,int indent);

ssize_t comment_mailbox_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,comment_mailbox_t_m *m,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

ssize_t comment_mailbox_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,comment_mailbox_t_m *m,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);

ssize_t comment_mailbox_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,comment_mailbox_t_m *m,comment_mailbox_t_pd *pd,comment_mailbox_t *rep);
typedef Pstring obs_FWS_t;
typedef struct obs_FWS_t_m_s obs_FWS_t_m;
typedef Pbase_pd obs_FWS_t_pd;
struct obs_FWS_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t obs_FWS_t_init (P_t *pads,obs_FWS_t *rep);

Perror_t obs_FWS_t_pd_init (P_t *pads,obs_FWS_t_pd *pd);

Perror_t obs_FWS_t_cleanup (P_t *pads,obs_FWS_t *rep);

Perror_t obs_FWS_t_pd_cleanup (P_t *pads,obs_FWS_t_pd *pd);

Perror_t obs_FWS_t_copy (P_t *pads,obs_FWS_t *rep_dst,obs_FWS_t *rep_src);

Perror_t obs_FWS_t_pd_copy (P_t *pads,obs_FWS_t_pd *pd_dst,obs_FWS_t_pd *pd_src);

void obs_FWS_t_m_init (P_t *pads,obs_FWS_t_m *mask,Pbase_m baseMask);

Perror_t obs_FWS_t_m_rec_init (P_t *pads,obs_FWS_t_m *mask,Pbase_m baseMask);

Perror_t obs_FWS_t_read (P_t *pads,obs_FWS_t_m *m,obs_FWS_t_pd *pd,obs_FWS_t *rep);

int obs_FWS_t_verify (P_t *pads,obs_FWS_t *rep);

int obs_FWS_t_genPD (P_t *pads,obs_FWS_t *rep,obs_FWS_t_pd *pd);
typedef Pstring_acc obs_FWS_t_acc;

Perror_t obs_FWS_t_acc_init (P_t *pads,obs_FWS_t_acc *acc);

Perror_t obs_FWS_t_acc_reset (P_t *pads,obs_FWS_t_acc *acc);

Perror_t obs_FWS_t_acc_cleanup (P_t *pads,obs_FWS_t_acc *acc);

Perror_t obs_FWS_t_acc_add (P_t *pads,obs_FWS_t_acc *acc,obs_FWS_t_pd *pd,obs_FWS_t *rep);

Perror_t obs_FWS_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,obs_FWS_t_acc *acc);

Perror_t obs_FWS_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,obs_FWS_t_acc *acc);

Perror_t obs_FWS_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,obs_FWS_t_acc *acc);

ssize_t obs_FWS_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_FWS_t_pd *pd,obs_FWS_t *rep);

ssize_t obs_FWS_t_write2io (P_t *pads,Sfio_t *io,obs_FWS_t_pd *pd,obs_FWS_t *rep);

ssize_t obs_FWS_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_FWS_t_pd *pd,obs_FWS_t *rep,char const *_tag,int indent);

ssize_t obs_FWS_t_write_xml_2io (P_t *pads,Sfio_t *io,obs_FWS_t_pd *pd,obs_FWS_t *rep,char const *_tag,int indent);

ssize_t obs_FWS_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_FWS_t_m *m,obs_FWS_t_pd *pd,obs_FWS_t *rep);

ssize_t obs_FWS_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_FWS_t_m *m,obs_FWS_t_pd *pd,obs_FWS_t *rep);

ssize_t obs_FWS_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,obs_FWS_t_m *m,obs_FWS_t_pd *pd,obs_FWS_t *rep);
typedef Pstring FWS_t;
typedef struct FWS_t_m_s FWS_t_m;
typedef Pbase_pd FWS_t_pd;
struct FWS_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t FWS_t_init (P_t *pads,FWS_t *rep);

Perror_t FWS_t_pd_init (P_t *pads,FWS_t_pd *pd);

Perror_t FWS_t_cleanup (P_t *pads,FWS_t *rep);

Perror_t FWS_t_pd_cleanup (P_t *pads,FWS_t_pd *pd);

Perror_t FWS_t_copy (P_t *pads,FWS_t *rep_dst,FWS_t *rep_src);

Perror_t FWS_t_pd_copy (P_t *pads,FWS_t_pd *pd_dst,FWS_t_pd *pd_src);

void FWS_t_m_init (P_t *pads,FWS_t_m *mask,Pbase_m baseMask);

Perror_t FWS_t_m_rec_init (P_t *pads,FWS_t_m *mask,Pbase_m baseMask);

Perror_t FWS_t_read (P_t *pads,FWS_t_m *m,FWS_t_pd *pd,FWS_t *rep);

int FWS_t_verify (P_t *pads,FWS_t *rep);

int FWS_t_genPD (P_t *pads,FWS_t *rep,FWS_t_pd *pd);
typedef Pstring_acc FWS_t_acc;

Perror_t FWS_t_acc_init (P_t *pads,FWS_t_acc *acc);

Perror_t FWS_t_acc_reset (P_t *pads,FWS_t_acc *acc);

Perror_t FWS_t_acc_cleanup (P_t *pads,FWS_t_acc *acc);

Perror_t FWS_t_acc_add (P_t *pads,FWS_t_acc *acc,FWS_t_pd *pd,FWS_t *rep);

Perror_t FWS_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,FWS_t_acc *acc);

Perror_t FWS_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,FWS_t_acc *acc);

Perror_t FWS_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,FWS_t_acc *acc);

ssize_t FWS_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,FWS_t_pd *pd,FWS_t *rep);

ssize_t FWS_t_write2io (P_t *pads,Sfio_t *io,FWS_t_pd *pd,FWS_t *rep);

ssize_t FWS_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,FWS_t_pd *pd,FWS_t *rep,char const *_tag,int indent);

ssize_t FWS_t_write_xml_2io (P_t *pads,Sfio_t *io,FWS_t_pd *pd,FWS_t *rep,char const *_tag,int indent);

ssize_t FWS_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,FWS_t_m *m,FWS_t_pd *pd,FWS_t *rep);

ssize_t FWS_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,FWS_t_m *m,FWS_t_pd *pd,FWS_t *rep);

ssize_t FWS_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,FWS_t_m *m,FWS_t_pd *pd,FWS_t *rep);
typedef Pstring CFWS_t;
typedef struct CFWS_t_m_s CFWS_t_m;
typedef Pbase_pd CFWS_t_pd;
struct CFWS_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t CFWS_t_init (P_t *pads,CFWS_t *rep);

Perror_t CFWS_t_pd_init (P_t *pads,CFWS_t_pd *pd);

Perror_t CFWS_t_cleanup (P_t *pads,CFWS_t *rep);

Perror_t CFWS_t_pd_cleanup (P_t *pads,CFWS_t_pd *pd);

Perror_t CFWS_t_copy (P_t *pads,CFWS_t *rep_dst,CFWS_t *rep_src);

Perror_t CFWS_t_pd_copy (P_t *pads,CFWS_t_pd *pd_dst,CFWS_t_pd *pd_src);

void CFWS_t_m_init (P_t *pads,CFWS_t_m *mask,Pbase_m baseMask);

Perror_t CFWS_t_m_rec_init (P_t *pads,CFWS_t_m *mask,Pbase_m baseMask);

Perror_t CFWS_t_read (P_t *pads,CFWS_t_m *m,CFWS_t_pd *pd,CFWS_t *rep);

int CFWS_t_verify (P_t *pads,CFWS_t *rep);

int CFWS_t_genPD (P_t *pads,CFWS_t *rep,CFWS_t_pd *pd);
typedef Pstring_acc CFWS_t_acc;

Perror_t CFWS_t_acc_init (P_t *pads,CFWS_t_acc *acc);

Perror_t CFWS_t_acc_reset (P_t *pads,CFWS_t_acc *acc);

Perror_t CFWS_t_acc_cleanup (P_t *pads,CFWS_t_acc *acc);

Perror_t CFWS_t_acc_add (P_t *pads,CFWS_t_acc *acc,CFWS_t_pd *pd,CFWS_t *rep);

Perror_t CFWS_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,CFWS_t_acc *acc);

Perror_t CFWS_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,CFWS_t_acc *acc);

Perror_t CFWS_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,CFWS_t_acc *acc);

ssize_t CFWS_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CFWS_t_pd *pd,CFWS_t *rep);

ssize_t CFWS_t_write2io (P_t *pads,Sfio_t *io,CFWS_t_pd *pd,CFWS_t *rep);

ssize_t CFWS_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,CFWS_t_pd *pd,CFWS_t *rep,char const *_tag,int indent);

ssize_t CFWS_t_write_xml_2io (P_t *pads,Sfio_t *io,CFWS_t_pd *pd,CFWS_t *rep,char const *_tag,int indent);

ssize_t CFWS_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CFWS_t_m *m,CFWS_t_pd *pd,CFWS_t *rep);

ssize_t CFWS_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,CFWS_t_m *m,CFWS_t_pd *pd,CFWS_t *rep);

ssize_t CFWS_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,CFWS_t_m *m,CFWS_t_pd *pd,CFWS_t *rep);

int is_obs_char (Pchar x);
typedef Pchar obs_char_t;
typedef struct obs_char_t_m_s obs_char_t_m;
typedef Pbase_pd obs_char_t_pd;
struct obs_char_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t obs_char_t_init (P_t *pads,obs_char_t *rep);

Perror_t obs_char_t_pd_init (P_t *pads,obs_char_t_pd *pd);

Perror_t obs_char_t_cleanup (P_t *pads,obs_char_t *rep);

Perror_t obs_char_t_pd_cleanup (P_t *pads,obs_char_t_pd *pd);

Perror_t obs_char_t_copy (P_t *pads,obs_char_t *rep_dst,obs_char_t *rep_src);

Perror_t obs_char_t_pd_copy (P_t *pads,obs_char_t_pd *pd_dst,obs_char_t_pd *pd_src);

void obs_char_t_m_init (P_t *pads,obs_char_t_m *mask,Pbase_m baseMask);

Perror_t obs_char_t_m_rec_init (P_t *pads,obs_char_t_m *mask,Pbase_m baseMask);

Perror_t obs_char_t_read (P_t *pads,obs_char_t_m *m,obs_char_t_pd *pd,obs_char_t *rep);

int obs_char_t_verify (P_t *pads,obs_char_t *rep);

int obs_char_t_genPD (P_t *pads,obs_char_t *rep,obs_char_t_pd *pd);
typedef Pchar_acc obs_char_t_acc;

Perror_t obs_char_t_acc_init (P_t *pads,obs_char_t_acc *acc);

Perror_t obs_char_t_acc_reset (P_t *pads,obs_char_t_acc *acc);

Perror_t obs_char_t_acc_cleanup (P_t *pads,obs_char_t_acc *acc);

Perror_t obs_char_t_acc_add (P_t *pads,obs_char_t_acc *acc,obs_char_t_pd *pd,obs_char_t *rep);

Perror_t obs_char_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,obs_char_t_acc *acc);

Perror_t obs_char_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,obs_char_t_acc *acc);

Perror_t obs_char_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,obs_char_t_acc *acc);

ssize_t obs_char_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_char_t_pd *pd,obs_char_t *rep);

ssize_t obs_char_t_write2io (P_t *pads,Sfio_t *io,obs_char_t_pd *pd,obs_char_t *rep);

ssize_t obs_char_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_char_t_pd *pd,obs_char_t *rep,char const *_tag,int indent);

ssize_t obs_char_t_write_xml_2io (P_t *pads,Sfio_t *io,obs_char_t_pd *pd,obs_char_t *rep,char const *_tag,int indent);

ssize_t obs_char_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_char_t_m *m,obs_char_t_pd *pd,obs_char_t *rep);

ssize_t obs_char_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_char_t_m *m,obs_char_t_pd *pd,obs_char_t *rep);

ssize_t obs_char_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,obs_char_t_m *m,obs_char_t_pd *pd,obs_char_t *rep);

int obs_char_verify_8 (int i);
typedef Pstring obs_qp_t;
typedef struct obs_qp_t_m_s obs_qp_t_m;
typedef Pbase_pd obs_qp_t_pd;
struct obs_qp_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t obs_qp_t_init (P_t *pads,obs_qp_t *rep);

Perror_t obs_qp_t_pd_init (P_t *pads,obs_qp_t_pd *pd);

Perror_t obs_qp_t_cleanup (P_t *pads,obs_qp_t *rep);

Perror_t obs_qp_t_pd_cleanup (P_t *pads,obs_qp_t_pd *pd);

Perror_t obs_qp_t_copy (P_t *pads,obs_qp_t *rep_dst,obs_qp_t *rep_src);

Perror_t obs_qp_t_pd_copy (P_t *pads,obs_qp_t_pd *pd_dst,obs_qp_t_pd *pd_src);

void obs_qp_t_m_init (P_t *pads,obs_qp_t_m *mask,Pbase_m baseMask);

Perror_t obs_qp_t_m_rec_init (P_t *pads,obs_qp_t_m *mask,Pbase_m baseMask);

Perror_t obs_qp_t_read (P_t *pads,obs_qp_t_m *m,obs_qp_t_pd *pd,obs_qp_t *rep);

int obs_qp_t_verify (P_t *pads,obs_qp_t *rep);

int obs_qp_t_genPD (P_t *pads,obs_qp_t *rep,obs_qp_t_pd *pd);
typedef Pstring_acc obs_qp_t_acc;

Perror_t obs_qp_t_acc_init (P_t *pads,obs_qp_t_acc *acc);

Perror_t obs_qp_t_acc_reset (P_t *pads,obs_qp_t_acc *acc);

Perror_t obs_qp_t_acc_cleanup (P_t *pads,obs_qp_t_acc *acc);

Perror_t obs_qp_t_acc_add (P_t *pads,obs_qp_t_acc *acc,obs_qp_t_pd *pd,obs_qp_t *rep);

Perror_t obs_qp_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,obs_qp_t_acc *acc);

Perror_t obs_qp_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,obs_qp_t_acc *acc);

Perror_t obs_qp_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,obs_qp_t_acc *acc);

ssize_t obs_qp_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_qp_t_pd *pd,obs_qp_t *rep);

ssize_t obs_qp_t_write2io (P_t *pads,Sfio_t *io,obs_qp_t_pd *pd,obs_qp_t *rep);

ssize_t obs_qp_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_qp_t_pd *pd,obs_qp_t *rep,char const *_tag,int indent);

ssize_t obs_qp_t_write_xml_2io (P_t *pads,Sfio_t *io,obs_qp_t_pd *pd,obs_qp_t *rep,char const *_tag,int indent);

ssize_t obs_qp_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_qp_t_m *m,obs_qp_t_pd *pd,obs_qp_t *rep);

ssize_t obs_qp_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_qp_t_m *m,obs_qp_t_pd *pd,obs_qp_t *rep);

ssize_t obs_qp_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,obs_qp_t_m *m,obs_qp_t_pd *pd,obs_qp_t *rep);
typedef Pstring obs_text_t;
typedef struct obs_text_t_m_s obs_text_t_m;
typedef Pbase_pd obs_text_t_pd;
struct obs_text_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t obs_text_t_init (P_t *pads,obs_text_t *rep);

Perror_t obs_text_t_pd_init (P_t *pads,obs_text_t_pd *pd);

Perror_t obs_text_t_cleanup (P_t *pads,obs_text_t *rep);

Perror_t obs_text_t_pd_cleanup (P_t *pads,obs_text_t_pd *pd);

Perror_t obs_text_t_copy (P_t *pads,obs_text_t *rep_dst,obs_text_t *rep_src);

Perror_t obs_text_t_pd_copy (P_t *pads,obs_text_t_pd *pd_dst,obs_text_t_pd *pd_src);

void obs_text_t_m_init (P_t *pads,obs_text_t_m *mask,Pbase_m baseMask);

Perror_t obs_text_t_m_rec_init (P_t *pads,obs_text_t_m *mask,Pbase_m baseMask);

Perror_t obs_text_t_read (P_t *pads,obs_text_t_m *m,obs_text_t_pd *pd,obs_text_t *rep);

int obs_text_t_verify (P_t *pads,obs_text_t *rep);

int obs_text_t_genPD (P_t *pads,obs_text_t *rep,obs_text_t_pd *pd);
typedef Pstring_acc obs_text_t_acc;

Perror_t obs_text_t_acc_init (P_t *pads,obs_text_t_acc *acc);

Perror_t obs_text_t_acc_reset (P_t *pads,obs_text_t_acc *acc);

Perror_t obs_text_t_acc_cleanup (P_t *pads,obs_text_t_acc *acc);

Perror_t obs_text_t_acc_add (P_t *pads,obs_text_t_acc *acc,obs_text_t_pd *pd,obs_text_t *rep);

Perror_t obs_text_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,obs_text_t_acc *acc);

Perror_t obs_text_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,obs_text_t_acc *acc);

Perror_t obs_text_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,obs_text_t_acc *acc);

ssize_t obs_text_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_text_t_pd *pd,obs_text_t *rep);

ssize_t obs_text_t_write2io (P_t *pads,Sfio_t *io,obs_text_t_pd *pd,obs_text_t *rep);

ssize_t obs_text_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,obs_text_t_pd *pd,obs_text_t *rep,char const *_tag,int indent);

ssize_t obs_text_t_write_xml_2io (P_t *pads,Sfio_t *io,obs_text_t_pd *pd,obs_text_t *rep,char const *_tag,int indent);

ssize_t obs_text_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_text_t_m *m,obs_text_t_pd *pd,obs_text_t *rep);

ssize_t obs_text_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,obs_text_t_m *m,obs_text_t_pd *pd,obs_text_t *rep);

ssize_t obs_text_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,obs_text_t_m *m,obs_text_t_pd *pd,obs_text_t *rep);

int is_qtext (Pchar x);
typedef Pchar qtext_t;
typedef struct qtext_t_m_s qtext_t_m;
typedef Pbase_pd qtext_t_pd;
struct qtext_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t qtext_t_init (P_t *pads,qtext_t *rep);

Perror_t qtext_t_pd_init (P_t *pads,qtext_t_pd *pd);

Perror_t qtext_t_cleanup (P_t *pads,qtext_t *rep);

Perror_t qtext_t_pd_cleanup (P_t *pads,qtext_t_pd *pd);

Perror_t qtext_t_copy (P_t *pads,qtext_t *rep_dst,qtext_t *rep_src);

Perror_t qtext_t_pd_copy (P_t *pads,qtext_t_pd *pd_dst,qtext_t_pd *pd_src);

void qtext_t_m_init (P_t *pads,qtext_t_m *mask,Pbase_m baseMask);

Perror_t qtext_t_m_rec_init (P_t *pads,qtext_t_m *mask,Pbase_m baseMask);

Perror_t qtext_t_read (P_t *pads,qtext_t_m *m,qtext_t_pd *pd,qtext_t *rep);

int qtext_t_verify (P_t *pads,qtext_t *rep);

int qtext_t_genPD (P_t *pads,qtext_t *rep,qtext_t_pd *pd);
typedef Pchar_acc qtext_t_acc;

Perror_t qtext_t_acc_init (P_t *pads,qtext_t_acc *acc);

Perror_t qtext_t_acc_reset (P_t *pads,qtext_t_acc *acc);

Perror_t qtext_t_acc_cleanup (P_t *pads,qtext_t_acc *acc);

Perror_t qtext_t_acc_add (P_t *pads,qtext_t_acc *acc,qtext_t_pd *pd,qtext_t *rep);

Perror_t qtext_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,qtext_t_acc *acc);

Perror_t qtext_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,qtext_t_acc *acc);

Perror_t qtext_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,qtext_t_acc *acc);

ssize_t qtext_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,qtext_t_pd *pd,qtext_t *rep);

ssize_t qtext_t_write2io (P_t *pads,Sfio_t *io,qtext_t_pd *pd,qtext_t *rep);

ssize_t qtext_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,qtext_t_pd *pd,qtext_t *rep,char const *_tag,int indent);

ssize_t qtext_t_write_xml_2io (P_t *pads,Sfio_t *io,qtext_t_pd *pd,qtext_t *rep,char const *_tag,int indent);

ssize_t qtext_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,qtext_t_m *m,qtext_t_pd *pd,qtext_t *rep);

ssize_t qtext_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,qtext_t_m *m,qtext_t_pd *pd,qtext_t *rep);

ssize_t qtext_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,qtext_t_m *m,qtext_t_pd *pd,qtext_t *rep);

int qtext_verify_9 (int i);

int is_separators (Pchar x);
typedef Pchar separators_t;
typedef struct separators_t_m_s separators_t_m;
typedef Pbase_pd separators_t_pd;
struct separators_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t separators_t_init (P_t *pads,separators_t *rep);

Perror_t separators_t_pd_init (P_t *pads,separators_t_pd *pd);

Perror_t separators_t_cleanup (P_t *pads,separators_t *rep);

Perror_t separators_t_pd_cleanup (P_t *pads,separators_t_pd *pd);

Perror_t separators_t_copy (P_t *pads,separators_t *rep_dst,separators_t *rep_src);

Perror_t separators_t_pd_copy (P_t *pads,separators_t_pd *pd_dst,separators_t_pd *pd_src);

void separators_t_m_init (P_t *pads,separators_t_m *mask,Pbase_m baseMask);

Perror_t separators_t_m_rec_init (P_t *pads,separators_t_m *mask,Pbase_m baseMask);

Perror_t separators_t_read (P_t *pads,separators_t_m *m,separators_t_pd *pd,separators_t *rep);

int separators_t_verify (P_t *pads,separators_t *rep);

int separators_t_genPD (P_t *pads,separators_t *rep,separators_t_pd *pd);
typedef Pchar_acc separators_t_acc;

Perror_t separators_t_acc_init (P_t *pads,separators_t_acc *acc);

Perror_t separators_t_acc_reset (P_t *pads,separators_t_acc *acc);

Perror_t separators_t_acc_cleanup (P_t *pads,separators_t_acc *acc);

Perror_t separators_t_acc_add (P_t *pads,separators_t_acc *acc,separators_t_pd *pd,separators_t *rep);

Perror_t separators_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,separators_t_acc *acc);

Perror_t separators_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,separators_t_acc *acc);

Perror_t separators_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,separators_t_acc *acc);

ssize_t separators_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,separators_t_pd *pd,separators_t *rep);

ssize_t separators_t_write2io (P_t *pads,Sfio_t *io,separators_t_pd *pd,separators_t *rep);

ssize_t separators_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,separators_t_pd *pd,separators_t *rep,char const *_tag,int indent);

ssize_t separators_t_write_xml_2io (P_t *pads,Sfio_t *io,separators_t_pd *pd,separators_t *rep,char const *_tag,int indent);

ssize_t separators_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,separators_t_m *m,separators_t_pd *pd,separators_t *rep);

ssize_t separators_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,separators_t_m *m,separators_t_pd *pd,separators_t *rep);

ssize_t separators_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,separators_t_m *m,separators_t_pd *pd,separators_t *rep);

int separators_verify_10 (int i);
typedef Pstring text_t;
typedef struct text_t_m_s text_t_m;
typedef Pbase_pd text_t_pd;
struct text_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t text_t_init (P_t *pads,text_t *rep);

Perror_t text_t_pd_init (P_t *pads,text_t_pd *pd);

Perror_t text_t_cleanup (P_t *pads,text_t *rep);

Perror_t text_t_pd_cleanup (P_t *pads,text_t_pd *pd);

Perror_t text_t_copy (P_t *pads,text_t *rep_dst,text_t *rep_src);

Perror_t text_t_pd_copy (P_t *pads,text_t_pd *pd_dst,text_t_pd *pd_src);

void text_t_m_init (P_t *pads,text_t_m *mask,Pbase_m baseMask);

Perror_t text_t_m_rec_init (P_t *pads,text_t_m *mask,Pbase_m baseMask);

Perror_t text_t_read (P_t *pads,text_t_m *m,text_t_pd *pd,text_t *rep);

int text_t_verify (P_t *pads,text_t *rep);

int text_t_genPD (P_t *pads,text_t *rep,text_t_pd *pd);
typedef Pstring_acc text_t_acc;

Perror_t text_t_acc_init (P_t *pads,text_t_acc *acc);

Perror_t text_t_acc_reset (P_t *pads,text_t_acc *acc);

Perror_t text_t_acc_cleanup (P_t *pads,text_t_acc *acc);

Perror_t text_t_acc_add (P_t *pads,text_t_acc *acc,text_t_pd *pd,text_t *rep);

Perror_t text_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,text_t_acc *acc);

Perror_t text_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,text_t_acc *acc);

Perror_t text_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,text_t_acc *acc);

ssize_t text_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,text_t_pd *pd,text_t *rep);

ssize_t text_t_write2io (P_t *pads,Sfio_t *io,text_t_pd *pd,text_t *rep);

ssize_t text_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,text_t_pd *pd,text_t *rep,char const *_tag,int indent);

ssize_t text_t_write_xml_2io (P_t *pads,Sfio_t *io,text_t_pd *pd,text_t *rep,char const *_tag,int indent);

ssize_t text_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,text_t_m *m,text_t_pd *pd,text_t *rep);

ssize_t text_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,text_t_m *m,text_t_pd *pd,text_t *rep);

ssize_t text_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,text_t_m *m,text_t_pd *pd,text_t *rep);
typedef Pstring quoted_pair_mailbox_t;
typedef struct quoted_pair_mailbox_t_m_s quoted_pair_mailbox_t_m;
typedef Pbase_pd quoted_pair_mailbox_t_pd;
struct quoted_pair_mailbox_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t quoted_pair_mailbox_t_init (P_t *pads,quoted_pair_mailbox_t *rep);

Perror_t quoted_pair_mailbox_t_pd_init (P_t *pads,quoted_pair_mailbox_t_pd *pd);

Perror_t quoted_pair_mailbox_t_cleanup (P_t *pads,quoted_pair_mailbox_t *rep);

Perror_t quoted_pair_mailbox_t_pd_cleanup (P_t *pads,quoted_pair_mailbox_t_pd *pd);

Perror_t quoted_pair_mailbox_t_copy (P_t *pads,quoted_pair_mailbox_t *rep_dst,quoted_pair_mailbox_t *rep_src);

Perror_t quoted_pair_mailbox_t_pd_copy (P_t *pads,quoted_pair_mailbox_t_pd *pd_dst,quoted_pair_mailbox_t_pd *pd_src);

void quoted_pair_mailbox_t_m_init (P_t *pads,quoted_pair_mailbox_t_m *mask,Pbase_m baseMask);

Perror_t quoted_pair_mailbox_t_m_rec_init (P_t *pads,quoted_pair_mailbox_t_m *mask,Pbase_m baseMask);

Perror_t quoted_pair_mailbox_t_read (P_t *pads,quoted_pair_mailbox_t_m *m,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

int quoted_pair_mailbox_t_verify (P_t *pads,quoted_pair_mailbox_t *rep);

int quoted_pair_mailbox_t_genPD (P_t *pads,quoted_pair_mailbox_t *rep,quoted_pair_mailbox_t_pd *pd);
typedef Pstring_acc quoted_pair_mailbox_t_acc;

Perror_t quoted_pair_mailbox_t_acc_init (P_t *pads,quoted_pair_mailbox_t_acc *acc);

Perror_t quoted_pair_mailbox_t_acc_reset (P_t *pads,quoted_pair_mailbox_t_acc *acc);

Perror_t quoted_pair_mailbox_t_acc_cleanup (P_t *pads,quoted_pair_mailbox_t_acc *acc);

Perror_t quoted_pair_mailbox_t_acc_add (P_t *pads,quoted_pair_mailbox_t_acc *acc,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

Perror_t quoted_pair_mailbox_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,quoted_pair_mailbox_t_acc *acc);

Perror_t quoted_pair_mailbox_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,quoted_pair_mailbox_t_acc *acc);

Perror_t quoted_pair_mailbox_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,quoted_pair_mailbox_t_acc *acc);

ssize_t quoted_pair_mailbox_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

ssize_t quoted_pair_mailbox_t_write2io (P_t *pads,Sfio_t *io,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

ssize_t quoted_pair_mailbox_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep,char const *_tag,int indent);

ssize_t quoted_pair_mailbox_t_write_xml_2io (P_t *pads,Sfio_t *io,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep,char const *_tag,int indent);

ssize_t quoted_pair_mailbox_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,quoted_pair_mailbox_t_m *m,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

ssize_t quoted_pair_mailbox_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,quoted_pair_mailbox_t_m *m,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);

ssize_t quoted_pair_mailbox_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,quoted_pair_mailbox_t_m *m,quoted_pair_mailbox_t_pd *pd,quoted_pair_mailbox_t *rep);
typedef Pstring qcontent_t;
typedef struct qcontent_t_m_s qcontent_t_m;
typedef Pbase_pd qcontent_t_pd;
struct qcontent_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t qcontent_t_init (P_t *pads,qcontent_t *rep);

Perror_t qcontent_t_pd_init (P_t *pads,qcontent_t_pd *pd);

Perror_t qcontent_t_cleanup (P_t *pads,qcontent_t *rep);

Perror_t qcontent_t_pd_cleanup (P_t *pads,qcontent_t_pd *pd);

Perror_t qcontent_t_copy (P_t *pads,qcontent_t *rep_dst,qcontent_t *rep_src);

Perror_t qcontent_t_pd_copy (P_t *pads,qcontent_t_pd *pd_dst,qcontent_t_pd *pd_src);

void qcontent_t_m_init (P_t *pads,qcontent_t_m *mask,Pbase_m baseMask);

Perror_t qcontent_t_m_rec_init (P_t *pads,qcontent_t_m *mask,Pbase_m baseMask);

Perror_t qcontent_t_read (P_t *pads,qcontent_t_m *m,qcontent_t_pd *pd,qcontent_t *rep);

int qcontent_t_verify (P_t *pads,qcontent_t *rep);

int qcontent_t_genPD (P_t *pads,qcontent_t *rep,qcontent_t_pd *pd);
typedef Pstring_acc qcontent_t_acc;

Perror_t qcontent_t_acc_init (P_t *pads,qcontent_t_acc *acc);

Perror_t qcontent_t_acc_reset (P_t *pads,qcontent_t_acc *acc);

Perror_t qcontent_t_acc_cleanup (P_t *pads,qcontent_t_acc *acc);

Perror_t qcontent_t_acc_add (P_t *pads,qcontent_t_acc *acc,qcontent_t_pd *pd,qcontent_t *rep);

Perror_t qcontent_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,qcontent_t_acc *acc);

Perror_t qcontent_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,qcontent_t_acc *acc);

Perror_t qcontent_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,qcontent_t_acc *acc);

ssize_t qcontent_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,qcontent_t_pd *pd,qcontent_t *rep);

ssize_t qcontent_t_write2io (P_t *pads,Sfio_t *io,qcontent_t_pd *pd,qcontent_t *rep);

ssize_t qcontent_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,qcontent_t_pd *pd,qcontent_t *rep,char const *_tag,int indent);

ssize_t qcontent_t_write_xml_2io (P_t *pads,Sfio_t *io,qcontent_t_pd *pd,qcontent_t *rep,char const *_tag,int indent);

ssize_t qcontent_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,qcontent_t_m *m,qcontent_t_pd *pd,qcontent_t *rep);

ssize_t qcontent_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,qcontent_t_m *m,qcontent_t_pd *pd,qcontent_t *rep);

ssize_t qcontent_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,qcontent_t_m *m,qcontent_t_pd *pd,qcontent_t *rep);
typedef Pstring quoted_string_t;
typedef struct quoted_string_t_m_s quoted_string_t_m;
typedef Pbase_pd quoted_string_t_pd;
struct quoted_string_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t quoted_string_t_init (P_t *pads,quoted_string_t *rep);

Perror_t quoted_string_t_pd_init (P_t *pads,quoted_string_t_pd *pd);

Perror_t quoted_string_t_cleanup (P_t *pads,quoted_string_t *rep);

Perror_t quoted_string_t_pd_cleanup (P_t *pads,quoted_string_t_pd *pd);

Perror_t quoted_string_t_copy (P_t *pads,quoted_string_t *rep_dst,quoted_string_t *rep_src);

Perror_t quoted_string_t_pd_copy (P_t *pads,quoted_string_t_pd *pd_dst,quoted_string_t_pd *pd_src);

void quoted_string_t_m_init (P_t *pads,quoted_string_t_m *mask,Pbase_m baseMask);

Perror_t quoted_string_t_m_rec_init (P_t *pads,quoted_string_t_m *mask,Pbase_m baseMask);

Perror_t quoted_string_t_read (P_t *pads,quoted_string_t_m *m,quoted_string_t_pd *pd,quoted_string_t *rep);

int quoted_string_t_verify (P_t *pads,quoted_string_t *rep);

int quoted_string_t_genPD (P_t *pads,quoted_string_t *rep,quoted_string_t_pd *pd);
typedef Pstring_acc quoted_string_t_acc;

Perror_t quoted_string_t_acc_init (P_t *pads,quoted_string_t_acc *acc);

Perror_t quoted_string_t_acc_reset (P_t *pads,quoted_string_t_acc *acc);

Perror_t quoted_string_t_acc_cleanup (P_t *pads,quoted_string_t_acc *acc);

Perror_t quoted_string_t_acc_add (P_t *pads,quoted_string_t_acc *acc,quoted_string_t_pd *pd,quoted_string_t *rep);

Perror_t quoted_string_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,quoted_string_t_acc *acc);

Perror_t quoted_string_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,quoted_string_t_acc *acc);

Perror_t quoted_string_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,quoted_string_t_acc *acc);

ssize_t quoted_string_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,quoted_string_t_pd *pd,quoted_string_t *rep);

ssize_t quoted_string_t_write2io (P_t *pads,Sfio_t *io,quoted_string_t_pd *pd,quoted_string_t *rep);

ssize_t quoted_string_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,quoted_string_t_pd *pd,quoted_string_t *rep,char const *_tag,int indent);

ssize_t quoted_string_t_write_xml_2io (P_t *pads,Sfio_t *io,quoted_string_t_pd *pd,quoted_string_t *rep,char const *_tag,int indent);

ssize_t quoted_string_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,quoted_string_t_m *m,quoted_string_t_pd *pd,quoted_string_t *rep);

ssize_t quoted_string_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,quoted_string_t_m *m,quoted_string_t_pd *pd,quoted_string_t *rep);

ssize_t quoted_string_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,quoted_string_t_m *m,quoted_string_t_pd *pd,quoted_string_t *rep);

int is_token_char (Pchar x);
typedef Pchar token_char_t;
typedef struct token_char_t_m_s token_char_t_m;
typedef Pbase_pd token_char_t_pd;
struct token_char_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t token_char_t_init (P_t *pads,token_char_t *rep);

Perror_t token_char_t_pd_init (P_t *pads,token_char_t_pd *pd);

Perror_t token_char_t_cleanup (P_t *pads,token_char_t *rep);

Perror_t token_char_t_pd_cleanup (P_t *pads,token_char_t_pd *pd);

Perror_t token_char_t_copy (P_t *pads,token_char_t *rep_dst,token_char_t *rep_src);

Perror_t token_char_t_pd_copy (P_t *pads,token_char_t_pd *pd_dst,token_char_t_pd *pd_src);

void token_char_t_m_init (P_t *pads,token_char_t_m *mask,Pbase_m baseMask);

Perror_t token_char_t_m_rec_init (P_t *pads,token_char_t_m *mask,Pbase_m baseMask);

Perror_t token_char_t_read (P_t *pads,token_char_t_m *m,token_char_t_pd *pd,token_char_t *rep);

int token_char_t_verify (P_t *pads,token_char_t *rep);

int token_char_t_genPD (P_t *pads,token_char_t *rep,token_char_t_pd *pd);
typedef Pchar_acc token_char_t_acc;

Perror_t token_char_t_acc_init (P_t *pads,token_char_t_acc *acc);

Perror_t token_char_t_acc_reset (P_t *pads,token_char_t_acc *acc);

Perror_t token_char_t_acc_cleanup (P_t *pads,token_char_t_acc *acc);

Perror_t token_char_t_acc_add (P_t *pads,token_char_t_acc *acc,token_char_t_pd *pd,token_char_t *rep);

Perror_t token_char_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,token_char_t_acc *acc);

Perror_t token_char_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,token_char_t_acc *acc);

Perror_t token_char_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,token_char_t_acc *acc);

ssize_t token_char_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,token_char_t_pd *pd,token_char_t *rep);

ssize_t token_char_t_write2io (P_t *pads,Sfio_t *io,token_char_t_pd *pd,token_char_t *rep);

ssize_t token_char_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,token_char_t_pd *pd,token_char_t *rep,char const *_tag,int indent);

ssize_t token_char_t_write_xml_2io (P_t *pads,Sfio_t *io,token_char_t_pd *pd,token_char_t *rep,char const *_tag,int indent);

ssize_t token_char_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,token_char_t_m *m,token_char_t_pd *pd,token_char_t *rep);

ssize_t token_char_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,token_char_t_m *m,token_char_t_pd *pd,token_char_t *rep);

ssize_t token_char_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,token_char_t_m *m,token_char_t_pd *pd,token_char_t *rep);

int token_char_verify_11 (int i);
typedef Pstring token_t;
typedef struct token_t_m_s token_t_m;
typedef Pbase_pd token_t_pd;
struct token_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t token_t_init (P_t *pads,token_t *rep);

Perror_t token_t_pd_init (P_t *pads,token_t_pd *pd);

Perror_t token_t_cleanup (P_t *pads,token_t *rep);

Perror_t token_t_pd_cleanup (P_t *pads,token_t_pd *pd);

Perror_t token_t_copy (P_t *pads,token_t *rep_dst,token_t *rep_src);

Perror_t token_t_pd_copy (P_t *pads,token_t_pd *pd_dst,token_t_pd *pd_src);

void token_t_m_init (P_t *pads,token_t_m *mask,Pbase_m baseMask);

Perror_t token_t_m_rec_init (P_t *pads,token_t_m *mask,Pbase_m baseMask);

Perror_t token_t_read (P_t *pads,token_t_m *m,token_t_pd *pd,token_t *rep);

int token_t_verify (P_t *pads,token_t *rep);

int token_t_genPD (P_t *pads,token_t *rep,token_t_pd *pd);
typedef Pstring_acc token_t_acc;

Perror_t token_t_acc_init (P_t *pads,token_t_acc *acc);

Perror_t token_t_acc_reset (P_t *pads,token_t_acc *acc);

Perror_t token_t_acc_cleanup (P_t *pads,token_t_acc *acc);

Perror_t token_t_acc_add (P_t *pads,token_t_acc *acc,token_t_pd *pd,token_t *rep);

Perror_t token_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,token_t_acc *acc);

Perror_t token_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,token_t_acc *acc);

Perror_t token_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,token_t_acc *acc);

ssize_t token_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,token_t_pd *pd,token_t *rep);

ssize_t token_t_write2io (P_t *pads,Sfio_t *io,token_t_pd *pd,token_t *rep);

ssize_t token_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,token_t_pd *pd,token_t *rep,char const *_tag,int indent);

ssize_t token_t_write_xml_2io (P_t *pads,Sfio_t *io,token_t_pd *pd,token_t *rep,char const *_tag,int indent);

ssize_t token_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,token_t_m *m,token_t_pd *pd,token_t *rep);

ssize_t token_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,token_t_m *m,token_t_pd *pd,token_t *rep);

ssize_t token_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,token_t_m *m,token_t_pd *pd,token_t *rep);
typedef Pstring field_name_t;
typedef struct field_name_t_m_s field_name_t_m;
typedef Pbase_pd field_name_t_pd;
struct field_name_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t field_name_t_init (P_t *pads,field_name_t *rep);

Perror_t field_name_t_pd_init (P_t *pads,field_name_t_pd *pd);

Perror_t field_name_t_cleanup (P_t *pads,field_name_t *rep);

Perror_t field_name_t_pd_cleanup (P_t *pads,field_name_t_pd *pd);

Perror_t field_name_t_copy (P_t *pads,field_name_t *rep_dst,field_name_t *rep_src);

Perror_t field_name_t_pd_copy (P_t *pads,field_name_t_pd *pd_dst,field_name_t_pd *pd_src);

void field_name_t_m_init (P_t *pads,field_name_t_m *mask,Pbase_m baseMask);

Perror_t field_name_t_m_rec_init (P_t *pads,field_name_t_m *mask,Pbase_m baseMask);

Perror_t field_name_t_read (P_t *pads,field_name_t_m *m,field_name_t_pd *pd,field_name_t *rep);

int field_name_t_verify (P_t *pads,field_name_t *rep);

int field_name_t_genPD (P_t *pads,field_name_t *rep,field_name_t_pd *pd);
typedef Pstring_acc field_name_t_acc;

Perror_t field_name_t_acc_init (P_t *pads,field_name_t_acc *acc);

Perror_t field_name_t_acc_reset (P_t *pads,field_name_t_acc *acc);

Perror_t field_name_t_acc_cleanup (P_t *pads,field_name_t_acc *acc);

Perror_t field_name_t_acc_add (P_t *pads,field_name_t_acc *acc,field_name_t_pd *pd,field_name_t *rep);

Perror_t field_name_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,field_name_t_acc *acc);

Perror_t field_name_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,field_name_t_acc *acc);

Perror_t field_name_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,field_name_t_acc *acc);

ssize_t field_name_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_name_t_pd *pd,field_name_t *rep);

ssize_t field_name_t_write2io (P_t *pads,Sfio_t *io,field_name_t_pd *pd,field_name_t *rep);

ssize_t field_name_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_name_t_pd *pd,field_name_t *rep,char const *_tag,int indent);

ssize_t field_name_t_write_xml_2io (P_t *pads,Sfio_t *io,field_name_t_pd *pd,field_name_t *rep,char const *_tag,int indent);

ssize_t field_name_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_name_t_m *m,field_name_t_pd *pd,field_name_t *rep);

ssize_t field_name_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_name_t_m *m,field_name_t_pd *pd,field_name_t *rep);

ssize_t field_name_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,field_name_t_m *m,field_name_t_pd *pd,field_name_t *rep);
typedef Pstring ws_t;
typedef struct ws_t_m_s ws_t_m;
typedef Pbase_pd ws_t_pd;
struct ws_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t ws_t_init (P_t *pads,ws_t *rep);

Perror_t ws_t_pd_init (P_t *pads,ws_t_pd *pd);

Perror_t ws_t_cleanup (P_t *pads,ws_t *rep);

Perror_t ws_t_pd_cleanup (P_t *pads,ws_t_pd *pd);

Perror_t ws_t_copy (P_t *pads,ws_t *rep_dst,ws_t *rep_src);

Perror_t ws_t_pd_copy (P_t *pads,ws_t_pd *pd_dst,ws_t_pd *pd_src);

void ws_t_m_init (P_t *pads,ws_t_m *mask,Pbase_m baseMask);

Perror_t ws_t_m_rec_init (P_t *pads,ws_t_m *mask,Pbase_m baseMask);

Perror_t ws_t_read (P_t *pads,ws_t_m *m,ws_t_pd *pd,ws_t *rep);

int ws_t_verify (P_t *pads,ws_t *rep);

int ws_t_genPD (P_t *pads,ws_t *rep,ws_t_pd *pd);
typedef Pstring_acc ws_t_acc;

Perror_t ws_t_acc_init (P_t *pads,ws_t_acc *acc);

Perror_t ws_t_acc_reset (P_t *pads,ws_t_acc *acc);

Perror_t ws_t_acc_cleanup (P_t *pads,ws_t_acc *acc);

Perror_t ws_t_acc_add (P_t *pads,ws_t_acc *acc,ws_t_pd *pd,ws_t *rep);

Perror_t ws_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,ws_t_acc *acc);

Perror_t ws_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,ws_t_acc *acc);

Perror_t ws_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,ws_t_acc *acc);

ssize_t ws_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,ws_t_pd *pd,ws_t *rep);

ssize_t ws_t_write2io (P_t *pads,Sfio_t *io,ws_t_pd *pd,ws_t *rep);

ssize_t ws_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,ws_t_pd *pd,ws_t *rep,char const *_tag,int indent);

ssize_t ws_t_write_xml_2io (P_t *pads,Sfio_t *io,ws_t_pd *pd,ws_t *rep,char const *_tag,int indent);

ssize_t ws_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,ws_t_m *m,ws_t_pd *pd,ws_t *rep);

ssize_t ws_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,ws_t_m *m,ws_t_pd *pd,ws_t *rep);

ssize_t ws_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,ws_t_m *m,ws_t_pd *pd,ws_t *rep);
typedef Pstring field_content0_t;
typedef struct field_content0_t_m_s field_content0_t_m;
typedef Pbase_pd field_content0_t_pd;
struct field_content0_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t field_content0_t_init (P_t *pads,field_content0_t *rep);

Perror_t field_content0_t_pd_init (P_t *pads,field_content0_t_pd *pd);

Perror_t field_content0_t_cleanup (P_t *pads,field_content0_t *rep);

Perror_t field_content0_t_pd_cleanup (P_t *pads,field_content0_t_pd *pd);

Perror_t field_content0_t_copy (P_t *pads,field_content0_t *rep_dst,field_content0_t *rep_src);

Perror_t field_content0_t_pd_copy (P_t *pads,field_content0_t_pd *pd_dst,field_content0_t_pd *pd_src);

void field_content0_t_m_init (P_t *pads,field_content0_t_m *mask,Pbase_m baseMask);

Perror_t field_content0_t_m_rec_init (P_t *pads,field_content0_t_m *mask,Pbase_m baseMask);

Perror_t field_content0_t_read (P_t *pads,field_content0_t_m *m,field_content0_t_pd *pd,field_content0_t *rep);

int field_content0_t_verify (P_t *pads,field_content0_t *rep);

int field_content0_t_genPD (P_t *pads,field_content0_t *rep,field_content0_t_pd *pd);
typedef Pstring_acc field_content0_t_acc;

Perror_t field_content0_t_acc_init (P_t *pads,field_content0_t_acc *acc);

Perror_t field_content0_t_acc_reset (P_t *pads,field_content0_t_acc *acc);

Perror_t field_content0_t_acc_cleanup (P_t *pads,field_content0_t_acc *acc);

Perror_t field_content0_t_acc_add (P_t *pads,field_content0_t_acc *acc,field_content0_t_pd *pd,field_content0_t *rep);

Perror_t field_content0_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,field_content0_t_acc *acc);

Perror_t field_content0_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,field_content0_t_acc *acc);

Perror_t field_content0_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,field_content0_t_acc *acc);

ssize_t field_content0_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_content0_t_pd *pd,field_content0_t *rep);

ssize_t field_content0_t_write2io (P_t *pads,Sfio_t *io,field_content0_t_pd *pd,field_content0_t *rep);

ssize_t field_content0_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_content0_t_pd *pd,field_content0_t *rep,char const *_tag,int indent);

ssize_t field_content0_t_write_xml_2io (P_t *pads,Sfio_t *io,field_content0_t_pd *pd,field_content0_t *rep,char const *_tag,int indent);

ssize_t field_content0_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_content0_t_m *m,field_content0_t_pd *pd,field_content0_t *rep);

ssize_t field_content0_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_content0_t_m *m,field_content0_t_pd *pd,field_content0_t *rep);

ssize_t field_content0_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,field_content0_t_m *m,field_content0_t_pd *pd,field_content0_t *rep);
typedef Pstring field_content_t;
typedef struct field_content_t_m_s field_content_t_m;
typedef Pbase_pd field_content_t_pd;
struct field_content_t_m_s {
  Pbase_m base;		/* Base mask */
  Pbase_m compoundLevel;		/* Typedef mask */
};

Perror_t field_content_t_init (P_t *pads,field_content_t *rep);

Perror_t field_content_t_pd_init (P_t *pads,field_content_t_pd *pd);

Perror_t field_content_t_cleanup (P_t *pads,field_content_t *rep);

Perror_t field_content_t_pd_cleanup (P_t *pads,field_content_t_pd *pd);

Perror_t field_content_t_copy (P_t *pads,field_content_t *rep_dst,field_content_t *rep_src);

Perror_t field_content_t_pd_copy (P_t *pads,field_content_t_pd *pd_dst,field_content_t_pd *pd_src);

void field_content_t_m_init (P_t *pads,field_content_t_m *mask,Pbase_m baseMask);

Perror_t field_content_t_m_rec_init (P_t *pads,field_content_t_m *mask,Pbase_m baseMask);

Perror_t field_content_t_read (P_t *pads,field_content_t_m *m,field_content_t_pd *pd,field_content_t *rep);

int field_content_t_verify (P_t *pads,field_content_t *rep);

int field_content_t_genPD (P_t *pads,field_content_t *rep,field_content_t_pd *pd);
typedef Pstring_acc field_content_t_acc;

Perror_t field_content_t_acc_init (P_t *pads,field_content_t_acc *acc);

Perror_t field_content_t_acc_reset (P_t *pads,field_content_t_acc *acc);

Perror_t field_content_t_acc_cleanup (P_t *pads,field_content_t_acc *acc);

Perror_t field_content_t_acc_add (P_t *pads,field_content_t_acc *acc,field_content_t_pd *pd,field_content_t *rep);

Perror_t field_content_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,field_content_t_acc *acc);

Perror_t field_content_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,field_content_t_acc *acc);

Perror_t field_content_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,field_content_t_acc *acc);

ssize_t field_content_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_content_t_pd *pd,field_content_t *rep);

ssize_t field_content_t_write2io (P_t *pads,Sfio_t *io,field_content_t_pd *pd,field_content_t *rep);

ssize_t field_content_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_content_t_pd *pd,field_content_t *rep,char const *_tag,int indent);

ssize_t field_content_t_write_xml_2io (P_t *pads,Sfio_t *io,field_content_t_pd *pd,field_content_t *rep,char const *_tag,int indent);

ssize_t field_content_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_content_t_m *m,field_content_t_pd *pd,field_content_t *rep);

ssize_t field_content_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_content_t_m *m,field_content_t_pd *pd,field_content_t *rep);

ssize_t field_content_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,field_content_t_m *m,field_content_t_pd *pd,field_content_t *rep);
typedef enum _bnf_1_t_tag_e _bnf_1_t_tag;
typedef union _bnf_1_t_u_u _bnf_1_t_u;
typedef struct _bnf_1_t_s _bnf_1_t;
typedef struct _bnf_1_t_m_s _bnf_1_t_m;
typedef union _bnf_1_t_pd_u_u _bnf_1_t_pd_u;
typedef struct _bnf_1_t_pd_s _bnf_1_t_pd;
enum _bnf_1_t_tag_e {
  _bnf_1_t_err=0,
  field_content=1,
  LWS=2
  };
union _bnf_1_t_pd_u_u {
  field_content_t_pd field_content;
  LWS_t_pd LWS;
};
struct _bnf_1_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  _bnf_1_t_tag tag;
  _bnf_1_t_pd_u val;
};
union _bnf_1_t_u_u {
  field_content_t field_content;
  LWS_t LWS;
};
struct _bnf_1_t_s {
  _bnf_1_t_tag tag;
  _bnf_1_t_u val;
};
struct _bnf_1_t_m_s {
  Pbase_m compoundLevel;
  field_content_t_m field_content;		/* nested constraints */
  LWS_t_m LWS;		/* nested constraints */
};

ssize_t _bnf_1_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_1_t_pd *pd,_bnf_1_t *rep);

ssize_t _bnf_1_t_write2io (P_t *pads,Sfio_t *io,_bnf_1_t_pd *pd,_bnf_1_t *rep);

ssize_t _bnf_1_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_1_t_pd *pd,_bnf_1_t *rep,char const *_tag,int indent);

ssize_t _bnf_1_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_1_t_pd *pd,_bnf_1_t *rep,char const *_tag,int indent);

char const *_bnf_1_t_tag2str (_bnf_1_t_tag which);

Perror_t _bnf_1_t_init (P_t *pads,_bnf_1_t *rep);

Perror_t _bnf_1_t_pd_init (P_t *pads,_bnf_1_t_pd *pd);

Perror_t _bnf_1_t_cleanup (P_t *pads,_bnf_1_t *rep);

Perror_t _bnf_1_t_pd_cleanup (P_t *pads,_bnf_1_t_pd *pd);

Perror_t _bnf_1_t_copy (P_t *pads,_bnf_1_t *rep_dst,_bnf_1_t *rep_src);

Perror_t _bnf_1_t_pd_copy (P_t *pads,_bnf_1_t_pd *pd_dst,_bnf_1_t_pd *pd_src);

void _bnf_1_t_m_init (P_t *pads,_bnf_1_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_1_t_m_rec_init (P_t *pads,_bnf_1_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_1_t_read (P_t *pads,_bnf_1_t_m *m,_bnf_1_t_pd *pd,_bnf_1_t *rep);

int _bnf_1_t_verify (P_t *pads,_bnf_1_t *rep);

int _bnf_1_t_genPD (P_t *pads,_bnf_1_t *rep,_bnf_1_t_pd *pd);
typedef struct _bnf_1_t_acc_s _bnf_1_t_acc;
struct _bnf_1_t_acc_s {
  Pint32_acc tag;
  field_content_t_acc field_content;
  LWS_t_acc LWS;
};

Perror_t _bnf_1_t_acc_init (P_t *pads,_bnf_1_t_acc *acc);

Perror_t _bnf_1_t_acc_reset (P_t *pads,_bnf_1_t_acc *acc);

Perror_t _bnf_1_t_acc_cleanup (P_t *pads,_bnf_1_t_acc *acc);

Perror_t _bnf_1_t_acc_add (P_t *pads,_bnf_1_t_acc *acc,_bnf_1_t_pd *pd,_bnf_1_t *rep);

Perror_t _bnf_1_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_1_t_acc *acc);

Perror_t _bnf_1_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_1_t_acc *acc);

Perror_t _bnf_1_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_1_t_acc *acc);

ssize_t _bnf_1_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_1_t_m *m,_bnf_1_t_pd *pd,_bnf_1_t *rep);

ssize_t _bnf_1_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_1_t_m *m,_bnf_1_t_pd *pd,_bnf_1_t *rep);

ssize_t _bnf_1_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_1_t_m *m,_bnf_1_t_pd *pd,_bnf_1_t *rep);
typedef enum _bnf_3_t_tag_e _bnf_3_t_tag;
typedef union _bnf_3_t_u_u _bnf_3_t_u;
typedef struct _bnf_3_t_s _bnf_3_t;
typedef struct _bnf_3_t_m_s _bnf_3_t_m;
typedef union _bnf_3_t_pd_u_u _bnf_3_t_pd_u;
typedef struct _bnf_3_t_pd_s _bnf_3_t_pd;
enum _bnf_3_t_tag_e {
  _bnf_3_t_err=0,
  _bnf_5=1,
  _bnf_6=2
  };
union _bnf_3_t_pd_u_u {
  field_content_t_pd _bnf_5;
  LWS_t_pd _bnf_6;
};
struct _bnf_3_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  _bnf_3_t_tag tag;
  _bnf_3_t_pd_u val;
};
union _bnf_3_t_u_u {
  field_content_t _bnf_5;
  LWS_t _bnf_6;
};
struct _bnf_3_t_s {
  _bnf_3_t_tag tag;
  _bnf_3_t_u val;
};
struct _bnf_3_t_m_s {
  Pbase_m compoundLevel;
  field_content_t_m _bnf_5;		/* nested constraints */
  LWS_t_m _bnf_6;		/* nested constraints */
};

ssize_t _bnf_3_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_3_t_pd *pd,_bnf_3_t *rep);

ssize_t _bnf_3_t_write2io (P_t *pads,Sfio_t *io,_bnf_3_t_pd *pd,_bnf_3_t *rep);

ssize_t _bnf_3_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_3_t_pd *pd,_bnf_3_t *rep,char const *_tag,int indent);

ssize_t _bnf_3_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_3_t_pd *pd,_bnf_3_t *rep,char const *_tag,int indent);

char const *_bnf_3_t_tag2str (_bnf_3_t_tag which);

Perror_t _bnf_3_t_init (P_t *pads,_bnf_3_t *rep);

Perror_t _bnf_3_t_pd_init (P_t *pads,_bnf_3_t_pd *pd);

Perror_t _bnf_3_t_cleanup (P_t *pads,_bnf_3_t *rep);

Perror_t _bnf_3_t_pd_cleanup (P_t *pads,_bnf_3_t_pd *pd);

Perror_t _bnf_3_t_copy (P_t *pads,_bnf_3_t *rep_dst,_bnf_3_t *rep_src);

Perror_t _bnf_3_t_pd_copy (P_t *pads,_bnf_3_t_pd *pd_dst,_bnf_3_t_pd *pd_src);

void _bnf_3_t_m_init (P_t *pads,_bnf_3_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_3_t_m_rec_init (P_t *pads,_bnf_3_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_3_t_read (P_t *pads,_bnf_3_t_m *m,_bnf_3_t_pd *pd,_bnf_3_t *rep);

int _bnf_3_t_verify (P_t *pads,_bnf_3_t *rep);

int _bnf_3_t_genPD (P_t *pads,_bnf_3_t *rep,_bnf_3_t_pd *pd);
typedef struct _bnf_3_t_acc_s _bnf_3_t_acc;
struct _bnf_3_t_acc_s {
  Pint32_acc tag;
  field_content_t_acc _bnf_5;
  LWS_t_acc _bnf_6;
};

Perror_t _bnf_3_t_acc_init (P_t *pads,_bnf_3_t_acc *acc);

Perror_t _bnf_3_t_acc_reset (P_t *pads,_bnf_3_t_acc *acc);

Perror_t _bnf_3_t_acc_cleanup (P_t *pads,_bnf_3_t_acc *acc);

Perror_t _bnf_3_t_acc_add (P_t *pads,_bnf_3_t_acc *acc,_bnf_3_t_pd *pd,_bnf_3_t *rep);

Perror_t _bnf_3_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_3_t_acc *acc);

Perror_t _bnf_3_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_3_t_acc *acc);

Perror_t _bnf_3_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_3_t_acc *acc);

ssize_t _bnf_3_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_3_t_m *m,_bnf_3_t_pd *pd,_bnf_3_t *rep);

ssize_t _bnf_3_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_3_t_m *m,_bnf_3_t_pd *pd,_bnf_3_t *rep);

ssize_t _bnf_3_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_3_t_m *m,_bnf_3_t_pd *pd,_bnf_3_t *rep);
typedef struct _bnf_7_t_s _bnf_7_t;
typedef struct _bnf_7_t_m_s _bnf_7_t_m;
typedef struct _bnf_7_t_pd_s _bnf_7_t_pd;
struct _bnf_7_t_m_s {
  Pbase_m compoundLevel;
  ws_t_m ws;		/* nested constraints */
  _bnf_3_t_m _bnf_3;		/* nested constraints */
};
struct _bnf_7_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  ws_t_pd ws;
  _bnf_3_t_pd _bnf_3;
};
struct _bnf_7_t_s {
  ws_t ws;
  _bnf_3_t _bnf_3;
};

Perror_t _bnf_7_t_init (P_t *pads,_bnf_7_t *rep);

Perror_t _bnf_7_t_pd_init (P_t *pads,_bnf_7_t_pd *pd);

Perror_t _bnf_7_t_cleanup (P_t *pads,_bnf_7_t *rep);

Perror_t _bnf_7_t_pd_cleanup (P_t *pads,_bnf_7_t_pd *pd);

Perror_t _bnf_7_t_copy (P_t *pads,_bnf_7_t *rep_dst,_bnf_7_t *rep_src);

Perror_t _bnf_7_t_pd_copy (P_t *pads,_bnf_7_t_pd *pd_dst,_bnf_7_t_pd *pd_src);

void _bnf_7_t_m_init (P_t *pads,_bnf_7_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_7_t_m_rec_init (P_t *pads,_bnf_7_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_7_t_read (P_t *pads,_bnf_7_t_m *m,_bnf_7_t_pd *pd,_bnf_7_t *rep);

int _bnf_7_t_verify (P_t *pads,_bnf_7_t *rep);

int _bnf_7_t_genPD (P_t *pads,_bnf_7_t *rep,_bnf_7_t_pd *pd);
typedef struct _bnf_7_t_acc_s _bnf_7_t_acc;
struct _bnf_7_t_acc_s {
  Puint32_acc nerr;
  ws_t_acc ws;
  _bnf_3_t_acc _bnf_3;
};

Perror_t _bnf_7_t_acc_init (P_t *pads,_bnf_7_t_acc *acc);

Perror_t _bnf_7_t_acc_reset (P_t *pads,_bnf_7_t_acc *acc);

Perror_t _bnf_7_t_acc_cleanup (P_t *pads,_bnf_7_t_acc *acc);

Perror_t _bnf_7_t_acc_add (P_t *pads,_bnf_7_t_acc *acc,_bnf_7_t_pd *pd,_bnf_7_t *rep);

Perror_t _bnf_7_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_7_t_acc *acc);

Perror_t _bnf_7_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_7_t_acc *acc);

Perror_t _bnf_7_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_7_t_acc *acc);

ssize_t _bnf_7_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_7_t_pd *pd,_bnf_7_t *rep);

ssize_t _bnf_7_t_write2io (P_t *pads,Sfio_t *io,_bnf_7_t_pd *pd,_bnf_7_t *rep);

ssize_t _bnf_7_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_7_t_pd *pd,_bnf_7_t *rep,char const *_tag,int indent);

ssize_t _bnf_7_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_7_t_pd *pd,_bnf_7_t *rep,char const *_tag,int indent);

ssize_t _bnf_7_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_7_t_m *m,_bnf_7_t_pd *pd,_bnf_7_t *rep);

ssize_t _bnf_7_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_7_t_m *m,_bnf_7_t_pd *pd,_bnf_7_t *rep);

ssize_t _bnf_7_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_7_t_m *m,_bnf_7_t_pd *pd,_bnf_7_t *rep);
typedef struct _bnf_2_t_s _bnf_2_t;
typedef struct _bnf_2_t_m_s _bnf_2_t_m;
typedef struct _bnf_2_t_pd_s _bnf_2_t_pd;
typedef struct _bnf_2_t_ro_params_t_s _bnf_2_t_ro_params_t;
struct _bnf_2_t_m_s {
  _bnf_7_t_m element;		/* per-element */
  Pbase_m compoundLevel;		/* entire array */
};
struct _bnf_2_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;		/* Number of array errors */
  PerrCode_t errCode;
  Ploc_t loc;
  Puint32 neerr;		/* Number of element errors */
  Puint32 firstError;		/* if errCode == ARRAY_ELEM_ERR, index of first error */
  Puint32 numRead;		/* Number of elements read */
  Puint32 length;		/* Number of elements in memory */
  _bnf_7_t_pd *elts;
  RBuf_t *_internal;
};
struct _bnf_2_t_s {
  Puint32 length;
  _bnf_7_t *elts;
  RBuf_t *_internal;
};
struct _bnf_2_t_ro_params_t_s {
  Ploc_t beginLoc;		/* location of array beginning */
};

Perror_t _bnf_2_t_init (P_t *pads,_bnf_2_t *rep);

Perror_t _bnf_2_t_pd_init (P_t *pads,_bnf_2_t_pd *pd);

Perror_t _bnf_2_t_cleanup (P_t *pads,_bnf_2_t *rep);

Perror_t _bnf_2_t_pd_cleanup (P_t *pads,_bnf_2_t_pd *pd);

Perror_t _bnf_2_t_copy (P_t *pads,_bnf_2_t *rep_dst,_bnf_2_t *rep_src);

Perror_t _bnf_2_t_pd_copy (P_t *pads,_bnf_2_t_pd *pd_dst,_bnf_2_t_pd *pd_src);

void _bnf_2_t_m_init (P_t *pads,_bnf_2_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_2_t_m_rec_init (P_t *pads,_bnf_2_t_m *mask,Pbase_m baseMask);

void _bnf_2_t_ro_params_init (_bnf_2_t_ro_params_t *params);

Pread_res_t _bnf_2_t_final_checks (P_t *pads,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep,Ploc_t *loc_ptr,int consume);

Pread_res_t _bnf_2_t_read_one_init (P_t *pads,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep,Ploc_t *loc_ptr);

Pread_res_t _bnf_2_t_read_one (P_t *pads,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep,Ploc_t *loc_ptr,_bnf_7_t_pd *elt_pd,_bnf_7_t *elt_rep);

Perror_t _bnf_2_t_read (P_t *pads,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep);

Pread_res_t _bnf_2_t_reread_one (P_t *pads,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep,Ploc_t *loc_ptr,_bnf_7_t_pd *elt_pd,_bnf_7_t *elt_rep,int notFirstElt);

int _bnf_2_t_verify (P_t *pads,_bnf_2_t *rep);

int _bnf_2_t_genPD (P_t *pads,_bnf_2_t *rep,_bnf_2_t_pd *pd);
typedef struct _bnf_2_t_acc_s _bnf_2_t_acc;
struct _bnf_2_t_acc_s {
  Puint32_acc length;		/* Accumulator for array length */
  _bnf_7_t_acc compoundLevel;		/* Accumulator for all array elements */
  _bnf_7_t_acc arrayDetail[10];		/* Accumulator for first 10 array elements */
};

Perror_t _bnf_2_t_acc_init (P_t *pads,_bnf_2_t_acc *acc);

Perror_t _bnf_2_t_acc_reset (P_t *pads,_bnf_2_t_acc *acc);

Perror_t _bnf_2_t_acc_cleanup (P_t *pads,_bnf_2_t_acc *acc);

Perror_t _bnf_2_t_acc_add (P_t *pads,_bnf_2_t_acc *acc,_bnf_2_t_pd *pd,_bnf_2_t *rep);

Perror_t _bnf_2_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_2_t_acc *acc);

Perror_t _bnf_2_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_2_t_acc *acc);

Perror_t _bnf_2_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_2_t_acc *acc);

ssize_t _bnf_2_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_2_t_pd *pd,_bnf_2_t *rep);

ssize_t _bnf_2_t_write2io (P_t *pads,Sfio_t *io,_bnf_2_t_pd *pd,_bnf_2_t *rep);

ssize_t _bnf_2_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_2_t_pd *pd,_bnf_2_t *rep,char const *_tag,int indent);

ssize_t _bnf_2_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_2_t_pd *pd,_bnf_2_t *rep,char const *_tag,int indent);

ssize_t _bnf_2_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep);

ssize_t _bnf_2_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep);

ssize_t _bnf_2_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_2_t_m *m,_bnf_2_t_pd *pd,_bnf_2_t *rep);
typedef struct _bnf_0_t_s _bnf_0_t;
typedef struct _bnf_0_t_m_s _bnf_0_t_m;
typedef struct _bnf_0_t_pd_s _bnf_0_t_pd;
struct _bnf_0_t_m_s {
  Pbase_m compoundLevel;
  _bnf_1_t_m _bnf_1;		/* nested constraints */
  _bnf_2_t_m _bnf_2;		/* nested constraints */
};
struct _bnf_0_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  _bnf_1_t_pd _bnf_1;
  _bnf_2_t_pd _bnf_2;
};
struct _bnf_0_t_s {
  _bnf_1_t _bnf_1;
  _bnf_2_t _bnf_2;
};

Perror_t _bnf_0_t_init (P_t *pads,_bnf_0_t *rep);

Perror_t _bnf_0_t_pd_init (P_t *pads,_bnf_0_t_pd *pd);

Perror_t _bnf_0_t_cleanup (P_t *pads,_bnf_0_t *rep);

Perror_t _bnf_0_t_pd_cleanup (P_t *pads,_bnf_0_t_pd *pd);

Perror_t _bnf_0_t_copy (P_t *pads,_bnf_0_t *rep_dst,_bnf_0_t *rep_src);

Perror_t _bnf_0_t_pd_copy (P_t *pads,_bnf_0_t_pd *pd_dst,_bnf_0_t_pd *pd_src);

void _bnf_0_t_m_init (P_t *pads,_bnf_0_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_0_t_m_rec_init (P_t *pads,_bnf_0_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_0_t_read (P_t *pads,_bnf_0_t_m *m,_bnf_0_t_pd *pd,_bnf_0_t *rep);

int _bnf_0_t_verify (P_t *pads,_bnf_0_t *rep);

int _bnf_0_t_genPD (P_t *pads,_bnf_0_t *rep,_bnf_0_t_pd *pd);
typedef struct _bnf_0_t_acc_s _bnf_0_t_acc;
struct _bnf_0_t_acc_s {
  Puint32_acc nerr;
  _bnf_1_t_acc _bnf_1;
  _bnf_2_t_acc _bnf_2;
};

Perror_t _bnf_0_t_acc_init (P_t *pads,_bnf_0_t_acc *acc);

Perror_t _bnf_0_t_acc_reset (P_t *pads,_bnf_0_t_acc *acc);

Perror_t _bnf_0_t_acc_cleanup (P_t *pads,_bnf_0_t_acc *acc);

Perror_t _bnf_0_t_acc_add (P_t *pads,_bnf_0_t_acc *acc,_bnf_0_t_pd *pd,_bnf_0_t *rep);

Perror_t _bnf_0_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_0_t_acc *acc);

Perror_t _bnf_0_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_0_t_acc *acc);

Perror_t _bnf_0_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_0_t_acc *acc);

ssize_t _bnf_0_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_0_t_pd *pd,_bnf_0_t *rep);

ssize_t _bnf_0_t_write2io (P_t *pads,Sfio_t *io,_bnf_0_t_pd *pd,_bnf_0_t *rep);

ssize_t _bnf_0_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_0_t_pd *pd,_bnf_0_t *rep,char const *_tag,int indent);

ssize_t _bnf_0_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_0_t_pd *pd,_bnf_0_t *rep,char const *_tag,int indent);

ssize_t _bnf_0_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_0_t_m *m,_bnf_0_t_pd *pd,_bnf_0_t *rep);

ssize_t _bnf_0_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_0_t_m *m,_bnf_0_t_pd *pd,_bnf_0_t *rep);

ssize_t _bnf_0_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_0_t_m *m,_bnf_0_t_pd *pd,_bnf_0_t *rep);
typedef enum field_value_t_tag_e field_value_t_tag;
typedef union field_value_t_u_u field_value_t_u;
typedef struct field_value_t_s field_value_t;
typedef struct field_value_t_m_s field_value_t_m;
typedef union field_value_t_pd_u_u field_value_t_pd_u;
typedef struct field_value_t_pd_s field_value_t_pd;
enum field_value_t_tag_e {
  field_value_t_err=0,
  _bnf_0=1,
  _bnf_8=2
  };
union field_value_t_pd_u_u {
  _bnf_0_t_pd _bnf_0;
  Pbase_pd _bnf_8;		/* _bnf_8 = 0 */
};
struct field_value_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  field_value_t_tag tag;
  field_value_t_pd_u val;
};
union field_value_t_u_u {
  _bnf_0_t _bnf_0;
};
struct field_value_t_s {
  field_value_t_tag tag;
  field_value_t_u val;
};
struct field_value_t_m_s {
  Pbase_m compoundLevel;
  _bnf_0_t_m _bnf_0;		/* nested constraints */
  Pbase_m _bnf_8;		/* nested constraints */
};

ssize_t field_value_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_value_t_pd *pd,field_value_t *rep);

ssize_t field_value_t_write2io (P_t *pads,Sfio_t *io,field_value_t_pd *pd,field_value_t *rep);

ssize_t field_value_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,field_value_t_pd *pd,field_value_t *rep,char const *_tag,int indent);

ssize_t field_value_t_write_xml_2io (P_t *pads,Sfio_t *io,field_value_t_pd *pd,field_value_t *rep,char const *_tag,int indent);

char const *field_value_t_tag2str (field_value_t_tag which);

Perror_t field_value_t_init (P_t *pads,field_value_t *rep);

Perror_t field_value_t_pd_init (P_t *pads,field_value_t_pd *pd);

Perror_t field_value_t_cleanup (P_t *pads,field_value_t *rep);

Perror_t field_value_t_pd_cleanup (P_t *pads,field_value_t_pd *pd);

Perror_t field_value_t_copy (P_t *pads,field_value_t *rep_dst,field_value_t *rep_src);

Perror_t field_value_t_pd_copy (P_t *pads,field_value_t_pd *pd_dst,field_value_t_pd *pd_src);

void field_value_t_m_init (P_t *pads,field_value_t_m *mask,Pbase_m baseMask);

Perror_t field_value_t_m_rec_init (P_t *pads,field_value_t_m *mask,Pbase_m baseMask);

Perror_t field_value_t_read (P_t *pads,field_value_t_m *m,field_value_t_pd *pd,field_value_t *rep);

int field_value_t_verify (P_t *pads,field_value_t *rep);

int field_value_t_genPD (P_t *pads,field_value_t *rep,field_value_t_pd *pd);
typedef struct field_value_t_acc_s field_value_t_acc;
struct field_value_t_acc_s {
  Pint32_acc tag;
  _bnf_0_t_acc _bnf_0;
};

Perror_t field_value_t_acc_init (P_t *pads,field_value_t_acc *acc);

Perror_t field_value_t_acc_reset (P_t *pads,field_value_t_acc *acc);

Perror_t field_value_t_acc_cleanup (P_t *pads,field_value_t_acc *acc);

Perror_t field_value_t_acc_add (P_t *pads,field_value_t_acc *acc,field_value_t_pd *pd,field_value_t *rep);

Perror_t field_value_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,field_value_t_acc *acc);

Perror_t field_value_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,field_value_t_acc *acc);

Perror_t field_value_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,field_value_t_acc *acc);

ssize_t field_value_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_value_t_m *m,field_value_t_pd *pd,field_value_t *rep);

ssize_t field_value_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,field_value_t_m *m,field_value_t_pd *pd,field_value_t *rep);

ssize_t field_value_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,field_value_t_m *m,field_value_t_pd *pd,field_value_t *rep);
typedef enum _bnf_4_t_tag_e _bnf_4_t_tag;
typedef union _bnf_4_t_u_u _bnf_4_t_u;
typedef struct _bnf_4_t_s _bnf_4_t;
typedef struct _bnf_4_t_m_s _bnf_4_t_m;
typedef union _bnf_4_t_pd_u_u _bnf_4_t_pd_u;
typedef struct _bnf_4_t_pd_s _bnf_4_t_pd;
enum _bnf_4_t_tag_e {
  _bnf_4_t_err=0,
  field_value=1,
  _bnf_9=2
  };
union _bnf_4_t_pd_u_u {
  field_value_t_pd field_value;
  Pbase_pd _bnf_9;		/* _bnf_9 = 0 */
};
struct _bnf_4_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  _bnf_4_t_tag tag;
  _bnf_4_t_pd_u val;
};
union _bnf_4_t_u_u {
  field_value_t field_value;
};
struct _bnf_4_t_s {
  _bnf_4_t_tag tag;
  _bnf_4_t_u val;
};
struct _bnf_4_t_m_s {
  Pbase_m compoundLevel;
  field_value_t_m field_value;		/* nested constraints */
  Pbase_m _bnf_9;		/* nested constraints */
};

ssize_t _bnf_4_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_4_t_pd *pd,_bnf_4_t *rep);

ssize_t _bnf_4_t_write2io (P_t *pads,Sfio_t *io,_bnf_4_t_pd *pd,_bnf_4_t *rep);

ssize_t _bnf_4_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,_bnf_4_t_pd *pd,_bnf_4_t *rep,char const *_tag,int indent);

ssize_t _bnf_4_t_write_xml_2io (P_t *pads,Sfio_t *io,_bnf_4_t_pd *pd,_bnf_4_t *rep,char const *_tag,int indent);

char const *_bnf_4_t_tag2str (_bnf_4_t_tag which);

Perror_t _bnf_4_t_init (P_t *pads,_bnf_4_t *rep);

Perror_t _bnf_4_t_pd_init (P_t *pads,_bnf_4_t_pd *pd);

Perror_t _bnf_4_t_cleanup (P_t *pads,_bnf_4_t *rep);

Perror_t _bnf_4_t_pd_cleanup (P_t *pads,_bnf_4_t_pd *pd);

Perror_t _bnf_4_t_copy (P_t *pads,_bnf_4_t *rep_dst,_bnf_4_t *rep_src);

Perror_t _bnf_4_t_pd_copy (P_t *pads,_bnf_4_t_pd *pd_dst,_bnf_4_t_pd *pd_src);

void _bnf_4_t_m_init (P_t *pads,_bnf_4_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_4_t_m_rec_init (P_t *pads,_bnf_4_t_m *mask,Pbase_m baseMask);

Perror_t _bnf_4_t_read (P_t *pads,_bnf_4_t_m *m,_bnf_4_t_pd *pd,_bnf_4_t *rep);

int _bnf_4_t_verify (P_t *pads,_bnf_4_t *rep);

int _bnf_4_t_genPD (P_t *pads,_bnf_4_t *rep,_bnf_4_t_pd *pd);
typedef struct _bnf_4_t_acc_s _bnf_4_t_acc;
struct _bnf_4_t_acc_s {
  Pint32_acc tag;
  field_value_t_acc field_value;
};

Perror_t _bnf_4_t_acc_init (P_t *pads,_bnf_4_t_acc *acc);

Perror_t _bnf_4_t_acc_reset (P_t *pads,_bnf_4_t_acc *acc);

Perror_t _bnf_4_t_acc_cleanup (P_t *pads,_bnf_4_t_acc *acc);

Perror_t _bnf_4_t_acc_add (P_t *pads,_bnf_4_t_acc *acc,_bnf_4_t_pd *pd,_bnf_4_t *rep);

Perror_t _bnf_4_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,_bnf_4_t_acc *acc);

Perror_t _bnf_4_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,_bnf_4_t_acc *acc);

Perror_t _bnf_4_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,_bnf_4_t_acc *acc);

ssize_t _bnf_4_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_4_t_m *m,_bnf_4_t_pd *pd,_bnf_4_t *rep);

ssize_t _bnf_4_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,_bnf_4_t_m *m,_bnf_4_t_pd *pd,_bnf_4_t *rep);

ssize_t _bnf_4_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,_bnf_4_t_m *m,_bnf_4_t_pd *pd,_bnf_4_t *rep);
typedef struct message_header_t_s message_header_t;
typedef struct message_header_t_m_s message_header_t_m;
typedef struct message_header_t_pd_s message_header_t_pd;
struct message_header_t_m_s {
  Pbase_m compoundLevel;
  field_name_t_m field_name;		/* nested constraints */
  ws_t_m ws;		/* nested constraints */
  ws_t_m _bnf_10;		/* nested constraints */
  _bnf_4_t_m _bnf_4;		/* nested constraints */
};
struct message_header_t_pd_s {
  Pflags_t pstate;
  Puint32 nerr;
  PerrCode_t errCode;
  Ploc_t loc;
  field_name_t_pd field_name;
  ws_t_pd ws;
  ws_t_pd _bnf_10;
  _bnf_4_t_pd _bnf_4;
};
struct message_header_t_s {
  field_name_t field_name;
  ws_t ws;
  ws_t _bnf_10;
  _bnf_4_t _bnf_4;
};

Perror_t message_header_t_init (P_t *pads,message_header_t *rep);

Perror_t message_header_t_pd_init (P_t *pads,message_header_t_pd *pd);

Perror_t message_header_t_cleanup (P_t *pads,message_header_t *rep);

Perror_t message_header_t_pd_cleanup (P_t *pads,message_header_t_pd *pd);

Perror_t message_header_t_copy (P_t *pads,message_header_t *rep_dst,message_header_t *rep_src);

Perror_t message_header_t_pd_copy (P_t *pads,message_header_t_pd *pd_dst,message_header_t_pd *pd_src);

void message_header_t_m_init (P_t *pads,message_header_t_m *mask,Pbase_m baseMask);

Perror_t message_header_t_m_rec_init (P_t *pads,message_header_t_m *mask,Pbase_m baseMask);

Perror_t message_header_t_read (P_t *pads,message_header_t_m *m,message_header_t_pd *pd,message_header_t *rep);

int message_header_t_verify (P_t *pads,message_header_t *rep);

int message_header_t_genPD (P_t *pads,message_header_t *rep,message_header_t_pd *pd);
typedef struct message_header_t_acc_s message_header_t_acc;
struct message_header_t_acc_s {
  Puint32_acc nerr;
  field_name_t_acc field_name;
  ws_t_acc ws;
  ws_t_acc _bnf_10;
  _bnf_4_t_acc _bnf_4;
};

Perror_t message_header_t_acc_init (P_t *pads,message_header_t_acc *acc);

Perror_t message_header_t_acc_reset (P_t *pads,message_header_t_acc *acc);

Perror_t message_header_t_acc_cleanup (P_t *pads,message_header_t_acc *acc);

Perror_t message_header_t_acc_add (P_t *pads,message_header_t_acc *acc,message_header_t_pd *pd,message_header_t *rep);

Perror_t message_header_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,message_header_t_acc *acc);

Perror_t message_header_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,message_header_t_acc *acc);

Perror_t message_header_t_acc_report2xml_io (P_t *pads,Sfio_t *outstr,int nst,message_header_t_acc *acc);

ssize_t message_header_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,message_header_t_pd *pd,message_header_t *rep);

ssize_t message_header_t_write2io (P_t *pads,Sfio_t *io,message_header_t_pd *pd,message_header_t *rep);

ssize_t message_header_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,message_header_t_pd *pd,message_header_t *rep,char const *_tag,int indent);

ssize_t message_header_t_write_xml_2io (P_t *pads,Sfio_t *io,message_header_t_pd *pd,message_header_t *rep,char const *_tag,int indent);

ssize_t message_header_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,message_header_t_m *m,message_header_t_pd *pd,message_header_t *rep);

ssize_t message_header_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,message_header_t_m *m,message_header_t_pd *pd,message_header_t *rep);

ssize_t message_header_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,message_header_t_m *m,message_header_t_pd *pd,message_header_t *rep);

void P_lib_init ();

#endif /*  __MESSAGE_HEADER__H__  */
