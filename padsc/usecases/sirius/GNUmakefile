
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../../..; pwd)
endif

all:
	@(cd src; $(MAKE) -f GNUmakefile )

regress:
	@(cd src; $(MAKE) -f GNUmakefile regress)

clean:
	@(cd src; $(MAKE) -f GNUmakefile clean)

veryclean:
	@(cd src; $(MAKE) -f GNUmakefile veryclean)
