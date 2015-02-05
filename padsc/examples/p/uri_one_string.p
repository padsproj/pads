
#ifdef BNF_INPUT

URI-reference = ([(absoluteURI|relativeURI)] [("#" fragment)]).
absoluteURI = ((scheme ":") (hier_part|opaque_part)).
relativeURI = (((net_path|abs_path)|rel_path) [("?" query)]).
hier_part = ((net_path|abs_path) [("?" query)]).
opaque_part = (uric_no_slash *uric).
uric_no_slash = ((((((((((unreserved|escaped)|";")|"?")|":")|"@")|"&")|"=")|"+")|"$")|",").
net_path = (("//" authority) [abs_path]).
abs_path = ("/" path_segments).
rel_path = (rel_segment [abs_path]).
rel_segment = 1*((((((((unreserved|escaped)|";")|"@")|"&")|"=")|"+")|"$")|",").
scheme = (alpha *((((alpha|digit)|"+")|"-")|".")).
authority = (server|reg_name).
reg_name = 1*(((((((((unreserved|escaped)|"$")|",")|";")|":")|"@")|"&")|"=")|"+").
server = [([(userinfo "@")] hostport)].
userinfo = *((((((((unreserved|escaped)|";")|":")|"&")|"=")|"+")|"$")|",").
hostport = (host [(":" port)]).
host = (hostname|IPv4address).
hostname = ((*(domainlabel ".") toplabel) ["."]).
domainlabel = (alphanum *(["-"] alphanum)).
toplabel = (alpha *(["-"] alphanum)).
IPv4address = ((((((1*digit ".") 1*digit) ".") 1*digit) ".") 1*digit).
port = *digit.
path = [(abs_path|opaque_part)].
path_segments = (segment1 *("/" segment)).
segment1 = (1*param_char *(";" param)).
segment = (*param_char *(";" param)).
param = *param_char.
param_char = ((((((((unreserved|escaped)|":")|"@")|"&")|"=")|"+")|"$")|",").
query = *uric.
fragment = *uric.
uric = ((reserved|unreserved)|escaped).
reserved = (((((((((";"|"/")|"?")|":")|"@")|"&")|"=")|"+")|"$")|",").
unreserved = (alphanum|mark).
mark = (((((((("-"|"_")|".")|"!")|"~")|"*")|"'")|"(")|")").
escaped = (("%" hex) hex).
hex = ((((((((((((digit|"A")|"B")|"C")|"D")|"E")|"F")|"a")|"b")|"c")|"d")|"e")|"f").
alphanum = (alpha|digit).
alpha = (lowalpha|upalpha).
lowalpha = ((((((((((((((((((((((((("a"|"b")|"c")|"d")|"e")|"f")|"g")|"h")|"i")|"j")|"k")|"l")|"m")|"n")|"o")|"p")|"q")|"r")|"s")|"t")|"u")|"v")|"w")|"x")|"y")|"z").
upalpha = ((((((((((((((((((((((((("A"|"B")|"C")|"D")|"E")|"F")|"G")|"H")|"I")|"J")|"K")|"L")|"M")|"N")|"O")|"P")|"Q")|"R")|"S")|"T")|"U")|"V")|"W")|"X")|"Y")|"Z").
digit = ((((((((("0"|"1")|"2")|"3")|"4")|"5")|"6")|"7")|"8")|"9").

