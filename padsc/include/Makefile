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

all: $(ARCH) $(PADS_PCGEN_TARGETS)

install:: 

uninstall::

clean::
	@($(RM) $(PADS_PCGEN_TARGETS))

veryclean:: clean
	@($(DELTREE) $(ARCH))

veryveryclean:: veryclean

clobber:: veryclean

#
# Individual targets
#
$(PADS_PCGEN_OUT): $(PADS_SCRIPT_MAKESRC) $(PADS_PCGEN_IN)
	@echo "Building $@"
	$(PADS_SCRIPT_MAKESRC) $(CC) $(PADS_PCGEN_IN) $(PADS_INCLUDE_BASE_ARCH) $(CONF_PACKAGE_SRC)

$(PADS_PCGEN_GALAX_OUT): $(PADS_SCRIPT_MAKESRC) $(PADS_PCGEN_GALAX_IN)
	@echo "Building $@"
	$(PADS_SCRIPT_MAKESRC) $(CC) $(PADS_PCGEN_GALAX_IN) $(PADS_INCLUDE_BASE_ARCH) $(CONF_PACKAGE_SRC)


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
#	for i in $(GALAX_ALL_SUBCOMPONENTS) tools/ucs2_to_utf8; do (cd $$i ; $(MAKE) -f Makefile updatedepend); done

ifdef DEPDEPEND
.depend: 
#	$(OCAMLDEP) $(GALAX_INCLUDES) $(GALAX_MLIFILES) $(GALAX_MLFILES) | $(SED) -e 's?\([a-z]\)\\?\1\/?g' > .depend
else
.depend:
#	$(OCAMLDEP) $(GALAX_INCLUDES) $(GALAX_MLIFILES) $(GALAX_MLFILES) | $(SED) -e 's?\([a-z]\)\\?\1\/?g' > .depend
endif

ifndef NODEPEND
include .depend
endif

endif