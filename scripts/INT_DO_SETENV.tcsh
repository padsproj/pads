#!/bin/echo You should SOURCE rather than execute
# INT_DO_SETENV.tcsh is a helper script.
# See DO_SETENV.tcsh and Q_DO_SETENV.tcsh.

# First figure out what env variables are set

set _is_pads_home
if (! $?PADS_HOME) then
  unset _is_pads_home
else
  if ("$PADS_HOME"x == x) then
    unset _is_pads_home
  endif
endif

set _is_ast_home_force
if (! $?AST_HOME_FORCE) then
  unset _is_ast_home_force
else
  if ("$AST_HOME_FORCE"x == x) then
    unset _is_ast_home_force
  endif
endif

set _is_installroot_force
if (! $?INSTALLROOT_FORCE) then
  unset _is_installroot_force
else
  if ("$INSTALLROOT_FORCE"x == x) then
    unset _is_installroot_force
  endif
endif

set _is_dyld_library_path
if (! $?DYLD_LIBRARY_PATH) then
  unset _is_dyld_library_path
else
  if ("$DYLD_LIBRARY_PATH"x == x) then
    unset _is_dyld_library_path
  endif
endif

set _is_ld_library_path
if (! $?LD_LIBRARY_PATH) then
  unset _is_ld_library_path
else
  if ("$LD_LIBRARY_PATH"x == x) then
    unset _is_ld_library_path
  endif
endif

set _is_shlib_path
if (! $?SHLIB_PATH) then
  unset _is_shlib_path
else
  if ("$SHLIB_PATH"x == x) then
    unset _is_shlib_path
  endif
endif

set _is_manpath
if (! $?MANPATH) then
  unset _is_manpath
else
  if ("$MANPATH"x == x) then
    unset _is_manpath
  endif
endif

set _is_ocaml_lib
if (! $?OCAML_LIB_DIR) then
  unset _is_ocaml_lib
else
  if ("$OCAML_LIB_DIR"x == x) then
    unset _is_ocaml_lib
  endif
endif

set _is_ocaml_bin
if (! $?OCAML_BIN_DIR) then
  unset _is_ocaml_bin
else
  if ("$OCAML_BIN_DIR"x == x) then
    unset _is_ocaml_bin
  endif
endif

set _is_galax_home
if (! $?GALAX_HOME) then
  unset _is_galax_home
else
  if ("$GALAX_HOME"x == x) then
    unset _is_galax_home
  endif
endif

set _is_galax_src
if (! $?GALAX_SRC) then
  unset _is_galax_src
else
  if ("$GALAX_SRC"x == x) then
    unset _is_galax_src
  endif
endif

set _is_pcre_lib_dir
if (! $?PCRE_LIB_DIR) then
  unset _is_pcre_lib_dir
else
  if ("$PCRE_LIB_DIR"x == x) then
    unset _is_pcre_lib_dir
  endif
endif

set _is_padsglx_lib_dir_force
if (! $?PADSGLX_LIB_DIR_FORCE) then
  unset _is_padsglx_lib_dir_force
else
  if ("$PADSGLX_LIB_DIR_FORCE"x == x) then
    unset _is_padsglx_lib_dir_force
  endif
endif

set _pads_status = OK

if (! $?_pads_verbose) then
  echo "##############################################################################"
  echo "# Do not use INT_DO_SETENV directly, use DO_SETENV or Q_DO_SETENV"
  echo "##############################################################################"
  echo " "
  set _pads_status = FAILED
endif 

if ($_pads_status == OK) then
  if ($_pads_verbose != 0) then
    echo " "
  endif
  if (! $?_is_pads_home) then
    echo "##############################################################################"
    echo "# Set env var PADS_HOME and then use $_pads_do_prog again."
    echo "##############################################################################"
    echo " "
    set _pads_status = FAILED
  endif
endif

if ($_pads_status == "OK") then
  if (! (-e $PADS_HOME/ast-ast/bin/package.cvs)) then
    echo "##############################################################################"
    echo "# Invalid setting (?) : PADS_HOME = $PADS_HOME"
    echo "#"
    echo "# Cannot find $PADS_HOME/ast-ast/bin/package.cvs"
    echo "#"
    echo "# Set env var PADS_HOME correctly and then use $_pads_do_prog again."
    echo "##############################################################################"
    echo " "
    set _pads_status = FAILED
  endif
endif

