#!/usr/bin/env python

import sys
import os
from random import randint


test_no = 10
task_name = "najnaj"

def gen_element():
  return chr(ord('0') + randint(0, 1));

def fill_square(mat, top_r, left_c, k):
  for i in xrange(top_r, top_r + k):
    for j in xrange(left_c, left_c + k):
      mat[i][j] = '0'

def create_matrix(n, min_sol):
  min_sol = min(n, min_sol)
  mat = [[gen_element() for _ in range(n)] for _ in range(n)]
  fill_square(
      mat,
      randint(0, n - min_sol - 1),
      randint(0, n - min_sol - 1),
      min_sol)
  for _ in xrange(1, 5):
    k = randint(3, min(n, int(min_sol * 1.2)))
    top_r = randint(0, n - k - 1)
    top_c = randint(0, n - k - 1)
    fill_square(mat, top_r, top_c, k)
    mat[top_r + randint(0, k - 1)][top_c + randint(0, k - 1)] = '1'
  return mat

for i in xrange(1, test_no+1):
  print "Stvaram primjer", i
  test_file = open(task_name+".in."+str(i), "w")
  if i <= 3:
    N = randint(3, 15)
  elif i <= 6:
    N = randint(15, 100)
  else:
    N = randint(900, 1000)
  test_file.write("%d\n" % (N))
  mat = create_matrix(N, randint(int(0.5 * N), int(0.9 * N)))
  test_file.write("\n".join(["".join(row) for row in mat]))
  test_file.write("\n")
  test_file.close()
