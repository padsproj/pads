#define DEF_INPUT_FILE "../../data/punion"
#define EXTRA_GOOD_READ_CODE do { \
  error(2, "test2_read returned: id %s", test2_tag2str(rep->tag)); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "test2_read returned: error"); \
} while (0)

#define PADS_TY(suf) test2 ## suf

#include "punion.h"
#include "template/accum_report.h"

