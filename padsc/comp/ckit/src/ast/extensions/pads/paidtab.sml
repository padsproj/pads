(* Copyright (c) 1998 by Lucent Technologies *)

(* imperative tables for "type adornments" *)
(* DBM: was named TypeAdornmentTabImp *)

structure Paidtab = UidtabImpFn (structure Uid = Paid)
