Precord Pstruct simple2_types {
  Ptimestamp(:'|':) birthtimestamp; '|';
  Ptime(:'|':) birthtime; '|';
  Pdate(:'|':) birthdate : birthtime + birthdate == birthtimestamp; '|';
  Pint32 num_accts; '|';
  Pstring_SE(:"/$/":) name;
};
Psource Parray simple2_example {
  simple2_types [];
};
