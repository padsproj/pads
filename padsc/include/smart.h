/*
 * smart nodes types.
 * 
 * Robert Gruber, Yitzhak Mandelbaum
 * AT&T Labs Research
 */

#ifndef __SMART_H__
#define __SMART_H__


typedef unsigned long PDCI_gen_t;// XXX: Soundness not guaranteed, due to potential 
                                 // wrapping of gen counts.

// ======================================================================
// Core Data Structure Typedefs
// ======================================================================

typedef struct PDCI_smart_elt_info_s     PDCI_smart_elt_info_t;
typedef struct PDCI_smart_node_s         PDCI_smart_node_t;
typedef struct PDCI_smart_array_info_s   PDCI_smart_array_info_t; 
typedef PDCI_smart_node_t                PDCI_manager_t;

// ======================================================================
// Functions needed by smart nodes
// ======================================================================

// Type: PDCI_smart_elt_read_fn
//
// The smart elt read function allocates and initializes info->rep, info->pd, and info->mask,
// (parent->m is the smart node mask, read_elt_fn pulls out the elt mask after doing appropriate cast)
// (parent->pd is used to track read state so far / final state if finalized is true) 
// and then reads the element. 
// Additionally, this function will deal with paging out other elements, if necessary. 
//
// Input: info->idx, info->offset should be valid,
//        node->next_idx tells us whether we are re-reading or reading for the first time
//          when re-reading, we do not bump node->contents.pd.(err/nerr) beccause
//          they were already bumped on the first read, and we do not need to check
//          for termination conditions because they were already checked.
// 
// Returns: P_OK if read succeeded, P_ERR otherwise. Note that a read with data errors is still a 
//          successful read.

typedef  Pread_res_t (*PDCI_smart_elt_read_fn)(PDCI_node_t *node, P_t *pads, PDCI_smart_elt_info_t *info);


// Type: PDCI_smart_elt_alloc_fn
//
// Allocates a new rep, pd and any other necessary memory.
// 

typedef  Perror_t (*PDCI_smart_elt_alloc_fn)(PDCI_node_t *smartNode, P_t *pads,
					     void **elt_pd, void **elt_rep);

// Type: PDCI_smart_elt_free_fn
//
// Because the above allocates them, we need a way to free info->rep, info->pd, info->mask

typedef  Perror_t (*PDCI_smart_elt_free_fn)(P_t *pads, PDCI_smart_elt_info_t *info);


// Type: PDCI_offset_walk_fn
//
// Walk PADS representation rep, pd and m to find rep, pd and m of structure at offset.

typedef Perror_t  (* PDCI_path_walk_fn) (P_t *pads, void *m, void *pd, void *rep, PDCI_path_t path,
					 void **m_out, void **pd_out, void **rep_out);


// Type: PDCI_smart_failure_fn
//
// Report that something very wrong happened.
// elt_info can be NULL if failure not associated with a particular elt

typedef void   (* PDCI_smart_failure_fn) (P_t *pads, PDCI_smart_node_t *node, 
					  PDCI_smart_elt_info_t *info,
					  int error_level,
					  const char *descr);


// ======================================================================
// Core Data Structures
// ======================================================================


//////////////////////////////////////
// Type: PDCI_smart_node_t
//
// Construction Notes:
//   smart array -
//        P_PS_setPartial(&(content.pd))
//   ...
//

struct PDCI_smart_node_s {

  // information needed to manage elements
  PDCI_smart_elt_read_fn     elt_read;
  PDCI_smart_elt_alloc_fn    elt_alloc;
  PDCI_smart_elt_free_fn     elt_free;
  PDCI_path_walk_fn          elt_path_walk;
  /* Deprecated: */
  PDCI_smart_failure_fn      handle_failure;

  // For arrays, elt_state is a <ty>_array_info_t, which will always include
  // an instance of PDCI_smart_array_t
  void                      *elt_state;  
};


//////////////////////////////////////
// Type: PDCI_smart_array_info_t
//
// Information used by the elt_read function implemented for arrays.
//

struct PDCI_smart_array_info_s {
  // INV: tmap[0] ... tmap[next_idx_create-1] are all allocated elements.
  // INV: tmap[0] ... tmap[next_idx_read-1] are all valid elements.
  // INV: Forall valid idx, tmap[idx].rep != NULL iff tmap[idx] is in memory.
  // INV: Forall valid idx, tmap[idx].pd != NULL iff tmap[idx] is in memory.
  PDCI_smart_elt_info_t     *tmap;         // alias of _internal's buf; reset on growth
  RBuf_t                    *_internal;    // growable rbuf for tmap
  PDCI_childIndex_t         *liveList;       // list of live elements, used to choose an evictee.
  RBuf_t                    *_internal_live;    // growable rbuf for liveList.

