#! /bin/bash

g++ gen.cc -o gen
g++ plodovi.cc -o sol

for i in {1..10}
do
	INPUT="test/plodovi.in."$i
	OUTPUT="test/plodovi.out."$i
	
	echo -n "Running "$i"..."
	
	if [ $i -lt 6 ] 
	then
	  j=$((2 * $i))
	else
	  j="100"
	fi
	
	#j="10"
	
	./gen 10 $j > $INPUT
	./sol < $INPUT > $OUTPUT
	sleep 1
	
done

exit 0
