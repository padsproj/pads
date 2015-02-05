# N.B.: At the top of each Makefile, define the variable PADS_HOME
#       OR set an env variable PADS_HOME, before doing:
#
#   include $(PADS_HOME)/mk/rules.mk
#
# and set VPATH to location(s) of source files.
#
# If you are building the PADSL library, use:
#
#   BuildPADSLib = 1
#   include $(PADS_HOME)/mk/rules.mk
#
# and set VPATH to location(s) of source files.
#
# If there is a directory with generated .h/.c files, define GEN_DIR before including rules.mk
#
# Static link rule:
# foo : foo.o $(LIB_DEPS_O)
# 	$(LINK_O) -o $< foo.o $(STATIC_LIBS_O)

# Shared lib link:
# foo : foo.o $(LIB_DEPS_O)
# 	$(LINK_O) -o $< foo.o $(DYNAMIC_LIBS_O)
#
# (You can use _D instead of _O to choose debug rather than optimized)
#
# If using rules that cause the padsc compiler to be called, you can
# define PADSC_EXTRA to specify extra padsc params (such as -x).
#
# If USE_GALAX is defined, the padsc option -x is included
# and the pglx library is added to the set of libraries to link against.
# In this case env variables GALAX_HOME and GALAX_SRC must be defined.
# Also, the GALAX include paths are added as -I
# options and the appropriate ocaml and Galax libraries are added
# to the set of libraries to link against. In addition, the compilation
# flag -DUSE_GALAX is added.

# uncomment this to debug rules.mk
# DEBUG_RULES_MK = 1

# uncomment this once we build a shared ast library
# HAVE_SHARED_ASTLIB = 1

# uncomment this to force static builds
FORCE_STATIC = 1

# uncomment this to use gprof with debug libaries/executables
# (only works with GNU compilers)
# you should also uncomment FORCE_STATIC to include pads
# library routines in the profile
#  GPROF_FLAGS = -pg


# uncomment this to use memory profiling with debug libraries/executables
# WARNING: there seems to be a bug in the support for VM_RSZERO
# (zero-fill allocating memory) when this flag is set, observed for
# a case where the memory region shifted during a realloc
# VM_FLAGS = -DVMFL=1


# uncomment this to turn off loc setting for (most) reads
# NOREAD_FLAGS = -DNO_READ_LOCS


ifdef USE_GALAX
ifndef GALAX_HOME
%: forceabort2
	@echo "ERROR: env variable GALAX_HOME must be defined when building with USE_GALAX defined"
	@exit 1
forceabort2: ;
endif
ifndef GALAX_SRC
%: forceabort2
	@echo "ERROR: env variable GALAX_SRC must be defined when building with USE_GALAX defined"
	@exit 1
forceabort2: ;
endif
ifdef NO_READ_LOCS
%: forceabort2
	@echo "ERROR: GALAX requires read locations -- cannot use both USE_GALAX and NO_READ_LOCS"
	@exit 1
forceabort2: ;
endif
endif

ifndef AST_ARCH
AST_ARCH := $(shell $(PADS_HOME)/ast-ast/bin/package.cvs)
export AST_ARCH
endif

ifeq ($(AST_ARCH),cygwin.i386)
# Until we have time to figure out dynamic linking rules for cygwin,
# we need to force static linking.
FORCE_STATIC = 1
endif 



ifndef INSTALLROOT
INSTALLROOT = $(PADS_HOME)/ast-ast/arch/$(AST_ARCH)
endif

ifdef GIGASCOPE_HOME
# gigascope distribution
FORCE_STATIC = 1
PADS_INSTALLROOT = $(GIGASCOPE_HOME)
GIGASCOPE_FLAGS = -DFOR_GIGASCOPE
GIGASCOPE_INCLUDES = pads_gigascope.h pads_gigascope_macros.h  
else
# non-gigascope distribution
PADS_INSTALLROOT = $(INSTALLROOT)
GIGASCOPE_FLAGS =
GIGASCOPE_INCLUDES =
endif

INSTALL_LIBDIR = $(PADS_INSTALLROOT)/lib
INSTALL_INCDIR = $(PADS_INSTALLROOT)/include

FORCE_RESULT := $(shell $(PADS_HOME)/scripts/getprobeinfo.pl)
include $(PADS_HOME)/mk/rules.arch.$(AST_ARCH).mk

ifndef AST_HOME
AST_HOME := $(PADS_HOME)/ast-ast/arch/$(AST_ARCH)
export AST_HOME
endif

ifndef OCAML_LIB_DIR
OCAML_LIB_DIR = /usr/lib/ocaml
export OCAML_LIB_DIR
endif

ifndef PCRE_LIB_DIR
PCRE_LIB_DIR = /usr/lib
export PCRE_LIB_DIR
endif

ifndef USR_LIB_DIR
USR_LIB_DIR = /usr/lib
endif

ARCH_N_OPSYS = $(shell $(PADS_HOME)/scripts/arch-n-opsys)
ARCH_N_HEAPOPSYS = $(shell $(PADS_HOME)/scripts/arch-n-heapopsys)
OPSYS = $(shell $(PADS_HOME)/scripts/opsys)

ifndef OPSYS
%: forceabort2
	@echo "ERROR: env variable OPSYS must be defined; set by script $(PADS_HOME)/scripts/opsys"
	@exit 1
forceabort2: ;
endif

LIB_DEP_PATTERN = %$(mam_cc_SUFFIX_ARCHIVE)

STATIC_ASTLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)ast$(mam_cc_SUFFIX_ARCHIVE)
STATIC_ASTLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)ast$(mam_cc_SUFFIX_ARCHIVE)

STATIC_PZLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)pz$(mam_cc_SUFFIX_ARCHIVE)
STATIC_PZLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)pz$(mam_cc_SUFFIX_ARCHIVE)

STATIC_BZLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)bz$(mam_cc_SUFFIX_ARCHIVE)
STATIC_BZLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)bz$(mam_cc_SUFFIX_ARCHIVE)

STATIC_ZLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)z$(mam_cc_SUFFIX_ARCHIVE)
STATIC_ZLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)z$(mam_cc_SUFFIX_ARCHIVE)

STATIC_DLL_LIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)dll$(mam_cc_SUFFIX_ARCHIVE)
STATIC_DLL_LIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)dll$(mam_cc_SUFFIX_ARCHIVE)

ifndef USE_GALAX
PADS_NAME = pads
PADS_LIBOPT_O = -lpads
PADS_LIBOPT_D = -lpads-g
else
PADS_NAME = pads-for-galax
PADS_LIBOPT_O = -lpads-for-galax
PADS_LIBOPT_D = -lpads-for-galax-g
endif

