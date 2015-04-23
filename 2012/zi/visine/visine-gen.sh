#!/bin/bash

for (( i=1; i<=10; ++i ))
do
    ./sol < "visine.in.$i" > "visine.out.$i"
    echo "test $i" 
    ./brute2 < "visine.in.$i" > tmp
    diff visine.out.$i tmp
done

rm tmp