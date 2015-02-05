 # Redirect gmake to AST_ARCH directory
 # AST_ARCH must be set before including this file.

ifndef AST_ARCH
%: forceabort
	@echo "AST_ARCH must be defined before including redirect.mk"
	@exit 1

forceabort: ;

else

.SUFFIXES:

MAKETARGET = $(MAKE) --no-print-directory -C $@ -f $(CURDIR)/tmp_GNUmakefile.ptest $(MAKECMDGOALS)

.PHONY: $(AST_ARCH)
$(AST_ARCH):
	+@echo "Making $(MAKECMDGOALS) in $@"
	+@(if [ ! -d $@ ]; then \
		mkdir -p $@; \
	  fi)
	+@$(MAKETARGET)

GNUmakefile : ;
%.mk :: ;

% :: $(AST_ARCH) ;

endif
