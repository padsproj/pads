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

#ifndef DEF_OUTPUT_FILE_1
#  define DEF_OUTPUT_FILE_1 "r_and_rr_out1.xml"
#endif

#ifndef DEF_OUTPUT_FILE_2
#  define DEF_OUTPUT_FILE_2 "r_and_rr_out2.xml"
#endif

#ifndef MAX_RECS
#  define MAX_RECS 0
#endif

Puint64 num_recs = 0;

Perror_t test_rwxml (P_t *pads,Sfio_t *out1, Sfio_t *out2, PADS_TY(_m) *m,PADS_TY(_pd) *pd,PADS_TY( ) *rep);

int main(int argc, char** argv) {
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Ppos_t            bpos, epos;
  PADS_TY( )        rep;
  PADS_TY(_pd)      pd;
  PADS_TY(_m)       m;
#ifdef PADS_HDR_TY
  PADS_HDR_TY( )    hdr_rep;
  PADS_HDR_TY(_pd)  hdr_pd;
  PADS_HDR_TY(_m)   hdr_m;
#endif /* PADS_HDR_TY */
  Sfio_t       *io, *out1,*out2;
  char             *inName  = 0;
  char             *outName1 = 0;
  char             *outName2 = 0;

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

  if (argc >= 3) {
    outName1 = argv[2];
  } else {
    outName1 = DEF_OUTPUT_FILE_1;
  }
  error(0, "Output file 1 = %s\n", outName1);

  if (argc >= 4) {
    outName2 = argv[3];
  } else {
    outName2 = DEF_OUTPUT_FILE_2;
  }
  error(0, "Output file 2 = %s\n", outName2);

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
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

  out1 = P_fopen(outName1,"w");
  if (!out1) {
    error(2, "*** P_fopen failed ***");
    exit(-1);
  }

  out2 = P_fopen(outName2,"w");
  if (!out2) {
    error(2, "*** P_fopen failed ***");
    exit(-1);
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
      error(2, "<note>header read returned error</note>");
    } else {
      error(2, "<note>header read returned OK</note>");
    }
    if (P_ERR == PADS_HDR_TY(_write_xml_2io)(pads, io, &hdr_pd, &hdr_rep, (const char*)0, 0 EXTRA_HDR_READ_ARGS )) {
      error(ERROR_FATAL, "*** IO error during header write");
    }
  }
#endif /* PADS_HDR_TY */

  /*
   * Try to read each item of data
   */
  while (!P_io_at_eof(pads) && (MAX_RECS == 0 || num_recs++ < MAX_RECS)) {
#ifdef PRE_SKIP_BYTES
    {
      size_t bytes_skipped;
      if (P_ERR == P_io_skip_bytes(pads, PRE_SKIP_BYTES, &bytes_skipped)) {
        error(ERROR_FATAL, "*** tried to skip %lu bytes prior to read, only skipped %lu bytes",
	      (unsigned long)PRE_SKIP_BYTES, (unsigned long)bytes_skipped);
      }
      error(2, "<note>skipped %lu bytes prior to read</note>", (unsigned long)PRE_SKIP_BYTES);
    }
#endif
    P_io_getPos(pads, &bpos, 0);
    if (P_OK != test_rwxml(pads, out1, out2, &m, &pd, &rep EXTRA_READ_ARGS )) {
      error(2, "<note>test_rwxml returned error</note>");
    } else {
      error(2, "<note>test_rwxml returned OK</note>");
    }
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(2, "<note>test_rwxml call did not advance IO cursor, stopping read loop</note>");
      break;
    }
#ifdef POST_SKIP_BYTES
    {
      size_t bytes_skipped;
      if (P_ERR == P_io_skip_bytes(pads, POST_SKIP_BYTES, &bytes_skipped)) {
        error(ERROR_FATAL, "*** tried to skip %lu bytes prior to read, only skipped %lu bytes",
	      (unsigned long)POST_SKIP_BYTES, (unsigned long)bytes_skipped);
      }
      error(2, "<note>skipped %lu bytes prior to read</note>", (unsigned long)POST_SKIP_BYTES);
    }
#endif
  }
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
  sfclose(out1);
  sfclose(out2);
  return 0;
}


/* XXX TEMP XXX */
Sfio_t *P_io_get(P_t *pads)
{
  return pads->io;
}

Perror_t P_io_seek(P_t *pads, Sfoff_t offset){
  Sfio_t *io = P_io_get(pads);
  P_io_close(pads);
  if (-1 == sfseek(io, offset, 0)) {
    return P_ERR;
  }

  return P_io_set(pads, io);
}

/*int pdCommon_eq(Pbase_pd *pd1, Pbase_pd *pd2){
  int size = sizeof(Pbase_pd);
  int i;

  unsigned char *p1 = (unsigned char *)pd1;
  unsigned char *p2 = (unsigned char *)pd2;
  
  for(i=0;i<size;i++){
    if (p1[i] != p2[i])
      return 0;
  }
  return 1;
}
*/

Perror_t test_rwxml (P_t *pads,Sfio_t *out1, Sfio_t *out2, PADS_TY(_m) *m,PADS_TY(_pd) *pd,PADS_TY( ) *rep)
{
  PDCI_IODISC_3P_CHECKS ("test_rwxml",m,pd,rep);
  PD_COMMON_INIT_NO_ERR (pd);
  PD_COMMON_READ_INIT (pads,pd);
  {
    Ploc_t tloc,loc;
    Ploc_t *loc_ptr=&tloc;

    /*
    _PADS_ELT_TY    erep;
    _PADS_ELT_PD_TY  epd;
    */

    int i=0;
    Pread_res_t result;
    Pread_res_t r2;

    /* PD_COMMON_INIT(&epd); */

    result = PADS_TY(_read_one_init) (pads,m,pd,rep,loc_ptr);
    //while (result == P_READ_VALID || result == P_READ_INVALID )
    while (P_PS_isPartial(pd))
      {
	AR_RESERVE_SPACE (_PADS_TY,_PADS_ELT_TY,_PADS_ELT_PD_TY,0);

	P_io_getLocB (pads,&loc,0);
	result = PADS_TY(_read_one) (pads,m,pd,rep,loc_ptr,&(pd->elts)[i],&(rep->elts)[i]);
	P_io_getLocE (pads,&loc,0);

	if (P_READ_VALID == result){
	  if (P_ERR == PADS_ELT_TY(_write_xml_2io)(pads, out1,  
						   &(pd->elts)[i], &(rep->elts)[i], (const char*)0, 0) EXTRA_READ_ARGS) {
	    error(ERROR_FATAL, "*** write xml call failed");
	  }

	  P_io_seek(pads,loc.b.offset);
	  r2 = PADS_TY(_reread_one)(pads,m,pd,rep,loc_ptr,&(pd->elts)[i], &(rep->elts)[i], (pd->numRead > 1));
	  P_io_seek(pads,loc.e.offset);

	  if (r2 == P_READ_VALID){
	    if (P_ERR == PADS_ELT_TY(_write_xml_2io)(pads, out2, 
						     &(pd->elts)[i], &(rep->elts)[i], (const char*)0, 0) EXTRA_READ_ARGS ) {
	      error(ERROR_FATAL, "*** write xml call failed");
	    }
	  }else{
	    fprintf(out2,"<err>Failed to find element when expected.</err>");
	  }
	}
	
	i = (rep->length);
      }
      
    PCGEN_FIND_EOR ("test_rwxml");
      
    return AR_STD_RETURN ();
  }
}

