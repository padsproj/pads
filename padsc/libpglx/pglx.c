/*
 * Implementation of
 *    public and private APIs, galax-pads
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "pads-internal.h"
#include "pglx-internal.h"
#include "pglx.h"
#include "caml/fail.h"
#include <stdio.h>


/* ocaml header files can be found in /usr/common/lib/ocaml/caml */


/* conversion function from PDCI_pglx_id_t to padsNID. */
padsNID PDCI_pglx_id_2_padsNID(PDCI_pglx_id_t id);

/* ================================================================================
 * PUBLIC GALAX->PADS CALLS (see pglx.h) */ 

nodeRep PGLX_generic_kth_child (nodeRep ocaml_n, childIndex idx)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  if (!n)
    PGLX_report_err(n->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PGLX_generic_kth_child","PADS/Galax INVALID_PARAM: n null");
  if (!n->vt)
    PGLX_report_err(n->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PGLX_generic_kth_child","PADS/Galax INVALID_PARAM: n->vt null");
  PDCI_NODE_VT_CHECK(n, "PGLX_generic_kth_child");
  return (nodeRep) ((n->vt->kth_child)(n, idx));
}

nodeRep PGLX_generic_kth_child_named (nodeRep ocaml_n, childIndex idx, const char *name)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  /*  error(2, "In PGLX_generic_kth_child_named %d %s\n", idx, name);  */
  if (!n)
    PGLX_report_err(n->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PGLX_generic_kth_child_named","PADS/Galax INVALID_PARAM: n null");
  if (!n->vt)
    PGLX_report_err(n->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PGLX_generic_kth_child_named","PADS/Galax INVALID_PARAM: n->vt null");
  PDCI_NODE_VT_CHECK(n, "PGLX_generic_kth_child_named");
  return (nodeRep) ((n->vt->kth_child_named)(n, idx, name));
}

nodeRep PGLX_generic_parent (nodeRep ocaml_n)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_generic_parent");
  return (nodeRep ) (n->parent);
}

/* Return value TBD */

item PGLX_generic_typed_value (nodeRep  ocaml_n)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_VT_CHECK(n, "PGLX_generic_typed_value");
  return (n->vt->typed_value)(n);
}

const char* PGLX_generic_string_value(nodeRep ocaml_n)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_generic_string_value");
  return (n->vt->string_value)(n);
}

const char* PGLX_generic_name(nodeRep ocaml_n){
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_generic_name");
  return n->name;
}

const char* PGLX_generic_kind(nodeRep ocaml_n){
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_generic_kind");
  return n->kind;
}

padsNID PGLX_generic_get_id(nodeRep ocaml_n){
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_generic_get_id");
  return PDCI_pglx_id_2_padsNID(n->vt->get_id(n));
}

void PGLX_node_free(nodeRep ocaml_n)
{
  PDCI_node_t *n = (PDCI_node_t *) ocaml_n; 
  PDCI_NODE_CHECK(n, "PGLX_node_free");
  PDCI_FREE_NODE(n);
}

void PGLX_nodelist_free(nodeRepArray list)
{
  PDCI_FREE_NODE_PTR_LIST(list);
}

/* ================================================================================
 * INTERNAL */

Perror_t
PGLX_report_err(P_t *pads, int level, Ploc_t *loc,
		PerrCode_t errCode, const char *whatfn, const char *format, ...)
{
  if (errCode == P_FAILWITH_ERR){
    failwith((char *)format);
    return P_OK;
  }else{
    va_list ap;
    Perror_t res;

    va_start(ap,format);
    res = PDCI_report_err(pads,level,loc,errCode,whatfn,format,ap);
    va_end(ap);
    return res;
  }
}

padsNID PDCI_pglx_id_2_padsNID(PDCI_pglx_id_t id){
  padsNID id_;
  id_.gId = id.gId;
  id_.mId = id.mId;
  return id_;
}

/* Helper macros  */

#define PDCI_SND_INIT_DEF(ty) \
PDCI_node_t * ty ## _sndNode_init(PDCI_node_t *node,          \
				  PDCI_manager_t *manager, \
                                  PDCI_childIndex_t ancestor_idx, \
				  PDCI_gen_t gen, 	      \
				  PDCI_childIndex_t idx)      \
{                                                             \
  PDCI_SND_INIT(ty,node,manager,ancestor_idx,gen,idx);		 \
  return node;						      \
}							      

#define PDCI_IMPL_BASE_VT(ty) \
\
PDCI_node_t * ty ## _node_new(PDCI_node_t *parent, \
			 const char *name, \
			 void* m, void* pd, void* rep,\
			 const char *kind,const char *whatfn)\
{\
  PDCI_node_t *result;\
  PDCI_MK_NODE (result,& ty ## _node_vtable,\
		parent,name,m,pd,rep,kind,whatfn);\
  result->id_offset = 0;\
  return result;\
}\
\
PDCI_node_t * ty ## _cachedNode_init(PDCI_node_t *node){\
\
  /* Setup the virtual table */ \
  node->vt = & ty ## _cachedNode_vtable;\
\
  /* Setup node-type specific fields */ \
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(2);\
  if(node->child_cache == NULL)\
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_cachedNode_init","PADS/Galax ALLOC_ERROR");  \
\
  return node;\
}\
\
PDCI_SND_INIT_DEF(ty)\
\
PDCI_node_t * ty ## _node_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  ty        *rep = (ty*)node->rep; \
  Pbase_pd  *pd  = (Pbase_pd*)node->pd; \
  PDCI_node_t *result = 0; \
  /* the mk calls below raise an exception on alloc error */ \
  switch (idx) { \
    case 0: \
      if (pd->errCode == P_NO_ERR || pd->errCode == P_USER_CONSTRAINT_VIOLATION) \
        result = ty ## _val_node_new(node, "val", pd, rep, PDCI_VAL_OFF,PDCI_MacroArg2String(ty) "_node_kthChild"); \
      else \
        result = Pbase_pd_node_new(node, "pd",  pd,  PDCI_MacroArg2String(ty) "_node_kthChild"); \
      break; \
    case 1: \
      if (pd->nerr > 0 && pd->errCode == P_USER_CONSTRAINT_VIOLATION) \
        result = Pbase_pd_node_new(node, "pd",  pd,  PDCI_MacroArg2String(ty) "_node_kthChild"); \
      break; \
  } \
  return result; \
} \
\
PDCI_node_t * ty ## _node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name) \
{ \
  PDCI_node_t *result = 0; \
  Pbase_pd  *pd  = (Pbase_pd*)node->pd; \
\
  /* the only valid idx is 0  */ \
  if (idx) return result; \
  /* the mk calls below raise an exception on alloc error */ \
  /* Mary: The logic here is a bit convoluted, because the child name \
     does not determine the index value.  Base types seem to be the only nodes \
     for which child name alone does not determine index value. \
\
     name = "val" && (errCode == P_NO_ERR && P_USER_CONSTRAINT_VIOLATION) => index = 0 \
     name = "pd" && \
        errCode == P_USER_CONSTRAINT_VIOLATION => index = 1 \
        otherwise => index = 0 \
  */ \
  if (strcmp(name, "val") == 0 &&  \
      (pd->errCode == P_NO_ERR || pd->errCode == P_USER_CONSTRAINT_VIOLATION)) idx = 0; \
  else if (strcmp(name, "pd") == 0) { \
    if (pd->errCode == P_USER_CONSTRAINT_VIOLATION) idx = 1; \
    else idx = 0; \
  } else return result; /* no such child */ \
\
  return (node->vt->kth_child)(node,idx); \
} \
 \
PDCI_node_t * ty ## _cachedNode_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  PDCI_node_t *result = 0; \
\
  if (idx >= 2) \
    return result; \
\
  result = node->child_cache[idx]; \
  if (result == NULL){ \
    /* create a new node for the kth child */ \
    result = ty ## _node_kthChild(node,idx); \
\
    /* initialize the node to be a cachedNode */ \
    (result->vt->cachedNode_init)(result);\
\
    /* cache the result */ \
    node->child_cache[idx] = result; \
  } \
\
  return PDCI_ALIAS_NODE(result);\
} \
\
\
PDCI_node_t * ty ## _sndNode_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  ty        *rep = (ty*)node->rep; \
  Pbase_pd  *pd  = (Pbase_pd*)node->pd; \
  PDCI_node_t *result = 0; \
  /* the mk calls below raise an exception on alloc error */ \
  switch (idx) { \
    case 0: \
\
      /* Make sure that the node is valid before attempting to access its contents. */ \
      PDCI_sndNode_validate(node);\
      rep = node->rep; \
      pd = node->pd;\
\
      if (pd->errCode == P_NO_ERR || pd->errCode == P_USER_CONSTRAINT_VIOLATION) { \
        result = ty ## _val_node_new(node, "val", pd, rep, PDCI_VAL_OFF, \
				     PDCI_MacroArg2String(ty) "_sndNode_kthChild"); \
        ty ## _val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx); \
      } else { \
        result = Pbase_pd_node_new(node, "pd",  pd,  PDCI_MacroArg2String(ty) "_sndNode_kthChild"); \
        Pbase_pd_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);\
      } \
      break; \
    case 1: \
      if (pd->nerr > 0  && pd->errCode == P_USER_CONSTRAINT_VIOLATION) { \
        result = Pbase_pd_node_new(node, "pd",  pd,  PDCI_MacroArg2String(ty) "_sndNode_kthChild"); \
        Pbase_pd_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);\
      } \
      break; \
  } \
  return result; \
} \
\
const PDCI_vtable_t ty ## _node_vtable = {ty ## _cachedNode_init, \
				     ty ## _node_kthChild, \
				     ty ## _node_kthChildNamed, \
                                     PDCI_node_free, \
                                     PDCI_node_getId,\
				     PDCI_error_typed_value, \
				     PDCI_not_impl_yet_string_value};\
\
const PDCI_vtable_t ty ## _cachedNode_vtable = {PDCI_error_cachedNode_init, \
					    ty ## _cachedNode_kthChild, \
					    ty ## _node_kthChildNamed, \
					    PDCI_cachedNode_free, \
                                            PDCI_node_getId,\
					    PDCI_error_typed_value, \
					    PDCI_not_impl_yet_string_value}; \
\
const PDCI_vtable_t ty ## _sndNode_vtable = {PDCI_error_cachedNode_init, \
					    ty ## _sndNode_kthChild, \
					    ty ## _node_kthChildNamed, \
					    PDCI_node_free, \
                                            PDCI_sndNode_getId,\
					    PDCI_error_typed_value, \
					    PDCI_not_impl_yet_string_value}

