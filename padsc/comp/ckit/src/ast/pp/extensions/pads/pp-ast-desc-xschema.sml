local 
  fun isPads loc = 
      case loc 
      of SourceMap.UNKNOWN => false
      |  SourceMap.LOC r => (let val fname = OS.Path.file (#srcFile r) 
				 val isPads = case OS.Path.splitBaseExt fname
				     of {base, ext = SOME extension} => extension = "p"
				     | _  => false
			     in
				 isPads
			     end)
     
  structure PPAstPaidAdornment : PPASTPAIDADORNMENT =
  struct
    type aidinfo = unit
    type paidinfo = Tables.paidtab

    fun ppExpressionAdornment ppCoreExpr aidinfo tidtab pps (Ast.EXPR (coreExpr,_,_)) = 
	ppCoreExpr aidinfo tidtab pps coreExpr

    fun ppStatementAdornment ppCoreStmt aidinfo tidtab pps  (Ast.STMT (coreStmt,_,_)) = 
	ppCoreStmt aidinfo tidtab pps coreStmt

    (* *)
    fun ppExternalDeclAdornment srcFileOpt paidinfo ppCoreExternalDecl aidinfo tidtab pps
	  (Ast.DECL (coreExtDecl,_,paid:Paid.uid,loc:SourceMap.location)) = 
	  if isPads loc then 
	      ppCoreExternalDecl (Paidtab.find(paidinfo,paid)) aidinfo tidtab pps coreExtDecl
	  else ()

end
in
  structure PPDescXSchemaAst = PPAstDescXschemaFn(structure PPAstPaidAdornment=PPAstPaidAdornment)
end
