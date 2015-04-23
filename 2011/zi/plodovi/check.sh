#! /bin/bash

g++ brute.cc -o run1
g++ plodovi.cc -o run2

for i in {1..3}
do
	INPUT="test/plodovi.dummy.in."$i
	OUTPUT1="out.out1"
	OUTPUT2="out.out2"
	
	echo -n "Running dummy "$i"..."
	
	./run1 < $INPUT > $OUTPUT1
	./run2 < $INPUT > $OUTPUT2
	
	hash1=$( md5sum $OUTPUT1 | cut -f1 -d' ')
	hash2=$( md5sum $OUTPUT2 | cut -f1 -d' ')
	
	if [ $hash1 == $hash2 ]
	then
		echo "OK"
	else
		echo "WA"
	fi
	
done


for i in {1..10}
do
	INPUT="test/plodovi.in."$i
	OUTPUT1="out.out1"
	OUTPUT2="out.out2"
	
	echo -n "Running "$i"..."
	
	./run1 < $INPUT > $OUTPUT1
	./run2 < $INPUT > $OUTPUT2
	
	hash1=$( md5sum $OUTPUT1 | cut -f1 -d' ')
	hash2=$( md5sum $OUTPUT2 | cut -f1 -d' ')
	
	if [ $hash1 == $hash2 ]
	then
		echo "OK"
	else
		echo "WA"
	fi
	
done

exit 0
