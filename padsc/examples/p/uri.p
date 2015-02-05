#define Pvoid(label) Pcompute Pomit Puint32 label = 0
int is_digit(char x) { return
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
Ptypedef Pstring_ME(:"/[[:digit:]]+/":) _bnf_0_t;
Ptypedef Pstring_ME(:"/[[:digit:]]+/":) _bnf_1_t;
Ptypedef Pstring_ME(:"/[[:digit:]]+/":) _bnf_2_t;
Ptypedef Pstring_ME(:"/[[:digit:]]+/":) _bnf_3_t;
Pstruct IPv4address_t {
  _bnf_0_t _bnf_0;
  ".";
  _bnf_1_t _bnf_1;
  ".";
  _bnf_2_t _bnf_2;
  ".";
  _bnf_3_t _bnf_3;
};
int is_hex(char x) { return
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
Pstruct escaped_t {
  "%";
  hex_t hex;
  hex_t _bnf_32;
};
int is_lowalpha(char x) { return
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
int is_mark(char x) { return
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
Ptypedef Pstring_ME(:"/[[:digit:]]*/":) port_t;
int is_reserved(char x) { return
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
int is_upalpha(char x) { return
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
int is_alpha(char x) { return
  is_lowalpha(x)
  || is_upalpha(x)
  ;
};
Ptypedef Pchar alpha_t : alpha_t x => { is_alpha(x) };
Pcharclass alpha {is_alpha};
int is_alphanum(char x) { return
  is_alpha(x)
  || is_digit(x)
  ;
};
Ptypedef Pchar alphanum_t : alphanum_t x => { is_alphanum(x) };
Pcharclass alphanum {is_alphanum};
Punion _bnf_5_t {
  __cident__ Pfrom("-");
  Pvoid(_bnf_33);
};
Pstruct _bnf_34_t {
  _bnf_5_t _bnf_5;
  alphanum_t alphanum;
};

Pstruct domainlabel_t {
  alphanum_t alphanum;
  _bnf_34_t[0:] _bnf_4 : Plongest;
};
Pstruct _bnf_35_t {
  ".";
  domainlabel_t domainlabel;
};
Parray _bnf_6_t {
  _bnf_35_t[0:] : Plongest;
};
Punion _bnf_7_t {
  _bnf_36 Pfrom(".");
  Pvoid(_bnf_37);
};
int hostname_check(domainlabel_t *domainlabel, _bnf_6_t *_bnf_6) {
  // the first character of the final domainlabel must be alpha
  if (_bnf_6->length > 0) {
    // the final label is in the _bnf_6 array
    return is_alpha(_bnf_6->elts[_bnf_6->length-1].domainlabel.alphanum);
  }
  // the final label is domainlabel (i.e., the first label)
  return is_alpha(domainlabel->alphanum);
}
Pstruct hostname_t {
  domainlabel_t domainlabel;
  _bnf_6_t _bnf_6;
  _bnf_7_t _bnf_7;
} Pwhere { hostname_check(&domainlabel, &_bnf_6); };
Punion host_t {
  hostname_t hostname;
  IPv4address_t IPv4address;
};
Pstruct _bnf_9_t {
  ":";
  port_t port;
};
Punion _bnf_8_t {
  _bnf_9_t _bnf_9;
  Pvoid(_bnf_38);
};
Pstruct hostport_t {
  host_t host;
  _bnf_8_t _bnf_8;
};
Ptypedef Pstring_ME(:"/[[:alpha:][:digit:]\\x2b\\x2d\\x2e]*/":) _bnf_10_t;
Pstruct scheme_t {
  alpha_t alpha;
  _bnf_10_t _bnf_10;
};
Punion _bnf_12_t {
  _bnf_39 Pfrom("-");
  Pvoid(_bnf_40);
};
Pstruct _bnf_41_t {
  _bnf_12_t _bnf_12;
  alphanum_t alphanum;
};
Parray _bnf_11_t {
  _bnf_41_t[0:] : Plongest;
};
Pstruct toplabel_t {
  alpha_t alpha;
  _bnf_11_t _bnf_11;
};
int is_unreserved(char x) { return
  is_alphanum(x)
  || is_mark(x)
  ;
};
Ptypedef Pchar unreserved_t : unreserved_t x => { is_unreserved(x) };
Pcharclass unreserved {is_unreserved};
Punion pchar_t {
  unreserved_t unreserved;
  escaped_t escaped;
  _bnf_42 Pfrom(":");
  _bnf_43 Pfrom("@");
  _bnf_44 Pfrom("&");
  _bnf_45 Pfrom("=");
  _bnf_46 Pfrom("+");
  _bnf_47 Pfrom("$");
  _bnf_48 Pfrom(",");
};
Parray param_t {
  pchar_t[0:] : Plongest;
};
Punion _bnf_49_t {
  unreserved_t _bnf_50;
  escaped_t _bnf_51;
  _bnf_52 Pfrom("$");
  _bnf_53 Pfrom(",");
  _bnf_54 Pfrom(";");
  _bnf_55 Pfrom(":");
  _bnf_56 Pfrom("@");
  _bnf_57 Pfrom("&");
  _bnf_58 Pfrom("=");
  _bnf_59 Pfrom("+");
};
Parray reg_name_t {
  _bnf_49_t[1:] : Plongest;
};
Punion _bnf_60_t {
  unreserved_t _bnf_61;
  escaped_t _bnf_62;
  _bnf_63 Pfrom(";");
  _bnf_64 Pfrom("@");
  _bnf_65 Pfrom("&");
  _bnf_66 Pfrom("=");
  _bnf_67 Pfrom("+");
  _bnf_68 Pfrom("$");
  _bnf_69 Pfrom(",");
};
Parray rel_segment_t {
  _bnf_60_t[1:] : Plongest;
};
Parray _bnf_13_t {
  pchar_t[0:] : Plongest;
};
Pstruct _bnf_70_t {
  ";";
  param_t param;
};
Parray _bnf_14_t {
  _bnf_70_t[0:] : Plongest;
};
Pstruct segment_t {
  _bnf_13_t _bnf_13;
  _bnf_14_t _bnf_14;
};
Pstruct _bnf_71_t {
  "/";
  segment_t segment;
};
Parray _bnf_15_t {
  _bnf_71_t[0:] : Plongest;
};
Pstruct path_segments_t {
  segment_t segment;
  _bnf_15_t _bnf_15;
};
Pstruct abs_path_t {
  "/";
  path_segments_t path_segments;
};
Punion _bnf_16_t {
  abs_path_t abs_path;
  Pvoid(_bnf_72);
};
Pstruct rel_path_t {
  rel_segment_t rel_segment;
  _bnf_16_t _bnf_16;
};
Punion uric_t {
  reserved_t reserved;
  unreserved_t _bnf_73;
  escaped_t _bnf_74;
};
Parray fragment_t {
  uric_t[0:] : Plongest;
};
Parray query_t {
  uric_t[0:] : Plongest;
};
Punion uric_no_slash_t {
  unreserved_t _bnf_75;
  escaped_t _bnf_76;
  _bnf_77 Pfrom(";");
  _bnf_78 Pfrom("?");
  _bnf_79 Pfrom(":");
  _bnf_80 Pfrom("@");
  _bnf_81 Pfrom("&");
  _bnf_82 Pfrom("=");
  _bnf_83 Pfrom("+");
  _bnf_84 Pfrom("$");
  _bnf_85 Pfrom(",");
};
Parray _bnf_17_t {
  uric_t[0:] : Plongest;
};
Pstruct opaque_part_t {
  uric_no_slash_t uric_no_slash;
  _bnf_17_t _bnf_17;
};
Punion path_t {
  abs_path_t _bnf_86;
  opaque_part_t opaque_part;
  Pvoid(_bnf_87);
};
Punion _bnf_88_t {
  unreserved_t _bnf_89;
  escaped_t _bnf_90;
  _bnf_91 Pfrom(";");
  _bnf_92 Pfrom(":");
  _bnf_93 Pfrom("&");
  _bnf_94 Pfrom("=");
  _bnf_95 Pfrom("+");
  _bnf_96 Pfrom("$");
  _bnf_97 Pfrom(",");
};
Parray userinfo_t {
  _bnf_88_t[0:] : Plongest;
};
Pstruct _bnf_20_t {
  userinfo_t userinfo;
  "@";
};
Punion _bnf_19_t {
  _bnf_20_t _bnf_20;
  Pvoid(_bnf_98);
};
Pstruct _bnf_18_t {
  _bnf_19_t _bnf_19;
  hostport_t hostport;
};
Punion server_t {
  _bnf_18_t _bnf_18;
  Pvoid(_bnf_99);
};
Punion authority_t {
  server_t server;
  reg_name_t reg_name;
};
Punion _bnf_21_t {
  abs_path_t _bnf_100;
  Pvoid(_bnf_101);
};
Pstruct net_path_t {
  "//";
  authority_t authority;
  _bnf_21_t _bnf_21;
};
Punion _bnf_22_t {
  net_path_t net_path;
  abs_path_t _bnf_102;
};
Pstruct _bnf_24_t {
  "?";
  query_t query;
};
Punion _bnf_23_t {
  _bnf_24_t _bnf_24;
  Pvoid(_bnf_103);
};
Pstruct hier_part_t {
  _bnf_22_t _bnf_22;
  _bnf_23_t _bnf_23;
};
Punion _bnf_25_t {
  hier_part_t hier_part;
  opaque_part_t _bnf_104;
};
Pstruct absoluteURI_t {
  scheme_t scheme;
  ":";
  _bnf_25_t _bnf_25;
};
Punion _bnf_26_t {
  net_path_t _bnf_105;
  abs_path_t _bnf_106;
  rel_path_t rel_path;
};
Pstruct _bnf_28_t {
  "?";
  query_t query;
};
Punion _bnf_27_t {
  _bnf_28_t _bnf_28;
  Pvoid(_bnf_107);
};
Pstruct relativeURI_t {
  _bnf_26_t _bnf_26;
  _bnf_27_t _bnf_27;
};
Punion _bnf_29_t {
  absoluteURI_t absoluteURI;
  relativeURI_t relativeURI;
  Pvoid(_bnf_108);
};
Pstruct _bnf_31_t {
  "#";
  fragment_t fragment;
};
Punion _bnf_30_t {
  _bnf_31_t _bnf_31;
  Pvoid(_bnf_109);
};
Precord Pstruct URI_reference_t {
  _bnf_29_t _bnf_29;
  _bnf_30_t _bnf_30;
};