#define PDCI_IMPL_TYPED_VALUE_FLOAT(ty) \
item ty ## _typed_value (PDCI_node_t *node) \
{ \
  item       res = 0; \
  double     d   = (double)*((ty*)node->rep); \
  if (galax_atomicFloat(d, &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
}\
\
item ty ## _sndNode_typed_value (PDCI_node_t *node) \
{ \
  item       res = 0; \
  double     d;\
\
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _typed_value(node); \
}

item Pfloat64_typed_value (PDCI_node_t *node)
{
  item      res = 0;
  Pfloat64  flt = *(Pfloat64*)node->rep;
  Pbase_pd  *pd = (Pbase_pd*)node->pd;
  Pbase_pd   tpd;

  if (!pd) {
    pd = &tpd;
    pd->errCode = P_NO_ERR;
  }
  PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,
		  "Pfloat64_typed_value",
		  "PADS/Galax Pfloat64_typed_value unimplemented");
  return res;
}

item Pfloat64_sndNode_typed_value (PDCI_node_t *node)
{
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Pfloat64_typed_value(node); 
}


#define PDCI_IMPL_TYPED_VALUE_INT(ty) \
item ty ## _typed_value (PDCI_node_t *node) \
{ \
  item       res = 0; \
  int        r   = *((ty*)node->rep); \
  if (galax_atomicInteger(r, &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
}\
\
item ty ## _sndNode_typed_value (PDCI_node_t *node) \
{ \
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _typed_value(node); \
}

/* XXX should use long long */
#define PDCI_IMPL_TYPED_VALUE_INTEGER(ty) \
item ty ## _typed_value (PDCI_node_t *node) \
{ \
  item         res = 0; \
  int          r   = *((ty*)node->rep); \
  if (galax_atomicInteger(r, &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
}\
\
item ty ## _sndNode_typed_value (PDCI_node_t *node) \
{ \
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _typed_value(node); \
}

/* For the case where a base type requires an arg, such as stop char for Pstring */

#define PDCI_IMPL_TYPED_VALUE_ARG1(ty, ty_arg1) \
item ty ## _typed_value (PDCI_node_t *node) \
{ \
  item         res = 0; \
  ty           *r   = (ty*)node->rep; \
  Pbase_pd   tpd; \
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r, ty_arg1)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_typed_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  if (galax_atomicUntyped(PDCI_sfstr_use(node->pads->tmp2), &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
}\
\
item ty ## _sndNode_typed_value (PDCI_node_t *node) \
{ \
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _typed_node (node); \
}

#define PDCI_NO_CHILD_CN_INIT_DEF(ty)\
\
PDCI_node_t * ty ## _cachedNode_init(PDCI_node_t *node){\
\
  /* Setup the virtual table */ \
  node->vt = & ty ## _cachedNode_vtable;\
\
  /*  The node has no children, hence no cache */ \
  node->child_cache = NULL; \
\
  return node;\
}

/* val node has one child, a text node with no name */ 
#define PDCI_IMPL_BASE_VAL_FUNS(ty) \
\
PDCI_node_t * ty ## _val_node_new(PDCI_node_t *parent, \
			 const char *name, \
			 void *pd, void *rep,\
                         unsigned int id_offset,\
			 const char *whatfn)\
{\
  PDCI_node_t *result;\
  PDCI_MK_TNODE (result,& ty ## _val_node_vtable,\
		parent,name,rep,whatfn);\
  result->pd = pd;\
  result->id_offset = id_offset;\
  return result;\
}\
\
PDCI_node_t * ty ## _text_node_new(PDCI_node_t *parent, const char *whatfn)\
{\
  PDCI_node_t *result;\
  PDCI_MK_TEXTNODE (result,& ty ## _text_node_vtable,parent,whatfn);\
  result->pd = parent->pd;\
  result->id_offset = PDCI_TEXT_OFF; \
  return result;\
}\
\
PDCI_node_t * ty ## _val_cachedNode_init(PDCI_node_t *node){\
\
  /* Setup the virtual table */ \
  node->vt = & ty ## _val_cachedNode_vtable;\
\
  /*  Setup node-type specific fields */ \
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(1);\
  if(node->child_cache == NULL)\
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_val_cachedNode_init","PADS/Galax ALLOC_ERROR:");  \
\
  return node;\
}\
\
PDCI_NO_CHILD_CN_INIT_DEF(ty ## _text)\
PDCI_SND_INIT_DEF(ty ## _val) \
PDCI_SND_INIT_DEF(ty ## _text) \
\
PDCI_node_t * ty ## _val_node_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  PDCI_node_t *result = 0; \
  /* the only valid idx is 0  */ \
  if (idx) return 0; \
  /* PDCI_MK_TEXTNODE(result, & ty ## _text_node_vtable,  node, PDCI_MacroArg2String(ty) "_val_node_kthChild"); */ \
  /* Mary: This function initializes the text node's pd: */ \
  result = ty ## _text_node_new(node, PDCI_MacroArg2String(ty) "_val_node_kthChild"); \
  return result; \
} \
 \
PDCI_node_t * ty ## _val_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  PDCI_node_t *result = 0; \
\
  if (idx >= 1) \
    return result; \
\
  result = node->child_cache[idx]; \
  if (result == NULL){ \
    /* create a new node for the kth child */ \
    result = ty ## _node_kthChild(node,idx); \
\
    /* initialize the node to be a cachedNode */ \
    (result->vt->cachedNode_init)(result);\
\
    /* cache the result */ \
    node->child_cache[idx] = result; \
  } \
\
  return PDCI_ALIAS_NODE(result);\
} \
 \
\
PDCI_node_t * ty ## _val_sndNode_kthChild(PDCI_node_t *node, childIndex idx) \
{ \
  PDCI_node_t *result = 0; \
\
  /* the only valid idx is 0  */ \
  if (idx) return 0; \
\
 /* PDCI_MK_TEXTNODE(result, & ty ## _text_sndNode_vtable,  node, PDCI_MacroArg2String(ty) "_val_sndNode_kthChild"); */\
  result = ty ## _text_node_new(node, PDCI_MacroArg2String(ty) "_val_sndNode_kthChild"); \
  ty ## _text_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx); \
  return result; \
}

#define PDCI_DEF_BASE_VAL_VT(ty)\
const PDCI_vtable_t ty ## _val_node_vtable = {ty ## _val_cachedNode_init, \
					      ty ## _val_node_kthChild, \
					      PDCI_node_no_kthChildNamed, /* no named children */ \
					      PDCI_node_free,\
                                              PDCI_node_getId,\
					      ty ## _typed_value, \
					      ty ## _string_value}; \
					      \
const PDCI_vtable_t ty ## _val_cachedNode_vtable = {PDCI_error_cachedNode_init, \
		          			    ty ## _val_cachedNode_kthChild, \
						    PDCI_node_no_kthChildNamed, /* no named children */ \
						    PDCI_cachedNode_free,\
                                                    PDCI_node_getId,\
						    ty ## _typed_value, \
						    ty ## _string_value}; \
						    \
const PDCI_vtable_t ty ## _val_sndNode_vtable = {PDCI_error_cachedNode_init, \
		          			    ty ## _val_sndNode_kthChild, \
 						    PDCI_node_no_kthChildNamed, /* no named children */ \
	  					    PDCI_node_free,\
                                                    PDCI_sndNode_getId,\
						    ty ## _sndNode_typed_value, \
						    ty ## _sndNode_string_value}; \
						    \
const PDCI_vtable_t ty ## _text_node_vtable = {ty ## _text_cachedNode_init,\
					       PDCI_node_no_kthChild, \
					       PDCI_node_no_kthChildNamed, \
					       PDCI_node_free,\
					       PDCI_node_getId, /* PDCI_error_getId, */\
					       ty ## _text_typed_value, \
					       ty ## _string_value};\
					       \
const PDCI_vtable_t ty ## _text_cachedNode_vtable = {PDCI_error_cachedNode_init, \
						     PDCI_node_no_kthChild, /* no children */\
						     PDCI_node_no_kthChildNamed, /* no children */\
						     PDCI_cachedNode_free,  \
					             PDCI_node_getId, /* PDCI_error_getId, */\
						     ty ## _text_typed_value, \
						     ty ## _string_value};\
\
const PDCI_vtable_t ty ## _text_sndNode_vtable = {PDCI_error_cachedNode_init, \
						     PDCI_node_no_kthChild, /* no children */\
						     PDCI_node_no_kthChildNamed, /* no children */\
						     PDCI_node_free,  \
  					             PDCI_sndNode_getId, /* PDCI_error_getId */\
						     ty ## _text_sndNode_typed_value, \
						     ty ## _sndNode_string_value}

#define PDCI_IMPL_BASE_VAL_VT(ty) \
PDCI_IMPL_BASE_VAL_FUNS(ty) \
const char * ty ## _string_value (PDCI_node_t *node) \
{ \
  ty        *r   = (ty*)node->rep; \
  Pbase_pd   tpd; \
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_string_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  return (PDCI_sfstr_use(node->pads->tmp2)); \
} \
 \
item ty ## _text_typed_value (PDCI_node_t *node) \
{ \
  item         res = 0; \
  ty           *r   = (ty*)node->rep; \
  Pbase_pd   tpd; \
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_text_typed_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  if (galax_atomicUntyped(PDCI_sfstr_use(node->pads->tmp2), &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_text_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
} \
const char * ty ## _sndNode_string_value (PDCI_node_t *node) \
{ \
  ty        *r;\
  Pbase_pd   tpd; \
\
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  r   = (ty*)node->rep; \
\
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_sndNode_string_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  return (PDCI_sfstr_use(node->pads->tmp2)); \
} \
 \
item ty ## _text_sndNode_typed_value (PDCI_node_t *node) \
{ \
  item         res = 0; \
  ty           *r;\
  Pbase_pd   tpd; \
\
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _text_typed_value(node); \
  r   = (ty*)node->rep; \
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_text_sndNode_typed_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  if (galax_atomicUntyped(PDCI_sfstr_use(node->pads->tmp2), &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_text_sndNode_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
} \
PDCI_DEF_BASE_VAL_VT(ty)

#define PDCI_IMPL_BASE_VAL_VT_ARG1(ty, ty_arg1) \
PDCI_IMPL_BASE_VAL_FUNS(ty)\
\
const char * ty ## _string_value (PDCI_node_t *node) \
{ \
  ty           *r   = (ty*)node->rep; \
  Pbase_pd   tpd; \
  tpd.errCode = P_NO_ERR; \
  PDCI_sfstr_seek2zero(node->pads->tmp2); \
  /* Mary: The _write2io functions have the side effect of changing the rep when errCode != P_NO_ERR,  \
     but we only call these functions for sub-elements/structures whose values are known and error-free,  \
     so we explicitly call them with tpd.errCode = P_NO_ERR. */ \
  if (-1 == ty ## _write2io(node->pads, node->pads->tmp2, &tpd, r, ty_arg1)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_string_value","PADS/Galax UNEXPECTED_IO_FAILURE"); \
  } \
  return (PDCI_sfstr_use(node->pads->tmp2)); \
} \
const char * ty ## _sndNode_string_value (PDCI_node_t *node) \
{ \
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _string_value(node); \
} \
 \
item ty ## _text_typed_value (PDCI_node_t *node) \
{ \
  item         res = 0; \
  if (galax_atomicUntyped(ty ## _string_value(node), &res)) { \
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, PDCI_MacroArg2String(ty) "_text_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE"); \
  } \
  return res; \
} \
item ty ## _text_sndNode_typed_value (PDCI_node_t *node) \
{ \
  /* Make sure that the node is valid before attempting to access its contents. */ \
  PDCI_sndNode_validate(node);\
  return ty ## _text_typed_value(node); \
} \
 \
PDCI_DEF_BASE_VAL_VT(ty)

/*
 * XXX TEMPORARY:
 */

static const char *print_children_spaces = "                                                                                                                        ";

void print_children(void *n, int indent) {
  void       *child = NULL;
  int         iter;
  

  if (strcmp(PGLX_generic_name(n), "pd") == 0)
    return;

  if (strcmp(PGLX_generic_kind(n), "element") == 0 || strcmp(PGLX_generic_kind(n), "document") == 0) {
    const char *n_name = PGLX_generic_name(n);
    error(0, "%.*s<%s>",
	  indent, print_children_spaces, n_name);
    child = PGLX_generic_kth_child(n,0);
    for (iter = 1; child; iter++) {
      print_children(child, indent+4);
      PGLX_node_free(child); 
      child = PGLX_generic_kth_child(n,iter);
    }
    error(0, "%.*s</%s>",
	  indent, print_children_spaces, n_name);
  } else {
    error(0, "%.*s%s",
	  indent, print_children_spaces, PGLX_generic_string_value(n));
  }
}

void walk_children(void *n) {
  void       *child = NULL;
  int         iter;
  const char *kind = PGLX_generic_kind(n);

  if (strcmp(PGLX_generic_name(n), "pd") == 0)
    return;

  if (strcmp(kind, "element") == 0 || strcmp(kind, "document") == 0) {
    child = PGLX_generic_kth_child(n,0);
    for (iter = 1; child; iter++) {
      walk_children(child);
      PGLX_node_free(child); 
      child = PGLX_generic_kth_child(n,iter);
    }
  }
}

/* HELPERS */

/* ---------------------------
 * Some children functions
 * --------------------------- */

/* A pos_t has 3 children (byte, num, and sfio-offset) */
#undef NUM_CHILDREN
#define NUM_CHILDREN 3
PDCI_node_t * Ppos_t_node_new(PDCI_node_t *parent, 
			      const char *name, 
			      void* pd, void* rep,
			      unsigned int id_offset,
			      const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result, (& Ppos_t_node_vtable), parent, name, rep, whatfn);
  result->pd = pd;
  result->id_offset = id_offset;
  return result;
}

PDCI_node_t * Ppos_t_cachedNode_init(PDCI_node_t *node){

  /* Setup the virtual table */ 
  node->vt = & Ppos_t_cachedNode_vtable;

  /*  Setup node-type specific fields */ 
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(node->child_cache == NULL)
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Ppos_t_cachedNode_init","PADS/Galax ALLOC_ERROR");  

  return node;
}

PDCI_SND_INIT_DEF(Ppos_t)

#undef WHATFN
#define WHATFN "Ppos_t_node_kthChild"
PDCI_node_t * Ppos_t_node_kthChild(PDCI_node_t *node, childIndex idx)
{
  Ppos_t *pos = (Ppos_t *) node->rep;
  PDCI_node_t *result = 0;
  switch (idx) {
  case 0:
    result = Pint32_val_node_new(node, "num", node->pd, &(pos->num), 
				 node->id_offset + PDCI_NUM_OFF,				 
				 WHATFN);
    break;
  case 1:
    result = Pint32_val_node_new(node, "byte", node->pd, &(pos->byte), 
				 node->id_offset + PDCI_BYTE_OFF,
				 WHATFN);
    break;
  case 2:
    /*  PDCI_MK_TNODE(result[2], &Puint64_val_vtable,  node, "offset",  (Puint64)(pos->offset), WHATFN); */
    break;
  }
  return result;
}

#undef WHATFN
#define WHATFN "Ppos_t_node_kthChildNamed"
PDCI_node_t * Ppos_t_node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name)
{
  PDCI_node_t *result = 0;

  /* the only valid idx is 0 */
  if (idx) return result;

  if (strcmp(name, "num") == 0)    	idx = 0;
  else if (strcmp(name, "byte") == 0)   idx = 1;
/*else if (strcmp(name, "offset") == 0) idx = 2; */
  else  return result;

  return (node->vt->kth_child)(node,idx);
}

PDCI_node_t *  Ppos_t_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) 
{ 
  PDCI_node_t *result = 0; 

  if (idx >= NUM_CHILDREN) 
    return result;   

  result = node->child_cache[idx]; 
  if (result == NULL){ 
    /* create a new node for the kth child */ 
    result = Ppos_t_node_kthChild(node,idx); 

    /* initialize the node to be a cachedNode */ 
    (result->vt->cachedNode_init)(result);

    /* cache the result */ 
    node->child_cache[idx] = result; 
  } 

  return PDCI_ALIAS_NODE(result);
} 

#undef WHATFN
#define WHATFN "Ppos_t_sndNode_kthChild"
PDCI_node_t * Ppos_t_sndNode_kthChild(PDCI_node_t *node, childIndex idx)
{
  Ppos_t *pos = (Ppos_t *) node->rep;
  PDCI_node_t *result = 0;

  // check the validaty of the data
  if (pos == NULL || !PDCI_sndNode_is_valid(node)){
    // in case the right-side of the || got us here:
    node->rep = NULL;  
    node->pd  = NULL;

    switch (idx) {
    case 0:
      result = Pint32_val_node_new(node, "num", NULL, NULL, 
				   node->id_offset + PDCI_NUM_OFF, WHATFN);
      Pint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Pint32_val_node_new(node, "byte", NULL, NULL, 
				   node->id_offset + PDCI_BYTE_OFF, WHATFN);
      Pint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      /* PDCI_MK_TNODE(result[2], &Puint64_val_vtable,  node, "offset",  (Puint64)(pos->offset), WHATFN); */
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Pint32_val_node_new(node, "num", node->pd, &(pos->num), 
				   node->id_offset + PDCI_NUM_OFF, WHATFN);
      Pint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Pint32_val_node_new(node, "byte", node->pd, &(pos->byte), 
				   node->id_offset + PDCI_BYTE_OFF, WHATFN);
      Pint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      /*  PDCI_MK_TNODE(result[2], &Puint64_val_vtable,  node, "offset",  (Puint64)(pos->offset), WHATFN); */
      break;
    }
  }
  return result;
}


/* A loc_t has 2 children (b and e) */
#undef NUM_CHILDREN
#define NUM_CHILDREN 2
PDCI_node_t * Ploc_t_node_new(PDCI_node_t *parent, 
			      const char *name, 
			      void* pd,void* rep,
			      unsigned int id_offset,
			      const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result,& Ploc_t_node_vtable,
		parent,name,rep,whatfn);
  result->pd = pd;
  result->id_offset = id_offset;
  return result;
}

PDCI_node_t * Ploc_t_cachedNode_init(PDCI_node_t *node){

  /* Setup the virtual table */ 
  node->vt = & Ploc_t_cachedNode_vtable;

  /*  Setup node-type specific fields */ 
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(node->child_cache == NULL)
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Ploc_t_cachedNode_init","PADS/Galax ALLOC_ERROR");  

  return node;
}

PDCI_SND_INIT_DEF(Ploc_t)

#undef WHATFN
#define WHATFN "Ploc_t_node_kthChild"
PDCI_node_t * Ploc_t_node_kthChild(PDCI_node_t *node, childIndex idx)
{
  Ploc_t *loc = (Ploc_t *) node->rep;
  PDCI_node_t *result = 0;
  switch (idx) {
  case 0:
    // PDCI_MK_TNODE(result, &Ppos_t_node_vtable,      node, "b",     &(loc->b),     WHATFN);
    result = Ppos_t_node_new(node, "b", node->pd, &(loc->b),     
			     node->id_offset + PDCI_B_OFF, WHATFN);
    break;
  case 1:
    result =  Ppos_t_node_new(node, "e",     node->pd, &(loc->e),     
			      node->id_offset + PDCI_E_OFF, WHATFN);
    break;
  }
  return result;
}

#undef WHATFN
#define WHATFN "Ploc_t_node_kthChildNamed"
PDCI_node_t * Ploc_t_node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name)
{
  PDCI_node_t *result = 0;

  /* the only valid idx is 0 */
  if (idx) return result;

  if (strcmp(name, "b") == 0)       idx = 0;
  else if (strcmp(name, "e") == 0)  idx = 1;
  else return result;
 
  return (node->vt->kth_child)(node,idx);  
}

PDCI_node_t *  Ploc_t_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) 
{ 
  PDCI_node_t *result = 0; 

  if (idx >= NUM_CHILDREN) 
    return result;   

  result = node->child_cache[idx]; 
  if (result == NULL){ 
    /* create a new node for the kth child */ 
    result = Ploc_t_node_kthChild(node,idx); 

    /* initialize the node to be a cachedNode */ 
    (result->vt->cachedNode_init)(result);

    /* cache the result */ 
    node->child_cache[idx] = result; 
  } 

  return PDCI_ALIAS_NODE(result);
} 

#undef WHATFN
#define WHATFN "Ploc_t_sndNode_kthChild"
PDCI_node_t * Ploc_t_sndNode_kthChild(PDCI_node_t *node, childIndex idx)
{
  Ploc_t *loc = (Ploc_t *) node->rep;
  PDCI_node_t *result = 0;

  // check the validaty of the data
  if (loc == NULL || !PDCI_sndNode_is_valid(node)){
    // in case the right-side of the || got us here:
    node->rep = NULL;  
    node->pd  = NULL;

    switch (idx) {
    case 0:
      result = Ppos_t_node_new(node, "b", NULL, NULL,     
			       node->id_offset + PDCI_B_OFF, WHATFN);
      Ppos_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result =  Ppos_t_node_new(node, "e", NULL, NULL,     
				node->id_offset + PDCI_E_OFF, WHATFN);
      Ppos_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Ppos_t_node_new(node, "b",     node->pd, &(loc->b),     
			       node->id_offset + PDCI_B_OFF, WHATFN);
      Ppos_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result =  Ppos_t_node_new(node, "e",     node->pd, &(loc->e),     
				node->id_offset + PDCI_E_OFF, WHATFN);
      Ppos_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    }
  }
  return result;
}

/* A base_pd has three children (pstate, errCode, loc) */
#undef NUM_CHILDREN
#define NUM_CHILDREN 3
PDCI_node_t * Pbase_pd_node_new(PDCI_node_t *parent, 
				const char *name, 
				void* rep,const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result,& Pbase_pd_node_vtable,
		parent,name,rep,whatfn);
  result->pd = rep;
  result->id_offset = PDCI_BASE_PD_OFF;
  return result;
}

PDCI_node_t * Pbase_pd_cachedNode_init(PDCI_node_t *node){

  /* Setup the virtual table */ 
  node->vt = & Pbase_pd_cachedNode_vtable;

  /*  Setup node-type specific fields */ 
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(node->child_cache == NULL)
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Pbase_pd_cachedNode_init","PADS/Galax ALLOC_ERROR");  

  return node;
}

PDCI_SND_INIT_DEF(Pbase_pd)

#undef WHATFN
#define WHATFN "Pbase_pd_node_kthChild"
PDCI_node_t * Pbase_pd_node_kthChild(PDCI_node_t *node, childIndex idx)
{
  Pbase_pd     *pd = (Pbase_pd *) node->rep;
  PDCI_node_t  *result = 0;
  switch (idx) {
  case 0:
    result = Puint32_val_node_new(node, "pstate",  pd, &(pd->pstate),  
				  node->id_offset + PDCI_PSTATE_OFF, WHATFN);
    break;
  case 1:
    result = Puint32_val_node_new(node, "errCode", pd, &(pd->errCode), 
				  node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
    break;
  case 2:
    if (pd->errCode >= 100) {
      result = Ploc_t_node_new(node, "loc", pd, &(pd->loc),
			       node->id_offset + PDCI_LOC_OFF, WHATFN);
    }
    break;
  }
  return result;
}

#undef WHATFN
#define WHATFN "Pbase_pd_node_kthChildNamed"
PDCI_node_t * Pbase_pd_node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name)
{
  Pbase_pd     *pd = (Pbase_pd *) node->rep;
  PDCI_node_t  *result = 0;

  /* the only valid idx is 0 */
  if (idx) return 0;

  if (strcmp(name, "pstate") == 0)           idx = 0;
  else if (strcmp(name, "errCode") == 0)     idx = 1;
  else if (strcmp(name, "loc") == 0 
	   && pd->errCode >= 100)            idx = 2;
  else return result;

  return (node->vt->kth_child)(node,idx);
}

PDCI_node_t *  Pbase_pd_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) 
{ 
  Pbase_pd        *pd = (Pbase_pd*)node->rep; 
  PDCI_node_t *result = 0; 

  if ((pd->errCode >= 100 && idx >= NUM_CHILDREN) 
      || (pd->errCode < 100 && idx >= NUM_CHILDREN - 1)) 
    return result;   

  result = node->child_cache[idx]; 
  if (result == NULL){ 
    /* create a new node for the kth child */ 
    result = Pbase_pd_node_kthChild(node,idx); 

    /* initialize the node to be a cachedNode */ 
    (result->vt->cachedNode_init)(result);

    /* cache the result */ 
    node->child_cache[idx] = result; 
  } 

  return PDCI_ALIAS_NODE(result);
} 

#undef WHATFN
#define WHATFN "Pbase_pd_sndNode_kthChild"
PDCI_node_t * Pbase_pd_sndNode_kthChild(PDCI_node_t *node, childIndex idx)
{
  Pbase_pd     *pd = (Pbase_pd *) node->rep;
  PDCI_node_t  *result = 0;

  // check the validaty of the data
  if (pd == NULL || !PDCI_sndNode_is_valid(node)){
    // in case the right-side of the || got us here:
    node->rep = NULL;  
    node->pd  = NULL;

    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",  NULL, NULL,  
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "errCode", NULL, NULL, 
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      /* We need to know the value of errCode, so force validation. */
      if (P_ERR == PDCI_sndNode_make_valid(node)){
	PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, 
			WHATFN,"PADS/Galax failed to page node into memory"); 
      }
      pd = node->rep;

      if (pd->errCode >= 100) {
	result = Ploc_t_node_new(node, "loc",  pd, &(pd->loc),     
				 node->id_offset + PDCI_LOC_OFF, WHATFN);
	Ploc_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      }
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",  pd, &(pd->pstate),  
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "errCode", pd, &(pd->errCode), 
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      if (pd->errCode >= 100) {
	result = Ploc_t_node_new(node, "loc",   pd,  &(pd->loc),     
				 node->id_offset + PDCI_LOC_OFF, WHATFN);
	Ploc_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      }
      break;
    }
  }
  return result;
}

