(** generation of common PADS-Galax stuff **)

structure GenGalax = struct

  structure PT   = ParseTree     (* the parse tree *)
  structure P    = ParseTreeUtil (* Utility functions for manipulating the parse tree *)
  structure PX   = ParseTreeExt  (* Pads extensions *)
  structure PL   = PLib          (* Information about values/functions available from pads library *)
  structure PN   = PNames

  val m = PN.m
  val pd = PN.pd
  val rep = PN.rep
  val smartNode = PN.smartNode
  val m_out = PN.m_out
  val pd_out = PN.pd_out
  val rep_out = PN.rep_out
  val max_elts = PN.max_elts
  val elt_rep   = PN.elt_rep
  val elt_pd    = PN.elt_pd
  val info = PN.info
  val base = PN.base
  val params = PN.params
  
  
  val kind = "kind"
  val whatfn = "whatfn"
  val result    = "result"

  val self      = "self"
  val parent = "parent"
  val idx       = "idx"  
  val childName = "name"
  val nameStr = childName
  val elt =  "elt"
  val manager = "manager"
  val ancIdx = "ancestor_idx"
  val gen = "gen"
  val path = "path"
  val pads = "pads"

  (* auxiliary functions *)
  fun apply [] x = []
    | apply (f::fs) x = (f x)::(apply fs x)

  fun inc x = x + 1

  fun listOf n = List.tabulate (n, inc)

  (* enumerate should start at zero *)
  fun enumerate xs = ListPair.zip(0 :: listOf ((List.length xs) - 1), xs)

  fun getUniqueTys nil = nil
    | getUniqueTys (fieldTy::fs) = 
      let val utys = getUniqueTys fs
	  fun notIn (fd,nil) = true
	    | notIn (fd,f::fs) = fd <> f andalso notIn (fd,fs)	
      in 
	  if notIn(fieldTy,utys) then fieldTy::utys
	  else utys
      end


  (* header: common declaration part in foo_children function *) 
  fun headerGalaxChildrenFun(nameTy) =
      let val nodeRepTy = PL.nodeT
	  fun varDecl(field, ty) = 
	      let fun typePref n = P.ptrPCT (P.makeTypedefPCT n)		
		  val typeField = typePref ty
	      in P.varDeclS(typeField, field, PT.Cast(typeField, P.fieldX(self, field)))
	      end
      in List.map varDecl (ListPair.zip([PN.rep, PN.pd, PN.m], (apply [PN.repSuf, PN.pdSuf, PN.mSuf] nameTy)))
	 @ [P.varDeclS'(P.ptrPCT (P.ptrPCT nodeRepTy), result)]
      end

  (* header: common declaration part in foo_kth_child function *) 
  fun headerGalaxKthChildFun(nameTy) =
      let val nodeRepTy = PL.nodeT
	  fun varDecl(field, ty) = 
	      let fun typePref n = P.ptrPCT (P.makeTypedefPCT n)		
		  val typeField = typePref ty
	      in P.varDeclS(typeField, field, PT.Cast(typeField, P.fieldX(self, field)))
	      end
      in List.map varDecl (ListPair.zip([PN.rep, PN.pd, PN.m], (apply [PN.repSuf, PN.pdSuf, PN.mSuf] nameTy)))
	 @ [P.varDeclS(P.ptrPCT nodeRepTy, result, P.zero)]
      end

  (* if: common if-then in foo_children function *)
  fun ifGalaxChildren(returnName, number, errorString) =
      [PT.IfThen(P.notX(P.assignX(returnName,
				  PT.Call(PL.PDCI_NEW_NODE_PTR_LIST, 
					  [number]))),		
		 PT.Expr(PT.Call(PT.Id "failwith", [PT.String ("PADS/Galax " ^ errorString)])))]

  (* PDCI_MK_TNODE: common in foo_children function
     Takes a *general* result expression.*)
  fun macroTNodeCallGeneral (returnExpr, structId, valStr, valId, cnvName) = 
      [PT.Expr(PT.Call(PL.PDCI_MK_TNODE,	
		       [returnExpr,
			P.addrX(PT.Id(PN.nodeVTableSuf structId)),
			PT.Id self, 
			PT.String valStr, 
			valId,
			PT.String cnvName]))]

  (* PDCI_MK_TNODE: common in foo_children function *)
  fun macroTNodeCall (returnName, index, structId, valStr, valId, cnvName) = 
      [PT.Expr(PT.Call(PL.PDCI_MK_TNODE,	
		       [P.subX(returnName, index), 
			P.addrX(PT.Id(PN.nodeVTableSuf structId)),
			PT.Id self, 
			PT.String valStr, 
			valId,
			PT.String cnvName]))]

  fun macroTNode (returnName, structId, valStr, valId, cnvName) = 
      (P.mkCommentS "parse descriptor child")
      :: macroTNodeCall(returnName, P.zero, structId, valStr, valId, cnvName)

  fun macroTNodeGeneral (returnName, structId, valStr, valId, cnvName) = 
      (P.mkCommentS "parse descriptor child")
      :: macroTNodeCallGeneral(returnName, structId, valStr, valId, cnvName)

  (* calls PDCI_MK_NODE. Takes a *general* result expression. *)
  fun macroNodeCallGeneral (returnExp, tyField, nameField, getField1, getField2, getField3, nameStruct) = 
      PT.Expr(PT.Call(PL.PDCI_MK_NODE,
		      [returnExp, 
		       P.addrX(PT.Id(PN.nodeVTableSuf tyField)),
		       PT.Id self, 
		       nameField, 
		       getField1, getField2, getField3,
		       PT.String "element",
		       PT.String nameStruct])) 

  (* calls PDCI_MK_NODE. Assumes that result expression is an array element.
	   Therefore, takes array name "returnName" and index "n". common in foo_children function *)
  fun macroNodeCall (returnName, n, tyField, nameField, getField1, getField2, getField3, nameStruct) = 
      macroNodeCallGeneral(P.subX(returnName, n),tyField,nameField,
			   getField1,getField2,getField3,nameStruct)

  (* calls NODE_NEW_BODY macro*)
  fun macroNodeNew(ty) =
		    PT.Expr(PT.Call(PL.NODE_NEW_BODY,
				    [PT.Id ty]))
  (* calls NODE_NEW_RET macro*)
  fun macroNodeNewRet() = PT.Call(PL.NODE_NEW_RET,nil)

  (* calls CACHED_NODE_INIT_BODY macro*)
  fun macroCNInit(ty,numChildrenExpr) =
		    PT.Expr(PT.Call(PL.CACHED_NODE_INIT_BODY,
				    [PT.Id ty, numChildrenExpr]))

  (* calls CACHED_NODE_INIT_RET macro*)
  fun macroCNInitRet() = PT.Call(PL.CACHED_NODE_INIT_RET,nil)

  (* calls CACHED_NODE_INIT_BODY macro*)
  fun macroCNKthChild(ty,numChildrenExpr) =
		    PT.Expr(PT.Call(PL.CACHED_NODE_KTH_CHILD_BODY,
				    [PT.Id ty, numChildrenExpr]))

  (* calls CACHED_NODE_INIT_RET macro*)
  fun macroCNKthChildRet() = PT.Call(PL.CACHED_NODE_KTH_CHILD_RET,nil)

  fun macroSNDInit(ty) = 
      PT.Expr(PT.Call(PL.SND_NODE_INIT_BODY,[PT.Id ty]))
  fun macroSNDInitRet() = 
      PT.Call(PL.SND_NODE_INIT_RET,nil)

  (****  Struct  macros ****)
  fun macroStructKCBegin(ty) =
      PT.Expr(PT.Call(PL.STR_NODE_KTH_CHILD_BODY_BEGIN,
		      [PT.Id ty]))

  fun macroStructKCEnd(pdidx) =
		    PT.Expr(PT.Call(PL.STR_NODE_KTH_CHILD_BODY_END,
				    [P.intX pdidx]))

  fun macroStructKCRet() =
		    PT.Call(PL.STR_NODE_KTH_CHILD_RET,nil)

  fun macroKCCase(ty,n,fieldTy,fieldName) =
      PT.Expr(PT.Call(PL.NODE_KC_CASE,
		      [PT.Id ty,P.intX n,PT.Id fieldTy,PT.Id fieldName]))

  fun makeKCCase name (n, (fieldName, fieldTy, _)) =
      macroKCCase(name,n,fieldTy,fieldName)				      

  fun macroStructKCN(ty,fieldNames) =
      let val fnList = map PT.String fieldNames
      in
	  PT.Expr(PT.Call(PL.STR_NODE_KTH_CHILD_NAMED_BODY,
			  (PT.Id ty) :: fnList))
      end

  fun macroStructKCNRet() =
		    PT.Call(PL.STR_NODE_KTH_CHILD_NAMED_RET,nil)

  fun macroSNDKCCase(ty,n,fieldTy,fieldName) =
      PT.Expr(PT.Call(PL.SND_NODE_KC_CASE,
		      [PT.Id ty,P.intX n,PT.Id fieldTy,PT.Id fieldName]))
  fun macroStructSNDKCBegin(ty) =
      PT.Expr(PT.Call(PL.STR_SND_NODE_KTH_CHILD_BODY_BEGIN,[PT.Id ty]))
  fun macroStructSNDKCEnd(pdidx) =
      PT.Expr(PT.Call(PL.STR_SND_NODE_KTH_CHILD_BODY_END,[P.intX pdidx]))
  fun macroStructSNDKCRet() = 
      PT.Call(PL.STR_SND_NODE_KTH_CHILD_RET,nil)

  fun makeSNDKCCase name (n, (fieldName, fieldTy, _)) =
      macroSNDKCCase(name,n,fieldTy,fieldName)				      

  fun macroStructPWBegin() =
      PT.Expr(PT.Call(PL.STR_NODE_PATH_WALK_BODY_BEGIN,nil))

  fun macroStructPWEnd(pdidx) =
		    PT.Expr(PT.Call(PL.STR_NODE_PATH_WALK_BODY_END,
				    [P.intX pdidx]))

  fun macroStructPWRet() =
		    PT.Call(PL.STR_NODE_PATH_WALK_RET,nil)

  fun macroPWCase(n,fieldTy,fieldName) =
      PT.Expr(PT.Call(PL.NODE_PW_CASE,
		      [P.intX n,PT.Id fieldTy,PT.Id fieldName]))

  fun makePWCase (n, (fieldName, fieldTy, _)) =
      macroPWCase(n,fieldTy,fieldName)				      

  (****  Array macros ****)
  fun macroArrKC(ty,childTy) = 
      PT.Expr(PT.Call(PL.ARR_NODE_KTH_CHILD_BODY,
		      [PT.Id ty,PT.Id childTy]))

  fun macroArrKCRet() = PT.Call(PL.ARR_NODE_KTH_CHILD_RET,nil)

  fun macroArrLength(ty) = PT.Call(PL.ARR_LENGTH, [PT.Id ty])

  fun macroArrKCN(ty) =
      PT.Expr(PT.Call(PL.ARR_NODE_KTH_CHILD_NAMED_BODY,
			  [PT.Id ty]))
  fun macroArrKCNRet() =
      PT.Call(PL.ARR_NODE_KTH_CHILD_NAMED_RET,nil)

  fun macroArrSNDKCBody(ty,childTy) =
      PT.Expr(PT.Call(PL.ARR_SND_NODE_KTH_CHILD_BODY,[PT.Id ty, PT.Id childTy]))

  fun macroArrSNDKCRet() = 
      PT.Call(PL.ARR_SND_NODE_KTH_CHILD_RET,nil)

  fun macroArrPWBody(childTy) =
      PT.Expr(PT.Call(PL.ARR_NODE_PATH_WALK_BODY,[PT.Id childTy]))

  fun macroArrPWRet() = 
      PT.Call(PL.ARR_NODE_PATH_WALK_RET,nil)


  (****  Rec. macros ****)
  (* calls REC_NODE_NEW_BODY macro*)
  fun macroRecNodeNew(ty,baseTy) =
		    PT.Expr(PT.Call(PL.REC_NODE_NEW_BODY,
				    [PT.Id ty, PT.Id baseTy]))

  fun macroRecKC(ty,childTy) = 
      PT.Expr(PT.Call(PL.REC_NODE_KTH_CHILD_BODY,
		      [PT.Id ty,PT.Id childTy]))

  fun macroRecKCRet() = PT.Call(PL.REC_NODE_KTH_CHILD_RET,nil)

  fun macroRecKCN() =
	  PT.Expr(PT.Call(PL.REC_NODE_KTH_CHILD_NAMED_BODY,
			  nil))
  fun macroRecKCNRet() =
		    PT.Call(PL.REC_NODE_KTH_CHILD_NAMED_RET,nil)
  fun macroRecSNDKCBody(ty,childTy) =
      PT.Expr(PT.Call(PL.REC_SND_NODE_KTH_CHILD_BODY,[PT.Id ty, PT.Id childTy]))

  fun macroRecSNDKCRet() = 
      PT.Call(PL.REC_SND_NODE_KTH_CHILD_RET,nil)

  fun macroRecPWBody(childTy) =
      PT.Expr(PT.Call(PL.REC_NODE_PATH_WALK_BODY,[PT.Id childTy]))

  fun macroRecPWRet() = 
      PT.Call(PL.REC_NODE_PATH_WALK_RET,nil)

  (****  Typedef macros ****)
  fun macroTypKC(ty,childTy) = 
      PT.Expr(PT.Call(PL.TYP_NODE_KTH_CHILD_BODY,
		      [PT.Id ty,PT.Id childTy]))

  fun macroTypKCRet() = PT.Call(PL.TYP_NODE_KTH_CHILD_RET,nil)

  fun macroTypKCN() =
	  PT.Expr(PT.Call(PL.TYP_NODE_KTH_CHILD_NAMED_BODY,
			  nil))
  fun macroTypKCNRet() =
		    PT.Call(PL.TYP_NODE_KTH_CHILD_NAMED_RET,nil)
  fun macroTypSNDKCBody(ty,childTy) =
      PT.Expr(PT.Call(PL.TYP_SND_NODE_KTH_CHILD_BODY,[PT.Id ty, PT.Id childTy]))

  fun macroTypSNDKCRet() = 
      PT.Call(PL.TYP_SND_NODE_KTH_CHILD_RET,nil)

  fun macroTypPWBody(childTy, maskX) =
      PT.Expr(PT.Call(PL.TYP_NODE_PATH_WALK_BODY,[PT.Id childTy, maskX]))

  fun macroTypPWRet() = 
      PT.Call(PL.TYP_NODE_PATH_WALK_RET,nil)

  (****  Union macros ****)
  fun macroUnionKCBegin(ty) =
      PT.Expr(PT.Call(PL.UNION_NODE_KTH_CHILD_BODY_BEGIN,
		      [PT.Id ty]))

  fun macroUnionKCEnd() =
		    PT.Expr(PT.Call(PL.UNION_NODE_KTH_CHILD_BODY_END,
				    nil))

  fun macroUnionKCRet() =
		    PT.Call(PL.UNION_NODE_KTH_CHILD_RET,nil)

  fun macroUnionKCCase(ty,branchTag,branchTy) =
      PT.Expr(PT.Call(PL.UNION_NODE_KC_CASE,
		      [PT.Id ty, PT.Id branchTag, PT.Id branchTy]))

  fun macroUnionKCCaseLiteral(ty,branchTag) =
      PT.Expr(PT.Call(PL.UNION_NODE_KC_CASE_LITERAL,
		      [PT.Id ty, PT.Id branchTag]))

  fun makeUnionKCCase name (branchTag, branchTy) = 
      case branchTy of 
	  NONE =>  macroUnionKCCaseLiteral(name, branchTag) 
	| SOME branchTy =>  macroUnionKCCase(name, branchTag, branchTy)

  fun macroUnionKCN(ty) =
	  PT.Expr(PT.Call(PL.UNION_NODE_KTH_CHILD_NAMED_BODY,
			  [PT.Id ty]))

  fun macroUnionKCNRet() =
		    PT.Call(PL.UNION_NODE_KTH_CHILD_NAMED_RET,nil)

  fun macroUnionSNDKCBegin(ty) =
      PT.Expr(PT.Call(PL.UNION_SND_NODE_KTH_CHILD_BODY_BEGIN,
		      [PT.Id ty]))
  fun macroUnionSNDKCEnd() =
      PT.Expr(PT.Call(PL.UNION_SND_NODE_KTH_CHILD_BODY_END,nil))
  fun macroUnionSNDKCRet() = 
      PT.Call(PL.UNION_SND_NODE_KTH_CHILD_RET,nil)

  fun macroUnionSNDKCCase(ty,branchTag,branchTy) =
      case branchTy of 
        NONE => PT.Expr(PT.Call(PL.UNION_SND_NODE_KC_CASE_LITERAL,
			   [PT.Id ty, PT.Id branchTag]))
      | SOME branchTy =>
           PT.Expr(PT.Call(PL.UNION_SND_NODE_KC_CASE,
			   [PT.Id ty, PT.Id branchTag,PT.Id branchTy]))

  fun makeUnionSNDKCCase name (branchTag,branchTy) =
      macroUnionSNDKCCase(name,branchTag,branchTy)

  fun macroUnionPWBegin(name) =
      PT.Expr(PT.Call(PL.UNION_NODE_PATH_WALK_BODY_BEGIN,[PT.Id name]))

  fun macroUnionPWEnd() =
		    PT.Expr(PT.Call(PL.UNION_NODE_PATH_WALK_BODY_END,
				    nil))

  fun macroUnionPWRet() =
		    PT.Call(PL.UNION_NODE_PATH_WALK_RET,nil)

  fun macroUnionPWCase(ty, branchTag,branchTy) =
      case branchTy 
      of NONE =>  PT.Expr(PT.Call(PL.UNION_NODE_PW_CASE_LITERAL,
				  [PT.Id ty, PT.Id branchTag]))
      | SOME branchTy => 
	  PT.Expr(PT.Call(PL.UNION_NODE_PW_CASE,
		      [PT.Id branchTag,PT.Id branchTy]))

  fun makeUnionPWCase ty (branchTag,branchTy) =
      macroUnionPWCase(ty, branchTag,branchTy)


  (****  Enum macros ****)
  fun macroEnumKC(ty) = 
      PT.Expr(PT.Call(PL.ENUM_NODE_KTH_CHILD_BODY,
		      [PT.Id ty, PT.Id(PN.toStringSuf (ty))]))

  fun macroEnumKCRet() = PT.Call(PL.ENUM_NODE_KTH_CHILD_RET,nil)

  fun macroEnumKCN() =
	  PT.Expr(PT.Call(PL.ENUM_NODE_KTH_CHILD_NAMED_BODY,
			  nil))
  fun macroEnumKCNRet() =
		    PT.Call(PL.ENUM_NODE_KTH_CHILD_NAMED_RET,nil)
  fun macroEnumSNDKCBody(ty) =
      PT.Expr(PT.Call(PL.ENUM_SND_NODE_KTH_CHILD_BODY,[PT.Id ty, PT.Id(PN.toStringSuf(ty))]))

  fun macroEnumSNDKCRet() = 
      PT.Call(PL.ENUM_SND_NODE_KTH_CHILD_RET,nil)

  fun macroEnumPWBody(name) =
      PT.Expr(PT.Call(PL.ENUM_NODE_PATH_WALK_BODY,[PT.Id name]))

  fun macroEnumPWRet() = 
      PT.Call(PL.ENUM_NODE_PATH_WALK_RET,nil)

  (**** General purpose functions ****)
  fun makeInvisibleDecls(tys,fields) =
      let fun makeDecl ty name = 
	      PT.Decl (PT.DeclarationExt (PX.PPhantomDecl (ty, name)))

	  val tyDecls = map (makeDecl "type_t") tys
	  val fieldDecls = map (makeDecl "field_t") fields 
      in 
	  tyDecls @ fieldDecls
      end


  fun makeNodeNewFun(name) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.nodeNewSuf name
	  val paramTys = [returnTy, P.ccharPtr, 
			  P.voidPtr,P.voidPtr,P.voidPtr,
			  P.ccharPtr,P.ccharPtr]
	  val paramNames = [parent,nameStr,
			    PN.m,PN.pd,PN.rep,
			    kind,whatfn]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name],nil)
		       @ [macroNodeNew(name)]
		       @ [P.returnS (macroNodeNewRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end
			      
  fun makeCNInitFun(name,numChildrenExpr) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.cnInitSuf name
	  val paramTys = [returnTy]
	  val paramNames = [self]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name],nil)
		       @ [macroCNInit(name,numChildrenExpr)]
		       @ [P.returnS (macroCNInitRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeCNKCFun(name,numChildrenExpr) = 
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.cnKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name],nil)
		       @ [macroCNKthChild(name,numChildrenExpr)]     
		       @ [P.returnS (macroCNKthChildRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams,PT.Compound bodySs, returnTy)
      end
			      

  fun makeSNDInitFun(name) =		
      let val nodeRepTy = PL.nodeT
	  val managerTy = P.ptrPCT PL.managerT   
	  val genTy = PL.genT                     
	  val childTy = PL.childIndexT                   
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndInitSuf name
	  val paramTys = [returnTy, managerTy, childTy, genTy, childTy]
	  val paramNames = [self,manager,ancIdx,gen,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name],nil)
		       @ [macroSNDInit(name)]     
		       @ [P.returnS (macroSNDInitRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end
			      
  fun makeNodeVtable(name) =
	  PT.ExternalDecl(PT.Declaration({specifiers=[PL.PDCI_vtable_t], qualifiers=[PT.CONST], storage=[]},
					 [(PT.VarDecr (PN.nodeVTableSuf name),
					   PT.InitList [PT.Id(PN.cnInitSuf name),
							PT.Id(PN.nodeKCSuf name),
							PT.Id(PN.nodeKCNSuf name),
							PL.PDCI_node_free,
							PL.PDCI_node_getId,
							PL.PDCI_error_typed_value,
							P.zero])])) 

(*
const PDCI_vtable_t \
ty ## _cachedNode_vtable = {PDCI_error_cachedNode_init, \
			     ty ## _cachedNode_kthChild, \
			     ty ## _node_kthChildNamed, \
                             PDCI_cachedNode_free, \
			     PDCI_error_typed_value, \
			     PDCI_not_impl_yet_string_value};\

*)
  fun makeCachedNodeVtable(name) =
	  PT.ExternalDecl(PT.Declaration({specifiers=[PL.PDCI_vtable_t], qualifiers=[PT.CONST], storage=[]},
					 [(PT.VarDecr (PN.cnVTableSuf name),
					   PT.InitList [PL.PDCI_error_cachedNode_init,
							PT.Id(PN.cnKCSuf name),
							PT.Id(PN.nodeKCNSuf name),
							PL.PDCI_cachedNode_free,
							PL.PDCI_node_getId,
							PL.PDCI_error_typed_value,
							P.zero])])) 

  fun makeSNDNodeVtable(name) =
	  PT.ExternalDecl(PT.Declaration({specifiers=[PL.PDCI_vtable_t], qualifiers=[PT.CONST], storage=[]},
					 [(PT.VarDecr (PN.sndVTableSuf name),
					   PT.InitList [PL.PDCI_error_cachedNode_init,
							PT.Id(PN.sndKCSuf name),
							PT.Id(PN.nodeKCNSuf name),
							PL.PDCI_node_free,
							PL.PDCI_sndNode_getId,
							PL.PDCI_error_typed_value,
							P.zero])])) 

  (* Pads-type specific functions *)

  fun makeStructSNDKthChildFun(name,fields) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val uniqueFieldTys = getUniqueTys (List.map (fn(x,y,z) => y) fields)
	  val fieldNames = map (fn (n,_,_) => n) fields						   
	  val bodySs = makeInvisibleDecls(name :: uniqueFieldTys, fieldNames)
		       @ [macroStructSNDKCBegin(name)] 
		       @ (List.map (makeSNDKCCase name) (enumerate fields)) 
		       @ [macroStructSNDKCEnd(List.length fields),   
			  P.returnS (macroStructSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

(* Perror_t ty ## _node_pathWalk(P_t *pads, ty ## _m *m, ty ## _pd *pd, ty  *rep, PDCI_path_t path,
		      void **m_out, void **pd_out, void **rep_out) *)
  fun makeStructPathWalkFun(name,fields) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val uniqueFieldTys = getUniqueTys (List.map (fn(x,y,z)=> y) fields)
	  val fieldNames = map (fn (n,_,_) => n) fields						   
	  val bodySs = makeInvisibleDecls(name :: uniqueFieldTys, fieldNames)
		       @ [macroStructPWBegin()] 
		       @ (List.map makePWCase (enumerate fields)) 
		       @ [macroStructPWEnd(List.length fields),   
			  P.returnS (macroStructPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeArrSNDKthChildFun(name,childName) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name,childName], nil)
		       @ [macroArrSNDKCBody(name,childName)] 
		       @ [P.returnS (macroArrSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeArrPathWalkFun(name,childName) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([childName], nil)
		       @ [macroArrPWBody(childName)] 
		       @ [P.returnS (macroArrPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  (* Rec. type masquerades as underlying type, so need underlying type name as well. *)
  fun makeRecNodeNewFun(name,baseName) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.nodeNewSuf name
	  val paramTys = [returnTy, P.ccharPtr, 
			  P.voidPtr,P.voidPtr,P.voidPtr,
			  P.ccharPtr,P.ccharPtr]
	  val paramNames = [parent,nameStr,
			    PN.m,PN.pd,PN.rep,
			    kind,whatfn]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name,baseName],nil)
		       @ [macroRecNodeNew(name,baseName)]
		       @ [P.returnS (macroNodeNewRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end
			      
  (* Rec. type masquerades as underlying type, so need underlying type name as well. *)
  fun makeRecSNDInitFun(name,baseName) =		
      let val nodeRepTy = PL.nodeT
	  val managerTy = P.ptrPCT PL.managerT   
	  val genTy = PL.genT                     
	  val childTy = PL.childIndexT                   
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndInitSuf name
	  val paramTys = [returnTy, managerTy, childTy, genTy, childTy]
	  val paramNames = [self,manager,ancIdx,gen,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([baseName],nil)
		       @ [macroSNDInit(baseName)]     
		       @ [P.returnS (macroSNDInitRet())]
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end
			      
  fun makeRecSNDKthChildFun(name,baseName) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name,baseName], nil)
		       @ [macroRecSNDKCBody(name,baseName)] 
		       @ [P.returnS (macroRecSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeRecPathWalkFun(name,baseName) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([baseName], nil)
		       @ [macroRecPWBody(baseName)] 
		       @ [P.returnS (macroRecPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeTypedefSNDKthChildFun(name,baseName) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name,baseName], nil)
		       @ [macroTypSNDKCBody(name,baseName)] 
		       @ [P.returnS (macroTypSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeTypedefPathWalkFun(name,baseName, maskX) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([baseName], nil)
		       @ [macroTypPWBody(baseName,maskX)] 
		       @ [P.returnS (macroTypPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeUnionSNDKthChildFun(name,branches) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val uniqueBranchTys = getUniqueTys (List.mapPartial (fn(x,y) => y ) branches)
	  val branchNames = map (fn (n,_) => n) branches						   
	  val mkCase = makeUnionSNDKCCase name
	  val caseSs = List.map mkCase branches

	  val bodySs = makeInvisibleDecls(name :: uniqueBranchTys,nil)
		       @ [macroUnionSNDKCBegin(name)] 
		       @ caseSs
		       @ [macroUnionSNDKCEnd(),   
			  P.returnS (macroUnionSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeUnionPathWalkFun(name,branches) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val uniqueBranchTys = getUniqueTys (List.mapPartial (fn(x,y) => y ) branches)
	  val branchNames = map (fn (n,_) => n) branches						   
	  val caseSs = List.map (makeUnionPWCase name) branches

	  val bodySs = makeInvisibleDecls(name :: uniqueBranchTys,nil)
		       @ [macroUnionPWBegin(name)] 
		       @ caseSs
		       @ [macroUnionPWEnd(),   
			  P.returnS (macroUnionPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeEnumSNDKthChildFun(name) =		
      let val nodeRepTy = PL.nodeT
	  val returnTy = P.ptrPCT nodeRepTy
	  val cnvName = PN.sndKCSuf name
	  val paramTys = [P.ptrPCT nodeRepTy, PL.childIndexT]
	  val paramNames = [self,idx]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name], nil)
		       @ [macroEnumSNDKCBody(name)] 
		       @ [P.returnS (macroEnumSNDKCRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  fun makeEnumPathWalkFun(name) =		
      let val padsTy = P.ptrPCT PL.toolStatePCT
	  val returnTy = PL.toolErrPCT
	  val cnvName = PN.nodePWSuf name
	  val maskTy = P.ptrPCT (P.makeTypedefPCT (PN.mSuf name))
	  val pdTy  = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf name))
	  val repTy  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf name))
	  val pathTy = PL.pathT
	  val vppT = P.voidPtrPtr
	  val paramTys = [padsTy,maskTy,pdTy,repTy,pathTy,vppT,vppT,vppT]
	  val paramNames = [pads,PN.m,PN.pd,PN.rep,path,"m_out","pd_out","rep_out"]
	  val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	  val bodySs = makeInvisibleDecls([name],nil)
		       @ [macroEnumPWBody(name)] 
		       @ [P.returnS (macroEnumPWRet())] 
      in   
	  P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
      end

  type cparams = (string * ParseTree.ctype) list
  type stparams = (ParseTree.ctype * string) list

  structure SmartNode = struct
    val errTy =  PL.toolErrPCT
    val padsTy = P.ptrPCT PL.toolStatePCT
    val nodeTy = P.ptrPCT PL.nodeT
    val vppTy = P.voidPtrPtr
    val seinfoPtrTy = P.ptrPCT PL.smartEltInfoT
    val vpTy = P.voidPtr
    val pathTy = PL.pathT
    val intTy = P.int
    val uintTy = P.uint
    val idxTy = PL.childIndexT
    val sainfoTy = PL.smartArrayInfoT
    val ccpTy = P.ccharPtr

    fun maskTy ty = P.ptrPCT (P.makeTypedefPCT (PN.mSuf ty))
    fun pdTy ty = P.ptrPCT (P.makeTypedefPCT (PN.pdSuf ty))
    fun repTy ty  = P.ptrPCT (P.makeTypedefPCT (PN.repSuf ty))

    (* macro call gen functions *)
    fun macroEltAllocBody(ty,eltTy,eltPdTy,smartNode,pads,elt_pd,elt_rep) = 	               
	PT.Expr(PT.Call(PL.SN_ELT_ALLOC_BODY,
			List.map PT.Id [ty,eltTy,eltPdTy,smartNode,pads,
					elt_pd,elt_rep])) 
    fun macroEltAllocRet() = 				
	PT.Call(PL.SN_ELT_ALLOC_RET,[])     
    fun macroRoParam p =
	PT.Call(PL.SN_RO_PARAM,[PT.Id p])     

    (* Wrap parameters used in initialization. *)
    fun macroWrapParams'(params) =
	(* The first argument passed, P.zero, is thrown away by the macro. *)
	(* See pglx-codegen-macros.h for explanation. *)
	PT.Call(PL.SN_WRAP_PARAMS, P.zero :: List.map PT.Id params) 	    

    (* Wrap parameters already in the ro_params structure. *)
    fun macroWrapParams(params) =
	(* The first argument passed, P.zero, is thrown away by the macro. *)
	(* See pglx-codegen-macros.h for explanation. *)
	PT.Call(PL.SN_WRAP_PARAMS, P.zero :: List.map macroRoParam params) 	    

    fun macroEltReadBody(ty,eltTy,eltPdTy,smartNode,pads,info,wrapcX,wrapstX) = 
	PT.Expr(PT.Call(PL.SN_ELT_READ_BODY, map PT.Id [ty,eltTy,eltPdTy]
						 @ map PT.Id [smartNode,pads,info]
						 @ [wrapcX,wrapstX]))
    fun macroEltReadRet() =            			       
	PT.Call(PL.SN_ELT_READ_RET,[])  
    fun macroEltFreeBody(ty,pads,info) =
 	PT.Expr(PT.Call(PL.SN_ELT_FREE_BODY,map PT.Id [ty,pads,info]))  
    fun macroEltFreeRet() =				       
	PT.Call(PL.SN_ELT_FREE_RET,[])  
    fun macroEltPathWalkBody(ty,eltTy,eltPdTy,eltMaskTy) =     
	PT.Expr(PT.Call(PL.SN_ELT_PATH_WALK_BODY,
			map PT.Id [ty,eltTy,eltPdTy,eltMaskTy,
				   pads,m,pd,rep,path,m_out,pd_out,rep_out]))
    fun macroEltPathWalkRet(eltTy,pads,path,m_out,pd_out,rep_out) =  
	PT.Call(PL.SN_ELT_PATH_WALK_RET,map PT.Id [eltTy,pads,path,m_out,pd_out,rep_out])
    fun macroArrayInfoInitBody(ty,pads,max_elts,wrapX) =
	PT.Expr(PT.Call(PL.SN_ARRAY_INFO_INIT_BODY,
			[PT.Id ty] @ List.map PT.Id [pads,max_elts] @ [wrapX]))			
    fun macroArrayInfoInitRet() =            			       
	PT.Call(PL.SN_ARRAY_INFO_INIT_RET,[]) 	
    fun macroInitBody(ty,self,max_elts,cinitX,stX,cX) =   
	PT.Expr(PT.Call(PL.SN_INIT_BODY,[PT.Id ty]
					    @ List.map PT.Id [self,max_elts] 
					    @ [cinitX,stX, cX]))  
    fun macroInitRet() =            			       
	PT.Call(PL.SN_INIT_RET,[PT.Id self]) 	
    fun macroKthChildBody(ty,eltTy,self,idx) = 		       
	PT.Expr(PT.Call(PL.SN_KTH_CHILD_BODY,map PT.Id [ty,eltTy,self,idx]))
    fun macroKthChildRet() =				       
	PT.Call(PL.SN_KTH_CHILD_RET,[]) 

    fun macroKthChildNamedBody(ty,self,idx,name) = 		       
	PT.Expr(PT.Call(PL.SN_KTH_CHILD_NAMED_BODY,map PT.Id [ty,self,idx,name]))
    fun macroKthChildNamedRet() =				       
	PT.Call(PL.SN_KTH_CHILD_NAMED_RET,[]) 


    (* function gen functions *)
    fun makeEltAllocFun(ty, eltTy, eltPdTy) =
	let val returnTy = errTy
	    val cnvName = PN.snEltAllocSuf ty 
	    val paramTys = [nodeTy,padsTy,vppTy,vppTy]
	    val paramNames = [smartNode,pads,elt_pd,elt_rep]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				
	    val bodySs = makeInvisibleDecls([ty,eltTy,eltPdTy],nil)
			 @ [macroEltAllocBody(ty,eltTy,eltPdTy, 
					      smartNode,pads,elt_pd,elt_rep)] 
			 @ [P.returnS (macroEltAllocRet())]  
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end
	      	  
      fun makeEltReadFun(ty, eltTy, eltPdTy, cparams, stparams) = 
	let val returnTy = PL.readResPCT
	    val cnvName = PN.snEltReadSuf ty
	    val paramTys = [nodeTy,padsTy,seinfoPtrTy]
	    val paramNames = [smartNode,pads,info]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				
	    val stNames = map (fn (_,x) => x) stparams
	    val wrapstX = macroWrapParams(stNames) 
	    val cpNames = map (fn (x,_) => x) cparams
	    val wrapcX = macroWrapParams(cpNames)

	    val bodySs = makeInvisibleDecls([ty,eltTy,eltPdTy],stNames @ cpNames)
			 @ [macroEltReadBody(ty,eltTy,eltPdTy,smartNode,pads,
					     info,wrapcX,wrapstX)]  
			 @ [P.returnS (macroEltReadRet())]              
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeEltFreeFun(ty) = 
	  let val returnTy = errTy
	      val cnvName = PN.snEltFreeSuf ty
	      val paramTys = [padsTy,seinfoPtrTy]
	      val paramNames = [pads,info]
	      val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))

	      val bodySs = makeInvisibleDecls([ty],nil)
			   @ [macroEltFreeBody(ty,pads,info)] 
			   @ [P.returnS (macroEltFreeRet())] 
	  in   
	      P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	  end	      

      fun makeEltPathWalkFun(ty,eltTy,eltPdTy,eltMaskTy) = 
	let val returnTy = errTy
	    val cnvName = PN.snEltPathWalkSuf ty
	    val paramTys = [padsTy,vpTy,vpTy,vpTy,pathTy,vppTy,vppTy,vppTy]
	    val paramNames = [pads,m,pd,rep,path,m_out,pd_out,rep_out]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				
	    val bodySs = makeInvisibleDecls([ty,eltTy,eltPdTy,eltMaskTy],nil)
			 @ [macroEltPathWalkBody(ty,eltTy,eltPdTy,eltMaskTy)]  
			 @ [P.returnS (macroEltPathWalkRet(eltTy,pads,path,m_out,pd_out,rep_out))]  
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeArrayInfoInitFun(ty,cparams) =
	let val returnTy = P.ptrPCT PL.smartArrayInfoT
	    val cnvName = PN.aiInitSuf ty
	    val paramTys = [padsTy,uintTy]
	    val paramNames = [pads,max_elts]
	    val allParams = ListPair.zip(paramTys, paramNames)

	    val formalParams =  List.map P.mkParam allParams
				@ List.map (fn (s,ty) => P.mkParam (ty,s)) cparams
				
	    val cpNames = map (fn (x,_) => x) cparams
	    val wrapX = macroWrapParams'(cpNames)

	    val bodySs = makeInvisibleDecls([ty],cpNames)
			 @ [macroArrayInfoInitBody(ty,pads,max_elts,wrapX)]  
			 @ [P.returnS (macroArrayInfoInitRet())]              
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeInitFun(ty,cparams,stparams) = 
	let val returnTy = nodeTy
	    val cnvName = PN.snInitSuf ty
	    val paramTys = [nodeTy,uintTy]
	    val paramNames = [self,max_elts]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				@ List.map (fn (s,ty) => P.mkParam (ty,s)) cparams

	    val stNames = map (fn (_,x) => x) stparams
	    val wrapstX = macroWrapParams(stNames) 

	    val cpNames = map (fn (x,_) => x) cparams
	    val wrapcInitX = macroWrapParams'(cpNames)
	    val wrapcX = macroWrapParams(cpNames)

	    val bodySs = makeInvisibleDecls([ty],stNames @ cpNames)
			 @ [macroInitBody(ty,self,max_elts,wrapcInitX,wrapstX,wrapcX)]  
			 @ [P.returnS (macroInitRet())]              
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeKthChildFun(ty,eltTy) = 
	let val returnTy = nodeTy
	    val cnvName = PN.snKCSuf ty
	    val paramTys = [nodeTy,idxTy]
	    val paramNames = [self,idx]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				
	    val bodySs = makeInvisibleDecls([ty,eltTy],nil)
			 @ [macroKthChildBody(ty,eltTy,self,idx)]  
			 @ [P.returnS (macroKthChildRet())]  
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeKthChildNamedFun(ty) = 
	let val returnTy = nodeTy
	    val cnvName = PN.snKCNSuf ty 
	    val paramTys = [nodeTy,idxTy,ccpTy]
	    val paramNames = [self,idx,childName]
	    val formalParams =  List.map P.mkParam (ListPair.zip(paramTys, paramNames))
				
	    val bodySs = makeInvisibleDecls([ty],nil)
			 @ [macroKthChildNamedBody(ty,self,idx,childName)]  
			 @ [P.returnS (macroKthChildNamedRet())]   
	in   
	    P.mkFunctionEDecl(cnvName, formalParams, PT.Compound bodySs, returnTy)
	end

      fun makeVTable(ty) = 
	  PT.ExternalDecl(PT.Declaration({specifiers=[PL.PDCI_vtable_t], qualifiers=[PT.CONST], storage=[]},
					 [(PT.VarDecr (PN.snVTableSuf ty),  
					   PT.InitList [PL.PDCI_error_cachedNode_init,
							PT.Id(PN.snKCSuf ty),
							PT.Id(PN.snKCNSuf ty),
							PL.PDCI_cachedNode_free,
							PL.PDCI_smartNode_getId, 
							PL.PDCI_error_typed_value,
							P.zero])]))
      (* Generate type-specific array info structure  *)
      fun makeArrayInfoStructED(ty) =
	  let val aiFields = [(base, sainfoTy, NONE),
			      (params, P.makeTypedefPCT (PN.roParamsSuf ty), 
			       SOME("Type-specific parameters to read related funcitons."))]
	      val aiStructED = P.makeTyDefStructEDecl (aiFields, PN.arrayInfoSuf ty)
	  in
	      aiStructED
	  end

      fun makeAllEDs(ty,eltTy,eltPdTy,eltMaskTy,cparams,stparams) = 
	  [makeEltAllocFun(ty, eltTy, eltPdTy),
	   makeEltReadFun(ty, eltTy, eltPdTy, cparams, stparams),
	   makeEltFreeFun(ty),
	   makeEltPathWalkFun(ty,eltTy,eltPdTy,eltMaskTy),
	   makeArrayInfoInitFun(ty,cparams),
	   makeInitFun(ty,cparams,stparams),
           makeKthChildFun(ty,eltTy),
           makeKthChildNamedFun(ty),
	   makeVTable(ty)]
	      
  end (* SmartNode struct *)

end
