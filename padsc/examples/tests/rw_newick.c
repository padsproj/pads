#define PADS_TY(suf) tree ## suf
#define BASE_MASK_TY _tree_m
#define CUSTOM_MASK_CODE \
  P_DynamicMaskInit(m, PADS_TY(_m), BASE_MASK_TY, READ_MASK,m->branches.element.interior);
#define MAX_RECS 1
#define DEF_INPUT_FILE "../../data/newick"

#include "newick.h"
#include "template/read_write.h"
