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
GEN_DIR = ..
GEN_WRITE = 1

CODE_DIR = ../
USE_GALAX = 1

XML_DIR =../../xml/

VPATH = ..

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

# DEP_myenum =

BULK_QUERY_TESTS=test_bulk_pfloat
REGRESS_TESTS=regress_pfloat

ALL_TESTS_O = $(BULK_QUERY_TESTS)
ALL_TESTS_D = $(ALL_TESTS_O:%=%_d)
ALL_TESTS = $(ALL_TESTS_O) $(ALL_TESTS_D)

.PHONY: pglx_lib clean
# Test bulk load & query
test_bulk_%-d: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/test_bulk_%.c $(TEMPL_DIR)/pglx_bulk_query.h $(INCLUDE_DEPS) $(LIB_DEPS_D)
	@$(CCExec_DYNAMIC_D)

test_bulk_%: $(GEN_DIR)/%.c $(CODE_DIR)/test_%.h  $(CODE_DIR)/test_bulk_%.c $(TEMPL_DIR)/pglx_bulk_query.h $(INCLUDE_DEPS) $(LIB_DEPS_O)
	@$(CCExec_DYNAMIC_O)

pglx_lib:
	@(cd $(PADS_HOME)/padsc; $(MAKE) -f GNUmakefile pglx_lib)

# REGRESSION TESTS
compare_files:
	(cmp $${S} $${T} && echo "*** OK: $${N} PASSED") || echo "*** ERROR: $${N} FAILED" 

regress_bulk_%: test_bulk_% 
	./$? 
	$(MAKE) -f ../GNUmakefile -k -s N=test_bulk_$* S=test_bulk_$*.xml T=../../regress/test_$*.xml compare_files

regress_pfloat: regress_bulk_pfloat

#regress: $(REGRESS_TESTS)

regress: regress_pfloat

clean:
	$(RM) -f *~ *.o $(ALL_TESTS) 

veryclean: clean
	$(RM) $(GEN_DIR)/*.[hc] $(GEN_DIR)/*.xsd *.xml

 # End of rules that are run from the arch directory
endif
