MOD = 2 ** 32
tests = int(raw_input())
for temp in xrange(tests):
	var = 1
	N = int(raw_input())
	if N >= 50:
		print 0
		continue
	for i in xrange(2, N + 1):
		var *= i
		var %= MOD
	print var
