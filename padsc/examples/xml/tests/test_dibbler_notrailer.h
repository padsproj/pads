#define DEF_INPUT_FILE "../../../data/dibbler.1"
#define DEF_QUERY_FILE "../../queries/dot.xq"

#define PADS_HDR_TY_ out_sum_header
#define PADS_HDR_TY(suf) out_sum_header ## suf
#define PPADS_HDR_TY(pref) out_sum_header ## myfile

#define PADS_TY_ entries_t
#define PADS_TY(suf) entries_t ## suf
#define PPADS_TY(pref) entries_t ## myfile

#include "dibbler_notrailer.h"
