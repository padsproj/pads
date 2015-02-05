Punion last {
	    Pint8 i;
	    Pchar c;
};

Precord Pstruct entry_t {
			Pdate(:'|':) date;
			'|';
			Pip ip;
			'|';
			Pstring(:'|':) str;
			'|';
			Pint16 foo;
			'|';
			last l;			
} 
 
