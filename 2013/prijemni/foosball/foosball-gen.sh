#! /bin/bash

COUNT=10
TP_SIZES="10 100 1000 1000 5000 5000 10000 50000 90000 100000"

echo -n "Compiling generator... "
g++ foosball-gen.cpp -o generator
if [ $? -ne 0 ]; then
    echo "Failed"
    exit 1
fi
echo "Done"
echo -n "Compiling solution... "
g++ foosball.cpp -o foos
if [ $? -ne 0 ]; then
    echo "Failed"
    exit 1
fi
echo "Done"

I=1
for N in $TP_SIZES; do
    echo "Test "$((I))
    echo -n "Creating... "
    ./generator $N > testovi/foos.in.${I}
    echo "Done"
    echo -n "Solving... "
    ./foos < testovi/foos.in.${I} > testovi/foos.out.${I}
    echo "Done"
    I=$((I + 1))

    sleep 1
done

echo -n "Cleaning up... "
rm generator
rm foos
echo "Done"

exit 0
