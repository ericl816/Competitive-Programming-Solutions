import sys
raw_input = sys.stdin.readline
ans = 0L
n, m = map(int, raw_input().split())
deg = [0 for i in range(m + 1)]
for i in xrange(0, m):
    x, y = map(int, raw_input().split())
    deg[x - 1] += 1
    deg[y - 1] += 1
for i in xrange(0, n): ans += deg[i] * deg[i]
print(ans)