//////////
// A PADS instantation of free-list-impl.h
//


/* Definitions of free, memset, calloc are in the ast library (?) */
#define FLDEF
#define FLNEXT(n) ((n)->parent)
#define FLFREE(n) (free(n))
#define FLCLEAR(n) (memset((n),0,sizeof(PDCI_node_t)))
#define FLALLOC() \
  ((PDCI_node_t*)calloc(1, sizeof(PDCI_node_t)))

#include "pglx-free-list.h"

// Import the implementation:
#include "free-list-imp.h"
