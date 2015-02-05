(* Copyright (c) 1998 by Lucent Technologies 
 * pretty-printer which simply ignores any aidinfo.
 *)

local 

  structure PPAstAdornment : PPASTADORNMENT =
  struct
    type aidinfo = unit

    fun ppExpressionAdornment ppCoreExpr aidinfo tidtab pps (Ast.EXPR (coreExpr,_,_)) = 
	ppCoreExpr aidinfo tidtab pps coreExpr

    fun ppStatementAdornment ppCoreStmt aidinfo tidtab pps  (Ast.STMT (coreStmt,_,_)) = 
	ppCoreStmt aidinfo tidtab pps coreStmt

   (* PADS: added argument to denote source file.  Output from all other sources files
            will be filtered out. *)

    fun ppExternalDeclAdornment srcFileOpt ppCoreExternalDecl aidinfo tidtab pps
	  (Ast.DECL (coreExtDecl,_,paid:Paid.uid,loc:SourceMap.location)) = 
	  (case loc of SourceMap.UNKNOWN => ppCoreExternalDecl aidinfo tidtab pps coreExtDecl
           | SourceMap.LOC r => let val fname = OS.Path.file (#srcFile r) (* PADS *)
	                            val isPads = case OS.Path.splitBaseExt fname
					         of {base, ext = SOME extension} => extension = "p"
					         | _  => false
				 in
				     case srcFileOpt
				     of NONE => ppCoreExternalDecl aidinfo tidtab pps coreExtDecl
                                     |  SOME srcname => 
					 if isPads
					 then ppCoreExternalDecl aidinfo tidtab pps coreExtDecl
					 else ()
				 end)
  end

in
  structure PPAst = PPAstFn(structure PPAstAdornment=PPAstAdornment)
end
