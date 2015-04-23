#! /bin/bash

function generate {
    for ((i=1; i<=$4; ++i))
    do
        ./$1 < $2$i > $3$i
    done   
}

INPUT="test/rekonstrukcija.in."
OUTPUT="test/rekonstrukcija.out."

DUMMY_IN="test/rekonstrukcija.dummy.in."
DUMMY_OUT="test/rekonstrukcija.dummy.out."

_RUN="_RUNABLE"

g++ rekonstrukcija.cc -o $_RUN &> /dev/null

if [ $? -ne 0 ]
then
    echo "Compile error"
    exit 1
fi

echo "Generating dummy"
generate $_RUN $DUMMY_IN $DUMMY_OUT 2
echo "Generating test"
generate $_RUN $INPUT $OUTPUT 10

rm $_RUN

exit 0
