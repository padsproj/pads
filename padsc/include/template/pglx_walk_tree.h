/*
 * Template: pglx_load.h 
 * Bulk load PADS source, pass to Galax, and serialize in XML.
 */
#include "pads.h"
#include "pglx.h"

#ifndef PDCI_MacroArg2String
#define PDCI_MacroArg2String(s) #s
#endif


#if !(defined(PGLX_BULK) || defined(PGLX_LINEAR) || defined(PGLX_SMART))
#  error "Data loading scheme undefined! Choose PGLX_BULK, PGLX_LINEAR, or PGLX_SMART."
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

#define exit_on_error(_Expr,_Msg) {err = (_Expr); if (err != 0) {error(2, "%s: %s\n", _Msg,galax_error_string); }}

int main(int argc, char** argv) {
  P_t*          pads;
  Pdisc_t       my_disc = Pdefault_disc;
  Pio_disc_t  	*io_disc = 0;
  PADS_TY( )    rep;
  PADS_TY(_pd)  pd ;
  PADS_TY(_m)   m;
  PDCI_node_t   *doc_node;

#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
  Sfio_t       *io;
  char         *inName  = 0;

  galax_err err;
  item doc;
  processing_context pc; 
  itemlist docitems, monitems;

  /* Galax configuration options */
  int monitor_flag = 0; 
  char *monitor_out;
/*   char *file_out; */
/*   FILE *file_fp; */

  monitor_out = malloc(strlen(argv[0]) + strlen(".out"));
  strcpy(monitor_out,argv[0]); strcat(monitor_out,".out");
/*   file_out = malloc(strlen(argv[0]) + strlen(".xml")); */
/*   strcpy(file_out,argv[0]); strcat(file_out,".xml"); */

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

  /* When linking with the Galax library, which contains a custom O'Caml runtime system, 
     it is necessary to call galax_init first, so the runtime is initialized and then 
     can delegate control back to the C program 
  */
  galax_init();

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

  /* The remaining flags are for galax */
  {
    int i;
    for (i = 3; i < argc; i++) { 
      if (strcmp(argv[i], "-output-monitor") == 0) {
	monitor_flag = 1;
	i++;
	if (i < argc) {
	  monitor_out = argv[i];
	} else error(2, "Usage: -output-monitor <filename>");
      }
/*       else if (strcmp(argv[i], "-output-xml") == 0) { */
/* 	i++; */
/* 	if (i < argc) { */
/* 	  file_out = argv[i]; */
/* 	} else error(2, "Usage: -output-xml <filename>"); */
/*       } */
    }
  }
  /* Open files */	
/*   if (!(file_fp = fopen(file_out, "w"))) { error(2, "Cannot open %s\n", file_out); exit(-1); } */

  /* Initialize Galax flags */
  exit_on_error(galax_default_processing_context(&pc), "galax_default_processing_context");
  if (monitor_flag) {
    exit_on_error(galax_set_monitor_mem(pc, 1), "galax_set_monitor_mem");
    exit_on_error(galax_set_monitor_time(pc, 1), "galax_set_monitor_time");
  }
  exit_on_error(galax_set_serialization_kind(pc, Serialize_As_Well_Formed), "galax_set_serialization_kind");

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

  /* Initialize NodeMM. */
  NodeMM_initMM(pads,50);  
  
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
  exit_on_error(galax_start_monitor_call(pc, "pads_init"), "galax_start_monitor_call");
  PADS_HDR_TY(_m_init)(pads, &hdr_m, P_CheckAndSet);
  exit_on_error(galax_end_monitor_call(pc), "galax_end_monitor_call");
#endif /* PADS_HDR_TY */

#ifdef PADS_HDR_TY
  /*
   * Try to read header
   */
  if (!P_io_at_eof(pads)) {
    exit_on_error(galax_start_monitor_call(pc, "pads_header_read"), "galax_start_monitor_call");
    if (P_OK != PADS_HDR_TY(_read)(pads, &hdr_m, &hdr_pd, &hdr_rep EXTRA_HDR_READ_ARGS )) {
      error(2, "<note>header read returned error</note>");
    } else {
      exit_on_error(galax_end_monitor_call(pc), "galax_end_monitor_call");
      error(2, "<note>header read returned OK</note>"); 
    }
  }
#endif /* PADS_HDR_TY */

  /* For now, we hardwire the padsns namespace into the template file */
  char *pdci_uri = strcat(strcpy(malloc(strlen("file:") + strlen(PDCI_source)), "file:"), 
			  PDCI_source);

  /* make the top-level node */
  PDCI_MK_TOP_NODE_NORET (doc_node, &PADS_TY(_node_vtable), pads, "PSource", 
			  &m, &pd, &rep, "main");

#ifdef PGLX_BULK
  /* Try to read entire file */
  exit_on_error(galax_start_monitor_call(pc, "pads_read"), "galax_start_monitor_call");
  if (P_OK != PADS_TY(_read)(pads, &m, &pd, &rep EXTRA_READ_ARGS)) {
      error(2, "read returned error");
  }
  exit_on_error(galax_end_monitor_call(pc), "galax_end_monitor_call");
#endif 
#ifdef PGLX_LINEAR
   PADS_TY(_linearNode_init)(doc_node  EXTRA_READ_ARGS);
#endif
#ifdef PGLX_SMART
   PADS_TY(_smartNode_init)(doc_node, MAX_ELTS  EXTRA_READ_ARGS);
#endif

  exit_on_error((padsDocument(pc, inName, pdci_uri, (nodeRep)doc_node, &doc)), "padsDocument");
  docitems = itemlist_cons(doc, itemlist_empty()); 

  if (is_empty(docitems)) error(2, "*** Result is empty") ;
  else {
/*     char *result; */
    walkPadsDocument(doc);
    /*	exit_on_error(galax_serialize_to_string(pc,docitems,&result), "galax_serialize_to_string"); */
    /* fprintf(file_fp,"%s",result); */
/*     fflush(file_fp); */
/*     fclose(file_fp); */
  }
  if (monitor_flag) {
    exit_on_error(galax_monitor_of_all_calls(pc, &monitems), "galax_monitor_of_all_calls");
    exit_on_error(galax_serialize_to_file(pc,"load-monitor.out", monitems), "galax_serialize_to_file");
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
