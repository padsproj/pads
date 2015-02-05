#!/bin/sh
# this script should be run from the top level pads directory
# it will leave a tar ball at that level, and a directory pads_remove_me
# that is the source of the tar ball.

# pads2005-03-07   pads 1.0     2005-03-07  
# pads-1-01-a      pads 1.01    2006-01-26
# pads-1-01-b      pads 1.01b   2006-05-17  new license

cvs -d :ext:cvs-graphviz.research.att.com:/cvsroot export -D today pads
bundlename=current
echo $bundlename

# build documentation
cd pads/documents/manual
make 

# install documentation
mkdir ../../temp_docs
for x in `cat take_list`; do cp $x ../../temp_docs; done
cd ../..  # now at pads
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
