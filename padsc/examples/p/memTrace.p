Punion address_t{
  Puint32 nil : nil == 0;
  Pstring(:':':) val;
};

Precord Pstruct entry_t{
  address_t      old_address;  ':';
  address_t      new_address;  ':';
  Puint32        numAlloced;   ':';
  Puint32        alignment;    ':';
  address_t      region;       ':';
  Pchar          method;       ':';
};
