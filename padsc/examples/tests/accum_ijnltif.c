#define MAX_RECS 4
// Note:  max data in record is 3092 bytes
#define DEF_INPUT_FILE "../../data/injltif"
#define PADS_TY_STR "injltif"
#define IO_DISC_MK P_vlrec_noseek_make(1, 3100)
#define PADS_HDR_TY(suf) cpy_ijnltifh ## suf
#define PADS_TY(suf) d_or_t ## suf
#include "ijnltif.h"
#include "template/accum_report_xml.h"
