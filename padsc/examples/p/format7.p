Precord Pstruct test {
  Pint32 id : id < 100000;     /- identity 
  '|';
  Pint32 ts : ts == 11 * id;   /- time stamp
};

/* variant of test that is not a record type */
Pstruct test_not_rec {
  Pint32 id : id < 100000;     /- identity 
  '|';
  Pint32 ts : ts == 11 * id;   /- time stamp
};

Precord Pstruct test2 {
  test_not_rec bigger;
  '=';
  Pint32 two;
};

Psource Parray myfile {
  test [];
};
