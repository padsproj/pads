#include "pads-internal.h"
#include "pglx-internal.h"
char* PDCI_source = "dibbler_new.p";
#include "dibbler_new.h"
Perror_t pn_t_init (P_t *pads,pn_t *rep)
{
  return P_OK;
}
Perror_t pn_t_pd_init (P_t *pads,pn_t_pd *pd)
{
  return P_OK;
}
Perror_t pn_t_cleanup (P_t *pads,pn_t *rep)
{
  return P_OK;
}
Perror_t pn_t_pd_cleanup (P_t *pads,pn_t_pd *pd)
{
  return P_OK;
}
Perror_t pn_t_copy (P_t *pads,pn_t *rep_dst,pn_t *rep_src)
{
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(pn_t));
  return P_OK;
}
Perror_t pn_t_pd_copy (P_t *pads,pn_t_pd *pd_dst,pn_t_pd *pd_src)
{
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(pn_t_pd));
  return P_OK;
}
void pn_t_m_init (P_t *pads,pn_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(pn_t_m));
}
Perror_t pn_t_read (P_t *pads,pn_t_m *m,pn_t_pd *pd,pn_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("pn_t_read",m,pd,rep);
  PCGEN_TYPEDEF_READ ("pn_t_read",Puint64_read (pads,&(m->base),pd,rep));
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int pn_t_verify (pn_t *rep)
{
  return 1;
}
Perror_t pn_t_acc_init (P_t *pads,pn_t_acc *acc)
{
  return Puint64_acc_init (pads,acc);
}
Perror_t pn_t_acc_reset (P_t *pads,pn_t_acc *acc)
{
  return Puint64_acc_reset (pads,acc);
}
Perror_t pn_t_acc_cleanup (P_t *pads,pn_t_acc *acc)
{
  return Puint64_acc_cleanup (pads,acc);
}
Perror_t pn_t_acc_add (P_t *pads,pn_t_acc *acc,pn_t_pd *pd,pn_t *rep)
{
  return Puint64_acc_add (pads,acc,pd,rep);
}
Perror_t pn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,pn_t_acc *acc)
{
  PCGEN_TYPEDEF_ACC_REP2IO ("typedef pn_t","Puint64",Puint64_acc_report2io (pads,outstr,prefix,what,nst,acc));
}
Perror_t pn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,pn_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = pn_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t pn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,pn_t_pd *pd,pn_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("pn_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Puint64_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t pn_t_write2io (P_t *pads,Sfio_t *io,pn_t_pd *pd,pn_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("pn_t_write2io",pn_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t pn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,pn_t_pd *pd,pn_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("pn_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  if (!tag) 
    tag = "pn_t";
  tlen_PCGEN_ = Puint64_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep,tag,indent);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t pn_t_write_xml_2io (P_t *pads,Sfio_t *io,pn_t_pd *pd,pn_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("pn_t_write_xml_2io",pn_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t pn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_TYPEDEF_FMT2BUF_FINAL_INIT ("pn_t_fmt2buf_final");
  PCGEN_FMT2BUF_TYPEDEF (Puint64_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->base),pd,rep));
  return length_PCGEN_;
}
ssize_t pn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("pn_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"pn_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return pn_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t pn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,pn_t_m *m,pn_t_pd *pd,pn_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("pn_t_fmt2io",pn_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *pn_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (pn_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *pn_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (pn_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *pn_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_NODE_KTH_CHILD_BODY (pn_t,Puint64);
  return TYP_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *pn_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  TYP_NODE_KTH_CHILD_NAMED_BODY ();
  return TYP_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *pn_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (pn_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *pn_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (pn_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *pn_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_SND_NODE_KTH_CHILD_BODY (pn_t,Puint64);
  return TYP_SND_NODE_KTH_CHILD_RET ();
}
Perror_t pn_t_node_pathWalk (P_t *pads,pn_t_m *m,pn_t_pd *pd,pn_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  TYP_NODE_PATH_WALK_BODY (Puint64);
  return TYP_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const pn_t_node_vtable={pn_t_cachedNode_init,pn_t_node_kthChild,pn_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const pn_t_cachedNode_vtable={PDCI_error_cachedNode_init,pn_t_cachedNode_kthChild,pn_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const pn_t_sndNode_vtable={PDCI_error_cachedNode_init,pn_t_sndNode_kthChild,pn_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t zipSep_t_init (P_t *pads,zipSep_t *rep)
{
  return P_OK;
}
Perror_t zipSep_t_pd_init (P_t *pads,zipSep_t_pd *pd)
{
  return P_OK;
}
Perror_t zipSep_t_cleanup (P_t *pads,zipSep_t *rep)
{
  return P_OK;
}
Perror_t zipSep_t_pd_cleanup (P_t *pads,zipSep_t_pd *pd)
{
  return P_OK;
}
Perror_t zipSep_t_copy (P_t *pads,zipSep_t *rep_dst,zipSep_t *rep_src)
{
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(zipSep_t));
  return P_OK;
}
Perror_t zipSep_t_pd_copy (P_t *pads,zipSep_t_pd *pd_dst,zipSep_t_pd *pd_src)
{
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(zipSep_t_pd));
  return P_OK;
}
void zipSep_t_m_init (P_t *pads,zipSep_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(zipSep_t_m));
}
Perror_t zipSep_t_read (P_t *pads,zipSep_t_m *m,zipSep_t_pd *pd,zipSep_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("zipSep_t_read",m,pd,rep);
  PCGEN_TYPEDEF_READ_CHECK ("zipSep_t_read",Pchar_read (pads,&(m->base),pd,rep),(((*rep)==45)||((*rep)==47))||((*rep)==32));
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int zipSep_t_verify (zipSep_t *rep)
{
  return (((*rep)==45)||((*rep)==47))||((*rep)==32);
}
Perror_t zipSep_t_acc_init (P_t *pads,zipSep_t_acc *acc)
{
  return Pchar_acc_init (pads,acc);
}
Perror_t zipSep_t_acc_reset (P_t *pads,zipSep_t_acc *acc)
{
  return Pchar_acc_reset (pads,acc);
}
Perror_t zipSep_t_acc_cleanup (P_t *pads,zipSep_t_acc *acc)
{
  return Pchar_acc_cleanup (pads,acc);
}
Perror_t zipSep_t_acc_add (P_t *pads,zipSep_t_acc *acc,zipSep_t_pd *pd,zipSep_t *rep)
{
  return Pchar_acc_add (pads,acc,pd,rep);
}
Perror_t zipSep_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,zipSep_t_acc *acc)
{
  PCGEN_TYPEDEF_ACC_REP2IO ("typedef zipSep_t","Pchar",Pchar_acc_report2io (pads,outstr,prefix,what,nst,acc));
}
Perror_t zipSep_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,zipSep_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = zipSep_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t zipSep_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zipSep_t_pd *pd,zipSep_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("zipSep_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pchar_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t zipSep_t_write2io (P_t *pads,Sfio_t *io,zipSep_t_pd *pd,zipSep_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zipSep_t_write2io",zipSep_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t zipSep_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zipSep_t_pd *pd,zipSep_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("zipSep_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  if (!tag) 
    tag = "zipSep_t";
  tlen_PCGEN_ = Pchar_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep,tag,indent);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t zipSep_t_write_xml_2io (P_t *pads,Sfio_t *io,zipSep_t_pd *pd,zipSep_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zipSep_t_write_xml_2io",zipSep_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t zipSep_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zipSep_t_m *m,zipSep_t_pd *pd,zipSep_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_TYPEDEF_FMT2BUF_FINAL_INIT ("zipSep_t_fmt2buf_final");
  PCGEN_FMT2BUF_TYPEDEF (Pchar_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->base),pd,rep));
  return length_PCGEN_;
}
ssize_t zipSep_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zipSep_t_m *m,zipSep_t_pd *pd,zipSep_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("zipSep_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"zipSep_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return zipSep_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t zipSep_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,zipSep_t_m *m,zipSep_t_pd *pd,zipSep_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zipSep_t_fmt2io",zipSep_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *zipSep_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (zipSep_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *zipSep_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (zipSep_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *zipSep_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_NODE_KTH_CHILD_BODY (zipSep_t,Pchar);
  return TYP_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *zipSep_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  TYP_NODE_KTH_CHILD_NAMED_BODY ();
  return TYP_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *zipSep_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (zipSep_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *zipSep_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (zipSep_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *zipSep_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_SND_NODE_KTH_CHILD_BODY (zipSep_t,Pchar);
  return TYP_SND_NODE_KTH_CHILD_RET ();
}
Perror_t zipSep_t_node_pathWalk (P_t *pads,zipSep_t_m *m,zipSep_t_pd *pd,zipSep_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  TYP_NODE_PATH_WALK_BODY (Pchar);
  return TYP_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const zipSep_t_node_vtable={zipSep_t_cachedNode_init,zipSep_t_node_kthChild,zipSep_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const zipSep_t_cachedNode_vtable={PDCI_error_cachedNode_init,zipSep_t_cachedNode_kthChild,zipSep_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const zipSep_t_sndNode_vtable={PDCI_error_cachedNode_init,zipSep_t_sndNode_kthChild,zipSep_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t extended_zip_t_init (P_t *pads,extended_zip_t *rep)
{
  return P_OK;
}
Perror_t extended_zip_t_pd_init (P_t *pads,extended_zip_t_pd *pd)
{
  return P_OK;
}
Perror_t extended_zip_t_cleanup (P_t *pads,extended_zip_t *rep)
{
  return P_OK;
}
Perror_t extended_zip_t_pd_cleanup (P_t *pads,extended_zip_t_pd *pd)
{
  return P_OK;
}
Perror_t extended_zip_t_copy (P_t *pads,extended_zip_t *rep_dst,extended_zip_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("extended_zip_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(extended_zip_t));
  return P_OK;
}
Perror_t extended_zip_t_pd_copy (P_t *pads,extended_zip_t_pd *pd_dst,extended_zip_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("extended_zip_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(extended_zip_t_pd));
  return P_OK;
}
void extended_zip_t_m_init (P_t *pads,extended_zip_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(extended_zip_t_m));
}
Perror_t extended_zip_t_read (P_t *pads,extended_zip_t_m *m,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("extended_zip_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'zip'
  PCGEN_STRUCT_READ_FIRST ("extended_zip_t_read",zip,Puint32_read (pads,&(m->zip),&(pd->zip),&(rep->zip)),_NOOP);
  // Read field 'sep'
  PCGEN_STRUCT_READ_NEXT ("extended_zip_t_read",sep,zipSep_t_read (pads,&(m->sep),&(pd->sep),&(rep->sep)),_NOOP);
  // Read field 'suffix'
  PCGEN_STRUCT_READ_NEXT ("extended_zip_t_read",suffix,Puint32_read (pads,&(m->suffix),&(pd->suffix),&(rep->suffix)),_NOOP);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int extended_zip_t_verify (extended_zip_t *rep)
{
  return zipSep_t_verify (&(rep->sep))&&1;
}
Perror_t extended_zip_t_acc_init (P_t *pads,extended_zip_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->zip))) 
    {
      nerr++;
    }
  if (P_ERR==zipSep_t_acc_init (pads,&(acc->sep))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->suffix))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t extended_zip_t_acc_reset (P_t *pads,extended_zip_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->zip))) 
    {
      nerr++;
    }
  if (P_ERR==zipSep_t_acc_reset (pads,&(acc->sep))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->suffix))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t extended_zip_t_acc_cleanup (P_t *pads,extended_zip_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->zip))) 
    {
      nerr++;
    }
  if (P_ERR==zipSep_t_acc_cleanup (pads,&(acc->sep))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->suffix))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t extended_zip_t_acc_add (P_t *pads,extended_zip_t_acc *acc,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint32_acc_add (pads,&(acc->zip),&(pd->zip),&(rep->zip))) 
        {
          nerr++;
        }
      if (P_ERR==zipSep_t_acc_add (pads,&(acc->sep),&(pd->sep),&(rep->sep))) 
        {
          nerr++;
        }
      if (P_ERR==Puint32_acc_add (pads,&(acc->suffix),&(pd->suffix),&(rep->suffix))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t extended_zip_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,extended_zip_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct extended_zip_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.zip",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->zip))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.sep",prefix);
  if (P_ERR==zipSep_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->sep))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.suffix",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->suffix))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t extended_zip_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,extended_zip_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = extended_zip_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t extended_zip_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("extended_zip_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->zip),&(rep->zip));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = zipSep_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->sep),&(rep->sep));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->suffix),&(rep->suffix));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t extended_zip_t_write2io (P_t *pads,Sfio_t *io,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("extended_zip_t_write2io",extended_zip_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t extended_zip_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,extended_zip_t_pd *pd,extended_zip_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("extended_zip_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("extended_zip_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->zip),&(rep->zip),"zip",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = zipSep_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->sep),&(rep->sep),"sep",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->suffix),&(rep->suffix),"suffix",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t extended_zip_t_write_xml_2io (P_t *pads,Sfio_t *io,extended_zip_t_pd *pd,extended_zip_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("extended_zip_t_write_xml_2io",extended_zip_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t extended_zip_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,extended_zip_t_m *m,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("extended_zip_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->zip),&(pd->zip),&(rep->zip)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("zipSep_t_fmt2buf",zipSep_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->sep),&(pd->sep),&(rep->sep)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->suffix),&(pd->suffix),&(rep->suffix)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t extended_zip_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,extended_zip_t_m *m,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("extended_zip_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"extended_zip_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return extended_zip_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t extended_zip_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,extended_zip_t_m *m,extended_zip_t_pd *pd,extended_zip_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("extended_zip_t_fmt2io",extended_zip_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *extended_zip_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (extended_zip_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *extended_zip_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (extended_zip_t,4);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *extended_zip_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (extended_zip_t);
  NODE_KC_CASE (extended_zip_t,0,Puint32,zip);
  NODE_KC_CASE (extended_zip_t,1,zipSep_t,sep);
  NODE_KC_CASE (extended_zip_t,2,Puint32,suffix);
  STR_NODE_KTH_CHILD_BODY_END (3);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *extended_zip_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (extended_zip_t,"zip","sep","suffix");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *extended_zip_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (extended_zip_t,4);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *extended_zip_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (extended_zip_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *extended_zip_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (extended_zip_t);
  SND_NODE_KC_CASE (extended_zip_t,0,Puint32,zip);
  SND_NODE_KC_CASE (extended_zip_t,1,zipSep_t,sep);
  SND_NODE_KC_CASE (extended_zip_t,2,Puint32,suffix);
  STR_SND_NODE_KTH_CHILD_BODY_END (3);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t extended_zip_t_node_pathWalk (P_t *pads,extended_zip_t_m *m,extended_zip_t_pd *pd,extended_zip_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Puint32,zip);
  NODE_PW_CASE (1,zipSep_t,sep);
  NODE_PW_CASE (2,Puint32,suffix);
  STR_NODE_PATH_WALK_BODY_END (3);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const extended_zip_t_node_vtable={extended_zip_t_cachedNode_init,extended_zip_t_node_kthChild,extended_zip_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const extended_zip_t_cachedNode_vtable={PDCI_error_cachedNode_init,extended_zip_t_cachedNode_kthChild,extended_zip_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const extended_zip_t_sndNode_vtable={PDCI_error_cachedNode_init,extended_zip_t_sndNode_kthChild,extended_zip_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t Pzip_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Pzip_pd *pd,Pzip *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("Pzip_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case extendedZip: 
      {
        tlen_PCGEN_ = extended_zip_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).extendedZip),&((rep->val).extendedZip));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case smallZip: 
      {
        tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).smallZip),&((rep->val).smallZip));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case largeZip: 
      {
        tlen_PCGEN_ = Puint64_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).largeZip),&((rep->val).largeZip));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case Pzip_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t Pzip_write2io (P_t *pads,Sfio_t *io,Pzip_pd *pd,Pzip *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("Pzip_write2io",Pzip_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t Pzip_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,Pzip_pd *pd,Pzip *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("Pzip_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("Pzip");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case extendedZip: 
      {
        tlen_PCGEN_ = extended_zip_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).extendedZip),&((rep->val).extendedZip),"extendedZip",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case smallZip: 
      {
        tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).smallZip),&((rep->val).smallZip),"smallZip",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case largeZip: 
      {
        tlen_PCGEN_ = Puint64_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).largeZip),&((rep->val).largeZip),"largeZip",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case Pzip_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t Pzip_write_xml_2io (P_t *pads,Sfio_t *io,Pzip_pd *pd,Pzip *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("Pzip_write_xml_2io",Pzip_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
char const *Pzip_tag2str (Pzip_tag which)
{
  switch (which)
    {
      
    case extendedZip: 
      {
        return "extendedZip";
      }
      
    case smallZip: 
      {
        return "smallZip";
      }
      
    case largeZip: 
      {
        return "largeZip";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t Pzip_init (P_t *pads,Pzip *rep)
{
  return P_OK;
}
Perror_t Pzip_pd_init (P_t *pads,Pzip_pd *pd)
{
  return P_OK;
}
Perror_t Pzip_cleanup (P_t *pads,Pzip *rep)
{
  return P_OK;
}
Perror_t Pzip_pd_cleanup (P_t *pads,Pzip_pd *pd)
{
  return P_OK;
}
Perror_t Pzip_copy (P_t *pads,Pzip *rep_dst,Pzip *rep_src)
{
  PDCI_DISC_2P_CHECKS ("Pzip_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(Pzip));
  return P_OK;
}
Perror_t Pzip_pd_copy (P_t *pads,Pzip_pd *pd_dst,Pzip_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("Pzip_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(Pzip_pd));
  return P_OK;
}
void Pzip_m_init (P_t *pads,Pzip_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(Pzip_m));
}
Perror_t Pzip_read (P_t *pads,Pzip_m *m,Pzip_pd *pd,Pzip *rep)
{
  PDCI_IODISC_3P_CHECKS ("Pzip_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    {
      PCGEN_UNION_READ_SETUP_STAT ("Pzip_read",extendedZip,Pzip_cleanup,Pzip_init,Pzip_copy,Pzip_pd_cleanup,Pzip_pd_init,Pzip_pd_copy);
      // Read branch 'extendedZip'
      PCGEN_UNION_READ_STAT ("Pzip_read","extendedZip",extendedZip,Pzip_cleanup,Pzip_init,Pzip_copy,Pzip_pd_cleanup,Pzip_pd_init,Pzip_pd_copy,extended_zip_t_read (pads,&(m->extendedZip),&((pd->val).extendedZip),&((rep->val).extendedZip)),Pzip_write_xml_2io (pads,sfstderr,pd,rep,"Pzip",4),_NOOP);
      // Read branch 'smallZip'
      PCGEN_UNION_READ_STAT ("Pzip_read","smallZip",smallZip,Pzip_cleanup,Pzip_init,Pzip_copy,Pzip_pd_cleanup,Pzip_pd_init,Pzip_pd_copy,Puint32_read (pads,&(m->smallZip),&((pd->val).smallZip),&((rep->val).smallZip)),Pzip_write_xml_2io (pads,sfstderr,pd,rep,"Pzip",4),_NOOP);
      // Read branch 'largeZip'
      PCGEN_UNION_READ_STAT ("Pzip_read","largeZip",largeZip,Pzip_cleanup,Pzip_init,Pzip_copy,Pzip_pd_cleanup,Pzip_pd_init,Pzip_pd_copy,Puint64_read (pads,&(m->largeZip),&((pd->val).largeZip),&((rep->val).largeZip)),Pzip_write_xml_2io (pads,sfstderr,pd,rep,"Pzip",4),_NOOP);
      // Failed to match any branch of union Pzip
      PCGEN_UNION_READ_CHECK_FAILED ("Pzip_read","Pzip",Pzip_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int Pzip_verify (Pzip *rep)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case extendedZip: 
      {
        isValid = extended_zip_t_verify (&((rep->val).extendedZip));
        break;
      }
      
    case smallZip: 
      {
        // PADS type has no is_ function and there is no user constraint
        break;
      }
      
    case largeZip: 
      {
        // PADS type has no is_ function and there is no user constraint
        break;
      }
      
    case Pzip_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t Pzip_acc_init (P_t *pads,Pzip_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==extended_zip_t_acc_init (pads,&(acc->extendedZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->smallZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_init (pads,&(acc->largeZip))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t Pzip_acc_reset (P_t *pads,Pzip_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==extended_zip_t_acc_reset (pads,&(acc->extendedZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->smallZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_reset (pads,&(acc->largeZip))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t Pzip_acc_cleanup (P_t *pads,Pzip_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==extended_zip_t_acc_cleanup (pads,&(acc->extendedZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->smallZip))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_cleanup (pads,&(acc->largeZip))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t Pzip_acc_add (P_t *pads,Pzip_acc *acc,Pzip_pd *pd,Pzip *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case extendedZip: 
          {
            if (P_ERR==extended_zip_t_acc_add (pads,&(acc->extendedZip),&((pd->val).extendedZip),&((rep->val).extendedZip))) 
              {
                nerr++;
              }
            break;
          }
          
        case smallZip: 
          {
            if (P_ERR==Puint32_acc_add (pads,&(acc->smallZip),&((pd->val).smallZip),&((rep->val).smallZip))) 
              {
                nerr++;
              }
            break;
          }
          
        case largeZip: 
          {
            if (P_ERR==Puint64_acc_add (pads,&(acc->largeZip),&((pd->val).largeZip),&((rep->val).largeZip))) 
              {
                nerr++;
              }
            break;
          }
          
        case Pzip_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t Pzip_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,Pzip_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "union Pzip";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Union tag","tag",-1,(Pint32_map_fn) Pzip_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.extendedZip",prefix);
  if (P_ERR==extended_zip_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->extendedZip))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.smallZip",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->smallZip))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.largeZip",prefix);
  if (P_ERR==Puint64_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->largeZip))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t Pzip_acc_report (P_t *pads,char const *prefix,char const *what,int nst,Pzip_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = Pzip_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t Pzip_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Pzip_m *m,Pzip_pd *pd,Pzip *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("Pzip_fmt2buf_final");
  switch (rep->tag)
    {
      
    case extendedZip: 
      {
        PCGEN_FMT2BUF_UNION ("extended_zip_t_fmt2buf",extended_zip_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->extendedZip),&((pd->val).extendedZip),&((rep->val).extendedZip)),"extendedZip");
        break;
      }
      
    case smallZip: 
      {
        PCGEN_FMT2BUF_UNION ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->smallZip),&((pd->val).smallZip),&((rep->val).smallZip)),"smallZip");
        break;
      }
      
    case largeZip: 
      {
        PCGEN_FMT2BUF_UNION ("Puint64_fmt2buf",Puint64_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->largeZip),&((pd->val).largeZip),&((rep->val).largeZip)),"largeZip");
        break;
      }
      
    case Pzip_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t Pzip_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,Pzip_m *m,Pzip_pd *pd,Pzip *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("Pzip_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"Pzip"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return Pzip_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t Pzip_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,Pzip_m *m,Pzip_pd *pd,Pzip *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("Pzip_fmt2io",Pzip_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *Pzip_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (Pzip);
  return NODE_NEW_RET ();
}
PDCI_node_t *Pzip_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (Pzip,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *Pzip_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (Pzip);
  UNION_NODE_KC_CASE (Pzip,extendedZip,extended_zip_t);
  UNION_NODE_KC_CASE (Pzip,smallZip,Puint32);
  UNION_NODE_KC_CASE (Pzip,largeZip,Puint64);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *Pzip_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (Pzip);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *Pzip_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (Pzip,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *Pzip_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (Pzip);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *Pzip_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (Pzip);
  UNION_SND_NODE_KC_CASE (Pzip,extendedZip,extended_zip_t);
  UNION_SND_NODE_KC_CASE (Pzip,smallZip,Puint32);
  UNION_SND_NODE_KC_CASE (Pzip,largeZip,Puint64);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t Pzip_node_pathWalk (P_t *pads,Pzip_m *m,Pzip_pd *pd,Pzip *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (Pzip);
  UNION_NODE_PW_CASE (extendedZip,extended_zip_t);
  UNION_NODE_PW_CASE (smallZip,Puint32);
  UNION_NODE_PW_CASE (largeZip,Puint64);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const Pzip_node_vtable={Pzip_cachedNode_init,Pzip_node_kthChild,Pzip_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const Pzip_cachedNode_vtable={PDCI_error_cachedNode_init,Pzip_cachedNode_kthChild,Pzip_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const Pzip_sndNode_vtable={PDCI_error_cachedNode_init,Pzip_sndNode_kthChild,Pzip_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t summary_header_t_init (P_t *pads,summary_header_t *rep)
{
  return P_OK;
}
Perror_t summary_header_t_pd_init (P_t *pads,summary_header_t_pd *pd)
{
  return P_OK;
}
Perror_t summary_header_t_cleanup (P_t *pads,summary_header_t *rep)
{
  return P_OK;
}
Perror_t summary_header_t_pd_cleanup (P_t *pads,summary_header_t_pd *pd)
{
  return P_OK;
}
Perror_t summary_header_t_copy (P_t *pads,summary_header_t *rep_dst,summary_header_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("summary_header_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(summary_header_t));
  return P_OK;
}
Perror_t summary_header_t_pd_copy (P_t *pads,summary_header_t_pd *pd_dst,summary_header_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("summary_header_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(summary_header_t_pd));
  return P_OK;
}
void summary_header_t_m_init (P_t *pads,summary_header_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(summary_header_t_m));
}
Perror_t summary_header_t_read (P_t *pads,summary_header_t_m *m,summary_header_t_pd *pd,summary_header_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("summary_header_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read delimeter field: "0|"
  PCGEN_STRUCT_READ_FIRST_STR_LIT ("summary_header_t_read","0|",2);
  // Read field 'tstamp'
  PCGEN_STRUCT_READ_NEXT ("summary_header_t_read",tstamp,Puint32_read (pads,&(m->tstamp),&(pd->tstamp),&(rep->tstamp)),_NOOP);
  PCGEN_FIND_EOR ("summary_header_t_read");
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int summary_header_t_verify (summary_header_t *rep)
{
  return 1;
}
Perror_t summary_header_t_acc_init (P_t *pads,summary_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t summary_header_t_acc_reset (P_t *pads,summary_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t summary_header_t_acc_cleanup (P_t *pads,summary_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t summary_header_t_acc_add (P_t *pads,summary_header_t_acc *acc,summary_header_t_pd *pd,summary_header_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint32_acc_add (pads,&(acc->tstamp),&(pd->tstamp),&(rep->tstamp))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t summary_header_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,summary_header_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct summary_header_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.tstamp",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->tstamp))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t summary_header_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,summary_header_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = summary_header_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t summary_header_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,summary_header_t_pd *pd,summary_header_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("summary_header_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = PDCI_io_rec_open_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"summary_header_t_write2buf");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"0|");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->tstamp),&(rep->tstamp));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = PDCI_io_rec_close_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,buf,length_PCGEN_,"summary_header_t_write2buf");
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t summary_header_t_write2io (P_t *pads,Sfio_t *io,summary_header_t_pd *pd,summary_header_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("summary_header_t_write2io",summary_header_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t summary_header_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,summary_header_t_pd *pd,summary_header_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("summary_header_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("summary_header_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->tstamp),&(rep->tstamp),"tstamp",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t summary_header_t_write_xml_2io (P_t *pads,Sfio_t *io,summary_header_t_pd *pd,summary_header_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("summary_header_t_write_xml_2io",summary_header_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t summary_header_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,summary_header_t_m *m,summary_header_t_pd *pd,summary_header_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("summary_header_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->tstamp),&(pd->tstamp),&(rep->tstamp)));
  PCGEN_FMT2BUF_FIX_LAST ();
  PCGEN_FMT2BUF_RECORD ("summary_header_t_fmt2buf_final");
  return length_PCGEN_;
}
ssize_t summary_header_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,summary_header_t_m *m,summary_header_t_pd *pd,summary_header_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("summary_header_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"summary_header_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return summary_header_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t summary_header_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,summary_header_t_m *m,summary_header_t_pd *pd,summary_header_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("summary_header_t_fmt2io",summary_header_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *summary_header_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (summary_header_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *summary_header_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (summary_header_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *summary_header_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (summary_header_t);
  NODE_KC_CASE (summary_header_t,0,Puint32,tstamp);
  STR_NODE_KTH_CHILD_BODY_END (1);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *summary_header_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (summary_header_t,"tstamp");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *summary_header_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (summary_header_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *summary_header_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (summary_header_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *summary_header_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (summary_header_t);
  SND_NODE_KC_CASE (summary_header_t,0,Puint32,tstamp);
  STR_SND_NODE_KTH_CHILD_BODY_END (1);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t summary_header_t_node_pathWalk (P_t *pads,summary_header_t_m *m,summary_header_t_pd *pd,summary_header_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Puint32,tstamp);
  STR_NODE_PATH_WALK_BODY_END (1);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const summary_header_t_node_vtable={summary_header_t_cachedNode_init,summary_header_t_node_kthChild,summary_header_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const summary_header_t_cachedNode_vtable={PDCI_error_cachedNode_init,summary_header_t_cachedNode_kthChild,summary_header_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const summary_header_t_sndNode_vtable={PDCI_error_cachedNode_init,summary_header_t_sndNode_kthChild,summary_header_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t no_ramp_t_init (P_t *pads,no_ramp_t *rep)
{
  return P_OK;
}
Perror_t no_ramp_t_pd_init (P_t *pads,no_ramp_t_pd *pd)
{
  return P_OK;
}
Perror_t no_ramp_t_cleanup (P_t *pads,no_ramp_t *rep)
{
  return P_OK;
}
Perror_t no_ramp_t_pd_cleanup (P_t *pads,no_ramp_t_pd *pd)
{
  return P_OK;
}
Perror_t no_ramp_t_copy (P_t *pads,no_ramp_t *rep_dst,no_ramp_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("no_ramp_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(no_ramp_t));
  return P_OK;
}
Perror_t no_ramp_t_pd_copy (P_t *pads,no_ramp_t_pd *pd_dst,no_ramp_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("no_ramp_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(no_ramp_t_pd));
  return P_OK;
}
void no_ramp_t_m_init (P_t *pads,no_ramp_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(no_ramp_t_m));
}
Perror_t no_ramp_t_read (P_t *pads,no_ramp_t_m *m,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("no_ramp_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read delimeter field: "no_ii"
  PCGEN_STRUCT_READ_FIRST_STR_LIT ("no_ramp_t_read","no_ii",5);
  // Read field 'id'
  PCGEN_STRUCT_READ_NEXT ("no_ramp_t_read",id,Puint64_read (pads,&(m->id),&(pd->id),&(rep->id)),_NOOP);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int no_ramp_t_verify (no_ramp_t *rep)
{
  return 1;
}
Perror_t no_ramp_t_acc_init (P_t *pads,no_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_init (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t no_ramp_t_acc_reset (P_t *pads,no_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_reset (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t no_ramp_t_acc_cleanup (P_t *pads,no_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint64_acc_cleanup (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t no_ramp_t_acc_add (P_t *pads,no_ramp_t_acc *acc,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint64_acc_add (pads,&(acc->id),&(pd->id),&(rep->id))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t no_ramp_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,no_ramp_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct no_ramp_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.id",prefix);
  if (P_ERR==Puint64_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->id))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t no_ramp_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,no_ramp_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = no_ramp_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t no_ramp_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("no_ramp_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"no_ii");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint64_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->id),&(rep->id));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t no_ramp_t_write2io (P_t *pads,Sfio_t *io,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("no_ramp_t_write2io",no_ramp_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t no_ramp_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,no_ramp_t_pd *pd,no_ramp_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("no_ramp_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("no_ramp_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Puint64_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->id),&(rep->id),"id",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t no_ramp_t_write_xml_2io (P_t *pads,Sfio_t *io,no_ramp_t_pd *pd,no_ramp_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("no_ramp_t_write_xml_2io",no_ramp_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t no_ramp_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,no_ramp_t_m *m,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("no_ramp_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint64_fmt2buf",Puint64_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->id),&(pd->id),&(rep->id)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t no_ramp_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,no_ramp_t_m *m,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("no_ramp_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"no_ramp_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return no_ramp_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t no_ramp_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,no_ramp_t_m *m,no_ramp_t_pd *pd,no_ramp_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("no_ramp_t_fmt2io",no_ramp_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *no_ramp_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (no_ramp_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *no_ramp_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (no_ramp_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *no_ramp_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (no_ramp_t);
  NODE_KC_CASE (no_ramp_t,0,Puint64,id);
  STR_NODE_KTH_CHILD_BODY_END (1);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *no_ramp_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (no_ramp_t,"id");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *no_ramp_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (no_ramp_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *no_ramp_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (no_ramp_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *no_ramp_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (no_ramp_t);
  SND_NODE_KC_CASE (no_ramp_t,0,Puint64,id);
  STR_SND_NODE_KTH_CHILD_BODY_END (1);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t no_ramp_t_node_pathWalk (P_t *pads,no_ramp_t_m *m,no_ramp_t_pd *pd,no_ramp_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Puint64,id);
  STR_NODE_PATH_WALK_BODY_END (1);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const no_ramp_t_node_vtable={no_ramp_t_cachedNode_init,no_ramp_t_node_kthChild,no_ramp_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const no_ramp_t_cachedNode_vtable={PDCI_error_cachedNode_init,no_ramp_t_cachedNode_kthChild,no_ramp_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const no_ramp_t_sndNode_vtable={PDCI_error_cachedNode_init,no_ramp_t_sndNode_kthChild,no_ramp_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t dib_ramp_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("dib_ramp_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case ramp: 
      {
        tlen_PCGEN_ = Pint64_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).ramp),&((rep->val).ramp));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case genRamp: 
      {
        tlen_PCGEN_ = no_ramp_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).genRamp),&((rep->val).genRamp));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case dib_ramp_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t dib_ramp_t_write2io (P_t *pads,Sfio_t *io,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("dib_ramp_t_write2io",dib_ramp_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t dib_ramp_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,dib_ramp_t_pd *pd,dib_ramp_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("dib_ramp_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("dib_ramp_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case ramp: 
      {
        tlen_PCGEN_ = Pint64_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).ramp),&((rep->val).ramp),"ramp",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case genRamp: 
      {
        tlen_PCGEN_ = no_ramp_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).genRamp),&((rep->val).genRamp),"genRamp",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case dib_ramp_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t dib_ramp_t_write_xml_2io (P_t *pads,Sfio_t *io,dib_ramp_t_pd *pd,dib_ramp_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("dib_ramp_t_write_xml_2io",dib_ramp_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
char const *dib_ramp_t_tag2str (dib_ramp_t_tag which)
{
  switch (which)
    {
      
    case ramp: 
      {
        return "ramp";
      }
      
    case genRamp: 
      {
        return "genRamp";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t dib_ramp_t_init (P_t *pads,dib_ramp_t *rep)
{
  return P_OK;
}
Perror_t dib_ramp_t_pd_init (P_t *pads,dib_ramp_t_pd *pd)
{
  return P_OK;
}
Perror_t dib_ramp_t_cleanup (P_t *pads,dib_ramp_t *rep)
{
  return P_OK;
}
Perror_t dib_ramp_t_pd_cleanup (P_t *pads,dib_ramp_t_pd *pd)
{
  return P_OK;
}
Perror_t dib_ramp_t_copy (P_t *pads,dib_ramp_t *rep_dst,dib_ramp_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("dib_ramp_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(dib_ramp_t));
  return P_OK;
}
Perror_t dib_ramp_t_pd_copy (P_t *pads,dib_ramp_t_pd *pd_dst,dib_ramp_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("dib_ramp_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(dib_ramp_t_pd));
  return P_OK;
}
void dib_ramp_t_m_init (P_t *pads,dib_ramp_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(dib_ramp_t_m));
}
Perror_t dib_ramp_t_read (P_t *pads,dib_ramp_t_m *m,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("dib_ramp_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    {
      PCGEN_UNION_READ_SETUP_STAT ("dib_ramp_t_read",ramp,dib_ramp_t_cleanup,dib_ramp_t_init,dib_ramp_t_copy,dib_ramp_t_pd_cleanup,dib_ramp_t_pd_init,dib_ramp_t_pd_copy);
      // Read branch 'ramp'
      PCGEN_UNION_READ_STAT ("dib_ramp_t_read","ramp",ramp,dib_ramp_t_cleanup,dib_ramp_t_init,dib_ramp_t_copy,dib_ramp_t_pd_cleanup,dib_ramp_t_pd_init,dib_ramp_t_pd_copy,Pint64_read (pads,&(m->ramp),&((pd->val).ramp),&((rep->val).ramp)),dib_ramp_t_write_xml_2io (pads,sfstderr,pd,rep,"dib_ramp_t",4),_NOOP);
      // Read branch 'genRamp'
      PCGEN_UNION_READ_STAT ("dib_ramp_t_read","genRamp",genRamp,dib_ramp_t_cleanup,dib_ramp_t_init,dib_ramp_t_copy,dib_ramp_t_pd_cleanup,dib_ramp_t_pd_init,dib_ramp_t_pd_copy,no_ramp_t_read (pads,&(m->genRamp),&((pd->val).genRamp),&((rep->val).genRamp)),dib_ramp_t_write_xml_2io (pads,sfstderr,pd,rep,"dib_ramp_t",4),_NOOP);
      // Failed to match any branch of union dib_ramp_t
      PCGEN_UNION_READ_CHECK_FAILED ("dib_ramp_t_read","dib_ramp_t",dib_ramp_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int dib_ramp_t_verify (dib_ramp_t *rep)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case ramp: 
      {
        // PADS type has no is_ function and there is no user constraint
        break;
      }
      
    case genRamp: 
      {
        isValid = no_ramp_t_verify (&((rep->val).genRamp));
        break;
      }
      
    case dib_ramp_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t dib_ramp_t_acc_init (P_t *pads,dib_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pint64_acc_init (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==no_ramp_t_acc_init (pads,&(acc->genRamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t dib_ramp_t_acc_reset (P_t *pads,dib_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pint64_acc_reset (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==no_ramp_t_acc_reset (pads,&(acc->genRamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t dib_ramp_t_acc_cleanup (P_t *pads,dib_ramp_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pint64_acc_cleanup (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==no_ramp_t_acc_cleanup (pads,&(acc->genRamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t dib_ramp_t_acc_add (P_t *pads,dib_ramp_t_acc *acc,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case ramp: 
          {
            if (P_ERR==Pint64_acc_add (pads,&(acc->ramp),&((pd->val).ramp),&((rep->val).ramp))) 
              {
                nerr++;
              }
            break;
          }
          
        case genRamp: 
          {
            if (P_ERR==no_ramp_t_acc_add (pads,&(acc->genRamp),&((pd->val).genRamp),&((rep->val).genRamp))) 
              {
                nerr++;
              }
            break;
          }
          
        case dib_ramp_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t dib_ramp_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,dib_ramp_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "union dib_ramp_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Union tag","tag",-1,(Pint32_map_fn) dib_ramp_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.ramp",prefix);
  if (P_ERR==Pint64_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->ramp))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.genRamp",prefix);
  if (P_ERR==no_ramp_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->genRamp))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t dib_ramp_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,dib_ramp_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = dib_ramp_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t dib_ramp_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,dib_ramp_t_m *m,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("dib_ramp_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case ramp: 
      {
        PCGEN_FMT2BUF_UNION ("Pint64_fmt2buf",Pint64_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->ramp),&((pd->val).ramp),&((rep->val).ramp)),"ramp");
        break;
      }
      
    case genRamp: 
      {
        PCGEN_FMT2BUF_UNION ("no_ramp_t_fmt2buf",no_ramp_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->genRamp),&((pd->val).genRamp),&((rep->val).genRamp)),"genRamp");
        break;
      }
      
    case dib_ramp_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t dib_ramp_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,dib_ramp_t_m *m,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("dib_ramp_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"dib_ramp_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return dib_ramp_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t dib_ramp_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,dib_ramp_t_m *m,dib_ramp_t_pd *pd,dib_ramp_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("dib_ramp_t_fmt2io",dib_ramp_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *dib_ramp_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (dib_ramp_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *dib_ramp_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (dib_ramp_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *dib_ramp_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (dib_ramp_t);
  UNION_NODE_KC_CASE (dib_ramp_t,ramp,Pint64);
  UNION_NODE_KC_CASE (dib_ramp_t,genRamp,no_ramp_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *dib_ramp_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (dib_ramp_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *dib_ramp_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (dib_ramp_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *dib_ramp_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (dib_ramp_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *dib_ramp_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (dib_ramp_t);
  UNION_SND_NODE_KC_CASE (dib_ramp_t,ramp,Pint64);
  UNION_SND_NODE_KC_CASE (dib_ramp_t,genRamp,no_ramp_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t dib_ramp_t_node_pathWalk (P_t *pads,dib_ramp_t_m *m,dib_ramp_t_pd *pd,dib_ramp_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (dib_ramp_t);
  UNION_NODE_PW_CASE (ramp,Pint64);
  UNION_NODE_PW_CASE (genRamp,no_ramp_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const dib_ramp_t_node_vtable={dib_ramp_t_cachedNode_init,dib_ramp_t_node_kthChild,dib_ramp_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const dib_ramp_t_cachedNode_vtable={PDCI_error_cachedNode_init,dib_ramp_t_cachedNode_kthChild,dib_ramp_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const dib_ramp_t_sndNode_vtable={PDCI_error_cachedNode_init,dib_ramp_t_sndNode_kthChild,dib_ramp_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t service_tn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("service_tn_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case some_service_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_service_tn_t),&((rep->val).some_service_tn_t));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t service_tn_t_write2io (P_t *pads,Sfio_t *io,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("service_tn_t_write2io",service_tn_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep,order_num,att_order_num,ord_version));
  return -1;
}
ssize_t service_tn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,service_tn_t_pd *pd,service_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("service_tn_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("service_tn_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case some_service_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_service_tn_t),&((rep->val).some_service_tn_t),"some_service_tn_t",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t service_tn_t_write_xml_2io (P_t *pads,Sfio_t *io,service_tn_t_pd *pd,service_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("service_tn_t_write_xml_2io",service_tn_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent,order_num,att_order_num,ord_version));
  return -1;
}
char const *service_tn_t_tag2str (service_tn_t_tag which)
{
  switch (which)
    {
      
    case some_service_tn_t: 
      {
        return "some_service_tn_t";
      }
      
    case none_service_tn_t: 
      {
        return "none_service_tn_t";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t service_tn_t_init (P_t *pads,service_tn_t *rep)
{
  return P_OK;
}
Perror_t service_tn_t_pd_init (P_t *pads,service_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t service_tn_t_cleanup (P_t *pads,service_tn_t *rep)
{
  return P_OK;
}
Perror_t service_tn_t_pd_cleanup (P_t *pads,service_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t service_tn_t_copy (P_t *pads,service_tn_t *rep_dst,service_tn_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("service_tn_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(service_tn_t));
  return P_OK;
}
Perror_t service_tn_t_pd_copy (P_t *pads,service_tn_t_pd *pd_dst,service_tn_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("service_tn_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(service_tn_t_pd));
  return P_OK;
}
void service_tn_t_m_init (P_t *pads,service_tn_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(service_tn_t_m));
}
Perror_t service_tn_t_read (P_t *pads,service_tn_t_m *m,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  PDCI_IODISC_3P_CHECKS ("service_tn_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Puint32 none_service_tn_t_Ptmp_;
    {
      PCGEN_UNION_READ_SETUP_STAT ("service_tn_t_read",some_service_tn_t,service_tn_t_cleanup,service_tn_t_init,service_tn_t_copy,service_tn_t_pd_cleanup,service_tn_t_pd_init,service_tn_t_pd_copy);
      // Read branch 'some_service_tn_t'
      PCGEN_UNION_READ_STAT ("service_tn_t_read","some_service_tn_t",some_service_tn_t,service_tn_t_cleanup,service_tn_t_init,service_tn_t_copy,service_tn_t_pd_cleanup,service_tn_t_pd_init,service_tn_t_pd_copy,pn_t_read (pads,&(m->some_service_tn_t),&((pd->val).some_service_tn_t),&((rep->val).some_service_tn_t)),service_tn_t_write_xml_2io (pads,sfstderr,pd,rep,"service_tn_t",4,order_num,att_order_num,ord_version),_NOOP);
      // Pcompute branch 'none_service_tn_t'
      PCGEN_UNION_READ_MAN_STAT_VIRT_PRE ("service_tn_t_read",none_service_tn_t,service_tn_t_init,service_tn_t_pd_init);
      none_service_tn_t_Ptmp_ = 0;
      PCGEN_UNION_READ_MAN_STAT_POST ("service_tn_t_read",service_tn_t_copy,service_tn_t_cleanup,service_tn_t_pd_copy,service_tn_t_pd_cleanup);
      // Failed to match any branch of union service_tn_t
      PCGEN_UNION_READ_CHECK_FAILED ("service_tn_t_read","service_tn_t",service_tn_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int service_tn_t_verify (service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case some_service_tn_t: 
      {
        isValid = pn_t_verify (&((rep->val).some_service_tn_t));
        break;
      }
      
    case none_service_tn_t: 
      {
        // Pomit branch: no user constraint
        break;
      }
      
    case service_tn_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t service_tn_t_acc_init (P_t *pads,service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_init (pads,&(acc->some_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t service_tn_t_acc_reset (P_t *pads,service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_reset (pads,&(acc->some_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t service_tn_t_acc_cleanup (P_t *pads,service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_cleanup (pads,&(acc->some_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t service_tn_t_acc_add (P_t *pads,service_tn_t_acc *acc,service_tn_t_pd *pd,service_tn_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case some_service_tn_t: 
          {
            if (P_ERR==pn_t_acc_add (pads,&(acc->some_service_tn_t),&((pd->val).some_service_tn_t),&((rep->val).some_service_tn_t))) 
              {
                nerr++;
              }
            break;
          }
          
        case none_service_tn_t: 
          {
            // Pomit branch: cannot accumulate
            break;
          }
          
        case service_tn_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t service_tn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,service_tn_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "opt service_tn_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Opt tag","tag",-1,(Pint32_map_fn) service_tn_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.some_service_tn_t",prefix);
  if (P_ERR==pn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->some_service_tn_t))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  // Pomit branch: cannot accumulate
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t service_tn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,service_tn_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = service_tn_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t service_tn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,service_tn_t_m *m,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("service_tn_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case some_service_tn_t: 
      {
        PCGEN_FMT2BUF_UNION ("pn_t_fmt2buf",pn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->some_service_tn_t),&((pd->val).some_service_tn_t),&((rep->val).some_service_tn_t)),"some_service_tn_t");
        break;
      }
      
    case none_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t service_tn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,service_tn_t_m *m,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("service_tn_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"service_tn_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version));
  return service_tn_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version);
}
ssize_t service_tn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,service_tn_t_m *m,service_tn_t_pd *pd,service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("service_tn_t_fmt2io",service_tn_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version));
  return -1;
}
PDCI_node_t *service_tn_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (service_tn_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *service_tn_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (service_tn_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *service_tn_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (service_tn_t);
  UNION_NODE_KC_CASE (service_tn_t,some_service_tn_t,pn_t);
  UNION_NODE_KC_CASE_LITERAL (service_tn_t,none_service_tn_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *service_tn_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (service_tn_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *service_tn_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (service_tn_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *service_tn_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (service_tn_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *service_tn_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (service_tn_t);
  UNION_SND_NODE_KC_CASE (service_tn_t,some_service_tn_t,pn_t);
  UNION_SND_NODE_KC_CASE_LITERAL (service_tn_t,none_service_tn_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t service_tn_t_node_pathWalk (P_t *pads,service_tn_t_m *m,service_tn_t_pd *pd,service_tn_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (service_tn_t);
  UNION_NODE_PW_CASE (some_service_tn_t,pn_t);
  UNION_NODE_PW_CASE_LITERAL (service_tn_t,none_service_tn_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const service_tn_t_node_vtable={service_tn_t_cachedNode_init,service_tn_t_node_kthChild,service_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const service_tn_t_cachedNode_vtable={PDCI_error_cachedNode_init,service_tn_t_cachedNode_kthChild,service_tn_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const service_tn_t_sndNode_vtable={PDCI_error_cachedNode_init,service_tn_t_sndNode_kthChild,service_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t billing_tn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("billing_tn_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case some_billing_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_billing_tn_t),&((rep->val).some_billing_tn_t));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t billing_tn_t_write2io (P_t *pads,Sfio_t *io,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("billing_tn_t_write2io",billing_tn_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep,order_num,att_order_num,ord_version,service_tn));
  return -1;
}
ssize_t billing_tn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,billing_tn_t_pd *pd,billing_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("billing_tn_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("billing_tn_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case some_billing_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_billing_tn_t),&((rep->val).some_billing_tn_t),"some_billing_tn_t",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t billing_tn_t_write_xml_2io (P_t *pads,Sfio_t *io,billing_tn_t_pd *pd,billing_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("billing_tn_t_write_xml_2io",billing_tn_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent,order_num,att_order_num,ord_version,service_tn));
  return -1;
}
char const *billing_tn_t_tag2str (billing_tn_t_tag which)
{
  switch (which)
    {
      
    case some_billing_tn_t: 
      {
        return "some_billing_tn_t";
      }
      
    case none_billing_tn_t: 
      {
        return "none_billing_tn_t";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t billing_tn_t_init (P_t *pads,billing_tn_t *rep)
{
  return P_OK;
}
Perror_t billing_tn_t_pd_init (P_t *pads,billing_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t billing_tn_t_cleanup (P_t *pads,billing_tn_t *rep)
{
  return P_OK;
}
Perror_t billing_tn_t_pd_cleanup (P_t *pads,billing_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t billing_tn_t_copy (P_t *pads,billing_tn_t *rep_dst,billing_tn_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("billing_tn_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(billing_tn_t));
  return P_OK;
}
Perror_t billing_tn_t_pd_copy (P_t *pads,billing_tn_t_pd *pd_dst,billing_tn_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("billing_tn_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(billing_tn_t_pd));
  return P_OK;
}
void billing_tn_t_m_init (P_t *pads,billing_tn_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(billing_tn_t_m));
}
Perror_t billing_tn_t_read (P_t *pads,billing_tn_t_m *m,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  PDCI_IODISC_3P_CHECKS ("billing_tn_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Puint32 none_billing_tn_t_Ptmp_;
    {
      PCGEN_UNION_READ_SETUP_STAT ("billing_tn_t_read",some_billing_tn_t,billing_tn_t_cleanup,billing_tn_t_init,billing_tn_t_copy,billing_tn_t_pd_cleanup,billing_tn_t_pd_init,billing_tn_t_pd_copy);
      // Read branch 'some_billing_tn_t'
      PCGEN_UNION_READ_STAT ("billing_tn_t_read","some_billing_tn_t",some_billing_tn_t,billing_tn_t_cleanup,billing_tn_t_init,billing_tn_t_copy,billing_tn_t_pd_cleanup,billing_tn_t_pd_init,billing_tn_t_pd_copy,pn_t_read (pads,&(m->some_billing_tn_t),&((pd->val).some_billing_tn_t),&((rep->val).some_billing_tn_t)),billing_tn_t_write_xml_2io (pads,sfstderr,pd,rep,"billing_tn_t",4,order_num,att_order_num,ord_version,service_tn),_NOOP);
      // Pcompute branch 'none_billing_tn_t'
      PCGEN_UNION_READ_MAN_STAT_VIRT_PRE ("billing_tn_t_read",none_billing_tn_t,billing_tn_t_init,billing_tn_t_pd_init);
      none_billing_tn_t_Ptmp_ = 0;
      PCGEN_UNION_READ_MAN_STAT_POST ("billing_tn_t_read",billing_tn_t_copy,billing_tn_t_cleanup,billing_tn_t_pd_copy,billing_tn_t_pd_cleanup);
      // Failed to match any branch of union billing_tn_t
      PCGEN_UNION_READ_CHECK_FAILED ("billing_tn_t_read","billing_tn_t",billing_tn_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int billing_tn_t_verify (billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case some_billing_tn_t: 
      {
        isValid = pn_t_verify (&((rep->val).some_billing_tn_t));
        break;
      }
      
    case none_billing_tn_t: 
      {
        // Pomit branch: no user constraint
        break;
      }
      
    case billing_tn_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t billing_tn_t_acc_init (P_t *pads,billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_init (pads,&(acc->some_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t billing_tn_t_acc_reset (P_t *pads,billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_reset (pads,&(acc->some_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t billing_tn_t_acc_cleanup (P_t *pads,billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_cleanup (pads,&(acc->some_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t billing_tn_t_acc_add (P_t *pads,billing_tn_t_acc *acc,billing_tn_t_pd *pd,billing_tn_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case some_billing_tn_t: 
          {
            if (P_ERR==pn_t_acc_add (pads,&(acc->some_billing_tn_t),&((pd->val).some_billing_tn_t),&((rep->val).some_billing_tn_t))) 
              {
                nerr++;
              }
            break;
          }
          
        case none_billing_tn_t: 
          {
            // Pomit branch: cannot accumulate
            break;
          }
          
        case billing_tn_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t billing_tn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,billing_tn_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "opt billing_tn_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Opt tag","tag",-1,(Pint32_map_fn) billing_tn_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.some_billing_tn_t",prefix);
  if (P_ERR==pn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->some_billing_tn_t))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  // Pomit branch: cannot accumulate
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t billing_tn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,billing_tn_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = billing_tn_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t billing_tn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,billing_tn_t_m *m,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("billing_tn_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case some_billing_tn_t: 
      {
        PCGEN_FMT2BUF_UNION ("pn_t_fmt2buf",pn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->some_billing_tn_t),&((pd->val).some_billing_tn_t),&((rep->val).some_billing_tn_t)),"some_billing_tn_t");
        break;
      }
      
    case none_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t billing_tn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,billing_tn_t_m *m,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("billing_tn_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"billing_tn_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn));
  return billing_tn_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn);
}
ssize_t billing_tn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,billing_tn_t_m *m,billing_tn_t_pd *pd,billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("billing_tn_t_fmt2io",billing_tn_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn));
  return -1;
}
PDCI_node_t *billing_tn_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (billing_tn_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *billing_tn_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (billing_tn_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *billing_tn_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (billing_tn_t);
  UNION_NODE_KC_CASE (billing_tn_t,some_billing_tn_t,pn_t);
  UNION_NODE_KC_CASE_LITERAL (billing_tn_t,none_billing_tn_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *billing_tn_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (billing_tn_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *billing_tn_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (billing_tn_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *billing_tn_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (billing_tn_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *billing_tn_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (billing_tn_t);
  UNION_SND_NODE_KC_CASE (billing_tn_t,some_billing_tn_t,pn_t);
  UNION_SND_NODE_KC_CASE_LITERAL (billing_tn_t,none_billing_tn_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t billing_tn_t_node_pathWalk (P_t *pads,billing_tn_t_m *m,billing_tn_t_pd *pd,billing_tn_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (billing_tn_t);
  UNION_NODE_PW_CASE (some_billing_tn_t,pn_t);
  UNION_NODE_PW_CASE_LITERAL (billing_tn_t,none_billing_tn_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const billing_tn_t_node_vtable={billing_tn_t_cachedNode_init,billing_tn_t_node_kthChild,billing_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const billing_tn_t_cachedNode_vtable={PDCI_error_cachedNode_init,billing_tn_t_cachedNode_kthChild,billing_tn_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const billing_tn_t_sndNode_vtable={PDCI_error_cachedNode_init,billing_tn_t_sndNode_kthChild,billing_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t nlp_service_tn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nlp_service_tn_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case some_nlp_service_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_nlp_service_tn_t),&((rep->val).some_nlp_service_tn_t));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_nlp_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t nlp_service_tn_t_write2io (P_t *pads,Sfio_t *io,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_service_tn_t_write2io",nlp_service_tn_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn));
  return -1;
}
ssize_t nlp_service_tn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nlp_service_tn_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("nlp_service_tn_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case some_nlp_service_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_nlp_service_tn_t),&((rep->val).some_nlp_service_tn_t),"some_nlp_service_tn_t",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_nlp_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t nlp_service_tn_t_write_xml_2io (P_t *pads,Sfio_t *io,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_service_tn_t_write_xml_2io",nlp_service_tn_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent,order_num,att_order_num,ord_version,service_tn,billing_tn));
  return -1;
}
char const *nlp_service_tn_t_tag2str (nlp_service_tn_t_tag which)
{
  switch (which)
    {
      
    case some_nlp_service_tn_t: 
      {
        return "some_nlp_service_tn_t";
      }
      
    case none_nlp_service_tn_t: 
      {
        return "none_nlp_service_tn_t";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t nlp_service_tn_t_init (P_t *pads,nlp_service_tn_t *rep)
{
  return P_OK;
}
Perror_t nlp_service_tn_t_pd_init (P_t *pads,nlp_service_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t nlp_service_tn_t_cleanup (P_t *pads,nlp_service_tn_t *rep)
{
  return P_OK;
}
Perror_t nlp_service_tn_t_pd_cleanup (P_t *pads,nlp_service_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t nlp_service_tn_t_copy (P_t *pads,nlp_service_tn_t *rep_dst,nlp_service_tn_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("nlp_service_tn_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(nlp_service_tn_t));
  return P_OK;
}
Perror_t nlp_service_tn_t_pd_copy (P_t *pads,nlp_service_tn_t_pd *pd_dst,nlp_service_tn_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("nlp_service_tn_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(nlp_service_tn_t_pd));
  return P_OK;
}
void nlp_service_tn_t_m_init (P_t *pads,nlp_service_tn_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(nlp_service_tn_t_m));
}
Perror_t nlp_service_tn_t_read (P_t *pads,nlp_service_tn_t_m *m,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  PDCI_IODISC_3P_CHECKS ("nlp_service_tn_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Puint32 none_nlp_service_tn_t_Ptmp_;
    {
      PCGEN_UNION_READ_SETUP_STAT ("nlp_service_tn_t_read",some_nlp_service_tn_t,nlp_service_tn_t_cleanup,nlp_service_tn_t_init,nlp_service_tn_t_copy,nlp_service_tn_t_pd_cleanup,nlp_service_tn_t_pd_init,nlp_service_tn_t_pd_copy);
      // Read branch 'some_nlp_service_tn_t'
      PCGEN_UNION_READ_STAT ("nlp_service_tn_t_read","some_nlp_service_tn_t",some_nlp_service_tn_t,nlp_service_tn_t_cleanup,nlp_service_tn_t_init,nlp_service_tn_t_copy,nlp_service_tn_t_pd_cleanup,nlp_service_tn_t_pd_init,nlp_service_tn_t_pd_copy,pn_t_read (pads,&(m->some_nlp_service_tn_t),&((pd->val).some_nlp_service_tn_t),&((rep->val).some_nlp_service_tn_t)),nlp_service_tn_t_write_xml_2io (pads,sfstderr,pd,rep,"nlp_service_tn_t",4,order_num,att_order_num,ord_version,service_tn,billing_tn),_NOOP);
      // Pcompute branch 'none_nlp_service_tn_t'
      PCGEN_UNION_READ_MAN_STAT_VIRT_PRE ("nlp_service_tn_t_read",none_nlp_service_tn_t,nlp_service_tn_t_init,nlp_service_tn_t_pd_init);
      none_nlp_service_tn_t_Ptmp_ = 0;
      PCGEN_UNION_READ_MAN_STAT_POST ("nlp_service_tn_t_read",nlp_service_tn_t_copy,nlp_service_tn_t_cleanup,nlp_service_tn_t_pd_copy,nlp_service_tn_t_pd_cleanup);
      // Failed to match any branch of union nlp_service_tn_t
      PCGEN_UNION_READ_CHECK_FAILED ("nlp_service_tn_t_read","nlp_service_tn_t",nlp_service_tn_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int nlp_service_tn_t_verify (nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case some_nlp_service_tn_t: 
      {
        isValid = pn_t_verify (&((rep->val).some_nlp_service_tn_t));
        break;
      }
      
    case none_nlp_service_tn_t: 
      {
        // Pomit branch: no user constraint
        break;
      }
      
    case nlp_service_tn_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t nlp_service_tn_t_acc_init (P_t *pads,nlp_service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_init (pads,&(acc->some_nlp_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_service_tn_t_acc_reset (P_t *pads,nlp_service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_reset (pads,&(acc->some_nlp_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_service_tn_t_acc_cleanup (P_t *pads,nlp_service_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_cleanup (pads,&(acc->some_nlp_service_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_service_tn_t_acc_add (P_t *pads,nlp_service_tn_t_acc *acc,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case some_nlp_service_tn_t: 
          {
            if (P_ERR==pn_t_acc_add (pads,&(acc->some_nlp_service_tn_t),&((pd->val).some_nlp_service_tn_t),&((rep->val).some_nlp_service_tn_t))) 
              {
                nerr++;
              }
            break;
          }
          
        case none_nlp_service_tn_t: 
          {
            // Pomit branch: cannot accumulate
            break;
          }
          
        case nlp_service_tn_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_service_tn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,nlp_service_tn_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "opt nlp_service_tn_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Opt tag","tag",-1,(Pint32_map_fn) nlp_service_tn_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.some_nlp_service_tn_t",prefix);
  if (P_ERR==pn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->some_nlp_service_tn_t))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  // Pomit branch: cannot accumulate
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t nlp_service_tn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,nlp_service_tn_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = nlp_service_tn_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t nlp_service_tn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nlp_service_tn_t_m *m,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("nlp_service_tn_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case some_nlp_service_tn_t: 
      {
        PCGEN_FMT2BUF_UNION ("pn_t_fmt2buf",pn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->some_nlp_service_tn_t),&((pd->val).some_nlp_service_tn_t),&((rep->val).some_nlp_service_tn_t)),"some_nlp_service_tn_t");
        break;
      }
      
    case none_nlp_service_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_service_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t nlp_service_tn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nlp_service_tn_t_m *m,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("nlp_service_tn_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"nlp_service_tn_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn));
  return nlp_service_tn_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn);
}
ssize_t nlp_service_tn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,nlp_service_tn_t_m *m,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_service_tn_t_fmt2io",nlp_service_tn_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn));
  return -1;
}
PDCI_node_t *nlp_service_tn_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (nlp_service_tn_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *nlp_service_tn_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (nlp_service_tn_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *nlp_service_tn_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (nlp_service_tn_t);
  UNION_NODE_KC_CASE (nlp_service_tn_t,some_nlp_service_tn_t,pn_t);
  UNION_NODE_KC_CASE_LITERAL (nlp_service_tn_t,none_nlp_service_tn_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nlp_service_tn_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (nlp_service_tn_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *nlp_service_tn_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (nlp_service_tn_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nlp_service_tn_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (nlp_service_tn_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *nlp_service_tn_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (nlp_service_tn_t);
  UNION_SND_NODE_KC_CASE (nlp_service_tn_t,some_nlp_service_tn_t,pn_t);
  UNION_SND_NODE_KC_CASE_LITERAL (nlp_service_tn_t,none_nlp_service_tn_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t nlp_service_tn_t_node_pathWalk (P_t *pads,nlp_service_tn_t_m *m,nlp_service_tn_t_pd *pd,nlp_service_tn_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (nlp_service_tn_t);
  UNION_NODE_PW_CASE (some_nlp_service_tn_t,pn_t);
  UNION_NODE_PW_CASE_LITERAL (nlp_service_tn_t,none_nlp_service_tn_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const nlp_service_tn_t_node_vtable={nlp_service_tn_t_cachedNode_init,nlp_service_tn_t_node_kthChild,nlp_service_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nlp_service_tn_t_cachedNode_vtable={PDCI_error_cachedNode_init,nlp_service_tn_t_cachedNode_kthChild,nlp_service_tn_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nlp_service_tn_t_sndNode_vtable={PDCI_error_cachedNode_init,nlp_service_tn_t_sndNode_kthChild,nlp_service_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t nlp_billing_tn_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nlp_billing_tn_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case some_nlp_billing_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_nlp_billing_tn_t),&((rep->val).some_nlp_billing_tn_t));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_nlp_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t nlp_billing_tn_t_write2io (P_t *pads,Sfio_t *io,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_billing_tn_t_write2io",nlp_billing_tn_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn));
  return -1;
}
ssize_t nlp_billing_tn_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nlp_billing_tn_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("nlp_billing_tn_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case some_nlp_billing_tn_t: 
      {
        tlen_PCGEN_ = pn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_nlp_billing_tn_t),&((rep->val).some_nlp_billing_tn_t),"some_nlp_billing_tn_t",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_nlp_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t nlp_billing_tn_t_write_xml_2io (P_t *pads,Sfio_t *io,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_billing_tn_t_write_xml_2io",nlp_billing_tn_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn));
  return -1;
}
char const *nlp_billing_tn_t_tag2str (nlp_billing_tn_t_tag which)
{
  switch (which)
    {
      
    case some_nlp_billing_tn_t: 
      {
        return "some_nlp_billing_tn_t";
      }
      
    case none_nlp_billing_tn_t: 
      {
        return "none_nlp_billing_tn_t";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t nlp_billing_tn_t_init (P_t *pads,nlp_billing_tn_t *rep)
{
  return P_OK;
}
Perror_t nlp_billing_tn_t_pd_init (P_t *pads,nlp_billing_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t nlp_billing_tn_t_cleanup (P_t *pads,nlp_billing_tn_t *rep)
{
  return P_OK;
}
Perror_t nlp_billing_tn_t_pd_cleanup (P_t *pads,nlp_billing_tn_t_pd *pd)
{
  return P_OK;
}
Perror_t nlp_billing_tn_t_copy (P_t *pads,nlp_billing_tn_t *rep_dst,nlp_billing_tn_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("nlp_billing_tn_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(nlp_billing_tn_t));
  return P_OK;
}
Perror_t nlp_billing_tn_t_pd_copy (P_t *pads,nlp_billing_tn_t_pd *pd_dst,nlp_billing_tn_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("nlp_billing_tn_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(nlp_billing_tn_t_pd));
  return P_OK;
}
void nlp_billing_tn_t_m_init (P_t *pads,nlp_billing_tn_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(nlp_billing_tn_t_m));
}
Perror_t nlp_billing_tn_t_read (P_t *pads,nlp_billing_tn_t_m *m,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  PDCI_IODISC_3P_CHECKS ("nlp_billing_tn_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Puint32 none_nlp_billing_tn_t_Ptmp_;
    {
      PCGEN_UNION_READ_SETUP_STAT ("nlp_billing_tn_t_read",some_nlp_billing_tn_t,nlp_billing_tn_t_cleanup,nlp_billing_tn_t_init,nlp_billing_tn_t_copy,nlp_billing_tn_t_pd_cleanup,nlp_billing_tn_t_pd_init,nlp_billing_tn_t_pd_copy);
      // Read branch 'some_nlp_billing_tn_t'
      PCGEN_UNION_READ_STAT ("nlp_billing_tn_t_read","some_nlp_billing_tn_t",some_nlp_billing_tn_t,nlp_billing_tn_t_cleanup,nlp_billing_tn_t_init,nlp_billing_tn_t_copy,nlp_billing_tn_t_pd_cleanup,nlp_billing_tn_t_pd_init,nlp_billing_tn_t_pd_copy,pn_t_read (pads,&(m->some_nlp_billing_tn_t),&((pd->val).some_nlp_billing_tn_t),&((rep->val).some_nlp_billing_tn_t)),nlp_billing_tn_t_write_xml_2io (pads,sfstderr,pd,rep,"nlp_billing_tn_t",4,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn),_NOOP);
      // Pcompute branch 'none_nlp_billing_tn_t'
      PCGEN_UNION_READ_MAN_STAT_VIRT_PRE ("nlp_billing_tn_t_read",none_nlp_billing_tn_t,nlp_billing_tn_t_init,nlp_billing_tn_t_pd_init);
      none_nlp_billing_tn_t_Ptmp_ = 0;
      PCGEN_UNION_READ_MAN_STAT_POST ("nlp_billing_tn_t_read",nlp_billing_tn_t_copy,nlp_billing_tn_t_cleanup,nlp_billing_tn_t_pd_copy,nlp_billing_tn_t_pd_cleanup);
      // Failed to match any branch of union nlp_billing_tn_t
      PCGEN_UNION_READ_CHECK_FAILED ("nlp_billing_tn_t_read","nlp_billing_tn_t",nlp_billing_tn_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int nlp_billing_tn_t_verify (nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case some_nlp_billing_tn_t: 
      {
        isValid = pn_t_verify (&((rep->val).some_nlp_billing_tn_t));
        break;
      }
      
    case none_nlp_billing_tn_t: 
      {
        // Pomit branch: no user constraint
        break;
      }
      
    case nlp_billing_tn_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t nlp_billing_tn_t_acc_init (P_t *pads,nlp_billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_init (pads,&(acc->some_nlp_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_billing_tn_t_acc_reset (P_t *pads,nlp_billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_reset (pads,&(acc->some_nlp_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_billing_tn_t_acc_cleanup (P_t *pads,nlp_billing_tn_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==pn_t_acc_cleanup (pads,&(acc->some_nlp_billing_tn_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_billing_tn_t_acc_add (P_t *pads,nlp_billing_tn_t_acc *acc,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case some_nlp_billing_tn_t: 
          {
            if (P_ERR==pn_t_acc_add (pads,&(acc->some_nlp_billing_tn_t),&((pd->val).some_nlp_billing_tn_t),&((rep->val).some_nlp_billing_tn_t))) 
              {
                nerr++;
              }
            break;
          }
          
        case none_nlp_billing_tn_t: 
          {
            // Pomit branch: cannot accumulate
            break;
          }
          
        case nlp_billing_tn_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nlp_billing_tn_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,nlp_billing_tn_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "opt nlp_billing_tn_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Opt tag","tag",-1,(Pint32_map_fn) nlp_billing_tn_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.some_nlp_billing_tn_t",prefix);
  if (P_ERR==pn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->some_nlp_billing_tn_t))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  // Pomit branch: cannot accumulate
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t nlp_billing_tn_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,nlp_billing_tn_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = nlp_billing_tn_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t nlp_billing_tn_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nlp_billing_tn_t_m *m,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("nlp_billing_tn_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case some_nlp_billing_tn_t: 
      {
        PCGEN_FMT2BUF_UNION ("pn_t_fmt2buf",pn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->some_nlp_billing_tn_t),&((pd->val).some_nlp_billing_tn_t),&((rep->val).some_nlp_billing_tn_t)),"some_nlp_billing_tn_t");
        break;
      }
      
    case none_nlp_billing_tn_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case nlp_billing_tn_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t nlp_billing_tn_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nlp_billing_tn_t_m *m,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("nlp_billing_tn_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"nlp_billing_tn_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn));
  return nlp_billing_tn_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn);
}
ssize_t nlp_billing_tn_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,nlp_billing_tn_t_m *m,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nlp_billing_tn_t_fmt2io",nlp_billing_tn_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn));
  return -1;
}
PDCI_node_t *nlp_billing_tn_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (nlp_billing_tn_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *nlp_billing_tn_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (nlp_billing_tn_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *nlp_billing_tn_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (nlp_billing_tn_t);
  UNION_NODE_KC_CASE (nlp_billing_tn_t,some_nlp_billing_tn_t,pn_t);
  UNION_NODE_KC_CASE_LITERAL (nlp_billing_tn_t,none_nlp_billing_tn_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nlp_billing_tn_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (nlp_billing_tn_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *nlp_billing_tn_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (nlp_billing_tn_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nlp_billing_tn_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (nlp_billing_tn_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *nlp_billing_tn_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (nlp_billing_tn_t);
  UNION_SND_NODE_KC_CASE (nlp_billing_tn_t,some_nlp_billing_tn_t,pn_t);
  UNION_SND_NODE_KC_CASE_LITERAL (nlp_billing_tn_t,none_nlp_billing_tn_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t nlp_billing_tn_t_node_pathWalk (P_t *pads,nlp_billing_tn_t_m *m,nlp_billing_tn_t_pd *pd,nlp_billing_tn_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (nlp_billing_tn_t);
  UNION_NODE_PW_CASE (some_nlp_billing_tn_t,pn_t);
  UNION_NODE_PW_CASE_LITERAL (nlp_billing_tn_t,none_nlp_billing_tn_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const nlp_billing_tn_t_node_vtable={nlp_billing_tn_t_cachedNode_init,nlp_billing_tn_t_node_kthChild,nlp_billing_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nlp_billing_tn_t_cachedNode_vtable={PDCI_error_cachedNode_init,nlp_billing_tn_t_cachedNode_kthChild,nlp_billing_tn_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nlp_billing_tn_t_sndNode_vtable={PDCI_error_cachedNode_init,nlp_billing_tn_t_sndNode_kthChild,nlp_billing_tn_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t zip_code_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("zip_code_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case some_zip_code_t: 
      {
        tlen_PCGEN_ = Pzip_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_zip_code_t),&((rep->val).some_zip_code_t));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_zip_code_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case zip_code_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t zip_code_t_write2io (P_t *pads,Sfio_t *io,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zip_code_t_write2io",zip_code_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn));
  return -1;
}
ssize_t zip_code_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,zip_code_t_pd *pd,zip_code_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("zip_code_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("zip_code_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case some_zip_code_t: 
      {
        tlen_PCGEN_ = Pzip_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).some_zip_code_t),&((rep->val).some_zip_code_t),"some_zip_code_t",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case none_zip_code_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case zip_code_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t zip_code_t_write_xml_2io (P_t *pads,Sfio_t *io,zip_code_t_pd *pd,zip_code_t *rep,char const *tag,int indent,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zip_code_t_write_xml_2io",zip_code_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn));
  return -1;
}
char const *zip_code_t_tag2str (zip_code_t_tag which)
{
  switch (which)
    {
      
    case some_zip_code_t: 
      {
        return "some_zip_code_t";
      }
      
    case none_zip_code_t: 
      {
        return "none_zip_code_t";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t zip_code_t_init (P_t *pads,zip_code_t *rep)
{
  return P_OK;
}
Perror_t zip_code_t_pd_init (P_t *pads,zip_code_t_pd *pd)
{
  return P_OK;
}
Perror_t zip_code_t_cleanup (P_t *pads,zip_code_t *rep)
{
  return P_OK;
}
Perror_t zip_code_t_pd_cleanup (P_t *pads,zip_code_t_pd *pd)
{
  return P_OK;
}
Perror_t zip_code_t_copy (P_t *pads,zip_code_t *rep_dst,zip_code_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("zip_code_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(zip_code_t));
  return P_OK;
}
Perror_t zip_code_t_pd_copy (P_t *pads,zip_code_t_pd *pd_dst,zip_code_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("zip_code_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(zip_code_t_pd));
  return P_OK;
}
void zip_code_t_m_init (P_t *pads,zip_code_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(zip_code_t_m));
}
Perror_t zip_code_t_read (P_t *pads,zip_code_t_m *m,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  PDCI_IODISC_3P_CHECKS ("zip_code_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Puint32 none_zip_code_t_Ptmp_;
    {
      PCGEN_UNION_READ_SETUP_STAT ("zip_code_t_read",some_zip_code_t,zip_code_t_cleanup,zip_code_t_init,zip_code_t_copy,zip_code_t_pd_cleanup,zip_code_t_pd_init,zip_code_t_pd_copy);
      // Read branch 'some_zip_code_t'
      PCGEN_UNION_READ_STAT ("zip_code_t_read","some_zip_code_t",some_zip_code_t,zip_code_t_cleanup,zip_code_t_init,zip_code_t_copy,zip_code_t_pd_cleanup,zip_code_t_pd_init,zip_code_t_pd_copy,Pzip_read (pads,&(m->some_zip_code_t),&((pd->val).some_zip_code_t),&((rep->val).some_zip_code_t)),zip_code_t_write_xml_2io (pads,sfstderr,pd,rep,"zip_code_t",4,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn),_NOOP);
      // Pcompute branch 'none_zip_code_t'
      PCGEN_UNION_READ_MAN_STAT_VIRT_PRE ("zip_code_t_read",none_zip_code_t,zip_code_t_init,zip_code_t_pd_init);
      none_zip_code_t_Ptmp_ = 0;
      PCGEN_UNION_READ_MAN_STAT_POST ("zip_code_t_read",zip_code_t_copy,zip_code_t_cleanup,zip_code_t_pd_copy,zip_code_t_pd_cleanup);
      // Failed to match any branch of union zip_code_t
      PCGEN_UNION_READ_CHECK_FAILED ("zip_code_t_read","zip_code_t",zip_code_t_err);
      
    branches_done: 
      {
      }
      
    final_check: 
      {
      }
    }
    return ((pd->nerr)==0) ? P_OK : P_ERR;
  }
}
int zip_code_t_verify (zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case some_zip_code_t: 
      {
        isValid = Pzip_verify (&((rep->val).some_zip_code_t));
        break;
      }
      
    case none_zip_code_t: 
      {
        // Pomit branch: no user constraint
        break;
      }
      
    case zip_code_t_err: 
      {
        // error case
        {
          isValid = 0;
          break;
        }
      }
    }
  return isValid;
}
Perror_t zip_code_t_acc_init (P_t *pads,zip_code_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pzip_acc_init (pads,&(acc->some_zip_code_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t zip_code_t_acc_reset (P_t *pads,zip_code_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pzip_acc_reset (pads,&(acc->some_zip_code_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t zip_code_t_acc_cleanup (P_t *pads,zip_code_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Pzip_acc_cleanup (pads,&(acc->some_zip_code_t))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t zip_code_t_acc_add (P_t *pads,zip_code_t_acc *acc,zip_code_t_pd *pd,zip_code_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (((pd->errCode)==P_UNION_MATCH_ERR) ? P_UNION_MATCH_ERR : P_NO_ERR);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pint32_acc_add (pads,&(acc->tag),&tpd,(Pint32 *) (&(rep->tag)))) 
        {
          nerr++;
        }
      switch (rep->tag)
        {
          
        case some_zip_code_t: 
          {
            if (P_ERR==Pzip_acc_add (pads,&(acc->some_zip_code_t),&((pd->val).some_zip_code_t),&((rep->val).some_zip_code_t))) 
              {
                nerr++;
              }
            break;
          }
          
        case none_zip_code_t: 
          {
            // Pomit branch: cannot accumulate
            break;
          }
          
        case zip_code_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t zip_code_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,zip_code_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "opt zip_code_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Opt tag","tag",-1,(Pint32_map_fn) zip_code_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.some_zip_code_t",prefix);
  if (P_ERR==Pzip_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->some_zip_code_t))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  // Pomit branch: cannot accumulate
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t zip_code_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,zip_code_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = zip_code_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t zip_code_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zip_code_t_m *m,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("zip_code_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case some_zip_code_t: 
      {
        PCGEN_FMT2BUF_UNION ("Pzip_fmt2buf",Pzip_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->some_zip_code_t),&((pd->val).some_zip_code_t),&((rep->val).some_zip_code_t)),"some_zip_code_t");
        break;
      }
      
    case none_zip_code_t: 
      {
        // Pomit branch: cannot output
        break;
      }
      
    case zip_code_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t zip_code_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,zip_code_t_m *m,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("zip_code_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"zip_code_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn));
  return zip_code_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn);
}
ssize_t zip_code_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,zip_code_t_m *m,zip_code_t_pd *pd,zip_code_t *rep,Puint32 *order_num,Puint32 *att_order_num,Puint32 *ord_version,service_tn_t *service_tn,billing_tn_t *billing_tn,nlp_service_tn_t *nlp_service_tn,nlp_billing_tn_t *nlp_billing_tn)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("zip_code_t_fmt2io",zip_code_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep,order_num,att_order_num,ord_version,service_tn,billing_tn,nlp_service_tn,nlp_billing_tn));
  return -1;
}
PDCI_node_t *zip_code_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (zip_code_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *zip_code_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (zip_code_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *zip_code_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (zip_code_t);
  UNION_NODE_KC_CASE (zip_code_t,some_zip_code_t,Pzip);
  UNION_NODE_KC_CASE_LITERAL (zip_code_t,none_zip_code_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *zip_code_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (zip_code_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *zip_code_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (zip_code_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *zip_code_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (zip_code_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *zip_code_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (zip_code_t);
  UNION_SND_NODE_KC_CASE (zip_code_t,some_zip_code_t,Pzip);
  UNION_SND_NODE_KC_CASE_LITERAL (zip_code_t,none_zip_code_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t zip_code_t_node_pathWalk (P_t *pads,zip_code_t_m *m,zip_code_t_pd *pd,zip_code_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (zip_code_t);
  UNION_NODE_PW_CASE (some_zip_code_t,Pzip);
  UNION_NODE_PW_CASE_LITERAL (zip_code_t,none_zip_code_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const zip_code_t_node_vtable={zip_code_t_cachedNode_init,zip_code_t_node_kthChild,zip_code_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const zip_code_t_cachedNode_vtable={PDCI_error_cachedNode_init,zip_code_t_cachedNode_kthChild,zip_code_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const zip_code_t_sndNode_vtable={PDCI_error_cachedNode_init,zip_code_t_sndNode_kthChild,zip_code_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t order_header_t_init (P_t *pads,order_header_t *rep)
{
  PDCI_DISC_1P_CHECKS ("order_header_t_init",rep);
  memset ((void *) rep,0,sizeof(order_header_t));
  return P_OK;
}
Perror_t order_header_t_pd_init (P_t *pads,order_header_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("order_header_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(order_header_t_pd));
  return P_OK;
}
Perror_t order_header_t_cleanup (P_t *pads,order_header_t *rep)
{
  PDCI_DISC_1P_CHECKS ("order_header_t_cleanup",rep);
  Pstring_cleanup (pads,&(rep->order_type));
  Pstring_cleanup (pads,&(rep->unused));
  Pstring_cleanup (pads,&(rep->stream));
  return P_OK;
}
Perror_t order_header_t_pd_cleanup (P_t *pads,order_header_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("order_header_t_pd_cleanup",pd);
  Pstring_pd_cleanup (pads,&(pd->order_type));
  Pstring_pd_cleanup (pads,&(pd->unused));
  Pstring_pd_cleanup (pads,&(pd->stream));
  return P_OK;
}
Perror_t order_header_t_copy (P_t *pads,order_header_t *rep_dst,order_header_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("order_header_t_copy",rep_src,rep_dst);
  // Copy fields order_num, att_order_num, ord_version, service_tn, billing_tn, nlp_service_tn, nlp_billing_tn, zip_code, ramp
  memcpy ((void *) (&(rep_dst->order_num)),(void *) (&(rep_src->order_num)),((((((((sizeof(Puint32))+(sizeof(Puint32)))+(sizeof(Puint32)))+(sizeof(service_tn_t)))+(sizeof(billing_tn_t)))+(sizeof(nlp_service_tn_t)))+(sizeof(nlp_billing_tn_t)))+(sizeof(zip_code_t)))+(sizeof(dib_ramp_t)));
  Pstring_copy (pads,&(rep_dst->order_type),&(rep_src->order_type));
  memcpy ((void *) (&(rep_dst->order_details)),(void *) (&(rep_src->order_details)),sizeof(Puint32));
  Pstring_copy (pads,&(rep_dst->unused),&(rep_src->unused));
  Pstring_copy (pads,&(rep_dst->stream),&(rep_src->stream));
  return P_OK;
}
Perror_t order_header_t_pd_copy (P_t *pads,order_header_t_pd *pd_dst,order_header_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("order_header_t_pd_copy",pd_src,pd_dst);
  // Copy fields order_num, att_order_num, ord_version, service_tn, billing_tn, nlp_service_tn, nlp_billing_tn, zip_code, ramp
  memcpy ((void *) (&(pd_dst->order_num)),(void *) (&(pd_src->order_num)),((((((((sizeof(Pbase_pd))+(sizeof(Pbase_pd)))+(sizeof(Pbase_pd)))+(sizeof(service_tn_t_pd)))+(sizeof(billing_tn_t_pd)))+(sizeof(nlp_service_tn_t_pd)))+(sizeof(nlp_billing_tn_t_pd)))+(sizeof(zip_code_t_pd)))+(sizeof(dib_ramp_t_pd)));
  Pstring_pd_copy (pads,&(pd_dst->order_type),&(pd_src->order_type));
  memcpy ((void *) (&(pd_dst->order_details)),(void *) (&(pd_src->order_details)),sizeof(Pbase_pd));
  Pstring_pd_copy (pads,&(pd_dst->unused),&(pd_src->unused));
  Pstring_pd_copy (pads,&(pd_dst->stream),&(pd_src->stream));
  return P_OK;
}
void order_header_t_m_init (P_t *pads,order_header_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(order_header_t_m));
}
Perror_t order_header_t_read (P_t *pads,order_header_t_m *m,order_header_t_pd *pd,order_header_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("order_header_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'order_num'
  PCGEN_STRUCT_READ_FIRST ("order_header_t_read",order_num,Puint32_read (pads,&(m->order_num),&(pd->order_num),&(rep->order_num)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'att_order_num'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",att_order_num,Puint32_read (pads,&(m->att_order_num),&(pd->att_order_num),&(rep->att_order_num)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'ord_version'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",ord_version,Puint32_read (pads,&(m->ord_version),&(pd->ord_version),&(rep->ord_version)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'service_tn'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",service_tn,service_tn_t_read (pads,&(m->service_tn),&(pd->service_tn),&(rep->service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'billing_tn'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",billing_tn,billing_tn_t_read (pads,&(m->billing_tn),&(pd->billing_tn),&(rep->billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'nlp_service_tn'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",nlp_service_tn,nlp_service_tn_t_read (pads,&(m->nlp_service_tn),&(pd->nlp_service_tn),&(rep->nlp_service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'nlp_billing_tn'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",nlp_billing_tn,nlp_billing_tn_t_read (pads,&(m->nlp_billing_tn),&(pd->nlp_billing_tn),&(rep->nlp_billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'zip_code'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",zip_code,zip_code_t_read (pads,&(m->zip_code),&(pd->zip_code),&(rep->zip_code),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn),&(rep->nlp_billing_tn)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'ramp'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",ramp,dib_ramp_t_read (pads,&(m->ramp),&(pd->ramp),&(rep->ramp)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'order_type'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",order_type,Pstring_read (pads,&(m->order_type),&(pd->order_type),&(rep->order_type),124),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'order_details'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",order_details,Puint32_read (pads,&(m->order_details),&(pd->order_details),&(rep->order_details)),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'unused'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",unused,Pstring_read (pads,&(m->unused),&(pd->unused),&(rep->unused),124),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  // Read field 'stream'
  PCGEN_STRUCT_READ_NEXT ("order_header_t_read",stream,Pstring_read (pads,&(m->stream),&(pd->stream),&(rep->stream),124),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("order_header_t_read",124);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int order_header_t_verify (order_header_t *rep)
{
  return service_tn_t_verify (&(rep->service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version))&&(billing_tn_t_verify (&(rep->billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn))&&(nlp_service_tn_t_verify (&(rep->nlp_service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn))&&(nlp_billing_tn_t_verify (&(rep->nlp_billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn))&&(zip_code_t_verify (&(rep->zip_code),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn),&(rep->nlp_billing_tn))&&(dib_ramp_t_verify (&(rep->ramp))&&1)))));
}
Perror_t order_header_t_acc_init (P_t *pads,order_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->att_order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->ord_version))) 
    {
      nerr++;
    }
  if (P_ERR==service_tn_t_acc_init (pads,&(acc->service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==billing_tn_t_acc_init (pads,&(acc->billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_service_tn_t_acc_init (pads,&(acc->nlp_service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_billing_tn_t_acc_init (pads,&(acc->nlp_billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==zip_code_t_acc_init (pads,&(acc->zip_code))) 
    {
      nerr++;
    }
  if (P_ERR==dib_ramp_t_acc_init (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->order_type))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->order_details))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->unused))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->stream))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t order_header_t_acc_reset (P_t *pads,order_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->att_order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->ord_version))) 
    {
      nerr++;
    }
  if (P_ERR==service_tn_t_acc_reset (pads,&(acc->service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==billing_tn_t_acc_reset (pads,&(acc->billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_service_tn_t_acc_reset (pads,&(acc->nlp_service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_billing_tn_t_acc_reset (pads,&(acc->nlp_billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==zip_code_t_acc_reset (pads,&(acc->zip_code))) 
    {
      nerr++;
    }
  if (P_ERR==dib_ramp_t_acc_reset (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->order_type))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->order_details))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->unused))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->stream))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t order_header_t_acc_cleanup (P_t *pads,order_header_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->att_order_num))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->ord_version))) 
    {
      nerr++;
    }
  if (P_ERR==service_tn_t_acc_cleanup (pads,&(acc->service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==billing_tn_t_acc_cleanup (pads,&(acc->billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_service_tn_t_acc_cleanup (pads,&(acc->nlp_service_tn))) 
    {
      nerr++;
    }
  if (P_ERR==nlp_billing_tn_t_acc_cleanup (pads,&(acc->nlp_billing_tn))) 
    {
      nerr++;
    }
  if (P_ERR==zip_code_t_acc_cleanup (pads,&(acc->zip_code))) 
    {
      nerr++;
    }
  if (P_ERR==dib_ramp_t_acc_cleanup (pads,&(acc->ramp))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->order_type))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->order_details))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->unused))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->stream))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t order_header_t_acc_add (P_t *pads,order_header_t_acc *acc,order_header_t_pd *pd,order_header_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint32_acc_add (pads,&(acc->order_num),&(pd->order_num),&(rep->order_num))) 
        {
          nerr++;
        }
      if (P_ERR==Puint32_acc_add (pads,&(acc->att_order_num),&(pd->att_order_num),&(rep->att_order_num))) 
        {
          nerr++;
        }
      if (P_ERR==Puint32_acc_add (pads,&(acc->ord_version),&(pd->ord_version),&(rep->ord_version))) 
        {
          nerr++;
        }
      if (P_ERR==service_tn_t_acc_add (pads,&(acc->service_tn),&(pd->service_tn),&(rep->service_tn))) 
        {
          nerr++;
        }
      if (P_ERR==billing_tn_t_acc_add (pads,&(acc->billing_tn),&(pd->billing_tn),&(rep->billing_tn))) 
        {
          nerr++;
        }
      if (P_ERR==nlp_service_tn_t_acc_add (pads,&(acc->nlp_service_tn),&(pd->nlp_service_tn),&(rep->nlp_service_tn))) 
        {
          nerr++;
        }
      if (P_ERR==nlp_billing_tn_t_acc_add (pads,&(acc->nlp_billing_tn),&(pd->nlp_billing_tn),&(rep->nlp_billing_tn))) 
        {
          nerr++;
        }
      if (P_ERR==zip_code_t_acc_add (pads,&(acc->zip_code),&(pd->zip_code),&(rep->zip_code))) 
        {
          nerr++;
        }
      if (P_ERR==dib_ramp_t_acc_add (pads,&(acc->ramp),&(pd->ramp),&(rep->ramp))) 
        {
          nerr++;
        }
      if (P_ERR==Pstring_acc_add (pads,&(acc->order_type),&(pd->order_type),&(rep->order_type))) 
        {
          nerr++;
        }
      if (P_ERR==Puint32_acc_add (pads,&(acc->order_details),&(pd->order_details),&(rep->order_details))) 
        {
          nerr++;
        }
      if (P_ERR==Pstring_acc_add (pads,&(acc->unused),&(pd->unused),&(rep->unused))) 
        {
          nerr++;
        }
      if (P_ERR==Pstring_acc_add (pads,&(acc->stream),&(pd->stream),&(rep->stream))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t order_header_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,order_header_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct order_header_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.order_num",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->order_num))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.att_order_num",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->att_order_num))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.ord_version",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->ord_version))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.service_tn",prefix);
  if (P_ERR==service_tn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->service_tn))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.billing_tn",prefix);
  if (P_ERR==billing_tn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->billing_tn))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.nlp_service_tn",prefix);
  if (P_ERR==nlp_service_tn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->nlp_service_tn))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.nlp_billing_tn",prefix);
  if (P_ERR==nlp_billing_tn_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->nlp_billing_tn))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.zip_code",prefix);
  if (P_ERR==zip_code_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->zip_code))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.ramp",prefix);
  if (P_ERR==dib_ramp_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->ramp))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.order_type",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->order_type))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.order_details",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->order_details))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.unused",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->unused))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.stream",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->stream))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t order_header_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,order_header_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = order_header_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t order_header_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,order_header_t_pd *pd,order_header_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("order_header_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_num),&(rep->order_num));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->att_order_num),&(rep->att_order_num));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ord_version),&(rep->ord_version));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = service_tn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->service_tn),&(rep->service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = billing_tn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->billing_tn),&(rep->billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = nlp_service_tn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->nlp_service_tn),&(rep->nlp_service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = nlp_billing_tn_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->nlp_billing_tn),&(rep->nlp_billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = zip_code_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->zip_code),&(rep->zip_code),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn),&(rep->nlp_billing_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = dib_ramp_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ramp),&(rep->ramp));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_type),&(rep->order_type),124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_details),&(rep->order_details));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->unused),&(rep->unused),124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->stream),&(rep->stream),124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t order_header_t_write2io (P_t *pads,Sfio_t *io,order_header_t_pd *pd,order_header_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("order_header_t_write2io",order_header_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t order_header_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,order_header_t_pd *pd,order_header_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("order_header_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("order_header_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_num),&(rep->order_num),"order_num",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->att_order_num),&(rep->att_order_num),"att_order_num",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ord_version),&(rep->ord_version),"ord_version",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = service_tn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->service_tn),&(rep->service_tn),"service_tn",indent+2,&(rep->order_num),&(rep->att_order_num),&(rep->ord_version));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = billing_tn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->billing_tn),&(rep->billing_tn),"billing_tn",indent+2,&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = nlp_service_tn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->nlp_service_tn),&(rep->nlp_service_tn),"nlp_service_tn",indent+2,&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = nlp_billing_tn_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->nlp_billing_tn),&(rep->nlp_billing_tn),"nlp_billing_tn",indent+2,&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = zip_code_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->zip_code),&(rep->zip_code),"zip_code",indent+2,&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn),&(rep->nlp_billing_tn));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = dib_ramp_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ramp),&(rep->ramp),"ramp",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_type),&(rep->order_type),"order_type",indent+2,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->order_details),&(rep->order_details),"order_details",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->unused),&(rep->unused),"unused",indent+2,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->stream),&(rep->stream),"stream",indent+2,124);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t order_header_t_write_xml_2io (P_t *pads,Sfio_t *io,order_header_t_pd *pd,order_header_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("order_header_t_write_xml_2io",order_header_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t order_header_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,order_header_t_m *m,order_header_t_pd *pd,order_header_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("order_header_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->order_num),&(pd->order_num),&(rep->order_num)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->att_order_num),&(pd->att_order_num),&(rep->att_order_num)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->ord_version),&(pd->ord_version),&(rep->ord_version)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("service_tn_t_fmt2buf",service_tn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->service_tn),&(pd->service_tn),&(rep->service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("billing_tn_t_fmt2buf",billing_tn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->billing_tn),&(pd->billing_tn),&(rep->billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("nlp_service_tn_t_fmt2buf",nlp_service_tn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->nlp_service_tn),&(pd->nlp_service_tn),&(rep->nlp_service_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("nlp_billing_tn_t_fmt2buf",nlp_billing_tn_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->nlp_billing_tn),&(pd->nlp_billing_tn),&(rep->nlp_billing_tn),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("zip_code_t_fmt2buf",zip_code_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->zip_code),&(pd->zip_code),&(rep->zip_code),&(rep->order_num),&(rep->att_order_num),&(rep->ord_version),&(rep->service_tn),&(rep->billing_tn),&(rep->nlp_service_tn),&(rep->nlp_billing_tn)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("dib_ramp_t_fmt2buf",dib_ramp_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->ramp),&(pd->ramp),&(rep->ramp)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->order_type),&(pd->order_type),&(rep->order_type),124));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->order_details),&(pd->order_details),&(rep->order_details)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->unused),&(pd->unused),&(rep->unused),124));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->stream),&(pd->stream),&(rep->stream),124));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t order_header_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,order_header_t_m *m,order_header_t_pd *pd,order_header_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("order_header_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"order_header_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return order_header_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t order_header_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,order_header_t_m *m,order_header_t_pd *pd,order_header_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("order_header_t_fmt2io",order_header_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *order_header_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (order_header_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *order_header_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (order_header_t,14);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *order_header_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (order_header_t);
  NODE_KC_CASE (order_header_t,0,Puint32,order_num);
  NODE_KC_CASE (order_header_t,1,Puint32,att_order_num);
  NODE_KC_CASE (order_header_t,2,Puint32,ord_version);
  NODE_KC_CASE (order_header_t,3,service_tn_t,service_tn);
  NODE_KC_CASE (order_header_t,4,billing_tn_t,billing_tn);
  NODE_KC_CASE (order_header_t,5,nlp_service_tn_t,nlp_service_tn);
  NODE_KC_CASE (order_header_t,6,nlp_billing_tn_t,nlp_billing_tn);
  NODE_KC_CASE (order_header_t,7,zip_code_t,zip_code);
  NODE_KC_CASE (order_header_t,8,dib_ramp_t,ramp);
  NODE_KC_CASE (order_header_t,9,Pstring,order_type);
  NODE_KC_CASE (order_header_t,10,Puint32,order_details);
  NODE_KC_CASE (order_header_t,11,Pstring,unused);
  NODE_KC_CASE (order_header_t,12,Pstring,stream);
  STR_NODE_KTH_CHILD_BODY_END (13);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *order_header_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (order_header_t,"order_num","att_order_num","ord_version","service_tn","billing_tn","nlp_service_tn","nlp_billing_tn","zip_code","ramp","order_type","order_details","unused","stream");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *order_header_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (order_header_t,14);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *order_header_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (order_header_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *order_header_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (order_header_t);
  SND_NODE_KC_CASE (order_header_t,0,Puint32,order_num);
  SND_NODE_KC_CASE (order_header_t,1,Puint32,att_order_num);
  SND_NODE_KC_CASE (order_header_t,2,Puint32,ord_version);
  SND_NODE_KC_CASE (order_header_t,3,service_tn_t,service_tn);
  SND_NODE_KC_CASE (order_header_t,4,billing_tn_t,billing_tn);
  SND_NODE_KC_CASE (order_header_t,5,nlp_service_tn_t,nlp_service_tn);
  SND_NODE_KC_CASE (order_header_t,6,nlp_billing_tn_t,nlp_billing_tn);
  SND_NODE_KC_CASE (order_header_t,7,zip_code_t,zip_code);
  SND_NODE_KC_CASE (order_header_t,8,dib_ramp_t,ramp);
  SND_NODE_KC_CASE (order_header_t,9,Pstring,order_type);
  SND_NODE_KC_CASE (order_header_t,10,Puint32,order_details);
  SND_NODE_KC_CASE (order_header_t,11,Pstring,unused);
  SND_NODE_KC_CASE (order_header_t,12,Pstring,stream);
  STR_SND_NODE_KTH_CHILD_BODY_END (13);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t order_header_t_node_pathWalk (P_t *pads,order_header_t_m *m,order_header_t_pd *pd,order_header_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Puint32,order_num);
  NODE_PW_CASE (1,Puint32,att_order_num);
  NODE_PW_CASE (2,Puint32,ord_version);
  NODE_PW_CASE (3,service_tn_t,service_tn);
  NODE_PW_CASE (4,billing_tn_t,billing_tn);
  NODE_PW_CASE (5,nlp_service_tn_t,nlp_service_tn);
  NODE_PW_CASE (6,nlp_billing_tn_t,nlp_billing_tn);
  NODE_PW_CASE (7,zip_code_t,zip_code);
  NODE_PW_CASE (8,dib_ramp_t,ramp);
  NODE_PW_CASE (9,Pstring,order_type);
  NODE_PW_CASE (10,Puint32,order_details);
  NODE_PW_CASE (11,Pstring,unused);
  NODE_PW_CASE (12,Pstring,stream);
  STR_NODE_PATH_WALK_BODY_END (13);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const order_header_t_node_vtable={order_header_t_cachedNode_init,order_header_t_node_kthChild,order_header_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const order_header_t_cachedNode_vtable={PDCI_error_cachedNode_init,order_header_t_cachedNode_kthChild,order_header_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const order_header_t_sndNode_vtable={PDCI_error_cachedNode_init,order_header_t_sndNode_kthChild,order_header_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t event_t_init (P_t *pads,event_t *rep)
{
  PDCI_DISC_1P_CHECKS ("event_t_init",rep);
  memset ((void *) rep,0,sizeof(event_t));
  return P_OK;
}
Perror_t event_t_pd_init (P_t *pads,event_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("event_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(event_t_pd));
  return P_OK;
}
Perror_t event_t_cleanup (P_t *pads,event_t *rep)
{
  PDCI_DISC_1P_CHECKS ("event_t_cleanup",rep);
  Pstring_cleanup (pads,&(rep->state));
  return P_OK;
}
Perror_t event_t_pd_cleanup (P_t *pads,event_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("event_t_pd_cleanup",pd);
  Pstring_pd_cleanup (pads,&(pd->state));
  return P_OK;
}
Perror_t event_t_copy (P_t *pads,event_t *rep_dst,event_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("event_t_copy",rep_src,rep_dst);
  Pstring_copy (pads,&(rep_dst->state),&(rep_src->state));
  memcpy ((void *) (&(rep_dst->tstamp)),(void *) (&(rep_src->tstamp)),sizeof(Puint32));
  return P_OK;
}
Perror_t event_t_pd_copy (P_t *pads,event_t_pd *pd_dst,event_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("event_t_pd_copy",pd_src,pd_dst);
  Pstring_pd_copy (pads,&(pd_dst->state),&(pd_src->state));
  memcpy ((void *) (&(pd_dst->tstamp)),(void *) (&(pd_src->tstamp)),sizeof(Pbase_pd));
  return P_OK;
}
void event_t_m_init (P_t *pads,event_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(event_t_m));
}
Perror_t event_t_read (P_t *pads,event_t_m *m,event_t_pd *pd,event_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("event_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'state'
  PCGEN_STRUCT_READ_FIRST ("event_t_read",state,Pstring_read (pads,&(m->state),&(pd->state),&(rep->state),124),_NOOP);
  // Read delimter field: '|'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("event_t_read",124);
  // Read field 'tstamp'
  PCGEN_STRUCT_READ_NEXT ("event_t_read",tstamp,Puint32_read (pads,&(m->tstamp),&(pd->tstamp),&(rep->tstamp)),_NOOP);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int event_t_verify (event_t *rep)
{
  return 1;
}
Perror_t event_t_acc_init (P_t *pads,event_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->state))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t event_t_acc_reset (P_t *pads,event_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->state))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t event_t_acc_cleanup (P_t *pads,event_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->state))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->tstamp))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t event_t_acc_add (P_t *pads,event_t_acc *acc,event_t_pd *pd,event_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Pstring_acc_add (pads,&(acc->state),&(pd->state),&(rep->state))) 
        {
          nerr++;
        }
      if (P_ERR==Puint32_acc_add (pads,&(acc->tstamp),&(pd->tstamp),&(rep->tstamp))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t event_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,event_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct event_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.state",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->state))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.tstamp",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->tstamp))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t event_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,event_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = event_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t event_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,event_t_pd *pd,event_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("event_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->state),&(rep->state),124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->tstamp),&(rep->tstamp));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t event_t_write2io (P_t *pads,Sfio_t *io,event_t_pd *pd,event_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("event_t_write2io",event_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t event_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,event_t_pd *pd,event_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("event_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("event_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->state),&(rep->state),"state",indent+2,124);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->tstamp),&(rep->tstamp),"tstamp",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t event_t_write_xml_2io (P_t *pads,Sfio_t *io,event_t_pd *pd,event_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("event_t_write_xml_2io",event_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t event_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,event_t_m *m,event_t_pd *pd,event_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("event_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->state),&(pd->state),&(rep->state),124));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->tstamp),&(pd->tstamp),&(rep->tstamp)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t event_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,event_t_m *m,event_t_pd *pd,event_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("event_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"event_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return event_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t event_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,event_t_m *m,event_t_pd *pd,event_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("event_t_fmt2io",event_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *event_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (event_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *event_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (event_t,3);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *event_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (event_t);
  NODE_KC_CASE (event_t,0,Pstring,state);
  NODE_KC_CASE (event_t,1,Puint32,tstamp);
  STR_NODE_KTH_CHILD_BODY_END (2);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *event_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (event_t,"state","tstamp");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *event_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (event_t,3);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *event_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (event_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *event_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (event_t);
  SND_NODE_KC_CASE (event_t,0,Pstring,state);
  SND_NODE_KC_CASE (event_t,1,Puint32,tstamp);
  STR_SND_NODE_KTH_CHILD_BODY_END (2);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t event_t_node_pathWalk (P_t *pads,event_t_m *m,event_t_pd *pd,event_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Pstring,state);
  NODE_PW_CASE (1,Puint32,tstamp);
  STR_NODE_PATH_WALK_BODY_END (2);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const event_t_node_vtable={event_t_cachedNode_init,event_t_node_kthChild,event_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const event_t_cachedNode_vtable={PDCI_error_cachedNode_init,event_t_cachedNode_kthChild,event_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const event_t_sndNode_vtable={PDCI_error_cachedNode_init,event_t_sndNode_kthChild,event_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t eventSeq_init (P_t *pads,eventSeq *rep)
{
  PDCI_DISC_1P_CHECKS ("eventSeq_init",rep);
  memset ((void *) rep,0,sizeof(eventSeq));
  return P_OK;
}
Perror_t eventSeq_pd_init (P_t *pads,eventSeq_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("eventSeq_pd_init",pd);
  memset ((void *) pd,0,sizeof(eventSeq_pd));
  return P_OK;
}
Perror_t eventSeq_cleanup (P_t *pads,eventSeq *rep)
{
  PDCI_DISC_1P_CHECKS ("eventSeq_cleanup",rep);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("eventSeq_cleanup",rep,event_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t eventSeq_pd_cleanup (P_t *pads,eventSeq_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("eventSeq_pd_cleanup",pd);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("eventSeq_pd_cleanup",pd,event_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t eventSeq_copy (P_t *pads,eventSeq *rep_dst,eventSeq *rep_src)
{
  PDCI_DISC_2P_CHECKS ("eventSeq_copy",rep_src,rep_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("eventSeq_copy",rep_src,rep_dst,event_t_copy,event_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t eventSeq_pd_copy (P_t *pads,eventSeq_pd *pd_dst,eventSeq_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("eventSeq_pd_copy",pd_src,pd_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("eventSeq_pd_copy",pd_src,pd_dst,event_t_pd_copy,event_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
void eventSeq_m_init (P_t *pads,eventSeq_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(eventSeq_m));
}
void eventSeq_ro_params_init (eventSeq_ro_params_t *params)
{
}
Pread_res_t eventSeq_final_checks (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep,Ploc_t *loc_ptr,int consume)
{
  PDCI_IODISC_3P_CHECKS ("eventSeq_final_checks",m,pd,rep);
  {
    PCGEN_ARRAY_UNSET_PARTIAL ();
    pd->length = (rep->length);
    // Checking user-defined array constraints
    if (P_Test_SemCheck (m->compoundLevel)&&(!P_PS_isPanic (pd))) 
      {
        // Checking Pforall constraint
        {
          int violated=0;
          {
            int i;
            ssize_t supper_PCGEN_=(ssize_t) ((rep->length)-2);
            ssize_t slength_PCGEN_=(ssize_t) (rep->length);
            if (!((0<=0)&&(supper_PCGEN_<slength_PCGEN_))) 
              {
                violated = 1;
              }
            for (i = 0; (!violated)&&((supper_PCGEN_>=0)&&(i<=((rep->length)-2))); i++)
              {
                if (!(((rep->elts)[i].tstamp)<=((rep->elts)[i+1].tstamp))) 
                  {
                    violated = 1;
                  }
              }
          }
          if (violated) 
            {
              if (!(pd->nerr)) 
                {
                  (pd->nerr)++;
                  pd->errCode = P_ARRAY_USER_CONSTRAINT_ERR;
                  PDCI_READFN_ENDLOC_MINUS1 (pads,*loc_ptr);
                  PDCI_report_err (pads,P_LEV_WARN,loc_ptr,pd->errCode,"eventSeq_read","Pforall constraint for array eventSeq violated");
                }
              else
                {
                  (pd->nerr)++;
                }
              if (P_spec_level (pads)) 
                return P_READ_ERR;
            }
        }
      }
    return PCGEN_ARRAY_RET_DONE (consume);
  }
}
Pread_res_t eventSeq_read_one_init (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep,Ploc_t *loc_ptr)
{
  PDCI_IODISC_3P_CHECKS ("eventSeq_read_one_init",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    rep->length = 0;
    pd->neerr = 0;
    pd->firstError = 0;
    pd->numRead = 0;
    PDCI_READFN_BEGINLOC (pads,*loc_ptr);
    if (0==(rep->_internal)) 
      {
        rep->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(rep->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"eventSeq_read","");
          }
      }
    if (0==(pd->_internal)) 
      {
        pd->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(pd->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"eventSeq_read","");
          }
      }
    if (P_PS_isPanic (pd)||P_io_at_eof (pads)) 
      PCGEN_ARRAY_DO_FINAL_CHECKS ();
    PDCI_READFN_BEGINLOC (pads,pd->loc);
    PCGEN_ARRAY_SET_PARTIAL ();
    return PCGEN_ARRAY_RET_ONGOING (0);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return eventSeq_final_checks (pads,m,pd,rep,loc_ptr,0);
  }
}
Pread_res_t eventSeq_read_one (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep,Ploc_t *loc_ptr,event_t_pd *elt_pd,event_t *elt_rep)
{
  PDCI_IODISC_3P_CHECKS ("eventSeq_read_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("eventSeq_read_one",elt_pd,elt_rep);
  {
    int haveData=0;
    PCGEN_ARRAY_RO_DECS ();
    PCGEN_ARRAY_TEST_ALREADY_DONE ();
    PCGEN_ARRAY_GET_BEGIN_LOC ();
    // Ready to read next element
    if ((pd->numRead)>0) 
      {
        // Array not finished; reading separator
        {
          size_t offset;
          PDCI_READFN_BEGINLOC (pads,pd->loc);
          if (P_OK==Pchar_lit_scan1 (pads,124,1,0,&offset)) 
            {
              if (P_Test_SynCheck (m->compoundLevel)) 
                {
                  if (offset) 
                    {
                      if (!(pd->nerr)) 
                        {
                          (pd->nerr)++;
                          pd->errCode = P_ARRAY_EXTRA_BEFORE_SEP;
                          PDCI_READFN_ENDLOC_MINUS2 (pads,pd->loc);
                          PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,"eventSeq_read",0);
                        }
                      else
                        {
                          (pd->nerr)++;
                        }
                      if (P_spec_level (pads)) 
                        return P_READ_ERR;
                    }
                }
            }
          else
            {
              // Error reading separator
              {
                if (!(pd->nerr)) 
                  {
                    (pd->nerr)++;
                    pd->errCode = P_ARRAY_SEP_ERR;
                    PDCI_READFN_ENDLOC_MINUS1 (pads,pd->loc);
                    PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,"eventSeq_read","Missing separator");
                  }
                else
                  {
                    (pd->nerr)++;
                  }
                if (P_spec_level (pads)) 
                  return P_READ_ERR;
                P_PS_setPanic (pd);
              }
              PCGEN_ARRAY_DO_FINAL_CHECKS ();
            }
        }
      }
    PCGEN_ARRAY_READ_ELEM_HD (event_t_read (pads,&(m->element),elt_pd,elt_rep),haveData);
    PCGEN_ARRAY_TEST_READ_ERR (1,1);
    if (P_PS_isPanic (elt_pd)) 
      {
        {
          size_t offset;
          // Try to recover to separator
          if (P_OK==Pchar_lit_scan1 (pads,124,1,1,&offset)) 
            {
              // We recovered; restored invariant
            }
          else
            {
              // Recovery failed
              P_PS_setPanic (pd);
              PCGEN_ARRAY_DO_FINAL_CHECKS ();
            }
        }
      }
    // Have we finished reading array?
    if (P_io_at_eof (pads)||P_io_at_eor (pads)) 
      {
        PCGEN_ARRAY_DO_FINAL_CHECKS ();
      }
    PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE2 ();
    return PCGEN_ARRAY_RET_ONGOING (1);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return eventSeq_final_checks (pads,m,pd,rep,loc_ptr,haveData);
  }
}
Perror_t eventSeq_read (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep)
{
  PDCI_IODISC_3P_CHECKS ("eventSeq_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc;
    Ploc_t *loc_ptr=&tloc;
    int i=0;
    int result;
    eventSeq_read_one_init (pads,m,pd,rep,loc_ptr);
    PCGEN_ARRAY_READ_ALL (PCGEN_ARRAY_RESERVE_SPACE (eventSeq,event_t,event_t_pd,0),eventSeq_read_one (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]),i = (rep->length),"eventSeq_read");
    return PCGEN_ARRAY_STD_RETURN ();
  }
}
Pread_res_t eventSeq_reread_one (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep,Ploc_t *loc_ptr,event_t_pd *elt_pd,event_t *elt_rep,int notFirstElt)
{
  PDCI_IODISC_3P_CHECKS ("eventSeq_reread_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("eventSeq_reread_one",elt_pd,elt_rep);
  {
    // Ready to read element
    if (notFirstElt) 
      {
        // Array not finished; reading separator
        {
          size_t offset;
          if (P_ERR==Pchar_lit_scan1 (pads,124,1,0,&offset)) 
            return P_READ_ERR;
        }
      }
    PCGEN_ARRAY_REREAD_ELEM_BODY (event_t_read (pads,&(m->element),elt_pd,elt_rep));
    return PCGEN_ARRAY_REREAD_ELEM_RET ();
  }
}
int eventSeq_verify (eventSeq *rep)
{
  int violated=0;
  {
    int i;
    for (i = 0; (!violated)&&(i<(rep->length)); i++)
      {
        if (!event_t_verify (&(rep->elts)[i])) 
          {
            violated = 1;
          }
      }
  }
  {
    int i;
    ssize_t supper_PCGEN_=(ssize_t) ((rep->length)-2);
    ssize_t slength_PCGEN_=(ssize_t) (rep->length);
    if (!((0<=0)&&(supper_PCGEN_<slength_PCGEN_))) 
      {
        violated = 1;
      }
    for (i = 0; (!violated)&&((supper_PCGEN_>=0)&&(i<=((rep->length)-2))); i++)
      {
        if (!(((rep->elts)[i].tstamp)<=((rep->elts)[i+1].tstamp))) 
          {
            violated = 1;
          }
      }
  }
  return !violated;
}
Perror_t eventSeq_acc_init (P_t *pads,eventSeq_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==event_t_acc_init (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==event_t_acc_init (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t eventSeq_acc_reset (P_t *pads,eventSeq_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==event_t_acc_reset (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==event_t_acc_reset (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t eventSeq_acc_cleanup (P_t *pads,eventSeq_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==event_t_acc_cleanup (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==event_t_acc_cleanup (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t eventSeq_acc_add (P_t *pads,eventSeq_acc *acc,eventSeq_pd *pd,eventSeq *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (pd->errCode);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint32_acc_add (pads,&(acc->length),&tpd,&(rep->length))) 
        {
          nerr++;
        }
      {
        int i;
        for (i = 0; i<(rep->length); i++)
          {
            if (i<10) 
              {
                if (P_ERR==event_t_acc_add (pads,&(acc->arrayDetail)[i],&(pd->elts)[i],&(rep->elts)[i])) 
                  {
                    nerr++;
                  }
              }
            if (P_ERR==event_t_acc_add (pads,&(acc->compoundLevel),&(pd->elts)[i],&(rep->elts)[i])) 
              {
                nerr++;
              }
          }
      }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t eventSeq_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,eventSeq_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "array eventSeq of event_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_ARRAY_ACC_REP_NOVALS ();
  if (P_ERR==Puint32_acc_report2io (pads,outstr,"Array lengths","array length",-1,&(acc->length))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.allArrayElts",prefix);
  if (P_ERR==event_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"all array element",nst,&(acc->compoundLevel))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  {
    int i;
    for (i = 0; i<((((acc->length).max)<10) ? (acc->length).max : 10); i++)
      {
        sfprintf (tmpstr,"%s.arrayDetail[%d]",prefix,i);
        if (P_ERR==event_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"array element",nst,&(acc->arrayDetail)[i])) 
          {
            sfstrclose (tmpstr);
            return P_ERR;
          }
      }
  }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t eventSeq_acc_report (P_t *pads,char const *prefix,char const *what,int nst,eventSeq_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = eventSeq_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t eventSeq_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,eventSeq_pd *pd,eventSeq *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("eventSeq_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  {
    int i=0;
    if ((rep->length)>1) 
      {
        for (i = 0; i<((rep->length)-1); i++)
          {
            tlen_PCGEN_ = event_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
            PCGEN_TLEN_UPDATES ();
            tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,124);
            PCGEN_TLEN_UPDATES ();
          }
      }
    if ((rep->length)!=0) 
      {
        tlen_PCGEN_ = event_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
        PCGEN_TLEN_UPDATES ();
      }
  }
  return length_PCGEN_;
}
ssize_t eventSeq_write2io (P_t *pads,Sfio_t *io,eventSeq_pd *pd,eventSeq *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("eventSeq_write2io",eventSeq_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t eventSeq_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,eventSeq_pd *pd,eventSeq *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("eventSeq_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_ARRAY_OPEN_XML_OUT ();
  {
    int i=0;
    for (i = 0; i<(rep->length); i++)
      {
        tlen_PCGEN_ = event_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"elt",indent+2);
        PCGEN_TLEN_UPDATES ();
      }
  }
  PCGEN_XML_VALUE_OUT ("length",rep->length);
  PCGEN_ARRAY_PD_XML_OUT ();
  PCGEN_ARRAY_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t eventSeq_write_xml_2io (P_t *pads,Sfio_t *io,eventSeq_pd *pd,eventSeq *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("eventSeq_write_xml_2io",eventSeq_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t eventSeq_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  int i=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("eventSeq_fmt2buf_final");
  PCGEN_FMT2BUF_ARRAY ("eventSeq_fmt2buf_final",event_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->element),&(pd->elts)[i],&(rep->elts)[i]));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t eventSeq_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("eventSeq_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"eventSeq"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return eventSeq_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t eventSeq_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("eventSeq_fmt2io",eventSeq_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *eventSeq_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (eventSeq);
  return NODE_NEW_RET ();
}
PDCI_node_t *eventSeq_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (eventSeq,ARR_LENGTH (eventSeq));
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *eventSeq_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_NODE_KTH_CHILD_BODY (eventSeq,event_t);
  return ARR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *eventSeq_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ARR_NODE_KTH_CHILD_NAMED_BODY (eventSeq);
  return ARR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *eventSeq_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (eventSeq,ARR_LENGTH (eventSeq));
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *eventSeq_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (eventSeq);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *eventSeq_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_SND_NODE_KTH_CHILD_BODY (eventSeq,event_t);
  return ARR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t eventSeq_node_pathWalk (P_t *pads,eventSeq_m *m,eventSeq_pd *pd,eventSeq *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ARR_NODE_PATH_WALK_BODY (event_t);
  return ARR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const eventSeq_node_vtable={eventSeq_cachedNode_init,eventSeq_node_kthChild,eventSeq_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const eventSeq_cachedNode_vtable={PDCI_error_cachedNode_init,eventSeq_cachedNode_kthChild,eventSeq_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const eventSeq_sndNode_vtable={PDCI_error_cachedNode_init,eventSeq_sndNode_kthChild,eventSeq_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t entry_t_init (P_t *pads,entry_t *rep)
{
  PDCI_DISC_1P_CHECKS ("entry_t_init",rep);
  memset ((void *) rep,0,sizeof(entry_t));
  return P_OK;
}
Perror_t entry_t_pd_init (P_t *pads,entry_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("entry_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(entry_t_pd));
  return P_OK;
}
Perror_t entry_t_cleanup (P_t *pads,entry_t *rep)
{
  PDCI_DISC_1P_CHECKS ("entry_t_cleanup",rep);
  order_header_t_cleanup (pads,&(rep->header));
  eventSeq_cleanup (pads,&(rep->events));
  return P_OK;
}
Perror_t entry_t_pd_cleanup (P_t *pads,entry_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("entry_t_pd_cleanup",pd);
  order_header_t_pd_cleanup (pads,&(pd->header));
  eventSeq_pd_cleanup (pads,&(pd->events));
  return P_OK;
}
Perror_t entry_t_copy (P_t *pads,entry_t *rep_dst,entry_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("entry_t_copy",rep_src,rep_dst);
  order_header_t_copy (pads,&(rep_dst->header),&(rep_src->header));
  eventSeq_copy (pads,&(rep_dst->events),&(rep_src->events));
  return P_OK;
}
Perror_t entry_t_pd_copy (P_t *pads,entry_t_pd *pd_dst,entry_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("entry_t_pd_copy",pd_src,pd_dst);
  order_header_t_pd_copy (pads,&(pd_dst->header),&(pd_src->header));
  eventSeq_pd_copy (pads,&(pd_dst->events),&(pd_src->events));
  return P_OK;
}
void entry_t_m_init (P_t *pads,entry_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(entry_t_m));
}
Perror_t entry_t_read (P_t *pads,entry_t_m *m,entry_t_pd *pd,entry_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("entry_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'header'
  PCGEN_STRUCT_READ_FIRST ("entry_t_read",header,order_header_t_read (pads,&(m->header),&(pd->header),&(rep->header)),_NOOP);
  // Read field 'events'
  PCGEN_STRUCT_READ_NEXT ("entry_t_read",events,eventSeq_read (pads,&(m->events),&(pd->events),&(rep->events)),_NOOP);
  PCGEN_FIND_EOR ("entry_t_read");
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int entry_t_verify (entry_t *rep)
{
  return order_header_t_verify (&(rep->header))&&(eventSeq_verify (&(rep->events))&&1);
}
Perror_t entry_t_acc_init (P_t *pads,entry_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==order_header_t_acc_init (pads,&(acc->header))) 
    {
      nerr++;
    }
  if (P_ERR==eventSeq_acc_init (pads,&(acc->events))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entry_t_acc_reset (P_t *pads,entry_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==order_header_t_acc_reset (pads,&(acc->header))) 
    {
      nerr++;
    }
  if (P_ERR==eventSeq_acc_reset (pads,&(acc->events))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entry_t_acc_cleanup (P_t *pads,entry_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==order_header_t_acc_cleanup (pads,&(acc->header))) 
    {
      nerr++;
    }
  if (P_ERR==eventSeq_acc_cleanup (pads,&(acc->events))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entry_t_acc_add (P_t *pads,entry_t_acc *acc,entry_t_pd *pd,entry_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==order_header_t_acc_add (pads,&(acc->header),&(pd->header),&(rep->header))) 
        {
          nerr++;
        }
      if (P_ERR==eventSeq_acc_add (pads,&(acc->events),&(pd->events),&(rep->events))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entry_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entry_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct entry_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.header",prefix);
  if (P_ERR==order_header_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->header))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.events",prefix);
  if (P_ERR==eventSeq_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->events))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t entry_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entry_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = entry_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t entry_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("entry_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = PDCI_io_rec_open_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"entry_t_write2buf");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = order_header_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->header),&(rep->header));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = eventSeq_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->events),&(rep->events));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = PDCI_io_rec_close_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,buf,length_PCGEN_,"entry_t_write2buf");
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t entry_t_write2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entry_t_write2io",entry_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t entry_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entry_t_pd *pd,entry_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("entry_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("entry_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = order_header_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->header),&(rep->header),"header",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = eventSeq_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->events),&(rep->events),"events",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t entry_t_write_xml_2io (P_t *pads,Sfio_t *io,entry_t_pd *pd,entry_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entry_t_write_xml_2io",entry_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t entry_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("entry_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("order_header_t_fmt2buf",order_header_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->header),&(pd->header),&(rep->header)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("eventSeq_fmt2buf",eventSeq_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->events),&(pd->events),&(rep->events)));
  PCGEN_FMT2BUF_FIX_LAST ();
  PCGEN_FMT2BUF_RECORD ("entry_t_fmt2buf_final");
  return length_PCGEN_;
}
ssize_t entry_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("entry_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"entry_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return entry_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t entry_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entry_t_m *m,entry_t_pd *pd,entry_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entry_t_fmt2io",entry_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *entry_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (entry_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *entry_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (entry_t,3);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *entry_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (entry_t);
  NODE_KC_CASE (entry_t,0,order_header_t,header);
  NODE_KC_CASE (entry_t,1,eventSeq,events);
  STR_NODE_KTH_CHILD_BODY_END (2);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *entry_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (entry_t,"header","events");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *entry_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (entry_t,3);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *entry_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (entry_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *entry_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (entry_t);
  SND_NODE_KC_CASE (entry_t,0,order_header_t,header);
  SND_NODE_KC_CASE (entry_t,1,eventSeq,events);
  STR_SND_NODE_KTH_CHILD_BODY_END (2);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t entry_t_node_pathWalk (P_t *pads,entry_t_m *m,entry_t_pd *pd,entry_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,order_header_t,header);
  NODE_PW_CASE (1,eventSeq,events);
  STR_NODE_PATH_WALK_BODY_END (2);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const entry_t_node_vtable={entry_t_cachedNode_init,entry_t_node_kthChild,entry_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const entry_t_cachedNode_vtable={PDCI_error_cachedNode_init,entry_t_cachedNode_kthChild,entry_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const entry_t_sndNode_vtable={PDCI_error_cachedNode_init,entry_t_sndNode_kthChild,entry_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t entries_t_init (P_t *pads,entries_t *rep)
{
  PDCI_DISC_1P_CHECKS ("entries_t_init",rep);
  memset ((void *) rep,0,sizeof(entries_t));
  return P_OK;
}
Perror_t entries_t_pd_init (P_t *pads,entries_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("entries_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(entries_t_pd));
  return P_OK;
}
Perror_t entries_t_cleanup (P_t *pads,entries_t *rep)
{
  PDCI_DISC_1P_CHECKS ("entries_t_cleanup",rep);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("entries_t_cleanup",rep,entry_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t entries_t_pd_cleanup (P_t *pads,entries_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("entries_t_pd_cleanup",pd);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("entries_t_pd_cleanup",pd,entry_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t entries_t_copy (P_t *pads,entries_t *rep_dst,entries_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("entries_t_copy",rep_src,rep_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("entries_t_copy",rep_src,rep_dst,entry_t_copy,entry_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t entries_t_pd_copy (P_t *pads,entries_t_pd *pd_dst,entries_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("entries_t_pd_copy",pd_src,pd_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("entries_t_pd_copy",pd_src,pd_dst,entry_t_pd_copy,entry_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
void entries_t_m_init (P_t *pads,entries_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(entries_t_m));
}
void entries_t_ro_params_init (entries_t_ro_params_t *params)
{
}
Pread_res_t entries_t_final_checks (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,int consume)
{
  PDCI_IODISC_3P_CHECKS ("entries_t_final_checks",m,pd,rep);
  {
    PCGEN_ARRAY_UNSET_PARTIAL ();
    pd->length = (rep->length);
    return PCGEN_ARRAY_RET_DONE (consume);
  }
}
Pread_res_t entries_t_read_one_init (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr)
{
  PDCI_IODISC_3P_CHECKS ("entries_t_read_one_init",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    rep->length = 0;
    pd->neerr = 0;
    pd->firstError = 0;
    pd->numRead = 0;
    PDCI_READFN_BEGINLOC (pads,*loc_ptr);
    if (0==(rep->_internal)) 
      {
        rep->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(rep->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"entries_t_read","");
          }
      }
    if (0==(pd->_internal)) 
      {
        pd->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(pd->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"entries_t_read","");
          }
      }
    if (P_PS_isPanic (pd)||P_io_at_eof (pads)) 
      PCGEN_ARRAY_DO_FINAL_CHECKS ();
    PDCI_READFN_BEGINLOC (pads,pd->loc);
    PCGEN_ARRAY_SET_PARTIAL ();
    return PCGEN_ARRAY_RET_ONGOING (0);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return entries_t_final_checks (pads,m,pd,rep,loc_ptr,0);
  }
}
Pread_res_t entries_t_read_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,entry_t_pd *elt_pd,entry_t *elt_rep)
{
  PDCI_IODISC_3P_CHECKS ("entries_t_read_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("entries_t_read_one",elt_pd,elt_rep);
  {
    int haveData=0;
    PCGEN_ARRAY_RO_DECS ();
    PCGEN_ARRAY_TEST_ALREADY_DONE ();
    PCGEN_ARRAY_GET_BEGIN_LOC ();
    // Ready to read next element
    if ((pd->numRead)>0) 
      {
      }
    PCGEN_ARRAY_READ_ELEM_HD (entry_t_read (pads,&(m->element),elt_pd,elt_rep),haveData);
    PCGEN_ARRAY_TEST_READ_ERR (1,1);
    if (P_PS_isPanic (elt_pd)) 
      {
        {
          // No recovery possible
          P_PS_setPanic (pd);
          PCGEN_ARRAY_DO_FINAL_CHECKS ();
        }
      }
    // Have we finished reading array?
    if (P_io_at_eof (pads)||P_io_at_eor (pads)) 
      {
        PCGEN_ARRAY_DO_FINAL_CHECKS ();
      }
    PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE2 ();
    return PCGEN_ARRAY_RET_ONGOING (1);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return entries_t_final_checks (pads,m,pd,rep,loc_ptr,haveData);
  }
}
Perror_t entries_t_read (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("entries_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc;
    Ploc_t *loc_ptr=&tloc;
    int i=0;
    int result;
    entries_t_read_one_init (pads,m,pd,rep,loc_ptr);
/*     if (0 != RBuf_RESERVE_HINT(rep->_internal, rep->elts, entry_t, 25000, 0))  */
/*       { */
/* 	PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"entries_t_read",0); */
/*       } */
/*     if (0 != RBuf_RESERVE_HINT(pd->_internal, pd->elts, entry_t_pd, 25000, 0))  */
/*       { */
/* 	PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"entries_t_read",0); */
/*       } */
    PCGEN_ARRAY_READ_ALL (PCGEN_ARRAY_RESERVE_SPACE(entries_t,entry_t,entry_t_pd,PADS_ALLOC_HINT),entries_t_read_one (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]),i = (rep->length),"entries_t_read");
    return PCGEN_ARRAY_STD_RETURN ();
  }
}
Pread_res_t entries_t_reread_one (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,Ploc_t *loc_ptr,entry_t_pd *elt_pd,entry_t *elt_rep,int notFirstElt)
{
  PDCI_IODISC_3P_CHECKS ("entries_t_reread_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("entries_t_reread_one",elt_pd,elt_rep);
  {
    // Ready to read element
    PCGEN_ARRAY_REREAD_ELEM_BODY (entry_t_read (pads,&(m->element),elt_pd,elt_rep));
    return PCGEN_ARRAY_REREAD_ELEM_RET ();
  }
}
int entries_t_verify (entries_t *rep)
{
  int violated=0;
  {
    int i;
    for (i = 0; (!violated)&&(i<(rep->length)); i++)
      {
        if (!entry_t_verify (&(rep->elts)[i])) 
          {
            violated = 1;
          }
      }
  }
  return !violated;
}
Perror_t entries_t_acc_init (P_t *pads,entries_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==entry_t_acc_init (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==entry_t_acc_init (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entries_t_acc_reset (P_t *pads,entries_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==entry_t_acc_reset (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==entry_t_acc_reset (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entries_t_acc_cleanup (P_t *pads,entries_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==entry_t_acc_cleanup (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==entry_t_acc_cleanup (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entries_t_acc_add (P_t *pads,entries_t_acc *acc,entries_t_pd *pd,entries_t *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = (pd->errCode);
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==Puint32_acc_add (pads,&(acc->length),&tpd,&(rep->length))) 
        {
          nerr++;
        }
      {
        int i;
        for (i = 0; i<(rep->length); i++)
          {
            if (i<10) 
              {
                if (P_ERR==entry_t_acc_add (pads,&(acc->arrayDetail)[i],&(pd->elts)[i],&(rep->elts)[i])) 
                  {
                    nerr++;
                  }
              }
            if (P_ERR==entry_t_acc_add (pads,&(acc->compoundLevel),&(pd->elts)[i],&(rep->elts)[i])) 
              {
                nerr++;
              }
          }
      }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t entries_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,entries_t_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "array entries_t of entry_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_ARRAY_ACC_REP_NOVALS ();
  if (P_ERR==Puint32_acc_report2io (pads,outstr,"Array lengths","array length",-1,&(acc->length))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.allArrayElts",prefix);
  if (P_ERR==entry_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"all array element",nst,&(acc->compoundLevel))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  {
    int i;
    for (i = 0; i<((((acc->length).max)<10) ? (acc->length).max : 10); i++)
      {
        sfprintf (tmpstr,"%s.arrayDetail[%d]",prefix,i);
        if (P_ERR==entry_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"array element",nst,&(acc->arrayDetail)[i])) 
          {
            sfstrclose (tmpstr);
            return P_ERR;
          }
      }
  }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t entries_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,entries_t_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = entries_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t entries_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entries_t_pd *pd,entries_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("entries_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  {
    int i=0;
    if ((rep->length)>1) 
      {
        for (i = 0; i<((rep->length)-1); i++)
          {
            tlen_PCGEN_ = entry_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
            PCGEN_TLEN_UPDATES ();
          }
      }
    if ((rep->length)!=0) 
      {
        tlen_PCGEN_ = entry_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
        PCGEN_TLEN_UPDATES ();
      }
  }
  return length_PCGEN_;
}
ssize_t entries_t_write2io (P_t *pads,Sfio_t *io,entries_t_pd *pd,entries_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entries_t_write2io",entries_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t entries_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,entries_t_pd *pd,entries_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("entries_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_ARRAY_OPEN_XML_OUT ();
  {
    int i=0;
    for (i = 0; i<(rep->length); i++)
      {
        tlen_PCGEN_ = entry_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"elt",indent+2);
        PCGEN_TLEN_UPDATES ();
      }
  }
  PCGEN_XML_VALUE_OUT ("length",rep->length);
  PCGEN_ARRAY_PD_XML_OUT ();
  PCGEN_ARRAY_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t entries_t_write_xml_2io (P_t *pads,Sfio_t *io,entries_t_pd *pd,entries_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entries_t_write_xml_2io",entries_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t entries_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  int i=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("entries_t_fmt2buf_final");
  PCGEN_FMT2BUF_ARRAY ("entries_t_fmt2buf_final",entry_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->element),&(pd->elts)[i],&(rep->elts)[i]));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t entries_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("entries_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"entries_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return entries_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t entries_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,entries_t_m *m,entries_t_pd *pd,entries_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("entries_t_fmt2io",entries_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *entries_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (entries_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *entries_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (entries_t,ARR_LENGTH (entries_t));
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *entries_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_NODE_KTH_CHILD_BODY (entries_t,entry_t);
  return ARR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *entries_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ARR_NODE_KTH_CHILD_NAMED_BODY (entries_t);
  return ARR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *entries_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (entries_t,ARR_LENGTH (entries_t));
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *entries_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (entries_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *entries_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_SND_NODE_KTH_CHILD_BODY (entries_t,entry_t);
  return ARR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t entries_t_node_pathWalk (P_t *pads,entries_t_m *m,entries_t_pd *pd,entries_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ARR_NODE_PATH_WALK_BODY (entry_t);
  return ARR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const entries_t_node_vtable={entries_t_cachedNode_init,entries_t_node_kthChild,entries_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const entries_t_cachedNode_vtable={PDCI_error_cachedNode_init,entries_t_cachedNode_kthChild,entries_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const entries_t_sndNode_vtable={PDCI_error_cachedNode_init,entries_t_sndNode_kthChild,entries_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t entries_t_smartNode_eltAlloc (PDCI_node_t *smartNode,P_t *pads,void **elt_pd,void **elt_rep)
{
  SN_ELT_ALLOC_BODY (entries_t,entry_t,entry_t_pd,smartNode,pads,elt_pd,elt_rep);
  return SN_ELT_ALLOC_RET ();
}
Pread_res_t entries_t_smartNode_eltRead (PDCI_node_t *smartNode,P_t *pads,PDCI_smart_elt_info_t *info)
{
  SN_ELT_READ_BODY (entries_t,entry_t,entry_t_pd,smartNode,pads,info,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return SN_ELT_READ_RET ();
}
Perror_t entries_t_smartNode_eltFree (P_t *pads,PDCI_smart_elt_info_t *info)
{
  SN_ELT_FREE_BODY (entries_t,pads,info);
  return SN_ELT_FREE_RET ();
}
Perror_t entries_t_smartNode_eltPathWalk (P_t *pads,void *m,void *pd,void *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  SN_ELT_PATH_WALK_BODY (entries_t,entry_t,entry_t_pd,entry_t_m,pads,m,pd,rep,path,m_out,pd_out,rep_out);
  return SN_ELT_PATH_WALK_RET (entry_t,pads,path,m_out,pd_out,rep_out);
}
PDCI_smart_array_info_t *entries_t_array_info_init (P_t *pads,unsigned int max_elts)
{
  SN_ARRAY_INFO_INIT_BODY (entries_t,pads,max_elts,SN_WRAP_PARAMS (0));
  return SN_ARRAY_INFO_INIT_RET ();
}
PDCI_node_t *entries_t_smartNode_init (PDCI_node_t *self,unsigned int max_elts)
{
  SN_INIT_BODY (entries_t,self,max_elts,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return SN_INIT_RET (self);
}
PDCI_node_t *entries_t_smartNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  SN_KTH_CHILD_BODY (entries_t,entry_t,self,idx);
  return SN_KTH_CHILD_RET ();
}
PDCI_node_t *entries_t_smartNode_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  SN_KTH_CHILD_NAMED_BODY (entries_t,self,idx,name);
  return SN_KTH_CHILD_NAMED_RET ();
}
PDCI_vtable_t const entries_t_smartNode_vtable={
  PDCI_error_cachedNode_init,
  entries_t_smartNode_kthChild,
  entries_t_smartNode_kthChildNamed,
  PDCI_cachedNode_free,
  PDCI_smartNode_getId,
  PDCI_error_typed_value,
  0};

/*
 **************************** HAND-CODED : BEGIN ****************************
 */

PDCI_vtable_t const entries_t_linearNode_vtable={
  PDCI_error_cachedNode_init,
  entries_t_linearNode_kthChild,
  entries_t_linearNode_kthChildNamed,
  PDCI_cachedNode_free,
  PDCI_node_getId,
  PDCI_error_typed_value,
  0};

PDCI_node_t *entries_t_linearNode_init (PDCI_node_t *self)
{
  LN_INIT_BODY (entries_t,entry_t,entry_t_pd,self,
		SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return LN_INIT_RET (self);
}
PDCI_node_t *entries_t_linearNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  LN_KTH_CHILD_BODY (entries_t,entry_t,self,idx,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return LN_KTH_CHILD_RET ();
}
PDCI_node_t *entries_t_linearNode_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,
						 char const *name)
{
  LN_KTH_CHILD_NAMED_BODY (entries_t,self,idx,name);
  return LN_KTH_CHILD_NAMED_RET ();
}

/*
 **************************** HAND-CODED : END ****************************
 */

Perror_t out_sum_init (P_t *pads,out_sum *rep)
{
  PDCI_DISC_1P_CHECKS ("out_sum_init",rep);
  memset ((void *) rep,0,sizeof(out_sum));
  return P_OK;
}
Perror_t out_sum_pd_init (P_t *pads,out_sum_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("out_sum_pd_init",pd);
  memset ((void *) pd,0,sizeof(out_sum_pd));
  return P_OK;
}
Perror_t out_sum_cleanup (P_t *pads,out_sum *rep)
{
  PDCI_DISC_1P_CHECKS ("out_sum_cleanup",rep);
  entries_t_cleanup (pads,&(rep->es));
  return P_OK;
}
Perror_t out_sum_pd_cleanup (P_t *pads,out_sum_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("out_sum_pd_cleanup",pd);
  entries_t_pd_cleanup (pads,&(pd->es));
  return P_OK;
}
Perror_t out_sum_copy (P_t *pads,out_sum *rep_dst,out_sum *rep_src)
{
  PDCI_DISC_2P_CHECKS ("out_sum_copy",rep_src,rep_dst);
  memcpy ((void *) (&(rep_dst->h)),(void *) (&(rep_src->h)),sizeof(summary_header_t));
  entries_t_copy (pads,&(rep_dst->es),&(rep_src->es));
  return P_OK;
}
Perror_t out_sum_pd_copy (P_t *pads,out_sum_pd *pd_dst,out_sum_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("out_sum_pd_copy",pd_src,pd_dst);
  memcpy ((void *) (&(pd_dst->h)),(void *) (&(pd_src->h)),sizeof(summary_header_t_pd));
  entries_t_pd_copy (pads,&(pd_dst->es),&(pd_src->es));
  return P_OK;
}
void out_sum_m_init (P_t *pads,out_sum_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(out_sum_m));
}
Perror_t out_sum_read (P_t *pads,out_sum_m *m,out_sum_pd *pd,out_sum *rep)
{
  PDCI_IODISC_3P_CHECKS ("out_sum_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'h'
  PCGEN_STRUCT_READ_FIRST ("out_sum_read",h,summary_header_t_read (pads,&(m->h),&(pd->h),&(rep->h)),_NOOP);
  // Read field 'es'
  PCGEN_STRUCT_READ_NEXT ("out_sum_read",es,entries_t_read (pads,&(m->es),&(pd->es),&(rep->es)),_NOOP);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int out_sum_verify (out_sum *rep)
{
  return summary_header_t_verify (&(rep->h))&&(entries_t_verify (&(rep->es))&&1);
}
Perror_t out_sum_acc_init (P_t *pads,out_sum_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==summary_header_t_acc_init (pads,&(acc->h))) 
    {
      nerr++;
    }
  if (P_ERR==entries_t_acc_init (pads,&(acc->es))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t out_sum_acc_reset (P_t *pads,out_sum_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==summary_header_t_acc_reset (pads,&(acc->h))) 
    {
      nerr++;
    }
  if (P_ERR==entries_t_acc_reset (pads,&(acc->es))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t out_sum_acc_cleanup (P_t *pads,out_sum_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==summary_header_t_acc_cleanup (pads,&(acc->h))) 
    {
      nerr++;
    }
  if (P_ERR==entries_t_acc_cleanup (pads,&(acc->es))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t out_sum_acc_add (P_t *pads,out_sum_acc *acc,out_sum_pd *pd,out_sum *rep)
{
  Puint32 nerr=0;
  Pbase_pd tpd;
  tpd.errCode = P_NO_ERR;
  if (P_ERR==Puint32_acc_add (pads,&(acc->nerr),&tpd,&(pd->nerr))) 
    {
      nerr++;
    }
  if ((pd->errCode)!=P_PANIC_SKIPPED) 
    {
      if (P_ERR==summary_header_t_acc_add (pads,&(acc->h),&(pd->h),&(rep->h))) 
        {
          nerr++;
        }
      if (P_ERR==entries_t_acc_add (pads,&(acc->es),&(pd->es),&(rep->es))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t out_sum_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,out_sum_acc *acc)
{
  Sfio_t *tmpstr;
  if (!(tmpstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if ((!prefix)||(0==(*prefix))) 
    {
      prefix = "<top>";
    }
  if (!what) 
    {
      what = "struct out_sum";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.h",prefix);
  if (P_ERR==summary_header_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->h))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.es",prefix);
  if (P_ERR==entries_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->es))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t out_sum_acc_report (P_t *pads,char const *prefix,char const *what,int nst,out_sum_acc *acc)
{
  Perror_t result;
  Sfio_t *outstr;
  if (!(outstr = sfstropen ())) 
    {
      return P_ERR;
    }
  if (((!pads)||(!acc))||(!(pads->disc))) 
    {
      return P_ERR;
    }
  if (!((pads->disc)->error_fn)) 
    {
      return P_OK;
    }
  result = out_sum_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t out_sum_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,out_sum_pd *pd,out_sum *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("out_sum_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = summary_header_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->h),&(rep->h));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = entries_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->es),&(rep->es));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t out_sum_write2io (P_t *pads,Sfio_t *io,out_sum_pd *pd,out_sum *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("out_sum_write2io",out_sum_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t out_sum_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,out_sum_pd *pd,out_sum *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("out_sum_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_SOURCE_XML_OUT_BEGIN ("dibbler_new.p");
  PCGEN_TAG_OPEN_XML_OUT ("out_sum");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = summary_header_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->h),&(rep->h),"h",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = entries_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->es),&(rep->es),"es",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  PCGEN_SOURCE_XML_OUT_END ();
  return length_PCGEN_;
}
ssize_t out_sum_write_xml_2io (P_t *pads,Sfio_t *io,out_sum_pd *pd,out_sum *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("out_sum_write_xml_2io",out_sum_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t out_sum_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,out_sum_m *m,out_sum_pd *pd,out_sum *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("out_sum_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("summary_header_t_fmt2buf",summary_header_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->h),&(pd->h),&(rep->h)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("entries_t_fmt2buf",entries_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->es),&(pd->es),&(rep->es)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t out_sum_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,out_sum_m *m,out_sum_pd *pd,out_sum *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("out_sum_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"out_sum"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return out_sum_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t out_sum_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,out_sum_m *m,out_sum_pd *pd,out_sum *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("out_sum_fmt2io",out_sum_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *out_sum_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (out_sum);
  return NODE_NEW_RET ();
}
PDCI_node_t *out_sum_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (out_sum,3);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *out_sum_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (out_sum);
  NODE_KC_CASE (out_sum,0,summary_header_t,h);
  NODE_KC_CASE (out_sum,1,entries_t,es);
  STR_NODE_KTH_CHILD_BODY_END (2);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *out_sum_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (out_sum,"h","es");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *out_sum_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (out_sum,3);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *out_sum_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (out_sum);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *out_sum_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (out_sum);
  SND_NODE_KC_CASE (out_sum,0,summary_header_t,h);
  SND_NODE_KC_CASE (out_sum,1,entries_t,es);
  STR_SND_NODE_KTH_CHILD_BODY_END (2);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t out_sum_node_pathWalk (P_t *pads,out_sum_m *m,out_sum_pd *pd,out_sum *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,summary_header_t,h);
  NODE_PW_CASE (1,entries_t,es);
  STR_NODE_PATH_WALK_BODY_END (2);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const out_sum_node_vtable={out_sum_cachedNode_init,out_sum_node_kthChild,out_sum_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const out_sum_cachedNode_vtable={PDCI_error_cachedNode_init,out_sum_cachedNode_kthChild,out_sum_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const out_sum_sndNode_vtable={PDCI_error_cachedNode_init,out_sum_sndNode_kthChild,out_sum_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
void P_lib_init ()
{
  // Initialize character classes
}

