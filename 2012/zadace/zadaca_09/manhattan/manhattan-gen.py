#!/usr/bin/python3

import random
import sys

def main():
  n = int(sys.argv[1])
  r = int(sys.argv[2])
  min_c = -r
  max_c = r
  
  random.seed()
  points = set()
  while len(points) < n:
    point = (random.randint(min_c, max_c), random.randint(min_c, max_c), random.randint(min_c, max_c))
    if not point in points:
      points.add(point)
    
  print(n)
  for point in points:
    print(point[0], point[1], point[2])
  
if __name__ == '__main__':
  main()