Ptypedef Pstring_ME(:"/[\\\\][\"]/":) slashQuote_t;    
Ptypedef Pstring_ME(:"/[\\\\]/":)   mslash_t;        
Ptypedef Pstring_ME(:"/[^\"\\\\]+/" :) elem3_t 

Punion elem1_t {
  slashQuote_t    sq;
  mslash_t        sl;
  elem3_t v_other_chars;   // Read anything except either a slash or a quotation
};

Parray elems_t {
  elem1_t [] : Plongest;
}
 
Precord Pstruct string_t {
  elems_t elems;
  "\"";
} 
