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
GEN_DIR =../../gen
GEN_WRITE = 1

CODE_DIR =../
USE_GALAX = 1

XML_DIR =../../xml/

VPATH = ../../../p

# the following indicates that generated .c files should not be removed
.PRECIOUS: $(GEN_DIR)/%.c $(GEN_DIR)/%_expanded.c 

# need to give these rules before including rules.mk
REGRESS_TESTS = 1

CURDIR := $(shell pwd)
SCRIPTS = $(PADS_HOME)/scripts

include $(PADS_HOME)/mk/rules.mk

# Extend the INCLUDES after including rules.mk
TEMPL_DIR=$(PADS_HOME)/padsc/include/template
INCLUDES += -I$(TEMPL_DIR)

ifdef GALAXCOMPILE
CDBGFLAGS += -DGALAXCOMPILE
COPTFLAGS += -DGALAXCOMPILE
endif

ifeq ($(PADS_KIND),bulk)
COPTFLAGS += -D PADS_BULK
endif 

ifeq ($(PADS_KIND),smart)
COPTFLAGS += -D PADS_SMART
endif

ifeq ($(PADS_KIND),linear)
CDBGFLAGS += -D MAX_ELTS=1
COPTFLAGS += -D MAX_ELTS=1
COPTFLAGS += -D PADS_SMART
endif

ifdef MAX_ELTS
CDBGFLAGS += -D MAX_ELTS=$(MAX_ELTS)
COPTFLAGS += -D MAX_ELTS=$(MAX_ELTS)
endif

ifdef MAX_NODES
CDBGFLAGS += -D MAX_NODES=$(MAX_NODES)
COPTFLAGS += -D MAX_NODES=$(MAX_NODES)
endif

# DEP_myenum =

LOAD_TESTS=load_format7 load_ai load_dns load_dibbler_notrailer
BULK_QUERY_TESTS=bulk_format7 bulk_ai bulk_dns bulk_dibbler_notrailer
SMART_QUERY_TESTS=smart_format7 smart_ai smart_dibbler_notrailer
REGRESS_TESTS=regress_format7 regress_ai regress_dns regress_dibbler_notrailer

ALL_TESTS_O = $(LOAD_TESTS) $(BULK_QUERY_TESTS) $(SMART_QUERY_TESTS)
ALL_TESTS_D = $(ALL_TESTS_O:%=%_d)
ALL_TESTS = $(ALL_TESTS_O) $(ALL_TESTS_D)

.PHONY: pglx_lib clean

foo:
	echo "INCLUDE_DEPS=$(INCLUDE_DEPS)"
	echo "LIB_DEPS_D=$(LIB_DEPS_D)"

# Test O'Caml tree walk
walk_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/walk_%.c $(TEMPL_DIR)/pglx_load.h $(INCLUDE_DEPS) $(LIB_DEPS_D) 
	@$(CCExec_DYNAMIC_D)

walk_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/walk_%.c $(TEMPL_DIR)/pglx_load.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

load_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/load_%.c $(TEMPL_DIR)/pglx_load.h $(INCLUDE_DEPS) $(LIB_DEPS_D) 
	@$(CCExec_DYNAMIC_D)

load_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/load_%.c $(TEMPL_DIR)/pglx_load.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

# Test bulk load & query
bulk_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/bulk_%.c $(TEMPL_DIR)/pglx_bulk_query.h $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

bulk_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/bulk_%.c $(TEMPL_DIR)/pglx_bulk_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

bulk_%_dd: $(GEN_DIR)/%_expanded.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/bulk_%.c $(TEMPL_DIR)/pglx_bulk_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

# Test linear load & query
linear_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/smart_%.c $(TEMPL_DIR)/pglx_smart_query.h $(INCLUDE_DEPS) $(LIB_DEPS_D)  
	@$(CCExec_DYNAMIC_D)

linear_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/smart_%.c $(TEMPL_DIR)/pglx_smart_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

# Test smart load & query
smart_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/smart_%.c $(TEMPL_DIR)/pglx_smart_query.h $(INCLUDE_DEPS) $(LIB_DEPS_D)  
	@$(CCExec_DYNAMIC_D)

smart_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/smart_%.c $(TEMPL_DIR)/pglx_smart_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

smart_%_dd: $(GEN_DIR)/%_expanded.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/smart_%.c $(TEMPL_DIR)/pglx_smart_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

# Miscellaneous tests
test_kth_child_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_kth_child_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

test_kth_child_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_kth_child_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)  
	@$(CCExec_DYNAMIC_D)

test_rr_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_rr_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

test_rr_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_rr_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)  
	@$(CCExec_DYNAMIC_D)

pglx_lib:
	@(cd $(PADS_HOME)/padsc; $(MAKE) -f GNUmakefile pglx_lib)

# REGRESSION TESTS
compare_files:
	(cmp $${S} $${T} && echo "*** OK: $${N} PASSED") || echo "*** ERROR: $${N} FAILED" 

regress_load_%: load_% 
	./$? 
	$(MAKE) -f ../GNUmakefile -k -s N=load_$* S=load_$*.xml T=../../regress/$*.xml compare_files

regress_bulk_%: bulk_% 
	./$? 
	$(MAKE) -f ../GNUmakefile -k -s N=bulk_$* S=bulk_$*.xml T=../../regress/$*.xml compare_files

regress_smart_%: smart_% 
	./$? 
	$(MAKE) -f ../GNUmakefile -k -s N=smart_$* S=smart_$*.xml T=../../regress/$*.xml compare_files

regress_format7: regress_load_format7 regress_bulk_format7 regress_smart_format7 schema_format7

regress_ai: regress_load_ai regress_bulk_ai regress_smart_ai schema_ai 

regress_dns: regress_load_dns regress_bulk_dns schema_dns 

regress_dibbler_notrailer: regress_load_dibbler_notrailer regress_bulk_dibbler_notrailer regress_smart_dibbler_notrailer schema_dibbler_notrailer

regress: $(REGRESS_TESTS)

# XML Schema Tests

schema_%: load_%
	./$?
	$(GALAX_HOME)/bin/galax-parse load_$*.xml -validate on -xmlschema ../../gen/$*.xsd

#	$(MAKE) -f ../GNUmakefile -k -s N=schema_$* S=schema_$*.xml T=../../regress/schema_$*.xml compare_files

ifeq ($(PGLX_KIND),bulk)
COPTFLAGS += -D PGLX_BULK -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=$(PGLX_ALLOC_HINT)
endif
ifeq ($(PGLX_KIND),linear)
COPTFLAGS += -D PGLX_LINEAR -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=$(PGLX_ALLOC_HINT)
endif
ifeq ($(PGLX_KIND),smart)
COPTFLAGS += -D PGLX_SMART -DE_REP_LEV=PerrorRep_None -D PADS_ALLOC_HINT=$(PGLX_ALLOC_HINT)
endif

# Test O'Caml tree walk
walk_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/walk_%.c \
$(TEMPL_DIR)/pglx_walk_tree.h $(INCLUDE_DEPS) $(LIB_DEPS_D) 
	@$(CCExec_DYNAMIC_D)

walk_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h $(CODE_DIR)/walk_%.c \
$(TEMPL_DIR)/pglx_walk_tree.h $(INCLUDE_DEPS) $(LIB_DEPS_O)  
	@$(CCExec_DYNAMIC_O)

#regress: regress_ai

clean:
	$(RM) -f *~ *.o $(ALL_TESTS) 

veryclean: clean
	$(RM) $(GEN_DIR)/*.[hc] $(GEN_DIR)/*.xsd *.xml

 # End of rules that are run from the arch directory
endif
