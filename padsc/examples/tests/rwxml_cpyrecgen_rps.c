#define MAX_RECS 20
#define IO_DISC_MK P_fwrec_noseek_make(0, 450, 0)
#define PADS_TY(suf) cpy_rps ## suf
#include "cpyrecgen_rps.h"
#include "template/read_orig_write_xml.h"
