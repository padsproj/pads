#define DEF_INPUT_FILE "../../data/wsl"
#include "wsl.h"
#define PADS_TY(suf) entry_t ## suf
#define IO_DISC_MK P_nlrec_make(0)


/*  fmt function used to override the default Phostname fmt function.
    Shortly, Phostname will become a built in PADS type, at which
    point, this function will no longer be necessary */
ssize_t
my_Phostname_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
	       int *buf_full, int *requested_out, char const *delims,
	       void *m, void  *pd, void *rep, va_list type_args)
{
  Phostname  *t_rep = (Phostname*)    rep;
  Sfio_t     *tmpstr;
  ssize_t     res = 0;
  int         i;

  (*requested_out) = 1;
  if (!(tmpstr = sfstropen ())) { 
    return -1;
  };
  for (i = 0; i < t_rep->length - 1; i++){
    Pstring_preserve(pads, &t_rep->elts[i]);
    res += sfprintf(tmpstr, "%s.", t_rep->elts[i].str);
    if (res > buf_len) { // not enough space in buffer
      (*buf_full) = 1;
      return -1;
    };
  };
  Pstring_preserve(pads, &t_rep->elts[t_rep->length - 1]);
  res += sfprintf(tmpstr, "%s", t_rep->elts[t_rep->length -1].str);

  memcpy(buf, sfstruse(tmpstr), res);
  return res;
}

#define FMT_OVERRIDE_TY1   "Phostname"
#define FMT_OVERRIDE_FN1   my_Phostname_fmt2buf
#define DATE_OUT_FMT "%D:%T"
#define DELIMS "|"
#include "template/read_format.h"