#undef WHATFN
#define WHATFN "Pbase_pd_sndNode_kthChildNamed"
PDCI_node_t * Pbase_pd_sndNode_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name)
{
  Pbase_pd     *pd = (Pbase_pd *) node->rep;
  PDCI_node_t  *result = 0;

  /* the only valid idx is 0 */
  if (idx) return 0;

  if (strcmp(name, "pstate") == 0)           idx = 0;
  else if (strcmp(name, "errCode") == 0)     idx = 1;
  else if (strcmp(name, "loc") == 0){
    /* We need to know the value of errCode, so force validation. */
    if (P_ERR == PDCI_sndNode_make_valid(node)){
      PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, 
		      WHATFN,"PADS/Galax failed to page node into memory"); 
    }
    pd = (Pbase_pd *) node->rep;
    
    if (pd->errCode >= 100) idx = 2;
    else return 0;
  } 
  else return result;

  return (node->vt->kth_child)(node,idx);
}

/* A structured_pd has four children (pstate, nerr, errCode, loc) */
#undef NUM_CHILDREN
#define NUM_CHILDREN 4
PDCI_node_t * PDCI_structured_pd_node_new(PDCI_node_t *parent, 
				const char *name, 
				void* rep,const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result,& PDCI_structured_pd_node_vtable,
		parent,name,rep,whatfn);
  result->pd = rep;
  result->id_offset = PDCI_STR_PD_OFF;
  return result;
}

