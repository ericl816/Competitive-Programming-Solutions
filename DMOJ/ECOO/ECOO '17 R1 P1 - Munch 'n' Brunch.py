import sys
raw_input = sys.stdin.readline
T = 10
for i in range(T):
	C = int(raw_input())
	a, b, c, d = map(float, raw_input().split())
	N = int(raw_input())
	tot = int(N * a) * 12 + int(N * b) * 10 + int(N * c) * 7 + int(N * d) * 5
	if tot >= C * 2: print("NO")
	else: print("YES")