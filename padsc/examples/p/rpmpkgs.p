#include "vanilla.p"
Popt Pstring_ME(:"/\\+/":) Opt_16;
Pstruct Struct_20 {
	PPstring  v_string_6;
	'+';
	Opt_16  v_opt_16;
	'-';
};
Popt Struct_20 Opt_4;
Pstruct Struct_23 {
	Opt_4  v_opt_4;
	PPhostname  v_host_21;
};
Precord Punion Union_24 {
	v_stringconst_26 Pfrom("gpg-pubkey-443e1821-421f218f.(none).rpm");
	Struct_23  v_struct_23;
};
Psource Parray entries_t {
	Union_24[];
};

Pstruct Char_Arg {
  '/';
  Pstring(:' ':) test;
};

Penum Enum_10 Pprefix("S_"){
       Installed10 Pfrom("Installed") = 1,
       Updated10 Pfrom("Updated"),
       Erased10 Pfrom("Erased")
};

Precord Ptypedef Puint8 Intconst_1 : Intconst_1 x => {x == 35};

Popt Pstring_ME(:"/\\+/":) Top_Option;

Pstruct Char_Arg2 {
  '/';
  Popt Pstring_ME(:"/\\+/":) Nested_Option;
};

Psource Punion foo(: Pint32 msg:) {
   Pswitch (msg) {
       Pcase 4:  Pint32 t04;
       Pdefault: Pb_uint16 [4] tushorts_1;
   }
};



Pstruct Struct_52 {
	' ';
	PPstring  v_string_40;
	Popt Pstring_ME(:"/ Columbia/":) v_opt_45;
};


Pstruct log_t(: Puint8 x, Puint16 y:) {
  Puint8 [x:x+y] ip  : Psep('.') && Pterm(Pnosep); /- resolved ip address
};

Parray ip_top(: Puint8 x, Puint16 y:) {
  Puint8 [x:x+y] : Psep('.') && Pterm(Pnosep);
}


Precord Pstruct entry4(:Puint8 x :){
  Popt Puint32 x1 : Psome i => { i % x == 0} | Pnone => {0==0};
};

Popt Puint32 even_t(:Puint8 x :) : Psome i => {i % x == 0} | Pnone => {0==0};
