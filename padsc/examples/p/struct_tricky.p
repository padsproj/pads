
Pstruct good {
  Pstring_ME(:"(.*)X/$/":)   field_1 : field_1.len > 0;
  Puint32                    field_2 : field_2 > 0;
  Puint32                    field_3 : field_3 > 0;
} Pwhere {
  (field_1.len < 100)
    && (field_2 < 100)
    && (field_3 < 100);
};

Pstruct bad {
  Pstring_ME(:"(.*)X/$/":)   f_1 : f_2 > 0;
  Puint32                    f_2 : f_3 > 0;
  Puint32                    f_3;
};