#endif  // end BNF_INPUT
int is_digit(Pchar x) { return
  (x == 48)
  || (x == 49)
  || (x == 50)
  || (x == 51)
  || (x == 52)
  || (x == 53)
  || (x == 54)
  || (x == 55)
  || (x == 56)
  || (x == 57)
  ;
};
Ptypedef Pchar digit_t : digit_t x => { is_digit(x) };
Pcharclass digit {is_digit};
#define RE_digit "[[:digit:]]"
#define RE_IPv4address "(" "(" "(" "(" "(" "(" "(" RE_digit "){1,}" "\\." ")" "(" RE_digit "){1,}" ")" "\\." ")" "(" RE_digit "){1,}" ")" "\\." ")" "(" RE_digit "){1,}" ")"
Ptypedef Pstring_ME(:"/" RE_IPv4address "/":) IPv4address_t;
int is_hex(Pchar x) { return
  is_digit(x)
  || (x == 65)
  || (x == 66)
  || (x == 67)
  || (x == 68)
  || (x == 69)
  || (x == 70)
  || (x == 97)
  || (x == 98)
  || (x == 99)
  || (x == 100)
  || (x == 101)
  || (x == 102)
  ;
};
Ptypedef Pchar hex_t : hex_t x => { is_hex(x) };
Pcharclass hex {is_hex};
#define RE_hex "[[:hex:]]"
#define RE_escaped "(" "(" "\\%" RE_hex ")" RE_hex ")"
Ptypedef Pstring_ME(:"/" RE_escaped "/":) escaped_t;
int is_lowalpha(Pchar x) { return
  (x == 97)
  || (x == 98)
  || (x == 99)
  || (x == 100)
  || (x == 101)
  || (x == 102)
  || (x == 103)
  || (x == 104)
  || (x == 105)
  || (x == 106)
  || (x == 107)
  || (x == 108)
  || (x == 109)
  || (x == 110)
  || (x == 111)
  || (x == 112)
  || (x == 113)
  || (x == 114)
  || (x == 115)
  || (x == 116)
  || (x == 117)
  || (x == 118)
  || (x == 119)
  || (x == 120)
  || (x == 121)
  || (x == 122)
  ;
};
Ptypedef Pchar lowalpha_t : lowalpha_t x => { is_lowalpha(x) };
Pcharclass lowalpha {is_lowalpha};
#define RE_lowalpha "[[:lowalpha:]]"
int is_mark(Pchar x) { return
  (x == 45)
  || (x == 95)
  || (x == 46)
  || (x == 33)
  || (x == 126)
  || (x == 42)
  || (x == 39)
  || (x == 40)
  || (x == 41)
  ;
};
Ptypedef Pchar mark_t : mark_t x => { is_mark(x) };
Pcharclass mark {is_mark};
#define RE_mark "[[:mark:]]"
#define RE_port "(" RE_digit "){0,}"
Ptypedef Pstring_ME(:"/" RE_port "/":) port_t;
int is_reserved(Pchar x) { return
  (x == 59)
  || (x == 47)
  || (x == 63)
  || (x == 58)
  || (x == 64)
  || (x == 38)
  || (x == 61)
  || (x == 43)
  || (x == 36)
  || (x == 44)
  ;
};
Ptypedef Pchar reserved_t : reserved_t x => { is_reserved(x) };
Pcharclass reserved {is_reserved};
#define RE_reserved "[[:reserved:]]"
int is_upalpha(Pchar x) { return
  (x == 65)
  || (x == 66)
  || (x == 67)
  || (x == 68)
  || (x == 69)
  || (x == 70)
  || (x == 71)
  || (x == 72)
  || (x == 73)
  || (x == 74)
  || (x == 75)
  || (x == 76)
  || (x == 77)
  || (x == 78)
  || (x == 79)
  || (x == 80)
  || (x == 81)
  || (x == 82)
  || (x == 83)
  || (x == 84)
  || (x == 85)
  || (x == 86)
  || (x == 87)
  || (x == 88)
  || (x == 89)
  || (x == 90)
  ;
};
Ptypedef Pchar upalpha_t : upalpha_t x => { is_upalpha(x) };
Pcharclass upalpha {is_upalpha};
#define RE_upalpha "[[:upalpha:]]"
int is_alpha(Pchar x) { return
  is_lowalpha(x)
  || is_upalpha(x)
  ;
};
Ptypedef Pchar alpha_t : alpha_t x => { is_alpha(x) };
Pcharclass alpha {is_alpha};
#define RE_alpha "[[:alpha:]]"
int is_alphanum(Pchar x) { return
  is_alpha(x)
  || is_digit(x)
  ;
};
Ptypedef Pchar alphanum_t : alphanum_t x => { is_alphanum(x) };
Pcharclass alphanum {is_alphanum};
#define RE_alphanum "[[:alphanum:]]"
#define RE_domainlabel "(" RE_alphanum "(" "(" "(" "\\-" ")?" RE_alphanum ")" "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_domainlabel "/":) domainlabel_t;
#define RE_scheme "(" RE_alpha "(" "(" "(" "(" "(" RE_alpha "|" RE_digit ")"  "|" "\\+" ")"  "|" "\\-" ")"  "|" "\\." ")"  "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_scheme "/":) scheme_t;
#define RE_toplabel "(" RE_alpha "(" "(" "(" "\\-" ")?" RE_alphanum ")" "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_toplabel "/":) toplabel_t;
#define RE_hostname "(" "(" "(" "(" RE_domainlabel "\\." ")" "){0,}" RE_toplabel ")" "(" "\\." ")?" ")"
Ptypedef Pstring_ME(:"/" RE_hostname "/":) hostname_t;
#define RE_host "(" RE_hostname "|" RE_IPv4address ")" 
Ptypedef Pstring_ME(:"/" RE_host "/":) host_t;
#define RE_hostport "(" RE_host "(" "(" "\\:" RE_port ")" ")?" ")"
Ptypedef Pstring_ME(:"/" RE_hostport "/":) hostport_t;
int is_unreserved(Pchar x) { return
  is_alphanum(x)
  || is_mark(x)
  ;
};
Ptypedef Pchar unreserved_t : unreserved_t x => { is_unreserved(x) };
Pcharclass unreserved {is_unreserved};
#define RE_unreserved "[[:unreserved:]]"
#define RE_param_char "(" "(" "(" "(" "(" "(" "(" "(" RE_unreserved "|" RE_escaped ")"  "|" "\\:" ")"  "|" "\\@" ")"  "|" "\\&" ")"  "|" "\\=" ")"  "|" "\\+" ")"  "|" "\\$" ")"  "|" "\\," ")" 
Ptypedef Pstring_ME(:"/" RE_param_char "/":) param_char_t;
#define RE_param "(" RE_param_char "){0,}"
Ptypedef Pstring_ME(:"/" RE_param "/":) param_t;
#define RE_reg_name "(" "(" "(" "(" "(" "(" "(" "(" "(" "(" RE_unreserved "|" RE_escaped ")"  "|" "\\$" ")"  "|" "\\," ")"  "|" "\\;" ")"  "|" "\\:" ")"  "|" "\\@" ")"  "|" "\\&" ")"  "|" "\\=" ")"  "|" "\\+" ")"  "){1,}"
Ptypedef Pstring_ME(:"/" RE_reg_name "/":) reg_name_t;
#define RE_rel_segment "(" "(" "(" "(" "(" "(" "(" "(" "(" RE_unreserved "|" RE_escaped ")"  "|" "\\;" ")"  "|" "\\@" ")"  "|" "\\&" ")"  "|" "\\=" ")"  "|" "\\+" ")"  "|" "\\$" ")"  "|" "\\," ")"  "){1,}"
Ptypedef Pstring_ME(:"/" RE_rel_segment "/":) rel_segment_t;
#define RE_segment "(" "(" RE_param_char "){0,}" "(" "(" "\\;" RE_param ")" "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_segment "/":) segment_t;
#define RE_segment1 "(" "(" RE_param_char "){1,}" "(" "(" "\\;" RE_param ")" "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_segment1 "/":) segment1_t;
#define RE_path_segments "(" RE_segment1 "(" "(" "\\/" RE_segment ")" "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_path_segments "/":) path_segments_t;
#define RE_abs_path "(" "\\/" RE_path_segments ")"
Ptypedef Pstring_ME(:"/" RE_abs_path "/":) abs_path_t;
#define RE_rel_path "(" RE_rel_segment "(" RE_abs_path ")?" ")"
Ptypedef Pstring_ME(:"/" RE_rel_path "/":) rel_path_t;
#define RE_uric "(" "(" RE_reserved "|" RE_unreserved ")"  "|" RE_escaped ")" 
Ptypedef Pstring_ME(:"/" RE_uric "/":) uric_t;
#define RE_fragment "(" RE_uric "){0,}"
Ptypedef Pstring_ME(:"/" RE_fragment "/":) fragment_t;
#define RE_query "(" RE_uric "){0,}"
Ptypedef Pstring_ME(:"/" RE_query "/":) query_t;
#define RE_uric_no_slash "(" "(" "(" "(" "(" "(" "(" "(" "(" "(" RE_unreserved "|" RE_escaped ")"  "|" "\\;" ")"  "|" "\\?" ")"  "|" "\\:" ")"  "|" "\\@" ")"  "|" "\\&" ")"  "|" "\\=" ")"  "|" "\\+" ")"  "|" "\\$" ")"  "|" "\\," ")" 
Ptypedef Pstring_ME(:"/" RE_uric_no_slash "/":) uric_no_slash_t;
#define RE_opaque_part "(" RE_uric_no_slash "(" RE_uric "){0,}" ")"
Ptypedef Pstring_ME(:"/" RE_opaque_part "/":) opaque_part_t;
#define RE_path "(" "(" RE_abs_path "|" RE_opaque_part ")"  ")?"
Ptypedef Pstring_ME(:"/" RE_path "/":) path_t;
#define RE_userinfo "(" "(" "(" "(" "(" "(" "(" "(" "(" RE_unreserved "|" RE_escaped ")"  "|" "\\;" ")"  "|" "\\:" ")"  "|" "\\&" ")"  "|" "\\=" ")"  "|" "\\+" ")"  "|" "\\$" ")"  "|" "\\," ")"  "){0,}"
Ptypedef Pstring_ME(:"/" RE_userinfo "/":) userinfo_t;
#define RE_server "(" "(" "(" "(" RE_userinfo "\\@" ")" ")?" RE_hostport ")" ")?"
Ptypedef Pstring_ME(:"/" RE_server "/":) server_t;
#define RE_authority "(" RE_server "|" RE_reg_name ")" 
Ptypedef Pstring_ME(:"/" RE_authority "/":) authority_t;
#define RE_net_path "(" "(" "\\/\\/" RE_authority ")" "(" RE_abs_path ")?" ")"
Ptypedef Pstring_ME(:"/" RE_net_path "/":) net_path_t;
#define RE_hier_part "(" "(" RE_net_path "|" RE_abs_path ")"  "(" "(" "\\?" RE_query ")" ")?" ")"
Ptypedef Pstring_ME(:"/" RE_hier_part "/":) hier_part_t;
#define RE_absoluteURI "(" "(" RE_scheme "\\:" ")" "(" RE_hier_part "|" RE_opaque_part ")"  ")"
Ptypedef Pstring_ME(:"/" RE_absoluteURI "/":) absoluteURI_t;
#define RE_relativeURI "(" "(" "(" RE_net_path "|" RE_abs_path ")"  "|" RE_rel_path ")"  "(" "(" "\\?" RE_query ")" ")?" ")"
Ptypedef Pstring_ME(:"/" RE_relativeURI "/":) relativeURI_t;
#define RE_URI_reference "(" "(" "(" RE_absoluteURI "|" RE_relativeURI ")"  ")?" "(" "(" "\\#" RE_fragment ")" ")?" ")"
Precord Ptypedef Pstring_ME(:"/" RE_URI_reference "/":) URI_reference_t;
