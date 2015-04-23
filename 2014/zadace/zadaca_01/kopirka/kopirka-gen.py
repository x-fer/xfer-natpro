#!/usr/bin/env python

import sys
import os
import random


test_no = 10
task_name = "kopirka"

rng1 = 500

mini = 1
maxi = 10000000-1

for i in xrange(1, test_no+1):
	
	test_file = open(task_name+".in."+str(i), "w")

	lo, hi = float(i-1)/test_no, float(i)/test_no
	
	M = int(random.uniform(1+lo*rng1,hi*rng1))
	K = int(random.uniform(1, M))
	
	test_file.write(str(M)+" "+str(K)+"\n")

	for i in range(M):
		down = int(1+lo*(mini+maxi)/2)
		up = int(hi*maxi)
		b = int(random.uniform(down, up))
		test_file.write(str(b) + " ")

	test_file.write("\n")
	test_file.close()