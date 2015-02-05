/*
 * histogram implementation
 * 
 */

#include "pads-internal.h"

/* Default mapping functions, can be overwritten by users */
static Perror_t Pint8_to        (Pint8 *i, Pfloat64 *f)      { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Pint8_from      (Pfloat64 f, Pint8 *v)       { *v = (Pint8)f; return P_OK; }
static Perror_t Pint16_to       (Pint16 *i, Pfloat64 *f)     { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Pint16_from     (Pfloat64 f, Pint16 *v)      { *v = (Pint16)f; return P_OK; }
static Perror_t Pint32_to       (Pint32 *i, Pfloat64 *f)     { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Pint32_from     (Pfloat64 f, Pint32 *v)      { *v = (Pint32)f; return P_OK; }
static Perror_t Pint64_to       (Pint64 *i, Pfloat64 *f)     { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Pint64_from     (Pfloat64 f, Pint64 *v)      { *v = (Pint64)f; return P_OK; }
static Perror_t Puint8_to       (Puint8 *i, Pfloat64 *f)     { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Puint8_from     (Pfloat64 f, Puint8 *v)      { *v = (Puint8)f; return P_OK; }
static Perror_t Puint16_to      (Puint16 *i, Pfloat64 *f)    { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Puint16_from    (Pfloat64 f, Puint16 *v)     { *v = (Puint16)f; return P_OK; }
static Perror_t Puint32_to      (Puint32 *i, Pfloat64 *f)    { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Puint32_from    (Pfloat64 f, Puint32 *v)     { *v = (Puint32)f; return P_OK; }
static Perror_t Puint64_to      (Puint64 *i, Pfloat64 *f)    { *f = (Pfloat64)(*i); return P_OK; }
static Perror_t Puint64_from    (Pfloat64 f, Puint64 *v)     { *v = (Puint64)f; return P_OK; }
static Perror_t Pfloat32_to     (Pfloat32 *i, Pfloat64 *o)   { *o = (Pfloat64)(*i); return P_OK; }
static Perror_t Pfloat32_from   (Pfloat64 i, Pfloat32 *o)    { *o = (Pfloat32)i; return P_OK; }
static Perror_t Pfloat64_to     (Pfloat64 *i, Pfloat64 *o)   { *o = *i; return P_OK; }
static Perror_t Pfloat64_from   (Pfloat64 i, Pfloat64 *o)    { *o = i; return P_OK; }
static Perror_t Pchar_to        (Pchar *c, Pfloat64 *f)      { *f = (Pfloat64)((Puint8)(*c)); return P_OK; }
static Perror_t Pchar_from      (Pfloat64 f, Pchar *c)       { *c = (Pchar)('a'); return P_OK; }
static Perror_t Pstring_to      (Pstring *s, Pfloat64 *f)    { *f = 0; return P_OK; }
static Perror_t Pstring_from    (Pfloat64 f, Pstring *s)     { s->str = "non defined."; s->len = 12; return P_OK; }
static Perror_t Pip_to          (Pip *i, Pfloat64 *f)        { *f = (Pfloat64)((Puint32)(*i)); return P_OK; }
static Perror_t Pip_from        (Pfloat64 f, Pip *i)         { *i = (Puint32)f; return P_OK; }
static Perror_t Ptimestamp_to   (Ptimestamp *t, Pfloat64 *f) { *f = (Pfloat64)((Puint64)(*t)); return P_OK; }
static Perror_t Ptimestamp_from (Pfloat64 f, Ptimestamp *t)  { *t = (Ptimestamp)((Puint64)f); return P_OK; }
static Perror_t Ptime_to        (Ptime *t, Pfloat64 *f)      { *f = (Pfloat64)((Puint64)(*t)); return P_OK; }
static Perror_t Ptime_from      (Pfloat64 f, Ptime *t)       { *t = (Ptime)((Puint64)f); return P_OK; }
static Perror_t Pdate_to        (Pdate *d, Pfloat64 *f)      { *f = (Pfloat64)((Puint64)(*d)); return P_OK; }
static Perror_t Pdate_from      (Pfloat64 f, Pdate *d)       { *d = (Pdate)((Puint64)f); return P_OK; }

static const char *PDCI_hdr_strings[] = {
  "*****************************************************************************************************\n",
  "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n",
  "=====================================================================================================\n",
  "-----------------------------------------------------------------------------------------------------\n",
  ".....................................................................................................\n",
  "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",
  "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +\n",
  "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n",
  "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"
};

/* Begin Macro */
#define TYPE_HIST_GEN(type, fmt) \
\
Perror_t type ## _hist_init (P_t *pads, type ## _hist *h) { \
  /* Initialize */ \
  h->N = 14; \
  h->B = 2; \
  h->M = 100; \
  h->isE = 0; \
  h->isO = 0; \
  h->n = 2; \
  h->e = 1; \
  h->scale = 10000000; \
  h->maxPortion = 3; \
  h->toFloat = (P_toFloat_fn) type ## _to; \
  h->fromFloat = (P_fromFloat_fn) type ## _from; \
  allocateS(h); \
  return P_OK; \
} \
\
Perror_t type ## _hist_setPara (P_t *pads, type ## _hist *h, P_hist* d_hist) { \
  if (d_hist->toFloat != 0) h->toFloat = (P_toFloat_fn) d_hist->toFloat; \
  if (d_hist->fromFloat != 0) h->fromFloat = (P_fromFloat_fn) d_hist->fromFloat; \
  h->N = d_hist->N; \
  h->B = d_hist->B; \
  if (d_hist->M < 2) d_hist->M = 2; \
  h->M = d_hist->M; \
  h->isE = d_hist->isE; \
  h->isO = d_hist->isO; \
  h->n = d_hist->n; \
  h->e = d_hist->e; \
  h->scale = d_hist->scale; \
  if (d_hist->maxPortion < 1) d_hist->maxPortion = 3; \
  h->maxPortion = d_hist->maxPortion; \
  type ## _hist_cleanup(pads, h); \
  allocateS(h); \
  return P_OK; \
} \
\
Perror_t type ## _hist_reset (P_t *pads, type ## _hist *h) { \
  h->ind = 0; \
  if (h->isE != 0) { \
    /* Equally spaced */ \
    h->partS = 0; \
    h->bukI = 0; \
  } \
  else { \
    if (h->isO != 0) h->robI = 0; \
    else { \
      h->topI = 0; \
      h->boundI = 0; \
      h->robI = 1; \
    } \
  } \
  return P_OK; \
} \
\
Perror_t type ## _hist_cleanup (P_t *pads, type ## _hist *h) { \
  Pint8 i; \
\
  for (i = 0; i < h->maxPortion; i++) free(h->result[i]); \
  free(h->result); \
  if (h->isE == 0) { \
    free(h->rob); \
    if (h->isO == 0) { \
      free(h->leftS); \
      free(h->rightS); \
      free(h->top); \
      free(h->bound); \
    } \
  } \
  return P_OK; \
} \
\
Perror_t type ## _hist_add (P_t *pads, type ## _hist *h, Pbase_pd *pd, type *rep, Puint32 *isFull) { \
  Pfloat64 d; \
  Perror_t res; \
\
  if (h->ind == h->N || h->ind > h->N) { \
    h->portionInd++; \
    if (h->portionInd == h->maxPortion) { \
      /* Space exceeds. Probably user programme error */ \
      printf("*** Warning: Full histograms cleared without reported *** \n"); \
      h->portionInd = 0; \
    } \
    type ## _hist_reset(pads, h); \
  } \
  res = (*(type ## _toFloat_fn) (h->toFloat)) (rep, &d); \
  d = d / (Pfloat64)h->scale; \
  res = P_OK; \
  if (h->isE != 0) res = EqualHis(h, d); \
  else { \
    if (h->isO != 0) res = OptHis(h, d); \
    else res = NearOptHis(h, d); \
  } \
  h->ind++; \
\
  *isFull = 0; \
  if (h->ind == h->N) { \
    /* The last element in the scope */ \
    if (h->isE == 0) { \
      if (h->isO == 0) buildRob(h); \
      compOpt(h); \
    } \
    else EqualHis(h, d); \
    *isFull = 1; \
  } \
  return res; \
} \
\
Perror_t type ## _hist_reportFull2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, type ## _hist *h) { \
  Perror_t res = P_OK; \
  Pint64 i; \
\
  if (h->portionInd == 0 && h->ind != h->N) return P_OK; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  what = fmt; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "Basic Information:\n"); \
  sfprintf(outstr, "Portion length: %d;    ", h->N); \
  sfprintf(outstr, "Number of buckets: %d \n", h->B); \
  if (h->isE != 0) sfprintf(outstr, "Equal width buckets required. \n"); \
  else{ \
    if (h->isO != 0) sfprintf(outstr, "Optimal histogram required, with norm %d \n", h->n); \
    else sfprintf(outstr, "Histogram within poly-(1+%f) times error \n", h->e); \
  } \
  for (i = 0; i < h->portionInd; i++) res = type ## _report (outstr, h, i); \
  /* Reset the reported ones */ \
  for (i = 0; i < h->B; i++) { \
    h->result[0][i].bound = h->result[h->portionInd][i].bound; \
    h->result[0][i].hei = h->result[h->portionInd][i].hei; \
  } \
  h->portionInd = 0; \
  return res; \
} \
\
Perror_t type ## _hist_reportAll2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, type ## _hist *h) { \
  Perror_t res; \
  Pint64 i; \
  Pint64 tempInd; \
  Pint64 tempN = h->N; \
\
  type ## _hist_reportFull2io(pads, outstr, prefix, what, nst, h); \
  res = P_OK; \
  if (h->ind == 0) return res; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "Basic Information:\n"); \
  sfprintf(outstr, "Portion length: %d;    ", h->N); \
  sfprintf(outstr, "Number of buckets: %d \n", h->B); \
  if (h->isE != 0) sfprintf(outstr, "Equal width buckets required. \n"); \
  else{ \
    if (h->isO != 0) sfprintf(outstr, "Optimal histogram required, with norm %d \n", h->n); \
    else sfprintf(outstr, "Histogram within poly-(1+%f) times error \n", h->e); \
  } \
  if (h->ind != h->N) { \
    /* Real data is less than the estimated dimension */ \
    if (h->isE != 0) { \
      h->result[h->portionInd][h->bukI].hei = h->partS; \
      h->result[h->portionInd][h->bukI].bound = h->ind; \
      h->bukI++; \
    } \
    else { \
      if (h->isO == 1) { \
	h->robI = h->ind; \
	h->N = h->ind; \
	if (h->B > h->robI) h->B = h->robI; \
	compOpt(h); \
      } \
      else { \
	tempInd = h->ind; \
	for (i = tempInd; i < h->N; i++) { \
	  res = NearOptHis(h, 0); \
          h->ind++; \
        } \
	buildRob(h); \
	h->ind = tempInd; \
	compOpt(h); \
      } \
    } \
  } \
  res = type ## _report (outstr, h, h->portionInd); \
  h->N = tempN; \
  return res; \
} \
\
Perror_t type ## _hist_reportFull (P_t *pads, const char *prefix, const char *what, int nst, type ## _hist *h) { \
  Sfio_t *tmpstr = sfstdout; \
  Perror_t res; \
  res = type ## _hist_reportFull2io (pads, tmpstr, prefix, what, nst, h); \
  return P_OK; \
} \
\
Perror_t type ## _hist_reportAll (P_t *pads, const char *prefix, const char *what, int nst, type ## _hist *h) { \
  Sfio_t *tmpstr = sfstdout; \
  Perror_t res; \
  res = type ## _hist_reportAll2io (pads, tmpstr, prefix, what, nst, h); \
  return P_OK; \
} 
/* END_MACRO */

