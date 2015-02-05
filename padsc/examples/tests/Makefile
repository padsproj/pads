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
#				applications in the build environment
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
# Other paths defined
#
GEN_DIR=../../gen
VPATH+=../../p
TEST_BUILD_O=$(CC) -Wall -DNDEBUG $(CFLAGS) $(CPPFLAGS) $(PADS_INCLUDES) -I../../gen $^ $(PADS_LIBDIRS) -lpads-$(ARCH) -last $(CCLIBS) -o $@ 
TEST_BUILD_D=$(CC) -g -Wall -DDEBUG $(CFLAGS) $(CPPFLAGS) $(PADS_INCLUDES) -I../../gen $^ $(PADS_LIBDIRS) -lpads-$(ARCH)-g -last $(CCLIBS) -o $@ 

# the following indicates that generated files should not be removed
.PRECIOUS: %.o $(GEN_DIR)/%.c $(GEN_DIR)/%_expanded.c %_expanded.c \
	$(foreach mask,$(RMASKS),time_read_$(mask)_%_bulk)\
	$(foreach mask,$(RMASKS),time_read_$(mask)_%_linear)

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

FORMAT_TESTS_O = test_format1 test_format2 test_format3 test_format5 test_format6 test_struct_regexp test_array_regexp \
               test_array_nosep test_array_pred test_array_pred2 test_array_ended test_array_ended2 test_array_post \
               test_array_skip test_array_skip2 test_charclass test_me test_me_fooclass
DIB_TESTS_O =  test_dibbler1 test_dibbler1_mod test_fast_dib test_fast_dib_mod
WRITE_TESTS_O = test_write_struct1 test_write_struct_strings
OTHER_TESTS_O  = test_array test_array_string test_record_enum test_struct1 test_struct2 \
               test_punion2 test_punion_manifest test_typedef \
               test_cpygen_crs test_enum test_from test_ai test_readint test_depends \
               test_pswitch test_pswitch2 test_struct3 manifest_union test_dns rw_dns rw_struct_good rw_pendian rwxml_struct1 \
               test_cpyrecgen_rps rwxml_cpyrecgen_rps rwxml_format7 rwxml_newick rw_newick

ALL_TESTS_O = $(FORMAT_TESTS_O) $(DIB_TESTS_O) $(WRITE_TESTS_O) $(OTHER_TESTS_O)
ALL_TESTS_D = $(ALL_TESTS_O:%=%_d)
ALL_TESTS_EXE = $(ALL_TESTS_O) $(ALL_TESTS_D)
MISC_TESTS_O = test_ios 
MISC_TESTS_D = $(MISC_TESTS_O:%=%_d)
MISC_TESTS_EXE = $(MISC_TESTS_O) $(MISC_TESTS_D)
OTHER_TESTS_D = $(OTHER_TESTS_O:%=%_d)
DIB_TESTS_D = $(DIB_TESTS_O:%=%_d)
WRITE_TESTS_D = $(WRITE_TESTS_O:%=%_d)

ifeq ($(PADS_PROFILING),false)
ALL_TESTS=$(ALL_TESTS_O)
MISC_TESTS=$(MISC_TESTS_O)
else
ALL_TESTS=$(ALL_TESTS_D)
MISC_TESTS=$(MISC_TESTS_D)
OTHER_TESTS=$(OTHER_TESTS_D)
DIB_TESTS=$(DIB_TESTS_D)
WRITE_TESTS=$(WRITE_TESTS_D)
endif

all: $(ALL_TESTS)
misc: $(MISC_TESTS)
dib: $(DIB_TESTS)
format: $(FORMAT_TESTS)
write: $(WRITE_TESTS)
other: $(OTHER_TESTS)

