# INT_DO_SETENV.sh is a helper script.
# See DO_SETENV.sh and Q_DO_SETENV.sh.

_pads_status=OK 

if [ "$_pads_verbose"x = x ]; then
  echo "##############################################################################"
  echo "# Do not use INT_DO_SETENV directly, use DO_SETENV or Q_DO_SETENV"
  echo "##############################################################################"
  echo " "
  _pads_status=FAILED
fi


if [ $_pads_status = "OK" ]; then
  if [ "$_pads_verbose" != 0 ]; then
    echo " "
  fi

  if [ "$PADS_HOME"x = x ]; then
    echo "##############################################################################"
    echo "# Set env var PADS_HOME and then use $_pads_do_prog again."
    echo "##############################################################################"
    echo " "
    _pads_status=FAILED
  fi
fi

if [ $_pads_status = "OK" ]; then
  if [ ! -e $PADS_HOME/ast-ast/bin/package.cvs ]; then
    echo "##############################################################################"
    echo "# Invalid setting (?) : PADS_HOME = $PADS_HOME"
    echo "#"
    echo "# Cannot find $PADS_HOME/ast-ast/bin/package.cvs"
    echo "#"
    echo "# Set env var PADS_HOME correctly and then use DO_SETENV.tcsh again."
    echo "##############################################################################"
    echo " "
    _pads_status=FAILED
  fi
fi

