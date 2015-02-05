int chkErr(int found_error, int *consume) {
   if (found_error) {
     *consume = 0;
     return 1;
   };
   return 0;
};

#define Plongest Pended(Pparsecheck(chkErr(pds[current].nerr, &consume)))
#define Plongest_check(expr) Pended(Pparsecheck(chkErr(pds[current].nerr > 0 || (expr), &consume)))
#define Pvoid(label) Pcompute Pomit Puint32 label = 0

Pstruct IPv4address_t {
   Puint32 _bnf_0;
   ".";
   Puint32 _bnf_1;
   ".";
   Puint32 _bnf_2;
   ".";
   Puint32 _bnf_3;
};

#define IS_DIGIT(x)      (x >= 48 && x <= 57)
#define IS_AtoF(x)       (x >= 65 && x <= 70)
#define IS_atof(x)       (x >= 97 && x <= 102)
#define IS_HEX(x)        (IS_DIGIT(x)||IS_AtoF(x)||IS_atof(x))
#define IS_AtoZ(x)       (x >= 65 && x <= 90)
#define IS_atoz(x)       (x >= 97 && x <= 122)
#define IS_ALPHA(x)      (IS_AtoZ(x)||IS_atoz(x))
#define IS_ALPHANUM(x)   (IS_DIGIT(x)||IS_AtoZ(x)||IS_atoz(x))
#define IS_MARK(x)       (x == 45||x == 95||x == 46||x == 33||x == 126||x == 42||x == 39||x == 40||x == 41)
#define IS_RESERVED(x)   (x == 59||x == 47||x == 63||x == 58||x == 64 ||x == 38||x == 61||x == 43||x == 36||x == 44)
#define IS_UNRESERVED(x) (IS_ALPHANUM(x) || IS_MARK(x))

int is_digit(char x) { return IS_DIGIT(x); };
Ptypedef Pchar digit_t : digit_t x => { is_digit(x) };
Pcharclass digit {is_digit};

int is_hex(char x) { return IS_HEX(x); }
Ptypedef Pchar hex_t : hex_t x => { is_hex(x) };
Pcharclass hex {is_hex};

int is_lowalpha(char x) { return IS_atoz(x); };
Ptypedef Pchar lowalpha_t : lowalpha_t x => { is_lowalpha(x) };
Pcharclass lowalpha {is_lowalpha};

int is_upalpha(char x) { return IS_AtoZ(x); };
Ptypedef Pchar upalpha_t : upalpha_t x => { is_upalpha(x) };
Pcharclass upalpha {is_upalpha};

int is_alpha(char x) { return IS_ALPHA(x); };
Ptypedef Pchar alpha_t : alpha_t x => { is_alpha(x) };
Pcharclass alpha {is_alpha};

int is_alphanum(char x) { return IS_ALPHANUM(x); };
Ptypedef Pchar alphanum_t : alphanum_t x => { is_alphanum(x) };
Pcharclass alphanum {is_alphanum};

int is_mark(char x) { return IS_MARK(x); };
Ptypedef Pchar mark_t : mark_t x => { is_mark(x) };
Pcharclass mark {is_mark};

int is_reserved(char x) { return IS_RESERVED(x); };
Ptypedef Pchar reserved_t : reserved_t x => { is_reserved(x) };
Pcharclass reserved {is_reserved};

int is_unreserved(char x) { return IS_UNRESERVED(x); };
Ptypedef Pchar unreserved_t : unreserved_t x => { is_unreserved(x) };
Pcharclass unreserved {is_unreserved};

Pstruct escaped_t {
   "%";
   hex_t hex;
   hex_t _bnf_32;
};

Ptypedef Pstring_ME(:"/[[:digit:]]+/":) port_t;

Ptypedef Pstring_ME(: "/[[:alpha:]]([[:alpha:]]|[[:digit:]]|\\+|\\-|\\.)*/" :) scheme_t;

Ptypedef Pstring_ME(: "/[[:alphanum:]]|(([[:alphanum:]]([[:alphanum:]]|\\-)*)[[:alphanum:]])/" :) domainlabel_t;

Ptypedef Pstring_ME(: "/[[:alpha:]]|(([[:alpha:]]([[:alphanum:]]|\\-)*)[[:alphanum:]])/" :) toplabel_t;

// longest match of label_t is length 0 only if next char is not an alphanum
Ptypedef Pstring_ME(: "/(([[:alphanum:]]([[:alphanum:]]|\\-)*)[[:alphanum:]])|[[:alphanum:]]?/" :) label_t;

int alphaStart(Pstring *s) { return (s->len && IS_ALPHA(s->str[0])); }

// hostname_t : array of 1 or more labels separated by "."
//    allows optional trailing "." if a zero-length label is read
//    (zero-length label is not placed in the array)
Parray hostname_t {
  label_t [1:] : Psep(".") && Pterm(Pnosep) && Plongest_check(hostname_t[current].len == 0);
};
// need to add post-constraint check: final label (toplabel) does not start with a digit

Punion host_t {
   hostname_t hostname;
   IPv4address_t IPv4address;
};

