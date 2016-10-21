import sys
import random
from math import *

EPS = 1e-6
lines = [i.strip() for i in sys.stdin.readlines()]

T = int(lines[0])
F = lines[1]
cases = []
for i in lines[2:]:
    cases.append([float(j) for j in i.split()])

polin, R = F.replace('^', '**').split('=')
polin_znani = "+".join([i if i[0]!="A" else "0" for i in polin.split("+")])
nepoznati = polin.split("A")[1].strip("*").split("+")[0]
if nepoznati == "":
    nepoznati = "1.0"
#print("{} ... {}".format(polin_znani, nepoznati))

for i in cases:
    x = i[0]
    y = eval(polin_znani)
    N = eval(nepoznati)
    R = i[1] - y
    if R == 0 and N == 0:
        print(random.random())
    elif N != 0:
        A = R / N
        print(A)
    else:
        print("Nema")
    
