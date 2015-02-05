#! /bin/bash

# run as <prog_name> <dataDir> <timingDir> <data> <results>
prog=$1
dataDir=$2
timingDir=$3
data=$4
results=$5

TIMEFORMAT='%3R %3U %3S'

function getFifth { echo $5; }

size=$(getFifth $(ls -l $dataDir/$data))

if [ -z $PROCESS_ONLY ]; then
    rm -f $timingDir/$results
    (time $prog $dataDir/$data 2>&1) 2> /dev/null # drop the first run
    (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results 
    (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results 
    (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results
fi
#     (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results
#     (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results
#     (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results
#     (time $prog $dataDir/$data  2>&1) 2>> $timingDir/$results
echo -n "$results: Average (us/byte): " $'\t'
cat $timingDir/$results | awk -v size=$size '{ real += $1; user += $2; sys += $3; ct += 1; } END { print real/ct * (1000000/size), user/ct * (1000000/size), sys/ct * (1000000/size); }'
