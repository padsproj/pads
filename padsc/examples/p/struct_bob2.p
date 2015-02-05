Pstruct test {
  Pfloat32        f;
  '|';
  Pstring(:'|':)  c : c.len > 0;
  '|';
  Puint32 id : id < 100000;     /- identity 
  '|';
  Puint32 ts : ts == 11 * id;   /- time stamp
};

Precord Pstruct testtwo {
  test header;
  '|';
  Puint32_FW(:4:) f : f == header.ts;   
};
