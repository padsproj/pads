structure PTyUtils = 
struct
  open Ast

  (* XXX: These types are special-cased because they are
     native C types, but fields of these types occur in PD structs. *)
  fun isPdFieldType t = 
      (case t
	   of "Ploc_t" => true
	 | "PerrCode_t" => true
	 | "Pbase_pd" => true 
	 | "Pflags_t" => true
	 | _ => false)

  fun isPdFieldName (t, f) = 
      (case f
	   of "pstate" => true
	 | "nerr" => true
	 | "errCode" => true
	 | "loc" => true 
	 | "neerr" => true
	 | "firstError" => true
	 | _ => false)

  (* Given a tid, return the corresponding padsTy kind (Base,
     Compound, C) and (optional) type name *)
  fun padsTyKindName tidtab tid = 
      (case Tidtab.find (tidtab, tid) 
	  of SOME (tyBinding : Bindings.tidBinding) => 
	      let val SOME n = #name tyBinding in
		  ((* print ("Found "^n^"\n"); *)
		   case PBaseTys.find(PBaseTys.baseInfo, Atom.atom n)
		       of SOME b => (PTys.BaseTy b, SOME n)
		     |  NONE => (case PTys.find(Atom.atom n)
				     of NONE => (PTys.CTy, SOME n)
				   | SOME b =>  (PTys.CompoundTy b, SOME n)))
	      end
	| NONE => (PTys.CTy, NONE))

  (* Given a tid, return the (optional) Base or Compound type name. *)
  fun padsTyName tidtab tid = 
      (case (padsTyKindName tidtab tid) 
	  (* Native C types should never be mapped to XML Schema *)
	   (* !!HACK ALERT!! Mary : These native C types appear in PDs, therefore they are mapped *)
	  of (PTys.CTy, SOME n) => if (isPdFieldType n) then SOME n else NONE
	| (PTys.CTy, NONE) => NONE
        | (_, nopt) => nopt)

  (* Given a tid, return its corresponding name *)
  fun tyBindingName tidtab tid = 
      (case Tidtab.find(tidtab,tid) 
	   of SOME (tyBinding : Bindings.tidBinding) => (#name tyBinding)
	 | NONE => NONE)

  (* Given a C type, return the Abstract PADS Type *)
  fun getAbstractTypeName tidtab (cty:Ast.ctype) symName = 
      let fun getAbstractTypeNameAux (cty : Ast.ctype)  = 
	  (case cty 
	       of Qual(qual, ctype) => getAbstractTypeNameAux ctype
		   (* Native C types only should never be mapped to XML Schema *)
	     |  Numeric(_,_,signedness,intKind,signednessTag) => NONE
	     |  Pointer ctype => ((* print ("Lookup pointer \n"); *)getAbstractTypeNameAux ctype)
	     |  StructRef tid => ((* print ("Lookup struct \n"); *)  tyBindingName tidtab tid)
	     |  UnionRef tid =>  ((* print ("Lookup union \n"); *)  tyBindingName tidtab tid)
	     |  EnumRef tid =>   ((* print ("Lookup enum \n"); *)  tyBindingName tidtab tid)
	     |  TypeRef tid =>   ((* print ("Lookup typedef \n"); *)  padsTyName tidtab tid)
	     |  _ => ((* print ("Lookup OTHER \n"); *)  NONE))
	       handle Option => NONE
      in
	  case getAbstractTypeNameAux cty
	      of SOME name => SOME (SOME name, symName)
	    |  NONE => NONE
      end
(*        |  Numeric(_,_,signedness,intKind,signednessTag) => (getIntName (intKind, signedness, signednessTag),  symNameOpt) 
         fun getIntName(intKind, signedness, signednessTag) =
	     case (intKind, signedness) 
	     of (Ast.INT, Ast.SIGNED) => SOME("xsd:int")
             |  (Ast.FLOAT, _) => SOME("xsd:float")
             | _ => SOME ("ToBeImplemented")
*)


  (* get binding of tid in table tidtable. *)
  (* INV: tid in tidtab. Otherwise, will throw exception, *)
  fun getBinding tidtab tid = 
      let val binding : Bindings.tidBinding = valOf (Tidtab.find(tidtab,tid)) 
      in 
       binding
      end

  fun cnvStructField tidtab (cty, memOpt : Ast.member option, _, _) = 
      let val fsym : Symbol.symbol = #name(valOf memOpt)
      in
	  getAbstractTypeName tidtab cty (Symbol.name fsym)
      end

  fun structFields tidtab tid =
      let val binding = getBinding tidtab tid
	  val Bindings.Typedef(tid',cty) = valOf(#ntype binding)
	  val (Ast.StructRef stid) = cty
	  val Bindings.Struct(tid'',fields) = valOf(#ntype (getBinding tidtab stid))
      in
	 (#name binding, List.mapPartial (cnvStructField tidtab) fields)
	 handle Match => (PError.bug "expected typedef to struct binding"; (SOME "bogus", []))
  	 handle Option => (PError.bug "expected SOME"; (SOME "bogus", []))
      end

  fun structPdFields tidtab pdtid =
      let val (name, pdfields) = structFields tidtab pdtid 
      in (name, List.filter isPdFieldName pdfields)
      end

  fun unionFields tidtab tid = 
      let val binding = getBinding tidtab tid
	  val Bindings.Typedef(tid',cty) = valOf(#ntype binding)
	  val (Ast.StructRef stid) = cty
          val Bindings.Struct(tid'',fields) = valOf(#ntype (getBinding tidtab stid))   (* first field = tag  *)
          val value = List.hd(List.tl(fields))                                   (* second field = val *)
          fun valtid (uctype,_,_,_) = uctype
          val (Ast.TypeRef utid) = valtid value
          val Bindings.Typedef(tid''',utype) = valOf(#ntype (getBinding tidtab utid))
          val (Ast.UnionRef uutid) = utype
          val Bindings.Union(tid'''',ufields) = valOf(#ntype (getBinding tidtab uutid)) (* union fields *)
          fun cnvUField (cty, mem : Ast.member,_) =
              let val fsym : Symbol.symbol = #name mem
              in
                  getAbstractTypeName tidtab cty (Symbol.name fsym)
              end
      in 
	(#name binding,List.mapPartial cnvUField ufields)
	handle Match => (PError.bug "expected typedef to struct binding"; (SOME "bogus", []))
	handle Option => (PError.bug "expected SOME"; (SOME "bogus", []))
      end

  fun unionPdFields tidtab pdtid =
      let val binding = getBinding tidtab pdtid
          val Bindings.Typedef(tid',cty) = valOf(#ntype binding)
          val (Ast.StructRef stid) = cty
          val Bindings.Struct(tid'',pdfields) = valOf(#ntype (getBinding tidtab stid))   
      in
	 (#name binding, List.filter isPdFieldName (List.mapPartial (cnvStructField tidtab) pdfields))
	 handle Match => (PError.bug "expected typedef to struct binding"; (SOME "bogus", []))
  	 handle Option => (PError.bug "expected SOME"; (SOME "bogus", []))
      end

  fun enumInfo tidtab tid =
      let val binding = getBinding tidtab tid
	  val Bindings.Typedef(tid',cty) = valOf(#ntype binding)
	  val (Ast.EnumRef stid) = cty
	  val Bindings.Enum(tid'',fields) = valOf(#ntype (getBinding tidtab stid))
	  fun cnvField (mem: Ast.member,_,_) = 
	      let val fsym : Symbol.symbol = #name mem
	      in
		  (SOME (Symbol.name fsym))
	      end
      in
	 (#name binding,List.mapPartial cnvField fields)
	 handle Match => (PError.bug "expected typedef to struct binding"; (SOME "bogus", []))
  	 handle Option => (PError.bug "expected SOME"; (SOME "bogus", []))
      end

  fun typedefInfo tidtab tid =
      let val binding = getBinding tidtab tid
	  val Bindings.Typedef(tid',cty) = valOf(#ntype binding)
	  val (Ast.TypeRef stid) = cty
          val bindTy = getBinding tidtab stid
      in
	  (#name binding,#name bindTy)
	  handle Match => (PError.bug "expected typedef to struct binding"; (SOME "bogus", SOME "bogus type"))
  	  handle Option => (PError.bug "expected SOME"; (SOME "bogus", SOME "bogus type"))
      end

  fun recursiveInfo tidtab tid =
      (let val binding = getBinding tidtab tid
	   val Bindings.Typedef (tid',cty) = valOf(#ntype binding)
	   val (Ast.Pointer (Ast.StructRef stid)) = cty
           val bindTy = getBinding tidtab stid
       in
	   (#name binding, #name bindTy)
       end)
      handle Match => (PError.bug "unexpected datatype constructor"; (SOME "bogus", SOME "bogus type"))
      handle Option => (PError.bug "expected SOME"; (SOME "bogus", SOME "bogus type"))

    fun mungeFileName (fileName, from, to) = 
    (case OS.Path.splitBaseExt fileName
     of {base, ext=SOME from} =>
	 SOME (OS.Path.joinBaseExt{base=base, ext=SOME to})
     | _ => NONE (*end case *))

end
