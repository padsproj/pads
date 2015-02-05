Parray a1 {
  Pchar [] : Pterm('x');
};
Parray a2 {
  Pchar [] : Pterm('y');
};
Plongest Punion test {
  a1         arm1;
  a2         arm2;
};
Precord Pstruct rec {
  test                   longest;
  Pstring_ME(:"/.*/":)   remainder;
};

Precord Pstruct recfoo {
  Puint32                remove_this1;
  Puint32                remove_this2;
  test                   longest;
  Puint32                remove_this3;
  Puint32                remove_this4;
  Pstring_ME(:"/.*/":)   remainder;
  Puint32                remove_this5;
};

Punion testfoo {
  a1         my_arm1;
  Pint32     i32;
};
