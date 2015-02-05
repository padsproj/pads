/* ********************* BEGIN_MACROS(pglx-codegen-macros-gen.h) ********************** */
/*
 * Macros used to generate pads-galax code.
 * 
 * Yitzhak Mandelbaum
 * AT&T Labs Research
 */

/* ********************************** END_HEADER ********************************** */

/* ================================================================================ */

#define GLX_STR_MATCH(p,s) (strcmp((p),(s)) == 0)

#define NODE_NEW_BODY(ty)
  PDCI_node_t *result;
  PDCI_MK_NODE (result,& ty ## _node_vtable,
		parent,name,m,pd,rep,kind, PDCI_MacroArg2String(ty) "_node_new");
  result->manager = 0;
  result->id_offset = 0
/* END_MACRO */

#define NODE_NEW_RET()
result
/* END_MACRO */

#define CACHED_NODE_INIT_BODY(ty,NUM_CHILDREN)
  /* Setup the virtual table */
  self->vt = & ty ## _cachedNode_vtable;
  
  /* Setup node-type specific fields */
  self->child_cache = (PDCI_node_t **)PDCI_NEW_LIST(NUM_CHILDREN);
  if(self->child_cache == NULL)
    error (ERROR_FATAL, "ALLOC_ERROR: in " PDCI_MacroArg2String(ty) "_cachedNode_init")
/* END_MACRO */

#define CACHED_NODE_INIT_RET()
self
/* END_MACRO */

#define SND_NODE_INIT_BODY(ty)
  PDCI_SND_INIT(ty,self,manager,ancestor_idx,gen,idx)
/* END_MACRO */

#define SND_NODE_INIT_RET()
self
/* END_MACRO */

#define CACHED_NODE_KTH_CHILD_BODY(ty,NUM_CHILDREN)
  PDCI_node_t *result = 0;

  /* Array bounds check for cache.*/
  if (idx >= NUM_CHILDREN) /* non-existent child */
    return result;

  result = self->child_cache[idx];
  if (result == NULL){
    /* create a new node for the kth child */
    result = ty ## _node_kthChild(self,idx);

    /*  initialize the node to be a cachedNode. */
    (result->vt->cachedNode_init)(result);

    /* cache the result */
    self->child_cache[idx] = result;
  }

/* END_MACRO */

#define CACHED_NODE_KTH_CHILD_RET()
PDCI_ALIAS_NODE(result)
/* END_MACRO */

/******* Struct macros ******/

/* 
   Mary : If the order of elements in STR_NODE_KTH_CHILD_BODY_BEGIN changes, then 
  STR_NODE_KTH_CHILD_NAMED_BODY(ty,...) must also change
*/
#define STR_NODE_KTH_CHILD_BODY_BEGIN(ty)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  ty ## _pd *pd=(ty ## _pd *) (self->pd);
  ty ## _m *m=(ty ## _m *) (self->m);

  switch(idx){
/* END_MACRO */

#define STR_NODE_KTH_CHILD_BODY_END(pdidx)
  case pdidx:
    /* parse descriptor child */
    if (pd->nerr > 0)
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_node_kthChild");
    break;
  }
/* END_MACRO */

#define STR_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

/* case for kthChild function */
#define NODE_KC_CASE(ty,fieldNumIN,fieldTy,fieldNameIN)
  case fieldNumIN:
    result = fieldTy ## _node_new(self,PDCI_MacroArg2String(fieldNameIN),
				  &(m->fieldNameIN),
				  &(pd->fieldNameIN),
				  &(rep->fieldNameIN),
				  "element", PDCI_MacroArg2String(ty) "_node_kthChild");
    break
/* END_MACRO */

/* Note: this macro assumes that there is at least one optional parameter. */
#define STR_NODE_KTH_CHILD_NAMED_BODY(ty,...)
  PDCI_node_t *result = 0;
  PDCI_childIndex_t i;
  const char *fieldNames[] = { __VA_ARGS__ , "pd",0}; 
  /* The index must be 0 as all field names are unique.*/
  if (idx != 0)
    return result;
  for (i = 0; 1; i++) {
    if (fieldNames[i] == 0) {
      /* error(2, "fieldNames[i] == 0\n"); */
      return result;
    }
    /* error(2, "name = %s fieldNames[%d] = %s\n", name, i, fieldNames[i]);  */
    if (GLX_STR_MATCH(name, fieldNames[i])) {
      /* error(2, "%s matches %s at %d\n", name, fieldNames[i], i);  */
      break;
    }
  } 
/* error(2, "... %d\n", i);  */
  /* fall through if i set correctly */
/* END_MACRO */

#define STR_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,i)
/* END_MACRO */

#define STR_SND_NODE_KTH_CHILD_BODY_BEGIN(ty)
  PDCI_node_t *result = 0;
  ty *rep;
  ty ## _pd *pd;
  ty ## _m *m;

  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (ty ## _pd *) (self->pd);
  m=(ty ## _m *) (self->m);

  switch(idx){
/* END_MACRO */

#define STR_SND_NODE_KTH_CHILD_BODY_END(pdidx)
  case pdidx: 
    /* parse descriptor child */
    if (pd->nerr > 0) 
    {
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_sndNode_kthChild");
      PDCI_structured_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    }
    break;
  }

/* END_MACRO */  

#define STR_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define SND_NODE_KC_CASE(ty,fieldNumIN,fieldTy,fieldNameIN)
  case fieldNumIN:
    result = fieldTy ## _node_new(self,PDCI_MacroArg2String(fieldNameIN),
				  &(m->fieldNameIN),
				  &(pd->fieldNameIN),
				  &(rep->fieldNameIN),
				  "element", PDCI_MacroArg2String(ty) "_sndNode_kthChild");
    fieldTy ## _sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    break
/* END_MACRO */

#define STR_NODE_PATH_WALK_BODY_BEGIN()
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    switch(idx){
/* END_MACRO */

#define STR_NODE_PATH_WALK_BODY_END(pdidx)
    case pdidx: 
      *m_out = NULL;
      res = PDCI_structured_pd_node_pathWalk(pads,(PDCI_structured_pd *)pd,path,pd_out,rep_out);
      break;
    } /* end switch */
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define STR_NODE_PATH_WALK_RET()
res
/* END_MACRO */

#define NODE_PW_CASE(fieldNumIN,fieldTy,fieldNameIN)
    case fieldNumIN:
      res = fieldTy ## _node_pathWalk(pads,&(m->fieldNameIN),&(pd->fieldNameIN),&(rep->fieldNameIN),path,m_out,pd_out,rep_out);      
      break
/* END_MACRO */

/******* Array macros ******/

#define ARR_LENGTH(ty) (2 + ((ty *)self->rep)->length)

#define ARR_NODE_KTH_CHILD_BODY(ty,childTy)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  ty ## _pd *pd=(ty ## _pd *) (self->pd);
  ty ## _m *m=(ty ## _m *) (self->m);

/* error(2, PDCI_MacroArg2String(ty)"_node_kthChild\n"); */
  if (idx < rep-> length) { /* indexes between 0 and rep->length belong to elements */
      result = childTy ## _node_new(self,"elt",&(m->element),&(pd->elts)[idx],&(rep->elts)[idx],"element",
 				    PDCI_MacroArg2String(ty)"_node_kthChild");
  } else if (idx == rep->length) { /* index of rep->length indicates length */
      result = Puint32_val_node_new(self,"length",pd,&(rep->length),
	 			    PDCI_LENGTH_OFF,
				    PDCI_MacroArg2String(ty) "_node_kthChild");
  } else if (idx == rep->length+1) {  /* index of rep->length indicates parse descriptor */
    if (pd->nerr > 0)
      result = PDCI_sequenced_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_node_kthChild");
  } /* otherwise, an illegal child was requested */

