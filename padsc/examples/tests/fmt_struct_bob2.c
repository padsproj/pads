#include "struct_bob2.h"

// fmt function used to override the default Pstring fmt function
ssize_t
my_string_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
		  int *buf_full, int *requested_out, char const *delims,
		  void *m, void  *pd, void *rep, va_list type_args)
{
  Pstring    *t_rep = (Pstring*)    rep;
  Pbase_pd   *t_pd  = (Pbase_pd*)   pd;
  // Pbase_m    *t_m   = (Pbase_m*)    m;
  Sfio_t     *tmpstr;
  ssize_t     res;

  // format a string using format:
  //     string[foo]
  // or
  //     string[ERROR]
  //
  (*requested_out) = 1;
  if (!(tmpstr = sfstropen ())) { 
    return -1;
  }
  if (!t_pd->nerr) { // not an error, use the string (otherwise uses ERROR setup above)
    res = sfprintf(tmpstr, "string[%.*s]", t_rep->len, t_rep->str);
  } else {
    res = sfprintf(tmpstr, "string[ERROR]");
  }
  if (res > buf_len) { // not enough space in buffer
    (*buf_full) = 1;
    return -1;
  }
  memcpy(buf, sfstruse(tmpstr), res);
  return res;
}

// fmt function used to override the default test_fmt function
// 
// In this case we only output the c and id fields,
// and we reverse the order so that id comes first.

ssize_t
my_test_fmt2buf(P_t *pads, Pbyte *buf, size_t buf_len,
		int *buf_full, int *requested_out, char const *delims,
		void *m, void  *pd, void *rep, va_list type_args)
{
  test          *t_rep = (test*)    rep;
  test_pd       *t_pd  = (test_pd*) pd;
  test_m        *t_m   = (test_m*)  m;

  ssize_t        res   = 0;
  ssize_t        tres;
  int            id_requested_out = 0, c_requested_out = 0;
  char           dlm;

  // grab the delimiter to use and advance delims to the next one
  dlm = *delims;
  delims = P_ADVANCE_DELIMS(delims);
  // (since we only use base type write2buf calls below, there is
  //  actually no need to advance delims, but in general it should be done)

  // output Puint32 id
  tres = Puint32_fmt2buf(pads, buf, buf_len, buf_full, &id_requested_out, delims,
			 &(t_m->id), &(t_pd->id), &(t_rep->id));
  if (tres < 0) {
    return -1; // call resulted in an error or buf_full problem
  }
  // update res (total bytes added), buf, and buf_len
  res += tres;
  buf += tres;
  buf_len -= tres;

  if (id_requested_out) { // need to put in a delim
    tres = Pchar_lit_write2buf(pads, buf, buf_len, buf_full, dlm);
    if (tres < 0) {
      return -1; // call resulted in an error or buf_full problem
    }
    // update res (total bytes added), buf, and buf_len
    res += tres;
    buf += tres;
    buf_len -= tres;
  }

  // output string c
  tres = Pstring_fmt2buf(pads, buf, buf_len, buf_full, &c_requested_out, delims,
			 &(t_m->c), &(t_pd->c), &(t_rep->c), '|');
  if (tres < 0) {
    return -1; // call resulted in an error or buf_full problem
  }
  // update res (total bytes added)
  res += tres;
  // we do not need to update buf or buf_len because we have no
  // more fmt calls to make

  // done -- set (*requested_out) to 1 if either the id or c field requested it
  (*requested_out) = (id_requested_out || c_requested_out) ? 1 : 0;
  return res;
}

#define FMT_OVERRIDE_TY1   "Pstring"
#define FMT_OVERRIDE_FN1   my_string_fmt2buf

#define FMT_OVERRIDE_TY2   "test"
#define FMT_OVERRIDE_FN2   my_test_fmt2buf

#define DEF_INPUT_FILE "../../data/struct_bob2"

//#define MASK_MOD   P_Dont_Write(m.compoundLevel);
//#define MASK_MOD   P_Dont_Write(m.header.c); P_Do_WriteVoid(m.header.c); P_Dont_Write(m.header.ts); P_Do_WriteVoid(m.header.ts);
//#define MASK_MOD   P_Dont_Write(m.header.compoundLevel);

#define WSPACE_OK 1
#define PADS_TY(suf) testtwo ## suf
#define DELIMS "|,"
#define FMT_ERROR_CASES 1
#include "template/read_format.h"
