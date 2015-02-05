(* Copyright (c) 1998 by Lucent Technologies *)

structure AstExt = struct

      datatype Edecl = 
         EComment of string | Pinclude of string

      datatype Stmt = 
         SComment of string

      type binopExt = unit
      type unopExt = unit
      type ('expression, 'statement, 'binop, 'unop) expressionExt = unit
      type ('expression, 'statement, 'binop, 'unop) statementExt = Stmt
      type ('expression, 'statement, 'binop, 'unop) externalDeclExt = Edecl
          
       
end