Pstruct _bnf_12_t {
   ":";
   port_t port;
};
Punion _bnf_11_t {
   _bnf_12_t _bnf_12;
   Pvoid(_bnf_36);
};
Pstruct hostport_t {
   host_t host;
   _bnf_11_t _bnf_11;
};

#define URIC_PAT "(\\%[[:hex:]][[:hex:]]|[[:reserved:][:unreserved:]])"
#define URIC_NO_SLASH_PAT "(\\%[[:hex:]][[:hex:]]|[[:unreserved:]\\;\\?\\:\\@\\&\\=\\+\\$\\,])"
#define URIC_NO_SLASH_NO_Q_PAT "(\\%[[:hex:]][[:hex:]]|[[:unreserved:]\\;\\:\\@\\&\\=\\+\\$\\,])"
#define URIC_NO_SLASH_NO_Q_NO_COL_PAT "(\\%[[:hex:]][[:hex:]]|[[:unreserved:]\\;\\@\\&\\=\\+\\$\\,])"
#define URIC_NO_SLASH_NO_AT_NO_Q_PAT "(\\%[[:hex:]][[:hex:]]|[[:unreserved:]\\;\\:\\&\\=\\+\\$\\,])"
#define URIC_NO_SLASH_NO_SEMI_NO_Q_PAT "(\\%[[:hex:]][[:hex:]]|[[:unreserved:]\\:\\@\\&\\=\\+\\$\\,])"

Ptypedef Pstring_ME(: "/" URIC_PAT "*/" :) fragment_t;
Ptypedef Pstring_ME(: "/" URIC_PAT "*/" :) query_t;
Ptypedef Pstring_ME(: "/" URIC_NO_SLASH_NO_SEMI_NO_Q_PAT "*/" :) param_t;
Ptypedef Pstring_ME(: "/" URIC_NO_SLASH_NO_Q_PAT "*/" :) reg_name_t;
Ptypedef Pstring_ME(: "/" URIC_NO_SLASH_NO_Q_NO_COL_PAT "*/" :) rel_segment_t;
Ptypedef Pstring_ME(: "/" URIC_NO_SLASH_PAT URIC_PAT  "*/" :) opaque_part_t;
Ptypedef Pstring_ME(: "/" URIC_NO_SLASH_NO_AT_NO_Q_PAT "*/" :) userinfo_t;

Parray segment_t {
  param_t[1:] : Psep(";") && Pterm(Pnosep);
};

Parray path_segments_t {
  segment_t[1:] : Psep("/") && Pterm(Pnosep);
}

Pstruct abs_path_t {
   "/";
   path_segments_t path_segments;
};

Punion opt_abs_path_t {
   abs_path_t abs_path;
   Pvoid(no_abs_path);
};

Pstruct rel_path_t {
   rel_segment_t  rel_segment;
   opt_abs_path_t opt_abs_path;
};

Punion path_t {
   abs_path_t      path;
   opaque_part_t   opaque_part;
   Pvoid(no_path);
};

Pstruct _bnf_20_t {
   userinfo_t userinfo;
   "@";
};

Punion _bnf_19_t {
   _bnf_20_t _bnf_20;
   Pvoid(_bnf_93);
};

Pstruct _bnf_18_t {
   _bnf_19_t _bnf_19;
   hostport_t hostport;
};

Punion server_t {
   _bnf_18_t _bnf_18;
   Pvoid(_bnf_94);
};

Punion authority_t {
   server_t server;
   reg_name_t reg_name;
};

Punion _bnf_21_t {
   abs_path_t _bnf_95;
   Pvoid(_bnf_96);
};

Pstruct net_path_t {
   "//";
   authority_t authority;
   _bnf_21_t _bnf_21;
};

Punion _bnf_22_t {
   net_path_t net_path;
   abs_path_t _bnf_97;
};

Pstruct _bnf_24_t {
   "?";
   query_t query;
};

Punion _bnf_23_t {
   _bnf_24_t _bnf_24;
   Pvoid(_bnf_98);
};

Pstruct hier_part_t {
   _bnf_22_t _bnf_22;
   _bnf_23_t _bnf_23;
};

Punion _bnf_25_t {
   hier_part_t hier_part;
   opaque_part_t _bnf_99;
};

Pstruct absoluteURI_t {
   scheme_t scheme;
   ":";
   _bnf_25_t _bnf_25;
};

Punion _bnf_26_t {
   net_path_t _bnf_100;
   abs_path_t _bnf_101;
   rel_path_t rel_path;
};

Pstruct _bnf_28_t {
   "?";
   query_t query;
};

Punion _bnf_27_t {
   _bnf_28_t _bnf_28;
   Pvoid(_bnf_102);
};

Pstruct relativeURI_t {
   _bnf_26_t _bnf_26;
   _bnf_27_t _bnf_27;
};

Punion _bnf_29_t {
   absoluteURI_t absoluteURI;
   relativeURI_t relativeURI;
   Pvoid(_bnf_103);
};

Pstruct _bnf_31_t {
   "#";
   fragment_t fragment;
};

Punion _bnf_30_t {
   _bnf_31_t _bnf_31;
   Pvoid(_bnf_104);
};

Precord Pstruct URI_reference_t {
   _bnf_29_t _bnf_29;
   _bnf_30_t _bnf_30;
};