PADSGALAX_NAME = pads-galax
PADSGALAX_LIBOPT_O = -lpads-galax
PADSGALAX_LIBOPT_D = -lpads-galax-g

NORMAL_STATIC_PADSLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)$(PADS_NAME)$(mam_cc_SUFFIX_ARCHIVE)
NORMAL_STATIC_PADSLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)$(PADS_NAME)-g$(mam_cc_SUFFIX_ARCHIVE)

GALAX_STATIC_PADSLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_ARCHIVE)
GALAX_STATIC_PADSLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_ARCHIVE)

ifdef USE_GALAX
STATIC_PADSLIB_NM_O = $(GALAX_STATIC_PADSLIB_NM_O)
STATIC_PADSLIB_NM_D = $(GALAX_STATIC_PADSLIB_NM_D)
else
STATIC_PADSLIB_NM_O = $(NORMAL_STATIC_PADSLIB_NM_O)
STATIC_PADSLIB_NM_D = $(NORMAL_STATIC_PADSLIB_NM_D)
endif

STATIC_PGLXLIB_NM_O = $(mam_cc_PREFIX_ARCHIVE)pglx$(mam_cc_SUFFIX_ARCHIVE)
STATIC_PGLXLIB_NM_D = $(mam_cc_PREFIX_ARCHIVE)pglx-g$(mam_cc_SUFFIX_ARCHIVE)

ifdef HAVE_SHARED_ASTLIB
SHARED_ASTLIB_NM_O = $(mam_cc_PREFIX_SHARED)ast$(mam_cc_SUFFIX_SHARED)
SHARED_ASTLIB_NM_D = $(mam_cc_PREFIX_SHARED)ast$(mam_cc_SUFFIX_SHARED)

SHARED_PZLIB_NM_O = $(mam_cc_PREFIX_SHARED)pz$(mam_cc_SUFFIX_SHARED)
SHARED_PZLIB_NM_D = $(mam_cc_PREFIX_SHARED)pz$(mam_cc_SUFFIX_SHARED)

SHARED_BZLIB_NM_O = $(mam_cc_PREFIX_SHARED)bz$(mam_cc_SUFFIX_SHARED)
SHARED_BZLIB_NM_D = $(mam_cc_PREFIX_SHARED)bz$(mam_cc_SUFFIX_SHARED)

SHARED_ZLIB_NM_O = $(mam_cc_PREFIX_SHARED)z$(mam_cc_SUFFIX_SHARED)
SHARED_ZLIB_NM_D = $(mam_cc_PREFIX_SHARED)z$(mam_cc_SUFFIX_SHARED)

SHARED_DLL_LIB_NM_O = $(mam_cc_PREFIX_SHARED)dll$(mam_cc_SUFFIX_SHARED)
SHARED_DLL_IB_NM_D = $(mam_cc_PREFIX_SHARED)dll$(mam_cc_SUFFIX_SHARED)
else
SHARED_ASTLIB_NM_O = $(STATIC_ASTLIB_NM_O)
SHARED_ASTLIB_NM_D = $(STATIC_ASTLIB_NM_D)

SHARED_PZLIB_NM_O = $(STATIC_PZLIB_NM_O)
SHARED_PZLIB_NM_D = $(STATIC_PZLIB_NM_D)

SHARED_BZLIB_NM_O = $(STATIC_BZLIB_NM_O)
SHARED_BZLIB_NM_D = $(STATIC_BZLIB_NM_D)

SHARED_ZLIB_NM_O = $(STATIC_ZLIB_NM_O)
SHARED_ZLIB_NM_D = $(STATIC_ZLIB_NM_D)

SHARED_DLL_LIB_NM_O = $(STATIC_DLL_LIB_NM_O)
SHARED_DLL_LIB_NM_D = $(STATIC_DLL_LIB_NM_D)
endif

NORMAL_SHARED_PADSLIB_NM_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1.0
NORMAL_SHARED_PADSLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1
NORMAL_SHARED_PADSLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED)

GALAX_SHARED_PADSLIB_NM_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED).1.0
GALAX_SHARED_PADSLIB_NM_ALT1_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED).1
GALAX_SHARED_PADSLIB_NM_ALT2_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED)

ifdef USE_GALAX
SHARED_PADSLIB_NM_D = $(GALAX_SHARED_PADSLIB_NM_D)
SHARED_PADSLIB_NM_ALT1_D = $(GALAX_SHARED_PADSLIB_NM_ALT1_D)
SHARED_PADSLIB_NM_ALT2_D = $(GALAX_SHARED_PADSLIB_NM_ALT2_D)
else
SHARED_PADSLIB_NM_D = $(NORMAL_SHARED_PADSLIB_NM_D)
SHARED_PADSLIB_NM_ALT1_D = $(NORMAL_SHARED_PADSLIB_NM_ALT1_D)
SHARED_PADSLIB_NM_ALT2_D = $(NORMAL_SHARED_PADSLIB_NM_ALT2_D)
endif

NORMAL_SHARED_PADSLIB_NM_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1.0
NORMAL_SHARED_PADSLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1
NORMAL_SHARED_PADSLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED)

GALAX_SHARED_PADSLIB_NM_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED).1.0
GALAX_SHARED_PADSLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED).1
GALAX_SHARED_PADSLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED)

ifdef USE_GALAX
SHARED_PADSLIB_NM_O = $(GALAX_SHARED_PADSLIB_NM_O)
SHARED_PADSLIB_NM_ALT1_O =  $(GALAX_SHARED_PADSLIB_NM_ALT1_O)
SHARED_PADSLIB_NM_ALT2_O =  $(GALAX_SHARED_PADSLIB_NM_ALT2_O)
else
SHARED_PADSLIB_NM_O =  $(NORMAL_SHARED_PADSLIB_NM_O)
SHARED_PADSLIB_NM_ALT1_O =  $(NORMAL_SHARED_PADSLIB_NM_ALT1_O)
SHARED_PADSLIB_NM_ALT2_O =  $(NORMAL_SHARED_PADSLIB_NM_ALT2_O)
endif

NORMAL_SHARED_PADSLIB_NM_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1.0
NORMAL_SHARED_PADSLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED).1
NORMAL_SHARED_PADSLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)$(mam_cc_SUFFIX_SHARED)

GALAX_SHARED_PADSLIB_NM_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED).1.0
GALAX_SHARED_PADSLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED).1
GALAX_SHARED_PADSLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)$(mam_cc_SUFFIX_SHARED)

