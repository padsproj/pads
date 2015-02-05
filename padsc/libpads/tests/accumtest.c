#include "pads-internal.h"

P_NOGEN

const char* names[] = {
  "foo",
  "bobozot",
  "hi there Greg",
  "testing" ,
  "woo hoo hoo hoo",
  "link",
  "a",
  "nimbus 200",
  "bjork bjork bjorken",
  "mr ed",
  "frankly my dear",
  "zot",
}; 

const char* mymap(Pint32 v) {
  int idx = (v + 20)/10; /* -20 -> 0 ; 90 -> 11 */
  return names[idx];
}

int main(int argc, char** argv) {
  int                i;
  P_t*             pads;
  Pdisc_t*        disc = 0;
  Pint32_acc      accum;
  Pint32          key1;
  Pbase_pd        pd = {0};

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  if (!disc) {
    disc = pads->disc;
  }
  error(0, "\n\ninit the accum\n");
  if (P_ERR == Pint32_acc_init(pads, &accum)) {
    error(2, "** init failed **");
    exit(-1);
  }

  error(0, "\n\nadd vals to the accum\n");
  pd.errCode = P_NO_ERR;
  for (i = 0; i < 100000; i++) {
    for (key1 = -20; key1 < 100; key1 += 10) {
      if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
      if (key1 <= 10) {
	if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	  error(0, "** accum_add failed **");
	}
      }
      if (key1 <= 50) {
	if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	  error(0, "** accum_add failed **");
	}
      }
    }
  }
  pd.errCode = P_INVALID_A_NUM;
  for (i = 0; i < 100000; i++) {
    for (key1 = -100; key1 < -40; key1 += 10) {
      if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
    }
  }
  error(0, "\n\ndescribe the accum\n");
  if (P_ERR == Pint32_acc_report (pads, "foo_prefix", 0, 0, &accum)) {
    error(0, "** accum_report failed **");
  }


  error(0, "\n\nadd MORE vals to the accum\n");
  pd.errCode = P_NO_ERR;
  for (i = 0; i < 100000; i++) {
    for (key1 = -20; key1 < 100; key1 += 10) {
      if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
      if (key1 <= 10) {
	if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	  error(0, "** accum_add failed **");
	}
      }
      if (key1 <= 50) {
	if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	  error(0, "** accum_add failed **");
	}
      }
    }
  }
  pd.errCode = P_INVALID_A_NUM;
  for (i = 0; i < 100000; i++) {
    for (key1 = -100; key1 < -40; key1 += 10) {
      if (P_ERR == Pint32_acc_add(pads, &accum, &pd, &key1)) {
	error(0, "** accum_add failed **");
      }
    }
  }
  error(0, "\n\ndescribe the accum\n");
  if (P_ERR == Pint32_acc_report_map (pads, "foo", "union tag", 0, mymap, &accum)) {
    error(0, "** accum_report failed **");
  }

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }
  return 0;
}
