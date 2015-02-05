structure ParseTreeUtil =
struct

    structure PT = ParseTree
    structure PX = ParseTreeExt
    structure PTSub= ParseTreeSubst(* Function for subtituting an expression for a string in an expression *)

    fun makePCT s : PT.ctype = {qualifiers=[], specifiers=s}
    fun makePDT s : PT.decltype = {qualifiers=[],specifiers=s,storage=[]}
    fun pctToPDT (ct : PT.ctype) : PT.decltype = 
	let val {specifiers,qualifiers} = ct
	in
	    {specifiers=specifiers,qualifiers=qualifiers,storage=[]}
	end

    fun pctToPTyDefDT (ct : PT.ctype) : PT.decltype = 
	let val {specifiers,qualifiers} = ct
	in
	    {specifiers=specifiers,qualifiers=qualifiers,storage=[PT.TYPEDEF]}
	end

    fun mkParam(ct,s) = (pctToPDT ct, PT.VarDecr s)


    fun makeStructTagPCT (isStruct,name) = 
	makePCT [PT.StructTag{isStruct=isStruct,
			      name=name}]

    fun makeStructPCT (fields : (string * PT.ctype * string option) list, tag : string option) =
	let fun genField (id,ct,sOpt) = 
	    (ct,[ (PT.VarDecr id, PT.EmptyExpr) ],sOpt)
	in
	    makePCT [PT.Struct {isStruct = true,
				 tagOpt = tag,
				 members = List.map genField fields
				 }
		      ]
	end

    fun makeUnionPCT (variants : (string * PT.ctype * string option) list, tag : string option) =
	let fun genVariant (id,ct,sOpt) = 
	    (ct,[ (PT.VarDecr id, PT.EmptyExpr) ],sOpt)
	in
	    makePCT [PT.Struct {isStruct = false,
				 tagOpt = tag,
				 members = List.map genVariant variants
				 }
		      ]
	end

    fun makeEnumPCT (members : (string * PT.expression * string option) list, tag : string option) =
	    makePCT [PT.Enum   { tagOpt = tag,
				 enumerators = members,
				 trailingComma = false
				 }
		      ]


    fun makeTypedefPCT s  = makePCT [PT.TypedefName s]
    fun ptrPCT ty         = makePCT [PT.Pointer ty]
    fun arrayPCT (sizeX,ty) = makePCT [PT.Array(sizeX,ty)]

    val char       = makePCT [PT.Char]
    val uchar      = makePCT [PT.Unsigned, PT.Char]
    val uint       = makePCT [PT.Unsigned, PT.Int]
    val int        = makePCT [PT.Int]
    val ushort     = makePCT [PT.Unsigned, PT.Short]
    val short      = makePCT [PT.Short]
    val long       = makePCT [PT.Long]
    val ulong      = makePCT [PT.Long, PT.Unsigned]
    val longlong   = makePCT [PT.Long, PT.Long]
    val ulonglong  = makePCT [PT.Long, PT.Long, PT.Unsigned]
    val float      = makePCT [PT.Float]
    val double     = makePCT [PT.Double]
    val intPtr     = ptrPCT  int
    val charPtr    = ptrPCT  char
    val ccharPtr   = ptrPCT {qualifiers = [PT.CONST], specifiers = [PT.Char]}
    val ucharPtr   = ptrPCT  uchar
    val charPtrPtr = ptrPCT  charPtr
    val void       = makePCT [PT.Void]
    val voidPtr    = ptrPCT  void
    val voidPtrPtr = ptrPCT (voidPtr)

    fun func (ret:PT.ctype) (args:PT.ctype list) =
	let fun f ct = (pctToPDT ct,PT.EmptyDecr) in	    
	    makePCT [PT.Function {retType = ret, params = List.map f args}]
	end


    fun intX i = PT.IntConst (IntInf.fromInt i, false)
    fun int32X i = PT.IntConst (IntInf.fromInt (Int32.toInt i), false)

    val zero = intX 0

    val trueX             = intX 1
    val falseX            = zero

    fun addrX e           = PT.Unop(PT.AddrOf,e)
    fun andX (e1,e2)      = PT.Binop(PT.And,e1,e2)
    fun arrowX (e1,e2)    = PT.Binop(PT.Arrow,e1,e2)
    fun assignX (lhs,rhs) = PT.Binop(PT.Assign,lhs,rhs)
    fun assignS (lhs,rhs) = PT.Expr(assignX (lhs,rhs))
    fun callS(name, args) = PT.Expr(PT.Call(name, args))
    fun commaX (e1,e2)    = PT.Binop(PT.Comma,e1,e2)
    fun dotX (lhs,rhs)    = PT.Binop(PT.Dot,lhs,rhs)
    fun eqX (e1,e2)       = PT.Binop(PT.Eq,e1,e2)
    fun neqX (e1,e2)      = PT.Binop(PT.Neq,e1,e2)
    fun ltX (e1,e2)       = PT.Binop(PT.Lt,e1,e2)
    fun lteX(e1,e2)       = PT.Binop(PT.Lte,e1,e2)
    fun gtX (e1,e2)       = PT.Binop(PT.Gt,e1,e2)
    fun gteX (e1,e2)      = PT.Binop(PT.Gte,e1,e2)
    fun notX e            = PT.Unop(PT.Not,e)
    fun bitNotX e         = PT.Unop(PT.BitNot,e)
    fun orX (e1,e2)       = PT.Binop(PT.Or,e1,e2)
    fun plusX (e1,e2)     = PT.Binop(PT.Plus,e1,e2)
    fun minusX (e1,e2)    = PT.Binop(PT.Minus,e1,e2)
    fun minusAssignS(e1,e2)= PT.Expr(PT.Binop(PT.MinusAssign,e1,e2))
    fun timesX (e1,e2)    = PT.Binop(PT.Times,e1,e2)
    fun rshiftX (e1,e2)   = PT.Binop(PT.Rshift,e1,e2)
    fun modX (e1,e2)      = PT.Binop(PT.Mod,e1,e2)
    fun bitAndX (e1,e2)   = PT.Binop(PT.BitAnd,e1,e2)
    fun bitOrX (e1,e2)    = PT.Binop(PT.BitOr,e1,e2)
    fun plusAssignS(e1,e2)= PT.Expr(PT.Binop(PT.PlusAssign,e1,e2))
    fun postIncX e        = PT.Unop(PT.PostInc, e)
    fun postIncS e        = PT.Expr(PT.Unop(PT.PostInc, e))
    fun postDecX e        = PT.Unop(PT.PostDec, e)
    fun postDecS e        = PT.Expr(PT.Unop(PT.PostDec, e))
    fun starX e           = PT.Unop(PT.Star,e)
    fun sizeofX ct        = PT.Unop(PT.SizeofType(ct),PT.EmptyExpr)
    fun sizeofEX e        = PT.Unop(PT.Sizeof, e)
    fun strIsNonNull name = PT.Binop(PT.Neq,PT.Id name,zero)
    fun subX(e1,e2)       = PT.Binop(PT.Sub, e1, e2)
    fun timesX(e1,e2)     = PT.Binop(PT.Times, e1, e2)
    fun timesAssignS(e1,e2) = PT.Expr(PT.Binop(PT.TimesAssign,e1,e2))
    val emptyS            = (PT.Expr PT.EmptyExpr)
    fun returnS e         = PT.Return(e) 
    fun condX (e1,e2,e3)  = PT.QuestionColon(e1,e2,e3)
    fun fieldX (base, field) = arrowX(PT.Id base, PT.Id field)
    fun getFieldX (base, field) = addrX(fieldX(base,field))


    fun declS (dt : PT.decltype,
	       decr : PT.declarator,
	       init : PT.expression) : PT.statement =
	PT.Decl(PT.Declaration (dt,[(decr,init)]))

    fun varDeclS (ct,v,init) = declS(pctToPDT ct,PT.VarDecr v,init)
    fun varDeclS' (ct,v) = varDeclS(ct,v,PT.EmptyExpr)
    fun mkCommentS s = PT.StatExt(PX.PComment s)

    (* 
     * Makes a list of statements beginning with a case label and 
     * ending with a break statement. 
     *)
    fun   makeSwitchCase (e,[]) =  [PT.CaseLabel (e, PT.Break)]
    |     makeSwitchCase (e,[s]) = [PT.CaseLabel (e, s), PT.Break]
    |     makeSwitchCase (e,s::ss) = ((PT.CaseLabel (e, s))::ss) @ [PT.Break]

    (* 
     * Makes a list of statements beginning with a default label and 
     * ending with a break statement. 
     *)
    fun   makeDefaultCase nil =  [PT.DefaultLabel PT.Break]
    |     makeDefaultCase [s] = [PT.DefaultLabel s, PT.Break]
    |     makeDefaultCase (s::ss) = ((PT.DefaultLabel s)::ss) @ [PT.Break]

    (* Makes a switch statement where each element of cases becomes a case with a break at the end. *)
    fun switchS (e : PT.expression,
		 cases : (PT.expression * PT.statement list) list) =
	let
	    val caseListList = List.map makeSwitchCase cases
	    val caseList = List.concat caseListList
	in
	    PT.Switch(e,PT.Compound caseList)
	end

    (* Makes a switch statement where each element of cases becomes a case with a break at the end
       and d becomes the default case (again with break). *)
    fun switchWithDefS (e : PT.expression,
			cases : (PT.expression * PT.statement list) list,
			d : PT.statement list)  = 
	let
	    val caseListList = List.map makeSwitchCase cases
	    val caseList = List.concat caseListList
	in
	    PT.Switch(e, PT.Compound (caseList @ (makeDefaultCase d)))
	end

    fun unionBranchX (base, name) = dotX(fieldX(base, PNames.unionVal), PT.Id name)
    fun getUnionBranchX (base, name) = addrX(unionBranchX(base, name))

    fun mkCase (swval, rest) =
	case rest
	    of SOME restSs =>
		[PT.CaseLabel(swval, PT.Compound(restSs))]
	  | NONE =>
		[PT.CaseLabel(swval, mkCommentS(" (do nothing) "))]

    fun mkDefCase (rest) =
	case rest
	    of SOME restSs =>
		[PT.DefaultLabel(PT.Compound(restSs))]
	  | NONE =>
		[PT.DefaultLabel(mkCommentS(" (do nothing) "))]

    fun mkCommentCase (swval, comment, rest) =
	case rest
	    of SOME restSs =>
		[PT.CaseLabel(swval, PT.Compound([mkCommentS(comment), PT.Compound(restSs)]))]
	  | NONE =>
		[PT.CaseLabel(swval, mkCommentS(comment))]

    fun mkDefCommentCase (comment, rest) =
	case rest
	    of SOME restSs =>
		[PT.DefaultLabel(PT.Compound([mkCommentS(comment), PT.Compound(restSs)]))]
	  | NONE =>
		[PT.DefaultLabel(mkCommentS(comment))]

    fun mkBreakCase (swval, rest) =
	case rest
	    of SOME restSs =>
		[PT.CaseLabel(swval, PT.Compound(restSs @ [PT.Break]))]
	  | NONE =>
		[PT.CaseLabel(swval, PT.Compound([mkCommentS(" (do nothing) "), PT.Break]))]

    fun mkDefBreakCase (rest) =
	case rest
	    of SOME restSs =>
		[PT.DefaultLabel(PT.Compound(restSs @ [PT.Break]))]
	  | NONE =>
		[PT.DefaultLabel(PT.Compound([mkCommentS(" (do nothing) "), PT.Break]))]

    fun mkCommentBreakCase (swval, comment, rest) =
	case rest
	    of SOME restSs =>
		[PT.CaseLabel(swval, PT.Compound([mkCommentS(comment), PT.Compound(restSs @ [PT.Break])]))]
	  | NONE =>
		[PT.CaseLabel(swval, PT.Compound([mkCommentS(comment), PT.Break]))]

    fun mkDefCommentBreakCase (comment, rest) =
	case rest
	    of SOME restSs =>
		[PT.DefaultLabel(PT.Compound([mkCommentS(comment), PT.Compound(restSs @ [PT.Break])]))]
	  | NONE =>
		[PT.DefaultLabel(PT.Compound([mkCommentS(comment), PT.Break]))]


    fun andBools [] = trueX
      | andBools [bX] = bX
      | andBools (cX::cXs) = andX(cX, andBools cXs)

    fun makeStructEDecl (fields : (string*PT.ctype*string option) list, tag : string option) =
        PT.ExternalDecl(
          PT.Declaration(
              pctToPDT(makeStructPCT(fields,tag)),
              []))

    fun makeTyDefStructEDecl (fields : (string*PT.ctype * string option) list, tag : string) =
        PT.ExternalDecl(
          PT.Declaration(
              pctToPTyDefDT(makeStructPCT(fields,SOME (tag^"_s"))),
              [(PT.VarDecr tag, PT.EmptyExpr)]))

    fun makeTyDefUnionEDecl (fields : (string*PT.ctype * string option) list, tag : string) =
        PT.ExternalDecl(
          PT.Declaration(
              pctToPTyDefDT(makeUnionPCT(fields,SOME (tag^"_u"))),
              [(PT.VarDecr tag, PT.EmptyExpr)]))

    fun makeTyDefEnumEDecl (fields : (string * PT.expression * string option) list, tag : string) =
        PT.ExternalDecl(
          PT.Declaration(
              pctToPTyDefDT(makeEnumPCT(fields,SOME (tag^"_e"))),
              [(PT.VarDecr tag, PT.EmptyExpr)]))


    fun makeTyDefEDecl (oldpct : PT.ctype, newName:string) =
        PT.ExternalDecl(
          PT.Declaration(
              pctToPTyDefDT(oldpct),
              [(PT.VarDecr newName, PT.EmptyExpr)]))

    (* Makes only the declaration, without definition. *)
    fun mkFunEDeclNoDef(funName, paramList, retTy) =
	PT.ExternalDecl 
	    (PT.Declaration
		 (pctToPDT retTy,
		  [(PT.FuncDecr (PT.VarDecr funName, paramList),PT.EmptyExpr)]))
	    
    fun mkFunctionEDecl(funName, paramList, bodyS, retTy:PT.ctype) =
           PT.FunctionDef
              {body = bodyS,
               funDecr = PT.FuncDecr(PT.VarDecr funName, paramList),
               krParams = [],
               retType = pctToPDT retTy}

    fun stripExp p =
        case p
        of PT.MARKexpression (loc,e) => stripExp e
        |  PT.Unop (rator,exp) => PT.Unop (rator, stripExp exp)
        |  PT.Binop (rator, e1,e2)  => PT.Binop (rator, stripExp e1, stripExp e2)
        |  PT.QuestionColon (e1,e2,e3) => PT.QuestionColon (stripExp e1,stripExp e2, stripExp e3)
        |  PT.Call (e,es) => PT.Call (stripExp e, List.map stripExp es)
        |  PT.Cast(ct,e) => PT.Cast(ct, stripExp e)
        |  PT.InitList es => PT.InitList (List.map stripExp es)
        |  p => p
    fun ppPL nested = if nested then "(" else ""
    fun ppPR nested = if nested then ")" else ""
    fun expToString {nested} p =
        case p
        of PT.EmptyExpr => ""
        |  PT.IntConst (i,isChar) => if isChar then Char.toString(Char.chr (IntInf.toInt i))
	                             else IntInf.toString i
        |  PT.RealConst r => Real.toString r
        |  PT.String s => "\"" ^ s ^ "\""
        |  PT.Id s => s
        |  PT.Unop uexp => printUnopExp {nested=nested} uexp
        |  PT.Binop binexp => printBinopExp {nested=nested} binexp
        |  PT.QuestionColon (e1,e2,e3) => (ppPL nested)^
	                                  (expToString {nested = true} e1)^ " ? " ^
                                          (expToString {nested = false} e2)^ " : " ^
                                          (expToString {nested = false} e3)^
					  (ppPR nested)
        |  PT.Call (e,es) => (expToString {nested=true} e)^"("^(printExpList "," es) ^")"
        |  PT.Cast (ct, e) => (ppPL nested)^"(ctype)"^(expToString {nested=true}e)^(ppPR nested)
        |  PT.MARKexpression (loc,e) => expToString {nested=nested}e
        |  _ => ""

    and printUnopExp {nested} (rator, exp) =
	case rator
        of PT.Star =>   (ppPL nested)^"*"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.AddrOf => (ppPL nested)^"&"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.Sizeof => (ppPL nested)^"sizeof("^(expToString {nested=false}exp)^")"^(ppPR nested)
        |  PT.PreInc => (ppPL nested)^"++"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.PostInc =>(ppPL nested)^ (expToString {nested=true} exp)^"++"^(ppPR nested)
        |  PT.PreDec => (ppPL nested)^ "--"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.PostDec =>(ppPL nested)^ (expToString {nested=true} exp)^"--"^(ppPR nested)
        |  PT.Not =>    (ppPL nested)^"!"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.Negate => (ppPL nested)^"-"^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.BitNot => (ppPL nested)^"~ "^(expToString {nested=true} exp)^(ppPR nested)
        |  PT.Uplus =>  (ppPL nested)^"+ "^(expToString {nested=true} exp)^(ppPR nested)
        |  (PT.SizeofType ct) => "sizeof(" ^ "ctype" ^")"
        |  _ => "unop(" ^ (expToString {nested = false}exp) ^")"

    and printBinopExp {nested} (rator, exp1, exp2) =
        let fun ppB mid = (ppPL nested)^(expToString {nested=true} exp1)^ mid ^(expToString {nested=false} exp2)^(ppPR nested)
	in
	case rator
        of PT.Plus =>   ppB " + "
        |  PT.Minus =>  ppB " - " 
        |  PT.Times =>  ppB " * " 
        |  PT.Divide => ppB " / "
        |  PT.Mod =>    ppB " % "
        |  PT.Gt =>     ppB " > " 
        |  PT.Lt =>     ppB " < " 
        |  PT.Gte =>    ppB " >= " 
        |  PT.Lte => ppB " <= " 
        |  PT.Eq => ppB " == " 
        |  PT.Neq => ppB " != " 
        |  PT.And => ppB " && " 
        |  PT.Or => ppB " || " 
        |  PT.BitOr => ppB " | "
        |  PT.BitAnd => ppB " & "
        |  PT.BitXor => ppB " ^ "
        |  PT.Lshift => ppB " << "
        |  PT.Rshift => ppB " >> "
        |  PT.Dot =>    ppB "."
        |  PT.Arrow =>  ppB "->"
        |  PT.Sub =>    (expToString {nested=true} exp1)^ "[" ^(expToString {nested=false} exp2)^ "]" 
        |  PT.Comma => "("^(expToString {nested=false} exp1)^ ", " ^(expToString {nested=false} exp2)^ ")" 
        |  PT.Assign => ppB " = "
        |  PT.PlusAssign => ppB " += "
        |  PT.MinusAssign => ppB " -= "
        |  PT.TimesAssign => ppB " *= "
        |  PT.DivAssign => ppB " /= " 
        |  PT.ModAssign => ppB " %= " 
        |  PT.XorAssign => ppB " ^= " 
        |  PT.OrAssign => ppB " |= " 
        |  PT.AndAssign => ppB " &= " 
        |  PT.LshiftAssign => ppB " <<= " 
        |  PT.RshiftAssign => ppB " >>= " 
        |  _ => ppB "binop" 
	end

    and printExpList s [] = ""
      | printExpList s [e] = expToString {nested=false} e
      | printExpList s (e::es) = ((expToString {nested=false} e) ^ s ^ " " ^ (printExpList s es))

    val expToString = expToString {nested = false}

    fun substPostCond subs [] = []
      | substPostCond subs (x::xs) = 
	let val rest = (substPostCond subs xs)
	in
	    case x of PX.General x  => 	  (PX.General (PTSub.substExps subs x)) :: rest 
            | PX.ParseCheck x      => 	  (PX.ParseCheck (PTSub.substExps subs x)) :: rest 
	end

    fun isFreeInPostCond subs [] = false
      | isFreeInPostCond subs (x::xs) = 
	let val rest = (isFreeInPostCond subs xs)
	    val core = case x of PX.General e => e | PX.ParseCheck e => e
	in
	    PTSub.isFreeInExp(subs, core) andalso rest
	end
    
    fun getIsPredXs [] = []
	| getIsPredXs (x::xs) = case x of PX.General e => e :: (getIsPredXs xs) | _ => (getIsPredXs xs)

    fun getPredXs [] = []
	| getPredXs (x::xs) = case x of PX.General e => e :: (getPredXs xs) | PX.ParseCheck e => e :: (getPredXs xs)


    (* Functions for walking over lists of struct or union elements *)
    
    fun mungeField f b m (PX.Full fd) = f fd
      | mungeField f b m (PX.Brief e) = b e
      | mungeField f b m (PX.Manifest md) = m md
    fun mungeFields f b m [] = []
      | mungeFields f b m (x::xs) = (mungeField f b m x) @ (mungeFields f b m xs)

    fun tyName (ty:PX.Pty) = case ty of PX.Name s => s


end