PDCI_node_t * PDCI_structured_pd_cachedNode_init(PDCI_node_t *node){

  /* Setup the virtual table */ 
  node->vt = & PDCI_structured_pd_cachedNode_vtable;

  /*  Setup node-type specific fields */ 
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(node->child_cache == NULL)
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PDCI_structured_pd_cachedNode_init","PADS/Galax ALLOC_ERROR");  

  return node;
}

PDCI_SND_INIT_DEF(PDCI_structured_pd)

#undef WHATFN
#define WHATFN "PDCI_structured_pd_node_kthChild"
PDCI_node_t * PDCI_structured_pd_node_kthChild(PDCI_node_t *node, childIndex idx)
{
  PDCI_structured_pd  *pd = (PDCI_structured_pd *) node->rep;
  PDCI_node_t         *result = 0;
  /* the following mk calls raise an exception on alloc error */
  switch (idx) {
  case 0:
    /* We need to print pstate and errCode values as strings in XML, as
       we do for ENUM values in pglx-codegen-macros.h, but there is a lot of overhead to create a pads string 
       from an integer. P_pstate2str((pd)->pstate); */
    result = Puint32_val_node_new(node, "pstate",  pd, &(pd->pstate),  
				  node->id_offset + PDCI_PSTATE_OFF, WHATFN);
    break;
  case 1:
    result = Puint32_val_node_new(node, "nerr",    pd, &(pd->nerr),    
				  node->id_offset + PDCI_NERR_OFF, WHATFN);
    break;
  case 2:
    /*    P_errCode2str((pd)->errCode) */
    result = Puint32_val_node_new(node, "errCode", pd, &(pd->errCode),    
				  node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
    break;
  case 3:
    if (pd->errCode >= 100) {
      result = Ploc_t_node_new(node, "loc",   pd,  &(pd->loc),     
			       node->id_offset + PDCI_LOC_OFF, WHATFN);
    }
    break;
  }
  return result;
}

#undef WHATFN
#define WHATFN "PDCI_structured_pd_node_kthChildNamed"
PDCI_node_t * PDCI_structured_pd_node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char * name)
{
  PDCI_structured_pd  *pd = (PDCI_structured_pd *) node->rep;
  PDCI_node_t         *result = 0;

  /* the only valid idx is 0 */
  if (idx) return 0;

  /* the following mk calls raise an exception on alloc error */
  if (strcmp(name, "pstate") == 0)            idx = 0;
  else if (strcmp(name, "nerr") == 0)         idx = 1;
  else if (strcmp(name, "errCode") == 0)      idx = 2;
  else if (strcmp(name, "loc") == 0         
           && pd->errCode >= 100)             idx = 3;
  else return result;

  return (node->vt->kth_child)(node,idx);
}

