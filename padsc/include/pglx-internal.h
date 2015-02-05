/*
 * internal APIs, galax-pads
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __PGLX_INTERNAL_H__
#define __PGLX_INTERNAL_H__

#include "pads-internal.h"

#if defined(FOR_CKIT)
// Include minimum set of defs for ckit, rather than having ckit
// parse all the standard OS includes, which often contain a lot of
// compiler-specific macros and pragmas.
#include "ckit-replace-galax.h"
#else
//normal includes
#include "galax.h"              /* Need to pack/unpack Galax atomic values */
#include "limits.h"
#endif

/* Source variable */
extern char * PDCI_source;

/* ================================================================================
 * Predeclare some types */

typedef struct PDCI_path_s          PDCI_path_t;
typedef unsigned long               PDCI_childIndex_t;
typedef struct PDCI_node_s          PDCI_node_t;
typedef struct PDCI_vtable_s        PDCI_vtable_t;
typedef struct PDCI_structured_pd_s PDCI_structured_pd;
typedef struct PDCI_sequenced_pd_s  PDCI_sequenced_pd;
typedef struct PDCI_pglx_id_s       PDCI_pglx_id_t;

#include "node_mm.h"
#include "path_walk.h"
#include "smart.h"
#include "linear.h"

/* ================================================================================
 * HELPER MACROS */

/* These macros are defined in pglx-impl.h.  Here we give prototypes for CKIT: */ 

#ifndef FOR_CKIT
#  include "pglx-impl.h"
#  include "pglx-codegen-macros-gen.h"
#else

void PDCI_NODE_CHECK(PDCI_node_t *n, const char *whatfn);
void PDCI_NODE_VT_CHECK(PDCI_node_t *n, const char *whatfn);
PDCI_node_t *PDCI_NEW_NODE(P_t *pads);
PDCI_node_t **PDCI_NEW_NODE_PTR_LIST(unsigned int num);
void PDCI_FREE_NODE(PDCI_node_t *n);
void PDCI_FREE_NODE_PTR_LIST(PDCI_node_t **list);

void PDCI_MK_TNODE(PDCI_node_t *result,
		   const PDCI_vtable_t *vt,
		   PDCI_node_t *parent,
		   const char *name, 
		   void* val, /* rep* */
		   const char *whatfn);

void PDCI_MK_TEXTNODE(PDCI_node_t *result,
		      const PDCI_vtable_t *vt,
		      PDCI_node_t *parent,
		      void* val, /* rep* */
		      const char *whatfn);

void  PDCI_MK_NODE(PDCI_node_t *result,
		   const PDCI_vtable_t *vt,
		   PDCI_node_t *parent,
		   const char *name, 
		   void* m, void* pd,
		   void* rep,
		   const char *kind,
		   const char *whatfn);

void  PDCI_MK_TOP_NODE(PDCI_node_t *result,
		       const PDCI_vtable_t *vt,
		       P_t *pads,
		       const char *name, 
		       void* m, void* pd,
		       void* rep,
		       const char *whatfn);

void NODE_NEW_BODY(type_t ty);
PDCI_node_t *NODE_NEW_RET();

void CACHED_NODE_INIT_BODY(type_t ty, int NUM_CHILDREN);
PDCI_node_t *CACHED_NODE_INIT_RET();

void SND_NODE_INIT_BODY(type_t ty);
PDCI_node_t
    *SND_NODE_INIT_RET();

void CACHED_NODE_KTH_CHILD_BODY(type_t ty, int NUM_CHILDREN);
PDCI_node_t 
    *CACHED_NODE_KTH_CHILD_RET();

void STR_NODE_KTH_CHILD_BODY_BEGIN(type_t ty);
void STR_NODE_KTH_CHILD_BODY_END();
PDCI_node_t *STR_NODE_KTH_CHILD_RET();

void NODE_KC_CASE(type_t ty, int fieldNumIN, type_t fieldTy, field_t fieldNameIN);
void STR_NODE_KTH_CHILD_NAMED_BODY(type_t ty, ...);
PDCI_node_t
    *STR_NODE_KTH_CHILD_NAMED_RET();

void STR_SND_NODE_KTH_CHILD_BODY_BEGIN(type_t ty);
void STR_SND_NODE_KTH_CHILD_BODY_END();
PDCI_node_t
    *STR_SND_NODE_KTH_CHILD_RET();
