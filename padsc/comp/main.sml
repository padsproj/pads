(* main.sml
 *
 * COPYRIGHT (c) 2002 AT&T Research
 *)

structure Main : sig

    datatype ReturnType = Parse of ParseTree.externalDecl list
      | Ast of Ast.ast
      | Nothing

    val main : bool -> (string * string list) -> OS.Process.status
    val emit : bool -> ReturnType

  end = struct
    structure PCL  = ParseCmdLine
    structure CKIT = ParseToAst

    datatype ReturnType = Parse of ParseTree.externalDecl list
      | Ast of Ast.ast
      | Nothing

    exception Exit of OS.Process.status
    exception DebugExn of ReturnType
 
    (* Translation state *)
    val anyErrors = ref false
    val curFile = ref ""
    val stage = ref ""

    (* Values/Flags supplied by user at command line *)
    val compilerFileLoc = "/padsc/comp/ckit/src/ast/extensions/pads/"


    datatype ArgType = Pads | Unknown
    val srcFiles = ref [] : (ArgType * string) list ref 
    val baseTables  = ref [] : string list ref  (* paths to user defined base ty info tables *)
    val accumulators  = ref [] : string list ref  (* type names for which we should generate accumulators *)

    val includes    = ref ""  (* paths user listed as include paths with -I flag *)
    val defines     = ref ""  (* symbols user defined with -U flag *)
    val undefines   = ref ""  (* symbols user undefined with -D flag *)
    val translates  = ref [] :  string list ref  (* files specifying a transform *)

    val traceFlag = ref true
    val xmlFlag   = ref true
    val histFlag   = ref false
    val clusterFlag = ref false
    val parseTreeOnlyFlag = ref false
    val astOnlyFlag = ref false
    val outputHeaderFileName = ref ""
    val outputHeaderFileFlag = ref false 
    val outputCFileName = ref ""
    val outputCFileFlag = ref false
    val outputDir = ref ""
    val outputDirFlag = ref false

    val xschemaNoneFlag = ref false
    val writeNoneFlag = ref false
    val readNoneFlag = ref false
    val accumNoneFlag = ref false
    val experimentFlag = ref false

    fun addPadsFile s =    srcFiles := ((Pads,s) :: !srcFiles)
    fun addUnknownFile s = srcFiles := ((Unknown,s) :: !srcFiles)

    fun addBaseTable s = baseTables := (s :: !baseTables)
    fun addAccumulator s = accumulators := (s :: !accumulators)

    fun addInclude i = (includes := (" -I "^i^(!includes)))
    fun addDefine  i = (defines := (" -D"^i^(!defines)))
    fun addUndefine  i = (undefines := (" -U"^i^(!undefines)))
    fun addTranslate  i = (translates := (i :: (!translates)))
  
    fun setHeaderOutputFile s = (
        outputHeaderFileName := s; 
        outputHeaderFileFlag := true)

    fun setCOutputFile s = (
        outputCFileName := s; 
        outputCFileFlag := true)
  
    fun setOutputDir s = (
        outputDir := s;
        outputDirFlag := true)


    val extensions = [("p", "PADS files", PCL.Extension(addPadsFile,true))]

    val flags_release = [
	 ("wnone", "suppress write function generation", PCL.BoolSet writeNoneFlag),
	 ("xsnone", "suppress XSchema generation", PCL.BoolSet xschemaNoneFlag),
	 ("anone", "suppress accumulator generation", PCL.BoolSet accumNoneFlag),
         ("x", "output Galax Data API",   PCL.BoolSet xmlFlag),
         ("hist", "output histogram functions",   PCL.BoolSet histFlag),
         ("cluster", "output cluster functions",   PCL.BoolSet clusterFlag),
         ("r", "output directory",        PCL.String (setOutputDir, false)),
         ("b", "add base type table",         PCL.String (addBaseTable, false)),
	 ("I", "augment include path",        PCL.String (addInclude, true)),
	 ("D", "add definition",              PCL.String (addDefine, true)),
	 ("U", "remove definition",           PCL.String (addUndefine, true)),
         ("t", "trace system commands",       PCL.BoolSet traceFlag)
        ]

    val flags_debug = [
         ("h", "output header file",      PCL.String (setHeaderOutputFile, false)),
         ("c", "output code file",        PCL.String (setCOutputFile, false)),

         ("a", "generate accumulator program",    PCL.String (addAccumulator, true)),	 
         ("parse", "generate parsetree only", PCL.BoolSet parseTreeOnlyFlag),
	 ("ast",   "generate ast only", PCL.BoolSet astOnlyFlag),
         ("experimental", "generate experimental features", PCL.BoolSet experimentFlag),
         ("T", "transform specification",      PCL.String (addTranslate, true))
        ]

    (* Error handling *)
    fun error msg = (
	  anyErrors := true;
	  TextIO.output(TextIO.stdErr, !curFile ^ ": ");
	  TextIO.output(TextIO.stdErr, msg);
	  TextIO.output1(TextIO.stdErr, #"\n"))

    fun err s = (print  (!stage ^ " failed: " ^ s ^ "\n");
		 raise Exit OS.Process.failure)

    (* SML directives *)
    fun silenceGC () = (SMLofNJ.Internals.GC.messages false)
    fun setPrintDepth () =
	(Compiler.Control.Print.printDepth := valOf(Int.maxInt);
	 Compiler.Control.Print.printLength := valOf(Int.maxInt))

    (* Utilities ***************************************************)
    val tempFiles = ref [] : string list ref
    fun tmp ext = 
	let val t = (OS.FileSys.tmpName ()) ^ ext
	in
	    tempFiles := t :: !tempFiles;
	    t
	end

    fun mungeFileName (fileName, from, to) = 
    (case OS.Path.splitBaseExt fileName
     of {base, ext=SOME from} =>
	 SOME (OS.Path.joinBaseExt{base=base, ext=SOME to})
     | _ => NONE (*end case *))

    fun rmFile f = 
	 let val relFopt = mungeFileName(f,"c", "o")
	 in
	  if !traceFlag then print ("rm " ^ f ^ "\n") else ();
	  OS.FileSys.remove f handle e => ();
	  (case relFopt of NONE => () 
              | SOME f' => (	
		 if !traceFlag then print ("rm " ^ f' ^ "\n") else ();
	         OS.FileSys.remove f' handle e => () )(*end case*))
	 end

    fun rm f = 
	(tempFiles := List.filter (fn x => x<>f) (!tempFiles);
        rmFile f)

    fun rmTmp () = (
	    List.app rmFile (!tempFiles);
	    tempFiles := [])


    fun exec s =
	((if !traceFlag then print (s ^ "\n") else ());
	 OS.Process.system s)

    (* Run preprocessor ********************************************)
    fun preprocess(padsDir, cc, baseTyFile, srcFile, destFile) = 
	let val srcFile = OS.FileSys.fullPath srcFile
            val ppFile = tmp ".c"
            val ppcommand = padsDir^"/scripts/ppp.pl "^ srcFile ^" > "^ppFile
            val combineStrLitsCmd = padsDir^"/scripts/c_str_lits.pl"
            val status = exec ppcommand
	    val () = if status <> OS.Process.success then err "Pads pre-process failed." else ()
            val compositeFile = tmp ".c"
            val includePrefix = ("#include <ckit-first.h>\n"^
				 "#include <pads-internal.h>\n"^
				 (if !xmlFlag then "#include <pglx-internal.h>\n" else "") ^ 
				 "#include \""^baseTyFile^"\"\n"^
                                 "\n")
            val compositeProg = (includePrefix ^
				 "#include \"" ^ppFile^"\"\n")
	    val outStrm = TextIO.openOut compositeFile
            val () = (TextIO.output(outStrm, compositeProg);
		      TextIO.closeOut outStrm)
            val command = (cc  (* invoke c compiler *)
                          ^ " -E "  (* preprocessor only *)
			  ^ "-DFOR_CKIT" (* tell include files to include prototypes for macros *)
                          ^ " -U__ppc__ "
                          ^ " -D__ppc64__ "
                          ^ " -U__APPLE_CC__ "
                          ^ (!defines)  (* symbols defined by user *)
                          ^ (!undefines)  (* symbols undefined by user *)
                          ^ (!includes)  (* augment include path *)
                          ^ " "
                          ^ compositeFile (* on composite file *)
(*                          ^ " | "
                          ^ combineStrLitsCmd (* combine C string literals *) *)
                          ^ " >"
                          ^ destFile)
	    val status = exec command
	in
	    (rm ppFile; rm compositeFile; status)
	end

    fun doParseOnly(srcFile:string) = 
       let val () = stage := "Parsing"
           val errorState = Error.mkErrState TextIO.stdErr
           val tree = Parser.parseFile errorState srcFile
       in (setPrintDepth(); 
	   raise DebugExn(Parse tree))
       end
  
    fun getAccStream(name) : TextIO.outstream = 
        let val name' = if !outputDirFlag 
			then OS.Path.joinDirFile {dir = (!outputDir),
						  file = OS.Path.file name}
			else name
	in
            TextIO.openOut name'
	    handle Io => err ("Couldn't open output file: " ^ name' ^ ".")
	end 

    fun getOutStream(destFile, from, to) : string * TextIO.outstream = 
	let val name = valOf (mungeFileName(destFile, from, to))
	in
	    (OS.Path.file name, getAccStream name)
	end
	
    fun buildIncludeName fileName = 
        let val {base,ext} = OS.Path.splitBaseExt(OS.Path.file fileName)
            fun cvt c = if Char.isAlphaNum c then (String.str o Char.toUpper) c else "_"
            val upper = String.translate (cvt) base
	in
	    "__"^upper^"__H__"
	end
    fun generateAccumProgram (padsDir, headerFile, name,
			      {memChar, repName,repInit,repRead,repClean,pdName,pdInit,pdClean,
			       accName,accInit,accAdd,accReport,accClean,...}:PTys.pTyInfo) =
	let val aname = name^".c"
	    val aoutstream = getAccStream(aname)
	in
	    TextIO.output(aoutstream, "#define PADS_TY(suf) " ^repName^ " ## suf\n\n");
	    TextIO.output(aoutstream, "#include \""^headerFile^"\"\n");
	    TextIO.output(aoutstream, "#include \"template/accum_report.h\"\n\n");

	    TextIO.flushOut aoutstream;
	    TextIO.closeOut aoutstream
	end

    fun generateMakeFile(padsDir, headerFile, genLibFile, makeFileName, name) = 
	let val moutstream = getAccStream(makeFileName)
	    val programName = name^".c"
            fun outputRule (exeName,suf) = 
		(TextIO.output(moutstream, exeName^":\t"^programName^" "^headerFile^" "^genLibFile);
		 TextIO.output(moutstream, " $(INCLUDE_DEPS) $(LIB_DEPS_"^suf^")\n");
		 TextIO.output(moutstream, "\t$(COMPILE_"^suf^") "^programName^" "^genLibFile);
		 TextIO.output(moutstream, " $(DYNAMIC_LIBS_"^suf^") -o $@\n"))

	in
	    TextIO.output(moutstream, "PADS_HOME="^padsDir^"\n");
	    TextIO.output(moutstream, "include $(PADS_HOME)/mk/rules.mk\n\n\n");
            outputRule(name, "O");
            outputRule(name^"-g", "D");
	    TextIO.flushOut moutstream;
	    TextIO.closeOut moutstream
	end
    fun compileAccum(makeFileName) = 
	let val () = print "Building accumulator program.\n"
	    val command = "cd "^(OS.FileSys.fullPath (!outputDir))^"; make -f " ^makeFileName
	    val () = print (command ^"\n")
	    val status = exec command
	    val command = "cd -"
	    val () = print (command ^"\n")
	in
	    if status = OS.Process.failure then
		        print "Build of accumulator program failed.\n"
			else ()
	end

    fun generateSelect(fileName) = 
	if Select.isSelection() then
	    let val (qoutname, qoutstream) = getOutStream(fileName, "p", "q")
		val itemsStr = Select.selectListToString (Select.listSelections())
	    in
		TextIO.output(qoutstream, itemsStr);
		TextIO.flushOut qoutstream;
		TextIO.closeOut qoutstream
	    end
	else ()


    fun generateAccum (padsDir, fileName, headerFile, genLibFile) = 
	let val p = PTys.pTys
	    fun doOne(name : string) = 
	        case PTys.find(Atom.atom name)
		  of NONE => err("File "^fileName^" does not contain a type "^name^". "^
				 "Could not generate accumlator program.\n")
		   | SOME s => (let val makeFileName = name^".mk"
				in
				    generateAccumProgram (padsDir,headerFile,name, s);
				    generateMakeFile (padsDir,headerFile,genLibFile,makeFileName, name);
				    compileAccum(makeFileName)
				end)
	in
	    List.app doOne (!accumulators)
	end

    fun generateXschema(padsDir, fileName, ast, tidtab,paidtab) =
	if ((!xmlFlag) orelse not (!writeNoneFlag)) andalso not (!xschemaNoneFlag) then  
	    let val (xoutname, xoutstream) = getOutStream(fileName, "p", "xsd")		(* This name computation is repeated in cnv-ext.sml*)
		val srcPath = OS.FileSys.fullPath(fileName)
	    in
		PPLib.ppToStrm((PPXSchemaAst.ppAst padsDir (SOME srcPath) paidtab) () tidtab) xoutstream ast;
		TextIO.flushOut xoutstream;
		TextIO.closeOut xoutstream			
	    end
	else ()

    fun generateDescXschema(padsDir, fileName, ast, tidtab,paidtab) =
	if ((!xmlFlag) orelse not (!writeNoneFlag)) andalso not (!xschemaNoneFlag) then  
	    let val (xoutname, xoutstream) = getOutStream(fileName, "p", "pxml")
		val srcPath = OS.FileSys.fullPath(fileName)
	    in
		PPLib.ppToStrm((PPDescXSchemaAst.ppAst padsDir (SOME srcPath) paidtab) () tidtab) xoutstream ast;
		TextIO.flushOut xoutstream;
		TextIO.closeOut xoutstream			
	    end
	else ()

    fun generateCoreLibrary(padsDir, ast, tidtab, fileName) = 
	let val srcFile = OS.Path.file fileName
	    val (houtname, houtstream) = 
		if !outputHeaderFileFlag then 
		    (OS.Path.file (!outputHeaderFileName), TextIO.openOut (!outputHeaderFileName))
		else getOutStream(fileName, "p", "h")
	    val (coutname, coutstream) = 
		if !outputCFileFlag then 
		    (OS.Path.file(!outputCFileName), TextIO.openOut (!outputCFileName))
		else getOutStream(fileName, "p", "c")
	    val includeName = buildIncludeName fileName
	in
	    TextIO.output(houtstream, "#ifndef "^ includeName ^"\n");
	    TextIO.output(houtstream, "#define "^ includeName ^"\n");
	    TextIO.output(houtstream, "#include \"pads.h\"\n");
	    if (!xmlFlag) then 
		(TextIO.output(houtstream, "#include \"pglx-internal.h\"\n"))
	    else ();
	    PPLib.ppToStrm ((PPAst.ppAst PPAst.HEADER (SOME srcFile)) () tidtab) houtstream ast;
	    TextIO.output(houtstream, "#endif /*  "^ includeName ^"  */\n");
	    TextIO.flushOut houtstream;
	    TextIO.closeOut houtstream;
	    TextIO.output(coutstream, "#include \"pads-internal.h\"\n");
	    if (!xmlFlag) then 
		(TextIO.output(coutstream, "#include \"pglx-internal.h\"\n");
		 TextIO.output(coutstream, "char* PDCI_source = \""^(OS.Path.file fileName) ^"\";\n"))
	    else ();
	    TextIO.output(coutstream, ("#include \"" ^ houtname ^ "\"\n"));
	    PPLib.ppToStrm ((PPAst.ppAst PPAst.IMPL (SOME srcFile)) () tidtab) coutstream ast;		   
	    TextIO.flushOut coutstream;
	    TextIO.closeOut coutstream;
	    (houtname, coutname)
	end

    fun generateTransforms(ast, tidtab, paidtab) = 
	    List.app (Transform.doFile (ast, tidtab, paidtab)) (!translates)

    fun generateOutput (padsDir, astInfo : BuildAst.astBundle, fileName) =
      let val {ast,tidtab,errorCount,warningCount,auxiliaryInfo={paidtab,...},...} = astInfo
	  val (houtname, coutname) = generateCoreLibrary(padsDir, ast, tidtab, fileName)
      in
	  generateSelect(fileName);
	  generateAccum(padsDir, fileName, houtname, coutname);
	  generateXschema(padsDir, fileName, ast,tidtab, paidtab);
	  generateDescXschema(padsDir, fileName, ast,tidtab, paidtab);
          generateTransforms(ast,tidtab,paidtab)
      end
	    
    fun doFile (padsDir, cc, baseTyFile) (typ, fname) = 
      (curFile := fname;
       case typ of Pads =>
	 let val () = PadsState.reset fname
	     val () = stage := "Preprocessing"
	     val ppoutFile = tmp ".c"
	     val status = preprocess(padsDir, cc, baseTyFile, fname, ppoutFile)
	     val () = if status <> OS.Process.success 
	              then err "Pre-processor failed."
		      else ()
	     val () = stage := "Parsing"
             val () = if (!parseTreeOnlyFlag) then doParseOnly ppoutFile else ()
	     val () = stage := "Translating"
	     val astInfo as {ast, tidtab, ...} = CKIT.fileToAst ppoutFile
             val () = if (!astOnlyFlag) then (setPrintDepth(); raise DebugExn(Ast ast)) else ()
	     val () = stage := "Generating output"
	 in
	     generateOutput(padsDir, astInfo, fname)
	 end
      | _ => error "Unrecognized file type")

    fun checkFlags _ = (* Check that the user didn't supply bogus flag combinations. *)
	if !readNoneFlag then
            (if !xmlFlag then err "-x flag illegal with -rnone flag" else ();
             xmlFlag := false; accumNoneFlag := true; writeNoneFlag := true; xschemaNoneFlag := true)
	else ()
        
    fun initState() = (* more customization in the future *)
	( if !accumNoneFlag  then PInput.emitAccum false else ();
	  if !writeNoneFlag  then PInput.emitWrite false else ();
	  if !experimentFlag then PInput.emitExperiment true else();
	  if !histFlag       then PInput.emitHist true else();
	  if !clusterFlag    then PInput.emitCluster true else();
          if !xmlFlag        then PInput.emitXML true else ();
          if !xschemaNoneFlag     then PInput.emitXSchema false else ())

    fun main release (cmd, args) = 
      (stage := "Command-line processing";
       let val padsDir = hd args
           val cc = hd (tl args)
           val arguments = tl (tl args)
           val flags = if release then flags_release @ extensions
                       else flags_release @ flags_debug @ extensions
           val banner = PCL.genBanner("padsc", 
				      "PADS Compiler version 2.01", flags)
           val () = PCL.parseArgs(arguments, flags, addUnknownFile, banner)
           val () = checkFlags()
           (* At this point, flag booleans have been set from command-line *)
           (* Generate base type typedefs from base description file *)
           val baseTyDefsFile = tmp ".h"
	   val internalBaseTysPath = [padsDir^compilerFileLoc^"base-ty-info.txt"]
	                             @(!baseTables)
       in
         PBaseTys.genPadsInternal(internalBaseTysPath, baseTyDefsFile);	   
         initState();
         app (doFile (padsDir, cc, baseTyDefsFile)) (!srcFiles); 
         rmTmp();
         if !anyErrors 
	     then  OS.Process.exit(OS.Process.failure)
	 else  OS.Process.exit(OS.Process.success)
       end)  
            handle PCL.Invalid => (rmTmp(); OS.Process.exit(OS.Process.failure))
                  | DebugExn r => raise DebugExn r
                  | Exit r => OS.Process.exit(OS.Process.failure)
                  | OS.SysErr(s, sopt) => (TextIO.output(TextIO.stdErr, 
					   concat[s,"\n"]); 
					   OS.Process.exit(OS.Process.failure))
                  | ex => (TextIO.output(TextIO.stdErr, concat[
		          "uncaught exception ", exnName ex,
		          " [", exnMessage ex, "]\n"
	                  ]);
			  app (fn s => TextIO.output(TextIO.stdErr, concat[
		          "  raised at ", s, "\n"
	                  ])) (SMLofNJ.exnHistory ex);
	                   OS.Process.exit(OS.Process.failure))



    (* Generates the compiler and exports an executable. *)
    fun emit release = 
	if release then 
	    (silenceGC();
	     SMLofNJ.exportFn ("../../lib/padsc", main release);
	    Nothing)
	else 
	    (if not (SMLofNJ.exportML "../../lib/padsc") then 
		 (print "\nPadsc translator image built.\n";
		  Nothing)
	     else ((silenceGC ();
		    main release ("", CommandLine.arguments()); Nothing)
		   handle DebugExn r => r))

  end; 

