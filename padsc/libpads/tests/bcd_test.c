/*
 *  bcd_test: tests
 *       Pbcd_int8_read
 *       Pbcd_uint8_read
 *       Pbcd_int16_read
 *       Pbcd_uint16_read
 *       Pbcd_int32_read
 *       Pbcd_uint32_read
 *       Pbcd_int64_read
 *       Pbcd_uint64_read
 */

#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#define NEXT_REC do {\
  if (strncmp(argv[1], "norec", 5) == 0) { \
    if (P_ERR == Pe_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) { \
      error(2, "Could not find EOR (0xFF), ending program"); \
      goto done; \
    } \
  } else { \
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) { \
      error(2, "Could not find EOR (OxFF), ending program"); \
      goto done; \
    } \
  } \
  ultmp = bytes_skipped; \
  error(0, "next_rec returned bytes_skipped = %ld", ultmp); \
} while (0)

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
  Pdisc_t      my_disc = Pdefault_disc;
  Pbase_m      m       = P_CheckAndSet;
  Pbase_pd     pd;
  size_t          bytes_skipped;
  unsigned long   ultmp;

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

  if (argc != 2) {
    goto usage;
  }

  if (strcmp(argv[1], "fwrec") == 0) {
    io_disc = P_fwrec_make(0, 20, 1);
  } else if (strcmp(argv[1], "ctrec") == 0) {
    io_disc = P_ctrec_make(0xFF, 0);
  } else if (strcmp(argv[1], "norec") == 0) {
    io_disc = P_norec_make(0);
  } else if (strcmp(argv[1], "fwrec_noseek") == 0) {
    io_disc = P_fwrec_noseek_make(0, 20, 1);
  } else if (strcmp(argv[1], "ctrec_noseek") == 0) {
    io_disc = P_ctrec_noseek_make(0xFF, 0);
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
    error(2, "*** P_libopen failed ***");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.bcd_test")) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  if (P_OK == Pbcd_int8_read(pads, &m, &pd, &i8, 3)) {
    error(0, "Read bcd integer: %ld", (long)i8);
    if (i8 != 0) {
      error(0, "XXX failure: should be %ld XXX", (long)0);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int8_read(pads, &m, &pd, &i8, 3)) {
    error(0, "Read bcd integer: %ld", (long)i8);
    if (i8 != P_MIN_INT8) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int8_read(pads, &m, &pd, &i8, 3)) {
    error(0, "Read bcd integer: %ld", (long)i8);
    if (i8 != P_MAX_INT8) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_uint8_read(pads, &m, &pd, &u8, 3)) {
    error(0, "Read bcd integer: %lu", (unsigned long)u8);
    if (u8 != P_MAX_UINT8) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int16_read(pads, &m, &pd, &i16, 5)) {
    error(0, "Read bcd integer: %ld", (long)i16);
    if (i16 != P_MIN_INT16) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int16_read(pads, &m, &pd, &i16, 5)) {
    error(0, "Read bcd integer: %ld", (long)i16);
    if (i16 != P_MAX_INT16) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_uint16_read(pads, &m, &pd, &u16, 5)) {
    error(0, "Read bcd integer: %lu", (unsigned long)u16);
    if (u16 != P_MAX_UINT16) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int32_read(pads, &m, &pd, &i32, 11)) {
    error(0, "Read bcd integer: %ld", (long)i32);
    if (i32 != P_MIN_INT32) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int32_read(pads, &m, &pd, &i32, 10)) {
    error(0, "Read bcd integer: %ld", (long)i32);
    if (i32 != P_MAX_INT32) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_uint32_read(pads, &m, &pd, &u32, 10)) {
    error(0, "Read bcd integer: %lu", (unsigned long)u32);
    if (u32 != P_MAX_UINT32) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int64_read(pads, &m, &pd, &i64, 19)) {
    error(0, "Read bcd integer: %lld", (long long)i64);
    if (i64 != P_MIN_INT64) {
      error(0, "XXX failure: should be %lld XXX", (long long)P_MIN_INT64);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_int64_read(pads, &m, &pd, &i64, 19)) {
    error(0, "Read bcd integer: %lld", (long long)i64);
    if (i64 != P_MAX_INT64) {
      error(0, "XXX failure: should be %lld XXX", (long long)P_MAX_INT64);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pbcd_uint64_read(pads, &m, &pd, &u64, 20)) {
    error(0, "Read bcd integer: %llu", (unsigned long long)u64);
    if (u64 != P_MAX_UINT64) {
      error(0, "XXX failure: should be %llu XXX", (unsigned long long)P_MAX_UINT64);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

 done:
  if (P_ERR == P_io_close(pads)) {
    error(2, "*** P_io_close failed ***");
    return -1;
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    return -1;
  }

  return 0;

 usage:
  error(2, "\nUsage: %s <io-disc-name>\n\n\twhere <io-disc-name> is one of: fwrec, ctrec, norec, fwrec_noseek, ctrec_noseek, norec_noseek\n", argv[0]);
  return -1;
}
