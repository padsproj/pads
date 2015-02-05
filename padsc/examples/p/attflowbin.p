Ptypedef Pb_uint32 My_ipaddr_t;
Ptypedef Pb_uint32 My_time_t;

Precord Pstruct attflow {
  Pstring_FW(:32:  )             PopNm;      //- Analyzer POP name.
  Pb_uint64                      FlowID;     //- Flow id: [SourceIP+DestIP+SourcePort+DestPort+PROTOCOL].
  My_ipaddr_t                    AnalyzerIP; //- Analyzer IP address.
  Pb_uint32                      AnalyzerID; //- Analyzer ID.
  My_ipaddr_t                    SourceIP;   //- Source IP address.
  My_ipaddr_t                    DestIP;     //- Destination IP address.
  Pb_uint32                      PktsSent;   //- Number of packets sent by source.
  Pb_uint32                      BytesSent;  //- Number of bytes sent by source.
  My_time_t                      StartTime;  //- Time for the first packet in the flow.
  My_time_t                      EndTime;    //- Time for the last packet in the flow.
  Pb_uint32                      SourcePort; //- TCP/UDP source port number or ICMP code+type. [MAP icmpcode]
  Pb_uint32                      DestPort;   //- TCP/UDP destination port number or 0 for ICMP.
  Pb_uint32                      Flags;      //- Inclusive OR of flags for all packets in the flow. [MAP ipflags]
  Pb_uint32                      Protocol;   //- IP protocol. [MAP ipprotocol]
};

// length: 32 + 8 + 12*4 = 88 bytes 
