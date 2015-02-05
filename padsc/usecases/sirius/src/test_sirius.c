#define DEF_INPUT_FILE "../../data/sirius"
#define PADS_HDR_TY(suf) summary_header_t ## suf
#define PADS_TY(suf) entry_t ## suf
#define IO_DISC_MK P_nlrec_make(0)
#include "sirius.h"

#include "template/accum_report.h"
