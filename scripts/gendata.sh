#! /bin/bash
# gendata.sh data_dir fmt_name target_size target_filename 

dataDir=$1
fmt=$2

# target file size for generated data
targetSize=$3

# file name for generated data. Must be one word.
targetFile=$4

function getFifth { echo $5; }
function genList { 
    local count=$1
    for ((i=0; i < count; i++)); do echo $2; done 
}
function getCount { 
    local size=$(getFifth $(ls -l $1))
    echo $(( targetSize/size ))
}

cd $dataDir
rm -f $targetFile
if [ $fmt = dibbler ]; then
    (read line; cat > dibbler.body) < dibbler.120
    head -n 1 dibbler.10001 > $targetFile 
    count=$(getCount dibbler.body)  
    if [ $count = 0 ]; then 
	echo "error target size $targetSize is smaller than file size."
	exit 1
    fi
    cat $(genList $count dibbler.body) >> $targetFile
    rm -f dibbler.body
elif [ -e $fmt ]; then
    count=$(getCount $fmt)  
    if [ $count = 0 ]; then 
	echo "error: target size $targetSize is smaller than size of file $fmt."
	exit 1
    fi
    cat $(genList $count $fmt) > $targetFile
else
    echo "error: unknown format $fmt"
fi
