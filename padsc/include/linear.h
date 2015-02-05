/*
 * linear-read nodes types.
 * 
 * Yitzhak Mandelbaum
 * AT&T Labs Research
 */

#ifndef __LINEAR_NODE_H__
#define __LINEAR_NODE_H__

typedef struct PDCI_linear_node_s PDCI_linear_node_t;

// ======================================================================
// Core Data Structures
// ======================================================================


//////////////////////////////////////
// Type: PDCI_linear_node_t
//
// Construction Notes:
//   linear array -
//        P_PS_setPartial(&(content.pd))
//   ...
//

struct PDCI_linear_node_s {
  PDCI_childIndex_t   next_idx_read;    // first unread array index

  // Data structures for reading elements

  /* ??? The mask field might be unnecessary, as read_one doesn't use it */
  void                *elt_m; 
  void                *elt_rep;
  void                *elt_pd;

  // Extra parameters for read_one function.
  void                *ro_params;
};

// ======================================================================
// Macros
// ======================================================================

#define PDCI_NEW_LINEAR_NODE(padsIN)\
  ((PDCI_linear_node_t *)calloc(1,sizeof(PDCI_linear_node_t)))

#define PDCI_INIT_LINEAR_NODE(resultIN, mIN,pdIN,repIN, ro_paramsIN) \
  do {  \
    (resultIN)->next_idx_read = 0; \
    (resultIN)->elt_m = (mIN); \
    (resultIN)->elt_pd = (pdIN); \
    (resultIN)->elt_rep = (repIN); \
    (resultIN)->ro_params = (ro_paramsIN);\
  } while (0)

#define PDCI_MK_LINEAR_NODE(resultIN, padsIN, mIN,pdIN,repIN, ro_paramsIN, whatfn) \
  do {  \
    if (!(resultIN = PDCI_NEW_LINEAR_NODE(padsIN))) { \
      failwith("PADS/Galax ALLOC_ERROR: in " whatfn); \
    } \
    PDCI_INIT_LINEAR_NODE(resultIN,mIN,pdIN,repIN, ro_paramsIN); \
  } while (0)


// ======================================================================
// Function Headers
// ======================================================================


#endif /*   __LINEAR_NODE_H__    */