ifdef USE_GALAX
SHARED_PADSLIB_NM_O =  $(GALAX_SHARED_PADSLIB_NM_O)
SHARED_PADSLIB_NM_ALT1_O =  $(GALAX_SHARED_PADSLIB_NM_ALT1_O)
SHARED_PADSLIB_NM_ALT2_O =  $(GALAX_SHARED_PADSLIB_NM_ALT2_O)
else
SHARED_PADSLIB_NM_O =  $(NORMAL_SHARED_PADSLIB_NM_O)
SHARED_PADSLIB_NM_ALT1_O =  $(NORMAL_SHARED_PADSLIB_NM_ALT1_O)
SHARED_PADSLIB_NM_ALT2_O =  $(NORMAL_SHARED_PADSLIB_NM_ALT2_O)
endif

NORMAL_SHARED_PADSLIB_NM_D = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)-g$(mam_cc_SUFFIX_SHARED).1.0
NORMAL_SHARED_PADSLIB_NM_ALT1_D = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)-g$(mam_cc_SUFFIX_SHARED).1
NORMAL_SHARED_PADSLIB_NM_ALT2_D = $(mam_cc_PREFIX_SHARED)$(PADS_NAME)-g$(mam_cc_SUFFIX_SHARED)

GALAX_SHARED_PADSLIB_NM_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED).1.0
GALAX_SHARED_PADSLIB_NM_ALT1_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED).1
GALAX_SHARED_PADSLIB_NM_ALT2_D = $(mam_cc_PREFIX_SHARED)$(PADSGALAX_NAME)-g$(mam_cc_SUFFIX_SHARED)

ifdef USE_GALAX
SHARED_PADSLIB_NM_D =  $(GALAX_SHARED_PADSLIB_NM_D)
SHARED_PADSLIB_NM_ALT1_D =  $(GALAX_SHARED_PADSLIB_NM_ALT1_D)
SHARED_PADSLIB_NM_ALT2_D =  $(GALAX_SHARED_PADSLIB_NM_ALT2_D)
else
SHARED_PADSLIB_NM_D =  $(NORMAL_SHARED_PADSLIB_NM_D)
SHARED_PADSLIB_NM_ALT1_D =  $(NORMAL_SHARED_PADSLIB_NM_ALT1_D)
SHARED_PADSLIB_NM_ALT2_D =  $(NORMAL_SHARED_PADSLIB_NM_ALT2_D)
endif

SHARED_PGLXLIB_NM_O = $(mam_cc_PREFIX_SHARED)pglxc$(mam_cc_SUFFIX_SHARED).1.0
SHARED_PGLXLIB_NM_ALT1_O = $(mam_cc_PREFIX_SHARED)pglxc$(mam_cc_SUFFIX_SHARED).1
SHARED_PGLXLIB_NM_ALT2_O = $(mam_cc_PREFIX_SHARED)pglxc$(mam_cc_SUFFIX_SHARED)

SHARED_PGLXLIB_NM_D = $(mam_cc_PREFIX_SHARED)pglxc-g$(mam_cc_SUFFIX_SHARED).1.0
SHARED_PGLXLIB_NM_ALT1_D = $(mam_cc_PREFIX_SHARED)pglxc-g$(mam_cc_SUFFIX_SHARED).1
SHARED_PGLXLIB_NM_ALT2_D = $(mam_cc_PREFIX_SHARED)pglxc-g$(mam_cc_SUFFIX_SHARED)

ASTLIBS = $(STATIC_ASTLIB_NM_O) 
ifdef USE_PZIP
ASTLIBS += $(STATIC_PZLIB_NM_O) $(STATIC_BZLIB_NM_O) $(STATIC_ZLIB_NM_O) $(STATIC_DLL_LIB_NM_O) 
endif

CC = $(mam_cc_CC)
CDBGFLAGS = $(mam_cc_WARN) $(mam_cc_DEBUG) 
COPTFLAGS = $(mam_cc_WARN) $(mam_cc_OPTIMIZE) -DNDEBUG


ifdef BuildPADSLib
CSHAREFLAGS = $(CC_DLL)
else
CSHAREFLAGS =
endif

# XXX Nothing for these in rules.arch.<ARCH>.mk ???
CARCHFLAGS =
STATIC_LIBTOOL = ar cr
STATIC_LIBTOOL_OPTS =

SHARED_LIBTOOL = $(CC) $(mam_cc_SHARED) $(mam_cc_SHARED_REGISTRY)
SHARED_LIBTOOL_WHOLE_ARCHIVE = $(mam_cc_LIB_ALL)
SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE = $(mam_cc_LIB_UNDEF)
SHARED_LIBTOOL_OPTS = $(mam_cc_DLL_LIBRARIES)

LINKER = $(mam_cc_LD)
LINKOPTS_D = $(CDBGFLAGS) $(mam_cc_LD_ORIGIN)
LINKOPTS_O = $(COPTFLAGS) $(mam_cc_LD_ORIGIN)

OS_SPEC_XTRA_LIBS =  -lm

empty:=
space:=$(empty) $(empty)

CC_DLL = $(mam_cc_DLL)

# Mary : for profiling using gprof
ifdef PROFILE
CDBGFLAGS += -pg
COPTFLAGS += -pg
endif

# OS specific rules
# (may override some of the above)

# compiler-specific rules

#if using gcc and -Wno-long-double is supported, use it
ifeq ($(PADS_CC_IS_GNU),1)
NOLONGDOUBLE_TEST = $(shell $(CC) -c -Wno-long-double $(PADS_HOME)/scripts/dummy.c -o /dev/null 2>&1)
ifeq ($(NOLONGDOUBLE_TEST),)
CDBGFLAGS += -Wno-long-double
COPTFLAGS += -Wno-long-double
endif
endif

ifeq ($(OPSYS),irix)
COPTFLAGS := $(subst -O$(space),-O2$(space),$(COPTFLAGS))
ifeq ($(PADS_CC_IS_GNU),1)
# do not use woff
else
CDBGFLAGS += -woff 47,1174,3201,3434,3421
COPTFLAGS += -woff 47,1174,3201,3434,3421
endif
endif

ifeq ($(OPSYS),linux)
COPTFLAGS := $(subst -O$(space),-O2$(space),$(COPTFLAGS))
endif

ifeq ($(AST_ARCH),linux.x86_64)
CDBGFLAGS += -DHAVE_VA_LIST
COPTFLAGS += -DHAVE_VA_LIST
endif 


# Fix for compilation on OS X Panther
ifeq ($(ARCH_N_OPSYS),ppc-darwin)
PADSC_EXTRA += -D__ppc__
endif

