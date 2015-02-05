/*
 * Helpers
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "cmonster.h"
#include "helpers.h"

void describe_query(Sfio_t *io, CM_query *q)
{
  Puint32 len = q->params.length;
  int ok_switch_type;
  Puint32 i;

  ok_switch_type = (q->entry->sval_fn) ? 1 : 0;

  sfprintf(io, "%s = %s (", P_fmt_str(&(q->qy_id)), P_fmt_str(&(q->ty_id)));
  for (i = 0; i < len; i++) {
    if (i) sfprintf(io, ",");
    sfprintf(io, "%lu", (unsigned long)q->params.elts[i]);
  }
  sfprintf(io, ") [offset: %lu]", (unsigned long)q->off);
  sfprintf(io, " type: %s, ok_switch_type: %d, in_sz: %lu out_sz: %lu\n",
	q->entry->tname, ok_switch_type,
	(unsigned long)q->in_sz, (unsigned long)q->out_sz);
}

void describe_queries(Sfio_t *io, CM_queries *qs)
{
  Puint32 len = qs->length;
  Puint32 i;
  sfprintf(io, "          QUERIES:\n");
  for (i = 0; i < len; i++) {
    sfprintf(io, "            ");
    describe_query(io, &(qs->elts[i]));
  }
}

void describe_c_cookie(Sfio_t *io, CM_c_cookie *c)
{
  sfprintf(io, "        C_COOKIE (out_sz: %ld):\n", (long)c->out_sz);
  describe_queries(io, &(c->queries));
}

void describe_s_cookie(Sfio_t *io, CM_s_cookie *s)
{
  Puint32 len = s->arms.length;
  Puint32 i;
  sfprintf(io, "  S_COOKIE (out_sz: %ld):\n", (long)s->out_sz);
  sfprintf(io, "    SWITCH:\n");
  sfprintf(io, "            ");
  describe_query(io, &(s->s_qy));
  for (i = 0; i < len; i++) {
    sfprintf(io, "      ARM %d:\n", (int)s->arms.elts[i].s_val);
    describe_c_cookie(io, &(s->arms.elts[i].cookie));
  }
}

void describe_cookie(Sfio_t *io, CM_cspec *cspec)
{
  switch (cspec->cookie.tag) {
  case CM_c_or_s_err:
    sfprintf(io, "  Invalid c_or_s tag\n");
    break;
  case c_cookie:
    describe_c_cookie(io, &(cspec->cookie.val.c_cookie));
    break;
  case s_cookie:
    describe_s_cookie(io, &(cspec->cookie.val.s_cookie));
    break;
  }
}

Perror_t rw_c_cookie(CM_t *cm, CM_c_cookie *c, Pbyte *begin, Pbyte *end)
{
  Puint32 len = c->queries.length;
  Puint32 i;
  for (i = 0; i < len; i++) {
    if (P_ERR == c->queries.elts[i].entry->rw_fn(cm, &(c->queries.elts[i]), begin, end)) {
      return P_ERR;
    }
  }
  return P_OK;
}

Perror_t rw_s_cookie(CM_t *cm, CM_s_cookie *s, Pbyte *begin, Pbyte *end)
{
  Puint32 len = s->arms.length;
  Puint32 i;
  Pint32  sval;
  if (P_ERR == s->s_qy.entry->sval_fn(cm, &(s->s_qy), begin, end, &sval)) {
    /* failed to read switch value */
    return P_ERR;
  }
  for (i = 0; i < len; i++) {
    if (sval == s->arms.elts[i].s_val) {
      /* found matching switch arm */
      return rw_c_cookie(cm, &(s->arms.elts[i].cookie), begin, end);
    }
  }
  /* did not find matching switch arm.  not considered an error. */
  return P_OK;
}

size_t CM_sz_1(CM_query *qy)
{
  return 1;
}

size_t CM_sz_2(CM_query *qy)
{
  return 2;
}

size_t CM_sz_4(CM_query *qy)
{
  return 4;
}

size_t CM_sz_8(CM_query *qy)
{
  return 8;
}

size_t CM_sz_p1(CM_query *qy)
{
  return (size_t)(qy->params.elts[0]);
}

size_t CM_sz_p1plus1div2(CM_query *qy)
{
  return (size_t)((qy->params.elts[0] + 1)/2);
}

CM_tmentry_t* CM_get_tmentry(Pstring *s, int is_switch_qy)
{
  CM_tmentry_t *e = &(tmap[0]);
  for (; e->tname; e++) {
    if (Pstring_eq_cstr(s, e->tname)) {
      if (is_switch_qy && !e->sval_fn) {
	sfprintf(error_cm->errf,
	      "\n*** FATAL: type %s not a valid switch type (char type or int32 target type).\n"
	      "    Use 'cmonster -h' for details.\n\n", P_fmt_str(s));
	abort();
      }
      return e;
    }
  }
  sfprintf(error_cm->errf, "\n*** FATAL: unknown type: %s\n\n", P_fmt_str(s));
  abort();
  return 0; /* control never gets here, but it may make compilers happy */
}

/* Finishing functions fill in NULL Pcompute fields, abort on error. */
int CM_finish_query(CM_query *q, int is_switch_qy, int is_out_val)
{
  q->entry = CM_get_tmentry(&(q->ty_id), is_switch_qy); /* aborts on error */
  if (q->entry->num_params != q->params.length) {
    sfprintf(error_cm->errf,
	     "\n*** FATAL: type %s requires %d params, found %lu.\n"
	     "    Use 'cmonster -h' for details.\n\n",
	     P_fmt_str(&(q->ty_id)),
	     q->entry->num_params, (unsigned long)q->params.length);
    abort();
  }
  q->in_sz = q->entry->in_sz_fn(q);
  if (!is_out_val) return 1; /* leave q->out_sz == 0 */
  q->out_sz = q->entry->out_sz_fn(q);
  return 1;
}

int CM_finish_c_cookie(CM_c_cookie *c)
{
  Puint32    len = c->queries.length;
  Puint32    i;
  CM_query     *q;

  for (i = 0; i < len; i++) {
    q = &(c->queries.elts[i]);
    CM_finish_query(q, 0, 1);
    c->out_sz += q->out_sz;
  }
  return 1;
}

int CM_finish_s_cookie(CM_s_cookie *s)
{
  Puint32 len = s->arms.length;
  Puint32 i, tmp;

  s->out_sz = s->arms.elts[0].cookie.out_sz;
  for (i = 1; i < len; i++) {
    tmp = s->arms.elts[i].cookie.out_sz;
    if (tmp > s->out_sz) {
      s->out_sz = tmp;
    }
  }

  CM_finish_query(&(s->s_qy), 1, s->sval_out);
  s->out_sz += s->s_qy.out_sz;
  return 1;
}

size_t out_sz_cookie(CM_cspec *cspec)
{
  switch (cspec->cookie.tag) {
  case CM_c_or_s_err:
    break;
  case c_cookie:
    return (size_t)(cspec->cookie.val.c_cookie.out_sz);
  case s_cookie:
    return (size_t)(cspec->cookie.val.s_cookie.out_sz);
  }
  return (size_t)-1;
}
