
/* Example using two Pdate_explicit fields, one Pdate field */

Precord Pstruct threedates {
  Pdate(:'|':) date1; '|';
  Pdate_explicit(: '|',      "%y-%m-%d", P_cstr2timezone("-0400") :) date2; '|';
  Pdate_explicit_SE(: "/$/", "%m-%d-%y", P_cstr2timezone("-0500") :) date3;
}; 
