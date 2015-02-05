Ptypedef Pstring_ME(:"/([A-Za-z][A-Za-z0-9_\\-]*)/":) PPstring;

Punion Union_1 {
 PPstring v_str_1;
 Puint32 v_int_1;
 Pempty;
}

Precord Parray Array_1 {
       Union_1[] : Psep(',') && Pterm('|');
};
