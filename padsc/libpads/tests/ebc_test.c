/*
 *  ebc_test: tests
 *       Pebc_int8_read
 *       Pebc_uint8_read
 *       Pebc_int16_read
 *       Pebc_uint16_read
 *       Pebc_int32_read
 *       Pebc_uint32_read
 *       Pebc_int64_read
 *       Pebc_uint64_read
 */

#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#define NEXT_REC do {\
  if (strncmp(argv1, "norec", 5) == 0) { \
    if (P_ERR == Pe_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) { \
      error(2, "Could not find EOR (newline), ending program"); \
      goto done; \
    } \
  } else { \
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) { \
      error(2, "Could not find EOR (newline), ending program"); \
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
  const char     *argv1;

  my_disc.flags |= (Pflags_t)P_WSPACE_OK;

  if ((argc != 1) && (argc != 2)) {
    goto usage;
  }

  if (argc == 1) {
    argv1 = "fwrec_noseek";
  } else {
    argv1 = argv[1];
  }

  if (strcmp(argv1, "fwrec") == 0) {
    io_disc = P_fwrec_make(0, 25, 1);
  } else if (strcmp(argv1, "ctrec") == 0) {
    io_disc = P_ctrec_make(P_EBCDIC_NEWLINE, 0);
  } else if (strcmp(argv1, "norec") == 0) {
    io_disc = P_norec_make(0);
  } else if (strcmp(argv1, "fwrec_noseek") == 0) {
    io_disc = P_fwrec_noseek_make(0, 25, 1);
  } else if (strcmp(argv1, "ctrec_noseek") == 0) {
    io_disc = P_ctrec_noseek_make(P_EBCDIC_NEWLINE, 0);
  } else if (strcmp(argv1, "norec_noseek") == 0) {
    io_disc = P_norec_noseek_make(0);
  } else {
    goto usage;
  }
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline %s", argv1);
  } else {
    error(0, "\nInstalled IO discipline %s", argv1);
  }

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    return -1;
  }
  if (P_ERR == P_io_fopen(pads, "../../data/ex_data.ebc_test")) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  if (P_OK == Pebc_int8_read(pads, &m, 4, &pd, &i8) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int8_read(pads, &m, 3, &pd, &i8)) {
    error(0, "Read ebc integer: %ld", (long)i8);
    if (i8 != 0) {
      error(0, "XXX failure: should be %ld XXX", (long)0);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int8_read(pads, &m, 0, &pd, &i8) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int8_read(pads, &m, 3, &pd, &i8)) {
    error(0, "Read ebc integer: %ld", (long)i8);
    if (i8 != P_MIN_INT8) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int8_read(pads, &m, 3, &pd, &i8) || pd.errCode != P_RANGE) {
    error(0, "XXX failure: did not get expected RANGE error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int8_read(pads, &m, 3, &pd, &i8)) {
    error(0, "Read ebc integer: %ld", (long)i8);
    if (i8 != P_MAX_INT8) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_uint8_read(pads, &m, 3, &pd, &u8) || pd.errCode != P_RANGE) {
    error(0, "XXX failure: did not get expected RANGE error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_uint8_read(pads, &m, 3, &pd, &u8)) {
    error(0, "Read ebc integer: %lu", (unsigned long)u8);
    if (u8 != P_MAX_UINT8) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT8);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int16_read(pads, &m, 0, &pd, &i16) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int16_read(pads, &m, 5, &pd, &i16)) {
    error(0, "Read ebc integer: %ld", (long)i16);
    if (i16 != P_MIN_INT16) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int16_read(pads, &m, 10, &pd, &i16) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int16_read(pads, &m, 5, &pd, &i16)) {
    error(0, "Read ebc integer: %ld", (long)i16);
    if (i16 != P_MAX_INT16) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_uint16_read(pads, &m, 5, &pd, &u16) || pd.errCode != P_RANGE) {
    error(0, "XXX failure: did not get expected RANGE error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_uint16_read(pads, &m, 5, &pd, &u16)) {
    error(0, "Read ebc integer: %lu", (unsigned long)u16);
    if (u16 != P_MAX_UINT16) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT16);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int32_read(pads, &m, 11, &pd, &i32) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int32_read(pads, &m, 10, &pd, &i32)) {
    error(0, "Read ebc integer: %ld", (long)i32);
    if (i32 != P_MIN_INT32) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MIN_INT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int32_read(pads, &m, 0, &pd, &i32) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int32_read(pads, &m, 10, &pd, &i32)) {
    error(0, "Read ebc integer: %ld", (long)i32);
    if (i32 != P_MAX_INT32) {
      error(0, "XXX failure: should be %ld XXX", (long)P_MAX_INT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_uint32_read(pads, &m, 11, &pd, &u32) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_uint32_read(pads, &m, 10, &pd, &u32)) {
    error(0, "Read ebc integer: %lu", (unsigned long)u32);
    if (u32 != P_MAX_UINT32) {
      error(0, "XXX failure: should be %lu XXX", (unsigned long)P_MAX_UINT32);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int64_read(pads, &m, 19, &pd, &i64) || pd.errCode != P_RANGE) {
    error(0, "XXX failure: did not get expected RANGE error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int64_read(pads, &m, 19, &pd, &i64)) {
    error(0, "Read ebc integer: %lld", (long long)i64);
    if (i64 != P_MIN_INT64) {
      error(0, "XXX failure: should be %lld XXX", (long long)P_MIN_INT64);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_int64_read(pads, &m, 0, &pd, &i64) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_int64_read(pads, &m, 19, &pd, &i64)) {
    error(0, "Read ebc integer: %lld", (long long)i64);
    if (i64 != P_MAX_INT64) {
      error(0, "XXX failure: should be %lld XXX", (long long)P_MAX_INT64);
      return -1;
    }
  } else { return -1; } 
  NEXT_REC;

  if (P_OK == Pebc_uint64_read(pads, &m, 21, &pd, &u64) || pd.errCode != P_BAD_PARAM) {
    error(0, "XXX failure: did not get expected BAD_PARAM error XXX");
    return -1;
  }
  NEXT_REC;

  if (P_OK == Pebc_uint64_read(pads, &m, 20, &pd, &u64)) {
    error(0, "Read ebc integer: %llu", (unsigned long long)u64);
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
