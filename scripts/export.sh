#!/bin/sh
# this script should be run from the top level pads directory
# it will leave a tar ball at that level, and a directory pads_remove_me
# that is the source of the tar ball.
#
# Notes: When putting out a new release, 
#  . Increment the compiler version number in main.sml
#  . Increment the manual version in version.tex
#  . Be sure to update the take_lists in examples/{p,tests,data}
#  . Make sure compiler is set to generate release version of compiler
#  . Add tarball to pads-private/dist directory.
#  . update bin/package.cvs if updated version of ast
#
# When you take a new set of tgz files from gsf you should take the
# latest version of the bin/package script (which gets installed when it
# unbundles and builds ast) and copy it to 'bin/package.cvs'

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
# pads-1-04-d      pads 1.04d   2007-15-03  upgraded to 2007-01-11 ast library
# pads-1-04-e      pads 1.04e   2007-15-03  fixed bug in manual
# pads-2-00-a      pads 2.00a   2007-06-06  changed license, fixed bug in plongest
# pads-2-00-b      pads 2.00b   2007-06-06  various files I forgot to check in previously
# pads-2-01-a      pads 2.01a   2007-12-18  upgrade to ast.2007-11-05, fixes to fmt program
# pads-2-01-b      pads 2.01b   2007-12-18  package.cvs, binary data file added for runtime regression, missed .p file

cvs -d :ext:cvs-graphviz.research.att.com:/cvsroot export -r $1 pads
bundlename=`echo $1 | awk -F "-" '{print $1"."$2"."$3}'`
echo $bundlename

# build documentation
cd pads/documents/manual
make 

# install documentation
mkdir ../../temp_docs
for x in `cat take_list`; do cp $x ../../temp_docs; done
mkdir ../../temp_docs/pictures
cd pictures
for x in `cat take_list`; do cp $x ../../../temp_docs/pictures; done
cd ../../..  # now at pads
rm -rf documents
mv temp_docs documents


# remove internal directories/files
rm Changes
rm -rf GIGASCOPE_README
rm -rf Notes

#remove .cvs files
#rules.mk generates entries for some of these, so we're going to leave 
#the residual files in to avoid duplicating rules.mk
#for x in `find . -name .cvsignore`; do rm $x ; done

# clean example directory
cd padsc/examples
pwd
#clean examples/p directory
echo cleaning examples/p directory
mkdir temp_p
for x in `cat p/RELEASE_PFILES`; do cp p/$x temp_p; done
rm -rf p
mv temp_p p

#clean examples/test directory
echo cleaning examples/test directory
mkdir temp_tests
for x in `cat tests/RELEASE_TESTS`; do cp tests/$x temp_tests; done
rm -rf tests
mv temp_tests tests

#clean examples/data directory
echo cleaning examples/data directory
mkdir temp_data
for x in `cat data/take_list`; do cp data/$x temp_data; done
rm -rf data 
mv temp_data data

cd ..  # now in pads/padsc
echo cleaning example directory
pwd
mkdir temp_examples
for x in `cat examples/take_list`; do mv examples/$x temp_examples; done
rm -rf examples
mv temp_examples examples

echo cleaning usecases directory
pwd
mkdir temp_usecases
for x in `cat usecases/take_list`; do mv usecases/$x temp_usecases; done
rm -rf usecases
mv temp_usecases usecases


cd .. # now in pads directory

echo cleaning padsc directory
mkdir temp_padsc
for x in `cat padsc/take_list`; do mv padsc/$x temp_padsc; done
rm -rf padsc
mv temp_padsc padsc

echo Adding licenses
# should be in pads directory
# must do this before cleaning scripts directory
scripts/release/make.notices.sh

echo cleaning scripts directory
mkdir temp_scripts
for x in `cat scripts/RELEASE_SCRIPTS`; do mv scripts/$x temp_scripts; done
rm -rf scripts
mv temp_scripts scripts


echo taring up the desired files
cd ..  # now above checked out pads directory
echo building bundle
tar cfz $bundlename.tar.gz `cat pads/take_list`

# uncomment these lines if exporting gigascope as well
#rm -rf pads/scripts
#mkdir pads/scripts
#cp scripts/gigascope_make.pl pads/scripts
#cp -r scripts/templates pads/scripts/
#rm -rf pads/scripts/templates/CVS
#cp GIGASCOPE_README pads/

#tar cfz $bundlename_gscp.tar.gz pads/scripts pads/GIGASCOPE_README

mv pads pads_remove_me
