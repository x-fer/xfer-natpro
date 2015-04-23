import random


def generate_test(size, id):
	
	file = open("test/soci.in."+str(id), "w")
	maxi = 1000000000
	out_list = []
	print >> file, size
	for i in range(size/2):
		if i % 10 != 0:
			poz = len(out_list)/2
		else:
			poz = random.randrange(0, len(out_list)+1)
		num = random.randrange(0, maxi)
		out_list.insert(poz, num)
		out_list.insert(poz, num)

	for i in out_list:
		print >> file, i

	file.close()
	
size_list = [1000, 10000, 100000, 200000, 300000, 400000, 500000, 700000, 800000, 1000000]

for i in range(len(size_list)):	
	generate_test(size_list[i], i+1)
	print size_list[i], i+1
	 