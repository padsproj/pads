
Ptypedef Puint32 My_time_t;

Precord Pstruct attflow {
  Puint64                        FlowID;     '|'; //- Flow id: [SourceIP+DestIP+SourcePort+DestPort+PROTOCOL].
  Pstring(:'|':)                 AnalyzerIP; '|'; //- Analyzer IP address.
  Puint32                        AnalyzerID; '|'; //- Analyzer ID.
  Pstring(:'|':)                 PopNm;      '|'; //- Analyzer POP name.
  Pip                            SourceIP;   '|'; //- Source IP address.
  Pip                            DestIP;     '|'; //- Destination IP address.
  Puint32                        PktsSent;   '|'; //- Number of packets sent by source.
  Puint32                        BytesSent;  '|'; //- Number of bytes sent by source.
  My_time_t                      StartTime;  '|'; //- Time for the first packet in the flow.
  My_time_t                      EndTime;    '|'; //- Time for the last packet in the flow.
  Puint32                        SourcePort; '|'; //- TCP/UDP source port number or ICMP code+type. [MAP icmpcode]
  Puint32                        DestPort;   '|'; //- TCP/UDP destination port number or 0 for ICMP.
  Puint32                        Flags;      '|'; //- Inclusive OR of flags for all packets in the flow. [MAP ipflags]
  Puint32                        Protocol;   '|'; //- IP protocol. [MAP ipprotocol]
};

