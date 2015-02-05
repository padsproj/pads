Precord Pstruct simple_types {
  Pdate(:'|':) birthdate; '|';
  Pint32 num_accts; '|';
  Pstring_SE(:"/$/":) name;
};
Psource Parray simple_example {
  simple_types [];
};
