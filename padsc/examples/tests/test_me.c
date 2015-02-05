#include "pads.h"
#include "me.h"

#define DAT_FILE "../../data/me"

#define P_PROC_DATA(t) do { \
  error(2, "line contains: %s|%s|%s", P_fmt_str(&(t.id1)), P_fmt_str(&(t.id2)), P_fmt_str(&(t.id3))); \
} while (0)

#define SUF(x, s)     x ## s

/* following is generic, can do sed -e 's/ T1 / T2 /' to use other type T2 */

int main(int argc, char** argv) {
  P_t*             pads;
  T1                 t;
  SUF( T1 , _m)      t_m;
  SUF( T1 , _pd)     t_pd;

  P_open(&pads, 0, 0);
  if (P_ERR == P_io_fopen(pads, DAT_FILE)) {
    error(ERROR_FATAL, "*** P_io_fopen failed on file %s ***", DAT_FILE);
  }

  P_INIT_ALL(pads, T1 , t, t_m, t_pd, P_CheckAndSet);

  /*
   * Try to read each line of data
   */

  while (!P_io_at_eof(pads)) {
    if (P_OK == SUF( T1 , _read)(pads, &t_m, &t_pd, &t)) {
      /* do something with the data */
      P_PROC_DATA(t);
    }
  }

  P_CLEANUP_ALL(pads, T1 , t, t_pd);
  P_io_close(pads);
  P_close(pads);
  return 0;
}