void SND_NODE_KC_CASE(type_t ty, int fieldNumIN,type_t fieldTy, field_t fieldNameIN);

void STR_NODE_PATH_WALK_BODY_BEGIN();
void STR_NODE_PATH_WALK_BODY_END();
Perror_t STR_NODE_PATH_WALK_RET();

int  NODE_PW_CASE(int fieldNumIN,type_t fieldTy,field_t fieldNameIN);

void VTABLE_DEFS(type_t ty);

void ARR_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t 
    *ARR_NODE_KTH_CHILD_RET();

void ARR_NODE_KTH_CHILD_NAMED_BODY();
PDCI_node_t
    *ARR_NODE_KTH_CHILD_NAMED_RET();

int  ARR_LENGTH(type_t ty);

void ARR_SND_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t *
     ARR_SND_NODE_KTH_CHILD_RET();

void ARR_NODE_PATH_WALK_BODY(type_t childTy);
Perror_t
     ARR_NODE_PATH_WALK_RET();

void REC_NODE_NEW_BODY(type_t ty, type_t baseTy);
void REC_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t 
    *REC_NODE_KTH_CHILD_RET();

void REC_NODE_KTH_CHILD_NAMED_BODY();
PDCI_node_t
    *REC_NODE_KTH_CHILD_NAMED_RET();
void REC_SND_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t *
     REC_SND_NODE_KTH_CHILD_RET();

void REC_NODE_PATH_WALK_BODY(type_t childTy);
Perror_t
     REC_NODE_PATH_WALK_RET();

void TYP_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t 
    *TYP_NODE_KTH_CHILD_RET();

void TYP_NODE_KTH_CHILD_NAMED_BODY();
PDCI_node_t
    *TYP_NODE_KTH_CHILD_NAMED_RET();
void TYP_SND_NODE_KTH_CHILD_BODY(type_t ty, type_t childTy);
PDCI_node_t *
     TYP_SND_NODE_KTH_CHILD_RET();

void TYP_NODE_PATH_WALK_BODY(type_t childTy, void * mask);
Perror_t
     TYP_NODE_PATH_WALK_RET();

void UNION_NODE_KTH_CHILD_BODY_BEGIN(type_t ty);
void UNION_NODE_KTH_CHILD_BODY_END();
PDCI_node_t *UNION_NODE_KTH_CHILD_RET();
void UNION_NODE_KC_CASE(type_t ty, int branchTagIN, type_t branchTy);
void UNION_NODE_KC_CASE_LITERAL(type_t ty, int branchTagIN);
void UNION_NODE_KTH_CHILD_NAMED_BODY(type_t ty, ...);
PDCI_node_t*UNION_NODE_KTH_CHILD_NAMED_RET();
void UNION_SND_NODE_KTH_CHILD_BODY_BEGIN(type_t ty);
void UNION_SND_NODE_KTH_CHILD_BODY_END();
PDCI_node_t *UNION_SND_NODE_KTH_CHILD_RET();
void UNION_SND_NODE_KC_CASE(type_t ty, int branchTagIN, type_t branchTy);
void UNION_SND_NODE_KC_CASE_LITERAL(type_t ty, int branchTagIN);
void UNION_NODE_PATH_WALK_BODY_BEGIN(type_t ty);
void UNION_NODE_PATH_WALK_BODY_END();
Perror_t UNION_NODE_PATH_WALK_RET();

int  UNION_NODE_PW_CASE(int branchTagIN, type_t branchTy);
int  UNION_NODE_PW_CASE_LITERAL(type_t ty, int branchTagIN);

void ENUM_NODE_KTH_CHILD_BODY(type_t ty, const char *(rep2str_fn)(int));
PDCI_node_t *ENUM_NODE_KTH_CHILD_RET();

void ENUM_NODE_KTH_CHILD_NAMED_BODY();
PDCI_node_t *ENUM_NODE_KTH_CHILD_NAMED_RET();
void ENUM_SND_NODE_KTH_CHILD_BODY(type_t ty, const char *(rep2str_fn)(int));
PDCI_node_t *ENUM_SND_NODE_KTH_CHILD_RET();
void ENUM_NODE_PATH_WALK_BODY(type_t ty);
Perror_t ENUM_NODE_PATH_WALK_RET();

