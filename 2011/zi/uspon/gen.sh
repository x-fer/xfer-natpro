#! /bin/bash

g++ gen.cc -o gen
g++ uspon.cc -o sol

for i in {1..10}
do
	INPUT="test/uspon.in."$i
	OUTPUT="test/uspon.out."$i
	
	echo -n "Running "$i"..."
	
	./gen $INPUT $i"00" $i"00" $i"00"  
	time ./sol < $INPUT > $OUTPUT
done

exit 0
