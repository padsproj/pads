Ptypedef Pint32 even : even x => {x % 2 == 0};
Ptypedef Pint32 odd  : odd  x => {x % 2 == 1};

Parray eseq_t {
  even [] : Psep(Pre "/a/") && Pended(Pparsecheck(pds[current].errCode != P_NO_ERR));
};

Parray oseq_t {
  odd [] :  Psep(Pre "/a/") && Pended(Pparsecheck(pds[current].errCode != P_NO_ERR)) && Pterm('b');
};

Precord Pstruct entry{
  eseq_t evens;
  'a';
  oseq_t odds;
  'b';
};