void SN_ELT_ALLOC_FROM_RBUF_BODY(type_t ty,type_t eltTy, type_t eltPdTy, PDCI_node_t *smartNodeIN, 
				 P_t *padsIN, void **elt_pdIN, void **elt_repIN);
Perror_t SN_ELT_ALLOC_FROM_RBUF_RET();
void SN_ELT_ALLOC_BODY(type_t ty,type_t eltTy, type_t eltPdTy,PDCI_node_t *smartNodeIN,
		       P_t *padsIN,void **elt_pdIN,void **elt_repIN);
Perror_t SN_ELT_ALLOC_RET();
int SN_RO_PARAM(field_t p);
int SN_WRAP_PARAMS(int x,...);
void SN_ELT_READ_BODY(type_t ty,type_t eltTy, type_t eltPdTy,PDCI_node_t *smartNodeIN,
			  P_t *padsIN,PDCI_smart_elt_info_t *infoIN,int ST_PARAMS,int C_PARAMS);
Pread_res_t SN_ELT_READ_RET();
void SN_ELT_FREE_BODY(type_t ty,P_t *padsIN,PDCI_smart_elt_info_t *infoIN) ;
Perror_t SN_ELT_FREE_RET();
void SN_ELT_PATH_WALK_BODY(type_t ty,type_t eltTy, type_t eltPdTy, type_t eltMaskTy, 
			   P_t *padsIN,void *mIN, void *pdIN, void *repIN,
			   PDCI_path_t pathIN, void **m_outIN, void **pd_outIN, void **rep_outIN);
Perror_t SN_ELT_PATH_WALK_RET(type_t eltTy, P_t *padsIN, PDCI_path_t pathIN, 
			      void **m_outIN, void **pd_outIN, void **rep_outIN);
void SN_ARRAY_INFO_INIT_BODY(type_t ty, P_t *padsIN, unsigned int max_eltsIN, int C_PARAMS);
PDCI_smart_array_info_t *SN_ARRAY_INFO_INIT_RET();
void SN_INIT_BODY(type_t ty,PDCI_node_t *selfIN,unsigned int max_eltsIN, int INIT_C_PARAMS, int ST_PARAMS,int C_PARAMS);
PDCI_node_t *SN_INIT_RET(PDCI_node_t *selfIN);
void SN_KTH_CHILD_BODY(type_t ty, type_t eltTy,PDCI_node_t *selfIN, PDCI_childIndex_t idxIN);
PDCI_node_t *SN_KTH_CHILD_RET();
void SN_KTH_CHILD_NAMED_BODY(type_t ty,PDCI_node_t *selfIN, PDCI_childIndex_t kthIN, const char *nameIN);
PDCI_node_t *SN_KTH_CHILD_NAMED_RET();
#endif

/* Helper macros that we always want expanded */

#define PDCI_MAX_CHILD_INDEX ULONG_MAX

#define PDCI_DECL_NEW(ty) \
PDCI_node_t * ty ## _node_new(PDCI_node_t *parent, \
			 const char *name, \
			 void* m, void* pd, void* rep,\
			 const char *kind,const char *whatfn); \
\
PDCI_node_t * ty ## _sndNode_init(PDCI_node_t *self,          \
				  PDCI_manager_t *manager,\
                                  PDCI_childIndex_t ancestor_idx, \
				  PDCI_gen_t gen, 	      \
				  PDCI_childIndex_t idx)

#define PDCI_DECL_VT(ty) \
extern const PDCI_vtable_t ty ## _node_vtable; \
extern const PDCI_vtable_t ty ## _cachedNode_vtable; \
extern const PDCI_vtable_t ty ## _sndNode_vtable

#define PDCI_DECL_NEW_VT(ty)\
PDCI_DECL_NEW(ty);\
PDCI_DECL_VT(ty)

#define PDCI_DECL_VAL_VT(ty) \
PDCI_node_t * ty ## _val_node_new(PDCI_node_t *parent, const char *name, \
			 void* pd, void* rep, unsigned int id_offset, const char *whatfn);\
PDCI_node_t * ty ## _text_node_new(PDCI_node_t *parent, const char *whatfn);\
PDCI_node_t  * ty ## _val_cachedNode_init(PDCI_node_t *node); \
PDCI_node_t  * ty ## _text_cachedNode_init(PDCI_node_t *node); \
PDCI_node_t  * ty ## _val_sndNode_init(PDCI_node_t *node, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, \
				     PDCI_gen_t gen, PDCI_childIndex_t idx); \
