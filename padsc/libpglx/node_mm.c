//#include <stdlib.h>
#include "pglx-free-list.h"
#include "node_mm.h"

/* This should be modified to work the way the rest of the system works,
   but in the meantime ... */
#define MM_FATAL(padsIN,s,WHATFN)\
  PGLX_report_err(padsIN,P_LEV_FATAL,0,P_FAILWITH_ERR,WHATFN,\
		  "PADS/Galax: Fatal Error in Node Memory Manager: %s.",(s));

struct NodeMM_s {
  char init;
  FreeList_head_t list;
};

NodeMM_t *NodeMM_newMM(){
  /* We depend on calloc to ensure that init is initially 0 */
  return (NodeMM_t *)calloc(1, sizeof(NodeMM_t));
}

void NodeMM_initMM(P_t *pads, unsigned int max_size){
  NodeMM_t *mm = NodeMM_newMM();
  pads->ext1 = mm;  

  if (max_size == 0)
    max_size = FREE_LIST_DEFAULT_MAX_SIZE;

  if (!mm->init){
    FreeList_init(&(mm->list), max_size);  
    mm->init = 1;
  }
}

void NodeMM_freeMM(P_t *pads){
  NodeMM_t *mm = (NodeMM_t *)pads->ext1;
  free(mm);
  pads->ext1 = 0;
}

PDCI_node_t *NodeMM_get_alias(PDCI_node_t *n){
  n->rc++;
  return n;
}

PDCI_node_t *NodeMM_alloc(P_t *pads){
  NodeMM_t *mm = (NodeMM_t *)pads->ext1;
  if (!mm->init){
    MM_FATAL(pads,"Node Memory Manager not initialized","NodeMM_alloc");
    return 0; //never reached.
  }

  PDCI_node_t *n = FreeList_alloc(&(mm->list));
  n->rc = 1;
  return n;
}

void NodeMM_free(P_t *pads, PDCI_node_t *n){
  NodeMM_t *mm = (NodeMM_t *)pads->ext1;
  if (!mm->init){
    MM_FATAL(pads,"Node Memory Manager not initialized","NodeMM_free");
  }

  // Decrement and check the reference count
  if (--(n->rc) == 0){
    if (n->parent != NULL)
      PDCI_FREE_NODE(n->parent);
    FreeList_add(&(mm->list), n);
  }
}

// If the array is longer than MAX_INT, then free it in pieces.
void NodeMM_freeArray(P_t *pads, PDCI_node_t **nArray, unsigned int length){
  int i;
  for (i=0; i < length; i++)
    NodeMM_free(pads,nArray[i]);
}
