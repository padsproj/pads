# Q_DO_SETENV.sh is for use with sh/ksh/bash.
# It is the 'quite' version of DO_SETENV.sh
# From the same directory as Q_DO_SETENV.sh, do:
#     . ./Q_DO_SETENV.sh
#

_pads_do_program=Q_DO_SETENV.sh
_pads_status=OK 

if [ "$PADS_HOME"x = x ]; then
  echo "##############################################################################"
  echo "# Set env var PADS_HOME and then use DO_SETENV.sh again."
  echo "##############################################################################"
  echo " "
  _pads_status=FAILED
fi

if [ $_pads_status = "OK" ]; then
  _pads_verbose=0
  _pads_use_nmake=0
  . $PADS_HOME/scripts/INT_DO_SETENV.sh
  _pads_use_nmake=
  _pads_verbose=
fi

_pads_status=
_pads_do_program=
