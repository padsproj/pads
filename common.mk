
 # This is a GNU makefile.

ifndef PADS_HOME
  export PADS_HOME=$(shell pwd)
endif

TARGS = ast_lib padsc_lib
# Set ADDITIONAL_TARGS in any file that includes this one to augment
# TARGS. Be sure to set ADDITIONAL_TARGS *before* including this file.
TARGS += $(ADDITIONAL_TARGS)
ifdef USE_GALAX
TARGS += pads_glx pglx_lib 
endif

ifndef AST_ARCH
AST_ARCH := $(shell $(PADS_HOME)/ast-ast/bin/package.cvs)
export AST_ARCH
endif
AST_LIB = ast-ast/arch/$(AST_ARCH)/lib/libast.a

all: $(TARGS)

ast_lib : $(AST_LIB)

padsc_lib:
	@(cd padsc; $(MAKE) -f GNUmakefile padsc_lib)

pglx_lib:
	@(cd padsc; $(MAKE) -f GNUmakefile pglx_lib)

pads_glx:
	@(cd padsc; $(MAKE) -f GNUmakefile pads_glx)

padsc_comp:
	@(cd padsc; $(MAKE) -f GNUmakefile padsc_comp)

regress:
	@(cd padsc; $(MAKE) -f GNUmakefile regress)

pglx_regress:
	@(cd padsc; $(MAKE) -f GNUmakefile pglx_regress)

usecase_regress:
	@(cd padsc; $(MAKE) -f GNUmakefile usecase_regress)

perf_regress:
	@(cd padsc; $(MAKE) -f GNUmakefile perf_regress)

test_xml:
	@(cd padsc; $(MAKE) -f GNUmakefile test_xml)

test_libpads:
	@(cd padsc; $(MAKE) -f GNUmakefile test_libpads)

test_comp:
	@(cd padsc; $(MAKE) -f GNUmakefile test_comp)

clean:
	@(cd padsc; $(MAKE) -f GNUmakefile clean)

veryclean:
	@(cd padsc; $(MAKE) -f GNUmakefile veryclean)

veryveryclean: veryclean
	@(cd ast-ast/arch; $(RM) -rf `../bin/package`)
	@($(RM) ./mk/rules.arch.`ast-ast/bin/package`.mk)

WHERE_NMAKE := $(shell (type nmake 2>/dev/null) | grep -v 'not found')

PATH_FIX = echo -n 
ifneq ($(WHERE_NMAKE),)
PATH_FIX = export PATH=$(PADS_HOME)/scripts/nmake_fix:$$PATH 
endif

MODS = ast-ast/mods/mods.tar

$(AST_LIB) : $(MODS) ast-ast/lib/package/tgz/*.tgz
	@(if [ ! -f ast-ast/bin/package ]; then cp ast-ast/bin/package.cvs ast-ast/bin/package; fi)
	@( $(PATH_FIX) ; cd ast-ast; PWD=`pwd`; ./bin/package read SHELL=$(SHELL) )
	tar xf $(MODS)
	@( $(PATH_FIX) ; cd ast-ast; PWD=`pwd`; ./bin/package make SHELL=$(SHELL) )
	( $(RM) mk/rules.arch.$(AST_ARCH).mk )

foo:
	echo SHELL=$(SHELL)


