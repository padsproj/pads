#include "dibbler_new.h"

// dibbler_select
//
//   usage:  dibbler_select [SELECT_STATE [CLEAN_INPUT_FILE [OUTPUT_FILE]]]
//
// Where the defaults are:

#define SELECT_STATE       "10"
#define CLEAN_INPUT_FILE   "/home/kfisher/esig/dibbler_clean_big_C"
#define OUTPUT_FILE        "/home/kfisher/esig/dibbler_selected_big_C"

// dibber_select parses entry lines from CLEAN_INPUT_FILE according to
// the spec in dibbler_new.p.  It does not do any error checking, and
// it only 'sets' entry.h.order_num and state fields in entry.events.
// For each entry that passes through state SELECT_STATE, it outputs
// order_num to OUTPUT_FILE.

int main(int argc, char** argv) {
  P_t                *pads;
  Pdisc_t             my_disc = Pdefault_disc;
  Pio_disc_t         *io_disc;
  summary_header_t      header;
  summary_header_t_pd   header_pd;
  summary_header_t_m    header_m;
  entry_t             entry;
  entry_t_pd          entry_pd;
  entry_t_m           entry_m;
  char               *select_state = SELECT_STATE;
  char               *input_name   = CLEAN_INPUT_FILE;
  char               *output_name  = OUTPUT_FILE;
  Sfio_t*             output_io;
  int                 i;
  size_t              num_elts;
  size_t              select_state_len;

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
   my_disc.e_rep = PerrorRep_None;
  summary_header_t_init(pads, &header);
  summary_header_t_pd_init(pads, &header_pd);
  summary_header_t_m_init(pads, &header_m, P_Set);

  // INIT entry -- must do this for all variable data types
  entry_t_init(pads, &entry);
  entry_t_pd_init(pads, &entry_pd);

  // start with Ignore
  entry_t_m_init(pads, &entry_m, P_Ignore);
  // Do not ignore order_num field
  entry_m.header.order_num = P_Set;
  // Do not ignore state fields
  entry_m.events.element.state = P_Set;

  // Need to check union fields to choose the right arm
  zip_code_t_m_init(pads, &entry_m.header.zip_code, P_BothCheck);
  entry_m.header.zip_code.compoundLevel = P_Ignore;


#if 0
  // Need to do CheckAndSet for union field (zip_code) ???
  zip_code_t_m_init(pads, &entry_m.header.zip_code, P_CheckAndSet);
  entry_m.header.zip_code.compoundLevel = P_Ignore;
#endif

#if 0
  // start with P_Set
  entry_t_m_init(pads, &entry_m, P_Set);  
  // turn off setting of timestamp fields in elements
  entry_m.events.element.tstamp = P_Ignore;  
  // turn off setting for entire header
  order_header_t_m_init(pads, &(entry_m.header), P_Set);
  zip_code_t_m_init(pads, &entry_m.header.zip_code, P_CheckAndSet);  // Necessary for proper parsing of union
  entry_m.header.zip_code.compoundLevel = P_Ignore;
  // turn back on setting of header's order_num field
  entry_m.header.order_num = P_Set;
#endif

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

  // Look for entries that pass through select_state
  while (!P_io_at_eof(pads)) {
    // notice there is no error check in this loop
    entry_t_read(pads, &entry_m, &entry_pd, &entry);
    num_elts = entry.events.length;
    for (i = 0; i < num_elts; i++) {
      event_t *elt = &(entry.events.elts[i]);
      if (elt->state.len == select_state_len && 
	  strncmp(elt->state.str, select_state, select_state_len) == 0) {
	// found one
	sfprintf(output_io, "%lu\n", entry.header.order_num);
	break; // exit for loop
      }
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
