Parray seq_t {
  Pstring_ME(:"/[[:alnum:]]+/":) [] : 
    Psep(Pre "/\\s+/") && 
    /*   Psep(" ") &&  */
    Plast(Pstring_eq_cstr(&elts[current], "end"));
};

Precord Pstruct entry{
  seq_t seq;
};

Pstruct foo{
  Puint32 f : f % 2 == 0;
};

Parray isCheck_t{
  foo [3] : Psep('|');
} Pwhere {
  Pforall (i Pin [0..length-2] : (elts[i].f < elts[i+1].f));  
};
