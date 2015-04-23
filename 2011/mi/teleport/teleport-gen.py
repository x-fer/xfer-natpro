#!/usr/bin/env python3
# Copyright 2011 Bruno Rahle

import argparse
import numpy as np
import operator
import random

class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.parent = np.arange(n)
        self.count = np.ones(n, int)

    def find(self, a):
        if self.parent[a] == a:
            return a
        self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def join(self, a, b):
        parent_a = self.find(a)
        parent_b = self.find(b)
        if parent_a == parent_b:
            return False
        if self.count[parent_a] > self.count[parent_b]:
            self.count[parent_a] += self.count[parent_b]
            self.parent[parent_b] = parent_a
        else:
            self.count[parent_b] += self.count[parent_a]
            self.parent[parent_a] = parent_b
        return True


class coor(tuple):
    def __add__(self, other):
        return self.__class__(map(operator.add, self, other))
    def __mul__(self, other):
        return self.__class__(map(other.__mul__, self))

def neparno(x):
    return x - (x%2==0)

def generiraj_labirint(realR, realS):
    R = neparno(realR)
    S = neparno(realS)

    blokirano = np.ones((realR, realS), np.int)
    posjetio = np.zeros((realR, realS), np.int)

    pomak = [coor([0,-1]), coor([0,1]), coor([-1,0]), coor([1,0])]
    stack = []

    def valid(X):
        return X[0] < R and X[0] >= 0 and X[1] < S and X[1] >= 0

    blokirano[0][0] = 0
    stack.append([coor([0,0]), [], 0])

    while len(stack) > 0:
        X = stack[-1][0]
        if not posjetio[X]:
            posjetio[X] = 1
            red = [0, 1, 2, 3]
            random.shuffle(red)
            stack[-1][1] = red
            zadnji = 0
        else:
            red = stack[-1][1]
            zadnji = stack[-1][2] + 1

        if zadnji == 4:
            stack.pop()
            continue

        for i in range(zadnji, 4):
            iduci = pomak[red[i]]*2 + X
            stack[-1][2] = i
            if valid(iduci) and not posjetio[iduci]:
                blokirano[iduci] = 0
                blokirano[pomak[red[i]]+X] = 0
                stack.append([iduci, [], 0])
                break

    pomak = 0
    if R < realR:
        pomak = 1
        for i in range(realS):
            sad = coor([realR-1, i])
            if i == 0:
                blokiraj = random.randint(0, 1)
            else:
                a = blokirano[coor([realR-1, i-1])]
                b = blokirano[coor([realR-2, i-1])]
                c = blokirano[coor([realR-2, i])]
                if (a and not c) or (b and not c) or (c and not a):
                    blokiraj = random.randint(0, 1)
                else:
                    blokiraj = 1
            blokirano[sad] = blokiraj
    if S < realS:
        for i in range(realR-1-pomak, -1, -1):
            sad = coor([i, realS-1])
            if i == realR-1:
                blokiraj = random.randint(0,1)
            else:
                a = blokirano[coor([i+1, realS-1])]
                b = blokirano[coor([i+1, realS-2])]
                c = blokirano[coor([i, realS-2])]
                if (a and not c) or (b and not c) or (c and not a):
                    blokiraj = random.randint(0, 1)
                else:
                    blokiraj = 1
            blokirano[sad] = blokiraj
    return blokirano

def prebroji(X, labirint, posjetio=None, posjeceni=None):
    R = len(labirint)
    S = len(labirint[0])
    def valid(X):
        return X[0] < R and X[0] >= 0 and X[1] < S and X[1] >= 0

    if not valid(X) or labirint[X]:
        return 0
    if posjetio is None:
        posjetio = np.zeros((R, S), int)
    pomak = [coor([0,-1]), coor([0,1]), coor([-1,0]), coor([1,0])]
    stack = []
    stack.append([X, 0])
    dio = []
    cnt = 0

    while len(stack) > 0:
        X = stack[-1][0]
        if not posjetio[X]:
            posjetio[X] = 1
            zadnji = 0
            cnt += 1
        else:
            zadnji = stack[-1][1] + 1
        if zadnji == 4:
            stack.pop()
            continue
        for i in range(zadnji, 4):
            iduci = pomak[i] + X
            stack[-1][1] = i
            if valid(iduci) and not posjetio[iduci] and not labirint[iduci]:
                stack.append([iduci, 0])
                dio.append(X)
                break
    if posjeceni is not None:
        for d in dio:
            if d not in posjeceni:
                posjeceni.append(d)

    return cnt

