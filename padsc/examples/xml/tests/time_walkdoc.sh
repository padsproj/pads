#!/bin/bash
#run as: <script_name> data_format <bulk | linear | smart> input_extension
#measure the time to walk entire document using the pads_dm implementation of the Galax data model.

format=$1
kind=$2
size=$3
timing_scr=$PADS_HOME/scripts/timing.sh
data_dir=../../data
timing_dir=../../timing

# change this value to the appropriate architecture.
ast_arch=darwin.ppc
echo "$ast_arch chosen as native architecture."

# timing_dir=../timing
alloc_hint=0
if [[ $format = dibbler_new && $kind = bulk ]]; then
    case $size in
	10MB) alloc_hint=50000;;
	20MB) alloc_hint=100000;;
	50MB) alloc_hint=250000;;
	100MB) alloc_hint=500000;;
    esac
fi
make PGLX_FORMAT=$format PGLX_KIND=$kind PGLX_ALLOC_HINT=$alloc_hint \
     walk_$format

$timing_scr $ast_arch/walk_$format  $data_dir $timing_dir $format.$size \
	glxwalk_"$format"_"$size"_"$kind".time

#cat $timing_dir/"$format"_"$size"_"$kind".time
