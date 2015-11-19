// #include "vanilla.p"

Ptypedef Pstring_ME(:"/(?:[A-Za-z][A-Za-z0-9_\\-]*)/":) PPstring;

Punion Union_1 {
 PPstring v_str_1;
 Puint32 v_int_1;
 Pempty;
 // Equivalent to: Pcompute Puint8 Union_1_Default = 0;
}

Parray Array_1 {
       Union_1[] : Psep(',') && Pterm('|'); 
};

Precord Pstruct sentry_t{
  Union_1 f1;
  ',';
  Union_1 f2;
}

Precord Pstruct entry_t {
  Array_1 data;
  '|';
}

Parray entries_t{
  Array_1[];
};
