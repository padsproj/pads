#include "pads.h"
#include "format6.h"

#define NO_NL 0|ERROR_PROMPT

int main(int argc, char** argv) {
  P_t*          pads;
  defPN_pd        ppd;
  defPN           pdata;
  defPN_m         pm;

  /* Open pads handle */
  if (P_ERR == P_open(&pads, 0, 0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  /* Open output file */
  if (P_ERR == P_io_fopen(pads, "../../data/format6")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /* init mask -- must do this! */
  defPN_m_init(pads, &pm, P_CheckAndSet);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    Perror_t res;
    res= defPN_read(pads, &pm, &ppd, &pdata, 1999999999LL, 9999999999LL);

    if (res == P_OK) {
      error(NO_NL, "Record okay:\t");
    } else {
      error(NO_NL, "Record not okay:\t");
    }
    error(NO_NL, "x = %llu\n", pdata.id);
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
