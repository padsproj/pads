/* use with data file me_test, nlrec IO discipline */

Precord Pstruct T1 {
  Pstring_ME(:"/[^|]+/":)             id1;
  "|";
  Pstring_ME(:"/[[:alnum:]]+/":)      id2;
  "|";
  Pstring_ME(:"/(.+)[^X]/":)          id3;
  /* eat the final X if it exists */
  Pomit Pstring_ME(:"/X?/":)          id_omit;
};

