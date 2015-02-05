Pstruct test {
  Pint32 id : id < 100000;     /- identity 
  '|';
  Pint32 ts : ts == 11 * id;   /- time stamp
};

Precord Pstruct testtwo{
  test header;
  '|';
  Pint32 f : f == header.ts;   
};
