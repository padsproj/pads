
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
include $(PADS_HOME)/mk/rules.mk

VPATH = ..

SRC_INCDIR = $(PADS_HOME)/padsc/include
PCGEN_IN = $(SRC_INCDIR)/pcgen-macros.h
PCGEN = $(SRC_INCDIR)/pcgen-macros-gen.h

PGLXGEN_IN = $(SRC_INCDIR)/pglx-codegen-macros.h
PGLXGEN = $(SRC_INCDIR)/pglx-codegen-macros-gen.h

INSTALL_INCLUDES = io_disc.h rbuf.h pads.h pads-private.h pads-internal.h pcgen-macros-gen.h pads-hist.h pads-cluster.h

TEMPLATE_INCLUDES = accum_report.h read_and_reread.h read_write.h init_select_act_done.h \
        read_format.h just_read.h read_orig_write_xml.h

INSTALL_INCLUDES += $(GIGASCOPE_INCLUDES)
ifdef USE_GALAX
INSTALL_INCLUDES  += node_mm.h path_walk.h smart.h free-list-internal.h \
                     pglx-codegen-macros-gen.h pglx-free-list.h free-list-imp.h
TEMPLATE_INCLUDES += pglx_bulk_query.h pglx_load.h pglx_smart_query.h test_kth_child.h 
endif

all : $(PCGEN) $(PGLXGEN)

install : all
	+@(set -x ; \
	mkdir -p $(INSTALL_INCDIR)/template; \
	for file in $(INSTALL_INCLUDES); do \
		$(PADS_HOME)/scripts/install-sh -c -m 444 $(SRC_INCDIR)/$$file $(INSTALL_INCDIR); \
	done; \
	for file in $(TEMPLATE_INCLUDES); do \
		$(PADS_HOME)/scripts/install-sh -c -m 444 $(SRC_INCDIR)/template/$$file $(INSTALL_INCDIR)/template; \
	done;)

$(PCGEN) : $(SCRIPTS)/mksrc.pl $(PCGEN_IN)
	@echo "Building pcgen-macros-gen.h"
	$(SCRIPTS)/mksrc.pl $(CC) $(PCGEN_IN) $(SRC_INCDIR) $(PADS_HOME)

$(PGLXGEN) : $(PGLXGEN_IN) $(SCRIPTS)/mksrc.pl 
	@echo "Building pglx-codegen-macros-gen.h"
	$(SCRIPTS)/mksrc.pl $(CC) $(PGLXGEN_IN) $(SRC_INCDIR) $(PADS_HOME)

clean :
	$(RM) *~ ../*~

veryclean :
	$(RM) *~ ../*~ $(PCGEN) $(PGLXGEN)
	(cd $(INSTALL_INCDIR); $(RM) $(INSTALL_INCLUDES); )
	(cd $(INSTALL_INCDIR)/template; $(RM) $(TEMPLATE_INCLUDES); )

 # End of rules that are run from the arch directory
endif
