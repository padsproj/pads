(* Collects naming functions common to parse tree and AST. *)
structure CommonNames = 
struct

fun recPre s = "_" ^ s (* Assign a prefix to the type underlying a recursive type *)

end
