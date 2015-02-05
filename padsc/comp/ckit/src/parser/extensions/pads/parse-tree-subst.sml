(* XXX - should substitute through declarators too This case only
 matters if the expression contains a sizeof a type with complex
 declarators containing an array mentioning the variable we are
 substituting for.  Should clean this up sometime. (Why do we need
 both substitution functions?)  

 Specifier extensions are proably wrong too.
 *) 

structure ParseTreeSubst : PARSE_TREE_SUBST = struct

    open ParseTree
    open ParseTreeExt

    fun fieldArgOp oper = 
	(case oper of
	     (Dot | Arrow) => true
	   | _ => false)

    fun substExp (id,e,exp) =
	let fun s' exp = substExp (id,e,exp)
	in
	    case exp of
		Id s => if (id=s) then e else exp
	      | Binop(oper,e1,e2) => 
		    if fieldArgOp oper then
			Binop(oper,s' e1,e2)
		    else 
			Binop(substOper (id,e,oper),s' e1,s' e2)
              | Unop(oper, e) => Unop(oper, s' e)
	      | QuestionColon(e1,e2,e3) => QuestionColon(s' e1, s' e2, s' e3)
	      | Call (e,es) => Call(s' e,map s' es)
	      | Cast(ct,e) => Cast(ct,s' e)
	      | InitList es => InitList (map s' es)
	      | MARKexpression (l,e) => MARKexpression(l,s' e)
	      | _ => exp
	end

    and substOper (id,e,x) =
	(case x of
	     SizeofType(ct) => SizeofType(substCT(id,e,ct))
	   | _ => x)
    and substCT (id,e,{qualifiers=q,specifiers=s}) =
	{qualifiers=q,
	 specifiers=List.map (fn x => substSpec (id,e,x)) s}
    and substSpec (id,e,x) =
	let fun se' x = substExp(id,e,x)
	    fun sct' x = substCT(id,e,x)
	in
	    case x of
		Array(e',ct) => Array(substExp (id,e,e'),
				      substCT(id,e,ct))
	      | Pointer(ct) => Pointer(substCT (id,e,ct))
	      | Enum {tagOpt,enumerators,trailingComma} =>
		    Enum {tagOpt=tagOpt,
			  enumerators = List.map (fn (s,e,c) => (s,se' e,c)) enumerators,
			  trailingComma=trailingComma}
	      | Struct {isStruct,tagOpt,members} =>
		    let fun g (d,e) = (d,se' e)
			fun f (ct,des, commentOpt) = 
			    (sct' ct, List.map g des, commentOpt)
		    in 
			Struct {isStruct = isStruct,
				tagOpt = tagOpt,
				members = List.map f members
				}
		    end
	      | _ => x
	end

    fun substExps (bindings:(string * ParseTree.expression) list) exp =
	let fun s' exp = substExps bindings exp
	    fun lookup id bindings = 
		let fun f [] = Id id
		    |   f ((x,ex)::l) = if x = id then ex else f l
		in
		    f bindings
		end
	in
	    case exp of
		Id s => lookup s bindings
	      | Binop(oper,e1,e2) => 
		    if fieldArgOp oper then
			Binop(oper,s' e1,e2)
		    else 
			Binop(substOpers bindings oper,s' e1,s' e2)
              | Unop(oper, e) => Unop(oper, s' e)
	      | QuestionColon(e1,e2,e3) => QuestionColon(s' e1, s' e2, s' e3)
	      | Call (e,es) => Call(s' e,map s' es)
	      | Cast(ct,e) => Cast(ct,s' e)
	      | InitList es => InitList (map s' es)
	      | MARKexpression (l,e) => MARKexpression(l,s' e)
	      | _ => exp
	end

    and substOpers bindings x =
	(case x of
	     SizeofType(ct) => SizeofType(substCTs bindings ct)
	   | _ => x)
    and substCTs bindings {qualifiers=q,specifiers=s} =
	{qualifiers=q, specifiers=List.map (fn x => substSpecs bindings x) s}
    and substSpecs bindings x =
	let fun se' x = substExps bindings x
	    fun sct' x = substCTs bindings x
	in
	    case x of
		Array(e',ct) => Array(substExps bindings e',
				      substCTs bindings ct)
	      | Pointer(ct) => Pointer(substCTs bindings ct)
	      | Enum {tagOpt,enumerators,trailingComma} =>
		    Enum {tagOpt=tagOpt,
			  enumerators = List.map (fn (s,e,c) => (s,se' e,c)) enumerators,
			  trailingComma=trailingComma}
	      | Struct {isStruct,tagOpt,members} =>
		    let fun g (d,e) = (d,se' e)
			fun f (ct,des, commentOpt) = 
			    (sct' ct, List.map g des, commentOpt)
		    in 
			Struct {isStruct = isStruct,
				tagOpt = tagOpt,
				members = List.map f members
				}
		    end
	      | _ => x
	end

(*    fun substExps ([]:(string * ParseTree.expression) list) (e : ParseTree.expression) = e
      | substExps ((n,nexp)::ls) e = substExps ls (substExp(n,nexp,e))*)

    fun isFreeInExp (vars : string list, EmptyExpr )  = false
      | isFreeInExp (vars : string list, IntConst _ )  = false
      | isFreeInExp (vars : string list, RealConst _ )  = false
      | isFreeInExp (vars : string list, String _ )  = false		       
      | isFreeInExp (vars : string list, Id s )  = List.exists (fn s'=> s = s') vars
      | isFreeInExp (vars : string list, Unop (rator,exp) )  = isFreeInExp(vars,exp)
      | isFreeInExp (vars : string list, Binop (rator,exp1,exp2) )  = 
	isFreeInExp(vars,exp1) orelse isFreeInExp(vars,exp2)
      | isFreeInExp (vars : string list, QuestionColon (exp1,exp2,exp3) )  = 
	isFreeInExp(vars,exp1) orelse isFreeInExp(vars,exp2) orelse isFreeInExp(vars,exp3)
      | isFreeInExp (vars : string list, Call (exp1,exps) )  = 
	isFreeInExp(vars,exp1) orelse (List.exists (fn e => isFreeInExp(vars,e)) exps)
      | isFreeInExp (vars : string list, Cast (ty,exp) )  = isFreeInExp(vars,exp)
      | isFreeInExp (vars : string list, InitList exps )  = 
         List.exists (fn e => isFreeInExp(vars,e)) exps
      | isFreeInExp (vars : string list, MARKexpression(l, exp)) = isFreeInExp(vars,exp)
      | isFreeInExp (vars : string list, ExprExt e) = isFreeInExpExt(vars, e)

    and isFreeInExpExt (vars, _) = false

    fun expIsClosed (vars : string list, EmptyExpr )  = true
      | expIsClosed (vars : string list, IntConst _ )  = true
      | expIsClosed (vars : string list, RealConst _ )  = true
      | expIsClosed (vars : string list, String _ )  = true
      | expIsClosed (vars : string list, Id s )  = List.exists (fn s'=> s = s') vars
      | expIsClosed (vars : string list, Unop (rator,exp) )  = expIsClosed(vars,exp)
      | expIsClosed (vars : string list, Binop (rator,exp1,exp2) )  = 
	expIsClosed(vars,exp1) andalso expIsClosed(vars,exp2)
      | expIsClosed (vars : string list, QuestionColon (exp1,exp2,exp3) )  = 
	expIsClosed(vars,exp1) andalso expIsClosed(vars,exp2) andalso expIsClosed(vars,exp3)
      | expIsClosed (vars : string list, Call (exp1,exps) )  = 
	expIsClosed(vars,exp1) andalso (List.all (fn e => expIsClosed(vars,e)) exps)
      | expIsClosed (vars : string list, Cast (ty,exp) )  = expIsClosed(vars,exp)
      | expIsClosed (vars : string list, InitList exps )  = 
         List.all (fn e => expIsClosed(vars,e)) exps
      | expIsClosed (vars : string list, MARKexpression(l, exp)) = expIsClosed(vars,exp)
      | expIsClosed (vars : string list, ExprExt e) = expIsClosedExt(vars, e)

    and expIsClosedExt (vars, _) = true


   fun mungePCT(f:string -> string, pcty:ctype) : ParseTree.ctype = 
       let val {qualifiers, specifiers} = pcty
           fun mungeSpec spec = 
               case spec
               of TypedefName s => TypedefName (f s)
               | Array(e,cty) => Array(e, mungePCT(f, cty))
               | Pointer cty => Pointer(mungePCT(f, cty))
               | Function {retType, params} =>
		   Function {retType = mungePCT(f, retType),
			     params = List.map (mungePDT f) params}
               | Struct{isStruct, tagOpt,members} =>
		   let fun mungeMem (pcty', del, sOpt) = 
		       (mungePCT(f, pcty'), del, sOpt)
		   in
		       Struct {isStruct=isStruct, tagOpt=tagOpt,
			       members = List.map mungeMem members}
		   end
               | x => x
	   val newSpecs = List.map mungeSpec specifiers
   in
       {qualifiers = qualifiers, specifiers = newSpecs}
   end

   and mungePDT f (dt:decltype, decl) = 
       let val {qualifiers, specifiers, storage} = dt
	   val {qualifiers, specifiers} = mungePCT(f, {qualifiers=qualifiers, specifiers=specifiers})
       in
          ({qualifiers=qualifiers, specifiers=specifiers, storage=storage}, decl)
       end
end
