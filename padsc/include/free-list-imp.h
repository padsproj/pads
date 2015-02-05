#ifndef __FREE_LIST_IMP_H__
#define __FREE_LIST_IMP_H__

/*
 * This file is a template. Define the types/macros below 
 * to instantiate it.
 *
 
typedef <TY> FreeList_node_t;
#define FLDEF
#define FLNEXT(n) 
#define FLFREE(n) 
#define FLCLEAR(n)
#define FLALLOC() 

*/

#include "free-list-internal.h"

// for internal use
static FreeList_node_t *FreeList_remove(FreeList_head_t *head);

void FreeList_init(FreeList_head_t *head, unsigned int max_size){
  head->list_head = (FreeList_node_t *)NULL;
  head->list_size = 0;
  head->max_size = max_size;
}

void FreeList_add(FreeList_head_t *head, FreeList_node_t *n){
  if (head->list_size < head->max_size){
    FLNEXT(n) = head->list_head;
    head->list_head = n;
    head->list_size++;
  } else {
    FLFREE(n);
  }
}

FreeList_node_t *FreeList_alloc(FreeList_head_t *head){
  FreeList_node_t *result;

  if (head->list_size > 0){
    result = FreeList_remove(head);
  }else
    result = FLALLOC();

  return result;
}

////////////////////////////////////////
// Internal use
//

static FreeList_node_t *FreeList_remove(FreeList_head_t *head){
  FreeList_node_t *result = 
    head->list_head;
  head->list_head = FLNEXT(result);
  FLCLEAR(result);
  head->list_size--;

  return result;
}

#endif /* __FREE_LIST_IMP_H__ */ 
