Ptypedef Puint64 pn_t(:Puint64 lo, Puint64 hi:) : pn_t x => {x > lo && x <= hi};

Precord Pstruct defPN (:Puint64 lo, Puint64 hi:){
  pn_t(:lo, hi:) id; 
};

#if 0
Pstruct defPN{
  "no_PN";
  Puint32 id;
};



#define MINPN 19999999999
#define MAXPN 99999999999

Punion dibblerPN{
  defPN                  derived;   /- No phone number from data source; generated dummy for tracking
  pn_t(:MINPN, MAXPN:)   supplied;  /- Phone number given in data source;
};
#endif








