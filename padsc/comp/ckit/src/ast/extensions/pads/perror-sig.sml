
signature PERROR =
sig
    exception PadsFail

    val bug : string -> 'a
    val fail : string -> 'a
    val error : string -> unit
    val warn : string -> unit

    (* No mutually recursive modules ==> hidden state 
	                             ==> setup function. *)
    val setup : Error.errorState -> (string -> unit) -> (string -> unit) -> unit
end
