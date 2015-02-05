
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell cd ../..; pwd)
endif

ifndef AST_ARCH
  export AST_ARCH=$(shell $(PADS_HOME)/ast-ast/bin/package.cvs)
endif

CURDIR := $(shell pwd)
ifneq ($(AST_ARCH),$(notdir $(CURDIR)))
include $(PADS_HOME)/mk/redirect.mk
else

 # The following rules are run from the arch directory

SCRIPTS = $(PADS_HOME)/scripts
BuildPADSLib = 1
INCLUDE_DEPS_ADD = *-gen.h
include $(PADS_HOME)/mk/rules.mk

VPATH = ..

SRC_INCDIR = $(PADS_HOME)/padsc/include
PCGEN_IN = $(SRC_INCDIR)/pcgen-macros.h
PCGEN = $(SRC_INCDIR)/pcgen-macros-gen.h

OBJS_O = default_io_disc.o pads-gen.o pads-acc-gen.o pads-read-gen.o pads-write-gen.o pads-misc-gen.o rbuf.o pads-hist.o pads-cluster.o

OBJS_D = $(OBJS_O:%.o=%_d.o)

GEN_FILES = pads-acc-gen.c \
            pads-misc-gen.c \
            pads-acc-macros-gen.h  \
            pads-misc-macros-gen.h \
            pads-gen.c             \
            pads-read-gen.c \
            pads-write-gen.c \
            pads-macros-gen.h      \
            pads-read-macros-gen.h \
            pads-write-macros-gen.h

all :
	@$(MAKE) -f ../GNUmakefile dogen
	@$(MAKE) -f ../GNUmakefile real_all


foo:
	echo USE_GALAX = '$(USE_GALAX)'
	echo STATIC_LIBS_O = '$(STATIC_LIBS_O)'
	echo STATIC_LIBS_D = '$(STATIC_LIBS_D)'
	echo OS_SPEC_XTRA_LIBS = '$(OS_SPEC_XTRA_LIBS)'
	echo OPSYS = '$(OPSYS)'
	echo ARCH_N_OPSYS = '$(ARCH_N_OPSYS)'
	echo LINK_INTO_SHARED_O = '$(LINK_INTO_SHARED_O)'

opt :
	@$(MAKE) -f ../GNUmakefile dogen
	@$(MAKE) -f ../GNUmakefile real_opt

debug :
	@$(MAKE) -f ../GNUmakefile dogen
	@$(MAKE) -f ../GNUmakefile real_debug

ifdef FORCE_STATIC
OPT_TARGS = $(STATIC_PADSLIB_NM_O)
DBG_TARGS = $(STATIC_PADSLIB_NM_D)
ALL_TARGS = $(STATIC_PADSLIB_NM_O) $(STATIC_PADSLIB_NM_D)
else
OPT_TARGS = $(STATIC_PADSLIB_NM_O) $(SHARED_PADSLIB_NM_O)
DBG_TARGS = $(STATIC_PADSLIB_NM_D) $(SHARED_PADSLIB_NM_D)
ALL_TARGS = $(STATIC_PADSLIB_NM_O) $(SHARED_PADSLIB_NM_O) $(STATIC_PADSLIB_NM_D) $(SHARED_PADSLIB_NM_D)
endif

real_all : $(ALL_TARGS)

real_opt : $(OPT_TARGS)

real_debug : $(DBG_TARGS)

$(STATIC_PADSLIB_NM_O) : $(OBJS_O)
	$(STATIC_LIBTOOL) $(STATIC_PADSLIB_NM_O) $(STATIC_LIBTOOL_OPTS) $^
	(lib=$@; $(FixStaticLib))

$(SHARED_PADSLIB_NM_O) : $(OBJS_O) $(LINK_INTO_SHARED_O)
	$(SHARED_LIBTOOL) -o $(SHARED_PADSLIB_NM_O) $(SHARED_LIBTOOL_WHOLE_ARCHIVE) \
        $^ $(SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE) $(SHARED_LIBTOOL_OPTS)

$(STATIC_PADSLIB_NM_D) : $(OBJS_D)
	$(STATIC_LIBTOOL) $(STATIC_PADSLIB_NM_D) $(STATIC_LIBTOOL_OPTS) $^
	(lib=$@; $(FixStaticLib))

