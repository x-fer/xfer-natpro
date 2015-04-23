#/bin/bash
mkdir tc

cnt=0
for i in 100 1000 10000 10000 100000 100000 1000000 1000000 1000000 1000000;
do
  cnt=$((cnt+1));
  ./gen $i $RANDOM > tc/inv.$cnt.in;
  echo "Testcase #$cnt created!";
  ./inv < tc/inv.$cnt.in > tc/inv.$cnt.out;
  echo "Output for testcase #$cnt created!";
done;
