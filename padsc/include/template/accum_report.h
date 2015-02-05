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

#ifndef EXTRA_TRL_READ_ARGS
#  define EXTRA_TRL_READ_ARGS
#endif

#ifndef DEF_INPUT_FILE
#  define DEF_INPUT_FILE "/dev/stdin"
#endif

#ifndef MAX_RECS
#  define MAX_RECS 0
#endif

#include <stdlib.h>
#include <rbuf-internal.h>
Puint64 num_recs = 0;


int main(int argc, char** argv) {
  RMM_t            *rmm_zero;
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Ppos_t            bpos, epos;
  PADS_TY( )       *rep;
  PADS_TY(_pd)     *pd;
  PADS_TY(_m)      *m;
  PADS_TY(_acc)    *acc;
#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_TRL_TY */
#ifdef PADS_TRL_TY
  PADS_TRL_TY( )    trl_rep;
  PADS_TRL_TY(_pd)  trl_pd;
  PADS_TRL_TY(_m)   trl_m;
#endif /* PADS_TRL_TY */
  char             *fileName = 0;
#ifdef EXTRA_DECLS
  EXTRA_DECLS;
#endif

#ifdef PRE_LIT_LWS
  my_disc.pre_lit_lws = PRE_LIT_LWS;
#endif
#ifdef WSPACE_OK
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
#endif

  my_disc.copy_strings = 1;  /* strings should almost always be copied for accumulator programs */

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

  if (argc == 2) {
    fileName = argv[1];
  } else {
    fileName = DEF_INPUT_FILE;
  }
  error(0, "Data file = %s\n", fileName);

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }
  if (P_ERR == P_io_fopen(pads, fileName)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  /* allocate the main rep, pd, m, and acc in the heap */
  rmm_zero = P_rmm_zero(pads);
  rep  = (PADS_TY( )*)   RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY( )));
  pd   = (PADS_TY(_pd)*) RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY(_pd)));
  m    = (PADS_TY(_m)*)  RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY(_m)));
  acc  = (PADS_TY(_acc)*)RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY(_acc)));

  if (P_ERR == PADS_TY(_init)(pads, rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == PADS_TY(_pd_init)(pads, pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }
  if (P_ERR == PADS_TY(_acc_init)(pads, acc)) {
    error(ERROR_FATAL, "*** accumulator initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_TY(_m_init)(pads, m, READ_MASK);
#ifdef EXTRA_BEGIN_CODE
  EXTRA_BEGIN_CODE;
#endif

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

#ifdef PADS_TRL_TY
  if (P_ERR == PADS_TRL_TY(_init)(pads, &trl_rep)) {
    error(ERROR_FATAL, "*** trailer representation initialization failed ***");
  }
  if (P_ERR == PADS_TRL_TY(_pd_init)(pads, &trl_pd)) {
    error(ERROR_FATAL, "*** trailer parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  PADS_TRL_TY(_m_init)(pads, &trl_m, P_CheckAndSet);
#endif /* PADS_HDR_TY */



#ifdef PADS_HDR_TY
  /*
   * Try to read header
   */
  if (!P_io_at_eof(pads)) {
    if (P_OK != PADS_HDR_TY(_read)(pads, &hdr_m, &hdr_pd, &hdr_rep EXTRA_HDR_READ_ARGS)) {
      error(ERROR_FATAL, "Note: header read returned error");
    } else {
      error(2, "Note: header read returned OK");
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
    if (P_OK != PADS_TY(_read)(pads, m, pd, rep EXTRA_READ_ARGS )) {
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
#ifdef EXTRA_GOOD_READ_CODE
    else {
      if (PADS_TY(_verify)(pads, rep EXTRA_READ_ARGS ) ) {  
	error(2, "read reported no errors and passed predicate test.");  
      } else {  error(2, "read reported no errors but failed predicate test.");  } 
      EXTRA_GOOD_READ_CODE;
    }
#endif
#ifdef PADS_TRL_TY
    P_io_commit(pads);
#endif
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(ERROR_FATAL, "*** read loop stuck: read call did not advance IO cursor");
    }
    /* accum both good and bad vals */
    if (P_ERR == PADS_TY(_acc_add)(pads, acc, pd, rep)) {
      error(ERROR_FATAL, "*** accumulator add failed ***");
      }
  }
#ifdef PADS_TRL_TY
  /*
   * Try to read trailer
   */
  if (!P_io_at_eof(pads)) {
    if (P_OK != PADS_TRL_TY(_read)(pads, &trl_m, &trl_pd, &trl_rep EXTRA_TRL_READ_ARGS )) {
      error(ERROR_FATAL, "trailer read returned error");
    } else {
      error(2, "Note: trailer read returned OK");
    }
  }
#endif /* PADS_TRL_TY */


  if (P_ERR == PADS_TY(_acc_report)(pads, "", 0, 0, acc)) {
    error(ERROR_FATAL, "** accum_report failed **");
  }

#ifdef EXTRA_DONE_CODE
  EXTRA_DONE_CODE;
#endif
  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }
  if (P_ERR == PADS_TY(_cleanup)(pads, rep)) {
    error(ERROR_FATAL, "** representation cleanup failed **");
  }
  if (P_ERR == PADS_TY(_pd_cleanup)(pads, pd)) {
    error(ERROR_FATAL, "** parse descriptor cleanup failed **");
  }
  if (P_ERR == PADS_TY(_acc_cleanup)(pads, acc)) {
    error(ERROR_FATAL, "** accumulator cleanup failed **");
  }

  /* free the heap-allocated rep, pd, m, acc */
  RMM_free_buf(rmm_zero, (void*)rep);
  RMM_free_buf(rmm_zero, (void*)pd);
  RMM_free_buf(rmm_zero, (void*)m);
  RMM_free_buf(rmm_zero, (void*)acc);

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }
  return 0;
}
