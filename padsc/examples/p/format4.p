Pstruct test(:Puint32 h, int x:) {
  Puint32 id : id == h * x;     /- identity 
};

#define RECLIST_SIZE 10
Parray recList(:Puint32 h, int x, int size:) {
  test(:h,x:) [size];
} Pwhere {
  Pforall (i Pin [0 .. length - 2] :  i==x || recList[i].id < recList[i+1].id );
};


Parray recList2(:Puint32 h, int x, int size:) {
  test(:h,x:) [size];
} Pwhere{
  Pforall (i Pin recList2  :  recList2[i].id % 2 == 0);
};


Pstruct test2 {
  Puint32 h;
  '|';
  Puint32 s;
  '|';
  test(:h,10:) i;
#if 0
  Pstring_FW(:10:) fw;
  Pstring(:'|':) v;     /- stop char
  '|';
#endif
};