PDCI_node_t *  PDCI_structured_pd_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) 
{ 
  PDCI_structured_pd        *pd = (PDCI_structured_pd*)node->rep; 
  PDCI_node_t *result = 0; 

  if ((pd->errCode >= 100 && idx >= NUM_CHILDREN) 
      || (pd->errCode < 100 && idx >= NUM_CHILDREN - 1)) 
    return result;   

  result = node->child_cache[idx]; 
  if (result == NULL){ 
    /* create a new node for the kth child */ 
    result = PDCI_structured_pd_node_kthChild(node,idx); 

    /* initialize the node to be a cachedNode */ 
    (result->vt->cachedNode_init)(result);

    /* cache the result */ 
    node->child_cache[idx] = result; 
  } 

  return PDCI_ALIAS_NODE(result);
} 

#undef WHATFN
#define WHATFN "PDCI_structured_pd_sndNode_kthChild"
PDCI_node_t * PDCI_structured_pd_sndNode_kthChild(PDCI_node_t *node, childIndex idx)
{
  PDCI_structured_pd  *pd = (PDCI_structured_pd *) node->rep;
  PDCI_node_t         *result = 0;

  // check the validaty of the data
  if (pd == NULL || !PDCI_sndNode_is_valid(node)){
    // in case the right-side of the || got us here:
    node->rep = NULL;  
    node->pd  = NULL;

    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",  NULL, NULL,  
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr", NULL, NULL,  
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode", NULL, NULL, 
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 3:
      /* We need to know the value of errCode, so force validation. */
      if (P_ERR == PDCI_sndNode_make_valid(node)){
	PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, 
			WHATFN,"PADS/Galax failed to page node into memory"); 
      }
      pd = node->rep;

      if (pd->errCode >= 100) {
	result = Ploc_t_node_new(node, "loc", pd, &(pd->loc),     
				 node->id_offset + PDCI_LOC_OFF, WHATFN);
	Ploc_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      }
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",  pd, &(pd->pstate),  
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr",    pd, &(pd->nerr),    
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode",    pd, &(pd->errCode),    
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 3:
      if (pd->errCode >= 100) {
	result = Ploc_t_node_new(node, "loc",  pd, &(pd->loc),     
				 node->id_offset + PDCI_LOC_OFF, WHATFN);
	Ploc_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      }
      break;
    }
  }
  return result;
}

