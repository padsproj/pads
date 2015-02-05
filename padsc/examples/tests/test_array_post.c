#define DEF_INPUT_FILE "../../data/array_post"

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "intList_read returned array of length: %d", rep->length); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "intList_read returned: error"); \
} while (0)

#define PADS_TY(suf) intList ## suf

#include "array_post.h"
#include "template/accum_report.h"