# iffy generated mam_cc_SHARED=-G is incorrect
ifeq ($(OPSYS),darwin)
# XXX why doesn't mamake figure this out ???
OS_SPEC_XTRA_LIBS += -liconv
#OS_SPEC_XTRA_LIBS += /usr/lib/libiconv.dylib
CDBGFLAGS += -Wno-enum-conversion
COPTFLAGS += -Wno-enum-conversion
mam_cc_SHARED=
COPTFLAGS := $(subst -O$(space),-O2$(space),$(COPTFLAGS))
SHARED_LIBTOOL_NOT_WHOLE_ARCHIVE :=-dynamiclib -flat_namespace -undefined suppress -read_only_relocs suppress
SHARED_LIBTOOL_WHOLE_ARCHIVE :=-dynamiclib -flat_namespace -undefined suppress -read_only_relocs suppress
CARCHFLAGS :=-fno-common 
endif

# gsf suggested
#(ranlib $$lib)>/dev/null 2>&1 || true
# but darwin always has ranlib
# so we just call ranlib $$lib below

# use this rule as follows
# (lib=<library>; $(FixStaticLib))
ifeq ($(OPSYS),darwin)
define FixStaticLib
(echo not calling ranlib $$lib)
endef
else
define FixStaticLib
endef
endif
# commented out from echo not calling above (echo calling ranlib $$lib; ranlib $$lib)
# (echo calling ranlib $$lib; chmod a+w $$lib; ranlib $$lib; chmod a-w $$lib)
# (echo calling ranlib $$lib; ranlib $$lib)

# We need to learn more about symbol visibility for the
# new gcc compiler.  This is a temporary fix which folds
# the static libast into shared libraries.
# Right now the problem is showing up
# for darwin, but it might be a general gcc 4 problem.
LINK_INTO_SHARED_O =
LINK_INTO_SHARED_D =
ifeq ($(OPSYS),darwin)
LINK_INTO_SHARED_O = $(STATIC_ASTLIB_O)
LINK_INTO_SHARED_D = $(STATIC_ASTLIB_D)
endif

ifeq ($(ARCH_N_OPSYS),x86-freebsd)
COPTFLAGS := $(subst -O$(space),-O2$(space),$(COPTFLAGS))
# XXX why doesn't mamake figure this out ???
# OS_SPEC_XTRA_LIBS += -liconv
endif

ifeq ($(OPSYS),solaris)
CC_DLL = $(mam_cc_DLLBIG)
COPTFLAGS := $(subst -O$(space),-O2$(space),$(COPTFLAGS))
# XXX /bin/sh on solaris does not test the same way as on other os
SHELL = bash
endif

# Done with architecture-specific stuff

ifdef FOR_CKIT
CDBGFLAGS += -DFOR_CKIT
COPTFLAGS += -DFOR_CKIT
endif

ifdef ECHO_TOKEN
CDBGFLAGS += -DECHO_TOKEN=$(ECHO_TOKEN)
COPTFLAGS += -DECHO_TOKEN=$(ECHO_TOKEN)
endif

ifdef USE_GALAX
PADSC_EXTRA = -x
CDBGFLAGS += -DUSE_GALAX
COPTFLAGS += -DUSE_GALAX
endif
ifdef USE_PZIP
CDBGFLAGS += -DUSE_PZIP
COPTFLAGS += -DUSE_PZIP
endif

CDBGFLAGS += $(GIGASCOPE_FLAGS)
COPTFLAGS += $(GIGASCOPE_FLAGS)

STATIC_PADSLIB_O = $(INSTALL_LIBDIR)/$(STATIC_PADSLIB_NM_O)
STATIC_PGLXLIB_O = $(INSTALL_LIBDIR)/$(STATIC_PGLXLIB_NM_O)
STATIC_PZLIB_O = $(INSTALL_LIBDIR)/$(STATIC_PZLIB_NM_O)
STATIC_BZLIB_O = $(INSTALL_LIBDIR)/$(STATIC_BZLIB_NM_O)
STATIC_ZLIB_O = $(INSTALL_LIBDIR)/$(STATIC_ZLIB_NM_O)
STATIC_DLL_LIB_O = $(INSTALL_LIBDIR)/$(STATIC_DLL_LIB_NM_O)
ifdef USE_PZIP
STATIC_ASTLIB_O = $(STATIC_PZLIB_O) $(STATIC_ZLIB_O) $(STATIC_BZLIB_O) $(STATIC_DLL_LIB_O) $(INSTALL_LIBDIR)/$(STATIC_ASTLIB_NM_O)
else
STATIC_ASTLIB_O = $(INSTALL_LIBDIR)/$(STATIC_ASTLIB_NM_O)
endif

ifndef PADSGLX_LIB_DIR
PADSGLX_LIB_DIR = $(PADS_HOME)/padsc/pads-glx/$(AST_ARCH)
endif

STATIC_GALAXLIB_O = $(PADSGLX_LIB_DIR)/$(mam_cc_PREFIX_ARCHIVE)padsglxopt$(mam_cc_SUFFIX_ARCHIVE)
STATIC_GALAXLIB_D = $(PADSGLX_LIB_DIR)/$(mam_cc_PREFIX_ARCHIVE)padsglxopt$(mam_cc_SUFFIX_ARCHIVE)
SHARED_GALAXLIB_O = $(PADSGLX_LIB_DIR)/$(mam_cc_PREFIX_SHARED)padsglxopt$(mam_cc_SUFFIX_SHARED)
STATIC_OCAMLLIB_O = \
  $(OCAML_LIB_DIR)/std-lib/libnums$(mam_cc_SUFFIX_ARCHIVE) \
  $(OCAML_LIB_DIR)/std-lib/libunix$(mam_cc_SUFFIX_ARCHIVE) \
  $(OCAML_LIB_DIR)/std-lib/libstr$(mam_cc_SUFFIX_ARCHIVE)

# These libraries on MacOS are not static:
#  $(USR_LIB_DIR)/libm$(mam_cc_SUFFIX_ARCHIVE) \
#  $(USR_LIB_DIR)/libdl$(mam_cc_SUFFIX_ARCHIVE) \
#  $(USR_LIB_DIR)/libcurses$(mam_cc_SUFFIX_ARCHIVE) \
# XXX what about $(mam_cc_PREFIX_ARCHIVE)camlrun$(mam_cc_SUFFIX_ARCHIVE) ?
ifdef USE_GALAX
STATIC_LIBS_O = $(STATIC_PGLXLIB_O) $(STATIC_PADSLIB_O) $(STATIC_ASTLIB_O)
else
STATIC_LIBS_O = $(STATIC_PADSLIB_O) $(STATIC_ASTLIB_O)
endif
ifdef USE_GALAX
STATIC_LIBS_O += $(STATIC_GALAXLIB_O) $(STATIC_OCAMLLIB_O)
endif
LIB_DEPS_O = $(STATIC_LIBS_O)


