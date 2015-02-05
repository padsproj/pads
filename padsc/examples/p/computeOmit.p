Pstruct ins_status
{
   Pb_uint16 status;
   Pcompute Pomit Puint32 align = (status & (1 << 15));
};
