
def powerOf2(n):
	return  (n&(n-1) == 0)

for a in range(0, 100):
	print str(a) + " " + str(powerOf2(a))