#include "vanilla.p"
Punion Union_4 {
	PPhostname  v_host_1;
	PPip  v_ip_6;
	Pempty;
};
Penum Enum_16 {
	string_bty_16_0 Pfrom("-"),
	I_bty_16 Pfrom("I"),
	OK_bty_16 Pfrom("OK"),
	umesh_bty_16 Pfrom("umesh")
};
Punion Union_192 {
	v_stringconst_194 Pfrom("-");
	Pint64  v_int_189;
	Pempty;
};
Punion Union_205 {
	PPpath  v_path_202; 
  /*        Pstring(:'-':) v_path_202; */
	v_stringconst_207 Pfrom("-");
	Pempty;
};
Penum Enum_1960 {
	localhost_bty_1960 Pfrom("localhost"),
	string_bty_1960_1 Pfrom("bj-cnc")
};
Pstruct Struct_1962 {
	Popt Pstring_ME(:"/\\-/":) v_opt_1955;
	Enum_1960  v_enum_1960;
};
Pstruct Struct_2062 {
	"\"\" [";
	PPdate  v_date_1980;
	':';
	PPtime  v_time_1984;
	"] \"GET ";
	PPpath  v_path_1999; 
	/*        Pstring(:' ':) v_path_1999; */
	" HTTP/";
	Pfloat64  v_float_2007;
	"\" ";
	Puint16  v_intconst_2019 : v_intconst_2019 == 401;
	' ';
	Puint16  v_intconst_2023 : v_intconst_2023 == 409;
	" \"";
	PPpath  v_path_2030;
	/*	Pstring(:'\\':)  v_path_2030; */
	"\" \"Mozilla/";
	Pfloat64  v_float_2044;
	" (compatible; MS";
};
Pstruct Struct_39 {
	"accept ";
	PPpath  v_path_35; 
	/*        Pstring(:' ':) v_path_35; */
	' ';
};
Pstruct Struct_2107 {
	'[';
	PPdate  v_date_43;
	':';
	PPtime  v_time_47;
	"] \"";
};
Pstruct Struct_2109 {
	"\" ";
	Puint16  v_intrange_184;
	' ';
};
Pstruct Struct_2093 {
	" [";
	PPemail  v_email_2087;
	']';
};
Pstruct Struct_2080 {
	PPhostname  v_host_2076;
	'/';
};
Punion Union_2098 {
	Struct_2093  v_struct_2093;
	Struct_2080  v_struct_2080;
	v_stringconst_2095 Pfrom("\'");
};
Precord Pstruct Struct_1922 {
	Union_4  v_union_4;
	Popt Struct_1962 v_opt_1935;
	" - ";
	Popt Struct_2062 v_opt_1937;
	Enum_16  v_enum_16;
	Popt Pstring_ME(:"/E/":) v_opt_1938;
	' ';
	Popt Struct_39 v_opt_29;
	Popt Struct_2107 v_opt_1939;
	Pstring(:'"':)  v_blob_154;
	Popt Struct_2109 v_opt_1944;
	Union_192  v_union_192;
	Popt Pstring_ME(:"/ \\\"/":) v_opt_1948;
	Union_205  v_union_205;
	Popt Union_2098 v_opt_1936;
	Popt Pstring_ME(:"/\\\" \\\"/":) v_opt_1950;
	Pstring(:'"':)  v_blob_1917;
	'\"';
};
Psource Parray entries_t {
	Struct_1922[];
};
