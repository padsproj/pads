
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../..; pwd)
endif

SUBDIRS = simple wsl sirius syslog simple2

all:
	+@(for subdir in $(SUBDIRS); do \
		(cd $$subdir; $(MAKE) -f GNUmakefile ); \
	done)

regress:
	+@(for subdir in $(SUBDIRS); do \
		(cd $$subdir; $(MAKE) -f GNUmakefile regress); \
	done)

clean:
	+@(for subdir in $(SUBDIRS); do \
		(cd $$subdir; $(MAKE) -f GNUmakefile clean); \
	done)

veryclean:
	+@(for subdir in $(SUBDIRS); do \
		(cd $$subdir; $(MAKE) -f GNUmakefile veryclean); \
	done)
