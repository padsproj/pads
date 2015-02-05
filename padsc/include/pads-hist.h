/*
 * PADS histogram header file
 * 
 */

#ifndef __PADS_H__
#error "Do not include pads_hist.h directly -- include pads.h instead"
#endif

#ifndef __P_HIST_H__
#define __P_HIST_H__

#ifndef INF
#define INF 10000000
#endif

/* Data structure defined for private use only. */
struct wave {
  Pint64   level; // Starting from 0. Log n means the uniform one.
  Pint64   index; // Starting from 0. Continuous.
  Pfloat64 coef;  // The coefficient of the wavelet vector.
};
struct bucket {
  Pint64   bound; // Start (close) or end point (open) of that bucket.
  Pfloat64 hei;   // Height of that bucket.
};
struct dpCell {
  Pfloat64 error; // SSE error in that range.
  Pfloat64 hei;   // Height in that range.
  Pint64   bound; // Start point (close) of the last bucket. 
};

/* Data structure defined with public access. */

/* Map function maps between a given type and the Pfloat64 type */
typedef Perror_t (*P_toFloat_fn)   (void*, Pfloat64*);
typedef Perror_t (*P_fromFloat_fn) (Pfloat64, void*);

typedef Perror_t (*Pint8_toFloat_fn)        (Pint8*, Pfloat64*);
typedef Perror_t (*Pint8_fromFloat_fn)      (Pfloat64, Pint8*);
typedef Perror_t (*Pint16_toFloat_fn)       (Pint16*, Pfloat64*);
typedef Perror_t (*Pint16_fromFloat_fn)     (Pfloat64, Pint16*);
typedef Perror_t (*Pint32_toFloat_fn)       (Pint32*, Pfloat64*);
typedef Perror_t (*Pint32_fromFloat_fn)     (Pfloat64, Pint32*);
typedef Perror_t (*Pint64_toFloat_fn)       (Pint64*, Pfloat64*);
typedef Perror_t (*Pint64_fromFloat_fn)     (Pfloat64, Pint64*);
typedef Perror_t (*Puint8_toFloat_fn)       (Puint8*, Pfloat64*);
typedef Perror_t (*Puint8_fromFloat_fn)     (Pfloat64, Puint8*);
typedef Perror_t (*Puint16_toFloat_fn)      (Puint16*, Pfloat64*);
typedef Perror_t (*Puint16_fromFloat_fn)    (Pfloat64, Puint16*);
typedef Perror_t (*Puint32_toFloat_fn)      (Puint32*, Pfloat64*);
typedef Perror_t (*Puint32_fromFloat_fn)    (Pfloat64, Puint32*);
typedef Perror_t (*Puint64_toFloat_fn)      (Puint64*, Pfloat64*);
typedef Perror_t (*Puint64_fromFloat_fn)    (Pfloat64, Puint64*);
typedef Perror_t (*Pfloat32_toFloat_fn)     (Pfloat32*, Pfloat64*);
typedef Perror_t (*Pfloat32_fromFloat_fn)   (Pfloat64, Pfloat32*);
typedef Perror_t (*Pfloat64_toFloat_fn)     (Pfloat64*, Pfloat64*);
typedef Perror_t (*Pfloat64_fromFloat_fn)   (Pfloat64, Pfloat64*);
typedef Perror_t (*Pchar_toFloat_fn)        (Pchar*, Pfloat64*);
typedef Perror_t (*Pchar_fromFloat_fn)      (Pfloat64, Pchar*);
typedef Perror_t (*Pstring_toFloat_fn)      (Pstring*, Pfloat64*);
typedef Perror_t (*Pstring_fromFloat_fn)    (Pfloat64, Pstring*);
typedef Perror_t (*Pip_toFloat_fn)          (Pip*, Pfloat64*);
typedef Perror_t (*Pip_fromFloat_fn)        (Pfloat64, Pip*);
typedef Perror_t (*Ptimestamp_toFloat_fn)   (Ptimestamp*, Pfloat64*);
typedef Perror_t (*Ptimestamp_fromFloat_fn) (Pfloat64, Ptimestamp*);
typedef Perror_t (*Ptime_toFloat_fn)        (Ptime*, Pfloat64*);
typedef Perror_t (*Ptime_fromFloat_fn)      (Pfloat64, Ptime*);
typedef Perror_t (*Pdate_toFloat_fn)        (Pdate*, Pfloat64*);
typedef Perror_t (*Pdate_fromFloat_fn)      (Pfloat64, Pdate*);

