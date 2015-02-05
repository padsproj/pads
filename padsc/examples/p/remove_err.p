#include "vanilla.p"

Ptypedef Pstring_ME(:"/0x[0-9a-f]+/":) hex_t;

Pstruct record_t {
 '{';
 Pstring_SE(:"/}[,)] /":) v_rec_content;
 '}';
};

Pstruct list_t {
 '[';
 Pstring_SE(:"/\\\][,)] /":) v_rec_content;
 ']';
};

/*  Alternative way of expressing same patterns as those in elem_t
Ptypedef Pstring_ME(:"/[\\\\][\"]/":)  slashQuote_t;    
Ptypedef Pstring_ME(:"/[\\\\]/":)      mslash_t;        
Ptypedef Pstring_ME(:"/[^\"\\\\]+/" :) elem3_t 
*/

Punion elem_t {
  v_quotes Pfrom ("\\\"");
  v_slash  Pfrom ("\\");
  Pstring_ME (:"/[^\\\"]+/":) v_other_chars;
};

Pstruct string_t {
 '"';
 elem_t [] v_rec_content : Plongest;
 '"';
 Popt Pstring_ME(:"/\\.\\.\\./":) v_dots;
};

Pstruct paren_t {
  '(';
  Pstring(:')':) arg;
  ')';
}

Punion param_t {
  record_t v_record;
  list_t v_list;
  hex_t v_hex_val;
  string_t v_string;
  Pstring_SE(:"/[,)]/":) v_other_param;
};

Parray params_array_t {
  param_t[] : Psep(", ") && Pterm(')');
};

Punion params_t {
  params_array_t v_params_a;
  Pstring_SE(:"/\\)[ \\t]+=/":) v_params_def; /* catch all for params */
};

Punion val_t {
  hex_t v_hex;
  Pint32 v_int;
  v_que Pfrom ("?");
};

Pstruct err_t {
  PPwhite v_space1;
  PPstring v_err_code;
};

Pstruct err_msg_t {
  PPwhite v_space2;
  "(";
  Pstring(:')':) v_err_msg;
  ')';
};

Pstruct return_t {
  val_t v_val;
  Popt err_t v_err_code;
  Popt err_msg_t v_msg;
};

  
Pstruct timing_t {
  '<';
  Pfloat64 v_timing;
 '>';
};


Pstruct unfinished_t {
  Pstring_ME (:"/[a-zA-Z0-9_]+/":) v_func_name;
  Pstring_SE (:"/\\\<unfinished \\\.\\\.\\\.\\\>/":) v_unfinished;
  "<unfinished ...>";
}

Pstruct resumed_t {
 "<...";
 Pstring_SE (:"/\\\) = /":) v_resumed;
 ") = ";
 return_t v_result;
 Popt PPwhite v_space3;
 Popt timing_t v_time;
};

Pstruct norm_func_t {
  Pstring_ME (:"/[a-zA-Z0-9_]+/":) v_func_name;
  '(';
  params_t v_params;
  ')';
  PPwhite v_space1;
  '=';
  PPwhite v_space2;
  return_t v_result;
  Popt PPwhite v_space3;
  Popt timing_t v_time;
};

Precord Punion message_t {
  //  unfinished_t v_unfinished_msg;
  //  resumed_t v_resumed_msg;
  norm_func_t v_normal_fun;
  /* Pstring_SE (:Peor:) v_other_msgs; */
}

Precord Pstruct entry_t {
	Puint16 v_proc_id;
        PPwhite v_space;
        Puint32 v_int1;
        '.';
        Puint32 v_int2;
        ' ';
        message_t v_msg;
};

Psource Parray entries_t {
	entry_t[];
};
