#include <stdlib.h>
#include <rbuf-internal.h>
Puint64 num_recs = 0;


int main(int argc, char** argv) {
  RMM_t            *rmm_zero;
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;
  Ppos_t            bpos, epos;
  entry_t          *rep;
  entry_t_pd       *pd;
  entry_t_m        *m;
  entry_t_acc     *acc;
  char             *fileName = 0;
  Pregexp_t         compiled_exp = {0};

  my_disc.copy_strings = 1;  /* strings should almost always be copied for accumulator programs */


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
  rep  = (entry_t*)   RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY( )));
  pd   = (entry_t_pd)*) RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY(_pd)));
  m    = (entry_t_m)*)  RMM_alloc_unmanaged_buf(rmm_zero, sizeof(PADS_TY(_m)));

  if (P_ERR == entry_t_init)(pads, rep)) {
    error(ERROR_FATAL, "*** representation initialization failed ***");
  }
  if (P_ERR == entry_t_pd_init)(pads, pd)) {
    error(ERROR_FATAL, "*** parse description initialization failed ***");
  }
  /* init mask -- must do this! */
  entry_t_m_init)(pads, m, READ_MASK);

  /*
   * Try to read each line of data
   */

  while (!P_io_at_eof(pads) && (MAX_RECS == 0 || num_recs++ < MAX_RECS)) {
    P_io_getPos(pads, &bpos, 0);
    if (P_OK != entry_t_read(pads, m, pd, rep)) {
      error(2, "read returned error");
    }
    P_io_getPos(pads, &epos, 0);
    if (P_POS_EQ(bpos, epos)) {
      error(ERROR_FATAL, "*** read loop stuck: read call did not advance IO cursor");
    }
  }
  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }

  return 0;
}
