Pstruct test {
  Pint32 id : id < 100000;     /- identity 
  '|';
  Pint32 ts : ts == 11 * id;   /- time stamp
};

Precord Punion test2 {
  test bigger;
  Pint32 two;
} Pwhere{
  (tag == bigger)? val.bigger.id > 0 : 1;
};

Psource Parray source {
  test2[];
};
