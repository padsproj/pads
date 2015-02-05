// Set the output time zone to the one where the ai data (web log) was
// recorded (the data file has dates with a trailing -0700).  This
// means timestamp output will be consistent with the timestamps in the data.

#define OUT_TIME_ZONE "-0700"
#define DEF_INPUT_FILE "../../data/ai"

#ifdef PADS_BULK
#  define PADS_TY(suf) log_t ## suf
#elif defined PADS_LINEAR
#  define PADS_TY(suf) http_clf_t ## suf
#else
#  error "Must set either PADS_BULK or PADS_LINEAR."
#endif

#include "ai.h"
#include "template/timed_read.h"
