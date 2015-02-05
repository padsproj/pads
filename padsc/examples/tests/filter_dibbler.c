/*@FILE@CENTER dibbler_filter.tex */
#include "dibbler_new.h"
#define SEQ_MASK P_CheckAndSet
#define ERR_FILE sfstderr
#define CLEAN_FILE sfstdout
#define entry_t_verify is_entry_t

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
/*@BEGIN dibbler_filter.tex */
  P_t                  *p;
/*@END dibbler_filter.tex */
  Pio_disc_t           *io_disc;
  summary_header_t     header;
  summary_header_t_pd  header_pd;
  summary_header_t_m   header_m;
/*@BEGIN dibbler_filter.tex */
  entry_t              entry;
  entry_t_pd           pd;
  entry_t_m            mask;
/*@END dibbler_filter.tex */
  char                 *fname = "../../data/dibbler_short";
  char                 *errname = "/home/kfisher/esig/dibbler_errors";
  char                 *cleanname  = "/home/kfisher/esig/dibbler_clean";
  Sfio_t*              errfile;
  Sfio_t*              cleanfile;
  Pbase_m              amask = SEQ_MASK;
  
  errfile = sfopen(0, errname, "rw");
  cleanfile = sfopen(0, cleanname, "rw");

  if (argc >= 2 ) {
    fname = argv[1];
  }
  error(0, "\nUsing input file %s", fname);

  if (argc >= 3 ) {
    amask = atoi(argv[2]);
  }
  error(0, "\nUsing mask %d", amask);
  error(0, "\nset mask: %d", P_Set);
  error(0, "\ncheck and set mask: %d", P_CheckAndSet);

  io_disc = P_nlrec_noseek_make(0);
  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline nlrec_noseek");
  } else {
    error(0, "\nInstalled IO discipline nlrec_noseek");
  }

  if (P_ERR == P_open(&p, 0, io_disc)) {
    error(2, "*** P_open failed ***");
    return -1;
  }

  /*@BEGIN dibbler_filter.tex*/
  /*@INSERT
    ...
  P_open(&p, 0, 0); 
  P_io_fopen(p, "dibbler/data/2004.11.11");
      ...
   */
  /*@END dibbler_filter.tex*/
  summary_header_t_init(p, &header);
  summary_header_t_pd_init(p, &header_pd);
  summary_header_t_m_init(p, &header_m, P_CheckAndSet);


  /* INIT entry -- must do this for all variable data types */
  entry_t_init(p, &entry);
  entry_t_pd_init(p, &pd);

  /*@BEGIN dibbler_filter.tex */
  entry_t_m_init(p, &mask, P_CheckAndSet);
  mask.events.compoundLevel = P_Set;
  /*@INSERT
    ...
   */
  /*@END dibbler_filter.tex */

  if (P_ERR == P_io_fopen(p, fname)) {
    error(2, "*** P_io_fopen failed ***");
    return -1;
  }

  /*
   * Try to read header
   */

  if (P_OK == summary_header_t_read(p, &header_m, &header_pd, &header)) {
    error(0, "reading header returned: OK");
    summary_header_t_write2io(p, CLEAN_FILE, &header_pd, &header);
  } else {
    error(2, "reading header returned: error");
  }

  /*
   * Try to read each line of data
   */
  /*@BEGIN dibbler_filter.tex */
  while (!P_io_at_eof(p)) {
    entry_t_read(p, &mask, &pd, &entry);
    if (pd.nerr > 0) {
      entry_t_write2io(p, ERR_FILE, &pd, &entry);
    } else {
      cnvPhoneNumbers(&entry);      
      if (entry_t_verify(&entry)) {
        entry_t_write2io(p, CLEAN_FILE, &pd, &entry);
      } else {
	error(2, "Data transform failed.");
      }
    }
  }
  /*@END dibbler_filter.tex */      

  if (P_ERR == P_io_close(p)) {
    error(2, "*** P_io_close failed ***");
    return -1;
  }

  if (P_ERR == P_close(p)) {
    error(2, "*** P_close failed ***");
    return -1;
  }

  return 0;
}
