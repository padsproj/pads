
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../../..; pwd)
endif

ifndef AST_ARCH
  export AST_ARCH=$(shell $(PADS_HOME)/ast-ast/bin/package.cvs)
endif

CURDIR := $(shell pwd)
ifneq ($(AST_ARCH),$(notdir $(CURDIR)))
include $(PADS_HOME)/mk/redirect.mk
else

 # The following rules are run from the arch directory

include $(PADS_HOME)/mk/rules.mk

VPATH = ..

HELPERS = myrand cvt_ebcdic_to_ascii cvt_ascii_to_ebcdic dttest

LIBTESTS_O = rwtest1 \
           recrwtest1 \
           re_scan_test \
           io_openclose_test \
           ebcdic_test \
           cobol_ebc_test \
           bcd_test \
           sb_test \
           ebc_fpoint_test \
           bcd_fpoint_test \
           adate_test \
           mk_ex_data_libtest2 \
           mk_ex_data_endian \
           mk_ex_data_ebcdic_test \
           mk_ex_data_ebc_test \
           mk_ex_data_bcd_test \
           mk_ex_data_sb_test \
           libtest1 \
           libtest2 \
           ebcdic_libtest4 \
           libtest4 \
           rbuftest1 \
           mk_ex_data_biglibtest1 \
           biglibtest1 \
           string_share_test \
           a_ip_test

LIBTESTS_D = $(LIBTESTS_O:%=%_d)
LIBTESTS = $(LIBTESTS_O) $(LIBTESTS_D) 

ACCUMTESTS = accumtest accumtest2 accumtest_s
MISC_TESTS = test_re2_d

ALL_PROGS = $(HELPERS) $(LIBTESTS) $(ACCUMTESTS) $(MISC_TESTS)

rcount:
	@(cd ..; $(MAKE) -f GNUmakefile regress) | $(PADS_HOME)/scripts/count_differs.pl

regress: regress_o regress_d repeat_library_sanity_check

perf_regress: regress perf_regress_o perf_regress_d repeat_library_sanity_check

regress_o: sanity_check \
	  regress_o_announce \
          regress_libtest1_o \
          regress_libtest2_o \
          regress_libtest4_o \
          regress_ebcdic_test_o \
          regress_ebcdic_libtest4_o \
          regress_cobol_ebc_test_o \
          regress_bcd_test_o \
          regress_sb_test_o \
          regress_bcd_fpoint_test_o \
          regress_ebc_fpoint_test_o \
          regress_re_scan_test_o \
          regress_rwtest1_o \
          regress_recrwtest1_o \
          regress_a_ip_test_o
	@echo "DONE"

regress_d: sanity_check \
	  regress_d_announce \
          regress_libtest1_d \
          regress_libtest2_d \
          regress_libtest4_d \
          regress_ebcdic_test_d \
          regress_ebcdic_libtest4_d \
          regress_cobol_ebc_test_d \
          regress_bcd_test_d \
          regress_sb_test_d \
          regress_bcd_fpoint_test_d \
          regress_ebc_fpoint_test_d \
          regress_re_scan_test_d \
          regress_rwtest1_d \
          regress_recrwtest1_d \
          regress_a_ip_test_d
	@echo "DONE"

perf_regress_o: sanity_check \
	perf_regress_o_announce \
	perf_regress_libtest1_o \
	perf_regress_libtest2_o \
        perf_regress_libtest4_o \
        perf_regress_ebcdic_test_o \
        perf_regress_ebcdic_libtest4_o \
        perf_regress_cobol_ebc_test_o \
        perf_regress_bcd_test_o \
        perf_regress_sb_test_o \
        perf_regress_bcd_fpoint_test_o \
        perf_regress_ebc_fpoint_test_o \
        perf_regress_re_scan_test_o \
        perf_regress_rwtest1_o \
        perf_regress_recrwtest1_o \
        perf_regress_a_ip_test_o \
	perf_regress_o_final
	@echo "DONE"

perf_regress_d: sanity_check \
	perf_regress_d_announce \
	perf_regress_libtest1_d \
	perf_regress_libtest2_d \
        perf_regress_libtest4_d \
        perf_regress_ebcdic_test_d \
        perf_regress_ebcdic_libtest4_d \
        perf_regress_cobol_ebc_test_d \
        perf_regress_bcd_test_d \
        perf_regress_sb_test_d \
        perf_regress_bcd_fpoint_test_d \
        perf_regress_ebc_fpoint_test_d \
        perf_regress_re_scan_test_d \
        perf_regress_rwtest1_d \
        perf_regress_recrwtest1_d \
        perf_regress_a_ip_test_d \
	perf_regress_d_final
	@echo "DONE"

libtests: sanity_check $(LIBTESTS)
accumtests: sanity_check $(ACCUMTESTS)
all: sanity_check $(ALL_PROGS)

sanity_check:
	@$(LibraryPathSanityCheck)
	@$(LibSanityCheck)

repeat_library_sanity_check:
	@$(LibraryPathSanityCheck)

test_regaddclass_o: test_regaddclass.c
	@$(TrivCCExec_O)

test_regaddclass_d: test_regaddclass.c
	@$(TrivCCExec_D)

long_regaddclass_o: long_regaddclass.c
	@$(TrivCCExec_O)

