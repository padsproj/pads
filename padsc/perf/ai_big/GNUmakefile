
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../../..; pwd)
endif

.PHONY	: regress perf_regress

all:
	@(cd src; $(MAKE))

regress:
	(cd src; $(MAKE) regress)

perf_regress:
	@(cd src; $(MAKE) perf_regress)

clean:
	@(cd src; $(MAKE) clean)

veryclean:
	@(cd src; $(MAKE) veryclean)
