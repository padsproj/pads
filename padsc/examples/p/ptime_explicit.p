Precord Pstruct threetimes {
  Ptime_explicit_FW(: 6, "%H%M%S", P_cstr2timezone("UTC") :) time1; '|';
  Ptime_explicit_ME(: "/\\d\\d\\:\\d\\d\\:\\d\\d/", "%H:%M:%S", P_cstr2timezone("UTC") :) time2; '|';
  Ptime_explicit_SE(: "/$/", "%H:%M:%S", P_cstr2timezone("UTC") :) time3;
};
