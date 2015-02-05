#!ksh
# Mnemonic: stdfun
# Abstract: This file contains several standard functions that are included
#           and used by many scripts.  The file should be in the user's 
#           path and can be included using the following command:
#                   . stdfun.ksh
#           The following functions are contained in this file:
#                getarg, error_msg, usage, cleanup, lockfile, unlockfile
#                verbose, log_msg, incseq, yesterday, startup, solo
#
#           In addition to providing standard functions any aliases for 
#           the rm, cp, and mv commands are removed, and a trap is set 
#           for signals 1,2,3 and 15. If any of these signals are caught
#           the cleanup function is invoked.
#
# Mods:		13 Apr 2001 (sd) : Ported into Ningaui.
#		26 Mar 2002 (sd) : addes spaceman_nm function
#		15 May 2002 (sd) : ensure solo name has solo in it to use as
#		a delete mask during system start as /tmp is not cleared on 
#		linux.
#		17 Jun 2002 (sd) : To ensure -r option supported on spaceman_nm
#		26 Feb 2002 (sd) : added space before -x in trace-on test.
# -------------------------------------------------------------------------
#  WARNING:  stdfun.ksh canNOT be documented using scd as it is an imbed
#            script segment. The SCD documenttion for stdfun.ksh is in the 
#            file stdfun.xfm in this directory.
# -------------------------------------------------------------------------

