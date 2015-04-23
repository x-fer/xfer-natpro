#!/bin/bash

set -e

rm -rf tp/*
g++ -Wall -ogen kobila-gen.cpp
g++ -Wall -okobila kobila.cpp

while read line; do
  infile=test/$(echo $line | cut -f1 -d' ')
  oufile=${infile/in/out}
  echo "generating $line ..."
  rows=$(echo $line | cut -f2 -d' ')
  cols=$(echo $line | cut -f3 -d' ')
  (while true; do
    ./gen $rows $cols 1> $infile 2> tmp
    ./kobila < $infile > $oufile
    [ $(cat $oufile | wc -l) -eq 1 ] && exit;
  done)
  diff -wq tmp $oufile
  rm tmp;
done < tp-schema.txt

rm gen kobila
