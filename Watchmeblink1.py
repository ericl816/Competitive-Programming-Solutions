import sys
raw_input = sys.stdin.readline
N = int(raw_input())
K = int(raw_input())
J = int(raw_input())
diff = [[0 for i in range(100010)] for i in range(4)] #equivalent of diff[4][100010]
for i in range(J):
	L, R, I, T = map(int, raw_input().split())
	diff[T][L] += I
	diff[T][R + 1] -= I
for i in xrange(1, 4):
	ans = 0
	for j in xrange(1, N + 1):
		diff[i][j] += diff[i][j - 1]
		ans += diff[i][j] < K
	print(ans)