$(SHARED_PADSLIB_NM_D) : $(OBJS_D) $(LINK_INTO_SHARED_D)
	$(SHARED_LIBTOOL) -o $(SHARED_PADSLIB_NM_D) $(SHARED_LIBTOOL_WHOLE_ARCHIVE) \
        $^ $(SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE) $(SHARED_LIBTOOL_OPTS)

install_static : all
	+@(set -x ; \
	mkdir -p $(INSTALL_LIBDIR); \
	for file in $(ASTLIBS); do \
		$(PADS_HOME)/scripts/install-sh -c -m 444 $(INSTALLROOT)/lib/$$file $(INSTALL_LIBDIR); \
		(lib=$(INSTALL_LIBDIR)/$$file; $(FixStaticLib)); \
	done; \
	$(PADS_HOME)/scripts/install-sh -c -m 444 $(STATIC_PADSLIB_NM_O) $(INSTALL_LIBDIR); \
	(lib=$(INSTALL_LIBDIR)/$(STATIC_PADSLIB_NM_O); $(FixStaticLib)); \
	$(PADS_HOME)/scripts/install-sh -c -m 444 $(STATIC_PADSLIB_NM_D) $(INSTALL_LIBDIR); \
	(lib=$(INSTALL_LIBDIR)/$(STATIC_PADSLIB_NM_D); $(FixStaticLib)) )
	@(cd $(SRC_INCDIR); $(MAKE) -f GNUmakefile install)

install_dynamic : all
	+@(set -x ; \
	mkdir -p $(INSTALL_LIBDIR); \
	$(PADS_HOME)/scripts/install-sh -c -m 555 $(SHARED_PADSLIB_NM_O) $(INSTALL_LIBDIR); \
	$(PADS_HOME)/scripts/install-sh -c -m 555 $(SHARED_PADSLIB_NM_D) $(INSTALL_LIBDIR); \
	( cd $(INSTALL_LIBDIR); \
	  $(RM) $(SHARED_PADSLIB_NM_ALT1_O); \
	  ln $(SHARED_PADSLIB_NM_O) $(SHARED_PADSLIB_NM_ALT1_O); \
	  $(RM) $(SHARED_PADSLIB_NM_ALT2_O); \
	  ln $(SHARED_PADSLIB_NM_O) $(SHARED_PADSLIB_NM_ALT2_O); \
	  $(RM) $(SHARED_PADSLIB_NM_ALT1_D); \
	  ln $(SHARED_PADSLIB_NM_D) $(SHARED_PADSLIB_NM_ALT1_D); \
	  $(RM) $(SHARED_PADSLIB_NM_ALT2_D); \
	  ln $(SHARED_PADSLIB_NM_D) $(SHARED_PADSLIB_NM_ALT2_D); \
	  ) )

INSTALL_TARGETS = install_static

ifndef FORCE_STATIC
INSTALL_TARGETS += install_dynamic
endif

install : $(INSTALL_TARGETS)

dogen : $(PCGEN) $(SCRIPTS)/mksrc.pl $(PADS_HOME)/padsc/libpads/pads.c $(INCLUDE_DEPS)
	@echo "Building generated source files"
	$(SCRIPTS)/mksrc.pl $(CC) $(PADS_HOME)/padsc/libpads/pads.c $(CURDIR) $(PADS_HOME)
	touch dogen

$(PCGEN) : $(SCRIPTS)/mksrc.pl $(PCGEN_IN)
	@(cd $(SRC_INCDIR); $(MAKE) -f GNUmakefile all)

pads-gen-g.o: pads-gen.c $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule A-mod-D"
endif
	$(COMPILE_D) -c $< -o $@

pads-gen.o: pads-gen.c $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule A-mod-O"
endif
	$(COMPILE_O) -c $< -o $@

clean :
	$(RM) *~ *.o ../*~
	$(RM) $(NORMAL_STATIC_PADSLIB_NM_O) $(NORMAL_SHARED_PADSLIB_NM_O) $(NORMAL_STATIC_PADSLIB_NM_D) $(NORMAL_SHARED_PADSLIB_NM_D)
	$(RM) $(GALAX_STATIC_PADSLIB_NM_O) $(GALAX_SHARED_PADSLIB_NM_O) $(GALAX_STATIC_PADSLIB_NM_D) $(GALAX_SHARED_PADSLIB_NM_D)

veryclean : clean
	$(RM) dogen $(GEN_FILES)

 # End of rules that are run from the arch directory
endif
