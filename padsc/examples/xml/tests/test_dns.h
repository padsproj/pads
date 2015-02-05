#define DEF_INPUT_FILE "../../../data/dns.1"
#define DEF_QUERY_FILE "../../queries/dot.xq"
#define MAX_RECS 1
#define PADS_TY_ dns_msg_array
#define PADS_TY(suf) dns_msg_array ## suf
#define PPADS_TY(pref) pref ## dns_msg_array
#define IO_DISC_MK P_norec_noseek_make(0)
#define COPY_STRINGS 1

#include "dns.h"
