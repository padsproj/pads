#define DEF_INPUT_FILE "../../data/simple"
#define IO_DISC_MK P_nlrec_make(0)
#define DATE_OUT_FMT "%m%d%y"
#define PADS_TY(suf) simple_types ## suf
#define DELIMS "|,"
#include "simple.h"
#include "template/read_format.h"
