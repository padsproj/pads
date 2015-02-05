#include "pads.h"
#include "test2out.h"

int main(int argc, char** argv) {
  P_t             *pads;
  Pdisc_t         my_disc = Pdefault_disc;
  Pio_disc_t     *io_disc;

  hdr_rec            hdr;
  hdr_rec_pd         hdr_pd;
  hdr_rec_m          hdr_m;

  magic_rec          magic;
  magic_rec_pd       magic_pd;
  magic_rec_m        magic_m;

  data_rec           data;
  data_rec_pd        data_pd;
  data_rec_m         data_m;

  if (argc != 2) {
    goto usage;
  }
  io_disc = P_fwrec_make(0, 12, 1);
  P_open(&pads,&my_disc,io_disc);
  error(0, "\nOpening data file %s\n", argv[1]);
  if (P_ERR == P_io_fopen(pads, argv[1])) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
    return -1;
  }

  hdr_rec_init(pads, &hdr);
  hdr_rec_pd_init(pads, &hdr_pd);
  hdr_rec_m_init(pads, &hdr_m, P_CheckAndSet);

  magic_rec_init(pads, &magic);
  magic_rec_pd_init(pads, &magic_pd);
  magic_rec_m_init(pads, &magic_m, P_CheckAndSet);

  data_rec_init(pads, &data);
  data_rec_pd_init(pads, &data_pd);
  data_rec_m_init(pads, &data_m, P_CheckAndSet);

  /* Read the hdr rec */
  if (P_ERR == hdr_rec_read(pads, &hdr_m, &hdr_pd, &hdr)) {
    error(ERROR_FATAL, "*** hdr_rec_read failed ***");
  }

  /* Read the magic rec */
  if (P_ERR == magic_rec_read(pads, &magic_m, &magic_pd, &magic)) {
    error(ERROR_FATAL, "*** magic_rec_read failed ***");
  }

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    /* P_io_checkpoint(pads, 0); */
    if (P_ERR == data_rec_read(pads, &data_m, &data_pd, &data)) {
      error(ERROR_FATAL, "*** data_rec_read failed ***");
    }
    /* output data description */
    error(0, "*** TODO: describe data ***");
    switch (data.switch_val) {
    case -1:
      error(0, "switch_val -1  qy1 = %s", P_fmt_str(&(data.arms.val.a1.qy1)));
      break;
    case 0:
      error(0, "switch_val  0  qy2 = %s", P_fmt_str(&(data.arms.val.a2.qy2)));
      break;
    case 1:
      error(0, "switch_val  1  qy3 = %s  qy4 = %s",
	    P_fmt_str(&(data.arms.val.a3.qy3)),
	    P_fmt_str(&(data.arms.val.a3.qy4)));
      break;
    }
    /* P_io_commit(pads); */
  }

  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }

  return 0;

 usage:
  error(0,
	"\nUsage: print_test2out <data_file>"
	"\n    "
	"\n    Where <data_file> could be /dev/stdin or a file pathname"
	"\n    ");
  return -1;
}
