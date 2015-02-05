#include "pads.h"
#include "format5.h"


#define NO_NL 0|ERROR_PROMPT

int main(int argc, char** argv) {
  P_t*          pads;
  call_pd         cpd = {0};
  call            cdata;
  call_m          cm;

  /* Open pads handle */
  if (P_ERR == P_open(&pads, 0, 0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  /* Open output file */
  if (P_ERR == P_io_fopen(pads, "../../data/format5")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /* Init mask -- must do this! */
  call_m_init(pads, &cm, P_CheckAndSet);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    Perror_t res;
    res= call_read(pads, &cm, &cpd, &cdata);

    if (res == P_OK) {
      error(NO_NL, "Record okay:\t");
    } else {
      error(NO_NL, "Record not okay:\t");
    }
    error(NO_NL, "x = %d\t", cdata.x.x);
    switch (cdata.pn.tag ){
    case code : 
	error(0, "tagged as code: %d",cdata.pn.val.code );
	break;
    case pn :
	error(0, "tagged as phone number: %d", cdata.pn.val.pn);
	break;
    default:
	error(0, "bogus tag. ");
	break;      
    }
  }

  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    exit(-1);
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }

  return 0;
}
