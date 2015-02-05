structure CharClass  =
struct
   structure PT = ParseTree

   type Info = PT.statement

   val ccList : Info list ref = ref []

   fun insert (c : Info) = 
       ccList := c::(!ccList)

   fun listClasses () = List.rev(!ccList)

   fun isCharClass () = not (List.null (!ccList))

   fun reset() = ccList := nil

end