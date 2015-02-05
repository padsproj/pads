/*
 * Template: time_pglx_all.h 
 *
 * bulk: Load entire source using PADS function and then walk over
 * result.
 *
 * linear: Walk over all children in source, incrementally load PADS
 * source using linear-streaming arrays.
 *
 * smart: Walk over all children in source, selectively load PADS
 * source using smart arrays.
 */

#include "pads.h"
#include "pglx.h"

#ifndef PDCI_MacroArg2String
#define PDCI_MacroArg2String(s) #s
#endif

#ifndef READ_MASK
#define READ_MASK P_CheckAndSet
#endif

#ifndef COPY_STRINGS
#  define COPY_STRINGS 1
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

#ifndef DEF_OUTPUT_FILE_1
#  define DEF_OUTPUT_FILE_1 ""
#endif

#ifndef DEF_OUTPUT_FILE_2
#  define DEF_OUTPUT_FILE_2 ""
#endif

#ifndef MAX_RECS
#  define MAX_RECS 0
#endif

#define exit_on_error(_Expr, _Msg) {err = _Expr; if (err != 0) {error(2, "%s: %s\n", _Msg, galax_error_string); exit(-1); }}

#define MAX_NODES 100000

#ifndef MAX_ELTS
#  define MAX_ELTS 1
#endif

#ifndef EXTRA_ARGS
#  define EXTRA_ARGS
#endif

int main(int argc, char** argv) {
  P_t*          pads;
  Pdisc_t       my_disc = Pdefault_disc;
  Pio_disc_t  	*io_disc = 0;
  PADS_TY( )    rep;
  PADS_TY(_pd)  pd ;
  PADS_TY(_m)   m;
  PDCI_node_t   *node;

  my_disc.out_formats.timestamp = "%Y-%m-%dT%H:%M:%S"; 
  my_disc.out_formats.timestamp_explicit = "%Y-%m-%dT%H:%M:%S"; 

#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
  Sfio_t       *io;
  char         *inName  = 0;

/*   clock_t start, finish, duration; */

#ifdef PRE_LIT_LWS
  my_disc.pre_lit_lws = PRE_LIT_LWS;
#endif
#ifdef WSPACE_OK
  my_disc.flags |= (Pflags_t)P_WSPACE_OK;
#endif
#ifdef COPY_STRINGS
  my_disc.copy_strings = 1;
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

#ifdef IN_TIME_ZONE
  my_disc.in_time_zone = IN_TIME_ZONE;
  error(0, "Note: set my_disc.in_time_zone to \"%s\"\n", IN_TIME_ZONE);
#endif
#ifdef OUT_TIME_ZONE
  my_disc.out_time_zone = OUT_TIME_ZONE;
  error(0, "Note: set my_disc.out_time_zone to \"%s\"\n", OUT_TIME_ZONE);
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

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }
  io = P_fopen(inName,"r");
  if (!io) {
    error(2, "*** P_fopen failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_set(pads, io)) {
    error(2, "*** P_io_set failed ***");
    exit(-1);
  }

  /* Initialize nodeid generator */
  PDCI_ID_RESET(pads,0);

  NodeMM_initMM(pads, MAX_NODES);  
  
  /* End initialize pads-galax */

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
      error(2, "<note>header read returned error</note>");
    } else {
      error(2, "<note>header read returned OK</note>");
    }
  }
#endif /* PADS_HDR_TY */

/*   error(2,"Make top level node"); */
  /* make the top-level node */
  PDCI_MK_TOP_NODE_NORET (node, &PADS_TY(_node_vtable), pads, "padsns:PSource", &m, &pd, &rep, "main");
 {
#ifdef PGLX_BULK
/*    error(2,"Read data"); */
   PADS_TY(_read)(pads, &m, &pd, &rep EXTRA_READ_ARGS);
#endif
#ifdef PGLX_LINEAR
   PADS_TY(_linearNode_init)(node  EXTRA_ARGS);
#endif
#ifdef PGLX_SMART
   PADS_TY(_smartNode_init)(node, MAX_ELTS  EXTRA_ARGS);
#endif
/*    error(2,"begin children walk"); */
   walk_children(node);
/*    error(2,"end chilren walk"); */
 }
  /* 
   * The linear and code doesn't use rep->elts, pd->elts, 
   * but it does use the length variables. Therefore,
   * we need to reset them to 0 before cleanup.
   */
  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }
  rep.length = 0;
  if (P_ERR == PADS_TY(_cleanup)(pads, &rep)) {
    error(ERROR_FATAL, "** representation cleanup failed **");
  }
  pd.length = 0;
  if (P_ERR == PADS_TY(_pd_cleanup)(pads, &pd)) {
    error(ERROR_FATAL, "** parse descriptor cleanup failed **");
  }
  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }
  sfclose(io);

  NodeMM_freeMM(pads);

  return 0;
}
