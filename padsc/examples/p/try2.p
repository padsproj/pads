/*@FILE @LEFT try.tex */

/*@BEGIN try.tex */
Ptry ForwardInt Puint8_FW(:1:);

Punion VarInt(:Puint8 i:){
  Pswitch(i>5) {
    Pcase 0: Puint32 smallInt;
    Pcase 1: Puint64 largeInt;
  }
};

/*@END try.tex */
Precord 
/*@BEGIN try.tex */
Pstruct entry_t{
  ForwardInt           firstDigit;
  VarInt(:firstDigit:) fullNumber;
};
/*@END try.tex */
