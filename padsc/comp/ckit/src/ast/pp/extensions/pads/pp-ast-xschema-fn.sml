(*

  This module implements the PADS to XML Schema mapping rules in
  pads/documents/pads-to-schema-mapping.txt.  They are also included
  inline as comments here.

  A PADS description has a structurally isomorphic definition in XML
  Schema and, correspondingly, a PADS data file has a structurally
  isomorphic representation in XML, such that the following constraint
  holds:
  
    For any PADS description X.p and 
        any X.data that conforms to X.p,
    If [[ X.p ]]_schema == X.xsd and [[ X.data ]]_data == X.xml
    Then X.xml conforms to X.xsd
  
  where [[ ]]_schema is the mapping from a PADS description to an XML
  schema and [[ ]]_data is the mapping from PADS data to XML. 
  
  The following rewrite rules define the mapping [[ ]]_schema.  
  
  Each PADS type in the source PDL is mapped to a list of global schema
  declarations (a complex type, a simple type, or an element):
  
     [[ PADS type decl ]]_schema == XML Schema Declaration

*)
functor PPAstXschemaFn (structure PPAstPaidAdornment : PPASTPAIDADORNMENT) : PP_XML_AST = struct 

  structure Tid = Tid
  structure Pid = Pid
  structure PP = OldPrettyPrint
  structure B = Bindings
  structure PPAA = PPAstPaidAdornment
  structure PPAE = PPAstExtFn (type aidinfo = PPAstPaidAdornment.aidinfo);
  structure PPL = PPLib

  open PPLib
  open Ast
  open PTyUtils

  type aidinfo = PPAE.aidinfo
  type paidinfo = PPAstPaidAdornment.paidinfo
  type ptyinfo = PTys.pTyInfo

  val printLocation = false (* internal flag - pretty print locations as comments *)

  fun ppLoc pps (SourceMap.LOC {srcFile, beginLine, beginCol, endLine, endCol}) =
      if printLocation then ( PPL.addStr pps "/*["
			    ; PPL.addStr pps (srcFile)
			    ; PPL.addStr pps ":"
			    ; PPL.addStr pps (Int.toString beginLine)
			    ; PPL.addStr pps "]*/ "
			    )
      else ()
    | ppLoc pps _ = ()

  val warning = PPL.warning

  val ppLParen = PPL.ppGuarded "("

  val ppRParen = PPL.ppGuarded ")"

  val optionalFacet = SOME("0", "1")
  val unboundedFacet = SOME("0", "unbounded")

  fun getCtype ({stClass,ctype,...}: Ast.id) = (stClass,ctype)

(* Type-name munging functions *)

(*

   A reference to a base type in a PADS field is mapped to a reference
   to the corresponding complex type in the pads.xsd namespace, and is
   enclosed in quotes:

       [[ base_ty ]]_field_typename 
            ==
       "\"p:val_" ^ base_ty ^ "\""

   Any other reference to a base type is mapped to the corresponding
   base type in the pads.xsd namespace, and is enclosed in quotes:

       [[ base_ty ]]_typename 
            ==
       "\"p:" ^ base_ty ^ "\""

   Any reference to a user-defined type is mapped to a reference to
   the corresponding complex type in the empty namespace (i.e., the
   target schema) and is enclosed in quotes:

       [[ ty ]]_field_typename 
         ty not a base type
            ==
           "\"" ^ ty ^ "\""

       [[ ty ]]_typename 
         ty not a base type
            ==
           "\"" ^ ty ^ "\""

   A reference to a type's parse descriptor is just the name of the
   type concatenated with "_pdname":

       [[ identifier ]]_pdname
            ==
       \"[[ identifier ]]^"_pdname"\"

*)
  fun strip suf s = String.extract(s, 0, SOME (String.size s - String.size suf))
      
  fun isSuffix suf s = 
      if String.size suf >= String.size s then false
      else let val schars = String.explode s
	       val endStr = String.implode (
					    List.drop (schars, String.size s - String.size suf))
	   in
	       endStr = suf
	   end

  fun stripAll s = if isSuffix "_pd" s 
		       then strip "_pd" s
		   else if isSuffix "_tag" s
			    then strip "_tag" s
			else if isSuffix "_pd_u" s
				 then strip "_pd_u" s
			     else if isSuffix "\" minOccurs=\"0\" maxOccurs=\"unbounded" s
				      then strip "\" minOccurs=\"0\" maxOccurs=\"unbounded" s
				  else s 

  (* An XML Schema type attribute *)
  fun isBaseTypeName s = 
      not(Option.isSome (PTys.find (Atom.atom (stripAll s))))
