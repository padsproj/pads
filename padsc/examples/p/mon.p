Penum code_t {
  RTE, CPU
}; 

Pstruct rte_t {
      Puint32  num;
':';  Pip[num] route: Psep(';');
}

Punion info_t(:code_t code:){
  Pswitch (code){
    Pcase RTE: rte_t  rte;
    Pcase CPU: Puint32  cpu;
  }
};

Precord Pstruct alarms_t {
       code_t              code;
 ' ';  Puint32             severity : 1 <= severity && severity <= 4;
 '|';  Popt Pdate(:'|':)   timestamp;
 '|';  Pip                 addr;  
 "__"; info_t(:code:) info;
 '|';  Pstring_SE(:Peor:)     comment;
};
