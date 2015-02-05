Ptypedef Pstring_ME(:"/[^!]/":) elem_t;

Parray myID_t {
  elem_t [] : Pterm('!');
}

Precord Pstruct myString1_t {
  myID_t v_elem;
  '!';
}

Pstruct myString_t {
  elem_t[] v_elem : Pterm('!');
  '!';
}
