structure Cluster = struct
  structure PT   = ParseTree     (* the parse tree *)
  structure PX   = ParseTreeExt  (* Pads extensions *)
  structure P    = ParseTreeUtil (* Utility functions for manipulating the parse tree *)
  structure PE   = PError        (* Error reporting utilities *)
  structure PBTys = PBaseTys     (* Information about the pads base types *)
  structure PL   = PLib          (* Information about values/functions available from pads library *)
  structure PN = PNames
  structure BU = BuildUtils

  open PNames

  type pty = PX.Pty
  type pcexp = ParseTree.expression
  type pcty = ParseTree.ctype

  val analysis        = "cluster"  

  val def_analysis    = "default_" ^analysis
  val uint32Analysis  = "Puint32_" ^analysis
  val intAnalysis     = "Pint32_"  ^analysis
  val defaultAnalysisPCT = P.makeTypedefPCT ("P_"^analysis)

  fun analysisSuf  s = s^"_"^analysis
  val def_analysisX = PT.Id def_analysis
  val defPackage = (defaultAnalysisPCT, def_analysisX, def_analysis)
  val uint32AnalysisPCT = P.makeTypedefPCT uint32Analysis
  val intAnalysisPCT    = P.makeTypedefPCT intAnalysis

  fun setParamSuf s = s^"_setPara"
  fun lookupAnalysis(ty:pty) = 
      case ty of PX.Name s => 
	  ( case PBTys.find(PBTys.baseInfo, Atom.atom s)
		of NONE => analysisSuf s  (* non-base type; acc constructed from type name*)
	        |  SOME(b:PBTys.baseInfoTy) => analysisSuf(Atom.toString (#repname b)))


  (*  Perror_t T_acc_add (P_t* , T_acc* , T_pd*, T* , Puint32 *isFull) *)
  fun genAddFun (addName, var, varPCT, pdPCT, repPCT, bodySs) = 
      let val paramTys = [P.ptrPCT PL.toolStatePCT, 
			  P.ptrPCT varPCT, 
			  P.ptrPCT pdPCT,
			  P.ptrPCT repPCT,
			  P.ptrPCT PL.uint32PCT]
	  val paramNames = [pads, var, pd, rep, "isFull"]
	  val formalParams = List.map P.mkParam (ListPair.zip (paramTys, paramNames))
	  val addDeclSs =  [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val fullDeclSs = [P.varDeclS(PL.uint32PCT, "tIsFull", P.zero)]
	  val setIsFull = [P.assignS(P.starX(PT.Id "isFull"), PT.Id "tIsFull")]
	  val addReturnS = [BU.genReturnChk (PT.Id nerr)]
	  val bodySs = addDeclSs @ fullDeclSs @ bodySs @ setIsFull @ addReturnS
	  val returnTy =  PL.toolErrPCT
	  val addFunED = 
	      P.mkFunctionEDecl(addName, formalParams, PT.Compound bodySs, returnTy)
      in
	  addFunED
      end

  fun chkAddFun (funName, accX, pdX, repX) = 
      [PT.IfThen(P.eqX(PL.P_ERROR, 
		       PT.Call(PT.Id funName, 
			       [PT.Id pads, accX, pdX, repX, PT.Id "isFull"])),
		 BU.incNerrCompS),
       PT.IfThen(P.starX(PT.Id "isFull"), PT.Compound[ P.assignS(PT.Id "tIsFull", P.starX(PT.Id "isFull"))])]


  fun genRepTypedef (name,baseTy) = 
      let val analysisED = P.makeTyDefEDecl (P.makeTypedefPCT (lookupAnalysis baseTy), analysisSuf name)
	  val analysisPCT = P.makeTypedefPCT (analysisSuf name)		
      in
	  (analysisED, analysisPCT)
      end

  fun split3 [] = ([],[],[])
    | split3 ((a,b,c)::xs) = 
       let val (ays, bs, cs) = split3 xs
       in
	   (a::ays, b::bs, c::cs)
       end

  fun genWalkFunsTypedef (name, baseTy, thePCT, whichSuf, others) = 
      let val whichFun = (whichSuf o analysisSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichBodySs = BU.chk3Pfun(whichSuf (lookupAnalysis baseTy), (PT.Id analysis)::otherXs)
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ whichBodySs @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT::otherPCTs, analysis::otherVars, whichBodySs)
      in
	  whichFunED
      end


  fun genAddFunTypedef (name, baseTy, analysisPCT, repPCT, pdPCT, repX) = 
      let val addFun = (addSuf o analysisSuf) name
          val bodySs = chkAddFun(addSuf (lookupAnalysis baseTy), PT.Id analysis,  PT.Id pd, repX)
	  val addFunED = genAddFun(addFun, analysis, analysisPCT, pdPCT, repPCT, bodySs)
      in
	  addFunED
      end

  fun genReportFunTypedef(name, baseTy, analysisPCT,kind) =
      let val reportFun = (reportSuf o analysisSuf) name
	  val repioCallX = PT.Call(PT.Id((ioSuf o reportSuf) (lookupAnalysis baseTy)),
				   [PT.Id pads, PT.Id outstr, PT.Id prefix, PT.Id what, PT.Id nst, PT.Id analysis])
	  val reportBodySs = [PT.Expr repioCallX]
	  val reportFunEDs = BU.genReportFuns(reportFun, kind^" "^name, analysisPCT, analysis, reportBodySs)
      in
	  reportFunEDs
      end


  fun genSimple (name, baseTy, repPCT, pdPCT, kind) = 
      let val (analysisED, analysisPCT) = genRepTypedef  (name, baseTy)
	  val initFunED = genWalkFunsTypedef(name, baseTy, analysisPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsTypedef(name, baseTy, analysisPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsTypedef(name, baseTy, analysisPCT, resetSuf,[])
	  val cleanupFunED = genWalkFunsTypedef(name, baseTy, analysisPCT, cleanupSuf,[])
	  val addFunED = genAddFunTypedef(name, baseTy, analysisPCT, repPCT, pdPCT, PT.Id rep)
	  val reportFunEDs = genReportFunTypedef(name, baseTy, analysisPCT,kind) 
      in
	  [analysisED, initFunED, setParamsFunED, resetFunED,  addFunED] @  reportFunEDs @  [cleanupFunED] 
      end


  fun genRepEnum name = 
      let val analysisED  = P.makeTyDefEDecl (intAnalysisPCT, analysisSuf name)
	  val analysisPCT = P.makeTypedefPCT(analysisSuf name)
      in
	  (analysisED, analysisPCT)
      end

  fun genWalkFunsEnum (name, analysisPCT, whichSuf, others) = 
      let val whichFun : string = (whichSuf o analysisSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val whichBodyE = PT.Call(PT.Id(whichSuf intAnalysis), [PT.Id pads, PT.Id analysis]@otherXs)
	  val whichReturnS = PT.Return whichBodyE
	  val whichFunED = BU.gen3PFun(whichFun, analysisPCT::otherPCTs, analysis::otherVars, [whichReturnS])
      in
	  whichFunED
      end

  (* This version is more efficient, but less uniform.  Optimize if performance becomes a problem. *)
  fun genAddFunEnum(name, analysisPCT, repPCT, pdPCT) =
      let val addFun = (addSuf o analysisSuf) name
	  val addX = PT.Call(PT.Id(addSuf intAnalysis), 
				      [PT.Id pads, PT.Id analysis, PT.Id pd, 
				       PT.Cast(P.ptrPCT PL.intPCT, PT.Id rep)])
	  val addReturnS = PT.Return addX
	  val addBodySs =  [addReturnS]
	  val addFunED = BU.genAddFun(addFun, analysis, analysisPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  fun genAddFunEnum(name, analysisPCT,repPCT,pdPCT) = 
      genAddFunTypedef(name, PX.Name "Pint32", analysisPCT, repPCT,pdPCT, PT.Cast(P.ptrPCT PL.intPCT, PT.Id rep))

  fun genReportFunEnum(name, analysisPCT) =
      let val reportFun = (reportSuf o analysisSuf) name
	  val repioCallX = BU.callEnumPrint((ioSuf o reportSuf o mapSuf) intAnalysis,
					    PT.Id prefix, PT.Id what, PT.Id nst,
					    PT.Id(toStringSuf name), PT.Id analysis)
	  val reportBodySs = [PT.Expr repioCallX]
	  val reportFunEDs = BU.genReportFuns(reportFun, "enum "^name, analysisPCT, analysis, reportBodySs)
      in
	  reportFunEDs
      end

  fun genEnum (name, repPCT, pdPCT) = 
      let val (analysisED, analysisPCT) = genRepEnum  name 
	  val initFunED = genWalkFunsEnum(name, analysisPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsEnum(name, analysisPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsEnum(name, analysisPCT, resetSuf,[])
	  val cleanupFunED = genWalkFunsEnum(name, analysisPCT, cleanupSuf,[])
	  val addFunED = genAddFunEnum(name, analysisPCT, repPCT, pdPCT)
	  val reportFunEDs = genReportFunEnum(name, analysisPCT)

      in
	  [analysisED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFunEDs @ [cleanupFunED]
      end


  fun genRepArray name baseTy = 
      let val baseFields = [(arrayLevel, P.makeTypedefPCT (lookupAnalysis baseTy), SOME "Analysisogram for all array elements")]
	  val analysisFields = (arrayLen, uint32AnalysisPCT, SOME "Analysisogram for array length")::baseFields
	  val analysisED = P.makeTyDefStructEDecl (analysisFields, analysisSuf name)
	  val analysisPCT = P.makeTypedefPCT (analysisSuf name)			
      in
	  (analysisED, analysisPCT)
      end

  fun genWalkFunsArray (name, baseTy, whichPCT, whichSuf,others) = 
      let val whichFun = (whichSuf o analysisSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val elemFunName = whichSuf (lookupAnalysis baseTy)
	  val lengthX = P.addrX(P.arrowX(PT.Id analysis, PT.Id length))
	  val doLength = BU.chk3Pfun(whichSuf uint32Analysis, lengthX::otherXs)
	  val arrayX = P.addrX(P.arrowX(PT.Id analysis, PT.Id arrayLevel))
          val doArraySs = BU.chk3Pfun (elemFunName, arrayX::otherXs)
	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichReturnSs = [BU.genReturnChk (PT.Id nerr)]
	  val whichBodySs = whichDeclSs @ doLength @ doArraySs @ whichReturnSs
	  val whichFunED = BU.gen3PFun(whichFun, whichPCT::otherPCTs, analysis::otherVars, whichBodySs)
      in
	  whichFunED
      end

  (* -- generate analysisogram add function *)
  fun genAddFunArray (name, baseTy, analysisPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o analysisSuf) name
	  val elemFunName = addSuf (lookupAnalysis baseTy)
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), P.arrowX(PT.Id pd, PT.Id errCode))]
	  val doLength = chkAddFun(addSuf uint32Analysis, P.getFieldX(analysis, length), P.addrX(PT.Id tpd), P.getFieldX(rep, length))
	  fun getArrayFieldX (base, field) = P.addrX(P.subX(P.arrowX(PT.Id base, PT.Id field), PT.Id "i"))
	  val doArrayDetailSs = [PT.Compound
				    [P.varDeclS'(P.int, "i"),
				     PT.For(P.assignX(PT.Id "i", P.zero),
					    P.ltX(PT.Id "i", P.arrowX(PT.Id rep, PT.Id length)),
					    P.postIncX (PT.Id "i"),
					    PT.Compound (chkAddFun(elemFunName, 
								   P.getFieldX(analysis, arrayLevel), 
								   getArrayFieldX(pd, arrayElts), 
								   getArrayFieldX(rep, arrayElts))))]]
	  val addBodySs = addDeclSs @ initTpdSs @ BU.ifNotPanicSkippedSs(doLength @ doArrayDetailSs)
	  val addFunED = genAddFun(addFun, analysis, analysisPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  (* -- generate analysisogram report function array *)
  fun genReportFunArray (name, baseTy, analysisPCT) = 
      let val reportFun = (reportSuf o analysisSuf) name
	  val elemFunName = ioSuf(reportSuf (lookupAnalysis baseTy))
	  val baseTyStr = case baseTy of PX.Name n => n
	  val lengthX = P.arrowX(PT.Id analysis, PT.Id length)
	  val doLengthSs =  BU.chkPrintCall(ioSuf(reportSuf uint32Analysis), [PT.Id outstr, PT.String "Array lengths", 
									     PT.String "array length", P.intX ~1, P.addrX(lengthX)])
	  val arrayX = P.arrowX(PT.Id analysis, PT.Id arrayLevel)
          val doArraySs = BU.chkPrintCall (elemFunName, [PT.Id outstr, PT.String "allArrayElts", PT.String "all array elements", 
							 PT.Id nst, P.addrX (arrayX)])

	  val reportBodySs   = doLengthSs @ doArraySs 
	  val reportFunEDs   = BU.genReportFuns(reportFun, "array "^ name ^" of "^baseTyStr, 
						analysisPCT, analysis, reportBodySs)
      in
	  reportFunEDs
      end


  fun genArray(name, baseTy, repPCT, pdPCT) = 
      let val (analysisED, analysisPCT) = genRepArray name baseTy
	  val initFunED    = genWalkFunsArray (name, baseTy, analysisPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsArray (name, baseTy, analysisPCT, setParamSuf,[defPackage])
	  val resetFunED   = genWalkFunsArray (name, baseTy, analysisPCT, resetSuf,[])
	  val addFunED     = genAddFunArray   (name, baseTy, analysisPCT, repPCT, pdPCT)
	  val reportFunEDs = genReportFunArray(name, baseTy, analysisPCT)
	  val cleanupFunED = genWalkFunsArray (name, baseTy, analysisPCT, cleanupSuf,[])
      in
	  [analysisED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFunEDs @ [ cleanupFunED]
      end

  (* PUNIONS *)
  fun genRepUnion ptyfuns name variants = 
      let fun genAnalysisFull ({pty: PX.Pty, args: pcexp list, name: string, 
			    isVirtual: bool, isEndian: bool, 
			    isRecord, containsRecord, largeHeuristic: bool,
			    pred, comment: string option,...}: BU.pfieldty) = 
	  if not isVirtual then 
	      let val predStringOpt = Option.map BU.constraintToString pred
		  val fullCommentOpt = BU.stringOptMerge(comment, predStringOpt)
	      in
		  [(name, P.makeTypedefPCT (lookupAnalysis pty), fullCommentOpt )]
	      end
	  else []
	  fun genAnalysisBrief e = []
	  fun genAnalysisMan ptyfuns m = BU.genMan ptyfuns (lookupAnalysis, NONE, false, m)
	  val analysisFields = P.mungeFields genAnalysisFull genAnalysisBrief (genAnalysisMan ptyfuns) variants
	  val auxAnalysisFields = [(unionTag, intAnalysisPCT, NONE)]

	  val analysisED = P.makeTyDefStructEDecl (auxAnalysisFields @ analysisFields, analysisSuf name)
	  val analysisPCT = P.makeTypedefPCT (analysisSuf name)			 
      in
	  (analysisED, analysisPCT)
      end

  fun genWalkFunsUnion (ptyfuns, name, variants, thePCT, whichSuf,others) = 
      let val whichFun = (whichSuf o analysisSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  fun genWhichFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else BU.callFun(whichSuf (lookupAnalysis pty), analysis, name,otherXs)
          
	  fun genWhichBrief e = []
	  fun genWhichMan (ptyfuns, whichSuf) m = BU.genFunMan ptyfuns (lookupAnalysis, whichSuf, analysis, otherXs, m)

	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichFields = P.mungeFields genWhichFull genWhichBrief (genWhichMan (ptyfuns, whichSuf)) variants
	  val auxFields = BU.chk3Pfun(whichSuf intAnalysis, (P.getFieldX(analysis, unionTag))::otherXs)
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ auxFields @ whichFields @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT::otherPCTs, analysis::otherVars, whichBodySs)
      in
	  whichFunED
      end

  fun genAddFunUnion (ptyfuns, name, variants, analysisPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o analysisSuf) name
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), 
				     P.condX(P.eqX(P.arrowX(PT.Id pd, PT.Id errCode),
						   PL.P_UNION_MATCH_FAILURE),
					     PL.P_UNION_MATCH_FAILURE, PL.P_NO_ERROR))]
	  val addTagSs = chkAddFun(addSuf intAnalysis, P.getFieldX(analysis, unionTag), P.addrX(PT.Id tpd), 
				   PT.Cast(P.ptrPCT PL.intPCT, P.getFieldX(rep, unionTag)))
	  fun fieldAddrX (base, name) = P.addrX(P.arrowX(PT.Id base, PT.Id name))
	  fun genCase (name, pty, initSs, pdX) = 
	      let val funName = addSuf (lookupAnalysis pty)
		  val repX = P.getUnionBranchX(rep, name)
		  val caseSs = initSs @ chkAddFun(funName, fieldAddrX(analysis, name), pdX, repX)
	      in
		  P.mkBreakCase(PT.Id name, SOME caseSs)
	      end
	  fun genVirt name = P.mkCommentBreakCase(PT.Id name, "Pomit branch: cannot accumulate", NONE)

	  fun genAddFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then genVirt name
	      else genCase(name, pty, [], P.getUnionBranchX(pd, name))
	  fun genAddBrief e = []
	  fun genAddMan (ptyfuns as (isPadsTy, getPadsName)) ({tyname, name,isVirtual,...}:BU.pmanty) = 
	      if isVirtual then genVirt name
	      else case isPadsTy tyname 
                   of PTys.CTy =>  P.mkCommentBreakCase(PT.Id name, "branch has C type: C type accum not implemented (yet)", NONE) 
	     	    | _  => (let val pty = getPadsName tyname
			     in
				 genCase(name, getPadsName tyname, [],  P.getUnionBranchX(pd, name))
			     end)

	  val addFields = P.mungeFields genAddFull genAddBrief (genAddMan ptyfuns) variants
	  val errBranchSs = P.mkCommentBreakCase(PT.Id(errSuf name), "error case", NONE)
	  val addVariantsSs = [PT.Switch (P.arrowX(PT.Id rep, PT.Id unionTag), PT.Compound (addFields @ errBranchSs))]
	  val addBodySs = addDeclSs @ initTpdSs @ BU.ifNotPanicSkippedSs(addTagSs @ addVariantsSs)
	  val addFunED = genAddFun(addFun, analysis, analysisPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  fun genReportFunUnion (ptyfuns, name, variants, analysisPCT, fromOpt) = 
      let val reportFun = (reportSuf o analysisSuf) name
	  val header = if fromOpt then "opt" else "union"
	  val reportTags = [
			     BU.chkPrint(BU.callEnumPrint((ioSuf o reportSuf o mapSuf) intAnalysis,
							 PT.String header, PT.String "tag", P.intX ~1,
							 PT.Id((toStringSuf o tgSuf) name), P.getFieldX(analysis, unionTag))),
			    PL.sfprintf(PT.Id outstr, 
					PT.String "\n[Describing each tag arm of %s]\n", 
					[PT.Id prefix])]
	  fun reportUnionField (pty, fieldName) = 
	      BU.genPrintPiece(ioSuf(reportSuf (lookupAnalysis pty)), fieldName, P.zero, P.getFieldX(analysis,fieldName), [])
	  fun genReportFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then [P.mkCommentS("Pomit branch: cannot accumulate")]
	      else reportUnionField(pty, name)

	  fun genReportBrief e = []
	  fun genReportMan (ptyfuns as (isPadsTy, getPadsName)) ({tyname, name,isVirtual,...}:BU.pmanty) = 
	      if isVirtual then [P.mkCommentS("Pomit branch: cannot accumulate")]
	      else case isPadsTy tyname 
                   of PTys.CTy => [] 
	     	    | _  =>  reportUnionField(getPadsName tyname, name)

	  val reportFields   = P.mungeFields genReportFull genReportBrief (genReportMan ptyfuns) variants
	  val reportBodySs   = reportTags @ reportFields 
	  val reportFunEDs   = BU.genReportFuns(reportFun, header^" unionTag "^name, analysisPCT, analysis, reportBodySs)
      in
	  reportFunEDs
      end


  fun genUnion ptyfuns (name, variants, repPCT, pdPCT, fromOpt) = 
      let val (analysisED, analysisPCT) = genRepUnion ptyfuns name variants
	  val initFunED = genWalkFunsUnion (ptyfuns, name, variants, analysisPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsUnion (ptyfuns, name, variants, analysisPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsUnion (ptyfuns, name, variants, analysisPCT, resetSuf,[])
	  val addFunED = genAddFunUnion(ptyfuns, name, variants, analysisPCT, repPCT, pdPCT)
	  val reportFunEDs = genReportFunUnion(ptyfuns, name, variants, analysisPCT, fromOpt)
	  val cleanupFunED = genWalkFunsUnion (ptyfuns, name, variants, analysisPCT, cleanupSuf,[])
      in
	  [analysisED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFunEDs @ [cleanupFunED]
      end

  (* PSTRUCTS *)
  fun genRepStruct ptyfuns name fields = 
      let fun genAnalysisFull ({pty: PX.Pty, args: pcexp list, name: string, 
			    isVirtual: bool, isEndian: bool, 
			    isRecord, containsRecord, largeHeuristic: bool,
			    pred, comment: string option,...}: BU.pfieldty) = 
	  if not isVirtual then 
	      let val predStringOpt = Option.map BU.constraintToString pred
		  val fullCommentOpt = BU.stringOptMerge(comment, predStringOpt)
	      in
		  [(name, P.makeTypedefPCT (lookupAnalysis pty), fullCommentOpt )]
	      end
	  else []
	  fun genAnalysisBrief e = []
	  fun genAnalysisMan ptyfuns m = BU.genMan ptyfuns (lookupAnalysis, NONE, false, m)
	  val analysisFields = P.mungeFields genAnalysisFull genAnalysisBrief (genAnalysisMan ptyfuns) fields
	  val analysisED = P.makeTyDefStructEDecl (analysisFields, analysisSuf name)
	  val analysisPCT = P.makeTypedefPCT (analysisSuf name)			 
      in
	  (analysisED, analysisPCT)
      end

  fun genWalkFunsStruct (ptyfuns, name, fields, thePCT, whichSuf, others) = 
      let val whichFun = (whichSuf o analysisSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  fun genWhichFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else BU.callFun(whichSuf (lookupAnalysis pty), analysis, name,otherXs)
          
	  fun genWhichBrief e = []
	  fun genWhichMan (ptyfuns, whichSuf) m = BU.genFunMan ptyfuns (lookupAnalysis, whichSuf, analysis, otherXs, m)

	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichFields = P.mungeFields genWhichFull genWhichBrief (genWhichMan (ptyfuns, whichSuf)) fields
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ whichFields @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT :: otherPCTs, analysis::otherVars, whichBodySs)
      in
	  whichFunED
      end


  fun genAddFunStruct (ptyfuns, name, fields, analysisPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o analysisSuf) name
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), PL.P_NO_ERROR)]

	  fun genAddFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else chkAddFun(addSuf (lookupAnalysis pty), P.getFieldX(analysis,name),  P.getFieldX(pd, name), P.getFieldX(rep,name))

	  fun genAddBrief e = []
	  fun genAddMan (ptyfuns as (isPadsTy, getPadsName)) ({tyname, name,isVirtual,...}:BU.pmanty) = 
	      if isVirtual then []
	      else case isPadsTy tyname 
                   of PTys.CTy => [] 
	     	    | _  => (let val pty = getPadsName tyname
			     in
				 chkAddFun(addSuf(lookupAnalysis pty), P.getFieldX(analysis,name), P.addrX(PT.Id tpd), P.getFieldX(rep, name))
			     end)

	  val addFields = P.mungeFields genAddFull genAddBrief (genAddMan ptyfuns) fields
	  val addBodySs = addDeclSs @ initTpdSs @ BU.ifNotPanicSkippedSs(addFields)
	  val addFunED = genAddFun(addFun, analysis, analysisPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end


  fun genReportFunStruct (ptyfuns, name, fields, analysisPCT) = 
      let val reportFun = (reportSuf o analysisSuf) name
	  val headerSs = [PL.sfprintf(PT.Id outstr, 
				      PT.String "\n[Describing each field of %s]\n", 
				      [PT.Id prefix])]
	  fun reportStructField (pty, fieldName) = 
	      BU.genPrintPiece(ioSuf(reportSuf (lookupAnalysis pty)), fieldName, P.zero, P.getFieldX(analysis,fieldName), [])
	  fun genReportFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else reportStructField(pty, name)

	  fun genReportBrief e = []
	  fun genReportMan (ptyfuns as (isPadsTy, getPadsName)) ({tyname, name,isVirtual,...}:BU.pmanty) = 
	      if isVirtual then []
	      else case isPadsTy tyname 
                   of PTys.CTy => [] 
	     	    | _  =>  reportStructField(getPadsName tyname, name)

	  val reportFields   = P.mungeFields genReportFull genReportBrief (genReportMan ptyfuns) fields
	  val reportBodySs   = headerSs @ reportFields 
	  val reportFunEDs   = BU.genReportFuns(reportFun, "struct "^name, analysisPCT, analysis, reportBodySs)
      in
	  reportFunEDs
      end

  fun genStruct ptyfuns (name, fields, repPCT, pdPCT) = 
      let val (analysisED, analysisPCT) = genRepStruct ptyfuns name fields
	  val initFunED = genWalkFunsStruct (ptyfuns, name, fields, analysisPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsStruct (ptyfuns, name, fields, analysisPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsStruct (ptyfuns, name, fields, analysisPCT, resetSuf,[])
	  val addFunED = genAddFunStruct(ptyfuns, name, fields, analysisPCT, repPCT, pdPCT)
	  val reportFunEDs = genReportFunStruct(ptyfuns, name, fields, analysisPCT)
	  val cleanupFunED = genWalkFunsStruct (ptyfuns, name, fields, analysisPCT, cleanupSuf,[])
      in
	  [analysisED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFunEDs @ [cleanupFunED]
      end

end
