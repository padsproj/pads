Punion foo(: Pint32 msg:) {
   Pswitch (msg) {
       Pcase 4:  Pint32 t04;
       Pdefault: Pb_uint16 [4] tushorts_1;
   }
};

Punion bar(: Puint32 len, Pint32 pkt :) {
   Pswitch (pkt) {
       Pcase 2: Pb_uint16 [len / 4] tushorts;
       Pcase 0: Pb_uint8 [3] bytes;
   }
};
