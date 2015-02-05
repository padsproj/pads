#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#include <stdio.h>

int main(int argc, char** argv) {
  P_t*          pads;
  const char* fname = "../../data/ex_data.sb_test";
  char tmp[100];
  Sfio_t* io;
  int len;

  for (len = 0; len < 100; len++) {
    tmp[len] = P_EBCDIC_SPACE;
  }

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    return -1;
  }

  printf("fname = %s\n", fname);
  io = sfopen(0, fname, "w");

  if (1 != PDCI_int8_2sbl_io(pads, io, 0, 1))  goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_int8_2sbl_io(pads, io, P_MIN_INT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_int8_2sbl_io(pads, io, P_MAX_INT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_uint8_2sbl_io(pads, io, P_MAX_UINT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (2 != PDCI_int16_2sbl_io(pads, io, P_MIN_INT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (2 != PDCI_int16_2sbl_io(pads, io, P_MAX_INT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (2 != PDCI_uint16_2sbl_io(pads, io, P_MAX_UINT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (4 != PDCI_int32_2sbl_io(pads, io, P_MIN_INT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (4 != PDCI_int32_2sbl_io(pads, io, P_MAX_INT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (4 != PDCI_uint32_2sbl_io(pads, io, P_MAX_UINT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (8 != PDCI_int64_2sbl_io(pads, io, P_MIN_INT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);

  if (8 != PDCI_int64_2sbl_io(pads, io, P_MAX_INT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);

  if (8 != PDCI_uint64_2sbl_io(pads, io, P_MAX_UINT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);


  if (1 != PDCI_int8_2sbh_io(pads, io, 0, 1))  goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_int8_2sbh_io(pads, io, P_MIN_INT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_int8_2sbh_io(pads, io, P_MAX_INT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (1 != PDCI_uint8_2sbh_io(pads, io, P_MAX_UINT8, 1)) goto write_err;
  sfwrite(io, tmp, 15);

  if (2 != PDCI_int16_2sbh_io(pads, io, P_MIN_INT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (2 != PDCI_int16_2sbh_io(pads, io, P_MAX_INT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (2 != PDCI_uint16_2sbh_io(pads, io, P_MAX_UINT16, 2)) goto write_err;
  sfwrite(io, tmp, 14);

  if (4 != PDCI_int32_2sbh_io(pads, io, P_MIN_INT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (4 != PDCI_int32_2sbh_io(pads, io, P_MAX_INT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (4 != PDCI_uint32_2sbh_io(pads, io, P_MAX_UINT32, 4)) goto write_err;
  sfwrite(io, tmp, 12);

  if (8 != PDCI_int64_2sbh_io(pads, io, P_MIN_INT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);

  if (8 != PDCI_int64_2sbh_io(pads, io, P_MAX_INT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);

  if (8 != PDCI_uint64_2sbh_io(pads, io, P_MAX_UINT64, 8)) goto write_err;
  sfwrite(io, tmp, 8);

  sfclose(io);
  return 0;

 write_err:
  error(0, "XXX write error occurred");
  sfclose(io);
  return -1;
}
