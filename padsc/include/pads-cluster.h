/*
 * PADS cluster header file
 * 
 */

#ifndef __PADS_H__
#error "Do not include pads_cluster.h directly -- include pads.h instead"
#endif

#ifndef __P_CLUSTER_H__
#define __P_CLUSTER_H__

#ifndef INF
#define INF 10000000
#endif

#ifndef PI
#define PI 3.1415976
#endif

/* Data structure defined for private use only. */
enum distri { K_MEAN, GAUSSIAN, EXPONENTIAL, LAPLACE, OTHERS };
typedef enum distri P_distri;

struct S_link {
  double ele;
  struct S_link *next;
};
typedef struct S_link clink;

/* Data structure defined with public access. */
typedef double   (*Distri_fn) (double, double, double);

typedef struct P_cluster_s {
  /* Fields with public access */
  P_distri       cType;          // Distribution type of each cluster.
  Pint32         k;              // Number of clusters.
  Pfloat64       open;           // Threshold for opening a new cluster.
  Pfloat64       initVar;        // Initial variance for each cluster.
  Pfloat64       anorm_pos;      // Possibity threshold for detecting anormality.
  Pfloat64       anorm_num;      // Element ratio threshold for detecting anormality.
  Distri_fn      probFn;         // Function computing probability for general distribution.
  P_toFloat_fn   toFloat;        // Conversion from given type to Pfloat64.
  P_fromFloat_fn fromFloat;      // Conversion from Pfloat64 to give type.
 
  /* Fields for private use only */
  Pint64         total;          // Total number of data items.
  Pint32         ind;            // Number of existing clusters.
  Pfloat64       **para;         // Parameters characterizing each distribution.
  Pint64         *num;           // Number of elements in each cluster.
  clink          *head;          // Keep head of anormalities list.
  clink          *tail;          // Keep tail of anormalities list.
  Pfloat64       mean;      
  Pfloat64       squareM;   
} P_cluster;  

typedef P_cluster Pint8_cluster;
typedef P_cluster Pint16_cluster;
typedef P_cluster Pint32_cluster;
typedef P_cluster Pint64_cluster;
typedef P_cluster Puint8_cluster;
typedef P_cluster Puint16_cluster;
typedef P_cluster Puint32_cluster;
typedef P_cluster Puint64_cluster;
typedef P_cluster Pfloat32_cluster;
typedef P_cluster Pfloat64_cluster;
typedef P_cluster Pfpoint8_cluster;
typedef P_cluster Pfpoint16_cluster;
typedef P_cluster Pfpoint32_cluster;
typedef P_cluster Pfpoint64_cluster;
typedef P_cluster Pufpoint8_cluster;
typedef P_cluster Pufpoint16_cluster;
typedef P_cluster Pufpoint32_cluster;
typedef P_cluster Pufpoint64_cluster;
typedef P_cluster Pchar_cluster;
typedef P_cluster Pstring_cluster;
typedef P_cluster Pip_cluster;
typedef P_cluster Ptimestamp_cluster;
typedef P_cluster Ptime_cluster;
typedef P_cluster Pdate_cluster;

/* Functions defined with public access */
Perror_t Pint8_cluster_init           (P_t *pads, Pint8_cluster *c);
Perror_t Pint8_cluster_setPara        (P_t *pads, Pint8_cluster *c, P_cluster *d_cluster);
Perror_t Pint8_cluster_reset          (P_t *pads, Pint8_cluster *c);
Perror_t Pint8_cluster_cleanup        (P_t *pads, Pint8_cluster *c);
Perror_t Pint8_cluster_add            (P_t *pads, Pint8_cluster *c, Pbase_pd *pd, Pint8 *rep, Puint32 *isFull);
Perror_t Pint8_cluster_report2io      (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_cluster *c);
Perror_t Pint8_cluster_map_report2io  (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint8_map_fn fn, Pint8_cluster *c);
Perror_t Pint8_cluster_report         (P_t *pads, const char *prefix, const char *what, int nst, Pint8_cluster *c);

Perror_t Pint16_cluster_init          (P_t *pads, Pint16_cluster *c);
Perror_t Pint16_cluster_setPara       (P_t *pads, Pint16_cluster *c, P_cluster* d_cluster);
Perror_t Pint16_cluster_reset         (P_t *pads, Pint16_cluster *c);
Perror_t Pint16_cluster_cleanup       (P_t *pads, Pint16_cluster *c);
Perror_t Pint16_cluster_add           (P_t *pads, Pint16_cluster *c, Pbase_pd *pd, Pint16 *rep, Puint32 *isFull);
Perror_t Pint16_cluster_report2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_cluster *c);
Perror_t Pint16_cluster_map_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint16_map_fn fn, Pint16_cluster *c);
Perror_t Pint16_cluster_report        (P_t *pads, const char *prefix, const char *what, int nst, Pint16_cluster *c);

