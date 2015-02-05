(***************************************************************************

  TOKEN.SML: hash table for token recognition

 ***************************************************************************)


signature TTOKENTABLE =
sig
	structure Tokens : T_TOKENS
	val checkToken : (string * int) -> (Tokens.svalue,int)Tokens.token
end

functor TTokenTable(structure Tokens : T_TOKENS): TTOKENTABLE = 
struct
  
  structure Tokens = Tokens
  type item = (int * int) -> (Tokens.svalue, int) Tokens.token
  exception Keyword
  exception LexError
  val keywords : item AtomTable.hash_table = AtomTable.mkTable(64, Keyword)
    
  val _ = let
    val insert = AtomTable.insert keywords
    fun ins (s, item) = insert (Atom.atom s, item)
  in
    app ins ([
 	      ("Output",     Tokens.OUTPUT),
 	      ("Transform",  Tokens.TRANSFORM),
 	      ("TyName",     Tokens.TYNAME),
 	      ("TyDecl",     Tokens.TYDECL),
 	      ("String",     Tokens.STR),
 	      ("IO",         Tokens.IO),
	      ("Palternate", Tokens.PALTERNATE),
	      ("Parray",     Tokens.PARRAY),
	      ("Penum",      Tokens.PENUM),
	      ("Pstruct",    Tokens.PSTRUCT),
	      ("Ptypedef",   Tokens.PTYPEDEF),
	      ("Punion",     Tokens.PUNION),
	      ("Begin",      Tokens.BEGIN),
	      ("End",        Tokens.END),
	      ("Pre",        Tokens.PRE),
	      ("Each",       Tokens.EACH),
	      ("Post",       Tokens.POST)
              ])


  end

  fun checkToken (s, pos) = let
    val endPos = pos + size s
    val name = Atom.atom s
  in
    case (AtomTable.find keywords name)
      of (SOME tokFn) => tokFn(pos, endPos)
       | NONE => Tokens.ID(s,pos,endPos)
  (* end case *)
  end

end
