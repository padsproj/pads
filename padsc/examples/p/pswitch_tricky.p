
Punion good(:Puint32 a:) {
  Pswitch (a) {
    Pcase 1:  Pstring_ME(:"(.*)X/$/":)   branch_1 : branch_1.len > 0;
    Pcase 2:  Puint32                    branch_2 : branch_2 > 0;
    Pdefault: Puint32                    branch_d : branch_d > 0;
  }
} Pwhere {
  ( (tag == branch_1) ?
    (val.branch_1.len < 100) : ( (tag == branch_2) ?
				 (val.branch_2 < 100) : ( (tag == branch_d) ?
							  (val.branch_d < 100) : 0
							  )
				 )
    );
};

Punion bad(:Puint32 a:) {
  Pswitch (a) {
    Pcase 1:  Pstring_ME(:"(.*)X/$/":)   br_1 : br_d > 0;
    Pcase 2:  Puint32                    br_2 : br_1.len > 0;
    Pdefault: Puint32                    br_d : br_2 > 0;
  }
};