typedef struct P_hist_s {
  /* These fields can be customized by users */
  Pint64         N;              // Dimension of the original data item. 
  Pint32         B;              // Number of buckets in the final histogram.
  Pint64         M;              // Bound on the range that values can take.
  Pint8          isE;            // Buckets required to be of same lenght or not.  
  Pint8          isO;            // Result required to be optimal one or near-optimal. Valid when isEqual = f;
  Pint8          n;              // Only 1 and 2 are allowed. Specify L1 or L2 norm. Valid when isEqual = f and isOpt = t.
  Pfloat64       e;              // Error tolence. For isOpt = f only.
  Pint64         scale;          // SCALE factor to make data having proper value.
  Pint8          maxPortion;     // Maximal number of histogram portions allowed to store.
  P_toFloat_fn   toFloat;        // Conversion from given type to Pfloat64.
  P_fromFloat_fn fromFloat;      // Conversion from Pfloat64 to give type.

  /* These fields are defined for private use only */
  Pint64         ind;            // Index of current data item.
  Pint8          portionInd;     // Portion index.
  struct bucket  **result;       // Result histogram link.  
  Pfloat64       partS;          // Used in EqualHis.
  Pint64         bukI;       	 // Used in EqualHis.      
  Pint8          lNumber;        // Level Number in wavelet representation.
  Pfloat64       *leftS,*rightS; // Store pipelined information in computing coefficients.
  Pint32         rSize;          // Size of robust representation.
  struct wave    *top;           // Store wavelets with top coefficients.
  Pint32         topI;        	 // Used in NearOptHis, for top array. 
  struct bucket  *bound; 	 // Used in NearOptHis.
  Pint32         boundI;         // Used in NearOptHis, for bound array.      
  struct bucket  *rob;           // Robust histogram.
  Pint64         robI;   	 // Used in NearOptHis, for rob array. 
  struct dpCell  **dpTable;      // Table to compute the dynamic programming.
  Pint32         rowN;   	 // Used in NearOptHis, for dpTable.
  Pint64         colN;   	 // Used in NearOptHis, for dpTable.
} P_hist;  

typedef P_hist Pint8_hist;
typedef P_hist Pint16_hist;
typedef P_hist Pint32_hist;
typedef P_hist Pint64_hist;
typedef P_hist Puint8_hist;
typedef P_hist Puint16_hist;
typedef P_hist Puint32_hist;
typedef P_hist Puint64_hist;
typedef P_hist Pfloat32_hist;
typedef P_hist Pfloat64_hist;
typedef P_hist Pfpoint8_hist;
typedef P_hist Pfpoint16_hist;
typedef P_hist Pfpoint32_hist;
typedef P_hist Pfpoint64_hist;
typedef P_hist Pufpoint8_hist;
typedef P_hist Pufpoint16_hist;
typedef P_hist Pufpoint32_hist;
typedef P_hist Pufpoint64_hist;
typedef P_hist Pchar_hist;
typedef P_hist Pstring_hist;
typedef P_hist Pip_hist;
typedef P_hist Ptimestamp_hist;
typedef P_hist Ptime_hist;
typedef P_hist Pdate_hist;

