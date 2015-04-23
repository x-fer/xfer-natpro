#!/usr/bin/env python

import sys
import os
import random


test_no = 10
task_name = "znamenka"

max_num = 18

for i in xrange(1, test_no+1):
	
	test_file = open(task_name+".in."+str(i), "w")

	lo, hi = float(i-1)/test_no, float(i)/test_no

	down = (10**int(max_num*lo))
	up = (10**int(max_num*hi))

	num = random.uniform((down+hi)/2, up)
	num = int(num)

	if num > int(1e18):
		print "ERROR"

	test_file.write("{}\n".format(num))
	
	test_file.close()