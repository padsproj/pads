Pstruct ignorethis {
  Pint8   x1;
  Pa_int8 x2;
  Pe_int8 x3;
  Pb_int8 x4;

  Pebc_int8(:4:) x5;
  Pbcd_int8(:4:) x6;
  Psbl_int8(:4:) x7;
  Psbh_int8(:4:) x8;

  Pfloat32     x9;
  Pfloat64    x10;

  Pa_float32  x11;
  Pa_float64  x12;

  Pe_float32  x13;
  Pe_float64  x14;

  Pstring_ME(:"/[^|]+/":) x15;
  Pstring_SE(:"/$/":)     x16;

};

Pstruct test {
  Pfloat32        f;
  '|';
  Pstring(:'|':)  c;
  '|';
  Puint32 id : id < 100000;     /- identity 
  '|';
  Puint32 ts : ts == 11 * id;   /- time stamp
};

Precord Pstruct testtwo{
  test header;
  '|';
  Puint32_FW(:4:) f : f == header.ts;   
};
