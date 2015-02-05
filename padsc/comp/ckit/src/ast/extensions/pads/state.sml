structure PadsState =
struct
  val padsName : string ref = ref "";
  fun reset name = 
     (padsName := name;
      Select.reset();
      CharClass.reset()
      )
end
