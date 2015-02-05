Precord Pstruct syslog {
      Pdate(:'|':) syslog_date;                /- DATE
'|';  Pstring(:'|':) syslog_time;              /- VARCHAR2(30)
'|';  Pstring(:'|':) router_name;              /- VARCHAR2(30)
'|';  Pstring(:'|':) classification;           /- VARCHAR2(30)
'|';  Pstring(:'|':) source_router;            /- VARCHAR2(30)
'|';  Pstring(:'|':) source_interface;         /- VARCHAR2(30)
'|';  Pstring(:'|':) dest_router;              /- VARCHAR2(30)
'|';  Pstring(:'|':) dest_interface;           /- VARCHAR2(30)
'|';  Pstring(:'|':) message;                  /- VARCHAR2(30)
'|';  Pstring_SE(:Pre "/$/":) link_ospf_state; /- VARCHAR2(30)
};
Psource Parray syslogs {
  syslog [];
};