clean::
	$(RM) $(ALL_TESTS_EXE) $(MISC_TESTS_EXE)

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
          regress_test_format1_o \
          regress_test_format2_o \
          regress_test_format3_o \
          regress_test_format5_o \
          regress_test_format6_o \
          regress_test_readint_o \
          regress_test_punion_manifest_o \
	  regress_rwxml_punion_literal2_o \
          regress_test_ai_o \
	  regress_test_pswitch_o \
	  regress_test_pswitch2_o \
	  regress_test_depends_o \
	  regress_test_struct3_o \
          regress_test_me_o \
          regress_test_me_fooclass_o \
	  regress_test_write_struct1_o \
	  regress_test_write_struct_strings_o \
          regress_test_struct_regexp_o \
          regress_test_array_regexp_o \
          regress_test_array_nosep_o \
          regress_test_array_pred_o  \
          regress_test_array_pred2_o  \
          regress_test_array_ended_o \
          regress_test_array_ended2_o \
          regress_test_array_post_o \
          regress_test_array_skip_o \
          regress_test_array_skip2_o \
          regress_test_in_place_o \
          regress_test_opt_o \
          regress_test_charclass_o \
          regress_rw_struct_good_o \
          regress_rw_pendian_o \
          regress_rwxml_struct1_o \
          regress_rwxml_newick_o \
          regress_rw_newick_o \
          regress_rwxml_alt1_o \
          regress_rwxml_2ips_o \
          regress_rwxml_pfloat_o \
          regress_rwxml_ptime_o \
          regress_rwxml_ptime_explicit_o \
          regress_rwxml_pdate_o \
          regress_rwxml_pdate_explicit_o \
          regress_rwxml_pdate_explicit_me_o \
          regress_rwxml_enum_o \
          regress_rwxml_enum3_o \
	  regress_rwxml_array_advance_o \
	  regress_rwxml_message_header_o \
          regress_rwxml_pads-comp_o \
          regress_rwxml_transform_o \
          regress_test_transform_o \
          regress_rwxml_try_o 
	@echo " "; echo "DONE"; echo " ";

perf_regress_o: \
	  perf_regress_o_announce \
          perf_regress_test_format1_o \
          perf_regress_test_format2_o \
          perf_regress_test_format3_o \
          perf_regress_test_format5_o \
          perf_regress_test_format6_o \
          perf_regress_test_readint_o \
          perf_regress_test_punion_manifest_o \
	  perf_regress_rwxml_punion_literal2_o \
          perf_regress_test_ai_o \
	  perf_regress_test_pswitch_o \
	  perf_regress_test_pswitch2_o \
	  perf_regress_test_depends_o \
	  perf_regress_test_struct3_o \
          perf_regress_test_me_o \
          perf_regress_test_me_fooclass_o \
	  perf_regress_test_write_struct1_o \
	  perf_regress_test_write_struct_strings_o \
          perf_regress_test_struct_regexp_o \
          perf_regress_test_array_regexp_o \
          perf_regress_test_array_nosep_o \
          perf_regress_test_array_pred_o  \
          perf_regress_test_array_pred2_o  \
          perf_regress_test_array_ended_o \
          perf_regress_test_array_ended2_o \
          perf_regress_test_array_post_o \
          perf_regress_test_array_skip_o \
          perf_regress_test_array_skip2_o \
          perf_regress_test_in_place_o \
          perf_regress_test_opt_o \
          perf_regress_test_charclass_o \
          perf_regress_rw_struct_good_o \
          perf_regress_rw_pendian_o \
          perf_regress_rwxml_struct1_o \
          perf_regress_rwxml_newick_o \
          perf_regress_rw_newick_o \
          perf_regress_rwxml_alt1_o \
          perf_regress_rwxml_2ips_o \
          perf_regress_rwxml_pfloat_o \
          perf_regress_rwxml_ptime_o \
          perf_regress_rwxml_ptime_explicit_o \
          perf_regress_rwxml_pdate_o \
          perf_regress_rwxml_pdate_explicit_o \
          perf_regress_rwxml_pdate_explicit_me_o \
          perf_regress_rwxml_enum_o \
	  perf_regress_rwxml_array_advance_o \
	  perf_regress_rwxml_message_header_o \
          perf_regress_rwxml_pads-comp_o \
          perf_regress_rwxml_transform_o \
          perf_regress_test_transform_o 
	@echo " "; echo "DONE"; echo " "

