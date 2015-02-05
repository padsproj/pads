
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

GEN_DIR = ../../gen
GEN_WRITE = 1

# Variables used for timing tests
DATA_DIR = ../../data
TIMING_DIR=../../timing
TIMING_SCR=$(PADS_HOME)/scripts/timing.sh
TFORMATS=dns ai dibbler_new
RMASKS=CaS SyS Ig

# the following indicates that generated files should not be removed
.PRECIOUS: %.o $(GEN_DIR)/%.c $(GEN_DIR)/%_expanded.c %_expanded.c \
	$(foreach mask,$(RMASKS),time_read_$(mask)_%_bulk)\
	$(foreach mask,$(RMASKS),time_read_$(mask)_%_linear)

# need to set this before including rules.mk
REGRESS_TESTS = 1

include $(PADS_HOME)/mk/rules.mk

VPATH =  .. ../../p

ifndef GEN_GALAX
ifndef USE_GALAX
GALAX_NONE = 1
endif
endif

ifdef GALAX_NONE
XML_TESTS =
else
XML_TESTS = test_children
endif

FORMAT_TESTS = test_format1 test_format2 test_format3 test_format5 test_format6 test_struct_regexp test_array_regexp \
               test_array_nosep test_array_pred test_array_pred2 test_array_ended test_array_ended2 test_array_post \
               test_array_skip test_array_skip2 test_charclass test_me test_me_fooclass rwxml_punion_literal2 test_in_place \
               test_opt rwxml_alt1 rwxml_2ips rwxml_pfloat  rwxml_ptime rwxml_ptime_explicit rwxml_pdate rwxml_pdate_explicit \
               rwxml_pdate_explicit_me rwxml_enum rwxml_enum3 rwxml_array_advace rwxml_message_header rwxml_pads-comp rwxml_transform \
               rwxml_try fmt_format-bug test_punion_manifest rwxml_ptimestamp rwxml_ptimestamp_explicit test_transform fmt_format-bug2 \
               rwxml_array_advance fmt_union_empty fmt_format_array test_liste

DIB_TESTS =  test_dibbler1 test_dibbler1_mod test_fast_dib test_fast_dib_mod
WRITE_TESTS = test_write_struct1 test_write_struct_strings
OTHER_TESTS  = test_array test_array_string test_record_enum test_struct1 test_struct2 \
               test_punion2 test_typedef \
               test_cpygen_crs test_enum test_from test_ai test_readint test_depends \
               test_pswitch test_pswitch2 test_struct3 manifest_union test_dns rw_dns rw_struct_good rw_pendian rwxml_struct1 \
               test_cpyrecgen_rps rwxml_cpyrecgen_rps rwxml_format7 rwxml_newick rw_newick
ALL_TESTS_O = $(FORMAT_TESTS) $(DIB_TESTS) $(WRITE_TESTS) $(OTHER_TESTS) $(XML_TESTS)
ALL_TESTS_D = $(ALL_TESTS_O:%=%_d)
ALL_TESTS = $(ALL_TESTS_O) $(ALL_TESTS_D)

# do not build MISC tests when building 'all'
MISC_TESTS_O = test_ios 
MISC_TESTS_D = $(MISC_TESTS_O:%=%_d)
MISC_TESTS = $(MISC_TESTS_O) $(MISC_TESTS_D)
CLEANUP_TESTS = $(ALL_TESTS) $(MISC_TESTS)
TIMING_TEST = timing_ai

# XXX removed these 2 for now (compilation very slow?)
#           regress_test_dns_o \
#           regress_test_dns_d \

rcount:
	@(cd ..; $(MAKE) -f GNUmakefile regress) | $(PADS_HOME)/scripts/count_differs.pl

regress: regress_o regress_d repeat_library_sanity_check

foo: 
	echo $(PADSC) $(PADSC_REAL)

perf_regress: regress perf_regress_o perf_regress_d repeat_library_sanity_check

