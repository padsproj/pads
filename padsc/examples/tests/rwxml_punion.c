#define DEF_INPUT_FILE "../../data/punion"

#define PADS_TY(suf) test2 ## suf

#define READ_MASK (P_CheckAndSet|P_DbgRead)

#include "punion.h"
#include "template/read_orig_write_xml.h"

