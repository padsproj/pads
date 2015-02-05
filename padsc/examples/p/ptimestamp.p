Precord Pstruct threetimestamps {
  Ptimestamp(:'|':) ts1; '|';
  Ptimestamp(:'|':) ts2; '|';
  Ptimestamp_SE(:"/$/":) ts3;
};

Psource Parray source {
  threetimestamps[];
};		      
