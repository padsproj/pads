structure PNames =
struct
              val pstate    = "pstate"
              val errCode   = "errCode"
              val loc       = "loc"
	      val pads      = "pads"
              val rep       = "rep"
              val io        = "io"
	      val buf       = "buf"
	      val bufLen    = "buf_len"
	      val bufFull   = "buf_full"
	      val delims    = "delims"
	      val requestedOut = "requestedOut"
	      val length    = "length"
	      val xmltag    = "_tag" 
	      val indent    = "indent"
	      val tpd       = "tpd"
	      val tm        = "tm"
	      val tloc      = "tloc"
	      val beginLoc  = "beginLoc"
	      val haveData   = "haveData"
	      val locPtr    = "loc_ptr"
	      val prefix    = "prefix"
	      val what      = "what"
	      val nst       = "nst"
	      val tmpstr    = "tmpstr"
	      val outstr    = "outstr"
	      val result    = "result"
	      val errorf    = "error_fn"
	      val self      = "self"
	      val paramsVar = "params"

  val unionVal    = "val"
  val unionTag    = "tag"
  val recVal      = "val"
  val arrayLen    = "length"
  val numRead     = "numRead"
  val arrayElts   = "elts"
  val pdElts      = "pds"
  val arrayCur    = "current"
  val curElt      = "elt"
  val curPd       = "pd"
  val consume     = "consume"
  val offset      = "offset"
  val nerr        = "nerr"
  val arrayBegin  = "begin"  (* tloc.b     : Ppos_t *)
  val arrayEnd    = "end"    (* tloc.e     : Ppos_t *)
  val elemBegin   = "eltBegin"    (* pd->loc.b  : Ppos_t *)
  val elemEnd     = "eltEnd"      (* pd->loc.e  : Ppos_t *)
  val structBegin = "begin"  (* tloc.b     : Ppos_t *)
  val structEnd   = "end"    (* tloc.e     : Ppos_t *)
  val unionBegin  = "begin"  (* tloc.b     : Ppos_t *)
  val unionEnd    = "end"    (* tloc.e     : Ppos_t *)
  val position    = "position"
  val identifier  = "_id_"
  val setEndID    = "_SET"
  val noopID      = "_NOOP"

  val structLevel = "compoundLevel"
  val unionLevel  = "compoundLevel"
  val arrayLevel  = "compoundLevel"
  val user        = "compoundLevel"  (* typedef case *)


  val elt_rep   = "elt_rep"
  val elt_pd    = "elt_pd"
  val info = "info"
  val m         = "m" 
  val pd        = "pd"
  val rep       = "rep"
  val smartNode = "smartNode"
  val m_out = "m_out"
  val pd_out = "pd_out"
  val rep_out = "rep_out"
  val max_elts = "max_elts"
  val base = "base"
  val params = "params"

  val acc       = "acc"
  val sfstderr  = "sfstderr"

  val recPre = CommonNames.recPre

  fun repSuf  s = s (* Make rep type same as pads name *)
  fun padsxSuf  s = s (* Make pads/x type same as pads name. will only differ at base types (potentially). *)
  fun mSuf   s = s^"_"^m
  fun mConSuf s = s^"_con"
  fun pdSuf   s = s^"_"^pd
  fun accSuf  s = s^"_"^acc
  val hist = "hist"
  fun histSuf  s = s^"_"^hist
  fun initSuf s = s^"_init"
  fun resetSuf s = s^"_reset"
  fun cleanupSuf s = s^"_cleanup"
  fun copySuf s = s^"_copy"
  fun srcSuf s = s^"_src"
  fun dstSuf s = s^"_dst"
  fun addSuf  s = s^"_add"
  fun readSuf s = s^"_read"
  fun arrayInfoSuf s = s^"_array_info_t"
  fun roParamsSuf s = s^"_ro_params_t"
  fun roParamsInitSuf s = s^"_ro_params_init"
  fun roDriverSuf s = s^"_ro_driver"
  fun roArgsSuf s = s^"_roArgs"
  fun roInitSuf s = s^"_read_one_init"
  fun readOneSuf s = s^"_read_one"
  fun rereadOneSuf s = s^"_reread_one"
  fun finalChecksSuf s = s^"_final_checks"
  fun scan1Suf s = s^"_scan1"
  fun scan2Suf s = s^"_scan2"
  fun maskInitSuf s = s^"_m_init"
  fun maskRecInitSuf s = s^"_m_rec_init"
  val maskRecInitErrorLabel = "cleanup"
  fun writeSuf s = s^"_write"
  fun writeXMLSuf s = s^"_write_xml_"
  fun fmtSuf s = s^"_fmt"
  fun ioSuf s = s^"2io"
  fun ioxmlSuf s = s^"2xml_io"
  fun bufSuf s = s^"2buf"
  fun bufFinalSuf s = s^"2buf_final"
  fun reportSuf s = s^"_report"
  fun mapSuf s = s^"_map"
  fun toStringSuf s = s^"2str"
  fun errSuf s = s^"_err"
  fun findEORSuf s = s^"_findpostlude"
  fun findEndSuf s = s^"_end"
  fun gTemp base = "tmp"^base
  fun tgSuf s = s^"_tag"
  fun unSuf s = s^"_u"


  fun childrenSuf name = name^"_children" 
  fun kthChildSuf name = name^"_kthChild" 
  fun kthChildNamedSuf name = name^"_kthChildNamed" 
  fun pathWalkSuf name = name^"_pathWalk" 
  fun vTableSuf name = name^"_vtable"
  fun cnInitSuf name = name^"_cachedNode_init"
  fun sndInitSuf name = name^"_sndNode_init"
  

  fun nodeSuf name = name^"_node"
  fun cnSuf name = name^"_cachedNode"  
  fun sndSuf name = name^"_sndNode"  
  fun snSuf name = name^"_smartNode"
  fun ssnSuf name = name^"_seqSmartNode"

  fun nodeNewSuf name = (nodeSuf name)^"_new" 
  fun nodeKCSuf name = kthChildSuf (nodeSuf name)
  fun nodeKCNSuf name = kthChildNamedSuf (nodeSuf name)
  fun nodePWSuf name = pathWalkSuf (nodeSuf name)  
  fun nodeVTableSuf name = vTableSuf (nodeSuf name)

  fun cnKCSuf name = kthChildSuf (cnSuf name)
  fun cnVTableSuf name = vTableSuf (cnSuf name)

  fun sndKCSuf name = kthChildSuf (sndSuf name)
  fun sndKCNSuf name = kthChildNamedSuf (sndSuf name)
  fun sndVTableSuf name = vTableSuf (sndSuf name)

  fun snEltAllocSuf name = (snSuf name) ^ "_eltAlloc"
  fun snEltReadSuf name = (snSuf name) ^ "_eltRead"
  fun snEltFreeSuf name = (snSuf name) ^ "_eltFree"
  fun snEltPathWalkSuf name = (snSuf name) ^ "_eltPathWalk"
  fun snKCSuf name = kthChildSuf (snSuf name)
  fun snKCNSuf name = kthChildNamedSuf (snSuf name)
  fun snInitSuf name = (snSuf name) ^ "_init"
  fun snVTableSuf name = vTableSuf (snSuf name)

  fun ssnInitSuf name = (ssnSuf name) ^ "_init"
  fun ssnVTableSuf name = vTableSuf (ssnSuf name)

  fun aiInitSuf s = s^"_array_info_init"

  fun isPref name = name^"_verify"
  fun genPD name = name^"_genPD"

end
