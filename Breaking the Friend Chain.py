import sys
raw_input = sys.stdin.readline
N, M = map(int, raw_input().split())
root = [i for i in range(N + 1)]
rank = [0 for i in range(N + 1)]

def Find (n):
	while root[n] != n:
		root[n] = root[root[n]]
		n = root[n]
	return n

def Merge(x, y):
	return Find(x) != Find(y)

def Rank(x, y):
	a = Find(x)
	b = Find(y)
	if Merge(x, y):
		if rank[a] > rank[b]:
			root[b] = a
			rank[a] += rank[b]
		else:
			root[a] = b
			rank[b] += rank[a]

for i in range(M):
	A, B = map(int, raw_input().split())
	if Merge(A, B):
	    Rank(A, B)
X, Y = map(int, raw_input().split())
print (0 if Merge(X, Y) else 1)