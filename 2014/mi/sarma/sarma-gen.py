import sys
import random

N = int(sys.argv[1])
M = int(sys.argv[2])

print N
print M

for _ in xrange(N):
    sys.stdout.write(str(random.randrange(10000000)) + " ")

print ""
