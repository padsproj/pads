#define INIT_N 14 
#define INIT_B 2 
#define INIT_M 1024 * 1024 
#define INIT_ISE 0 
#define INIT_ISO 1 
#define INIT_n 1 
#define INIT_e .1 
#define INIT_scale 100000000 
#define INIT_maxPortion 3 
/*
#define EXTRA_INIT_CODE \
Perror_t myFromFn (Pfloat64 f, Pint16 *v)  { *v = (Pint16)f + 100; return P_OK; } \
Perror_t myToFn   (Pint16 *v, Pfloat64 *f) { *f = (Pfloat64)(*v); return P_OK; } \
h.foo.fromFloat = (P_fromFloat_fn)myFromFn; \
h.foo.toFloat = (P_toFloat_fn)myToFn;
*/
#define DEF_INPUT_FILE "../../data/ai"
#define PADS_TY(suf) http_clf_t ## suf
#include "ai.h"
#include "template/hist_report.h"

// Test programe to build histograms.

////////////////////////////////////////////////////////////////////////////////

