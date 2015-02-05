#include "pglx-internal.h"

/* the first caller should pass 0 as curLength */
PDCI_path_t PDCI_node_getPath(PDCI_node_t *node, int curLength)
{
  PDCI_path_t path;
  if (node->parent->snExt == node->manager){
    PDCI_PATH_NEW(path,curLength);
  }else{
    path = PDCI_node_getPath(node->parent,curLength + 1);
    /* path.p[curLength] = node->idx */
    PDCI_PATH_SET(path,curLength,node->idx);
  }
    
  return path;
}

#define PDCI_DEF_BASE_PATH_WALK(ty)\
Perror_t ty ## _node_pathWalk(P_t *pads, Pbase_m *m, Pbase_pd *pd, ty *rep, PDCI_path_t path,\
			      void **m_out, void **pd_out, void **rep_out)\
{\
  PDCI_childIndex_t idx;\
  Perror_t res = P_ERR; \
                        \
  if (path.length > 0){ \
    /* modifies path */ \
    idx = PDCI_PATH_GET(path);\
\
    switch (idx) { \
      case 0: \
	if (pd->errCode == P_NO_ERR || pd->errCode == P_USER_CONSTRAINT_VIOLATION) { \
	  *m_out = NULL;										    \
	  res = ty ## _val_node_pathWalk(pads,pd,rep,path,pd_out,rep_out); \
	} else { \
	  *m_out = NULL;\
  	  res = Pbase_pd_node_pathWalk(pads,pd,path,pd_out,rep_out);\
        } \
	break; \
      case 1: \
	*m_out = NULL;\
	if (pd->nerr > 0 && pd->errCode == P_USER_CONSTRAINT_VIOLATION) \
	  res = Pbase_pd_node_pathWalk(pads,pd,path,pd_out,rep_out);\
	else { \
	  *rep_out = rep;\
          *pd_out = pd;\
	  res = P_OK;    \
        } \
	break; \
    } \
  }else{\
    *rep_out = rep;\
    *pd_out = pd;\
    *m_out = m;\
    res = P_OK;    \
  }\
\
  return res; \
}\
\
Perror_t ty ## _val_node_pathWalk(P_t *pads, Pbase_pd *pd, ty *rep, PDCI_path_t path,void **pd_out, void **rep_out)\
{ \
  PDCI_childIndex_t idx;\
  Perror_t res = P_ERR; \
                        \
  if (path.length > 0){ \
    /* modifies path */ \
    idx = PDCI_PATH_GET(path);\
\
    /* the only valid idx is 0  */\
    if (idx == 0){\
      *pd_out = NULL;\
      res = ty ## _text_node_pathWalk(pads,rep,path,rep_out);\
    }\
  }else{\
    *pd_out = pd;\
    *rep_out = rep;\
    res = P_OK;    \
  }\
\
  return res; \
} \
\
Perror_t ty ## _text_node_pathWalk(P_t *pads, ty *rep, PDCI_path_t path,void **rep_out)\
{ \
  Perror_t res = P_ERR; \
                        \
  if (path.length == 0){ \
    *rep_out = rep;\
    res = P_OK;    \
  }\
\
  return res; \
} 

PDCI_DEF_BASE_PATH_WALK(Pchar);
PDCI_DEF_BASE_PATH_WALK(Pstring);

PDCI_DEF_BASE_PATH_WALK(Pip);
PDCI_DEF_BASE_PATH_WALK(Pdate);
PDCI_DEF_BASE_PATH_WALK(Ptime);
PDCI_DEF_BASE_PATH_WALK(Ptimestamp);

PDCI_DEF_BASE_PATH_WALK(Pint8);
PDCI_DEF_BASE_PATH_WALK(Pint16);
PDCI_DEF_BASE_PATH_WALK(Pint32);
PDCI_DEF_BASE_PATH_WALK(Pint64);
PDCI_DEF_BASE_PATH_WALK(Puint8);
PDCI_DEF_BASE_PATH_WALK(Puint16);
PDCI_DEF_BASE_PATH_WALK(Puint32);
PDCI_DEF_BASE_PATH_WALK(Puint64);

PDCI_DEF_BASE_PATH_WALK(Pfloat32);
PDCI_DEF_BASE_PATH_WALK(Pfloat64);

