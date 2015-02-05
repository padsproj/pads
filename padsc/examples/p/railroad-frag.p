//Ptypedef Pstring_ME(:"/([\"'])(([A-Za-z][A-Za-z0-9_\\-]*)|[,;. ])+([\"'])/":) Mytext;
Ptypedef Pstring_ME(:"|([\"])[A-Za-z]+([\"])|":) Mytext;

Pstruct entry_t{
  Mytext name; ',';
  //  PPtext place; ',';
  //  Puint8[] numbers: Psep(',');
};
