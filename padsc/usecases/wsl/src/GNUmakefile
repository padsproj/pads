
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../../../..; pwd)
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

# the following indicates that generated files should not be removed
.PRECIOUS: %.o $(GEN_DIR)/%.c $(GEN_DIR)/%_expanded.c %_expanded.c

# need to set this before including rules.mk
REGRESS_TESTS = 1

include $(PADS_HOME)/mk/rules.mk

VPATH =  .. ../../p

ifndef GEN_GALAX
ifndef USE_GALAX
GALAX_NONE = 1
endif
endif

ALL_TESTS = test_wsl rwxml_wsl fmt_wsl
REGRESS_TESTS = $(ALL_TESTS:%=regress_%)

all: regress

regress: sanity_check $(REGRESS_TESTS)
	@echo " "; echo "DONE"; echo " "

sanity_check:
	@$(SanityCheck)

regress_test_wsl: test_wsl
	@(args=""; suf=""; $(RegressDef))

regress_fmt_wsl: fmt_wsl
	@(args=""; suf=""; $(RegressDef))

regress_rwxml_wsl: rwxml_wsl
	@(args=""; suf=""; $(RegressDef))

clean:
	$(RM) -f *~ *.o $(ALL_TESTS)

veryclean: clean
	$(RM) $(GEN_DIR)/*.[hc] $(GEN_DIR)/*.xsd tmp/*

 # End of rules that are run from the arch directory
endif
