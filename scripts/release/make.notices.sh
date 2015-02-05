#!/bin/sh


function insertCR {
for p in `cat $1`
do
  echo $p:
  for f in `find $p -type f`
  do
	echo Updating $f
	proto -l  scripts/release/pads.lic -hpr -c"$2" -o author=$3 $f
  done
done
}

echo inserting notices
pwd
insertCR scripts/release/sml.files  '(*)' kfisher+gruber+yitzhak
insertCR scripts/release/caml.files '(*)' mff
insertCR scripts/release/pads.files '/*/' gruber+kfisher+yitzhak
insertCR scripts/release/analysis.files '/*/' kfisher+xuan
insertCR scripts/release/padx.files '/*/' mff+gruber+yitzhak+kfisher
insertCR scripts/release/sh.files   '#'   kfisher+gruber

    












