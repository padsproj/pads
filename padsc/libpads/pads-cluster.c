/*
 * cluster implementation
 * 
 */

#include "pads-internal.h"

Pfloat64 Gaussian (Pfloat64 mean, Pfloat64 var, Pfloat64 x) {
  Pfloat64 res;

  if (var == 0) {
    if (x == mean) return (Pfloat64)1;
    else return (Pfloat64)0;
  }

  res = pow(x - mean, (Pfloat64)2) / ((Pfloat64)2 * var); 
  res = exp(0 - res);
  res = res / pow((Pfloat64)(2 * PI * var), (Pfloat64)0.5);
  return res;
}

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
#define TYPE_CLUSTER_GEN(type, fmt) \
\
Perror_t type ## _cluster_init (P_t *pads, type ## _cluster *c) { \
  /* Initialize */ \
  c->cType = OTHERS; \
  c->k = 3; \
  c->initVar = 0; \
  c->open = .8; \
  c->anorm_pos = .1; \
  c->anorm_num = .5; \
  c->probFn = (Distri_fn) Gaussian; \
  c->toFloat = (P_toFloat_fn) type ## _to; \
  c->fromFloat = (P_fromFloat_fn) type ## _from; \
  cluster_allocateS(c); \
  return P_OK; \
} \
\
Perror_t type ## _cluster_setPara (P_t *pads, type ## _cluster *c, P_cluster* d_cluster) { \
  if (d_cluster->toFloat != 0) c->toFloat = (P_toFloat_fn) d_cluster->toFloat; \
  if (d_cluster->fromFloat != 0) c->fromFloat = (P_fromFloat_fn) d_cluster->fromFloat; \
  if (d_cluster->probFn != 0) c->probFn = (Distri_fn) d_cluster->probFn; \
  c->cType = d_cluster->cType; \
  c->k = d_cluster->k; \
  c->initVar = d_cluster->initVar; \
  c->open = d_cluster->open; \
  c->anorm_pos = d_cluster->anorm_pos; \
  c->anorm_num = d_cluster->anorm_num; \
  cluster_allocateS(c); \
  return P_OK; \
} \
\
Perror_t type ## _cluster_reset (P_t *pads, type ## _cluster *c) { \
  Puint32 i; \
  clink *temp; \
\
  c->total = 0; \
  c->ind = 0; \
  for (i = 0; i < c->k; i++) c->num[i] = 0; \
  temp = c->head; \
  while (temp != c->tail) { \
    temp = temp -> next; \
    free(c->head); \
    c->head = temp; \
  } \
  c->head = c->tail; \
  return P_OK; \
} \
\
Perror_t type ## _cluster_cleanup (P_t *pads, type ## _cluster *c) { \
  clink *temp; \
  Pint32 i; \
\
  temp = c->head; \
  while (temp != c->tail) { \
    temp = temp -> next; \
    free(c->head); \
    c->head = temp; \
  } \
  free(temp); \
  free(c->num); \
  for (i = 0; i < c->k; i++) free(c->para[i]); \
  free(c->para); \
  return P_OK; \
} \
\
Perror_t type ## _cluster_add (P_t *pads, type ## _cluster *c, Pbase_pd *pd, type *rep, Puint32 *isFull) { \
  Pfloat64 d; \
