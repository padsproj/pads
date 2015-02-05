Pstruct tuple_t {
  '(';
  Pint8 x;
  ',';
  Pint8 y;
  ')';
};

Precord Parray entry_t{
 tuple_t[];
}

Psource Parray entries_t {
	entry_t[];
};
