
#ifndef __NODE_MM_H__
#define __NODE_MM_H__

#define FREE_LIST_DEFAULT_MAX_SIZE 1000

/* !!! The type PDCI_node_t must be defined before including this file. !!! */

typedef struct NodeMM_s NodeMM_t;

NodeMM_t *NodeMM_newMM();

/*
 * If max_size == 0, then the default max size is used.
 */
void NodeMM_initMM(P_t *pads, unsigned int max_size);

void NodeMM_freeMM(P_t *pads);

PDCI_node_t *NodeMM_alloc(P_t *pads);

void NodeMM_free(P_t *pads, PDCI_node_t *n);

// If the array is longer than MAX_INT, then free it in pieces.
void NodeMM_freeArray(P_t *pads, PDCI_node_t **nArray, unsigned int length);

PDCI_node_t *NodeMM_get_alias(PDCI_node_t *n);

#endif /* __NODE_MM_H__ */
