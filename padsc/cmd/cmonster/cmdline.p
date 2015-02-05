/*
 * This file describes two kinds of command-line arguments, CM_spec and CM_cspec
 * 
 * Some examples of valid CM_dspec:
 *
 *     fwrec(:80:)
 * OR
 *     nlrec(::)
 *
 * Some examples of valid CM_cspec:
 *
 *     c{qy1=Pa_string_FW(:8:)[172]|qy2=Pb_uint64(::)[8]}
 *
 *     s-{qy1=Pe_int32_FW(:3:)[90]/1:c{qy2=Pa_string_FW(:8:)[172]}}
 *
 *     s+{qy1=Pe_int32_FW(:3:)[90]/1:c{qy2=Pa_string_FW(:8:)[172]}/2:c{qy3=Pb_uint64(::)[202]}}
 *
 * Informal BNF for cookie_spec:
 *
 *          cookie :: s_cookie | c_cookie
 *        s_cookie :: "s" sval_out "{" s_qy "/" arms "}"
 *        sval_out :: "-" | "+"
 *            s_qy :: query
 *            arms :: arm | arm "/" arms
 *             arm :: s_val ":" c_cookie
 *        c_cookie :: "c{" queries "}"
 *         queries :: query | query "|" queries
 *           query :: qy_id "=" ty_id "(" params ")" "[" off "]"
 *          params :: param | param "," params
 *           qy_id :: ID
 *           ty_id :: ID
 *           s_val :: INT
 *           param :: UINT
 *             off :: UINT
 */

/* predeclare some types */
typedef struct CM_tmentry_s  CM_tmentry_t;

typedef struct CM_c_cookie_s CM_c_cookie_t;    /* aka CM_c_cookie */
typedef struct CM_s_cookie_s CM_s_cookie_t;    /* aka CM_s_cookie */

/* Finishing functions that fill in
 * NULL Pcompute fields (in cookies and their contained queries).
 * Should return 1 or abort on error.
 */

int CM_finish_c_cookie(CM_c_cookie_t *c);
int CM_finish_s_cookie(CM_s_cookie_t *s);

Parray CM_params {
  Pa_uint32 [] : Psep(',') && Pterm(':');
};

Pstruct CM_query {
  Pa_string(:'=':)         qy_id;
  '=';
  Pa_string(:'(':)         ty_id;
  "(:";
  CM_params                params;
  ":)[";
  Pa_uint32                off;
  ']';
  /* additional (non-parsed) state */
  Pcompute CM_tmentry_t   *entry  = (CM_tmentry_t*)0;
  Pcompute Puint32         in_sz  = 0;
  Pcompute Puint32         out_sz = 0;
};

Parray CM_queries {
  CM_query [1:] : Psep('|') && Pterm('}') ;
};

Pstruct CM_c_cookie {
  "c{";
  CM_queries               queries;
  "}";
  /* additional (non-parsed) state */
  Pcompute Puint32         out_sz = 0;
} Pwhere {
  CM_finish_c_cookie(rep);
};

Pstruct CM_arm {
  Pa_int32                 s_val;
  ':';
  CM_c_cookie              cookie;
};

/* note that this array 'eats' the terminating curly */
Parray CM_arms {
  CM_arm [1:] : Psep('/') && Pterm('}');
};

Pstruct CM_s_cookie {
  's';
  Pomit Pa_char            sval_out_char : sval_out_char == '+' || sval_out_char == '-';
  Pcompute Pint32          sval_out = ((sval_out_char == '+') ? 1 : 0);
  '{';
  CM_query                 s_qy;
  '/';
  CM_arms                  arms;
  /* additional (non-parsed) state */
  Pcompute Puint32         out_sz = 0;
} Pwhere {
  CM_finish_s_cookie(rep);
};

Punion CM_c_or_s {
  CM_c_cookie              c_cookie;
  CM_s_cookie              s_cookie;
};

Pstruct CM_cspec {
  CM_c_or_s                cookie;
};

Penum CM_disc {
  fwrec_noseek,
  ctrec_noseek,
  nlrec_noseek,
  vlrec_noseek,
  fwrec,
  ctrec,
  nlrec,
  vlrec
};

Pstruct CM_dspec {
  CM_disc                  disc;
  "(:";
  CM_params                params;
  ":)";
};
