#define DEF_INPUT_FILE "../../data/simple.txt"
#define DEF_QUERY_FILE "../../queries/dot.xq"
#define PADS_TY(suf) _tree ## suf
/* #define IO_DISC_MK P_nlrec_make(0) */
#define EXTRA_BAD_READ_CODE printf("Tree read error.\n");
#define CUSTOM_MASK_CODE \
do{\
  PADS_TY(_m_init)(pads, &m, READ_MASK);\
  m.branches.element.interior = &m;\
}while(0)\

#include "newick.h"
#include "template/pglx_bulk_query.h"