#
# Mnemonic: getarg
# Abstract: find a value associated with an option in either -xvalue or 
#           -x value form.  It will assign the value to the variable name
#           passed as the first argument. The variable shift count is set
#           to the number of arguments that were used ($2 == 1; $2 and $3 == 2)
#           so the caller knows what to shift off. 
# Parms:    $1 - Name of variable to assign value to
#           $2 - -x or -xvalue option (where x is the option letter)
#           $3 - Value if $2 is only -x
# Returns:  Nothing.
# Date:     9 April 1997
# Author:   E. Scott Daniels
# -------------------------------------------------------------------------
function getarg 
{             
 shiftcount=1                  # incase user did not set this (they should!!!)
 a="${2#-?}"                   # strip -x prefix from -xvalue 
 if [[ -z "$a" ]]              # if there was no suffex on the -x option
  then                         # assume $3 has it
   a="$3"
   shiftcount=2                # caller must shift two cmd line args 
  fi
 eval $1=\"$a\"                # assign value of argument to caller's variable
}

  
#
# ----------------------------------------------------------------------------
# Mnemonic: lockfile
# Abstract: This function will attempt to lock a file by creating a directory 
#           with the same name as the file and a .lck extension.  If the 
#           directory can be made then it will continue (as only one directory
#           can be made and thus only one process can successfully create 
#           the directory). If the directory cannot be made, then it will 
#           wait until it can make the directory (unless the NOWAIT string 
#           is passed in as $2). Once the directory can be made, a file 
#           with the current process ID is created in the directory which 
#           identifies the owner of the lock.
# Parms:    $1 - The file name to lock
#           $2 - The word NOWAIT if the function should return immediatly
#                The word MAXWAIT if the function should return a failure
#                if unable to get the lock after MAX_LOCKWAIT attemtps. 
# Returns:  Exit code 0 indicates that the lock was successfully obtained
#           exit code 1 indicates that the lock could not be obtained
#           exit code 2 indicates that the file name was not passed in
# Date:     3 July 1997
# Author:   E. Scott Daniels
# Mods:     26 Dec 1997 (sd) - To add log msg if waiting a long time and 
#                              ability to escape after MAX_WAIT (I67)
#           29 Dec 1997 (sd) - To add log msg if lock cleared after alarm
#                              and to capture process name in lock file.
# ----------------------------------------------------------------------------
function lockfile
{
 if [[ -z "$1" ]]
  then
   return 2 
  fi

 if ! mkdir $1.lck >/dev/null 2>&1             # make a directory
  then
   if [[ -n "$2"  && "$2" = "NOWAIT" ]]        # yes - user elected not to wait
    then                     
     return 1                                  # so immediate error return
    else
     _alrm=${MAX_LOCKWAIT:-60}                 # alarm if waiting a long time
     unset _opid

     while ! mkdir $1.lck >/dev/null 2>&1      # wait until we can make dir
      do
       if [[ -z "$_opid" ]]                    # get initial owner of the lock
        then
          _x=`ls $1.lck/lock.*`                        
          _opid=${_x##*.}    
        fi
       
       if [[ "$_alrm" -le 0 ]]                 # its been too long
        then
          _x=`ls $1.lck/lock.*`                        
          _cpid=${_x##*.}                      # get current owner of lock 

         if [[ "$_opid" = "$_cpid" ]]          # stagnant owner?
          then 
           if [[ "$2" = "MAXWAIT" ]]           # caller wanted only a max wait 
            then 
             return 1                          # fail now - no alarm
            fi
 
           ng_log $PRI_CRITICAL $argv0 "long wait on lock: $1 owner=$_opid UT0007"
           _alrm=${MAX_LOCKWAIT:-180}          # alarm if waiting a long time
           _msg=1
           _opid=$cpid                         # save current for next time
          fi
         fi                                    # end if owner not changing

       sleep 5                                        # nite nite
       _alrm=$(( $_alrm - 1 ))
      done

     if [[ -n "$_msg" ]]                      # we issued a long wait message 
      then
       ng_log $PRI_NOTICE $argv0 "lock cleared, no problems now"
      fi
    fi                         # end if nowait
  fi                           # end if lock existed

 #touch $1.lck/lock.$$          # establish owner of the lock with pid on file
 echo $argv0 >$1.lck/lock.$$       # lock with pid, process name into file
 if [[ ! -f $1.lck/lock.$$ ]]  # file did not get created
  then
   ng_log $PRI_ERROR $argv0 "lockfile: unable to create file in $1.lck: lock.$$"
  fi
 lock_list="$lock_list $1"     # keep list of locked files for cleanup
 return 0 
}                              # end lockfile

#
#---------------------------------------------------------------------------
# Mnemonic: unlockfile
# Abstract: This routine will unlock a given file if the lock directory 
#           contains a file called lock.$$ (indicating that this process 
#           is the owner). 
# Parms:    $1 file name
# Returns:  0  - Success
#           1  - Unable to unlock
#           2  - No file name passed in 
#           3  - File was not locked - no action
# Date:     3 July 1997
# Modified: 14 May 1998 - To mv lck dir prior to rm to prevent false 
#                         messages when busy
# Author:   E. Scott Daniels
# --------------------------------------------------------------------------
function unlockfile
{
 if [[ -z "$1" ]]                        # ensure caller passed name in
  then
   return 2 
  fi

 if [[ -d $1.lck ]]                      # ensure directory is there 
  then
   if [[ -f $1.lck/lock.$$ ]]            # ensure we own the lock
    then
     mv $1.lck $1.lckx$$                   # effectively delete it
     rm -rf  $1.lckx$$                     # then we can really delete it
     if [[ -d $1.lckx$$ ]]                 # ensure it went away 
      then
       ng_log $PRI_ERROR $argv0 "unlockfile: remove left lock hanging: $1.lckx$$"
      fi
   else
    return 1                             # dont own it - get out w/error 
   fi                                    # end if lock existed
  else                                   # no lock file existed
   return 3
  fi

 return 0 
}


# ---------------------------------------------------------------------------
# Mnemonic: incseq
# Abstract: This routine will lock and increase the sequence number in the 
#           file whose name is passed in. If the current sequence value is 
#           >= to  the wrap value, the sequence number will be reset
#           to 0. If the sequence file does not exist, then it is intialized
#           at 1 and 0 is returned.
# Parms:    $1 - The name of the sequence file
#           $2 - The wrap value - 0 if no wrap needed (0 default).
#           $3 - The base for the sequence 0 default
#           $4 - The string NOWAIT if we should not wait on a lock
# Returns:  The sequence value is returned via an echo statement... the user
#           must assign the results of this function to a variable or it 
#           will be echoed to the stdout device.  If there is an error, -1
#           is echoed. 
# Date:     3 July 1997
# Author:   E. Scott Daniels
#
# Modified: 14 Dec 1997 - To prevent invalid stuff in sequence file from 
#                         causing errors.
#            7 Jun 1998 - To wait to unlock seqfile until after update.
#           22 Jun 1998 - To lock file FIRST 
#           23 Sep 1998 - To support _SEQ_BASE variable.
#		03 Jul 2002 - To adjust for KSH  <$1 difference.
# Example:  snum=`incseq $seq_file $max_seq`  # get the sequence number
# ----------------------------------------------------------------------------
function incseq
{
 typeset max=${2:-0}             # max value - roll point
 typeset base=${3:-0}            # index base 
 typeset seq=$base

 if lockfile $1 $4                                 # ensure lock on file
  then
   if [[ -f "$1" ]]                                # if $1 is a file 
    then
     read seq <${1:-/dev/fd/0}                                  # get current value
    fi
  else
   echo -1
   return 1                                      # error if cannot get lock
  fi

 seq=${seq%%[!0-9]*}                # ensure seq is numeric, "" if not
 if [[ -z "$seq" ]]                 # prevent failure in $(( )) later (I39)
  then
   seq=$base                        # nothing - set at base
  fi

 if [[ "$max" -ne 0  && $((seq + 1)) -ge $max ]]   # need to roll it over
  then
   echo $base >$1                  # save rolled value
  else
   echo $((seq + 1)) >$1                           # save next value
  fi

 unlockfile $1                                     # release file

 echo $seq                                         # Pass back sequence #
 return 0                                          # good return code
} 


# ----------------------------------------------------------------------------
#
# Mnemonic: cleanup
# Abstract: This function should be called in place of the exit function 
#           so that any tmp files created will be deleted before the script 
#           exits. Typical use is to list this function on the trap command.
# Parms:    $1 - Return code to exit with
# Returns:  Does not return to the caller - exits the process
# Date:     9 April 1997
# Author:   E. Scott Daniels
# --------------------------------------------------------------------------
function cleanup                # ensure temp files are deleted before leaving
{
 $trace_on

 if [[ "$1" = "-k" ]]           # keep temp files?
  then
   shift                    
  else
   rm -f /tmp/*.$$ >/dev/null 2>&1
   rm -f ${TMP:-/ningaui/tmp}/*.$$ >/dev/null 2>&1

   if [[ ${1:-0} -eq 0 && -e ${_trace_log:-nosuchfile} ]]
   then
	rm -f $_trace_log
   fi
  fi

 if [[ -f $_solo_file ]]          # solo file still lives?
  then
   rm -f $_solo_file >/dev/null 2>&1         # nuke it
  fi

 for f in $lock_list                         # attempt to unlock each listed 
  do
   if unlockfile $f                          # successful unlock is "bad"
    then
     ng_log $PRI_WARN $argv0 "lockfile existed at cleanup: $f"
    fi
  done

 exit ${1:-0}                                # do not trust default
}

# ----------------------------------------------------------------------------
#
# Mnemonic: log_msg
# Abstract: This function will echo the message passed in to the process'
#           log file (assumed to be stdout unless LOG_MSG_FILE is defined)
#           The user message is prefixed with the current date/time.
# Parms:    Message text
# Returns:  Nothing.
# Author:   E. Scott Daniels
# Mod:		25 Jan 2002 - to cope with a problem when writing to /dev/fd/2
#		02 Jul 2002 - to convert to printf and change $@ to $*
# ----------------------------------------------------------------------------
function log_msg                
{
	if [[ $LOG_MSG_FILE = "/dev/fd/2" ]]
	then
		printf "`ng_dt -p` [$$] $* \n"  >&2		# do NOT use $@
	else
		printf "`ng_dt -p` [$$] $* \n"  >>$LOG_MSG_FILE
	fi
}

# ----------------------------------------------------------------------------
#
# Mnemonic: error_msg
# Abstract: This function will echo the message passed in to the standard
#           error device. The message is prefixed with the script name ($0).
# Parms:    Message text
# Returns:  Nothing.
# Author:   E. Scott Daniels
#		02 Jul 2002 (sd) : convert to $* and printf
# ----------------------------------------------------------------------------
function error_msg                  # generate an error message to stderror
{
 printf "`ng_dt -p` [$$] ${argv0##*/}: $*\n" >&2
}

# ----------------------------------------------------------------------------
#
# Mnemonic: usage
# Abstract: This function will generate a usage message to the standard error
#           device. The string "Usage:" and the script name ($0) are prepended
#           to the usage string. The usage string may be passed in on the 
#           command line or the function will look for it in the $ustring 
#           variable.
# Parms:    $1 - The string to echo ($ustring used if omitted)
# Returns:  Nothing.
# Author:   E. Scott Daniels
# ---------------------------------------------------------------------------
function usage
{
 echo "Usage:" `basename $argv0` "${1:-$ustring}" >&2
}

#
#---------------------------------------------------------------------------
#
# Mnemonic: verbose
# Abstract: This funton will echo the parameters passed to it if
#           the verbose variable is set to "true".  The string is 
#           echoed to STANDARD OUTPUT or the file defined by MSG_LOG_FILE.
#           If the first parameter ($1) is an at sign, the the parm list
#           is assumed to be a command. It will be executed if in verbose 
#           mode. Will also get chatty if in debug mode. 
# Parms:    Stuff to echo - all parameters echoed
# Author:   E. Scott Daniels
# ---------------------------------------------------------------------------
function verbose
{
 if [[ "$verbose" = "true"  || "$verbose" = "TRUE" || "$verbose" -gt 0 || "$_debug" = "true" ]]
  then
   if [[ "$1" = "@" ]]
    then
     shift
     "$@" >>$LOG_MSG_FILE
    else
     log_msg "$@" 
    fi
  fi
}


# -----------------------------------------------------------------------
# Mnemoic:  setkey
# Abstract: setup a standard key symbol and generate a key message to the 
#           log file (standard output)
# Parms:    $1 - Key to echo (A!! used if omitted)
# Author:   E. Scott Daniels
# -----------------------------------------------------------------------
function setkey
{
  key=${1:-A!!}                      # set variable incase user wants to know
  printf  "\n$key  `date`  script=$argv0\n" >>$LOG_MSG_FILE
}

#
# ---------------------------------------------------------------------------
#  Mnemonic: yesterday.ksh
#  Abstract: This file can be . included into a script to provide a yesterday
#            function.  The function will calculate the date previous to 
#            either the current date or the m d y date passed in on the 
#            command line. 
#  Parms:    $1 - Month (current date assumed if $1, $2, $3 are omitted)
#            $2 - day
#            $3 - Year (1900 + y assumed if $3 is < 10)
#  Returns:  Echos the date of yesterday.
#  Date:     25 September 1995
#  Author:   E. Scott Daniels
#
#  Usage:    varname=`yesterday [m d y]`
#  Modified: 13 Aug 1997 - To convert to kshell from Bourne shell.
#            22 Oct 1997 - To accept date in yyyy mm dd OR mm dd yy and to 
#                          return date in yyyy mm dd format
# ---------------------------------------------------------------------------

function yesterday
{
 if [[ $# -lt 3 ]]                         # none/not enough command line parms
  then
   date "+%m %d %Y" | read y_m y_d y_y     # get current date
  else
   if [[ "$1" -gt 12 ]]                    # assume its is in yyyy mm dd
    then
      y_y=$1
      y_m=$2
      y_d=$3                                  # get user's date to work with
    else
      y_m=$1
      y_d=$2
      y_y=$3                                  # get user's date to work with
    fi
   if [[ $y_y -lt 100 ]]
    then
     y_y=$(( $y_y + 1900 ))                # want to work with 4 digit years
    fi
  fi

 y_d=$(( $y_d - 1 ))             # bump back to yesterday
 if [[ $y_d -lt 1 ]]
  then
   y_m=$(( $y_m - 1 ))           # crossed a month boundry
   if [[ $y_m -lt 10 ]]          # need to add a lead 0
    then
     y_m=0$y_m
    fi

   if [[ $y_m -lt 1 ]]
    then
     y_m=12                      # crossed a year boundry
     y_y=$(( y_y - 1 ))
    fi

   case $y_m in                             # set to last day in new month
    04 | 06 | 09 | 11)            y_d=30 ;;
    01|03|05|07|08|10|12)         y_d=31 ;;
    02)                           y_d=$(( 28 + `leapdays $y_y`)) ;;
   esac
  else
   if [[ $y_d -lt 10 ]]
    then 
     y_d="0$y_d"
    fi
  fi

 echo "$y_y $y_m $y_d"            # echo date in ningaui standard format
}

