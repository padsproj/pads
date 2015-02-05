/*
 * PADS output macros
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __P_OUT_MACROS_H__
#define __P_OUT_MACROS_H__

//#define TRACE 1

#ifdef FOR_CKIT
/* Prototypes for CKIT */
extern int P_LEV_INFO;
extern int P_LEV_WARN;
extern int P_LEV_ERR;
extern int P_LEV_FATAL;
extern int P_LEV_MASK;

extern int P_FLG_PROMPT;
extern int P_FLG_SYSERR;
extern int P_FLG_LIBRARY;

int P_GET_LEV(int flags);
int P_GET_FLG(int flags);

void P_DBG(Pdisc_t *t, char * fmt);
void P_DBG1(Pdisc_t *t, char * fmt,...);
void P_DBG2(Pdisc_t *t, char * fmt,...);
void P_DBG3(Pdisc_t *t, char * fmt,...);
void P_DBG4(Pdisc_t *t, char * fmt,...);
void P_DBG5(Pdisc_t *t, char * fmt,...);
void P_DBG6(Pdisc_t *t, char * fmt,...);
void P_DBG7(Pdisc_t *t, char * fmt,...);

void P_TRACE(Pdisc_t *t, char * fmt);
void P_TRACE1(Pdisc_t *t, char * fmt,...);
void P_TRACE2(Pdisc_t *t, char * fmt,...);
void P_TRACE3(Pdisc_t *t, char * fmt,...);
void P_TRACE4(Pdisc_t *t, char * fmt,...);
void P_TRACE5(Pdisc_t *t, char * fmt,...);
void P_TRACE6(Pdisc_t *t, char * fmt,...);
void P_TRACE7(Pdisc_t *t, char * fmt,...);

void P_WARN(Pdisc_t *t, char * fmt);
void P_WARN1(Pdisc_t *t, char * fmt,...);
void P_WARN2(Pdisc_t *t, char * fmt,...);
void P_WARN3(Pdisc_t *t, char * fmt,...);
void P_WARN4(Pdisc_t *t, char * fmt,...);
void P_WARN5(Pdisc_t *t, char * fmt,...);
void P_WARN6(Pdisc_t *t, char * fmt,...);
void P_WARN7(Pdisc_t *t, char * fmt,...);

void P_SYSERR(Pdisc_t *t, char * fmt);
void P_SYSERR1(Pdisc_t *t, char * fmt,...);
void P_SYSERR2(Pdisc_t *t, char * fmt,...);
void P_SYSERR3(Pdisc_t *t, char * fmt,...);
void P_SYSERR4(Pdisc_t *t, char * fmt,...);
void P_SYSERR5(Pdisc_t *t, char * fmt,...);
void P_SYSERR6(Pdisc_t *t, char * fmt,...);
void P_SYSERR7(Pdisc_t *t, char * fmt,...);

void P_FATAL(Pdisc_t *t, char * fmt);
void P_FATAL1(Pdisc_t *t, char * fmt,...);
void P_FATAL2(Pdisc_t *t, char * fmt,...);
void P_FATAL3(Pdisc_t *t, char * fmt,...);
void P_FATAL4(Pdisc_t *t, char * fmt,...);
void P_FATAL5(Pdisc_t *t, char * fmt,...);
void P_FATAL6(Pdisc_t *t, char * fmt,...);
void P_FATAL7(Pdisc_t *t, char * fmt,...);

#else
/* The actual impls */

#define P_LEV_INFO      ERROR_INFO
#define P_LEV_WARN      ERROR_WARNING
#define P_LEV_ERR       ERROR_ERROR
#define P_LEV_FATAL     ERROR_FATAL
#define P_LEV_MASK      ERROR_LEVEL

#define P_FLG_PROMPT    ERROR_PROMPT
#define P_FLG_SYSERR    ERROR_SYSTEM
#define P_FLG_LIBRARY   ERROR_LIBRARY

#define P_GET_LEV(flags) (flags & P_LEV_MASK)
#define P_GET_FLG(flags) (flags & ~P_LEV_MASK)

#define P_DBG_FLAGS      -2
/* #define P_TRACE_FLAGS    -4 */
#define P_TRACE_FLAGS    P_LEV_WARN
#define P_WARN_FLAGS     P_LEV_WARN
#define P_SYSERR_FLAGS   P_LEV_ERR|P_FLG_SYSERR
#define P_FATAL_FLAGS    P_LEV_FATAL

#define P_NULL_STMT do { } while (0)

