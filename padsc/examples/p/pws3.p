Ptypedef Pstring_ME(:"/([0-9]{2}):([0-9]{2}):([0-9]{2})([ ]*(am|AM|pm|PM))?([ \\t]+([+-][0-1][0-9]00))?/":) PPtime;

Ptypedef Pstring_ME(:"/([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})/":) PPip;

Ptypedef Pstring_ME(:"/([0-9a-zA-Z\\-_+][0-9a-zA-Z\\-_+.]*)@((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*))/":) PPemail;

Ptypedef Pstring_ME(:"/(([0-9a-fA-F]{2})(:|\\-)){5}([0-9a-fA-F]{2})/":) PPmac;

Ptypedef Pstring_ME(:"/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\/([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([0-2][0-9]{3})|([0-2][0-9]{3})\\/((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\/([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\-([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\-((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([0-2][0-9]{3})|([0-2][0-9]{3})\\-((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\-([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\.([0-2][0-9]{3})|([1-9]|[1-2][0-9]|0[1-9]|3[0-1])\\.((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([0-2][0-9]{3})|([0-2][0-9]{3})\\.((Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)|(0?[1-9]|1[0-2]))\\.([1-9]|[1-2][0-9]|0[1-9]|3[0-1])|((Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday|Sun|Sunday|mon|tue|wed|thu|fri|sat|sun),?[ \\t]+)?(Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)[ \\t]+([1-9]|[1-2][0-9]|0[1-9]|3[0-1])(,[ \\t]+([0-2][0-9]{3}))?|((Mon|Monday|Tue|Tuesday|Wed|Wednesday|Thu|Thursday|Fri|Friday|Sat|Saturday|Sun|Sunday|mon|tue|wed|thu|fri|sat|sun),?[ \\t]+)?([1-9]|[1-2][0-9]|0[1-9]|3[0-1])[ \\t]+(Jan|jan|Feb|feb|Mar|mar|Apr|apr|May|may|Jun|jun|Jul|jul|Aug|aug|Sep|sep|Oct|oct|Nov|nov|Dec|dec|January|February|March|April|May|June|July|August|September|October|November|December)(,[ \\t]+([0-2][0-9]{3}))?/":) PPdate;

Ptypedef Pstring_ME(:"/\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?)*\\/?|([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/(([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\/)*([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?|\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?(\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?)*\\\\?|([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)\\\\([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\(([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?\\\\)*([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*)?|(http|ftp|https):\\/\\/(((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+([0-9A-Za-z_][A-Za-z0-9_\\-]*))|([0-9A-Za-z_][A-Za-z0-9_\\-]*))(:([1-9][0-9]*))?\\/?[^ \\t\\n\\r\"()']*|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*)\\?[^ \\t\\n\\r\"()']*|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\;([A-Za-z][A-Za-z0-9_\\-]*)=([A-Za-z][A-Za-z0-9_\\-]*)|(\\/([0-9A-Za-z_.][A-Za-z0-9_\\-.*%'&]*))+\\/?\\?[^ \\t\\n\\r\"()']*/":) PPpath;

Ptypedef Pstring_ME(:"/((([0-9A-Za-z_][A-Za-z0-9_\\-]*)\\.)+(com|net|edu|org|gov|co|ac|mil|info|int)(\\.[a-zA-Z][a-zA-Z])?)/":) PPhostname1;

//Ptypedef Pstring_ME(:"/[0-9A-Za-z_][A-Za-z0-9_\\-\\.]*\\.[a-zA-Z][a-zA-Z]+/":) PPhostname;
Ptypedef Pstring_ME(:"/(?:[0-9A-Za-z_][A-Za-z0-9_\\-]*\\.)+[a-zA-Z][a-zA-Z]+/":) PPhostname;

Ptypedef Pstring_ME(:"/\\<([a-zA-Z])+\\>/":) PPbXML;

Ptypedef Pstring_ME(:"/\\<\\/[^>]+\\>/":) PPeXML;

Ptypedef Pstring_ME(:"/[ \\t\\r\\n]+/":) PPwhite;

Ptypedef Pstring_ME(:"/[0-9]+/":) PPint;

Ptypedef Pstring_ME(:"/([A-Za-z][A-Za-z0-9_\\-]*)/":) PPstring;

Ptypedef Pstring_ME(:"/[^0-9A-Za-z \\t\\r\\n]/":) PPchar;


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
