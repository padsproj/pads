Penum foo {
    S_init,
    S_care,
    S_tpv
};

/*
Ptypedef Puint32 fooInt : fooInt x => {x == 3 || x == 5};

Pstruct fooS{
  Pint i;
};
*/
Punion ubar {
  Pint16 f1;
  //  f_pipe Pfrom('|');
  Pchar f2;
}

Precord Pstruct bar {
  Pint32[] farr : Psep(':') && Pterm('|') && Pended(0);
  //Pint32[] farr : Pterm('|');
  '|'; Pint16 f1;
  '|'; Pint32 f2;
  '|'; Pchar f3;
  '|'; foo   f4;
}

Psource Parray barArray{
  bar[:30];
}

