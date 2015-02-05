#include "pads-internal.h"
#include "readint.h"
#include <error.h>


int main(int argc, char** argv) {
  P_t*          pads;
  rec             r;
  rec_pd          pd = {0};
  rec_m           m;

  if (P_ERR == P_open(&pads, 0, 0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/readint")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /* init mask -- must do this! */
  rec_m_init(pads, &m, P_CheckAndSet);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    if (P_OK == rec_read(pads, &m, &pd, &r)) {
      /* do something with the data */
    } else {
      error(0, "rec_read returned: error");
      if (pd.l.i8.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "i8 error: ");
	PDCI_report_err(pads, 0, &(pd.l.i8.loc), pd.l.i8.errCode, "main", 0);
      }
      if (pd.l.i16.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "i16 error: ");
	PDCI_report_err(pads, 0, &(pd.l.i16.loc), pd.l.i16.errCode, "main", 0);
      }
      if (pd.l.i32.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "i32 error: ");
	PDCI_report_err(pads, 0, &(pd.l.i32.loc), pd.l.i32.errCode, "main", 0);
      }
      if (pd.l.i64.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "i64 error: ");
	PDCI_report_err(pads, 0, &(pd.l.i64.loc), pd.l.i64.errCode, "main", 0);
      }
      if (pd.l.ui8.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "ui8 error: ");
	PDCI_report_err(pads, 0, &(pd.l.ui8.loc), pd.l.ui8.errCode, "main", 0);
      }
      if (pd.l.ui16.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "ui16 error: ");
	PDCI_report_err(pads, 0, &(pd.l.ui16.loc), pd.l.ui16.errCode, "main", 0);
      }
      if (pd.l.ui32.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "ui32 error: ");
	PDCI_report_err(pads, 0, &(pd.l.ui32.loc), pd.l.ui32.errCode, "main", 0);
      }
      if (pd.l.ui64.errCode != P_NO_ERR) {
	error(0|ERROR_PROMPT, "ui64 error: ");
	PDCI_report_err(pads, 0, &(pd.l.ui64.loc), pd.l.ui64.errCode, "main", 0);
      }
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