PDCI_node_t  * ty ## _text_sndNode_init(PDCI_node_t *node, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, \
				     PDCI_gen_t gen, PDCI_childIndex_t idx); \
PDCI_node_t  * ty ## _val_node_kthChild(PDCI_node_t *node, PDCI_childIndex_t idx); \
PDCI_node_t  * ty ## _val_node_kthChildNamed(PDCI_node_t *node, PDCI_childIndex_t idx, const char *name); \
item ty ## _typed_value(PDCI_node_t *node); \
const char * ty ## _string_value(PDCI_node_t *node); \
extern const PDCI_vtable_t ty ## _val_node_vtable; \
extern const PDCI_vtable_t ty ## _val_cachedNode_vtable; \
extern const PDCI_vtable_t ty ## _val_sndNode_vtable; \
extern const PDCI_vtable_t ty ## _text_node_vtable; \
extern const PDCI_vtable_t ty ## _text_cachedNode_vtable; \
extern const PDCI_vtable_t ty ## _text_sndNode_vtable


/* Identifier offsets for nodes that don't have their own pd. 
 * The offsets are relative to the _id_ of their pd field.
 */
#define PDCI_BASE_PD_OFF      1
#define PDCI_STR_PD_OFF       1

#define PDCI_PSTATE_OFF       1
#define PDCI_NERR_OFF         2
#define PDCI_ERRCODE_OFF      3
#define PDCI_LOC_OFF          4
#define PDCI_B_OFF            1
#define PDCI_BYTE_OFF         1
#define PDCI_NUM_OFF          2
#define PDCI_E_OFF            4

#define PDCI_VAL_OFF          12
#define PDCI_TEXT_OFF         13

#define PDCI_SEQ_PD_OFF       1
#define PDCI_FIRSTERROR_OFF   12
#define PDCI_NEERR_OFF        13
#define PDCI_LENGTH_OFF       14

/* ================================================================================
 * TYPES */

/* prototypes for vtable functions */
typedef PDCI_node_t *       (* PDCI_cachedNode_init_fn)  (PDCI_node_t *node); 
typedef PDCI_node_t *       (* PDCI_kth_child_fn)        (PDCI_node_t *node, PDCI_childIndex_t idx); 
typedef PDCI_node_t *       (* PDCI_kth_child_named_fn)  (PDCI_node_t *node, PDCI_childIndex_t idx, const char *name); 
typedef void                (* PDCI_free_fn)             (PDCI_node_t *node);
typedef PDCI_pglx_id_t      (* PDCI_get_id_fn)           (PDCI_node_t *node);
typedef item                (* PDCI_typed_value_fn)      (PDCI_node_t *node); 
typedef const char *        (* PDCI_string_value_fn)     (PDCI_node_t *node);

/* Type PDCI_node_t: */
struct PDCI_node_s {
  const PDCI_vtable_t     *vt;
  P_t                     *pads;

  void                    *m;
  void                    *pd;
  void                    *rep;
  const char              *name;
  const char              *kind;
  PDCI_node_t             *parent;

  // reference counting
  unsigned long            rc;

  // Used by smart node descendents

  /* 
   *  Note: the manager field is non-NULL iff element is a
   *  smart-node descendent. Therefore, this field can
   *  can be used as a tag to determine whether it is an snd.
   *
   *  manager: pointer to manager of ancestor element.
   *  ancestor_idx: idx of ancestor element.
   *  ptr_gen: generation of rep and pd pointers.
   */     
  PDCI_manager_t          *manager;
  PDCI_childIndex_t        ancestor_idx;
  PDCI_gen_t               ptr_gen;

  /*
   * index of object in relation to parent
   */
  PDCI_childIndex_t        idx;
  
  
  // Used by caching nodes
  PDCI_node_t           **child_cache;  

  union{
    // Used by smart nodes:
    PDCI_smart_node_t       *snExt;

    /// Used by linear nodes:
    PDCI_linear_node_t      *lnExt;

    // Used by other nodes:
    unsigned int id_offset;
#ifndef FOR_CKIT
  };
#else
  // add name for union because ckit does not understand anonymous unions.
  } ext; 
#endif
};

