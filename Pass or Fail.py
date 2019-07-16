import sys
raw_input = sys.stdin.readline
T = 10
for z in range(T):
	a, b, c, d = map(int, raw_input().split())
	n = int(raw_input())
	cnt = 0
	for i in range(n):
		t, e, p, q = map(int, raw_input().split())
		mark = a * t + b * e + c * p + d * q
		if mark >= 5000: cnt += 1
	print(cnt)