Perror_t Pint32_cluster_init          (P_t *pads, Pint32_cluster *c);
Perror_t Pint32_cluster_setPara       (P_t *pads, Pint32_cluster *c, P_cluster* d_cluster);
Perror_t Pint32_cluster_reset         (P_t *pads, Pint32_cluster *c);
Perror_t Pint32_cluster_cleanup       (P_t *pads, Pint32_cluster *c);
Perror_t Pint32_cluster_add           (P_t *pads, Pint32_cluster *c, Pbase_pd *pd, Pint32 *rep, Puint32 *isFull);
Perror_t Pint32_cluster_report2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_cluster *c);
Perror_t Pint32_cluster_map_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint32_map_fn fn, Pint32_cluster *c);
Perror_t Pint32_cluster_report        (P_t *pads, const char *prefix, const char *what, int nst, Pint32_cluster *c);

Perror_t Pint64_cluster_init          (P_t *pads, Pint64_cluster *c);
Perror_t Pint64_cluster_setPara       (P_t *pads, Pint64_cluster *c, P_cluster* d_cluster);
Perror_t Pint64_cluster_reset         (P_t *pads, Pint64_cluster *c);
Perror_t Pint64_cluster_cleanup       (P_t *pads, Pint64_cluster *c);
Perror_t Pint64_cluster_add           (P_t *pads, Pint64_cluster *c, Pbase_pd *pd, Pint64 *rep, Puint32 *isFull);
Perror_t Pint64_cluster_report2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_cluster *c);
Perror_t Pint64_cluster_map_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pint64_map_fn fn, Pint64_cluster *c);
Perror_t Pint64_cluster_report        (P_t *pads, const char *prefix, const char *what, int nst, Pint64_cluster *c);

Perror_t Puint8_cluster_init          (P_t *pads, Puint8_cluster *c);
Perror_t Puint8_cluster_setPara       (P_t *pads, Puint8_cluster *c, P_cluster* d_cluster);
Perror_t Puint8_cluster_reset         (P_t *pads, Puint8_cluster *c);
Perror_t Puint8_cluster_cleanup       (P_t *pads, Puint8_cluster *c);
Perror_t Puint8_cluster_add           (P_t *pads, Puint8_cluster *c, Pbase_pd *pd, Puint8 *rep, Puint32 *isFull);
Perror_t Puint8_cluster_report2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_cluster *c);
Perror_t Puint8_cluster_map_report2io (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint8_map_fn fn, Puint8_cluster *c);
Perror_t Puint8_cluster_report        (P_t *pads, const char *prefix, const char *what, int nst, Puint8_cluster *c);

Perror_t Puint16_cluster_init         (P_t *pads, Puint16_cluster *c);
Perror_t Puint16_cluster_setPara      (P_t *pads, Puint16_cluster *c, P_cluster* d_cluster);
Perror_t Puint16_cluster_reset        (P_t *pads, Puint16_cluster *c);
Perror_t Puint16_cluster_cleanup      (P_t *pads, Puint16_cluster *c);
Perror_t Puint16_cluster_add          (P_t *pads, Puint16_cluster *c, Pbase_pd *pd, Puint16 *rep, Puint32 *isFull);
Perror_t Puint16_cluster_report2io    (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_cluster *c);
Perror_t Puint16_cluster_map_report2io(P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint16_map_fn fn, Puint16_cluster *c);
Perror_t Puint16_cluster_report       (P_t *pads, const char *prefix, const char *what, int nst, Puint16_cluster *c);

Perror_t Puint32_cluster_init         (P_t *pads, Puint32_cluster *c);
Perror_t Puint32_cluster_setPara      (P_t *pads, Puint32_cluster *c, P_cluster* d_cluster);
Perror_t Puint32_cluster_reset        (P_t *pads, Puint32_cluster *c);
Perror_t Puint32_cluster_cleanup      (P_t *pads, Puint32_cluster *c);
Perror_t Puint32_cluster_add          (P_t *pads, Puint32_cluster *c, Pbase_pd *pd, Puint32 *rep, Puint32 *isFull);
Perror_t Puint32_cluster_report2io    (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_cluster *c);
Perror_t Puint32_cluster_map_report2io(P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint32_map_fn fn, Puint32_cluster *c);
Perror_t Puint32_cluster_report       (P_t *pads, const char *prefix, const char *what, int nst, Puint32_cluster *c);

