#include "out_macros.h"

#ifndef PDCI_MacroArg2String
#define PDCI_MacroArg2String(s) #s
#endif

#ifndef READ_MASK
#define READ_MASK P_CheckAndSet
#endif

#ifndef EXTRA_READ_ARGS
#  define EXTRA_READ_ARGS
#endif

#ifndef EXTRA_HDR_READ_ARGS
#  define EXTRA_HDR_READ_ARGS
#endif

#ifndef DEF_INPUT_FILE
#  define DEF_INPUT_FILE "/dev/stdin"
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

  PADS_TY( )       *rep_ptr = &rep;
  PADS_TY(_pd)     *pd_ptr = &pd;
  PADS_TY(_m)      *m_ptr = &m;

#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
  char             *inName  = 0;

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

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }
  if (P_ERR == P_io_fopen(pads, inName)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }
  if (P_ERR == PADS_TY(_init)(pads, &rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == PADS_TY(_pd_init)(pads, &pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_TY(_m_init)(pads, &m, READ_MASK);

#ifdef PADS_HDR_TY
  if (P_ERR == PADS_HDR_TY(_init)(pads, &hdr_rep)) {
    error(ERROR_FATAL, "*** header representation initialization failed ***");
  }
  if (P_ERR == PADS_HDR_TY(_pd_init)(pads, &hdr_pd)) {
    error(ERROR_FATAL, "*** header parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_HDR_TY(_m_init)(pads, &hdr_m, P_CheckAndSet);
#endif /* PADS_HDR_TY */

#ifdef PADS_HDR_TY
  /*
   * Try to read header
   */
  if (!P_io_at_eof(pads)) {
    if (P_OK != PADS_HDR_TY(_read)(pads, &hdr_m, &hdr_pd, &hdr_rep EXTRA_HDR_READ_ARGS )) {
      error(ERROR_FATAL, "header read returned error");
    }
  }
#endif /* PADS_HDR_TY */

  DO_INIT(pads, m_ptr);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads) && (MAX_RECS == 0 || num_recs++ < MAX_RECS)) {
    P_io_getPos(pads, &bpos, 0);
    PADS_TY(_read)(pads, &m, &pd, &rep EXTRA_READ_ARGS);
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(ERROR_FATAL, "*** read loop stuck: read call did not advance IO cursor");
    }
    if (DO_SELECT(pads, pd_ptr, rep_ptr)) {
      DO_ACT(pads, pd_ptr, rep_ptr);
    }
  }

  DO_DONE(pads);

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
  return 0;
}
