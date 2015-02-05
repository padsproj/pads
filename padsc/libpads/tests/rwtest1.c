/*
 *  rwtest1: Test var-length ascii read/write functions
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#ifndef PDCI_MacroArg2String
#define PDCI_MacroArg2String(s) #s
#endif

#define CHECK_EOF do { \
  if (P_io_at_eof(pads)) { \
    error(0, "Main program found eof"); \
    break; \
  } \
} while(0)

#define NEXT_REC do { \
  if (strncmp(argv[1], "norec", 5) == 0) { \
    if (P_ERR == Pa_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) { \
      error(2|ERROR_FATAL, "Could not find EOR (newline), ending program"); \
    } \
  } else { \
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) { \
      error(2|ERROR_FATAL, "Could not find EOR (newline), ending program"); \
    } \
  } \
  if (bytes_skipped != 0) { \
    error(2|ERROR_FATAL, "Bytes skipped should be 0, got %d, ending program", bytes_skipped); \
  } \
} while(0)

#define READ1(int_type, ivar, expect, fmt) do { \
  CHECK_EOF; \
  if (P_ERR == Pa_ ## int_type ## _read(pads, &m, &pd, &ivar)) { \
    error(2|ERROR_FATAL, "Failed to read " PDCI_MacroArg2String(int_type)); \
  } \
  if (ivar != expect) { \
    error(2|ERROR_FATAL, "Expected %" fmt ", found %" fmt, expect, ivar); \
  } \
  NEXT_REC; \
} while(0)

#define WRITE1(int_type, ivar) do { \
  if (-1 == Pa_ ## int_type ## _write2io(pads, io, &pd, &ivar)) { \
    error(2|ERROR_FATAL, "Failed to write " PDCI_MacroArg2String(int_type)); \
  } \
  if (-1 == sfprintf(io, "\n")) { \
    error(2|ERROR_FATAL, "Failed to write newline"); \
  } \
} while(0)

int main(int argc, char** argv) {
  P_t*          pads;
  Pio_disc_t*  io_disc;
  Pint8        i8;
  Pint16       i16;
  Pint32       i32;
  Pint64       i64;
  Puint8       u8;
  Puint16      u16;
  Puint32      u32;
  Puint64      u64;
  Pbase_m      m     = P_CheckAndSet;
  Pbase_pd     pd;
  Pdisc_t      my_disc = Pdefault_disc;
  size_t          bytes_skipped;
  Sfio_t         *io;
  char           *outf = "tmp/rwtest.write";

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

  if (argc != 2) {
    goto usage;
  }

  if (strcmp(argv[1], "nlrec") == 0) {
    io_disc = P_nlrec_make(0);
  } else if (strcmp(argv[1], "norec") == 0) {
    io_disc = P_norec_make(0);
  } else if (strcmp(argv[1], "nlrec_noseek") == 0) {
    io_disc = P_nlrec_noseek_make(0);
  } else if (strcmp(argv[1], "norec_noseek") == 0) {
    io_disc = P_norec_noseek_make(0);
  } else {
    goto usage;
  }
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline %s", argv[1]);
  } else {
    error(0, "\nInstalled IO discipline %s", argv[1]);
  }

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2|ERROR_FATAL, "*** P_libopen failed ***");
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.rwtest1")) {
    error(2|ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  if (!(io = sfopen(NiL, outf, "w"))) {
    P_SYSERR1(pads->disc, "Failed to open output file \"%s\" for writing", outf);
  }
  /*
   * XXX Process the data here XXX
   */
  while (1) {
    /* read then write all the min/max integers */
    READ1 (int8,   i8,  P_MIN_INT8,   "d");
    WRITE1(int8,   i8);
    READ1 (int8,   i8,  P_MAX_INT8,   "d");
    WRITE1(int8,   i8);
    READ1 (uint8,  u8,  P_MAX_UINT8,  "u");
    WRITE1(uint8,  u8);

    READ1 (int16,  i16, P_MIN_INT16,   "d");
    WRITE1(int16,  i16);
    READ1 (int16,  i16, P_MAX_INT16,   "d");
    WRITE1(int16,  i16);
    READ1 (uint16, u16, P_MAX_UINT16,  "u");
    WRITE1(uint16, u16);

    READ1 (int32,  i32, P_MIN_INT32,   "ld");
    WRITE1(int32,  i32);
    READ1 (int32,  i32, P_MAX_INT32,   "ld");
    WRITE1(int32,  i32);
    READ1 (uint32, u32, P_MAX_UINT32,  "lu");
    WRITE1(uint32, u32);

    READ1 (int64,  i64, P_MIN_INT64,   "lld");
    WRITE1(int64,  i64);
    READ1 (int64,  i64, P_MAX_INT64,   "lld");
    WRITE1(int64,  i64);
    READ1 (uint64, u64, P_MAX_UINT64,  "llu");
    WRITE1(uint64, u64);

    if (P_ERR == P_io_close(pads)) {
      error(2|ERROR_FATAL, "*** P_io_close failed ***");
    }

    sfclose(io);

    if (P_ERR == P_io_fopen(pads, outf)) {
      error(2|ERROR_FATAL, "*** P_io_fopen failed for file %s ***", outf);
    }

    /* read all the min/max integers */
    READ1 (int8,   i8,  P_MIN_INT8,   "d");
    READ1 (int8,   i8,  P_MAX_INT8,   "d");
    READ1 (uint8,  u8,  P_MAX_UINT8,  "u");

    READ1 (int16,  i16, P_MIN_INT16,   "d");
    READ1 (int16,  i16, P_MAX_INT16,   "d");
    READ1 (uint16, u16, P_MAX_UINT16,  "u");

    READ1 (int32,  i32, P_MIN_INT32,   "ld");
    READ1 (int32,  i32, P_MAX_INT32,   "ld");
    READ1 (uint32, u32, P_MAX_UINT32,  "lu");

    READ1 (int64,  i64, P_MIN_INT64,   "lld");
    READ1 (int64,  i64, P_MAX_INT64,   "lld");
    READ1 (uint64, u64, P_MAX_UINT64,  "llu");
    break;
  }

  if (P_ERR == P_io_close(pads)) {
    error(2|ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == P_close(pads)) {
    error(2|ERROR_FATAL, "*** P_close failed ***");
  }

  return 0;

 usage:
  error(2, "\nUsage: %s <io-disc-name>\n\n\twhere <io-disc-name> is one of: nlrec, norec, nlrec_noseek, norec_noseek\n", argv[0]);
  return -1;
}