/* Functions defined with public access */
Perror_t Pint8_hist_init                (P_t *pads, Pint8_hist *h);
Perror_t Pint8_hist_setPara             (P_t *pads, Pint8_hist *h, P_hist *d_hist);
Perror_t Pint8_hist_reset               (P_t *pads, Pint8_hist *h);
Perror_t Pint8_hist_cleanup             (P_t *pads, Pint8_hist *h);
Perror_t Pint8_hist_add                 (P_t *pads, Pint8_hist *h, Pbase_pd *pd, Pint8 *rep, Puint32 *isFull);
Perror_t Pint8_hist_reportFull2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_hist *h);
Perror_t Pint8_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_hist *h);
Perror_t Pint8_hist_map_reportFull2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_map_fn fn, Pint8_hist *h);
Perror_t Pint8_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_hist *h);
Perror_t Pint8_hist_reportFull          (P_t *pads, const char *prefix, const char *what, int nst, Pint8_hist *h);
Perror_t Pint8_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_hist *h);

Perror_t Pint16_hist_init               (P_t *pads, Pint16_hist *h);
Perror_t Pint16_hist_setPara            (P_t *pads, Pint16_hist *h, P_hist* d_hist);
Perror_t Pint16_hist_reset              (P_t *pads, Pint16_hist *h);
Perror_t Pint16_hist_cleanup            (P_t *pads, Pint16_hist *h);
Perror_t Pint16_hist_add                (P_t *pads, Pint16_hist *h, Pbase_pd *pd, Pint16 *rep, Puint32 *isFull);
Perror_t Pint16_hist_reportFull2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_hist *h);
Perror_t Pint16_hist_reportAll2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_hist *h);
Perror_t Pint16_hist_map_reportFull2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_map_fn fn, Pint16_hist *h);
Perror_t Pint16_hist_map_reportAll2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_map_fn fn, Pint16_hist *h);
Perror_t Pint16_hist_reportFull         (P_t *pads, const char *prefix, const char *what, int nst, Pint16_hist *h);
Perror_t Pint16_hist_reportAll          (P_t *pads, const char *prefix, const char *what, int nst, Pint16_hist *h);

Perror_t Pint32_hist_init               (P_t *pads, Pint32_hist *h);
Perror_t Pint32_hist_setPara            (P_t *pads, Pint32_hist *h, P_hist* d_hist);
Perror_t Pint32_hist_reset              (P_t *pads, Pint32_hist *h);
Perror_t Pint32_hist_cleanup            (P_t *pads, Pint32_hist *h);
Perror_t Pint32_hist_add                (P_t *pads, Pint32_hist *h, Pbase_pd *pd, Pint32 *rep, Puint32 *isFull);
Perror_t Pint32_hist_reportFull2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_hist *h);
Perror_t Pint32_hist_reportAll2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_hist *h);
Perror_t Pint32_hist_map_reportFull2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_map_fn fn, Pint32_hist *h);
Perror_t Pint32_hist_map_reportAll2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_map_fn fn, Pint32_hist *h);
Perror_t Pint32_hist_reportFull         (P_t *pads, const char *prefix, const char *what, int nst, Pint32_hist *h);
Perror_t Pint32_hist_reportAll          (P_t *pads, const char *prefix, const char *what, int nst, Pint32_hist *h);

Perror_t Pint64_hist_init               (P_t *pads, Pint64_hist *h);
Perror_t Pint64_hist_setPara            (P_t *pads, Pint64_hist *h, P_hist* d_hist);
Perror_t Pint64_hist_reset              (P_t *pads, Pint64_hist *h);
Perror_t Pint64_hist_cleanup            (P_t *pads, Pint64_hist *h);
Perror_t Pint64_hist_add                (P_t *pads, Pint64_hist *h, Pbase_pd *pd, Pint64 *rep, Puint32 *isFull);
Perror_t Pint64_hist_reportFull2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_hist *h);
Perror_t Pint64_hist_reportAll2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_hist *h);
Perror_t Pint64_hist_map_reportFull2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_map_fn fn, Pint64_hist *h);
Perror_t Pint64_hist_map_reportAll2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_map_fn fn, Pint64_hist *h);
Perror_t Pint64_hist_reportFull         (P_t *pads, const char *prefix, const char *what, int nst, Pint64_hist *h);
Perror_t Pint64_hist_reportAll          (P_t *pads, const char *prefix, const char *what, int nst, Pint64_hist *h);

