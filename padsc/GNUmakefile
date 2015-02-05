
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ..; pwd)
endif

TARGS = padsc_lib
ifdef USE_GALAX
TARGS +=  pads_glx pglx_lib
endif
TARGS += padsc_comp

all:	$(TARGS)

padsc_lib:
	echo Making padsc library
	@(cd libpads; $(MAKE) -f GNUmakefile install)

pglx_lib:
	echo Making pglx library
	@(cd libpglx; $(MAKE) -f GNUmakefile install)

pads_glx:
	echo Making pads-glx library
	@(cd pads-glx; $(MAKE) -f GNUmakefile install)

padsc_comp:
	echo Making padsc compiler
	@(cd comp; $(MAKE) -f GNUmakefile all)

regress:
	@(cd libpads/tests; $(MAKE) -f GNUmakefile regress; echo "Finished runtime regression."; cd ../../examples/tests; $(MAKE) -f GNUmakefile regress; echo "Finished example regression.") | $(PADS_HOME)/scripts/count_differs.pl

pglx_regress:
	@(cd tests_pglx; $(MAKE) -f GNUmakefile ) | $(PADS_HOME)/scripts/count_differs.pl

usecase_regress:
	@(cd usecases; $(MAKE) -f GNUmakefile ) | $(PADS_HOME)/scripts/count_differs.pl

perf_regress:
	@(cd libpads/tests; $(MAKE) -f GNUmakefile perf_regress; cd ../../perf; $(MAKE) -f GNUmakefile perf_regress ; \
	cd ../examples/tests; $(MAKE) -f GNUmakefile perf_regress ) | $(PADS_HOME)/scripts/count_differs.pl

test_xml:
	@(cd examples/xml/tests; $(MAKE) -f GNUmakefile regress) 

test_libpads:
	@(cd libpads/tests; $(MAKE) -f GNUmakefile ) | $(PADS_HOME)/scripts/count_differs.pl

test_comp:
	@(cd examples/tests; $(MAKE) -f GNUmakefile ) | $(PADS_HOME)/scripts/count_differs.pl

clean:
	@(cd comp; $(MAKE) -f GNUmakefile clean)
	@(cd libpads; $(MAKE) -f GNUmakefile clean)
	@(if [ -d usecases ]; then cd usecases; $(MAKE) -f GNUmakefile clean; fi)
ifdef USE_GALAX
	@(cd pads-glx; $(MAKE) -f GNUmakefile clean)
	@(cd libpglx; $(MAKE) -f GNUmakefile clean)
endif

veryclean:
	@(cd comp; $(MAKE) -f GNUmakefile veryclean)
	@(cd libpads; $(MAKE) -f GNUmakefile veryclean)
	@(if [ -d usecases ]; then cd usecases; $(MAKE) -f GNUmakefile veryclean; fi)
ifdef USE_GALAX
	@(cd pads-glx; $(MAKE) -f GNUmakefile veryclean)
	@(cd libpglx; $(MAKE) -f GNUmakefile veryclean)
endif
