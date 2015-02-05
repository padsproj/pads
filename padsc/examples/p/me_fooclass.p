/*@FILE foo_charclass*/
/* use with data file me_test, nlrec IO discipline */

/* to define a new char class, we need an int->int predicate.
   want a class that just allows 'f', 'o', and digits */

#undef isdigit

/*@BEGIN foo_charclass*/
int is_foo(char c) { return (c == 'f') || (c == 'o') || isdigit((int)c); };

Pcharclass foo {is_foo};
/*@END foo_charclass*/

Precord Pstruct T1 {
  Pstring_ME(:"/[[:foo:]]+/":)            id1;
  "|";
  Pstring_ME(:"/[^| ]+/":)                id2;
  "|";
  Pstring_ME(:"/([[:alnum:]]+)[^X]/":)    id3;
  /* eat the final X if it exists */
  Pomit Pstring_ME(:"/X?/":)              id_omit;
};

