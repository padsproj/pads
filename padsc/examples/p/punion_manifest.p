Pstruct str1 {
  Pint32 id : id < 100000;     /- identity 
  '|';
  Pint32 ts : ts == 11 * id;   /- time stamp
};

Punion choice {
  str1 bigger;
  Pcompute Pint32 first = 12; /- default value
  Pint32 two;
};

Precord Pstruct str2{
  choice c;
  ' ';
  Pint32 t;
  Pcompute Pint32 v = 11; /- struct manifest field
};


