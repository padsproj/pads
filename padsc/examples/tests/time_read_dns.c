#define DEF_INPUT_FILE "../../data/dns"


#ifdef PADS_BULK
#  define PADS_TY(suf) dns_msg_array ## suf
#elif defined PADS_LINEAR
#  define PADS_TY(suf) dns_msg ## suf
#else
#  error "Must set either PADS_BULK or PADS_LINEAR."
#endif

#define IO_DISC_MK P_norec_noseek_make(0)
#define COPY_STRINGS 1
#include "dns.h"
#include "template/timed_read.h"
