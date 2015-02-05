#include "pads.h"
#include "struct_strings.h"
#define FILENAME  "../../data/write_struct_strings"


Perror_t my_string_inv_val(P_t *pads, void *pd_void, void *val_void, va_list type_args) {
  Pbase_pd *pd  = (Pbase_pd*)pd_void;
  Pstring  *val = (Pstring*)val_void;
  if (pd->errCode == P_USER_CONSTRAINT_VIOLATION) {
    Pstring_cstr_copy(pads, val, "BAD_LEN", 7);
  } else {
    Pstring_cstr_copy(pads, val, "INV_STR", 7);
  }
  return P_OK;
}

Perror_t my_string_fw_inv_val(P_t *pads, void *pd_void, void *val_void, va_list type_args) {
  Pbase_pd *pd    = (Pbase_pd*)pd_void;
  Pstring  *val   = (Pstring*)val_void;
  size_t    width;

  width = va_arg(type_args, size_t);

  if (pd->errCode == P_USER_CONSTRAINT_VIOLATION) {
    Pstring_cstr_copy(pads, val, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", width);
  } else {
    Pstring_cstr_copy(pads, val, "x---------------------------------------------------------", width);
  }
  return P_OK;
}

int main(int argc, char** argv) {
  P_t*         pads;
  test           rep;
  test_pd        pd = {0};
  test_m         m;
  const char    *fname = FILENAME;

  if (argc == 2) {
    fname = argv[1];
  }

  if (P_ERR == P_open(&pads,0,0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }

  test_init(pads, &rep);

  pads->disc->inv_val_fn_map = Pinv_val_fn_map_create(pads); /* only needed if no map installed yet */ 
#if 1
  P_set_inv_val_fn(pads, pads->disc->inv_val_fn_map, "Pstring", my_string_inv_val);
  P_set_inv_val_fn(pads, pads->disc->inv_val_fn_map, "Pstring_FW", my_string_fw_inv_val);
#endif

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
  test_m_init(pads, &m, P_CheckAndSet);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    error(0, "\ncalling testtwo_read");
    if (P_OK == test_read(pads, &m, &pd, &rep)) {
      /* do something with the data */
      error(2, "test_read returned: s1 %.*s  s2 %.*s", rep.s1.len, rep.s1.str, rep.s2.len, rep.s2.str);
      test_write2io(pads, sfstdout, &pd, &rep);
    } else {
      error(2, "test_read returned: error");
      test_write2io(pads, sfstdout, &pd, &rep);
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