  unsigned int               max_elts;         // maximum number of elements allowed in-memory at once.

  // parse state
  Sfoff_t                    first_offset; // offset for idx 0
  Sfoff_t                    next_offset;  // offset for next_idx

  PDCI_childIndex_t          next_idx_read;    // first unread index
  PDCI_childIndex_t          next_idx_create;  // first uncreated index

  /* live is used as a "producer" and 
   * evict is used as a "consumer".
   */
  unsigned int               next_idx_live;    // next available space in the live list
  unsigned int               next_idx_evict;   // next eviction candidate of the live list.
  unsigned int               live_count;
  // ...
  
};

//////////////////////////////////////
// Type: PDCI_smart_elt_info_s
//
// Information stored for each smart element of a smart node.
//

struct PDCI_smart_elt_info_s {

  // always valid (and all we need to read into memory -- 
  //               plus some stuff at smart array level):

  PDCI_node_t         *parent;  // the smart node that contains this element.
  PDCI_childIndex_t    idx;
  Sfoff_t              offset; // can be used as the key if stored in a hash table.
  PDCI_gen_t           gen; 
  void                *m; 

  // only valid if data is in memory:

  void                *rep;
  void                *pd;
};

// ======================================================================
// Macros
// ======================================================================

#define PDCI_NEW_SMART_NODE(padsIN)\
  ((PDCI_smart_node_t *)calloc(1,sizeof(PDCI_smart_node_t)))

#define PDCI_INIT_SMART_NODE(resultIN, readIN, allocIN, freeIN, walkIN, failIN, stateIN) \
  do {  \
    (resultIN)->elt_read = (readIN); \
    (resultIN)->elt_alloc = (allocIN); \
    (resultIN)->elt_free = (freeIN); \
    (resultIN)->elt_path_walk = (walkIN); \
    (resultIN)->handle_failure = (failIN); \
    (resultIN)->elt_state = (stateIN); \
  } while (0)

#define PDCI_MK_SMART_NODE(resultIN, padsIN, readIN, allocIN, freeIN, walkIN, failIN, stateIN, whatfn) \
  do {  \
    if (!(resultIN = PDCI_NEW_SMART_NODE(padsIN))) { \
      failwith("PADS/Galax ALLOC_ERROR: in " whatfn); \
    } \
    PDCI_INIT_SMART_NODE(resultIN, readIN, allocIN, freeIN, walkIN, failIN, stateIN); \
  } while (0)

#define PDCI_INIT_SMART_ELT(eltIN, parentIN, idxIN, offsetIN, genIN, repIN, pdIN, mIN) \
do {\
  (eltIN).parent = (parentIN);\
  (eltIN).idx    = (idxIN);\
  (eltIN).offset = (offsetIN);\
  (eltIN).gen    = (genIN);\
  (eltIN).rep    = (repIN);\
  (eltIN).pd     = (pdIN);\
  (eltIN).m      = (mIN);\
} while (0)

// ======================================================================
// Function Headers
// ======================================================================

Perror_t P_sn_getFreeElt(PDCI_node_t *smartNode, P_t *pads,
			 void **elt_pd, void **elt_rep);

/* Tell the system that element with index elt is in memory. 
   Called after getFreeElt. */
Perror_t P_sn_markElementLive(PDCI_smart_array_info_t *arrayInfo,
			      PDCI_childIndex_t elt,
			      void *elt_pd,void *elt_rep);

/* Current implementation uses a FIFO eviction strategy. */
Perror_t P_sn_chooseEltToEvict(PDCI_smart_array_info_t *arrayInfo,
			       PDCI_childIndex_t *elt);

/* After an element is evicted, and its memory recycled, it must be
   marked as dead. */
Perror_t P_sn_markElementDead(PDCI_smart_array_info_t *arrayInfo, 
			      PDCI_childIndex_t elt);

/* A default implementation of the smart node handle_failure function.*/
void P_sn_handleFailure(P_t *pads, PDCI_smart_node_t *node, 
			PDCI_smart_elt_info_t *info,
			int error_level,
			const char *descr);

PDCI_smart_array_info_t *PDCI_makeSmartArrayInfo(P_t *pads,int max_elts, int size);

//
// Check whether *node refers to an in-memory element.
//
int PDCI_sndNode_is_valid(PDCI_node_t *node);

//
// Make *node valid. This function includes all the logic for 
// ensuring that node is a valid reference (e.g. all flags are set 
// correctly, everything is in memory that should be, etc.)
// Use only if !PDCI_node_is_valid(node)
//
// In: node
// Out: *node.
//
Perror_t PDCI_sndNode_make_valid(PDCI_node_t *node);

// Regardless of current state of node, node will be valid on return from function.
void PDCI_sndNode_validate(PDCI_node_t *node);

#endif /*   __SMART_H__    */
