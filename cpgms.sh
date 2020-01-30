#!/bin/bash
  set -x

  time=$(pwd | awk -F '\/' '{print $6}')
  crashapp=com.google.android.gms
  dest=../../$crashapp-$time
  mkdir $dest

  find . -name $crashapp -type d | while read line
  do
    echo $line
    cp $line $dest --parents -a
  done
