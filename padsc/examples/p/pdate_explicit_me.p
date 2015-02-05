
Precord Pstruct threedates {
  Pdate_explicit_ME(: "/\\d+/", "%s", P_cstr2timezone("UTC") :) date1; '|';
  Pdate_explicit_ME(: "/\\d+/", "%s", P_cstr2timezone("UTC") :) date2; '|';
  Pdate_explicit_ME(: "/\\d+/", "%s", P_cstr2timezone("UTC") :) date3;
};