ifeq ($(PADS_PROFILING),true)
regress_d: \
	  regress_d_announce \
          regress_test_format1_d \
          regress_test_format2_d \
          regress_test_format3_d \
          regress_test_format5_d \
          regress_test_format6_d \
          regress_test_readint_d \
          regress_test_punion_manifest_d \
	  regress_rwxml_punion_literal2_d \
          regress_test_ai_d \
	  regress_test_pswitch_d \
	  regress_test_pswitch2_d \
	  regress_test_depends_d \
	  regress_test_struct3_d \
          regress_test_me_d \
          regress_test_me_fooclass_d \
	  regress_test_write_struct1_d \
	  regress_test_write_struct_strings_d \
          regress_test_struct_regexp_d \
          regress_test_array_regexp_d \
          regress_test_array_nosep_d \
          regress_test_array_pred_d \
          regress_test_array_pred2_d \
          regress_test_array_ended_d  \
          regress_test_array_ended2_d \
          regress_test_array_post_d \
          regress_test_array_skip_d \
          regress_test_array_skip2_d \
          regress_test_in_place_d \
          regress_test_opt_d \
          regress_test_charclass_d \
          regress_rw_struct_good_d \
          regress_rw_pendian_d \
          regress_rwxml_struct1_d \
          regress_rwxml_newick_d \
          regress_rw_newick_d \
          regress_rwxml_alt1_d \
          regress_rwxml_2ips_d \
          regress_rwxml_pfloat_d \
          regress_rwxml_ptime_d \
          regress_rwxml_ptime_explicit_d \
          regress_rwxml_ptimestamp_d \
          regress_rwxml_ptimestamp_explicit_d \
          regress_rwxml_pdate_d \
          regress_rwxml_pdate_explicit_d \
          regress_rwxml_pdate_explicit_me_d \
          regress_rwxml_enum_d \
          regress_rwxml_enum3_d \
          regress_rwxml_array_advance_d \
          regress_rwxml_message_header_d \
          regress_rwxml_pads-comp_d \
          regress_rwxml_transform_d \
          regress_test_transform_d \
          regress_rwxml_try_d 
	@echo " "; echo "DONE"; echo " "

perf_regress_d: \
	  perf_regress_d_announce \
          perf_regress_test_format1_d \
          perf_regress_test_format2_d \
          perf_regress_test_format3_d \
          perf_regress_test_format5_d \
          perf_regress_test_format6_d \
          perf_regress_test_readint_d \
          perf_regress_test_punion_manifest_d \
	  perf_regress_rwxml_punion_literal2_d \
          perf_regress_test_ai_d \
	  perf_regress_test_pswitch_d \
	  perf_regress_test_pswitch2_d \
	  perf_regress_test_depends_d \
	  perf_regress_test_struct3_d \
          perf_regress_test_me_d \
          perf_regress_test_me_fooclass_d \
	  perf_regress_test_write_struct1_d \
	  perf_regress_test_write_struct_strings_d \
          perf_regress_test_struct_regexp_d \
          perf_regress_test_array_regexp_d \
          perf_regress_test_array_nosep_d \
          perf_regress_test_array_pred_d \
          perf_regress_test_array_pred2_d \
          perf_regress_test_array_ended_d  \
          perf_regress_test_array_ended2_d \
          perf_regress_test_array_post_d \
          perf_regress_test_array_skip_d \
          perf_regress_test_array_skip2_d \
          perf_regress_test_in_place_d \
          perf_regress_test_opt_d \
          perf_regress_test_charclass_d \
          perf_regress_rw_struct_good_d \
          perf_regress_rw_pendian_d \
          perf_regress_rwxml_struct1_d \
          perf_regress_rwxml_newick_d \
          perf_regress_rw_newick_d \
          perf_regress_rwxml_alt1_d \
          perf_regress_rwxml_2ips_d \
          perf_regress_rwxml_pfloat_d \
          perf_regress_rwxml_ptime_d \
          perf_regress_rwxml_ptime_explicit_d \
          perf_regress_rwxml_ptimestamp_d \
          perf_regress_rwxml_ptimestamp_explicit_d \
          perf_regress_rwxml_pdate_d \
          perf_regress_rwxml_pdate_explicit_d \
          perf_regress_rwxml_pdate_explicit_me_d \
          perf_regress_rwxml_enum_d \
          perf_regress_rwxml_array_advance_d \
          perf_regress_rwxml_message_header_d \
          perf_regress_rwxml_pads-comp_d \
          perf_regress_rwxml_transform_d \
          perf_regress_test_transform_d 
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
regress_test_me_o: test_me
	@(args=""; suf=""; $(RegressDef))
regress_test_me_d: test_me_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_me_o: test_me
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_me_d: test_me_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_me_fooclass_o: test_me_fooclass
	@(args=""; suf=""; $(RegressDef))
regress_test_me_fooclass_d: test_me_fooclass_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_me_fooclass_o: test_me_fooclass
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_me_fooclass_d: test_me_fooclass_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format1_o: test_format1
	@(args=""; suf=""; $(RegressDef))