/* Functions defined with public access */
TYPE_HIST_GEN (Pint8, "int8");
TYPE_HIST_GEN (Pint16, "int16");
TYPE_HIST_GEN (Pint32, "int32");
TYPE_HIST_GEN (Pint64, "int64");
TYPE_HIST_GEN (Puint8, "uint8");
TYPE_HIST_GEN (Puint16, "uint16");
TYPE_HIST_GEN (Puint32, "uint32");
TYPE_HIST_GEN (Puint64, "uint64");
TYPE_HIST_GEN (Pfloat32, "float32");
TYPE_HIST_GEN (Pfloat64, "float64");
TYPE_HIST_GEN (Pchar, "char");
TYPE_HIST_GEN (Pstring, "string");
TYPE_HIST_GEN (Pip, "ip");
TYPE_HIST_GEN (Ptimestamp, "timestamp");
TYPE_HIST_GEN (Ptime, "time");
TYPE_HIST_GEN (Pdate, "date");

/* BEGIN_MACRO */
#define MAP_REPORT_GEN(int_type) \
Perror_t int_type ## _hist_map_reportFull2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, int_type ## _map_fn fn, int_type ## _hist *h) { \
  Perror_t res = P_OK; \
  Pint64 i; \
\
  if (h->portionInd == 0 && h->ind != h->N) return P_OK; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "Basic Information:\n"); \
  sfprintf(outstr, "Portion length: %d;    ", h->N); \
  sfprintf(outstr, "Number of buckets: %d \n", h->B); \
  if (h->isE != 0) sfprintf(outstr, "Equal width buckets required. \n"); \
  else{ \
    if (h->isO != 0) sfprintf(outstr, "Optimal histogram required, with norm %d \n", h->n); \
    else sfprintf(outstr, "Histogram within poly-(1+%f) times error \n", h->e); \
  } \
  for (i = 0; i < h->portionInd; i++) res = int_type ## _map_report (outstr, fn, h, i); \
  /* Reset the reported ones */ \
  for (i = 0; i < h->B; i++) { \
    h->result[0][i].bound = h->result[h->portionInd][i].bound; \
    h->result[0][i].hei = h->result[h->portionInd][i].hei; \
  } \
  h->portionInd = 0; \
  return res; \
} \
\
Perror_t int_type ## _hist_map_reportAll2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, int_type ## _map_fn fn, int_type ## _hist *h) { \
  Perror_t res = P_OK; \
  Pint64 i; \
  Pint64 tempInd; \
  Pint64 tempN = h->N; \