regress_o:  sanity_check \
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
          regress_rwxml_try_o \
	  regress_fmt_format-bug_o \
	  regress_fmt_format-bug2_o \
	  regress_fmt_union_empty_o \
	  regress_fmt_format_array_o \
	  regress_test_liste_o

	@echo "DONE"

regress_d:  sanity_check \
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
          regress_rwxml_try_d \
	  regress_fmt_format-bug_d \
	  regress_fmt_union_empty_d \
	  regress_fmt_format_array_d \
          regress_test_liste_d	  
	@echo "DONE"

perf_regress_o:  sanity_check \
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
	@echo "DONE"

perf_regress_d:  sanity_check \
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
	@echo "DONE"

dib_tests: sanity_check $(DIB_TESTS)
format_tests: sanity_check $(FORMAT_TESTS)
other_tests: sanity_check $(OTHER_TESTS)
all_tests: sanity_check $(ALL_TESTS)

sanity_check:
	@$(LibraryPathSanityCheck)
	@$(SanityCheck)

repeat_library_sanity_check:
	@$(LibraryPathSanityCheck)

regress_o_announce:
	@echo " "; echo "REGRESS USING OPTIMIZED CODE"; echo " " \

regress_d_announce:
	@echo " "; echo "REGRESS USING DEBUG CODE"; echo " " \

perf_regress_o_announce:
	@echo " "; echo "Performance REGRESSION TEST USING OPTIMIZED CODE"; echo " " \

perf_regress_d_announce:
	@echo " "; echo "Performance REGRESSION TEST USING DEBUG CODE"; echo " " \

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

regress_fmt_format-bug_o: fmt_format-bug
	@(args=""; suf=""; $(RegressDef))
regress_fmt_format-bug_d: fmt_format-bug_d
	@(args=""; suf=""; $(RegressDef))

regress_fmt_format-bug2_o: fmt_format-bug2
	@(args=""; suf=""; $(RegressDef))
regress_fmt_format-bug2_d: fmt_format-bug2_d
	@(args=""; suf=""; $(RegressDef))

regress_fmt_union_empty_o: fmt_union_empty
	@(args=""; suf=""; $(RegressDef))
regress_fmt_union_empty_d: fmt_union_empty_d
	@(args=""; suf=""; $(RegressDef))

regress_fmt_format_array_o: fmt_format_array
	@(args=""; suf=""; $(RegressDef))
regress_fmt_format_array_d: fmt_format_array_d
	@(args=""; suf=""; $(RegressDef))

regress_test_liste_o: test_liste
	@(args=""; suf=""; $(RegressDef))
regress_test_liste_d: test_liste_d
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

clean:
	$(RM) -f *~ *.o $(CLEANUP_TESTS)