Perror_t Puint8_hist_init               (P_t *pads, Puint8_hist *h);
Perror_t Puint8_hist_setPara            (P_t *pads, Puint8_hist *h, P_hist* d_hist);
Perror_t Puint8_hist_reset              (P_t *pads, Puint8_hist *h);
Perror_t Puint8_hist_cleanup            (P_t *pads, Puint8_hist *h);
Perror_t Puint8_hist_add                (P_t *pads, Puint8_hist *h, Pbase_pd *pd, Puint8 *rep, Puint32 *isFull);
Perror_t Puint8_hist_reportFull2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_hist *h);
Perror_t Puint8_hist_reportAll2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_hist *h);
Perror_t Puint8_hist_map_reportFull2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_map_fn fn, Puint8_hist *h);
Perror_t Puint8_hist_map_reportAll2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_map_fn fn, Puint8_hist *h);
Perror_t Puint8_hist_reportFull         (P_t *pads, const char *prefix, const char *what, int nst, Puint8_hist *h);
Perror_t Puint8_hist_reportAll          (P_t *pads, const char *prefix, const char *what, int nst, Puint8_hist *h);

Perror_t Puint16_hist_init              (P_t *pads, Puint16_hist *h);
Perror_t Puint16_hist_setPara           (P_t *pads, Puint16_hist *h, P_hist* d_hist);
Perror_t Puint16_hist_reset             (P_t *pads, Puint16_hist *h);
Perror_t Puint16_hist_cleanup           (P_t *pads, Puint16_hist *h);
Perror_t Puint16_hist_add               (P_t *pads, Puint16_hist *h, Pbase_pd *pd, Puint16 *rep, Puint32 *isFull);
Perror_t Puint16_hist_reportFull2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_hist *h);
Perror_t Puint16_hist_reportAll2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_hist *h);
Perror_t Puint16_hist_map_reportFull2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_map_fn fn, Puint16_hist *h);
Perror_t Puint16_hist_map_reportAll2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_map_fn fn, Puint16_hist *h);
Perror_t Puint16_hist_reportFull        (P_t *pads, const char *prefix, const char *what, int nst, Puint16_hist *h);
Perror_t Puint16_hist_reportAll         (P_t *pads, const char *prefix, const char *what, int nst, Puint16_hist *h);

Perror_t Puint32_hist_init              (P_t *pads, Puint32_hist *h);
Perror_t Puint32_hist_setPara           (P_t *pads, Puint32_hist *h, P_hist* d_hist);
Perror_t Puint32_hist_reset             (P_t *pads, Puint32_hist *h);
Perror_t Puint32_hist_cleanup           (P_t *pads, Puint32_hist *h);
Perror_t Puint32_hist_add               (P_t *pads, Puint32_hist *h, Pbase_pd *pd, Puint32 *rep, Puint32 *isFull);
Perror_t Puint32_hist_reportFull2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_hist *h);
Perror_t Puint32_hist_reportAll2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_hist *h);
Perror_t Puint32_hist_map_reportFull2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_map_fn fn, Puint32_hist *h);
Perror_t Puint32_hist_map_reportAll2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_map_fn fn, Puint32_hist *h);
Perror_t Puint32_hist_reportFull        (P_t *pads, const char *prefix, const char *what, int nst, Puint32_hist *h);
Perror_t Puint32_hist_reportAll         (P_t *pads, const char *prefix, const char *what, int nst, Puint32_hist *h);

Perror_t Puint64_hist_init              (P_t *pads, Puint64_hist *h);
Perror_t Puint64_hist_setPara           (P_t *pads, Puint64_hist *h, P_hist* d_hist);
Perror_t Puint64_hist_reset             (P_t *pads, Puint64_hist *h);
Perror_t Puint64_hist_cleanup           (P_t *pads, Puint64_hist *h);
Perror_t Puint64_hist_add               (P_t *pads, Puint64_hist *h, Pbase_pd *pd, Puint64 *rep, Puint32 *isFull);
Perror_t Puint64_hist_reportFull2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_hist *h);
Perror_t Puint64_hist_reportAll2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_hist *h);
Perror_t Puint64_hist_map_reportFull2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_map_fn fn, Puint64_hist *h);
Perror_t Puint64_hist_map_reportAll2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_map_fn fn, Puint64_hist *h);
Perror_t Puint64_hist_reportFull        (P_t *pads, const char *prefix, const char *what, int nst, Puint64_hist *h);
Perror_t Puint64_hist_reportAll         (P_t *pads, const char *prefix, const char *what, int nst, Puint64_hist *h);