STATIC_PADSLIB_D = $(INSTALL_LIBDIR)/$(STATIC_PADSLIB_NM_D)
STATIC_PGLXLIB_D = $(INSTALL_LIBDIR)/$(STATIC_PGLXLIB_NM_D)
STATIC_PZLIB_D = $(INSTALL_LIBDIR)/$(STATIC_PZLIB_NM_D)
STATIC_BZLIB_D = $(INSTALL_LIBDIR)/$(STATIC_BZLIB_NM_D)
STATIC_ZLIB_D = $(INSTALL_LIBDIR)/$(STATIC_ZLIB_NM_D)
STATIC_DLL_LIB_D = $(INSTALL_LIBDIR)/$(STATIC_DLL_LIB_NM_D)
ifdef USE_PZIP
STATIC_ASTLIB_D = $(STATIC_PZLIB_D) $(STATIC_ZLIB_D) $(STATIC_BZLIB_D) $(STATIC_DLL_LIB_D) $(INSTALL_LIBDIR)/$(STATIC_ASTLIB_NM_D)
else
STATIC_ASTLIB_D = $(INSTALL_LIBDIR)/$(STATIC_ASTLIB_NM_D)
endif
# mff may need to change next two defns
STATIC_OCAMLLIB_D = $(STATIC_OCAMLLIB_O) # no debug versions available

ifdef USE_GALAX
STATIC_LIBS_D = $(STATIC_PGLXLIB_D)
endif
STATIC_LIBS_D += $(STATIC_PADSLIB_D) $(STATIC_ASTLIB_D)
ifdef USE_GALAX
STATIC_LIBS_D += $(STATIC_GALAXLIB_D) $(STATIC_OCAMLLIB_D)
endif
LIB_DEPS_D = $(STATIC_LIBS_D)

################################################################################
ifdef FORCE_STATIC

SHARED_ASTLIB_O       = $(STATIC_ASTLIB_O)
DYNAMIC_LIBS_O        = $(STATIC_LIBS_O)
DYNAMIC_LIB_DEPS_O    =

SHARED_ASTLIB_D       = $(STATIC_ASTLIB_D)
DYNAMIC_LIBS_D        = $(STATIC_LIBS_D)
DYNAMIC_LIB_DEPS_D    =

TRIV_LIBS             = $(STATIC_ASTLIB_D)

################################################################################
else # (not FORCE_STATIC)

ifdef HAVE_SHARED_ASTLIB
ifdef USE_PZIP
SHARED_ASTLIB_O = -lpz -lz -lbz -ldll -last
SHARED_ASTLIB_D = -lpz -lz -lbz -ldll -last
else
SHARED_ASTLIB_O = -last
SHARED_ASTLIB_D = -last
endif
else
SHARED_ASTLIB_O = $(STATIC_ASTLIB_O)
SHARED_ASTLIB_D = $(STATIC_ASTLIB_D)
endif

DYNAMIC_LIBS_O = -L$(INSTALL_LIBDIR)
DYNAMIC_LIBS_O += -lm

ifdef USE_GALAX
# Note: PCRE_LIB_DIR needs to be defined in any makefile using Galax.
DYNAMIC_LIBS_O += \
  $(PADSGALAX_LIBOPT_O) $(SHARED_ASTLIB_O)  \
  -L$(PADSGLX_LIB_DIR) -lpadsglxopt -lpglx -lcamlidl \
  -L$(OCAML_LIB_DIR)/std-lib -lnums -lm -ldl -lcurses -lunix -lstr -lbigarray -lthreadsnat -lpthread \
  -L$(PCRE_LIB_DIR) -lpcre -L$(GALAX_HOME)/lib/c \
  -L$(OCAML_LIB_DIR)/pkg-lib/pcre -lpcre_stubs
else 
DYNAMIC_LIBS_O += $(PADS_LIBOPT_O) $(SHARED_ASTLIB_O) 
endif
SHARED_PADSLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_PADSLIB_NM_O)
SHARED_PGLXLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_PGLXLIB_NM_O)
SHARED_ASTLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_ASTLIB_NM_O)
SHARED_PZLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_PZLIB_NM_O)
SHARED_BZLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_BZLIB_NM_O)
SHARED_ZLIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_ZLIB_NM_O)
SHARED_DLL_LIB_DEP_O = $(INSTALL_LIBDIR)/$(SHARED_DLL_LIB_NM_O)
ifdef USE_GALAX
DYNAMIC_LIB_DEPS_O = $(SHARED_PGLXLIB_DEP_O) $(SHARED_PADSLIB_DEP_O) $(SHARED_ASTLIB_DEP_O)
else
DYNAMIC_LIB_DEPS_O = $(SHARED_PADSLIB_DEP_O) $(SHARED_ASTLIB_DEP_O)
endif
ifdef USE_GALAX
DYNAMIC_LIB_DEPS_O += $(SHARED_GALAXLIB_O) $(STATIC_OCAMLLIB_O)
endif
ifdef USE_PZIP
DYNAMIC_LIB_DEPS_O += $(SHARED_DLL_LIB_DEP_O) $(SHARED_BZLIB_DEP_O) $(SHARED_ZLIB_DEP_O) $(SHARED_PZLIB_DEP_O) 
endif

DYNAMIC_LIBS_D = -L$(INSTALL_LIBDIR)
DYNAMIC_LIBS_D += -lm
ifdef USE_GALAX
DYNAMIC_LIBS_D += \
  $(PADSGALAX_LIBOPT_D) $(SHARED_ASTLIB_D)  \
  -L$(PADSGLX_LIB_DIR) -lpadsglxopt -lpglx-g -lcamlidl \
  -L$(OCAML_LIB_DIR)/std-lib -lnums -lm -ldl -lcurses -lunix -lstr -lbigarray  -lthreadsnat -lpthread \
  -L$(PCRE_LIB_DIR) -lpcre -L$(GALAX_HOME)/lib/c \
  -L$(OCAML_LIB_DIR)/pkg-lib/pcre -lpcre_stubs
