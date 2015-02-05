Parray seq_t{
  Pint32 [] : Psep('|') && Plast(elts[current] > 10) && Pterm('b');
};

Precord Pstruct entry{
  seq_t seq;
  'b';
};