regress_test_format1_d: test_format1_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format1_o: test_format1
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format1_d: test_format1_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format2_o: test_format2
	@(args=""; suf=""; $(RegressDef))
regress_test_format2_d: test_format2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format2_o: test_format2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format2_d: test_format2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format3_o: test_format3
	@(args=""; suf=""; $(RegressDef))
regress_test_format3_d: test_format3_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format3_o: test_format3
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format3_d: test_format3_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format4_o: test_format4
	@(args=""; suf=""; $(RegressDef))
regress_test_format4_d: test_format4_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format4_o: test_format4
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format4_d: test_format4_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format5_o: test_format5
	@(args=""; suf=""; $(RegressDef))
regress_test_format5_d: test_format5_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format5_o: test_format5
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format5_d: test_format5_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_format6_o: test_format6
	@(args=""; suf=""; $(RegressDef))
regress_test_format6_d: test_format6_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_format6_o: test_format6
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_format6_d: test_format6_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_readint_o: test_readint
	@(args=""; suf=""; filter="error:"; $(RegressFilter))
regress_test_readint_d: test_readint_d
	@(args=""; suf=""; filter="error:"; $(RegressFilter))
perf_regress_test_readint_o: test_readint
	@(args=""; suf=""; filter="error:"; $(PerfRegressDef))
perf_regress_test_readint_d: test_readint_d
	@(args=""; suf=""; filter="error:"; $(PerfRegressDef))

regress_test_ai_o: test_ai
	@(args=""; suf=""; $(RegressDef))
regress_test_ai_d: test_ai_d
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_ai_o: rwxml_ai
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_ai_o: test_ai
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_ai_d: test_ai_d
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_ai_o: rwxml_ai
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_transform_o: test_transform
	@(args=""; suf=""; $(RegressDef))
regress_test_transform_d: test_transform_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_transform_o: test_transform
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_transform_d: test_transform_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_transform_o: rwxml_transform
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_transform_d: rwxml_transform_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_transform_o: rwxml_transform
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_transform_d: rwxml_transform_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_try_o: rwxml_try
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_try_d: rwxml_try_d
	@(args=""; suf=""; $(RegressDef))


regress_test_dns_o: test_dns
	@(args=""; suf=""; $(RegressDef))
regress_test_dns_d: test_dns_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_dns_o: test_dns
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_dns_d: test_dns_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_write_struct1_o: test_write_struct1
	@(args=""; suf=""; $(RegressDef))
regress_test_write_struct1_d: test_write_struct1_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_write_struct1_o: test_write_struct1
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_write_struct1_d: test_write_struct1_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_write_struct_strings_o: test_write_struct_strings
	@(args=""; suf=""; $(RegressDef))
regress_test_write_struct_strings_d: test_write_struct_strings_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_write_struct_strings_o: test_write_struct_strings
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_write_struct_strings_d: test_write_struct_strings_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_punion_manifest_o: test_punion_manifest
	@(args=""; suf=""; $(RegressDef))
regress_test_punion_manifest_d: test_punion_manifest_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_punion_manifest_o: test_punion_manifest
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_punion_manifest_d: test_punion_manifest_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_punion_literal2_o: rwxml_punion_literal2
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_punion_literal2_d: rwxml_punion_literal2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_punion_literal2_o: rwxml_punion_literal2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_punion_literal2_d: rwxml_punion_literal2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_pswitch_o: test_pswitch
	@(args=""; suf=""; $(RegressDef))
regress_test_pswitch_d: test_pswitch_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_pswitch_o: test_pswitch
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_pswitch_d: test_pswitch_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_pswitch2_o: test_pswitch2
	@(args=""; suf=""; $(RegressDef))
regress_test_pswitch2_d: test_pswitch2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_pswitch2_o: test_pswitch2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_pswitch2_d: test_pswitch2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_depends_o: test_depends
	@(args=""; suf=""; $(RegressDef))
regress_test_depends_d: test_depends_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_depends_o: test_depends
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_depends_d: test_depends_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_struct3_o: test_struct3
	@(args=""; suf=""; $(RegressDef))
regress_test_struct3_d: test_struct3_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_struct3_o: test_struct3
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_struct3_d: test_struct3_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_struct_regexp_o: test_struct_regexp
	@(args=""; suf=""; $(RegressDef))