else
DYNAMIC_LIBS_D += $(PADS_LIBOPT_D) $(SHARED_ASTLIB_D) 
endif
SHARED_PADSLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_PADSLIB_NM_D)
SHARED_PGLXLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_PGLXLIB_NM_D)
SHARED_ASTLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_ASTLIB_NM_D)
SHARED_PZLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_PZLIB_NM_D)
SHARED_BZLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_BZLIB_NM_D)
SHARED_ZLIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_ZLIB_NM_D)
SHARED_DLL_LIB_DEP_D = $(INSTALL_LIBDIR)/$(SHARED_DLL_LIB_NM_D)
ifdef USE_GALAX
DYNAMIC_LIB_DEPS_D = $(SHARED_PGLXLIB_DEP_D)
endif
DYNAMIC_LIB_DEPS_D += $(SHARED_PADSLIB_DEP_D) $(SHARED_ASTLIB_DEP_D)
ifdef USE_GALAX
# only statics available
DYNAMIC_LIB_DEPS_D += $(STATIC_GALAXLIB_D) $(STATIC_OCAMLLIB_D)
endif
ifdef USE_PZIP
DYNAMIC_LIB_DEPS_D += $(SHARED_DLL_LIB_DEP_D) $(SHARED_BZLIB_DEP_D) $(SHARED_ZLIB_DEP_D) $(SHARED_PZLIB_DEP_D)
endif

TRIV_LIBS = -L$(INSTALL_LIBDIR) $(SHARED_ASTLIB_D)

################################################################################
endif # FORCE_STATIC
################################################################################

STATIC_LIBS_XTRA_O = $(STATIC_LIBS_O) $(OS_SPEC_XTRA_LIBS)
STATIC_LIBS_XTRA_D = $(STATIC_LIBS_D) $(OS_SPEC_XTRA_LIBS)
DYNAMIC_LIBS_XTRA_O = $(DYNAMIC_LIBS_O) $(OS_SPEC_XTRA_LIBS)
DYNAMIC_LIBS_XTRA_D = $(DYNAMIC_LIBS_D) $(OS_SPEC_XTRA_LIBS)

INCLUDES =  -I. -I.. -I$(AST_HOME)/include/ast
ifdef GEN_DIR
INCLUDES += -I$(GEN_DIR)
endif

ifdef USE_GALAX
INCLUDES +=  -I$(GALAX_HOME)/lib/c -I$(PADS_HOME)/padsc/pads-glx -I$(PADS_HOME)/padsc/pads-glx/$(AST_ARCH) -I$(OCAML_LIB_DIR)/std-lib 
endif

