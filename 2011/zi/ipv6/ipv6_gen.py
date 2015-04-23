import argparse
import random

def generate_one(hole=0, bits=128):
    if hole == 0:
        return random.getrandbits(bits)
    else:
        a = random.randint(0, bits-hole)
        if a == 0:
            part1 = 0
        else:
            part1 = random.getrandbits(a)
        if a == bits-hole:
            part2 = 0
        else:
            part2 = random.getrandbits(bits-hole-a)
        return part2 * 2**(hole+a) + part1

class IP(object):
    def __init__(self, hole=0, bits=128):
        self.ip = generate_one(hole, bits)
    
    def to_string(self, remove_leading=0, remove_zeroes=0):
        ret = hex(self.ip)[2:].rjust(32, '0')
        parts = []
        for i in range(0, len(ret), 4):
            if remove_leading:
                parts.append(hex(int(ret[i:i+4], 16))[2:])
            else:
                parts.append(ret[i:i+4])
        if remove_zeroes:
            parts2 = []
            started = 0
            done = 0
            for p in parts:
                if (p == '0' or p == '0000') and not done:
                    if started: continue
                    started = 1 
                    parts2.append('::')
                    continue
                if started and not done:
                    done = 1
                parts2.append(p)
            ret = '.'.join(parts2).replace('::.', '::').replace('.::', '::')
        else:
            ret = '.'.join(parts)
        if ret == '::':
            return '::0'
        ret.replace('.', ':')
        return ret
    
    def __str__(self):
        return self.to_string()
        
    def __lt__(self, other):
        return self.ip < other.ip

def main():
    random.seed()
    parser = argparse.ArgumentParser()
    parser.add_argument('N', type=int)
    parser.add_argument('-b', '--bits', type=int, choices=list(range(5, 129)), default=128)
    parser.add_argument('-r', '--hole', type=int, choices=[1, 0], default=1)
    parser.add_argument('-p', '--remove-empty-parts', type=int, choices=[1, 0], default=1)
    parser.add_argument('-l', '--remove-leading', type=int, choices=[1, 0], default=1)
    args = parser.parse_args()
    
    print(args.N)
    for i in range(args.N):
        hole_size = random.randint(0, args.hole*(args.bits-3))
        A = IP(hole_size, args.bits)
        hole_size = random.randint(0, args.hole*(args.bits-3))
        B = IP(hole_size, args.bits)
        if A < B:
            print(A.to_string(args.remove_leading, args.remove_empty_parts), 
                  B.to_string(args.remove_leading, args.remove_empty_parts))
        else:
            print(B.to_string(args.remove_leading, args.remove_empty_parts), 
                  A.to_string(args.remove_leading, args.remove_empty_parts))

if __name__ == '__main__':
    main()
