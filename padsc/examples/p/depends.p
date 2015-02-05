Parray intList {
  Pint32 [] : Psep('|') && Pterm('.') ;
};

Punion auth_id_t {
  Pchar          unauthorized : unauthorized == '-';  /- non-authenticated http session
  Pstring(:' ':) id;                                  /- login supplied during authentication
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

Precord Pstruct line{
       intList    f;
  '.'; Pint32     a : a == f.length;
  ' '; auth_id_t  user;
  ' '; Pint32     t : check(t, user);
};

Psource Parray source {
 line[];
};

