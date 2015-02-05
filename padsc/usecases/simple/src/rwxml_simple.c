#define DEF_INPUT_FILE "../../data/simple"
#define IO_DISC_MK P_nlrec_make(0)
#define PADS_TY(suf) simple_types ## suf
#include "simple.h"
#define DATE_OUT_FMT "%K"
#include "template/read_orig_write_xml.h"