if ($_pads_status == "OK") then

  setenv AST_ARCH `$PADS_HOME/ast-ast/bin/package.cvs`

  if (! $?_is_ast_home_force) then
    setenv AST_HOME $PADS_HOME/ast-ast/arch/$AST_ARCH
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var AST_HOME to $AST_HOME"
      echo "# If you do not like this setting, set AST_HOME_FORCE to the"
      echo "# desired value for AST_HOME, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    endif
  else
    setenv AST_HOME $AST_HOME_FORCE
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var AST_HOME to value of AST_HOME_FORCE = $AST_HOME"
      echo "# If you prefer to use the PADS default, unsetenv AST_HOME_FORCE"
      echo "##############################################################################"
      echo " "
    endif
  endif

  if (! $?_is_installroot_force) then
    if (! $?GIGASCOPE_HOME) then
       setenv INSTALLROOT $PADS_HOME/ast-ast/arch/$AST_ARCH
    else
       setenv INSTALLROOT $GIGASCOPE_HOME
    endif
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var INSTALLROOT to $INSTALLROOT"
      echo "# If you do not like this setting, set INSTALLROOT_FORCE to the"
      echo "# desired value for INSTALLROOT, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    endif
  else
    setenv INSTALLROOT $INSTALLROOT_FORCE
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var INSTALLROOT to value of INSTALLROOT_FORCE = $INSTALLROOT"
      echo "# If you prefer to use the PADS default, unsetenv INSTALLROOT_FORCE"
      echo "##############################################################################"
      echo " "
    endif
  endif

  if (! $?_is_padsglx_lib_dir_force) then
    setenv PADSGLX_LIB_DIR $PADS_HOME/padsc/pads-glx/$AST_ARCH
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var PADSGLX_LIB_DIR to $PADSGLX_LIB_DIR"
      echo "# If you do not like this setting, set PADSGLX_LIB_DIR_FORCE to the"
      echo "# desired value for PADSGLX_LIB_DIR, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    endif
  else
    setenv PADSGLX_LIB_DIR $PADSGLX_LIB_DIR_FORCE
    if ($_pads_verbose != 0) then
      echo "##############################################################################"
      echo "# Setting env var PADSGLX_LIB_DIR to value of PADSGLX_LIB_DIR_FORCE = $PADSGLX_LIB_DIR"
      echo "# If you prefer to use the PADS default, unsetenv PADSGLX_LIB_DIR_FORCE"
      echo "##############################################################################"
      echo " "
    endif
  endif

  if (! -e $INSTALLROOT) then
    (mkdir -p $INSTALLROOT >& /dev/null) || set _pads_status = FAILED
  endif
  if (! -e $INSTALLROOT/bin) then
    (mkdir -p $INSTALLROOT/bin >& /dev/null) || set _pads_status = FAILED
  endif
  if (! -e $INSTALLROOT/include) then
    (mkdir -p $INSTALLROOT/include >& /dev/null) || set _pads_status = FAILED
  endif
  if (! -e $INSTALLROOT/lib) then
    (mkdir -p $INSTALLROOT/lib >& /dev/null) || set _pads_status = FAILED
  endif
  if (! -e $INSTALLROOT/man) then
    (mkdir -p $INSTALLROOT/man >& /dev/null) || set _pads_status = FAILED
  endif

  if ($_pads_status == "FAILED") then
    echo "##############################################################################"
    echo "# WARNING: Could not create INSTALLROOT $INSTALLROOT"
    echo "# or one of its subdirs (bin, include, lib, man).  Correct problem (e.g.,"
    echo "# define another INSTALLROOT) and then use $_pads_do_prog again."
    echo "##############################################################################"
    echo " "
  endif

  set ast_lib_dir  = $AST_HOME/lib
  set ast_man_dir  = $AST_HOME/man

  set pads_bin_dir    = $INSTALLROOT/bin
  set pads_lib_dir    = $INSTALLROOT/lib
  set pads_man_dir    = $INSTALLROOT/man
  set pads_script_dir = $PADS_HOME/scripts
  set remove_dups     = $pads_script_dir/removedups.pl
  set remove_pads_parts = $pads_script_dir/removepadsparts.pl

  if (! $?_is_dyld_library_path) then
    setenv DYLD_LIBRARY_PATH ""
  endif
  if (! $?_is_ld_library_path) then
    setenv LD_LIBRARY_PATH ""
  endif
  if (! $?_is_shlib_path) then
    setenv SHLIB_PATH ""
  endif
  if (! $?_is_manpath) then
    setenv MANPATH ""
  endif
  if (! $?_is_ocaml_lib) then
    setenv OCAML_LIB_DIR /usr/local/lib/ocaml
  endif
  if (! $?_is_ocaml_bin) then
    setenv OCAML_BIN_DIR /usr/local/bin
  endif
  if (! $?_is_galax_home) then
    setenv GALAX_HOME /home/mff/Galax
  endif
  if (! $?_is_galax_src) then
    setenv GALAX_SRC /home/mff/galax
  endif
  if (! $?_is_pcre_lib_dir) then
    setenv PCRE_LIB_DIR /home/mff/pcre-4.5-rh9/lib
  endif

  # remove old PADS path components
  setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH} | $remove_pads_parts`
  setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH} | $remove_pads_parts`
  setenv SHLIB_PATH      `echo ${SHLIB_PATH} | $remove_pads_parts`
  setenv MANPATH         `echo ${MANPATH} | $remove_pads_parts`
  setenv PATH            `echo ${PATH} | $remove_pads_parts`

  # add new path components
  setenv DYLD_LIBRARY_PATH `echo ${pads_lib_dir}:${ast_lib_dir}:${DYLD_LIBRARY_PATH} | $remove_dups`
  setenv LD_LIBRARY_PATH `echo ${pads_lib_dir}:${ast_lib_dir}:${LD_LIBRARY_PATH} | $remove_dups`
  setenv SHLIB_PATH      `echo ${pads_lib_dir}:${ast_lib_dir}:${SHLIB_PATH} | $remove_dups`
  setenv MANPATH         `echo ${pads_man_dir}:${ast_man_dir}:${MANPATH} | $remove_dups`
  setenv PATH            `echo ${pads_bin_dir}:${pads_script_dir}:${PATH} | $remove_dups`

  if (-d $OCAML_LIB_DIR) then
    setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    setenv SHLIB_PATH `echo ${SHLIB_PATH}:${OCAML_LIB_DIR} | $remove_dups`
  endif
  if (-d $OCAML_LIB_DIR) then
    setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    setenv SHLIB_PATH `echo ${SHLIB_PATH}:${OCAML_LIB_DIR} | $remove_dups`
  endif
  if (-d $GALAX_HOME/lib/c) then
    setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
    setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
    setenv SHLIB_PATH `echo ${SHLIB_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
  endif
  if (-d $PADSGLX_LIB_DIR) then
    setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
    setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
    setenv SHLIB_PATH `echo ${SHLIB_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
  endif
  if (-d $PCRE_LIB_DIR) then
    setenv DYLD_LIBRARY_PATH `echo ${DYLD_LIBRARY_PATH}:${PCRE_LIB_DIR} | $remove_dups`
    setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${PCRE_LIB_DIR} | $remove_dups`
    setenv SHLIB_PATH `echo ${SHLIB_PATH}:${PCRE_LIB_DIR} | $remove_dups`
  endif

  if ($_pads_use_nmake == 1) then
    set ast_bin_dir  = $AST_HOME/bin
    setenv PATH `echo ${ast_bin_dir}:${PATH} | $remove_dups`
  endif

  # on linux, figure out where ligcc_s.so is using /usr/common/bin/gcc (if it exists)
  # and add that dir to LD_LIBRARY_PATH.  This is required because
  # gsf builds libast using /usr/common/bin/gcc.
  #  switch ("`uname -a`")
  #    case *Linux*:
  #    case *linux*:
  #      if (-e /usr/common/bin/gcc) then
  #        set _foo = `/usr/common/bin/gcc -print-file-name=libgcc_s.so`
  #        set _bar = $_foo:h
  #        set _zot = `(cd $_bar; pwd)`
  #        setenv LD_LIBRARY_PATH `echo ${LD_LIBRARY_PATH}:${_zot} | $remove_dups`
  #        unset _foo
  #        unset _bar
  #        unset _zot
  #        endif
  #      breaksw
  #  endsw

  if ($_pads_verbose != 0) then
    echo "PADS_HOME=$PADS_HOME"
    echo "INSTALLROOT=$INSTALLROOT"
    echo "AST_ARCH=$AST_ARCH"
    echo "AST_HOME=$AST_HOME"
    echo "DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH"
    echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"
    echo "SHLIB_PATH=$SHLIB_PATH"
    echo "MANPATH=$MANPATH"
    echo "PATH=$PATH"
    echo "OCAML_LIB_DIR=$OCAML_LIB_DIR"
    echo "OCAML_BIN_DIR=$OCAML_BIN_DIR"
    echo "GALAX_HOME=$GALAX_HOME"
    echo "GALAX_SRC=$GALAX_SRC"
    echo "PCRE_LIB_DIR=$PCRE_LIB_DIR"
    echo " "
  endif

  unset ast_lib_dir
  unset ast_man_dir
  unset pads_bin_dir
  unset pads_lib_dir
  unset pads_man_dir
  unset pads_scripts_dir
  unset remove_dups
endif

unset _is_pads_home
unset _is_ast_home
unset _is_installroot
unset _is_dyld_library_path
unset _is_ld_library_path
unset _is_shlib_path
unset _is_manpath
unset _is_ocaml_lib
unset _is_galax_home