Perror_t Pfloat32_hist_init             (P_t *pads, Pfloat32_hist *h);
Perror_t Pfloat32_hist_setPara          (P_t *pads, Pfloat32_hist *h, P_hist* d_hist);
Perror_t Pfloat32_hist_reset            (P_t *pads, Pfloat32_hist *h);
Perror_t Pfloat32_hist_cleanup          (P_t *pads, Pfloat32_hist *h);
Perror_t Pfloat32_hist_add              (P_t *pads, Pfloat32_hist *h, Pbase_pd *pd, Pfloat32 *rep, Puint32 *isFull);
Perror_t Pfloat32_hist_reportFull2io    (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat32_hist *h);
Perror_t Pfloat32_hist_reportAll2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat32_hist *h);
Perror_t Pfloat32_hist_reportFull       (P_t *pads, const char *prefix, const char *what, int nst, Pfloat32_hist *h);
Perror_t Pfloat32_hist_reportAll        (P_t *pads, const char *prefix, const char *what, int nst, Pfloat32_hist *h);

Perror_t Pfloat64_hist_init             (P_t *pads, Pfloat64_hist *h);
Perror_t Pfloat64_hist_setPara          (P_t *pads, Pfloat64_hist *h, P_hist* d_hist);
Perror_t Pfloat64_hist_reset            (P_t *pads, Pfloat64_hist *h);
Perror_t Pfloat64_hist_cleanup          (P_t *pads, Pfloat64_hist *h);
Perror_t Pfloat64_hist_add              (P_t *pads, Pfloat64_hist *h, Pbase_pd *pd, Pfloat64 *rep, Puint32 *isFull);
Perror_t Pfloat64_hist_reportFull2io    (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat64_hist *h);
Perror_t Pfloat64_hist_reportAll2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat64_hist *h);
Perror_t Pfloat64_hist_reportFull       (P_t *pads, const char *prefix, const char *what, int nst, Pfloat64_hist *h);
Perror_t Pfloat64_hist_reportAll        (P_t *pads, const char *prefix, const char *what, int nst, Pfloat64_hist *h);

Perror_t Pchar_hist_init                (P_t *pads, Pchar_hist *h);
Perror_t Pchar_hist_setPara             (P_t *pads, Pchar_hist *h, P_hist* d_hist);
Perror_t Pchar_hist_reset               (P_t *pads, Pchar_hist *h);
Perror_t Pchar_hist_cleanup             (P_t *pads, Pchar_hist *h);
Perror_t Pchar_hist_add                 (P_t *pads, Pchar_hist *h, Pbase_pd *pd, Pchar *rep, Puint32 *isFull);
Perror_t Pchar_hist_reportFull2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pchar_hist *h);
Perror_t Pchar_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pchar_hist *h);
Perror_t Pchar_hist_reportFull          (P_t *pads, const char *prefix, const char *what, int nst, Pchar_hist *h);
Perror_t Pchar_hist_reportAll           (P_t *pads, const char *prefix, const char *what, int nst, Pchar_hist *h);

Perror_t Pstring_hist_init              (P_t *pads, Pstring_hist *h);
Perror_t Pstring_hist_setPara           (P_t *pads, Pstring_hist *h, P_hist* d_hist);
Perror_t Pstring_hist_reset             (P_t *pads, Pstring_hist *h);
Perror_t Pstring_hist_cleanup           (P_t *pads, Pstring_hist *h);
Perror_t Pstring_hist_add               (P_t *pads, Pstring_hist *h, Pbase_pd *pd, Pstring *rep, Puint32 *isFull);
Perror_t Pstring_hist_reportFull2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pstring_hist *h);
Perror_t Pstring_hist_reportAll2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pstring_hist *h);
Perror_t Pstring_hist_reportFull        (P_t *pads, const char *prefix, const char *what, int nst, Pstring_hist *h);
Perror_t Pstring_hist_reportAll         (P_t *pads, const char *prefix, const char *what, int nst, Pstring_hist *h);

