#define PADS_TY(suf) dns_msg ## suf
#define IO_DISC_MK P_norec_noseek_make(0)
#define COPY_STRINGS 1
#define MAX_RECS 4
#include "dns.h"
#include "template/read_write.h"
