#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#include <stdio.h>

int main(int argc, char** argv) {
  P_t*          pads;
  const char* fname = "../../data/ex_data.ebc_test";
  char tmp[100];
  Sfio_t* io;
  int len, i;

  for (len = 0; len < 100; len++) {
    tmp[len] = P_EBCDIC_SPACE;
  }

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    return -1;
  }

  printf("fname = %s\n", fname);
  io = sfopen(0, fname, "w");

  for (i = 0; i < 2; i++) {
    if (3 != PDCI_int8_2ebc_io(pads, io, 0, 3))  goto write_err;
    sfwrite(io, tmp, 22);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  for (i = 0; i < 2; i++) {
    if (3 != PDCI_int8_2ebc_io(pads, io, P_MIN_INT8, 3)) goto write_err;
    sfwrite(io, tmp, 22);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  /* set up for range error prior to MAX_INT8 */
  if (3 != PDCI_int16_2ebc_io(pads, io, 999, 3)) goto write_err;
  sfwrite(io, tmp, 22);
  sfputc(io, P_EBCDIC_NEWLINE);

  if (3 != PDCI_int8_2ebc_io(pads, io, P_MAX_INT8, 3)) goto write_err;
  sfwrite(io, tmp, 22);
  sfputc(io, P_EBCDIC_NEWLINE);

  /* set up for range error prior to MAX_UINT8 */
  if (3 != PDCI_uint16_2ebc_io(pads, io, 999, 3)) goto write_err;
  sfwrite(io, tmp, 22);
  sfputc(io, P_EBCDIC_NEWLINE);

  if (3 != PDCI_uint8_2ebc_io(pads, io, P_MAX_UINT8, 3)) goto write_err;
  sfwrite(io, tmp, 22);
  sfputc(io, P_EBCDIC_NEWLINE);

  for (i = 0; i < 2; i++) {
    if (5 != PDCI_int16_2ebc_io(pads, io, P_MIN_INT16, 5)) goto write_err;
    sfwrite(io, tmp, 20);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  for (i = 0; i < 2; i++) {
    if (5 != PDCI_int16_2ebc_io(pads, io, P_MAX_INT16, 5)) goto write_err;
    sfwrite(io, tmp, 20);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  /* set up for range error prior to MAX_UINT16 */
  if (5 != PDCI_uint32_2ebc_io(pads, io, 99999, 5)) goto write_err;
  sfwrite(io, tmp, 20);
  sfputc(io, P_EBCDIC_NEWLINE);

  if (5 != PDCI_uint16_2ebc_io(pads, io, P_MAX_UINT16, 5)) goto write_err;
  sfwrite(io, tmp, 20);
  sfputc(io, P_EBCDIC_NEWLINE);

  for (i = 0; i < 2; i++) {
    if (10 != PDCI_int32_2ebc_io(pads, io, P_MIN_INT32, 10)) goto write_err;
    sfwrite(io, tmp, 15);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  for (i = 0; i < 2; i++) {
    if (10 != PDCI_int32_2ebc_io(pads, io, P_MAX_INT32, 10)) goto write_err;
    sfwrite(io, tmp, 15);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  for (i = 0; i < 2; i++) {
    if (10 != PDCI_uint32_2ebc_io(pads, io, P_MAX_UINT32, 10)) goto write_err;
    sfwrite(io, tmp, 15);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  /* set up for range error prior to MIN_INT64 */
  if (2 != PDCI_int8_2ebc_io(pads, io, 99, 2)) goto write_err;
  if (17 != PDCI_int64_2ebc_io(pads, io, P_MIN_INT64/100, 17)) goto write_err;
  sfwrite(io, tmp, 6);
  sfputc(io, P_EBCDIC_NEWLINE);

  if (19 != PDCI_int64_2ebc_io(pads, io, P_MIN_INT64, 19)) goto write_err;
  sfwrite(io, tmp, 6);
  sfputc(io, P_EBCDIC_NEWLINE);

  for (i = 0; i < 2; i++) {
    if (19 != PDCI_int64_2ebc_io(pads, io, P_MAX_INT64, 19)) goto write_err;
    sfwrite(io, tmp, 6);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  for (i = 0; i < 2; i++) {
    if (20 != PDCI_uint64_2ebc_io(pads, io, P_MAX_UINT64, 20)) goto write_err;
    sfwrite(io, tmp, 5);
    sfputc(io, P_EBCDIC_NEWLINE);
  }

  sfclose(io);
  return 0;

 write_err:
  error(0, "XXX write error occurred");
  sfclose(io);
  return -1;
}
