python sarma-gen.py 100 31 > sarma.in.1
python sarma-gen.py 200 75 > sarma.in.2
python sarma-gen.py 300 31 > sarma.in.3
python sarma-gen.py 1000 311 > sarma.in.4
python sarma-gen.py 100000 98765 > sarma.in.5
python sarma-gen.py 100000 86511 > sarma.in.6
python sarma-gen.py 100000 50000 > sarma.in.7
python sarma-gen.py 100000 41411 > sarma.in.8
python sarma-gen.py 100000 451815 > sarma.in.9
python sarma-gen.py 100000 500 > sarma.in.10
for i in {1..10};
do
  ./sarma < sarma.in.$i > sarma.out.$i;
done