if [ $_pads_status = "OK" ]; then
  export AST_ARCH=`$PADS_HOME/ast-ast/bin/package.cvs SHELL=$SHELL`

  if [ "$AST_HOME_FORCE"x = x ]; then
    export AST_HOME=$PADS_HOME/ast-ast/arch/$AST_ARCH
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var AST_HOME to $AST_HOME"
      echo "# If you do not like this setting, set AST_HOME_FORCE to the"
      echo "# desired value for AST_HOME, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    fi
  else
    export AST_HOME=$AST_HOME_FORCE
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var AST_HOME to value of AST_HOME_FORCE = $AST_HOME"
      echo "# If you prefer to use the PADS default, unsetenv AST_HOME_FORCE"
      echo "##############################################################################"
      echo " "
    fi
  fi

  if [ "$INSTALLROOT_FORCE"x = x ]; then
    if [ "$GIGASCOPE_HOME"x = x ]; then
      export INSTALLROOT=$PADS_HOME/ast-ast/arch/$AST_ARCH
    else
      export INSTALLROOT=$GIGASCOPE_HOME
    fi
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var INSTALLROOT to $INSTALLROOT"
      echo "# If you do not like this setting, set INSTALLROOT_FORCE to the"
      echo "# desired value for INSTALLROOT, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    fi
  else
    export INSTALLROOT=$INSTALLROOT_FORCE
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var INSTALLROOT to value of INSTALLROOT_FORCE = $INSTALLROOT"
      echo "# If you prefer to use the PADS default, unsetenv INSTALLROOT_FORCE"
      echo "##############################################################################"
      echo " "
    fi
  fi

  if [ "$PADSGLX_LIB_DIR"x = x ]; then
    export PADSGLX_LIB_DIR=$PADS_HOME/padsc/pads-glx/$AST_ARCH
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var PADSGLX_LIB_DIR to $PADSGLX_LIB_DIR"
      echo "# If you do not like this setting, set PADSGLX_LIB_DIR_FORCE to the"
      echo "# desired value for PADSGLX_LIB_DIR, then use $_pads_do_prog again."
      echo "##############################################################################"
      echo " "
    fi
  else
    export PADSGLX_LIB_DIR=$PADGLX_LIB_DIR_FORCE
    if [ "$_pads_verbose" != 0 ]; then
      echo "##############################################################################"
      echo "# Setting env var PADSGLX_LIB_DIR to value of PADSGLX_LIB_DIR_FORCE = $PADSGLX_LIB_DIR"
      echo "# If you prefer to use the PADS default, unsetenv PADSGLX_LIB_DIR_FORCE"
      echo "##############################################################################"
      echo " "
    fi
  fi


  if [ "$OCAML_LIB_DIR"x = x ]; then
    export OCAML_LIB_DIR=/usr/local/lib/ocaml
  fi
  if [ "$OCAML_BIN_DIR"x = x ]; then
    export OCAML_BIN_DIR=/usr/local/bin
  fi
  if [ "$GALAX_HOME"x = x ]; then
    export GALAX_HOME=/home/mff/Galax
  fi
  if [ "$GALAX_SRC"x = x ]; then
    export GALAX_SRC=/home/mff/galax
  fi
  if [ "$PCRE_LIB_DIR"x = x ]; then
    export PCRE_LIB_DIR=/home/mff/pcre-4.5-rh9/lib
  fi

  if [ ! -e $INSTALLROOT ]; then
    (mkdir -p $INSTALLROOT > /dev/null 2>&1) || _pads_status=FAILED
  fi
  if [ ! -e $INSTALLROOT/bin ]; then
    (mkdir -p $INSTALLROOT/bin > /dev/null 2>&1) || _pads_status=FAILED
  fi
  if [ ! -e $INSTALLROOT/include ]; then
    (mkdir -p $INSTALLROOT/include > /dev/null 2>&1) || _pads_status=FAILED
  fi
  if [ ! -e $INSTALLROOT/lib ]; then
    (mkdir -p $INSTALLROOT/lib > /dev/null 2>&1) || _pads_status=FAILED
  fi
  if [ ! -e $INSTALLROOT/man ]; then
    (mkdir -p $INSTALLROOT/man > /dev/null 2>&1) || _pads_status=FAILED
  fi

  if [ $_pads_status = "FAILED" ]; then
    echo "##############################################################################"
    echo "# WARNING: Could not create INSTALLROOT $INSTALLROOT"
    echo "# or one of its subdirs (bin, include, lib, man).  Correct problem (e.g.,"
    echo "# define another INSTALLROOT) and then use DO_SETENV.tcsh again."
    echo "##############################################################################"
    echo " "
  fi

  ast_lib_dir=$AST_HOME/lib
  ast_man_dir=$AST_HOME/man

  pads_bin_dir=$INSTALLROOT/bin
  pads_lib_dir=$INSTALLROOT/lib
  pads_man_dir=$INSTALLROOT/man
  pads_script_dir=$PADS_HOME/scripts
  remove_dups=$pads_script_dir/removedups.pl
  remove_pads_parts=$pads_script_dir/removepadsparts.pl

  # remove old PADS path components
  export DYLD_LIBRARY_PATH=`echo ${DYLD_LIBRARY_PATH} | $remove_pads_parts`
  export LD_LIBRARY_PATH=`echo ${LD_LIBRARY_PATH} | $remove_pads_parts`
  export SHLIB_PATH=`echo ${SHLIB_PATH} | $remove_pads_parts`
  export MANPATH=`echo ${MANPATH} | $remove_pads_parts`
  export PATH=`echo ${PATH} | $remove_pads_parts`

  # add new path components
  export DYLD_LIBRARY_PATH=`echo ${pads_lib_dir}:${ast_lib_dir}:${DYLD_LIBRARY_PATH} | $remove_dups`
  export LD_LIBRARY_PATH=`echo ${pads_lib_dir}:${ast_lib_dir}:${LD_LIBRARY_PATH} | $remove_dups`
  export SHLIB_PATH=`echo ${pads_lib_dir}:${ast_lib_dir}:${SHLIB_PATH} | $remove_dups`
  export MANPATH=`echo ${pads_man_dir}:${ast_man_dir}:${MANPATH} | $remove_dups`
  export PATH=`echo ${pads_bin_dir}:${pads_script_dir}:${PATH} | $remove_dups`

  if [ -e $OCAML_LIB_DIR ]; then
    export DYLD_LIBRARY_PATH=`echo ${DYLD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    export LD_LIBRARY_PATH=`echo ${LD_LIBRARY_PATH}:${OCAML_LIB_DIR} | $remove_dups`
    export SHLIB_PATH=`echo ${SHLIB_PATH}:${OCAML_LIB_DIR} | $remove_dups`
  fi
  if [ -e $GALAX_HOME/lib/c ]; then
    export DYLD_LIBRARY_PATH=`echo ${DYLD_LIBRARY_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
    export LD_LIBRARY_PATH=`echo ${LD_LIBRARY_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
    export SHLIB_PATH=`echo ${SHLIB_PATH}:${GALAX_HOME}/lib/c | $remove_dups`
  fi
  if [ -e $PADSGLX_LIB_DIR ]; then
    export DYLD_LIBRARY_PATH=`echo ${DYLD_LIBRARY_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
    export LD_LIBRARY_PATH=`echo ${LD_LIBRARY_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
    export SHLIB_PATH=`echo ${LD_LIBRARY_PATH}:${PADSGLX_LIB_DIR} | $remove_dups`
  fi
  if [ -e $PCRE_LIB_DIR ]; then
    export DYLD_LIBRARY_PATH=`echo ${DYLD_LIBRARY_PATH}:${PCRE_LIB_DIR} | $remove_dups`
    export LD_LIBRARY_PATH=`echo ${LD_LIBRARY_PATH}:${PCRE_LIB_DIR} | $remove_dups`
    export SHLIB_PATH=`echo ${LD_LIBRARY_PATH}:${PCRE_LIB_DIR} | $remove_dups`
  fi

  if [ "$_pads_use_nmake" != 0 ]; then
    ast_bin_dir=$AST_HOME/bin
    export PATH=`echo ${ast_bin_dir}:${PATH} | $remove_dups`
  fi

  if [ "$_pads_verbose" != 0 ]; then
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
  fi
fi
