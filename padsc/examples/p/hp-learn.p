Punion BTy_5 {
	Pstring_ME(:"/[[:word:]]/":) BTy_4;
	Pint32 BTy_6;
};
Precord Pstruct BTy_8 {
	"\"";	Pint32 BTy_1;
	", ";	BTy_5 BTy_5_Name;
	"\"";
};

Psource Parray entries_t {
	BTy_8[];
};

