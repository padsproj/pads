/* This header should not be included directly.
   It should always be included through pglx-internal.h
*/

#ifndef __PATH_WALK_H__
#define __PATH_WALK_H__

/* Type PDCI_path_t: */
/* Note that maximum path length is limited by maximum integer. */
struct PDCI_path_s{
  PDCI_childIndex_t *p;
  unsigned int length;
};

PDCI_path_t PDCI_node_getPath(PDCI_node_t *node, int curLength);

#define PDCI_DECL_BASE_PATH_WALK(ty)\
Perror_t ty ## _node_pathWalk(P_t *pads, Pbase_m *m, Pbase_pd *pd, ty *rep, PDCI_path_t path,\
			      void **m_out, void **pd_out, void **rep_out);\
Perror_t ty ## _val_node_pathWalk(P_t *pads, Pbase_pd *pd, ty *rep, PDCI_path_t path,void **pd_out, void **rep_out);\
Perror_t ty ## _text_node_pathWalk(P_t *pads, ty *rep, PDCI_path_t path,void **rep_out)


PDCI_DECL_BASE_PATH_WALK(Pchar);
PDCI_DECL_BASE_PATH_WALK(Pstring);
/* Is this #ifndef still necessary? --YHM */
#ifndef FOR_CKIT
PDCI_DECL_BASE_PATH_WALK(Pip);
PDCI_DECL_BASE_PATH_WALK(Pdate);
PDCI_DECL_BASE_PATH_WALK(Ptime);
PDCI_DECL_BASE_PATH_WALK(Ptimestamp);
#endif
PDCI_DECL_BASE_PATH_WALK(Pint8);
PDCI_DECL_BASE_PATH_WALK(Pint16);
PDCI_DECL_BASE_PATH_WALK(Pint32);
PDCI_DECL_BASE_PATH_WALK(Pint64);
PDCI_DECL_BASE_PATH_WALK(Puint8);
PDCI_DECL_BASE_PATH_WALK(Puint16);
PDCI_DECL_BASE_PATH_WALK(Puint32);
PDCI_DECL_BASE_PATH_WALK(Puint64);

PDCI_DECL_BASE_PATH_WALK(Pfloat32);
PDCI_DECL_BASE_PATH_WALK(Pfloat64);

extern const unsigned char Ppos_t_pathWidth;
extern const unsigned char Ppos_t_pathMask;
extern const unsigned char Ploc_t_pathWidth;
extern const unsigned char Ploc_t_pathMask;
extern const unsigned char Pbase_pd_pathWidth;
extern const unsigned char Pbase_pd_pathMask;
extern const unsigned char PDCI_structured_pd_pathWidth;
extern const unsigned char PDCI_structured_pd_pathMask;
extern const unsigned char PDCI_sequenced_pd_pathWidth;
extern const unsigned char PDCI_sequenced_pd_pathMask;

Perror_t Ppos_t_node_pathWalk(P_t *pads, Pbase_pd *pd, Ppos_t *pos, PDCI_path_t path, void **pd_out, void **rep_out);
Perror_t Ploc_t_node_pathWalk(P_t *pads, Pbase_pd *pd, Ploc_t *loc, PDCI_path_t path, void **pd_out, void **rep_out);
Perror_t Pbase_pd_node_pathWalk(P_t *pads, Pbase_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out);
Perror_t PDCI_structured_pd_node_pathWalk(P_t *pads, PDCI_structured_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out);
Perror_t PDCI_sequenced_pd_node_pathWalk(P_t *pads, PDCI_sequenced_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out);
Perror_t PDCI_cstr_val_node_pathWalk(P_t *pads,Pbase_pd *pd,char *rep, PDCI_path_t path,void **pd_out,void **rep_out);

#endif /* __PATH_WALK_H__ */