/* END_MACRO */

#define ARR_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

/* Mary: This code must align with kth_child, above.  All array <elt>
   elements come first, followed by the <pd> element, followed by the
   <length> element.
*/
#define ARR_NODE_KTH_CHILD_NAMED_BODY(ty)
  PDCI_childIndex_t k = 0;
  ty *rep=(ty *) (self->rep);

/* error(2, PDCI_MacroArg2String(ty)"_sndNode_kthChildNamed\n"); */
  if (GLX_STR_MATCH(name,"elt")) {
    k = idx;
  } else if (GLX_STR_MATCH(name,"length")){
    if (idx == 0) k = rep->length;
    else return 0;
  } else if (GLX_STR_MATCH(name,"pd")){
    if (idx == 0) k = rep->length + 1;
    else return 0;
  } else return 0;
/* END_MACRO */

#define ARR_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,k);
/* END_MACRO */

/* Mary: This code must align with ARR_NODE_KTH_CHILD_BODY, above.  All array <elt>
   elements come first, followed by the <pd> element, followed by the
   <length> element.
*/
#define ARR_SND_NODE_KTH_CHILD_BODY(ty,childTy)
  PDCI_node_t *result = 0;
  ty *rep;
  ty ## _pd *pd;
  ty ## _m *m;

/* error(2, PDCI_MacroArg2String(ty)"_sndNode_kthChild [%d]\n", idx); */
  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (ty ## _pd *) (self->pd);
  m=(ty ## _m *) (self->m);

  if (idx < rep-> length) { /* indexes between 0 and rep->length belong to elements */
    result = childTy ## _node_new(self,"elt",&(m->element),&(pd->elts)[idx],&(rep->elts)[idx],"element",
				  PDCI_MacroArg2String(ty)"_sndNode_kthChild");
    childTy ## _sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);

  } else if (idx == rep->length) { /* index of rep->length+1 indicates length */
    result = Puint32_val_node_new(self,"length",pd,&(rep->length),
				  PDCI_LENGTH_OFF,
				  PDCI_MacroArg2String(ty) "_sndNode_kthChild");
    Puint32_val_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
  } else if (idx == rep->length + 1) {  /* index of rep->length indicates parse descriptor */
    if (pd->nerr > 0) { 
      /* parse descriptor child */
      result = PDCI_sequenced_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_sndNode_kthChild");
      PDCI_sequenced_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    }
  } /* otherwise, an illegal child was requested */

/* END_MACRO */

#define ARR_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

/* Mary: This code must align with ARR_NODE_KTH_CHILD_BODY, above.  All array <elt>
   elements come first, followed by the <pd> element, followed by the
   <length> element.
*/
#define ARR_NODE_PATH_WALK_BODY(childTy)
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    if (idx < rep-> length) { /* indexes between 0 and rep->length belong to elements */
      res = childTy ## _node_pathWalk(pads,&(m->element),&(pd->elts)[idx],&(rep->elts)[idx],
				      path,m_out,pd_out,rep_out);
    } else if (idx == rep->length) { /* index of rep->length+1 indicates length */
      *m_out = NULL;
      res = Puint32_val_node_pathWalk(pads,(Pbase_pd *)pd,&(rep->length),path,pd_out,rep_out);      
    } else if (idx == rep->length + 1) {  /* index of rep->length indicates parse descriptor */
      *m_out = NULL;
      res = PDCI_sequenced_pd_node_pathWalk(pads,(PDCI_sequenced_pd *)pd,path,pd_out,rep_out);
    }
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define ARR_NODE_PATH_WALK_RET()
res
/* END_MACRO */

/******* Recursive-type macros ******/

#define REC_NODE_NEW_BODY(ty,baseTy)
  PDCI_node_t *result = baseTy ## _node_new(parent,name,*(ty ## _m *)m,((ty ## _pd *)pd)->val,*(ty *)rep,kind,PDCI_MacroArg2String(ty) "_node_new");
/* END_MACRO */

/* Rec. node kthChild function */
#define REC_NODE_KTH_CHILD_BODY(ty,baseTy)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  ty ## _pd *pd=(ty ## _pd *) (self->pd);
  ty ## _m *m=(ty ## _m *) (self->m);

  if (idx == 0){
    result = baseTy ## _node_new(self,"impl",
				  *m,
				  pd->val,
				  *rep,
				  "element", PDCI_MacroArg2String(ty) "_node_kthChild");
  }
/* END_MACRO */

#define REC_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define REC_NODE_KTH_CHILD_NAMED_BODY()
  PDCI_childIndex_t k = 0;
  
  /* The index must be 0 as all field names are unique.*/
  if (idx != 0)
    return 0;
  
  if (GLX_STR_MATCH(name,"impl")) {k = 0;}
  else return 0;
/* END_MACRO */

#define REC_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,k);
/* END_MACRO */

/* Rec. snd node kthChild function */
#define REC_SND_NODE_KTH_CHILD_BODY(ty,baseTy)
  PDCI_node_t *result = 0;
  ty *rep;
  ty ## _pd *pd;
  ty ## _m *m;

  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (ty ## _pd *) (self->pd);
  m=(ty ## _m *) (self->m);

  if (idx == 0){
    result = baseTy ## _node_new(self,"impl",
				  *m,
				  pd->val,
				  *rep,
				  "element", PDCI_MacroArg2String(ty) "_node_kthChild");
    baseTy ## _sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
  }
/* END_MACRO */

#define REC_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define REC_NODE_PATH_WALK_BODY(baseTy)
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    if (idx == 0){
      res = baseTy ## _node_pathWalk(pads,*m,pd->val,*rep,path,m_out,pd_out,rep_out);
    }
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define REC_NODE_PATH_WALK_RET()
res
/* END_MACRO */

/******* Typedef macros ******/

/* Typedef node kthChild function */
#define TYP_NODE_KTH_CHILD_BODY(ty,baseTy)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  ty ## _pd *pd=(ty ## _pd *) (self->pd);
/*  ty ## _m *m=(ty ## _m *) (self->m); */

  switch(idx){
  case 0:
    result = baseTy ## _val_node_new(self, "val",  pd, rep, PDCI_VAL_OFF, 
				 PDCI_MacroArg2String(ty) "_node_kthChild");
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0)
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_node_kthChild");
    break;
  }