#ifndef NDEBUG
# define P_DBG(disc,fmt)                         P_FMT_ERR_MSG ((disc),(fmt),P_DBG_FLAGS)
# define P_DBG1(disc,fmt,a1)                     P_FMT_ERR_MSG1((disc),(fmt),P_DBG_FLAGS,(a1))
# define P_DBG2(disc,fmt,a1,a2)                  P_FMT_ERR_MSG2((disc),(fmt),P_DBG_FLAGS,(a1),(a2))
# define P_DBG3(disc,fmt,a1,a2,a3)               P_FMT_ERR_MSG3((disc),(fmt),P_DBG_FLAGS,(a1),(a2),(a3))
# define P_DBG4(disc,fmt,a1,a2,a3,a4)            P_FMT_ERR_MSG4((disc),(fmt),P_DBG_FLAGS,(a1),(a2),(a3),(a4))
# define P_DBG5(disc,fmt,a1,a2,a3,a4,a5)         P_FMT_ERR_MSG5((disc),(fmt),P_DBG_FLAGS,(a1),(a2),(a3),(a4),(a5))
# define P_DBG6(disc,fmt,a1,a2,a3,a4,a5,a6)      P_FMT_ERR_MSG6((disc),(fmt),P_DBG_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6))
# define P_DBG7(disc,fmt,a1,a2,a3,a4,a5,a6,a7)   P_FMT_ERR_MSG7((disc),(fmt),P_DBG_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6),(a7))
#else
# define P_DBG(disc,fmt)                         P_NULL_STMT
# define P_DBG1(disc,fmt,a1)                     P_NULL_STMT
# define P_DBG2(disc,fmt,a1,a2)                  P_NULL_STMT
# define P_DBG3(disc,fmt,a1,a2,a3)               P_NULL_STMT
# define P_DBG4(disc,fmt,a1,a2,a3,a4)            P_NULL_STMT
# define P_DBG5(disc,fmt,a1,a2,a3,a4,a5)         P_NULL_STMT
# define P_DBG6(disc,fmt,a1,a2,a3,a4,a5,a6)      P_NULL_STMT
# define P_DBG7(disc,fmt,a1,a2,a3,a4,a5,a6,a7)   P_NULL_STMT
#endif

#ifdef TRACE
# define P_TRACE(disc,fmt)                       P_FMT_ERR_MSG ((disc),(fmt),P_TRACE_FLAGS)
# define P_TRACE1(disc,fmt,a1)                   P_FMT_ERR_MSG1((disc),(fmt),P_TRACE_FLAGS,(a1))
# define P_TRACE2(disc,fmt,a1,a2)                P_FMT_ERR_MSG2((disc),(fmt),P_TRACE_FLAGS,(a1),(a2))
# define P_TRACE3(disc,fmt,a1,a2,a3)             P_FMT_ERR_MSG3((disc),(fmt),P_TRACE_FLAGS,(a1),(a2),(a3))
# define P_TRACE4(disc,fmt,a1,a2,a3,a4)          P_FMT_ERR_MSG4((disc),(fmt),P_TRACE_FLAGS,(a1),(a2),(a3),(a4))
# define P_TRACE5(disc,fmt,a1,a2,a3,a4,a5)       P_FMT_ERR_MSG5((disc),(fmt),P_TRACE_FLAGS,(a1),(a2),(a3),(a4),(a5))
# define P_TRACE6(disc,fmt,a1,a2,a3,a4,a5,a6)    P_FMT_ERR_MSG6((disc),(fmt),P_TRACE_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6))
# define P_TRACE7(disc,fmt,a1,a2,a3,a4,a5,a6,a7) P_FMT_ERR_MSG7((disc),(fmt),P_TRACE_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6),(a7))
#else
# define P_TRACE(disc,fmt)                       P_NULL_STMT
# define P_TRACE1(disc,fmt,a1)                   P_NULL_STMT
# define P_TRACE2(disc,fmt,a1,a2)                P_NULL_STMT
# define P_TRACE3(disc,fmt,a1,a2,a3)             P_NULL_STMT
# define P_TRACE4(disc,fmt,a1,a2,a3,a4)          P_NULL_STMT
# define P_TRACE5(disc,fmt,a1,a2,a3,a4,a5)       P_NULL_STMT
# define P_TRACE6(disc,fmt,a1,a2,a3,a4,a5,a6)    P_NULL_STMT
# define P_TRACE7(disc,fmt,a1,a2,a3,a4,a5,a6,a7) P_NULL_STMT
#endif

