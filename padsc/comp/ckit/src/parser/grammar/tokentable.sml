(* Copyright (c) 1998 by Lucent Technologies *)

(***************************************************************************

  TOKEN.SML: hash table for token recognition

 ***************************************************************************)


signature TOKENTABLE =
sig
	structure Tokens : C_TOKENS
	val checkToken : (string * int) -> (Tokens.svalue,int)Tokens.token
end

functor TokenTable(structure Tokens : C_TOKENS): TOKENTABLE = 
struct
  
  structure Tokens = Tokens
  structure ParseControl = Config.ParseControl
  type item = (int * int) -> (Tokens.svalue, int) Tokens.token
  exception Keyword
  exception LexError
  val keywords : item AtomTable.hash_table = AtomTable.mkTable(64, Keyword)
    
  val _ = let
    val insert = AtomTable.insert keywords
    fun ins (s, item) = insert (Atom.atom s, item)
  in
    app ins ([
	      ("break", Tokens.BREAK),
	      ("case", Tokens.CASE),
	      ("continue", Tokens.CONTINUE),
	      ("default", Tokens.DEFAULT),
	      ("do", Tokens.DO),
	      ("else", Tokens.ELSE),
	      ("auto", Tokens.AUTO),
	      ("extern", Tokens.EXTERN),
	      ("register", Tokens.REGISTER),
	      ("static", Tokens.STATIC),
	      ("for", Tokens.FOR),
	      ("goto", Tokens.GOTO),
	      ("if", Tokens.IF),
	      ("char", Tokens.CHAR),
	      ("double", Tokens.DOUBLE),
	      ("enum", Tokens.ENUM),
	      ("float", Tokens.FLOAT),
	      ("int", Tokens.INT),
 	      ("long", Tokens.LONG),
	      ("short", Tokens.SHORT),
	      ("struct", Tokens.STRUCT),
	      ("union", Tokens.UNION),
	      ("unsigned", Tokens.UNSIGNED),
	      ("signed", Tokens.SIGNED),
	      ("const", fn p => if ParseControl.constAllowed 
				  then (Tokens.CONST p)
				else (ParseControl.violation "the keyword 'const' not allowed";
				      raise LexError)),
	      ("volatile", fn p => if ParseControl.volatileAllowed 
				     then (Tokens.VOLATILE p)
				   else (ParseControl.violation "the keyword 'volatile' not allowed";
					 raise LexError)),
	      ("void", Tokens.VOID),
	      ("sizeof", Tokens.SIZEOF),
	      ("typedef", Tokens.TYPEDEF),
	      ("return", Tokens.RETURN),
	      ("switch", Tokens.SWITCH),
	      ("while", Tokens.WHILE)
	      ] @ [  (* PADSC *)
               ("_Pdone", Tokens.PDONE),
               ("Palternates", Tokens.PALTERNATES),
               ("Parray", Tokens.PARRAY),
               ("Pcase", Tokens.PCASE),
               ("Pcharclass", Tokens.PCHARCLASS),
               ("Pcompute",  Tokens.PCOMPUTE),       
               ("Pdefault", Tokens.PDEFAULT),
               ("Pempty",   Tokens.PEMPTY),       
               ("Pended",   Tokens.PENDED),       
               ("Pendian",   Tokens.PENDIAN),       
               ("Penum", Tokens.PENUM),
               ("Pforall", Tokens.PFORALL),
               ("Pfrom", Tokens.PFROM),
               ("Pin", Tokens.PIN),
               ("Plast", Tokens.PLAST),
               ("Pmaskmap", Tokens.PMASKMAP),
	       ("Pnone", Tokens.PNONE),
               ("Pnosep", Tokens.PNOSEP),
               ("Pomit", Tokens.POMIT),
               ("Popt", Tokens.POPT),
	       ("Pparsecheck", Tokens.PPARSECHECK),
               ("Pprefix", Tokens.PPREFIX),     
               ("Pre", Tokens.PRE),    
               ("Plongest", Tokens.PLONGEST),     	       
               ("Precord", Tokens.PRECORD),     
	       ("Pselect", Tokens.PSELECT),
               ("Psep", Tokens.PSEP),
	       ("Psome", Tokens.PSOME),
               ("Psource", Tokens.PSOURCE),     
               ("Pstruct", Tokens.PSTRUCT),
               ("Pswitch", Tokens.PSWITCH),
               ("Pterm", Tokens.PTERM),
               ("Ptrans", Tokens.PTRANS),
               ("Ptry", Tokens.PTRY),
               ("Ptypedef", Tokens.PTYPEDEF),
               ("Precur", Tokens.PRECURSIVE),
(*                ("Pdyn", Tokens.PDYNAMIC), *)
               ("Punion", Tokens.PUNION),
               ("Pwhere", Tokens.PWHERE)
              ])


  end

  fun checkToken (s, pos) = let
    val endPos = pos + size s
    val name = Atom.atom s
  in
    case (AtomTable.find keywords name)
      of (SOME tokFn) => tokFn(pos, endPos)
       | NONE => 
	   (if TypeDefs.checkTdef(s) then 
	      Tokens.TYPE_NAME(s,pos,endPos)
	    else Tokens.ID(s,pos,endPos))
  (* end case *)
  end

end
