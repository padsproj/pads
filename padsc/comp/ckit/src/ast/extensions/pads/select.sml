structure Select =
struct
   structure PT = ParseTree

   datatype selectInfo = Select of {selName : string, tyName : string, args : IntInf.int list,
				    offset : IntInf.int, size : IntInf.int}

   datatype pathNode = Id of string | Dot of string | Sub of IntInf.int 
   type path = pathNode list

   fun sexprToPath (p) : path = 
       let fun cnvExp (exp, accumP) = 
	       case exp
	       of PT.Id s => (Id s):: accumP
	       |  PT.Binop (PT.Dot, e1, PT.Id f) => cnvExp(e1, (Dot f) :: accumP)
	       |  PT.Binop (PT.Sub, e1, PT.IntConst (i,b))  => cnvExp(e1, (Sub  i) :: accumP)
	       |  p => raise Fail "Ill-formed path expression."
       in
	   cnvExp(p, [])
       end


   fun selectToString (Select {selName, tyName, args, offset, size}) =
       let fun argsToString [] = ""
             | argsToString [i] = IntInf.toString i
             | argsToString (i::is) = (IntInf.toString i)^","^(argsToString is)
       in
	   selName^"="^tyName^"(:"^(argsToString args)^":)"^"["^(IntInf.toString offset)^","^(IntInf.toString size)^"]"
       end

   fun selectListToString sl = 
       let fun h sl = 
	   case sl 
           of [] => ""
           |  [s] => (selectToString s)
           |  (s::sl) => ((selectToString s)^"|"^(h sl))
       in
	   "{"^(h sl)^"}"
       end

   fun cmp (Select {offset=offset1, size=size1,...}, Select {offset=offset2, size=size2,...})  = 
       if IntInf.< (offset1, offset2) then LESS
       else if IntInf.>(offset1, offset2) then GREATER
       else if IntInf.<(size1, size2) then LESS
       else if IntInf.>(size1, size2) then GREATER
       else EQUAL

   val selectList : selectInfo list ref = ref []

   fun insert (s : selectInfo) = 
       selectList := s::(!selectList)

   fun listSelections () = List.rev(!selectList)

   fun isSelection () = not (List.null (!selectList))
   fun reset () = selectList := nil

end