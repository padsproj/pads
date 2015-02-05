#ifndef __FREE_LIST_INTERNAL_H__
#define __FREE_LIST_INTERNAL_H__

/* !!! The type FreeList_node_t must be defined before including this file. !!! */

typedef struct FreeList_head_s{
  FreeList_node_t    *list_head;
  unsigned int        list_size;
  unsigned int        max_size;
}FreeList_head_t;

void FreeList_init(FreeList_head_t *head, unsigned int max_size);

FreeList_node_t *FreeList_alloc(FreeList_head_t *head);

//
// 
//
void FreeList_add(FreeList_head_t *head, FreeList_node_t *n);

#endif /* __FREE_LIST_INTERNAL_H__ */
