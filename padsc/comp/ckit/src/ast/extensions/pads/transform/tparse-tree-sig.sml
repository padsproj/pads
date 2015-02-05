signature TPARSETREE =
sig
  datatype sTy = TyName | TyDecl 
  datatype dTy = Str | IO
  datatype conTy = Pstruct | Punion | Palternate | Parray | Ptypedef | Penum

  datatype targ = ArgS of string | ArgC of conTy * string

  datatype body 
         = Bsimple of string 
         | Bstruct of {pre : string option, each: (string * string * string option * string) option, post : string option}
       
  datatype externalDecl 
         = Output of string
         | TransformTy of string * sTy * dTy
         | Transform of string * targ * body
         | MARKexternalDecl of (SourceMap.location * externalDecl)  

end (* signature TPARSETREE *)
