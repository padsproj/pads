local 
  type 'a pp =  Tables.tidtab -> OldPrettyPrint.ppstream -> 'a -> unit

  type ('aidinfo,'a,'b) adornment_pp = ('aidinfo -> 'a) -> 'aidinfo -> 'b

  type ('pTyInfo, 'aidinfo, 'a, 'b) padornment_pp = ('pTyInfo -> 'aidinfo -> 'a) -> 'aidinfo -> 'b
in
signature PPASTPAIDADORNMENT = sig
  type aidinfo
  type paidinfo
  val ppExpressionAdornment: (aidinfo,Ast.coreExpression pp,Ast.expression pp) adornment_pp
  val ppStatementAdornment : (aidinfo,Ast.coreStatement pp,Ast.statement pp) adornment_pp
  val ppExternalDeclAdornment: string option -> paidinfo -> (* PADS *)
      (PTys.pTyInfo option, aidinfo,Ast.coreExternalDecl pp,Ast.externalDecl pp) padornment_pp
end
end
