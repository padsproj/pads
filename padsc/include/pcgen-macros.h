## This source file is run through mksrc.pl to produce:
##
##    pcgen-macros-gen.h        : pads codegen macros
##
/* ********************* BEGIN_MACROS(pcgen-macros-gen.h) ********************** */

/*
 * PCGEN_*: pads codegen macros
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

/* Prototypes for CKIT */

#ifdef FOR_CKIT

void PCGEN_TYPEDEF_READ(const char *fn_nm, Perror_t base_read_call);
void PCGEN_TYPEDEF_READ_REC(const char *fn_nm, Perror_t base_read_call);
void PCGEN_TYPEDEF_READ_CHECK(const char *fn_nm, Perror_t base_read_call, int usercheck);
void PCGEN_TYPEDEF_READ_CHECK_REC(const char *fn_nm, Perror_t base_read_call, int usercheck);

void PCGEN_STRUCT_READ_PRE(const char *fn_nm, void *the_field);
void PCGEN_STRUCT_READ_POST_CHECK(const char *fn_nm, void *the_field, int usercheck);
void PCGEN_STRUCT_READ_POST_CHECK_ENDIAN(const char *fn_nm, void *the_field, int usercheck, Perror_t swap_call);

void PCGEN_STRUCT_READ_FIRST(const char *fn_nm, void *the_field, Perror_t read_call, int setEnd);
void PCGEN_STRUCT_READ_FIRST_CHECK(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, int setEnd);
void PCGEN_STRUCT_READ_FIRST_CHECK_ENDIAN(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, Perror_t swap_call, int setEnd);
void PCGEN_STRUCT_READ_NEXT(const char *fn_nm, void *the_field, Perror_t read_call, int setEnd);
void PCGEN_STRUCT_READ_NEXT_CHECK(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, int setEnd);
void PCGEN_STRUCT_READ_NEXT_CHECK_ENDIAN(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, Perror_t swap_call, int setEnd);

void PCGEN_STRUCT_READ_FIRST_CHAR_LIT(const char *fn_nm, Pchar char_lit);
void PCGEN_STRUCT_READ_NEXT_CHAR_LIT(const char *fn_nm, Pchar char_lit);
void PCGEN_STRUCT_READ_FIRST_STR_LIT(const char *fn_nm, const char *str_lit, size_t str_len_expr);
void PCGEN_STRUCT_READ_NEXT_STR_LIT(const char *fn_nm, const char *str_lit, size_t str_len_expr);
void PCGEN_STRUCT_READ_FIRST_REGEXP(const char *fn_nm, const char *regexp_str);
void PCGEN_STRUCT_READ_NEXT_REGEXP(const char *fn_nm, const char *regexp_str);

void PCGEN_ALT_READ_BEGIN(const char *fn_nm);
void PCGEN_ALT_READ_END(const char *fn_nm);

void PCGEN_ALT_READ_PRE(const char *fn_nm, void *the_field);
void PCGEN_ALT_READ_POST_CHECK(const char *fn_nm, void *the_field, int usercheck);
void PCGEN_ALT_READ_POST_CHECK_ENDIAN(const char *fn_nm, void *the_field, int usercheck, Perror_t swap_call);

void PCGEN_ALT_READ(const char *fn_nm, void *the_field, Perror_t read_call, int setEnd);
void PCGEN_ALT_READ_CHECK(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, int setEnd);
void PCGEN_ALT_READ_CHECK_ENDIAN(const char *fn_nm, void *the_field, Perror_t read_call, int usercheck, Perror_t swap_call, int setEnd);

void PCGEN_ALT_READ_CHAR_LIT(const char *fn_nm, Pchar char_lit);
void PCGEN_ALT_READ_STR_LIT(const char *fn_nm, const char *str_lit, size_t str_len_expr);
void PCGEN_ALT_READ_REGEXP(const char *fn_nm, const char *regexp_str);

#define PDCI_UNION_READ_SETUP_ARGS    const char *fn_nm, int the_tag, \
                                      void *rep_cleanup, void *rep_init, void *rep_copy, \
                                      void *pd_cleanup, void *pd_init, void *pd_copy

#define PDCI_UNION_READ_ARGS          const char *fn_nm, const char *the_tag_nm, int the_tag, \
                                      void *rep_cleanup, void *rep_init, void *rep_copy, \
                                      void *pd_cleanup, void *pd_init, void *pd_copy, \
                                      Perror_t read_call, Perror_t xmlwrite_call, int setEnd

#define PDCI_UNION_READ_MAN_PRE_ARGS  const char *fn_nm, int the_tag, \
                                      void *rep_init, void *pd_init

void PCGEN_UNION_READ_SETUP_STAT(PDCI_UNION_READ_SETUP_ARGS);
void PCGEN_UNION_READ_SETUP(PDCI_UNION_READ_SETUP_ARGS);

