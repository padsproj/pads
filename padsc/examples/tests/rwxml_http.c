#define IO_DISC_MK P_norec_noseek_make(0)
#define DEF_INPUT_FILE "../../data/http/reply01-mod"
#define PADS_TY(suf) HTTP_message_t ## suf
#include "http.h"
#include "template/read_orig_write_xml.h"
