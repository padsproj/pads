Precord Ptypedef Pstring_SE(:Peor:) header_line_t;

Parray header_piece_t {
  header_line_t [] : Pterm("--");
};

Parray columns_t{
  Pstring_SE(:"/[\t\r]/":) [8] : Psep('\t');
};

Precord Pstruct header_t{
  header_piece_t       disclaimer;
  Pomit header_line_t  dash1;
  header_piece_t       description;
  Pomit header_line_t  dash2;
  Pomit header_line_t  blank;
  columns_t            columns;
  '\r';
};

Parray aliasSeq_t {
  Pstring(:';':) [] : Psep(";") && Pterm(";\t");
};

Pstruct aliases_t {
  ';';
  aliasSeq_t as;
  ';';
};

Punion aliasInfo_t {
  "NONE";
  aliases_t as;
};


Parray pubmedSeq_t {
  Puint32 [] : Psep(";") && Pterm(";\r");
};

Pstruct pubmeds_t {
  ';';
  pubmedSeq_t ps;
  ';';
};

Punion pubMedsInfo_t{
  "UNKNOWN";
  pubmeds_t id;
};

Precord Pstruct entry_t {
  Pstring(:'\t':) interactor_a;  '\t';
  Pstring(:'\t':) interactor_b;  '\t'; 
  aliasInfo_t     alias_a;       '\t';
  aliasInfo_t     alias_b;       '\t';
  Pstring(:'\t':) experiment;    '\t'; 
  Pstring(:'\t':) source;        '\t'; 
  Pstring(:'\t':) direction;     '\t'; 
  pubMedsInfo_t   pub_meds;      '\r';
};

Psource Pstruct bio_t {
  header_t  h;
  entry_t[] entries;
};