def probaj_oznaciti_mjesto(X, labirint):
    if labirint[X] == 1:
        return 0
    labirint[X] = 1
    pomak = [coor([0,-1]), coor([0,1]), coor([-1,0]), coor([1,0])]
    sume = [0, 0, 0, 0]
    for i in range(4):
        sume[i] = prebroji(X+pomak[i], labirint)
    if sum(1 for x in sume if x > 4) and all(map(lambda x: x>=4 or x==0, sume)):
        return sum(1 for x in sume if x) - 1
    labirint[X] = 0
    return 0

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('R', type=int, help='broj redaka')
    parser.add_argument('S', type=int, help='broj stupaca')
    parser.add_argument('N', type=int, help='broj teladi')
    parser.add_argument('K', type=int, help='broj komponenti',
                        default=1)
    parser.add_argument('T', type=int, help='broj teleportova',
                        default=0)
    args = parser.parse_args()
    R = args.R
    S = args.S
    N = args.N
    K = args.K
    T = args.T

    ###########################################################################
    # korak 1
    ###########################################################################
    # generiraj labirint velicine R*S
    labirint = generiraj_labirint(R, S)

    ###########################################################################
    # korak 2
    ###########################################################################
    # napravi (bar) K komponenti
    while K > 1:
        x = random.randint(0, R-1)
        y = random.randint(0, S-1)
        K -= probaj_oznaciti_mjesto(coor([x, y]), labirint)

    ###########################################################################
    # korak 3
    ###########################################################################
    # pronadji komponente
    posjetio = np.zeros((R,S), int)
    komponente = []
    for i in range(R):
        for j in range(S):
            X = coor([i, j])
            if posjetio[X] or labirint[X]:
                continue
            posjeceni = []
            broj = prebroji(X, labirint, posjetio, posjeceni)
            komponente.append([X, len(posjeceni), posjeceni])

    ###########################################################################
    # korak 4
    ###########################################################################
    # povezi komponente u graf
    parovi = []
    for i in range(len(komponente)):
        for j in range(i, len(komponente)):
            parovi.append((i, j))
    random.shuffle(parovi)
    d = DisjointSet(len(komponente))
    spojeni = []
    for p in parovi:
        a = p[0]
        b = p[1]
        if komponente[a][1] == 0 or komponente[b][1] == 0:
            continue
        if d.join(a, b):
            spojeni.append(p)
            komponente[a][1] -= 1
            komponente[b][1] -= 1

    T -= len(spojeni)
    while T > 0:
        p = random.choice(parovi)
        a = p[0]
        b = p[1]
        if (komponente[a][1] == 0 or komponente[b][1] == 0 or
            (komponente[a][1] == 1 and a == b)):
            continue
        spojeni.append(p)
        komponente[a][1] -= 1
        komponente[b][1] -= 1
        T -= 1

#    print([k[1] for k in komponente])
    ###########################################################################
    # korak 5
    ###########################################################################
    # postavi teleporte
    for i in range(len(spojeni)):
        a = spojeni[i][0]
        b = spojeni[i][1]
        slovo = ord('A') + i
        pozicija_a = random.randint(0, len(komponente[a][2])-1)
        pozicija_b = random.randint(0, len(komponente[b][2])-1)
        while pozicija_a <= pozicija_b and a == b:
            pozicija_a = random.randint(0, len(komponente[a][2])-1)
            pozicija_b = random.randint(0, len(komponente[b][2])-1)
        kraj_a = komponente[a][2][pozicija_a]
        kraj_b = komponente[b][2][pozicija_b]
        labirint[kraj_a] = slovo
        labirint[kraj_b] = slovo
#        print(komponente[a][2], komponente[b][2])
        del komponente[a][2][pozicija_a]
        del komponente[b][2][pozicija_b]
#        print(komponente[a][2], komponente[b][2])

    ###########################################################################
    # korak 6
    ###########################################################################
    # postavi telad i stalu
    kandidati = []
    for i in range(R):
        for j in range(S):
            X = coor([i, j])
            if labirint[X] == 0:
                kandidati.append(X)
    random.shuffle(kandidati)
    labirint[kandidati[0]] = ord('s')
    for i in range(1, N+1):
        labirint[kandidati[i]] = ord('t')

    ###########################################################################
    # korak 7
    ###########################################################################
    # ispisi labirint
    print(R, S)
    for red in labirint:
        for znak in red:
            if znak == 1:
                print('#', end='')
            elif znak == 0:
                print('.', end='')
            elif znak >= 65:
                print(chr(znak), end='')
            else:
                print(znak, end='')
        print()

if __name__ == '__main__':
    main()