regress_test_struct_regexp_d: test_struct_regexp_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_struct_regexp_o: test_struct_regexp
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_struct_regexp_d: test_struct_regexp_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_regexp_o: test_array_regexp
	@(args=""; suf=""; $(RegressDef))
regress_test_array_regexp_d: test_array_regexp_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_regexp_o: test_array_regexp
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_regexp_d: test_array_regexp_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_nosep_o: test_array_nosep
	@(args=""; suf=""; $(RegressDef))
regress_test_array_nosep_d: test_array_nosep_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_nosep_o: test_array_nosep
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_nosep_d: test_array_nosep_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_pred_o: test_array_pred
	@(args=""; suf=""; $(RegressDef))
regress_test_array_pred_d: test_array_pred_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_pred_o: test_array_pred
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_pred_d: test_array_pred_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_pred2_o: test_array_pred2
	@(args=""; suf=""; $(RegressDef))
regress_test_array_pred2_d: test_array_pred2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_pred2_o: test_array_pred2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_pred2_d: test_array_pred2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_ended_o: test_array_ended
	@(args=""; suf=""; $(RegressDef))
regress_test_array_ended_d: test_array_ended_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_ended_o: test_array_ended
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_ended_d: test_array_ended_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_ended2_o: test_array_ended2
	@(args=""; suf=""; $(RegressDef))
regress_test_array_ended2_d: test_array_ended2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_ended2_o: test_array_ended2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_ended2_d: test_array_ended2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_skip_o: test_array_skip
	@(args=""; suf=""; $(RegressDef))
regress_test_array_skip_d: test_array_skip_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_skip_o: test_array_skip
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_skip_d: test_array_skip_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_skip2_o: test_array_skip2
	@(args=""; suf=""; $(RegressDef))
regress_test_array_skip2_d: test_array_skip2_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_skip2_o: test_array_skip2
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_skip2_d: test_array_skip2_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_in_place_o: test_in_place
	@(args=""; suf=""; $(RegressDef))
regress_test_in_place_d: test_in_place_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_in_place_o: test_in_place
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_in_place_d: test_in_place_d
	@(args=""; suf=""; $(PerfRegressDef))


regress_test_opt_o: test_opt
	@(args=""; suf=""; $(RegressDef))
regress_test_opt_d: test_opt_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_opt_o: test_opt
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_opt_d: test_opt_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_array_post_o: test_array_post
	@(args=""; suf=""; $(RegressDef))
regress_test_array_post_d: test_array_post_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_array_post_o: test_array_post
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_array_post_d: test_array_post_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_charclass_o: test_charclass
	@(args=""; suf=""; $(RegressDef))
regress_test_charclass_d: test_charclass_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_charclass_o: test_charclass
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_test_charclass_d: test_charclass_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_ios_o: test_ios
	@(args=""; input="../../data/small_ios_config"; suf=""; pp="$(PADS_HOME)/scripts/ios_pp.pl"; $(RegressInputPP))
regress_test_ios_d: test_ios_d
	@(args=""; input="../../data/small_ios_config"; suf=""; pp="$(PADS_HOME)/scripts/ios_pp.pl"; $(RegressInputPP))

regress_rw_dns_o: rw_dns
	@(args=""; input="../../data/dns"; suf=""; $(RegressRW))

regress_rw_dns_d: rw_dns_d
	@(args=""; input="../../data/dns"; suf=""; $(RegressRW))

regress_rw_struct_good_o: rw_struct_good
	@(args=""; input="../../data/struct_good"; suf=""; $(RegressRW))
regress_rw_struct_good_d: rw_struct_good_d
	@(args=""; input="../../data/struct_good"; suf=""; $(RegressRW))
perf_regress_rw_struct_good_o: rw_struct_good
	@(args=""; input="../../data/struct_good"; suf=""; $(PerfRegressDef))
perf_regress_rw_struct_good_d: rw_struct_good_d
	@(args=""; input="../../data/struct_good"; suf=""; $(PerfRegressDef))

regress_rw_pendian_o: rw_pendian
	@(args=""; input="../../data/endian.delenn"; suf="_delenn"; $(RegressRW))
	@(args=""; input="../../data/endian.raptor"; suf="_raptor"; $(RegressRW))
regress_rw_pendian_d: rw_pendian_d
	@(args=""; input="../../data/endian.delenn"; suf="_delenn"; $(RegressRW))
	@(args=""; input="../../data/endian.raptor"; suf="_raptor"; $(RegressRW))
