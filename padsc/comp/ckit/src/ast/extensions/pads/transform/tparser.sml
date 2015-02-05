structure TParser : TPARSER = 
struct

  (* instantiate parser structures *)
  structure TLrVals = TLrValsFun(structure Token = LrParser.Token)

  structure TTokTable = TTokenTable(structure Tokens = TLrVals.Tokens)

  structure TLex = TLexFun(structure Tokens = TLrVals.Tokens
			   structure TTokTable = TTokTable)

  structure P = JoinWithArg(structure ParserData = TLrVals.ParserData
			    structure Lex = TLex
			    structure LrParser = LrParser)

  fun parseFile errState f = 
    let val sourceMap = SourceMap.newmap{srcFile=f}

	fun lexErr (p1, p2, msg) =
	  Error.error (errState, SourceMap.location sourceMap (p1, p2), msg)
	fun lexWarn (p1, p2, msg) =
	  Error.warning (errState, SourceMap.location sourceMap (p1, p2), msg)
	fun parseErr (msg, p1, p2) =
	  Error.error (errState, SourceMap.location sourceMap (p1, p2), msg)

	fun inputc instrm i = TextIO.inputN(instrm,i)

	val lexArg = {comLevel = ref 0,
		      sourceMap = sourceMap,
		      charlist = ref ([] : string list),
		      stringstart = ref 0,
		      errWarn = {err=lexErr, warn = lexWarn}
		      }
	val instrm = TextIO.openIn f
	val lookahead = 15

	val lexer = LrParser.Stream.streamify (TLex.makeLexer (inputc instrm) lexArg)
	val (res,_) = P.parse(lookahead, lexer, parseErr, sourceMap) 
	val _ = TextIO.closeIn instrm
     in res
    end
    handle P.ParseError =>
	(TextIO.output(Error.errStream errState,"ParseError raised\n");
	 [])

  val tFile = ref ""

  fun parseString errState s src = 
    let val _ = tFile := (OS.FileSys.tmpName () ^".p")
	val sourceMap = SourceMap.newmap{srcFile=src}
        
        val tStrm = TextIO.openOut (!tFile)
        val () = (TextIO.output(tStrm, (s^"\n")); TextIO.closeOut tStrm)

	fun lexErr (p1, p2, msg) =
	  Error.error (errState, SourceMap.location sourceMap (p1, p2), msg)
	fun lexWarn (p1, p2, msg) =
	  Error.warning (errState, SourceMap.location sourceMap (p1, p2), msg)
	fun parseErr (msg, p1, p2) =
	  Error.error (errState, SourceMap.location sourceMap (p1, p2), msg)

	fun inputc instrm i = TextIO.inputN(instrm,i)

	val lexArg = {comLevel = ref 0,
		      sourceMap = sourceMap,
		      charlist = ref ([] : string list),
		      stringstart = ref 0,
		      errWarn = {err=lexErr, warn = lexWarn}
		      }
	val instrm = TextIO.openIn (!tFile)
	val lookahead = 15

	val lexer = LrParser.Stream.streamify (TLex.makeLexer (inputc instrm) lexArg)
	val (res,_) = P.parse(lookahead, lexer, parseErr, sourceMap) 
	val _ = TextIO.closeIn instrm
	val _ =  OS.FileSys.remove (!tFile) handle e => (); 
     in res
    end
    handle P.ParseError =>
	(TextIO.output(Error.errStream errState,"ParseError raised\n");
         OS.FileSys.remove (!tFile) handle e => (); 
	 [])

end (* structure Parser *)
