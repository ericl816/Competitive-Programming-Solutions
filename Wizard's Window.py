import sys
raw_input = sys.stdin.readline
for T in range(10):
	N, M = map(int, raw_input().split())
	s = {}
	for i in range(4):
		x, y = raw_input().split()
		s[x] = y
	bott = raw_input().strip()
	for i in range(M - 1):
		top = ""
		for j in range(N):
			top += s[bott[j - 1] + bott[(j + 1) % N]]
		bott = top
	print(bott)
	ch = raw_input()