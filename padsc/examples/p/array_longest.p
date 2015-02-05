Ptypedef Pstring_ME(:"/[A-Za-z][A-Za-z0-9_\\-]*/":) PPstring;

Precord Parray Entry_t {
	PPstring [] : Psep('.') && Plongest;
};
