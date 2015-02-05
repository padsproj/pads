/*
 *  libtest2: Test binary read functions
 */


#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

#include <stdio.h>

/* Remove comments to see classic example of a case where mixing binary data and newlines can fail */
/* #define USE_NLREC */

int main(int argc, char** argv) {
  /* int             ctr; */
  /* size_t          n; */
  /* unsigned char   c; */
  char fname[1000];
  char* h;
  int rev = 0;
  P_t*            pads;
  Pio_disc_t*     io_disc;
  Pint8           i1;
  Pint16          i2;
  Pint32          i4;
  Pint64          i8;
  Puint8          ui1;
  Puint16         ui2;
  Puint32         ui4;
  Puint64         ui8;
  Pbase_m         m    = P_CheckAndSet;
  Pbase_pd        pd;
  Pdisc_t         my_disc = Pdefault_disc;
  size_t          bytes_skipped;
  unsigned long   ultmp;

#ifdef USE_NLREC
  error(0, "\nUsing PADSC IO discipline nlrec_noseek\n\n");
  io_disc = P_nlrec_noseek_make(0);
#else
  error(0, "\nUsing PADSC IO discipline norec\n\n");
  io_disc = P_norec_make(0);
#endif

  if (argc >= 2) {
    h = argv[1];
  } else {
    h = getenv("AST_ARCH");
  }
  if (argc >= 3 && strcmp(argv[2], "rev") == 0) {
    rev = 1;
  }
  sprintf(fname, "../../data/ex_data.libtest2.%s", h);
  error(0, "fname = %s    rev = %d\n", fname, rev);

  if (P_ERR == P_libopen(&pads, &my_disc, io_disc, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }

  switch (pads->m_endian) {
  case PbigEndian:
    my_disc.d_endian = rev ? PlittleEndian : PbigEndian;
    break;
  case PlittleEndian:
    my_disc.d_endian = rev ? PbigEndian : PlittleEndian;
    break;
  }

  if (P_ERR == P_io_fopen(pads, fname)) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  while (1) {
    if (P_io_at_eof(pads)) {
      error(0, "Main program found eof");
      break;
    }

    if (P_ERR == Pb_int8_read(pads, &m, &pd, &i1)) {
      goto check_newline;
    } else {
      error(0, "Read bint8  : %ld", (long)i1);
    }
    if (P_ERR == Pb_uint8_read(pads, &m, &pd, &ui1)) {
      goto check_newline;
    } else {
      error(0, "Read buint8 : %lu", ui1);
    }

    if (P_ERR == Pb_int16_read(pads, &m, &pd, &i2)) {
      goto check_newline;
    } else {
      error(0, "Read bint16  : %ld", (long)i2);
    }
    if (P_ERR == Pb_uint16_read(pads, &m, &pd, &ui2)) {
      goto check_newline;
    } else {
      error(0, "Read buint16 : %lu", (unsigned long)ui2);
    }
    if (P_ERR == Pb_int32_read(pads, &m, &pd, &i4)) {
      goto check_newline;
    } else {
      error(0, "Read bint32  : %ld", (long)i4);
    }
    if (P_ERR == Pb_uint32_read(pads, &m, &pd, &ui4)) {
      goto check_newline;
    } else {
      error(0, "Read buint32 : %lu", (unsigned long)ui4);
    }
    if (P_ERR == Pb_int64_read(pads, &m, &pd, &i8)) {
      goto check_newline;
    } else {
      error(0, "Read bint64  : %lld", i8);
    }
    if (P_ERR == Pb_uint64_read(pads, &m, &pd, &ui8)) {
      goto check_newline;
    } else {
      error(0, "Read buint64 : %llu", ui8);
    }

  check_newline:
#ifdef USE_NLREC
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      error(2, "Could not find EOR (newline), ending program");
      goto done;
    }
#else
    if (P_ERR == Pa_char_lit_scan1(pads, '\n', 1, 0, &bytes_skipped)) {
      error(2, "Could not find newline, ending program");
      break;
    }
#endif
    ultmp = bytes_skipped;
    error(0, "bytes_skipped to find EOR/newline = %ld", ultmp);
  }

#ifdef USE_NLREC
 done:
#endif
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