ifndef BuildAST4PADSLib
INCLUDES += -I$(PADS_HOME)/padsc/include
INCLUDE_DEPS = $(PADS_HOME)/padsc/include/*.h $(PADS_HOME)/padsc/include/ptypes/*.h $(PADS_HOME)/padsc/include/template/*.h
else
INCLUDE_DEPS =
endif
DEFS =
ifdef BuildPADSLib
SHAREDEFS = -D_BLD_DLL -D_PACKAGE_ast
# SHAREDEFS = -D_BLD_DLL
else
SHAREDEFS =
endif

DEFS += $(NOREAD_FLAGS)

CFLAGS_D = $(GPROF_FLAGS) $(VM_FLAGS) $(CDBGFLAGS) $(CARCHFLAGS) $(INCLUDES)
COMPILE_D = $(CC) $(CSHAREFLAGS) $(CFLAGS_D) $(DEFS) $(SHAREDEFS)
MKSRC_D = $(CC) -E $(CFLAGS_D)

CFLAGS_O = $(COPTFLAGS) $(CARCHFLAGS) $(INCLUDES)
COMPILE_O = $(CC) $(CSHAREFLAGS) $(CFLAGS_O) $(DEFS) $(SHAREDEFS)
MKSRC_O = $(CC) -E $(CFLAGS_O)

LINK_D = $(LINKER) $(LINKOPTS_D)
LINK_O = $(LINKER) $(LINKOPTS_O)

PADSC = $(PADS_HOME)/scripts/padsc 
PADSC_REAL = $(PADS_HOME)/lib/padsc.$(ARCH_N_OPSYS)
# PADSC_REAL = $(shell ls $(PADS_HOME)/lib/padsc.* | head -n 1)
# ifeq ($(PADSC_REAL),)
# %: forceabort2
# 	@echo "ERROR: no padsc compiler found in $(PADS_HOME)/lib."
# 	@exit 1
# forceabort2: ;
# endif

LIBRARY_PATH_TEST = $(LD_LIBRARY_PATH)
LIBRARY_PATH_TEST_NM = "LD_LIBRARY_PATH"
ifeq ($(OPSYS),darwin)
LIBRARY_PATH_TEST = $(DYLD_LIBRARY_PATH)
LIBRARY_PATH_TEST_NM = "DYLD_LIBRARY_PATH"
endif
ifeq ($(OPSYS),hpux)
LIBRARY_PATH_TEST = $(SHLIB_PATH)
LIBRARY_PATH_TEST_NM = "SHLIB_PATH"
endif

ifdef FORCE_STATIC
define LibraryPathSanityCheck
( : )
endef
else
define LibraryPathSanityCheck
( if [ "$(LIBRARY_PATH_TEST)"x = x ]; then \
    echo "*** WARNING: $(LIBRARY_PATH_TEST_NM) is not set."; \
    echo "*** You probably want it set it, and to include directory"; \
    echo "***     $(INSTALL_LIBDIR)"; \
    echo "*** to pick up the PADS/AST shared libraries."; \
    echo "*** It can be set via a DO_SETENV script -- see pads/README"; \
  else \
    found=0; \
    for dir in `echo $(LIBRARY_PATH_TEST) | sed -e 's|:| |g'`; do \
      if [ $$dir = $(INSTALL_LIBDIR) ]; then \
        found=1; \
      fi; \
    done; \
    if [ $$found = 0 ]; then \
      echo "*** WARNING: $(LIBRARY_PATH_TEST_NM) may be incomplete:"; \
      echo "*** you probably want it to include directory"; \
      echo "***     $(INSTALL_LIBDIR)"; \
      echo "*** to pick up the PADS/AST shared libraries."; \
      echo "*** It can be set via a DO_SETENV script -- see pads/README"; \
    fi; \
  fi; \
)
endef
endif

define SanityCheck
( if [ ! -e $(PADSC) ]; then \
      echo "UNEXPECTED: $(PADSC) not found"; \
      exit 1; \
  fi; \
  if [ ! -e $(PADSC_REAL) ]; then \
      echo "UNEXPECTED: padsc compiler obj $(PADSC_REAL) not found"; \
      echo "     Have you built the PADS compiler?"; \
      echo "     Try: using 'gmake' in the top-level padsc directory."; \
      exit 1; \
  fi; \
  for file in $(LIB_DEPS_D) $(LIB_DEPS_O); do \
    if [ ! -e $$file ]; then \
      echo "UNEXPECTED: library $$file does not exist"; \
      exit 1; \
    fi; \
  done; \
)
endef

define SanityCheckTest
( echo "if [ ! -e $(PADSC) ]; then \
      echo \"UNEXPECTED: $(PADSC) not found\"; \
      exit 1; \
  fi"; \
  echo "if [ ! -e $(PADSC_REAL) ]; then \
      echo \"UNEXPECTED: padsc compiler obj $(PADSC_REAL) not found\"; \
      echo \"     Have you built the PADS compiler?\"; \
      echo \"     Try: using 'gmake' in the top-level padsc directory.\"; \
      exit 1; \
  fi"; \
  for file in $(LIB_DEPS_D) $(LIB_DEPS_O); do \
    echo "if [ ! -e $$file ]; then \
      echo \"UNEXPECTED: library $$file does not exist\"; \
      exit 1; \
    fi"; \
  done; \
)
endef

define LibSanityCheck
( for file in $(LIB_DEPS_D) $(LIB_DEPS_O); do \
    if [ ! -e $$file ]; then \
      echo "UNEXPECTED: library $$file does not exist"; \
      exit 1; \
    fi; \
  done; \
)
endef

define TrivCCExec_O
(set -x; \
 $(RM) $@; \
 $(COMPILE_O) $^ $(TRIV_LIBS) -o $@; \
)
endef

define TrivCCExec_D
(set -x; \
 $(RM) $@; \
 $(COMPILE_D) $^ $(TRIV_LIBS) -o $@; \
)
endef

define CCExec_DYNAMIC_D
(set -x; \
 $(RM) $@; \
 $(COMPILE_D) $(patsubst $(LIB_DEP_PATTERN),,$(patsubst %.h,,$^)) $(DYNAMIC_LIBS_XTRA_D) -o $@; \
)
endef

define CCExec_DYNAMIC_O
(set -x; \
 $(RM) $@; \
 $(COMPILE_O) $(patsubst $(LIB_DEP_PATTERN),,$(patsubst %.h,,$^)) $(DYNAMIC_LIBS_XTRA_O) -o $@; \
)
endef

define CCExec_STATIC_D
(set -x; \
 $(RM) $@; \
 $(COMPILE_D) $(patsubst $(LIB_DEP_PATTERN),,$(patsubst %.h,,$^)) $(STATIC_LIBS_XTRA_D) -o $@; \
)
endef

define CCExec_STATIC_O
(set -x; \
 $(RM) $@; \
 $(COMPILE_O) $(patsubst $(LIB_DEP_PATTERN),,$(patsubst %.h,,$^)) $(STATIC_LIBS_XTRA_O) -o $@; \
)
endef

define RegressPre
echo "Performing $@"; \
  if [ ! -e tmp ]; then mkdir tmp; fi; \
  $(RM) tmp/tmp.$<$$suf;
endef

define RegressPost
echo diff tmp/tmp.$<$$suf $$regfile; \
  diff tmp/tmp.$<$$suf $$regfile || echo "**********" $<$$suf DIFFERS; \
  echo " "; 
endef

PERFHOST=`hostname -s`
define PerfRegressPre
$(RegressPre)
endef

###
# PERF_DELTA_THRESHOLD is the percentage difference between a current
# measurement and a baseline measurement before is SIGNIFICANT*.  I.e.
# if CURRENT is PERF_DELTA_THRESHOLD % greater than BASELINE, then a
# "DIFFERS" message is issued and counted.
# ---
# * assumes PERF_DELTA_THRESHOLD exceeds estimate of error in measurement

PERF_DELTA_THRESHOLD = 10	# in percent.  (+/- PERF_TOLERANCE %)

define PerfRegressPost
echo $(PADS_HOME)/scripts/check_performance.pl $$regfile tmp/tmp.$<$$suf $(PERF_DELTA_THRESHOLD); \
  $(PADS_HOME)/scripts/check_performance.pl $$regfile tmp/tmp.$<$$suf $(PERF_DELTA_THRESHOLD) ||  echo "**********" $@$$suf DIFFERS; \
  echo " "; 
endef

define RegressDef
($(RegressPre) \
  regfile=`echo ../../regress/$<.regress$$suf | sed -e 's|_d[.]regress|.regress|'`; \
  echo "(./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf"; \
  (./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf; \
  $(RegressPost) )
endef

define RegressInput
($(RegressPre) \
  regfile=`echo ../../regress/$<.regress$$suf | sed -e 's|_d[.]regress|.regress|'`; \
  echo "(./$< $$args < $$input 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf"; \
  (./$< $$args < $$input 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf; \
  $(RegressPost) )
endef

define RegressInputPP
($(RegressPre) \
  regfile=`echo ../../regress/$<.regress$$suf | sed -e 's|_d[.]regress|.regress|'`; \
  echo "(cat $$input | $$pp | ./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf"; \
  (cat $$input | $$pp | ./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | cat > tmp/tmp.$<$$suf; \
  $(RegressPost) )
endef

define RegressFilter
($(RegressPre) \
  regfile=`echo ../../regress/$<.regress$$suf | sed -e 's|_d[.]regress|.regress|'`; \
  echo "(./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | grep $$filter | cat > tmp/tmp.$<$$suf"; \
  (./$< $$args 2>&1) | $(PADS_HOME)/scripts/remove_junk.pl | grep $$filter | cat > tmp/tmp.$<$$suf; \
  $(RegressPost) )
endef

define RegressRW
($(RegressPre) \
  echo "./$< $$args < $$input > tmp/tmp.$<$$suf 2>/dev/null"; \
  ./$< $$args < $$input > tmp/tmp.$<$$suf 2>/dev/null; \
  echo cmp tmp/tmp.$<$$suf $$input; cmp tmp/tmp.$<$$suf $$input || echo "**********" $<$$suf DIFFERS; \
  echo " "; )
endef

define PerfRegressDef
($(RegressPre) \
  regfile="../../regress/$<.perf_regress$$suf.$(PERFHOST)"; \
  echo "$(PADS_HOME)/scripts/time_execution.pl ./$< $$args > tmp/tmp.$<$$suf"; \
  $(PADS_HOME)/scripts/time_execution.pl ./$< $$args > tmp/tmp.$<$$suf; \
  $(PerfRegressPost) )
endef

define PerfRegressRW
($(RegressPre) \
  regfile="../../regress/$<.perf_regress$$suf.$(PERFHOST)"; \
  echo "$(PADS_HOME)/scripts/time_execution.pl ./$< $$args $$input > tmp/tmp.$<$$suf"; \
  $(PADS_HOME)/scripts/time_execution.pl ./$< $$args $$input > tmp/tmp.$<$$suf; \
  $(PerfRegressPost) )
endef

define PerfRegressInput
$(PerfRegressRW)
endef

.SUFFIXES:
.SUFFIXES: .c .o

ifdef GEN_DIR
$(GEN_DIR)/%_expanded.c: $(GEN_DIR)/%.c
	$(MKSRC_D) $< | $(PADS_HOME)/scripts/addnl.pl | $(PADS_HOME)/scripts/fix_FILE_LINE.pl $< > $@
endif


ifndef TRULES_MK
ifdef GEN_DIR

# PADSC_OPTIONS=-r $(GEN_DIR) -I. -I.. 
PADSC_OPTIONS=-r $(GEN_DIR) -I. -I.. $(INCLUDES)

ifdef GEN_WRITE
$(GEN_DIR)/%.c: %.p $(PADSC) $(PADSC_REAL)
ifdef DEBUG_RULES_MK
	@echo "Using rule P"
endif
	$(PADSC) $< $(PADSC_EXTRA) $(PADSC_OPTIONS) 

else # !GEN_WRITE

$(GEN_DIR)/%.c: %.p $(PADSC) $(PADSC_REAL)
ifdef DEBUG_RULES_MK
	@echo "Using rule P-nowrite"
endif
	$(PADSC) $< $(PADSC_EXTRA) -wnone $(PADSC_OPTIONS) 

endif # GEN_WRITE
endif # GEN_DIR

# First we put all the _d rules

ifdef REGRESS_TESTS
test_%_d: $(GEN_DIR)/%.c test_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule R_D"
endif
	@$(CCExec_DYNAMIC_D)

accum_%_d: $(GEN_DIR)/%.c accum_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule ACCUM_D"
endif
	@$(CCExec_DYNAMIC_D)

fmt_%_d: $(GEN_DIR)/%.c fmt_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FMT_D"
endif
	@$(CCExec_DYNAMIC_D)

filter_%_d: $(GEN_DIR)/%.c filter_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FILTER_D"
endif
	@$(CCExec_DYNAMIC_D)

rw_%_d: $(GEN_DIR)/%.c rw_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RW_D"
endif
	@$(CCExec_DYNAMIC_D)

rdonly_%_d: $(GEN_DIR)/%.c rdonly_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RDONLY_D"
endif
	@$(CCExec_DYNAMIC_D)

rwxml_%_d: $(GEN_DIR)/%.c rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RWXML_D"
endif
	@$(CCExec_DYNAMIC_D)

test_%_dd: $(GEN_DIR)/%_expanded.c test_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule R_DD"
endif
	@$(CCExec_DYNAMIC_D)

accum_%_dd: $(GEN_DIR)/%_expanded.c accum_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule ACCUM_DD"
endif
	@$(CCExec_DYNAMIC_D)

fmt_%_dd: $(GEN_DIR)/%_expanded.c fmt_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FMT_DD"
endif
	@$(CCExec_DYNAMIC_D)

filter_%_dd: $(GEN_DIR)/%_expanded.c filter_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FILTER_DD"
endif
	@$(CCExec_DYNAMIC_D)

rw_%_dd: $(GEN_DIR)/%_expanded.c rw_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RW_DD"
endif
	@$(CCExec_DYNAMIC_D)

rdonly_%_dd: $(GEN_DIR)/%_expanded.c rdonly_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RDONLY_DD"
endif
	@$(CCExec_DYNAMIC_D)

rwxml_%_dd: $(GEN_DIR)/%_expanded.c rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RWXML_DD"
endif
	@$(CCExec_DYNAMIC_D)
endif # REGRESS_TESTS / _d rule

ifdef BuildPADSLib
 # Just one _d rule needed for BuildPADSLib

%_d.o: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule A_D"
endif
	$(COMPILE_D) -c $< -o $@

else
 # Three _d rules needed for !BuildPADSLib

%_d: %_d.o $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule J_D"
endif
	$(LINK_D) $< $(DYNAMIC_LIBS_XTRA_D) -o $@

%_d.o: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule K_D"
endif
	$(COMPILE_D) -c $< -o $@

ifndef REGRESS_TESTS
%_d: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS) $(LIB_DEPS_D)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule L_D"
endif
	$(COMPILE_D) $< $(DYNAMIC_LIBS_XTRA_D) -o $@
endif # !REGRESS_TESTS

endif # BuildPADSLib / _d rules

# Now the non _d rules

ifdef REGRESS_TESTS
test_%: $(GEN_DIR)/%.c test_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule R_O"
endif
	@$(CCExec_DYNAMIC_O)

accum_%: $(GEN_DIR)/%.c accum_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule ACCUM_O"
endif
	@$(CCExec_DYNAMIC_O)

fmt_%: $(GEN_DIR)/%.c fmt_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FMT_O"
endif
	@$(CCExec_DYNAMIC_O)

filter_%: $(GEN_DIR)/%.c filter_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule FILTER_O"
endif
	@$(CCExec_DYNAMIC_O)

rw_%: $(GEN_DIR)/%.c rw_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RW_O"
endif
	@$(CCExec_DYNAMIC_O)

rdonly_%: $(GEN_DIR)/%.c rdonly_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RDONLY_O"
endif
	@$(CCExec_DYNAMIC_O)

rwxml_%: $(GEN_DIR)/%.c rwxml_%.c $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule RWXML_O"
endif
	@$(CCExec_DYNAMIC_O)
endif # REGRESS_TESTS / non _d rule

ifdef BuildPADSLib
 # Just one non _d rule needed for BuildPADSLib

%.o: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule A_O"
endif
	$(COMPILE_O) -c $< -o $@

else
 # Three non _d rules needed for !BuildPADSLib

%: %.o $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule J_O"
endif
	$(LINK_O) $< $(DYNAMIC_LIBS_XTRA_O) -o $@

%.o: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule K_O"
endif
	$(COMPILE_O) -c $< -o $@

%: %.c $(INCLUDE_DEPS_ADD) $(INCLUDE_DEPS) $(LIB_DEPS_O)
ifdef DEBUG_RULES_MK
	@echo "Using rules.mk rule L_O"
endif
	$(COMPILE_O) $< $(DYNAMIC_LIBS_XTRA_O) -o $@

endif # BuildPadsLib / non _d rules

endif # !TRULES_MK
