#define DEF_INPUT_FILE "../../data/ptime_explicit"
#define WSPACE_OK 1
#define PADS_TY(suf) threetimes ## suf
#include "ptime_explicit.h"
#define TIME_OUT_FMT "default_time_explicit_out_fmt:%H:%M:%S"
#include "template/read_orig_write_xml.h"
