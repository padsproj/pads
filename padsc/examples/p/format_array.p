Parray foo_t{
  Puint8[] : Psep(',') && Pterm(':');
};

Precord Pstruct entry_t {
        Puint8 i;
	':';
	foo_t  v_array_7;
	':';
	Pstring_SE(:Peor:) slurp;
};