\
  (*(type ## _toFloat_fn) (c->toFloat)) (rep, &d); \
  switch (c->cType) { \
  case K_MEAN: \
    K_mean_add(c, d); \
    break; \
  case GAUSSIAN: \
    Other_add(c, d); \
    break; \
  case EXPONENTIAL: \
    Exponential_add(c, d); \
    break; \
  case LAPLACE: \
    Laplace_add(c, d); \
    break; \
  case OTHERS: \
    Other_add(c, d); \
    break; \
  default: \
    printf("\n *** Distribution type not supported (case sensitive) *** \n"); \
    exit(0); \
  } \
  c->total ++; \
\
  return P_OK; \
} \
\
Perror_t type ## _cluster_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, type ## _cluster *c) { \
  Pint64 i; \
  clink *temp = c->head; \
  Pfloat64 var = 0; \
  Pfloat64 b = 0; \
\
  if (c->ind == 0) return P_OK; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  what = fmt; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "\nClustering based distribution: "); \
  switch (c->cType) { \
  case K_MEAN: \
    sfprintf(outstr, "K_mean. \n"); \
    break; \
  case GAUSSIAN: \
    sfprintf(outstr, "Gaussion/Normal distribution. \n"); \
    break; \
  case EXPONENTIAL: \
    sfprintf(outstr, "Exponential distribution. \n"); \
    break; \
  case LAPLACE: \
    sfprintf(outstr, "Laplace distribution. \n"); \
    break; \
  case OTHERS: \
    sfprintf(outstr, "User defined distribution. \n"); \
    break; \
  } \
  for (i = 0; i < c->ind; i++) { \
    if (c->cType == K_MEAN) { \
      type ## _cluster_report_private (outstr, c, c->para[i][0], 0); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == GAUSSIAN || c->cType == OTHERS) { \
      var = c->para[i][1] - pow(c->para[i][0], (Pfloat64)2); \
      type ## _cluster_report_private (outstr, c, c->para[i][0], var); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == EXPONENTIAL) { \
      type ## _cluster_report_private (outstr, c, c->para[i][0], var); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == LAPLACE) { \
      var = c->para[i][1] - pow(c->para[i][0], (Pfloat64)2); \
      b = pow(var / (Pfloat64)2, (Pfloat64).5); \
      type ## _cluster_report_private (outstr, c, c->para[i][0], b); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
  } \
  sfprintf(outstr, "%s", PDCI_hdr_strings[2]); \
  sfprintf(outstr, "Possible anormality based on probability %f: \n", c->anorm_pos); \
  temp = c->head; \
  while (temp != c->tail) { \
    type ## _cluster_report_private (outstr, c, temp->ele, 0 - INF); \
    temp = temp->next; \
  } \
  sfprintf(outstr, "Possible anormality based on clustering elements number %f: \n", c->anorm_num); \
  for (i = 0; i < c->ind; i++) { \
    if (c->cType == EXPONENTIAL) break; \
    if (c->num[i] < (int)(c->total * c->anorm_num) && c->num[i] > 0) \
      type ## _cluster_report_private (outstr, c, c->para[i][0], 0 - INF); \
  } \
  return P_OK; \
} \
\
Perror_t type ## _cluster_report (P_t *pads, const char *prefix, const char *what, int nst, type ## _cluster *h) { \
  Sfio_t *tmpstr = sfstdout; \
  Perror_t res; \
  res = type ## _cluster_report2io (pads, tmpstr, prefix, what, nst, h); \
  return P_OK; \
} 
/* END_MACRO */

/* Functions defined with public access */
TYPE_CLUSTER_GEN (Pint8, "int8");
TYPE_CLUSTER_GEN (Pint16, "int16");
TYPE_CLUSTER_GEN (Pint32, "int32");
TYPE_CLUSTER_GEN (Pint64, "int64");
TYPE_CLUSTER_GEN (Puint8, "uint8");
TYPE_CLUSTER_GEN (Puint16, "uint16");
TYPE_CLUSTER_GEN (Puint32, "uint32");
TYPE_CLUSTER_GEN (Puint64, "uint64");
TYPE_CLUSTER_GEN (Pfloat32, "float32");
TYPE_CLUSTER_GEN (Pfloat64, "float64");
TYPE_CLUSTER_GEN (Pchar, "char");
TYPE_CLUSTER_GEN (Pstring, "string");
TYPE_CLUSTER_GEN (Pip, "ip");
TYPE_CLUSTER_GEN (Ptimestamp, "timestamp");
TYPE_CLUSTER_GEN (Ptime, "time");
TYPE_CLUSTER_GEN (Pdate, "date");

/* BEGIN_MACRO */
#define CLUSTER_MAP_REPORT_GEN(int_type) \
Perror_t int_type ## _cluster_map_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, int_type ## _map_fn fn, int_type ## _cluster *c) { \
  Pint64 i; \
  clink *temp; \
  int_type obj; \
  Pfloat64 var; \
  Pfloat64 b; \
