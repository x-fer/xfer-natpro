#!/usr/bin/env python

import sys
import os
import random


test_no = 10
task_name = "aleja"

cor = 100000

for i in xrange(1, test_no+1):
	
	test_file = open(task_name+".in."+str(i), "w")

	lo, hi = float(i-1)/test_no, float(i)/test_no
	
	Mx = int(random.uniform(-cor, cor))
	My = int(random.uniform(-cor, cor))
	
	Px = int(random.uniform(-cor, cor))
	Py = int(random.uniform(-cor, cor))

	Kx = int(random.uniform(-cor, cor))
	Ky = int(random.uniform(-cor, cor))

	test_file.write("{} {}\n".format(Mx, My))
	test_file.write("{} {} {} {}".format(Px, Py, Kx, Ky))

	test_file.write("\n")
	test_file.close()