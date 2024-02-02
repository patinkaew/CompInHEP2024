#!/bin/bash

njobs=${1:-10}
OUTDIR="bash_output"

for i in $(seq $njobs); do
    ./hello $i > "$OUTDIR/bash_job_$i.txt"
done