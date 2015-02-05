#define DEF_INPUT_FILE "data/Hello.class"    /* Default data location             */
#define PADS_TY(suf) ClassFile ## suf /* Name of record type = entry_t     */
#define IO_DISC_MK P_norec_make(0)    /* There are no records   */
#define MAX_RECS 1
#include "java_class.h"                 /* Header file for generated library */
#include "template/accum_report.h"    /* Accumulator template program      */
