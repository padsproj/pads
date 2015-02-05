#define DEF_INPUT_FILE "../../data/array_pred"

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "entry_read returned array of length: %d", rep->seq.length); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "entry_read returned: error"); \
} while (0)

#define PADS_TY(suf) entry ## suf

#include "array_pred.h"
#include "template/accum_report.h"

