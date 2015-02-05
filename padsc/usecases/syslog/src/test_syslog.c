#define DEF_INPUT_FILE "../../data/syslog"
#define IO_DISC_MK P_nlrec_make(0)
#define PADS_TY(suf) syslogs ## suf
#include "syslog.h"
#include "template/accum_report.h"
