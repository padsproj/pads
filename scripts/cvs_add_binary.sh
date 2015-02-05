#!/bin/csh
# cvs add binary : script for adding a binary file to cvs repository

cvs add -ko -m "Initial version." $1
cvs commit -m "Initial version." $1
cvs admin -ko $1
rm -f $1
cvs update $1