veryclean: clean
	$(RM) $(GEN_DIR)/*.[hc] $(GEN_DIR)/*.xsd tmp/* $(GEN_DIR)/*.pxml

# This works for some but not all test cases

# These cases do not fit the usual pattern

.PHONY: time_% process_% do_time_pads do_time_pglx

ifeq ($(PADS_KIND),bulk)
COPTFLAGS += -D PADS_BULK -D PADS_ALLOC_HINT=$(PADS_ALLOC_HINT)
endif
#ifeq ($(PADS_KIND),linear)
#COPTFLAGS += -D PADS_LINEAR
#endif

# Mary: I'm not sure which are the right switches to use here...
#COPTFLAGS += -D PADS_LINEAR -D PADS_ALLOC_HINT=0

ifeq ($(PADS_KIND),linear)
COPTFLAGS += -D PADS_SMART -D MAX_ELTS=1
endif

ifndef PADS_SIZE
PADS_SIZE=big
endif

time_read_SyS_%_d: CDBGFLAGS += -D 'READ_MASK=(P_SynCheck|P_Set)' -D 'E_REP_LEV=PerrorRep_None'
time_read_SyS_%_d: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

time_read_SyS_%: COPTFLAGS += -D 'READ_MASK=(P_SynCheck|P_Set)' -D 'E_REP_LEV=PerrorRep_None'
time_read_SyS_%_bulk\
time_read_SyS_%_linear: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

time_read_Ig_%_d: CDBGFLAGS += -D 'READ_MASK=(P_Ignore)' -D 'E_REP_LEV=PerrorRep_None'
time_read_Ig_%_d: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

time_read_Ig_%: COPTFLAGS += -D 'READ_MASK=(P_Ignore)' -D "E_REP_LEV=PerrorRep_None"
time_read_Ig_%_bulk\
time_read_Ig_%_linear: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

time_read_CaS_%_d: CDBGFLAGS += -D 'READ_MASK=(P_CheckAndSet)' -D 'E_REP_LEV=PerrorRep_None'
time_read_CaS_%_d: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

time_read_CaS_% : COPTFLAGS += -D 'READ_MASK=(P_CheckAndSet)' -DE_REP_LEV=PerrorRep_None
time_read_CaS_%_bulk\
time_read_CaS_%_linear: $(GEN_DIR)/%.o time_read_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

ifeq ($(PGLX_KIND),bulk)
COPTFLAGS += -D PGLX_BULK -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=$(PGLX_ALLOC_HINT)
endif
ifeq ($(PGLX_KIND),linear)
COPTFLAGS += -D PGLX_LINEAR -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=0
endif
ifeq ($(PGLX_KIND),smart)
COPTFLAGS += -D PGLX_SMART -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=0
endif

pglx_bulk_%_d pglx_linear_%_d pglx_smart_%_d: \
$(GEN_DIR)/%.c time_pglx_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

pglx_bulk_% pglx_linear_% pglx_smart_%: \
$(GEN_DIR)/%.o time_pglx_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

time_Ig_%: time_read_Ig_%_$(PADS_KIND)
	$(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) \
	Ig_$*_$(PADS_SIZE)_$(PADS_KIND).time

time_SyS_%: time_read_SyS_%_$(PADS_KIND)
	$(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) \
	SyS_$*_$(PADS_SIZE)_$(PADS_KIND).time

time_CaS_%: time_read_CaS_%_$(PADS_KIND)
	$(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) \
	CaS_$*_$(PADS_SIZE)_$(PADS_KIND).time

process_Ig_%: $(TIMING_DIR)/Ig_%_$(PADS_KIND).time
	@export PROCESS_ONLY=1;\
	 $(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) Ig_$*_$(PADS_KIND).time

process_SyS_%: $(TIMING_DIR)/SyS_%_$(PADS_KIND).time
	@export PROCESS_ONLY=1;\
	$(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) SyS_$*_$(PADS_KIND).time

process_CaS_%: $(TIMING_DIR)/CaS_%_$(PADS_KIND).time
	@export PROCESS_ONLY=1;\
	$(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $*.$(PADS_SIZE) CaS_$*_$(PADS_KIND).time


# do_time_pads: time_CaS_$(PADS_FORMAT)
# do_time_pglx: pglx_$(PGLX_KIND)_$(PGLX_FORMAT)
# 	 ./$< $(DATA_DIR)/$(PGLX_FORMAT).$(PGLX_SIZE) >| $(TIMING_DIR)/$<_$(PGLX_SIZE).time

do_time_pglx: pglx_$(PGLX_KIND)_$(PGLX_FORMAT)
	 $(TIMING_SCR) ./$<  $(DATA_DIR) $(TIMING_DIR) $(PGLX_FORMAT).$(PGLX_SIZE) \
	$(PGLX_FORMAT)_$(PGLX_SIZE)_$(PGLX_KIND).time

TIME_ALL_MASKS=$(foreach mask,$(RMASKS),time_all_$(mask))
TIME_ALL_FORMATS=$(foreach fmt,$(TFORMATS),time_all_$(fmt))
PROCESS_ALL_MASKS=$(foreach mask,$(RMASKS),process_all_$(mask))
PROCESS_ALL_FORMATS=$(foreach fmt,$(TFORMATS),process_all_$(fmt))

$(TIME_ALL_FORMATS):time_all_%:$(foreach mask,$(RMASKS),time_$(mask)_%)
$(TIME_ALL_MASKS): time_all_%:$(foreach fmt,$(TFORMATS),time_%_$(fmt))
time_all: $(foreach fmt,$(TFORMATS),time_all_$(fmt))

$(PROCESS_ALL_FORMATS):process_all_%:$(foreach mask,$(RMASKS),process_$(mask)_%)
$(PROCESS_ALL_MASKS): process_all_%:$(foreach fmt,$(TFORMATS),process_%_$(fmt))
process_all: $(foreach fmt,$(TFORMATS),process_all_$(fmt))

$(DATA_DIR)/dibbler_new.10MB:$(DATA_DIR)/dibbler.10001
	$(PADS_HOME)/scripts/gendata.sh $(DATA_DIR) dibbler 10000000 dibbler_new.10MB

$(DATA_DIR)/dibbler_new.50MB:$(DATA_DIR)/dibbler.10001
	$(PADS_HOME)/scripts/gendata.sh $(DATA_DIR) dibbler 50000000 dibbler_new.50MB

$(DATA_DIR)/dibbler_new.100MB:$(DATA_DIR)/dibbler.10001
	$(PADS_HOME)/scripts/gendata.sh $(DATA_DIR) dibbler 100000000 dibbler_new.100MB

$(DATA_DIR)/dibbler_new.big:$(DATA_DIR)/dibbler.10001
	$(PADS_HOME)/scripts/gendata.sh $(DATA_DIR) dibbler 5000000 dibbler_new.big

$(DATA_DIR)/dns.big: $(DATA_DIR)/dns
	$(PADS_HOME)/scripts/gendata.sh $(DATA_DIR) dns 5000000 dns.big

gendata: $(DATA_DIR)/dibbler_new.big $(DATA_DIR)/dns.big

test_copy_format5: $(GEN_DIR)/format5.c test_copy_format5.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_copy_format5_d: $(GEN_DIR)/format5.c test_copy_format5.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_write_struct1: $(GEN_DIR)/struct1.c test_write_struct1.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_write_struct1_d: $(GEN_DIR)/struct1.c test_write_struct1.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_write_struct_strings: $(GEN_DIR)/struct_strings.c test_write_struct_strings.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_write_struct_strings_d: $(GEN_DIR)/struct_strings.c test_write_struct_strings.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_copy_ai: $(GEN_DIR)/ai.c test_copy_ai.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_copy_ai_d: $(GEN_DIR)/ai.c test_copy_ai.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

regress_test_dibbler_new:	test_dibbler_new
	@(args=""; suf=""; $(RegressDef))
perf_regress_test_dibbler_new:	test_dibbler_new
	@(args=""; suf=""; $(PerfRegressDef))
regress_rwxml_dibbler_new:	rwxml_dibbler_new
	@(args=""; input="../../data/dibbler.10001"; suf=""; $(RegressInput))
perf_regress_rwxml_dibbler_new:	rwxml_dibbler_new
	@(args=""; input="../../data/dibbler.10001"; suf=""; $(PerfRegressInput))
#regress_test_format1_d: test_format1_d
#	@(args=""; suf=""; $(RegressDef))
#perf_regress_test_format1_o: test_format1
#	@(args=""; suf=""; $(PerfRegressDef))
#perf_regress_test_format1_d: test_format1_d
#	@(args=""; suf=""; $(PerfRegressDef))

count_dibbler: $(GEN_DIR)/dibbler_notrailer.c count_dibbler.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
count_dibbler_d: $(GEN_DIR)/dibbler_notrailer.c count_dibbler.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

filter_dibbler: $(GEN_DIR)/dibbler_new.c filter_dibbler.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
filter_dibbler_d: $(GEN_DIR)/dibbler_new.c filter_dibbler.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

filter_dibbler2: $(GEN_DIR)/dibbler_new.c filter_dibbler2.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
filter_dibbler2_d: $(GEN_DIR)/dibbler_new.c filter_dibbler2.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

dibbler_vetter: $(GEN_DIR)/dibbler_new.c dibbler_vetter.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
dibbler_vetter_d: $(GEN_DIR)/dibbler_new.c dibbler_vetter.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

dibblr_select: $(GEN_DIR)/dibbler_new.c dibbler_select.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
dibbler_select_d: $(GEN_DIR)/dibbler_new.c dibbler_select.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

dibbler_select_first: $(GEN_DIR)/dibbler_new2.c dibbler_select_first.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
dibbler_select_first_d: $(GEN_DIR)/dibbler_new2.c dibbler_select_first.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

pads_count_lines: pads_count_lines.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
pads_count_lines_d: pads_count_lines.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

ifdef GEN_DIR
$(GEN_DIR)/dibbler_select_expanded.c: $(GEN_DIR)/dibbler_select_expanded.c
	$(MKSRC_D) $< | $(PADS_HOME)/scripts/addnl.pl > $@
endif

dibbler_select_dd: $(GEN_DIR)/dibbler_select_expanded.c dibbler_select.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule R_DD"
endif
	@$(CCExec_DYNAMIC_D)

test_hist: $(GEN_DIR)/ai.c $(PADS_HOME)/padsc/libpads/pads-hist.c test_hist.c $(INCLUDE_DEDS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_hist_d: $(GEN_DIR)/ai.c $(PADS_HOME)/padsc/libpads/pads-hist.c test_hist.c $(INCLUDE_DEDS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_cluster: $(GEN_DIR)/ai.c $(PADS_HOME)/padsc/libpads/pads-cluster.c test_cluster.c $(INCLUDE_DEDS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)
test_cluster_d: $(GEN_DIR)/ai.c $(PADS_HOME)/padsc/libpads/pads-cluster.c test_cluster.c $(INCLUDE_DEDS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

regress_accum: regress_accum_2ips regress_accum_array regress_accum_array_advance regress_accum_depends regress_accum_enum  regress_accum_pfloat regress_accum_ptimestamp regress_accum_punion regress_accum_struct1 regress_accum_typedef

regress_accum_%: accum_%
	(accum_$* ../../data/$* -report-good -report-bad >$*_accum.xml; \
	echo "*** Validate $*_accum.xml"; \
	 $(GALAX_HOME)/bin/galax-parse -validate on -xmlschema $(PADS_HOME)/padsc/schemata/pads-accum.xsd $*_accum.xml; \
	echo "*** Validate $*_bad.xml"; \
	 if [ -s $*_bad.xml ]; then $(GALAX_HOME)/bin/galax-parse -validate on -xmlschema $(GEN_DIR)/$*.xsd $*_bad.xml; fi ;\
	echo "*** Validate $*_good.xml"; \
	 if [ -s $*_good.xml ]; then $(GALAX_HOME)/bin/galax-parse -validate on -xmlschema $(GEN_DIR)/$*.xsd $*_good.xml; fi ; \
	echo "*** Validate $*.pxml"; \
	 $(GALAX_HOME)/bin/galax-parse -validate on -xmlschema $(PADS_HOME)/padsc/schemata/pads-xml.xsd $(GEN_DIR)/$*.pxml; \
	)

ifdef GALAX_NONE
test_children: var_error

test_children_d: var_error

var_error:
	@echo " "
	@echo "ERROR: to build test_children you must use one of the following"
	@echo "   gmake GEN_GALAX=1 <target>"
	@echo "   gmake USE_GALAX=1 <target>"
	@echo " "
	@echo "GEN_GALAX: use the libpglx with fake calls to Galax API"
	@echo "USE_GALAX: use the libpglx with real calls to Galax API"
	@echo " "
	@echo "(you must build libpglx with the same option for things to work properly)"
	@echo " "

else
test_children: $(GEN_DIR)/format1.c test_children.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

test_children_d: $(GEN_DIR)/format1.c test_children.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)
endif

$(GEN_DIR)/http.c:
	$(PADS_HOME)/scripts/padsc -anone ../../p/http.p  -r ../../gen -I. -I..

 # End of rules that are run from the arch directory
endif