\
  if (c->ind == 0) return P_OK; \
  if (!prefix || *prefix == 0) prefix = "<top>"; \
  PDCI_nst_prefix_what(outstr, &nst, prefix, what, 0); \
  /* Print header */ \
  sfprintf(outstr, "\n Clustering based distribution: "); \
  switch (c->cType) { \
  case K_MEAN: \
    sfprintf(outstr, "K_mean. \n"); \
    break; \
  case GAUSSIAN: \
    sfprintf(outstr, "Gaussion/Normal distribution. \n"); \
    break; \
  case EXPONENTIAL: \
    sfprintf(outstr, "Exponential distribution. \n"); \
    break; \
  case LAPLACE: \
    sfprintf(outstr, "Laplace distribution. \n"); \
    break; \
  case OTHERS: \
    sfprintf(outstr, "User defined distribution. \n"); \
    break; \
  } \
  for (i = 0; i < c->ind; i++) { \
    if (c->cType == K_MEAN) { \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (c->para[i][0], &obj); \
      sfprintf(outstr, "mean %s, containing ", (*fn)(obj)); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == GAUSSIAN || c->cType == OTHERS) { \
      var = c->para[i][1] - pow(c->para[i][0], (Pfloat64)2); \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (c->para[i][0], &obj); \
      sfprintf(outstr, "mean %s, and variance ", (*fn)(obj)); \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (var, &obj); \
      sfprintf(outstr, "%s, containing ", (*fn)(obj)); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == EXPONENTIAL) { \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (c->para[i][0], &obj); \
      sfprintf(outstr, "ratio %s, containing ", (*fn)(obj)); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
    if (c->cType == LAPLACE) { \
      var = c->para[i][1] - pow(c->para[i][0], (Pfloat64)2); \
      b = pow(var / (Pfloat64)2, (Pfloat64).5); \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (c->para[i][0], &obj); \
      sfprintf(outstr, "mean %s, and b ", (*fn)(obj)); \
      (*(int_type ## _fromFloat_fn) (c->fromFloat)) (b, &obj); \
      sfprintf(outstr, "%s, containing ", (*fn)(obj)); \
      sfprintf(outstr, "%d elements. \n", c->num[i]); \
    } \
  } \
  sfprintf(outstr, PDCI_hdr_strings[0]); \
  sfprintf(outstr, "Possible anormality based on probability %f: \n", c->anorm_pos); \
  temp = c->head; \
  while (temp != c->tail) { \
    (*(int_type ## _fromFloat_fn) (c->fromFloat)) (temp->ele, &obj); \
    sfprintf(outstr, "Data: %s \n", (*fn)(obj)); \
    temp = temp->next; \
  } \
  sfprintf(outstr, "Possible anormality based on clustering elements number %f: \n", c->anorm_num); \
  for (i = 0; i < c->ind; i++) { \
    if (c->cType == EXPONENTIAL) break; \
    if (c->num[i] < (int)(c->total * c->anorm_num) && c->num[i] > 0) \
    (*(int_type ## _fromFloat_fn) (c->fromFloat)) (c->para[i][0], &obj); \
    sfprintf(outstr, "Data around %s \n", (*fn)(obj)); \
  } \
  return P_OK; \
}
/* END_MACRO */

CLUSTER_MAP_REPORT_GEN (Pint8);
CLUSTER_MAP_REPORT_GEN (Pint16);
CLUSTER_MAP_REPORT_GEN (Pint32);
CLUSTER_MAP_REPORT_GEN (Pint64);
CLUSTER_MAP_REPORT_GEN (Puint8);
CLUSTER_MAP_REPORT_GEN (Puint16);
CLUSTER_MAP_REPORT_GEN (Puint32);
CLUSTER_MAP_REPORT_GEN (Puint64);

/* BEGIN_MACRO */
#define CLUSTER_BASIC_REPORT_GEN(type, fmt) \
Perror_t type ## _cluster_report_private (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2) { \
  type obj; \
\
  if (p2 == 0-INF) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "Data (around): %" fmt " \n", obj); \
    return P_OK; \
  } \
  if (c->cType == K_MEAN) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean %" fmt ", containing ", obj); \
  } \
  if (c->cType == GAUSSIAN || c->cType == OTHERS) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean %" fmt ", and variance ", obj); \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p2, &obj); \
    sfprintf(outstr, "%" fmt ", containing ", obj); \
  } \
  if (c->cType == EXPONENTIAL) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "ratio %" fmt ", containing ", obj); \
  } \
  if (c->cType == LAPLACE) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean %" fmt ", and b ", obj); \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p2, &obj); \
    sfprintf(outstr, "%" fmt ", containing ", obj); \
  } \
  return P_OK; \
} 
/* END_MACRO */

