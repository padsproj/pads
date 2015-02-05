#define DEF_INPUT_FILE "../../data/ptimestamp_explicit"
#define WSPACE_OK 1
#define PADS_TY(suf) threetimestamps ## suf
#include "ptimestamp_explicit.h"
#define TIMESTAMP_OUT_FMT "default_timestamp_out_fmt:%K"
#define TIMESTAMP_EXPLICIT_OUT_FMT "default_timestamp_explicit_out_fmt:%K"
#include "template/read_orig_write_xml.h"
