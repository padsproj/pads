#include "pads.h"
#include "struct1.h"
/* #define FILENAME  "stdin" */
#define FILENAME  "../../data/write_struct1" 


Perror_t my_uint32_inv_val(P_t *pads, void *pd_void, void *val_void, va_list type_args) {
  Pbase_pd *pd  = (Pbase_pd*)pd_void;
  Puint32  *val = (Puint32*)val_void;
  if (pd->errCode == P_USER_CONSTRAINT_VIOLATION) {
    (*val) = 77777;
  } else {
    (*val) = 99999;
  }
  return P_OK;
}

int main(int argc, char** argv) {
  P_t*           pads;
  testtwo        f1data;
  testtwo_pd     pd = {0};
  testtwo_m      m;
  const char    *fname = FILENAME;

  if (argc == 2) {
    fname = argv[1];
  }
  if (P_ERR == P_open(&pads,0,0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  pads->disc->inv_val_fn_map = Pinv_val_fn_map_create(pads); /* only needed if no map installed yet */ 
  P_set_inv_val_fn(pads, pads->disc->inv_val_fn_map, "Puint32", my_uint32_inv_val);

  if (strcasecmp(fname, "stdin") == 0) {
    error(0, "Data file = standard in\n");
    if (P_ERR == P_io_set(pads, sfstdin)) {
      error(2, "*** P_io_set(sfstdin) failed ***");
      exit(-1);
    }
  } else {
    error(0, "Data file = %s\n", fname);
    if (P_ERR == P_io_fopen(pads, (char*)fname)) {
      error(2, "*** P_io_fopen failed ***");
      exit(-1);
    }
  }

  /* init mask -- must do this! */
  testtwo_m_init(pads, &m, P_CheckAndSet);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    error(0, "\ncalling testtwo_read");
    if (P_OK == testtwo_read(pads, &m, &pd, &f1data)) {
      /* do something with the data */
      error(2, "testtwo_read returned: id %d  ts %d  f %d ", f1data.header.id, f1data.header.ts, f1data.f);
      testtwo_write2io(pads, sfstdout, &pd, &f1data);
    } else {
      error(2, "testtwo_read returned: error");
      testtwo_write2io(pads, sfstdout, &pd, &f1data);
    }
  }
  error(0, "\nFound eof");

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
