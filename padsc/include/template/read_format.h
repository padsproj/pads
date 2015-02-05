#include "out_macros.h"

#ifndef PDCI_MacroArg2String
#define PDCI_MacroArg2String(s) #s
#endif

#ifndef READ_MASK
#define READ_MASK P_CheckAndSet
#endif

#ifndef FMT_MASK
#define FMT_MASK P_Write
#endif

#ifndef MASK_MOD
#define MASK_MOD
#endif

#ifndef FMT_DELIMS
#define FMT_DELIMS "|,:"
#endif

#ifndef EXTRA_READ_ARGS
#  define EXTRA_READ_ARGS
#endif

#ifndef EXTRA_HDR_READ_ARGS
#  define EXTRA_HDR_READ_ARGS
#endif

#ifndef EXTRA_TRL_READ_ARGS
#  define EXTRA_TRL_READ_ARGS
#endif

#ifndef DEF_INPUT_FILE
#  define DEF_INPUT_FILE "/dev/stdin"
#endif

#ifndef DEF_OUTPUT_FILE
#  define DEF_OUTPUT_FILE "/dev/stdout"
#endif

#ifndef MAX_RECS
#  define MAX_RECS 0
#endif

Puint64 num_recs = 0;

int main(int argc, char** argv) {
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Ppos_t            bpos, epos;
  PADS_TY( )        rep;
  PADS_TY(_pd)      pd;
  PADS_TY(_m)       m;
  int               requestedOut;
  Perror_t          err;
#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
#ifdef PADS_TRL_TY
  PADS_TRL_TY( )    trl_rep;
  PADS_TRL_TY(_pd)  trl_pd;
  PADS_TRL_TY(_m)   trl_m;
#endif /* PADS_TRL_TY */
  Sfio_t           *io;
  char             *inName  = 0;
  char             *outName = 0;
#ifdef FMT_ERROR_CASES
  int               fmt_error_cases = 1;
#else
  int               fmt_error_cases = 0;
#endif

#ifdef PRE_LIT_LWS
  my_disc.pre_lit_lws = PRE_LIT_LWS;
#endif
#ifdef WSPACE_OK
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
#endif
#ifdef COPY_STRINGS
  my_disc.copy_strings = 1;
#endif
#ifdef IN_TIME_ZONE
  my_disc.in_time_zone = IN_TIME_ZONE;
  error(0, "Note: set my_disc.in_time_zone to \"%s\"\n", IN_TIME_ZONE);
#endif
#ifdef OUT_TIME_ZONE
  my_disc.out_time_zone = OUT_TIME_ZONE;
  error(0, "Note: set my_disc.out_time_zone to \"%s\"\n", OUT_TIME_ZONE);
#endif

#ifdef TIMESTAMP_IN_FMT
  my_disc.in_formats.timestamp = TIMESTAMP_IN_FMT;
#endif
#ifdef DATE_IN_FMT
  my_disc.in_formats.date = DATE_IN_FMT;
#endif
#ifdef TIME_IN_FMT
  my_disc.in_formats.time = TIME_IN_FMT;
#endif

#ifdef TIMESTAMP_EXPLICIT_OUT_FMT
  my_disc.out_formats.timestamp_explicit = TIMESTAMP_EXPLICIT_OUT_FMT;
#endif
#ifdef TIMESTAMP_OUT_FMT
  my_disc.out_formats.timestamp = TIMESTAMP_OUT_FMT;
#endif
#ifdef DATE_EXPLICIT_OUT_FMT
  my_disc.out_formats.date_explicit = DATE_EXPLICIT_OUT_FMT;
#endif
#ifdef DATE_OUT_FMT
  my_disc.out_formats.date = DATE_OUT_FMT;
#endif
#ifdef TIME_EXPLICIT_OUT_FMT
  my_disc.out_formats.time_explicit = TIME_EXPLICIT_OUT_FMT;
#endif
#ifdef TIME_OUT_FMT
  my_disc.out_formats.time = TIME_OUT_FMT;
#endif

#ifdef IO_DISC_MK
  if (!(io_disc = IO_DISC_MK)) {
    error(ERROR_FATAL, "IO discipline make call [ " PDCI_MacroArg2String(IO_DISC_MK) " ] failed");
  }
#ifdef IO_DISC_DESCR
  else { 
    error(0, "Installed " IO_DISC_DESCR);
  }
#endif
#endif

  if (argc >= 2) {
    inName = argv[1];
  } else {
    inName = DEF_INPUT_FILE;
  }
  error(0, "Input file = %s\n", inName);
  if (argc == 3) {
    outName = argv[2];
  } else {
    outName = DEF_OUTPUT_FILE;
  }
  error(0, "Output file = %s\n", outName);

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }
  if (P_ERR == P_io_fopen(pads, inName)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }
  if (!(io = P_fopen(outName, "w"))) {
    P_SYSERR1(pads->disc, "Failed to open output file \"%s\" for writing", outName);
  }
  if (P_ERR == PADS_TY(_init)(pads, &rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == PADS_TY(_pd_init)(pads, &pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_TY(_m_init)(pads, &m, READ_MASK|FMT_MASK);

  MASK_MOD

#ifdef PADS_HDR_TY
  if (P_ERR == PADS_HDR_TY(_init)(pads, &hdr_rep)) {
    error(ERROR_FATAL, "*** header representation initialization failed ***");
  }
  if (P_ERR == PADS_HDR_TY(_pd_init)(pads, &hdr_pd)) {
    error(ERROR_FATAL, "*** header parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_HDR_TY(_m_init)(pads, &hdr_m, P_CheckAndSet|FMT_MASK);
#endif /* PADS_HDR_TY */

#ifdef PADS_TRL_TY
  if (P_ERR == PADS_TRL_TY(_init)(pads, &trl_rep)) {
    error(ERROR_FATAL, "*** trailer representation initialization failed ***");
  }
  if (P_ERR == PADS_TRL_TY(_pd_init)(pads, &trl_pd)) {
    error(ERROR_FATAL, "*** trailer parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_TRL_TY(_m_init)(pads, &trl_m, P_CheckAndSet|FMT_MASK);
#endif /* PADS_HDR_TY */



#if defined(FMT_OVERRIDE_TY1) && defined(FMT_OVERRIDE_FN1)
  if (!pads->disc->fmt_fn_map) {
    pads->disc->fmt_fn_map = Pfmt_fn_map_create(pads);
  }
  error(0, "Installing fmt override function %s for type %s",
	PDCI_MacroArg2String(FMT_OVERRIDE_TY1), FMT_OVERRIDE_TY1);
  P_set_fmt_fn(pads, pads->disc->fmt_fn_map, FMT_OVERRIDE_TY1, FMT_OVERRIDE_FN1);
#endif

#if defined(FMT_OVERRIDE_TY2) && defined(FMT_OVERRIDE_FN2)
  if (!pads->disc->fmt_fn_map) {
    pads->disc->fmt_fn_map = Pfmt_fn_map_create(pads);
  }
  error(0, "Installing fmt override function %s for type %s",
	PDCI_MacroArg2String(FMT_OVERRIDE_TY2), FMT_OVERRIDE_TY2);
  P_set_fmt_fn(pads, pads->disc->fmt_fn_map, FMT_OVERRIDE_TY2, FMT_OVERRIDE_FN2);
#endif

#ifdef PADS_HDR_TY
  /*
   * Try to read header
   */
  if (!P_io_at_eof(pads)) {
    if (P_OK != PADS_HDR_TY(_read)(pads, &hdr_m, &hdr_pd, &hdr_rep EXTRA_HDR_READ_ARGS )) {
      error(ERROR_FATAL, "header read returned error");
    }
    if (P_ERR == PADS_HDR_TY(_fmt2io)(pads, io, &requestedOut, DELIMS, &hdr_m,&hdr_pd, &hdr_rep  EXTRA_HDR_READ_ARGS )) {
      error(ERROR_FATAL, "*** IO error during header write");
    }
  }
#endif /* PADS_HDR_TY */

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads) && (MAX_RECS == 0 || num_recs++ < MAX_RECS)) {
    P_io_getPos(pads, &bpos, 0);
#ifdef PADS_TRL_TY
    P_io_checkpoint(pads,1); /* add error checking */
#endif
    err = PADS_TY(_read)(pads, &m, &pd, &rep EXTRA_READ_ARGS );
    if (err == P_ERR) {
#ifdef PADS_TRL_TY
      P_io_restore(pads);  /* add error checking */
      break;
#endif
#ifdef EXTRA_BAD_READ_CODE
      EXTRA_BAD_READ_CODE;
#else
      error(2, "read returned error");
#endif
    }
#ifdef PADS_TRL_TY
    P_io_commit(pads);
#endif
    if ((err == P_OK || fmt_error_cases) && (P_ERR == PADS_TY(_fmt2io)(pads, io, &requestedOut, DELIMS, &m, &pd, &rep EXTRA_READ_ARGS ))) {
      error(ERROR_FATAL, "*** IO error during format");
    }
#ifdef EXTRA_GOOD_READ_CODE
    if (err == P_OK) {
      EXTRA_GOOD_READ_CODE;
    }
#endif
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(ERROR_FATAL, "*** read loop stuck: read call did not advance IO cursor");
    }
  }
#ifdef PADS_TRL_TY
  /*
   * Try to read trailer
   */
  if (!P_io_at_eof(pads)) {
    if (P_OK != PADS_TRL_TY(_read)(pads, &trl_m, &trl_pd, &trl_rep EXTRA_TRL_READ_ARGS )) {
      error(ERROR_FATAL, "trailer read returned error");
    }
    if (P_ERR == PADS_TRL_TY(_fmt2io)(pads, io, &requestedOut, DELIMS, &trl_m,&trl_pd, &trl_rep  EXTRA_TRL_READ_ARGS )) {
      error(ERROR_FATAL, "*** IO error during trailer write");
    }
  }
#endif /* PADS_TRL_TY */

  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }
  if (P_ERR == PADS_TY(_cleanup)(pads, &rep)) {
    error(ERROR_FATAL, "** representation cleanup failed **");
  }
  if (P_ERR == PADS_TY(_pd_cleanup)(pads, &pd)) {
    error(ERROR_FATAL, "** parse descriptor cleanup failed **");
  }
  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }
  sfclose(io);
  return 0;
}