/* Type PDCI_vtable_t: */
struct PDCI_vtable_s {
  PDCI_cachedNode_init_fn    cachedNode_init;
  PDCI_kth_child_fn         kth_child;
  PDCI_kth_child_named_fn   kth_child_named;
  PDCI_free_fn              free;
  PDCI_get_id_fn            get_id;
  PDCI_typed_value_fn       typed_value;
  PDCI_string_value_fn      string_value;
};

/* Type PDCI_pglx_id_t */
struct PDCI_pglx_id_s {
  PDCI_id_t gId;  
  PDCI_id_t mId;  
};

/* PARSE DESCRIPTOR SUPPORT */
/* NB all generated structured pd types must BEGIN with the declarations given here: */

/* type PDCI_structured_pd: */
struct PDCI_structured_pd_s {
  Pflags_t     pstate;
  Puint32      nerr;
  PerrCode_t   errCode;
  Ploc_t       loc;
  /* The id field contains the node's identifier. 
   * It is not a child node. 
   */
  PDCI_id_t    _id_; 
};

/* NB all generated sequenced pd types must BEGIN with the declarations given here: */

/* Type PDCI_sequenced_pd_t: */
struct PDCI_sequenced_pd_s {
  Pflags_t    pstate;
  Puint32     nerr;
  PerrCode_t  errCode;
  Ploc_t      loc;
  /* The id field contains the node's identifier. 
   * It is not a child node. 
   */
  PDCI_id_t   _id_;
  Puint32     neerr;		        
  Puint32     firstError;		
};

/* ================================================================================
 * Helper functions */

Perror_t
PGLX_report_err(P_t *pads, int level, Ploc_t *loc,
  PerrCode_t errCode, const char *whatfn, const char *format, ...);

/* Node new functions */

PDCI_node_t * Pbase_pd_node_new(PDCI_node_t *parent, const char *name, 
			      void* rep, const char *whatfn);
PDCI_node_t * Ploc_t_node_new(PDCI_node_t *parent, const char *name, 
			      void* pd, void* rep, unsigned int id_offset, const char *whatfn);
PDCI_node_t * Ppos_t_node_new(PDCI_node_t *parent, const char *name, 
			      void* pd, void* rep, unsigned int id_offset, const char *whatfn);
PDCI_node_t * PDCI_structured_pd_node_new(PDCI_node_t *parent, const char *name, 
			      void* rep, const char *whatfn);
PDCI_node_t * PDCI_sequenced_pd_node_new(PDCI_node_t *parent, const char *name, 
			      void* rep, const char *whatfn);

/* cachedNode init functions */

PDCI_node_t  * Pbase_pd_cachedNode_init(PDCI_node_t *self);
PDCI_node_t  * Ploc_t_cachedNode_init(PDCI_node_t *self);
PDCI_node_t  * Ppos_t_cachedNode_init(PDCI_node_t *self);
PDCI_node_t  * PDCI_structured_pd_cachedNode_init(PDCI_node_t *self);
PDCI_node_t  * PDCI_sequenced_pd_cachedNode_init(PDCI_node_t *self);

/* sndNode init functions */

PDCI_node_t  * Pbase_pd_sndNode_init(PDCI_node_t *self, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, 
				     PDCI_gen_t gen, PDCI_childIndex_t idx);
PDCI_node_t  * Ploc_t_sndNode_init(PDCI_node_t *self, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, 
				     PDCI_gen_t gen, PDCI_childIndex_t idx);
PDCI_node_t  * Ppos_t_sndNode_init(PDCI_node_t *self, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, 
				     PDCI_gen_t gen, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_structured_pd_sndNode_init(PDCI_node_t *self, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, 
				     PDCI_gen_t gen, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_sequenced_pd_sndNode_init(PDCI_node_t *self, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx, 
				     PDCI_gen_t gen, PDCI_childIndex_t idx);

/* Node Kth child functions */

PDCI_node_t  * Pbase_pd_node_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ploc_t_node_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ppos_t_node_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_structured_pd_node_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_sequenced_pd_node_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);

/* Node Kth child named functions */

PDCI_node_t  * Pbase_pd_node_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);
PDCI_node_t  * Ploc_t_node_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);
PDCI_node_t  * Ppos_t_node_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);
PDCI_node_t  * PDCI_structured_pd_node_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);
PDCI_node_t  * PDCI_sequenced_pd_node_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);

