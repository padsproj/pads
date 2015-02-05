Pstruct no_pn {
  "no_TN";
  Pcompute Puint32 d = 0;
};

Punion dib_pn {
  Puint64           yesPN;
  no_pn             noPN;
  Pcompute Puint32  emptyPN = 0;
};

Pstruct no_ramp {
  "no_ii";
  Puint64 id;
};

Punion dib_ramp {
  Puint64  yesRamp;
  Pint64   negRamp;
  no_ramp  noRamp;
};

Pstruct event {
  Pstring(:'|':) state;   '|';
  Puint32        tstamp;  
};

Ptypedef Pchar zipSep_t : zipSep_t x => {x == '-' || x == '/' || x == ' '};

Pstruct extended_zip{
  Puint32 zip;
  zipSep_t sep;
  Puint32 suffix;
};

Punion zip_code_t{
  extended_zip extendedZip;
  Puint32      smallZip;
  Puint64      largeZip;
  Pcompute Pint32 defZip = 0;    
};

Precord Pstruct out_sum_header {
  "0|";
  Puint32       tstamp;
};
Parray eventSeq {
  event [] : Psep('|');
};

Pstruct header {
       Puint32             order_num;
 '|';  Puint32             att_order_num;
 '|';  Puint32             ord_version;
 '|';  dib_pn              servicen;
 '|';  dib_pn              billing_tn;
 '|';  dib_pn              nlp_service_tn;
 '|';  dib_pn              nlp_billing_tn;
 '|';  zip_code_t          zip_code;
 '|';  dib_ramp            ramp;
 '|';  Pstring(:'|':)      unknown1;
 '|';  Puint32             order_type;
 '|';  Pstring(:'|':)      unknown2;
 '|';  Pstring(:'|':)      unknown3;
 '|';
};

Precord Pstruct out_sum_data_line {
  header           h;
  eventSeq         events;
};

Psource Parray entries_t {
  out_sum_data_line[];
}
/*
Psource Pstruct out_sum{
  out_sum_header h;
  entries_t      es;
}
*/