#include "pads-internal.h" /* for testing - normally do not include internal */
P_NOGEN
#include <stdio.h>

int main(int argc, char** argv) {
  char fname[1000];
  char* h;
  Sfio_t* io;
  Pint32   header = 3;
  Pint32   val1   = 1;
  Pint32   val2   = 2;
  Pint32   val3   = 3;

  h = getenv("HOSTSHORT");
  sprintf(fname, "../../../examples/data/endian.%s", h);
  printf("fname = %s\n", fname);
  io = sfopen(0, fname, "w");
  sfwrite(io, (void*)&header, sizeof(header));
  sfwrite(io, (void*)&val1,   sizeof(val1));
  sfwrite(io, (void*)&val2,   sizeof(val2));
  sfwrite(io, (void*)&val3,   sizeof(val3));
  sfclose(io);
  return 0;
}
