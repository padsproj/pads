#define DEF_INPUT_FILE "../../data/array_ended"

#define EXTRA_GOOD_READ_CODE do { \
      error(2, "entry_read returned array evens of length: %d", rep->evens.length); \
      error(2, "entry_read returned array odds  of length: %d", rep->odds.length); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
      error(2, "entry_read returned: error"); \
} while (0)

#define PADS_TY(suf) entry ## suf

#include "array_ended.h"
#include "template/accum_report.h"
