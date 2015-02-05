#include "dibbler_new2.h"

// dibbler_select_first
//
//   usage:  dibbler_select_first [SELECT_STATE [CLEAN_INPUT_FILE [OUTPUT_FILE]]]
//
// Where the defaults are:

#define SELECT_STATE       "10"
#define CLEAN_INPUT_FILE   "/home/kfisher/esig/dibbler_clean_big_C"
#define OUTPUT_FILE        "/home/kfisher/esig/dibbler_selected_big_C"

// dibber_select_first parses entry lines from CLEAN_INPUT_FILE
// according to the spec in dibbler_new.p.  It does not do any error
// checking, and it only 'sets' entry.h.order_num and state fields in
// entry.events.  For each entry that starts in state
// SELECT_STATE, it outputs order_num to OUTPUT_FILE.

int main(int argc, char** argv) {
  P_t                *pads;
  Pdisc_t             my_disc = Pdefault_disc;
  Pio_disc_t         *io_disc;
  summary_header_t      header;
  summary_header_t_pd   header_pd;
  summary_header_t_m    header_m;
  order_header_1state_t        entry;
  order_header_1state_t_pd     entry_pd;
  order_header_1state_t_m      entry_m;

  char               *select_state = SELECT_STATE;
  char               *input_name   = CLEAN_INPUT_FILE;
  char               *output_name  = OUTPUT_FILE;
  Sfio_t*             output_io;
  size_t              select_state_len;
  size_t              bytes_skipped;

  if (argc >= 2 ) {
    select_state = argv[1];
  }
  if (argc >= 3) {
    input_name = argv[2];
  }
  if (argc >= 4) {
    output_name = argv[3];
  }

  error(0, "Select state %s", select_state);
  error(0, "Clean input file %s", input_name);
  error(0, "Output file %s", output_name);

  select_state_len = strlen(select_state);
  output_io = sfopen(0, output_name, "w");
  io_disc = P_nlrec_make(0);
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline nlrec");
  } else {
    error(0, "\nInstalled IO discipline nlrec");
  }

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(ERROR_FATAL, "*** P_open failed ***");
  }

  summary_header_t_init(pads, &header);
  summary_header_t_pd_init(pads, &header_pd);
  summary_header_t_m_init(pads, &header_m, P_Set);

  // start with Ignore
  order_header_1state_t_m_init(pads, &entry_m, P_Ignore);
  // Do not ignore order_num field
  entry_m.order_num = P_Set;
  // Do not ignore the state field
  entry_m.state = P_Set;

  // Need to do CheckAndSet for union field
  // that might otherwise eat up too much input
  // (e.g. fixed width field with a constraint such as must be digits)
  zip_code_0_t_m_init(pads, &(entry_m.zip_code), P_CheckAndSet);
  entry_m.zip_code.compoundLevel = P_Ignore;

  if (P_ERR == P_io_fopen(pads, input_name)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  // Try to read header
  if (P_OK == summary_header_t_read(pads, &header_m, &header_pd, &header)) {
    error(0, "reading header returned: OK");
    summary_header_t_write2io(pads, output_io, &header_pd, &header);
  } else {
    // something is very wrong, a clean file should have a valid header
    error(ERROR_FATAL, "reading header returned: error");
  }

  // Look for entries that start with select_state
  while (!P_io_at_eof(pads)) {
    // notice there is no error check in this loop
    order_header_1state_t_read(pads, &entry_m, &entry_pd, &entry);
    if (entry.state.len == select_state_len &&
	strncmp(entry.state.str, select_state, select_state_len) == 0) {
      // found one
      sfprintf(output_io, "%lu\n", entry.order_num);
    }
    if (P_ERR == P_io_next_rec(pads, &bytes_skipped)) {
      break;
    }
  }

  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }
  sfclose(output_io);
  return 0;
}