/* cachedNode Kth child functions */

PDCI_node_t  * Pbase_pd_cachedNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ploc_t_cachedNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ppos_t_cachedNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_structured_pd_cachedNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_sequenced_pd_cachedNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);

/* sndNode Kth child functions */

PDCI_node_t  * Pbase_pd_sndNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ploc_t_sndNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * Ppos_t_sndNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_structured_pd_sndNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_sequenced_pd_sndNode_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);

/* Helpers for nodes with no children */
PDCI_node_t  * PDCI_node_no_kthChild(PDCI_node_t *self, PDCI_childIndex_t idx);
PDCI_node_t  * PDCI_node_no_kthChildNamed(PDCI_node_t *self, PDCI_childIndex_t idx, const char *name);


/* Error function used to prevent reinitialization of cachedNode caches. */
PDCI_node_t *PDCI_error_cachedNode_init(PDCI_node_t *node); 

/* General-purpose memory management vtable functions. */
void PDCI_node_free(PDCI_node_t *node);
void PDCI_cachedNode_free(PDCI_node_t *node);

/* PDCI_cstr functions */
PDCI_node_t *PDCI_cstr_val_node_new(PDCI_node_t *parent, const char *name, 
                                    void *pd, void *rep,
                                    unsigned int id_offset,
                                    const char *whatfn);
PDCI_node_t  * PDCI_cstr_val_sndNode_init(PDCI_node_t *node, PDCI_manager_t *manager, PDCI_childIndex_t ancestor_idx,
				          PDCI_gen_t gen, PDCI_childIndex_t idx); 
item PDCI_cstr_typed_value (PDCI_node_t *node); /* node->rep is a C-style string (const char *) */
item PDCI_cstr_sndNode_typed_value(PDCI_node_t *node);

/* Error and Typed Value functions */
PDCI_node_t *PDCI_error_cachedNode_init(PDCI_node_t *node);
item PDCI_error_typed_value(PDCI_node_t *node); /* Error function used for many cases */

/* String Value functions */
const char * PDCI_not_impl_yet_string_value(PDCI_node_t *node);

/* Misc. */
PDCI_smart_elt_info_t *PDCI_get_ancestor(PDCI_node_t *node);
PDCI_pglx_id_t PDCI_node_getId(PDCI_node_t *self);
PDCI_pglx_id_t PDCI_sndNode_getId(PDCI_node_t *self);
PDCI_pglx_id_t PDCI_smartNode_getId(PDCI_node_t *self);
PDCI_pglx_id_t PDCI_error_getId(PDCI_node_t *self);

/* ================================================================================
 * VTABLES */

/* Special vtables */

PDCI_DECL_VT(PDCI_structured_pd);
PDCI_DECL_VT(PDCI_sequenced_pd);

PDCI_DECL_VT(Pbase_pd);
PDCI_DECL_VT(Ploc_t);
PDCI_DECL_VT(Ppos_t);

/* Special val_vtables */

PDCI_DECL_VAL_VT(PDCI_cstr);

/* Base type vtables */

/* I don't think that non in-memory types need their own vtables, as
   they are never referenced.  These tables should probably be done
   the same way as the val tables --YHM */

PDCI_DECL_NEW_VT(Pchar);
PDCI_DECL_NEW_VT(Pa_char);
PDCI_DECL_NEW_VT(Pe_char);

PDCI_DECL_NEW_VT(Pstring);
PDCI_DECL_NEW_VT(Pstring_ME);
PDCI_DECL_NEW_VT(Pstring_CME);
PDCI_DECL_NEW_VT(Pstring_SE);
PDCI_DECL_NEW_VT(Pstring_CSE);

PDCI_DECL_NEW_VT(Pa_string);
PDCI_DECL_NEW_VT(Pa_string_ME);
PDCI_DECL_NEW_VT(Pa_string_CME);
PDCI_DECL_NEW_VT(Pa_string_SE);
PDCI_DECL_NEW_VT(Pa_string_CSE);

PDCI_DECL_NEW_VT(Pe_string);
PDCI_DECL_NEW_VT(Pe_string_ME);
PDCI_DECL_NEW_VT(Pe_string_CME);
PDCI_DECL_NEW_VT(Pe_string_SE);
PDCI_DECL_NEW_VT(Pe_string_CSE);

