#! /bin/bash

function generate {
    for ((i=1; i<=$4; ++i))
    do
        ./$1 < $2$i > $3$i
    done   
}

function gen_input {
    for ((i=1; i<=$3; ++i))
    do
        ./$1 $i > $2$i
    done
}

INPUT="test/boom.in."
OUTPUT="test/boom.out."

DUMMY_IN="test/boom.dummy.in."
DUMMY_OUT="test/boom.dummy.out."

_RUN="_RUNABLE"
_GEN="_GENERATOR"

g++ boom.cc -o $_RUN &> /dev/null

if [ $? -ne 0 ]
then
    echo "Compile error"
    exit 1
fi

g++ boom-gen.cc  -o $_GEN &> /dev/null

# generate input
echo "Generating input files"
gen_input $_GEN $INPUT 10

# generate output
echo "Generating dummy"
generate $_RUN $DUMMY_IN $DUMMY_OUT 3
echo "Generating test"
generate $_RUN $INPUT $OUTPUT 10

rm $_RUN
rm $_GEN

exit 0
