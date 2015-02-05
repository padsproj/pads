Pstruct Hdr_v1
{
  Pendian Pb_uint16  version : version == 1; 
  Pb_uint16          count;
  Pb_uint32          uptime;
  Pb_uint32          sec;
  Pb_uint32          usec;
};

Pstruct Hdr_v5
{
  Pendian Pb_uint16  version : version == 5; 
  Pb_uint16          count;
  Pb_uint32          uptime;
  Pb_uint32          sec;
  Pb_uint32          usec;
  Pb_uint32          flow_sequence;
  Pb_uint8           engine_type;
  Pb_uint8           engine_id;
  Pb_uint16          sampling_interval;
};

Pstruct Hdr_v7
{
  Pendian Pb_uint16  version : version == 7;
  Pb_uint16          count;
  Pb_uint32          uptime;
  Pb_uint32          sec;
  Pb_uint32          usec;
  Pb_uint32          flow_sequence;
};

Pstruct Data_v1
{
  Pb_uint32    src_addr;
  Pb_uint32    dst_addr;
  Pb_uint32    hop;
  Pb_uint16    input;
  Pb_uint16    output;
  Pb_uint32    packets;
  Pb_uint32    bytes;
  Pb_uint32    first;
  Pb_uint32    last;
  Pb_uint16    src_port;
  Pb_uint16    dst_port;
  Pb_uint16    pad1;
  Pb_uint8     prot;
  Pb_uint8     tos;
  Pb_uint8     flags;
  Pb_uint8     tcp_retx_cnt;
  Pb_uint8     tcp_retx_secs;
  Pb_uint8     tcp_misseq_cnt;
};

Pstruct Data_v5
{
  Pb_uint32    src_addr;
  Pb_uint32    dst_addr;
  Pb_uint32    hop;
  Pb_uint16    input;
  Pb_uint16    output;
  Pb_uint32    packets;
  Pb_uint32    bytes;
  Pb_uint32    first;
  Pb_uint32    last;
  Pb_uint16    src_port;
  Pb_uint16    dst_port;
  Pb_uint8     pad1;
  Pb_uint8     tcp_flags;
  Pb_uint8     prot;
  Pb_uint8     tos;
  Pb_uint16    src_as;
  Pb_uint16    dst_as;
  Pb_uint8     src_mask;
  Pb_uint8     dst_mask;
};

Pstruct Data_v7
{
  Pb_uint32    src_addr;
  Pb_uint32    dst_addr;
  Pb_uint32    hop;
  Pb_uint16    input;
  Pb_uint16    output;
  Pb_uint32    packets;
  Pb_uint32    bytes;
  Pb_uint32    first;
  Pb_uint32    last;
  Pb_uint16    src_port;
  Pb_uint16    dst_port;
  Pb_uint8     flags;
  Pb_uint8     tcp_flags;
  Pb_uint8     prot;
  Pb_uint8     tos;
  Pb_uint16    src_as;
  Pb_uint16    dst_as;
  Pb_uint8     src_mask;
  Pb_uint8     dst_mask;
  Pb_uint16    pad2;
  Pb_uint32    router_sc;
};

Pstruct Packet_v1 {
  Hdr_v1   h;
  Data_v1  d;
};

Pstruct Packet_v5 {
  Hdr_v5   h;
  Data_v5  d;
};

Pstruct Packet_v7 {
  Hdr_v7   h;
  Data_v7  d;
};

Parray PacketArray_v1 { Packet_v1 []; };
Parray PacketArray_v5 { Packet_v5 []; };
Parray PacketArray_v7 { Packet_v7 []; };

Punion Netflow {
  PacketArray_v1 v1;
  PacketArray_v5 v5;
  PacketArray_v7 v7;
};

