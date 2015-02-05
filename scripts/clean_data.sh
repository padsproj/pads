#!/bin/sh

mkdir temp_data
for x in `cat data/take_list`; do cp data/$x temp_data; done
rm -rf data data
mv temp_data data
