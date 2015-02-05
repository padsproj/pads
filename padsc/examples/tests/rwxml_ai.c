// Set the output time zone to the one where the ai data (web log) was
// recorded (the data file has dates with a trailing -0700).  This
// means timestamp output will be consistent with the timestamps in the data.

#define OUT_TIME_ZONE "-0700"

#define DEF_INPUT_FILE "../../data/ai"
#define PADS_TY(suf) http_clf_t ## suf
#include "ai.h"
#include "template/read_orig_write_xml.h"
