#define DEF_INPUT_FILE "../../data/array_ended2"

#define EXTRA_GOOD_READ_CODE do { \
      error(2, "entry_read returned array first of length: %d", rep->first.length); \
      error(2, "entry_read returned array second  of length: %d", rep->second.length); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
      error(2, "entry_read returned: error"); \
} while (0)

#define PADS_TY(suf) entry ## suf
#include "array_ended2.h"
#include "template/accum_report.h"