CLUSTER_BASIC_REPORT_GEN (Pint8, "d");
CLUSTER_BASIC_REPORT_GEN (Pint16, "d");
CLUSTER_BASIC_REPORT_GEN (Pint32, "d");
CLUSTER_BASIC_REPORT_GEN (Pint64, "d");
CLUSTER_BASIC_REPORT_GEN (Puint8, "d");
CLUSTER_BASIC_REPORT_GEN (Puint16, "d");
CLUSTER_BASIC_REPORT_GEN (Puint32, "d");
CLUSTER_BASIC_REPORT_GEN (Puint64, "d");
CLUSTER_BASIC_REPORT_GEN (Pfloat32, "f");
CLUSTER_BASIC_REPORT_GEN (Pfloat64, "f");
CLUSTER_BASIC_REPORT_GEN (Pchar, "c");
CLUSTER_BASIC_REPORT_GEN (Pstring, "s");

Perror_t Pip_cluster_report_private (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2) {
  Pip obj;

  if (p2 == 0-INF) {
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p1, &obj);
    sfprintf(outstr, "Data (around): ");
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, " \n");
    return P_OK;
  }
  if (c->cType == K_MEAN) {
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p1, &obj);
    sfprintf(outstr, "mean ");
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", containing ");
  }
  if (c->cType == GAUSSIAN || c->cType == OTHERS) {
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p1, &obj);
    sfprintf(outstr, "mean ");
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", and variance ");
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p2, &obj);
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", containing ", obj);
  }
  if (c->cType == EXPONENTIAL) {
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p1, &obj);
    sfprintf(outstr, "ratio ");
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", containing ", obj);
  }
  if (c->cType == LAPLACE) {
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p1, &obj);
    sfprintf(outstr, "mean ");
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", and b ", obj);
    (*(Pip_fromFloat_fn) (c->fromFloat)) (p2, &obj);
    sfprintf(outstr, "%d.%d.%d.%d \n", P_IP_PART(obj, 1), P_IP_PART(obj, 2), P_IP_PART(obj, 3), P_IP_PART(obj, 4));
    sfprintf(outstr, ", containing ", obj);
  }
  return P_OK;
}

/* BEGIN_MACRO */
#define CLUSTER_TIME_DATE_REPORT_GEN(type) \
Perror_t type ## _cluster_report_private (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2) { \
  type obj; \
\
  if (p2 == 0-INF) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "Data (around): "); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, " \n"); \
    return P_OK; \
  } \
  if (c->cType == K_MEAN) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean "); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", containing "); \
  } \
  if (c->cType == GAUSSIAN || c->cType == OTHERS) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean "); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", and variance "); \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p2, &obj); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", containing ", obj); \
  } \
  if (c->cType == EXPONENTIAL) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "ratio "); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", containing ", obj); \
  } \
  if (c->cType == LAPLACE) { \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p1, &obj); \
    sfprintf(outstr, "mean "); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", and b ", obj); \
    (*(type ## _fromFloat_fn) (c->fromFloat)) (p2, &obj); \
    sfprintf(outstr, "%s \n", fmttime("%x %I:%M %p", (time_t)obj)); \
    sfprintf(outstr, ", containing ", obj); \
  } \
  return P_OK; \
}
/* END_MACRO */

CLUSTER_TIME_DATE_REPORT_GEN(Ptimestamp);
CLUSTER_TIME_DATE_REPORT_GEN(Ptime);
CLUSTER_TIME_DATE_REPORT_GEN(Pdate);

