from random import randint, choice

def gen_chr():
    return chr(ord('a') + randint(0, 25))

def gen_str(l):
    return ''.join([gen_chr() for i in range(l)])

def transform_change(s):
    z = list(s)
    z[randint(0, len(z) - 1)] = gen_chr()
    return ''.join(z)

def transform_erase(s):
    if len(s) == 1:
        return s
    z = list(s)
    del z[randint(0, len(z) - 1)]
    return ''.join(z)

def transform_insert(s):
    if len(s) == 10:
        return s
    z = list(s)
    z.insert(randint(0, len(z)), gen_chr())
    return ''.join(z)

T = [transform_change, transform_erase, transform_insert]

# generira sljedeci od trenutnog
def gen_path(n):
    S = set()
    s = gen_str(5)
    S.add(s)

    while len(S) < n:
        t = choice(T)
        s = t(s)
        S.add(s)

    return S

# drzi skup trenutnih
def gen_incremental(n):
    S = set()
    s = gen_str(5)
    S.add(s)

    while len(S) < n:
        t = choice(T)
        s = choice(list(S))
        s = t(s)
        S.add(s)

    return S

plan = [
    (5, 5 * 3, gen_path),
    (10, 10 * 5, gen_path),
    (30, 30 * 20, gen_path),
    (60, 60 * 40, gen_incremental),
    (100, 100 * 90, gen_path),
    (100, 100 * 90, gen_incremental),
    (150, 150 * 140, gen_incremental),
    (200, 200 * 190, gen_incremental),
    (250, 250 * 140, gen_incremental),
    (300, 300 * 290, gen_incremental)
]

fname = 'rijeci'

for i in range(len(plan)):
    in_ext = '.in.' + str(i + 1)
    n, m, gf = plan[i]

    fin = open(fname + in_ext, 'w')
    
    print >>fin, n, m
    
    S = gf(n)
    for i in S:
        print >>fin, i

    for i in range(m):
        a = randint(1, n)
        b = randint(1, n)
        print >>fin, a, b

    
    
    
