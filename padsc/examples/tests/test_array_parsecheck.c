#define DEF_INPUT_FILE "../../data/array_parsecheck"

#define EXTRA_GOOD_READ_CODE do { \
  error(2, "seq_read returned array of length: %d", rep->seq.length); \
  if (is_seq_t(&(rep->seq))) {  \
     error(2, "seq_read reported no errors and passed predicate test.");  \
  } else {  error(2, "seq_read reported no errors but failed predicate test.");  } \
} while (0)

#define EXTRA_BAD_READ_CODE do { \
  error(2, "entry_read returned: error"); \
  if (is_seq_t(&(rep->seq))) {  \
     error(2, "seq_read reported errors but passed predicate test.");  \
  } else {  error(2, "seq_read reported errors and failed predicate test.");  } \
} while (0)


#define PADS_TY(suf) entry ## suf


#include "array_parsecheck.h"
#include "template/accum_report.h"

