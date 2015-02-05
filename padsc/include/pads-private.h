/*
 * padc library interface -- private types : should be ignored by users of the library
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PADS_PRIVATE_H__
#define __PADS_PRIVATE_H__

/* private string state used to manage string memory */
#define P_STRING_PRIVATE_STATE \
  RBuf_t       *rbuf; \
  int           sharing

/* 
 * Set CACHE_REGEX to some non-zero value in order to use the regcache interface 
 * to AST's regex library as opposed to repeatedly using regcomp/regfree.
 */
#define CACHE_REGEX     1

/* private Pregexp_t state */

/* XXX_REMOVE */
/* #define DEBUG_REGEX 1 */

#ifdef DEBUG_REGEX
#define PDCI_REGEXP_MATCH_SZ 100
#else
#define PDCI_REGEXP_MATCH_SZ 1
#endif

#define P_REGEXP_T_PRIVATE_STATE \
  regex_t     preg; \
  regmatch_t  match[PDCI_REGEXP_MATCH_SZ]

#define P_PRIVATE_DECLS typedef struct PDCI_stkElt_s PDCI_stkElt_t

/* PADS handle private state */
#define P_PRIVATE_STATE \
  Vmalloc_t        *vm;          /* vm handle */ \
  void             *ext1;        /* used by PDCI_node extensions. */ \
  Sfio_t           *tmp1;        /* tmp sfprintf area 1: used for many things, including numeric formatting that is part of higher-level formatting */ \
  Sfio_t           *tmp2;        /* tmp sfprintf area 2 */ \
  Sfio_t           *tmp3;        /* tmp sfprintf area 3: used for base type xml output formatting */ \
  Sfio_t           *tmp4;        /* tmp sfprintf area 4: used for structured type xml output formatting */ \
  Sfio_t           *tokenOut5;   /* tmp sfprintf area 5: used for echoing tokens */ \
  const char       *tmp1_cstr;   /* C string used in tmp1 construction */ \
  const char       *tmp2_cstr;   /* C string used in tmp2 construction */ \
  Pstring          *tmp1_pstr;   /* Pstring* used in tmp1 construction */ \
  Pstring          *tmp2_pstr;   /* Pstring* used in tmp2 construction */ \
  Pstring           stmp1;       /* tmp string 1 */ \
  Pstring           stmp2;       /* tmp string 2 */ \
  RMM_t            *rmm_z;       /* rbuf memory mgr -- zeroes allocated memory */  \
  RMM_t            *rmm_nz;      /* rbuf memory mgr -- does not zero allocated memory */  \
  Pendian_t         m_endian;    /* endian-ness of the machine */ \
  /* The following are used for write functions */ \
  Void_t           *outbuf;      /* tmp buf to use with sfio out stream (alloc outbuf_len + 1) */ \
  size_t            outbuf_len;  /* len of outbuf */ \
  size_t            outbuf_res;  /* space to reserve per top-level write call */ \
  /* The following are all related to IO state / checkpointing */ \
  char             *path;        /* original path -- eventually want to support a set of input files */ \
  Tm_zone_t        *in_zone;     /* input time zone */ \
  Tm_zone_t        *out_zone;    /* output time zone */ \
  Sfio_t           *io;          /* sfio stream */ \
  Pbyte            *sfbuf;       /* buffer that is installed in any sfio that is opened */ \
  Pio_elt_t        *head;        /* head of list of input elts */ \
  PDCI_stkElt_t    *stack;       /* stack - resized dynamically */ \
  size_t            salloc;      /* total elts allocated for stack */ \
  size_t            top;         /* index of top stack elt */ \
  unsigned int      speclev;     /* speculative nesting level */ \
  /* The following are related to nested internal calls */ \
  unsigned int      inestlev;    /* internal call nesting level */ \
  /* dummy used for error case */ \
  char              dummy[1];    \
  Dt_t              *mask_map    /* map used in initializing recursive masks. */


/* ================================================================================ */
/* HELPER MACROS FOR SHARED STRING LIST */

#define P_SOME_SHSTR(elt) ((elt)->shstr_head->next != (elt)->shstr_head)
#define P_FIRST_SHSTR(elt) ((elt)->shstr_head->next)
#define P_LAST_SHSTR(elt)  ((elt)->shstr_head->prev)

#define P_REMOVE_SHSTR(s) do { \
  Pstring *tmp = (s); \
  tmp->priv.prev->next = tmp->priv.next; \
  tmp->priv.next->prev = tmp->priv.prev; \
} while (0)

#define P_APPEND_SHSTR(elt, s) do { \
  Pstring *head = (elt)->shstr_head; \
  Pstring *tmp = (s); \
  tmp->priv.prev = head->priv.prev; \
  tmp->priv.next = head; \
  tmp->priv.prev->next = tmp; \
  tmp->priv.next->prev = tmp; \
} while (0)

#define P_PREPEND_SHSTR(elt, s) do { \
  Pstring *head = (elt)->shstr_head; \
  Pstring *tmp = (s); \
  tmp->priv.prev = head; \
  tmp->priv.next = head->priv.next; \
  tmp->priv.prev->next = tmp; \
  tmp->priv.next->prev = tmp; \
} while (0)

#endif  /*  __PADS_PRIVATE_H__  */