long_regaddclass_d: long_regaddclass.c
	@$(TrivCCExec_D)

regress_o_announce:
	@echo " "; echo "REGRESS USING OPTIMIZED CODE"; echo " " \

regress_d_announce:
	@echo " "; echo "REGRESS USING DEBUG CODE"; echo " " \

perf_regress_o_announce:
	@echo " "; echo "Performance REGRESSION USING OPTIMIZED CODE"; echo " " \

perf_regress_d_announce:
	@echo " "; echo "Performance REGRESSION USING DEBUG CODE"; echo " " \

perf_regress_o_final:
	@echo " "; echo "Performance REGRESSION USING OPTIMIZED CODE DONE"; echo " " \

perf_regress_d_final:
	@echo " "; echo "Performance REGRESSION USING DEBUG CODE DONE"; echo " " \

regress_rwtest1_o: rwtest1
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
regress_rwtest1_d: rwtest1_d
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
perf_regress_rwtest1_o: rwtest1
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_rwtest1_d: rwtest1_d
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))

regress_recrwtest1_o: recrwtest1
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
regress_recrwtest1_d: recrwtest1_d
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
perf_regress_recrwtest1_o: recrwtest1
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_recrwtest1_d: recrwtest1_d
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))

regress_libtest1_o: libtest1
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
regress_libtest1_d: libtest1_d
	@(args="nlrec_noseek"; suf=""; $(RegressDef))
perf_regress_libtest1_o: libtest1
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_libtest1_d: libtest1_d
	@(args="nlrec_noseek"; suf=""; $(PerfRegressDef))

regress_libtest2_o: libtest2
	@(args=""; suf=".$(AST_ARCH)"; $(RegressDef))
regress_libtest2_d: libtest2_d
	@(args=""; suf=".$(AST_ARCH)"; $(RegressDef))
perf_regress_libtest2_o: libtest2
	@(args=""; suf=".$(AST_ARCH)"; $(PerfRegressDef))
perf_regress_libtest2_d: libtest2_d
	@(args=""; suf=".$(AST_ARCH)"; $(PerfRegressDef))

regress_libtest4_o: libtest4
	@(args=""; suf=""; $(RegressDef))
regress_libtest4_d: libtest4_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_libtest4_o: libtest4
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_libtest4_d: libtest4_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_ebcdic_libtest4_o: ebcdic_libtest4
	@(args=""; suf=""; $(RegressDef))
regress_ebcdic_libtest4_d: ebcdic_libtest4_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_ebcdic_libtest4_o: ebcdic_libtest4
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_ebcdic_libtest4_d: ebcdic_libtest4_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_re_scan_test_o: re_scan_test
	@(args=""; suf=""; $(RegressDef))
regress_re_scan_test_d: re_scan_test_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_re_scan_test_o: re_scan_test
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_re_scan_test_d: re_scan_test_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_ebcdic_test_o: ebcdic_test
	@(args="ctrec_noseek"; suf=""; $(RegressDef))
regress_ebcdic_test_d: ebcdic_test_d
	@(args="ctrec_noseek"; suf=""; $(RegressDef))
perf_regress_ebcdic_test_o: ebcdic_test
	@(args="ctrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_ebcdic_test_d: ebcdic_test_d
	@(args="ctrec_noseek"; suf=""; $(PerfRegressDef))

regress_cobol_ebc_test_o: cobol_ebc_test
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
regress_cobol_ebc_test_d: cobol_ebc_test_d
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
perf_regress_cobol_ebc_test_o: cobol_ebc_test
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_cobol_ebc_test_d: cobol_ebc_test_d
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))

regress_bcd_test_o: bcd_test
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
regress_bcd_test_d: bcd_test_d
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
perf_regress_bcd_test_o: bcd_test
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_bcd_test_d: bcd_test_d
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))

regress_sb_test_o: sb_test
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
regress_sb_test_d: sb_test_d
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
perf_regress_sb_test_o: sb_test
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_sb_test_d: sb_test_d
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))

regress_ebc_fpoint_test_o: ebc_fpoint_test
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
regress_ebc_fpoint_test_d: ebc_fpoint_test_d
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
perf_regress_ebc_fpoint_test_o: ebc_fpoint_test
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_ebc_fpoint_test_d: ebc_fpoint_test_d
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))

regress_bcd_fpoint_test_o: bcd_fpoint_test
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
regress_bcd_fpoint_test_d: bcd_fpoint_test_d
	@(args="fwrec_noseek"; suf=""; $(RegressDef))
perf_regress_bcd_fpoint_test_o: bcd_fpoint_test
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))
perf_regress_bcd_fpoint_test_d: bcd_fpoint_test_d
	@(args="fwrec_noseek"; suf=""; $(PerfRegressDef))

regress_a_ip_test_o: a_ip_test
	@(args=""; suf=""; $(RegressDef))
regress_a_ip_test_d: a_ip_test_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_a_ip_test_o: a_ip_test
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_a_ip_test_d: a_ip_test_d
	@(args=""; suf=""; $(PerfRegressDef))

clean:
	$(RM) $(ALL_PROGS) *.o *~ tmp/*

veryclean: clean

 # End of rules that are run from the arch directory
endif


foo:
	echo $(OPSYS)