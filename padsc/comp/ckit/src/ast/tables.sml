(* tables.sml *)

structure Tables =
struct

  type aidtab = Ast.ctype Aidtab.uidtab
  type tidtab = Bindings.tidBinding Tidtab.uidtab
  type paidtab = PTys.pTyInfo Paidtab.uidtab
end
