
 # This is a GNU makefile

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../..; pwd)
endif
include $(PADS_HOME)/mk/rules.mk

ifndef SML
  export SML=sml
endif

SML_VER = $(shell $(SML) '@SMLversion' | sed -e 's|.* ||')
SML_MINOR_VER = $(shell echo $(SML_VER) | sed -e 's|.*[.]||')
ifeq ($(SML_VER),$(SML_MINOR_VER))
SML_MINOR_VER = 0
endif
SML_MINOR_VER_TEST=$(shell test $(SML_MINOR_VER) -gt 39 && echo GT39)

ifeq ($(SML_MINOR_VER_TEST),GT39)
BUILD_EXEC = build-exec-45.sml
else
BUILD_EXEC = build-exec.sml
endif

all:	compiler

foo:
	@(echo SML = $(SML))
	@(echo SML_VER = $(SML_VER))
	@(echo SML_MINOR_VER = $(SML_MINOR_VER))
	@(echo SML_MINOR_VER_TEST = $(SML_MINOR_VER_TEST))
	@(echo BUILD_EXEC = $(BUILD_EXEC))

compiler:
	echo Making compiler
	$(SML) < $(BUILD_EXEC)

clean:
	$(RM) $(PADS_HOME)/lib/padsc.$(ARCH_N_OPSYS)
	@(cd ckit; x="`find . -name \*~`"; if [ "$$x"x != x ]; then echo "In ckit, removing:\n$$x"; $(RM) $$x; fi)

veryclean: clean
	@(echo "Removing .cm .bin files"; if [ -d .cm ]; then cd .cm; x="`find . -name .cm`"; if [ "$$x"x != x ]; then echo "In .cm, removing:\n$$x"; $(RM) -rf $$x; fi; fi)
	@(echo "Removing ckit .bin files"; cd ckit; x="`find . -name .cm`"; if [ "$$x"x != x ]; then echo "In ckit, removing:$$x"; $(RM) -rf $$x; fi)
	@(echo "Removing util .bin files"; cd util; x="`find . -name .cm`"; if [ "$$x"x != x ]; then echo "In util, removing:$$x"; $(RM) -rf $$x; fi)
	@(echo "Cleaning parser files"; cd ckit/src/parser/grammar; $(MAKE) -f Makefile clean)

redo_all:
	+@(for file in examples/p/*.p; do \
		echo $(PADS_HOME)/scripts/padsc $$file; \
		$(PADS_HOME)/scripts/padsc $$file; \
	done;)
