#include "pads-internal.h"
#include <dt.h>

typedef struct int32_dt_elt_s {
  Pint32    val;
  Puint32   cnt;
  Dtlink_t     link;
} int32_dt_elt_t;

int int32_dt_elt_describe(Dt_t* dt, Void_t* a, Void_t* data)
{
  int32_dt_elt_t* elt = (int32_dt_elt_t*)a;
  NoP(data);
  error(0, "  dt_elt: val %3d cnt %3d", elt->val, elt->cnt);
  return 0;
}

int
int32_dt_elt_cmp(Dt_t* dt, int32_dt_elt_t* a, int32_dt_elt_t* b, Dtdisc_t* disc)
{
  NoP(dt);
  NoP(disc);
  if (a->val < b->val)
    return -1;
  if (a->val > b->val)
    return 1;
  return 0;
}

void*
int32_dt_elt_make(Dt_t* dt, int32_dt_elt_t* a, Dtdisc_t* disc)
{
   int32_dt_elt_t* b;
  if ((b = oldof(0, int32_dt_elt_t, 1, 0))) {
    b->val = a->val;
    b->cnt = a->cnt;
  }
  return b;
}

void
int32_dt_elt_free(Dt_t* dt, int32_dt_elt_t* a, Dtdisc_t* disc)
{
  free(a);
}

int main(int argc, char** argv) {
  Pint32       key1;
  Dt_t*           dict;
  Dtdisc_t        dt_disc;
  int32_dt_elt_t  insert_val;
  int32_dt_elt_t* tmp1;

  dt_disc.key     = 0;
  dt_disc.size    = 0;
  dt_disc.link    = offsetof(int32_dt_elt_t, link);
  dt_disc.makef   = (Dtmake_f)int32_dt_elt_make;
  dt_disc.freef   = (Dtfree_f)int32_dt_elt_free;
#if 1
  dt_disc.comparf = (Dtcompar_f)int32_dt_elt_cmp;
#else
  dt_disc.comparf = NiL;
#endif
  dt_disc.hashf   = NiL;
  dt_disc.memoryf = NiL;
  dt_disc.eventf  = NiL;

  error(0, "\n opening the dictionary:");
  if (!(dict = dtopen(&dt_disc, Dtoset))) {
    error(2, "** dtopen failed **");
    return -1;
  }

  for (key1 = -20; key1 < 30; key1 += 10) {
    insert_val.val = key1;
    insert_val.cnt = 0;
    if (!(tmp1 = dtinsert(dict, &insert_val))) {
      return -1;
    }
    tmp1->cnt++;
  }

  for (key1 = -20; key1 < 30; key1 += 10) {
    if (!(tmp1 = dtmatch(dict, &key1))) {
      error(0, "lookup error: did not find key %d", key1);
    }
  }

  error(0, "\n walking the dictionary:");
  dtwalk(dict, int32_dt_elt_describe, 0);

  error(0, "\n closing the dictionary:");
  dtclose(dict);

  return 0;

 insert_err:
  error(ERROR_SYSTEM|2, "dtinsert failed");
  dtclose(dict);
}
