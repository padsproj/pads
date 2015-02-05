#define IO_DISC_MK P_nlrec_noseek_make(0)
#define COPY_STRINGS 1
#define PADS_TY(suf) entry_t ## suf
#define TRACE 1

#define EXTRA_DECLS int allocated, deallocated, moved
#define EXTRA_BEGIN_CODE do { \
  allocated = 0;  \
  deallocated = 0; \
  moved = 0; \
} while (0)

#define EXTRA_GOOD_READ_CODE do { \
  if (rep->old_address.tag == nil) {allocated += rep->numAlloced;} \
  else if (rep->new_address.tag == nil) {deallocated += rep->numAlloced;}\
  else {moved += rep->numAlloced;}\
    error(2, "current alloc counts: allocated= %d  deallocated= %d, moved = %d, number = %d", allocated, deallocated, moved, rep->numAlloced); \
} while (0)

#define EXTRA_DONE_CODE do { \
  error(2, "alloc counts: allocated= %d  deallocated= %d, moved = %d", allocated, deallocated, moved); \
} while (0)

#include "memTrace.h"
#include "template/accum_report.h"