\
  int_type ## _hist_map_reportFull2io(pads, outstr, prefix, what, nst, fn, h); \
  if (h->ind == 0 || h->result[h->portionInd][0].bound < 1) return P_OK; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "Basic Information:\n"); \
  sfprintf(outstr, "Portion length: %d;    ", h->N); \
  sfprintf(outstr, "Number of buckets: %d \n", h->B); \
  if (h->isE != 0) sfprintf(outstr, "Equal width buckets required. \n"); \
  else{ \
    if (h->isO != 0) sfprintf(outstr, "Optimal histogram required, with norm %d \n", h->n); \
    else sfprintf(outstr, "Histogram within poly-(1+%f) times error \n", h->e); \
  } \
  if (h->ind != h->N) { \
    /* Real data is less than the estimated dimension */ \
    if (h->isE != 0) { \
      h->result[h->portionInd][h->bukI].hei = h->partS; \
      h->result[h->portionInd][h->bukI].bound = h->ind; \
      h->bukI++; \
    } \
    else { \
      if (h->isO == 1) { \
	h->robI = h->ind; \
	h->N = h->ind; \
	if (h->B > h->robI) h->B = h->robI; \
	compOpt(h); \
      } \
      else { \
	tempInd = h->ind; \
	for (i = tempInd; i < h->N; i++) { \
	  res = NearOptHis(h, 0); \
          h->ind++; \
        } \
	buildRob(h); \
	h->ind = tempInd; \
	compOpt(h); \
      } \
    } \
  } \
  res = int_type ## _map_report (outstr, fn, h, h->portionInd); \
  h->N = tempN; \
  return res; \
}
/* END_MACRO */