(* PBaseTys.isBaseTy(PBaseTys.baseInfo, ParseTreeExt.Name (stripAll s))  *)

  fun typeAttribute s = (" type=\"" ^ s ^ "\"")

  fun mapBaseTypeName name = 
      if isBaseTypeName (name) then ("p:"^name) else name
  
  fun mapFieldTypeName name = 
      if isBaseTypeName (name) then ("p:val_"^name) else name

  fun makeFieldNames facet flds = 
      List.map (fn (t,n) => (mapFieldTypeName, t, n, facet)) flds 

  fun makeBaseNames flds = 
      List.map (fn (t,n) => (mapBaseTypeName, t, n, NONE)) flds 

  fun mapPdName s = 
      if isBaseTypeName s then ("p:Pbase_pd") else s^"_pd"

  fun isPostFix PostInc = true
    | isPostFix PostDec = true
    | isPostFix _ = false

  fun ppBinop aidinfo tidtab pps binop = 
      case binop
	of Plus   => PPL.addStr pps "+"
         | Minus  => PPL.addStr pps "-"
	 | Times  => PPL.addStr pps "*"
	 | Divide => PPL.addStr pps "/"
	 | Mod    => PPL.addStr pps "%"
	 | Gt     => PPL.addStr pps ">"
	 | Lt     => PPL.addStr pps "<"
	 | Gte    => PPL.addStr pps ">="
	 | Lte    => PPL.addStr pps "<="
	 | Eq     => PPL.addStr pps "=="
	 | Neq    => PPL.addStr pps "!="
	 | And    => PPL.addStr pps "&&"
	 | Or     => PPL.addStr pps "||"
	 | BitOr  => PPL.addStr pps "|"
	 | BitAnd => PPL.addStr pps "&"
	 | BitXor => PPL.addStr pps "^"
	 | Lshift => PPL.addStr pps "<<"
	 | Rshift => PPL.addStr pps ">>"
	 | PlusAssign   => PPL.addStr pps "+="
	 | MinusAssign  => PPL.addStr pps "-="
	 | TimesAssign  => PPL.addStr pps "*="
	 | DivAssign    => PPL.addStr pps "/="
	 | ModAssign    => PPL.addStr pps "%="
	 | XorAssign    => PPL.addStr pps "^="
	 | OrAssign     => PPL.addStr pps "|="
	 | AndAssign    => PPL.addStr pps "&="
	 | LshiftAssign => PPL.addStr pps "<<="
	 | RshiftAssign => PPL.addStr pps ">>="
	 | BinopExt be => PPAE.ppBinopExt aidinfo tidtab pps be

  fun ppUnop aidinfo tidtab pps unop = 
      case unop
	of Uplus   => PPL.addStr pps "+"
         | Not     => PPL.addStr pps "!"
	 | Negate  => PPL.addStr pps "-"
	 | BitNot  => PPL.addStr pps "~"
	 | PreInc  => PPL.addStr pps "++"
	 | PostInc => PPL.addStr pps "++"
	 | PreDec  => PPL.addStr pps "--"
	 | PostDec => PPL.addStr pps "--"
	 | UnopExt ue => PPAE.ppUnopExt aidinfo tidtab pps ue

  datatype Identifier
    = ID of Ast.id
    | MEMBER of Ast.member
    | TID of Tid.uid

  datatype params = 
      EMPTY
    | ANSI of Ast.id list
    | KNR of Ast.id list

  datatype ctStkItem
    = Arr of (IntInf.int * Ast.expression) option
    | Qua of Ast.qualifier
    | Fun of Ast.ctype list * params
    | Ptr 


  val printConst = ref true (* PADS *)

  fun ppIdentifier tidtab pps =
      fn (ID id) => ppId pps id
       | (MEMBER member) => ppMember pps member
       | (TID tid) => ppTid tidtab pps tid

  fun ppQualifier pps qf = 
    let val s = case qf
	          of CONST => if !printConst then "const " else ""
		   | VOLATILE => "volatile "
    in addStr pps s end

  fun ppStorageClass pps sc = 
    let val s = case sc
	          of STATIC => "static "
		   | EXTERN => "extern "
		   | REGISTER => "register "
		   | AUTO => ""
		   | DEFAULT => ""
    in addStr pps s end

      
  fun ppSignedness pps sign = 
    let val s = case sign
	          of SIGNED   => ""
		   | UNSIGNED => "unsigned "
    in addStr pps s end

  fun ppFractionality pps frac = 
    let val s = case frac 
	          of FRACTIONAL  => "fractional "
		   | WHOLENUM => ""
    in addStr pps s end

  fun ppSaturatedness pps sat = 
    let val s = case sat
	          of SATURATE   => "saturate "
		   | NONSATURATE => ""
    in addStr pps s end

  fun ppIntKind pps ik = 
    let val s = case ik
	          of CHAR   => "char"
		   | SHORT  => "short"
		   | INT    => "int"
		   | LONG   => "long"
		   | LONGLONG   => "long long"
		   | FLOAT  => "float"
		   | DOUBLE => "double"
		   | LONGDOUBLE => "long double"
    in addStr pps s end

  fun ppStk aidinfo tidtab pps (idOpt,stk) =
        let fun loop (prev,[]) = ppOpt (ppIdentifier tidtab) pps idOpt
	      | loop (prev,(Qua qf)::l) =
		  (ppQualifier pps qf
		  ;loop (prev,l)
		  )
	      | loop (prev,(a as Arr opt)::l) =
		  (loop (a,l)
		  ;addStr pps "["
		  ;(case opt of
		      SOME(i, expr) => ppExpr {nested=false} aidinfo tidtab pps expr
		    | NONE => ())
		  ;addStr pps "]"
		  )
	      | loop (prev, ((f as Fun (cts,idsOpt))::l)) =
		 (loop (f,l)
		 ;space pps
		 ;case idsOpt 
		    of EMPTY =>
		         ppList {pp=ppCtype aidinfo tidtab
				,sep=","
				,lDelim="("
				,rDelim=")"
				} pps cts
		     | ANSI ids => 
			 ppList {pp=ppIdDecl aidinfo tidtab
				,sep=","
				,lDelim="("
				,rDelim=")"
				} pps ids
		     | KNR ids => 
			 ppList {pp=ppId
				,sep=","
				,lDelim="("
				,rDelim=")"
				} pps ids
		 )
	      | loop (Ptr,p::l) =
		  (addStr pps "*"
		  ;loop (Ptr,l)
		  )
	      | loop (_,Ptr::l) =
		  (addStr pps "("
		  ;addStr pps "*"
		  ;loop (Ptr,l)
		  ;addStr pps ")"
		  )
	in loop (Ptr,stk) end

  and ppSpStk aidinfo tidtab pps (pair as (NONE,[])) = ppStk aidinfo tidtab pps pair
    | ppSpStk aidinfo tidtab pps (pair as (_,stk)) = (space pps; ppStk aidinfo tidtab pps pair)

  and ppDecl0 aidinfo tidtab pps (idOpt,idsOpt,ctype) =
    let fun loop (idsOpt,ctype,stk) = 
	  case ctype
	    of Void =>
		 (addStr pps "void"
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 )
	     | Ellipses => 
		 (case stk
		    of [] => addStr pps "..."
		     | _  => (warning
			        "ppDecl"
				"ill-formed ellipses type"
			     ;addStr pps "..."
			     ))
	     | Qual (qf,ct) =>
		   loop (idsOpt,ct,(Qua qf)::stk)
	     | Numeric (NONSATURATE,WHOLENUM, _, CHAR, SIGNASSUMED)  => 
		 (addStr pps "char"
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 ) 
	     | Numeric (NONSATURATE,WHOLENUM, SIGNED, CHAR, SIGNDECLARED)  => 
		 (addStr pps "signed char"
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 ) 
	     | Numeric (NONSATURATE,WHOLENUM, UNSIGNED, CHAR, SIGNDECLARED)  => 
		 (addStr pps "unsigned char"
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 ) 
	     | Numeric (sat, frac, sign, ik, _) =>
		 (ppSaturatedness pps sat
		 ;ppFractionality pps frac
		 ;ppSignedness pps sign
		 ;ppIntKind pps ik
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 )
	     | Array (opt,ct) => loop (idsOpt,ct,Arr opt::stk)
	     | Pointer ct =>  loop (idsOpt,ct,Ptr::stk)
	     | Function (ct,cts) => loop (EMPTY,ct,Fun (cts,idsOpt)::stk)
	     | EnumRef tid => 
		 (case Tidtab.find (tidtab,tid)
		    of SOME {ntype=SOME (B.Enum _),...} => 
			(addStr pps "enum "
			;ppTid tidtab pps tid
			)
		     | _ => (* print out partially defined enums *)
			(addStr pps "enum "
			;ppTid tidtab pps tid
			)
			(* addStr pps ("EnumRef(" ^ (Tid.toString tid) ^ ")") *)
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 )	 
	     | StructRef tid =>
		 (addStr pps "struct "
		 ;ppTid tidtab pps tid
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk))
	     | UnionRef tid =>
		 (addStr pps "union "
		 ;ppTid tidtab pps tid
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk))
	     | TypeRef tid => 
		 (case Tidtab.find (tidtab,tid)
		    of SOME {ntype=SOME (B.Typedef _),...} => ppTid tidtab pps tid
		     | _ => addStr pps ("TypeRef(" ^ (Tid.toString tid) ^ ")")
		 ;ppSpStk aidinfo tidtab pps (idOpt,stk)
		 )
	     | Error => (addStr pps "/* ErrorType */ "
			;ppSpStk aidinfo tidtab pps (idOpt,stk))
    in loop (idsOpt,ctype,[]) end

  and ppCtype aidinfo tidtab pps ctype = ppDecl0 aidinfo tidtab pps (NONE,EMPTY,ctype)
      
  (* Note: id is only used for printing purposes.
   All information needed to interpret a type is obtained via tid *)
  and ppNamedCtype aidinfo tidtab pps nct = 
    let fun ppOptList ppElt sep [] = ()
	  | ppOptList ppElt sep l = 
	    (addStr pps "{"
	    ;blockify 2 (separate (ppElt,fn pps => (addStr pps sep; newline pps))) pps l
	    ;newline pps
	    ;addStr pps "}"
	    )
	fun pseparate (ppElt, sep, ppTrail) pps [] = ()
          | pseparate (ppElt, sep, ppTrail) pps [x] = (ppElt pps x; ppTrail pps x)
	  | pseparate (ppElt, sep, ppTrail) pps (x::xs) = 
              (ppElt pps x; sep pps; ppTrail pps x; pseparate(ppElt,sep,ppTrail) pps xs)
	fun ppOptList2 ppElt sep ppTrail [] = ()
	  | ppOptList2 ppElt sep ppTrail l = 
	    (addStr pps "{"
	    ;blockify 2 (pseparate (ppElt,fn pps => (addStr pps sep), 
				    fn pps => (fn x => (ppTrail pps x; newline pps)))) pps l
	    ;addStr pps "}"
	    )
    in case nct
	 of B.Struct (tid,members) =>
	      let fun ppLI' pps li = (addStr pps ":"; ppLI pps (IntInf.toLarge li))

		  fun ppMember pps (ct, memberOpt, LIOpt, strOpt) = (* strOpt is PADS *)
		    (ppDecl0 aidinfo tidtab pps (Option.map MEMBER memberOpt,EMPTY,ct)
		    ;ppOpt ppLI' pps LIOpt
		    ;addStr pps ";"
		    ;(case strOpt of SOME s => addStr pps ("\t\t/* "^ s ^" */")
			          | NONE => () (* PADS *))
		    )

	      in (addStr pps "struct "
		 ;ppTid tidtab pps tid
		 ;space pps
		 ;ppOptList ppMember "" members)
	      end
	  | B.Union (tid,members) =>
	      let 
		  fun ppMember pps (ct, member,strOpt) =
		    (ppDecl0 aidinfo tidtab pps (SOME(MEMBER member),EMPTY,ct)
		    ;addStr pps ";"
		    ;(case strOpt of SOME s => addStr pps ("\t\t/* "^ s ^" */")
			          | NONE => () (* PADS *))
		    )
	      in addStr pps "union "
		;ppTid tidtab pps tid
		;space pps
	        ;ppOptList ppMember "" members
	      end
          | B.Enum (tid,members) =>
	        let fun ppMemberInt pps (member,li,commentOpt) =  (* commentOpt is PADS *)
		      (ppMember pps member
		      ;addStr pps "="
		      ;ppLI pps (IntInf.toLarge li)
		      )
		    fun ppTrail pps (member,li,commentOpt) = 
			(case commentOpt of SOME s => addStr pps ("\t\t/* "^ s ^" */")
			          | NONE => () (* PADS *))
		in (addStr pps "enum "
		   ;ppTid tidtab pps tid
		   ;space pps
		   ;ppOptList2 ppMemberInt "," ppTrail members
		   )
		end
	  | B.Typedef (tid,ctype) =>
	      (addStr pps "typedef "
	      ;ppDecl0 aidinfo tidtab pps (SOME (TID tid),EMPTY,ctype)
	      )
    end 


  and ppDecl aidinfo tidtab pps (id,ct) = ppDecl0 aidinfo tidtab pps (SOME (ID id),EMPTY,ct)

  and ppDeclaration aidinfo tidtab pps (TypeDecl{shadow=NONE, tid}) = 
       (case Tidtab.find (tidtab,tid)
	  of SOME {ntype=SOME nct,location,...} => 
	       (ppLoc pps location; ppNamedCtype aidinfo tidtab pps nct)
	   | _ => (warning
		     "ppCoreStmt" 
		     ("No type associated with tid:"^(Tid.toString tid));
		   PPL.addStr pps "...");
        PPL.addStr pps ";")
    | ppDeclaration aidinfo tidtab pps (TypeDecl{shadow=SOME{strct=true}, tid}) = 
	  (PPLib.addStr pps "struct "
	  ;PPLib.ppTid tidtab pps tid
	  ;PPL.addStr pps ";")
    | ppDeclaration aidinfo tidtab pps (TypeDecl{shadow=SOME{strct=false}, tid}) = 
	  (PPLib.addStr pps "union "
	  ;PPLib.ppTid tidtab pps tid
	  ;PPL.addStr pps ";")
    | ppDeclaration aidinfo tidtab pps (VarDecl (id as {location,...}, initOpt)) = 
       (ppLoc pps location
       ;ppIdDecl aidinfo tidtab pps id
       ;case initOpt
	  of SOME initExpr => 
	      (PPL.addStr pps "=";
	       ppInitExpression aidinfo tidtab pps initExpr)
	   | NONE => ()
       ;PPL.addStr pps ";")

  and ppIdDecl aidinfo tidtab pps (id: Ast.id) =
    let val (stClass,ctype) = getCtype id
    in (ppStorageClass pps stClass
       ;ppDecl aidinfo tidtab pps (id,ctype)
       )
    end

  and blockStmt aidinfo tidtab pps stmt = PPL.blockify 2 (ppStmt aidinfo tidtab) pps stmt

  and ppStmt aidinfo tidtab pps (stmt as (STMT (_,_,loc))) = 
      ( ppLoc pps loc
      ; PPAA.ppStatementAdornment ppCoreStmt aidinfo tidtab pps stmt
      )

  and ppCoreStmt aidinfo tidtab pps coreStmt = 
    case coreStmt
      of Expr expOpt => 
	   ( PPL.ppOpt (ppExpr {nested=false} aidinfo tidtab) pps expOpt
	   ; PPL.addStr pps ";"
	   )
       | Compound (decls,stmts) => 
	   ( PPL.addStr pps "{"
	   ; (case decls of 
		nil => ()
	      | _ => PPL.blockify 2 (PPL.separate (ppDeclaration aidinfo tidtab, PPL.newline)) pps decls)
	   ; (case stmts of
		nil => ()
	      | _ => PPL.blockify 2 (PPL.separate (ppStmt aidinfo tidtab, PPL.newline)) pps stmts)
	   ; PPL.newline pps
	   ; PPL.addStr pps "}"
	   )
       | While (exp,stmt) => 
	   ( PPL.addStr pps "while ("
	   ; ppExpr {nested=false} aidinfo tidtab pps exp
	   ; PPL.addStr pps ")"
	   ; blockStmt aidinfo tidtab pps stmt
	   )
       | Do (exp,stmt) => 
	   ( PPL.addStr pps "do"
	   ; blockStmt aidinfo tidtab pps stmt
	   ; PPL.newline pps
	   ; PPL.addStr pps "while ("
	   ; ppExpr {nested=false} aidinfo tidtab pps exp
	   ; PPL.addStr pps ");"
	   )
       | For (expOpt0,expOpt1,expOpt2,stmt) =>
	   ( PPL.addStr pps "for ("
	   ; PPL.ppOpt (ppExpr {nested=false} aidinfo tidtab) pps expOpt0
	   ; PPL.addStr pps "; "
	   ; PPL.ppOpt (ppExpr {nested=false} aidinfo tidtab) pps expOpt1
	   ; PPL.addStr pps "; "
	   ; PPL.ppOpt (ppExpr {nested=false} aidinfo tidtab) pps expOpt2
	   ; PPL.addStr pps ")"
	   ; blockStmt aidinfo tidtab pps stmt
	   )
       | Labeled (label,stmt) => 
	   ( PPL.bBlock pps PP.INCONSISTENT ~2
	   ; PPL.newline pps
	   ; PPL.ppLabel pps label
	   ; PPL.addStr pps ": "
	   ; PPL.eBlock pps
	   ; PPL.newline pps
	   ; ppStmt aidinfo tidtab pps stmt
	   )
       | CaseLabel (li,expOpt (*PADS *), stmt) => 
	   ( PPL.bBlock pps PP.INCONSISTENT ~2
	   ; PPL.newline pps
	   ; PPL.addStr pps "case "
	   ; (case expOpt of NONE => PPL.ppLI pps (IntInf.toLarge li)
	                  | SOME exp => (ppExpr {nested=false} aidinfo tidtab) pps exp)
	   ; PPL.addStr pps ": "
	   ; PPL.eBlock pps
	   ; PPL.newline pps
	   ; ppStmt aidinfo tidtab pps stmt
	   )
       | DefaultLabel stmt => 
	   ( PPL.bBlock pps PP.INCONSISTENT ~2
	   ; PPL.newline pps 
	   ; PPL.addStr pps "default: "
	   ; PPL.eBlock pps
	   ; PPL.newline pps
	   ; ppStmt aidinfo tidtab pps stmt
	   )
       | Goto label => 
	   ( PPL.addStr pps "goto "
	   ; PPL.ppLabel pps label
	   ; PPL.addStr pps ";"
	   )
       | Break => PPL.addStr pps "break;"
       | Continue => PPL.addStr pps "continue;"
       | Return expOpt => 
	   ( PPL.addStr pps "return "
	   ; PPL.ppOpt (ppExpr {nested=false} aidinfo tidtab) pps expOpt
	   ; PPL.addStr pps ";"
	   )
       | IfThen (exp,stmt) => 
	   ( PPL.addStr pps "if ("
	   ; ppExpr {nested=false} aidinfo tidtab pps exp
	   ; PPL.addStr pps ") "
	   ; blockStmt aidinfo tidtab pps stmt
	   )
       | IfThenElse (exp,stmt0,stmt1) => 
	   ( PPL.addStr pps "if ("
	   ; ppExpr {nested=false} aidinfo tidtab pps exp
	   ; PPL.addStr pps ") "
	   ; blockStmt aidinfo tidtab pps stmt0
	   ; PPL.newline pps
	   ; PPL.addStr pps "else"
	   ; blockStmt aidinfo tidtab pps stmt1
	   )
       | Switch (exp,stmt) =>
	   ( PPL.addStr pps "switch ("
	   ; ppExpr {nested=false} aidinfo tidtab pps exp
	   ; PPL.addStr pps ")"
	   ; blockStmt aidinfo tidtab pps stmt
	   )
       | ErrorStmt =>
	   ( PPL.addStr pps "/* ErrorStmt */"
	   )
    | StatExt se => PPAE.ppStatementExt (ppExpr {nested=false},ppStmt,ppBinop,ppUnop) aidinfo tidtab pps se

  and ppExpr nested aidinfo tidtab pps expr =
       PPAA.ppExpressionAdornment (ppCoreExpr nested) aidinfo tidtab pps expr

  and ppCoreExpr {nested} aidinfo tidtab pps coreExpr = 
    case coreExpr
      of IntConst li => PPL.ppLLI pps li
       | RealConst r => PPL.ppReal pps r
       | StringConst s => PPL.ppString pps s
       | Call (exp,exps) => 
	   ( ppExpr {nested=true} aidinfo tidtab pps exp
	   ; PPL.space pps
	   ; PPL.ppList { pp=ppExpr {nested=false} aidinfo tidtab
		        , sep=","
		        , lDelim="("
		        , rDelim=")"
		        } pps exps
	   )
       | QuestionColon (e0,e1,e2) =>
	   ( ppLParen nested pps 
	   ; ppExpr {nested=true} aidinfo tidtab pps e0
	   ; PPL.addStr pps " ? "
	   ; ppExpr {nested=false} aidinfo tidtab pps e1
	   ; PPL.addStr pps " : "
	   ; ppExpr {nested=false} aidinfo tidtab pps e2
	   ; ppRParen nested pps 
	   )
       | Assign (e0,e1) =>
	   ( ppLParen nested pps 
	   ; ppExpr {nested=false} aidinfo tidtab pps e0
	   ; PPL.addStr pps " = "
	   ; ppExpr {nested=true} aidinfo tidtab pps e1
	   ; ppRParen nested pps 
	   )
       | Comma (e0,e1) =>
	   ( PPL.addStr pps "("
	   ; ppExpr {nested=false} aidinfo tidtab pps e0
	   ; PPL.addStr pps ","
	   ; ppExpr {nested=false} aidinfo tidtab pps e1
	   ; PPL.addStr pps ")"
	   )
       | Sub (e0,e1) =>
	   ( ppExpr {nested=true} aidinfo tidtab pps e0
	   ; PPL.addStr pps "["
	   ; ppExpr {nested=false} aidinfo tidtab pps e1
	   ; PPL.addStr pps "]"
	   )
       | Member (exp,member) =>
	   ( ppLParen nested pps 
	   ; ppExpr {nested=true} aidinfo tidtab pps exp
	   ; PPL.addStr pps "."
	   ; PPL.ppMember pps member
	   ; ppRParen nested pps 
	   )
       | Arrow (exp,member) =>
	   ( ppLParen nested pps 
	   ; ppExpr {nested=true} aidinfo tidtab pps exp
	   ; PPL.addStr pps "->"
	   ; PPL.ppMember pps member
	   ; ppRParen nested pps 
	   )
       | Deref exp => 
	   ( ppLParen nested pps 
	   ; PPL.addStr pps "*"
	   ; ppExpr {nested=true} aidinfo tidtab pps exp
	   ; ppRParen nested pps 
	   )
       | AddrOf exp => 
	   ( ppLParen nested pps 
	   ; PPL.addStr pps "&"
	   ; ppExpr {nested=true} aidinfo tidtab pps exp
	   ; ppRParen nested pps 
	   )
       | Binop (binop,exp0,exp1) => 
	   ( ppLParen nested pps 
	   ; ppExpr {nested=true} aidinfo tidtab pps exp0
	   ; ppBinop aidinfo tidtab pps binop
	   ; ppExpr {nested=true} aidinfo tidtab pps exp1
	   ; ppRParen nested pps 
	   )
       | Unop (unop,exp) => 
 	   ( ppLParen nested pps 
 	   ; if (isPostFix unop)
 		 then (ppExpr {nested=true} aidinfo tidtab pps exp; ppUnop aidinfo tidtab pps unop)
 	     else (ppUnop aidinfo tidtab pps unop; ppExpr {nested=true} aidinfo tidtab pps exp)
 	   ; ppRParen nested pps 
 	   )
       | Cast (ctype,exp) => 
	   ( ppLParen nested pps 
	   ; PPL.addStr pps "("
	   ; ppCtype aidinfo tidtab pps ctype
	   ; PPL.addStr pps ") "
	   ; ppExpr {nested=true} aidinfo tidtab pps exp
	   ; ppRParen nested pps 
	   )
       | Id id => PPL.ppId pps id
       | EnumId (id,li) => PPL.ppMember pps id
       | SizeOf ctype =>
	   ( ppLParen nested pps
	   ; PPL.addStr pps "sizeof("
	   ; ppCtype aidinfo tidtab pps ctype
	   ; PPL.addStr pps ")"
	   ; ppRParen nested pps 
	   )

       | ExprExt ee => PPAE.ppExpressionExt (ppExpr {nested=false},ppStmt,ppBinop,ppUnop) aidinfo tidtab pps ee 
       | ErrorExpr => ( warning "ppCoreExpression" "found an error expression"
		      ; PPL.addStr pps "/* error expression */ 0"
		      )

  and ppInitExpression aidinfo tidtab pps initExpr =
      case initExpr 
	of Simple expr => ppExpr {nested=false} aidinfo tidtab pps expr
	 | Aggregate initExprs => 
	     PPL.ppList { pp=ppInitExpression aidinfo tidtab
		        , sep=","
		        , lDelim="{"
		        , rDelim="}"
		        } pps initExprs

  (** PADS to XML XSchema translation **)

  (* ppXMLHeader prints the header for a Schema declaration: 
     opentag [ name="Name" ]  [ type="typeOpt" ] [ min/max facets ] closetag 
  
     If the name of the element is "pd", it is always optional. 
     This is a hack!!!!
  *)
  fun ppXMLHeader opentag closetag pps (mapTypeName, tyNameOpt, name, facets) =	
      ( PPL.addStr pps opentag
      ; 
       let val NameAttr= ("name=\"" ^ name ^ "\"")
           val tyNameAttr = 
	       (case tyNameOpt of 
		   NONE => "" | 
		   SOME name => typeAttribute (mapTypeName name))
	   val facetStr = 
	       (case facets of 
		   NONE => "" | 
		   (SOME (min, max)) => (" minOccurs=\"" ^ min ^ "\" maxOccurs=\"" ^ max ^ "\""))
       in
	   PPL.addStr pps (NameAttr ^ tyNameAttr ^ facetStr)
       end
       ; PPL.addStr pps closetag)


  fun complexTypeOpen pps NameOpt =	
      ( PPL.addStr pps "<xs:complexType "
      ; 
       let val NameAttr = 
	   case NameOpt of 
	       NONE => ""
	     | SOME name => (("name=\"" ^ name ^ "\""))
       in
	   PPL.addStr pps NameAttr 
       end
       ; PPL.addStr pps ">\n")

  fun complexTypeClose pps = PPL.addStr pps "</xs:complexType>\n"

  fun simpleTypeOpen pps NameOpt =	
      ( PPL.addStr pps "<xs:simpleType "
      ; 
       let val NameAttr = 
	   case NameOpt of 
	       NONE => ""
	     | SOME name => (("name=\"" ^ name ^ "\""))
       in
	   PPL.addStr pps NameAttr 
       end
       ; PPL.addStr pps ">\n")

  fun simpleTypeClose pps = PPL.addStr pps "</xs:simpleType>\n"

  fun ppXMLFields pps eFields =			(* list of eFields w/o <seq> *)
      ( PPL.ppList { pp=ppXMLHeader "<xs:element " "/>" 
                      , sep="\n"
                      , lDelim=""
                      , rDelim=""
                      } pps eFields)

  fun ppXMLSequence pps eFields =		(* <seq> eFields </seq> *)
      ( PPL.addStr pps "<xs:sequence>\n"
      ; ppXMLFields pps eFields
      ; newline pps
      ; PPL.addStr pps "</xs:sequence>\n")

  fun ppXMLRestriction pps base =
      PPL.addStr pps ("<xs:restriction base=\"" ^ base ^ "\"/> \n")
      
  fun isIdentity  arg = case arg of
    (_,_,name,_) => name = PNames.identifier 

  fun id s = s

  (*
      <complexType name=[[identifier]]> 
        <sequence>
          [[ fields ]]_local 
        <sequence>
      </complexType>
  *)
  fun ppXMLComplex pps (eNameOpt,eFields) =	
        ( complexTypeOpen pps eNameOpt
        ; ppXMLSequence pps (List.filter (not o isIdentity) eFields) 
        ; complexTypeClose pps)

  (*
      The Psource modifier may be used as an annotation on any Pads type,
      indicating that the type in question describes the entirety of the
      external representation of the data.  In the XML representation of a
      PADS data source, the corresponding top-level or root XML element,
      which contains entirety of the PADS data, is named 'Psource'.
    
      [[ Psource pads_decl ]] 
      identifier is name of type in pads_decl
              ==
      [[ pads_decl ]]_schema @ 
      [ <element name="PSource" type=[[identifier]]> ]

  *)
  fun ppTopElemIfPsource pps (ptyInfo:PTys.pTyInfo,repNameOpt) =
	if (#isSource ptyInfo) 
	then ( ppXMLHeader "<xs:element " "/>" pps (mapFieldTypeName, repNameOpt, "PSource", NONE)
	     ; newline pps)
	else ()

  (*
    A Pstruct yields two global complex types: one for the type itself
    and one for its parse descriptor.

    [[  Pstruct identifier [p_formals] { fields } [ Pwhere { predicate }] ]]_schema
                              == 
    [ 
      <complexType name=[[identifier]]_pdname>
        <sequence>
          <element name="pstate" type="p:Pflags_t"/>
          <element name="nerr" type="p:Puint32"/>
          <element name="errCode" type="p:PerrCode_t"/>
          <element name="loc" type="p:Ploc_t"/>
        </sequence>
      </complexType>
      ; 
      <complexType name=[[identifier]]> 
        <sequence>
          [[ fields ]]_local @ 
          [ <element name="pd" type=[[identifier]]_pdname minOccurs="0" maxOccurs="1"> ]
        </sequence>
      </complexType>
    ]

  *)
    
  fun ppPStruct (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...})  = 
      let val pdTid = #pdTid ptyInfo
	  val (pdTyName, pdFields) = structPdFields tidtab pdTid
	  val pdHeader = makeBaseNames pdFields
          val (repName, repFields) = structFields tidtab tid
	  val augRepFields = (makeFieldNames NONE repFields) @ (makeFieldNames optionalFacet [(pdTyName, "pd")])
      in
	((newline pps
(*	; PPL.addStr pps "<!-- Pstruct "^repName^" -->" *)
        ; ppXMLComplex pps (pdTyName,pdHeader)
	; ppXMLComplex pps (repName, augRepFields) 
    	; newline pps
	; ppTopElemIfPsource pps (ptyInfo,repName)
	)						
	handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *))
      end  
    | ppPStruct ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)

  (* 

   A Punion is mapped into a complex type that contains a choice of
   all of the union's fields, an optional parse descriptor, and a
   simple type for the pd's tag field.

    [[ [Plongest] Punion identifier [p_formals] { union_bdy } [ Pwhere { predicate }] ]]_schema
                                  == 
*)  
  fun ppPUnion (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...}) =
      let val pdTid = #pdTid ptyInfo
          val (repName,uFields) = unionFields tidtab tid
	  val uFields' = makeFieldNames NONE uFields 
          val (pdTyName,pdFields) = unionPdFields tidtab pdTid
	  val pdFields = makeBaseNames pdFields
	  val tagName = SOME (valOf repName ^ "_tag")  
       in 

      ((newline pps
(*      ; PPL.addStr pps "<!-- Punion "^repName^" -->" *)
      (*
        <xs:simpleType name=[[identifier]]_tag>
          <restriction base="xsd:string"/> 
        </xs:simpleType>
      *)
      ; simpleTypeOpen pps (tagName)
      ; ppXMLRestriction pps "xs:string"
      ; simpleTypeClose pps 

      (*
        <complexType name=[[identifier]]_pd>
          <sequence>
	    <element name="pstate" type="Pflags_t"/>
            <element name="nerr" type="Puint32"/>
            <element name="errCode" type="PerrCode_t"/>
            <element name="loc" type="Ploc_t"/>
          </sequence>
        </complexType>
        ; 
      *)
      ; ppXMLComplex pps (pdTyName, pdFields) 

      (*
        <complexType name=[[identifier]]> 
          <sequence>
            <choice minOccurs="0" maxOccurs="1">  <!-- May be missing if syntactic error occurs -->
              [[ union_bdy ]]_local
            </choice>
            [ <element name="pd" type=[[identifier]]_pd minOccurs="0" maxOccurs="1"> ]
          </sequence>
        </complexType>
      *)
      ; complexTypeOpen pps repName
      ; PPL.addStr pps "<xs:sequence>\n"
      ; PPL.addStr pps "<xs:choice minOccurs=\"0\" maxOccurs=\"1\">\n"
      ; ppXMLFields pps uFields'
      ; newline pps
      ; PPL.addStr pps "</xs:choice>\n"
      ; ppXMLFields pps [(mapFieldTypeName, pdTyName, "pd", optionalFacet)]
      ; PPL.addStr pps "</xs:sequence>\n"
      ; complexTypeClose pps

      ; ppTopElemIfPsource pps (ptyInfo,repName)
      )
      handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *))
    end
    | ppPUnion ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)

  (* 

    A Parray is mapped to a complex type that contains a sequence of
    array elements, a length field, and a parse descriptor:

    [[ Parray identifier [p_formals] { 
         p_ty `['p_size_spec`]' [: p_array_constraints]
       } [ Pwhere { p_array_posts }] 
    ]]  ==
  *)
  fun ppPArray (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...})  = 
      let fun changeName newName (oldType,oldName) = (oldType, newName) 
	  val pdTid = #pdTid ptyInfo
	  val (pdTyName, pd1Fields) = structPdFields tidtab pdTid
          val pdFields = makeBaseNames pd1Fields
          val (repName, repFields) = structFields tidtab tid
          val lengthField = List.hd (makeBaseNames [List.hd repFields])	(* takes only two fields = length & elts *) 
	  val (eltBaseType, eltType, eltName, facet) = List.hd (makeFieldNames unboundedFacet (List.tl repFields))
	  val eltField = (eltBaseType, eltType, "elt", facet) 
          val Fields = eltField :: lengthField :: (mapFieldTypeName, pdTyName, "pd", optionalFacet) :: []
      in
	((newline pps
	  (* 
	   <complexType name="[[identifier]]_pd">
  	     <sequence>
	       <element name="pstate" type="p:Pflags_t"/>
	       <element name="nerr" type="p:Puint32"/>
	       <element name="errCode" type="p:PerrCode_t"/>
	       <element name="loc" type="p:Ploc_t"/>
	       <element name="neerr" type="p:Puint32"/>
	       <element name="firstError" type="p:Puint32"/>
	     </sequence>
	   </complexType>
	   *)
        ; ppXMLComplex pps (pdTyName,pdFields)  
        ; newline pps
	  (* 
	   <complexType name=[[identifier]]>
	     <sequence>
	       <element name="elt" type=[[p_ty]]_typename minOccurs="0" maxOccurs="unbounded"/>
	       <element name="length" type="p:Puint32"/>
	       <element name="pd" type=[[identifier]]_pd minOccurs="0" maxOccurs="1"/>
	     </sequence>
	   </complexType>
	  *) 
	; ppXMLComplex pps (repName,Fields)
    	; newline pps
	; ppTopElemIfPsource pps (ptyInfo,repName)
        )
	handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *))
      end  
    | ppPArray ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)

	  (* 
              Galax does not support derivation by extension yet, so we have 
              to use full-blown restriction, which requires specifying explicitly
              fields from the base type :

	   [[ Penum identifier [p_formals] [p_enum_prefix] { p_enum_fields } ]]_schema
                       == 
	   [
	     <complexType name=[[identifier]]>
               <xs:sequence>
                 <xs:element name="val" type=[[p_ty]]_typename minOccurs="0" maxOccurs="1"/>
                 <xs:element name="pd" type=[[[[p_ty]]_typename]]_pdname  minOccurs="0" maxOccurs="1"/>
              </xs:sequence>
	     </complexType>
	   ]
	 *)

  fun ppPEnum (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...})  = 
      let val (repName, repFields) = enumInfo tidtab tid
      in
	((newline pps
	  ; complexTypeOpen pps (repName)
	  (* We are emitting abstract rep of enum value, not internal int value *)
	  ; ppXMLSequence pps [(mapBaseTypeName, SOME "Pstring", "val", optionalFacet), (mapPdName o mapFieldTypeName, SOME "Pstring", "pd", optionalFacet)]
	  ; complexTypeClose pps
	  ; ppTopElemIfPsource pps (ptyInfo,repName)	
        )
	handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *))
      end  
    | ppPEnum ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)


  (*
      Ptypedef
      ========
      A Ptypedef is just a synonym for another type.  In XML Schema, we
      use type derivation by restriction to specify a synonym.
     *)
  fun ppPTypedef (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...})  =
      let val (Name, Ty) = typedefInfo tidtab tid
	  val Name_pd = mapPdName (valOf Name)
	  val base = (valOf Ty)
      in 
	  (* 
              Galax does not support derivation by extension yet, so we have 
              to use full-blown restriction, which requires specifying explicitly
              fields from the base type :

	   [[ Ptypedef p_ty identifier [p_formals] [:typedef_predicates] ]]_schema
                 p_ty is a base type
                       == 
	   [
	     <complexType name=[[identifier]]>
	       <restriction base=[[p_ty]]_field_typename/>
                 <xs:sequence>
                   <xs:element name="val" type=[[p_ty]]_typename  minOccurs="0" maxOccurs="1"/>
                   <xs:element name="pd" type=[[[[p_ty]]_typename]]_pdname  minOccurs="0" maxOccurs="1"/>
                 </xs:sequence>
               </restriction>
	     </complexType>
	   ]
	 *)
	  if isBaseTypeName base then 
	      (newline pps
	       (* ; PPL.addStr pps "<!-- Ptypedef "^Name^" -->" *)
	       ; complexTypeOpen pps (Name)
	       (* ; ppXMLRestriction pps base_name *)
	       ; ppXMLSequence pps [(mapBaseTypeName, SOME base, "val", optionalFacet), (mapPdName o mapFieldTypeName, SOME base, "pd", optionalFacet)]
	       ; complexTypeClose pps
	       (*
	     ; 
	     <simpleType name=[[identifier]]_pdname>
	       <restriction base=[[[[p_ty]]_base_typename]]_pdname/>
	     </simpleType>

	       ; simpleTypeOpen pps (SOME Name_pd)
	       ; ppXMLRestriction pps pd_base_name
	       ; simpleTypeClose pps
*)
		   ; ppTopElemIfPsource pps (ptyInfo,Name)
	       )
	      handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *)
	  (*
	   [[ Ptypedef p_ty identifier [p_formals] [:typedef_predicates] ]]_schema
                 p_ty not a base type
                       == 
	   [
	     <complexType name=[[identifier]]>
	       <restriction base=[[p_ty]]_base_typename/>
	     </complexType>
	     ; 
	     <complexType name=[[identifier]]_pdname>
	       <restriction base=[[[[p_ty]]_base_typename]]_pdname/>
	     </complexType>
	   ]
	   *)
	  else
	      (let val base_name = mapBaseTypeName base
		  val pd_base_name = mapPdName base_name
	       in
		   newline pps
		   ; complexTypeOpen pps Name
		   ; ppXMLRestriction pps base_name
		   ; complexTypeClose pps
		   ; complexTypeOpen pps (SOME Name_pd)
		   ; ppXMLRestriction pps pd_base_name
		   ; complexTypeClose pps
		   ; ppTopElemIfPsource pps (ptyInfo,Name)
	       end
	      )
	      handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *)
      end
    | ppPTypedef ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)

  (*
      Precursive
      ========
      As far as xschema is concerned, a Precursive is just a synonym for another type. 
      However, in the C type it is a pointer to that other type. So, we need to finesses that difference.
      In XML Schema, we use type derivation by restriction to specify a synonym.
     *)
  fun ppPRecursive (ptyInfo:PTys.pTyInfo) tidtab pps (Ast.TypeDecl{tid,...})  =
      let val Name = #name (PTyUtils.getBinding tidtab tid)
	  val TyProps.RecursiveInfo {base={tyCon= base,...}} = #info ptyInfo
	  val Name_pd = mapPdName (valOf Name)
      in 
	  (* 
              Galax does not support derivation by extension yet, so we have 
              to use full-blown restriction, which requires specifying explicitly
              fields from the base type :
	   [[ Precursive p_ty identifier [p_formals] [:typedef_predicates] ]]_schema
                 p_ty not a base type
                       == 
	   [
	     <complexType name=[[identifier]]>
	       <restriction base=[[p_ty]]_base_typename/>
	     </complexType>
	     ; 
	     <complexType name=[[identifier]]_pdname>
	       <restriction base=[[[[p_ty]]_base_typename]]_pdname/>
	     </complexType>
	   ]
	   *)
	  (*INV: base is either a struct or union. It is NOT a base type, enum, etc. *)
	  (let val base_name = mapBaseTypeName base
	       val pd_base_name = mapPdName base_name
	   in
	       newline pps
	       ; complexTypeOpen pps Name
	       ; ppXMLRestriction pps base_name
	       ; complexTypeClose pps
	       ; complexTypeOpen pps (SOME Name_pd)
	       ; ppXMLRestriction pps pd_base_name
	       ; complexTypeClose pps
	       ; ppTopElemIfPsource pps (ptyInfo,Name)
	   end
	       )
	  handle _ => PPL.addStr pps "ERROR: unbound tid" (* fix this *)
      end
    | ppPRecursive ptyInfo tidtab pps _ = PPL.addStr pps "ERROR: Unexepected variable" (* fix this *)


  fun ppPKind (ptyInfo : PTys.pTyInfo (* cmp-tys.sml*) ) tidtab pps decl = 
      case #info ptyInfo
      of TyProps.TransInfo     _ => ppPTypedef ptyInfo tidtab pps decl   (* for now, typedef and trans print the same *)
      |  TyProps.TryInfo       _ => ppPTypedef ptyInfo tidtab pps decl   (* for now, typedef and try print the same *)
      |  TyProps.TypedefInfo   _ => ppPTypedef ptyInfo tidtab pps decl
      |  TyProps.RecursiveInfo _ => ppPRecursive ptyInfo tidtab pps decl
      |  TyProps.StructInfo    _ => ppPStruct ptyInfo tidtab pps decl
      |  TyProps.UnionInfo     _ => ppPUnion ptyInfo tidtab pps decl 
      |  TyProps.ArrayInfo     _ => ppPArray ptyInfo tidtab pps decl 
      |  TyProps.EnumInfo      _ => ppPEnum ptyInfo tidtab pps decl
      |  TyProps.BaseInfo      _ => PPL.addStr pps "Unexpected Base Type"

  fun ppCoreExternalDecl' ptyInfo aidinfo tidtab pps edecl =
    case edecl
      of ExternalDecl decl => ppPKind ptyInfo tidtab pps decl
       | FunctionDef (id,ids,stmt) =>  (* This branch will not be called as functions aren't being tagged *)
	 let val {location,...} = id
	      val (stClass,ctype) = getCtype id
	      val (ctype,kNr,params) =
		  case ctype
		   of Ast.Function (retTy,paramTys) =>
		      if null paramTys andalso not (null ids)
		      then (ctype,true,KNR ids)
		      else (ctype,false,ANSI ids)
		    | _ =>
		      (warning
			   "ppCoreExternalDecl" 
			   ("No function type associated with id:"
			    ^(PPL.ppToString PPL.ppId id))
			   ;(Ast.Function (Ast.Void,[]),false,ANSI [])
			    )
	      fun kr pps [] = []
		| kr pps (id::ids) = 
		  (ppIdDecl aidinfo tidtab pps id
		   ;PPL.addStr pps ";"
		   ;if null ids then () else newline pps
		   ;kr pps ids
		    )
	  in ppLoc pps location
	  ;ppStorageClass pps stClass
	  ;ppDecl0 aidinfo tidtab pps (SOME (ID id),params,ctype)
	  ;PPL.newline pps
	  ;if kNr then (blockify 2 kr pps ids; newline pps) else ()
	  ;ppStmt aidinfo tidtab pps stmt
          ;PPL.newline pps
	  end 
       | ExternalDeclExt ed => 
	   PPAE.ppExternalDeclExt (* PADS *) NONE false (ppExpr {nested=false},ppStmt,ppBinop,ppUnop) aidinfo tidtab pps ed

  fun ppCoreExternalDecl NONE aidinfo tidtab pps edecl = ()
    | ppCoreExternalDecl (SOME p) aidinfo tidtab pps edecl = ppCoreExternalDecl' p aidinfo tidtab pps edecl

  fun ppExternalDecl paidinfo aidinfo tidtab pps edecl = 
       PPAA.ppExternalDeclAdornment NONE paidinfo ppCoreExternalDecl aidinfo tidtab pps edecl
 
  (* PADS: takes source name and description of output kind *)
  fun ppExternalDeclRefined srcFile paidinfo aidinfo tidtab pps edecl = 
      let val ppCoreED : ptyinfo option -> aidinfo -> Tables.tidtab -> Ast.coreExternalDecl pp = ppCoreExternalDecl
      in
	  PPAA.ppExternalDeclAdornment srcFile paidinfo ppCoreED aidinfo tidtab pps edecl
      end

  (*
    A complete PADS source file is mapped to a complete XML Schema.  The target
    namespace is the name of the PADS source file.  The default PADS
    schema is imported and associated with the 'p' namespace prefix.
    The content of the XML schema is the concatenation of all the global 
    declarations that result from mapping the top-level PADS types.
    
       [[ pads_decl pads_decl_list ]]_schema
          == 
       <schema targetNamespace=[[name-of-pads-source]]
         xmlns=[[name-of-pads-source]]
         xmlns:xs="http://www.w3.org/2001/XMLSchema"
         xmlns:p="http://www.padsproj.org/pads.xsd" >
         <import namespace="http://www.padsproj.org/pads.xsd"
                 schemaLocation=[[location-of-pads.xsd]]/>
         [[ pads_decl ]] @ [[ pads_decl_list ]]_schema
       </schema>
  *)
  fun ppAst padsDir srcFile paidinfo aidinfo tidtab pps edecls =
      let val fileName = case srcFile of NONE => "" | SOME name => OS.Path.file name
	  val endS = "\"\n"
	  val begS = "           "
	  val padsloc = padsDir ^ "/padsc/schemata/pads.xsd"
	  fun wrapLine s = begS ^ s ^ endS
	  val targetNamespace = "<xs:schema targetNamespace=\"file:" ^ fileName ^ endS
	  val xmlns   = wrapLine ("xmlns=\"file:" ^ fileName) 
	  val xmlnsxs = wrapLine "xmlns:xs=\"http://www.w3.org/2001/XMLSchema" 
	  val xmlnsp  = wrapLine "xmlns:p=\"http://www.padsproj.org/pads.xsd"
	  val elmFormDef  = begS ^ ">" 
(*	  val elmFormDef  = begS ^ "elementFormDefault=\"qualified\">"  *)
          val importStmt = "<xs:import namespace = \"http://www.padsproj.org/pads.xsd\"\n" ^
			   "           schemaLocation=\"file:"^padsloc^"\"/>"
      in
        ( PPL.addStr pps targetNamespace
        ; PPL.addStr pps xmlns
        ; PPL.addStr pps xmlnsxs
        ; PPL.addStr pps xmlnsp
        ; PPL.addStr pps elmFormDef
        ; PPL.newline pps 
        ; PPL.newline pps 
        ; PPL.addStr pps importStmt
        ; PPL.newline pps 
        ; List.app (ppExternalDeclRefined srcFile paidinfo aidinfo tidtab pps) edecls
        ; PPL.newline pps
        ; PPL.addStr pps "</xs:schema>" 
        ; PPL.newline pps
        )  
      end  

  (* The pretty-printer expects a block at top level, so all of the
   * external interfaces are wrapped to give it one.
   *)
  fun wrap pp aidinfo tidtab pps v = 
    ( PPL.bBlock pps PP.INCONSISTENT 0
    ; pp aidinfo tidtab pps v
    ; PPL.newline pps 
    ; PPL.eBlock pps
    )

  val ppBinop = wrap ppBinop
  val ppUnop = wrap ppUnop
  val ppDeclaration  = wrap ppDeclaration
  val ppStatement = wrap ppStmt
  val ppCoreStatement = wrap ppCoreStmt
  val ppExpression = wrap (ppExpr {nested=false})
  val ppCoreExpression = wrap (ppCoreExpr {nested=false})
  val ppExternalDecl = fn paidInfo => wrap (ppExternalDecl paidInfo) (* PADS*)
  val ppCoreExternalDecl = fn ptyInfoOpt => wrap (ppCoreExternalDecl ptyInfoOpt) (* PADS *)
  val ppAst  = fn padsDir => fn srcFile => fn paidInfo => wrap (ppAst padsDir srcFile paidInfo)  (* PADS *)
end
 
