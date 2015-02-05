#include "pads-internal.h"

P_NOGEN

static const char* names[] = {
  "bob",
  "kathleen",
  "foo",
  "foobar",
  "ba",
  "bar",
  "sam I am",
  "cat in the hat",
  "a",
  ""
};

int main(int argc, char** argv) {
  char*        nm;
  int                i;
  P_t*             pads;
  Pstring_acc     accum;
  Pstring         key1;
  Pbase_pd        pd = {0};

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  error(0, "\ninit the accum");
  if (P_ERR == Pstring_acc_init(pads, &accum)) {
    error(2, "** init failed **");
    exit(-1);
  }

  error(0, "\nadd vals to the accum");
  pd.errCode = P_NO_ERR;
  for (i = 0; i < 100000; i++) {
    nm = (char*)names[i % 10];
    key1.str = nm;
    key1.len = strlen(nm);
    if (P_ERR == Pstring_acc_add(pads, &accum, &pd, &key1)) {
      error(0, "** accum_add failed **");
    }
    if (i % 10 < 3) {
      if (P_ERR == Pstring_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
    }
    if (i % 10 < 7) {
      if (P_ERR == Pstring_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
    }
  }
  pd.errCode = P_CHAR_LIT_NOT_FOUND; /* typical error for string term by char lit */
  for (i = 0; i < 100000; i++) {
    nm = (char*)names[i % 10];
    key1.str = nm;
    key1.len = strlen(nm);
    if (P_ERR == Pstring_acc_add(pads, &accum, &pd, &key1)) {
      error(0, "** accum_add failed **");
    }
  }
  error(0, "\ndescribe the accum");
  if (P_ERR == Pstring_acc_report(pads, "foo_prefix", 0, 0, &accum)) {
    error(0, "** accum_report failed **");
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }
  return 0;
}
