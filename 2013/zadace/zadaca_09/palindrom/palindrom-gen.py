import sys
import random

def main():
    rijec = sys.argv[1]
    N = int(sys.argv[2])

    palindrom = (rijec + rijec[::-1]) * N

    # max length = 100000
    MAX = 100000
    ostalo = random.randint(2, MAX  - len(palindrom))

    left = random.randint(1, ostalo)
    rajt = ostalo - left

    for x in xrange(left):
        palindrom = chr(random.randint(0, 25) + ord('a')) + palindrom

    for x in xrange(rajt):
        palindrom = palindrom + chr(random.randint(0, 25) + ord('a'))

    print len(palindrom)
    print palindrom
    return

if __name__=="__main__":
    main()
