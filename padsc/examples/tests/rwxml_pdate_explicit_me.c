#define DEF_INPUT_FILE "../../data/pdate_explicit_me"
#define WSPACE_OK 1
#define PADS_TY(suf) threedates ## suf
#include "pdate_explicit_me.h"
#define DATE_OUT_FMT "default_date_out_fmt:%Y-%m-%d"
#define DATE_EXPLICIT_OUT_FMT "default_date_explicit_out_fmt:%Y-%m-%d"
#include "template/read_orig_write_xml.h"
