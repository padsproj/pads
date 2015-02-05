#include "pads.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Pstring          rep;
  Pbase_pd         pd;
  Pbase_m          m;
  char             *fileName = 0;

  my_disc.copy_strings = 1;  /* strings should almost always be copied for accumulator programs */
  fileName = argv[1];
  error(0, "Data file = %s\n", fileName);

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }
  if (P_ERR == P_io_fopen(pads, fileName)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }
  if (P_ERR == Pstring_init(pads, &rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == Pstring_pd_init(pads, &pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  m = P_CheckAndSet;

  error(0, "Finished initialization.\n");

  if (P_OK!= Pstring_ME_read (pads,&m,&pd,&rep,"/(http|ftp|https):\\/\\/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*))(:([1-9][0-9]*))\?\\/\?(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%]*))*\\/\?(\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*))\?(\\\?)\?\\&\?(([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*(\\&([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*)*\\&\?)\?(#([0-9A-Za-z_][A-Za-z0-9_\\-]*))\?|(http|ftp|https):\\/\\/(([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3}))(:([1-9][0-9]*))\?\\/\?(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%]*))*\\/\?(\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*))\?(\\\?)\?\\&\?(([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*(\\&([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*)*\\&\?)\?(#([0-9A-Za-z_][A-Za-z0-9_\\-]*))\?|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%]*))+(\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*))\?\\\?(([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*(\\&([0-9A-Za-z_][A-Za-z0-9_\\-]*)=[0-9a-zA-Z_\\-%;.+/:]*)*\\&\?)/")) {
      error(2, "read returned error");
  }
      error(2, "finished ME read\n");

    return P_OK;
}
