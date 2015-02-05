#!/bin/bash
#run as: <script_name> data_format <bulk | linear | smart> input_extension

format=$1
kind=$2
size=$3
# timing_dir=../timing
if [[ $format = dibbler_new && $kind = bulk ]]; then
    case $size in
	10MB) alloc_hint=50000;;
	20MB) alloc_hint=100000;;
	50MB) alloc_hint=250000;;
	100MB) alloc_hint=500000;;
    esac
fi
make PGLX_FORMAT=$format PGLX_KIND=$kind PGLX_SIZE=$size PGLX_ALLOC_HINT=$alloc_hint do_time_pglx
#cat $timing_dir/"$format"_"$size"_"$kind".time
