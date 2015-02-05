
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

USE_GALAX=1
SCRIPTS = $(PADS_HOME)/scripts
BuildPADSLib = 1
BuildPGLXLib = 1
include $(PADS_HOME)/mk/rules.mk

VPATH = ..

OBJS_O = pglx.o node_mm.o pglx-free-list.o path_walk.o smart.o

OBJS_D = $(OBJS_O:%.o=%_d.o)

INSTALL_INCLUDES = pglx.h

all : $(STATIC_PGLXLIB_NM_O) $(SHARED_PGLXLIB_NM_O) $(STATIC_PGLXLIB_NM_D) $(SHARED_PGLXLIB_NM_D)

opt : $(STATIC_PGLXLIB_NM_O) $(SHARED_PGLXLIB_NM_O)

debug : $(STATIC_PGLXLIB_NM_D) $(SHARED_PGLXLIB_NM_D)

$(STATIC_PGLXLIB_NM_O) : $(OBJS_O)
	$(STATIC_LIBTOOL) $(STATIC_PGLXLIB_NM_O) $(STATIC_LIBTOOL_OPTS) $(OBJS_O)
	(lib=$@; $(FixStaticLib))

$(SHARED_PGLXLIB_NM_O) : $(OBJ_O) $(LINK_INTO_SHARED_O)
	$(SHARED_LIBTOOL) -o $(SHARED_PGLXLIB_NM_O) $(SHARED_LIBTOOL_WHOLE_ARCHIVE) \
        $(OBJS_O) $(SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE) $(LINK_INTO_SHARED_O) $(SHARED_LIBTOOL_OPTS)

$(STATIC_PGLXLIB_NM_D) : $(OBJS_D)
	$(STATIC_LIBTOOL) $(STATIC_PGLXLIB_NM_D) $(STATIC_LIBTOOL_OPTS) $(OBJS_D)
	(lib=$@; $(FixStaticLib))

$(SHARED_PGLXLIB_NM_D) : $(OBJS_D) $(LINK_INTO_SHARED_D)
	$(SHARED_LIBTOOL) -o $(SHARED_PGLXLIB_NM_D) $(SHARED_LIBTOOL_WHOLE_ARCHIVE) \
        $(OBJS_D) $(SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE) $(LINK_INTO_SHARED_D) $(SHARED_LIBTOOL_OPTS)

install : all
	+@(set -x ; \
	$(PADS_HOME)/scripts/install-sh -c -m 444 $(STATIC_PGLXLIB_NM_O) $(INSTALL_LIBDIR); \
	(lib=$(INSTALL_LIBDIR)/$(STATIC_PGLXLIB_NM_O); $(FixStaticLib)); \
	$(PADS_HOME)/scripts/install-sh -c -m 555 $(SHARED_PGLXLIB_NM_O) $(INSTALL_LIBDIR); \
	$(PADS_HOME)/scripts/install-sh -c -m 444 $(STATIC_PGLXLIB_NM_D) $(INSTALL_LIBDIR); \
	(lib=$(INSTALL_LIBDIR)/$(STATIC_PGLXLIB_NM_D); $(FixStaticLib)); \
	$(PADS_HOME)/scripts/install-sh -c -m 555 $(SHARED_PGLXLIB_NM_D) $(INSTALL_LIBDIR); \
	( cd $(INSTALL_LIBDIR); \
	  $(RM) $(SHARED_PGLXLIB_NM_ALT1_O); \
	  ln $(SHARED_PGLXLIB_NM_O) $(SHARED_PGLXLIB_NM_ALT1_O); \
	  $(RM) $(SHARED_PGLXLIB_NM_ALT2_O); \
	  ln $(SHARED_PGLXLIB_NM_O) $(SHARED_PGLXLIB_NM_ALT2_O); \
	  $(RM) $(SHARED_PGLXLIB_NM_ALT1_D); \
	  ln $(SHARED_PGLXLIB_NM_D) $(SHARED_PGLXLIB_NM_ALT1_D); \
	  $(RM) $(SHARED_PGLXLIB_NM_ALT2_D); \
	  ln $(SHARED_PGLXLIB_NM_D) $(SHARED_PGLXLIB_NM_ALT2_D); \
	  ); \
	for file in $(INSTALL_INCLUDES); do \
		$(PADS_HOME)/scripts/install-sh -c -m 444 $(PADS_HOME)/padsc/include/$$file $(INSTALL_INCDIR); \
	done;)

clean :
	$(RM) $(STATIC_PGLXLIB_NM_O) $(SHARED_PGLXLIB_NM_O) $(STATIC_PGLXLIB_NM_D) $(SHARED_PGLXLIB_NM_D) *~ *.o ../*~

INSTALLED_LIBS = \
  $(STATIC_PGLXLIB_NM_O) \
  $(SHARED_PGLXLIB_NM_O) \
  $(STATIC_PGLXLIB_NM_D) \
  $(SHARED_PGLXLIB_NM_D) \
  $(SHARED_PGLXLIB_NM_ALT1_O) \
  $(SHARED_PGLXLIB_NM_ALT2_O) \
  $(SHARED_PGLXLIB_NM_ALT1_D) \
  $(SHARED_PGLXLIB_NM_ALT2_D)

veryclean : clean
	(cd $(INSTALL_INCDIR); $(RM) $(INSTALL_INCLUDES); )
	(cd $(INSTALL_LIBDIR); $(RM) $(INSTALLED_LIBS))

 # End of rules that are run from the arch directory
endif
