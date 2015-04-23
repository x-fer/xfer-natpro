#!/bin/bash

#                   R   S     T   K   P                1 tele      0 portala       <= 50 teleta
./teleport_gen.py   7   7     1   1   0 > teleport.in.1   # 1           1               1
time ./teleport.exe < teleport.in.1 > teleport.out.1
./teleport_gen.py  17  27     1  12  12 > teleport.in.2   # 2           1               2
time ./teleport.exe < teleport.in.2 > teleport.out.2
./teleport_gen.py 138  92     1  20  26 > teleport.in.3   # 3           1               3
time ./teleport.exe < teleport.in.3 > teleport.out.3
./teleport_gen.py  23  65     8   1   0 > teleport.in.4   # 3           2               4
time ./teleport.exe < teleport.in.4 > teleport.out.4
./teleport_gen.py 172 200 15000   1   0 > teleport.in.5   # 3           3               4
time ./teleport.exe < teleport.in.5 > teleport.out.5
./teleport_gen.py  78  99    40   5   8 > teleport.in.6   # 3           3               5
time ./teleport.exe < teleport.in.6 > teleport.out.6
./teleport_gen.py  17  27    50  12  20 > teleport.in.7   # 3           3               6
time ./teleport.exe < teleport.in.7 > teleport.out.7
./teleport_gen.py 190 191    50   8  26 > teleport.in.8   # 3           3               7
time ./teleport.exe < teleport.in.8 > teleport.out.8
./teleport_gen.py 156  88   503  13  25 > teleport.in.9   # 3           3               4
time ./teleport.exe < teleport.in.9 > teleport.out.9
./teleport_gen.py 200 200 20000  11  26 > teleport.in.10  # 3           3               4
time ./teleport.exe < teleport.in.10 > teleport.out.10


