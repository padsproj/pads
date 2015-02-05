(** generation of common PADS-Galax stuff **)

signature GENGALAX = sig
  val nameStr : string
  val parent : string
  val result : string
  val self : string
  val whatfn : string
  val childName : string
  val idx : string
  val kind : string

  val makeNodeVtable : string -> ParseTree.externalDecl
  val makeCachedNodeVtable : string -> ParseTree.externalDecl
  val makeSNDNodeVtable : string -> ParseTree.externalDecl

  val makeCNInitFun : string * ParseTree.expression -> ParseTree.externalDecl
  val makeNodeNewFun : string -> ParseTree.externalDecl

  val makeCNKCFun : string * ParseTree.expression -> ParseTree.externalDecl
  val makeSNDInitFun : string -> ParseTree.externalDecl
				 
  val makeStructSNDKthChildFun : string * (string * string * bool) list -> ParseTree.externalDecl
  val makeStructPathWalkFun : string * (string * string * bool) list -> ParseTree.externalDecl
									
  val makeArrSNDKthChildFun : string * string -> ParseTree.externalDecl
  val makeArrPathWalkFun : string * string -> ParseTree.externalDecl

  val makeRecNodeNewFun : string * string -> ParseTree.externalDecl
  val makeRecSNDInitFun : string  * string -> ParseTree.externalDecl
  val makeRecSNDKthChildFun : string * string -> ParseTree.externalDecl
  val makeRecPathWalkFun : string * string -> ParseTree.externalDecl

  val makeTypedefSNDKthChildFun : string * string -> ParseTree.externalDecl
  val makeTypedefPathWalkFun : string * string * ParseTree.expression -> ParseTree.externalDecl

  val makeUnionSNDKthChildFun : string * (string * string option) list -> ParseTree.externalDecl
  val makeUnionPathWalkFun : string * (string * string option) list -> ParseTree.externalDecl

  val makeEnumSNDKthChildFun : string -> ParseTree.externalDecl
  val makeEnumPathWalkFun : string -> ParseTree.externalDecl

  type cparams = (string * ParseTree.ctype) list
  type stparams = (ParseTree.ctype * string) list

  structure SmartNode : sig
      val makeEltAllocFun : string  * string * string ->
			    ParseTree.externalDecl
      val makeEltReadFun :  string * string * string *
			    cparams * stparams ->
			    ParseTree.externalDecl
      val makeEltFreeFun :  string -> ParseTree.externalDecl
      val makeEltPathWalkFun : string * string * string * string ->
			       ParseTree.externalDecl
      val makeArrayInfoInitFun : string * cparams -> 
				 ParseTree.externalDecl
      val makeInitFun : string * cparams * stparams ->
			ParseTree.externalDecl
      val makeKthChildFun : string * string ->
			    ParseTree.externalDecl
      val makeKthChildNamedFun : string ->
				 ParseTree.externalDecl
      val makeVTable:  string ->
		       ParseTree.externalDecl			
    
      val makeArrayInfoStructED: string ->
				 ParseTree.externalDecl			
				 
      val makeAllEDs:  string * string  * string * string * cparams * stparams->
		       ParseTree.externalDecl list
  end

  (* Internal calls.*)
  (* For the future: change cnv-ext.sml so that these calls are not needed.
   *  Instead, cnv-ext should use calls like those above. *)

  val headerGalaxChildrenFun : string -> ParseTree.statement list
  val headerGalaxKthChildFun : string -> ParseTree.statement list
  val ifGalaxChildren : ParseTree.expression * ParseTree.expression * string
                        -> ParseTree.statement list
  val makeInvisibleDecls : string list * string list
                           -> ParseTree.statement list
  val macroNodeNew : string -> ParseTree.statement
  val macroNodeNewRet : unit -> ParseTree.expression

  val makeKCCase : string
                   -> int * (string * string * bool) -> ParseTree.statement

  val makeUnionKCCase : string -> (string * string option) -> ParseTree.statement

  val apply : ('a -> 'b) list -> 'a -> 'b list
  val inc : int -> int
  val listOf : int -> int list
  val enumerate : 'a list -> (int * 'a) list
  val getUniqueTys : ''b list -> ''b list

  val macroTNode : ParseTree.expression * string * string
                   * ParseTree.expression * string
                   -> ParseTree.statement list
  val macroTNodeCall : ParseTree.expression * ParseTree.expression * string
                       * string * ParseTree.expression * string
                       -> ParseTree.statement list
  val macroTNodeCallGeneral : ParseTree.expression * string * string
                              * ParseTree.expression * string
                              -> ParseTree.statement list
  val macroTNodeGeneral : ParseTree.expression * string * string
                          * ParseTree.expression * string
                          -> ParseTree.statement list

  val macroRecKC : string * string -> ParseTree.statement
  val macroRecKCN : unit -> ParseTree.statement
  val macroRecKCNRet : unit -> ParseTree.expression
  val macroRecKCRet : unit -> ParseTree.expression

  val macroTypKC : string * string -> ParseTree.statement
  val macroTypKCN : unit -> ParseTree.statement
  val macroTypKCNRet : unit -> ParseTree.expression
  val macroTypKCRet : unit -> ParseTree.expression

  val macroStructKCBegin : string -> ParseTree.statement
  val macroStructKCEnd : int -> ParseTree.statement
  val macroStructKCRet : unit -> ParseTree.expression
  val macroStructKCN : string * string list -> ParseTree.statement
  val macroStructKCNRet : unit -> ParseTree.expression
   
  val macroArrKC : string * string -> ParseTree.statement
  val macroArrKCN : string -> ParseTree.statement
  val macroArrKCNRet : unit -> ParseTree.expression
  val macroArrKCRet : unit -> ParseTree.expression
  val macroArrLength : string -> ParseTree.expression

  val macroUnionKCBegin : string -> ParseTree.statement
  val macroUnionKCEnd : unit -> ParseTree.statement
  val macroUnionKCRet : unit -> ParseTree.expression
  val macroUnionKCN : string -> ParseTree.statement
  val macroUnionKCNRet : unit -> ParseTree.expression
   
  val macroEnumKC : string  -> ParseTree.statement
  val macroEnumKCN : unit -> ParseTree.statement
  val macroEnumKCNRet : unit -> ParseTree.expression
  val macroEnumKCRet : unit -> ParseTree.expression

  val macroCNInit : string * ParseTree.expression -> ParseTree.statement
  val macroCNInitRet : unit -> ParseTree.expression
  val macroKCCase : string * int * string * string -> ParseTree.statement
  val macroNodeCall : ParseTree.expression * ParseTree.expression * string
                      * ParseTree.expression * ParseTree.expression
                      * ParseTree.expression * ParseTree.expression * string
                      -> ParseTree.statement
  val macroNodeCallGeneral : ParseTree.expression * string
                             * ParseTree.expression * ParseTree.expression
                             * ParseTree.expression * ParseTree.expression
                             * string
                             -> ParseTree.statement
end
