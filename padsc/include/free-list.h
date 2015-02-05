#ifndef __FREE_LIST_H__
#define __FREE_LIST_H__

/*
 * Generic FreeList header. Can be used with any implementation.
 */

// define FreeList_node_t as an abstract type using bogus type "struct abs_free_list_h".
typdef struct abs_free_list_h FreeList_node_t;

#include "free-list-internal.h"

#endif /* __FREE_LIST_H__ */
