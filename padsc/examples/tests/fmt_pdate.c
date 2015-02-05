#define DEF_INPUT_FILE "../../data/pdate"

//#define MASK_MOD   P_Dont_Write(m.compoundLevel);
//#define MASK_MOD   P_Dont_Write(m.header.c); P_Do_WriteVoid(m.header.c); P_Dont_Write(m.header.ts); P_Do_WriteVoid(m.header.ts);
//#define MASK_MOD   P_Dont_Write(m.header.compoundLevel);

//#define DATE_OUT_FMT "%K"
#define DATE_OUT_FMT "%K %z (%Z)"

//XXX just for testing purposes, set up a time zone difference
//#define IN_TIME_ZONE "-0300"
//#define OUT_TIME_ZONE "EDT"
#define OUT_TIME_ZONE "-0100"

#define WSPACE_OK 1
#define PADS_TY(suf) threedates ## suf
#define DELIMS "|,"
#include "pdate.h"
#include "template/read_format.h"
