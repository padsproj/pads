#include "pads.h"
#include "pglx-internal.h"

///////////////////////////////////////////////////////////////////////
//
//   Smart Node functions
// 
//////////////////////////////////////////////////////////////////////


Perror_t P_sn_markElementLive(PDCI_smart_array_info_t *arrayInfo,
			      PDCI_childIndex_t elt,
			      void *elt_pd,void *elt_rep)
{
  PDCI_smart_elt_info_t *info = &arrayInfo->tmap[elt];

  if (arrayInfo->live_count >= arrayInfo->max_elts)
    return P_ERR;

  // Add elt to the live list.
  arrayInfo->liveList[arrayInfo->next_idx_live++] = elt;
  arrayInfo->next_idx_live %= arrayInfo->max_elts;
  
  arrayInfo->live_count++;
  
  // Set elt info.
  info->pd = elt_pd;
  info->rep = elt_rep;
  
  return P_OK;
}

/* FIFO eviction strategy. */
Perror_t P_sn_chooseEltToEvict(PDCI_smart_array_info_t *arrayInfo,
			       PDCI_childIndex_t *elt)
{
  if (arrayInfo->live_count == 0)
    return P_ERR;

  *elt = arrayInfo->liveList[arrayInfo->next_idx_evict++];
  arrayInfo->next_idx_evict %= arrayInfo->max_elts;

  arrayInfo->live_count--;

  return P_OK;
}

/*
 * Mark element elt as not present in memory.
 */
Perror_t P_sn_markElementDead(PDCI_smart_array_info_t *arrayInfo, 
			      PDCI_childIndex_t elt)
{
  arrayInfo->tmap[elt].rep = NULL;
  arrayInfo->tmap[elt].pd = NULL;
  arrayInfo->tmap[elt].gen++;

  return P_OK;
}

void P_sn_handleFailure(P_t *pads, PDCI_smart_node_t *node, 
			PDCI_smart_elt_info_t *info,
			int error_level,
			const char *descr)
{
  PGLX_report_err(pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,
		  "(via) P_sn_handleFailure",descr);
}

typedef struct Psequenced_rep_s{
  Puint32 length;
}Psequenced_rep_t;

Perror_t P_sn_getFreeElt(PDCI_node_t *smartNode, P_t *pads,
				  void **elt_pd, void **elt_rep)
{
  PDCI_smart_node_t       *sn  = smartNode->snExt;
  PDCI_smart_array_info_t *arrayInfo  = 
    (PDCI_smart_array_info_t *)sn->elt_state;
  Psequenced_rep_t        *rep  = (Psequenced_rep_t *)smartNode->rep;
  PDCI_childIndex_t        elt;
  Perror_t                 result = P_ERR;

  /* should we attempt to allocate an element? */
  if (rep->length < arrayInfo->max_elts){
    result = sn->elt_alloc(smartNode,pads,
			   elt_pd,elt_rep);
  }

  if (P_ERR == result){ // either the allocation failed, or was never attempted.
    if (P_ERR == P_sn_chooseEltToEvict(arrayInfo,&elt)){
      return P_ERR;
    }
    *elt_pd = arrayInfo->tmap[elt].pd;
    *elt_rep = arrayInfo->tmap[elt].rep;
    P_sn_markElementDead(arrayInfo, elt);
  }

  return P_OK;
}

#undef WHATFN
#define WHATFN "PDCI_makeSmartArrayInfo"
PDCI_smart_array_info_t *PDCI_makeSmartArrayInfo(P_t *pads,int max_elts, int size)
{
  PDCI_smart_array_info_t   *arrayInfo;

  arrayInfo = (PDCI_smart_array_info_t *)calloc(1,size);
  arrayInfo->_internal = RMM_new_rbuf(P_rmm_nozero (pads));
  if (0==(arrayInfo->_internal)) 
    {
      PGLX_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,WHATFN,"");
    }
  arrayInfo->_internal_live = RMM_new_rbuf(P_rmm_nozero (pads));
  if (0==(arrayInfo->_internal_live)) 
    {
      PGLX_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,WHATFN,"");
    }
  arrayInfo->max_elts = max_elts;

  arrayInfo->next_offset = 0;

  arrayInfo->next_idx_read = 0;
  arrayInfo->next_idx_create = 0;
  arrayInfo->next_idx_live = 0;
  arrayInfo->next_idx_evict = 0;
  arrayInfo->live_count = 0;

  return arrayInfo;
}

///////////////////////////////////////////////////////////////////////
//
//   Smart Node descendant functions
// 
//////////////////////////////////////////////////////////////////////

PDCI_smart_elt_info_t *PDCI_get_ancestor(PDCI_node_t *node){
  PDCI_smart_array_info_t *arrayInfo = (PDCI_smart_array_info_t *)node->manager->elt_state;
  PDCI_childIndex_t idx = node->ancestor_idx;
  return &arrayInfo->tmap[idx];
}

// PDCI_get_ancestor(node) must be valid.
int PDCI_sndNode_is_valid(PDCI_node_t *node){
  return (node->rep != NULL && PDCI_get_ancestor(node)->gen == node->ptr_gen);
}

// use only if !PDCI_node_is_valid(node)
Perror_t PDCI_sndNode_make_valid(PDCI_node_t *node){
  Pread_res_t res;
  Perror_t result;
  PDCI_smart_elt_info_t  *ancestor = PDCI_get_ancestor(node);
  PDCI_smart_node_t      *sn       = ancestor->parent->snExt; // Alias the smart node.
  PDCI_path_t             path;

  error(2, "In PDCI_sndNode_make_valid\n");
  if (ancestor->rep == NULL) { 
    /* must read from IO stream first */ 
    res = sn->elt_read(ancestor->parent, node->pads, ancestor);
    if (res != P_READ_OK_DATA) { 
      /* 
       * the read failed when we 
       * were expecting it to succeed.
       */
      return P_ERR;
    } 
  } 

  path = PDCI_node_getPath(node,0);

  /* update pointers and generation */ 
  result = sn->elt_path_walk(node->pads,ancestor->m, ancestor->pd, ancestor->rep, path,
			  &(node->m), &(node->pd), &(node->rep));

  PDCI_PATH_FREE(path);

  if (result == P_ERR) { 
    // Something's wrong:
    //sn->handle_failure(node->pads,sn,ancestor,ERROR_WARNING,"failed to find element in path walk");
    return P_ERR;
  } 
  node->ptr_gen = ancestor->gen; 

  return P_OK;
}

#undef WHATFN
#define WHATFN "PDCI_sndNode_validate"
void PDCI_sndNode_validate(PDCI_node_t *node){
  if (!PDCI_sndNode_is_valid(node) 
      && P_ERR == PDCI_sndNode_make_valid(node))
    {
      PGLX_report_err(node->pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,
		      WHATFN,"Failed to page node into memory.");
    }
}
