/*  eltBegin is also available in Plast and Pended predicates. */

int diff(Ppos_t e, Ppos_t b){
  int delta = e.offset - b.offset;
  error(2, "offset = %d\n", delta);
  return delta;
};

Parray seq_t{
  Pint32 [] : Psep('|') && Plast(Pparsecheck(elts[current] > 10 || (diff(eltEnd, begin) > 10))) && Pterm('b');
};

Precord Pstruct entry{
  seq_t seq;
  'b';
};




