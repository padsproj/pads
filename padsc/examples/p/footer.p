Precord Pstruct Line_t{
  Puint16 i;
  '|';
  Pchar c;
};

Precord Ptypedef Pstring_SE(:Peor:) Pstringln;

Pstruct Entry_t{
  Pstringln header;
  Line_t[] line : Plongest;
  Pstringln trailer;  
};
