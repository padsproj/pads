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
#								applications in the build environment
#########################################################################

include $(PADS_SRC)/config/Makefile.pads

#
# There is NO re-direction here because the SML tool builds its targets
# in architecture specific directories
#

#
# These variables determine which input file we use to build the compiler with SML
#
ifeq ($(CONF_BUILD_SML),true)
	export SML=$(CONF_SML_HOME)/bin/sml
	export SMLNJ_HOME=$(CONF_SML_HOME)
	export SMLNJ_CYGWIN_RUNTIME=$(CONF_SML_CYGWIN)
else
	ifeq ($(strip $(SML)),)
		$(error SML environment variable is undefined)
	endif
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

all: compiler

#########################################################################
# Sub-Section:	Secondary targets
# Description:
#		These are the targets listed as dependencies of "all".  They each
#		have their own install, uninstall, and clean targets.
#
#		compiler:		The SML compiler for PADS
#########################################################################

#########################################################################
# Sub-Sub-Section:	compiler
# Description:
#		These are the targets for building the toplevel applications
#
#		commands:				Builds the byte and opt command targets
#		install:				Installs the command targets
#		uninstall:				Uninstalls the command targets
#		clean:					Clean is delegated to each of the actual commands
#########################################################################

compiler:	
	@(echo SML = $(SML))
	@(echo SMLNJ_HOME = $(SMLNJ_HOME))
	@(echo SMLNJ_CYGWIN_RUNTIME = $(SMLNJ_CYGWIN_RUNTIME))
	@(echo SML_VER = $(SML_VER))
	@(echo SML_MINOR_VER = $(SML_MINOR_VER))
	@(echo SML_MINOR_VER_TEST = $(SML_MINOR_VER_TEST))
	@(echo BUILD_EXEC = $(BUILD_EXEC))
	@(echo "Building the compiler")
	$(SML) < $(BUILD_EXEC)

install::

uninstall::

clean::
	$(RM) $(PADS_PADSC_TARGET)
	@(cd ckit; x="`find . -name \*~`"; if [ "$$x"x != x ]; then echo "In ckit, removing:\n$$x"; $(RM) $$x; fi)

veryclean:: clean
	@(echo "Removing .cm .bin files"; if [ -d .cm ]; then cd .cm; x="`find . -name \*.bin`"; if [ "$$x"x != x ]; then echo "In .cm, removing:\n$$x"; $(RM) $$x; fi; fi)
	@(echo "Removing ckit .bin files"; cd ckit; x="`find . -name \*.bin`"; if [ "$$x"x != x ]; then echo "In ckit, removing:\n$$x"; $(RM) $$x; fi)
	@(echo "Removing util .bin files"; cd util; x="`find . -name \*.bin`"; if [ "$$x"x != x ]; then echo "In util, removing:\n$$x"; $(RM) $$x; fi)

veryveryclean:: veryclean

clobber:: veryclean

#########################################################################
# Section:	Makefile post-includes
# Description:
#		This is where the dependency file is included and generated
#		We place the dependencies to make sure that various files
#		are generated before we need them.
#########################################################################