/* Functions defined for private use only */ 
void cluster_allocateS(P_cluster *c) {
  Pint64 i;

  c->total = 0;
  c->ind = 0;
  c->para = malloc(c->k * sizeof(Pfloat64*));
  if (c->para == (Pfloat64**)0) exit(-1);
  c->num = malloc(c->k * sizeof(Pint64));
  if (c->num == (Pint64*)0) exit(-1);
  for (i = 0; i < c->k; i++) c->num[i] = 0;
  c->tail = malloc(sizeof(clink));
  if (c->tail == (clink*)0) exit(-1);
  c->head = c->tail;
  switch (c->cType) {
  case K_MEAN: 
    for (i = 0; i < c->k; i++) {
      c->para[i] = malloc(sizeof(Pfloat64));
      if (c->para[i] == (Pfloat64*)0) exit(-1);
    }
    break;
  case GAUSSIAN:
    c->probFn = (Distri_fn) Gaussian;
    for (i = 0; i < c->k; i++) {
      c->para[i] = malloc(2 * sizeof(Pfloat64));
      if (c->para[i] == (Pfloat64*)0) exit(-1);
    }
    break;
  case EXPONENTIAL:
    for (i = 0; i < c->k; i++) {
      c->para[i] = malloc(sizeof(Pfloat64));
      if (c->para[i] == (Pfloat64*)0) exit(-1);
    }
    break;
  case LAPLACE:
    for (i = 0; i < c->k; i++) {
      c->para[i] = malloc(2 * sizeof(Pfloat64));
      if (c->para[i] == (Pfloat64*)0) exit(-1);
    }
    break;
  case OTHERS:
    for (i = 0; i < c->k; i++) {
      c->para[i] = malloc(2 * sizeof(Pfloat64));
      if (c->para[i] == (Pfloat64*)0) exit(-1);
    }
    break;
  default:
    printf("\n *** Distribution type not supported (case sensitive) *** \n");
    exit(0);
  }
}

void K_mean_add (P_cluster *c, Pfloat64 d) {
  Pint32 i;
  Pfloat64 p = 0;
  Pfloat64 keepP = 100000000;
  Pint32 keepI = 0;
  Pint8 flag = 0;

  for (i = 0; i < c->ind; i++) {
    p = pow(c->para[i][0] - d, (Pfloat64)2);
    if (p < keepP) {
      keepP = p;
      keepI = i;
    }
  }

  if (c->ind != 0 && (keepP < c->open || c->ind == c->k)) {
    /* Add this data item into current clustering */
    c->para[keepI][0] = (c->para[keepI][0] * c->num[keepI] + d) / (c->num[keepI] + (Pfloat64)1);
    c->num[keepI] ++;
  }
  else {
    /* Open a new cluster for the coming data item */
    flag = 1;
    c->para[c->ind][0] = d;
    c->num[c->ind] = 1;
    c->ind ++;
  }

  if (keepP > c->anorm_pos && flag == 0) {
    /* Probable anormality based on threshold */
    c->tail->ele = d;
    c->tail->next = malloc(sizeof(clink));
    c->tail = c->tail->next;
  }

  return;
}

void Exponential_add (P_cluster *c, Pfloat64 d) {
  Pint32 i;
  Pfloat64 p = 0;
  Pfloat64 ratio;
  Pfloat64 keepP = 0;
  Pint32 keepI = 0;
  Pint8 flag = 0;

  for (i = 0; i < c->ind; i++) {
    ratio = (Pfloat64)1 / c->para[i][0];
    p = Exponential(ratio, d);
    if (p > keepP) {
      keepP = p;
      keepI = i;
    }
  }

  if (keepP > c->open || c->ind == c->k) {
    /* Add this data item into current clustering */
    c->para[keepI][0] = (c->para[keepI][0] * c->num[keepI] + d) / (c->num[keepI] + (Pfloat64)1);
    c->num[keepI] ++;
  }
  else {
    /* Open a new cluster for the coming data item */
    flag = 1;
    c->para[c->ind][0] = d;
    c->num[c->ind] = 1;
    c->ind ++;
  }

  if (keepP < c->anorm_pos && flag == 0) {
    /* Probable anormality based on threshold */
    c->tail->ele = d;
    c->tail->next = malloc(sizeof(clink));
    c->tail = c->tail->next;
  }

  return;
}

