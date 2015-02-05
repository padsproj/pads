// example invocation:  cat "../../data/typedef" | ./test_typedef

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "pn_t_read returned: id %lld", rep); \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "pn_t_read returned: error"); \
} while (0)


#define PADS_TY(suf) pn_t ## suf
#define EXTRA_READ_ARGS , 0, 9999999999LL

#include "typedef.h"
#include "template/accum_report.h"

