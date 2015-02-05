Precord Penum orderStates {
    S_init,
    S_lec = 2,
    S_care,
    S_for Pfrom("for") = 10,
    S_if  Pfrom("if"),
    S_tpv = 5
};

Psource Parray enums {
  orderStates[];
}