perf_regress_rw_pendian_o: rw_pendian
	@(args=""; input="../../data/endian.delenn"; suf="_delenn"; $(PerfRegressRW))
	@(args=""; input="../../data/endian.raptor"; suf="_raptor"; $(PerfRegressRW))
perf_regress_rw_pendian_d: rw_pendian_d
	@(args=""; input="../../data/endian.delenn"; suf="_delenn"; $(PerfRegressRW))
	@(args=""; input="../../data/endian.raptor"; suf="_raptor"; $(PerfRegressRW))

regress_rwxml_struct1_o: rwxml_struct1
	@(args=""; input="../../data/struct1"; suf=""; $(RegressInput))
#AJF: how come the action clause for *_d doesn't match *_o in this case?
regress_rwxml_struct1_d: rwxml_struct1_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_struct1_o: rwxml_struct1
	@(args=""; input="../../data/struct1"; suf=""; $(PerfRegressInput))
perf_regress_rwxml_struct1_d: rwxml_struct1_d
	@(args=""; input="../../data/struct1"; suf=""; $(PerfRegressInput))

regress_rwxml_newick_o: rwxml_newick
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_newick_d: rwxml_newick_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_newick_o: rwxml_newick
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_newick_d: rwxml_newick_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rw_newick_o: rw_newick
	@(args=""; suf=""; $(RegressDef))
regress_rw_newick_d: rw_newick_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rw_newick_o: rw_newick
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rw_newick_d: rw_newick_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_alt1_o: rwxml_alt1
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_alt1_d: rwxml_alt1_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_alt1_o: rwxml_alt1
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_alt1_d: rwxml_alt1_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_2ips_o: rwxml_2ips
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_2ips_d: rwxml_2ips_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_2ips_o: rwxml_2ips
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_2ips_d: rwxml_2ips_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_pfloat_o: rwxml_pfloat
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_pfloat_d: rwxml_pfloat_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_pfloat_o: rwxml_pfloat
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_pfloat_d: rwxml_pfloat_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_ptime_o: rwxml_ptime
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_ptime_d: rwxml_ptime_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_ptime_o: rwxml_ptime
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_ptime_d: rwxml_ptime_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_ptime_explicit_o: rwxml_ptime_explicit
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_ptime_explicit_d: rwxml_ptime_explicit_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_ptime_explicit_o: rwxml_ptime_explicit
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_ptime_explicit_d: rwxml_ptime_explicit_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_ptimestamp_o: rwxml_ptimestamp
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_ptimestamp_d: rwxml_ptimestamp_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_ptimestamp_o: rwxml_ptimestamp
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_ptimestamp_d: rwxml_ptimestamp_d
	@(args=""; suf=""; $(PerfRegressDef))

#AJF: _o Unused.
regress_rwxml_ptimestamp_explicit_o: rwxml_ptimestamp_explicit
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_ptimestamp_explicit_d: rwxml_ptimestamp_explicit_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_ptimestamp_explicit_o: rwxml_ptimestamp_explicit
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_ptimestamp_explicit_d: rwxml_ptimestamp_explicit_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_pdate_o: rwxml_pdate
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_pdate_d: rwxml_pdate_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_pdate_o: rwxml_pdate
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_pdate_d: rwxml_pdate_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_pdate_explicit_o: rwxml_pdate_explicit
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_pdate_explicit_d: rwxml_pdate_explicit_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_pdate_explicit_o: rwxml_pdate_explicit
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_pdate_explicit_d: rwxml_pdate_explicit_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_pdate_explicit_me_o: rwxml_pdate_explicit_me
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_pdate_explicit_me_d: rwxml_pdate_explicit_me_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_pdate_explicit_me_o: rwxml_pdate_explicit_me
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_pdate_explicit_me_d: rwxml_pdate_explicit_me_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_enum_o: rwxml_enum
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_enum_d: rwxml_enum_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_enum_o: rwxml_enum
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_enum_d: rwxml_enum_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_enum3_o: rwxml_enum3
	@(args=""; suf=""; $(RegressDef))

regress_rwxml_enum3_d: rwxml_enum3_d
	@(args=""; suf=""; $(RegressDef))

