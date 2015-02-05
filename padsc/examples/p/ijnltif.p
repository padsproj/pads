
extern Puint64 num_recs;

Pstruct XX_HDR_SMS_TIME_47_ijnltifh {
	Pe_string_FW(:2:)                                  XX_HDR_SMS_HH_48;
	Pe_string_FW(:2:)                                  XX_HDR_SMS_MM_49;
	Pe_string_FW(:2:)                                  XX_HDR_SMS_SS_50;
};
Pstruct XX_HDR_SMS_DATE_44_ijnltifh {
	Pe_string_FW(:2:)                                  XX_HDR_SMS_YY_45;
	Pe_string_FW(:3:)                                  XX_HDR_SMS_DDD_46;
};
Pstruct XX_HDR_SMS_37_ijnltifh {
	Pe_string_FW(:5:)                                  XX_HDR_SMS_REC_TYPE_CD_38;
	Pe_string_FW(:2:)                                  XX_HDR_SMS_RPC_CD_39;
	Pe_string_FW(:2:)                                  XX_HDR_SMS_PE_CD_40;
	Pe_string_FW(:1:)                                  FILLER_41;
	Pe_string_FW(:8:)                                  XX_HDR_SMS_JOBNAME_42;
	Pe_string_FW(:6:)                                  XX_HDR_SMS_SEQ_NM_43;
	XX_HDR_SMS_DATE_44_ijnltifh                        XX_HDR_SMS_DATE_44;
	XX_HDR_SMS_TIME_47_ijnltifh                        XX_HDR_SMS_TIME_47;
	Pe_string_FW(:13:)                                 FILLER_51;
};
Pstruct XX_HDR_VTNS_PARTITION_33_ijnltifh {
	Pe_string_FW(:1:)                                  XX_HDR_VTNS_PRTN_34;
	Pe_string_FW(:1:)                                  FILLER_35;
};
Pstruct XX_HDR_COM_YEAR_25_ijnltifh {
	Pebc_uint64(:2:)                                   XX_HDR_COM_CC_26;
	Pebc_uint64(:2:)                                   XX_HDR_COM_YR_27;
};
Pstruct XX_HDR_COM_DLM_DT_20_ijnltifh {
	Pebc_uint64(:2:)                                   XX_HDR_COM_MO_21;
	Pe_string_FW(:1:)                                  XX_HDR_COM_DLM_1_22;
	Pebc_uint64(:2:)                                   XX_HDR_COM_DY_23;
	Pe_string_FW(:1:)                                  XX_HDR_COM_DLM_2_24;
	XX_HDR_COM_YEAR_25_ijnltifh                        XX_HDR_COM_YEAR_25;
};
Pstruct XX_HDR_DLM_TM_13_ijnltifh {
	Pebc_uint64(:2:)                                   XX_HDR_HR_14;
	Pe_string_FW(:1:)                                  XX_TM_DLM_1_15;
	Pebc_uint64(:2:)                                   XX_HDR_MI_16;
	Pe_string_FW(:1:)                                  XX_TM_DLM_2_17;
	Pebc_uint64(:2:)                                   XX_HDR_SC_18;
};
Pstruct XX_HDR_DLM_DT_6_ijnltifh {
	Pebc_uint64(:2:)                                   XX_HDR_MO_7;
	Pe_string_FW(:1:)                                  XX_DT_DLM_1_8;
	Pebc_uint64(:2:)                                   XX_HDR_DY_9;
	Pe_string_FW(:1:)                                  XX_DT_DLM_2_10;
	Pebc_uint64(:4:)                                   XX_HDR_YR_11;
};
Palternates gen_alternates_1_ijnltifh_t {
	XX_HDR_DLM_DT_6_ijnltifh                           XX_HDR_DLM_DT_6;
	Pe_string_FW(:10:)                                 XX_HDR_DT_12;
};
Palternates gen_alternates_2_ijnltifh_t {
	XX_HDR_DLM_TM_13_ijnltifh                          XX_HDR_DLM_TM_13;
	Pe_string_FW(:8:)                                  XX_HDR_TM_19;
};
Palternates gen_alternates_3_ijnltifh_t {
	XX_HDR_COM_DLM_DT_20_ijnltifh                      XX_HDR_COM_DLM_DT_20;
	Pe_string_FW(:10:)                                 XX_HDR_COM_DT_28;
};
Palternates gen_alternates_4_ijnltifh_t {
	Pe_string_FW(:2:)                                  XX_HDR_PRCSS_ENTY_CD_32;
	XX_HDR_VTNS_PARTITION_33_ijnltifh                  XX_HDR_VTNS_PARTITION_33;
	Pe_string_FW(:2:)                                  XX_HDR_UB_BL_CYC_NB_36;
};
Pstruct XX_HDR_RC_1_ijnltifh {
	Pe_string_FW(:1:)                                  XX_HDR_REC_TYPE_CD_2;
	Pe_string_FW(:2:)                                  XX_HDR_CPY_CD_3;
	Pe_string_FW(:1:)                                  XX_HDR_FL_TYPE_CD_4;
	Pe_string_FW(:4:)                                  XX_HDR_SRCE_SYS_CD_5;
	gen_alternates_1_ijnltifh_t                        GEN_ALTERNATES_1_ijnltifh;
	gen_alternates_2_ijnltifh_t                        GEN_ALTERNATES_2_ijnltifh;
	gen_alternates_3_ijnltifh_t                        GEN_ALTERNATES_3_ijnltifh;
	Pe_string_FW(:1:)                                  XX_HDR_ACRL_CD_29;
	Pe_string_FW(:2:)                                  XX_HDR_BL_CYC_CD_30;
	Pe_string_FW(:1:)                                  XX_HDR_COMPLX_CD_31;
	gen_alternates_4_ijnltifh_t                        GEN_ALTERNATES_4_ijnltifh;
	XX_HDR_SMS_37_ijnltifh                             XX_HDR_SMS_37;
	Pe_string_FW(:12:)                                 FILLER_52;
};
Precord Pstruct cpy_ijnltifh {
	XX_HDR_RC_1_ijnltifh                               XX_HDR_RC_1;
};
Palternates gen_alternates_18_ijnltif_t {
	Pebc_fpoint64(:5,5:)                               XX_TB_TAX_RT_280;
	Pebc_fpoint64(:5,4:)                               XX_TB_TAX_RT4_281;
	Pebc_fpoint64(:5,3:)                               XX_TB_TAX_RT3_282;
};
Pstruct XX_TAX_TB_276_ijnltif {
	Pe_string_FW(:1:)                                  XX_TB_TAX_CLS_CD_277;
	Pe_string_FW(:5:)                                  XX_TB_TAX_CLSFCTN_CD_278;
	Pe_string_FW(:2:)                                  XX_TB_TAX_JURIS_CD_279;
	gen_alternates_18_ijnltif_t                        GEN_ALTERNATES_18_ijnltif;
	Pe_string_FW(:4:)                                  XX_TB_TAX_RSN_CD_283;
	Pbcd_fpoint64(:16,7:)                              XX_TB_TAX_AT_284;
	Pbcd_fpoint64(:13,4:)                              XX_TB_MAXTAX_AT_285;
	Pe_string_FW(:1:)                                  XX_TB_TAX_RT_TYPE_286;
	Pbcd_fpoint64(:13,4:)                              XX_TB_TAXABLE_AT_287;
	Pbcd_fpoint64(:13,4:)                              XX_TB_NTAXABLE_AT_288;
	Pbcd_fpoint64(:13,4:)                              XX_TB_SRCHG_AO_AT_289;
	Pe_string_FW(:1:)                                  XX_TB_MAXTAX_ND_290;
	Pbcd_fpoint64(:13,4:)                              XX_TB_GRS_TAX_AT_291;
	Pbcd_fpoint64(:5,5:)                               XX_TB_RTRANS_DIST_RT_292;
	Pbcd_fpoint64(:13,4:)                              XX_TB_RTRANS_DIST_TAX_293;
};
Parray gen_parray_of_XX_TAX_TB_276_ijnltif (:int len:){
	XX_TAX_TB_276_ijnltif [len];
};
Pstruct XX_TAX_SURCHG_INFO_274_ijnltif {
	Psbh_int64(:2:)                                    XX_CTM_ND_275;
	gen_parray_of_XX_TAX_TB_276_ijnltif(:XX_CTM_ND_275:) XX_TAX_TB_276;
};
Pstruct XX_EXTRN_INFO_2_267_ijnltif {
	Pe_string_FW(:3:)                                  XX_RMC_BKT_NB_268;
	Pe_string_FW(:4:)                                  XX_MCC_CAPTN_CD_269;
	Pe_string_FW(:51:)                                 XX_MCC_PHRS_1_270;
	Pe_string_FW(:51:)                                 XX_MCC_PHRS_2_271;
	Pe_string_FW(:3:)                                  XX_NREV_TAX_ND_272;
	Pe_string_FW(:213:)                                FILLER_273;
};
Pstruct XX_EXTRN_MCC_INFO_2_266_ijnltif {
	XX_EXTRN_INFO_2_267_ijnltif                        XX_EXTRN_INFO_2_267;
};
Pstruct XX_CUST_SEG_CD_259_ijnltif {
	Pe_string_FW(:7:)                                  XX_CUST_SEG_ID_260;
	Pe_string_FW(:3:)                                  XX_CUST_REV_BAND_261;
};
Pstruct XX_JRNL_TM_216_ijnltif {
	Pebc_uint64(:2:)                                   XX_JRNL_TM_HR_217;
	Pe_string_FW(:1:)                                  XX_JRNL_TM_1_218;
	Pebc_uint64(:2:)                                   XX_JRNL_TM_MN_219;
	Pe_string_FW(:1:)                                  XX_JRNL_TM_2_220;
	Pebc_uint64(:2:)                                   XX_JRNL_TM_SC_221;
};
Pstruct XX_JRNL_DT_208_ijnltif {
	Pebc_uint64(:2:)                                   XX_JRNL_DT_CENTRY_209;
	Pebc_uint64(:2:)                                   XX_JRNL_DT_YR_210;
	Pe_string_FW(:1:)                                  XX_JRNL_DT_1_211;
	Pebc_uint64(:2:)                                   XX_JRNL_DT_MO_212;
	Pe_string_FW(:1:)                                  XX_JRNL_DT_2_213;
	Pebc_uint64(:2:)                                   XX_JRNL_DT_DY_214;
};
Pstruct XX_IET_194_ijnltif {
	Pe_string_FW(:4:)                                  XX_IET_MNG_ENTY_CD_195;
	Pe_string_FW(:3:)                                  XX_IET_LGL_ENTY_CD_196;
	Pe_string_FW(:3:)                                  XX_IET_ACCT_ENTY_CD_197;
};
Pstruct XX_SOBP_190_ijnltif {
	Pe_string_FW(:4:)                                  XX_SOBP_MNG_ENTY_CD_191;
	Pe_string_FW(:3:)                                  XX_SOBP_LGL_ENTY_CD_192;
	Pe_string_FW(:3:)                                  XX_SOBP_ACCT_ENTY_CD_193;
};
Pstruct XX_TRNSCTN_EDIT_TM_180_ijnltif {
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_TM_HR_181;
	Pe_string_FW(:1:)                                  XX_TRNSCTN_EDIT_TM_1_182;
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_TM_MN_183;
	Pe_string_FW(:1:)                                  XX_TRNSCTN_EDIT_TM_2_184;
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_TM_SC_185;
};
Pstruct XX_TRNSCTN_EDIT_DT_172_ijnltif {
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_DT_CENTRY_173;
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_DT_YR_174;
	Pe_string_FW(:1:)                                  XX_TRNSCTN_EDIT_DT_1_175;
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_DT_MO_176;
	Pe_string_FW(:1:)                                  XX_TRNSCTN_EDIT_DT_2_177;
	Pebc_uint64(:2:)                                   XX_TRNSCTN_EDIT_DT_DY_178;
};
Palternates gen_alternates_12_ijnltif_t {
	XX_TRNSCTN_EDIT_DT_172_ijnltif                     XX_TRNSCTN_EDIT_DT_172;
	Pe_string_FW(:10:)                                 XX_TRNSCTN_EDIT_DT_A_179;
};
Palternates gen_alternates_13_ijnltif_t {
	XX_TRNSCTN_EDIT_TM_180_ijnltif                     XX_TRNSCTN_EDIT_TM_180;
	Pe_string_FW(:8:)                                  XX_TRNSCTN_EDIT_TM_A_186;
};
Palternates gen_alternates_14_ijnltif_t {
	XX_JRNL_DT_208_ijnltif                             XX_JRNL_DT_208;
	Pe_string_FW(:10:)                                 XX_JRNL_DT_A_215;
};
Palternates gen_alternates_15_ijnltif_t {
	XX_JRNL_TM_216_ijnltif                             XX_JRNL_TM_216;
	Pe_string_FW(:8:)                                  XX_JRNL_TM_A_222;
};
Palternates gen_alternates_16_ijnltif_t {
	Pe_string_FW(:10:)                                 XX_CUST_SEG_GRP_258;
	XX_CUST_SEG_CD_259_ijnltif                         XX_CUST_SEG_CD_259;
};
Pstruct XX_INTRN_INFO_168_ijnltif {
	Pe_string_FW(:10:)                                 XX_FACCT_CD_169;
	Pe_string_FW(:10:)                                 XX_PROD_SVC_CD_170;
	Pe_string_FW(:5:)                                  XX_CSUB_ACCT_CD_171;
	gen_alternates_12_ijnltif_t                        GEN_ALTERNATES_12_ijnltif;
	gen_alternates_13_ijnltif_t                        GEN_ALTERNATES_13_ijnltif;
	Psbh_int64(:4:)                                    XX_TRNSCTN_GP_NB_187;
	Psbh_int64(:4:)                                    XX_TRNSCTN_DERVD_NB_188;
	Psbh_int64(:4:)                                    XX_TRNSCTN_OFFST_NB_189;
	XX_SOBP_190_ijnltif                                XX_SOBP_190;
	XX_IET_194_ijnltif                                 XX_IET_194;
	Pe_string_FW(:9:)                                  XX_ORG_ORGNTG_CD_198;
	Pe_string_FW(:9:)                                  XX_ORG_CHRG_CD_199;
	Pe_string_FW(:2:)                                  XX_ST_CD_200;
	Pe_string_FW(:2:)                                  XX_JRNL_ST_CD_201;
	Pe_string_FW(:1:)                                  XX_ALLOC_ND_202;
	Pe_string_FW(:5:)                                  XX_TAX_CLSFCTN_CD_203;
	Pe_string_FW(:1:)                                  XX_TAX_CLS_CD_204;
	Pe_string_FW(:1:)                                  XX_LDS_ACSS_MTHD_CD_205;
	Pe_string_FW(:1:)                                  XX_FILE_TYPE_CD_206;
	Pe_string_FW(:4:)                                  XX_SRCE_SYS_ID_207;
	gen_alternates_14_ijnltif_t                        GEN_ALTERNATES_14_ijnltif;
	gen_alternates_15_ijnltif_t                        GEN_ALTERNATES_15_ijnltif;
	Pe_string_FW(:1:)                                  XX_ACRL_CD_223;
	Pe_string_FW(:3:)                                  XX_PRCSS_TYPE_CD_224;
	Pe_string_FW(:1:)                                  XX_BVSJ_RVNU_CAT_CD_225;
	Pe_string_FW(:1:)                                  XX_DERVD_DFLT_CD_226;
	Pe_string_FW(:6:)                                  XX_LOC_CD_227;
	Pe_string_FW(:11:)                                 XX_DERVD_SEQ_NB_228;
	Pe_string_FW(:1:)                                  XX_OFFSET_DRVR_ND_229;
	Pe_string_FW(:1:)                                  XX_FCE_ERR_CD_230;
	Pe_string_FW(:3:)                                  XX_DERVD_TB_ID_231;
	Pe_string_FW(:4:)                                  XX_LD_NRC_CD_232;
	Pe_string_FW(:1:)                                  XX_TAX_ONLY_ND_233;
	Pe_string_FW(:1:)                                  XX_CAP_OWN_CD_234;
	Pe_string_FW(:1:)                                  XX_CMPLX_ID_235;
	Pe_string_FW(:2:)                                  XX_PRCSS_ENTY_CPY_ID_236;
	Pe_string_FW(:2:)                                  XX_TAX_JURIS_CD_237;
	Pebc_fpoint64(:5,5:)                               XX_TAX_RT_238;
	Pe_string_FW(:4:)                                  XX_TAX_RSN_CD_239;
	Pe_string_FW(:4:)                                  XX_ALT_MSG_ID_240;
	Pe_string_FW(:20:)                                 XX_CIA_FML_DESC_241;
	Pe_string_FW(:20:)                                 XX_CIA_FML_DESC_SUB_242;
	Pbcd_fpoint64(:13,4:)                              XX_MAXTAX_AT_243;
	Pbcd_fpoint64(:13,4:)                              XX_TAX_NTAX_AT_244;
	Pe_string_FW(:1:)                                  XX_ACCS_LN_TRNK_TYPE_245;
	Pe_string_FW(:1:)                                  XX_TAX_RT_TYPE_246;
	Pbcd_fpoint64(:13,4:)                              XX_SURCHG_AO_AT_247;
	Pe_string_FW(:1:)                                  XX_MAXTAX_ND_248;
	Pbcd_fpoint64(:13,4:)                              XX_GRS_TAX_AT_249;
	Pbcd_fpoint64(:5,5:)                               XX_RTRANS_DIST_RT_250;
	Pbcd_fpoint64(:13,4:)                              XX_RTRANS_DIST_TAX_251;
	Pe_string_FW(:1:)                                  XX_CUST_CODE_REQD_252;
	Pe_string_FW(:1:)                                  XX_DR_CR_ND_253;
	Pe_string_FW(:1:)                                  XX_VTNS_PARTITION_NUM_254;
	Pe_string_FW(:2:)                                  XX_TAX_CAT_CD_FILL_255;
	Pe_string_FW(:2:)                                  XX_RVNU_XFER_CD_FILL_256;
	Pe_string_FW(:1:)                                  XX_UNREGU_SVC_ND_257;
	gen_alternates_16_ijnltif_t                        GEN_ALTERNATES_16_ijnltif;
	Pe_string_FW(:6:)                                  XX_RVPP_CD_262;
	Pe_string_FW(:1:)                                  XX_CHANNEL_ID_263;
	Pe_string_FW(:1:)                                  XX_JRNL_ENTRY_IET_TRANS_264;
	Pe_string_FW(:38:)                                 FILLER_265;
};
Pstruct XX_RVNU_XFER_FROM_TO_CD_156_ijnltif {
	Pe_string_FW(:1:)                                  XX_RVNU_XFER_FROM_CD_157;
	Pe_string_FW(:1:)                                  XX_RVNU_XFER_TO_CD_158;
};
Pstruct XX_BL_DT_REF_133_ijnltif {
	Pe_string_FW(:2:)                                  XX_BL_CC_134;
	Pe_string_FW(:2:)                                  XX_BL_YY_135;
	Pe_string_FW(:2:)                                  XX_BL_MM_136;
	Pe_string_FW(:2:)                                  XX_BL_DD_137;
};
Pstruct XX_BL_DT_BL_PRD_132_ijnltif {
	XX_BL_DT_REF_133_ijnltif                           XX_BL_DT_REF_133;
	Pe_string_FW(:12:)                                 FILLER_138;
};
Pstruct XX_BR_OFFC_CODE_REF_128_ijnltif {
	Pe_string_FW(:8:)                                  XX_BR_OFFC_CD_129;
	Pe_string_FW(:3:)                                  FILLER_130;
};
Palternates gen_alternates_8_ijnltif_t {
	Pe_string_FW(:10:)                                 XX_ORGN_SRCE_COM_DLM_DT_109;
	Pe_string_FW(:10:)                                 XX_BUNDLE_NAME_110;
};
Palternates gen_alternates_9_ijnltif_t {
	Pe_string_FW(:11:)                                 XX_CUST_SRVC_CTR_CD_127;
	XX_BR_OFFC_CODE_REF_128_ijnltif                    XX_BR_OFFC_CODE_REF_128;
};
Palternates gen_alternates_10_ijnltif_t {
	Pe_string_FW(:20:)                                 XX_INV_NB_131;
	XX_BL_DT_BL_PRD_132_ijnltif                        XX_BL_DT_BL_PRD_132;
};
Palternates gen_alternates_11_ijnltif_t {
	Pe_string_FW(:2:)                                  XX_RVNU_XFER_CD_155;
	XX_RVNU_XFER_FROM_TO_CD_156_ijnltif                XX_RVNU_XFER_FROM_TO_CD_156;
};
Pstruct XX_SUMM_KEY5_105_ijnltif {
	Pe_string_FW(:1:)                                  XX_ORGN_SRCE_COMPLX_CD_106;
	Pe_string_FW(:2:)                                  XX_ORGN_SRCE_PRCSS_ENTY_CD_107;
	Pe_string_FW(:2:)                                  XX_ORGN_SRCE_BL_CYC_CD_108;
	gen_alternates_8_ijnltif_t                         GEN_ALTERNATES_8_ijnltif;
	Pe_string_FW(:2:)                                  XX_SRCE_DEST_CD_111;
	Pe_string_FW(:5:)                                  XX_SVC_PRVD_ID_112;
	Pe_string_FW(:8:)                                  XX_WRLS_CYC_END_DT_113;
	Pe_string_FW(:5:)                                  XX_BLR_TAX_ID_114;
	Pe_string_FW(:2:)                                  XX_TYPE_OF_CHG_115;
	Pe_string_FW(:2:)                                  XX_SRVC_STATE_116;
	Pe_string_FW(:4:)                                  XX_TRANS_TYPE_117;
	Pe_string_FW(:4:)                                  XX_SALE_TYPE_118;
	Pe_string_FW(:1:)                                  XX_OCL_ND_119;
	Pe_string_FW(:1:)                                  XX_PRIM_SUPPL_ND_120;
	Pe_string_FW(:8:)                                  XX_CHG_EFF_DT_121;
	Pe_string_FW(:8:)                                  XX_LEASE_EFF_DT_122;
	Pe_string_FW(:4:)                                  XX_TERMS_CD_123;
	Pe_string_FW(:4:)                                  XX_PRICE_ELEM_GP_124;
	Pe_string_FW(:1:)                                  XX_CHG_FREQ_125;
	Pe_string_FW(:2:)                                  XX_TAX_CALC_ND_126;
	gen_alternates_9_ijnltif_t                         GEN_ALTERNATES_9_ijnltif;
	gen_alternates_10_ijnltif_t                        GEN_ALTERNATES_10_ijnltif;
	Pe_string_FW(:10:)                                 XX_LINE_NB_139;
	Pe_string_FW(:3:)                                  XX_TYPE_OF_SVC_140;
	Pe_string_FW(:1:)                                  XX_III_ND_141;
	Pe_string_FW(:24:)                                 XX_CKT_NUM_142;
	Pe_string_FW(:3:)                                  XX_BL_GRP_143;
	Pe_string_FW(:8:)                                  XX_PROD_BLNG_ID_144;
	Pe_string_FW(:8:)                                  XX_CALL_OCCUR_DT_145;
	Pe_string_FW(:1:)                                  XX_FILLER_146;
	Pe_string_FW(:1:)                                  XX_APPRTNMT_ND_147;
	Pe_string_FW(:2:)                                  XX_DR_CR_CD_148;
	Pe_string_FW(:1:)                                  XX_HYBRID_TAX_ND_149;
	Pe_string_FW(:1:)                                  XX_TARIFF_12_ND_150;
	Pe_string_FW(:1:)                                  XX_JURIS_SRCE_ND_151;
	Pe_string_FW(:1:)                                  XX_SVC_GP_SRCE_ND_152;
	Pe_string_FW(:1:)                                  XX_GEO_SRCE_ND_153;
	Pe_string_FW(:2:)                                  XX_TAX_CAT_CD_154;
	gen_alternates_11_ijnltif_t                        GEN_ALTERNATES_11_ijnltif;
	Pe_string_FW(:1:)                                  XX_FILLER_159;
	Pbcd_fpoint64(:9,2:)                               XX_VOLUME_QTY_160;
	Pe_string_FW(:8:)                                  XX_PRICING_PLAN_161;
	Pe_string_FW(:2:)                                  XX_PLATFORM_ID_162;
	Pe_string_FW(:4:)                                  XX_TYPE_OF_VOLUME_163;
	Pe_string_FW(:1:)                                  XX_BUNDLED_FEAT_ND_164;
	Pe_string_FW(:3:)                                  XX_JRNL_ADJMT_CD_165;
	Pe_string_FW(:10:)                                 XX_BTN_LEC_REF_NB_166;
	Pe_string_FW(:92:)                                 XX_FILLER_167;
};
Pstruct XX_EXTRACT_TYPE_RED_100_ijnltif {
	Pe_string_FW(:1:)                                  XX_FILLER_101;
	Pe_string_FW(:1:)                                  XX_MEMO_JRN_CD_102;
	Pe_string_FW(:1:)                                  XX_FILLER_103;
};
Palternates gen_alternates_7_ijnltif_t {
	Pe_string_FW(:3:)                                  XX_EXTRACT_TYPE_99;
	XX_EXTRACT_TYPE_RED_100_ijnltif                    XX_EXTRACT_TYPE_RED_100;
};
Pstruct XX_EX_TYP_DIS_PL_98_ijnltif {
	gen_alternates_7_ijnltif_t                         GEN_ALTERNATES_7_ijnltif;
	Pe_string_FW(:1:)                                  XX_DISCOUNT_PLAN_104;
};
Pstruct XX_TAX_REASONS_88_ijnltif {
	Pe_string_FW(:1:)                                  XX_TAX_RSN_FEDERAL_89;
	Pe_string_FW(:1:)                                  XX_TAX_RSN_STATE_90;
	Pe_string_FW(:1:)                                  XX_TAX_RSN_COUNTY_91;
	Pe_string_FW(:1:)                                  XX_TAX_RSN_CITY_92;
	Pe_string_FW(:1:)                                  XX_TAX_RSN_SUBCITY_93;
};
Pstruct XX_BL_DT_64_ijnltif {
	Pe_string_FW(:2:)                                  XX_BL_CENTRY_65;
	Pe_string_FW(:2:)                                  XX_BL_YR_66;
	Pe_string_FW(:2:)                                  XX_BL_MO_67;
};
Palternates gen_alternates_5_ijnltif_t {
	Pe_string_FW(:2:)                                  XX_ACCT_TYPE_CD_53;
	Pe_string_FW(:2:)                                  XX_EXEMPT_RSN_CD_54;
};
Palternates gen_alternates_6_ijnltif_t {
	Pe_string_FW(:5:)                                  XX_TAX_EXMPT_CD_87;
	XX_TAX_REASONS_88_ijnltif                          XX_TAX_REASONS_88;
};
Pstruct XX_SUMM_KEY4_48_ijnltif {
	Pe_string_FW(:1:)                                  XX_CASH_TRNSCTN_TO_CD_49;
	Pe_string_FW(:1:)                                  XX_JRNL_ADJMT_TO_CD_50;
	Pe_string_FW(:1:)                                  XX_ACCT_STAT_TO_CD_51;
	Pe_string_FW(:4:)                                  XX_STUDY_CD_52;
	gen_alternates_5_ijnltif_t                         GEN_ALTERNATES_5_ijnltif;
	Pe_string_FW(:1:)                                  XX_HOME_ST_TAX_ND_55;
	Pe_string_FW(:1:)                                  XX_MSG_RT_CLS_CD_56;
	Pe_string_FW(:1:)                                  XX_MSG_TYPE_CD_57;
	Pe_string_FW(:2:)                                  XX_MSG_SVC_TYPE_CD_58;
	Pe_string_FW(:2:)                                  XX_BL_CAT_CD_59;
	Pe_string_FW(:3:)                                  XX_CAP_ID_60;
	Pe_string_FW(:1:)                                  XX_TAX_NON_CMPLNC_ND_61;
	Pe_string_FW(:6:)                                  XX_CUST_DEF_GP_CD_62;
	Pe_string_FW(:1:)                                  XX_TIF_JIF_ND_63;
	XX_BL_DT_64_ijnltif                                XX_BL_DT_64;
	Pe_string_FW(:2:)                                  XX_SBS_BLNG_PRD_CD_68;
	Pe_string_FW(:1:)                                  XX_SPLT_BL_PULL_ND_69;
	Pe_string_FW(:8:)                                  XX_OFFR_CMPNT_ID_70;
	Pe_string_FW(:8:)                                  XX_ACCT_CMPNT_ID_71;
	Pe_string_FW(:8:)                                  XX_CMPNT_ID_72;
	Pe_string_FW(:8:)                                  XX_CMPNT_SECNDRY_ID_73;
	Pe_string_FW(:8:)                                  XX_JRNL_CD_74;
	Pe_string_FW(:4:)                                  XX_JRNL_MSG_ID_75;
	Pe_string_FW(:1:)                                  XX_USG_CR_CARD_ND_76;
	Pe_string_FW(:1:)                                  XX_BUS_RESDNT_ND_77;
	Pe_string_FW(:1:)                                  XX_ACSS_MTHD_CD_78;
	Pe_string_FW(:1:)                                  XX_ADV_AREAR_ND_79;
	Pe_string_FW(:1:)                                  XX_RVNU_TYPE_CD_80;
	Pe_string_FW(:1:)                                  XX_HOLD_BL_ND_81;
	Pe_string_FW(:3:)                                  XX_CNTRY_CD_82;
	Pe_string_FW(:11:)                                 XX_SLS_LOC_CD_83;
	Pe_string_FW(:13:)                                 XX_GEO_SHIP_TO_CD_84;
	Pe_string_FW(:13:)                                 XX_GEO_SHIP_FROM_CD_85;
	Pe_string_FW(:1:)                                  XX_TAX_SVC_GP_CD_86;
	gen_alternates_6_ijnltif_t                         GEN_ALTERNATES_6_ijnltif;
	Pe_string_FW(:1:)                                  XX_JRNL_JURIS_CD_94;
	Pe_string_FW(:1:)                                  XX_MPS_JURIS_CD_95;
	Pe_string_FW(:3:)                                  XX_SBS_CIA_SRCE_ND_96;
};
Pstruct XX_SUMM_KEY3_44_ijnltif {
	Pe_string_FW(:1:)                                  XX_RCRG_NRCRG_ND_45;
	Pe_string_FW(:10:)                                 XX_PROD_ELEM_CD_46;
};
Palternates gen_alternates_4_ijnltif_t {
	Pe_string_FW(:2:)                                  XX_TRNSCTN_CD_38;
	Pe_string_FW(:2:)                                  XX_VTNS_ADJMT_RSN_CD_39;
};
Pstruct XX_SUMM_KEY2_32_ijnltif {
	Pe_string_FW(:1:)                                  XX_ACCT_STAT_CD_33;
	Pe_string_FW(:1:)                                  XX_JRNL_CHRG_CAT_CD_34;
	Pe_string_FW(:1:)                                  XX_ADJMT_SRCE_CD_35;
	Pe_string_FW(:1:)                                  XX_JRNL_ADJMT_CAT_CD_36;
	Pe_string_FW(:1:)                                  XX_CASH_TRNSCTN_CD_37;
	gen_alternates_4_ijnltif_t                         GEN_ALTERNATES_4_ijnltif;
	Pe_string_FW(:1:)                                  XX_ACCT_QLTY_CNTL_ND_40;
};
Pstruct XX_EDIT_GRP2_31_ijnltif {
	XX_SUMM_KEY2_32_ijnltif                            XX_SUMM_KEY2_32;
	Pbcd_int64(:11:)                                   XX_MSG_CT_41;
	Pbcd_int64(:11:)                                   XX_MSG_MN_CT_42;
	Pbcd_int64(:11:)                                   XX_MSG_SC_CT_43;
	XX_SUMM_KEY3_44_ijnltif                            XX_SUMM_KEY3_44;
	Pbcd_fpoint64(:11,2:)                              XX_JRNL_TAXBL_AT_47;
	XX_SUMM_KEY4_48_ijnltif                            XX_SUMM_KEY4_48;
	Pbcd_int64(:7:)                                    XX_LOCAL_ACSS_LINE_CT_97;
	XX_EX_TYP_DIS_PL_98_ijnltif                        XX_EX_TYP_DIS_PL_98;
	XX_SUMM_KEY5_105_ijnltif                           XX_SUMM_KEY5_105;
};
Pstruct XX_VTNS_ACCT_ID_25_ijnltif {
	Pe_string_FW(:2:)                                  XX_VTNS_SALES_OFF_CD_26;
	Pe_string_FW(:6:)                                  XX_VTNS_MCN_27;
	Pe_string_FW(:3:)                                  XX_VTNS_MCN_SFX_28;
	Pe_string_FW(:2:)                                  XX_FILLER_29;
};
Pstruct XX_VTNS_MSTR_ACCT_NB_21_ijnltif {
	Pe_string_FW(:11:)                                 XX_VTNS_MBU_22;
	Pe_string_FW(:2:)                                  XX_FILLER_23;
};
Pstruct XX_VTNS_ACCT_NB_16_ijnltif {
	Pe_string_FW(:11:)                                 XX_VTNS_SBU_17;
	Pe_string_FW(:2:)                                  XX_FILLER_18;
};
Palternates gen_alternates_1_ijnltif_t {
	Pe_string_FW(:13:)                                 XX_ACCT_NB_15;
	XX_VTNS_ACCT_NB_16_ijnltif                         XX_VTNS_ACCT_NB_16;
};
Palternates gen_alternates_2_ijnltif_t {
	Pe_string_FW(:13:)                                 XX_LEAD_ACCT_NB_20;
	XX_VTNS_MSTR_ACCT_NB_21_ijnltif                    XX_VTNS_MSTR_ACCT_NB_21;
};
Palternates gen_alternates_3_ijnltif_t {
	Pe_string_FW(:13:)                                 XX_BL_ACCT_NB_24;
	XX_VTNS_ACCT_ID_25_ijnltif                         XX_VTNS_ACCT_ID_25;
};
Pstruct XX_SUMM_KEY1_5_ijnltif {
	Pe_string_FW(:1:)                                  XX_DTL_RC_TYPE_CD_6;
	Pe_string_FW(:5:)                                  XX_SVC_CLS_CD_7;
	Pe_string_FW(:2:)                                  XX_SVC_KIND_CD_8;
	Pe_string_FW(:2:)                                  XX_MKT_SEG_CD_9;
	Pe_string_FW(:5:)                                  XX_USOC_CD_10;
	Pe_string_FW(:2:)                                  XX_CHRG_TYPE_CD_11;
	Pe_string_FW(:5:)                                  XX_MISC_RVNU_TYPE_CD_12;
	Pe_string_FW(:3:)                                  XX_FEAT_CD_13;
	Pe_string_FW(:13:)                                 XX_GEO_CD_14;
	gen_alternates_1_ijnltif_t                         GEN_ALTERNATES_1_ijnltif;
	Pe_string_FW(:1:)                                  XX_RC_LVL_CD_19;
	gen_alternates_2_ijnltif_t                         GEN_ALTERNATES_2_ijnltif;
	gen_alternates_3_ijnltif_t                         GEN_ALTERNATES_3_ijnltif;
};
Pstruct XX_EDIT_GRP1_4_ijnltif {
	XX_SUMM_KEY1_5_ijnltif                             XX_SUMM_KEY1_5;
};
Pstruct XX_EXTRN_INFO_3_ijnltif {
	XX_EDIT_GRP1_4_ijnltif                             XX_EDIT_GRP1_4;
	Pbcd_fpoint64(:11,2:)                              XX_JRNL_GRS_AT_30;
	XX_EDIT_GRP2_31_ijnltif                            XX_EDIT_GRP2_31;
};
Palternates gen_alternates_17_ijnltif_t {
	XX_INTRN_INFO_168_ijnltif                          XX_INTRN_INFO_168;
	XX_EXTRN_MCC_INFO_2_266_ijnltif                    XX_EXTRN_MCC_INFO_2_266;
};
Pstruct XX_EXTRN_INTRN_INFO_2_ijnltif {
	XX_EXTRN_INFO_3_ijnltif                            XX_EXTRN_INFO_3;
	gen_alternates_17_ijnltif_t                        GEN_ALTERNATES_17_ijnltif;
};
Pstruct XX_DTL_RC_1_ijnltif {
	XX_EXTRN_INTRN_INFO_2_ijnltif                      XX_EXTRN_INTRN_INFO_2;
	XX_TAX_SURCHG_INFO_274_ijnltif                     XX_TAX_SURCHG_INFO_274;
};
Pstruct cpy_ijnltif {
	XX_DTL_RC_1_ijnltif                                XX_DTL_RC_1;
};
Pstruct XX_TRL_SMS_5_ijnltift {
	Pe_string_FW(:5:)                                  XX_TRL_SMS_REC_TYP_6;
	Pebc_uint64(:9:)                                   XX_TRL_SMS_CNT_7 : XX_TRL_SMS_CNT_7 == num_recs ;
	Pe_string_FW(:34:)                                 XX_TRL_SMS_COMMON_8;
	Pe_string_FW(:12:)                                 FILLER_9;
};
Pstruct XX_TRL_RC_1_ijnltift {
	Pe_string_FW(:1:)                                  XX_TRL_RC_TYPE_CD_2;
	Pbcd_int64(:9:)                                    XX_TRL_FILE_RC_CNT_3;
	Pbcd_fpoint64(:11,2:)                              XX_TRL_FILE_AMT_4;
	XX_TRL_SMS_5_ijnltift                              XX_TRL_SMS_5;
};
Pstruct cpy_ijnltift {
	XX_TRL_RC_1_ijnltift                               XX_TRL_RC_1;
};
Precord Palternates d_or_t {
	cpy_ijnltift                                       is_t;
	cpy_ijnltif                                        is_d;
};

Parray d_or_t_array {
	d_or_t [];
};

Psource Pstruct ijnltif_file {
	cpy_ijnltifh                                       hdr;
	d_or_t                                             rest;
};

