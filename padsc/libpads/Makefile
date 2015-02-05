#########################################################################
#                                                                       #
#                                PADS                                   #
#                   Processing Ad Hoc Data Engine                       #
#                                                                       #
#   Copyright 2006, AT&T Labs Research                                  #
#   Distributed only by permission.                                     #
#                                                                       #
#########################################################################

#########################################################################
# Author:	Pamela L. Dragosh (AT&T Labs Research)
# Descripton:
#		This is a replacement Makefile for PADS that relies on the output
#		of a configuration script.
#
# History:
#	
#########################################################################

#########################################################################
# Section:	Default target
# Description:
#		The default target for this Makefile is "all"
#########################################################################
default:	all

#########################################################################
# Section:	Makefile pre-includes
# Description:
#		This is where the file(s) generated during by the Configure script
#		are included.  If config/Makefile.conf does not exist, the
#		make will fail.
#
#		Makefile.pads:	Variables defined for compiling and linking PADS
#				applications in the build environment
#########################################################################

include $(PADS_SRC)/config/Makefile.pads

#
# Here is where we include the re-direction into the ARCH sub-directory so we
# can support multi-architecture builds.
#
ifneq ($(ARCH), $(notdir $(HERE)))
include $(PADS_SRC)/config/Makefile.redirect
else

#
# The rest of this file should be invoked from the ARCH sub-directory
#

#########################################################################
# Section:	Main targets
# Description:
#		This is where all of the named toplevel targets are placed.
#
#	all:		This target builds the PADS compiler
#	install::	This target does installation for files in the main section
#	uninstall::	This target uninstalls files installed in the main section
#	clean::		This target cleans files created in the all section
#	clobber::	This target cleans files created in the all section and .depend
#	
#########################################################################

#
# Because dogen generates c files, I must invoke it before libpads so when libpads is
# invoked, the implicit search will find all the source files before the build process.
# Else, make does not *know* that new .c have been created and it barfs looking for them.
#
all:
	@$(MAKE) -f ../Makefile dogen
	@$(MAKE) -f ../Makefile libpads

#########################################################################
# Sub-Section:	Secondary targets
# Description:
#		These are the targets listed as dependencies of "all".  They each
#		have their own install, uninstall, and clean targets.
#
#		dogen:			Generates source code files for libpads
#		libpads:		The PADS library
#########################################################################

#########################################################################
# Sub-Sub-Section:	dogen
# Description:
#		These are the targets for building libraries, installing them
#		uninstalling them, and cleaning them.
#
#		libs:			Builds the library targets (static and optional shared)
#		install:		Installs the library targets (static and optional shared)
#		uninstall:		Uninstalls the library targets (static and optional shared)
#		clean:			Cleans up the files used to create the libraries that
#						are created by automatic rules
#########################################################################

dogen: $(PADS_PCGEN_TARGETS) $(PADS_SCRIPT_MAKESRC) $(PADS_PACKAGE_SRC)/padsc/libpads/pads.c
	$(PADS_SCRIPT_MAKESRC) $(CC) $(PADS_SRC)/padsc/libpads/pads.c $(HERE) $(PADS_SRC)
	touch dogen

clean::
	@(cd $(PADS_INCLUDE_BASE); $(MAKE) -f Makefile clean)
	@($(RM) -f dogen)

veryclean:: clean
	@(cd $(PADS_INCLUDE_BASE); $(MAKE) -f Makefile veryclean)
	@($(RM) -f *-gen.*)

veryveryclean:: veryclean
	@(cd $(PADS_INCLUDE_BASE); $(MAKE) -f Makefile veryveryclean)

clobber:: veryclean
	@(cd $(PADS_INCLUDE_BASE); $(MAKE) -f Makefile clobber)

#
# Individual targets
#
$(PADS_PCGEN_TARGETS): $(PADS_SCRIPT_MAKESRC) $(PADS_PCGEN_IN)
	@(cd $(PADS_INCLUDE_BASE); $(MAKE) -f Makefile all)

#########################################################################
# Sub-Sub-Section:	libpads
# Description:
#		These are the targets for building the toplevel applications
#
#		commands:				Builds the byte and opt command targets
#		install:					Installs the command targets
#		uninstall:				Uninstalls the command targets
#		clean:					Clean is delegated to each of the actual commands
#########################################################################

libpads:	dogen $(PADS_TARGETS)

install::

uninstall::

clean::
	@($(RM) -f *.o)
	@($(RM) -f *$(LIB_SUFFIX))
	@($(RM) -f $(PADS_TARGETS))

veryclean:: clean
	@($(DELTREE) $(ARCH))

veryveryclean:: veryclean

clobber:: veryclean

#
# Individual command targets
#
LIBPADS_OBJS_O = \
        default_io_disc.o \
        pads-gen.o \
        pads-acc-gen.o \
        pads-read-gen.o \
        pads-write-gen.o \
        pads-misc-gen.o \
        rbuf.o \
        pads-hist.o \
        pads-cluster.o

LIBPADS_OBJS_D = $(LIBPADS_OBJS_O:%.o=%_d.o)

$(PADS_NAME_OPT): $(LIBPADS_OBJS_O)
	$(STATIC_LIBTOOL) $@ $(STATIC_LIBTOOL_OPTS) $^

$(PADS_NAME_DBG): $(LIBPADS_OBJS_D)
	$(STATIC_LIBTOOL) $@ $(STATIC_LIBTOOL_OPTS) $^

ifeq ($(PADS_SHARED),true)
$(PADS_SHARED_NAME_OPT): $(LIBPADS_OBJS_O)
	$(SHARED_LIBTOOL) -o $@ $(SHARED_LIBTOOL_OPTS) $^ $(PADS_AST_LIB) $(CCLIBS)

$(PADS_SHARED_NAME_DBG): $(LIBPADS_OBJS_D)
	$(SHARED_LIBTOOL) -o $@ $(SHARED_LIBTOOL_OPTS) $^ $(PADS_AST_LIB) $(CCLIBS)
endif

#########################################################################
# Section:	Makefile post-includes
# Description:
#		This is where the dependency file is included and generated
#		We place the dependencies to make sure that various files
#		are generated before we need them.
#########################################################################

clobber::
	$(RM) .depend

updatedepend::
	$(MAKE) -f Makefile .depend DEPDEPEND=1

.depend: 
#	$(MAKEDEPEND) | $(SED) -e 's?\([a-z]\)\\?\1\/?g' > .depend

ifndef NODEPEND
include .depend
endif

endif
