(* Relies on Atom and AtomBinarySet provided by SMLNJ-LIB *)

structure ParseCmdLine : PARSECMDLINE = 
    struct

	structure Sort = ListMergeSort

	datatype flagType = 
	    Bool   of   bool -> unit
	  | String of (string -> unit) * bool
	  | Int    of (int -> unit) * bool
	  | Float  of (real -> unit) * bool
	  | BoolSet of bool ref
	  | Extension of (string -> unit) * bool

	exception Invalid

	fun pr s = TextIO.output(TextIO.stdOut, s)
	fun prErr s = TextIO.output(TextIO.stdErr, s)

	val helpMsg = "Try --help for a complete description of the options."
	fun stdMsg msg = (pr (msg ^ "\n");
			   pr (helpMsg ^ "\n"))

	fun errMsg msg = (pr ("error: " ^ msg ^ "\n");
			  pr (helpMsg ^ "\n");
			  raise Invalid)

	fun helpMsg (banner,flags) = 
	    let fun msg (f,m,Extension _) = ()
		  | msg (f,m,k) =  (pr ("-" ^ f ^ "\t" ^ m ^ "\n"))
		fun loop (hd::tl) = (msg hd; loop tl)
		  | loop [] = (pr "\n")
	    fun msg (f,m,Extension _) = (pr ("."^f^"\t"^m^"\n"))
		  | msg _ =  ()
		fun loop2 (hd::tl) = (msg hd; loop2 tl)
		  | loop2 [] = (pr "\n")
	    in
		pr (banner ^ "\n");
		loop flags;
		pr ("File extensions:\n");
		loop2 flags;
		()
	    end

	fun isFlag (s:string) = (String.sub(s,0) = #"-" 
				 handle Subscript => false)

	fun hasExtension extn file =
	    (case (OS.Path.splitBaseExt file) of
		 {base=b,ext=SOME x} => (x=extn)
	       | _ => false)

	val visitedFlags = ref AtomBinarySet.empty
	    
	fun isFlagVisited f = AtomBinarySet.member(!visitedFlags,Atom.atom f)
	fun visitFlag f =
	    (visitedFlags := AtomBinarySet.add (!visitedFlags,Atom.atom f))
	   
	(* getFlag returns a flag that matched if any, and the string
	 remaining in arg once the flag was removed. *)
	fun getFlag (flags, extensions) arg =
	    let fun matchHd (f,_,_) =  String.isPrefix ("-"^f) arg
		fun matchExtn(x,_,_) = hasExtension x arg
		fun rest flag =
			String.extract(arg,(String.size flag) + 1,NONE)
	    in
		case List.find matchHd flags of
		    NONE => (case List.find matchExtn extensions of
				 NONE => NONE
			       | SOME f => SOME (f,"") )
		  | SOME (f as (flag,_,_)) => SOME (f,rest flag)
	    end

	fun processFlag ((flag,_,kind),arg0,args) =
	    let fun invalidOption opt =
		    errMsg ("Invalid option \""^opt^"\"")
		fun getOption () =
		    (case args of 
			 [] => errMsg ("Switch -"^flag^" requires an argument")
		       | (opt :: rest) => 
			     if isFlag opt then (invalidOption opt)
			     else (opt,rest))				 
		val _ =
		    let val w = 
			case kind of
			    String(_,w) => w
			  | Int(_,w) => w
			  | Float(_,w) => w
			  | Extension(_,w) => w
			  | _ => false
		    in
			if isFlagVisited flag andalso not w then 
			    errMsg ("Multiple occurences of -"^flag)
			else ()
		    end
	    in		
		visitFlag flag;
		case kind of
		    Bool bFun =>
			(bFun true; args)
		  | String (sFun,w) => 
			let val (opt,rest) = getOption ()
			in
			    (sFun opt); rest
			end
		  | Int (iFun,w) =>
			let val (opt,rest) = getOption ()
			    val i = case Int.fromString opt of
				NONE => (invalidOption opt)
			      | SOME i => i				
			in
			    (iFun i); rest
			end
		  | Float (fFun,w) =>
			let val (opt,rest) = getOption ()
			    val f = case Real.fromString opt of
				NONE => (invalidOption opt)
			      | SOME i => i				
			in
			    (fFun f); rest
			end
		  | BoolSet b => (b := true; args)
		  | Extension(xFun,w) => (xFun arg0; args)
	    end

	fun parseArgs (args,flags,default,banner) =
	    let fun help b = (if b then 
				  (helpMsg (banner,flags); raise Invalid)
			      else ())
		    
		fun isExtn (_,_,Extension _) = true
		  | isExtn _ = false

		val helpFlag = ("-help","print help message",Bool help)
		val helpFlag2 = ("help","print help message",Bool help)
		    
		val flags' = (helpFlag :: helpFlag2 :: flags)
		fun cmpFlags ((f1,_,_),(f2,_,_))=(String.size f1 <= String.size f2)
		val flags' = Sort.sort cmpFlags flags'
		val (extns',flags') = List.partition isExtn flags'
		val getFlag = getFlag (flags',extns')

		fun loop [] = ()
		  | loop (hd::tl : string list) = 
		    (case getFlag hd of
			 NONE => (default hd; loop tl)
		       | SOME(f,"") =>
			     loop (processFlag (f,hd,tl))
		       | SOME(f,hd_left) => 
			     loop (processFlag (f,hd,hd_left::tl)))
			 
		fun callUnvisited (flag,_,kind) =
		    (case (isFlagVisited flag,kind) of
			 (false,Bool bFun) => (bFun false)
		       | (false,BoolSet b) => (b := false)
		       | _ => ())

		fun fail () = raise Invalid
	    in
		if args = [] then (stdMsg banner; fail ())
		else let val result = loop args
		     in 
			 (List.app callUnvisited flags; result)
		     end
	    end

	fun genBanner(toolname, tooldesc, flags) =
	    let fun genDesc (name,typ,w) =
		    (" [-"^name^typ^
		    (if w then " ...]" else "]"))
		fun describe_flag (name,_,kind) =
		    (case kind of
			 Bool _ => genDesc(name,"",false)
		       | String (_,w) => genDesc(name," <string>",w)
		       | Int (_,w) => genDesc(name," <int>",w)
		       | Float (_,w) => genDesc(name," <float>",w)
		       | BoolSet _ => genDesc(name,"",false)
		       | Extension(_,w) => "")
		val helpFlag = ("-help","",Bool (fn b => ()))
	    in
		tooldesc ^ "\n" ^
		toolname ^ " "^ 
		(String.concat (List.map describe_flag (flags @ [helpFlag]))) ^
		" file..."
	    end
    end
