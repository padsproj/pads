/* This file uses an omitted field as a parameter to a later type.
   This means that the later type cannot be writtin out.
   So this file generates a typing error if the -wnone flag is not 
   supplied.  This is not ideal.  Possible fixes:
   1. perform analysis to track dependencies and not omit fields 
      that are required later, while issuing a warning.
   2. improve error message so that problem is clear.
   3. get rid of omit features in lieu of better transformation support. */

Pstruct a_uint32_vbar {
  Pa_uint32 val; '|';
};
Pstruct a_uint64_vbar {
  Pa_uint64 val; '|';
};
Pstruct just_vbar {
  '|';
  Pcompute Pint8 d = 0; /-- padsc should provide dummy field for 'empty' structs
};
Punion opt_a_uint32_vbar {
  a_uint32_vbar yes32;
  just_vbar    no32;
};
Punion opt_a_uint64_vbar {
  a_uint64_vbar yes64;
  just_vbar    no64;
};
Pstruct no_pn_vbar {
  "no_TN|";
  Pcompute Pint8 d = 0; /-- padsc should provide dummy field for 'empty' structs
};
Punion dib_pn_vbar {
  a_uint64_vbar yesPN;
  no_pn_vbar   noPN;
};
Pstruct event {
  Pa_string(:'|':) state;   '|';
  Pa_uint32        tstamp;  '|';
};
Precord Pstruct out_sum_header {
  "0|";
  Pa_uint32       tstamp;
};
Parray eventSeq(:int size:) {
  event [size];
};

int getLength(int numBars){ return (numBars - 4)/2; }

Precord Pstruct out_sum_data_line {
  a_uint32_vbar                 order_num;
  a_uint32_vbar                 order_item;
  dib_pn_vbar                   servicen;
  dib_pn_vbar                   billing_tn;
  a_uint32_vbar                 zip_code;
  dib_pn_vbar                   nlp_service_tn;
  dib_pn_vbar                   nlp_billing_tn;
  Pomit PcountX(:'|',1,0:)      vbars;
  eventSeq(:getLength(vbars):)  events;
  opt_a_uint32_vbar             siid;
  opt_a_uint32_vbar             create_id;
  opt_a_uint64_vbar             rampII;
  a_uint32_vbar                 order_type;
  Pa_uint32                     parent_order;
};