Perror_t Pip_hist_init                  (P_t *pads, Pip_hist *h);
Perror_t Pip_hist_setPara               (P_t *pads, Pip_hist *h, P_hist* d_hist);
Perror_t Pip_hist_reset                 (P_t *pads, Pip_hist *h);
Perror_t Pip_hist_cleanup               (P_t *pads, Pip_hist *h);
Perror_t Pip_hist_add                   (P_t *pads, Pip_hist *h, Pbase_pd *pd, Pip *rep, Puint32 *isFull);
Perror_t Pip_hist_reportFull2io         (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pip_hist *h);
Perror_t Pip_hist_reportAll2io          (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pip_hist *h);
Perror_t Pip_hist_reportFull            (P_t *pads, const char *prefix, const char *what, int nst, Pip_hist *h);
Perror_t Pip_hist_reportAll             (P_t *pads, const char *prefix, const char *what, int nst, Pip_hist *h);

Perror_t Ptimestamp_hist_init           (P_t *pads, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_setPara        (P_t *pads, Ptimestamp_hist *h, P_hist* d_hist);
Perror_t Ptimestamp_hist_reset          (P_t *pads, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_cleanup        (P_t *pads, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_add            (P_t *pads, Ptimestamp_hist *h, Pbase_pd *pd, Ptimestamp *rep, Puint32 *isFull);
Perror_t Ptimestamp_hist_reportFull2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_reportAll2io   (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_reportFull     (P_t *pads, const char *prefix, const char *what, int nst, Ptimestamp_hist *h);
Perror_t Ptimestamp_hist_reportAll      (P_t *pads, const char *prefix, const char *what, int nst, Ptimestamp_hist *h);

Perror_t Ptime_hist_init                (P_t *pads, Ptime_hist *h);
Perror_t Ptime_hist_setPara             (P_t *pads, Ptime_hist *h, P_hist* d_hist);
Perror_t Ptime_hist_reset               (P_t *pads, Ptime_hist *h);
Perror_t Ptime_hist_cleanup             (P_t *pads, Ptime_hist *h);
Perror_t Ptime_hist_add                 (P_t *pads, Ptime_hist *h, Pbase_pd *pd, Ptime *rep, Puint32 *isFull);
Perror_t Ptime_hist_reportFull2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptime_hist *h);
Perror_t Ptime_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptime_hist *h);
Perror_t Ptime_hist_reportFull          (P_t *pads, const char *prefix, const char *what, int nst, Ptime_hist *h);
Perror_t Ptime_hist_reportAll           (P_t *pads, const char *prefix, const char *what, int nst, Ptime_hist *h);

Perror_t Pdate_hist_init                (P_t *pads, Pdate_hist *h);
Perror_t Pdate_hist_setPara             (P_t *pads, Pdate_hist *h, P_hist* d_hist);
Perror_t Pdate_hist_reset               (P_t *pads, Pdate_hist *h);
Perror_t Pdate_hist_cleanup             (P_t *pads, Pdate_hist *h);
Perror_t Pdate_hist_add                 (P_t *pads, Pdate_hist *h, Pbase_pd *pd, Pdate *rep, Puint32 *isFull);
Perror_t Pdate_hist_reportFull2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pdate_hist *h);
Perror_t Pdate_hist_reportAll2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pdate_hist *h);
Perror_t Pdate_hist_reportFull          (P_t *pads, const char *prefix, const char *what, int nst, Pdate_hist *h);
Perror_t Pdate_hist_reportAll           (P_t *pads, const char *prefix, const char *what, int nst, Pdate_hist *h);