Perror_t Puint64_cluster_init             (P_t *pads, Puint64_cluster *c);
Perror_t Puint64_cluster_setPara          (P_t *pads, Puint64_cluster *c, P_cluster* d_cluster);
Perror_t Puint64_cluster_reset            (P_t *pads, Puint64_cluster *c);
Perror_t Puint64_cluster_cleanup          (P_t *pads, Puint64_cluster *c);
Perror_t Puint64_cluster_add              (P_t *pads, Puint64_cluster *c, Pbase_pd *pd, Puint64 *rep, Puint32 *isFull);
Perror_t Puint64_cluster_report2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_cluster *c);
Perror_t Puint64_cluster_map_report2io    (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Puint64_map_fn fn, Puint64_cluster *c);
Perror_t Puint64_cluster_report           (P_t *pads, const char *prefix, const char *what, int nst, Puint64_cluster *c);

Perror_t Pfloat32_cluster_init            (P_t *pads, Pfloat32_cluster *c);
Perror_t Pfloat32_cluster_setPara         (P_t *pads, Pfloat32_cluster *c, P_cluster* d_cluster);
Perror_t Pfloat32_cluster_reset           (P_t *pads, Pfloat32_cluster *c);
Perror_t Pfloat32_cluster_cleanup         (P_t *pads, Pfloat32_cluster *c);
Perror_t Pfloat32_cluster_add             (P_t *pads, Pfloat32_cluster *c, Pbase_pd *pd, Pfloat32 *rep, Puint32 *isFull);
Perror_t Pfloat32_cluster_report2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat32_cluster *c);
Perror_t Pfloat32_cluster_report          (P_t *pads, const char *prefix, const char *what, int nst, Pfloat32_cluster *c);

Perror_t Pfloat64_cluster_init            (P_t *pads, Pfloat64_cluster *c);
Perror_t Pfloat64_cluster_setPara         (P_t *pads, Pfloat64_cluster *c, P_cluster* d_cluster);
Perror_t Pfloat64_cluster_reset           (P_t *pads, Pfloat64_cluster *c);
Perror_t Pfloat64_cluster_cleanup         (P_t *pads, Pfloat64_cluster *c);
Perror_t Pfloat64_cluster_add             (P_t *pads, Pfloat64_cluster *c, Pbase_pd *pd, Pfloat64 *rep, Puint32 *isFull);
Perror_t Pfloat64_cluster_report2io       (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pfloat64_cluster *c);
Perror_t Pfloat64_cluster_report          (P_t *pads, const char *prefix, const char *what, int nst, Pfloat64_cluster *c);

Perror_t Pchar_cluster_init               (P_t *pads, Pchar_cluster *c);
Perror_t Pchar_cluster_setPara            (P_t *pads, Pchar_cluster *c, P_cluster* d_cluster);
Perror_t Pchar_cluster_reset              (P_t *pads, Pchar_cluster *c);
Perror_t Pchar_cluster_cleanup            (P_t *pads, Pchar_cluster *c);
Perror_t Pchar_cluster_add                (P_t *pads, Pchar_cluster *c, Pbase_pd *pd, Pchar *rep, Puint32 *isFull);
Perror_t Pchar_cluster_report2io          (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pchar_cluster *c);
Perror_t Pchar_cluster_report             (P_t *pads, const char *prefix, const char *what, int nst, Pchar_cluster *c);

Perror_t Pstring_cluster_init             (P_t *pads, Pstring_cluster *c);
Perror_t Pstring_cluster_setPara          (P_t *pads, Pstring_cluster *c, P_cluster* d_cluster);
Perror_t Pstring_cluster_reset            (P_t *pads, Pstring_cluster *c);
Perror_t Pstring_cluster_cleanup          (P_t *pads, Pstring_cluster *c);
Perror_t Pstring_cluster_add              (P_t *pads, Pstring_cluster *c, Pbase_pd *pd, Pstring *rep, Puint32 *isFull);
Perror_t Pstring_cluster_report2io        (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pstring_cluster *c);
Perror_t Pstring_cluster_report           (P_t *pads, const char *prefix, const char *what, int nst, Pstring_cluster *c);

