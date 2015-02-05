#include "pads-internal.h"
#include "pglx-internal.h"
char* PDCI_source = "ai2.p";
#include "ai2.h"
Perror_t nIP_init (P_t *pads,nIP *rep)
{
  PDCI_DISC_1P_CHECKS ("nIP_init",rep);
  memset ((void *) rep,0,sizeof(nIP));
  return P_OK;
}
Perror_t nIP_pd_init (P_t *pads,nIP_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("nIP_pd_init",pd);
  memset ((void *) pd,0,sizeof(nIP_pd));
  return P_OK;
}
Perror_t nIP_cleanup (P_t *pads,nIP *rep)
{
  PDCI_DISC_1P_CHECKS ("nIP_cleanup",rep);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_STAT ("nIP_cleanup",rep);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t nIP_pd_cleanup (P_t *pads,nIP_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("nIP_pd_cleanup",pd);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_STAT ("nIP_pd_cleanup",pd);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t nIP_copy (P_t *pads,nIP *rep_dst,nIP *rep_src)
{
  PDCI_DISC_2P_CHECKS ("nIP_copy",rep_src,rep_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_STAT ("nIP_copy",rep_src,rep_dst);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t nIP_pd_copy (P_t *pads,nIP_pd *pd_dst,nIP_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("nIP_pd_copy",pd_src,pd_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_STAT ("nIP_pd_copy",pd_src,pd_dst);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
void nIP_m_init (P_t *pads,nIP_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(nIP_m));
}
void nIP_ro_params_init (nIP_ro_params_t *params)
{
}
Pread_res_t nIP_final_checks (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep,Ploc_t *loc_ptr,int reachedLimit,int consume)
{
  PDCI_IODISC_3P_CHECKS ("nIP_final_checks",m,pd,rep);
  {
    PCGEN_ARRAY_UNSET_PARTIAL ();
    pd->length = (rep->length);
    // Checking basic array constraints
    if (P_Test_SynCheck (m->compoundLevel)&&(!P_PS_isPanic (pd))) 
      {
        // Checking that we read enough elements
        if ((!reachedLimit)&&((rep->length)<4)) 
          {
            if (!(pd->nerr)) 
              {
                (pd->nerr)++;
                pd->errCode = P_ARRAY_SIZE_ERR;
                PDCI_READFN_ENDLOC_MINUS1 (pads,*loc_ptr);
                PDCI_report_err (pads,P_LEV_WARN,loc_ptr,pd->errCode,"nIP_read","Read %d element(s) for array nIP; required %d",rep->length,4);
              }
            else
              {
                (pd->nerr)++;
              }
            if (P_spec_level (pads)) 
              return P_READ_ERR;
          }
      }
    return PCGEN_ARRAY_RET_DONE (consume);
  }
}
Pread_res_t nIP_read_one_init (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep,Ploc_t *loc_ptr)
{
  PDCI_IODISC_3P_CHECKS ("nIP_read_one_init",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    int reachedLimit=0;
    rep->length = 0;
    pd->neerr = 0;
    pd->firstError = 0;
    pd->numRead = 0;
    PDCI_READFN_BEGINLOC (pads,*loc_ptr);
    if (P_Test_SynCheck (m->compoundLevel)&&(4<0)) 
      {
        if (!(pd->nerr)) 
          {
            (pd->nerr)++;
            pd->errCode = P_ARRAY_MAX_NEGATIVE;
            PDCI_READFN_ENDLOC_MINUS1 (pads,*loc_ptr);
            PDCI_report_err (pads,P_LEV_WARN,loc_ptr,pd->errCode,"nIP_read","Maximum value for the size of array nIP(%d) is negative",4);
          }
        else
          {
            (pd->nerr)++;
          }
        if (P_spec_level (pads)) 
          return P_ERR;
        P_PS_setPanic (pd);
      }
    if (0==(rep->_internal)) 
      {
        rep->_internal = RMM_new_rbuf (P_rmm_nozero (pads));
        if (0==(rep->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"nIP_read","");
          }
      }
    if (0==(pd->_internal)) 
      {
        pd->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(pd->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"nIP_read","");
          }
      }
    if (P_PS_isPanic (pd)||P_io_at_eof (pads)) 
      PCGEN_ARRAY_DO_FINAL_CHECKS ();
    PDCI_READFN_BEGINLOC (pads,pd->loc);
    PCGEN_ARRAY_SET_PARTIAL ();
    return PCGEN_ARRAY_RET_ONGOING (0);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return nIP_final_checks (pads,m,pd,rep,loc_ptr,reachedLimit,0);
  }
}
Pread_res_t nIP_read_one (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep)
{
  PDCI_IODISC_3P_CHECKS ("nIP_read_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("nIP_read_one",elt_pd,elt_rep);
  {
    int haveData=0;
    int reachedLimit=0;
    PCGEN_ARRAY_RO_DECS ();
    PCGEN_ARRAY_TEST_ALREADY_DONE ();
    PCGEN_ARRAY_GET_BEGIN_LOC ();
    // Ready to read next element
    if ((pd->numRead)>0) 
      {
        // Checking for separator
        if (P_ERR==Pchar_lit_match (pads,46,1)) 
          {
            // No separator, therefore array is finished
            PCGEN_ARRAY_DO_FINAL_CHECKS ();
          }
      }
    PCGEN_ARRAY_READ_ELEM_HD (Puint8_read (pads,&(m->element),elt_pd,elt_rep),haveData);
    PCGEN_ARRAY_TEST_READ_ERR (1,1);
    if (P_PS_isPanic (elt_pd)) 
      {
        {
          if (reachedLimit) 
            {
              // No recovery possible
              P_PS_setPanic (pd);
              PCGEN_ARRAY_DO_FINAL_CHECKS ();
            }
          else
            {
              size_t offset;
              // Try to recover to separator
              if (P_OK==Pchar_lit_scan1 (pads,46,1,1,&offset)) 
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
      }
    reachedLimit = ((rep->length)>=4);
    // Have we finished reading array?
    if (P_io_at_eof (pads)||reachedLimit) 
      {
        PCGEN_ARRAY_DO_FINAL_CHECKS ();
      }
    PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE2 ();
    return PCGEN_ARRAY_RET_ONGOING (1);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return nIP_final_checks (pads,m,pd,rep,loc_ptr,reachedLimit,haveData);
  }
}
Perror_t nIP_read (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep)
{
  PDCI_IODISC_3P_CHECKS ("nIP_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc;
    Ploc_t *loc_ptr=&tloc;
    int i=0;
    int result;
    nIP_read_one_init (pads,m,pd,rep,loc_ptr);
    PCGEN_ARRAY_READ_ALL (PCGEN_ARRAY_RESERVE_SPACE (nIP,Puint8,Pbase_pd,4),nIP_read_one (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]),i = (rep->length),"nIP_read");
    return PCGEN_ARRAY_STD_RETURN ();
  }
}
Pread_res_t nIP_reread_one (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Puint8 *elt_rep,int notFirstElt)
{
  PDCI_IODISC_3P_CHECKS ("nIP_reread_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("nIP_reread_one",elt_pd,elt_rep);
  {
    // Ready to read element
    if (notFirstElt) 
      {
        // Checking for separator
        if (P_ERR==Pchar_lit_match (pads,46,1)) 
          {
            // No separator, therefore array is finished
            return P_READ_ERR;
          }
      }
    PCGEN_ARRAY_REREAD_ELEM_BODY (Puint8_read (pads,&(m->element),elt_pd,elt_rep));
    return PCGEN_ARRAY_REREAD_ELEM_RET ();
  }
}
int nIP_verify (nIP *rep)
{
  int violated=0;
  return !violated;
}
Perror_t nIP_acc_init (P_t *pads,nIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_init (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<4; i++)
      {
        if (P_ERR==Puint8_acc_init (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nIP_acc_reset (P_t *pads,nIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_reset (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<4; i++)
      {
        if (P_ERR==Puint8_acc_reset (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nIP_acc_cleanup (P_t *pads,nIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_cleanup (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<4; i++)
      {
        if (P_ERR==Puint8_acc_cleanup (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nIP_acc_add (P_t *pads,nIP_acc *acc,nIP_pd *pd,nIP *rep)
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
            if (i<4) 
              {
                if (P_ERR==Puint8_acc_add (pads,&(acc->arrayDetail)[i],&(pd->elts)[i],&(rep->elts)[i])) 
                  {
                    nerr++;
                  }
              }
            if (P_ERR==Puint8_acc_add (pads,&(acc->compoundLevel),&(pd->elts)[i],&(rep->elts)[i])) 
              {
                nerr++;
              }
          }
      }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t nIP_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,nIP_acc *acc)
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
      what = "array nIP of Puint8";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_ARRAY_ACC_REP_NOVALS ();
  if (P_ERR==Puint32_acc_report2io (pads,outstr,"Array lengths","array length",-1,&(acc->length))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.allArrayElts",prefix);
  if (P_ERR==Puint8_acc_report2io (pads,outstr,sfstruse (tmpstr),"all array element",nst,&(acc->compoundLevel))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  {
    int i;
    for (i = 0; i<((((acc->length).max)<10) ? (acc->length).max : 10); i++)
      {
        sfprintf (tmpstr,"%s.arrayDetail[%d]",prefix,i);
        if (P_ERR==Puint8_acc_report2io (pads,outstr,sfstruse (tmpstr),"array element",nst,&(acc->arrayDetail)[i])) 
          {
            sfstrclose (tmpstr);
            return P_ERR;
          }
      }
  }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t nIP_acc_report (P_t *pads,char const *prefix,char const *what,int nst,nIP_acc *acc)
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
  result = nIP_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t nIP_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nIP_pd *pd,nIP *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nIP_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  {
    int i=0;
    if ((rep->length)>1) 
      {
        for (i = 0; i<((rep->length)-1); i++)
          {
            tlen_PCGEN_ = Puint8_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
            PCGEN_TLEN_UPDATES ();
            tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,46);
            PCGEN_TLEN_UPDATES ();
          }
      }
    if ((rep->length)!=0) 
      {
        tlen_PCGEN_ = Puint8_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
        PCGEN_TLEN_UPDATES ();
      }
  }
  return length_PCGEN_;
}
ssize_t nIP_write2io (P_t *pads,Sfio_t *io,nIP_pd *pd,nIP *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nIP_write2io",nIP_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t nIP_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,nIP_pd *pd,nIP *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("nIP_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_ARRAY_OPEN_XML_OUT ();
  {
    int i=0;
    for (i = 0; i<(rep->length); i++)
      {
        tlen_PCGEN_ = Puint8_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"elt",indent+2);
        PCGEN_TLEN_UPDATES ();
      }
  }
  PCGEN_XML_VALUE_OUT ("length",rep->length);
  PCGEN_ARRAY_PD_XML_OUT ();
  PCGEN_ARRAY_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t nIP_write_xml_2io (P_t *pads,Sfio_t *io,nIP_pd *pd,nIP *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nIP_write_xml_2io",nIP_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t nIP_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nIP_m *m,nIP_pd *pd,nIP *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  int i=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("nIP_fmt2buf_final");
  PCGEN_FMT2BUF_ARRAY ("nIP_fmt2buf_final",Puint8_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->element),&(pd->elts)[i],&(rep->elts)[i]));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t nIP_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,nIP_m *m,nIP_pd *pd,nIP *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("nIP_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"nIP"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return nIP_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t nIP_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,nIP_m *m,nIP_pd *pd,nIP *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("nIP_fmt2io",nIP_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *nIP_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (nIP);
  return NODE_NEW_RET ();
}
PDCI_node_t *nIP_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (nIP,ARR_LENGTH (nIP));
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *nIP_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_NODE_KTH_CHILD_BODY (nIP,Puint8);
  return ARR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nIP_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ARR_NODE_KTH_CHILD_NAMED_BODY (nIP);
  return ARR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *nIP_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (nIP,ARR_LENGTH (nIP));
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *nIP_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (nIP);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *nIP_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_SND_NODE_KTH_CHILD_BODY (nIP,Puint8);
  return ARR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t nIP_node_pathWalk (P_t *pads,nIP_m *m,nIP_pd *pd,nIP *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ARR_NODE_PATH_WALK_BODY (Puint8);
  return ARR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const nIP_node_vtable={nIP_cachedNode_init,nIP_node_kthChild,nIP_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nIP_cachedNode_vtable={PDCI_error_cachedNode_init,nIP_cachedNode_kthChild,nIP_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const nIP_sndNode_vtable={PDCI_error_cachedNode_init,nIP_sndNode_kthChild,nIP_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t sIP_init (P_t *pads,sIP *rep)
{
  PDCI_DISC_1P_CHECKS ("sIP_init",rep);
  memset ((void *) rep,0,sizeof(sIP));
  return P_OK;
}
Perror_t sIP_pd_init (P_t *pads,sIP_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("sIP_pd_init",pd);
  memset ((void *) pd,0,sizeof(sIP_pd));
  return P_OK;
}
Perror_t sIP_cleanup (P_t *pads,sIP *rep)
{
  PDCI_DISC_1P_CHECKS ("sIP_cleanup",rep);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("sIP_cleanup",rep,Pstring_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t sIP_pd_cleanup (P_t *pads,sIP_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("sIP_pd_cleanup",pd);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("sIP_pd_cleanup",pd,Pstring_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t sIP_copy (P_t *pads,sIP *rep_dst,sIP *rep_src)
{
  PDCI_DISC_2P_CHECKS ("sIP_copy",rep_src,rep_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("sIP_copy",rep_src,rep_dst,Pstring_copy,Pstring_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t sIP_pd_copy (P_t *pads,sIP_pd *pd_dst,sIP_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("sIP_pd_copy",pd_src,pd_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("sIP_pd_copy",pd_src,pd_dst,Pstring_pd_copy,Pstring_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
void sIP_m_init (P_t *pads,sIP_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(sIP_m));
}
void sIP_ro_params_init (sIP_ro_params_t *params)
{
}
Pread_res_t sIP_final_checks (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep,Ploc_t *loc_ptr,int consume)
{
  PDCI_IODISC_3P_CHECKS ("sIP_final_checks",m,pd,rep);
  {
    PCGEN_ARRAY_UNSET_PARTIAL ();
    pd->length = (rep->length);
    return PCGEN_ARRAY_RET_DONE (consume);
  }
}
Pread_res_t sIP_read_one_init (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep,Ploc_t *loc_ptr)
{
  PDCI_IODISC_3P_CHECKS ("sIP_read_one_init",m,pd,rep);
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
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"sIP_read","");
          }
      }
    if (0==(pd->_internal)) 
      {
        pd->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(pd->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"sIP_read","");
          }
      }
    if (P_PS_isPanic (pd)||P_io_at_eof (pads)) 
      PCGEN_ARRAY_DO_FINAL_CHECKS ();
    PDCI_READFN_BEGINLOC (pads,pd->loc);
    PCGEN_ARRAY_SET_PARTIAL ();
    return PCGEN_ARRAY_RET_ONGOING (0);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return sIP_final_checks (pads,m,pd,rep,loc_ptr,0);
  }
}
Pread_res_t sIP_read_one (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pstring *elt_rep)
{
  PDCI_IODISC_3P_CHECKS ("sIP_read_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("sIP_read_one",elt_pd,elt_rep);
  {
    int haveData=0;
    PCGEN_ARRAY_RO_DECS ();
    PCGEN_ARRAY_TEST_ALREADY_DONE ();
    PCGEN_ARRAY_GET_BEGIN_LOC ();
    // Ready to read next element
    if ((pd->numRead)>0) 
      {
        // Checking for separator
        if (P_ERR==Pchar_lit_match (pads,46,1)) 
          {
            // No separator, therefore array is finished
            PCGEN_ARRAY_DO_FINAL_CHECKS ();
          }
      }
    PCGEN_ARRAY_READ_ELEM_HD (Pstring_SE_read (pads,&(m->element),elt_pd,elt_rep,"/[. ]/"),haveData);
    PCGEN_ARRAY_TEST_READ_ERR (1,1);
    if (P_PS_isPanic (elt_pd)) 
      {
        {
          size_t offset;
          // Try to recover to separator
          if (P_OK==Pchar_lit_scan1 (pads,46,1,1,&offset)) 
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
    return sIP_final_checks (pads,m,pd,rep,loc_ptr,haveData);
  }
}
Perror_t sIP_read (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep)
{
  PDCI_IODISC_3P_CHECKS ("sIP_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc;
    Ploc_t *loc_ptr=&tloc;
    int i=0;
    int result;
    sIP_read_one_init (pads,m,pd,rep,loc_ptr);
    PCGEN_ARRAY_READ_ALL (PCGEN_ARRAY_RESERVE_SPACE (sIP,Pstring,Pbase_pd,0),sIP_read_one (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]),i = (rep->length),"sIP_read");
    return PCGEN_ARRAY_STD_RETURN ();
  }
}
Pread_res_t sIP_reread_one (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep,Ploc_t *loc_ptr,Pbase_pd *elt_pd,Pstring *elt_rep,int notFirstElt)
{
  PDCI_IODISC_3P_CHECKS ("sIP_reread_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("sIP_reread_one",elt_pd,elt_rep);
  {
    // Ready to read element
    if (notFirstElt) 
      {
        // Checking for separator
        if (P_ERR==Pchar_lit_match (pads,46,1)) 
          {
            // No separator, therefore array is finished
            return P_READ_ERR;
          }
      }
    PCGEN_ARRAY_REREAD_ELEM_BODY (Pstring_SE_read (pads,&(m->element),elt_pd,elt_rep,"/[. ]/"));
    return PCGEN_ARRAY_REREAD_ELEM_RET ();
  }
}
int sIP_verify (sIP *rep)
{
  int violated=0;
  return !violated;
}
Perror_t sIP_acc_init (P_t *pads,sIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==Pstring_acc_init (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t sIP_acc_reset (P_t *pads,sIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==Pstring_acc_reset (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t sIP_acc_cleanup (P_t *pads,sIP_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==Pstring_acc_cleanup (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t sIP_acc_add (P_t *pads,sIP_acc *acc,sIP_pd *pd,sIP *rep)
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
                if (P_ERR==Pstring_acc_add (pads,&(acc->arrayDetail)[i],&(pd->elts)[i],&(rep->elts)[i])) 
                  {
                    nerr++;
                  }
              }
            if (P_ERR==Pstring_acc_add (pads,&(acc->compoundLevel),&(pd->elts)[i],&(rep->elts)[i])) 
              {
                nerr++;
              }
          }
      }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t sIP_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,sIP_acc *acc)
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
      what = "array sIP of Pstring_SE";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_ARRAY_ACC_REP_NOVALS ();
  if (P_ERR==Puint32_acc_report2io (pads,outstr,"Array lengths","array length",-1,&(acc->length))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.allArrayElts",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),"all array element",nst,&(acc->compoundLevel))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  {
    int i;
    for (i = 0; i<((((acc->length).max)<10) ? (acc->length).max : 10); i++)
      {
        sfprintf (tmpstr,"%s.arrayDetail[%d]",prefix,i);
        if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),"array element",nst,&(acc->arrayDetail)[i])) 
          {
            sfstrclose (tmpstr);
            return P_ERR;
          }
      }
  }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t sIP_acc_report (P_t *pads,char const *prefix,char const *what,int nst,sIP_acc *acc)
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
  result = sIP_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t sIP_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sIP_pd *pd,sIP *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("sIP_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  {
    int i=0;
    if ((rep->length)>1) 
      {
        for (i = 0; i<((rep->length)-1); i++)
          {
            tlen_PCGEN_ = Pstring_SE_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"/[. ]/");
            PCGEN_TLEN_UPDATES ();
            tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,46);
            PCGEN_TLEN_UPDATES ();
          }
      }
    if ((rep->length)!=0) 
      {
        tlen_PCGEN_ = Pstring_SE_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"/[. ]/");
        PCGEN_TLEN_UPDATES ();
      }
  }
  return length_PCGEN_;
}
ssize_t sIP_write2io (P_t *pads,Sfio_t *io,sIP_pd *pd,sIP *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("sIP_write2io",sIP_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t sIP_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,sIP_pd *pd,sIP *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("sIP_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_ARRAY_OPEN_XML_OUT ();
  {
    int i=0;
    for (i = 0; i<(rep->length); i++)
      {
        tlen_PCGEN_ = Pstring_SE_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"elt",indent+2,"/[. ]/");
        PCGEN_TLEN_UPDATES ();
      }
  }
  PCGEN_XML_VALUE_OUT ("length",rep->length);
  PCGEN_ARRAY_PD_XML_OUT ();
  PCGEN_ARRAY_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t sIP_write_xml_2io (P_t *pads,Sfio_t *io,sIP_pd *pd,sIP *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("sIP_write_xml_2io",sIP_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t sIP_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sIP_m *m,sIP_pd *pd,sIP *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  int i=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("sIP_fmt2buf_final");
  PCGEN_FMT2BUF_ARRAY ("sIP_fmt2buf_final",Pstring_SE_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->element),&(pd->elts)[i],&(rep->elts)[i],"/[. ]/"));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t sIP_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,sIP_m *m,sIP_pd *pd,sIP *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("sIP_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"sIP"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return sIP_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t sIP_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,sIP_m *m,sIP_pd *pd,sIP *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("sIP_fmt2io",sIP_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *sIP_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (sIP);
  return NODE_NEW_RET ();
}
PDCI_node_t *sIP_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (sIP,ARR_LENGTH (sIP));
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *sIP_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_NODE_KTH_CHILD_BODY (sIP,Pstring);
  return ARR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *sIP_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ARR_NODE_KTH_CHILD_NAMED_BODY (sIP);
  return ARR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *sIP_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (sIP,ARR_LENGTH (sIP));
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *sIP_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (sIP);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *sIP_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_SND_NODE_KTH_CHILD_BODY (sIP,Pstring);
  return ARR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t sIP_node_pathWalk (P_t *pads,sIP_m *m,sIP_pd *pd,sIP *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ARR_NODE_PATH_WALK_BODY (Pstring);
  return ARR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const sIP_node_vtable={sIP_cachedNode_init,sIP_node_kthChild,sIP_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const sIP_cachedNode_vtable={PDCI_error_cachedNode_init,sIP_cachedNode_kthChild,sIP_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const sIP_sndNode_vtable={PDCI_error_cachedNode_init,sIP_sndNode_kthChild,sIP_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t clihost_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,clihost_t_pd *pd,clihost_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("clihost_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case resolved: 
      {
        tlen_PCGEN_ = nIP_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).resolved),&((rep->val).resolved));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case symbolic: 
      {
        tlen_PCGEN_ = sIP_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).symbolic),&((rep->val).symbolic));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case clihost_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t clihost_t_write2io (P_t *pads,Sfio_t *io,clihost_t_pd *pd,clihost_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("clihost_t_write2io",clihost_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t clihost_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,clihost_t_pd *pd,clihost_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("clihost_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("clihost_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case resolved: 
      {
        tlen_PCGEN_ = nIP_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).resolved),&((rep->val).resolved),"resolved",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case symbolic: 
      {
        tlen_PCGEN_ = sIP_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).symbolic),&((rep->val).symbolic),"symbolic",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case clihost_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t clihost_t_write_xml_2io (P_t *pads,Sfio_t *io,clihost_t_pd *pd,clihost_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("clihost_t_write_xml_2io",clihost_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
char const *clihost_t_tag2str (clihost_t_tag which)
{
  switch (which)
    {
      
    case resolved: 
      {
        return "resolved";
      }
      
    case symbolic: 
      {
        return "symbolic";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t clihost_t_init (P_t *pads,clihost_t *rep)
{
  PDCI_DISC_1P_CHECKS ("clihost_t_init",rep);
  memset ((void *) rep,0,sizeof(clihost_t));
  return P_OK;
}
Perror_t clihost_t_pd_init (P_t *pads,clihost_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("clihost_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(clihost_t_pd));
  return P_OK;
}
Perror_t clihost_t_cleanup (P_t *pads,clihost_t *rep)
{
  PDCI_DISC_1P_CHECKS ("clihost_t_cleanup",rep);
  switch (rep->tag)
    {
      
    case resolved: 
      return nIP_cleanup (pads,&((rep->val).resolved));
      
    case symbolic: 
      return sIP_cleanup (pads,&((rep->val).symbolic));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t clihost_t_pd_cleanup (P_t *pads,clihost_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("clihost_t_pd_cleanup",pd);
  switch (pd->tag)
    {
      
    case resolved: 
      return nIP_pd_cleanup (pads,&((pd->val).resolved));
      
    case symbolic: 
      return sIP_pd_cleanup (pads,&((pd->val).symbolic));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t clihost_t_copy (P_t *pads,clihost_t *rep_dst,clihost_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("clihost_t_copy",rep_src,rep_dst);
  PCGEN_UNION_COPY_PRE ("clihost_t_copy",clihost_t_cleanup);
  switch (rep_src->tag)
    {
      
    case resolved: 
      return nIP_copy (pads,&((rep_dst->val).resolved),&((rep_src->val).resolved));
      
    case symbolic: 
      return sIP_copy (pads,&((rep_dst->val).symbolic),&((rep_src->val).symbolic));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t clihost_t_pd_copy (P_t *pads,clihost_t_pd *pd_dst,clihost_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("clihost_t_pd_copy",pd_src,pd_dst);
  PCGEN_UNION_PD_COPY_PRE ("clihost_t_pd_copy",clihost_t_pd_cleanup);
  switch (pd_src->tag)
    {
      
    case resolved: 
      return nIP_pd_copy (pads,&((pd_dst->val).resolved),&((pd_src->val).resolved));
      
    case symbolic: 
      return sIP_pd_copy (pads,&((pd_dst->val).symbolic),&((pd_src->val).symbolic));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
void clihost_t_m_init (P_t *pads,clihost_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(clihost_t_m));
}
Perror_t clihost_t_read (P_t *pads,clihost_t_m *m,clihost_t_pd *pd,clihost_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("clihost_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    {
      PCGEN_UNION_READ_SETUP ("clihost_t_read",resolved,clihost_t_cleanup,clihost_t_init,clihost_t_copy,clihost_t_pd_cleanup,clihost_t_pd_init,clihost_t_pd_copy);
      // Read branch 'resolved'
      PCGEN_UNION_READ_FIRST ("clihost_t_read","resolved",resolved,clihost_t_cleanup,clihost_t_init,clihost_t_copy,clihost_t_pd_cleanup,clihost_t_pd_init,clihost_t_pd_copy,nIP_read (pads,&(m->resolved),&((pd->val).resolved),&((rep->val).resolved)),clihost_t_write_xml_2io (pads,sfstderr,pd,rep,"clihost_t",4),_NOOP);
      // Read branch 'symbolic'
      PCGEN_UNION_READ_LAST ("clihost_t_read","symbolic",symbolic,clihost_t_cleanup,clihost_t_init,clihost_t_copy,clihost_t_pd_cleanup,clihost_t_pd_init,clihost_t_pd_copy,sIP_read (pads,&(m->symbolic),&((pd->val).symbolic),&((rep->val).symbolic)),clihost_t_write_xml_2io (pads,sfstderr,pd,rep,"clihost_t",4),_NOOP);
      // Failed to match any branch of union clihost_t
      PCGEN_UNION_READ_CHECK_FAILED ("clihost_t_read","clihost_t",clihost_t_err);
      
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
int clihost_t_verify (clihost_t *rep)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case resolved: 
      {
        isValid = nIP_verify (&((rep->val).resolved));
        break;
      }
      
    case symbolic: 
      {
        isValid = sIP_verify (&((rep->val).symbolic));
        break;
      }
      
    case clihost_t_err: 
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
Perror_t clihost_t_acc_init (P_t *pads,clihost_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==nIP_acc_init (pads,&(acc->resolved))) 
    {
      nerr++;
    }
  if (P_ERR==sIP_acc_init (pads,&(acc->symbolic))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t clihost_t_acc_reset (P_t *pads,clihost_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==nIP_acc_reset (pads,&(acc->resolved))) 
    {
      nerr++;
    }
  if (P_ERR==sIP_acc_reset (pads,&(acc->symbolic))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t clihost_t_acc_cleanup (P_t *pads,clihost_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==nIP_acc_cleanup (pads,&(acc->resolved))) 
    {
      nerr++;
    }
  if (P_ERR==sIP_acc_cleanup (pads,&(acc->symbolic))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t clihost_t_acc_add (P_t *pads,clihost_t_acc *acc,clihost_t_pd *pd,clihost_t *rep)
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
          
        case resolved: 
          {
            if (P_ERR==nIP_acc_add (pads,&(acc->resolved),&((pd->val).resolved),&((rep->val).resolved))) 
              {
                nerr++;
              }
            break;
          }
          
        case symbolic: 
          {
            if (P_ERR==sIP_acc_add (pads,&(acc->symbolic),&((pd->val).symbolic),&((rep->val).symbolic))) 
              {
                nerr++;
              }
            break;
          }
          
        case clihost_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t clihost_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,clihost_t_acc *acc)
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
      what = "union clihost_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Union tag","tag",-1,(Pint32_map_fn) clihost_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.resolved",prefix);
  if (P_ERR==nIP_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->resolved))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.symbolic",prefix);
  if (P_ERR==sIP_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->symbolic))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t clihost_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,clihost_t_acc *acc)
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
  result = clihost_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t clihost_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,clihost_t_m *m,clihost_t_pd *pd,clihost_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("clihost_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case resolved: 
      {
        PCGEN_FMT2BUF_UNION ("nIP_fmt2buf",nIP_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->resolved),&((pd->val).resolved),&((rep->val).resolved)),"resolved");
        break;
      }
      
    case symbolic: 
      {
        PCGEN_FMT2BUF_UNION ("sIP_fmt2buf",sIP_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->symbolic),&((pd->val).symbolic),&((rep->val).symbolic)),"symbolic");
        break;
      }
      
    case clihost_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t clihost_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,clihost_t_m *m,clihost_t_pd *pd,clihost_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("clihost_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"clihost_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return clihost_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t clihost_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,clihost_t_m *m,clihost_t_pd *pd,clihost_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("clihost_t_fmt2io",clihost_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *clihost_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (clihost_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *clihost_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (clihost_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *clihost_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (clihost_t);
  UNION_NODE_KC_CASE (clihost_t,resolved,nIP);
  UNION_NODE_KC_CASE (clihost_t,symbolic,sIP);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *clihost_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (clihost_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *clihost_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (clihost_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *clihost_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (clihost_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *clihost_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (clihost_t);
  UNION_SND_NODE_KC_CASE (clihost_t,resolved,nIP);
  UNION_SND_NODE_KC_CASE (clihost_t,symbolic,sIP);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t clihost_t_node_pathWalk (P_t *pads,clihost_t_m *m,clihost_t_pd *pd,clihost_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (clihost_t);
  UNION_NODE_PW_CASE (resolved,nIP);
  UNION_NODE_PW_CASE (symbolic,sIP);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const clihost_t_node_vtable={clihost_t_cachedNode_init,clihost_t_node_kthChild,clihost_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const clihost_t_cachedNode_vtable={PDCI_error_cachedNode_init,clihost_t_cachedNode_kthChild,clihost_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const clihost_t_sndNode_vtable={PDCI_error_cachedNode_init,clihost_t_sndNode_kthChild,clihost_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t unknown_t_init (P_t *pads,unknown_t *rep)
{
  return P_OK;
}
Perror_t unknown_t_pd_init (P_t *pads,unknown_t_pd *pd)
{
  return P_OK;
}
Perror_t unknown_t_cleanup (P_t *pads,unknown_t *rep)
{
  return P_OK;
}
Perror_t unknown_t_pd_cleanup (P_t *pads,unknown_t_pd *pd)
{
  return P_OK;
}
Perror_t unknown_t_copy (P_t *pads,unknown_t *rep_dst,unknown_t *rep_src)
{
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(unknown_t));
  return P_OK;
}
Perror_t unknown_t_pd_copy (P_t *pads,unknown_t_pd *pd_dst,unknown_t_pd *pd_src)
{
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(unknown_t_pd));
  return P_OK;
}
void unknown_t_m_init (P_t *pads,unknown_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(unknown_t_m));
}
Perror_t unknown_t_read (P_t *pads,unknown_t_m *m,unknown_t_pd *pd,unknown_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("unknown_t_read",m,pd,rep);
  PCGEN_TYPEDEF_READ_CHECK ("unknown_t_read",Pchar_read (pads,&(m->base),pd,rep),(*rep)==45);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int unknown_t_verify (unknown_t *rep)
{
  return (*rep)==45;
}
Perror_t unknown_t_acc_init (P_t *pads,unknown_t_acc *acc)
{
  return Pchar_acc_init (pads,acc);
}
Perror_t unknown_t_acc_reset (P_t *pads,unknown_t_acc *acc)
{
  return Pchar_acc_reset (pads,acc);
}
Perror_t unknown_t_acc_cleanup (P_t *pads,unknown_t_acc *acc)
{
  return Pchar_acc_cleanup (pads,acc);
}
Perror_t unknown_t_acc_add (P_t *pads,unknown_t_acc *acc,unknown_t_pd *pd,unknown_t *rep)
{
  return Pchar_acc_add (pads,acc,pd,rep);
}
Perror_t unknown_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,unknown_t_acc *acc)
{
  PCGEN_TYPEDEF_ACC_REP2IO ("typedef unknown_t","Pchar",Pchar_acc_report2io (pads,outstr,prefix,what,nst,acc));
}
Perror_t unknown_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,unknown_t_acc *acc)
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
  result = unknown_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t unknown_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,unknown_t_pd *pd,unknown_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("unknown_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pchar_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t unknown_t_write2io (P_t *pads,Sfio_t *io,unknown_t_pd *pd,unknown_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("unknown_t_write2io",unknown_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t unknown_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,unknown_t_pd *pd,unknown_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("unknown_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  if (!tag) 
    tag = "unknown_t";
  tlen_PCGEN_ = Pchar_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,pd,rep,tag,indent);
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t unknown_t_write_xml_2io (P_t *pads,Sfio_t *io,unknown_t_pd *pd,unknown_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("unknown_t_write_xml_2io",unknown_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t unknown_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,unknown_t_m *m,unknown_t_pd *pd,unknown_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_TYPEDEF_FMT2BUF_FINAL_INIT ("unknown_t_fmt2buf_final");
  PCGEN_FMT2BUF_TYPEDEF (Pchar_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->base),pd,rep));
  return length_PCGEN_;
}
ssize_t unknown_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,unknown_t_m *m,unknown_t_pd *pd,unknown_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("unknown_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"unknown_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return unknown_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t unknown_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,unknown_t_m *m,unknown_t_pd *pd,unknown_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("unknown_t_fmt2io",unknown_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *unknown_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (unknown_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *unknown_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (unknown_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *unknown_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_NODE_KTH_CHILD_BODY (unknown_t,Pchar);
  return TYP_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *unknown_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  TYP_NODE_KTH_CHILD_NAMED_BODY ();
  return TYP_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *unknown_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (unknown_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *unknown_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (unknown_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *unknown_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  TYP_SND_NODE_KTH_CHILD_BODY (unknown_t,Pchar);
  return TYP_SND_NODE_KTH_CHILD_RET ();
}
Perror_t unknown_t_node_pathWalk (P_t *pads,unknown_t_m *m,unknown_t_pd *pd,unknown_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  TYP_NODE_PATH_WALK_BODY (Pchar);
  return TYP_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const unknown_t_node_vtable={unknown_t_cachedNode_init,unknown_t_node_kthChild,unknown_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const unknown_t_cachedNode_vtable={PDCI_error_cachedNode_init,unknown_t_cachedNode_kthChild,unknown_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const unknown_t_sndNode_vtable={PDCI_error_cachedNode_init,unknown_t_sndNode_kthChild,unknown_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t auth_id_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,auth_id_t_pd *pd,auth_id_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("auth_id_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case unauthorized: 
      {
        tlen_PCGEN_ = unknown_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).unauthorized),&((rep->val).unauthorized));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case id: 
      {
        tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).id),&((rep->val).id),32);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case auth_id_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t auth_id_t_write2io (P_t *pads,Sfio_t *io,auth_id_t_pd *pd,auth_id_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("auth_id_t_write2io",auth_id_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t auth_id_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,auth_id_t_pd *pd,auth_id_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("auth_id_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("auth_id_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case unauthorized: 
      {
        tlen_PCGEN_ = unknown_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).unauthorized),&((rep->val).unauthorized),"unauthorized",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case id: 
      {
        tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).id),&((rep->val).id),"id",indent+2,32);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case auth_id_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t auth_id_t_write_xml_2io (P_t *pads,Sfio_t *io,auth_id_t_pd *pd,auth_id_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("auth_id_t_write_xml_2io",auth_id_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
char const *auth_id_t_tag2str (auth_id_t_tag which)
{
  switch (which)
    {
      
    case unauthorized: 
      {
        return "unauthorized";
      }
      
    case id: 
      {
        return "id";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t auth_id_t_init (P_t *pads,auth_id_t *rep)
{
  PDCI_DISC_1P_CHECKS ("auth_id_t_init",rep);
  memset ((void *) rep,0,sizeof(auth_id_t));
  return P_OK;
}
Perror_t auth_id_t_pd_init (P_t *pads,auth_id_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("auth_id_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(auth_id_t_pd));
  return P_OK;
}
Perror_t auth_id_t_cleanup (P_t *pads,auth_id_t *rep)
{
  PDCI_DISC_1P_CHECKS ("auth_id_t_cleanup",rep);
  switch (rep->tag)
    {
      
    case id: 
      return Pstring_cleanup (pads,&((rep->val).id));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t auth_id_t_pd_cleanup (P_t *pads,auth_id_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("auth_id_t_pd_cleanup",pd);
  switch (pd->tag)
    {
      
    case id: 
      return Pstring_pd_cleanup (pads,&((pd->val).id));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t auth_id_t_copy (P_t *pads,auth_id_t *rep_dst,auth_id_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("auth_id_t_copy",rep_src,rep_dst);
  PCGEN_UNION_COPY_PRE ("auth_id_t_copy",auth_id_t_cleanup);
  switch (rep_src->tag)
    {
      
    case unauthorized: 
      {
        memcpy ((void *) (&((rep_dst->val).unauthorized)),(void *) (&((rep_src->val).unauthorized)),sizeof(unknown_t));
        return P_OK;
      }
      
    case id: 
      return Pstring_copy (pads,&((rep_dst->val).id),&((rep_src->val).id));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
Perror_t auth_id_t_pd_copy (P_t *pads,auth_id_t_pd *pd_dst,auth_id_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("auth_id_t_pd_copy",pd_src,pd_dst);
  PCGEN_UNION_PD_COPY_PRE ("auth_id_t_pd_copy",auth_id_t_pd_cleanup);
  switch (pd_src->tag)
    {
      
    case unauthorized: 
      {
        memcpy ((void *) (&((pd_dst->val).unauthorized)),(void *) (&((pd_src->val).unauthorized)),sizeof(unknown_t_pd));
        return P_OK;
      }
      
    case id: 
      return Pstring_pd_copy (pads,&((pd_dst->val).id),&((pd_src->val).id));
      
    default: 
      {
        //  (do nothing) 
        break;
      }
    }
  return P_OK;
}
void auth_id_t_m_init (P_t *pads,auth_id_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(auth_id_t_m));
}
Perror_t auth_id_t_read (P_t *pads,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("auth_id_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    {
      PCGEN_UNION_READ_SETUP ("auth_id_t_read",unauthorized,auth_id_t_cleanup,auth_id_t_init,auth_id_t_copy,auth_id_t_pd_cleanup,auth_id_t_pd_init,auth_id_t_pd_copy);
      // Read branch 'unauthorized'
      PCGEN_UNION_READ_FIRST ("auth_id_t_read","unauthorized",unauthorized,auth_id_t_cleanup,auth_id_t_init,auth_id_t_copy,auth_id_t_pd_cleanup,auth_id_t_pd_init,auth_id_t_pd_copy,unknown_t_read (pads,&(m->unauthorized),&((pd->val).unauthorized),&((rep->val).unauthorized)),auth_id_t_write_xml_2io (pads,sfstderr,pd,rep,"auth_id_t",4),_NOOP);
      // Read branch 'id'
      PCGEN_UNION_READ_LAST ("auth_id_t_read","id",id,auth_id_t_cleanup,auth_id_t_init,auth_id_t_copy,auth_id_t_pd_cleanup,auth_id_t_pd_init,auth_id_t_pd_copy,Pstring_read (pads,&(m->id),&((pd->val).id),&((rep->val).id),32),auth_id_t_write_xml_2io (pads,sfstderr,pd,rep,"auth_id_t",4),_NOOP);
      // Failed to match any branch of union auth_id_t
      PCGEN_UNION_READ_CHECK_FAILED ("auth_id_t_read","auth_id_t",auth_id_t_err);
      
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
int auth_id_t_verify (auth_id_t *rep)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case unauthorized: 
      {
        isValid = unknown_t_verify (&((rep->val).unauthorized));
        break;
      }
      
    case id: 
      {
        // PADS type has no is_ function and there is no user constraint
        break;
      }
      
    case auth_id_t_err: 
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
Perror_t auth_id_t_acc_init (P_t *pads,auth_id_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_init (pads,&(acc->unauthorized))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t auth_id_t_acc_reset (P_t *pads,auth_id_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_reset (pads,&(acc->unauthorized))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t auth_id_t_acc_cleanup (P_t *pads,auth_id_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_cleanup (pads,&(acc->unauthorized))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->id))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t auth_id_t_acc_add (P_t *pads,auth_id_t_acc *acc,auth_id_t_pd *pd,auth_id_t *rep)
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
          
        case unauthorized: 
          {
            if (P_ERR==unknown_t_acc_add (pads,&(acc->unauthorized),&((pd->val).unauthorized),&((rep->val).unauthorized))) 
              {
                nerr++;
              }
            break;
          }
          
        case id: 
          {
            if (P_ERR==Pstring_acc_add (pads,&(acc->id),&((pd->val).id),&((rep->val).id))) 
              {
                nerr++;
              }
            break;
          }
          
        case auth_id_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t auth_id_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,auth_id_t_acc *acc)
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
      what = "union auth_id_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Union tag","tag",-1,(Pint32_map_fn) auth_id_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.unauthorized",prefix);
  if (P_ERR==unknown_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->unauthorized))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.id",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->id))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t auth_id_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,auth_id_t_acc *acc)
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
  result = auth_id_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t auth_id_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("auth_id_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case unauthorized: 
      {
        PCGEN_FMT2BUF_UNION ("unknown_t_fmt2buf",unknown_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->unauthorized),&((pd->val).unauthorized),&((rep->val).unauthorized)),"unauthorized");
        break;
      }
      
    case id: 
      {
        PCGEN_FMT2BUF_UNION ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->id),&((pd->val).id),&((rep->val).id),32),"id");
        break;
      }
      
    case auth_id_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t auth_id_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("auth_id_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"auth_id_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return auth_id_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t auth_id_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("auth_id_t_fmt2io",auth_id_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *auth_id_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (auth_id_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *auth_id_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (auth_id_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *auth_id_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (auth_id_t);
  UNION_NODE_KC_CASE (auth_id_t,unauthorized,unknown_t);
  UNION_NODE_KC_CASE (auth_id_t,id,Pstring);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *auth_id_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (auth_id_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *auth_id_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (auth_id_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *auth_id_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (auth_id_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *auth_id_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (auth_id_t);
  UNION_SND_NODE_KC_CASE (auth_id_t,unauthorized,unknown_t);
  UNION_SND_NODE_KC_CASE (auth_id_t,id,Pstring);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t auth_id_t_node_pathWalk (P_t *pads,auth_id_t_m *m,auth_id_t_pd *pd,auth_id_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (auth_id_t);
  UNION_NODE_PW_CASE (unauthorized,unknown_t);
  UNION_NODE_PW_CASE (id,Pstring);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const auth_id_t_node_vtable={auth_id_t_cachedNode_init,auth_id_t_node_kthChild,auth_id_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const auth_id_t_cachedNode_vtable={PDCI_error_cachedNode_init,auth_id_t_cachedNode_kthChild,auth_id_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const auth_id_t_sndNode_vtable={PDCI_error_cachedNode_init,auth_id_t_sndNode_kthChild,auth_id_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
ssize_t contentOpt_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("contentOpt_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  switch (rep->tag)
    {
      
    case len: 
      {
        tlen_PCGEN_ = Puint32_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).len),&((rep->val).len));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case unavailable: 
      {
        tlen_PCGEN_ = unknown_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).unavailable),&((rep->val).unavailable));
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case contentOpt_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t contentOpt_t_write2io (P_t *pads,Sfio_t *io,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("contentOpt_t_write2io",contentOpt_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t contentOpt_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,contentOpt_t_pd *pd,contentOpt_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("contentOpt_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("contentOpt_t");
  PCGEN_UNION_PD_XML_OUT ();
  switch (rep->tag)
    {
      
    case len: 
      {
        tlen_PCGEN_ = Puint32_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).len),&((rep->val).len),"len",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case unavailable: 
      {
        tlen_PCGEN_ = unknown_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&((pd->val).unavailable),&((rep->val).unavailable),"unavailable",indent+2);
        PCGEN_TLEN_UPDATES ();
        break;
      }
      
    case contentOpt_t_err: 
      {
        // error case
        break;
      }
    }
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t contentOpt_t_write_xml_2io (P_t *pads,Sfio_t *io,contentOpt_t_pd *pd,contentOpt_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("contentOpt_t_write_xml_2io",contentOpt_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
char const *contentOpt_t_tag2str (contentOpt_t_tag which)
{
  switch (which)
    {
      
    case len: 
      {
        return "len";
      }
      
    case unavailable: 
      {
        return "unavailable";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t contentOpt_t_init (P_t *pads,contentOpt_t *rep)
{
  return P_OK;
}
Perror_t contentOpt_t_pd_init (P_t *pads,contentOpt_t_pd *pd)
{
  return P_OK;
}
Perror_t contentOpt_t_cleanup (P_t *pads,contentOpt_t *rep)
{
  return P_OK;
}
Perror_t contentOpt_t_pd_cleanup (P_t *pads,contentOpt_t_pd *pd)
{
  return P_OK;
}
Perror_t contentOpt_t_copy (P_t *pads,contentOpt_t *rep_dst,contentOpt_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("contentOpt_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(contentOpt_t));
  return P_OK;
}
Perror_t contentOpt_t_pd_copy (P_t *pads,contentOpt_t_pd *pd_dst,contentOpt_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("contentOpt_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(contentOpt_t_pd));
  return P_OK;
}
void contentOpt_t_m_init (P_t *pads,contentOpt_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(contentOpt_t_m));
}
Perror_t contentOpt_t_read (P_t *pads,contentOpt_t_m *m,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("contentOpt_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    {
      PCGEN_UNION_READ_SETUP_STAT ("contentOpt_t_read",len,contentOpt_t_cleanup,contentOpt_t_init,contentOpt_t_copy,contentOpt_t_pd_cleanup,contentOpt_t_pd_init,contentOpt_t_pd_copy);
      // Read branch 'len'
      PCGEN_UNION_READ_STAT ("contentOpt_t_read","len",len,contentOpt_t_cleanup,contentOpt_t_init,contentOpt_t_copy,contentOpt_t_pd_cleanup,contentOpt_t_pd_init,contentOpt_t_pd_copy,Puint32_read (pads,&(m->len),&((pd->val).len),&((rep->val).len)),contentOpt_t_write_xml_2io (pads,sfstderr,pd,rep,"contentOpt_t",4),_NOOP);
      // Read branch 'unavailable'
      PCGEN_UNION_READ_STAT ("contentOpt_t_read","unavailable",unavailable,contentOpt_t_cleanup,contentOpt_t_init,contentOpt_t_copy,contentOpt_t_pd_cleanup,contentOpt_t_pd_init,contentOpt_t_pd_copy,unknown_t_read (pads,&(m->unavailable),&((pd->val).unavailable),&((rep->val).unavailable)),contentOpt_t_write_xml_2io (pads,sfstderr,pd,rep,"contentOpt_t",4),_NOOP);
      // Failed to match any branch of union contentOpt_t
      PCGEN_UNION_READ_CHECK_FAILED ("contentOpt_t_read","contentOpt_t",contentOpt_t_err);
      
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
int contentOpt_t_verify (contentOpt_t *rep)
{
  int isValid=1;
  switch (rep->tag)
    {
      
    case len: 
      {
        // PADS type has no is_ function and there is no user constraint
        break;
      }
      
    case unavailable: 
      {
        isValid = unknown_t_verify (&((rep->val).unavailable));
        break;
      }
      
    case contentOpt_t_err: 
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
Perror_t contentOpt_t_acc_init (P_t *pads,contentOpt_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_init (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_init (pads,&(acc->len))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_init (pads,&(acc->unavailable))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t contentOpt_t_acc_reset (P_t *pads,contentOpt_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_reset (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_reset (pads,&(acc->len))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_reset (pads,&(acc->unavailable))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t contentOpt_t_acc_cleanup (P_t *pads,contentOpt_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Pint32_acc_cleanup (pads,&(acc->tag))) 
    {
      nerr++;
    }
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->len))) 
    {
      nerr++;
    }
  if (P_ERR==unknown_t_acc_cleanup (pads,&(acc->unavailable))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t contentOpt_t_acc_add (P_t *pads,contentOpt_t_acc *acc,contentOpt_t_pd *pd,contentOpt_t *rep)
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
          
        case len: 
          {
            if (P_ERR==Puint32_acc_add (pads,&(acc->len),&((pd->val).len),&((rep->val).len))) 
              {
                nerr++;
              }
            break;
          }
          
        case unavailable: 
          {
            if (P_ERR==unknown_t_acc_add (pads,&(acc->unavailable),&((pd->val).unavailable),&((rep->val).unavailable))) 
              {
                nerr++;
              }
            break;
          }
          
        case contentOpt_t_err: 
          {
            // error case
            break;
          }
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t contentOpt_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,contentOpt_t_acc *acc)
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
      what = "union contentOpt_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_UNION_ACC_REP_NOVALS ();
  if (P_ERR==Pint32_acc_map_report2io (pads,outstr,"Union tag","tag",-1,(Pint32_map_fn) contentOpt_t_tag2str,&(acc->tag))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each tag arm of %s]\n",prefix);
  sfprintf (tmpstr,"%s.len",prefix);
  if (P_ERR==Puint32_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->len))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.unavailable",prefix);
  if (P_ERR==unknown_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->unavailable))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t contentOpt_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,contentOpt_t_acc *acc)
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
  result = contentOpt_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t contentOpt_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,contentOpt_t_m *m,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("contentOpt_t_fmt2buf_final");
  switch (rep->tag)
    {
      
    case len: 
      {
        PCGEN_FMT2BUF_UNION ("Puint32_fmt2buf",Puint32_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->len),&((pd->val).len),&((rep->val).len)),"len");
        break;
      }
      
    case unavailable: 
      {
        PCGEN_FMT2BUF_UNION ("unknown_t_fmt2buf",unknown_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->unavailable),&((pd->val).unavailable),&((rep->val).unavailable)),"unavailable");
        break;
      }
      
    case contentOpt_t_err: 
      {
        // error case
        break;
      }
    }
  return length_PCGEN_;
}
ssize_t contentOpt_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,contentOpt_t_m *m,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("contentOpt_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"contentOpt_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return contentOpt_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t contentOpt_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,contentOpt_t_m *m,contentOpt_t_pd *pd,contentOpt_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("contentOpt_t_fmt2io",contentOpt_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *contentOpt_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (contentOpt_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *contentOpt_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (contentOpt_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *contentOpt_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_NODE_KTH_CHILD_BODY_BEGIN (contentOpt_t);
  UNION_NODE_KC_CASE (contentOpt_t,len,Puint32);
  UNION_NODE_KC_CASE (contentOpt_t,unavailable,unknown_t);
  UNION_NODE_KTH_CHILD_BODY_END ();
  return UNION_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *contentOpt_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  UNION_NODE_KTH_CHILD_NAMED_BODY (contentOpt_t);
  return UNION_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *contentOpt_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (contentOpt_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *contentOpt_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (contentOpt_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *contentOpt_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  UNION_SND_NODE_KTH_CHILD_BODY_BEGIN (contentOpt_t);
  UNION_SND_NODE_KC_CASE (contentOpt_t,len,Puint32);
  UNION_SND_NODE_KC_CASE (contentOpt_t,unavailable,unknown_t);
  UNION_SND_NODE_KTH_CHILD_BODY_END ();
  return UNION_SND_NODE_KTH_CHILD_RET ();
}
Perror_t contentOpt_t_node_pathWalk (P_t *pads,contentOpt_t_m *m,contentOpt_t_pd *pd,contentOpt_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  UNION_NODE_PATH_WALK_BODY_BEGIN (contentOpt_t);
  UNION_NODE_PW_CASE (len,Puint32);
  UNION_NODE_PW_CASE (unavailable,unknown_t);
  UNION_NODE_PATH_WALK_BODY_END ();
  return UNION_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const contentOpt_t_node_vtable={contentOpt_t_cachedNode_init,contentOpt_t_node_kthChild,contentOpt_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const contentOpt_t_cachedNode_vtable={PDCI_error_cachedNode_init,contentOpt_t_cachedNode_kthChild,contentOpt_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const contentOpt_t_sndNode_vtable={PDCI_error_cachedNode_init,contentOpt_t_sndNode_kthChild,contentOpt_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t http_v_t_init (P_t *pads,http_v_t *rep)
{
  return P_OK;
}
Perror_t http_v_t_pd_init (P_t *pads,http_v_t_pd *pd)
{
  return P_OK;
}
Perror_t http_v_t_cleanup (P_t *pads,http_v_t *rep)
{
  return P_OK;
}
Perror_t http_v_t_pd_cleanup (P_t *pads,http_v_t_pd *pd)
{
  return P_OK;
}
Perror_t http_v_t_copy (P_t *pads,http_v_t *rep_dst,http_v_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("http_v_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(http_v_t));
  return P_OK;
}
Perror_t http_v_t_pd_copy (P_t *pads,http_v_t_pd *pd_dst,http_v_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("http_v_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(http_v_t_pd));
  return P_OK;
}
void http_v_t_m_init (P_t *pads,http_v_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(http_v_t_m));
}
Perror_t http_v_t_read (P_t *pads,http_v_t_m *m,http_v_t_pd *pd,http_v_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("http_v_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read delimeter field: "HTTP/"
  PCGEN_STRUCT_READ_FIRST_STR_LIT ("http_v_t_read","HTTP/",5);
  // Read field 'major'
  PCGEN_STRUCT_READ_NEXT ("http_v_t_read",major,Puint8_read (pads,&(m->major),&(pd->major),&(rep->major)),_NOOP);
  // Read delimter field: '.'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_v_t_read",46);
  // Read field 'minor'
  PCGEN_STRUCT_READ_NEXT ("http_v_t_read",minor,Puint8_read (pads,&(m->minor),&(pd->minor),&(rep->minor)),_NOOP);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int http_v_t_verify (http_v_t *rep)
{
  return 1;
}
Perror_t http_v_t_acc_init (P_t *pads,http_v_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_init (pads,&(acc->major))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_init (pads,&(acc->minor))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_v_t_acc_reset (P_t *pads,http_v_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_reset (pads,&(acc->major))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_reset (pads,&(acc->minor))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_v_t_acc_cleanup (P_t *pads,http_v_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_cleanup (pads,&(acc->major))) 
    {
      nerr++;
    }
  if (P_ERR==Puint8_acc_cleanup (pads,&(acc->minor))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_v_t_acc_add (P_t *pads,http_v_t_acc *acc,http_v_t_pd *pd,http_v_t *rep)
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
      if (P_ERR==Puint8_acc_add (pads,&(acc->major),&(pd->major),&(rep->major))) 
        {
          nerr++;
        }
      if (P_ERR==Puint8_acc_add (pads,&(acc->minor),&(pd->minor),&(rep->minor))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_v_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,http_v_t_acc *acc)
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
      what = "struct http_v_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.major",prefix);
  if (P_ERR==Puint8_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->major))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.minor",prefix);
  if (P_ERR==Puint8_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->minor))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t http_v_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,http_v_t_acc *acc)
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
  result = http_v_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t http_v_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_v_t_pd *pd,http_v_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_v_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"HTTP/");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint8_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->major),&(rep->major));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,46);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint8_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->minor),&(rep->minor));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t http_v_t_write2io (P_t *pads,Sfio_t *io,http_v_t_pd *pd,http_v_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_v_t_write2io",http_v_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t http_v_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_v_t_pd *pd,http_v_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_v_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("http_v_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = Puint8_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->major),&(rep->major),"major",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint8_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->minor),&(rep->minor),"minor",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t http_v_t_write_xml_2io (P_t *pads,Sfio_t *io,http_v_t_pd *pd,http_v_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_v_t_write_xml_2io",http_v_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t http_v_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_v_t_m *m,http_v_t_pd *pd,http_v_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("http_v_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint8_fmt2buf",Puint8_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->major),&(pd->major),&(rep->major)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint8_fmt2buf",Puint8_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->minor),&(pd->minor),&(rep->minor)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t http_v_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_v_t_m *m,http_v_t_pd *pd,http_v_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("http_v_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"http_v_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return http_v_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t http_v_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,http_v_t_m *m,http_v_t_pd *pd,http_v_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_v_t_fmt2io",http_v_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *http_v_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (http_v_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *http_v_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (http_v_t,3);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *http_v_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (http_v_t);
  NODE_KC_CASE (http_v_t,0,Puint8,major);
  NODE_KC_CASE (http_v_t,1,Puint8,minor);
  STR_NODE_KTH_CHILD_BODY_END (2);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_v_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (http_v_t,"major","minor");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *http_v_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (http_v_t,3);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_v_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (http_v_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *http_v_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (http_v_t);
  SND_NODE_KC_CASE (http_v_t,0,Puint8,major);
  SND_NODE_KC_CASE (http_v_t,1,Puint8,minor);
  STR_SND_NODE_KTH_CHILD_BODY_END (2);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t http_v_t_node_pathWalk (P_t *pads,http_v_t_m *m,http_v_t_pd *pd,http_v_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,Puint8,major);
  NODE_PW_CASE (1,Puint8,minor);
  STR_NODE_PATH_WALK_BODY_END (2);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const http_v_t_node_vtable={http_v_t_cachedNode_init,http_v_t_node_kthChild,http_v_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_v_t_cachedNode_vtable={PDCI_error_cachedNode_init,http_v_t_cachedNode_kthChild,http_v_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_v_t_sndNode_vtable={PDCI_error_cachedNode_init,http_v_t_sndNode_kthChild,http_v_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
char const *http_method_t2str (http_method_t which)
{
  switch (which)
    {
      
    case GET: 
      {
        return "GET";
      }
      
    case PUT: 
      {
        return "PUT";
      }
      
    case POST: 
      {
        return "POST";
      }
      
    case HEAD: 
      {
        return "HEAD";
      }
      
    case DELETE: 
      {
        return "DELETE";
      }
      
    case LINK: 
      {
        return "LINK";
      }
      
    case UNLINK: 
      {
        return "UNLINK";
      }
      
    default: 
      {
        return "*unknown_tag*";
      }
    }
}
Perror_t http_method_t_init (P_t *pads,http_method_t *rep)
{
  return P_OK;
}
Perror_t http_method_t_pd_init (P_t *pads,http_method_t_pd *pd)
{
  return P_OK;
}
Perror_t http_method_t_cleanup (P_t *pads,http_method_t *rep)
{
  return P_OK;
}
Perror_t http_method_t_pd_cleanup (P_t *pads,http_method_t_pd *pd)
{
  return P_OK;
}
Perror_t http_method_t_copy (P_t *pads,http_method_t *rep_dst,http_method_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("http_method_t_copy",rep_src,rep_dst);
  memcpy ((void *) rep_dst,(void *) rep_src,sizeof(http_method_t));
  return P_OK;
}
Perror_t http_method_t_pd_copy (P_t *pads,http_method_t_pd *pd_dst,http_method_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("http_method_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) pd_dst,(void *) pd_src,sizeof(http_method_t_pd));
  return P_OK;
}
void http_method_t_m_init (P_t *pads,http_method_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(http_method_t_m));
}
Perror_t http_method_t_read (P_t *pads,http_method_t_m *m,http_method_t_pd *pd,http_method_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("http_method_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Pstring strlit;
    Perror_t result;
    strlit.str = "GET";
    strlit.len = 3;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = GET;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "PUT";
    strlit.len = 3;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = PUT;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "POST";
    strlit.len = 4;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = POST;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "HEAD";
    strlit.len = 4;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = HEAD;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "DELETE";
    strlit.len = 6;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = DELETE;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "LINK";
    strlit.len = 4;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = LINK;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    strlit.str = "UNLINK";
    strlit.len = 6;
    if (P_ERR==P_io_checkpoint (pads,1)) 
      {
        PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR,"http_method_t_read",0);
      }
    if (P_ERR==Pstr_lit_match (pads,&strlit,1)) 
      {
        if (P_ERR==P_io_restore (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_RESTORE_ERR,"http_method_t_read",0);
          }
      }
    else
      {
        if (P_ERR==P_io_commit (pads)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_COMMIT_ERR,"http_method_t_read",0);
          }
        *rep = UNLINK;
        result = P_OK;
        goto http_method_t_findpostlude;
      }
    // We didn't match any branch
    pd->errCode = P_ENUM_MATCH_ERR;
    PDCI_READFN_GETLOC_SPAN0 (pads,pd->loc);
    PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,"http_method_t_read","Did not match any branch of enum http_method_t");
    P_PS_setPanic (pd);
    result = P_ERR;
    
  http_method_t_findpostlude: 
    {
      return result;
    }
  }
}
int http_method_t_verify (http_method_t *rep)
{
  switch (*rep)
    {
      
    case GET: 
      {
        return 1;
      }
      
    case PUT: 
      {
        return 1;
      }
      
    case POST: 
      {
        return 1;
      }
      
    case HEAD: 
      {
        return 1;
      }
      
    case DELETE: 
      {
        return 1;
      }
      
    case LINK: 
      {
        return 1;
      }
      
    case UNLINK: 
      {
        return 1;
      }
      
    default: 
      {
        return 0;
      }
    }
  return 1;
}
Perror_t http_method_t_acc_init (P_t *pads,http_method_t_acc *acc)
{
  return Pint32_acc_init (pads,acc);
}
Perror_t http_method_t_acc_reset (P_t *pads,http_method_t_acc *acc)
{
  return Pint32_acc_reset (pads,acc);
}
Perror_t http_method_t_acc_cleanup (P_t *pads,http_method_t_acc *acc)
{
  return Pint32_acc_cleanup (pads,acc);
}
Perror_t http_method_t_acc_add (P_t *pads,http_method_t_acc *acc,http_method_t_pd *pd,http_method_t *rep)
{
  return Pint32_acc_add (pads,acc,pd,(Pint32 *) rep);
}
Perror_t http_method_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,http_method_t_acc *acc)
{
  PCGEN_ENUM_ACC_REP2IO ("enum http_method_t",Pint32_acc_map_report2io (pads,outstr,prefix,what,nst,(Pint32_map_fn) http_method_t2str,acc));
}
Perror_t http_method_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,http_method_t_acc *acc)
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
  result = http_method_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t http_method_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_method_t_pd *pd,http_method_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_method_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,http_method_t2str (*rep));
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t http_method_t_write2io (P_t *pads,Sfio_t *io,http_method_t_pd *pd,http_method_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_method_t_write2io",http_method_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t http_method_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_method_t_pd *pd,http_method_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_method_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_ENUM_XML_OUT ("http_method_t",http_method_t2str);
  return length_PCGEN_;
}
ssize_t http_method_t_write_xml_2io (P_t *pads,Sfio_t *io,http_method_t_pd *pd,http_method_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_method_t_write_xml_2io",http_method_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t http_method_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_method_t_m *m,http_method_t_pd *pd,http_method_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_ENUM_FMT2BUF_FINAL_INIT ("http_method_t_fmt2buf_final");
  PCGEN_FMT2BUF_ENUM ("http_method_t_fmt2buf_final",http_method_t2str (*rep));
  return length_PCGEN_;
}
ssize_t http_method_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_method_t_m *m,http_method_t_pd *pd,http_method_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_ENUM_FMT2BUF_INIT ("http_method_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"http_method_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return http_method_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t http_method_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,http_method_t_m *m,http_method_t_pd *pd,http_method_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_method_t_fmt2io",http_method_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *http_method_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (http_method_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *http_method_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (http_method_t,2);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *http_method_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ENUM_NODE_KTH_CHILD_BODY (http_method_t);
  return ENUM_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_method_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ENUM_NODE_KTH_CHILD_NAMED_BODY ();
  return ENUM_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *http_method_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (http_method_t,2);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_method_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (http_method_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *http_method_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ENUM_SND_NODE_KTH_CHILD_BODY (http_method_t);
  return ENUM_SND_NODE_KTH_CHILD_RET ();
}
Perror_t http_method_t_node_pathWalk (P_t *pads,http_method_t_m *m,http_method_t_pd *pd,http_method_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ENUM_NODE_PATH_WALK_BODY (http_method_t);
  return ENUM_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const http_method_t_node_vtable={http_method_t_cachedNode_init,http_method_t_node_kthChild,http_method_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_method_t_cachedNode_vtable={PDCI_error_cachedNode_init,http_method_t_cachedNode_kthChild,http_method_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_method_t_sndNode_vtable={PDCI_error_cachedNode_init,http_method_t_sndNode_kthChild,http_method_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
int checkVersion (http_v_t version,http_method_t meth)
{
  if (((version.major)==1)&&((version.minor)==1)) 
    return 1;
  if ((meth==LINK)||(meth==UNLINK)) 
    return 0;
  return 1;
}
Perror_t http_request_t_init (P_t *pads,http_request_t *rep)
{
  PDCI_DISC_1P_CHECKS ("http_request_t_init",rep);
  memset ((void *) rep,0,sizeof(http_request_t));
  return P_OK;
}
Perror_t http_request_t_pd_init (P_t *pads,http_request_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("http_request_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(http_request_t_pd));
  return P_OK;
}
Perror_t http_request_t_cleanup (P_t *pads,http_request_t *rep)
{
  PDCI_DISC_1P_CHECKS ("http_request_t_cleanup",rep);
  Pstring_cleanup (pads,&(rep->req_uri));
  return P_OK;
}
Perror_t http_request_t_pd_cleanup (P_t *pads,http_request_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("http_request_t_pd_cleanup",pd);
  Pstring_pd_cleanup (pads,&(pd->req_uri));
  return P_OK;
}
Perror_t http_request_t_copy (P_t *pads,http_request_t *rep_dst,http_request_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("http_request_t_copy",rep_src,rep_dst);
  memcpy ((void *) (&(rep_dst->meth)),(void *) (&(rep_src->meth)),sizeof(http_method_t));
  Pstring_copy (pads,&(rep_dst->req_uri),&(rep_src->req_uri));
  memcpy ((void *) (&(rep_dst->version)),(void *) (&(rep_src->version)),sizeof(http_v_t));
  return P_OK;
}
Perror_t http_request_t_pd_copy (P_t *pads,http_request_t_pd *pd_dst,http_request_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("http_request_t_pd_copy",pd_src,pd_dst);
  memcpy ((void *) (&(pd_dst->meth)),(void *) (&(pd_src->meth)),sizeof(http_method_t_pd));
  Pstring_pd_copy (pads,&(pd_dst->req_uri),&(pd_src->req_uri));
  memcpy ((void *) (&(pd_dst->version)),(void *) (&(pd_src->version)),sizeof(http_v_t_pd));
  return P_OK;
}
void http_request_t_m_init (P_t *pads,http_request_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(http_request_t_m));
}
Perror_t http_request_t_read (P_t *pads,http_request_t_m *m,http_request_t_pd *pd,http_request_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("http_request_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read delimter field: '\"'
  PCGEN_STRUCT_READ_FIRST_CHAR_LIT ("http_request_t_read",34);
  // Read field 'meth'
  PCGEN_STRUCT_READ_NEXT ("http_request_t_read",meth,http_method_t_read (pads,&(m->meth),&(pd->meth),&(rep->meth)),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_request_t_read",32);
  // Read field 'req_uri'
  PCGEN_STRUCT_READ_NEXT ("http_request_t_read",req_uri,Pstring_read (pads,&(m->req_uri),&(pd->req_uri),&(rep->req_uri),32),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_request_t_read",32);
  // Read field 'version'
  PCGEN_STRUCT_READ_NEXT_CHECK ("http_request_t_read",version,http_v_t_read (pads,&(m->version),&(pd->version),&(rep->version)),checkVersion (rep->version,rep->meth),_NOOP);
  // Read delimter field: '\"'
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_request_t_read",34);
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int http_request_t_verify (http_request_t *rep)
{
  return http_method_t_verify (&(rep->meth))&&(http_v_t_verify (&(rep->version))&&(checkVersion (rep->version,rep->meth)&&1));
}
Perror_t http_request_t_acc_init (P_t *pads,http_request_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==http_method_t_acc_init (pads,&(acc->meth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->req_uri))) 
    {
      nerr++;
    }
  if (P_ERR==http_v_t_acc_init (pads,&(acc->version))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_request_t_acc_reset (P_t *pads,http_request_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==http_method_t_acc_reset (pads,&(acc->meth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->req_uri))) 
    {
      nerr++;
    }
  if (P_ERR==http_v_t_acc_reset (pads,&(acc->version))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_request_t_acc_cleanup (P_t *pads,http_request_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==http_method_t_acc_cleanup (pads,&(acc->meth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->req_uri))) 
    {
      nerr++;
    }
  if (P_ERR==http_v_t_acc_cleanup (pads,&(acc->version))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_request_t_acc_add (P_t *pads,http_request_t_acc *acc,http_request_t_pd *pd,http_request_t *rep)
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
      if (P_ERR==http_method_t_acc_add (pads,&(acc->meth),&(pd->meth),&(rep->meth))) 
        {
          nerr++;
        }
      if (P_ERR==Pstring_acc_add (pads,&(acc->req_uri),&(pd->req_uri),&(rep->req_uri))) 
        {
          nerr++;
        }
      if (P_ERR==http_v_t_acc_add (pads,&(acc->version),&(pd->version),&(rep->version))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_request_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,http_request_t_acc *acc)
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
      what = "struct http_request_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.meth",prefix);
  if (P_ERR==http_method_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->meth))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.req_uri",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->req_uri))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.version",prefix);
  if (P_ERR==http_v_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->version))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t http_request_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,http_request_t_acc *acc)
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
  result = http_request_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t http_request_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_request_t_pd *pd,http_request_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_request_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,34);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = http_method_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->meth),&(rep->meth));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->req_uri),&(rep->req_uri),32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = http_v_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->version),&(rep->version));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,34);
  PCGEN_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t http_request_t_write2io (P_t *pads,Sfio_t *io,http_request_t_pd *pd,http_request_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_request_t_write2io",http_request_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t http_request_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_request_t_pd *pd,http_request_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_request_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("http_request_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = http_method_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->meth),&(rep->meth),"meth",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->req_uri),&(rep->req_uri),"req_uri",indent+2,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = http_v_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->version),&(rep->version),"version",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t http_request_t_write_xml_2io (P_t *pads,Sfio_t *io,http_request_t_pd *pd,http_request_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_request_t_write_xml_2io",http_request_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t http_request_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_request_t_m *m,http_request_t_pd *pd,http_request_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("http_request_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("http_method_t_fmt2buf",http_method_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->meth),&(pd->meth),&(rep->meth)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->req_uri),&(pd->req_uri),&(rep->req_uri),32));
  PCGEN_FMT2BUF_STRUCT_FIELD ("http_v_t_fmt2buf",http_v_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->version),&(pd->version),&(rep->version)));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t http_request_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_request_t_m *m,http_request_t_pd *pd,http_request_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("http_request_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"http_request_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return http_request_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t http_request_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,http_request_t_m *m,http_request_t_pd *pd,http_request_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_request_t_fmt2io",http_request_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *http_request_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (http_request_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *http_request_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (http_request_t,4);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *http_request_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (http_request_t);
  NODE_KC_CASE (http_request_t,0,http_method_t,meth);
  NODE_KC_CASE (http_request_t,1,Pstring,req_uri);
  NODE_KC_CASE (http_request_t,2,http_v_t,version);
  STR_NODE_KTH_CHILD_BODY_END (3);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_request_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (http_request_t,"meth","req_uri","version");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *http_request_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (http_request_t,4);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_request_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (http_request_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *http_request_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (http_request_t);
  SND_NODE_KC_CASE (http_request_t,0,http_method_t,meth);
  SND_NODE_KC_CASE (http_request_t,1,Pstring,req_uri);
  SND_NODE_KC_CASE (http_request_t,2,http_v_t,version);
  STR_SND_NODE_KTH_CHILD_BODY_END (3);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t http_request_t_node_pathWalk (P_t *pads,http_request_t_m *m,http_request_t_pd *pd,http_request_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,http_method_t,meth);
  NODE_PW_CASE (1,Pstring,req_uri);
  NODE_PW_CASE (2,http_v_t,version);
  STR_NODE_PATH_WALK_BODY_END (3);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const http_request_t_node_vtable={http_request_t_cachedNode_init,http_request_t_node_kthChild,http_request_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_request_t_cachedNode_vtable={PDCI_error_cachedNode_init,http_request_t_cachedNode_kthChild,http_request_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_request_t_sndNode_vtable={PDCI_error_cachedNode_init,http_request_t_sndNode_kthChild,http_request_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t http_clf_t_init (P_t *pads,http_clf_t *rep)
{
  PDCI_DISC_1P_CHECKS ("http_clf_t_init",rep);
  memset ((void *) rep,0,sizeof(http_clf_t));
  return P_OK;
}
Perror_t http_clf_t_pd_init (P_t *pads,http_clf_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("http_clf_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(http_clf_t_pd));
  return P_OK;
}
Perror_t http_clf_t_cleanup (P_t *pads,http_clf_t *rep)
{
  PDCI_DISC_1P_CHECKS ("http_clf_t_cleanup",rep);
  clihost_t_cleanup (pads,&(rep->host));
  auth_id_t_cleanup (pads,&(rep->remoteID));
  auth_id_t_cleanup (pads,&(rep->auth));
  Pstring_cleanup (pads,&(rep->ts));
  http_request_t_cleanup (pads,&(rep->request));
  return P_OK;
}
Perror_t http_clf_t_pd_cleanup (P_t *pads,http_clf_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("http_clf_t_pd_cleanup",pd);
  clihost_t_pd_cleanup (pads,&(pd->host));
  auth_id_t_pd_cleanup (pads,&(pd->remoteID));
  auth_id_t_pd_cleanup (pads,&(pd->auth));
  Pstring_pd_cleanup (pads,&(pd->ts));
  http_request_t_pd_cleanup (pads,&(pd->request));
  return P_OK;
}
Perror_t http_clf_t_copy (P_t *pads,http_clf_t *rep_dst,http_clf_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("http_clf_t_copy",rep_src,rep_dst);
  clihost_t_copy (pads,&(rep_dst->host),&(rep_src->host));
  auth_id_t_copy (pads,&(rep_dst->remoteID),&(rep_src->remoteID));
  auth_id_t_copy (pads,&(rep_dst->auth),&(rep_src->auth));
  Pstring_copy (pads,&(rep_dst->ts),&(rep_src->ts));
  http_request_t_copy (pads,&(rep_dst->request),&(rep_src->request));
  // Copy fields response, contentLength
  memcpy ((void *) (&(rep_dst->response)),(void *) (&(rep_src->response)),(sizeof(Puint16))+(sizeof(contentOpt_t)));
  return P_OK;
}
Perror_t http_clf_t_pd_copy (P_t *pads,http_clf_t_pd *pd_dst,http_clf_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("http_clf_t_pd_copy",pd_src,pd_dst);
  clihost_t_pd_copy (pads,&(pd_dst->host),&(pd_src->host));
  auth_id_t_pd_copy (pads,&(pd_dst->remoteID),&(pd_src->remoteID));
  auth_id_t_pd_copy (pads,&(pd_dst->auth),&(pd_src->auth));
  Pstring_pd_copy (pads,&(pd_dst->ts),&(pd_src->ts));
  http_request_t_pd_copy (pads,&(pd_dst->request),&(pd_src->request));
  // Copy fields response, contentLength
  memcpy ((void *) (&(pd_dst->response)),(void *) (&(pd_src->response)),(sizeof(Pbase_pd))+(sizeof(contentOpt_t_pd)));
  return P_OK;
}
void http_clf_t_m_init (P_t *pads,http_clf_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(http_clf_t_m));
}
Perror_t http_clf_t_read (P_t *pads,http_clf_t_m *m,http_clf_t_pd *pd,http_clf_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("http_clf_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  // Read field 'host'
  PCGEN_STRUCT_READ_FIRST ("http_clf_t_read",host,clihost_t_read (pads,&(m->host),&(pd->host),&(rep->host)),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_clf_t_read",32);
  // Read field 'remoteID'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",remoteID,auth_id_t_read (pads,&(m->remoteID),&(pd->remoteID),&(rep->remoteID)),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_clf_t_read",32);
  // Read field 'auth'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",auth,auth_id_t_read (pads,&(m->auth),&(pd->auth),&(rep->auth)),_NOOP);
  // Read delimeter field: " ["
  PCGEN_STRUCT_READ_NEXT_STR_LIT ("http_clf_t_read"," [",2);
  // Read field 'ts'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",ts,Pstring_read (pads,&(m->ts),&(pd->ts),&(rep->ts),93),_NOOP);
  // Read delimeter field: "] "
  PCGEN_STRUCT_READ_NEXT_STR_LIT ("http_clf_t_read","] ",2);
  // Read field 'request'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",request,http_request_t_read (pads,&(m->request),&(pd->request),&(rep->request)),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_clf_t_read",32);
  // Read field 'response'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",response,Puint16_FW_read (pads,&(m->response),&(pd->response),&(rep->response),3),_NOOP);
  // Read delimter field: ' '
  PCGEN_STRUCT_READ_NEXT_CHAR_LIT ("http_clf_t_read",32);
  // Read field 'contentLength'
  PCGEN_STRUCT_READ_NEXT ("http_clf_t_read",contentLength,contentOpt_t_read (pads,&(m->contentLength),&(pd->contentLength),&(rep->contentLength)),_NOOP);
  PCGEN_FIND_EOR ("http_clf_t_read");
  return ((pd->nerr)==0) ? P_OK : P_ERR;
}
int http_clf_t_verify (http_clf_t *rep)
{
  return clihost_t_verify (&(rep->host))&&(auth_id_t_verify (&(rep->remoteID))&&(auth_id_t_verify (&(rep->auth))&&(http_request_t_verify (&(rep->request))&&(contentOpt_t_verify (&(rep->contentLength))&&1))));
}
Perror_t http_clf_t_acc_init (P_t *pads,http_clf_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==clihost_t_acc_init (pads,&(acc->host))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_init (pads,&(acc->remoteID))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_init (pads,&(acc->auth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_init (pads,&(acc->ts))) 
    {
      nerr++;
    }
  if (P_ERR==http_request_t_acc_init (pads,&(acc->request))) 
    {
      nerr++;
    }
  if (P_ERR==Puint16_acc_init (pads,&(acc->response))) 
    {
      nerr++;
    }
  if (P_ERR==contentOpt_t_acc_init (pads,&(acc->contentLength))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_clf_t_acc_reset (P_t *pads,http_clf_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==clihost_t_acc_reset (pads,&(acc->host))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_reset (pads,&(acc->remoteID))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_reset (pads,&(acc->auth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_reset (pads,&(acc->ts))) 
    {
      nerr++;
    }
  if (P_ERR==http_request_t_acc_reset (pads,&(acc->request))) 
    {
      nerr++;
    }
  if (P_ERR==Puint16_acc_reset (pads,&(acc->response))) 
    {
      nerr++;
    }
  if (P_ERR==contentOpt_t_acc_reset (pads,&(acc->contentLength))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_clf_t_acc_cleanup (P_t *pads,http_clf_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->nerr))) 
    {
      nerr++;
    }
  if (P_ERR==clihost_t_acc_cleanup (pads,&(acc->host))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_cleanup (pads,&(acc->remoteID))) 
    {
      nerr++;
    }
  if (P_ERR==auth_id_t_acc_cleanup (pads,&(acc->auth))) 
    {
      nerr++;
    }
  if (P_ERR==Pstring_acc_cleanup (pads,&(acc->ts))) 
    {
      nerr++;
    }
  if (P_ERR==http_request_t_acc_cleanup (pads,&(acc->request))) 
    {
      nerr++;
    }
  if (P_ERR==Puint16_acc_cleanup (pads,&(acc->response))) 
    {
      nerr++;
    }
  if (P_ERR==contentOpt_t_acc_cleanup (pads,&(acc->contentLength))) 
    {
      nerr++;
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_clf_t_acc_add (P_t *pads,http_clf_t_acc *acc,http_clf_t_pd *pd,http_clf_t *rep)
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
      if (P_ERR==clihost_t_acc_add (pads,&(acc->host),&(pd->host),&(rep->host))) 
        {
          nerr++;
        }
      if (P_ERR==auth_id_t_acc_add (pads,&(acc->remoteID),&(pd->remoteID),&(rep->remoteID))) 
        {
          nerr++;
        }
      if (P_ERR==auth_id_t_acc_add (pads,&(acc->auth),&(pd->auth),&(rep->auth))) 
        {
          nerr++;
        }
      if (P_ERR==Pstring_acc_add (pads,&(acc->ts),&(pd->ts),&(rep->ts))) 
        {
          nerr++;
        }
      if (P_ERR==http_request_t_acc_add (pads,&(acc->request),&(pd->request),&(rep->request))) 
        {
          nerr++;
        }
      if (P_ERR==Puint16_acc_add (pads,&(acc->response),&(pd->response),&(rep->response))) 
        {
          nerr++;
        }
      if (P_ERR==contentOpt_t_acc_add (pads,&(acc->contentLength),&(pd->contentLength),&(rep->contentLength))) 
        {
          nerr++;
        }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t http_clf_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,http_clf_t_acc *acc)
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
      what = "struct http_clf_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_STRUCT_ACC_REP_NOVALS ();
  if (P_ERR==P_nerr_acc_report2io (pads,outstr,"Errors","errors",-1,&(acc->nerr))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (outstr,"\n[Describing each field of %s]\n",prefix);
  sfprintf (tmpstr,"%s.host",prefix);
  if (P_ERR==clihost_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->host))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.remoteID",prefix);
  if (P_ERR==auth_id_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->remoteID))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.auth",prefix);
  if (P_ERR==auth_id_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->auth))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.ts",prefix);
  if (P_ERR==Pstring_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->ts))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.request",prefix);
  if (P_ERR==http_request_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->request))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.response",prefix);
  if (P_ERR==Puint16_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->response))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.contentLength",prefix);
  if (P_ERR==contentOpt_t_acc_report2io (pads,outstr,sfstruse (tmpstr),0,nst,&(acc->contentLength))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t http_clf_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,http_clf_t_acc *acc)
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
  result = http_clf_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t http_clf_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_clf_t_pd *pd,http_clf_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_clf_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  tlen_PCGEN_ = PDCI_io_rec_open_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"http_clf_t_write2buf");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = clihost_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->host),&(rep->host));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = auth_id_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->remoteID),&(rep->remoteID));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = auth_id_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->auth),&(rep->auth));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full," [");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ts),&(rep->ts),93);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,"] ");
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = http_request_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->request),&(rep->request));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint16_FW_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->response),&(rep->response),3);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,32);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = contentOpt_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->contentLength),&(rep->contentLength));
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = PDCI_io_rec_close_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,buf,length_PCGEN_,"http_clf_t_write2buf");
  PCGEN_FINAL_TLEN_UPDATES ();
  return length_PCGEN_;
}
ssize_t http_clf_t_write2io (P_t *pads,Sfio_t *io,http_clf_t_pd *pd,http_clf_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_clf_t_write2io",http_clf_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t http_clf_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,http_clf_t_pd *pd,http_clf_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("http_clf_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_TAG_OPEN_XML_OUT ("http_clf_t");
  PCGEN_STRUCT_PD_XML_OUT ();
  tlen_PCGEN_ = clihost_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->host),&(rep->host),"host",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = auth_id_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->remoteID),&(rep->remoteID),"remoteID",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = auth_id_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->auth),&(rep->auth),"auth",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Pstring_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->ts),&(rep->ts),"ts",indent+2,93);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = http_request_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->request),&(rep->request),"request",indent+2);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = Puint16_FW_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->response),&(rep->response),"response",indent+2,3);
  PCGEN_TLEN_UPDATES ();
  tlen_PCGEN_ = contentOpt_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->contentLength),&(rep->contentLength),"contentLength",indent+2);
  PCGEN_TLEN_UPDATES ();
  PCGEN_TAG_CLOSE_XML_OUT ();
  return length_PCGEN_;
}
ssize_t http_clf_t_write_xml_2io (P_t *pads,Sfio_t *io,http_clf_t_pd *pd,http_clf_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_clf_t_write_xml_2io",http_clf_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t http_clf_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_clf_t_m *m,http_clf_t_pd *pd,http_clf_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("http_clf_t_fmt2buf_final");
  PCGEN_FMT2BUF_STRUCT_FIELD ("clihost_t_fmt2buf",clihost_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->host),&(pd->host),&(rep->host)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("auth_id_t_fmt2buf",auth_id_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->remoteID),&(pd->remoteID),&(rep->remoteID)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("auth_id_t_fmt2buf",auth_id_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->auth),&(pd->auth),&(rep->auth)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Pstring_fmt2buf",Pstring_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->ts),&(pd->ts),&(rep->ts),93));
  PCGEN_FMT2BUF_STRUCT_FIELD ("http_request_t_fmt2buf",http_request_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->request),&(pd->request),&(rep->request)));
  PCGEN_FMT2BUF_STRUCT_FIELD ("Puint16_FW_fmt2buf",Puint16_FW_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->response),&(pd->response),&(rep->response),3));
  PCGEN_FMT2BUF_STRUCT_FIELD ("contentOpt_t_fmt2buf",contentOpt_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->contentLength),&(pd->contentLength),&(rep->contentLength)));
  PCGEN_FMT2BUF_FIX_LAST ();
  PCGEN_FMT2BUF_RECORD ("http_clf_t_fmt2buf_final");
  return length_PCGEN_;
}
ssize_t http_clf_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,http_clf_t_m *m,http_clf_t_pd *pd,http_clf_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("http_clf_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"http_clf_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return http_clf_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t http_clf_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,http_clf_t_m *m,http_clf_t_pd *pd,http_clf_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("http_clf_t_fmt2io",http_clf_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *http_clf_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (http_clf_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *http_clf_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (http_clf_t,8);
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *http_clf_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_NODE_KTH_CHILD_BODY_BEGIN (http_clf_t);
  NODE_KC_CASE (http_clf_t,0,clihost_t,host);
  NODE_KC_CASE (http_clf_t,1,auth_id_t,remoteID);
  NODE_KC_CASE (http_clf_t,2,auth_id_t,auth);
  NODE_KC_CASE (http_clf_t,3,Pstring,ts);
  NODE_KC_CASE (http_clf_t,4,http_request_t,request);
  NODE_KC_CASE (http_clf_t,5,Puint16,response);
  NODE_KC_CASE (http_clf_t,6,contentOpt_t,contentLength);
  STR_NODE_KTH_CHILD_BODY_END (7);
  return STR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_clf_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  STR_NODE_KTH_CHILD_NAMED_BODY (http_clf_t,"host","remoteID","auth","ts","request","response","contentLength");
  return STR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *http_clf_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (http_clf_t,8);
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *http_clf_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (http_clf_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *http_clf_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  STR_SND_NODE_KTH_CHILD_BODY_BEGIN (http_clf_t);
  SND_NODE_KC_CASE (http_clf_t,0,clihost_t,host);
  SND_NODE_KC_CASE (http_clf_t,1,auth_id_t,remoteID);
  SND_NODE_KC_CASE (http_clf_t,2,auth_id_t,auth);
  SND_NODE_KC_CASE (http_clf_t,3,Pstring,ts);
  SND_NODE_KC_CASE (http_clf_t,4,http_request_t,request);
  SND_NODE_KC_CASE (http_clf_t,5,Puint16,response);
  SND_NODE_KC_CASE (http_clf_t,6,contentOpt_t,contentLength);
  STR_SND_NODE_KTH_CHILD_BODY_END (7);
  return STR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t http_clf_t_node_pathWalk (P_t *pads,http_clf_t_m *m,http_clf_t_pd *pd,http_clf_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  STR_NODE_PATH_WALK_BODY_BEGIN ();
  NODE_PW_CASE (0,clihost_t,host);
  NODE_PW_CASE (1,auth_id_t,remoteID);
  NODE_PW_CASE (2,auth_id_t,auth);
  NODE_PW_CASE (3,Pstring,ts);
  NODE_PW_CASE (4,http_request_t,request);
  NODE_PW_CASE (5,Puint16,response);
  NODE_PW_CASE (6,contentOpt_t,contentLength);
  STR_NODE_PATH_WALK_BODY_END (7);
  return STR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const http_clf_t_node_vtable={http_clf_t_cachedNode_init,http_clf_t_node_kthChild,http_clf_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_clf_t_cachedNode_vtable={PDCI_error_cachedNode_init,http_clf_t_cachedNode_kthChild,http_clf_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const http_clf_t_sndNode_vtable={PDCI_error_cachedNode_init,http_clf_t_sndNode_kthChild,http_clf_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t log_t_init (P_t *pads,log_t *rep)
{
  PDCI_DISC_1P_CHECKS ("log_t_init",rep);
  memset ((void *) rep,0,sizeof(log_t));
  return P_OK;
}
Perror_t log_t_pd_init (P_t *pads,log_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("log_t_pd_init",pd);
  memset ((void *) pd,0,sizeof(log_t_pd));
  return P_OK;
}
Perror_t log_t_cleanup (P_t *pads,log_t *rep)
{
  PDCI_DISC_1P_CHECKS ("log_t_cleanup",rep);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("log_t_cleanup",rep,http_clf_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t log_t_pd_cleanup (P_t *pads,log_t_pd *pd)
{
  PDCI_DISC_1P_CHECKS ("log_t_pd_cleanup",pd);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN ("log_t_pd_cleanup",pd,http_clf_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t log_t_copy (P_t *pads,log_t *rep_dst,log_t *rep_src)
{
  PDCI_DISC_2P_CHECKS ("log_t_copy",rep_src,rep_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("log_t_copy",rep_src,rep_dst,http_clf_t_copy,http_clf_t_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
Perror_t log_t_pd_copy (P_t *pads,log_t_pd *pd_dst,log_t_pd *pd_src)
{
  PDCI_DISC_2P_CHECKS ("log_t_pd_copy",pd_src,pd_dst);
  {
    Puint32 nerr_PCGEN_=0;
    PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN ("log_t_pd_copy",pd_src,pd_dst,http_clf_t_pd_copy,http_clf_t_pd_cleanup);
    return (nerr_PCGEN_==0) ? P_OK : P_ERR;
  }
}
void log_t_m_init (P_t *pads,log_t_m *mask,Pbase_m baseMask)
{
  PDCI_fill_mask ((Pbase_m *) mask,baseMask,sizeof(log_t_m));
}
void log_t_ro_params_init (log_t_ro_params_t *params)
{
}
Pread_res_t log_t_final_checks (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep,Ploc_t *loc_ptr,int consume)
{
  PDCI_IODISC_3P_CHECKS ("log_t_final_checks",m,pd,rep);
  {
    PCGEN_ARRAY_UNSET_PARTIAL ();
    pd->length = (rep->length);
    return PCGEN_ARRAY_RET_DONE (consume);
  }
}
Pread_res_t log_t_read_one_init (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep,Ploc_t *loc_ptr)
{
  PDCI_IODISC_3P_CHECKS ("log_t_read_one_init",m,pd,rep);
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
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"log_t_read","");
          }
      }
    if (0==(pd->_internal)) 
      {
        pd->_internal = RMM_new_rbuf (P_rmm_zero (pads));
        if (0==(pd->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,"log_t_read","");
          }
      }
    if (P_PS_isPanic (pd)||P_io_at_eof (pads)) 
      PCGEN_ARRAY_DO_FINAL_CHECKS ();
    PDCI_READFN_BEGINLOC (pads,pd->loc);
    PCGEN_ARRAY_SET_PARTIAL ();
    return PCGEN_ARRAY_RET_ONGOING (0);
    PCGEN_ARRAY_LBL_FINAL_CHECKS ();
    return log_t_final_checks (pads,m,pd,rep,loc_ptr,0);
  }
}
Pread_res_t log_t_read_one (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep,Ploc_t *loc_ptr,http_clf_t_pd *elt_pd,http_clf_t *elt_rep)
{
  PDCI_IODISC_3P_CHECKS ("log_t_read_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("log_t_read_one",elt_pd,elt_rep);
  {
    int haveData=0;
    PCGEN_ARRAY_RO_DECS ();
    PCGEN_ARRAY_TEST_ALREADY_DONE ();
    PCGEN_ARRAY_GET_BEGIN_LOC ();
    // Ready to read next element
    if ((pd->numRead)>0) 
      {
      }
    PCGEN_ARRAY_READ_ELEM_HD (http_clf_t_read (pads,&(m->element),elt_pd,elt_rep),haveData);
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
    return log_t_final_checks (pads,m,pd,rep,loc_ptr,haveData);
  }
}
Perror_t log_t_read (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep)
{
  PDCI_IODISC_3P_CHECKS ("log_t_read",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc;
    Ploc_t *loc_ptr=&tloc;
    int i=0;
    int result;
    log_t_read_one_init (pads,m,pd,rep,loc_ptr);
    PCGEN_ARRAY_READ_ALL (PCGEN_ARRAY_RESERVE_SPACE (log_t,http_clf_t,http_clf_t_pd,0),log_t_read_one (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]),i = (rep->length),"log_t_read");
    return PCGEN_ARRAY_STD_RETURN ();
  }
}
Pread_res_t log_t_reread_one (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep,Ploc_t *loc_ptr,http_clf_t_pd *elt_pd,http_clf_t *elt_rep,int notFirstElt)
{
  PDCI_IODISC_3P_CHECKS ("log_t_reread_one",m,pd,rep);
  PDCI_IODISC_2P_CHECKS ("log_t_reread_one",elt_pd,elt_rep);
  {
    // Ready to read element
    PCGEN_ARRAY_REREAD_ELEM_BODY (http_clf_t_read (pads,&(m->element),elt_pd,elt_rep));
    return PCGEN_ARRAY_REREAD_ELEM_RET ();
  }
}
int log_t_verify (log_t *rep)
{
  int violated=0;
  {
    int i;
    for (i = 0; (!violated)&&(i<(rep->length)); i++)
      {
        if (!http_clf_t_verify (&(rep->elts)[i])) 
          {
            violated = 1;
          }
      }
  }
  return !violated;
}
Perror_t log_t_acc_init (P_t *pads,log_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_init (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==http_clf_t_acc_init (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==http_clf_t_acc_init (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t log_t_acc_reset (P_t *pads,log_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_reset (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==http_clf_t_acc_reset (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==http_clf_t_acc_reset (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t log_t_acc_cleanup (P_t *pads,log_t_acc *acc)
{
  Puint32 nerr=0;
  if (P_ERR==Puint32_acc_cleanup (pads,&(acc->length))) 
    {
      nerr++;
    }
  if (P_ERR==http_clf_t_acc_cleanup (pads,&(acc->compoundLevel))) 
    {
      nerr++;
    }
  {
    int i;
    for (i = 0; i<10; i++)
      {
        if (P_ERR==http_clf_t_acc_cleanup (pads,&(acc->arrayDetail)[i])) 
          {
            nerr++;
          }
      }
  }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t log_t_acc_add (P_t *pads,log_t_acc *acc,log_t_pd *pd,log_t *rep)
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
                if (P_ERR==http_clf_t_acc_add (pads,&(acc->arrayDetail)[i],&(pd->elts)[i],&(rep->elts)[i])) 
                  {
                    nerr++;
                  }
              }
            if (P_ERR==http_clf_t_acc_add (pads,&(acc->compoundLevel),&(pd->elts)[i],&(rep->elts)[i])) 
              {
                nerr++;
              }
          }
      }
    }
  return (nerr==0) ? P_OK : P_ERR;
}
Perror_t log_t_acc_report2io (P_t *pads,Sfio_t *outstr,char const *prefix,char const *what,int nst,log_t_acc *acc)
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
      what = "array log_t of http_clf_t";
    }
  PDCI_nst_prefix_what (outstr,&nst,prefix,what,0);
  PCGEN_ARRAY_ACC_REP_NOVALS ();
  if (P_ERR==Puint32_acc_report2io (pads,outstr,"Array lengths","array length",-1,&(acc->length))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  sfprintf (tmpstr,"%s.allArrayElts",prefix);
  if (P_ERR==http_clf_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"all array element",nst,&(acc->compoundLevel))) 
    {
      sfstrclose (tmpstr);
      return P_ERR;
    }
  {
    int i;
    for (i = 0; i<((((acc->length).max)<10) ? (acc->length).max : 10); i++)
      {
        sfprintf (tmpstr,"%s.arrayDetail[%d]",prefix,i);
        if (P_ERR==http_clf_t_acc_report2io (pads,outstr,sfstruse (tmpstr),"array element",nst,&(acc->arrayDetail)[i])) 
          {
            sfstrclose (tmpstr);
            return P_ERR;
          }
      }
  }
  sfstrclose (tmpstr);
  return P_OK;
}
Perror_t log_t_acc_report (P_t *pads,char const *prefix,char const *what,int nst,log_t_acc *acc)
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
  result = log_t_acc_report2io (pads,outstr,prefix,what,nst,acc);
  if (P_OK==result) 
    {
      ((pads->disc)->error_fn) (0,0,"%s",sfstruse (outstr));
    }
  sfstrclose (outstr);
  return result;
}
ssize_t log_t_write2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,log_t_pd *pd,log_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("log_t_write2buf",buf,buf_full,rep);
  *buf_full = 0;
  {
    int i=0;
    if ((rep->length)>1) 
      {
        for (i = 0; i<((rep->length)-1); i++)
          {
            tlen_PCGEN_ = http_clf_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
            PCGEN_TLEN_UPDATES ();
          }
      }
    if ((rep->length)!=0) 
      {
        tlen_PCGEN_ = http_clf_t_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i]);
        PCGEN_TLEN_UPDATES ();
      }
  }
  return length_PCGEN_;
}
ssize_t log_t_write2io (P_t *pads,Sfio_t *io,log_t_pd *pd,log_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("log_t_write2io",log_t_write2buf (pads,buf,buf_len,&buf_full,pd,rep));
  return -1;
}
ssize_t log_t_write_xml_2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,log_t_pd *pd,log_t *rep,char const *tag,int indent)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  PDCI_IODISC_3P_CHECKS_RET_SSIZE ("log_t_write_xml_2buf",buf,buf_full,rep);
  *buf_full = 0;
  PCGEN_SOURCE_XML_OUT_BEGIN ("ai2.p");
  PCGEN_ARRAY_OPEN_XML_OUT ();
  {
    int i=0;
    for (i = 0; i<(rep->length); i++)
      {
        tlen_PCGEN_ = http_clf_t_write_xml_2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&(pd->elts)[i],&(rep->elts)[i],"elt",indent+2);
        PCGEN_TLEN_UPDATES ();
      }
  }
  PCGEN_XML_VALUE_OUT ("length",rep->length);
  PCGEN_ARRAY_PD_XML_OUT ();
  PCGEN_ARRAY_CLOSE_XML_OUT ();
  PCGEN_SOURCE_XML_OUT_END ();
  return length_PCGEN_;
}
ssize_t log_t_write_xml_2io (P_t *pads,Sfio_t *io,log_t_pd *pd,log_t *rep,char const *tag,int indent)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("log_t_write_xml_2io",log_t_write_xml_2buf (pads,buf,buf_len,&buf_full,pd,rep,tag,indent));
  return -1;
}
ssize_t log_t_fmt2buf_final (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,log_t_m *m,log_t_pd *pd,log_t *rep)
{
  Pbyte *buf_cursor_PCGEN_=buf;
  ssize_t length_PCGEN_=0;
  ssize_t tlen_PCGEN_;
  char const *tdelim_PCGEN_;
  int trequestedOut_PCGEN_=0;
  int i=0;
  PCGEN_STRUCT_FMT2BUF_FINAL_INIT ("log_t_fmt2buf_final");
  PCGEN_FMT2BUF_ARRAY ("log_t_fmt2buf_final",http_clf_t_fmt2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,&trequestedOut_PCGEN_,tdelim_PCGEN_,&(m->element),&(pd->elts)[i],&(rep->elts)[i]));
  PCGEN_FMT2BUF_FIX_LAST ();
  return length_PCGEN_;
}
ssize_t log_t_fmt2buf (P_t *pads,Pbyte *buf,size_t buf_len,int *buf_full,int *requestedOut,char const *delims,log_t_m *m,log_t_pd *pd,log_t *rep)
{
  Pfmt_fn fn_PCGEN_;
  PCGEN_STANDARD_FMT2BUF_INIT ("log_t_fmt2buf",fn_PCGEN_ = PDCI_GET_FMT_FN (pads,"log_t"),P_invoke_fmt_fn (fn_PCGEN_,pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep));
  return log_t_fmt2buf_final (pads,buf,buf_len,buf_full,requestedOut,delims,m,pd,rep);
}
ssize_t log_t_fmt2io (P_t *pads,Sfio_t *io,int *requestedOut,char const *delims,log_t_m *m,log_t_pd *pd,log_t *rep)
{
  Pbyte *buf;
  int buf_full;
  size_t buf_len;
  PCGEN_WRITE2IO_USE_WRITE2BUF ("log_t_fmt2io",log_t_fmt2buf (pads,buf,buf_len,&buf_full,requestedOut,delims,m,pd,rep));
  return -1;
}
PDCI_node_t *log_t_node_new (PDCI_node_t *parent,char const *name,void *m,void *pd,void *rep,char const *kind,char const *whatfn)
{
  NODE_NEW_BODY (log_t);
  return NODE_NEW_RET ();
}
PDCI_node_t *log_t_cachedNode_init (PDCI_node_t *self)
{
  CACHED_NODE_INIT_BODY (log_t,ARR_LENGTH (log_t));
  return CACHED_NODE_INIT_RET ();
}
PDCI_node_t *log_t_node_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_NODE_KTH_CHILD_BODY (log_t,http_clf_t);
  return ARR_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *log_t_node_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  ARR_NODE_KTH_CHILD_NAMED_BODY (log_t);
  return ARR_NODE_KTH_CHILD_NAMED_RET ();
}
PDCI_node_t *log_t_cachedNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  CACHED_NODE_KTH_CHILD_BODY (log_t,ARR_LENGTH (log_t));
  return CACHED_NODE_KTH_CHILD_RET ();
}
PDCI_node_t *log_t_sndNode_init (PDCI_node_t *self,PDCI_manager_t *manager,PDCI_childIndex_t ancestor_idx,PDCI_gen_t gen,PDCI_childIndex_t idx)
{
  SND_NODE_INIT_BODY (log_t);
  return SND_NODE_INIT_RET ();
}
PDCI_node_t *log_t_sndNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  ARR_SND_NODE_KTH_CHILD_BODY (log_t,http_clf_t);
  return ARR_SND_NODE_KTH_CHILD_RET ();
}
Perror_t log_t_node_pathWalk (P_t *pads,log_t_m *m,log_t_pd *pd,log_t *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  ARR_NODE_PATH_WALK_BODY (http_clf_t);
  return ARR_NODE_PATH_WALK_RET ();
}
PDCI_vtable_t const log_t_node_vtable={log_t_cachedNode_init,log_t_node_kthChild,log_t_node_kthChildNamed,PDCI_node_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const log_t_cachedNode_vtable={PDCI_error_cachedNode_init,log_t_cachedNode_kthChild,log_t_node_kthChildNamed,PDCI_cachedNode_free,PDCI_node_getId,PDCI_error_typed_value,0};
PDCI_vtable_t const log_t_sndNode_vtable={PDCI_error_cachedNode_init,log_t_sndNode_kthChild,log_t_node_kthChildNamed,PDCI_node_free,PDCI_sndNode_getId,PDCI_error_typed_value,0};
Perror_t log_t_smartNode_eltAlloc (PDCI_node_t *smartNode,P_t *pads,void **elt_pd,void **elt_rep)
{
  SN_ELT_ALLOC_BODY (log_t,http_clf_t,http_clf_t_pd,smartNode,pads,elt_pd,elt_rep);
  return SN_ELT_ALLOC_RET ();
}
Pread_res_t log_t_smartNode_eltRead (PDCI_node_t *smartNode,P_t *pads,PDCI_smart_elt_info_t *info)
{
  SN_ELT_READ_BODY (log_t,http_clf_t,http_clf_t_pd,smartNode,pads,info,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return SN_ELT_READ_RET ();
}
Perror_t log_t_smartNode_eltFree (P_t *pads,PDCI_smart_elt_info_t *info)
{
  SN_ELT_FREE_BODY (log_t,pads,info);
  return SN_ELT_FREE_RET ();
}
Perror_t log_t_smartNode_eltPathWalk (P_t *pads,void *m,void *pd,void *rep,PDCI_path_t path,void **m_out,void **pd_out,void **rep_out)
{
  SN_ELT_PATH_WALK_BODY (log_t,http_clf_t,http_clf_t_pd,http_clf_t_m,pads,m,pd,rep,path,m_out,pd_out,rep_out);
  return SN_ELT_PATH_WALK_RET (http_clf_t,pads,path,m_out,pd_out,rep_out);
}
PDCI_smart_array_info_t *log_t_array_info_init (P_t *pads,unsigned int max_elts)
{
  SN_ARRAY_INFO_INIT_BODY (log_t,pads,max_elts,SN_WRAP_PARAMS (0));
  return SN_ARRAY_INFO_INIT_RET ();
}
PDCI_node_t *log_t_smartNode_init (PDCI_node_t *self,unsigned int max_elts)
{
  SN_INIT_BODY (log_t,self,max_elts,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return SN_INIT_RET (self);
}
PDCI_node_t *log_t_smartNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  SN_KTH_CHILD_BODY (log_t,http_clf_t,self,idx);
  return SN_KTH_CHILD_RET ();
}
PDCI_node_t *log_t_smartNode_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,char const *name)
{
  SN_KTH_CHILD_NAMED_BODY (log_t,self,idx,name);
  return SN_KTH_CHILD_NAMED_RET ();
}
PDCI_vtable_t const log_t_smartNode_vtable={PDCI_error_cachedNode_init,log_t_smartNode_kthChild,log_t_smartNode_kthChildNamed,PDCI_cachedNode_free,PDCI_smartNode_getId,PDCI_error_typed_value,0};

/*
 **************************** HAND-CODED : BEGIN ****************************
 */

PDCI_vtable_t const log_t_linearNode_vtable={
  PDCI_error_cachedNode_init,
  log_t_linearNode_kthChild,
  log_t_linearNode_kthChildNamed,
  PDCI_cachedNode_free,
  PDCI_node_getId,
  PDCI_error_typed_value,
  0};

PDCI_node_t *log_t_linearNode_init (PDCI_node_t *self)
{
  LN_INIT_BODY (log_t,http_clf_t,http_clf_t_pd,self,
		SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return LN_INIT_RET (self);
}
PDCI_node_t *log_t_linearNode_kthChild (PDCI_node_t *self,PDCI_childIndex_t idx)
{
  LN_KTH_CHILD_BODY (log_t,http_clf_t,self,idx,SN_WRAP_PARAMS (0),SN_WRAP_PARAMS (0));
  return LN_KTH_CHILD_RET ();
}
PDCI_node_t *log_t_linearNode_kthChildNamed (PDCI_node_t *self,PDCI_childIndex_t idx,
						 char const *name)
{
  LN_KTH_CHILD_NAMED_BODY (log_t,self,idx,name);
  return LN_KTH_CHILD_NAMED_RET ();
}

/*
 **************************** HAND-CODED : END ****************************
 */

void P_lib_init ()
{
  // Initialize character classes
}

