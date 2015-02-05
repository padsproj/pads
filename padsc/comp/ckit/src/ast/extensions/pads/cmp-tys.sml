structure PTys = 

struct
  type sTyInfo = {diskSize : TyProps.diskSize,
		  memChar  : TyProps.memChar,
		  endian   : bool,
                  isRecord : bool,
		  containsRecord : bool,
		  largeHeuristic : bool,
		  labels   : TyProps.labelInfo option list,
                  fieldInfo : TyProps.fieldInfoTy list} 

  type pTyInfo = {info     : TyProps.tyInfo,
                  typarams : (string * Ast.ctype) list,
                  fromNested : bool,
		  diskSize : TyProps.diskSize,
                  compoundDiskSize : TyProps.compoundSize,
		  memChar  : TyProps.memChar,
		  endian   : bool,
                  isRecord : bool,
		  containsRecord: bool,
	          largeHeuristic: bool,
		  isSource : bool,
		  numArgs  : int,
		  repName  : string,
		  repInit  : string option,
		  repRead  : string,
		  repClean : string option,
		  pdName   : string,
                  pdTid    : Tid.uid,
		  pdInit   : string option,
		  pdClean  : string option,
		  accName  : string,
		  accInit  : string,
		  accAdd   : string,
		  accReport: string,
		  accClean : string}

   datatype padsTy = BaseTy of PBaseTys.baseInfoTy | CompoundTy of pTyInfo | CTy


  fun getArrayInfo (tyInfo: pTyInfo) = 
     case #info tyInfo
     of TyProps.ArrayInfo ainfo => ainfo
     | _ => TyProps.defArrayInfo

  fun getUnionInfo (tyInfo: pTyInfo) = 
     case #info tyInfo
     of TyProps.UnionInfo ainfo => ainfo
     | _ => TyProps.defUnionInfo

  fun isOpt(tyInfo:pTyInfo) = 
      case #info tyInfo
      of TyProps.UnionInfo {fromOpt,...} => fromOpt
      | _ => false

  fun isSwitchedUnion(tyInfo:pTyInfo) = 
      case #info tyInfo
      of TyProps.UnionInfo {descriminator,...} => Option.isSome descriminator
      | _ => false

  fun getStructInfo (tyInfo: pTyInfo) = 
     case #info tyInfo
     of TyProps.StructInfo ainfo => ainfo
     | _ => TyProps.defStructInfo

  fun getEnumInfo (tyInfo: pTyInfo) = 
     case #info tyInfo
     of TyProps.EnumInfo ainfo => ainfo
     | _ => TyProps.defEnumInfo

  fun getTypedefInfo (tyInfo: pTyInfo) = 
     case #info tyInfo
     of TyProps.TypedefInfo ainfo => ainfo
     | _ => raise Fail "Expected a typedef in pretty printing"
  
  fun mergeTyInfo mergeDiskSizes (r1 : sTyInfo, r2:sTyInfo) =
      {diskSize = mergeDiskSizes (#diskSize r1, #diskSize r2),
       memChar  = TyProps.mergeMemChar(#memChar r1,   #memChar  r2),
       endian   = #endian r1 andalso #endian r2,
       isRecord = #isRecord r1 orelse #isRecord r2,
       containsRecord = #containsRecord r1 orelse #containsRecord r2,
       largeHeuristic = #largeHeuristic r1 orelse #largeHeuristic r2,
       labels = (#labels r1) @ (#labels r2),
       fieldInfo = (#fieldInfo r1) @ (#fieldInfo r2)}

  val minTyInfo : sTyInfo = 
                  {diskSize = TyProps.Size (IntInf.fromInt 0,IntInf.fromInt 0), 
                    memChar = TyProps.Static, 
                     endian = true, 
                   isRecord = false, 
             containsRecord = false,
             largeHeuristic = false, 
		     labels = [],
	          fieldInfo = []}

  type pTyMap = pTyInfo PBaseTys.PBST.map

  val pTys : pTyMap ref = ref PBaseTys.PBST.empty

  fun insert(name:Atom.atom, data:pTyInfo) = 
     pTys := PBaseTys.PBST.insert(!pTys, name, data)

  val find: Atom.atom -> pTyInfo option = fn a => PBaseTys.PBST.find(!pTys, a)

       
end