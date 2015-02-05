#define Pvoid(label) Pcompute Pomit Puint32 label = 0

int is_CR(Pchar x) { return (x == 13); };
Ptypedef Pchar CR_t : CR_t x => { is_CR(x) };
Pcharclass CR {is_CR};
#define RE_CR "[[:CR:]]"
int is_DQUOTE(Pchar x) { return
  (x == 34)
  ;
};
Ptypedef Pchar DQUOTE_t : DQUOTE_t x => { is_DQUOTE(x) };
Pcharclass DQUOTE {is_DQUOTE};
#define RE_DQUOTE "[[:DQUOTE:]]"
int is_HT(Pchar x) { return (x == 9); };
Ptypedef Pchar HT_t : HT_t x => { is_HT(x) };
Pcharclass HT {is_HT};
#define RE_HT "[[:HT:]]"
int is_LF(Pchar x) { return (x == 10); };
Ptypedef Pchar LF_t : LF_t x => { is_LF(x) };
Pcharclass LF {is_LF};
#define RE_LF "[[:LF:]]"
#define RE_CRLF "(" RE_CR "" RE_LF ")"
Ptypedef Pstring_ME(:"/" RE_CRLF "/":) CRLF_t;
int is_NO_WS_CTL(Pchar x) { return
  ((x >= 1) && (x <= 8))
  || (x == 11)
  || (x == 12)
  || ((x >= 14) && (x <= 31))
  || (x == 127)
  ;
};
Ptypedef Pchar NO_WS_CTL_t : NO_WS_CTL_t x => { is_NO_WS_CTL(x) };
Pcharclass NO_WS_CTL {is_NO_WS_CTL};
#define RE_NO_WS_CTL "[[:NO_WS_CTL:]]"
int is_SP(Pchar x) { return (x == 32); };
Ptypedef Pchar SP_t : SP_t x => { is_SP(x) };
Pcharclass SP {is_SP};
#define RE_SP "[[:SP:]]"
#define RE_LWS "(" RE_CRLF "?(" RE_SP "|" RE_HT ")+)"
Ptypedef Pstring_ME(:"/" RE_LWS "/":) LWS_t;
int is_TEXT(Pchar x) { return
  ((x >= 32) && (x <= 126))
  || (x >= 128);
};
Ptypedef Pchar TEXT_t : TEXT_t x => { is_TEXT(x) };
Pcharclass TEXT {is_TEXT};
#define RE_TEXT "[[:TEXT:]]"
int is_WSP(Pchar x) { return
  (x == 9)
  || (x == 32)
  ;
};
Ptypedef Pchar WSP_t : WSP_t x => { is_WSP(x) };
Pcharclass WSP {is_WSP};
#define RE_WSP "[[:WSP:]]"
#define RE_comment_mailbox "XX"
Ptypedef Pstring_ME(:"/" RE_comment_mailbox "/":) comment_mailbox_t;
#define RE_obs_FWS "(" RE_WSP "+(" RE_CRLF "" RE_WSP "+)*)"
Ptypedef Pstring_ME(:"/" RE_obs_FWS "/":) obs_FWS_t;
#define RE_FWS "(((" RE_WSP "*" RE_CRLF ")?" RE_WSP "+)|" RE_obs_FWS ")"
Ptypedef Pstring_ME(:"/" RE_FWS "/":) FWS_t;
#define RE_CFWS "((" RE_FWS "?" RE_comment_mailbox ")*((" RE_FWS "?" RE_comment_mailbox ")|" RE_FWS "))"
Ptypedef Pstring_ME(:"/" RE_CFWS "/":) CFWS_t;
int is_obs_char(Pchar x) { return
     (x <= 9)
  || (x == 11)
  || (x == 12)
  || ((x >= 14) && (x <= 127))
  ;
};
Ptypedef Pchar obs_char_t : obs_char_t x => { is_obs_char(x) };
Pcharclass obs_char {is_obs_char};
#define RE_obs_char "[[:obs_char:]]"
#define RE_obs_qp "(\\\\[\\x0-\\x7f])"
Ptypedef Pstring_ME(:"/" RE_obs_qp "/":) obs_qp_t;
#define RE_obs_text "(" RE_LF "*" RE_CR "*(" RE_obs_char "" RE_LF "*" RE_CR "*)*)"
Ptypedef Pstring_ME(:"/" RE_obs_text "/":) obs_text_t;
int is_qtext(Pchar x) { return
  is_NO_WS_CTL(x)
  || (x == 33)
  || ((x >= 35) && (x <= 91))
  || ((x >= 93) && (x <= 126))
  ;
};
Ptypedef Pchar qtext_t : qtext_t x => { is_qtext(x) };
Pcharclass qtext {is_qtext};
#define RE_qtext "[[:qtext:]]"
int is_separators(Pchar x) { return
  (x == 40)
  || (x == 41)
  || (x == 60)
  || (x == 62)
  || (x == 64)
  || (x == 44)
  || (x == 59)
  || (x == 58)
  || (x == 92)
  || (x == 34)
  || (x == 47)
  || (x == 91)
  || (x == 93)
  || (x == 63)
  || (x == 61)
  || (x == 123)
  || (x == 125)
  || is_SP(x)
  || is_HT(x)
  ;
};
Ptypedef Pchar separators_t : separators_t x => { is_separators(x) };
Pcharclass separators {is_separators};
#define RE_separators "[[:separators:]]"
#define RE_text "([\\x1-\\x9]|\\xb|\\xc|[\\xe-\\x7f]|" RE_obs_text ")"
Ptypedef Pstring_ME(:"/" RE_text "/":) text_t;
#define RE_quoted_pair_mailbox "((\\\\" RE_text ")|" RE_obs_qp ")"
Ptypedef Pstring_ME(:"/" RE_quoted_pair_mailbox "/":) quoted_pair_mailbox_t;
#define RE_qcontent "(" RE_qtext "|" RE_quoted_pair_mailbox ")"
Ptypedef Pstring_ME(:"/" RE_qcontent "/":) qcontent_t;
#define RE_quoted_string "(" RE_CFWS "?" RE_DQUOTE "(" RE_FWS "?" RE_qcontent ")*" RE_FWS "?" RE_DQUOTE "" RE_CFWS "?)"
Ptypedef Pstring_ME(:"/" RE_quoted_string "/":) quoted_string_t;
int is_token_char(Pchar x) { return
  (x == 33)
  || ((x >= 35) && (x <= 39))
  || ((x >= 42) && (x <= 43))
  || ((x >= 45) && (x <= 46))
  || ((x >= 48) && (x <= 57))
  || (x == 63)
  || ((x >= 65) && (x <= 90))
  || ((x >= 94) && (x <= 122))
  || (x == 124)
  || ((x >= 126) && (x <= 127))
  ;
};
Ptypedef Pchar token_char_t : token_char_t x => { is_token_char(x) };
Pcharclass token_char {is_token_char};
#define RE_token_char "[[:token_char:]]"
#define RE_token "" RE_token_char "+"
Ptypedef Pstring_ME(:"/" RE_token "/":) token_t;
#define RE_field_name RE_token
Ptypedef Pstring_ME(:"/" RE_field_name "/":) field_name_t;
#define RE_ws "(\\x20|\\x9)*"
Ptypedef Pstring_ME(:"/" RE_ws "/":) ws_t;
#define RE_field_content0 "((" RE_token "|" RE_separators "|" RE_quoted_string ")(" RE_ws "(" RE_token "|" RE_separators "|" RE_quoted_string "))*)?"
Ptypedef Pstring_ME(:"/" RE_field_content0 "/":) field_content0_t;
#define RE_field_content "(" RE_TEXT "*|" RE_field_content0 ")"
Ptypedef Pstring_ME(:"/" RE_field_content "/":) field_content_t;
Punion _bnf_1_t {
  field_content_t field_content;
  LWS_t LWS;
};
Punion _bnf_3_t {
  field_content_t _bnf_5;
  LWS_t _bnf_6;
};
Pstruct _bnf_7_t {
  ws_t ws;
  _bnf_3_t _bnf_3;
};
Parray _bnf_2_t {
  _bnf_7_t[] : Plongest;
};
Pstruct _bnf_0_t {
  _bnf_1_t _bnf_1;
  _bnf_2_t _bnf_2;
};
Punion field_value_t {
  _bnf_0_t _bnf_0;
  Pvoid(_bnf_8);
};
Punion _bnf_4_t {
  field_value_t field_value;
  Pvoid(_bnf_9);
};
Pstruct message_header_t {
  field_name_t field_name;
  ws_t ws;
  ":";
  ws_t _bnf_10;
  _bnf_4_t _bnf_4;
};