regress_rwxml_array_advance_o: rwxml_array_advance
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_array_advance_d: rwxml_array_advance_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_array_advance_o: rwxml_array_advance
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_array_advance_d: rwxml_array_advance_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_message_header_o: rwxml_message_header
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_message_header_d: rwxml_message_header_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_message_header_o: rwxml_message_header
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_message_header_d: rwxml_message_header_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_rwxml_pads-comp_o: rwxml_pads-comp
	@(args=""; suf=""; $(RegressDef))
regress_rwxml_pads-comp_d: rwxml_pads-comp_d
	@(args=""; suf=""; $(RegressDef))
perf_regress_rwxml_pads-comp_o: rwxml_pads-comp
	@(args=""; suf=""; $(PerfRegressDef))
perf_regress_rwxml_pads-comp_d: rwxml_pads-comp_d
	@(args=""; suf=""; $(PerfRegressDef))

regress_test_cpyrecgen_rps_o: test_cpyrecgen_rps_o
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(RegressInput))
regress_test_cpyrecgen_rps_d: test_cpyrecgen_rps_d
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(RegressInput))
perf_regress_test_cpyrecgen_rps_o: test_cpyrecgen_rps_o
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(PerfRegressInput))
perf_regress_test_cpyrecgen_rps_d: test_cpyrecgen_rps_d
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(PerfRegressInput))

regress_rwxml_cpyrecgen_rps_o: rwxml_cpyrecgen_rps_o
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(RegressInput))
regress_rwxml_cpyrecgen_rps_d: rwxml_cpyrecgen_rps_d
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(RegressInput))
perf_regress_rwxml_cpyrecgen_rps_o: rwxml_cpyrecgen_rps_o
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(PerfRegressInput))
perf_regress_rwxml_cpyrecgen_rps_d: rwxml_cpyrecgen_rps_d
	@(args=""; input="../../data/PPBS00.OX006550.RPSDTL.DATA.G0075V00.15465.20030921135804"; suf=""; $(PerfRegressInput))

#########################################################################
# Section:	Makefile post-includes
# Description:
#		This is where the dependency file is included and generated
#		We place the dependencies to make sure that various files
#		are generated before we need them.
#########################################################################

$(GEN_DIR)/%.c: %.p $(PADS_SCRIPT_PADSC) $(PADS_PADSC_TARGET)
	@echo "Generating $@"
	$(PADS_SCRIPT_PADSC) $< $(PADS_SCRIPT_PADSC_PARMS) -r $(GEN_DIR) $(PADS_INCLUDES) 

test_%: $(GEN_DIR)/%.c test_%.c
	$(TEST_BUILD_O)
test_%_d: $(GEN_DIR)/%.c test_%.c
	$(TEST_BUILD_D)

accum_%: $(GEN_DIR)/%.c accum_%.c
	$(TEST_BUILD_O)
accum_%_d: $(GEN_DIR)/%.c accum_%.c
	$(TEST_BUILD_D)

fmt_%: $(GEN_DIR)/%.c fmt_%.c
	$(TEST_BUILD_O)
fmt_%_d: $(GEN_DIR)/%.c fmt_%.c
	$(TEST_BUILD_D)

filter_%: $(GEN_DIR)/%.c filter_%.c
	$(TEST_BUILD_O)
filter_%_d: $(GEN_DIR)/%.c filter_%.c
	$(TEST_BUILD_D)

rw_%: $(GEN_DIR)/%.c rw_%.c
	$(TEST_BUILD_O)
rw_%_d: $(GEN_DIR)/%.c rw_%.c
	$(TEST_BUILD_D)

rwxml_%: $(GEN_DIR)/%.c rwxml_%.c
	$(TEST_BUILD_O)
rwxml_%_d: $(GEN_DIR)/%.c rwxml_%.c
	$(TEST_BUILD_D)

test_write_struct1: $(GEN_DIR)/struct1.c test_write_struct1.c 
	$(TEST_BUILD_O)
test_write_struct1_d: $(GEN_DIR)/struct1.c test_write_struct1.c 
	$(TEST_BUILD_D)

test_write_struct_strings: $(GEN_DIR)/struct_strings.c test_write_struct_strings.c
	$(TEST_BUILD_O)
test_write_struct_strings_d: $(GEN_DIR)/struct_strings.c test_write_struct_strings.c
	$(TEST_BUILD_D)

ifeq ($(PADS_PROFILING),false)
%: $(GEN_DIR)/%.c
	$(TEST_BUILD_O)
else
%: $(GEN_DIR)/%.c
	$(TEST_BUILD_D)
endif

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
