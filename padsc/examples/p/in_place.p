Pstruct foo(:Puint32 l:){
  Puint8 c;
  '|';
  Pcompute int f = l + 1;
  Puint8 [f] ip  : Psep('.') && Pterm(Pnosep)  && Plast(elts[current] == c); /- resolved ip address
  '|';
  Pchar d;
};

Precord Pstruct bar{
  Puint32 x;
  '|';
  foo(:x:) b;
};
