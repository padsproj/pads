/*
 * Decls for impl of cmonster ('cookie monster') command
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __CMONSTER_H__
#define __CMONSTER_H__

#include "pads-internal.h"
#include "cmdline.h"

/* -------------------------------------------------------------------------------- */
/* types */

typedef struct CM_s           CM_t;

/* A cmonster handle, type CM_t: */
struct CM_s {
  P_t           *pads;
  Vmalloc_t       *vm;
  Sfio_t          *inf;
  Sfio_t          *outf;
  Sfio_t          *errf;
  Sfio_t          *padslf;
  size_t           outbuf_sz;
  Pbyte        *outbuf;
  Pbyte        *outbuf_end;
  Pbyte        *outbuf_cursor; /* cursor always in range [outbuf, outbuf_end] */
  Pstring       tmp1;          /* used by string rw/sval functions */
};

extern CM_t *error_cm; /* cm handle for parser routines to use for error reporting */

/* signatures for:
 *    read-write function
 *    switch-val function
 *    calculate-in-sz function
 *    calculate-out-sz function
 */

typedef Perror_t (*CM_rw_fn)    (CM_t *cm, CM_query *qy, Pbyte *begin, Pbyte *end);
typedef Perror_t (*CM_sval_fn)  (CM_t *cm, CM_query *qy, Pbyte *begin, Pbyte *end, Pint32 *res_out);

typedef size_t      (*CM_in_sz_fn) (CM_query *qy);
typedef size_t      (*CM_out_sz_fn)(CM_query *qy);

/* A typemap entry, type CM_tmentry_t: */
struct CM_tmentry_s {
  const char      *tname;
  CM_rw_fn         rw_fn;
  CM_sval_fn       sval_fn;
  CM_in_sz_fn      in_sz_fn;
  CM_out_sz_fn     out_sz_fn;
  int              num_params;
};

/* -------------------------------------------------------------------------------- */
/* Static state */
extern CM_tmentry_t tmap[];

/* -------------------------------------------------------------------------------- */
/* io discipline helpers */

/* returns -1 on usage error, 0 otherwise */
/* (*iodisc_out) set to result of iodisc open call (may be NULL) */
int CM_open_iodisc(CM_t *cm, CM_dspec *dspec, Pio_disc_t **iodisc_out);

/* -------------------------------------------------------------------------------- */
/* helper macros */

/* the param signature of a rw_fn: */ 
#define CM_RW_FN_PARAMS \
  CM_t *cm, CM_query *qy, Pbyte *begin, Pbyte *end  

/* rw_fn function name for ty, e.g., CM_RW_FN_NM(a_int8) */
#define CM_RW_FN_NM(ty) \
CM_ ## ty ## _rw

/* rw_fn function decl for ty, e.g., CM_RW_FN_DECL(a_int8) */
#define CM_RW_FN_DECL(ty) \
Perror_t CM_RW_FN_NM(ty) (CM_RW_FN_PARAMS)

/* the param signature of a sval_fn: */ 
#define CM_SVAL_FN_PARAMS \
  CM_t *cm, CM_query *qy, Pbyte *begin, Pbyte *end, Pint32 *res_out  

/* sval_fn function name for ty, e.g., CM_SVAL_FN_NM(a_int8) */
#define CM_SVAL_FN_NM(ty) \
CM_ ## ty ## _sval

/* sval_fn function decl for ty, e.g., CM_SVAL_FN_DECL(a_int32) */
#define CM_SVAL_FN_DECL(ty) \
Perror_t CM_SVAL_FN_NM(ty) (CM_SVAL_FN_PARAMS)

/* out_sz_fn function name for ty, e.g., CM_OUT_SZ_FN_NM(a_int8) */
#define CM_OUT_SZ_FN_NM(ty) \
CM_ ## ty ## _out_sz

/* -------------------------------------------------------------------------------- */

#endif  /* __CMONSTER_H__  */

