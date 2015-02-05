structure PError : PERROR =
struct
        exception PadsFail

	fun dummy (s : string) : unit = (print "Dummy Error Function.";
					 raise PadsFail)

	val   bugRef = ref dummy
	val  failRef = ref dummy
	val errorRef = ref dummy
        val  warnRef = ref dummy

	fun   bug s = ((!bugRef) s; 
		       raise PadsFail)
	fun  fail s = ((!failRef) s;
		       raise PadsFail)
	fun error s = (!errorRef) s
	fun warn s = (!warnRef) s

	fun setup errorState err warn=
	    let fun   bug' s = Error.bug errorState ("P: " ^ s)
		fun error' s = err ("(Pads) " ^ s)
		fun  fail' s = error' s
                fun warning' s = warn ("(Pads) " ^ s)
	    in
		  bugRef :=   bug';
		 failRef :=  fail';
		errorRef := error';
		 warnRef := warning';
		()
	    end
end
