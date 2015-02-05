structure Hist = struct
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

  val hist = "hist"
  fun histSuf  s = s^"_"^hist
  val def_hist = "default_hist"
  val def_histX = PT.Id "default_hist"
  fun setParamSuf s = s^"_setPara"
  fun reportFullSuf s = s^"_reportFull"
  fun reportAllSuf s = s^"_reportAll"

  val uint32Hist    = "Puint32_hist"
  val uint32HistPCT = P.makeTypedefPCT "Puint32_hist"
  val intHist       = "Pint32_hist"
  val intHistPCT    = P.makeTypedefPCT "Pint32_hist"
  val defaultHistPCT = P.makeTypedefPCT "P_hist"
  val defPackage = (defaultHistPCT, def_histX, def_hist)



  fun lookupHist(ty:pty) = 
      case ty of PX.Name s => 
	  ( case PBTys.find(PBTys.baseInfo, Atom.atom s)
		of NONE => histSuf s  (* non-base type; acc constructed from type name*)
	        |  SOME(b:PBTys.baseInfoTy) => histSuf(Atom.toString (#repname b)))


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
      let val histED = P.makeTyDefEDecl (P.makeTypedefPCT (lookupHist baseTy), histSuf name)
	  val histPCT = P.makeTypedefPCT (histSuf name)		
      in
	  (histED, histPCT)
      end

  fun split3 [] = ([],[],[])
    | split3 ((a,b,c)::xs) = 
       let val (ays, bs, cs) = split3 xs
       in
	   (a::ays, b::bs, c::cs)
       end

  fun genWalkFunsTypedef (name, baseTy, thePCT, whichSuf, others) = 
      let val whichFun = (whichSuf o histSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichBodySs = BU.chk3Pfun(whichSuf (lookupHist baseTy), (PT.Id hist)::otherXs)
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ whichBodySs @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT::otherPCTs, hist::otherVars, whichBodySs)
      in
	  whichFunED
      end


  fun genAddFunTypedef (name, baseTy, histPCT, repPCT, pdPCT, repX) = 
      let val addFun = (addSuf o histSuf) name
          val bodySs = chkAddFun(addSuf (lookupHist baseTy), PT.Id hist,  PT.Id pd, repX)
	  val addFunED = genAddFun(addFun, hist, histPCT, pdPCT, repPCT, bodySs)
      in
	  addFunED
      end

  fun genReportFunTypedef(name, baseTy, histPCT, reportSuf, kind) =
      let val reportFun = (reportSuf o histSuf) name
	  val repioCallX = PT.Call(PT.Id((ioSuf o reportSuf) (lookupHist baseTy)),
				   [PT.Id pads, PT.Id outstr, PT.Id prefix, PT.Id what, PT.Id nst, PT.Id hist])
	  val reportBodySs = [PT.Expr repioCallX]
	  val reportFunEDs = BU.genReportFuns(reportFun, kind^" "^name, histPCT, hist, reportBodySs)
      in
	  reportFunEDs
      end


  fun genSimple (name, baseTy, repPCT, pdPCT, kind) = 
      let val (histED, histPCT) = genRepTypedef  (name, baseTy)
	  val initFunED = genWalkFunsTypedef(name, baseTy, histPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsTypedef(name, baseTy, histPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsTypedef(name, baseTy, histPCT, resetSuf,[])
	  val cleanupFunED = genWalkFunsTypedef(name, baseTy, histPCT, cleanupSuf,[])
	  val addFunED = genAddFunTypedef(name, baseTy, histPCT, repPCT, pdPCT, PT.Id rep)
	  val reportFullFunEDs = genReportFunTypedef(name, baseTy, histPCT, reportFullSuf, kind) 
	  val reportAllFunEDs = genReportFunTypedef(name, baseTy, histPCT, reportAllSuf, kind) 
      in
	  [histED, initFunED, setParamsFunED, resetFunED,  addFunED] @  
	  reportFullFunEDs @  reportAllFunEDs @ [cleanupFunED] 
      end


  fun genRepEnum name = 
      let val histED  = P.makeTyDefEDecl (intHistPCT, histSuf name)
	  val histPCT = P.makeTypedefPCT(histSuf name)
      in
	  (histED, histPCT)
      end

  fun genWalkFunsEnum (name, histPCT, whichSuf, others) = 
      let val whichFun : string = (whichSuf o histSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val whichBodyE = PT.Call(PT.Id(whichSuf intHist), [PT.Id pads, PT.Id hist]@otherXs)
	  val whichReturnS = PT.Return whichBodyE
	  val whichFunED = BU.gen3PFun(whichFun, histPCT::otherPCTs, hist::otherVars, [whichReturnS])
      in
	  whichFunED
      end

  (* This version is more efficient, but less uniform.  Optimize if performance becomes a problem. *)
  fun genAddFunEnum(name, histPCT, repPCT, pdPCT) =
      let val addFun = (addSuf o histSuf) name
	  val addX = PT.Call(PT.Id(addSuf intHist), 
				      [PT.Id pads, PT.Id hist, PT.Id pd, 
				       PT.Cast(P.ptrPCT PL.intPCT, PT.Id rep)])
	  val addReturnS = PT.Return addX
	  val addBodySs =  [addReturnS]
	  val addFunED = BU.genAddFun(addFun, hist, histPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  fun genAddFunEnum(name, histPCT,repPCT,pdPCT) = 
      genAddFunTypedef(name, PX.Name "Pint32", histPCT, repPCT,pdPCT, PT.Cast(P.ptrPCT PL.intPCT, PT.Id rep))

  fun genReportFunEnum(name, histPCT, reportSuf) =
      let val reportFun = (reportSuf o histSuf) name
	  val repioCallX = BU.callEnumPrint((ioSuf o reportSuf o mapSuf) intHist,
					    PT.Id prefix, PT.Id what, PT.Id nst,
					    PT.Id(toStringSuf name), PT.Id hist)
	  val reportBodySs = [PT.Expr repioCallX]
	  val reportFunEDs = BU.genReportFuns(reportFun, "enum "^name, histPCT, hist, reportBodySs)
      in
	  reportFunEDs
      end

  fun genEnum (name, repPCT, pdPCT) = 
      let val (histED, histPCT) = genRepEnum  name 
	  val initFunED = genWalkFunsEnum(name, histPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsEnum(name, histPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsEnum(name, histPCT, resetSuf,[])
	  val cleanupFunED = genWalkFunsEnum(name, histPCT, cleanupSuf,[])
	  val addFunED = genAddFunEnum(name, histPCT, repPCT, pdPCT)
	  val reportFullFunEDs = genReportFunEnum(name, histPCT,reportFullSuf)
	  val reportAllFunEDs = genReportFunEnum(name, histPCT,reportAllSuf)

      in
	  [histED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFullFunEDs @ reportAllFunEDs @[cleanupFunED]
      end


  fun genRepArray name baseTy = 
      let val baseFields = [(arrayLevel, P.makeTypedefPCT (lookupHist baseTy), SOME "Histogram for all array elements")]
	  val histFields = (arrayLen, uint32HistPCT, SOME "Histogram for array length")::baseFields
	  val histED = P.makeTyDefStructEDecl (histFields, histSuf name)
	  val histPCT = P.makeTypedefPCT (histSuf name)			
      in
	  (histED, histPCT)
      end

  fun genWalkFunsArray (name, baseTy, whichPCT, whichSuf,others) = 
      let val whichFun = (whichSuf o histSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  val elemFunName = whichSuf (lookupHist baseTy)
	  val lengthX = P.addrX(P.arrowX(PT.Id hist, PT.Id length))
	  val doLength = BU.chk3Pfun(whichSuf uint32Hist, lengthX::otherXs)
	  val arrayX = P.addrX(P.arrowX(PT.Id hist, PT.Id arrayLevel))
          val doArraySs = BU.chk3Pfun (elemFunName, arrayX::otherXs)
	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichReturnSs = [BU.genReturnChk (PT.Id nerr)]
	  val whichBodySs = whichDeclSs @ doLength @ doArraySs @ whichReturnSs
	  val whichFunED = BU.gen3PFun(whichFun, whichPCT::otherPCTs, hist::otherVars, whichBodySs)
      in
	  whichFunED
      end

  (* -- generate histogram add function *)
  fun genAddFunArray (name, baseTy, histPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o histSuf) name
	  val elemFunName = addSuf (lookupHist baseTy)
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), P.arrowX(PT.Id pd, PT.Id errCode))]
	  val doLength = chkAddFun(addSuf uint32Hist, P.getFieldX(hist, length), P.addrX(PT.Id tpd), P.getFieldX(rep, length))
	  fun getArrayFieldX (base, field) = P.addrX(P.subX(P.arrowX(PT.Id base, PT.Id field), PT.Id "i"))
	  val doArrayDetailSs = [PT.Compound
				    [P.varDeclS'(P.int, "i"),
				     PT.For(P.assignX(PT.Id "i", P.zero),
					    P.ltX(PT.Id "i", P.arrowX(PT.Id rep, PT.Id length)),
					    P.postIncX (PT.Id "i"),
					    PT.Compound (chkAddFun(elemFunName, 
								   P.getFieldX(hist, arrayLevel), 
								   getArrayFieldX(pd, arrayElts), 
								   getArrayFieldX(rep, arrayElts))))]]
	  val addBodySs = addDeclSs @ initTpdSs @ BU.ifNotPanicSkippedSs(doLength @ doArrayDetailSs)
	  val addFunED = genAddFun(addFun, hist, histPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  (* -- generate histogram report function array *)
  fun genReportFunArray (name, baseTy, histPCT, reportSuf) = 
      let val reportFun = (reportSuf o histSuf) name
	  val elemFunName = ioSuf(reportSuf (lookupHist baseTy))
	  val baseTyStr = case baseTy of PX.Name n => n
	  val lengthX = P.arrowX(PT.Id hist, PT.Id length)
	  val doLengthSs =  BU.chkPrintCall(ioSuf(reportSuf uint32Hist), [PT.Id outstr, PT.String "Array lengths", 
									     PT.String "array length", P.intX ~1, P.addrX(lengthX)])
	  val arrayX = P.arrowX(PT.Id hist, PT.Id arrayLevel)
          val doArraySs = BU.chkPrintCall (elemFunName, [PT.Id outstr, PT.String "allArrayElts", PT.String "all array elements", 
							 PT.Id nst, P.addrX (arrayX)])

	  val reportBodySs   = doLengthSs @ doArraySs 
	  val reportFunEDs   = BU.genReportFuns(reportFun, "array "^ name ^" of "^baseTyStr, histPCT, hist, reportBodySs)
      in
	  reportFunEDs
      end


  fun genArray(name, baseTy, repPCT, pdPCT) = 
      let val (histED, histPCT) = genRepArray name baseTy
	  val initFunED    = genWalkFunsArray (name, baseTy, histPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsArray (name, baseTy, histPCT, setParamSuf,[defPackage])
	  val resetFunED   = genWalkFunsArray (name, baseTy, histPCT, resetSuf,[])
	  val addFunED     = genAddFunArray   (name, baseTy, histPCT, repPCT, pdPCT)
	  val reportFullFunEDs = genReportFunArray(name, baseTy, histPCT, reportFullSuf)
	  val reportAllFunEDs = genReportFunArray(name, baseTy, histPCT, reportAllSuf)
	  val cleanupFunED = genWalkFunsArray (name, baseTy, histPCT, cleanupSuf,[])
      in
	  [histED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFullFunEDs @ reportAllFunEDs @ [ cleanupFunED]
      end

  (* PUNIONS *)
  fun genRepUnion ptyfuns name variants = 
      let fun genHistFull ({pty: PX.Pty, args: pcexp list, name: string, 
			    isVirtual: bool, isEndian: bool, 
			    isRecord, containsRecord, largeHeuristic: bool,
			    pred, comment: string option,...}: BU.pfieldty) = 
	  if not isVirtual then 
	      let val predStringOpt = Option.map BU.constraintToString pred
		  val fullCommentOpt = BU.stringOptMerge(comment, predStringOpt)
	      in
		  [(name, P.makeTypedefPCT (lookupHist pty), fullCommentOpt )]
	      end
	  else []
	  fun genHistBrief e = []
	  fun genHistMan ptyfuns m = BU.genMan ptyfuns (lookupHist, NONE, false, m)
	  val histFields = P.mungeFields genHistFull genHistBrief (genHistMan ptyfuns) variants
	  val auxHistFields = [(unionTag, intHistPCT, NONE)]

	  val histED = P.makeTyDefStructEDecl (auxHistFields @ histFields, histSuf name)
	  val histPCT = P.makeTypedefPCT (histSuf name)			 
      in
	  (histED, histPCT)
      end

  fun genWalkFunsUnion (ptyfuns, name, variants, thePCT, whichSuf,others) = 
      let val whichFun = (whichSuf o histSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  fun genWhichFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else BU.callFun(whichSuf (lookupHist pty), hist, name,otherXs)
          
	  fun genWhichBrief e = []
	  fun genWhichMan (ptyfuns, whichSuf) m = BU.genFunMan ptyfuns (lookupHist, whichSuf, hist, otherXs, m)

	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichFields = P.mungeFields genWhichFull genWhichBrief (genWhichMan (ptyfuns, whichSuf)) variants
	  val auxFields = BU.chk3Pfun(whichSuf intHist, (P.getFieldX(hist, unionTag))::otherXs)
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ auxFields @ whichFields @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT::otherPCTs, hist::otherVars, whichBodySs)
      in
	  whichFunED
      end

  fun genAddFunUnion (ptyfuns, name, variants, histPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o histSuf) name
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), 
				     P.condX(P.eqX(P.arrowX(PT.Id pd, PT.Id errCode),
						   PL.P_UNION_MATCH_FAILURE),
					     PL.P_UNION_MATCH_FAILURE, PL.P_NO_ERROR))]
	  val addTagSs = chkAddFun(addSuf intHist, P.getFieldX(hist, unionTag), P.addrX(PT.Id tpd), 
				   PT.Cast(P.ptrPCT PL.intPCT, P.getFieldX(rep, unionTag)))
	  fun fieldAddrX (base, name) = P.addrX(P.arrowX(PT.Id base, PT.Id name))
	  fun genCase (name, pty, initSs, pdX) = 
	      let val funName = addSuf (lookupHist pty)
		  val repX = P.getUnionBranchX(rep, name)
		  val caseSs = initSs @ chkAddFun(funName, fieldAddrX(hist, name), pdX, repX)
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
	  val addFunED = genAddFun(addFun, hist, histPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end

  fun genReportFunUnion (ptyfuns, name, variants, histPCT, fromOpt, reportSuf) = 
      let val reportFun = (reportSuf o histSuf) name
	  val header = if fromOpt then "opt" else "union"
	  val reportTags = [
			     BU.chkPrint(BU.callEnumPrint((ioSuf o reportSuf o mapSuf) intHist,
							 PT.String header, PT.String "tag", P.intX ~1,
							 PT.Id((toStringSuf o tgSuf) name), P.getFieldX(hist, unionTag))),
			    PL.sfprintf(PT.Id outstr, 
					PT.String "\n[Describing each tag arm of %s]\n", 
					[PT.Id prefix])]
	  fun reportUnionField (pty, fieldName) = 
	      BU.genPrintPiece(ioSuf(reportSuf (lookupHist pty)), fieldName, P.zero, P.getFieldX(hist,fieldName), [])
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
	  val reportFunEDs   = BU.genReportFuns(reportFun,  header^" unionTag "^name, histPCT, hist, reportBodySs)
      in
	  reportFunEDs
      end


  fun genUnion ptyfuns (name, variants, repPCT, pdPCT, fromOpt) = 
      let val (histED, histPCT) = genRepUnion ptyfuns name variants
	  val initFunED = genWalkFunsUnion (ptyfuns, name, variants, histPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsUnion (ptyfuns, name, variants, histPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsUnion (ptyfuns, name, variants, histPCT, resetSuf,[])
	  val addFunED = genAddFunUnion(ptyfuns, name, variants, histPCT, repPCT, pdPCT)
	  val reportFullFunEDs = genReportFunUnion(ptyfuns, name, variants, histPCT, fromOpt, reportFullSuf)
	  val reportAllFunEDs = genReportFunUnion(ptyfuns, name, variants, histPCT, fromOpt, reportAllSuf)
	  val cleanupFunED = genWalkFunsUnion (ptyfuns, name, variants, histPCT, cleanupSuf,[])
      in
	  [histED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFullFunEDs @ reportAllFunEDs @[cleanupFunED]
      end

  (* PSTRUCTS *)
  fun genRepStruct ptyfuns name fields = 
      let fun genHistFull ({pty: PX.Pty, args: pcexp list, name: string, 
			    isVirtual: bool, isEndian: bool, 
			    isRecord, containsRecord, largeHeuristic: bool,
			    pred, comment: string option,...}: BU.pfieldty) = 
	  if not isVirtual then 
	      let val predStringOpt = Option.map BU.constraintToString pred
		  val fullCommentOpt = BU.stringOptMerge(comment, predStringOpt)
	      in
		  [(name, P.makeTypedefPCT (lookupHist pty), fullCommentOpt )]
	      end
	  else []
	  fun genHistBrief e = []
	  fun genHistMan ptyfuns m = BU.genMan ptyfuns (lookupHist, NONE, false, m)
	  val histFields = P.mungeFields genHistFull genHistBrief (genHistMan ptyfuns) fields
	  val histED = P.makeTyDefStructEDecl (histFields, histSuf name)
	  val histPCT = P.makeTypedefPCT (histSuf name)			 
      in
	  (histED, histPCT)
      end

  fun genWalkFunsStruct (ptyfuns, name, fields, thePCT, whichSuf, others) = 
      let val whichFun = (whichSuf o histSuf) name
	  val (otherPCTs, otherXs, otherVars) = split3 others
	  fun genWhichFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else BU.callFun(whichSuf (lookupHist pty), hist, name,otherXs)
          
	  fun genWhichBrief e = []
	  fun genWhichMan (ptyfuns, whichSuf) m = BU.genFunMan ptyfuns (lookupHist, whichSuf, hist, otherXs, m)

	  val whichDeclSs = [P.varDeclS(PL.uint32PCT, nerr, P.zero)]
	  val whichFields = P.mungeFields genWhichFull genWhichBrief (genWhichMan (ptyfuns, whichSuf)) fields
	  val whichReturnS = BU.genReturnChk (PT.Id nerr)
	  val whichBodySs = whichDeclSs @ whichFields @ [whichReturnS]
	  val whichFunED = BU.gen3PFun(whichFun, thePCT :: otherPCTs, hist::otherVars, whichBodySs)
      in
	  whichFunED
      end


  fun genAddFunStruct (ptyfuns, name, fields, histPCT, repPCT, pdPCT) = 
      let val addFun = (addSuf o histSuf) name
	  val addDeclSs = [P.varDeclS'(PL.base_pdPCT, tpd)]
	  val initTpdSs = [P.assignS(P.dotX(PT.Id tpd, PT.Id errCode), PL.P_NO_ERROR)]

	  fun genAddFull ({pty: PX.Pty, name: string,isVirtual: bool, ...}:BU.pfieldty) = 
	      if isVirtual then []
	      else chkAddFun(addSuf (lookupHist pty), P.getFieldX(hist,name),  P.getFieldX(pd, name), P.getFieldX(rep,name))

	  fun genAddBrief e = []
	  fun genAddMan (ptyfuns as (isPadsTy, getPadsName)) ({tyname, name,isVirtual,...}:BU.pmanty) = 
	      if isVirtual then []
	      else case isPadsTy tyname 
                   of PTys.CTy => [] 
	     	    | _  => (let val pty = getPadsName tyname
			     in
				 chkAddFun(addSuf(lookupHist pty), P.getFieldX(hist,name), P.addrX(PT.Id tpd), P.getFieldX(rep, name))
			     end)

	  val addFields = P.mungeFields genAddFull genAddBrief (genAddMan ptyfuns) fields
	  val addBodySs = addDeclSs @ initTpdSs @ BU.ifNotPanicSkippedSs(addFields)
	  val addFunED = genAddFun(addFun, hist, histPCT, pdPCT, repPCT, addBodySs)
      in
	  addFunED
      end


  fun genReportFunStruct (ptyfuns, name, fields, histPCT, reportSuf) = 
      let val reportFun = (reportSuf o histSuf) name
	  val headerSs = [PL.sfprintf(PT.Id outstr, 
				      PT.String "\n[Describing each field of %s]\n", 
				      [PT.Id prefix])]
	  fun reportStructField (pty, fieldName) = 
	      BU.genPrintPiece(ioSuf(reportSuf (lookupHist pty)), fieldName, P.zero, P.getFieldX(hist,fieldName), [])
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
	  val reportFunEDs   = BU.genReportFuns(reportFun, "struct "^name, histPCT, hist, reportBodySs)
      in
	  reportFunEDs
      end

  fun genStruct ptyfuns (name, fields, repPCT, pdPCT) = 
      let val (histED, histPCT) = genRepStruct ptyfuns name fields
	  val initFunED = genWalkFunsStruct (ptyfuns, name, fields, histPCT, initSuf,[])
	  val setParamsFunED = genWalkFunsStruct (ptyfuns, name, fields, histPCT, setParamSuf,[defPackage])
	  val resetFunED = genWalkFunsStruct (ptyfuns, name, fields, histPCT, resetSuf,[])
	  val addFunED = genAddFunStruct(ptyfuns, name, fields, histPCT, repPCT, pdPCT)
	  val reportFullFunEDs = genReportFunStruct(ptyfuns, name, fields, histPCT, reportFullSuf)
	  val reportAllFunEDs = genReportFunStruct(ptyfuns, name, fields, histPCT, reportAllSuf)
	  val cleanupFunED = genWalkFunsStruct (ptyfuns, name, fields, histPCT, cleanupSuf,[])
      in
	  [histED, initFunED, setParamsFunED, resetFunED, addFunED] @ reportFullFunEDs @ reportAllFunEDs @ [cleanupFunED]
      end

end
