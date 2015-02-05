#include "ai.h"
#define PADS_TY(suf) http_clf_t ## suf
#define IO_DISC_MK P_nlrec_make(0)

#define DATE_OUT_FMT "%D:%T"
#define DELIMS "| "
#include "template/read_format.h"
