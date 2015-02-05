
Parray intList {
  Pint32 [] : Psep("|") && Pterm("end");
};

Precord Pstruct entry{
  intList seq;
  "end";
};
