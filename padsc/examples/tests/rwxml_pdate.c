#define DEF_INPUT_FILE "../../data/pdate"
#define PADS_TY(suf) threedates ## suf
#include "pdate.h"
#define DATE_OUT_FMT "default_date_out_fmt:%K"
#include "template/read_orig_write_xml.h"