#undef WHATFN
#define WHATFN "PDCI_structured_pd_sndNode_kthChildNamed"
PDCI_node_t * PDCI_structured_pd_sndNode_kthChildNamed(PDCI_node_t *node, childIndex idx, const char * name)
{
  PDCI_structured_pd  *pd = (PDCI_structured_pd *) node->rep;

  /* the only valid idx is 0 */
  if (idx) return 0;

  /* the following mk calls raise an exception on alloc error */
  if (strcmp(name, "pstate") == 0)            idx = 0;
  else if (strcmp(name, "nerr") == 0)         idx = 1;
  else if (strcmp(name, "errCode") == 0)      idx = 2;
  else if (strcmp(name, "loc") == 0){
      /* We need to know the value of errCode, so force validation. */
      if (P_ERR == PDCI_sndNode_make_valid(node)){
	PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, 
			WHATFN,"PADS/Galax failed to page node into memory"); 
      }
      pd = (PDCI_structured_pd *)node->rep;

      if (pd->errCode >= 100)  idx = 3;
      else return 0;
  }         
  else return 0;

  return (node->vt->kth_child)(node,idx);
}

/* A sequenced_pd has six children 
  (pstate, nerr, errCode, neerr, firstError, loc) */

#undef NUM_CHILDREN
#define NUM_CHILDREN 6
PDCI_node_t * PDCI_sequenced_pd_node_new(PDCI_node_t *parent, 
				const char *name, 
				void* rep,const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result,& PDCI_sequenced_pd_node_vtable,
		parent,name,rep,whatfn);
  result->pd = rep;
  result->id_offset = PDCI_SEQ_PD_OFF;
  return result;
}

PDCI_node_t * PDCI_sequenced_pd_cachedNode_init(PDCI_node_t *node){

  /* Setup the virtual table */ 
  node->vt = & PDCI_sequenced_pd_cachedNode_vtable;

  /*  Setup node-type specific fields */ 
  node->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(node->child_cache == NULL)
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PDCI_sequenced_pd_cachedNode_init","PADS/Galax ALLOC_ERROR");  

  return node;
}

PDCI_SND_INIT_DEF(PDCI_sequenced_pd)

#undef WHATFN
#define WHATFN "PDCI_sequenced_pd_node_kthChild"
PDCI_node_t * PDCI_sequenced_pd_node_kthChild(PDCI_node_t *node, childIndex idx)
{
  PDCI_sequenced_pd  *pd = (PDCI_sequenced_pd *) node->rep;
  PDCI_node_t        *result = 0;

  if (pd->errCode >= 100) { /* return loc as child */
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",   pd, &(pd->pstate),     
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr",     pd, &(pd->nerr),       
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode",  pd, &(pd->errCode),    
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      break;
    case 3:
      result = Ploc_t_node_new(node, "loc",      pd, &(pd->loc),        
			       node->id_offset + PDCI_LOC_OFF, WHATFN);
      break;
    case 4:
      result = Puint32_val_node_new(node, "neerr",    pd, &(pd->neerr),      
				    node->id_offset + PDCI_NEERR_OFF, WHATFN);
      break;
    case 5:
      result = Puint32_val_node_new(node, "firstError", pd, &(pd->firstError), 
				    node->id_offset + PDCI_FIRSTERROR_OFF, WHATFN);
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",   pd, &(pd->pstate),     
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr",     pd, &(pd->nerr),       
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode",  pd, &(pd->errCode),    
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      break;
    case 3:
      result = Puint32_val_node_new(node, "neerr",    pd, &(pd->neerr),      
				    node->id_offset + PDCI_NEERR_OFF, WHATFN);
      break;
    case 4:
      result = Puint32_val_node_new(node, "firstError", pd, &(pd->firstError), 
				    node->id_offset + PDCI_FIRSTERROR_OFF, WHATFN);
      break;
    }
  }
  return result;
}

#undef WHATFN
#define WHATFN "PDCI_sequenced_pd_node_kthChildNamed"
PDCI_node_t * PDCI_sequenced_pd_node_kthChildNamed(PDCI_node_t *node, childIndex idx, const char* name)
{
  PDCI_sequenced_pd  *pd = (PDCI_sequenced_pd *) node->rep;
  PDCI_node_t        *result = 0;

  /* the only valid idx is 0 */
  if (idx) return 0;

  if (pd->errCode >= 100){
    if (strcmp(name, "pstate") == 0)            idx = 0;
    else if (strcmp(name, "nerr") == 0)         idx = 1;
    else if (strcmp(name, "errCode") == 0)      idx = 2;
    else if (strcmp(name, "loc") == 0)          idx = 3;
    else if (strcmp(name, "neerr") == 0)        idx = 4;
    else if (strcmp(name, "firstError") == 0)   idx = 5;
    else return result;
  }else{
    if (strcmp(name, "pstate") == 0)            idx = 0;
    else if (strcmp(name, "nerr") == 0)         idx = 1;
    else if (strcmp(name, "errCode") == 0)      idx = 2;
    else if (strcmp(name, "neerr") == 0)        idx = 3;
    else if (strcmp(name, "firstError") == 0)   idx = 4;
    else return result;
  }
  return (node->vt->kth_child)(node,idx);
}

PDCI_node_t *  PDCI_sequenced_pd_cachedNode_kthChild(PDCI_node_t *node, childIndex idx) 
{ 
  PDCI_sequenced_pd        *pd = (PDCI_sequenced_pd*)node->rep; 
  PDCI_node_t *result = 0; 

  // Ensure that idx is within the (array) bounds of the cache.
  if ((pd->errCode >= 100 && idx >= NUM_CHILDREN) 
      || (pd->errCode < 100 && idx >= NUM_CHILDREN - 1)) 
    return result;   

  result = node->child_cache[idx]; 
  if (result == NULL){ 
    /* create a new node for the kth child */ 
    result = PDCI_sequenced_pd_node_kthChild(node,idx); 

    /* initialize the node to be a cachedNode */ 
    (result->vt->cachedNode_init)(result);

    /* cache the result */ 
    node->child_cache[idx] = result; 
  } 

  return PDCI_ALIAS_NODE(result);
} 

