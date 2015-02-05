// use with, e.g., fwrec(0,4,0)


Precord Pstruct data_header {
  Pendian Pb_int32 recs : recs < 1000;
};

Precord Pstruct data_elt {
  Pb_int32 x;
};

Parray data_seq(:int recs:) {
  data_elt [recs];
};

Pstruct data_file {
  data_header            hdr;
  data_seq(:hdr.recs:)   seq;
};

