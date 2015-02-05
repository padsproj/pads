#!/bin/tcsh


cd $1
foreach x (`find . -name Root`)
cp ../NEW_ROOT $x
end
cd ..