#include "vanilla.p"
Penum Enum_38 {
	POST38 Pfrom("POST"),
	GET38 Pfrom("GET")
};
Pstruct Struct_70 {
	"&atid=";
	Puint8  v_intconst_68 : v_intconst_68 == 121;
};
Popt Struct_70 Opt_60;
Pstruct Struct_72 {
	"\?group_id=";
	Puint8  v_intrange_55;
	Opt_60  v_opt_60;
};
Popt Struct_72 Opt_47;
Pstruct Struct_73 {
	PPpath  v_path_42;
	Opt_47  v_opt_47;
};
Penum Enum_87 {
	html87 Pfrom("html"),
	txt87 Pfrom("txt"),
	php87 Pfrom("php"),
	ico87 Pfrom("ico")
};
Pstruct Struct_89 {
	PPstring  v_string_83;
	'.';
	Enum_87  v_enum_87;
};
Popt Struct_89 Opt_91;
Pstruct Struct_92 {
	'/';
	Opt_91  v_opt_91;
};
Punion Union_108 {
	v_stringconst_116 Pfrom("/bridge-loan.html");
	PPurl  v_url_76;
	Struct_73  v_struct_73;
	Struct_92  v_struct_92;
};
Punion Union_150 {
	v_stringconst_152 Pfrom("-");
	Pint64  v_int_147;
};
Punion Union_163 {
	PPurl  v_url_165;
	v_stringconst_160 Pfrom("-");
};
Penum Enum_177 {
	Baiduspider177 Pfrom("Baiduspider"),
	Googlebot177 Pfrom("Googlebot"),
	Mozilla177 Pfrom("Mozilla"),
	ozilla177 Pfrom("ozilla"),
	msnbot177 Pfrom("msnbot")
};
Pstruct Struct_562 {
	Enum_177  v_enum_177;
	Pstring(:'(':)  v_blob_190;
	'(';
	Pstring(:')':)  v_blob_275;
	')';
	Pstring(:'"':)  v_blob_491;
};
Punion Union_563 {
	Struct_562  v_struct_562;
	v_stringconst_567 Pfrom("-");
};
Pstruct Struct_573 {
	Pstring_SE(:"/ \\[/":)  v_blob_13;
	" [";
	PPdate  v_date_23;
	':';
	PPtime  v_time_27;
	"] \"";
	Enum_38  v_enum_38;
	' ';
	Union_108  v_union_108;
	PPwhite  v_white_93;
	"HTTP/";
	Pfloat64  v_float_99;
	"\" ";
	Puint16  v_intrange_142;
	' ';
	Union_150  v_union_150;
	" \"";
	Union_163  v_union_163;
	"\" \"";
	Union_563  v_union_563;
	'\"';
};
Pstruct Struct_707 {
	'-';
	PPwhite  v_white_586;
	'[';
	PPdate  v_date_591;
	':';
	PPtime  v_time_595;
	']';
	PPwhite  v_white_601;
	"\"GET";
	PPwhite  v_white_608;
	PPpath  v_path_610;
	PPwhite  v_white_612;
	"HTTP/";
	Pfloat64  v_float_618;
	'\"';
	PPwhite  v_white_628;
	Puint8  v_intconst_630 : v_intconst_630 == 200;
	PPwhite  v_white_632;
	Puint16  v_intconst_634 : v_intconst_634 == 785;
	PPwhite  v_white_636;
	'\"';
	PPurl  v_url_641;
	'\"';
	PPwhite  v_white_647;
	"(compatible;";
	PPwhite  v_white_655;
	"MSIE";
	PPwhite  v_white_659;
	Pfloat64  v_float_661;
	';';
	PPwhite  v_white_669;
	"Windows";
	PPwhite  v_white_673;
	"NT";
	PPwhite  v_white_677;
	Pfloat64  v_float_679;
	';';
	PPwhite  v_white_687;
	"SV1;\"Mozilla/";
	Pfloat64  v_float_699;
	PPwhite  v_white_705;
};
Punion Union_574 {
	Struct_573  v_struct_573;
	Struct_707  v_struct_707;
};
Precord Pstruct Struct_713 {
	PPip  v_ip_1;
	" - ";
	Union_574  v_union_574;
};
Psource Parray entries_t {
	Struct_713[];
};
