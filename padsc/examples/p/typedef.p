Precord Ptypedef Puint64 pn_t(:Puint64 lo, Puint64 hi:) : pn_t x => {x > lo && x <= hi};

Psource Parray source {
 pn_t(:1,10000000000:) [];		      
};







