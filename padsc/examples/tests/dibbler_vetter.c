#include "dibbler_new.h"

// dibbler_vetter
//
//   usage:  dibbler_vetter [INPUT_FILE [SEQ_MASK [CLEAN_FILE [ERROR_FILE]]]]
//
// Where the defaults are:

#define INPUT_FILE  "../../data/dibbler.10001"
//#define INPUT_FILE  "../../data/dibbler_short"
#define SEQ_MASK    P_CheckAndSet 
#define CLEAN_FILE  "/home/kfisher/esig/dibbler_clean_C"
#define ERROR_FILE  "/home/kfisher/esig/dibbler_errors_C"

//    (SEQ_MASK arg must be numberic; P_CheckAndSet == 7, P_Set == 1)

// dibber_vetter parses input lines from INPUT_FILE according to the
// spec in dibbler_new.p.  For lines that are correct, it outputs
// dibbler lines to CLEAN_FILE, with the following 'cleanup' actions
// applied: (1) phone numbers equal to zero are replaced with blanks.
// All error lines are output to ERROR_FILE without modification.  In
// addition, error messages describing the kind of error and the error
// location are output to stderr.

void cnvServiceTN(service_tn_t *stn){
  if ((some_service_tn_t == stn->tag) && (stn->val.some_service_tn_t == 0)) {
    stn->tag = none_service_tn_t;
  };
  return;
}
void cnvBillingTN(billing_tn_t *stn){
  if ((some_billing_tn_t == stn->tag) && (stn->val.some_billing_tn_t == 0)) {
    stn->tag = none_billing_tn_t;
  };
  return;
}
void cnvNLPServiceTN(nlp_service_tn_t *stn){
  if ((some_nlp_service_tn_t == stn->tag) && (stn->val.some_nlp_service_tn_t == 0)) {
    stn->tag = none_nlp_service_tn_t;
  };
  return;
}
void cnvNLPBillingTN(nlp_billing_tn_t *stn){
  if ((some_nlp_billing_tn_t == stn->tag) && (stn->val.some_nlp_billing_tn_t == 0)) {
    stn->tag = none_nlp_billing_tn_t;
  };
  return;
}
void cnvPhoneNumbers(entry_t *entry){
  cnvServiceTN(&entry->header.service_tn);
  cnvBillingTN(&entry->header.billing_tn);
  cnvNLPServiceTN(&entry->header.nlp_service_tn);
  cnvNLPBillingTN(&entry->header.nlp_billing_tn);
}

int main(int argc, char** argv) {
  P_t                  *pads;
  Pdisc_t               my_disc = Pdefault_disc;
  Pio_disc_t           *io_disc;
  summary_header_t      header;
  summary_header_t_pd   header_pd;
  summary_header_t_m    header_m;
  entry_t               entry;
  entry_t_pd            entry_pd;
  entry_t_m             entry_m;
  char                  *input_name = INPUT_FILE;
  Pbase_m               mask       = SEQ_MASK;
  char                 *error_name = ERROR_FILE;
  char                 *clean_name = CLEAN_FILE;
  Sfio_t*               error_io;
  Sfio_t*               clean_io;

  // output error description/loc but not the additional marked-up error line
  my_disc.e_rep = PerrorRep_Med;

  if (argc >= 2 ) {
    input_name = argv[1];
  }
  if (argc >= 3 ) {
    mask = atoi(argv[2]);
  }
  if (argc >= 4) {
    clean_name = argv[3];
  }
  if (argc >= 5) {
    error_name = argv[4];
  }

  error(0, "Input file %s", input_name);
  error(0, "Sequence mask %d", mask);
  error(0, "    (P_Set == %d)", P_Set);
  error(0, "    (P_CheckAndSet  == %d)", P_CheckAndSet);
  error(0, "Clean file %s", clean_name);
  error(0, "Error file %s", error_name);

  error_io = sfopen(0, error_name, "w");
  clean_io = sfopen(0, clean_name, "w");
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
  summary_header_t_m_init(pads, &header_m, P_CheckAndSet);

  // INIT entry -- must do this for all variable data types
  entry_t_init(pads, &entry);
  entry_t_pd_init(pads, &entry_pd);
  entry_t_m_init(pads, &entry_m, P_CheckAndSet);
  entry_m.events.compoundLevel = SEQ_MASK;

  if (P_ERR == P_io_fopen(pads, input_name)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  // Try to read header
  if (P_OK == summary_header_t_read(pads, &header_m, &header_pd, &header)) {
    error(0, "reading header returned: OK");
    summary_header_t_write2io(pads, clean_io, &header_pd, &header);
  } else {
    // without a valid header we cannot generate a valid CLEAN_FILE
    error(ERROR_FATAL, "reading header returned: error");
  }

  // Try to read each line of data
  while (!P_io_at_eof(pads)) {
    entry_t_read(pads, &entry_m, &entry_pd, &entry);
    if (entry_pd.nerr > 0) {
      entry_t_write2io(pads, error_io, &entry_pd, &entry);
    } else {
      cnvPhoneNumbers(&entry);      
      entry_t_write2io(pads, clean_io, &entry_pd, &entry);
    }
  }
      
  if (P_ERR == P_io_close(pads)) {
    error(ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == P_close(pads)) {
    error(ERROR_FATAL, "*** P_close failed ***");
  }
  sfclose(error_io);
  sfclose(clean_io);
  return 0;
}
