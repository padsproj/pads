#include "pads.h"
#include "from.h"

int main(int argc, char** argv) {
  P_t*              pads;
  out_sum_data_line_t d;

  if (P_ERR == P_open(&pads, 0, 0)) {
    error(2, "*** P_open failed ***");
    exit(-1);
  }
  if (P_ERR == P_io_fopen(pads, "../../data/from")) {
    error(2, "*** P_io_fopen failed ***");
    exit(-1);
  }

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    Perror_t res;
    int i;
    res= out_sum_data_line_t_read(pads, 0, 0, &d);

    if (res == P_OK) {
      printf("Record okay:\t");
    } else {
      printf("Record not okay:\t");
    }
    printf("%d %d\n", d.order_item, d.create_id);
  }

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
