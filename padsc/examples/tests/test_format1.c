#define DEF_INPUT_FILE "../../data/format1"

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "test_read returned: id %d  ts %d", rep->id, rep->ts); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "test_read returned: error"); \
} while (0)

#define PADS_TY(suf) test ## suf
#define WSPACE_OK

#include "format1.h"
#include "template/accum_report.h"

