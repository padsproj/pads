structure Transform : sig
  val doFile : Ast.ast * (Bindings.tidBinding Tidtab.uidtab) * Tables.paidtab -> string -> unit
end = struct
  structure TPT = TParseTree
  structure Map = RedBlackMapFn(
                     struct type ord_key = Atom.atom
			    val compare = Atom.compare
		     end) 
  
  val output : string option ref =  ref NONE

  type iotf     = TPT.body Map.map ref
  type iotfsTy  = iotf Map.map ref
  val iotfs : iotfsTy = ref Map.empty          (* IO transforms *)

  type simpletf = string Map.map ref
  type simpletfTy = simpletf Map.map ref
  val simpletfs : simpletfTy = ref Map.empty  (* String transforms *)

  exception IO
  exception Unsupported

  fun isCap s = (Char.isUpper (String.sub(s,0))) handle Subscript => (print ("Unexpected empty string"); false)

  fun processEDecl (TPT.MARKexternalDecl(loc,edecl)) = processEDecl edecl
    | processEDecl (TPT.Output s) = (case (!output) of NONE => (output := SOME s)
                                     | _ => print "Multiple output statements.\n")
    | processEDecl (TPT.TransformTy(id,s,d)) = 
        let val idA = Atom.atom id
	    val () = if not (isCap id) then
		       print ("Transform names must be capitalized ("^id^").\n") else ()
	in
	    case (s,d) 
       	    of (TPT.TyName, TPT.Str) => (simpletfs := Map.insert(!simpletfs, idA, ref Map.empty))
            |  (TPT.TyDecl, TPT.IO ) => (iotfs     := Map.insert(!iotfs, idA, ref Map.empty))
            | _ => (print "Unsupported transform type.\n")
	end
    | processEDecl (TPT.Transform(name, arg, body)) = 
	let val idA = Atom.atom name
	    val simpleTrOpt = Map.find(!simpletfs, idA)
            val ioTrOpt     = Map.find(!iotfs, idA)
	in
	   case (simpleTrOpt, ioTrOpt) 
	   of (NONE,NONE) => (print ("Undeclared transform "^name^".\n"))
           |  (SOME _, SOME _)  => (print ("Transform "^name^" declared with two types.\n"))
           |  (SOME tmap, NONE) => 
		    (case (arg,body) 
			 of (TPT.ArgS args, TPT.Bsimple bs) => (tmap := Map.insert(!tmap, Atom.atom args, bs))
		       | _ => (print ("Body of transform "^name^" didn't match type declaration: TyName -> String.\n")))

           |  (NONE, SOME tmap) => 
		    (case arg
                     of TPT.ArgC(conTy,argS) => 
		       (case (conTy, body) 
		        of (TPT.Pstruct, TPT.Bstruct body) => 
			    ( tmap := Map.insert(!tmap, Atom.atom argS, TPT.Bstruct body))
		            (* XXX check well-formedness of body, already defined.*)
                        | _ => (print ("Body of transform "^name^" didn't match argument type.\n")))
                     | _ => (print ("Body of transform "^name^" didn't match type declaration: TyDecl -> IO.\n")))
	end

  fun STyToString TPT.TyName = "TyName"
    | STyToString TPT.TyDecl = "TyDecl"

  fun DTyToString TPT.Str = "String"
    | DTyToString TPT.IO = "IO"

  fun argToString arg = "arg"
  fun bodyToString body = "bdy"

  fun EdeclToString (TPT.MARKexternalDecl(loc,edecl)) = EdeclToString edecl
    | EdeclToString (TPT.Output s) = "Output(\""^s^"\");"
    | EdeclToString (TPT.TransformTy (id, s,d)) = "Transform "^id^" : "^ (STyToString s)^" -> " ^(DTyToString d)^";"
    | EdeclToString (TPT.Transform(id, arg, bdy)) = id^"("^(argToString arg)^")"^(bodyToString bdy)^";"

  fun printEdecl edecl = (print (EdeclToString edecl); print "\n")
  fun printEdecls ls = List.app printEdecl ls

  datatype trTree = Str of string | Deref of string | App of string * trTree | Seq of trTree * trTree

  fun trToString (Str s) = s
    | trToString (Deref s) = "^"^s
    | trToString (App (s, tr)) = "^"^s^"("^(trToString tr)^")"
    | trToString (Seq (tr1, tr2)) = (trToString tr1) ^ (trToString tr2)

  fun substTrToString mapping (tr:trTree) = 
    case tr 
    of (Str s) => s
    |  (Deref s) => (case (List.find (fn(k,b)=>  k = s) mapping)
                     of SOME (k,b) => b
                     | NONE => (print ("Unexpected variable name: ("^s^").\n"); "ERROR"))
    |  (App(s,trArg)) => let val argStr = substTrToString mapping trArg
                       in
		           case Map.find(!simpletfs, Atom.atom s)
                           of NONE => (print ("Unexpected simple transform name:"^s^"");"ERROR")
			   | SOME simpletf => 
			       (case Map.find(!simpletf, (Atom.atom argStr))
                                of NONE => (print ("Unexpected argument ("^argStr^") to transform:"^s^".\n");"ERROR")
                                | SOME result => result)
		       end
    |  (Seq(tr1, tr2)) => ((substTrToString mapping tr1) ^ (substTrToString mapping tr2))
                  
    
  fun cvtTr freeVars l = 
      let fun findMatching tr l = 
	    let fun fm nil n acc = (print ("Failed to find matching right paren after transform "^tr^".\n"); (acc, nil))
		  | fm (c::cs) n acc = if c = #")" andalso n = 0 then (acc, cs)
                                       else if c = #")" then fm cs (n-1) (acc@[c])
                                       else if c = #"(" then fm cs (n+1) (acc@[c])
				       else fm cs n (acc@[c])
	    in
		fm l 0 []
	    end
	  fun cvtTr'  l = 
          let fun finish cs = Str(String.implode(List.rev cs))
	      fun getStr nil acc = (finish acc, [])
                | getStr (c::cs) acc = 
		                       if c = #"^"  then ((finish acc), c::cs) 
				       else getStr cs (c::acc)
              fun getDeref (seq : char list)= 
		  let val seqS = String.implode seq
		  in
		  case (List.find (fn var => String.isPrefix var seqS) freeVars)
		  of NONE => (print ("Unexpected variable name: "^ seqS ^".\n"); (Str "", []))
                  | SOME which =>(Deref which, List.drop(seq, String.size which))
		  end
              fun getApp seq = 
		  let val stfs = Map.listItemsi (!simpletfs)
		  in
		      case List.find (fn (key,tfs) => String.isPrefix (Atom.toString key) 
				                       (String.implode (List.take(seq, 
									 String.size (Atom.toString key))))) stfs
		      of NONE => (print ("Unexpected transform name.\n"); (Str "", []))
                      | SOME (tname, tMap) => 
			  let val tStr = Atom.toString tname
			  in case (List.drop(seq, String.size tStr))
			     of nil => (print ("Expected '(' after string transform "^tStr^".\n");
					(Str "", []))
			     | (c::cs) => 
				 if not (c = #"(") then
				     (print ("Expected '(' after string transform "^tStr^".\n");
				      (Str "", []))
				 else let val (argS, rest) = findMatching tStr cs
					  val (argT, rest') = cvtTr' argS
					  val () = if not (List.null rest') then print "unexpected material in arg.\n" 
						   else()
				      in
					  (App(tStr, argT), rest)
				      end

			  end
		  end
   	      fun getMeta nil = (print "Ill-formed meta-sequence: ^ not followed by variable name"; (Str "", []))
                | getMeta (seq as c::cs) = if Char.isUpper c then getApp seq else getDeref seq
              fun getFirst nil = (Str "", [])
                | getFirst (str as (c::cs)) = 
		   if (c = #"^") then getMeta cs else getStr str []
	      val (first, rawR) = getFirst l
	  in
              if List.null rawR then (first, rawR)
	      else let val (result, rest) = cvtTr' rawR 
		   in
		       (Seq(first,result), rest)
		   end
	  end
      in
	  #1(cvtTr' l)
      end

  fun getFieldInfo (ptyInfo:PTys.pTyInfo) = 
      let val fieldInfo = #compoundDiskSize ptyInfo
	  fun cnvComment NONE = "" 
            | cnvComment (SOME s) = s
	  fun mungeOne infoOpt = case infoOpt of NONE => []
	                         | SOME (name,ty,args,isOmitted, commentOpt) => [(ty,name,cnvComment commentOpt, isOmitted)]
      in
	  case fieldInfo
	  of (TyProps.Struct sinfol) => List.concat(List.map mungeOne (#1(ListPair.unzip sinfol)))
          | _ => (print "Struct transform applied to non-struct.\n"; [])
      end
        
  fun doFields (stream, repFields,globals, globalMapping) (ty, field, commentOpt, bdyS) = 
      let fun chkParam p = if (isCap p) then
		       print ("Variable names must be not capitalized ("^p^").\n") else ()
	  val () = chkParam ty
          val () = chkParam field
          val comment = case commentOpt of NONE => [] | SOME s => (chkParam s; [s])
	  val trTree = cvtTr([ty, field] @ comment @ globals) (String.explode bdyS)
	  fun doField (tyname, fieldname, commentText, isOmitted) = 
              if isOmitted then ()
              else let val commentMapping = case commentOpt of NONE => [] | SOME s => [(s, commentText)]
		       val mapping = [(ty,tyname), (field,fieldname)] @ commentMapping @ globalMapping
                       val outStr = substTrToString mapping trTree
		   in
		       TextIO.output(stream, "  "^outStr^"\n")
		   end
      in
	  List.app doField repFields
      end

  fun doExp (globals, globalMapping, exp) = 
      let val trTree = cvtTr globals (String.explode exp)
	  val outStr = substTrToString globalMapping trTree
      in
	  outStr
      end
	  

  fun doStruct (stream, tid, tidtab, ptyInfo) {pre, each, post} = 
      let val repFields = getFieldInfo ptyInfo
          fun getOne label [] = ([], [])
            | getOne label ((_, field, _, _)::xs) = ([label], [(label, field)])
	  val (first, firstMap) = getOne "pFIRST" repFields
          val (last, lastMap) = getOne "pLAST" (List.rev repFields)
	  val globals = first @ last
	  val globalMap = firstMap @ lastMap
      in
	  ((case pre 
            of NONE => ()
            | SOME preS => TextIO.output(stream, (doExp(globals, globalMap, preS))^"\n"));
           (case each 
            of NONE => ()
            | SOME (ty, field, comment, bdyS) => doFields(stream, repFields, globals,globalMap) (ty,field,comment, bdyS));
           (case post 
            of NONE => ()
            | SOME postS => TextIO.output(stream, (doExp(globals, globalMap, postS))^"\n\n")))
      end

  fun doEDecl (stream, tidtab, paidtab) (Ast.DECL(cedecl, aid, paid, loc) : Ast.externalDecl) = 
      let val pinfo : PTys.pTyInfo option = Paidtab.find(paidtab, paid)  (* Is this the rep of a pads type?*)
	                                           (* What about base types?*)

      in
	  case pinfo of NONE => ()
          | SOME ptyInfo => (* if yes ... *)
	      let val name = #repName ptyInfo
		  val tid = case cedecl of (Ast.ExternalDecl(Ast.TypeDecl{tid,...})) => tid
                            | _ => (print ("Unexpected declaration.\n"); raise Unsupported)
		  fun doOneIOTF iotf = 
		      case Map.find(!iotf, Atom.atom name) of NONE => ()
		      | SOME (TPT.Bsimple b) => ()  (* This case should not arise *)
                      | SOME (TPT.Bstruct b) => doStruct (stream, tid, tidtab, ptyInfo) b
	      in
		  Map.app doOneIOTF (!iotfs)
	      end
	  handle Unsupported => ()
      end

  fun doFile (ast,tidtab, paidtab) f  = 
      let val errorState = Error.mkErrState TextIO.stdErr
          val tedecls = TParser.parseFile errorState f
	  val () = List.app processEDecl tedecls
	  val outputName = case (!output) of NONE => (print "Failed to specify output file.\n"; raise IO)
	                   | SOME s => s
          val stream = TextIO.openOut (outputName) 
	               handle IO => (print ("Couldn't open output file: "^(outputName)^".\n"); raise IO)
      in 
	  (List.app (doEDecl (stream, tidtab, paidtab))  ast;
	   TextIO.flushOut stream;
	   TextIO.closeOut stream ) 
	  handle IO => ()
      end
end

