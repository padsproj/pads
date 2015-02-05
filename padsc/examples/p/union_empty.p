Punion body_t(:Puint8 j:) {
  Pswitch (j) {
    Pcase 0 : Puint32 i;
    Pcase 1 : Pchar   c;
    Pdefault : Pempty;
  }
};

Precord Pstruct entry_t {
        Puint8 i;
	':';
	body_t(:i:) body;
};

