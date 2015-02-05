#define DEF_INPUT_FILE "../../data/simple2"
#define IO_DISC_MK P_nlrec_make(0)
#define DATE_OUT_FMT "%m%d%y"
#define PADS_TY(suf) simple2_types ## suf
#define DELIMS "|,"
#include "simple2.h"
#include "template/read_format.h"
