
Punion good {
  Pstring_ME(:"(.*)X/$/":)   b_1 : b_1.len > 0;
  Puint32                    b_2 : b_2 > 0;
  Puint32                    b_3 : b_3 > 0;
} Pwhere {
  ( (tag == b_1) ?
    (val.b_1.len < 100) : ( (tag == b_2) ?
			    (val.b_2 < 100) : ( (tag == b_3) ?
						(val.b_3 < 100) : 0
						)
			    )
    );
};

Punion bad {
  Pstring_ME(:"(.*)X/$/":)   br_1 : br_3 > 0;
  Puint32                    br_2 : br_1.len > 0;
  Puint32                    br_3 : br_2 > 0;
};

