/*
 * public API, galax-pads
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PGLX_H__
#define __PGLX_H__

/* generic calls from galax to pads */

#include "pads_dm.h"  /* Need Pads-Galax IDL defns */

/*
 * XXX TEMPORARY:
 */
void walk_children(void *n);
void print_children(void *n, int indent);

nodeRep      PGLX_generic_kth_child         (nodeRep ocaml_n, childIndex idx);
nodeRep      PGLX_generic_kth_child_named   (nodeRep ocaml_n, childIndex idx, const char *name);

nodeRep      PGLX_generic_parent      (nodeRep ocaml_n);
item         PGLX_generic_typed_value (nodeRep ocaml_n);
const char*  PGLX_generic_string_value(nodeRep ocaml_n);
const char*  PGLX_generic_name        (nodeRep ocaml_n);
const char*  PGLX_generic_kind        (nodeRep ocaml_n);
padsNID      PGLX_generic_get_id      (nodeRep ocaml_n);

void        PGLX_node_free           (nodeRep ocaml_n);     /* free node ocaml_n */
void        PGLX_nodelist_free       (nodeRepArray child_list); /* free a void ** list returned from generic_children */
/* Note: PGLX_nodelist_free does not free the child nodes, just the list that refers to them */

/* The Ptimestamp/xs:dateTime format for XML Schema: */
#define TIMESTAMP_OUT_FMT "%Y-%m-%dT%H:%M:%S"
#define TIMESTAMP_EXPLICIT_OUT_FMT "%Y-%m-%dT%H:%M:%S"

#endif  /*   __PGLX_H__   */
