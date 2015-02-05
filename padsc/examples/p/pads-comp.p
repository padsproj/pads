Pstruct header {
  Pstring(:' ':) foo;
  ' ';
  Pcompute Pstring(:' ':) bar = foo;
  Puint32 x;
};

Precord Pstruct entry{
  header h;
  Pcompute header b = h;
};

