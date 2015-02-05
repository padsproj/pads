#define DEF_INPUT_FILE "../../data/syslog"
#define IO_DISC_MK P_nlrec_make(0)
#define DATE_OUT_FMT "%m%d%y"
#define PADS_TY(suf) syslogs ## suf
#define DELIMS "|,"
#include "syslog.h"
#include "template/read_format.h"