Perror_t Ppos_t_node_pathWalk(P_t *pads, Pbase_pd *pd, Ppos_t *pos, PDCI_path_t path, void **pd_out, void **rep_out)
{
  PDCI_childIndex_t idx;
  Perror_t res = P_ERR; 
                        
  if (path.length > 0){ 
    /* modifies path */ 
    idx = PDCI_PATH_GET(path);

    switch (idx) {
    case 0:
      res = Pint32_val_node_pathWalk(pads,pd,&(pos->byte),path,pd_out,rep_out);
      break;
    case 1:
      res = Pint32_val_node_pathWalk(pads,pd,&(pos->num),path,pd_out,rep_out);
      break;
   /*
    case 2:
      PDCI_MK_TNODE(result[2], &Puint64_val_vtable,  self, "offset",  (Puint64)(pos->offset), WHATFN); 
      break;
   */	
    }
  }else{
    *pd_out = pd;
    *rep_out = pos;
    res = P_OK;    
  }

  return res; 
}

Perror_t Ploc_t_node_pathWalk(P_t *pads, Pbase_pd *pd, Ploc_t *loc, PDCI_path_t path, void **pd_out, void **rep_out)
{
  PDCI_childIndex_t idx;
  Perror_t res = P_ERR; 
                        
  if (path.length > 0){ 
    /* modifies path */ 
    idx = PDCI_PATH_GET(path);

    switch (idx) {
    case 0:
      res = Ppos_t_node_pathWalk(pads,pd,&(loc->b),path,pd_out,rep_out);
      break;
    case 1:
      res = Ppos_t_node_pathWalk(pads,pd,&(loc->e),path,pd_out,rep_out);
      break;
    }
  }else{
    *pd_out = pd;
    *rep_out = loc;
    res = P_OK;    
  }

  return res; 
}

Perror_t Pbase_pd_node_pathWalk(P_t *pads, Pbase_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out)
{
  PDCI_childIndex_t idx;
  Perror_t res = P_ERR; 
                        
  if (path.length > 0){ 
    /* modifies path */ 
    idx = PDCI_PATH_GET(path);

    switch (idx) {
    case 0:
      res = Puint32_val_node_pathWalk(pads,pd,&(pd->pstate),path,pd_out,rep_out);
      break;
    case 1:
      res = Puint32_val_node_pathWalk(pads,pd,&(pd->errCode),path,pd_out,rep_out);
      break;
    case 2:
      if (pd->errCode >= 100) {
	res = Ploc_t_node_pathWalk(pads,pd,&(pd->loc),path,pd_out,rep_out);
      }
      break;
    }
  }else{
    *pd_out = pd;
    *rep_out = pd;
    res = P_OK;    
  }

  return res; 
}

Perror_t PDCI_structured_pd_node_pathWalk(P_t *pads, PDCI_structured_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out)
{
  PDCI_childIndex_t idx;
  Perror_t res = P_ERR; 
                        
  if (path.length > 0){ 
    /* modifies path */ 
    idx = PDCI_PATH_GET(path);

    switch (idx) {
    case 0:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->pstate),path,pd_out,rep_out);
      break;
    case 1:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->nerr),path,pd_out,rep_out);
      break;
    case 2:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->errCode),path,pd_out,rep_out);
      break;
    case 3:
      if (pd->errCode >= 100) {
	res = Ploc_t_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->loc),path,pd_out,rep_out);
      }
      break;
    }
  }else{
    *pd_out = pd;
    *rep_out = pd;
    res = P_OK;    
  }

  return res; 
}

Perror_t PDCI_sequenced_pd_node_pathWalk(P_t *pads, PDCI_sequenced_pd *pd, PDCI_path_t path, void **pd_out, void **rep_out)
{
  PDCI_childIndex_t idx;
  Perror_t res = P_ERR; 
                        
  if (path.length > 0){ 
    /* modifies path */ 
    idx = PDCI_PATH_GET(path);

    switch (idx) {
    case 0:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->pstate),path,pd_out,rep_out);
      break;
    case 1:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->nerr),path,pd_out,rep_out);
      break;
    case 2:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->errCode),path,pd_out,rep_out);
      break;
    case 3:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->neerr),path,pd_out,rep_out);
      break;
    case 4:
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->firstError),path,pd_out,rep_out);
      break;
    case 5:
      if (pd->errCode >= 100) {
	res = Ploc_t_node_pathWalk(pads,(Pbase_pd *)pd,&(pd->loc),path,pd_out,rep_out);
      }
      break;
    }
  }else{
    *pd_out = pd;
    *rep_out = pd;
    res = P_OK;    
  }

  return res; 
}

Perror_t PDCI_cstr_val_node_pathWalk(P_t *pads,Pbase_pd *pd,char *rep, PDCI_path_t path,void **pd_out,void **rep_out)
{ 
  Perror_t res = P_ERR; 
                        
  if (path.length == 0){ 
    *pd_out = pd;
    *rep_out = rep;
    res = P_OK;    
  }

  return res; 
} 

