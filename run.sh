#!/bin/bash

# This script runs the Spiro program with the correct files.


if [ "$#" -lt 2 ]; then
    echo "usage: run.sh <input-file> <output-file>"
    exit
fi

IN=$1
OUT=$2

./bin/Spiro < $IN > tmp.txt
./jgraph/jgraph -P tmp.txt | ps2pdf - | convert -density 300 - -quality 100 $OUT
rm tmp.txt