/* END_MACRO */

#define TYP_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define TYP_NODE_KTH_CHILD_NAMED_BODY()
  PDCI_childIndex_t k = 0;
  
  /* The index must be 0 as all field names are unique.*/
  if (idx != 0)
    return 0;
  
  if (GLX_STR_MATCH(name,"val")) {k = 0;}
/*  if (GLX_STR_MATCH(name,"base")) {k = 0;} */
  else if (GLX_STR_MATCH(name,"pd")) {k = 1;}
  else return 0;
/* END_MACRO */

#define TYP_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,k);
/* END_MACRO */

/* Typedef snd node kthChild function */
#define TYP_SND_NODE_KTH_CHILD_BODY(ty,baseTy)
  PDCI_node_t *result = 0;
  ty *rep;
  ty ## _pd *pd;
  ty ## _m *m;

  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (ty ## _pd *) (self->pd);
  m=(ty ## _m *) (self->m);

  switch(idx){
  case 0:
    result = baseTy ## _val_node_new(self, "val",  pd, rep, PDCI_VAL_OFF, 
				  PDCI_MacroArg2String(ty) "_sndNode_kthChild");
    baseTy ## _val_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);

    /*    result = baseTy ## _node_new(self,"base",&(m->base),pd,rep,
				 "element", PDCI_MacroArg2String(ty) "_sndNode_kthChild");
    baseTy ## _sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    */
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0) { 
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_sndNode_kthChild");
      PDCI_structured_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    }
    break;
  }
/* END_MACRO */

#define TYP_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define TYP_NODE_PATH_WALK_BODY(baseTy, mask)
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    switch(idx){
    case 0: 
      res = baseTy ## _node_pathWalk(pads,mask,pd,rep,path,m_out,pd_out,rep_out);      
      break;
    case 1:
      *m_out = NULL;
      res = PDCI_structured_pd_node_pathWalk(pads,(PDCI_structured_pd *)pd,path,pd_out,rep_out);
      break;
    }
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define TYP_NODE_PATH_WALK_RET()
res
/* END_MACRO */

/******* Union macros ******/

#define UNION_NODE_KTH_CHILD_BODY_BEGIN(ty)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  ty ## _pd *pd=(ty ## _pd *) (self->pd);
  ty ## _m *m=(ty ## _m *) (self->m);
  char const *branch = ty ## _tag2str (rep->tag);

  switch(idx){
  case 0:
    switch (rep->tag){
      case ty ## _err: 
	/* (do nothing) */
	break;
/* END_MACRO */

#define UNION_NODE_KTH_CHILD_BODY_END()
      }  /* end switch (rep->tag) */
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0)
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_node_kthChild");
    break;
  }  /* end switch(idx)*/
/* END_MACRO */

#define UNION_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

/* case for kthChild function */
#define UNION_NODE_KC_CASE(ty,branchTagIN,branchTy)
  case branchTagIN:
    result = branchTy ## _node_new(self,branch,
				   &(m->branchTagIN),&((pd->val).branchTagIN),&((rep->val).branchTagIN),
				  "element", PDCI_MacroArg2String(ty) "_node_kthChild");
    break
/* END_MACRO */

/* case for kthChild function */
#define UNION_NODE_KC_CASE_LITERAL(ty,branchTagIN)
  case branchTagIN:
    result = PDCI_cstr_val_node_new(self,branch,&((pd->val).branchTagIN),(void *)branch, PDCI_VAL_OFF,
				    PDCI_MacroArg2String(ty) "_node_kthChild");
    break
/* END_MACRO */

#define UNION_NODE_KTH_CHILD_NAMED_BODY(ty)
  ty *rep=(ty *) (self->rep);
  char const *branch = ty ## _tag2str (rep->tag);
  PDCI_childIndex_t k = 0;
  
  /* The index must be 0 as all field names are unique.*/
  if (idx != 0)
    return 0;
  
  if(GLX_STR_MATCH(name,branch)) {k = 0;}
  else if (GLX_STR_MATCH(name,"pd")) {k = 1;}
  else return 0;
/* END_MACRO */

#define UNION_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,k)
/* END_MACRO */

#define UNION_SND_NODE_KTH_CHILD_BODY_BEGIN(ty)
  PDCI_node_t *result = 0;
  ty *rep;
  ty ## _pd *pd;
  ty ## _m *m;
  char const *branch;

  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (ty ## _pd *) (self->pd);
  m=(ty ## _m *) (self->m);
  branch = ty ## _tag2str (rep->tag);

  switch(idx){
  case 0:
    switch (rep->tag){
      case ty ## _err: 
	/* (do nothing) */
	break;
/* END_MACRO */

#define UNION_SND_NODE_KTH_CHILD_BODY_END()
    } /* end switch (rep->tag) */
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0) { 
      result = PDCI_structured_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_sndNode_kthChild");
      PDCI_structured_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    }
    break;
  }  /* end switch(idx)*/
/* END_MACRO */

#define UNION_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

/* case for kthChild function */
#define UNION_SND_NODE_KC_CASE(ty,branchTagIN,branchTy)
  case branchTagIN:
    result = branchTy ## _node_new(self,branch,
				   &(m->branchTagIN),&((pd->val).branchTagIN),&((rep->val).branchTagIN),
				  "element", PDCI_MacroArg2String(ty) "_node_kthChild");
    branchTy ## _sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    break;
/* END_MACRO */

/* case for kthChild function */
#define UNION_SND_NODE_KC_CASE_LITERAL(ty,branchTagIN)
  case branchTagIN:
    result = PDCI_cstr_val_node_new(self,branch,&((pd->val).branchTagIN),(void *)branch, PDCI_VAL_OFF,
				    PDCI_MacroArg2String(ty) "_node_kthChild");
    Pbase_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    break;
/* END_MACRO */


#define UNION_NODE_PATH_WALK_BODY_BEGIN(ty)
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    switch(idx){
    case 0: 
      switch (rep->tag){
      case ty ## _err: 
	/*  (do nothing) */
      break;
/* END_MACRO */

#define UNION_NODE_PATH_WALK_BODY_END()
      } /* end switch (rep->tag) */
    break;
    case 1:
      *m_out = NULL;
      res = PDCI_structured_pd_node_pathWalk(pads,(PDCI_structured_pd *)pd,path,pd_out,rep_out);
      break;
    } /* end switch(idx)*/
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define UNION_NODE_PATH_WALK_RET()
res
/* END_MACRO */