void PCGEN_UNION_READ_STAT        (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_FIRST       (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_NEXT        (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_LAST        (PDCI_UNION_READ_ARGS);

void PCGEN_UNION_READ_STAT_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_FIRST_CHECK (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_NEXT_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_LAST_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);

void PCGEN_UNION_READ_MAN_STAT_PRE       (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_MAN_FIRST_PRE      (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_MAN_NEXT_PRE       (PDCI_UNION_READ_MAN_PRE_ARGS);

void PCGEN_UNION_READ_MAN_STAT_VIRT_PRE  (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_MAN_FIRST_VIRT_PRE (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_MAN_NEXT_VIRT_PRE  (PDCI_UNION_READ_MAN_PRE_ARGS);

void PCGEN_UNION_READ_MAN_STAT_POST       (const char *fn_nm, void *rep_copy, void *rep_cleanup,
					   void *pd_copy, void *pd_cleanup);
void PCGEN_UNION_READ_MAN_POST            (const char *fn_nm, void *rep_copy, void *rep_cleanup,
					   void *pd_copy, void *pd_cleanup);
void PCGEN_UNION_READ_MAN_STAT_POST_CHECK (const char *fn_nm, void *rep_copy, void *rep_cleanup,
					   void *pd_copy, void *pd_cleanup, int usercheck);
void PCGEN_UNION_READ_MAN_POST_CHECK      (const char *fn_nm, void *rep_copy, void *rep_cleanup,
					   void *pd_copy, void *pd_cleanup, int usercheck);

void PCGEN_UNION_READ_CHECK_FAILED    (const char *fn_nm, const char *nm, int err_tag);
void PCGEN_UNION_READ_WHERE_CHECK     (const char *fn_nm, int usercheck, int isOpt);
void PCGEN_UNION_READ_WHERE_END_CHECK (const char *fn_nm, int usercheck, int isOpt);

void PCGEN_UNION_READ_LONGEST_SETUP_STAT(PDCI_UNION_READ_SETUP_ARGS);
void PCGEN_UNION_READ_LONGEST_SETUP(PDCI_UNION_READ_SETUP_ARGS);

void PCGEN_UNION_READ_LONGEST_STAT        (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_LONGEST_FIRST       (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_LONGEST_NEXT        (PDCI_UNION_READ_ARGS);
void PCGEN_UNION_READ_LONGEST_LAST        (PDCI_UNION_READ_ARGS);

void PCGEN_UNION_READ_LONGEST_STAT_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_LONGEST_FIRST_CHECK (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_LONGEST_NEXT_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);
void PCGEN_UNION_READ_LONGEST_LAST_CHECK  (PDCI_UNION_READ_ARGS, int usercheck);

void PCGEN_UNION_READ_LONGEST_MAN_STAT_PRE       (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_LONGEST_MAN_FIRST_PRE      (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_LONGEST_MAN_NEXT_PRE       (PDCI_UNION_READ_MAN_PRE_ARGS);

void PCGEN_UNION_READ_LONGEST_MAN_STAT_VIRT_PRE  (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_LONGEST_MAN_FIRST_VIRT_PRE (PDCI_UNION_READ_MAN_PRE_ARGS);
void PCGEN_UNION_READ_LONGEST_MAN_NEXT_VIRT_PRE  (PDCI_UNION_READ_MAN_PRE_ARGS);

void PCGEN_UNION_READ_LONGEST_MAN_STAT_POST       (const char *fn_nm, void *rep_copy, void *rep_cleanup,
						   void *pd_copy, void *pd_cleanup);
void PCGEN_UNION_READ_LONGEST_MAN_POST            (const char *fn_nm, void *rep_copy, void *rep_cleanup,
						   void *pd_copy, void *pd_cleanup);
void PCGEN_UNION_READ_LONGEST_MAN_STAT_POST_CHECK (const char *fn_nm, void *rep_copy, void *rep_cleanup,
						   void *pd_copy, void *pd_cleanup, int usercheck);
void PCGEN_UNION_READ_LONGEST_MAN_POST_CHECK      (const char *fn_nm, void *rep_copy, void *rep_cleanup,
						   void *pd_copy, void *pd_cleanup, int usercheck);

void PCGEN_UNION_READ_LONGEST_CHECK_FAILED    (const char *fn_nm, const char *nm, int err_tag);
void PCGEN_UNION_READ_LONGEST_WHERE_CHECK     (const char *fn_nm, int usercheck, int isOpt);
void PCGEN_UNION_READ_LONGEST_WHERE_END_CHECK (const char *fn_nm, int usercheck, int isOpt);

#define PDCI_SWUNION_READ_ARGS          const char *fn_nm, int the_tag, int err_tag, \
                                        void *rep_cleanup, void *rep_init, void *rep_copy, \
                                        void *pd_cleanup, void *pd_init, void *pd_copy, Perror_t read_call, int setEnd

#define PDCI_SWUNION_READ_MAN_PRE_ARGS  const char *fn_nm, int the_tag, \
                                        void *rep_cleanup, void *rep_init, void *rep_copy, \
                                        void *pd_cleanup, void *pd_init, void *pd_copy

void PCGEN_SWUNION_READ_STAT (PDCI_SWUNION_READ_ARGS);
void PCGEN_SWUNION_READ      (PDCI_SWUNION_READ_ARGS);

void PCGEN_SWUNION_READ_MAN_STAT_PRE      (PDCI_SWUNION_READ_MAN_PRE_ARGS);
void PCGEN_SWUNION_READ_MAN_STAT_VIRT_PRE (PDCI_SWUNION_READ_MAN_PRE_ARGS);
void PCGEN_SWUNION_READ_MAN_PRE           (PDCI_SWUNION_READ_MAN_PRE_ARGS);
void PCGEN_SWUNION_READ_MAN_VIRT_PRE      (PDCI_SWUNION_READ_MAN_PRE_ARGS);

void PCGEN_SWUNION_READ_POST_CHECK  (const char *fn_nm, int the_tag, int err_tag, int usercheck);
void PCGEN_SWUNION_READ_FAILED      (const char *fn_nm, const char *nm, int err_tag);
void PCGEN_SWUNION_READ_WHERE_CHECK (const char *fn_nm, int usercheck, int isOpt);
void PCGEN_SWUNION_READ_WHERE_END_CHECK (const char *fn_nm, int usercheck, int isOpt);

void PCGEN_UNION_COPY_PRE(const char *fn_nm, void *rep_cleanup);
void PCGEN_UNION_PD_COPY_PRE(const char *fn_nm, void *pd_cleanup);

void PCGEN_ARRAY_COPY_AR_STAT_ELT_STAT(const char *fn_nm, void *src, void *dst);
void PCGEN_ARRAY_COPY_AR_DYN_ELT_STAT(const char *fn_nm, void *src, void *dst);
void PCGEN_ARRAY_COPY_AR_STAT_ELT_DYN(const char *fn_nm, void *src, void *dst, void *elt_copy_fn, void *elt_cleanup_fn);
void PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN(const char *fn_nm, void *src, void *dst, void *elt_copy_fn, void *elt_cleanup_fn);

void PCGEN_ARRAY_CLEANUP_AR_STAT_ELT_STAT(const char *fn_nm, void *a);
void PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_STAT(const char *fn_nm, void *a);
void PCGEN_ARRAY_CLEANUP_AR_STAT_ELT_DYN(const char *fn_nm, void *a, void *elt_cleanup_fn);
void PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN(const char *fn_nm, void *a, void *elt_cleanup_fn);

void PCGEN_FIND_EOR(const char *fn_nm);


void PCGEN_STRUCT_ACC_REP_NOVALS();
void PCGEN_UNION_ACC_REP_NOVALS();
void PCGEN_UNION_ACC_XML_REP_NOVALS(const char *);
void PCGEN_ARRAY_ACC_REP_NOVALS();
Perror_t PCGEN_ENUM_ACC_REP2IO(const char *default_what, Perror_t int_acc_call);
Perror_t PCGEN_TYPEDEF_ACC_REP2IO(const char *default_what, const char *basety_nm, Perror_t base_acc_call);

void PCGEN_WRITE2IO_USE_WRITE2BUF(const char *fn_nm, ssize_t write2buf_call);

void PCGEN_TLEN_BUF_UPDATES();
void PCGEN_FINAL_TLEN_BUF_UPDATES();
void PCGEN_TLEN_IO_UPDATES();
void PCGEN_FINAL_TLEN_IO_UPDATES();
void PCGEN_TAG_OPEN_XML_BUF_OUT(const char *def_tag);
void PCGEN_TAG_OPEN_XML_IO_OUT(const char *def_tag);
void PCGEN_TAG_CLOSE_XML_BUF_OUT();
void PCGEN_TAG_CLOSE_XML_IO_OUT();
void PCGEN_ARRAY_OPEN_XML_BUF_OUT();
void PCGEN_ARRAY_OPEN_XML_IO_OUT();
void PCGEN_ARRAY_CLOSE_XML_BUF_OUT();
void PCGEN_ARRAY_CLOSE_XML_IO_OUT();
void PCGEN_XML_VALUE_BUF_OUT(const char *def_tag, int value);
void PCGEN_XML_VALUE_IO_OUT(const char *def_tag, int value);

void PCGEN_STRUCT_PD_XML_BUF_OUT();
void PCGEN_STRUCT_PD_XML_IO_OUT();
void PCGEN_ARRAY_PD_XML_BUF_OUT();
void PCGEN_ARRAY_PD_XML_IO_OUT();
void PCGEN_UNION_PD_XML_BUF_OUT();
void PCGEN_UNION_PD_XML_IO_OUT();
void PCGEN_SOURCE_XML_BUF_OUT_BEGIN(char *schema_name);
void PCGEN_SOURCE_XML_IO_OUT_BEGIN(char *schema_name);
void PCGEN_SOURCE_XML_BUF_OUT_END();
void PCGEN_SOURCE_XML_IO_OUT_END();

void PCGEN_ENUM_XML_BUF_OUT(const char *def_tag, const char *(rep2str_fn)(int));
void PCGEN_ENUM_XML_IO_OUT(const char *def_tag, const char *(rep2str_fn)(int));

void PCGEN_ENUM_FMT2BUF_FINAL_INIT(char * fnName);
void PCGEN_TYPEDEF_FMT2BUF_FINAL_INIT(char * fnName);
void PCGEN_STRUCT_FMT2BUF_FINAL_INIT(char * fnName);

void PCGEN_POINTER_FMT2BUF_INIT(char * fnName, Pfmt_fn fnLookupAssign, ssize_t fnInvoke);
void PCGEN_ENUM_FMT2BUF_INIT(char * fnName, Pfmt_fn fnLookupAssign, ssize_t fnInvoke);
void PCGEN_STANDARD_FMT2BUF_INIT(char * fnName, Pfmt_fn fnLookupAssign, ssize_t fnInvoke);

void PCGEN_FMT2BUF_STRUCT_FIELD(char *fieldName, ssize_t length);
void PCGEN_FMT2BUF_FIX_LAST();
void PCGEN_FMT2BUF_ARRAY(char *fnName, ssize_t length);
void PCGEN_FMT2BUF_UNION(char *fnName, ssize_t length, char *tagName);
void PCGEN_FMT2BUF_TYPEDEF(ssize_t length);
void PCGEN_FMT2BUF_ENUM(char *fnName, const char *tagName);
void PCGEN_FMT2BUF_RECORD(char * fnName);

typedef int type_t;
typedef int field_t;
typedef int var_t;

/* DYNAMIC macros are used in implementation of recursive types. -YHM */
void PCGEN_DYNAMIC_READ(Perror_t read_call);
void PCGEN_DYNAMIC_COPY(const char *fn_nm, type_t baseTy, void *src, void *dst, void *elt_copy_fn, void *elt_cleanup_fn);
void PCGEN_DYNAMIC_PD_COPY(const char *fn_nm, type_t baseTy, void *src, void *dst, void *elt_copy_fn, void *elt_cleanup_fn);

void PCGEN_DYNAMIC_REP_ALLOC(char *fnName, type_t baseTy);
void PCGEN_DYNAMIC_PD_ALLOC(char *fnName, type_t baseTy);
/* Allocs both rep and pd->value. */
void PCGEN_DYNAMIC_ALLOC(char *fnName, type_t baseTy);
void PCGEN_DYNAMIC_REP_CLEANUP(type_t baseTy);
void PCGEN_DYNAMIC_PD_CLEANUP(type_t baseTy);
void PCGEN_DYNAMIC_MASK_INIT(type_t baseTy,Pbase_m baseMask);

void PCGEN_ARRAY_TEST_MIN_GT_MAX(type_t ty);
void PCGEN_ARRAY_TEST_NEW_RBUF_ZERO(type_t ty,void *vIN);
void PCGEN_ARRAY_TEST_NEW_RBUF_NOZERO(type_t ty,void *vIN);
void PCGEN_ARRAY_TEST_FC_PANIC();
void PCGEN_ARRAY_TEST_FC_REACHED_END();
void PCGEN_ARRAY_TEST_FC_MATCH_TERM(void *funIn,char termIN,int eat_fIN,int panicIN);
void PCGEN_ARRAY_TEST_FC_REACHED_MAX(int maxIN);
int  PCGEN_ARRAY_RESERVE_SPACE(type_t ty,type_t elRepTy,type_t elPdTy,int hintIN);
void PCGEN_ARRAY_GET_BEGIN_LOC();
void PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE(Ploc_t bIN,Ploc_t eIN);
void PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE2();
void PCGEN_ARRAY_CHECKPOINT(type_t ty);
void PCGEN_ARRAY_READ_ELEM(Perror_t readCallIN);
void PCGEN_ARRAY_READ_ELEM_HD(Perror_t readCallIN,int haveDataIN);
Perror_t PCGEN_ARRAY_REREAD_ELEM_BODY(Perror_t readCallIN);
Perror_t PCGEN_ARRAY_REREAD_ELEM_RET();
void PCGEN_ARRAY_TEST_READ_ERR(int addTest1IN, int addTest2IN);
void PCGEN_ARRAY_TEST_FC_PANIC_RECOVER1(void *pdIN,int addTestIN,void *sepIN, void *termIN);
void PCGEN_ARRAY_TEST_FC_PANIC_RECOVER2(void *pdIN,int addTestIN,void *sepIN, void *termIN);
void PCGEN_ARRAY_FC_SCAN_SEP_TERM(type_t ty,void *funIn,void *sepIN,void *termIN,int eat_fIN,int eat_sIN,int panicIN);
void PCGEN_ARRAY_SCAN_SEP(type_t ty,void *funIn,void *sepIN,int eat_fIN,int panicIN);
void PCGEN_ARRAY_TEST_TRAILING_JUNK_C(type_t ty,void *funIn,char termIN);
void PCGEN_ARRAY_TEST_TRAILING_JUNK_P(type_t ty,void *funIn,void *termIN);
void PCGEN_ARRAY_READ_EOR(type_t ty);
void PCGEN_ARRAY_RECORD_ERROR(int errCodeIN,char *whatfn,...);
void PCGEN_ARRAY_CHK_ENOUGH_ELEMENTS(type_t ty);
void PCGEN_ARRAY_CFORALL_LOOP(var_t indexIN, int lowerIN,int upperIN, int bodyIN);
void PCGEN_ARRAY_CHK_FORALL_CONSTRAINT(type_t ty,var_t indexIN, int lowerIN,int upperIN, int bodyIN);
Perror_t PCGEN_ARRAY_STD_RETURN();
void PCGEN_ARRAY_TEST_ALREADY_DONE();
void PCGEN_ARRAY_DO_FINAL_CHECKS();
void PCGEN_ARRAY_RO_DECS();
void PCGEN_ARRAY_RO_DECS_SEP();
void PCGEN_ARRAY_LBL_FINAL_CHECKS();
//int  PCGEN_ARRAY_RET_FINAL_CHECKS();
int  PCGEN_ARRAY_RET_ONGOING(int keepElt);
int  PCGEN_ARRAY_RET_DONE(int keepElt);
void PCGEN_ARRAY_SET_PARTIAL();
void PCGEN_ARRAY_UNSET_PARTIAL();
void PCGEN_ARRAY_READ_ALL(int allocCall, Perror_t readCall, int incX, const char* whatfn);

#else
/* The actual macros */
/* ********************************** END_HEADER ********************************** */

#define PCGEN_FIND_EOR(fn_nm)
do {
  Pbase_pd tpd_PCGEN_;
  size_t bytes_skipped_PCGEN_;
  int no_panic_PCGEN_ = !P_PS_isPanic(pd);
  P_PS_unsetPanic(pd);
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  if (P_OK == P_io_next_rec(pads, &bytes_skipped_PCGEN_)) {
    PDCI_ECHO_RECORD(pads);
    if (bytes_skipped_PCGEN_) {
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      if (no_panic_PCGEN_) {
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_EXTRA_BEFORE_EOR, fn_nm, "Unexpected data before EOR");
	(pd->nerr)++;
	if (pd->nerr == 1) {
	  pd->errCode = P_EXTRA_BEFORE_EOR;
	  pd->loc = tpd_PCGEN_.loc;
	  if (P_spec_level(pads)) return P_ERR;
	}
      } else {
	PDCI_report_err(pads, P_LEV_INFO, &(tpd_PCGEN_.loc), P_NO_ERR, fn_nm, "Resynching at EOR");
      }
    }
  } else {
    PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
    PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_EOF_BEFORE_EOR, fn_nm, "Found EOF when searching for EOR");
    PDCI_ECHO_EOF(pads);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_EOF_BEFORE_EOR;
      pd->loc = tpd_PCGEN_.loc;
      if (P_spec_level(pads)) return P_ERR;
    }
  }
} while (0)
/* END_MACRO */

/* XXX should it be -1 or 0 below ??? */
#define PDCI_CONSTRAINT_ERR(fn_nm, ecode, msg)
do {
  (pd->nerr)++;
  pd->errCode = ecode;
  PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
  PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, msg);
} while (0)
/* END_MACRO */

#define PDCI_CONSTRAINT_ERR_LOC_ALREADY_SET(fn_nm, ecode, msg)
do {
  (pd->nerr)++;
  pd->errCode = ecode;
  PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, msg);
} while (0)
/* END_MACRO */

/* XXX should it be -1 or 0 below ??? */
#define PDCI_ELT_CONSTRAINT_ERR(fn_nm, elt_pd, elt_ecode, top_ecode, msg, xtra)
do {
  (elt_pd).nerr = 1;
  (elt_pd).errCode = elt_ecode;
  PDCI_READFN_ENDLOC_MINUS1(pads, (elt_pd).loc);
  PDCI_report_err(pads, P_LEV_WARN, &((elt_pd).loc), (elt_pd).errCode, fn_nm, msg);
  (pd->nerr)++;
  if (pd->nerr == 1) {
    pd->errCode = top_ecode;
    pd->loc = (elt_pd).loc;
    xtra
  }
} while (0)
/* END_MACRO */

#define PDCI_STRUCT_ELT_CONSTRAINT_ERR(fn_nm, the_field)
  PDCI_ELT_CONSTRAINT_ERR(fn_nm, pd->the_field, P_USER_CONSTRAINT_VIOLATION,
                          P_STRUCT_FIELD_ERR, "User constraint on field " PDCI_MacroArg2String(the_field) " violated",
			  if (P_spec_level(pads)) return P_ERR;)
/* END_MACRO */

/* for the following 4 macros, pd and rep shared with base type */
/* base_read_call reports error, fills in pd->nerr */

/* invoke this macro, return (pd->nerr == 0) ? P_OK : P_ERR */
#define PCGEN_TYPEDEF_READ(fn_nm, base_read_call)
do {
  PDCI_ECHO_TOKEN_PREFIX(pads,fn_nm);
  PDCI_IODISC_3P_CHECKS (fn_nm, m, pd, rep);
  base_read_call;
} while (0)
/* END_MACRO */

/* invoke this macro, return (pd->nerr == 0) ? P_OK : P_ERR */
#define PCGEN_TYPEDEF_READ_REC(fn_nm, base_read_call)
do {
  PDCI_IODISC_3P_CHECKS (fn_nm, m, pd, rep);
  PDCI_ECHO_TOKEN_PREFIX(pads,fn_nm);
  base_read_call;
  PCGEN_FIND_EOR(fn_nm);
} while (0)
/* END_MACRO */

/* invoke this macro, return (pd->nerr == 0) ? P_OK : P_ERR */
#define PCGEN_TYPEDEF_READ_CHECK(fn_nm, base_read_call, usercheck)
do {
  PDCI_IODISC_3P_CHECKS (fn_nm, m, pd, rep);
  PDCI_ECHO_TOKEN_PREFIX(pads,fn_nm);
  if (P_OK == (base_read_call) && P_Test_SemCheck (m->compoundLevel) && (!(usercheck))) {
    PDCI_CONSTRAINT_ERR(fn_nm, P_TYPEDEF_CONSTRAINT_ERR, 0);
  }
} while (0)
/* END_MACRO */

/* invoke this macro, return (pd->nerr == 0) ? P_OK : P_ERR */
#define PCGEN_TYPEDEF_READ_CHECK_REC(fn_nm, base_read_call, usercheck)
do {
  PDCI_IODISC_3P_CHECKS (fn_nm, m, pd, rep);
  PDCI_ECHO_TOKEN_PREFIX(pads,fn_nm);
  if (P_OK == (base_read_call) && P_Test_SemCheck (m->compoundLevel) && (!(usercheck))) {
    PDCI_CONSTRAINT_ERR(fn_nm, P_TYPEDEF_CONSTRAINT_ERR, 0);
  }
  PCGEN_FIND_EOR(fn_nm);
} while (0)
/* END_MACRO */

#define PCGEN_DYNAMIC_READ(read_call)
  Perror_t res;
  PDCI_READFN_BEGINLOC(pads, pd->val->loc);
  res = read_call;
  PDCI_READFN_ENDLOC_NOOP(pd->val->loc);
  if (P_ERR == res) {
    if (P_PS_isPanic(pd->val)) {
      P_PS_setPanic(pd);
    }
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_RECUR_VAL_ERR;
      pd->loc = pd->val->loc;
      if (P_spec_level(pads)) return P_ERR;
    }
  }
/* END_MACRO */

#define PCGEN_DYNAMIC_ANY_ALLOC(fn_nm, ty, dst)
do{
  if (dst == NULL){ 
    dst = (ty*) malloc (sizeof(ty));
    if (dst == NULL)
      {
	PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,fn_nm,0);
      }
    ty ## _init(pads,dst);
  }
}while(0)
/* END_MACRO */

#define PCGEN_DYNAMIC_REP_ALLOC(fn_nm,ty) PCGEN_DYNAMIC_ANY_ALLOC(fn_nm,ty,*rep)
#define PCGEN_DYNAMIC_PD_ALLOC(fn_nm,ty) PCGEN_DYNAMIC_ANY_ALLOC(fn_nm,ty ## _pd,pd->val)

#define PCGEN_DYNAMIC_ALLOC(fn_nm, ty)
do{
  PCGEN_DYNAMIC_REP_ALLOC(fn_nm,ty);
  PCGEN_DYNAMIC_PD_ALLOC(fn_nm,ty);  
}while(0)
/* END_MACRO */

#define PCGEN_DYNAMIC_REP_CLEANUP(baseTy)
do{
  if (*rep != NULL){
    baseTy ## _cleanup(pads,*rep);
    free(*rep);
    *rep = 0;
  }
}while(0)
/* END_MACRO */

#define PCGEN_DYNAMIC_PD_CLEANUP(baseTy)
do{
  if (pd->val != NULL){ 
    baseTy ## _pd_cleanup(pads,pd->val);
    free(pd->val);
    pd->val = 0;
  }
}while(0)
/* END_MACRO */

#define PCGEN_DYNAMIC_MASK_INIT(baseTy,baseMask)
do{
  baseTy ## _m_init(pads,*mask,baseMask);
}while(0)
/* END_MACRO */

#define PCGEN_DYNAMIC_COPY(fn_nm, baseTy, src, dst, val_copy_fn, cleanup_fn)
do {
  /* if source is empty, try to clean up destination. */
  if (*src == NULL) {
    cleanup_fn(pads, dst);
    return P_OK;
  }

  /* Ensure dst buffer is allocated */
  if (*dst == NULL){
    PCGEN_DYNAMIC_ANY_ALLOC(fn_nm, baseTy,*dst);
  }

  /* Copy underlying value */
  return val_copy_fn(pads, *dst, *src);
} while (0)
/* END_MACRO */

#define PCGEN_DYNAMIC_PD_COPY(fn_nm, baseTy, src, dst, val_copy_fn, cleanup_fn)
do {
  /* if source is empty, try to clean up destination. */
  if (src->val == NULL) {
    cleanup_fn(pads, dst);
    return P_OK;
  }

  /* Ensure dst buffer is allocated */
  if (dst->val == NULL){
    PCGEN_DYNAMIC_ANY_ALLOC(fn_nm, baseTy,dst->val);
  }

  /* Copy underlying value */
  return val_copy_fn(pads, dst->val, src->val);
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_PRE(fn_nm, the_field)
do {
  pd->the_field.errCode = P_NO_ERR;
  PDCI_READFN_BEGINLOC(pads, pd->the_field.loc);
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_POST_CHECK(fn_nm, the_field, usercheck)
do {
  if (P_Test_SemCheck(m->the_field ## _con) && (!(usercheck))) {
    PDCI_STRUCT_ELT_CONSTRAINT_ERR(fn_nm, the_field);
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_POST_CHECK_ENDIAN(fn_nm, the_field, usercheck, swap_call)
do {
  if (P_Test_SemCheck(m->the_field ## _con) && (!(usercheck))) {
    PDCI_READFN_ENDLOC_MINUS1(pads, pd->the_field.loc);
    swap_call;
    if (usercheck) {
       PerrorRep erep_PCGEN_ = pads->disc->e_rep;
       pads->disc->e_rep = PerrorRep_Med;
       pads->disc->d_endian = ((pads->disc->d_endian == PbigEndian) ? PlittleEndian : PbigEndian);
       PDCI_report_err(pads, P_LEV_INFO, &(pd->the_field.loc), P_NO_ERR, fn_nm,
                       "New data endian value: %s.  Machine endian value: %s (from " PDCI_MacroArg2String(the_field) " field test)",
                       Pendian2str(pads->disc->d_endian), Pendian2str(pads->m_endian));
       pads->disc->e_rep = erep_PCGEN_;
    } else {
      swap_call;
      PDCI_STRUCT_ELT_CONSTRAINT_ERR(fn_nm, the_field);
    }
  }
} while (0)
/* END_MACRO */

#define PDCI_READFN_ENDLOC_SET(loc)  PDCI_READFN_ENDLOC(pads, loc)
/* END_MACRO */

#define PDCI_READFN_ENDLOC_NOOP(loc) P_NULL_STMT
/* END_MACRO */

#define PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call, doEnd)
  Perror_t res;
  PDCI_READFN_BEGINLOC(pads, pd->the_field.loc);
  res = read_call;
  PDCI_READFN_ENDLOC##doEnd(pd->the_field.loc);
  if (P_ERR == res) {
    if (P_PS_isPanic(&(pd->the_field))) {
      P_PS_setPanic(pd);
    }
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_STRUCT_FIELD_ERR;
      pd->loc = pd->the_field.loc;
      if (P_spec_level(pads)) return P_ERR;
    }
  }
/* END_MACRO */

#define PDCI_STRUCT_READ_HANDLE_PANIC(fn_nm, the_field)
  P_PS_setPanic(&(pd->the_field));
  pd->the_field.errCode = P_io_at_eof(pads) ? P_AT_EOF : P_PANIC_SKIPPED;
  pd->the_field.nerr = 1;
  PDCI_READFN_GETLOC_SPAN0(pads, pd->the_field.loc);
  (pd->nerr)++;
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST(fn_nm, the_field, read_call, doEnd)
do {
  PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call, doEnd)
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST_CHECK(fn_nm, the_field, read_call, usercheck, doEnd)
do {
  PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call, doEnd)
  else PCGEN_STRUCT_READ_POST_CHECK(fn_nm, the_field, usercheck);
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST_CHECK_ENDIAN(fn_nm, the_field, read_call, usercheck, swap_call, doEnd)
do {
  PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call, doEnd)
  else PCGEN_STRUCT_READ_POST_CHECK_ENDIAN(fn_nm, the_field, usercheck, swap_call);
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT(fn_nm, the_field, read_call, doEnd)
do {
  if (P_PS_isPanic(pd)) {
    PDCI_STRUCT_READ_HANDLE_PANIC(fn_nm, the_field)
  } else {
    PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT_CHECK(fn_nm, the_field, read_call, usercheck,doEnd)
do {
  if (P_PS_isPanic(pd)) {
    PDCI_STRUCT_READ_HANDLE_PANIC(fn_nm, the_field)
  } else {
    PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
    else PCGEN_STRUCT_READ_POST_CHECK(fn_nm, the_field, usercheck);
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT_CHECK_ENDIAN(fn_nm, the_field, read_call, usercheck, swap_call, doEnd)
do {
  if (P_PS_isPanic(pd)) {
    PDCI_STRUCT_READ_HANDLE_PANIC(fn_nm, the_field)
  } else {
    PDCI_STRUCT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
    else PCGEN_STRUCT_READ_POST_CHECK_ENDIAN(fn_nm, the_field, usercheck, swap_call);
  }
} while (0)
/* END_MACRO */

#define PDCI_STRUCT_READ_CHAR_LIT(fn_nm, char_lit)
do {
  Pbase_pd tpd_PCGEN_;
  size_t toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  if (P_OK == Pchar_lit_scan1(pads, char_lit, 1, 0, &toffset_PCGEN_)) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before char separator %s", P_qfmt_char(char_lit));
	if (P_spec_level(pads)) return P_ERR;
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing char separator %s", P_qfmt_char(char_lit));
      if (P_spec_level(pads)) return P_ERR;
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST_CHAR_LIT(fn_nm, char_lit)
  PDCI_STRUCT_READ_CHAR_LIT(fn_nm, char_lit)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT_CHAR_LIT(fn_nm, char_lit)
do {
  if (P_PS_isPanic(pd)) {
    size_t toffset_PCGEN_;
    if (P_ERR != Pchar_lit_scan1(pads, char_lit, 1, 1, &toffset_PCGEN_)) {
      P_PS_unsetPanic(pd);
    }
  } else PDCI_STRUCT_READ_CHAR_LIT(fn_nm, char_lit);
} while (0)
/* END_MACRO */

#define PDCI_STRUCT_READ_STR_LIT(fn_nm, pads_str_lit)
do {
  Pbase_pd tpd_PCGEN_;
  size_t toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  if (P_OK == Pstr_lit_scan1(pads, pads_str_lit, 1, 0, &toffset_PCGEN_)) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before string separator %s", P_qfmt_str(pads_str_lit));
	if (P_spec_level(pads)) return P_ERR;
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing string separator %s", P_qfmt_str(pads_str_lit));
      if (P_spec_level(pads)) return P_ERR;
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST_STR_LIT(fn_nm, str_lit, str_len_expr)
do {
  P_STRING_DECL_CSTR_LEN(tstr, str_lit, str_len_expr);
  PDCI_STRUCT_READ_STR_LIT(fn_nm, &tstr);
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT_STR_LIT(fn_nm, str_lit, str_len_expr)
do {
  P_STRING_DECL_CSTR_LEN(tstr, str_lit, str_len_expr);
  if (P_PS_isPanic(pd)) {
    size_t toffset_PCGEN_;
    if (P_ERR != Pstr_lit_scan1(pads, &tstr, 1, 1, &toffset_PCGEN_)) {
      P_PS_unsetPanic(pd);
    }
  } else PDCI_STRUCT_READ_STR_LIT(fn_nm, &tstr);
} while (0)
/* END_MACRO */

#define PDCI_STRUCT_READ_REGEXP(fn_nm, regexp, regexp_str)
do {
  Perror_t terr_PCGEN_;
  Pbase_pd tpd_PCGEN_;
  size_t   toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  terr_PCGEN_ = Pre_scan1(pads, regexp, 1, 0, &toffset_PCGEN_);
  Pregexp_cleanup(pads, regexp);
  if (terr_PCGEN_ == P_OK) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before regexp separator Pre %s", P_qfmt_cstr(regexp_str));
	if (P_spec_level(pads)) return P_ERR;
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing regexp separator Pre %s", P_qfmt_cstr(regexp_str));
      if (P_spec_level(pads)) return P_ERR;
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_FIRST_REGEXP(fn_nm, regexp_str)
do {
  P_REGEXP_DECL_NULL(tregexp);
  PDCI_regexp_compile_cstr(pads, regexp_str, &tregexp, "Regexp-specified separator", fn_nm);
  if (!tregexp.valid) {
    pd->errCode = P_INVALID_REGEXP;
    (pd->nerr)++;
    P_PS_setPanic(pd);
  } else {
    PDCI_STRUCT_READ_REGEXP(fn_nm, &tregexp, regexp_str);
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_READ_NEXT_REGEXP(fn_nm, regexp_str)
do {
  P_REGEXP_DECL_NULL(tregexp);
  PDCI_regexp_compile_cstr(pads, regexp_str, &tregexp, "Regexp-specified separator", fn_nm);
  if (!tregexp.valid) {
    pd->errCode = P_INVALID_REGEXP;
    (pd->nerr)++;
    P_PS_setPanic(pd);
  } else {
    if (P_PS_isPanic(pd)) {
      Perror_t terr_PCGEN_;
      size_t toffset_PCGEN_;
      terr_PCGEN_ = Pre_scan1(pads, &tregexp, 1, 1, &toffset_PCGEN_);
      Pregexp_cleanup(pads, &tregexp);
      if (terr_PCGEN_ == P_OK) {
	P_PS_unsetPanic(pd);
      }
    } else {
      PDCI_STRUCT_READ_REGEXP(fn_nm, &tregexp, regexp_str);
    }
  }
} while (0)
/* END_MACRO */

#define PDCI_ALT_ELT_CONSTRAINT_ERR(fn_nm, the_field)
    PDCI_ELT_CONSTRAINT_ERR(fn_nm, pd->the_field, P_USER_CONSTRAINT_VIOLATION,
			    P_STRUCT_FIELD_ERR, "User constraint on field " PDCI_MacroArg2String(the_field) " violated",)
/* END_MACRO */

#define PCGEN_ALT_READ_BEGIN(fn_nm)
  Ppos_t start_pos_PCGEN_, cur_pos_PCGEN_, max_pos_PCGEN_;
  int no_panic_PCGEN_ = 0, moved_pos_PCGEN_ = 0;
  Perror_t res;
  do {
    PDCI_ALWAYS_GETPOS(pads, start_pos_PCGEN_);
    max_pos_PCGEN_    = start_pos_PCGEN_;
    if (P_ERR == P_io_checkpoint(pads, 0)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_CHKPOINT_ERR, fn_nm, 0);
    }
  } while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_END(fn_nm)
do {
  if (no_panic_PCGEN_) {
    P_PS_unsetPanic(pd);
  } else {
    P_PS_setPanic(pd);
  }
  if (moved_pos_PCGEN_) {
    if (P_ERR == P_io_commit_pos(pads, max_pos_PCGEN_)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
  } else {
    if (P_ERR == P_io_restore(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
    }
    PDCI_report_err(pads, P_LEV_WARN, 0, P_NO_ERR, fn_nm, "No branch of this Palternates advanced the IO cursor");
  }
} while (0)
/* END_MACRO */

#define PDCI_ALT_READ_FIELD_PRE(fn_nm)
  if (P_ERR == P_io_checkpoint(pads, 0)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_CHKPOINT_ERR, fn_nm, 0);
  }
  P_PS_unsetPanic(pd);
/* END_MACRO */

#define PDCI_ALT_READ_FIELD_POST(fn_nm)
  if (!P_PS_isPanic(pd)) {
    no_panic_PCGEN_ = 1;
    PDCI_ALWAYS_GETPOS(pads, cur_pos_PCGEN_);
    error(0, "XXX_REMOVE cur_pos_PCGEN_.offset %lu max_pos_PCGEN_.offset %lu",
	  (unsigned long)cur_pos_PCGEN_.offset, (unsigned long)max_pos_PCGEN_.offset); 
    if (P_POS_GT(cur_pos_PCGEN_, max_pos_PCGEN_)) {
      max_pos_PCGEN_ = cur_pos_PCGEN_;
      moved_pos_PCGEN_ = 1;
      error(0, "XXX_REMOVE modified max_pos_PCGEN_");
    }
  }
  PDCI_IO_RESTORE_KEEP_ID_GEN(fn_nm, pads);
/* END_MACRO */

#define PCGEN_ALT_READ_PRE(fn_nm, the_field)
do {
  pd->the_field.errCode = P_NO_ERR;
  PDCI_READFN_BEGINLOC(pads, pd->the_field.loc);
  P_PS_unsetPanic(pd);
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_POST_CHECK(fn_nm, the_field, usercheck)
do {
  if (P_Test_SemCheck(m->the_field ## _con) && (!(usercheck))) {
    PDCI_ALT_ELT_CONSTRAINT_ERR(fn_nm, the_field);
  }
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_POST_CHECK_ENDIAN(fn_nm, the_field, usercheck, swap_call)
do {
  if (P_Test_SemCheck(m->the_field ## _con) && (!(usercheck))) {
    PDCI_READFN_ENDLOC_MINUS1(pads, pd->the_field.loc);
    swap_call;
    if (usercheck) {
       PerrorRep erep_PCGEN_ = pads->disc->e_rep;
       pads->disc->e_rep = PerrorRep_Med;
       pads->disc->d_endian = ((pads->disc->d_endian == PbigEndian) ? PlittleEndian : PbigEndian);
       PDCI_report_err(pads, P_LEV_INFO, &(pd->the_field.loc), P_NO_ERR, fn_nm,
                       "New data endian value: %s.  Machine endian value: %s (from " PDCI_MacroArg2String(the_field) " field test)",
                       Pendian2str(pads->disc->d_endian), Pendian2str(pads->m_endian));
       pads->disc->e_rep = erep_PCGEN_;
    } else {
      swap_call;
      PDCI_ALT_ELT_CONSTRAINT_ERR(fn_nm, the_field);
    }
  }
} while (0)
/* END_MACRO */

#define PDCI_ALT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
  PDCI_READFN_BEGINLOC(pads, pd->the_field.loc);
  res = read_call;
  PDCI_READFN_ENDLOC ## doEnd(pd->the_field.loc);
  if (P_ERR == res) {
    if (P_PS_isPanic(&(pd->the_field))) {
      P_PS_setPanic(pd);
    }
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_STRUCT_FIELD_ERR;
      pd->loc = pd->the_field.loc;
    }
  }
/* END_MACRO */

#define PCGEN_ALT_READ(fn_nm, the_field, read_call, doEnd)
do {
  PDCI_ALT_READ_FIELD_PRE(fn_nm)
  PDCI_ALT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
  PDCI_ALT_READ_FIELD_POST(fn_nm)
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_CHECK(fn_nm, the_field, read_call, usercheck, doEnd)
do {
  PDCI_ALT_READ_FIELD_PRE(fn_nm)
  PDCI_ALT_READ_FIELD(fn_nm, the_field, read_call, doEnd)
  else PCGEN_ALT_READ_POST_CHECK(fn_nm, the_field, usercheck);
  PDCI_ALT_READ_FIELD_POST(fn_nm)
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_CHECK_ENDIAN(fn_nm, the_field, read_call, usercheck, swap_call, doEnd)
do {
  PDCI_ALT_READ_FIELD_PRE(fn_nm)
  PDCI_ALT_READ_FIELD(fn_nm, the_field, read_call,doEnd)
  else PCGEN_ALT_READ_POST_CHECK_ENDIAN(fn_nm, the_field, usercheck, swap_call);
  PDCI_ALT_READ_FIELD_POST(fn_nm)
} while (0)
/* END_MACRO */

#define PDCI_ALT_READ_CHAR_LIT(fn_nm, char_lit)
do {
  Pbase_pd tpd_PCGEN_;
  size_t toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  if (P_OK == Pchar_lit_scan1(pads, char_lit, 1, 0, &toffset_PCGEN_)) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
        PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before char separator %s", P_qfmt_char(char_lit));
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing char separator %s", P_qfmt_char(char_lit));
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_CHAR_LIT(fn_nm, char_lit)
do {
  PDCI_ALT_READ_FIELD_PRE(fn_nm)
  PDCI_ALT_READ_CHAR_LIT(fn_nm, char_lit);
  PDCI_ALT_READ_FIELD_POST(fn_nm)
} while (0)
/* END_MACRO */

#define PDCI_ALT_READ_STR_LIT(fn_nm, pads_str_lit)
do {
  Pbase_pd tpd_PCGEN_;
  size_t toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  if (P_OK == Pstr_lit_scan1(pads, pads_str_lit, 1, 0, &toffset_PCGEN_)) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before string separator %s", P_qfmt_str(pads_str_lit));
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing string separator %s", P_qfmt_str(pads_str_lit));
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_STR_LIT(fn_nm, str_lit, str_len_expr)
do {
  P_STRING_DECL_CSTR_LEN(tstr, str_lit, str_len_expr);
  PDCI_ALT_READ_FIELD_PRE(fn_nm)
  PDCI_ALT_READ_STR_LIT(fn_nm, &tstr);
  PDCI_ALT_READ_FIELD_POST(fn_nm)
} while (0)
/* END_MACRO */

#define PDCI_ALT_READ_REGEXP(fn_nm, regexp, regexp_str)
do {
  Perror_t terr_PCGEN_;
  Pbase_pd tpd_PCGEN_;
  size_t   toffset_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, tpd_PCGEN_.loc);
  terr_PCGEN_ = Pre_scan1(pads, regexp, 1, 0, &toffset_PCGEN_);
  Pregexp_cleanup(pads, regexp);
  if (terr_PCGEN_ == P_OK) {
    if (toffset_PCGEN_) {
      (pd->nerr)++;
      if (pd->nerr == 1) {
	pd->errCode = P_STRUCT_EXTRA_BEFORE_SEP;
	PDCI_READFN_ENDLOC_MINUS2(pads, tpd_PCGEN_.loc);
	pd->loc = tpd_PCGEN_.loc;
	PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_STRUCT_EXTRA_BEFORE_SEP, fn_nm,
			"Extra data before regexp separator Pre %s", P_qfmt_cstr(regexp_str));
      }
    }
  } else {
    P_PS_setPanic(pd);
    (pd->nerr)++;
    if (pd->nerr == 1) {
      pd->errCode = P_MISSING_LITERAL;
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd_PCGEN_.loc);
      pd->loc = tpd_PCGEN_.loc;
      PDCI_report_err(pads, P_LEV_WARN, &(tpd_PCGEN_.loc), P_MISSING_LITERAL, fn_nm,
		      "Missing regexp separator Pre %s", P_qfmt_cstr(regexp_str));
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_ALT_READ_REGEXP(fn_nm, regexp_str)
do {
  P_REGEXP_DECL_NULL(tregexp);
  PDCI_regexp_compile_cstr(pads, regexp_str, &tregexp, "Regexp-specified separator", fn_nm);
  if (!tregexp.valid) {
    pd->errCode = P_INVALID_REGEXP;
    (pd->nerr)++;
    P_PS_setPanic(pd);
  } else {
    PDCI_ALT_READ_FIELD_PRE(fn_nm)
    PDCI_ALT_READ_REGEXP(fn_nm, &tregexp, regexp_str);
    PDCI_ALT_READ_FIELD_POST(fn_nm)
  }
} while (0)
/* END_MACRO */

#ifndef NDEBUG
// union arm debugging macros
#define PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res)
do {
  if (P_Test_DbgRead(m->compoundLevel)) {
    if (read_res == P_ERR) {
      fprintf(sfstderr, "[in %s](DbgRead is set): read for union field %s failed.  Read result:\n",
	      fn_nm, the_tag_nm);
    } else {
      fprintf(sfstderr, "[in %s](DbgRead is set): read for union field %s succeeded, user-level check failed.  Read result:\n",
	      fn_nm, the_tag_nm);
    }
    xmlwrite_call;
  }
} while (0)
/* END_MACRO */

#else
// non-debug versions
#define PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res)       P_NULL_STMT
/* END_MACRO */

#endif

#define PCGEN_UNION_READ_SETUP_STAT(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
Ppos_t start_pos_PCGEN_;
do {
  PDCI_READFN_GETPOS(pads, start_pos_PCGEN_);
  pd->errCode = P_NO_ERR;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_SETUP(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
Ppos_t start_pos_PCGEN_;
do {
  PDCI_READFN_GETPOS(pads, start_pos_PCGEN_);
  if (rep->tag != the_tag) {
    PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
    rep_cleanup(pads, rep);
    pd_cleanup(pads, pd);
    rep_init(pads, rep);
    pd_init(pads, pd);
    PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
  }
  pd->errCode = P_NO_ERR;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_SETUP_COMMON(reptag, pdtag, fn_nm, the_tag, read_call, doEnd)
do{
  if (P_ERR == P_io_checkpoint(pads, 1)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_CHKPOINT_ERR, fn_nm, 0);
  }
  reptag = the_tag;
  pdtag  = the_tag;
  read_res_PCGEN_ = read_call;
  PDCI_READFN_ENDLOC##doEnd((pd->val).the_tag.loc);
} while (0);
/* END_MACRO */

#define PCGEN_UNION_READ_FIELD_SETUP(reptag, pdtag, fn_nm, the_tag, read_call, doEnd)
  Perror_t read_res_PCGEN_;
  PCGEN_UNION_READ_SETUP_COMMON(reptag, pdtag, fn_nm, the_tag, read_call,doEnd);
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_FIELD_SETUP(rep, pd, errCode, fn_nm, the_tag, read_call, doEnd, rep_init, pd_init)
  Perror_t read_res_PCGEN_;
  PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
  rep_init(pads, rep);
  pd_init(pads, pd);
  PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
  errCode = P_NO_ERR;
  PCGEN_UNION_READ_SETUP_COMMON(rep->tag, pd->tag, fn_nm, the_tag, read_call, doEnd);   
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_STAT(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call,doEnd)
do {
  PCGEN_UNION_READ_FIELD_SETUP(rep->tag, pd->tag, fn_nm, the_tag, read_call, doEnd);
  if (P_OK == read_res_PCGEN_) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_STAT_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_FIELD_SETUP(rep->tag, pd->tag, fn_nm, the_tag, read_call, doEnd);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

/* goes to branches_done on success, falls through on failure */
#define PCGEN_UNION_READ_FIRST(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd)
do {
  PCGEN_UNION_READ_FIELD_SETUP(rep->tag, pd->tag, fn_nm, the_tag, read_call, doEnd);
  if (P_OK == read_res_PCGEN_) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, rep);
  pd_cleanup  (pads, pd);
} while (0)
/* END_MACRO */

/* goes to branches_done on success, falls through on failure */

#define PCGEN_UNION_READ_FIRST_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_FIELD_SETUP(rep->tag, pd->tag,fn_nm, the_tag, read_call, doEnd);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, rep);
  pd_cleanup  (pads, pd);
} while (0)
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_NEXT(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call,doEnd)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(rep, pd, pd->errCode, fn_nm, the_tag, read_call, doEnd, rep_init, pd_init);
  if (P_OK == read_res_PCGEN_) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, rep);
  pd_cleanup  (pads, pd);
} while (0)
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_NEXT_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd,usercheck)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(rep, pd, pd->errCode, fn_nm, the_tag, read_call, doEnd, rep_init, pd_init);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, rep);
  pd_cleanup  (pads, pd);
} while (0)
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_LAST(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(rep, pd, pd->errCode, fn_nm,the_tag, read_call, doEnd, rep_init, pd_init);
  if (P_OK == read_res_PCGEN_) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

/* falls through on error, goes to branches_done on success */
#define PCGEN_UNION_READ_LAST_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(rep, pd, pd->errCode, fn_nm,the_tag, read_call, doEnd, rep_init, pd_init);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    if (P_ERR == P_io_commit(pads)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_COMMIT_ERR, fn_nm, 0);
    }
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  rep->tag = the_tag;
  pd->tag = the_tag;
  PD_COMMON_INIT_NO_ERR(&(pd->val.the_tag));
  PDCI_READFN_BEGINLOC(pads, pd->val.the_tag.loc);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_FIRST_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_FIRST_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_NEXT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
  rep_init(pads, rep);
  pd_init(pads, pd);
  PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
  pd->errCode = P_NO_ERR;
  PCGEN_UNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init);
} while (0)
/* END_MACRO */

/* not sure that the init calls are needed */
#define PCGEN_UNION_READ_MAN_NEXT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
  rep_init(pads, rep);
  pd_init(pads, pd);
  PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
  pd->errCode = P_NO_ERR;
  PCGEN_UNION_READ_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_STAT_POST(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup)
do {
  pd->loc.b = start_pos_PCGEN_;
  goto branches_done;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_POST(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup)
do {
  pd->loc.b = start_pos_PCGEN_;
  goto branches_done;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_STAT_POST_CHECK(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup, usercheck)
do {
  if (!P_Test_SemCheck(m->compoundLevel) || (usercheck)) {
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_MAN_POST_CHECK(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup, usercheck)
do {
  if (!P_Test_SemCheck(m->compoundLevel) || (usercheck)) {
    pd->loc.b = start_pos_PCGEN_;
    goto branches_done;
  }
  rep_cleanup(pads, rep);
  pd_cleanup(pads, pd);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_WHERE_CHECK(fn_nm, usercheck, isOpt)
do {
    if (P_Test_SemCheck(m->compoundLevel) && (!(usercheck))) {
      pd->loc.b = start_pos_PCGEN_;
      if (isOpt) {
        PDCI_CONSTRAINT_ERR(fn_nm, P_USER_CONSTRAINT_VIOLATION, "Popt specification violation");
      } else {
        PDCI_CONSTRAINT_ERR(fn_nm, P_USER_CONSTRAINT_VIOLATION, "Pwhere clause violation");
      }
    }
} while (0)
/* END_MACRO */

#define PDCI_UNION_READ_WHERE_END_CHECK(fn_nm, usercheck, isOpt)
do {
    PDCI_READFN_ENDLOC(pads, pd->loc);
    PCGEN_UNION_READ_WHERE_CHECK(fn_nm, usercheck, isOpt);
} while (0)
/* END_MACRO */

/* XXX why was K codegen using -2 below ??? XXX */
#define PCGEN_UNION_READ_CHECK_FAILED(fn_nm, nm, err_tag)
do {
  (pd->nerr)++;
  pd->errCode = P_UNION_MATCH_ERR;
  pd->loc.b = start_pos_PCGEN_;
  PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
  PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, "Failed to match any branch of union " nm);
  rep->tag = err_tag;
  pd->tag = err_tag;
  P_PS_setPanic(pd);
  goto final_check;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_SETUP_STAT(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
Ppos_t      start_pos_PCGEN_, end_pos_PCGEN_;
ssize_t     longest_PCGEN_ = -1;
do {
  PDCI_ALWAYS_GETPOS(pads, start_pos_PCGEN_);
  memset((void*)&trep_PCGEN_, 0, sizeof(trep_PCGEN_));
  memset((void*)&tpd_PCGEN_, 0, sizeof(tpd_PCGEN_));
  tpd_PCGEN_.errCode = P_NO_ERR;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_SETUP(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
Ppos_t      start_pos_PCGEN_, end_pos_PCGEN_;
ssize_t     longest_PCGEN_ = -1;
do {
  PDCI_ALWAYS_GETPOS(pads, start_pos_PCGEN_);
  rep_init(pads, &trep_PCGEN_);
  pd_init(pads, &tpd_PCGEN_);
  tpd_PCGEN_.errCode = P_NO_ERR;
} while (0)
/* END_MACRO */

#define PDCI_UNION_LONGEST_READ_CHECK_LONGEST_STAT
do {
    PDCI_ALWAYS_GETPOS(pads, end_pos_PCGEN_);
    if (end_pos_PCGEN_.offset - start_pos_PCGEN_.offset > longest_PCGEN_) {
      PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
      longest_PCGEN_ = end_pos_PCGEN_.offset - start_pos_PCGEN_.offset;
      memcpy(rep, &trep_PCGEN_, sizeof(trep_PCGEN_));
      memcpy(pd,  &tpd_PCGEN_,  sizeof(tpd_PCGEN_));
      PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
      pd->loc.b = start_pos_PCGEN_;
      pd->loc.e = end_pos_PCGEN_;
    }
} while (0)
/* END_MACRO */

#define PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy)
do {
    PDCI_ALWAYS_GETPOS(pads, end_pos_PCGEN_);
    if (end_pos_PCGEN_.offset - start_pos_PCGEN_.offset > longest_PCGEN_) {
      PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
      longest_PCGEN_ = end_pos_PCGEN_.offset - start_pos_PCGEN_.offset;
      rep_copy(pads, rep, &trep_PCGEN_);
      pd_copy(pads, pd,  &tpd_PCGEN_);
      PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
      pd->loc.b = start_pos_PCGEN_;
      pd->loc.e = end_pos_PCGEN_;
    }
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_STAT(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd)
do {
  PCGEN_UNION_READ_FIELD_SETUP(trep_PCGEN_.tag, tpd_PCGEN_.tag, fn_nm, the_tag, read_call, doEnd);
  if (P_OK == read_res_PCGEN_) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST_STAT;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_STAT_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_FIELD_SETUP(trep_PCGEN_.tag, tpd_PCGEN_.tag,fn_nm, the_tag, read_call, doEnd);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST_STAT;
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_FIRST(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd)
do {
  PCGEN_UNION_READ_FIELD_SETUP(trep_PCGEN_.tag, tpd_PCGEN_.tag, fn_nm, the_tag, read_call, doEnd);
  if (P_OK == read_res_PCGEN_) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_FIRST_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_FIELD_SETUP(trep_PCGEN_.tag, tpd_PCGEN_.tag, fn_nm, the_tag, read_call, doEnd);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_NEXT(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(&trep_PCGEN_, &tpd_PCGEN_, tpd_PCGEN_.errCode, fn_nm,the_tag, read_call, doEnd, rep_init, pd_init);
  if (P_OK == read_res_PCGEN_) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_NEXT_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd,  usercheck)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(&trep_PCGEN_, &tpd_PCGEN_, tpd_PCGEN_.errCode, fn_nm,the_tag, read_call, doEnd, rep_init, pd_init);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_LAST(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, doEnd, xmlwrite_call)
do {
  PCGEN_UNION_READ_LONGEST_FIELD_SETUP(&trep_PCGEN_, &tpd_PCGEN_, tpd_PCGEN_.errCode, fn_nm,the_tag, read_call, doEnd, rep_init, pd_init);
  if (P_OK ==  read_res_PCGEN_) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, P_ERR);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* always falls through */
#define PCGEN_UNION_READ_LONGEST_LAST_CHECK(fn_nm, the_tag_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, xmlwrite_call, doEnd, usercheck)
do {
  PCGEN_UNION_READ_FIELD_LONGEST_SETUP(&trep_PCGEN_, &tpd_PCGEN_, tpd_PCGEN_.errCode, fn_nm,the_tag, read_call, doEnd);
  if ((P_OK == read_res_PCGEN_) && (!P_Test_SemCheck(m->compoundLevel) || (usercheck))) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  PDCI_UNION_ARM_FAILED(fn_nm, the_tag_nm, xmlwrite_call, read_res_PCGEN_);
  if (P_ERR == P_io_restore(pads)) {
    PDCI_report_err(pads, P_LEV_FATAL, 0, P_RESTORE_ERR, fn_nm, 0);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  trep_PCGEN_.tag = the_tag;
  tpd_PCGEN_.tag = the_tag;
  PD_COMMON_INIT_NO_ERR(&(tpd_PCGEN_.val.the_tag));
  tpd_PCGEN_.val.the_tag.loc.b = start_pos_PCGEN_;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_LONGEST_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_FIRST_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_LONGEST_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_FIRST_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
  PCGEN_UNION_READ_LONGEST_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_NEXT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  rep_init(pads, &trep_PCGEN_);
  pd_init(pads, &tpd_PCGEN_);
  tpd_PCGEN_.errCode = P_NO_ERR;
  PCGEN_UNION_READ_LONGEST_MAN_STAT_PRE(fn_nm, the_tag, rep_init, pd_init);
} while (0)
/* END_MACRO */

/* not sure that the init calls are needed */
#define PCGEN_UNION_READ_LONGEST_MAN_NEXT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init) 
do {
  rep_init(pads, &trep_PCGEN_);
  pd_init(pads, &tpd_PCGEN_);
  tpd_PCGEN_.errCode = P_NO_ERR;
  PCGEN_UNION_READ_LONGEST_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_init, pd_init);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_STAT_POST(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup)
do {
  PDCI_UNION_LONGEST_READ_CHECK_LONGEST_STAT;
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_POST(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup)
do {
  PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_STAT_POST_CHECK(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup, usercheck)
do {
  if (!P_Test_SemCheck(m->compoundLevel) || (usercheck)) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST_STAT;
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_MAN_POST_CHECK(fn_nm, rep_copy, rep_cleanup, pd_copy, pd_cleanup, usercheck)
do {
  if (!P_Test_SemCheck(m->compoundLevel) || (usercheck)) {
    PDCI_UNION_LONGEST_READ_CHECK_LONGEST(rep_copy, pd_copy);
  }
  rep_cleanup (pads, &trep_PCGEN_);
  pd_cleanup  (pads, &tpd_PCGEN_);
} while (0)
/* END_MACRO */

/* pd->loc already set by CHECK_LONGEST macros */
#define PCGEN_UNION_READ_LONGEST_WHERE_CHECK(fn_nm, usercheck, isOpt)
do {
    if (P_Test_SemCheck(m->compoundLevel) && (!(usercheck))) {
      if (isOpt) {
        PDCI_CONSTRAINT_ERR_LOC_ALREADY_SET(fn_nm, P_USER_CONSTRAINT_VIOLATION, "Popt specification violation");
      } else {
        PDCI_CONSTRAINT_ERR_LOC_ALREADY_SET(fn_nm, P_USER_CONSTRAINT_VIOLATION, "Pwhere clause violation");
      }
    }
} while (0)
/* END_MACRO */

#define PDCI_UNION_LONGEST_READ_WHERE_END_CHECK(fn_nm, usercheck, isOpt)
    PCGEN_UNION_READ_LONGEST_WHERE_CHECK(fn_nm, usercheck, isOpt)
/* END_MACRO */

#define PCGEN_UNION_READ_LONGEST_CHECK_FAILED(fn_nm, nm, err_tag)
do {
  if (longest_PCGEN_ == -1) {
    (pd->nerr)++;
    pd->errCode = P_UNION_MATCH_ERR;
    pd->loc.b = start_pos_PCGEN_;
    PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
    PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, "Failed to match any branch of union " nm);
    rep->tag = err_tag;
    pd->tag = err_tag;
    P_PS_setPanic(pd);
    goto final_check;
  }
  if (P_ERR == PDCI_io_forward(pads, longest_PCGEN_)) {
    PDCI_READFN_RET_ERRCODE_FATAL(PDCI_MacroArg2String(fn_name), m->compoundLevel, "IO_forward error", P_FORWARD_ERR);
  }
} while (0)
/* END_MACRO */

#define PDCI_SWUNION_READ_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
do {
  if ((rep->tag) != the_tag) {
    PDCI_SAVE_PD_ID(pd_id_tmp_PCGEN_, pd);
    rep_cleanup(pads, rep);
    pd_cleanup(pads, pd);
    rep_init(pads, rep);
    pd_init(pads, pd);
    PDCI_REST_PD_ID(pd_id_tmp_PCGEN_, pd);
  }
} while (0)
/* END_MACRO */

/* falls through on success, goto branches_done on failure */
#define PCGEN_SWUNION_READ_STAT(fn_nm, the_tag, err_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, doEnd)
do {
  Perror_t read_res_PCGEN_;
  PDCI_READFN_BEGINLOC(pads, pd->loc);
  rep->tag = the_tag;
  pd->tag  = the_tag;
  read_res_PCGEN_ = read_call;
  PDCI_READFN_ENDLOC##doEnd(pd->loc);
  if (P_ERR == read_res_PCGEN_) {
    pd->nerr = 1;
    pd->errCode = P_UNION_MATCH_ERR;
    pd->loc = pd->val.the_tag.loc;
    PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, "Failed to match branch " PDCI_MacroArg2String(the_tag));
    goto branches_done;
  }
  pd->errCode = P_NO_ERR;
} while (0)
/* END_MACRO */

/* falls through on success, goto branches_done on failure */
#define PCGEN_SWUNION_READ(fn_nm, the_tag, err_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, doEnd)
do {
  PDCI_SWUNION_READ_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy);
  PCGEN_SWUNION_READ_STAT(fn_nm, the_tag, err_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy, read_call, doEnd);
} while (0)
/* END_MACRO */

#define PCGEN_SWUNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
do {
  PDCI_READFN_BEGINLOC(pads, pd->loc);
  pd->errCode = P_NO_ERR;
  rep->tag = the_tag;
  pd->tag = the_tag;
  PD_COMMON_INIT_NO_ERR(&(pd->val.the_tag));
  PDCI_READFN_BEGINLOC(pads, pd->val.the_tag.loc);
} while (0)
/* END_MACRO */

#define PCGEN_SWUNION_READ_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
  PCGEN_SWUNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
/* END_MACRO */

#define PCGEN_SWUNION_READ_MAN_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
do {
  PDCI_SWUNION_READ_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy);
  PCGEN_SWUNION_READ_MAN_STAT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy);
} while (0)
/* END_MACRO */

#define PCGEN_SWUNION_READ_MAN_VIRT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy)
do {
  PDCI_SWUNION_READ_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy);
  PCGEN_SWUNION_READ_MAN_STAT_VIRT_PRE(fn_nm, the_tag, rep_cleanup, rep_init, rep_copy, pd_cleanup, pd_init, pd_copy);
} while (0)
/* END_MACRO */

/* falls through on success, goto branches_done on failure */
#define PCGEN_SWUNION_READ_POST_CHECK(fn_nm, the_tag, err_tag, usercheck)
do {
  if (P_Test_SemCheck(m->compoundLevel) && (!(usercheck))) {
    PDCI_ELT_CONSTRAINT_ERR(fn_nm, pd->val.the_tag, P_USER_CONSTRAINT_VIOLATION, P_UNION_MATCH_ERR, "User constraint on branch " PDCI_MacroArg2String(the_tag) " violated",);
    goto branches_done;
  }
} while (0)
/* END_MACRO */

/* always does goto branches_done */
#define PCGEN_SWUNION_READ_FAILED(fn_nm, nm, err_tag)
do {
  (pd->nerr)++;
  pd->errCode = P_UNION_MATCH_ERR;
  PDCI_READFN_GETLOC_SPAN0(pads, pd->loc);
  PDCI_report_err(pads, P_LEV_WARN, &(pd->loc), pd->errCode, fn_nm, "Switch value failed to match any branch of switched union " nm);
  rep->tag = err_tag;
  pd->tag = err_tag;
  goto branches_done;
} while (0)
/* END_MACRO */

#define PCGEN_SWUNION_READ_WHERE_CHECK(fn_nm, usercheck, isOpt)
do {
    if (pd->nerr == 0 && P_Test_SemCheck(m->compoundLevel) && (!(usercheck))) {
      PDCI_CONSTRAINT_ERR(fn_nm, P_USER_CONSTRAINT_VIOLATION, "Pwhere clause violation");
    }
} while (0)
/* END_MACRO */

#define PCGEN_SWUNION_READ_WHERE_END_CHECK(fn_nm, usercheck, isOpt)
do {
    PDCI_READFN_ENDLOC(pads, pd->loc);
    PCGEN_SWUNION_READ_WHERE_CHECK(fn_nm, usercheck, isOpt);
} while (0)
/* END_MACRO */

#define PDCI_UNION_COPY_PRE(fn_nm, cleanup_fn, src, dst)
do {
  if (src->tag != dst->tag) {
    cleanup_fn(pads, dst);
    memset((void*)(&(dst->val)), 0, sizeof(dst->val));
  }
  memcpy((void*)(dst), (void*)(src), sizeof(*dst) - sizeof(dst->val));
} while (0)
/* END_MACRO */

#define PCGEN_UNION_COPY_PRE(fn_nm, rep_cleanup)
  PDCI_UNION_COPY_PRE(fn_nm, rep_cleanup, rep_src, rep_dst)
/* END_MACRO */

#define PCGEN_UNION_PD_COPY_PRE(fn_nm, pd_cleanup)
  PDCI_UNION_COPY_PRE(fn_nm, pd_cleanup, pd_src, pd_dst)
/* END_MACRO */

/* the ARRAY_COPY macros should bracketed by
       Puint32 nerr_PCGEN_ = 0;
       ...
       return (nerr_PCGEN_ == 0) ? P_OK : P_ERR;
 */

#define PCGEN_ARRAY_COPY_AR_STAT_ELT_STAT(fn_nm, src, dst)
do {
  memcpy((void*)dst, (void*)src, sizeof(*dst));
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_COPY_AR_DYN_ELT_STAT(fn_nm, src, dst)
do {
  memcpy((void*)dst, (void*)src, sizeof(*dst) - (2*sizeof(void*)));
  RBuf_CPY_SRC2DEST(src->_internal, dst->_internal, dst->elts, src->length * sizeof(src->elts[0]), P_rmm_nozero (pads));
} while (0);
/* END_MACRO */

#define PCGEN_ARRAY_COPY_AR_STAT_ELT_DYN(fn_nm, src, dst, elt_copy_fn, elt_cleanup_fn)
do {
  XXX TODO;
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_COPY_AR_DYN_ELT_DYN(fn_nm, src, dst, elt_copy_fn, elt_cleanup_fn)
do {
  Puint32 i_PCGEN_;
  /* if source is empty, try to clean up destination. */
  if (src->length == 0) {
    if (dst->length) {
      for (i_PCGEN_ = 0; i_PCGEN_ < dst->length; i_PCGEN_++) {
	elt_cleanup_fn(pads, &(dst->elts[i_PCGEN_]));
      }
    }
    /* XXX: What is this code doing? -YHM 
       It seems to be copying the src array rep. struct to dst, 
       minus the last two fields, pointers "elts" and "_internal".  
       However, given the fixed structure of array reps, why not just
       do dst->length = src->length?
    */
    memcpy((void*)dst, (void*)src, sizeof(*dst) - (2*sizeof(void*)));
    return P_OK;
  }
  /* Ensure dst buffer is allocated */
  if (!(dst->_internal) && !(dst->_internal = RMM_new_rbuf(P_rmm_zero(pads)))) {
    PDCI_report_err(pads, P_LEV_FATAL, 0 ,P_ALLOC_ERR, fn_nm, 0);
  }
  /* Ensure dst buffer has enough room. */
  if (src->length > dst->length) {
    if (0 != RBuf_RESERVE(dst->_internal, dst->elts, dst->elts[0], src->length)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_ALLOC_ERR, fn_nm, 0);
    }
    /* memset((void*)(&(dst->elts[dst->length])), 0, (src->length - dst->length)*sizeof(dst->elts[0])); */
  }
  /* leave extra elements in place for re-use by future array elts
     else if (src->length < dst->length) {
       for (i_PCGEN_ = src->length; i_PCGEN_ < dst->length; i_PCGEN_++) {
       elt_cleanup_fn(pads, &(dst->elts[i_PCGEN_]));
      }
  } */
  for (i_PCGEN_ = 0; i_PCGEN_ < src->length; i_PCGEN_++) {
    if (P_ERR == elt_copy_fn(pads, &(dst->elts[i_PCGEN_]), &(src->elts[i_PCGEN_]))) 
      nerr_PCGEN_++;
  }
  memcpy((void*)dst, (void*)src, sizeof(*dst) - (2*sizeof(void*)));
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLEANUP_AR_STAT_ELT_STAT(fn_nm, a)
do { } while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_STAT(fn_nm, a)
do {
  if (a->_internal) {
    if (0 != RMM_free_rbuf(a->_internal)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_ALLOC_ERR, fn_nm, "Couldn\'t free growable buffer");
    }
    a->_internal = 0;
  }
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLEANUP_AR_STAT_ELT_DYN(fn_nm, a, elt_cleanup_fn)
do {
  Puint32 i_PCGEN_;
  for (i_PCGEN_ = 0; i_PCGEN_ < a->length; i_PCGEN_++) {
    if (P_ERR == elt_cleanup_fn(pads, &(a->elts[i_PCGEN_]))) nerr_PCGEN_++;
  }
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLEANUP_AR_DYN_ELT_DYN(fn_nm, a, elt_cleanup_fn)
do {
  Puint32 i_PCGEN_;
  for (i_PCGEN_ = 0; i_PCGEN_ < a->length; i_PCGEN_++) {
    if (P_ERR == elt_cleanup_fn(pads, &(a->elts[i_PCGEN_]))) nerr_PCGEN_++;
  }
  if (a->_internal) {
    if (0 != RMM_free_rbuf(a->_internal)) {
      PDCI_report_err(pads, P_LEV_FATAL, 0, P_ALLOC_ERR, fn_nm, "Couldn\'t free growable buffer");
    }
    a->_internal = 0;
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_ACC_REP_NOVALS()
do {
  if (dtsize(acc->nerr.dict) == 0) {
    sfprintf(outstr, "(No %s values.)", what);
    sfstrclose(tmpstr);
    return P_OK;
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_ACC_REP_NOVALS()
do {
  if (dtsize(acc->tag.dict) == 0) {
    sfprintf(outstr, "(No %s values.)", what);
    sfstrclose(tmpstr);
    return P_OK;
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_ACC_XML_REP_NOVALS(endtag)
do {
  if (dtsize(acc->tag.dict) == 0) {
    nst--;
    PDCI_indent (outstr,nst);
    sfprintf (outstr,"</%s>\n",endtag);
    return P_OK;
  }
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_ACC_REP_NOVALS()
do {
  int dtsz_PCGEN_ = dtsize(acc->length.dict);
  if (dtsz_PCGEN_ == 0 && 0 == acc->length.bad) {
    sfprintf(outstr, "(No %s values.)", what);
    sfstrclose(tmpstr);
    return P_OK;
  }
  if (dtsz_PCGEN_ == 1) {
    Puint32_dt_key_t   lookup_key;
    lookup_key.val = 0;
    lookup_key.cnt = 0;
    if (dtmatch(acc->length.dict, &lookup_key)) {
      sfprintf(outstr, "(No element values accumulated; all arrays had zero length.)");
      sfstrclose(tmpstr);
      return P_OK;
    }
  }
} while (0)
/* END_MACRO */

#define PCGEN_ENUM_ACC_REP2IO(default_what, int_acc_call)
do {
  if (!what) {
    what = default_what;
  }
  return int_acc_call;
} while (0)
/* END_MACRO */

#define PCGEN_TYPEDEF_ACC_REP2IO(default_what, basety_nm, base_acc_call)
do {
  Perror_t res_PCGEN_;
  Sfio_t *tmpstr_PCGEN_;
  if (!(tmpstr_PCGEN_ = sfstropen())) {
    return P_ERR;
  }
  if (!what) {
    sfprintf (tmpstr_PCGEN_, "%s [--> %s]", default_what, basety_nm);
    what = PDCI_sfstr_use(tmpstr_PCGEN_);
  } else {
    sfprintf (tmpstr_PCGEN_, "%s [%s --> %s]", what, default_what, basety_nm);
    what = PDCI_sfstr_use(tmpstr_PCGEN_);
  }
  res_PCGEN_ = base_acc_call;
  sfstrclose(tmpstr_PCGEN_);
  return res_PCGEN_;
} while (0)
/* END_MACRO */

/* function body for a write2io function that has params pads, io, pd, rep */
/* always precede with decls for buf, buf_len, and buf_full and always follow with 'return -1' */
#define PCGEN_WRITE2IO_USE_WRITE2BUF(fn_nm, write2buf_call)
  int set_buf_PCGEN_;
  ssize_t length_PCGEN_;
  PDCI_IODISC_2P_CHECKS_RET_SSIZE(fn_nm, io, rep);
  buf_len = pads->outbuf_res;
  while (1) {
    set_buf_PCGEN_  = 0;
    buf_full = 0;
    buf = PDCI_io_write_start(pads, io, &buf_len, &set_buf_PCGEN_, fn_nm);
    if (!buf)  {
      /* Don't have to abort because start failed. */
      return -1;
    }
    length_PCGEN_ = write2buf_call;
    if (buf_full)  {
      /* Try again with a bigger buffer */
      PDCI_io_write_abort(pads, io, buf, set_buf_PCGEN_, fn_nm);
      buf_len*=2;
      continue;
    }
    break;
  }
  if (length_PCGEN_>=0) {
    return PDCI_io_write_commit(pads, io, buf, set_buf_PCGEN_, length_PCGEN_, fn_nm);
  }
  PDCI_io_write_abort(pads, io, buf, set_buf_PCGEN_, fn_nm)
/* END_MACRO */

#define PCGEN_TLEN_BUF_UPDATES()
do {
  if (tlen_PCGEN_<0) {
    return -1;
  }
  length_PCGEN_      += tlen_PCGEN_;
  buf_cursor_PCGEN_  += tlen_PCGEN_;
  buf_len            -= tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PCGEN_FINAL_TLEN_BUF_UPDATES()
do {
  if (tlen_PCGEN_<0) {
    return -1;
  }
  length_PCGEN_ += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PCGEN_TLEN_IO_UPDATES()
do {
  if (tlen_PCGEN_<0) {
    return -1;
  }
  length_PCGEN_      += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PCGEN_FINAL_TLEN_IO_UPDATES() 
do {
  if (tlen_PCGEN_<0) {
    return -1;
  }
  length_PCGEN_ += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PDCI_TMP4_TLEN_UPDATES()
do {
  if (tlen_PCGEN_ <= 0) {
    return -1;
  }
  if (tlen_PCGEN_ > buf_len) {
    (*buf_full) = 1;
    return -1;
  }
  memcpy(buf_cursor_PCGEN_, PDCI_sfstr_use(pads->tmp4), tlen_PCGEN_);
  length_PCGEN_     += tlen_PCGEN_;
  buf_cursor_PCGEN_ += tlen_PCGEN_;
  buf_len    -= tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PDCI_TMP4_TLEN_IO_UPDATES()
do {
  if (tlen_PCGEN_ <= 0) {
    return -1;
  }
/*  if (tlen_PCGEN_ > buf_len) { (*buf_full) = 1; return -1; } */
/*  memcpy(buf_cursor_PCGEN_, PDCI_sfstr_use(pads->tmp4), tlen_PCGEN_); */
  sfprintf(io, PDCI_sfstr_use(pads->tmp4), tlen_PCGEN_); 
  length_PCGEN_     += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PDCI_FINAL_TMP4_TLEN_UPDATES()
do {
  if (tlen_PCGEN_ <= 0) {
    return -1;
  }
  if (tlen_PCGEN_ > buf_len) {
    (*buf_full) = 1;
    return -1;
  }
  memcpy(buf_cursor_PCGEN_, PDCI_sfstr_use(pads->tmp4), tlen_PCGEN_);
  length_PCGEN_ += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PDCI_FINAL_TMP4_TLEN_IO_UPDATES()
do {
  if (tlen_PCGEN_ <= 0) {
    return -1;
  }
  sfprintf(io, PDCI_sfstr_use(pads->tmp4), tlen_PCGEN_);
  length_PCGEN_ += tlen_PCGEN_;
} while (0)
/* END_MACRO */

#define PCGEN_TAG_OPEN_XML_BUF_OUT(def_tag)
do {
  indent = (indent > 128) ? 128 : indent;
  if (!_tag) { _tag = def_tag; }
  PDCI_sfstr_seek2zero(pads->tmp4);
  tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s>\n", indent, PDCI_spaces, _tag);
  PDCI_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_TAG_CLOSE_XML_BUF_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
  tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s</%s>\n", indent, PDCI_spaces, _tag);
  PDCI_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_TAG_OPEN_XML_IO_OUT(def_tag)
do {
  indent = (indent > 128) ? 128 : indent;
  if (!_tag) { _tag = def_tag; }
  PDCI_sfstr_seek2zero(pads->tmp4);
  tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s>\n", indent, PDCI_spaces, _tag);
  PDCI_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_TAG_CLOSE_XML_IO_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
  tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s</%s>\n", indent, PDCI_spaces, _tag);
  PDCI_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */


#define PCGEN_ARRAY_OPEN_XML_BUF_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_OPEN_XML_IO_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLOSE_XML_BUF_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_CLOSE_XML_IO_OUT()
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
} while (0)
/* END_MACRO */

#define PCGEN_XML_VALUE_BUF_OUT(ltag, val)
do{
    indent = (indent > 126) ? 128 : indent + 2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s>%d</%s>\n", indent, PDCI_spaces, ltag, val, ltag);
    PDCI_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_XML_VALUE_IO_OUT(ltag, val)
do{
    indent = (indent > 126) ? 128 : indent + 2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s>%d</%s>\n", indent, PDCI_spaces, ltag, val, ltag);
    PDCI_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */

#define PDCI_UNION_TAG_XML_BUF_OUT(tag)
do {
  int tag_indent_PCGEN_ = (indent > 126) ? 128 : indent+2;
  PDCI_sfstr_seek2zero(pads->tmp4);
  tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<tag>%s</tag>\n", tag_indent_PCGEN_, PDCI_spaces, tag);
  PDCI_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PSTATE_NERR_ERRCODE_FMT "<pstate>%s</pstate><nerr>%I4u</nerr><errCode>%s</errCode>"
#define LOC_FMT "<loc><b><num>%lld</num><byte>%lld</byte></b><e><num>%lld</num><byte>%lld</byte></e></loc>"

#define PCGEN_ENUM_XML_BUF_OUT(def_tag, rep2str_fn)
do {
  if (!_tag) { _tag = def_tag; }
  indent = ((indent) > 128) ? 128 : indent;
  PDCI_sfstr_seek2zero(pads->tmp4);
  if ((pd)->errCode == P_NO_ERR) { /* no error */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><val>%s</val></%s>\n", indent, PDCI_spaces, _tag, rep2str_fn(*rep), _tag);
  } else if ((pd)->errCode < 100) { /* error, no location */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><pd>" PSTATE_NERR_ERRCODE_FMT "</pd></%s>\n",
		   indent, 
		   PDCI_spaces, 
		   _tag, 
		   P_pstate2str((pd)->pstate), 
		   (pd)->nerr, 
                   P_errCode2str((pd)->errCode), 
                   _tag);
  } else { /* error, location */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "</pd></%s>\n",
		    indent, 
		    PDCI_spaces, _tag, 
		    P_pstate2str((pd)->pstate), 
		    (pd)->nerr, 
		    P_errCode2str((pd)->errCode),
		    (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte, 
		    (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte, 
		    _tag);
  }
  PDCI_FINAL_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_ENUM_XML_IO_OUT(def_tag, rep2str_fn)
do {
  if (!_tag) { _tag = def_tag; }
  indent = ((indent) > 128) ? 128 : indent;
  PDCI_sfstr_seek2zero(pads->tmp4);
  if ((pd)->errCode == P_NO_ERR) { /* no error */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><val>%s</val></%s>\n", indent, PDCI_spaces, _tag, rep2str_fn(*rep), _tag);
  } else if ((pd)->errCode < 100) { /* error, no location */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><pd>" PSTATE_NERR_ERRCODE_FMT "</pd></%s>\n",
		   indent, 
		   PDCI_spaces, 
		   _tag, 
		   P_pstate2str((pd)->pstate), 
		   (pd)->nerr, 
                   P_errCode2str((pd)->errCode), 
                   _tag);
  } else { /* error, location */
    tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<%s><pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "</pd></%s>\n",
		    indent, 
		    PDCI_spaces, _tag, 
		    P_pstate2str((pd)->pstate), 
		    (pd)->nerr, 
		    P_errCode2str((pd)->errCode),
		    (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte, 
		    (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte, 
		    _tag);
  }
  PDCI_FINAL_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_PD_XML_BUF_OUT()
do {
  if ((pd)->errCode != P_NO_ERR) {
    int pd_indent_PCGEN_ = ((indent) > 126) ? 128 : (indent)+2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    if ((pd)->errCode < 100) { /* no location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT "</pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
		      P_pstate2str((pd)->pstate), 
		      (pd)->nerr,
		      P_errCode2str((pd)->errCode));
    } else { /* location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "</pd>\n",
		      pd_indent_PCGEN_, 
                      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode),
		      (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte, 
 		      (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte);
    }
    PDCI_TMP4_TLEN_UPDATES();
  }
} while (0)
/* END_MACRO */

#define PCGEN_STRUCT_PD_XML_IO_OUT()
do {
  if ((pd)->errCode != P_NO_ERR) {
    int pd_indent_PCGEN_ = ((indent) > 126) ? 128 : (indent)+2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    if ((pd)->errCode < 100) { /* no location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT "</pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
		      P_pstate2str((pd)->pstate), 
		      (pd)->nerr,
		      P_errCode2str((pd)->errCode));
    } else { /* location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "</pd>\n",
		      pd_indent_PCGEN_, 
                      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode),
		      (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte, 
 		      (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte);
    }
    PDCI_TMP4_TLEN_IO_UPDATES();
  }
} while (0)
/* END_MACRO */

#define PCGEN_UNION_PD_XML_BUF_OUT() PCGEN_STRUCT_PD_XML_BUF_OUT()
/* END_MACRO */

#define PCGEN_UNION_PD_XML_IO_OUT() PCGEN_STRUCT_PD_XML_IO_OUT()
/* END_MACRO */

#define PCGEN_ARRAY_PD_XML_BUF_OUT()
do {
  if ((pd)->errCode != P_NO_ERR) {
    int pd_indent_PCGEN_ = ((indent) > 126) ? 128 : (indent)+2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    if ((pd)->errCode < 100) { /* no location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT "<neerr>%lu</neerr><firstError>%lu</firstError></pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode), 
                      (pd)->neerr, 
                      (pd)->firstError);
    } else { /* location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "<neerr>%lu</neerr><firstError>%lu</firstError></pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode),
		      (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte,
		      (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte,
		      (pd)->neerr, 
                      (pd)->firstError);
    }
    PDCI_TMP4_TLEN_UPDATES();
  }
} while (0)
/* END_MACRO */

#define PCGEN_ARRAY_PD_XML_IO_OUT()
do {
  if ((pd)->errCode != P_NO_ERR) {
    int pd_indent_PCGEN_ = ((indent) > 126) ? 128 : (indent)+2;
    PDCI_sfstr_seek2zero(pads->tmp4);
    if ((pd)->errCode < 100) { /* no location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT "<neerr>%lu</neerr><firstError>%lu</firstError></pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode), 
                      (pd)->neerr, 
                      (pd)->firstError);
    } else { /* location */
      tlen_PCGEN_ = sfprintf(pads->tmp4, "%.*s<pd>" PSTATE_NERR_ERRCODE_FMT LOC_FMT "<neerr>%lu</neerr><firstError>%lu</firstError></pd>\n",
		      pd_indent_PCGEN_, 
		      PDCI_spaces, 
                      P_pstate2str((pd)->pstate), 
                      (pd)->nerr, 
                      P_errCode2str((pd)->errCode),
		      (long long)(pd)->loc.b.num, (long long)(pd)->loc.b.byte,
		      (long long)(pd)->loc.e.num, (long long)(pd)->loc.e.byte,
		      (pd)->neerr, 
                      (pd)->firstError);
    }
    PDCI_TMP4_TLEN_IO_UPDATES();
  }
} while (0)
/* END_MACRO */

#define PCGEN_SOURCE_XML_BUF_OUT_BEGIN(schema_name)
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
    tlen_PCGEN_ = sfprintf(pads->tmp4, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<padsns:PSource xmlns:padsns=\"file:%s\">\n",
			   schema_name);
    indent += 2;
    PDCI_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_SOURCE_XML_IO_OUT_BEGIN(schema_name)
do {
  PDCI_sfstr_seek2zero(pads->tmp4);
    tlen_PCGEN_ = sfprintf(pads->tmp4, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<padsns:PSource xmlns:padsns=\"file:%s\">\n",
			   schema_name);
    indent += 2;
    PDCI_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_SOURCE_XML_BUF_OUT_END()
do {
  PDCI_sfstr_seek2zero(pads->tmp4); 
    tlen_PCGEN_ = sfprintf(pads->tmp4, "</padsns:PSource>\n");
    PDCI_FINAL_TMP4_TLEN_UPDATES();
} while (0)
/* END_MACRO */

#define PCGEN_SOURCE_XML_IO_OUT_END()
do {
  PDCI_sfstr_seek2zero(pads->tmp4); 
    tlen_PCGEN_ = sfprintf(pads->tmp4, "</padsns:PSource>\n");
    PDCI_FINAL_TMP4_TLEN_IO_UPDATES();
} while (0)
/* END_MACRO */

//  fnLookupAssign should be of the form:
//     fn = PDCI_GET_FMT_FN(pads, "ty1")
//  fnInvoke should be of the form:
//     P_invoke_format_fn(fn, pads, buf, buf_len, buf_full, requestedOut, delims, m, pd, rep [, typearg1 ... typeargN])

#define PCGEN_ENUM_FMT2BUF_FINAL_INIT(fnName)
 do { 
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  (*buf_full) = 0;
 } while (0)
/* END_MACRO */

#define PCGEN_TYPEDEF_FMT2BUF_FINAL_INIT(fnName)
do {
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  PDCI_DELIMS_CHECK_RET_SSIZE(fnName, delims);
  tdelim_PCGEN_ = delims;
  (*buf_full) = 0;
 } while (0)
/* END_MACRO */

#define PCGEN_STRUCT_FMT2BUF_FINAL_INIT(fnName) 
 do { 
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  PDCI_DELIMS_CHECK_RET_SSIZE(fnName, delims);
  tdelim_PCGEN_ = P_ADVANCE_DELIMS(delims);
  (*buf_full) = 0;
} while (0)
/* END_MACRO */

#define PCGEN_STANDARD_FMT2BUF_INIT(fnName, fnLookupAssign, fnInvoke)
do {
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  PDCI_STANDARD_FMT2BUF_INIT(m->compoundLevel, requestedOut);
  if ((fnLookupAssign)) {
    return fnInvoke;
  }
 } while (0)
/* END_MACRO */

#define PCGEN_ENUM_FMT2BUF_INIT(fnName, fnLookupAssign, fnInvoke)
do {
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  PDCI_STANDARD_FMT2BUF_INIT(*m, requestedOut);
  if ((fnLookupAssign)) {
    return fnInvoke;
  }
 } while (0)
/* END_MACRO */

#define PCGEN_POINTER_FMT2BUF_INIT(fnName, fnLookupAssign, fnInvoke)
do {
  PDCI_IODISC_6P_CHECKS_RET_SSIZE(fnName, buf, buf_full, delims, m, pd, rep);
  PDCI_IODISC_1P_CHECKS_RET_SSIZE(fnName,*m);
  PDCI_STANDARD_FMT2BUF_INIT((*m)->compoundLevel, requestedOut);
  if ((fnLookupAssign)) {
    return fnInvoke;
  }
 } while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_TYPEDEF(fmtCall)
 do { 
      trequestedOut_PCGEN_ = 0;
      tlen_PCGEN_ = fmtCall;
      PCGEN_TLEN_BUF_UPDATES (); 
      if (trequestedOut_PCGEN_) { 
	*requestedOut = 1; 
      };
 } while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_ARRAY(fdName, fmtCall)
 do {
    const char * ttdelim_PCGEN_ = tdelim_PCGEN_;
    Pbase_pd pd_PCGEN_;
    pd_PCGEN_.errCode = P_NO_ERR;
    tdelim_PCGEN_  = P_ADVANCE_DELIMS(tdelim_PCGEN_);
    if (P_WriteMeta & m->compoundLevel) {
        tlen_PCGEN_ = Pa_uint32_write2buf(pads,buf_cursor_PCGEN_,buf_len,buf_full,&pd_PCGEN_, &rep->length); 
	PCGEN_TLEN_BUF_UPDATES (); 
        tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,delims[0]);
        PCGEN_TLEN_BUF_UPDATES ();
	*requestedOut = 1; 
      };
    for (i = 0; i<rep->length; i++){
       tlen_PCGEN_ = fmtCall;
       PCGEN_TLEN_BUF_UPDATES (); 
       if (trequestedOut_PCGEN_){
	 *requestedOut = 1;
	 tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,ttdelim_PCGEN_[0]);
	 PCGEN_TLEN_BUF_UPDATES ();
       };
    };
    *requestedOut = 1;

 } while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_STRUCT_FIELD(fdName, fmtCall)
 do { 
      trequestedOut_PCGEN_ = 0;
      tlen_PCGEN_ = fmtCall;   /* uses tdelim_PCGEN_, sets trequesetedOut */
      PCGEN_TLEN_BUF_UPDATES (); 
      if (trequestedOut_PCGEN_) { 
	*requestedOut = 1; 
        tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,delims[0]);
        PCGEN_TLEN_BUF_UPDATES ();
      };
 } while (0)
/* END_MACRO */


/*  If last field didn't request output, we need to unwrite the previous separator as well as the last one. */
#define PCGEN_FMT2BUF_FIX_LAST()
do{
  /*    if (!trequestedOut_PCGEN_ && length_PCGEN_ > 0 ) {
         length_PCGEN_--;
         buf_cursor_PCGEN_--;
         buf_len++;
      };
  */
    if (length_PCGEN_ > 0) {
      length_PCGEN_--;
      buf_cursor_PCGEN_--;
      buf_len++;
    }
} while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_UNION(fdName, fmtCall, tagStr)
 do { 
      trequestedOut_PCGEN_ = 0;
      if (P_WriteMeta & m->compoundLevel) {
        tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,tagStr);
	PCGEN_TLEN_BUF_UPDATES (); 
        tlen_PCGEN_ = Pchar_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,delims[0]);
        PCGEN_TLEN_BUF_UPDATES ();
	*requestedOut = 1; 
      };
      tlen_PCGEN_ = fmtCall;
      PCGEN_TLEN_BUF_UPDATES (); 
      if (trequestedOut_PCGEN_) { 
	*requestedOut = 1; 
      };
 } while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_ENUM(fdName, enumStr)
 do { 
      if (P_Write & (*m)){
         tlen_PCGEN_ = Pcstr_lit_write2buf (pads,buf_cursor_PCGEN_,buf_len,buf_full,enumStr);
	 PCGEN_TLEN_BUF_UPDATES (); 
	 *requestedOut = 1;
         tdelim_PCGEN_ = 0;
	 trequestedOut_PCGEN_ = 0;
      };
 } while (0)
/* END_MACRO */

#define PCGEN_FMT2BUF_RECORD(fname)
do {
    tlen_PCGEN_ = PDCI_io_rec_fmt2buf(pads, buf_cursor_PCGEN_, buf_len, buf_full, Pcharset_ASCII, (fname));
    PCGEN_FINAL_TLEN_BUF_UPDATES ();
} while (0)
/* END_MACRO */

/************
 * 
 *
 ***********/
#define PCGEN_ARRAY_TEST_MIN_GT_MAX(ty)
do{
    if (P_Test_SynCheck (m->compoundLevel)&&(min>max)) 
      {
        if (!(pd->nerr)) 
          {
            (pd->nerr)++;
            pd->errCode = P_ARRAY_MIN_BIGGER_THAN_MAX_ERR;
            PDCI_READFN_ENDLOC_MINUS1(pads, tloc);
            PDCI_report_err (pads,P_LEV_WARN,&tloc,pd->errCode,(#ty "_read"),
			     "Mininum value for the size of array " #ty "(%d) is greater than its maximum size (%d)",min,max);
          }
        else
          {
            (pd->nerr)++;
          }
        if (P_spec_level (pads)) 
          return P_READ_ERR;
      }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_NEW_RBUF_ZERO(ty,vIN)
do{
    if (0==((vIN)->_internal)) 
      {
        (vIN)->_internal = RMM_new_rbuf(P_rmm_zero (pads));
        if (0==((vIN)->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_read","");
          }
      }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_NEW_RBUF_NOZERO(ty,vIN)
do{
    if (0==((vIN)->_internal)) 
      {
        (vIN)->_internal = RMM_new_rbuf(P_rmm_nozero (pads));
        if (0==((vIN)->_internal)) 
          {
            PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_read","");
          }
      }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_PANIC()
do{
  if (P_PS_isPanic (pd)){
    goto do_final_checks;
  }      
}while(0)
/* END_MACRO */   

#define PCGEN_ARRAY_TEST_FC_REACHED_END()
do{
  if (P_io_at_eof (pads)|| P_io_at_eor (pads)){
    goto do_final_checks;
  }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_MATCH_TERM(funIn,termIN,eat_fIN,panicIN)
do{
  if (P_OK== (funIN) (pads,(termIN),(eat_fIN),(panicIN),&offset))
    {
      foundTerm = 1;
      goto do_final_checks;
    } 
}while(0)
/* END_MACRO */


#define PCGEN_ARRAY_TEST_FC_REACHED_MAX(maxIN)
do{
  if((rep->length)==(maxIN)){
    goto do_final_checks;
  }
  if((rep->length)>(maxIN))
    PDCI_report_err(...);
}while(0)
/* END_MACRO */


#define PCGEN_ARRAY_RESERVE_SPACE(ty,elRepTy,elPdTy,hintIN)
do{
  if (0 != RBuf_RESERVE_HINT(rep->_internal, rep->elts, elRepTy, rep->length + 1, hintIN)) 
    {
      PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_read",0);
    }
  if (0 != RBuf_RESERVE_HINT(pd->_internal, pd->elts, elPdTy, rep->length + 1, hintIN)) 
    {
      PDCI_report_err (pads,P_LEV_FATAL,0,P_ALLOC_ERR,#ty "_read",0);
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_GET_BEGIN_LOC()
do{
  PDCI_READFN_BEGINLOC(pads, beginLoc);
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE(bIN,eIN)
do{
  PDCI_ALWAYS_BEGINLOC(pads,(eIN));
  if (P_POS_EQ ((bIN).b, (eIN).b)) 
    {
      /*  array termination from lack of progress */
      (rep->length) -= 1;
      goto do_final_checks;
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE2()
do{
  PCGEN_ARRAY_TEST_FC_SOURCE_ADVANCE(beginLoc,endLoc);
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_CHECKPOINT(ty)
do{
    /*(pads->inestlev)++;*/
  if (P_ERR==P_io_checkpoint (pads,1)) 
    {
      PDCI_report_err (pads,P_LEV_FATAL,0,P_CHKPOINT_ERR, #ty "_read",0);
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_READ_ELEM(readCallIN)
do{
  result = (readCallIN);
  (pd->numRead)++;
  (rep->length)++;
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_READ_ELEM_HD(readCallIN,haveDataIN)
do{
  result = (readCallIN);
  (pd->numRead)++;
  (rep->length)++;
  (haveDataIN) = 1; /* after the read, the rep and pd are valid.*/
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_REREAD_ELEM_BODY(readCallIN)
do{
    (readCallIN);
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_REREAD_ELEM_RET() P_READ_OK_DATA

#define PCGEN_ARRAY_RECORD_ERROR(errCodeIN,WHATFN,ERRMSG,...)
do{
  if (!(pd->nerr)) 
    {
      (pd->nerr)++;
      pd->errCode = (errCodeIN);
      PDCI_READFN_ENDLOC_MINUS1(pads, tloc);
      PDCI_report_err (pads,P_LEV_WARN,&tloc,pd->errCode,WHATFN,ERRMSG);
    }
  else
    {
      (pd->nerr)++;
    }
  if (P_spec_level (pads)) 
    return P_READ_ERR;
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_SET_PARTIAL()
do{
  P_PS_setPartial(pd);  
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_UNSET_PARTIAL()
do{
  P_PS_unsetPartial(pd);  
}while(0)
/* END_MACRO */


#define PCGEN_ARRAY_TEST_READ_ERR(addTest1IN, addTest2IN)
do{
  if (result==P_ERR && (addTest1IN) && (addTest2IN)) 
    {
      /*  in markErrorSs */
      if (P_Test_NotIgnore (m->compoundLevel)) 
	{
	  (pd->neerr)++;
	  if (!(pd->nerr)) 
	    {
	      (pd->nerr)++;
	      pd->errCode = P_ARRAY_ELEM_ERR;
	      PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
	      /*  Index of first element with an error */
	      pd->firstError = ((rep->length)-1);
	    }
	  if (P_spec_level (pads)) {
	    PCGEN_ARRAY_UNSET_PARTIAL ();
	    return P_READ_ERR;
	  }
	}
    }
  
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_PANIC_RECOVER1(pdIN,addTestIN,sepIN,termIN)
do{
  if (P_PS_isPanic (&(pdIN)) && (addTestIN)) 
    {
      size_t offset;
      /*  Try to recover to separator and/or terminator */
      if (P_OK==Pchar_lit_scan1 (pads,(sepIN),(termIN),1,1,&offset)) 
	{
	  /*  We recovered; restored invariant */
	}
      else
	{
	  /*  Recovery failed */
	  P_PS_setPanic (pd);
	  goto do_final_checks;
	}
  }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_FC_PANIC_RECOVER2(pdIN,addTestIN,sepIN,termIN)
do{
  if (P_PS_isPanic (&(pdIN)) && (addTestIN)) 
    {
      {
	int f_found;
	size_t offset;
	/*  Try to recover to separator and/or terminator */
	if (P_OK==Pchar_lit_scan2 (pads,(sepIN),(termIN),1,0,1,&f_found,&offset)) 
	  {
	    /*  We recovered; restored invariant */
	  }
	else
	  {
	    /*  Recovery failed */
	    P_PS_setPanic (pd);
	    goto do_final_checks;
	  }
      }
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_FC_SCAN_SEP_TERM(ty,funIn,sepIN,termIN,eat_fIN,eat_sIN,panicIN)
do{
  int sepFound;
  size_t offset;
  PDCI_READFN_BEGINLOC(pads, pd->loc);
  if (P_OK==(funIN) (pads,(sepIN),(termIN),(eat_fIN),(eat_sIN),(panicIN),&sepFound,&offset)) 
    {
      if (!sepFound) 
	{
	  foundTerm = 1;
	}
      if (P_Test_SynCheck (m->compoundLevel)) 
	{
	  if (sepFound && offset) 
	    {
	      if (!(pd->nerr)) 
		{
		  (pd->nerr)++;
		  pd->errCode = P_ARRAY_EXTRA_BEFORE_SEP;
		  PDCI_READFN_ENDLOC_MINUS2(pads, pd->loc);
		  PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read",0);
		}
	      else
		{
		  (pd->nerr)++;
		}
	      if (P_spec_level (pads)) 
		return P_READ_ERR;
	    }
	  else
	    {
	      if (!sepFound) 
		{
		  if (!(pd->nerr)) 
		    {
		      (pd->nerr)++;
		      pd->errCode = P_ARRAY_EXTRA_BEFORE_TERM;
		      PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
		      PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read",0);
		    }
		  else
		    {
		      (pd->nerr)++;
		    }

		  if (P_spec_level (pads)) 
		    return P_READ_ERR;
		}
	      goto do_final_checks;
	    }
	}
    }
  else
    {
      /*  Error reading separator */
      {
	if (!(pd->nerr)) 
	  {
	    (pd->nerr)++;
	    pd->errCode = P_ARRAY_SEP_ERR;
	    PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
	    PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read","Missing separator");
	  }
	else
	  {
	    (pd->nerr)++;
	  }
	if (P_spec_level (pads)) 
	  return P_READ_ERR;
	P_PS_setPanic (pd);
      }
      goto do_final_checks;
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_SCAN_SEP(ty,funIn,sepIN,eat_fIN,panicIN)
do{
  size_t offset;
  PDCI_READFN_BEGINLOC(pads, pd->loc);
  if (P_OK== (funIn) (pads,(sepIN),(eat_fIN),(panicIN),&offset)) 
    {
      if (P_Test_SynCheck (m->compoundLevel)) 
	{
	  if (offset) 
	    {
	      if (!(pd->nerr)) 
		{
		  (pd->nerr)++;
		  pd->errCode = P_ARRAY_EXTRA_BEFORE_SEP;
		  PDCI_READFN_ENDLOC_MINUS2(pads, pd->loc);
		  PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read",0);
		}
	      else
		{
		  (pd->nerr)++;
		}
	      if (P_spec_level (pads)) 
		return P_READ_ERR;
	    }
	}
    }
  else
    {
      /*  Error reading separator */
      {
	if (!(pd->nerr)) 
	  {
	    (pd->nerr)++;
	    pd->errCode = P_ARRAY_SEP_ERR;
	    PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
	    PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read","Missing separator");
	  }
	else
	  {
	    (pd->nerr)++;
	  }
	if (P_spec_level (pads)) 
	  return P_READ_ERR;
	P_PS_setPanic (pd);
      }
      goto do_final_checks;
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_TRAILING_JUNK(ty,funIN,termIN)
do{
  /* End of loop. Read trailing terminator if there was trailing junk */
    if ((!P_PS_isPanic (pd))&&(!foundTerm)) 
      {
        size_t offset;
        PDCI_READFN_BEGINLOC(pads, pd->loc);
        if (P_OK == funIN(pads,(termIN),0,0,&offset)) 
          {
            if (P_Test_SynCheck (m->compoundLevel)) 
              {
                {
                  if (!(pd->nerr)) 
                    {
                      (pd->nerr)++;
                      pd->errCode = P_ARRAY_EXTRA_BEFORE_TERM;
                      PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
                      PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read",0);
                    }
                  else
                    {
                      (pd->nerr)++;
                    }
                  if (P_spec_level (pads)) 
                    return P_READ_ERR;
                }
                foundTerm = 1;
              }
          }
        else
          {
            if (!(pd->nerr)) 
              {
                (pd->nerr)++;
                pd->errCode = P_ARRAY_TERM_ERR;
                PDCI_READFN_ENDLOC_MINUS1(pads, pd->loc);
                PDCI_report_err (pads,P_LEV_WARN,&(pd->loc),pd->errCode,#ty "_read","Missing terminator");
              }
            else
              {
                (pd->nerr)++;
              }
            if (P_spec_level (pads)) 
              return P_READ_ERR;
            P_PS_setPanic (pd);
          }
      }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_TEST_TRAILING_JUNK_C(ty,funIN,termIN) PCGEN_ARRAY_TEST_TRAILING_JUNK(ty,funIN,termIN)
#define PCGEN_ARRAY_TEST_TRAILING_JUNK_P(ty,funIN,termIN) PCGEN_ARRAY_TEST_TRAILING_JUNK(ty,funIN,termIN)

#define PCGEN_ARRAY_READ_EOR(ty)
do{
  /*  Read to EOR */
  Pbase_pd tpd;
  size_t bytes_skipped;
  PDCI_READFN_BEGINLOC(pads, tpd.loc);
  if (P_OK==P_io_next_rec (pads,&bytes_skipped)) 
    {
      if (bytes_skipped) 
	{
	  /*  in genReadEOR1 */
	  PDCI_READFN_ENDLOC_MINUS1(pads, tpd.loc);
	  if (!P_PS_isPanic (pd)) 
	    {
	      PDCI_report_err (pads,P_LEV_WARN,&(tpd.loc),P_EXTRA_BEFORE_EOR,"list_read","Unexpected data before EOR");
	      if (0==(pd->nerr)) 
		{
		  pd->errCode = P_EXTRA_BEFORE_EOR;
		  PDCI_READFN_ENDLOC_MINUS1(pads, tpd.loc);
		  pd->loc = (tpd.loc);
		}
	      (pd->nerr)+=1;
	    }
	  else
	    {
	      PDCI_READFN_ENDLOC_MINUS1(pads, tpd.loc);
	      PDCI_report_err (pads,P_LEV_INFO,&(tpd.loc),P_NO_ERR,#ty "_read","Resynching at EOR");
	    }
	  if (P_spec_level (pads)) 
	    return P_READ_ERR;
	}
      P_PS_unsetPanic (pd);
    }
  else
    {
      /*  in genReadEOR2 */
      P_PS_unsetPanic (pd);
      PDCI_READFN_ENDLOC_MINUS1(pads, tpd.loc);
      PDCI_report_err (pads,P_LEV_WARN,&(tpd.loc),P_AT_EOR,#ty "_read","Found EOF when searching for EOR");
      if (P_spec_level (pads)) 
	return P_READ_ERR;
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_CHK_ENOUGH_ELEMENTS(ty)
do{
  if ((!reachedLimit)&&((rep->length)<min)) 
    PCGEN_ARRAY_RECORD_ERROR(P_ARRAY_SIZE_ERR,#ty "_read","Read %d element(s) for array " #ty "; required %d",rep->length,min);
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_CFORALL_LOOP(indexIN,lowerIN,upperIN,bodyIN)
do{
  int indexIN;
  if (!((0<=(lowerIN))&&((upperIN)<(rep->length)))) 
    {
      violated = 1;
    }
  for (indexIN = 0; !violated && indexIN <= (upperIN); indexIN++)
    {
      if (!(bodyIN)) 
	{
	  violated = 1;
	}
    }
}while(0)
/* END_MACRO */

/* 
 * Must preceed this call with a phantom declaration of indexIN.
 */
#define PCGEN_ARRAY_CHK_FORALL_CONSTRAINT(ty,indexIN,lowerIN,upperIN,bodyIN)
do{
  int violated=0;
  {
    PCGEN_ARRAY_CFORALL_LOOP(indexIN,lowerIN,upperIN,bodyIN);
  }
  if (violated) 
    {
      PCGEN_ARRAY_RECORD_ERROR(P_ARRAY_USER_CONSTRAINT_ERR,#ty "_read","Pforall constraint for array " #ty " violated");
    }
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_STD_RETURN()
((pd->nerr)==0) ? P_OK : P_ERR
/* END_MACRO */

#define PCGEN_ARRAY_TEST_ALREADY_DONE()
do{
  if (!P_PS_isPartial(pd))
    return P_READ_ALREADY_DONE_ERR;
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_DO_FINAL_CHECKS()
do{
  goto do_final_checks;
}while(0)
/* END_MACRO */

#define PCGEN_ARRAY_RO_DECS()
  int result;
  Ploc_t beginLoc;
/* END_MACRO */

#define PCGEN_ARRAY_RO_DECS_SEP() 
  Ploc_t endLoc
/* END_MACRO */ 

#define PCGEN_ARRAY_LBL_FINAL_CHECKS()
 do_final_checks:
/* END_MACRO */

#define PCGEN_ARRAY_RET_ONGOING(keepEltIN)
((keepEltIN) ? P_READ_OK_DATA : P_READ_OK_NO_DATA)
/* END_MACRO */

#define PCGEN_ARRAY_RET_DONE(keepEltIN)
((keepEltIN) ? P_READ_OK_DATA : P_READ_OK_NO_DATA)
/* END_MACRO */



#define PCGEN_ARRAY_READ_ALL(allocCallIN,readCallIN,incIN,WHATFN)
do{
    allocCallIN;
    result = readCallIN;
    incIN;
}while(P_PS_isPartial(pd))
/* END_MACRO */

/* ********************************* BEGIN_TRAILER ******************************** */
#endif /* FOR_CKIT */
/* ********************************** END_MACROS ********************************** */
