Pstruct RP519_CR_IET_111_rps {
	Pe_string_FW(:4:)                                  RP519_CR_IET_ME_112;
	Pe_string_FW(:3:)                                  RP519_CR_IET_LE_113;
	Pe_string_FW(:3:)                                  RP519_CR_IET_AE_114;
};
Pstruct RP519_DB_IET_107_rps {
	Pe_string_FW(:4:)                                  RP519_DB_IET_ME_108;
	Pe_string_FW(:3:)                                  RP519_DB_IET_LE_109;
	Pe_string_FW(:3:)                                  RP519_DB_IET_AE_110;
};
Pstruct RP519_JE_102_rps {
	Pe_string_FW(:4:)                                  RP519_JE_FIRST_103;
	Pe_string_FW(:1:)                                  RP519_JE_MIDDLE_104;
	Pe_string_FW(:1:)                                  RP519_JE_LAST_105;
};
Pstruct RP519_PLUSS_CKT_NUM_98_rps {
	Pe_string_FW(:22:)                                 FILLER_99;
	Pe_string_FW(:1:)                                  RP519_CKT_CHANNEL_ID_100;
	Pe_string_FW(:1:)                                  RP519_CKT_MCN_IND_101;
};
Pstruct RP519_PRIVATE_LINE_ID_92_rps {
	Pe_string_FW(:2:)                                  RP519_SALES_OFFC_CD_93;
	Pe_string_FW(:6:)                                  RP519_MCN_BASE_94;
	Pe_string_FW(:3:)                                  RP519_MCN_SUFFIX_95;
	Pe_string_FW(:3:)                                  RP519_BILL_GRP_NBR_96;
	Pe_string_FW(:2:)                                  RP519_SALES_GRP_CD_97;
};
Pstruct RP519_TRM_AGRE_STRT_DTE_88_rps {
	Pe_string_FW(:2:)                                  RP519_TRM_AGRE_STRT_YY_89;
	Pe_string_FW(:2:)                                  RP519_TRM_AGRE_STRT_MM_90;
	Pe_string_FW(:2:)                                  RP519_TRM_AGRE_STRT_DD_91;
};
Pstruct RP519_ORIG_START_DATE_73_rps {
	Pe_string_FW(:2:)                                  RP519_ORIG_START_YR_DTE_74;
	Pe_string_FW(:2:)                                  RP519_ORIG_START_MO_DTE_75;
	Pe_string_FW(:2:)                                  RP519_ORIG_START_DAY_DTE_76;
};
Pstruct RP519_BRANCH_OFFICE_CDE_70_rps {
	Pe_string_FW(:5:)                                  RP519_BR_CD_POS_1_5_71;
	Pe_string_FW(:3:)                                  FILLER_72;
};
Pstruct RP519_UNER_CSUB_54_rps {
	Pe_string_FW(:1:)                                  RP519_UN_CSUB_1_55;
	Pe_string_FW(:2:)                                  RP519_UN_CSUB_2_56;
	Pe_string_FW(:2:)                                  RP519_UN_CSUB_3_57;
};
Pstruct RP519_UN_FACCT_8_BYTE_48_rps {
	Pe_string_FW(:3:)                                  RP519_UN_FACCT_1_49;
	Pe_string_FW(:2:)                                  RP519_UN_FACCT_2_50;
	Pe_string_FW(:2:)                                  RP519_UN_FACCT_3_51;
	Pe_string_FW(:1:)                                  RP519_UN_FACCT_4_52;
};
Pstruct RP519_UNER_FACCT_47_rps {
	RP519_UN_FACCT_8_BYTE_48_rps                       RP519_UN_FACCT_8_BYTE_48;
	Pe_string_FW(:2:)                                  RP519_UN_FACCT_SPACES_53;
};
Pstruct RP519_DB_CSUB_43_rps {
	Pe_string_FW(:1:)                                  RP519_DB_CSUB_1_44;
	Pe_string_FW(:2:)                                  RP519_DB_CSUB_2_45;
	Pe_string_FW(:2:)                                  RP519_DB_CSUB_3_46;
};
Pstruct RP519_DB_FACCT_8_BYTE_37_rps {
	Pe_string_FW(:3:)                                  RP519_DB_FACCT_1_38;
	Pe_string_FW(:2:)                                  RP519_DB_FACCT_2_39;
	Pe_string_FW(:2:)                                  RP519_DB_FACCT_3_40;
	Pe_string_FW(:1:)                                  RP519_DB_FACCT_4_41;
};
Pstruct RP519_DB_FACCT_36_rps {
	RP519_DB_FACCT_8_BYTE_37_rps                       RP519_DB_FACCT_8_BYTE_37;
	Pe_string_FW(:2:)                                  RP519_DB_FACCT_SPACES_42;
};
Pstruct RP519_CR_CSUB_32_rps {
	Pe_string_FW(:1:)                                  RP519_CR_CSUB_1_33;
	Pe_string_FW(:2:)                                  RP519_CR_CSUB_2_34;
	Pe_string_FW(:2:)                                  RP519_CR_CSUB_3_35;
};
Pstruct RP519_CR_FACCT_8_BYTE_26_rps {
	Pe_string_FW(:3:)                                  RP519_CR_FACCT_1_27;
	Pe_string_FW(:2:)                                  RP519_CR_FACCT_2_28;
	Pe_string_FW(:2:)                                  RP519_CR_FACCT_3_29;
	Pe_string_FW(:1:)                                  RP519_CR_FACCT_4_30;
};
Pstruct RP519_CR_FACCT_25_rps {
	RP519_CR_FACCT_8_BYTE_26_rps                       RP519_CR_FACCT_8_BYTE_26;
	Pe_string_FW(:2:)                                  RP519_CR_FACCT_SPACES_31;
};
Pstruct RP519_EXTRACT_TYPE1_13_rps {
	Pe_string_FW(:1:)                                  RP519_EXTRACT_POS11_14;
	Pe_string_FW(:2:)                                  FILLER_15;
};
Pstruct RP519_EXTR_TYPE_10_rps {
	Pe_string_FW(:2:)                                  RP519_EXTR_TYPE_POS12_11;
	Pe_string_FW(:1:)                                  FILLER_12;
};
Pstruct RP519_EXTRACT_TYPE_7_rps {
	Pe_string_FW(:1:)                                  FILLER_8;
	Pe_string_FW(:2:)                                  RP519_EXTR_TYPE_POS23_9;
};
Punion gen_union_1_t {
	RP519_EXTRACT_TYPE_7_rps                           RP519_EXTRACT_TYPE_7_arm;
	RP519_EXTR_TYPE_10_rps                             RP519_EXTR_TYPE_10_arm;
	RP519_EXTRACT_TYPE1_13_rps                         RP519_EXTRACT_TYPE1_13_arm;
};
Pstruct RP519_RPS_REC_2_rps {
	Pe_string_FW(:1:)                                  RP519_REC_TYPE_CD_3;
	Pebc_uint64(:3:)                                   RP519_GDG_NO_4;
	Pebc_uint64(:4:)                                   RP519_EXTRACT_GDG_NO_5;
	Pe_string_FW(:2:)                                  RP519_CBS_COPY_NUM_6;
	gen_union_1_t                                      GEN_UNION_1;
	Pe_string_FW(:6:)                                  RP519_EFFECTIVE_DATE_16;
	Pe_string_FW(:11:)                                 RP519_BL_TO_CD_17;
	Pe_string_FW(:10:)                                 RP519_INVC_NUM_18;
	Pe_string_FW(:10:)                                 RP519_ORIGNL_INVC_NUM_19;
	Pe_string_FW(:2:)                                  RP519_ADJ_RSN_CD_20;
	Pe_string_FW(:2:)                                  RP519_DBCR_CD_21;
	Pebc_ufpoint64(:13,2:)                             RP519_CUR_AMT_22;
	Pebc_ufpoint64(:13,2:)                             RP519_UNER_AMT_23;
	Pebc_fpoint64(:14,2:)                              RP519_PE_REV_AMT_24;
	RP519_CR_FACCT_25_rps                              RP519_CR_FACCT_25;
	RP519_CR_CSUB_32_rps                               RP519_CR_CSUB_32;
	RP519_DB_FACCT_36_rps                              RP519_DB_FACCT_36;
	RP519_DB_CSUB_43_rps                               RP519_DB_CSUB_43;
	RP519_UNER_FACCT_47_rps                            RP519_UNER_FACCT_47;
	RP519_UNER_CSUB_54_rps                             RP519_UNER_CSUB_54;
	Pe_string_FW(:1:)                                  RP519_BILLER_ID_58;
	Pe_string_FW(:2:)                                  RP519_BILLER_STATE_CD_59;
	Pe_string_FW(:1:)                                  RP519_SOURCE_OF_CHRG_60;
	Pe_string_FW(:2:)                                  RP519_USER_ENTERED_STATE_61;
	Pe_string_FW(:1:)                                  RP519_III_IND_62;
	Pe_string_FW(:3:)                                  RP519_TYPE_SVC_63;
	Pe_string_FW(:5:)                                  RP519_CLASS_SVC_64;
	Pe_string_FW(:5:)                                  RP519_USOC_CD_65;
	Pe_string_FW(:1:)                                  RP519_ARREARS_BILLING_IND_66;
	Pe_string_FW(:1:)                                  RP519_DISC_PLAN_67;
	Pe_string_FW(:1:)                                  RP519_MIU_IND_68;
	Pe_string_FW(:1:)                                  RP519_ADJ_IND_69;
	RP519_BRANCH_OFFICE_CDE_70_rps                     RP519_BRANCH_OFFICE_CDE_70;
	RP519_ORIG_START_DATE_73_rps                       RP519_ORIG_START_DATE_73;
	Pe_string_FW(:6:)                                  RP519_ORIG_INVC_DT_77;
	Pe_string_FW(:1:)                                  RP519_PBS_GENERATED_78;
	Pe_string_FW(:1:)                                  RP519_JRNLZD_FLG_79;
	Pe_string_FW(:1:)                                  RP519_OMIT_BILL_FLG_80;
	Pe_string_FW(:1:)                                  RP519_TP_FROM_CD_81;
	Pe_string_FW(:4:)                                  RP519_DB_STUDY_CD_82;
	Pe_string_FW(:4:)                                  RP519_CR_STUDY_CD_83;
	Pe_string_FW(:4:)                                  RP519_UNER_STUDY_CD_84;
	Pe_string_FW(:1:)                                  RP519_ADJMT_PG_CD_85;
	Pe_string_FW(:8:)                                  RP519_SALES_CHANNEL_86;
	Pe_string_FW(:8:)                                  RP519_TRM_AGRE_PLN_TYPE_87;
	RP519_TRM_AGRE_STRT_DTE_88_rps                     RP519_TRM_AGRE_STRT_DTE_88;
	RP519_PRIVATE_LINE_ID_92_rps                       RP519_PRIVATE_LINE_ID_92;
	RP519_PLUSS_CKT_NUM_98_rps                         RP519_PLUSS_CKT_NUM_98;
	RP519_JE_102_rps                                   RP519_JE_102;
	Pe_string_FW(:4:)                                  RP519_ME_106;
	RP519_DB_IET_107_rps                               RP519_DB_IET_107;
	RP519_CR_IET_111_rps                               RP519_CR_IET_111;
	Pe_string_FW(:3:)                                  RP519_CNTRY_CD_115;
	Pe_string_FW(:10:)                                 RP519_DB_PROD_CD_116;
	Pe_string_FW(:10:)                                 RP519_CR_PROD_CD_117;
	Pe_string_FW(:11:)                                 RP519_DB_CUSTOMER_CD_118;
	Pe_string_FW(:11:)                                 RP519_CR_CUSTOMER_CD_119;
	Pe_string_FW(:9:)                                  RP519_ORG_CD_CHARGED_120;
	Pe_string_FW(:9:)                                  RP519_DB_ORG_CD_ORIG_121;
	Pe_string_FW(:9:)                                  RP519_CR_ORG_CD_ORIG_122;
	Pe_string_FW(:1:)                                  RP519_HOME_STE_TAX_IND_123;
	Pe_string_FW(:2:)                                  RP519_ACC_TYPE_CD_124;
	Pe_string_FW(:1:)                                  RP519_FILE_IND_125;
	Pe_string_FW(:2:)                                  RP519_ERROR_CODE_126;
	Pe_string_FW(:2:)                                  RP519_BILL_CYCLE_127;
	Pe_string_FW(:1:)                                  RP519_INBOUND_IND_128;
	Pe_string_FW(:2:)                                  RP519_TP_ID_129;
	Pe_string_FW(:1:)                                  RP519_SRCE_SVC_CD_130;
	Pe_string_FW(:10:)                                 RP519_CUST_SEG_CD_CR_131;
	Pe_string_FW(:3:)                                  RP519_CALL_TYPE_CD_132;
	Pbcd_int64(:9:)                                    RP519_CALL_CNT_133;
	Pbcd_int64(:12:)                                   RP519_ELPSD_TM_134;
	Pe_string_FW(:2:)                                  RP519_FROM_CNTRY_CD_135;
	Pe_string_FW(:10:)                                 RP519_CUST_SEG_CD_DB_136;
	Pe_string_FW(:13:)                                 RP519_LEAD_ACCOUNT_137;
	Pe_string_FW(:5:)                                  RP519_TAX_TYPE_138;
	Pbcd_fpoint64(:9,2:)                               RP519_VOL_QTY_139;
	Pe_string_FW(:4:)                                  RP519_VOL_TYPE_140;
	Pe_string_FW(:1:)                                  RP519_GV_IND_CODE_141;
	Pe_string_FW(:1:)                                  RP519_GV_NOVATED_IND_142;
	Pe_string_FW(:1:)                                  RP519_HE_ACCT_IND_143;
	Pe_string_FW(:7:)                                  FILLER_144;
};
Pstruct RP519_RECORD_1_rps {
	RP519_RPS_REC_2_rps                                RP519_RPS_REC_2;
};
Precord Pstruct cpy_rps {
	RP519_RECORD_1_rps                                 RP519_RECORD_1;
};
