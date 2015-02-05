#define DEF_INPUT_FILE "../../data/struct4"
#define WSPACE_OK 1

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "testtwo_read returned: id %d  ts %d  f %d ", rep.header.id, rep.header.ts, rep.f); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "testtwo_read returned: error"); \
} while (0)

#define PADS_TY(suf) testtwo ## suf
#define DELIMS ","
#include "struct4.h"
#include "template/read_format.h"

