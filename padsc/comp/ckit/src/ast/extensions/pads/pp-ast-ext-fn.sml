(* Copyright (c) 1998 by Lucent Technologies *)

functor PPAstExtFn (type aidinfo):PPASTEXT = struct
  type aidinfo = aidinfo
  fun ppUnopExt aidinfo pair pps unopExt = ()
  fun ppBinopExt aidinfo pair pps binopExt = ()
  fun ppExpressionExt quad aidinfo pair pps expExt = ()
  fun ppStatementExt quad aidinfo pair pps (AstExt.SComment s) =        
      (PPLib.addStr pps "// ";
	PPLib.addStr pps s)

  fun ppExternalDeclExt stringOpt isHeader quad aidinfo pair pps edeclExt = 
      case edeclExt 
      of AstExt.EComment s =>
       (PPLib.addStr pps "/* ";
	PPLib.addStr pps s;
        PPLib.addStr pps " */";
        PPLib.newline pps)
      | AstExt.Pinclude s =>
        if isHeader then
           (PPLib.addStr pps s;
	    PPLib.newline pps)
	else ()
	       
     
end

