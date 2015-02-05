#!/bin/sh
# this script should be run from the top level pads directory
# it will leave a tar ball at that level, and a directory pads_remove_me
# that is the source of the tar ball.
#
# Notes: When putting out a new release, 
#  . Add tarball to pads-private/dist directory.

# pads2005-03-07   pads 1.0     2005-03-07  
# pads-1-01-a      pads 1.01    2006-01-26
# pads-1-01-b      pads 1.01b   2006-05-17  new license
# pads-1-02-a      pads 1.02    2006-08-01  64 bit support, bug fixes
# pads-1-03-a      pads 1.03    2006-09-07  transform, pinclude, writetoio fix
# pads-1-03-b      pads 1.03b   2006-09-08  fixed takelists, version numbers
# pads-1-03-c      pads 1.03c   2006-09-08  fixed takelists, fixed makefile
# pads-1-04-a      pads 1.04    2006-07-11  try, enums can specify base type, mask generation functions
# pads-1-04-b      pads 1.04b   2006-07-11  enum test files added, manual script fixed?
# pads-1-04-c      pads 1.04c   2006-08-11  added jpg and gif to manual takelist
# pads-1-04-rt     pads 1.04rt  2007-01-23  added support for exporting the runtime only. used by pads/ml.
cvs -d :ext:cvs-graphviz.research.att.com:/cvsroot export -r $1 -d padsc_runtime pads
bundlename=`echo $1 | awk -F "-" '{print $1"."$2"."$3}'`
echo $bundlename

# move into checked out copy
if [ ! -e padsc_runtime ] ; then 
    echo cvs failed to create temporary padsc_runtime directory;
    exit 1
fi
cd padsc_runtime

echo cleaning padsc directory
mkdir temp_padsc
for x in `cat padsc/runtime_take_list`; do mv padsc/$x temp_padsc; done
rm -rf padsc
mv temp_padsc padsc

echo Adding licenses
# should be in padsc_runtime directory
# must do this before cleaning scripts directory
scripts/release/make.notices.sh

echo cleaning scripts directory
mkdir temp_scripts
for x in `cat scripts/RELEASE_SCRIPTS`; do mv scripts/$x temp_scripts; done
rm -rf scripts
mv temp_scripts scripts

echo Setting up makefiles
rm -f GNUmakefile
mv runtime.mk GNUmakefile

echo taring up the desired files
cd ..  # now above checked out padsc_runtime directory
echo building bundle
tar cfz "$bundlename".runtime.tar.gz `cat padsc_runtime/runtime_take_list`

mv padsc_runtime padsc_runtime_remove_me
