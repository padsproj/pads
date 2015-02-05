// example invocation: cat "../../data/record_enum" | ./test_record_enum

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "orderStates_read returned: id %s", orderStates2str(rep)); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "orderStates_read returned: error"); \
} while (0)

#define PADS_TY(suf) orderStates ## suf

#include "record_enum.h"
#include "template/accum_report.h"

