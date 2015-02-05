#include "pads.h"
#include "format5.h"

int main(int argc, char** argv) {
  P_t*          pads;
  call_pd         cpd, cpdCpy;
  call            cdata, cdataCpy;
  Pdisc_t      my_disc = Pdefault_disc;
  
  my_disc.flags |= P_WSPACE_OK;

  /* Open pads handle */
  if (P_ERR == P_open(&pads, &my_disc, 0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  /* Open output file */
  if (P_ERR == P_io_fopen(pads, "../data/format5.cpy")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    Perror_t res;
    res= call_read(pads, 0, &cpd, &cdata);

    if (res == P_OK) {
      sfprintf(sfstdout, "Record okay:\t");
      call_copy(pads, &cdataCpy, &cdata);
    } else {
      sfprintf(sfstdout, "Record not okay:\t");
      call_copy(pads, &cdataCpy, &cdata);
      call_pd_copy(pads, &cpdCpy, &cpd);
    }
    sfprintf(sfstdout, "x = %d\t", cdata.x.x);
    switch (cdata.pn.tag ){
    case code : 
	sfprintf(sfstdout, "tagged as code: %d\n",cdata.pn.val.code );
	break;
    case pn :
	sfprintf(sfstdout, "tagged as phone number: %d\n", cdata.pn.val.pn);
	break;
    default:
	sfprintf(sfstdout, "bogus tag. \n");
	break;      
    }
  }

  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_fclose failed ***");
    exit(-1);
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }

  return 0;
}
