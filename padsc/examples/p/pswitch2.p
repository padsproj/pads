Punion branches(:Puint32 a:){
  Pswitch (a) {
  Pcase 1 : Pint32               number : number % 2 == 0;
  Pcase 2 : Pstring_SE(:"/$/":)  name;
  }
};

Precord Pstruct choice{
  Puint32      a; 
  branches(:a:)  b; 
};
