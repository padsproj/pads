/*
 * Helpers
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __HELPERS_H__
#define __HELPERS_H__

#include "pads-internal.h"
#include "cmdline.h"

/* -------------------------------------------------------------------------------- */

void describe_params(Sfio_t *io, CM_params *ps);
void describe_query(Sfio_t *io, CM_query *q);
void describe_queries(Sfio_t *io, CM_queries *qs);
void describe_c_cookie(Sfio_t *io, CM_c_cookie *c);
void describe_arm(Sfio_t *io, CM_arm *a);
void describe_s_cookie(Sfio_t *io, CM_s_cookie *s);
void describe_cookie(Sfio_t *io, CM_cspec *cspec);

size_t out_sz_cookie(CM_cspec *cspec);

Perror_t rw_c_cookie(CM_t *cm, CM_c_cookie *c, Pbyte *begin, Pbyte *end);
Perror_t rw_s_cookie(CM_t *cm, CM_s_cookie *c, Pbyte *begin, Pbyte *end);

/* -------------------------------------------------------------------------------- */

#define USAGE \
"\n  Usage: cmonster [options] -d dspec -c cspec" \
"\n      dspec   : specifies an IO discipline and its creation params" \
"\n      cpsec   : a cookie specification that selects one or more data items" \
"\n  " \
"\n  Where valid options are:" \
"\n      -h         : print detailed help message to stdout exit" \
"\n      -i inf     : where to read data input       (default /dev/stdin)" \
"\n      -o outf    : where to write the data output (default /dev/stdout)" \
"\n      -e errf    : where to append error messages (default /dev/stderr)" \
"\n      -p padslf  : where to write PADSL description of output format" \
"\n                   (default is not to write the PADSL description)" \
"\n  " \
"\n  Specify inf using using '/dev/stdin' or a file pathname." \
"\n  Specify outf, errf, or padslf using '/dev/stdout', '/dev/stderr', or a file pathname." \
"\n\n"

#define DETAILED_USAGE \
USAGE \
  "  cmonster reads a record at a time using the specified IO discipline." \
"\n  For each record that matches cspec, cspec is used to read" \
"\n  one or more input data items and write corresponding data items to an" \
"\n  output record.  Each output data item is written in a canonical" \
"\n  (machine-independent) form." \
"\n  " \
"\n  One can learn about the format of the canonical output record for" \
"\n  a given cspec by specify the -p option, which generates a PADSL" \
"\n  description of the output format.  If -p is present then no" \
"\n  record processing occurs." \
"\n  " \
"\n  -----" \
"\n  ispec" \
"\n  -----" \
"\n    An ispec specifies an IO discipline and its creation params." \
"\n    The set of supported IO disciplines (with example params) is as follows:" \
"\n  " \
"\n      fwrec(:0,24,1:)" \
"\n          Specifies a fixed width record with 0 'leader' bytes," \
"\n          24 data bytes, and 1 'trailer' byte (25 bytes total)." \
"\n  " \
"\n      fwrec_noseek(:0,24,1:)" \
"\n          Like fwrec, but the stream is assumed to not support seeking." \
"\n  " \
"\n      nlrec(:0:)" \
"\n          Specifies newline(ASCII)-terminated records." \
"\n          The argument is a block size hint (see below). " \
"\n  " \
"\n      nlrec_noseek(:0:)" \
"\n          Like nlrec, but the stream is assumed to not support seeking." \
"\n  " \
"\n      ctrec(:10,0:)" \
"\n          Specifies character(ASCII)-terminated records.  The first argument" \
"\n          is the term. character, the second is a block size hint (see below)." \
"\n          In this case character 10 is a newline, so this ispec is equivalent" \
"\n          to nlrec(:0:)" \
"\n  " \
"\n      ctrec_noseek(:10,0:)" \
"\n          Like ctrec, but the stream is assumed to not support seeking." \
"\n  " \
"\n      vlrec(:0,0:)" \
"\n          Specifies an IBM-style variable-length record format.  The first argument" \
"\n          specifies whether the records are grouped into blocks (i.e., whether the input" \
"\n          is variable-length blocks of variable-length records). 0 indicates non-blocked." \
"\n          The second argument is a hint as to the average record length." \
"\n          Use of 0 indicates 'no hint.'" \
"\n  " \
"\n      vlrec_noseek(:0,0:)" \
"\n          Like vlrec, but the stream is assumed to not support seeking." \
"\n  " \
"\n  " \
"\n    Block size hint: a block size hint suggests an appropriate block size for the IO" \
"\n    discipline to use 'under the covers' when doing IO.  Use of 0 indicates 'no hint.'" \
"\n    The hint may be ignored. " \
"\n  " \
"\n  -----" \
"\n  cspec" \
"\n  -----" \
"\n    Legal switch tags must fit in a Pint32, and the switch query must use" \
"\n    a character type (Pchar, Pa_char, Pe_char) or a numeric type whose in-memory" \
"\n    representation is Pint32 (Pint32_FW, Pa_int32_FW, Pe_int32_FW, Pb_int32," \
"\n    Pebc_int32, Pbcd_int32, Psbl_int32, Psbh_int32)." \
"\n  " \
"\n    TODO: describe cspec details" \
"\n\n"

/* -------------------------------------------------------------------------------- */

#endif /*  !__HELPERS_H__  */
