Pstruct interface {
      Pstring(:'|':) network;                  /- VARCHAR (10)    NOT NULL
'|';  Pstring(:'|':) router_name;              /- VARCHAR(14)     NOT NULL
'|';  Pstring(:'|':) card;                     /- VARCHAR2(26)    NOT NULL
'|';  Pstring(:'|':) interface_date;           /- DATE            NOT NULL
'|';  Pstring(:'|':) interface_type;           /- VARCHAR2(20)
'|';  Pstring(:'|':) interface_ip;             /- VARCHAR2(16)
'|';  Pstring(:'|':) interface_mask;           /- VARCHAR2(16)
'|';  Pstring(:'|':) description;              /- VARCHAR2(120)
'|';  Pstring(:'|':) shutdown;                 /- VARCHAR2(2)
'|';  Pstring(:'|':) encapsulation;            /- VARCHAR2(20)
'|';  Pstring(:'|':) ospf_weight;              /- VARCHAR2(6)
'|';  Pstring(:'|':) in_access_group;          /- VARCHAR2(6)
'|';  Pstring(:'|':) out_access_group;         /- VARCHAR2(6)
'|';  Pstring(:'|':) dsu_bandwidth;            /- VARCHAR2(7)
'|';  Pstring(:'|':) bandwidth;                /- VARCHAR2(7)
'|';  Pstring(:'|':) mtu;                      /- VARCHAR2(6)
'|';  Pstring(:'|':) cablelength;              /- VARCHAR2(4)
'|';  Pstring(:'|':) crc;                      /- VARCHAR2(3)
'|';  Pstring(:'|':) framing;                  /- VARCHAR2(6)
'|';  Pstring(:'|':) cdp;                      /- VARCHAR2(2)
'|';  Pstring(:'|':) clock_si;                 /- VARCHAR2(2)
'|';  Pstring_SE(:Pre "/$/":) dir_broadcast;           /- VARCHAR2(2)
'\n';
};
