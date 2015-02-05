/* record input format */
extern int i;

Precord Pstruct in_rec {
  Pa_string_FW(:8:) s;
};

/* record output format */
Precord Pstruct out_rec {
  Pe_string_FW(:8:) s;
};

Pfile Parray in_file {
  in_rec [];
};

Pfile Parray out_file {
  out_rec [];
};

