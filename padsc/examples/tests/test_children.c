#include "pads.h"
#include "format1.h"
#include "pglx.h"

int main(int argc, char** argv) {
  P_t*          pads;
  Pdisc_t      my_disc = Pdefault_disc;
  test            rep;
  test_pd         pd ;
  test_m          m;
  PDCI_node_t    *top_node;

#ifdef USE_GALAX
  /* When linking with the Galax library, which contains a custom O'Caml runtime system, 
     it is necessary to call glx_init first, so the runtime is initialized and then 
     can delegate control back to the C program 
  */
  char *fake_argv[2];

  fake_argv[0] = "caml";
  fake_argv[1] = 0;
  glx_init(fake_argv);
#endif

  my_disc.flags |= P_WSPACE_OK;

  if (P_ERR == P_open(&pads,&my_disc,0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/format1.good")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  test_init(pads, &rep);
  test_pd_init(pads, &pd);
  /* init mask -- must do this! */
  test_m_init(pads, &m, P_CheckAndSet);

  /* make the top-level node */
  PDCI_MK_TOP_NODE_NORET (top_node, &test_vtable, pads, "top", &m, &pd, &rep, "main");

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    error(0, "\ncalling test_read");
    if (P_OK == test_read(pads, &m, &pd, &rep)) {
      /* do something with the data */
      error(2, "test_read returned: id %d  ts %d", rep.id, rep.ts);
      walk_children(top_node, 0);
    } else {
      error(2, "test_read returned: error");
      walk_children(top_node, 0);
    }
  }
  error(0, "\nFound eof");

  /* done with top-level node */
  PGLX_node_free(top_node);

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