# --------------------------------------------------------------------------
# Mnemonic: leapdays
# Abstract: Echo the number of leap days in the year $1
# Parms:    $1 - year to check
#
# --------------------------------------------------------------------------

function leapdays
{
 echo `awk "END {printf \"%d\", $1 % 4 ? 0 : ($1 % 100 ? 1 : ($1 % 400 ? 0 : 1))}" </dev/null`
}
 
#
# -------------------------------------------------------------------------
# Mnemonic: cvt_date 
# Abstract: Converts from one date type to another. If a julian date is 
#           passed in it is converted to month, day year. If month,day,
#           year is passed in it is converted to julian. All years are 
#           assumed to be 4 digit.
# Parms:    Three styles of parameters may be passed in:
#           1.  $1 = m  $2 = d $3 = y
#           2.  $1 = y  $2 = m  $3 = d
#           3.  $1 = yyyynnn    (nnn is the day number 1-365)
#           
# Returns:  Echos the converted date to stdout
# Date:     8 October 1997
# Author:   E. Scott Daniels
# -------------------------------------------------------------------------
#
function cvt_date
{
  _sums="000031059090120151181212243273304334366"         # sums by month

 if [[ $# -ge 3 ]]       # assume m d y or y m d passed in
  then
   if [[ $1 -gt 12 ]]    # assume year first if > 12
    then
     _y=$1                # allow either format ymd or mdy
     _m=$2
     _d=$3
    else
     _m=$1
     _d=$2
     _y=$3
    fi

   if [[ $_m -gt 2 ]]
    then
     d=$(( `leapdays $_y` + $_d ))           # need to add leap day if leap yr
    fi

   echo $_y`awk -v sums=$_sums -v m=$_m -v d=$_d 'END { 
       printf "%03d", substr( sums, ((m-1)*3)+1, 3 ) + d }'</dev/null`

  else
   if [[ $# -ge 1 ]]                           # assume julian date passed in 
    then
     _y=${1%%???}                                   # pick off the year
     _days=${1#????}                                # pick off days 

     if [[ `leapdays $_y` = 1 ]]
      then
       _sums="000031060091121152182213244274305335367"       # leap year sums
      fi

     echo "$_y "`awk -v sums="$_sums" -v days=$_days 'END {
       for( i = 1; days > substr( sums, (i*3)+1, 3)+0; i++ );
       printf "%02d %02d", i, days - substr( sums, ((i-1)*3)+1, 3)}
       '</dev/null`
     #echo $_y $_m $_d
    fi
  fi

 unset _m _d _y _days _sums
}                           # end cvt_date 

# --------------------------------------------------------------------------
# Mnemonic: start_msg
# Abstract: This function will generate a standard starting message to the 
#           ningaui master log. All parameters passed in will be written 
#           on the log message. If one or more parameters is enclosed in 
#           curley braces (space seperated), then it is assumed to be a 
#           variable name and is expanded and labled in the log message. 
# Example:  start_msg $* { admin_dir cache_dir }  will display all parms
#           passed to the script, and expand the admin_dir and cache dir 
#           variables.
# Parms:    All parameters will be added to the message.
# Returns:  Nothing.
#---------------------------------------------------------------------------
function start_msg
{
 eval indicator=\$$(($#-1))
 typeset _ex=false 
 typeset _stuff=""


 while [[ -n "$1" ]]
  do
   case $1 in
    {*})                             # expand single name
       _x=${1#\{}
       _x=${_x%\}} 
       if [[ -n "$_x" ]]
        then
         eval _stuff=\"$_stuff $_x=\(\$$_x\)\"
        fi
       ;;
    {*) _ex=true                      # start expanding variable names
       _x=${1#\{}                     # see if butted against first var
       if [[ -n "$_x" ]]
        then
         eval _stuff=\"$_stuff $_x=\(\$$_x\)\"
        fi
       ;;

    *}) 
       if [[ "$_ex" = "true" ]]       # must be in expand mode to stop 
        then
         _ex=false                     # stop expanding variable names
         _x=${1%\}}
         if [[ -n "$_x" ]]
          then
           eval _stuff=\"$_stuff $_x=\(\$$_x\)\"
          fi
        fi
       ;;

    *) if [[ $_ex = "true" ]]        # add var name and it value to stuff
        then
         eval _stuff=\"$_stuff $1=\(\$$1\)\"
        else
         _stuff="$_stuff $1"      # just add the parameter to stuff
        fi
        ;;
   esac
  shift
  done

 ng_log $PRI_INFO $argv0 "starting: $_stuff CONFIG=($CONFIG) STDFUN=($STDFUN)"

 unset _ex _stuff  
}


#
#---------------------------------------------------------------------------
# Mnemonic:	$trace_on/$trace_off/_trace_init
# Abstract:	These functions and "macros" will establish and facilitate the 
#		trace environment. Sets up several "global" things:
#		trace_on - turns on tracing (or null)
#		trace_off- turns off tracing (or null)
#		_switched_log - set to indicate that log file was switched
#		_trace_log - set to name of tracing log for cleanup
#		_trace_init - function to initialise the log file etc.
#		
#		If the -x option is set in the script's command line then the 
# 		trace_on/off macros are setup; otherwise they are null. The 
#		using script must invoke $trace_on to start tracing (suggested
#		at the top of each function and right after the standard funcations
#		are included.
# Parms:   	None; if user sets the varible trace_log before the first call
#		to trace_on, then that file will be used for the log file (detached
#		scripts ONLY. If unset, then $NG_ROOT/site/log/<argv0>.$$ is used.
#		Cleanup will delete this log file unless it is called with 
#		the -k option or the return code is > 0.
# Returns: 	Nothing.
# Date:     	5 July 2001
# Author: 	E. Scott Daniels
# -------------------------------------------------------------------------
#
_trace_switched_log=0
function _trace_init
{
	# DONT call trace_on here as it will become recursive and die
	if [[ -n "$trace_on" ]]
	then
		set -x
	fi

        if [[ $_trace_switched_log -lt 1 ]]	# if we have not switched the log yet
        then
                _trace_switched_log=1

                if [[ $_detached -gt 0 ]]	# we switch only for daemons
                then
                        typeset shortname=${argv0##*/}
                        _trace_log=${trace_log:-$NG_ROOT/site/log/$shortname.$$}
                        echo  "switching log to: $_trace_log" >&2
                        exec >>$_trace_log 2>&1
                fi
        fi
}

# older scripts might have used -x, but they will not have used trace_on/off, so this should be safe
if [[ "$@" = *" -x"* ]]
then
        trace_on="eval _trace_init; set -x"	# references will start/stop tracing when -x is on
        trace_off="eval set +x"
else
        trace_on=""				# harmless if -x is not on 
        trace_off=""
fi



#---------------------------------------------------------------------------
# Mnemonic: $detach
# Abstract: This function will cause the script to detach and restart 
#           itself in order to have the script run detached from the 
#           orignal parent process. It will exec stdout and stderr to 
#           what ever detach_log is set to or /dev/null if it is not set. 
#           The calling script needs to remember to do a shift immediatly
#           after the return so they can ignore the DETACHED cookie.
# Parms:    all parms that were passed in from the command line.
# Returns:  Nothing. Exits with a 0 return code if this is the first 
#           invocation (not our restart)
# Date:     14 October 1997
# Author:   E. Scott Daniels
# -------------------------------------------------------------------------
detach='eval _detach $*; shift'   # sneeky stuff to make it simple for user
function _detach
{
	$trace_on

	detach_log=${detach_log:-/dev/null}  # no log file specified then set to null
	if [[ "$1" != "DETACHED" ]]             # this is not the restart
	then
		if [[ -n "$_solo_file" ]]             # user called solo prior to detaching
		then
			rm -f $_solo_file >/dev/null 2>&1	# trash it so we can solo again
		fi

		$argv0 "DETACHED" "$@" >>$detach_log 2>&1&      # restart ourself, marked as detached
		exit 0						# original process should just exits nicely
	else
		_detached=1		# flag so script can know if necessary
	fi

	_trace_switched_log=0
	$trace_on			# force init to run to reset log after detached flag is set (new pid too)
}

# --------------------------------------------------------------------------
#  Mnemonic:  stdio
#  Abstract:  This function will redirect the standndard output and standard 
#             error for the script to the filename(s) listd on the 
#             command line. If the stderr name is not given, then it will 
#             be redirected to the stdout file. If either name is a 
#             dash (-) then that file is not changed. 
#             If the variable $detach_log is not /dev/null then it will 
#             be coppied to the new stderr file and then deleted.  This allows
#             messages generated between the $detach function call and this 
#             call not to be lost.
#  Parms:     $1 - file name for stdout (and possibly stderr)
#             $2 - file name for stderr (optional)
#  Returns:   Nothing
#  Date:      15 October 1997
#  Author:    E. Scott Daniels
# ---------------------------------------------------------------------------
function stdio 
{
 if [[ -n "$1" ]]
  then
   if [[ "$1" != "-" ]]       # leave as is if dash
    then
     exec 1>>$1
    fi

   if [[ -n "$2" ]]
    then
     if [[ "$2" != "-" ]]      # $2 supplied, but if dash, dont redirect
      then
       exec 2>>$2            
      fi
    else
     exec 2>&1                 # redirect stderr to stdout if $2 missing
    fi

   if [[ -n "$detach_log"  &&  "$detach_log" != "/dev/null" ]] 
    then
     if [[ -s "$detach_log" ]] 
      then 
       cat $detach_log >&2         # move logfile contents from temp log
       rm $detach_log              # and trash the file
      fi  
    fi
  fi
}

# --------------------------------------------------------------------------
#  Mnemonic:  hibernate
#  Abstract:  This function will check for the existence $HIBERNATE (set in
#             .config file).  The calling function should rely on the return
#             values, and do whatever it needs to do.
#  Parms:     none.
#  Returns:   0 - hibernate file exists
#             1 - hibernate file does not exist
#  Date:      19 February 1998
#  Author:    Gus MacLellan
# ---------------------------------------------------------------------------
function hibernate
{
 if [[ -f "$HIBERNATE" ]]
 then
   return 0
 else
   return 1
 fi
}

#
# -----------------------------------------------------------------------
# Mnemonic: solo
# Abstract: Ensure that this process is not already running. Error and 
#           exit if it is. The script is considered to be running if 
#           a file exists in the /tmp directory (so that it is deleted
#           if the machine crahses)
# Parms:    File name to look for in tmp directory... if file exists exit.
#           Uses the script name if omitted, logs a warning if it has 
#           a path.
# Returns:  If it returns it always returns success
# Date:     3 April 1998 (HBDTM!)
# Author:   E. Scott Daniels
# Modified: 23 Jun 1998 - To echo error message to stderr too.
# -----------------------------------------------------------------------
function solo
{
 if [[ -z "$1" || "${1##*/}" = "$1" ]]  # missing or not fully qualified
  then
   f=/tmp/solo.${1:-`basename $argv0`}           # file to check for; MUST be in /tmp
  else
   if [[ "${1#/tmp}" = "$1" ]]          # fully qualified, but not in /tmp
    then
     f="/tmp/solo.`basename $1`"
     ng_log ${PRI_WARN:-3} $argv0 "solo: file must be in /tmp; changed $1 to $f"
    else
	f=${1%/*}/solo                          # user supplied fully qualified name
	f=$f.${1##*/}				# add solo. to their basenam
    fi
  fi

 if [ -f $f.[0-9]* ]                     # dont use [[ ]]
  then
   eval ng_log ${PRI_ERROR:-3} $argv0 \"solo: already running. found file: $f.[0-9]* \"
   eval error_msg \"solo: not started, already running?? found solo file: $f.[0-9]* \"
   typeset lf=$ningaui/tmp/`basename $argv0`.solo
   echo "solo: attempted restart on: `ng_dt -p` PID=$$" >>$lf    # track event
   ps -ef  >>$lf
   cleanup 1
  else
   touch $f.$$
   _solo_file=$f.$$                       # global for cleanup
  fi

 return 0
}

# --------------------------------------------------------------------------
# Mnemonic: ed_mark
# Abstract: Add a marker to the edition log
# Parms:    $1 edtion number, $2 marker name, $3...$n user text
# Returns:  Nothing
# Date:     18 August 1998
# Author:   E. Scott Daniels
# --------------------------------------------------------------------------
function ed_mark
{
 typeset ed=$1
 typeset m=$2
 shift 2
 ng_log $ED_LOG_MARK $argv0 "e=$ed marker=$m $*"            # DONT use $@
}

# --------------------------------------------------------------------------
# Mnemonic: show_man
# Abstract: Causes the scd section of a script to be formatted and displayed
# Parms:    none
# Returns:  Nothing
# Date:     13 Apr 2001
# Author:   E. Scott Daniels
# --------------------------------------------------------------------------
function show_man
{
	if [[ -n $argv0 ]]
	then
		(export XFM_IMBED=$NG_ROOT/lib; tfm $argv0 stdout .im $XFM_IMBED/scd_start.im : | ${PAGER:-more})
	fi
}


# --------------------------------------------------------------------------
# Mnemonic: ng_leader
# Abstract: Causes the scd section of a script to be formatted and displayed
# Parms:    none
# Returns:  The name of the leader
# Date:     10 May 2001
# Author:   E. Scott Daniels
# --------------------------------------------------------------------------
function ng_leader
{
	if [[ -f $NG_ROOT/adm/leader ]]
	then
		head -1 $NG_ROOT/adm/leader
	else
		echo "NoLeader"
	fi
}

function ng_cluster
{
	if [[ -f $NG_ROOT/adm/cluster ]]
	then
		head -1 $NG_ROOT/adm/cluster
	else
		echo "NoCluster"
	fi
}

# ---------------------------------------------------------------------------
# Mnemonic:	chk_parms
# Abstract:	Runs the list of tokens on the command line and determines if 
#		they have been set. Generates a message and bad return if any
#		are missing.  
# Parms:	Tokens to check of the syntax: flag.parmname.varname (flag may
#		be omitted). to check that the variable scooter has been set
# 		and to issue an error message that -s value is what is used 
#		to set this parm, the token "-s.value.scooter" would be passed
#		in. 
# Date:		13 December 2001
# Author:	E. Scott Daniels
# ---------------------------------------------------------------------------
function chk_parms
{
        typeset errors=0
        typeset missing=""

        while [[ -n $1 ]]
        do

                flag=${1%%.*}
                parm=${1%.*}
                parm=${parm#*.}
                x=${1##*.}
                eval try=\$$x
                if [[ -z $try ]]
                then
                        missing="$missing$flag $parm "
                        errors=$(( $errors + 1 ))
                fi

                shift
        done

        if [[ $errors -gt 0 ]]
        then
                error_msg "required command line information missing: $missing"
                usage
                return 1
        fi

        return 0
}

# -------------------------------------------------------------------------------
# Mnemonic:	ng_spaceman_nm
# Abstract:	Replaces the stand alone process as we now dump into a common
#		directory and let spaceman daemon distribute to final resting 
#		place when registered.
# Parms:	While some are unused, we expect what could have been given to 
#		the old version for back compat sake.
#		old format: [options] node file size
#		new format: filename
# Date:		26 March 2002
# Author: 	E. Scott Daniels
# -------------------------------------------------------------------------------
function ng_spaceman_nm
{
	while [[ $1 = -* ]]		# ignore options
	do
              case $1 in
                -r)                     # new function invoke the real spaceman
                        $NG_ROOT/bin/ng_spaceman_nm -r "$@"
                        return
                        ;;
                *)
                        ;;
                esac

		shift
	done

	if [[ $# -gt 1 ]]		# assume old parm format - name is $2
	then
		echo ${NG_PROPYLAEUM:-$NG_ROOT/den/propyleaum}/${2##*/}
	else
		echo ${NG_PROPYLAEUM:-$NG_ROOT/den/propyleaum}/${1##*/}
	fi
}

# ------ end functions -----------------------------------------------------

# ---- this code is EXECUTED at "load" time; no funcitons
#

# new for Ning: assumption is that Linux and SGI got it right and 
# implement awk as the latest and greatest. Sun on the otherhand
# needs nawk.
if  whence nawk >/dev/null 2>&1
then
	alias awk=nawk		# blasted sun could not do it right
else
	alias nawk=awk	  # just in case I missed one during the port
fi

argv0=$0             # prevent problems when Ksh is upgraded

alias rm=""		# this is silly, but unalias returns 1 if they are not 
alias cp=""		# aliased and causes -e trap to be taken.
alias mv=""
unalias rm 2>>/dev/null	
unalias cp 2>>/dev/null
unalias mv 2>>/dev/null

umask 002
ustring="Idiot programmer omitted usage string, sorry Charlie!"

if [[ -z "$_NOTRAP" ]]
 then
  trap "cleanup 254" 1 2 3 15      # ensure locks are gone etc on signals
 fi

_debugf=${argv0##*/}
_debugf=$NG_ROOT/site/${_debugf%%.*}.debug

# ---------------------------------------------------------------------
#  Check to see if we should be very noisy.  Do NOT redirect stdout
#  or some scripts will not function properly.
# ---------------------------------------------------------------------
if [[ -e /ningaui/adm/debug && -z "$_NODEBUG" ]]
 then
  _debug=true                        # force verbose messages
  _l="$TMP/`basename $argv0`.$$.!!"      # write stderr to tmp directory
  stdio - $_l                        # write stderr to tmp directory
  LOG_MSG_FILE=$_l                   # cause verbose messages to go here
  read _x </ningaui/adm/debug          # see if intense mode on
  verbose "$@"  
  if [[ "$_x" -gt 0 ]]
   then
    set -x
   fi
  unset _x _l
 else
	LOG_MSG_FILE="/dev/fd/2"	# default to standard error
 fi

# DEPRECATED in Ningaui
# ---------------------------------------------------------------------
# must do this here as the config file can contian ONLY variable 
# assignments because ng_env cannot handle the code
# ---------------------------------------------------------------------
#unset PNUM_PAT
#qq=1
#while [[ qq -le ${PNUM_FSIZE:-3} ]]  # default to 3 just in case
#do
#        PNUM_PAT=$PNUM_PAT\?
#        qq=$((qq + 1))
#done
#export PNUM_PAT