Perror_t Pip_cluster_init                 (P_t *pads, Pip_cluster *c);
Perror_t Pip_cluster_setPara              (P_t *pads, Pip_cluster *c, P_cluster* d_cluster);
Perror_t Pip_cluster_reset                (P_t *pads, Pip_cluster *c);
Perror_t Pip_cluster_cleanup              (P_t *pads, Pip_cluster *c);
Perror_t Pip_cluster_add                  (P_t *pads, Pip_cluster *c, Pbase_pd *pd, Pip *rep, Puint32 *isFull);
Perror_t Pip_cluster_report2io            (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pip_cluster *c);
Perror_t Pip_cluster_report               (P_t *pads, const char *prefix, const char *what, int nst, Pip_cluster *c);

Perror_t Ptimestamp_cluster_init          (P_t *pads, Ptimestamp_cluster *c);
Perror_t Ptimestamp_cluster_setPara       (P_t *pads, Ptimestamp_cluster *c, P_cluster* d_cluster);
Perror_t Ptimestamp_cluster_reset         (P_t *pads, Ptimestamp_cluster *c);
Perror_t Ptimestamp_cluster_cleanup       (P_t *pads, Ptimestamp_cluster *c);
Perror_t Ptimestamp_cluster_add           (P_t *pads, Ptimestamp_cluster *c, Pbase_pd *pd, Ptimestamp *rep, Puint32 *isFull);
Perror_t Ptimestamp_cluster_report2io     (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptimestamp_cluster *c);
Perror_t Ptimestamp_cluster_report        (P_t *pads, const char *prefix, const char *what, int nst, Ptimestamp_cluster *c);

Perror_t Ptime_cluster_init               (P_t *pads, Ptime_cluster *c);
Perror_t Ptime_cluster_setPara            (P_t *pads, Ptime_cluster *c, P_cluster* d_cluster);
Perror_t Ptime_cluster_reset              (P_t *pads, Ptime_cluster *c);
Perror_t Ptime_cluster_cleanup            (P_t *pads, Ptime_cluster *c);
Perror_t Ptime_cluster_add                (P_t *pads, Ptime_cluster *c, Pbase_pd *pd, Ptime *rep, Puint32 *isFull);
Perror_t Ptime_cluster_report2io          (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Ptime_cluster *c);
Perror_t Ptime_cluster_report             (P_t *pads, const char *prefix, const char *what, int nst, Ptime_cluster *c);

Perror_t Pdate_cluster_init               (P_t *pads, Pdate_cluster *c);
Perror_t Pdate_cluster_setPara            (P_t *pads, Pdate_cluster *c, P_cluster* d_cluster);
Perror_t Pdate_cluster_reset              (P_t *pads, Pdate_cluster *c);
Perror_t Pdate_cluster_cleanup            (P_t *pads, Pdate_cluster *c);
Perror_t Pdate_cluster_add                (P_t *pads, Pdate_cluster *c, Pbase_pd *pd, Pdate *rep, Puint32 *isFull);
Perror_t Pdate_cluster_report2io          (P_t *pads, Sfio_t *outstr, const char *prefix, const char *what, int nst, Pdate_cluster *c);
Perror_t Pdate_cluster_report             (P_t *pads, const char *prefix, const char *what, int nst, Pdate_cluster *c);

/* Functions defined for private use only */
Perror_t Pint8_cluster_report_private       (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pint16_cluster_report_private      (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pint32_cluster_report_private      (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pint64_cluster_report_private      (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Puint8_cluster_report_private      (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Puint16_cluster_report_private     (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Puint32_cluster_report_private     (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Puint64_cluster_report_private     (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pfloat32_cluster_report_private    (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pfloat64_cluster_report_private    (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pchar_cluster_report_private       (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pstring_cluster_report_private     (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pip_cluster_report_private         (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Ptimestamp_cluster_report_private  (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Ptime_cluster_report_private       (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);
Perror_t Pdate_cluster_report_private       (Sfio_t *outstr, P_cluster *c, Pfloat64 p1, Pfloat64 p2);

/* Functions defined for private use only */
void     cluster_allocateS  (P_cluster *c);
void     K_mean_add         (P_cluster *c, Pfloat64 d);
void     Exponential_add    (P_cluster *c, Pfloat64 d);
void     Laplace_add        (P_cluster *c, Pfloat64 d);
void     Other_add          (P_cluster *c, Pfloat64 d);
Pfloat64 Exponential        (Pfloat64 ratio, Pfloat64 x);
Pfloat64 Laplace            (Pfloat64 mean, Pfloat64 b, Pfloat64 x);

#endif /*  __P_CLUSTER_H__  */