MAP_REPORT_GEN (Pint8);
MAP_REPORT_GEN (Pint16);
MAP_REPORT_GEN (Pint32);
MAP_REPORT_GEN (Pint64);
MAP_REPORT_GEN (Puint8);
MAP_REPORT_GEN (Puint16);
MAP_REPORT_GEN (Puint32);
MAP_REPORT_GEN (Puint64);

/* BEGIN_MACRO */
#define INT_TYPE_MAP_GEN(int_type) \
Perror_t int_type ## _map_report (Sfio_t *outstr, int_type ## _map_fn fn, int_type ## _hist *h, Pint8 pInd) { \
  Perror_t res = P_OK; \
  Pint64 i; \
  int_type obj; \
\
  for (i = 0; i < h->bukI; i++) { \
    if (i == 0) sfprintf(outstr, "From %d to ", 0); \
    else sfprintf(outstr, "From %d to ", h->result[pInd][i-1].bound); \
    sfprintf(outstr, "%d, with height ", h->result[pInd][i].bound - 1); \
    res = (*(int_type ## _fromFloat_fn) (h->fromFloat)) (h->result[pInd][i].hei * (Pfloat64)h->scale, &obj); \
    sfprintf(outstr, "%s \n", (*fn)(obj)); \
  } \
  sfprintf(outstr, "%s", PDCI_hdr_strings[2]); \
  return res; \
}
/* END_MACRO */

INT_TYPE_MAP_GEN (Pint8);
INT_TYPE_MAP_GEN (Pint16);
INT_TYPE_MAP_GEN (Pint32);
INT_TYPE_MAP_GEN (Pint64);
INT_TYPE_MAP_GEN (Puint8);
INT_TYPE_MAP_GEN (Puint16);
INT_TYPE_MAP_GEN (Puint32);
INT_TYPE_MAP_GEN (Puint64);

/* BEGIN_MACRO */
#define BASIC_REPORT_GEN(type, fmt) \
Perror_t type ## _report (Sfio_t *outstr, type ## _hist *h, Pint8 pInd) { \
  Perror_t res = P_OK; \
  Pint64 i; \
  type obj; \
\
  if (h->isE == 0) h->bukI = h->B; \
  for (i = 0; i < h->bukI; i++) { \
    if (i == 0) sfprintf(outstr, "From %d to ", 0); \
    else sfprintf(outstr, "From %d to ", h->result[pInd][i-1].bound); \
    sfprintf(outstr, "%d, with height ", h->result[pInd][i].bound - 1); \
    res = (*(type ## _fromFloat_fn) (h->fromFloat)) (h->result[pInd][i].hei * (Pfloat64)h->scale, &obj); \
    sfprintf(outstr, "%" fmt " \n", obj); \
  } \
  sfprintf(outstr, "%s", PDCI_hdr_strings[2]); \
  return res; \
} 
/* END_MACRO */

BASIC_REPORT_GEN (Pint8, "d");
BASIC_REPORT_GEN (Pint16, "d");
BASIC_REPORT_GEN (Pint32, "d");
BASIC_REPORT_GEN (Pint64, "d");
BASIC_REPORT_GEN (Puint8, "d");
BASIC_REPORT_GEN (Puint16, "d");
BASIC_REPORT_GEN (Puint32, "d");
BASIC_REPORT_GEN (Puint64, "d");
BASIC_REPORT_GEN (Pfloat32, "f");
BASIC_REPORT_GEN (Pfloat64, "f");
BASIC_REPORT_GEN (Pchar, "c");
BASIC_REPORT_GEN (Pstring, "s");

Perror_t Pip_report (Sfio_t *outstr, Pip_hist *h, Pint8 pInd) {
  Perror_t res = P_OK;
  Pint64 i;
  Pip obj;

  if (h->isE == 0) h->bukI = h->B;
  for (i = 0; i < h->bukI; i++) {
    if (i == 0) sfprintf(outstr, "From %d to ", 0);
    else sfprintf(outstr, "From %d to ", h->result[pInd][i-1].bound);
    sfprintf(outstr, "%d, with average ip address ", h->result[pInd][i].bound - 1);
    res = (*(Pip_fromFloat_fn) (h->fromFloat)) (h->result[pInd][i].hei * (Pfloat64)h->scale, &obj);
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
  }
  sfprintf(outstr, "%s", PDCI_hdr_strings[2]);
  return res;
}

/* BEGIN_MACRO */
#define TIME_DATE_REPORT_GEN(type) \
Perror_t type ## _report (Sfio_t *outstr, type ## _hist *h, Pint8 pInd) { \
  Perror_t res = P_OK; \
  Pint64 i; \
  type obj; \
\
  if (h->isE == 0) h->bukI = h->B; \
  for (i = 0; i < h->bukI; i++) { \
    if (i == 0) sfprintf(outstr, "From %d to ", 0); \
    else sfprintf(outstr, "From %d to ", h->result[pInd][i-1].bound); \
    sfprintf(outstr, "%d, with average time ", h->result[pInd][i].bound - 1); \
    res = (*(type ## _fromFloat_fn) (h->fromFloat)) (h->result[pInd][i].hei * (Pfloat64)h->scale, &obj); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
  } \
  sfprintf(outstr, "%s", PDCI_hdr_strings[2]); \
  return res; \
}
/* END_MACRO */

TIME_DATE_REPORT_GEN(Ptimestamp);
TIME_DATE_REPORT_GEN(Ptime);
TIME_DATE_REPORT_GEN(Pdate);

/* Functions defined for private use only */ 
void allocateS(P_hist *h) {
  Pint32 i;
  Pint8 j;
  Pint64 adj;

  h->ind = 0;
  h->portionInd = 0;
  h->result = malloc(h->maxPortion * sizeof(struct bucket*));
  if (h->result == (struct bucket**)0) exit(-1);
  for (j = 0; j < h->maxPortion; j++) {
    h->result[j] = malloc(h->B * sizeof(struct bucket));
    if (h->result[j] == (struct bucket*)0) exit(-1);
  }
  if (h->isE != 0) {
    /* Equally spaced */
    h->partS = 0;
    h->bukI = 0;
    for (j = 0; j < h->maxPortion; j++) {
      for (i = 0; i < h->B; i++) 
	h->result[j][i].bound = ((Pint64)(h->N / h->B) + 1) * (i + 1) - 1;
      h->result[j][h->B - 1].bound = h->N;
    }
  }
  else {
    if (h->isO != 0) {
      /* Optimal result required */
      h->rob = malloc(h->N * sizeof(struct bucket));
      if (h->rob == (struct bucket*)0) exit(-1);
      h->robI = 0;
    }
    else {
      /* Adjust dimension to be perfect power of 2. */
      adj = (Pint64)((Pfloat64)log(h->N) / (Pfloat64)log(2));
      if ((Pint64)pow(2, (Pfloat64)adj) != h->N) h->N = (Pint64)pow(2, (Pfloat64)adj + 1);

      h->lNumber = (Pint8)((Pfloat64)log(h->N) / (Pfloat64)log(2));
      h->leftS = malloc(h->lNumber * sizeof(Pfloat64));
      h->rightS = malloc(h->lNumber * sizeof(Pfloat64));
      if (h->leftS == (Pfloat64*)0 || h->rightS == (Pfloat64*)0) exit(-1);
      h->rSize = (Pint32)((Pfloat64)(h->B * ((Pfloat64)log(h->N) / (Pfloat64)log(2)) * ((Pfloat64)log(h->M) / (Pfloat64)log(2))) / h->e);
      h->top = malloc(2 * h->rSize * sizeof(struct wave));
      if (h->top == (struct wave*)0) exit(-1);
      h->topI = 0;
      h->bound = malloc(3 * h->rSize * sizeof(struct bucket));
      if (h->bound == (struct bucket*)0) exit(-1);
      h->boundI = 0;
      h->rob = malloc((3 * h->rSize + 1) * sizeof(struct bucket));
      if (h->rob == (struct bucket*)0) exit(-1);
      h->rob[0].bound = 0;
      h->rob[0].hei = 0;
      h->robI = 1;
    }
  }
}

Perror_t EqualHis(P_hist *h, Pfloat64 d) { 
  Pint64 i;
  if (h->ind == 0) h->bukI = 0;
  if (h->ind == h->result[h->portionInd][h->bukI].bound || h->ind == h->N) {
    /* Reach a boundary, height computed, end point recorded */
    h->result[h->portionInd][h->bukI].hei = h->partS;
    h->bukI++;
    h->partS = 0;
  }
  if (h->partS == 0) h->partS = d;
  else {
    if (h->bukI == 0) h->partS = (h->partS * h->ind + d) / (h->ind + 1);
    else {
      i = h->ind - h->result[h->portionInd][h->bukI - 1].bound;
      h->partS = (h->partS * i + d) / (i + 1);
    }
  }
  return P_OK;
}

Perror_t OptHis(P_hist *h, double d) {
  h->rob[h->ind].bound = h->ind;
  h->rob[h->ind].hei = d;
  h->robI++;
  return P_OK;
}

Perror_t NearOptHis(P_hist *h, double d) {
  Pint8 i;
  Pint8 tempCoefI;
  Pint64 rem;
  struct wave temp;
  struct wave* tempCoef;

  /* Compute coefficients */
  tempCoef = malloc((h->lNumber + 1) * sizeof(struct wave));
  if (tempCoef == (struct wave*)0) exit(-1);
  tempCoefI = 0;
  for (i = 0; i < h->lNumber; i++) {
    rem = h->ind % (Pint64)pow(2, (Pfloat64)i+1);
    if (rem == 0) {
      /* Hit the left half of a new wavelet on ith. level */
      if (h->ind != 0) {
	/* Roll back current wavelet vector */
	temp.level = i;
	temp.index = h->ind / (Pint64)pow(2, (Pfloat64)i+1) - 1;
	temp.coef = (h->rightS[i] - h->leftS[i]) / pow(2, ((Pfloat64)i+1)/2);
	tempCoef[tempCoefI] = temp;
	tempCoefI++;
      }
      h->leftS[i] = d;
    }
    if (rem == (Pint64)pow(2, (Pfloat64)i)) {
      /* Hit the right half of current wavelet on ith. level */
      h->rightS[i] = d;
    }
    if (rem > 0 && rem < (Pint64)pow(2, (Pfloat64)i)) {
      /* Keep on the left half of current wavelet on ith. level */
      h->leftS[i] += d;
    }
    if (rem > (Pint64)pow(2, (Pfloat64)i)) {
      /* Keep on the right half of current wavelet of ith. level */
      h->rightS[i] += d;
    }
    if (h->ind == h->N - 1) {
      /* The last element, roll up */
      temp.level = i;
      temp.index = h->ind / (Pint64)pow(2, (Pfloat64)i+1);
      temp.coef = (h->rightS[i] - h->leftS[i]) / pow(2, ((Pfloat64)i+1)/2);
      tempCoef[tempCoefI] = temp;
      tempCoefI++;
      if (i == h->lNumber - 1) {
	/* Add the uniform wavelet vector */
	temp.level = i + 1;
	temp.index = 0;
	temp.coef = (h->rightS[i] + h->leftS[i]) / sqrt((Pfloat64)(h->N));
	tempCoef[tempCoefI] = temp;
	tempCoefI++;
      }
    }
  }
  /* Examine and remain wavelet vectors with large coefficient only */
  for (i = 0; i < tempCoefI; i++) {
    h->top[h->topI] = tempCoef[i];
    h->topI++;
    if (h->topI == 2 * h->rSize) {
      /* The array is full. Prune required */
      select_w(&(h->top), h, 0, 2 * h->rSize - 1);
      h->topI = h->rSize;
    }
  }
  free(tempCoef);
  return P_OK;
}

void buildRob(P_hist *h) {
  Pint32 i;
  Pint64 left;
  Pint64 right;
  Pint64 mid;
  Pfloat64 hei;
  Pfloat64 help;
  Pint64 currB;
  Pfloat64 currH;
  struct wave temp;

  select_w(&(h->top), h, 0, h->topI - 1);
  if (h->rSize > h->topI) h->rSize = h->topI;
  /* Build the robust histogram out of the top array, start point recorded */
  for (i = 0; i < h->rSize; i++) {
    temp = h->top[i];
    if (temp.level == h->lNumber) {
      /* The uniform one */
      h->bound[h->boundI].bound = 0;
      h->bound[h->boundI].hei = temp.coef / sqrt((Pfloat64)(h->N));
      h->boundI++;
    }
    else {
      left = temp.index * (Pint64)pow(2, (Pfloat64)(temp.level + 1));
      right = (temp.index + 1) * (Pint64)pow(2, (Pfloat64)(temp.level + 1));
      mid = (Pint64)(left + right) / 2;
      help = -(Pfloat64)(temp.level+1) / (Pfloat64)2;
      hei = temp.coef * pow(2, help);

      h->bound[h->boundI].bound = left;
      h->bound[h->boundI].hei = -hei;
      h->boundI++;
      h->bound[h->boundI].bound = mid;
      h->bound[h->boundI].hei = 2 * hei;
      h->boundI++;
      if (right != h->N) {
	h->bound[h->boundI].bound = right;
	h->bound[h->boundI].hei = -hei;
	h->boundI++;
      }
    }
  }

  quickSort(&(h->bound), 0, h->boundI-1);

  currB = h->bound[0].bound;
  currH = h->bound[0].hei;
  h->robI = 0;
  for (i = 1; i < h->boundI; i++) {
    if (h->bound[i].bound != currB) {
      /* Finish height accumulation */
      h->rob[h->robI].bound = currB;
      h->rob[h->robI].hei = currH;
      h->robI++;
      currB = h->bound[i].bound;
    }
    currH += h->bound[i].hei;
  }
  h->rob[h->robI].bound = currB;
  h->rob[h->robI].hei = currH;
  h->robI++;
  h->rob[h->robI].bound = h->N;
}

struct dpCell OptHei(P_hist *h, Pint64 s, Pint64 e) {
  Pint64 len;
  Pint64 i;
  Pfloat64 hei;
  Pfloat64 err;
  Pfloat64 sum;
  struct dpCell temp_dp = {0};
  struct bucket *temp;

  if (h->n == 1) {
    /* L-1 norm */
    len = e - s + 1;
    temp = malloc(len * sizeof(struct bucket));
    if (temp == (struct bucket*)0) exit(-1);
    for (i = 0; i < len; i++) temp[i] = h->rob[s + i];
    hei = 0;
    if ((len % 2) == 0) hei = (select_b(&temp, h, 0, len-1, len/2) + select_b(&temp, h, 0, len-1, len/2-1 )) / 2;
    else hei = select_b(&temp, h, 0, len-1, (len-1)/2);
    free(temp);
    err = 0;
    for (i = s; i < e+1; i++) err += fabs(h->rob[i].hei - hei);
    temp_dp.error = err;
    temp_dp.hei = hei;
    return temp_dp;
  }

  /* L-2 norm. Compute the average */
  sum = 0;
  len = 0;
  for (i = s; i < e; i++) {
    len += h->rob[i+1].bound - h->rob[i].bound;
    sum += h->rob[i].hei * (h->rob[i+1].bound - h->rob[i].bound);
  }
  if (e == h->robI - 1) {
    len += h->N - h->rob[e].bound;
    sum += h->rob[e].hei * (h->N - h->rob[e].bound);
  }
  else {
    len += h->rob[e+1].bound - h->rob[e].bound;
    sum += h->rob[e].hei * (h->rob[e+1].bound - h->rob[e].bound);
  }
  hei = sum / (Pfloat64)len;

  /* Compute the error */
  err = 0;
  for (i = s; i < e; i++) {
    if ((Pfloat64)log(h->rob[i+1].bound) + 2 * (Pfloat64)log(fabs(h->rob[i].hei)) > 60 * (Pfloat64)log(2)) {
      printf("*** Overflow Error: Try increase parameter SCALE *** \n");
      exit(-1);
    }
    err += (h->rob[i+1].bound - h->rob[i].bound) * pow(h->rob[i].hei - hei, 2);
  }
  if (e == h->robI - 1)	{
    if ((Pfloat64)log(h->N) + 2 * (Pfloat64)log(fabs(h->rob[e].hei)) > 60 * (Pfloat64)log(2)) {
      printf("*** Overflow Error: Try increase parameter SCALE *** \n");
      exit(-1);
    }
    err += (h->N - h->rob[e].bound) * pow(h->rob[e].hei - hei, 2);
  }
  else {
    if ((Pfloat64)log(h->rob[e+1].bound) + 2 * (Pfloat64)log(fabs(h->rob[e].hei)) > 60 * (Pfloat64)log(2)) {
      printf("\n *** Overflow Error: Try increase parameter SCALE *** \n");
      exit(-1);
    }
    err += (h->rob[e+1].bound - h->rob[e].bound) * pow(h->rob[e].hei - hei, 2);
  }

  temp_dp.error = err;
  temp_dp.hei = hei;
  return temp_dp;
}

void compOpt(P_hist *h) {
  Pint64 i;
  Pint64 j;
  Pint64 k;
  Pfloat64 keepE;
  Pint64 keepB;
  Pfloat64 keepH;
  Pfloat64 err;
  Pint32 resultI;
  Pint64 track;
  struct dpCell temp;

  /* Size of the dynamic programming table */
  if (h->isO != 0) h->colN = h->N;
  else {
    if (h->ind != h->N) {
      i = 0;
      while (i < h->robI && h->rob[i].bound < h->ind) i++;
      h->robI = i;
    }
    if (h->B > h->robI) h->B = h->robI;
    h->colN = h->robI;
  }
  h->rowN = h->B;
  h->dpTable = malloc(h->rowN * sizeof(struct dpCell*));
  if (h->dpTable == (struct dpCell**)0) exit(-1);
  for (i = 0; i < h->rowN; i++) {
    h->dpTable[i] = malloc(h->colN * sizeof(struct dpCell));
    if (h->dpTable[i] == (struct dpCell*)0) exit(-1);
  }

  /* Histogram with one bucket only */
  for (i = 0; i < h->colN; i++) {
    h->dpTable[0][i] = OptHei(h, 0, i);
    h->dpTable[0][i].bound = 0;
  }
  /* Histogram with i buckets, computed based on those with i-1 buckets */
  for (j = 0; j < h->colN; j++) {
    /* j stands for the end boundary currently reached */
    for (i = 1; i < h->rowN; i++) {
      /* i stands for the number of buckets currently used */
      keepE = INF;
      keepB = INF;
      keepH = INF;
      for (k = 0; k < j; k++) {
	temp = OptHei(h, k + 1, j);
	err = temp.error + h->dpTable[i - 1][k].error;
	if (err < keepE) {
	  keepE = err;
	  keepB = k + 1;
	  keepH = temp.hei;
	}
      }
      h->dpTable[i][j].bound = keepB;
      h->dpTable[i][j].error = keepE;
      h->dpTable[i][j].hei = keepH;
    }
  }
  /* Fill the result table, for result histogram. End point recorded */
  resultI = h->rowN - 1;
  track = h->colN;
  while (track != 0) {
    if (track == h->colN) h->result[h->portionInd][resultI].bound = h->ind;
    else h->result[h->portionInd][resultI].bound = h->rob[track].bound;
    h->result[h->portionInd][resultI].hei = h->dpTable[resultI][track - 1].hei;
    track = h->dpTable[resultI][track - 1].bound;
    resultI--;
  }
  if (resultI > 0) {
    /* Use less than B buckets, with error guarantee */
     for (i = 0; i < resultI + 1; i++) h->result[h->portionInd][i].bound = 0;
  }
  if (h->dpTable != NULL) {
    for (i = 0; i < h->rowN; i++) free(h->dpTable[i]);
    free(h->dpTable);
  }
}

Pint64 partition_w(struct wave** A, Pint64 p, Pint64 r) {
  /* Set the last element in the scope to be pivot */
  struct wave x;
  struct wave swap;
  Pint64 i;
  Pint64 j;

  x = (*A)[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (fabs((*A)[j].coef) > fabs(x.coef)) {
      i++;
      swap = (*A)[i];
      (*A)[i] = (*A)[j];
      (*A)[j] = swap;
    }
  }
  swap = (*A)[i+1];
  (*A)[i+1] = (*A)[r];
  (*A)[r] = swap;

  return i+1;
}

void select_w(struct wave** A, P_hist* h, Pint64 p, Pint64 r) {
  Pint64 q;

  if (p == r) return;
  q = partition_w(A, p, r);
  if (q == h->rSize) return;
  if (q < h->rSize) select_w(A, h, q+1, r);
  else select_w(A, h, p, q-1);
}

Pint64 partition_b(struct bucket** A, Pint64 p, Pint64 r) {
  /* Set the last element in the scope to be pivot */
  struct bucket x;
  struct bucket swap;
  Pint64 i;
  Pint64 j;

  x = (*A)[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if ((*A)[j].bound < x.bound) {
      i++;
      swap = (*A)[i];
      (*A)[i] = (*A)[j];
      (*A)[j] = swap;
    }
  }

  swap = (*A)[i+1];
  (*A)[i+1] = (*A)[r];
  (*A)[r] = swap;

  return i+1;
}

Pfloat64 select_b(struct bucket** A, P_hist *h, Pint64 p, Pint64 r, Pint64 sel) {
  Pint64 q;

  if (p == r) return (*A)[p].hei;
  q = partition_b(A, p, r);
  if (q == sel) return (*A)[q].hei;
  if (q < sel) return select_b(A, h, q+1, r, sel);
  else return select_b(A, h, p, q-1, sel);
}

void quickSort(struct bucket** A, Pint64 p, Pint64 r) {
  if (p < r) {
      Pint64 q = partition_b(A, p, r);
      quickSort(A, p, q-1);
      quickSort(A, q+1, r);
  }
} 



