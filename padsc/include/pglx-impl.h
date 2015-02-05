/*
 * macros, galax-pads
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PGLX_IMPL_H__
#define __PGLX_IMPL_H__

#define PDCI_INIT_NODE(resultIN, vtIN, padsIN, parentIN, nameIN, mIN, pdIN, repIN, kindIN) \
  do {  \
    resultIN->vt     = (vtIN); \
    resultIN->pads    = (padsIN); \
    resultIN->parent = PDCI_ALIAS_NODE(parentIN); \
    resultIN->m      = (void *)(mIN); \
    resultIN->pd     = (void *)(pdIN); \
    resultIN->rep    = (repIN);   \
    resultIN->name   = (nameIN);  \
    resultIN->kind   = (kindIN);  \
  } while (0)

#define PDCI_MK_NODE(resultIN, vtIN, parentIN, nameIN, mIN, pdIN, repIN, kindIN, whatfn) \
  do {  \
    if (!(resultIN = PDCI_NEW_NODE((parentIN)->pads))) { \
      PGLX_report_err((parentIN)->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,whatfn,"PADS/Galax ALLOC_ERROR"); \
    } \
    PDCI_INIT_NODE(resultIN,vtIN,(parentIN)->pads,parentIN,nameIN,mIN,pdIN,repIN,kindIN); \
  } while (0)

#define PDCI_MK_TOP_NODE(resultIN, vtIN, padsIN, nameIN, mIN, pdIN, repIN, whatfn) \
  do {  \
    if (!(resultIN = PDCI_NEW_NODE(padsIN))) { \
      PGLX_report_err(padsIN,P_LEV_FATAL,0,P_FAILWITH_ERR,whatfn,"PADS/Galax ALLOC_ERROR"); \
    } \
    PDCI_INIT_NODE(resultIN,vtIN,padsIN,NULL,nameIN,mIN,pdIN,repIN,"element"); \
  } while (0)

#define PDCI_MK_TOP_NODE_NORET(resultIN, vtIN, padsIN, nameIN, mIN, pdIN, repIN, whatfn) \
  do {  \
    resultIN = PDCI_NEW_NODE(padsIN); \
    if (resultIN) { \
      PDCI_INIT_NODE(resultIN,vtIN,padsIN,NULL,nameIN,mIN,pdIN,repIN,"element"); \
    } \
  } while (0)

#define  PDCI_MK_TNODE(resultIN, vtIN, parentIN, nameIN, repIN, whatfn) \
  PDCI_MK_NODE(resultIN, vtIN, parentIN, nameIN, 0, 0, repIN,           "element", whatfn)

#define  PDCI_MK_TEXTNODE(resultIN, vtIN, parentIN, whatfn) \
  PDCI_MK_NODE(resultIN, vtIN, parentIN, "",     0, 0, (parentIN)->rep, "text", whatfn)

/* TODO: BASE TYPE: make macro for each base type */

#define PDCI_NEW_NODE(pads) (NodeMM_alloc(pads))

#define PDCI_NEW_LIST(num) \
  ((PDCI_node_t**)calloc((num), sizeof(void*)))
 
#define PDCI_NEW_NODE_PTR_LIST(num) \
  PDCI_NEW_LIST((num) + 1)

#define PDCI_ALIAS_NODE(n) ((n) == NULL ? NULL : NodeMM_get_alias(n))

#define PDCI_FREE_NODE(n) (((n)->vt->free)(n)) 

#define PDCI_FREE_NODE_PTR_LIST(list) \
  free(list)

#define PDCI_SND_INIT(ty,selfIN,managerIN,anc_idxIN,genIN,idxIN)   \
do{                                           \
   /* Setup the virtual table */              \
  (selfIN)->vt = & ty ## _sndNode_vtable;     \
					      \
  /* Setup node-type specific fields  */      \
  (selfIN)->manager = (managerIN);		      \
  (selfIN)->ancestor_idx = (anc_idxIN);		      \
  (selfIN)->ptr_gen = (genIN);	              \
  (selfIN)->idx = (idxIN);	              \
}while(0)

/*
extern const PDCI_path_t PDCI_emptyPath;
#define PDCI_EMPTY_PATH (PDCI_emptyPath)

#define PDCI_PATH_INC(pathIN) ((pathIN).length++)
#define PDCI_PATH_DEC(pathIN) ((pathIN).length--)
*/

/* child <= ty_PATH_MASK 
#define PDCI_PATH_ADD(ty,p,child)\
  {((p).path |((child) << (p).length)),(p).length+(ty ## _pathWidth)}
*/

#define PDCI_PATH_NEW(pathIN,LENGTH)\
do{\
  if ((LENGTH) > 0){\
    (pathIN).p = (PDCI_childIndex_t *)calloc((LENGTH),sizeof(PDCI_childIndex_t));\
  }else{ \
   (pathIN).p = 0;\
  }\
 (pathIN).length = (LENGTH);   \
}while(0)

#define PDCI_PATH_FREE(pathIN)\
do{\
  if ((pathIN).p != 0){\
    free((pathIN).p);  \
    (pathIN).p = 0;\
  }\
  (pathIN).length = 0;\
}while(0)

#define PDCI_PATH_SET(pathIN,idxIN,childIN)\
do{\
  (pathIN).p[idxIN] = (childIN);\
}while(0)

#define PDCI_PATH_GET(pathIN)     \
  ((pathIN).p[--((pathIN).length)])

#ifndef NDEBUG
#define PDCI_NODE_CHECK(n, whatfn) \
do { \
  if (!(n)) \
    PGLX_report_err((n)->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,whatfn,"PADS/Galax INVALID_PARAM: " PDCI_MacroArg2String(n) " null"); \
} while (0)

#define PDCI_NODE_VT_CHECK(n, whatfn) \
do { \
  if (!n) \
    PGLX_report_err((n)->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,whatfn,"PADS/Galax INVALID_PARAM: " PDCI_MacroArg2String(n) " null"); \
  if (!n->vt) \
    PGLX_report_err((n)->pads,P_LEV_FATAL,0,P_FAILWITH_ERR,whatfn,"PADS/Galax INVALID_PARAM: " PDCI_MacroArg2String(n) "->vt null"); \
} while (0)

#else

#define PDCI_NODE_CHECK(n, whatfn)      P_NULL_STMT
#define PDCI_NODE_VT_CHECK(n, whatfn)   P_NULL_STMT

#endif

#endif /*   __PGLX_IMPL_H__    */
