Precord Pstruct test {
  Pstring_FW(:10:)   s1 : s1.str[0] == 'x';
  '|';
  Pstring(:'|':)     s2 : s2.len == 7;
  '|';
};
