#include "pads-internal.h"

P_NOGEN

int main(int argc, char** argv) {
  int                i;
  P_t*             pads;
  Pint8_acc       accum8;
  Pint8           key8;
  Pint16_acc      accum16;
  Pint16          key16;
  Pint32_acc      accum32;
  Pint32          key32;
  Pint64_acc      accum64;
  Pint64          key64;

  Pint8_acc       accum8min;
  Pint8           key8min;
  Pint16_acc      accum16min;
  Pint16          key16min;
  Pint32_acc      accum32min;
  Pint32          key32min;
  Pint64_acc      accum64min;
  Pint64          key64min;

  Puint8_acc      accum8u;
  Puint8          key8u;
  Puint16_acc     accum16u;
  Puint16         key16u;
  Puint32_acc     accum32u;
  Puint32         key32u;
  Puint64_acc     accum64u;
  Puint64         key64u;
  Puint64_acc     accum64u20th;
  Puint64         key64u20th;
  Pbase_pd        pd = {0};

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  error(0, "\ninit all the accums");
  if (P_ERR == Pint8_acc_init(pads, &accum8)) {
    error(2, "** accum8 init failed **");
    exit(-1);
  }
  if (P_ERR == Pint16_acc_init(pads, &accum16)) {
    error(2, "** accum16 init failed **");
    exit(-1);
  }
  if (P_ERR == Pint32_acc_init(pads, &accum32)) {
    error(2, "** accum32 init failed **");
    exit(-1);
  }
  if (P_ERR == Pint64_acc_init(pads, &accum64)) {
    error(2, "** accum64 init failed **");
    exit(-1);
  }

  if (P_ERR == Pint8_acc_init(pads, &accum8min)) {
    error(2, "** accum8min init failed **");
    exit(-1);
  }
  if (P_ERR == Pint16_acc_init(pads, &accum16min)) {
    error(2, "** accum16min init failed **");
    exit(-1);
  }
  if (P_ERR == Pint32_acc_init(pads, &accum32min)) {
    error(2, "** accum32min init failed **");
    exit(-1);
  }
  if (P_ERR == Pint64_acc_init(pads, &accum64min)) {
    error(2, "** accum64min init failed **");
    exit(-1);
  }

  if (P_ERR == Puint8_acc_init(pads, &accum8u)) {
    error(2, "** accum8u init failed **");
    exit(-1);
  }
  if (P_ERR == Puint16_acc_init(pads, &accum16u)) {
    error(2, "** accum16u init failed **");
    exit(-1);
  }
  if (P_ERR == Puint32_acc_init(pads, &accum32u)) {
    error(2, "** accum32u init failed **");
    exit(-1);
  }
  if (P_ERR == Puint64_acc_init(pads, &accum64u)) {
    error(2, "** accum64u init failed **");
    exit(-1);
  }
  if (P_ERR == Puint64_acc_init(pads, &accum64u20th)) {
    error(2, "** accum64u20th init failed **");
    exit(-1);
  }

  error(0, "\nadd MIN/MAX vals to all the accums");
  pd.errCode = P_NO_ERR;
  for (i = 0; i < 100000; i++) {
    key8      = P_MAX_INT8;
    key16     = P_MAX_INT16;
    key32     = P_MAX_INT32;
    key64     = P_MAX_INT64;

    key8min   = P_MIN_INT8;
    key16min  = P_MIN_INT16;
    key32min  = P_MIN_INT32;
    key64min  = P_MIN_INT64;

    key8u     = P_MAX_UINT8;
    key16u    = P_MAX_UINT16;
    key32u    = P_MAX_UINT32;
    key64u    = P_MAX_UINT64;
    key64u20th = P_MAX_UINT64 / 20;

    if (P_ERR == Pint8_acc_add(pads, &accum8, &pd, &key8)) {
      error(0, "** accum8 add failed **");
    }
    if (P_ERR == Pint16_acc_add(pads, &accum16, &pd, &key16)) {
      error(0, "** accum16 add failed **");
    }
    if (P_ERR == Pint32_acc_add(pads, &accum32, &pd, &key32)) {
      error(0, "** accum32 add failed **");
    }
    if (P_ERR == Pint64_acc_add(pads, &accum64, &pd, &key64)) {
      error(0, "** accum64 add failed **");
    }

    if (P_ERR == Pint8_acc_add(pads, &accum8min, &pd, &key8min)) {
      error(0, "** accum8min add failed **");
    }
    if (P_ERR == Pint16_acc_add(pads, &accum16min, &pd, &key16min)) {
      error(0, "** accum16min add failed **");
    }
    if (P_ERR == Pint32_acc_add(pads, &accum32min, &pd, &key32min)) {
      error(0, "** accum32min add failed **");
    }
    if (P_ERR == Pint64_acc_add(pads, &accum64min, &pd, &key64min)) {
      error(0, "** accum64min add failed **");
    }

    if (P_ERR == Puint8_acc_add(pads, &accum8u, &pd, &key8u)) {
      error(0, "** accum8u add failed **");
    }
    if (P_ERR == Puint16_acc_add(pads, &accum16u, &pd, &key16u)) {
      error(0, "** accum16u add failed **");
    }
    if (P_ERR == Puint32_acc_add(pads, &accum32u, &pd, &key32u)) {
      error(0, "** accum32u add failed **");
    }
    if (P_ERR == Puint64_acc_add(pads, &accum64u, &pd, &key64u)) {
      error(0, "** accum64u add failed **");
    }
    if (P_ERR == Puint64_acc_add(pads, &accum64u20th, &pd, &key64u20th)) {
      error(0, "** accum64u20th add failed **");
    }
  }
  error(0, "\ndescribe the accums");

  if (P_ERR == Pint8_acc_report(pads, "int8max", 0, 0, &accum8)) {
    error(0, "** accum8 report failed **");
  }
  if (P_ERR == Pint16_acc_report(pads, "int16max", 0, 0, &accum16)) {
    error(0, "** accum16 report failed **");
  }
  if (P_ERR == Pint32_acc_report(pads, "int32max", 0, 0, &accum32)) {
    error(0, "** accum32 report failed **");
  }
  if (P_ERR == Pint64_acc_report(pads, "int64max", 0, 0, &accum64)) {
    error(0, "** accum64 report failed **");
  }

  if (P_ERR == Pint8_acc_report(pads, "int8min", 0, 0, &accum8min)) {
    error(0, "** accum8min report failed **");
  }
  if (P_ERR == Pint16_acc_report(pads, "int16min", 0, 0, &accum16min)) {
    error(0, "** accum16min report failed **");
  }
  if (P_ERR == Pint32_acc_report(pads, "int32min", 0, 0, &accum32min)) {
    error(0, "** accum32min report failed **");
  }
  if (P_ERR == Pint64_acc_report(pads, "int64min", 0, 0, &accum64min)) {
    error(0, "** accum64min report failed **");
  }

  if (P_ERR == Puint8_acc_report(pads, "uint8", 0, 0, &accum8u)) {
    error(0, "** accum8u report failed **");
  }
  if (P_ERR == Puint16_acc_report(pads, "uint16", 0, 0, &accum16u)) {
    error(0, "** accum16u report failed **");
  }
  if (P_ERR == Puint32_acc_report(pads, "uint32", 0, 0, &accum32u)) {
    error(0, "** accum32u report failed **");
  }
  if (P_ERR == Puint64_acc_report(pads, "uint64", 0, 0, &accum64u)) {
    error(0, "** accum64u report failed **");
  }
  if (P_ERR == Puint64_acc_report(pads, "uint64u20th", 0, 0, &accum64u20th)) {
    error(0, "** accum64u20th report failed **");
  }
  error(0, "NB ==> u64 20th = %llu", key64u20th);

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }
  return 0;
}
