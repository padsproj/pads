signature PARSECMDLINE =
sig
  datatype flagType = 
      Bool   of   bool -> unit
    | String of (string -> unit) * bool
    | Int    of    (int -> unit) * bool (* true = can occur multiply. *)
    | Float  of (real -> unit) * bool(* true = can occur multiply. *)
    | BoolSet of bool ref (* true if present, false otherwise. *)
    | Extension of (string -> unit) * bool

  exception Invalid

  val parseArgs : (string list * (string*string*flagType) list *
		   (string -> unit) * string) -> unit
(* parseArgs (arguments, flags, default, msg) 
 
 flags = [("a", "debug", Bool(fa)), 
 ("b","output file", String(fb)), 
 ("c","optimization level",Int(fc))]
 msg = "mytool is an amazing doohickey."
 default is a function to call when an argument is not recognized.

 There are two kinds of flags.  Regular flags which are prepended with
 a "-" and extensions which are prepended with a ".".
 
 All the flags are considered optional.  For boolean flags the
 associated function will always be called with a value of true
 if the flag is present and a value of false otherwise.  For string
 flags the function will be called with the following string in the
 string list unless that string is a flag.

 Every argument not associated with a flag is checked for its
 extension and passed to the appropriate extension function.  
 
 An empty command-line, or a desperately wrong command line
 generates.
 <msg>
 Try --help for a complete description of the options.
 
 A somewhat wrong command-line generates:
 <reason for error>
 Try --help for a complete description of the options.
 
 --help will print out the following formatted output.
 
 "-help" and "help" are reserved flag names.
 
 <flagname>  <flag desc>
 
 Flags should be unique.  If duplicate flags are provided the behavior 
 is undefined.
 
 Flags may occur multiple times on the comand-line if the appropriate
 boolean is set.
 
 We raise Fail("Invalid command-line") on failure.

 The flags are processed in left-to-right order.

 *)

  val genBanner : (string * string * (string * string * flagType) list) 
      -> string
(* A call genBanner(toolname,toolDescription,flags) generates a banner of 
 the form 
    toolDescription
    usage: toolname <short version of flags> 
    try --help for more detailed explanation.
  flags are the same as for parseArgs.
  *)

end
