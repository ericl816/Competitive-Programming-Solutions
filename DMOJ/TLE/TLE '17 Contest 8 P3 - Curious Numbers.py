import sys
raw_input = sys.stdin.readline
q, k = map(int, raw_input().split())
p = [i for i in xrange(k, 50000010, k) if `i` == `i`[::-1]]
for _ in xrange(q):
	m, n = map(int, raw_input().split())
	print(__import__("bisect").bisect(p, n) - __import__("bisect").bisect_left(p, m))