#define UNION_NODE_PW_CASE(branchTagIN,branchTy)
      case branchTagIN:
	res = branchTy ## _node_pathWalk(pads,&(m->branchTagIN),
					 &((pd->val).branchTagIN),
					 &((rep->val).branchTagIN),
					 path,m_out,pd_out,rep_out);      
       break;
/* END_MACRO */

#define UNION_NODE_PW_CASE_LITERAL(ty, branchTagIN)
      case branchTagIN:
	res = PDCI_cstr_val_node_pathWalk(pads,
					  &((pd->val).branchTagIN),
					  (void *)ty ## _tag2str(rep->tag),
					  path,pd_out,rep_out);      
       break;
/* END_MACRO */

/******* Enum macros ******/

/* Enum node kthChild function */
#define ENUM_NODE_KTH_CHILD_BODY(ty, rep2str_fn)
  PDCI_node_t *result = 0;
  ty *rep=(ty *) (self->rep);
  Pbase_pd *pd=(Pbase_pd *) (self->pd);

  Pstring *pstr; 
  RMM_t *memory_mgr;
  RBuf_t *rbuf;

  switch(idx){
  case 0:
    /* string val child */
    /* The XML rep of an ENUM value is its abstract string value, not its internal int rep */
    /* This is an awful lot of overhead to convert a Pint to a Pstring... Is there some other way? */
    memory_mgr = P_rmm_zero(self->pads); 
    rbuf = RMM_new_rbuf(memory_mgr);
    RBuf_RESERVE(rbuf, pstr, Pstring, 1);
    P_STRING_INIT_CSTR(*pstr,rep2str_fn(*rep));
    result = Pstring_val_node_new(self, "val",  pd, pstr, PDCI_VAL_OFF, 
				  PDCI_MacroArg2String(ty) "_node_kthChild");
    /*    result = Puint32_val_node_new(self, "val",  pd, rep, PDCI_VAL_OFF, 
	  PDCI_MacroArg2String(ty) "_node_kthChild"); */
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0) 
      result = Pbase_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_node_kthChild");
    break;
  }
/* END_MACRO */

#define ENUM_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define ENUM_NODE_KTH_CHILD_NAMED_BODY()
  PDCI_childIndex_t k = 0;
  
  /* The index must be 0 as all field names are unique.*/
  if (idx != 0)
    return 0;
  
  if (GLX_STR_MATCH(name,"val"))  {k = 0;}
  else if (GLX_STR_MATCH(name,"pd")) {k = 1;}
  else return 0;
/* END_MACRO */

#define ENUM_NODE_KTH_CHILD_NAMED_RET()
(self->vt->kth_child)(self,k);
/* END_MACRO */

/* Enum snd node kthChild function */
#define ENUM_SND_NODE_KTH_CHILD_BODY(ty, rep2str_fn)
  PDCI_node_t *result = 0;
  ty *rep;
  Pbase_pd *pd;

  Pstring *pstr; 
  RMM_t *memory_mgr;
  RBuf_t *rbuf;

  /* Make sure that the node is valid before attempting to access its contents. */ 
  PDCI_sndNode_validate(self);
  rep = (ty *) (self->rep);
  pd = (Pbase_pd *) (self->pd);
  switch(idx){
  case 0:
    /* The XML rep of an ENUM value is its abstract string value, not its internal int rep */
    /* This is an awful lot of overhead to convert a Pint to a Pstring... Is there some other way? */
    memory_mgr = P_rmm_zero(self->pads); 
    rbuf = RMM_new_rbuf(memory_mgr);
    RBuf_RESERVE(rbuf, pstr, Pstring, 1);
    P_STRING_INIT_CSTR(*pstr,rep2str_fn(*rep));
    result = Pstring_val_node_new(self, "val",  pd, pstr, PDCI_VAL_OFF, 
				  PDCI_MacroArg2String(ty) "_node_kthChild");
    Pstring_val_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);

    /*
    result = Puint32_val_node_new(self, "val",  pd, rep, PDCI_VAL_OFF, 
				  PDCI_MacroArg2String(ty) "_sndNode_kthChild");
    Puint32_val_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    */
    break;
  case 1:
    /* parse descriptor child */
    if (pd->nerr > 0) { 
      result = Pbase_pd_node_new(self,"pd",pd,PDCI_MacroArg2String(ty) "_sndNode_kthChild");
      Pbase_pd_sndNode_init(result,self->manager,self->ancestor_idx,self->ptr_gen,idx);
    }
    break;
  }
/* END_MACRO */

#define ENUM_SND_NODE_KTH_CHILD_RET()
result
/* END_MACRO */

#define ENUM_NODE_PATH_WALK_BODY(ty)
  Perror_t res = P_ERR;
  PDCI_childIndex_t idx;
  char *cstr;
  
  if (path.length > 0){
    /* modifies path */
    idx = PDCI_PATH_GET(path);

    switch(idx){
    case 0: 
      cstr = ((char *) ty ## 2str (*rep));
      *m_out = NULL;
      res = PDCI_cstr_val_node_pathWalk(pads,(Pbase_pd *)pd,cstr,path,pd_out,rep_out);      
      break;
    case 1:
      *m_out = NULL;
      res = Pbase_pd_node_pathWalk(pads,pd,path,pd_out,rep_out);
      break;
    }
  }else{
    *rep_out = rep;
    *pd_out = pd;
    *m_out = m;

    res = P_OK;
  }
/* END MACRO */

#define ENUM_NODE_PATH_WALK_RET()
res
/* END_MACRO */

/********************************************
 *   Smart node macros. 
 ********************************************/

/*
 * Reserves at least live_count+1 reps and pds.
 */ 
#define SN_ELT_ALLOC_FROM_RBUF_BODY(ty,eltTy, eltPdTy,smartNodeIN,padsIN,elt_pdIN,elt_repIN)
  PDCI_smart_node_t *sn  = (smartNodeIN)->snExt;
  PDCI_smart_array_info_t 
    *arrayInfo  = (PDCI_smart_array_info_t *)sn->elt_state;
  ty          *rep  = (ty *)(smartNodeIN)->rep;
  ty ## _pd   *pd  = (ty ## _pd *)(smartNodeIN)->pd;

  if (0 != RBuf_RESERVE_HINT(rep->_internal, rep->elts, eltTy, arrayInfo->live_count+1, arrayInfo->max_elts)) 
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement",0);
    }
  if (0 != RBuf_RESERVE_HINT(pd->_internal, pd->elts, eltPdTy, arrayInfo->live_count+1,  arrayInfo->max_elts)) 
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement",0);
    }
  if (0 != RBuf_RESERVE_HINT(arrayInfo->_internal_live,arrayInfo->liveList,
			     PDCI_childIndex_t, arrayInfo->live_count+1, arrayInfo->max_elts)) 
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement",0);
    }
  *(elt_pdIN) = &pd->elts[arrayInfo->live_count];
  *(elt_repIN) = &rep->elts[arrayInfo->live_count];
/* END_MACRO */

