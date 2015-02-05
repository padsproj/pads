// example invocation:  cat "../../data/struct2" | ./test_struct2

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "test_read returned: id %d  ts %d  nums %d ", rep->id, rep->ts, rep->nums); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "test_read returned: error"); \
} while (0)

#define PADS_TY(suf) test ## suf
#include "struct2.h"
#include "template/accum_report.h"

