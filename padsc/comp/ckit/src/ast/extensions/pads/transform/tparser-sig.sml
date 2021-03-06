signature TPARSER =
sig

  val parseFile : Error.errorState -> string -> TParseTree.externalDecl list
      (* parseFile takes an errorState and the name of a (preprocessed)
       * C source file and returns a list of external declaration parse
       * trees corresponding to the top-level declarations in the source file.
       * See ckit/src/parser/util/error-sig.sml for documentation on 
       * Error.errorState.
       *)
  val parseString : Error.errorState -> string -> string -> TParseTree.externalDecl list
end