#define P_WARN(disc,fmt)                         P_FMT_ERR_MSG ((disc),(fmt),P_WARN_FLAGS)
#define P_WARN1(disc,fmt,a1)                     P_FMT_ERR_MSG1((disc),(fmt),P_WARN_FLAGS,(a1))
#define P_WARN2(disc,fmt,a1,a2)                  P_FMT_ERR_MSG2((disc),(fmt),P_WARN_FLAGS,(a1),(a2))
#define P_WARN3(disc,fmt,a1,a2,a3)               P_FMT_ERR_MSG3((disc),(fmt),P_WARN_FLAGS,(a1),(a2),(a3))
#define P_WARN4(disc,fmt,a1,a2,a3,a4)            P_FMT_ERR_MSG4((disc),(fmt),P_WARN_FLAGS,(a1),(a2),(a3),(a4))
#define P_WARN5(disc,fmt,a1,a2,a3,a4,a5)         P_FMT_ERR_MSG5((disc),(fmt),P_WARN_FLAGS,(a1),(a2),(a3),(a4),(a5))
#define P_WARN6(disc,fmt,a1,a2,a3,a4,a5,a6)      P_FMT_ERR_MSG6((disc),(fmt),P_WARN_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6))
#define P_WARN7(disc,fmt,a1,a2,a3,a4,a5,a6,a7)   P_FMT_ERR_MSG7((disc),(fmt),P_WARN_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6),(a7))

#define P_SYSERR(disc,fmt)                       P_FMT_ERR_MSG ((disc),(fmt),P_SYSERR_FLAGS)
#define P_SYSERR1(disc,fmt,a1)                   P_FMT_ERR_MSG1((disc),(fmt),P_SYSERR_FLAGS,(a1))
#define P_SYSERR2(disc,fmt,a1,a2)                P_FMT_ERR_MSG2((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2))
#define P_SYSERR3(disc,fmt,a1,a2,a3)             P_FMT_ERR_MSG3((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2),(a3))
#define P_SYSERR4(disc,fmt,a1,a2,a3,a4)          P_FMT_ERR_MSG4((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2),(a3),(a4))
#define P_SYSERR5(disc,fmt,a1,a2,a3,a4,a5)       P_FMT_ERR_MSG5((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2),(a3),(a4),(a5))
#define P_SYSERR6(disc,fmt,a1,a2,a3,a4,a5,a6)    P_FMT_ERR_MSG6((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6))
#define P_SYSERR7(disc,fmt,a1,a2,a3,a4,a5,a6,a7) P_FMT_ERR_MSG7((disc),(fmt),P_SYSERR_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6),(a7))

#define P_FATAL(disc,fmt)                        P_FMT_ERR_MSG ((disc),("FATAL: " fmt),P_FATAL_FLAGS)
#define P_FATAL1(disc,fmt,a1)                    P_FMT_ERR_MSG1((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1))
#define P_FATAL2(disc,fmt,a1,a2)                 P_FMT_ERR_MSG2((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2))
#define P_FATAL3(disc,fmt,a1,a2,a3)              P_FMT_ERR_MSG3((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2),(a3))
#define P_FATAL4(disc,fmt,a1,a2,a3,a4)           P_FMT_ERR_MSG4((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2),(a3),(a4))
#define P_FATAL5(disc,fmt,a1,a2,a3,a4,a5)        P_FMT_ERR_MSG5((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2),(a3),(a4),(a5))
#define P_FATAL6(disc,fmt,a1,a2,a3,a4,a5,a6)     P_FMT_ERR_MSG6((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6))
#define P_FATAL7(disc,fmt,a1,a2,a3,a4,a5,a6,a7)  P_FMT_ERR_MSG7((disc),("FATAL: " fmt),P_FATAL_FLAGS,(a1),(a2),(a3),(a4),(a5),(a6),(a7))

#define P_FMT_ERR_MSG(disc,fmt,erlev) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt);} } while (0)
#define P_FMT_ERR_MSG1(disc,fmt,erlev,a1) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1);} } while (0)
#define P_FMT_ERR_MSG2(disc,fmt,erlev,a1,a2) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2);} } while (0)
#define P_FMT_ERR_MSG3(disc,fmt,erlev,a1,a2,a3) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2, a3);} } while (0)
#define P_FMT_ERR_MSG4(disc,fmt,erlev,a1,a2,a3,a4) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2, a3, a4);} } while (0)
#define P_FMT_ERR_MSG5(disc,fmt,erlev,a1,a2,a3,a4,a5) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2, a3, a4, a5);} } while (0)
#define P_FMT_ERR_MSG6(disc,fmt,erlev,a1,a2,a3,a4,a5,a6) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2, a3, a4, a5, a6);} } while (0)
#define P_FMT_ERR_MSG7(disc,fmt,erlev,a1,a2,a3,a4,a5,a6,a7) \
  do { if (disc != NULL && disc->error_fn) {disc->error_fn(NiL, erlev, fmt, a1, a2, a3, a4, a5, a6, a7);} } while (0)

#endif /* ! FOR_CKIT */


#endif /*  __P_OUT_MACROS_H__  */
