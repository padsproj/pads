#define IO_DISC_MK P_norec_noseek_make(0)
#define DEF_INPUT_FILE "../../data/message-header-01"
#define PADS_TY(suf) message_header_t ## suf
#include "message_header.h"
#include "template/read_orig_write_xml.h"