void Laplace_add (P_cluster *c, Pfloat64 d) {
  Pint32 i;
  Pfloat64 p = 0;
  Pfloat64 b;
  Pfloat64 keepP = 0;
  Pint32 keepI = 0;
  Pint8 flag = 0;

  for (i = 0; i < c->ind; i++) {
    b = (c->para[i][1] - pow(c->para[i][0], (Pfloat64)2)) / 2;
    b = pow(b, (Pfloat64).5);
    p = Laplace(c->para[i][0], b, d);
    if (p > keepP) {
      keepP = p;
      keepI = i;
    }
  }

  if (keepP > c->open || c->ind == c->k) {
    /* Add this data item into current clustering */
    c->para[keepI][0] = (c->para[keepI][0] * c->num[keepI] + d) / (c->num[keepI] + (Pfloat64)1);
    if (c->num[keepI] == 1) 
      c->para[keepI][1] = (pow(c->para[keepI][0], (Pfloat64)2) + pow(d, (Pfloat64)2)) / 2;
    else
      c->para[keepI][1] = (c->para[keepI][1] * c->num[keepI] + pow(d, (Pfloat64)2)) / (c->num[keepI] + (Pfloat64)1);
    c->num[keepI] ++;
  }
  else {
    /* Open a new cluster for the coming data item */
    flag = 1;
    c->para[c->ind][0] = d;
    c->para[c->ind][1] = pow(d, (Pfloat64)2) + c->initVar;
    c->num[c->ind] = 1;
    c->ind ++;
  }

  if (keepP < c->anorm_pos && flag == 0) {
    /* Probable anormality based on threshold */
    c->tail->ele = d;
    c->tail->next = malloc(sizeof(clink));
    c->tail = c->tail->next;
  }
  return;
}
void Other_add (P_cluster *c, Pfloat64 d) {
  Pint32 i;
  Pfloat64 p = 0;
  Pfloat64 var;
  Pfloat64 keepP = 0;
  Pint32 keepI = 0;
  Pint8 flag = 0;

  for (i = 0; i < c->ind; i++) {
    var = c->para[i][1] - pow(c->para[i][0], (Pfloat64)2);
    p = (*c->probFn)(c->para[i][0], var, d);
    if (p > keepP) {
      keepP = p;
      keepI = i;
    }
  }

  if (keepP > c->open || c->ind == c->k) {
    /* Add this data item into current clustering */
    c->para[keepI][0] = (c->para[keepI][0] * c->num[keepI] + d) / (c->num[keepI] + (Pfloat64)1);
    if (c->num[keepI] == 1) 
      c->para[keepI][1] = (pow(c->para[keepI][0], (Pfloat64)2) + pow(d, (Pfloat64)2)) / 2;
    else
      c->para[keepI][1] = (c->para[keepI][1] * c->num[keepI] + pow(d, (Pfloat64)2)) / (c->num[keepI] + (Pfloat64)1);
    c->num[keepI] ++;
  }
  else {
    /* Open a new cluster for the coming data item */
    flag = 1;
    c->para[c->ind][0] = d;
    c->para[c->ind][1] = pow(d, (Pfloat64)2) + c->initVar;
    c->num[c->ind] = 1;
    c->ind ++;
  }

  if (keepP < c->anorm_pos && flag == 0) {
    /* Probable anormality based on threshold */
    c->tail->ele = d;
    c->tail->next = malloc(sizeof(clink));
    c->tail = c->tail->next;
  }
  return;
}

Pfloat64 Exponential (Pfloat64 ratio, Pfloat64 x) {
  Pfloat64 res;

  res = exp(0 - ratio * x);
  res = res * ratio;
  return res;
}

Pfloat64 Laplace (Pfloat64 mean, Pfloat64 b, Pfloat64 x) {
  Pfloat64 res;

  if (b == 0) {
    if (x == mean) return (Pfloat64)1;
    else return (Pfloat64)0;
  }

  res = fabs(x - mean) / b;
  res = exp(0 - res);
  res = res / (2 * b);
  return res;
}
