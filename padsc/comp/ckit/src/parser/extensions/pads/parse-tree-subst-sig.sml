signature PARSE_TREE_SUBST =
sig
    val substExp: (string * ParseTree.expression * ParseTree.expression) ->
	ParseTree.expression

    val substExps : (string * ParseTree.expression) list ->  ParseTree.expression -> 
	ParseTree.expression

    val isFreeInExp : (string list * ParseTree.expression) -> bool

    val expIsClosed : (string list * ParseTree.expression) -> bool

    val mungePCT : ((string -> string) * ParseTree.ctype) -> ParseTree.ctype

end