PDCI_DECL_NEW_VT(Pip);
PDCI_DECL_NEW_VT(Pdate);
PDCI_DECL_NEW_VT(Ptime);
PDCI_DECL_NEW_VT(Ptimestamp);

PDCI_DECL_NEW_VT(Pint8);
PDCI_DECL_NEW_VT(Pint16);
PDCI_DECL_NEW_VT(Pint32);
PDCI_DECL_NEW_VT(Pint64);
PDCI_DECL_NEW_VT(Puint8);
PDCI_DECL_NEW_VT(Puint16);
PDCI_DECL_NEW_VT(Puint32);
PDCI_DECL_NEW_VT(Puint64);

PDCI_DECL_NEW_VT(Pfloat32);
PDCI_DECL_NEW_VT(Pfloat64);

/* We need one _val_vtable for each in-memory format.
   All of the PADS types that share an in-memory format 
   can share a vtable */

/* The required _val_vtable */
PDCI_DECL_VAL_VT(Pchar);
PDCI_DECL_VAL_VT(Pstring);

PDCI_DECL_VAL_VT(Pip);
PDCI_DECL_VAL_VT(Pdate);
PDCI_DECL_VAL_VT(Ptime);
PDCI_DECL_VAL_VT(Ptimestamp);

PDCI_DECL_VAL_VT(Pint8);
PDCI_DECL_VAL_VT(Pint16);
PDCI_DECL_VAL_VT(Pint32);
PDCI_DECL_VAL_VT(Pint64);
PDCI_DECL_VAL_VT(Puint8);
PDCI_DECL_VAL_VT(Puint16);
PDCI_DECL_VAL_VT(Puint32);
PDCI_DECL_VAL_VT(Puint64);

PDCI_DECL_VAL_VT(Pfloat32);
PDCI_DECL_VAL_VT(Pfloat64);

/* The cases where we can use vtable sharing */
#ifdef FOR_CKIT
PDCI_DECL_VAL_VT(Pa_char);
PDCI_DECL_VAL_VT(Pe_char);

PDCI_DECL_VAL_VT(Pstring_ME);
PDCI_DECL_VAL_VT(Pstring_CME);
PDCI_DECL_VAL_VT(Pstring_SE);
PDCI_DECL_VAL_VT(Pstring_CSE);

PDCI_DECL_VAL_VT(Pa_string);
PDCI_DECL_VAL_VT(Pa_string_ME);
PDCI_DECL_VAL_VT(Pa_string_CME);
PDCI_DECL_VAL_VT(Pa_string_SE);
PDCI_DECL_VAL_VT(Pa_string_CSE);

PDCI_DECL_VAL_VT(Pe_string);
PDCI_DECL_VAL_VT(Pe_string_ME);
PDCI_DECL_VAL_VT(Pe_string_CME);
PDCI_DECL_VAL_VT(Pe_string_SE);
PDCI_DECL_VAL_VT(Pe_string_CSE);

#else
#define Pa_char_val_vtable         Pchar_val_vtable
#define Pe_char_val_vtable         Pchar_val_vtable

#define Pstring_ME_val_vtable      Pstring_val_vtable
#define Pstring_CME_val_vtable     Pstring_val_vtable
#define Pstring_SE_val_vtable      Pstring_val_vtable
#define Pstring_CSE_val_vtable     Pstring_val_vtable

#define Pa_string_val_vtable       Pstring_val_vtable
#define Pa_string_ME_val_vtable    Pstring_val_vtable
#define Pa_string_CME_val_vtable   Pstring_val_vtable
#define Pa_string_SE_val_vtable    Pstring_val_vtable
#define Pa_string_CSE_val_vtable   Pstring_val_vtable

#define Pe_string_val_vtable       Pstring_val_vtable
#define Pe_string_ME_val_vtable    Pstring_val_vtable
#define Pe_string_CME_val_vtable   Pstring_val_vtable
#define Pe_string_SE_val_vtable    Pstring_val_vtable
#define Pe_string_CSE_val_vtable   Pstring_val_vtable

#endif /* FOR_CKIT */

/* XXX TEMP XXX */
Sfio_t *P_io_get(P_t *pads);
Perror_t P_io_seek(P_t *pads, Sfoff_t offset);
/* XXX END_TEMP XXX */

#endif  /*   __PGX_INTERNAL_H__   */

