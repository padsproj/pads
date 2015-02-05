
#ifdef PADS_BULK
#  define PADS_TY(suf) out_sum ## suf
#elif defined PADS_LINEAR
#  define PADS_HDR_TY(suf) summary_header_t ## suf
#  define PADS_TY(suf) entry_t ## suf
#else
#  error "Must set either PADS_BULK or PADS_LINEAR."
#endif

#include "dibbler_new.h"
#include "template/timed_read.h"