#define SN_ELT_ALLOC_FROM_RBUF_RET()
P_OK;
/* END_MACRO */

/*
 * Allocates individual elements.
 * Reserves additional space in the liveList.
 */
#define SN_ELT_ALLOC_BODY(ty,eltTy, eltPdTy,smartNodeIN,padsIN,elt_pdIN,elt_repIN)
  PDCI_smart_node_t *sn  = (smartNodeIN)->snExt;
  PDCI_smart_array_info_t 
    *arrayInfo  = (PDCI_smart_array_info_t *)sn->elt_state;

  *(elt_pdIN) = calloc(1,sizeof(eltPdTy));

  if (0 == *(elt_pdIN))
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement", "smart-node element PD allocation failed");
    }
  if (P_ERR == eltPdTy ## _init((padsIN), *(elt_pdIN))) {
    PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_SYS_ERR,#ty "_smartNode_allocElement", 0);
  }

  *(elt_repIN) = calloc(1,sizeof(eltTy));
  if (0 == *(elt_repIN))
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement", "smart-node element allocation failed");
    }
  if (P_ERR == eltTy ## _init((padsIN), *(elt_repIN))) {
    PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_SYS_ERR,#ty "_smartNode_allocElement",0);
  }

  if (0 != RBuf_RESERVE_HINT(arrayInfo->_internal_live, arrayInfo->liveList,
			     PDCI_childIndex_t, arrayInfo->live_count+1,
			     arrayInfo->max_elts)) 
    {
      PGLX_report_err ((padsIN),P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_smartNode_allocElement",0);
    }
/* END_MACRO */

#define SN_ELT_ALLOC_RET()
P_OK;
/* END_MACRO */

/* 
 *  Generated code should use this call to access read_one parameters.
 */
#define SN_RO_PARAM(p) ro_params->p

/* 
 *  Wrap a the variable parameter list in parens. The list can then be passed
 *  as a whole to macros without being interpereted as multiple parameters.
 *  Then, within the macro, we can pass these arguments to a macro or function 
 *  without parens around them. For example, see how we use SN_INS_PARAMS in ELT_READ.
 *  Note: we throw away parameter x. It's there merely so that the Ckit 
 *  declaration can type-check.
 */
#define SN_WRAP_PARAMS(x,...) (__VA_ARGS__)

#define SN_INS_PARAMS(...) , ## __VA_ARGS__

/* 
 * For successful reads, returns P_READ_OK_DATA.
 * For reads that fail because the index is too large, returns P_READ_OK_NO_DATA.
 * For errors, an appropriate error code is returned.
 *  
 * Currently, only reads sequentially.  Also, for new elements
 * (i.e. being read for the first time) this function fills in their
 * offset field.
 *
 * Parameters ST_PARAMS and C_PARAMS should be parenthesized, 
 * comma-seperated lists of arguments. For example, if there are no sep/term arguments:
 *   SN_SEQ_ELT_READ_BODY(ty,eltTy,eltPdTy,smartNode,pads,info,(),(c_params))
 * For example, with two arguments:
 *   SN_SEQ_ELT_READ_BODY(ty,eltTy,eltPdTy,smartNode,pads,info,(separator_regexp_ptr,terminator_regexp_ptr),(c_params))
 *
 * N.B. We are *not* guaranteed to be at the head of the io stream on entry/exit to/from this function.
 *      We chose not to enforce such a property so that we can efficiently reread sequentially.
 *      Otherwise, after each reread we would have to return to the head of the stream, which is
 *      inefficient if the next reread will continue where the previous left off.
 */
#define SN_ELT_READ_BODY(ty,eltTy,eltPdTy,smartNodeIN,padsIN,infoIN,C_PARAMS,ST_PARAMS)
  PDCI_IODISC_2P_CHECKS (#ty "_smartNode_eltRead",(smartNodeIN),(infoIN));
  {
    PDCI_smart_node_t *sn  = (smartNodeIN)->snExt;

    ty ## _array_info_t            *tai       = (ty ## _array_info_t *)sn->elt_state;
    PDCI_smart_array_info_t  *arrayInfo = &(tai->base);
    ty ## _ro_params_t       *ro_params = &(tai->params);

    ty          *rep  = (ty *)(smartNodeIN)->rep;
    ty ## _pd   *pd  = (ty ## _pd *)(smartNodeIN)->pd;
    ty ## _m    *m   = (ty ## _m *)(smartNodeIN)->m;
    eltTy     *elt_rep;
    eltPdTy   *elt_pd;
    PDCI_childIndex_t  virtIdx = (infoIN)->idx;
    
    Pread_res_t res;
    Sfoff_t begin_offset;
    
    /* are we trying to read ahead in a completed array? */
    if (!P_PS_isPartial(pd) && virtIdx >= arrayInfo->next_idx_read){
      return P_READ_OK_NO_DATA;
    }

    /*  are we trying to read more than one ahead? 
    if (virtIdx > arrayInfo->next_idx_read){
      return P_READ_OK_NO_DATA;
    }
    */
    
    if (P_ERR == P_sn_getFreeElt((smartNodeIN),(padsIN),(void **)&elt_pd,(void **)&elt_rep)){
      /*  There's a bug somewhere. There should always be  */
      /*  an element available. */
      return P_READ_FAILURE;
    }
    
    if (P_ERR == P_sn_markElementLive((PDCI_smart_array_info_t *)arrayInfo,virtIdx,elt_pd,elt_rep)){
      /*  There's a bug somewhere, so indicate failure. */
      return P_READ_FAILURE;
    }

    PDCI_ALWAYS_GETOFFSET((padsIN),begin_offset);

    PDCI_ID_RESET((padsIN),0);

    /*  are we trying to reread an earlier element? */
    if (virtIdx < arrayInfo->next_idx_read){
      /*  should we seek? */
      if (begin_offset != (infoIN)->offset){
	
	/*  seek to (infoIN)->offset. */
	if (P_io_seek((padsIN),(infoIN)->offset) == P_ERR){
	  /* sn->handle_failure((padsIN),sn,(infoIN),ERROR_FATAL, "*** failure in " #ty "_smartNode_eltRead" ": seek failed ***");          */
	  return P_READ_FAILURE;
	}
	
      }

      res = ty ## _reread_one((padsIN),m 
				SN_INS_PARAMS C_PARAMS,
				pd,rep,
				&SN_RO_PARAM(beginLoc),
				elt_pd,elt_rep,
				virtIdx != 0
			        SN_INS_PARAMS ST_PARAMS);

      if (res != P_READ_OK_DATA){
	PGLX_report_err((padsIN),P_LEV_WARN,0, P_IO_ERR,
		  #ty "_smartNode_eltRead","Reread failed at offset %ld.",(infoIN)->offset);
	return res;
      }
    
      /*  did we seek? */
      if (begin_offset != (infoIN)->offset){
	/*  are we still reading the array? */
	if (P_PS_isPartial(pd)){

	  /*  INV: if the current offset >= nextOffset then the current */
	  /*  offset is the farthest point in the stream that we've */
	  /*  read (the head of the stream).  Otherwise nextOffset is */
	  /*  the head of the stream.   */

	  /*  Therefore, if we're at the head of the stream and we're */
	  /*  seeking backwards, then we must save the offset of the */
	  /*  head in nextOffset. */

	  /*  are we at the head of the stream? */
	  if (begin_offset > arrayInfo -> next_offset){
	    arrayInfo->next_offset = begin_offset;
	  }
	}else{
	  /*  We are no longer reading the array. Therefore, we must */
	  /*  return the io stream to its former position so that other */
	  /*  pads read calls can proceed as normal. */

	  /*  seek to previous offset. */
	  if (P_ERR == P_io_seek((padsIN),begin_offset)){
	    /* sn->handle_failure(pads,sn,(infoIN),ERROR_FATAL, "*** failure in " #ty "_smartNode_eltRead" ": seek failed ***");   */
	    /*
	     * Although the data is in fact valid, 
	     * we return failure due to the severity
	     * of the error.
	     */
	    return P_READ_FAILURE;
	  }
	}
      }

      return P_READ_OK_DATA;
    }

    /* Are we at the head of the stream? */
    if (arrayInfo->next_offset > begin_offset){
      /*  seek to arrayInfo -> next_offset. */
      if (P_io_seek((padsIN),arrayInfo->next_offset) == P_ERR){
	return P_READ_FAILURE;
      }
      /* set begin_offset to the current offset. */
      begin_offset = arrayInfo->next_offset;
    }
    
    /* Read until we find the desired element, hit an error, or finish the array. */
    do { 
       /* Read until we find an element, hit an error, or finish the array */
       do{
	 res = ty ## _read_one((padsIN),m
			       SN_INS_PARAMS C_PARAMS,
			       pd,rep,
			       &SN_RO_PARAM(beginLoc),
			       elt_pd,elt_rep
			       SN_INS_PARAMS ST_PARAMS);
       }while(res == P_READ_OK_NO_DATA && P_PS_isPartial(pd));
       
       if (P_READ_OK_DATA != res){
	 return res;
       }
       
       arrayInfo->tmap[arrayInfo->next_idx_read].offset = begin_offset;
       arrayInfo->next_idx_read++;       

       PDCI_ALWAYS_GETOFFSET((padsIN),begin_offset);       
       PDCI_ID_RESET((padsIN),0);
     }while (P_PS_isPartial(pd) && virtIdx >= arrayInfo->next_idx_read);
     
    if (virtIdx >= arrayInfo->next_idx_read){
      /*  Array ended before virtIdx was reached. */
      return P_READ_OK_NO_DATA;
    }

    (infoIN)->rep = elt_rep;
    (infoIN)->pd = elt_pd;
  }  
/* END_MACRO */

#define SN_ELT_READ_RET() P_READ_OK_DATA

/*
 * The current implementation just recycles memory, never freeing it
 * back to the system. So, eltFree is just a  no-op.
 */
#define SN_ELT_FREE_BODY(ty,padsIN,infoIN)  /* no-op */
#define SN_ELT_FREE_RET()  P_OK

#define SN_ELT_PATH_WALK_BODY(ty,eltTy,eltPdTy,eltMaskTy,padsIN,mIN,pdIN,repIN,pathIN,m_outIN,pd_outIN,rep_outIN)
  eltTy    *c_rep = (eltTy *)(repIN);
  eltPdTy  *c_pd  = (eltPdTy *)(pdIN);
  eltMaskTy  *c_m   = (eltMaskTy *)(mIN);
/* END_MACRO */

#define SN_ELT_PATH_WALK_RET(eltTy,padsIN,pathIN,m_outIN,pd_outIN,rep_outIN)
eltTy ## _node_pathWalk((padsIN),c_m,c_pd,c_rep,(pathIN),(m_outIN),(pd_outIN),(rep_outIN))
/* END_MACRO */

/* Use when a type has no additional intialization to do in SN_ARRAY_INFO_INIT. 
 * For example,
 *       SN_ARRAY_INFO_INIT(fooType, SN_NO_OP_INIT);
 */
#define SN_NO_OP_INIT(a)

#define SN_ARRAY_INFO_INIT_BODY(ty,padsIN,max_eltsIN, INIT_C_PARAMS)
  PDCI_smart_array_info_t   *arrayInfo =
    PDCI_makeSmartArrayInfo((padsIN),(max_eltsIN),sizeof(ty ## _array_info_t));
  ty ## _ro_params_t *ro_params = &((ty ## _array_info_t *)arrayInfo)->params;

  ty ## _ro_params_init(ro_params SN_INS_PARAMS INIT_C_PARAMS);
/* END_MACRO */

#define SN_ARRAY_INFO_INIT_RET() arrayInfo

#define SN_GENERIC_INIT_BODY(initKind,ty,selfIN,max_eltsIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS)
  P_t               *pads = (selfIN)->pads;
  ty              *rep = (ty  *)(selfIN)->rep;
  ty ## _pd       *pd  = (ty ## _pd *)(selfIN)->pd;
  ty ## _m        *m   = (ty ## _m *) (selfIN)->m;
  
  ty ## _array_info_t            *tai;
  PDCI_smart_array_info_t  *arrayInfo;
  ty ## _ro_params_t       *ro_params;

  /*  Setup the virtual table */
  (selfIN)->vt  = & ty ## _ ## initKind ## _vtable;

  tai = (ty ## _array_info_t *)ty ## _array_info_init(pads,(max_eltsIN)
						      SN_INS_PARAMS INIT_C_PARAMS);

  arrayInfo = &(tai->base);
  ro_params = &(tai->params);

  ty ## _read_one_init(pads, m 
                       SN_INS_PARAMS C_PARAMS,
		       pd, rep, &SN_RO_PARAM(beginLoc)
		       SN_INS_PARAMS ST_PARAMS);

  PDCI_MK_SMART_NODE((selfIN)->snExt,pads,
		     ty ## _ ## initKind ## _eltRead,
		     ty ## _smartNode_eltAlloc,
		     ty ## _ ## initKind ## _eltFree,
		     ty ## _smartNode_eltPathWalk,
		     P_sn_handleFailure,
		     arrayInfo,#ty "_" #initKind "_init");    
/* END_MACRO */

#define SN_INIT_BODY(ty,selfIN,max_eltsIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS)
SN_GENERIC_INIT_BODY(smartNode,ty,selfIN,max_eltsIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS);
/* END_MACRO */

#define SN_INIT_RET(selfIN) (selfIN)

/* Sequential version of smartNode_init */
#define SN_SEQ_INIT_BODY(ty,selfIN,max_eltsIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS)
SN_GENERIC_INIT_BODY(seqSmartNode,ty,selfIN,max_eltsIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS);
/* END_MACRO */

#define SN_SEQ_INIT_RET(selfIN) (selfIN)

#define SN_KTH_CHILD_BODY(ty,eltTy,selfIN,idxIN)
  ty        *rep=(ty *) ((selfIN)->rep);
  ty ## _pd *pd=(ty ## _pd *) ((selfIN)->pd);
  ty ## _m *m=(ty ## _m *) ((selfIN)->m);  
  PDCI_node_t *result = 0;
  Pread_res_t res = P_READ_ERR;
  PDCI_smart_node_t *sn = (selfIN)->snExt;  
  PDCI_smart_array_info_t *arrayInfo = (PDCI_smart_array_info_t *)sn->elt_state;
  
  /* length field */
  if (!P_PS_isPartial(pd) && (idxIN) == arrayInfo->next_idx_read){
    return Puint32_val_node_new((selfIN),"length",pd,&arrayInfo->next_idx_read,
				  PDCI_LENGTH_OFF,
				    #ty "_smartNode_kthChild");
  }
  /*  parse descriptor child */
  if (!P_PS_isPartial(pd) && (idxIN) == arrayInfo->next_idx_read + 1){
    if (pd->nerr > 0) 
      return PDCI_sequenced_pd_node_new((selfIN),"pd",pd,#ty "_smartNode_kthChild");
    else 
      return 0;
  }

  if (!P_PS_isPartial(pd) && (idxIN) >= arrayInfo->next_idx_read + 2){
   return 0;
  }

  /* check whether element[(idxIN)] has been created.
   * if not, create it and read an element.
   */
  if ((idxIN) >= arrayInfo->next_idx_create)
  {
    PDCI_childIndex_t i = arrayInfo->next_idx_create;
    
    /* Grow the buffer to the needed size. */
    if (0 != RBuf_RESERVE_HINT(arrayInfo->_internal, arrayInfo->tmap,
			       PDCI_smart_elt_info_t, (idxIN)+1, 0)) 
      {
	PGLX_report_err ((selfIN)->pads,P_LEV_FATAL,0,P_ALLOC_ERR,
                          #ty "_smartNode_kthChild",0);
	return 0; /* Never reached. */
      }


    /* Initialize the element info, for all new elements. */
    for(;i<=(idxIN);i++){
      PDCI_INIT_SMART_ELT(arrayInfo->tmap[i],(selfIN),i,0,0,
			  NULL,NULL,&m->element);
      
    }
    
    arrayInfo->next_idx_create = (idxIN) + 1;

    /* Attempt to read the element(s).*/
    res = sn->elt_read((selfIN), (selfIN)->pads, &arrayInfo->tmap[(idxIN)]);

    /* Did the array terminate without yielding another element? */
    if (!P_PS_isPartial(pd) && P_READ_OK_NO_DATA == res){
      PDCI_childIndex_t i = (idxIN) - arrayInfo->next_idx_read;
      switch(i){
      case 0:    /* length field */
	return Puint32_val_node_new((selfIN),"length",pd,&rep->length,
				    PDCI_LENGTH_OFF, #ty "_smartNode_kthChild");
      case 1:    /*  parse descriptor child */
	if (pd->nerr > 0)
	  return PDCI_sequenced_pd_node_new((selfIN),"pd",pd,#ty "_smartNode_kthChild");
	else 
	  return 0;
      default:
	return 0;
      }
    }

    /* Was there an error? */
    if (P_READ_OK_DATA != res){
      PGLX_report_err((selfIN)->pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,#ty "_smartNode_kthChildNamed",
			"Element read failure due to error.");
      return 0; 
    }

    /* Otherwise, we successfully read an element */
  }
  result = eltTy ## _node_new((selfIN),"elt",&(m->element),
			      arrayInfo->tmap[(idxIN)].pd,arrayInfo->tmap[(idxIN)].rep,
			      "element",#ty "_smartNode_kthChild");
  eltTy ## _sndNode_init(result,sn,(idxIN),arrayInfo->tmap[(idxIN)].gen, (idxIN));
/* END_MACRO */

#define SN_KTH_CHILD_RET() result

#define SN_KTH_CHILD_NAMED_BODY(ty,selfIN,kthIN,nameIN)
  ty *rep=(ty *) ((selfIN)->rep);
  ty ## _pd *pd=(ty ## _pd *) ((selfIN)->pd);
  PDCI_node_t *result = 0;
  PDCI_smart_node_t *sn = (selfIN)->snExt;  
  PDCI_smart_array_info_t *arrayInfo = (PDCI_smart_array_info_t *)sn->elt_state;

  if (GLX_STR_MATCH((nameIN),"pd") ||
      GLX_STR_MATCH((nameIN),"length"))
  {
    /* There's only one pd/length field, so k must be zero*/
    if((kthIN) != 0)      
      return 0;

    if (P_PS_isPartial(pd)){
      /* 
       * Force the entire array to be read. 
       *
       * **Very inefficient**. This functionality 
       * should be pushed into kthChild or eltRead.
       */
      do{
	result = ((selfIN)->vt->kth_child)((selfIN),arrayInfo->next_idx_read);
      } while(result != 0 && P_PS_isPartial(pd));

      /* The array should no longer be partial.
       * If it is, then either the array is absurdly
       * large, or something is wrong.
       */
      if (P_PS_isPartial(pd)){
	PGLX_report_err((selfIN)->pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,#ty "_smartNode_kthChildNamed",
			"Array size meets or exceeds PDCI_MAX_CHILD_INDEX.");
	return 0;
      }
    }

    switch((nameIN)[0]){
    case 'l':
      result = ((selfIN)->vt->kth_child)((selfIN),rep->length);
      break;
    case 'p':
      result = ((selfIN)->vt->kth_child)((selfIN),rep->length + 1);
      break;
    }
  }else if(GLX_STR_MATCH((nameIN),"elt"))  
    result = ((selfIN)->vt->kth_child)((selfIN),(kthIN));
  else result = 0;

/* END_MACRO */

#define SN_KTH_CHILD_NAMED_RET() result

/******* Linear-node macros ******/

#define LN_INIT_BODY(ty,elRepTy,elPdTy,selfIN, INIT_C_PARAMS, ST_PARAMS,C_PARAMS)
  P_t               *pads = (selfIN)->pads;
  ty              *rep = (ty  *)(selfIN)->rep;
  ty ## _pd       *pd  = (ty ## _pd *)(selfIN)->pd;
  ty ## _m        *m   = (ty ## _m *) (selfIN)->m;
  
  ty ## _ro_params_t       *ro_params;

  /*  Setup the virtual table */
  (selfIN)->vt  = & ty ## _linearNode_vtable;

  /* Allocate read_one parameter struct. */
  ro_params = (ty ## _ro_params_t *) calloc(1,sizeof(ty ## _ro_params_t));
  ty ## _ro_params_init(ro_params SN_INS_PARAMS INIT_C_PARAMS);

  ty ## _read_one_init(pads, m 
                       SN_INS_PARAMS C_PARAMS,
		       pd, rep, &SN_RO_PARAM(beginLoc)
		       SN_INS_PARAMS ST_PARAMS);

  /* Reserve space for one element*/
  PCGEN_ARRAY_RESERVE_SPACE (ty,elRepTy,elPdTy,0);
  PDCI_MK_LINEAR_NODE((selfIN)->lnExt,pads,
                      &(m->element),&(pd->elts[0]),&(rep->elts[0]),
		      ro_params,
		      #ty "_linearNode_init");    
/* END_MACRO */

#define LN_INIT_RET(selfIN) (selfIN)

#define LN_KTH_CHILD_BODY(ty,eltTy,selfIN,idxIN, ST_PARAMS,C_PARAMS)
  P_t               *pads = (selfIN)->pads;
  ty        *rep=(ty *) ((selfIN)->rep);
  ty ## _pd *pd=(ty ## _pd *) ((selfIN)->pd);
  ty ## _m *m=(ty ## _m *) ((selfIN)->m);  
  PDCI_node_t *result = 0;
  Pread_res_t res = P_READ_ERR;
  PDCI_linear_node_t *ln = (selfIN)->lnExt;  
  ty ## _ro_params_t *ro_params = (ty ## _ro_params_t *)ln->ro_params;  

/*   printf("In ln_kthChild: idxIN = %ld  next_idx_read = %ld\n",(unsigned long)(idxIN), (unsigned long)ln->next_idx_read); */

  /* length field */
  if (!P_PS_isPartial(pd) && (idxIN) == ln->next_idx_read){
    return Puint32_val_node_new((selfIN),"length",pd,&ln->next_idx_read,
				  PDCI_LENGTH_OFF,
				    #ty "_linearNode_kthChild");
  }
  /*  parse descriptor child */
  if (!P_PS_isPartial(pd) && (idxIN) == ln->next_idx_read + 1){
    if (pd->nerr > 0) 
      return PDCI_sequenced_pd_node_new((selfIN),"pd",pd,#ty "_linearNode_kthChild");
    else 
      return 0;
  }

  if (!P_PS_isPartial(pd) && (idxIN) >= ln->next_idx_read + 2){
   return 0;
  }

  /* Is the index before the current element? If so, report error.
     Note: if current element is zero, then idxIN cannot be less as
     both are unsigned values. */
  if (ln->next_idx_read > 0 && (idxIN) < ln-> next_idx_read - 1){
    PGLX_report_err(pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,#ty "_linearNode_kthChildNamed",
		    "Attempt to reverse in linear stream.");
    return 0;
  }

  /* 
   * check whether idxIN has been read.If not, read it.
   */
  if ((idxIN) >= ln->next_idx_read){
    /* Read until we find the desired element, hit an error, or finish the array. */
    do { 
       /* Read until we find an element, hit an error, or finish the array */
       do{
	 res = ty ## _read_one(pads,m
			       SN_INS_PARAMS C_PARAMS,
			       pd,rep,
			       &SN_RO_PARAM(beginLoc),
			       ln->elt_pd,ln->elt_rep
			       SN_INS_PARAMS ST_PARAMS);
       }while(res == P_READ_OK_NO_DATA && P_PS_isPartial(pd));
       
       /* Hit an error or finished array. */
       if (P_READ_OK_DATA != res){
	 break;
       }
       
       ln->next_idx_read++;       

       PDCI_ID_RESET(pads,0);
     }while (P_PS_isPartial(pd) && (idxIN) >= ln->next_idx_read);
     
    /* Was there an error? */
    if (P_READ_OK_DATA != res && P_READ_OK_NO_DATA != res){
      PGLX_report_err(pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,#ty "_linearNode_kthChildNamed",
			"Element read failure due to error.");
      return 0; 
    }

    /* Did the array terminate without reading the desired element
       (yet without an error)? */
    if (!P_PS_isPartial(pd) && (idxIN) >= ln->next_idx_read){
      PDCI_childIndex_t i = (idxIN) - ln->next_idx_read;
      switch(i){
      case 0:    /* length field */
	return Puint32_val_node_new((selfIN),"length",pd,&rep->length,
				    PDCI_LENGTH_OFF, #ty "_linearNode_kthChild");
      case 1:    /*  parse descriptor child */
	if (pd->nerr > 0)
	  return PDCI_sequenced_pd_node_new((selfIN),"pd",pd,#ty "_linearNode_kthChild");
	else 
	  return 0;
      default:
	return 0;
      }
    }

    /* Otherwise, we successfully read the element */
  }
  result = eltTy ## _node_new((selfIN),"elt",&(m->element),
			      ln->elt_pd,ln->elt_rep,
			      "element",#ty "_linearNode_kthChild")
/* END_MACRO */

#define LN_KTH_CHILD_RET() result

#define LN_KTH_CHILD_NAMED_BODY(ty,selfIN,kthIN,nameIN)
  ty *rep=(ty *) ((selfIN)->rep);
  ty ## _pd *pd=(ty ## _pd *) ((selfIN)->pd);
  PDCI_node_t *result = 0;
  PDCI_linear_node_t *ln = (selfIN)->lnExt;  

  if (GLX_STR_MATCH((nameIN),"pd") ||
      GLX_STR_MATCH((nameIN),"length"))
  {
    /* There's only one pd/length field, so k must be zero*/
    if((kthIN) != 0)      
      return 0;

    if (P_PS_isPartial(pd)){
      /* 
       * Force the entire array to be read. 
       *
       * **Very inefficient**. This functionality 
       * should be pushed into kthChild or eltRead.
       */
      do{
	result = ((selfIN)->vt->kth_child)((selfIN),ln->next_idx_read);
      } while(result != 0 && P_PS_isPartial(pd));

      /* The array should no longer be partial.
       * If it is, then either the array is absurdly
       * large, or something is wrong.
       */
      if (P_PS_isPartial(pd)){
	PGLX_report_err((selfIN)->pads,P_LEV_FATAL,0,P_SMART_NODE_ERR,#ty "_linearNode_kthChildNamed",
			"Array size meets or exceeds PDCI_MAX_CHILD_INDEX.");
	return 0;
      }
    }

    switch((nameIN)[0]){
    case 'l':
      result = ((selfIN)->vt->kth_child)((selfIN),rep->length);
      break;
    case 'p':
      result = ((selfIN)->vt->kth_child)((selfIN),rep->length + 1);
      break;
    }
  }else if(GLX_STR_MATCH((nameIN),"elt"))  
    result = ((selfIN)->vt->kth_child)((selfIN),(kthIN));
  else result = 0;

/* END_MACRO */

#define LN_KTH_CHILD_NAMED_RET() result

/* ********************************* BEGIN_TRAILER ******************************** */
/* ********************************** END_MACROS ********************************** */
