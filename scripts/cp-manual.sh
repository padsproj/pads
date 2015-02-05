#!/bin/sh

echo creating manual
cd $PADS_HOME/documents/manual
#make
echo moving generated web pages to www.padsproj.org
scp *.html *.pdf pictures/*.jpg www.padsproj.org:/weblab/services/pads/pads/documents/manual

