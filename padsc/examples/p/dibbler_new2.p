/*@FILE @LEFT dibbler_new.tex */

/* add these as a Pase base type */
Ptypedef Puint64 pn_t;

Ptypedef Pchar zipSep_t : 
   zipSep_t x => {x == '-' || x == '/' || x == ' '};

Pstruct extended_zip_t{
  Puint32 zip;
  zipSep_t sep;
  Puint32 suffix;
};

Punion Pzip{
  extended_zip_t extendedZip;
  Puint32        smallZip;
  Puint64        largeZip;
};

/*@BEGIN dibbler_new.tex */
Precord Pstruct summary_header_t {
  "0|";
  Puint32       tstamp;
};

Pstruct no_ramp_t {
  "no_ii";
  Puint64 id;
};

Punion dib_ramp_t {
  Pint64     ramp;
  no_ramp_t  genRamp;
};

Pstruct order_header_t {
       Puint32             order_num;
 '|';  Puint32             att_order_num;
 '|';  Puint32             ord_version;
 '|';  Popt pn_t           service_tn;
 '|';  Popt pn_t           billing_tn;
 '|';  Popt pn_t           nlp_service_tn;
 '|';  Popt pn_t           nlp_billing_tn;
 '|';  Popt Pzip           zip_code;
 '|';  dib_ramp_t          ramp;
 '|';  Pstring(:'|':)      order_type;
 '|';  Puint32             order_details;
 '|';  Pstring(:'|':)      unused;
 '|';  Pstring(:'|':)      stream;
 '|';
};

Pstruct order_header_1state_t {
       Puint32             order_num;
 '|';  Puint32             att_order_num;
 '|';  Puint32             ord_version;
 '|';  Popt pn_t           service_tn;
 '|';  Popt pn_t           billing_tn;
 '|';  Popt pn_t           nlp_service_tn;
 '|';  Popt pn_t           nlp_billing_tn;
 '|';  Popt Pzip           zip_code;
 '|';  dib_ramp_t          ramp;
 '|';  Pstring(:'|':)      order_type;
 '|';  Puint32             order_details;
 '|';  Pstring(:'|':)      unused;
 '|';  Pstring(:'|':)      stream;
 '|';  Pstring(:'|':)      state;
};

Pstruct event_t {
  Pstring(:'|':) state;   '|';
  Puint32        tstamp;
};

Parray eventSeq {
  event_t[] : Psep('|') /* && Pterm(Peor) */;
} Pwhere {
  Pforall (i Pin [0..length-2] : 
           (elts[i].tstamp <= elts[i+1].tstamp));
};


Precord Pstruct entry_t {
  order_header_t  header;
  eventSeq        events;
};

Parray entries_t {
  entry_t[];
};

Psource Pstruct out_sum{
  summary_header_t  h;
  entries_t         es;
};
/*@END dibbler_new.tex */


