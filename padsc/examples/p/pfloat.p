
int within_epsilon(Pfloat64 a, Pfloat64 b) {
  Pfloat64 diff = (a > b) ? a-b : b-a;
  return (diff < .0001) ? 1 : 0;
}

Precord Pstruct test {
  Pfloat32 x;
  '|';
  Pfloat64 y : within_epsilon(x*25, y);
};

Psource Parray source {
  test[];
};
