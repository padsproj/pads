Pstruct entry(:int len:){
  Puint32 foo;
} Pwhere {
  foo % 2 == 0 && Pparsecheck(end.offset - begin.offset == len);
};


Precord Punion uni(:int len:){
  Puint32 goo;
} Pwhere {
  2 % 2 == 0 && Pparsecheck(end.offset - begin.offset == len);
};


Punion suni(:int len:){
  Pswitch(len){
  Pcase 1 : Pint32  number : number %2 == 0;
  } 
} Pwhere{
  2 % 2 == 0 && Pparsecheck(end.offset - begin.offset == len);
}
