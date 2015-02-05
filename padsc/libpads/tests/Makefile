#########################################################################
#                                                                       #
#                                PADS                                   #
#                   Processing Ad Hoc Data Engine                       #
#                                                                       #
#   Copyright 2006, AT&T Labs Research                                  #
#   Distributed only by permission.                                     #
#                                                                       #
#########################################################################

#########################################################################
# Author:	Pamela L. Dragosh (AT&T Labs Research)
# Descripton:
#		This is a replacement Makefile for PADS that relies on the output
#		of a configuration script.
#
# History:
#	
#########################################################################

#########################################################################
# Section:	Default target
# Description:
#		The default target for this Makefile is "all"
#########################################################################
default:	all

#########################################################################
# Section:	Makefile pre-includes
# Description:
#		This is where the file(s) generated during by the Configure script
#		are included.  If config/Makefile.conf does not exist, the
#		make will fail.
#
#		Makefile.pads:	Variables defined for compiling and linking PADS
#								applications in the build environment
#########################################################################

include $(PADS_SRC)/config/Makefile.pads

#
# Here is where we include the re-direction into the ARCH sub-directory so we
# can support multi-architecture builds.
#
ifneq ($(ARCH), $(notdir $(HERE)))
include $(PADS_SRC)/config/Makefile.redirect
else

#
# For backward compatibility with 64 bit changes
#
export AST_ARCH=$(shell $(CONF_AST_BIN)/package)
export LD_LIBRARY_PATH:=$(LD_LIBRARY_PATH):$(PADS_SRC)/padsc/libpads/$(ARCH)
export DYLD_LIBRARY_PATH:=$(DYLD_LIBRARY_PATH):$(PADS_SRC)/padsc/libpads/$(ARCH)

#
# The rest of this file should be invoked from the ARCH sub-directory
#
#########################################################################
# Section:	Main targets
# Description:
#		This is where all of the named toplevel targets are placed.
#
#	all:		This target builds the test suite
#	install::	This target does installation for files in the main section
#	uninstall::	This target uninstalls files installed in the main section
#	clean::		This target cleans files created in the all section
#	clobber::	This target cleans files created in the all section and .depend
#	
#########################################################################

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

ifeq ($(PADS_PROFILING),false)
HELPERS = myrand cvt_ebcdic_to_ascii cvt_ascii_to_ebcdic dttest
LIBTESTS = $(LIBTESTS_O)
ACCUMTESTS = accumtest accumtest2 accumtest_s
MISC_TESTS = test_re2_d
else
LIBTESTS = $(LIBTESTS_D)
endif

ALL_PROGS = $(HELPERS) $(LIBTESTS) $(ACCUMTESTS) $(MISC_TESTS)
ALL_PROGS_EXE = $(ALL_PROGS:%=%$(EXE))

libtests: $(LIBTESTS)
accumtests: $(ACCUMTESTS)
mistests: $(MISC_TESTS)
all: $(ALL_PROGS)

clean::
	$(RM) $(ALL_PROGS_EXE)

veryclean:: clean

veryveryclean:: clean

clobber:: clean

#########################################################################
# Sub-Section:	Secondary targets
# Description:
#		These are the targets listed as dependencies of "all".  They each
#		have their own install, uninstall, and clean targets.
#
#		regress:		Runs the regression test suite
#########################################################################

#########################################################################
# Sub-Sub-Section:	regress
# Description:
#		These are the targets for building libraries, installing them
#		uninstalling them, and cleaning them.
#
#		libs:			Builds the library targets (static and optional shared)
#		install:		Installs the library targets (static and optional shared)
#		uninstall:		Uninstalls the library targets (static and optional shared)
#		clean:			Cleans up the files used to create the libraries that
#						are created by automatic rules
#########################################################################

rcount:
	@(cd ..; $(MAKE) -f Makefile regress) | $(PADS_SRC)/scripts/count_differs.pl

ifeq ($(PADS_PROFILING),false)
regress: regress_o
perf: perf_regress_o
else
regress: regress_d
perf: perf_regress_d
endif

regress_o: \
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
	@echo " "; echo "DONE"; echo " "

perf_regress_o: \
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
	@echo " "; echo "DONE"; echo " "

ifeq ($(PADS_PROFILING),true)
regress_d: \
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
	@echo " "; echo "DONE"; echo " "

perf_regress_d: \
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
	@echo " "; echo "DONE"; echo " "

endif

clean::
	$(RM) *.o *~ tmp/*

veryclean:: clean

veryveryclean:: clean

clobber::
	$(DELTREE) tmp

#
# Announcements
#
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

#
# Individual targets
#
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

#########################################################################
# Section:	Makefile post-includes
# Description:
#		This is where the dependency file is included and generated
#		We place the dependencies to make sure that various files
#		are generated before we need them.
#########################################################################

% : %.c
	$(CC) -Wall $(CFLAGS) $(CPPFLAGS) $(PADS_INCLUDES) $(PADS_LIBDIRS) $< -lpads-$(ARCH) -last $(CCLIBS) -o $@ 

%_d : %.c
	$(CC) -Wall -g $(CFLAGS) $(CPPFLAGS) $(PADS_INCLUDES) $(PADS_LIBDIRS) $< -lpads-$(ARCH)-g -last $(CCLIBS) -o $@ 

clobber::
	$(RM) .depend

updatedepend::
	$(MAKE) -f Makefile .depend DEPDEPEND=1

.depend: 
#	$(MAKEDEPEND) | $(SED) -e 's?\([a-z]\)\\?\1\/?g' > .depend

ifndef NODEPEND
include .depend
endif

endif
