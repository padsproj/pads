Parray intList {
  Pa_int32 [] : Psep('|') && Pterm('.') ;
};

Punion auth_id_t {
  Pa_char           unauthorized : unauthorized == '-';  /- non-authenticated http session
  Pa_string(:' ':)  id;                                  /- login supplied during authentication
};

int check(Pint32 t, auth_id_t user){
  switch (user.tag) {
  case unauthorized: 
    return t == 1;
  case id:
    return t == 2;
  default: 
    return 1;  // Don't want to trigger another error 
  }
};
Ptypedef Pstring(:c:) foo(:Pchar c:) : foo x => { x.len  > 10};


Precord Pstruct line {
         intList    f;
 Pcompute Ppos_t p = position; 
  '.';   Pa_int32   a : a == f.length;
  ' ';   auth_id_t  user;
  ' ';   Pa_int32   t : check(t, user);
  ' ';   Pa_int32   s : s > 0;
} Pwhere {
  s == t + f.length;
};