/* Functions defined for private use only */
Perror_t Pint8_report       (Sfio_t *outstr, Pint8_hist *h, Pint8 pInd);
Perror_t Pint16_report      (Sfio_t *outstr, Pint16_hist *h, Pint8 pInd);
Perror_t Pint32_report      (Sfio_t *outstr, Pint32_hist *h, Pint8 pInd);
Perror_t Pint64_report      (Sfio_t *outstr, Pint64_hist *h, Pint8 pInd);
Perror_t Puint8_report      (Sfio_t *outstr, Puint8_hist *h, Pint8 pInd);
Perror_t Puint16_report     (Sfio_t *outstr, Puint16_hist *h, Pint8 pInd);
Perror_t Puint32_report     (Sfio_t *outstr, Puint32_hist *h, Pint8 pInd);
Perror_t Puint64_report     (Sfio_t *outstr, Puint64_hist *h, Pint8 pInd);
Perror_t Pint8_map_report   (Sfio_t *outstr, Pint8_map_fn fn, Pint8_hist *h, Pint8 pInd);
Perror_t Pint16_map_report  (Sfio_t *outstr, Pint16_map_fn fn, Pint16_hist *h, Pint8 pInd);
Perror_t Pint32_map_report  (Sfio_t *outstr, Pint32_map_fn fn, Pint32_hist *h, Pint8 pInd);
Perror_t Pint64_map_report  (Sfio_t *outstr, Pint64_map_fn fn, Pint64_hist *h, Pint8 pInd);
Perror_t Puint8_map_report  (Sfio_t *outstr, Puint8_map_fn fn, Puint8_hist *h, Pint8 pInd);
Perror_t Puint16_map_report (Sfio_t *outstr, Puint16_map_fn fn, Puint16_hist *h, Pint8 pInd);
Perror_t Puint32_map_report (Sfio_t *outstr, Puint32_map_fn fn, Puint32_hist *h, Pint8 pInd);
Perror_t Puint64_map_report (Sfio_t *outstr, Puint64_map_fn fn, Puint64_hist *h, Pint8 pInd);
Perror_t Pfloat32_report    (Sfio_t *outstr, Pfloat32_hist *h, Pint8 pInd);
Perror_t Pfloat64_report    (Sfio_t *outstr, Pfloat64_hist *h, Pint8 pInd);
Perror_t Pchar_report       (Sfio_t *outstr, Pchar_hist *h, Pint8 pInd);
Perror_t Pstring_report     (Sfio_t *outstr, Pstring_hist *h, Pint8 pInd);
Perror_t Pip_report         (Sfio_t *outstr, Pip_hist *h, Pint8 pInd);
Perror_t Ptimestamp_report  (Sfio_t *outstr, Ptimestamp_hist *h, Pint8 pInd);
Perror_t Ptime_report       (Sfio_t *outstr, Ptime_hist *h, Pint8 pInd);
Perror_t Pdate_report       (Sfio_t *outstr, Pdate_hist *h, Pint8 pInd);

Perror_t EqualHis   (P_hist *h, Pfloat64 d);
Perror_t OptHis     (P_hist *h, Pfloat64 d);
Perror_t NearOptHis (P_hist *h, Pfloat64 d);

struct dpCell OptHei      (P_hist *h, Pint64 s, Pint64 e);                                // Optimal height between A[s...e].
Pint64        partition_w (struct wave** A, Pint64 p, Pint64 r);                          // Rearrange the array A[p...r].
Pint64        partition_b (struct bucket** A, Pint64 p, Pint64 r);                        // Override function.
void          select_w    (struct wave** A, P_hist* h, Pint64 p, Pint64 r);               // Drops the least half numbers.   
Pfloat64      select_b    (struct bucket** A, P_hist* h, Pint64 p, Pint64 r, Pint64 sel); // Return element at sel rank; 
void          quickSort   (struct bucket** A, Pint64 p, Pint64 q);                        // Sort array A based on end point.
void          buildRob    (P_hist *h);                                                    // Build robust histograms. 
void          compOpt     (P_hist *h);                                                    // Get the optimal one from rob array.
void          allocateS   (P_hist *h);                                                    // Allocate space for future use.

#endif /*  __P_HIST_H__  */
