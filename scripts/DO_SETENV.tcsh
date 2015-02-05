#!/bin/echo You should SOURCE rather than execute
#
# DO_SETENV.tcsh is for use with csh/tcsh
# From the same directory as DO_SETENV.tcsh, do:
#      source DO_SETENV.tcsh
#

set _pads_status = OK
set _pads_do_prog = DO_SETENV.tcsh

if (! $?PADS_HOME) then
  set _pads_status = FAILED
else
  if ("$PADS_HOME"x == x) then
    set _pads_status = FAILED
  endif
endif

if ($_pads_status == "FAILED") then
  echo "##############################################################################"
  echo "# Set env var PADS_HOME and then use $_pads_do_prog again."
  echo "##############################################################################"
  echo " "
endif

if ($_pads_status == "OK") then
  set _pads_verbose = 1
  set _pads_use_nmake = 0
  source $PADS_HOME/scripts/INT_DO_SETENV.tcsh
  unset _pads_use_nmake
  unset _pads_verbose
endif

unset _pads_do_prog
unset _pads_status
