#ifndef PDCI_MacroArg2String
#  define PDCI_MacroArg2String(s) #s
#endif

#ifndef READ_MASK
#  define READ_MASK P_CheckAndSet
#endif

#ifndef INIT_N
#  define INIT_N 1024
#endif 

#ifndef INIT_B
#  define INIT_B 10
#endif 

#ifndef INIT_M
#  define INIT_M 1024 * 1024
#endif
 
#ifndef INIT_ISE
#  define INIT_ISE 1
#endif 

#ifndef INIT_ISO
#  define INIT_ISO 0
#endif 

#ifndef INIT_n
#  define INIT_n 2
#endif 

#ifndef INIT_e
#  define INIT_e .1
#endif 

#ifndef INIT_scale
#  define INIT_scale 100 
#endif

#ifndef INIT_maxPortion
#  define INIT_maxPortion 3
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
#define MAX_RECS 0
#endif

#include <stdlib.h>
#include <rbuf-internal.h>
Puint64 num_recs = 0;


int main(int argc, char** argv) {
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Ppos_t            bpos, epos;
  P_hist            default_hist;
  PADS_TY( )        rep;
  PADS_TY(_pd)      pd;
  PADS_TY(_m)       m;
  PADS_TY(_hist)    h;
  Puint32           isFull;
#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
  char             *fileName = 0;
#ifdef EXTRA_DECLS
  EXTRA_DECLS;
#endif

  default_hist.N = INIT_N;
  default_hist.B = INIT_B;
  default_hist.M = INIT_M;
  default_hist.isE = INIT_ISE;
  default_hist.isO = INIT_ISO;
  default_hist.n = INIT_n;
  default_hist.e = INIT_e;
  default_hist.scale = INIT_scale;
  default_hist.maxPortion = INIT_maxPortion;
  default_hist.toFloat = 0;
  default_hist.fromFloat = 0;

#ifdef PRE_LIT_LWS
  my_disc.pre_lit_lws = PRE_LIT_LWS;
#endif
#ifdef WSPACE_OK
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
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
  if (P_ERR == PADS_TY(_init)(pads, &rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == PADS_TY(_pd_init)(pads, &pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }

  PADS_TY(_hist_init)(pads, &h);	
  PADS_TY(_hist_setPara)(pads, &h, &default_hist);

#ifdef EXTRA_INIT_CODE
  EXTRA_INIT_CODE;
#endif

  /* init mask -- must do this! */
  PADS_TY(_m_init)(pads, &m, READ_MASK);
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
    if (P_OK == PADS_TY(_read)(pads, &m, &pd, &rep EXTRA_READ_ARGS )) {
      PADS_TY(_hist_add)(pads, &h, &pd, &rep, &isFull);
      if (isFull != 0) {
	PADS_TY(_hist_reportFull)(pads, "", 0, 0, &h);
      }
    }
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(ERROR_FATAL, "*** read loop stuck: read call did not advance IO cursor");
    }
  }

  PADS_TY(_hist_reportAll)(pads, "", 0, 0, &h);
  PADS_TY(_hist_cleanup)(pads, &h);

#ifdef EXTRA_DONE_CODE
  EXTRA_DONE_CODE;
#endif
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