#undef WHATFN
#define WHATFN "PDCI_sequenced_pd_sndNode_kthChild"
PDCI_node_t * PDCI_sequenced_pd_sndNode_kthChild(PDCI_node_t *node, childIndex idx)
{
  PDCI_sequenced_pd  *pd;
  PDCI_node_t        *result = 0;

  /* We need to know the value of errCode, so force validation. */
  if (P_ERR == PDCI_sndNode_make_valid(node)){
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, WHATFN,
		    "PADS/Galax failed to page node into memory"); 
  }
  pd = (PDCI_sequenced_pd *)node->rep;
  
  if (pd->errCode >= 100) {
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",   pd, &(pd->pstate),     
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr",     pd, &(pd->nerr),       
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode",  pd, &(pd->errCode),    
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 3:
	result = Ploc_t_node_new(node, "loc", pd, &(pd->loc),        
				 node->id_offset + PDCI_LOC_OFF, WHATFN);
	Ploc_t_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 4:
      result = Puint32_val_node_new(node, "neerr",    pd, &(pd->neerr),      
				    node->id_offset + PDCI_NEERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 5:
      result = Puint32_val_node_new(node, "firstError", pd, &(pd->firstError), 
				    node->id_offset + PDCI_FIRSTERROR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    }
  }else{
    switch (idx) {
    case 0:
      result = Puint32_val_node_new(node, "pstate",   pd, &(pd->pstate),     
				    node->id_offset + PDCI_PSTATE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 1:
      result = Puint32_val_node_new(node, "nerr",     pd, &(pd->nerr),       
				    node->id_offset + PDCI_NERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 2:
      result = Puint32_val_node_new(node, "errCode",  pd, &(pd->errCode),    
				    node->id_offset + PDCI_ERRCODE_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 3:
      result = Puint32_val_node_new(node, "neerr",    pd, &(pd->neerr),      
				    node->id_offset + PDCI_NEERR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    case 4:
      result = Puint32_val_node_new(node, "firstError", pd, &(pd->firstError), 
				    node->id_offset + PDCI_FIRSTERROR_OFF, WHATFN);
      Puint32_val_sndNode_init(result,node->manager,node->ancestor_idx,node->ptr_gen,idx);
      break;
    }
  }
  return result;
}

#undef WHATFN
#define WHATFN "PDCI_sequenced_pd_sndNode_kthChildNamed"
PDCI_node_t * PDCI_sequenced_pd_sndNode_kthChildNamed(PDCI_node_t *node, childIndex idx, const char* name)
{
  PDCI_sequenced_pd  *pd;
  PDCI_node_t        *result = 0;

  /* the only valid idx is 0 */
  if (idx) return 0;

  /* We need to know the value of errCode, so force validation. */
  if (P_ERR == PDCI_sndNode_make_valid(node)){
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, WHATFN,
		    "PADS/Galax failed to page node into memory"); 
  }
  pd = (PDCI_sequenced_pd *) node->rep;
  
  if (pd->errCode >= 100){
    if (strcmp(name, "pstate") == 0)            idx = 0;
    else if (strcmp(name, "nerr") == 0)         idx = 1;
    else if (strcmp(name, "errCode") == 0)      idx = 2;
    else if (strcmp(name, "loc") == 0)          idx = 3;
    else if (strcmp(name, "neerr") == 0)        idx = 4;
    else if (strcmp(name, "firstError") == 0)   idx = 5;
    else return result;
  }else{
    if (strcmp(name, "pstate") == 0)            idx = 0;
    else if (strcmp(name, "nerr") == 0)         idx = 1;
    else if (strcmp(name, "errCode") == 0)      idx = 2;
    else if (strcmp(name, "neerr") == 0)        idx = 3;
    else if (strcmp(name, "firstError") == 0)   idx = 4;
    else return result;
  }

  return (node->vt->kth_child)(node,idx);
}

/* Used for any node with no children */
/* 
   We have to accommodate Galax here.  For nodes that contain only typed values, 
   Galax expects children() to return a text node containing the typed
   value as a string.  This may be onerous, but necessary for the moment.
*/
#undef WHATFN
#define WHATFN "PDCI_no_children"
PDCI_node_t ** PDCI_no_children(PDCI_node_t *node)
{
  PDCI_node_t **result;

  if (!(result = PDCI_NEW_NODE_PTR_LIST(1))) {
      PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR, WHATFN,"PADS/Galax ALLOC_ERROR: in ");
  }
  return result;
}

PDCI_node_t * PDCI_node_no_kthChild(PDCI_node_t *node, childIndex idx)
{
  return 0;
}

PDCI_node_t * PDCI_node_no_kthChildNamed(PDCI_node_t *node, childIndex idx, const char *name)
{
  return 0;
}

/* ---------------------------
 * Some general-use functions
 * --------------------------- */

/*
int PDCI_pglx_error(const char *libnm, int level, ...){
  return P_error(libnm,.
}
*/

void PDCI_node_free(PDCI_node_t *node){
  NodeMM_free(node->pads, node);
}
 
void PDCI_cachedNode_free(PDCI_node_t *node)
  {/* ignore. cached nodes aren't freed. */} 

/* Get the id of (non-smart) nodes with pds of (super)type Pbase_pd,
   based on the offset in id_offset.
 * All pds currently fit this description.*/
PDCI_pglx_id_t PDCI_node_getId(PDCI_node_t *node){
  Pbase_pd *pd = (Pbase_pd *)node->pd;
  PDCI_pglx_id_t id;

  id.gId = 0;
  id.mId = pd->_id_ + node->id_offset;
  return id;
}

PDCI_pglx_id_t PDCI_sndNode_getId(PDCI_node_t *node){
  Pbase_pd *pd;
  PDCI_pglx_id_t id;

  /* Make sure that the node is valid before 
   * attempting to access its contents. 
   */ 
  PDCI_sndNode_validate(node);
  pd = (Pbase_pd *)node->pd;

  id.gId = node->ancestor_idx + 1;
  id.mId = pd->_id_ + node->id_offset;
  return id;
}

/* Get the id of smart nodes with pds of (super)type Pbase_pd. */
PDCI_pglx_id_t PDCI_smartNode_getId(PDCI_node_t *node){
  PDCI_pglx_id_t id;
  Pbase_pd *pd = (Pbase_pd *)node->pd;

  id.gId = 0;
  id.mId = pd->_id_;
  return id;
}

/* For use with textnodes which have no id.*/
PDCI_pglx_id_t PDCI_error_getId(PDCI_node_t *node)
{ 
  PDCI_pglx_id_t id = {0,0};
  
  PGLX_report_err(node->pads,P_LEV_FATAL,0, P_INVALID_FUNCTION_CALL,
		  "PDCI_error_getId","\nPads-galax node of name %s does not have a nodeid.\n",node->name);
  return id;  /* will never get here*/
}

/* Error function used for many cases */
item PDCI_error_typed_value(PDCI_node_t *node)
{
  /*
  PGLX_report_err(node->pads,P_LEV_FATAL,0, P_INVALID_FUNCTION_CALL,
		  "PDCI_error_getId","PADS/Galax NOT_A_VALUE: typed_value called on structured type.Name: %s, kind: %s.",node->name,node->kind);
  */
  PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PDCI_error_typed_value","PADS/Galax NOT_A_VALUE: typed_value called on structured type.");
  return 0;  /* will never get here*/
} 

/* Error function used for cachedNode vtables, as cachedNodes should never
   be reinitialized. */
PDCI_node_t *PDCI_error_cachedNode_init(PDCI_node_t *node)
{
  PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"PDCI_error_cachedNode_init",
		  "PADS/Galax Error: Attempting to re-initialize cachedNode.");
  return 0;  /* will never get here*/
} 

/* 
 * PDCI_cstr functions.
 * In a PDCI_cstr, node->rep is a C-style string (const char *) 
 */
PDCI_node_t * PDCI_cstr_val_node_new(PDCI_node_t *parent, 
			 const char *name, 
			 void *pd, void *rep,
                         unsigned int id_offset,
			 const char *whatfn)
{
  PDCI_node_t *result;
  PDCI_MK_TNODE (result,& PDCI_cstr_val_node_vtable,
		parent,name,rep,whatfn);
  result->pd = pd;
  result->id_offset = id_offset;
  return result;
}

PDCI_SND_INIT_DEF(PDCI_cstr_val) 

item PDCI_cstr_typed_value(PDCI_node_t *node)
{
  item        res = 0;
  char        *s   = (char *)node->rep;

  if (galax_atomicUntyped(s, &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Pcstr_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");
  }
  return res;
}

item PDCI_cstr_sndNode_typed_value(PDCI_node_t *node)
{
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return PDCI_cstr_typed_value(node);
}

/* Misc. XXX_value functions. */
item Pchar_typed_value (PDCI_node_t *node)
{
  item         res = 0;
  Pchar        c   = *((char*)node->rep);
  Pbase_pd  *pd  = (Pbase_pd*)node->pd;
  Pbase_pd   tpd;
  if (!pd) {
    pd = &tpd;
    pd->errCode = P_NO_ERR;
  }
  PDCI_sfstr_seek2zero(node->pads->tmp2);
  sfprintf(node->pads->tmp2, "%c", c);
  if (galax_atomicString(PDCI_sfstr_use(node->pads->tmp2), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Pchar_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");
  }
  return res;
}

item Pchar_sndNode_typed_value (PDCI_node_t *node)
{
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Pchar_typed_value(node);
}

item Pstring_typed_value (PDCI_node_t *node)
{
  item         res = 0;
  Pstring *ps = (Pstring*)node->rep;
  Pbase_pd  *pd  = (Pbase_pd*)node->pd;
  Pbase_pd   tpd;
  if (!pd) {
    pd = &tpd;
    pd->errCode = P_NO_ERR;
  }
  PDCI_sfstr_seek2zero(node->pads->tmp2);
  sfprintf(node->pads->tmp2, "%.*s", ps->len, ps->str);
  if (galax_atomicString(PDCI_sfstr_use(node->pads->tmp2), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Pstring_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");
  }
  return res;
}

item Pstring_sndNode_typed_value (PDCI_node_t *node)
{
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Pstring_typed_value(node); 
}

item Pdate_typed_value (PDCI_node_t *node){
  item       res = 0;
  if (galax_atomicDate(Pdate_string_value(node), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Pdate_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");  }
  return res;
}

item Pdate_sndNode_typed_value (PDCI_node_t *node){
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Pdate_typed_value(node);
}

item Ptime_typed_value (PDCI_node_t *node){
  item         res = 0;
  if (galax_atomicTime(Ptime_string_value(node), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Ptime_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");  }
  return res;
}

item Ptime_sndNode_typed_value (PDCI_node_t *node){
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Ptime_typed_value(node);
}

item Ptimestamp_typed_value (PDCI_node_t *node){
  item         res = 0;
  if (galax_atomicDateTime(Ptimestamp_string_value(node), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,"Ptimestamp_typed_value","PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");  }
  return res;
}

item Ptimestamp_sndNode_typed_value (PDCI_node_t *node){
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Ptimestamp_typed_value(node); 
}

item Pip_typed_value (PDCI_node_t *node)
{
  item         res = 0;
  Pip pip = *(Pip*)node->rep;
  Pbase_pd  *pd = (Pbase_pd*)node->pd;
  Pbase_pd   tpd;

  if (!pd) {
    pd = &tpd;
    pd->errCode = P_NO_ERR;
  }
  PDCI_sfstr_seek2zero(node->pads->tmp2);
  sfprintf(node->pads->tmp2, "%u.%u.%u.%u", 
	   (pip >> 24) & 0xFF, 
	   (pip >> 16) & 0xFF,
	   (pip >>  8) & 0xFF,
	    pip        & 0xFF);
  if (galax_atomicString(PDCI_sfstr_use(node->pads->tmp2), &res)) {
    PGLX_report_err(node->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,
		    "Pip_typed_value",
		    "PADS/Galax UNEXPECTED_GALAX_VALUE_WRAP_FAILURE");
  }
  return res;
}

item Pip_sndNode_typed_value (PDCI_node_t *node)
{
  /* Make sure that the node is valid before attempting to access its contents. */
  PDCI_sndNode_validate(node);
  return Pip_typed_value(node); 
}

/* ---------------------------
 * Some string_value functions
 * --------------------------- */

const char * PDCI_not_impl_yet_string_value(PDCI_node_t *node)
{
  return ""; /* not meaningful to concat the leaves of pads data? */
}

/* Helper vtables */

#define PDCI_DEF_HELPER_VT(ty,sndKCN) \
const PDCI_vtable_t \
ty ## _node_vtable = {ty ## _cachedNode_init, \
			     ty ## _node_kthChild, \
			     ty ## _node_kthChildNamed, \
                             PDCI_node_free, \
			     PDCI_node_getId,\
			     PDCI_error_typed_value, \
			     PDCI_not_impl_yet_string_value};\
\
const PDCI_vtable_t \
ty ## _cachedNode_vtable = {PDCI_error_cachedNode_init, \
			     ty ## _cachedNode_kthChild, \
			     ty ## _node_kthChildNamed, \
                             PDCI_cachedNode_free, \
			     PDCI_node_getId,\
			     PDCI_error_typed_value, \
			     PDCI_not_impl_yet_string_value};\
\
const PDCI_vtable_t \
ty ## _sndNode_vtable = {PDCI_error_cachedNode_init,\
			     ty ## _sndNode_kthChild, \
			     ty ## _ ## sndKCN ## _kthChildNamed, \
                             PDCI_node_free, \
			     PDCI_sndNode_getId,\
			     PDCI_error_typed_value, \
			     PDCI_not_impl_yet_string_value}

PDCI_DEF_HELPER_VT(PDCI_structured_pd,sndNode);
PDCI_DEF_HELPER_VT(PDCI_sequenced_pd,sndNode);
PDCI_DEF_HELPER_VT(Pbase_pd,sndNode);
PDCI_DEF_HELPER_VT(Ploc_t,node);
PDCI_DEF_HELPER_VT(Ppos_t,node);

PDCI_NO_CHILD_CN_INIT_DEF(PDCI_cstr_val)

const PDCI_vtable_t
PDCI_cstr_val_node_vtable = {PDCI_cstr_val_cachedNode_init,
			PDCI_node_no_kthChild,
			PDCI_node_no_kthChildNamed,
                        PDCI_node_free, \
			PDCI_node_getId,
			PDCI_cstr_typed_value,
			PDCI_not_impl_yet_string_value};

const PDCI_vtable_t
PDCI_cstr_val_cachedNode_vtable = {PDCI_error_cachedNode_init,
				   PDCI_node_no_kthChild,
				   PDCI_node_no_kthChildNamed,
				   PDCI_cachedNode_free,
				   PDCI_node_getId,
				   PDCI_cstr_typed_value,
				   PDCI_not_impl_yet_string_value};

const PDCI_vtable_t
PDCI_cstr_val_sndNode_vtable = {PDCI_error_cachedNode_init,
				PDCI_node_no_kthChild,
				PDCI_node_no_kthChildNamed,
				PDCI_node_free,
				PDCI_sndNode_getId,
				PDCI_cstr_sndNode_typed_value,
				PDCI_not_impl_yet_string_value};

/* Impl some base type children and typed_value functions and
   associated vtable/val_vtable pairs */

PDCI_IMPL_BASE_VT(Pip);
PDCI_IMPL_BASE_VAL_VT(Pip);

PDCI_IMPL_BASE_VT(Pdate);
/* The second parameter is copied from Pstring below. 
   I don't know that it is the correct choice. YHM.*/
PDCI_IMPL_BASE_VAL_VT_ARG1(Pdate, ' ');

PDCI_IMPL_BASE_VT(Ptime);
/* The second parameter is copied from Pstring below. 
   I don't know that it is the correct choice. YHM.*/
PDCI_IMPL_BASE_VAL_VT_ARG1(Ptime, ' ');

PDCI_IMPL_BASE_VT(Ptimestamp);
/* The second parameter is copied from Pstring below. 
   I don't know that it is the correct choice. YHM.*/
PDCI_IMPL_BASE_VAL_VT_ARG1(Ptimestamp, ' ');

PDCI_IMPL_BASE_VT(Pchar);
PDCI_IMPL_BASE_VAL_VT(Pchar);

PDCI_IMPL_BASE_VT(Pstring);
PDCI_IMPL_BASE_VAL_VT_ARG1(Pstring, ' ');

PDCI_IMPL_BASE_VT(Pint8);
PDCI_IMPL_TYPED_VALUE_INT(Pint8);
PDCI_IMPL_BASE_VAL_VT(Pint8);

PDCI_IMPL_BASE_VT(Pint16);
PDCI_IMPL_TYPED_VALUE_INT(Pint16);
PDCI_IMPL_BASE_VAL_VT(Pint16);

PDCI_IMPL_BASE_VT(Pint32);
PDCI_IMPL_TYPED_VALUE_INTEGER(Pint32);
PDCI_IMPL_BASE_VAL_VT(Pint32);

PDCI_IMPL_BASE_VT(Pint64);
PDCI_IMPL_TYPED_VALUE_INTEGER(Pint64);
PDCI_IMPL_BASE_VAL_VT(Pint64);

PDCI_IMPL_BASE_VT(Puint8);
PDCI_IMPL_TYPED_VALUE_INT(Puint8);
PDCI_IMPL_BASE_VAL_VT(Puint8);

PDCI_IMPL_BASE_VT(Puint16);
PDCI_IMPL_TYPED_VALUE_INT(Puint16);
PDCI_IMPL_BASE_VAL_VT(Puint16);

PDCI_IMPL_BASE_VT(Puint32);
PDCI_IMPL_TYPED_VALUE_INTEGER(Puint32);
PDCI_IMPL_BASE_VAL_VT(Puint32);

PDCI_IMPL_BASE_VT(Puint64);
PDCI_IMPL_TYPED_VALUE_INTEGER(Puint64);
PDCI_IMPL_BASE_VAL_VT(Puint64);

PDCI_IMPL_BASE_VT(Pfloat32);
PDCI_IMPL_TYPED_VALUE_FLOAT(Pfloat32)
PDCI_IMPL_BASE_VAL_VT(Pfloat32);

PDCI_IMPL_BASE_VT(Pfloat64);
PDCI_IMPL_BASE_VAL_VT(Pfloat64);

/*

 char,string -> atomicString

Integer types:
 everything < 32 is atomicInt
 32,64 are atomicInteger

 fpoint,floats,doubles are atomicFloat

*/

/* XXX TEMP XXX needs to be moved/removed */
Sfio_t *P_io_get(P_t *pads)
{
  return pads->io;
}

Perror_t P_io_seek(P_t *pads, Sfoff_t offset){
  Sfio_t *io = P_io_get(pads);
  P_io_close(pads);
  Sfoff_t off = sfseek(io, offset, 0);
  if (-1 == off || offset != off) {
    return P_ERR;
  }

  return P_io_set(pads, io);
}
