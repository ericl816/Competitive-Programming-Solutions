import sys
raw_input = sys.stdin.readline
N = int(raw_input())
path_node = 0
subtree_size = [0 for i in xrange(N + 1)]
idx = [-1 for i in xrange(N)]
parity = [False for i in xrange(N + 1)]
adj = __import__("collections").defaultdict(list)
A = [] * (N + 1)
ans = 0L

def DFS (node, prev):
	idx[node] = path_node
	subtree_size[path_node] += 1
	for next in adj[node]:
		if next == prev or ~idx[next]: continue
		DFS(next, node)

A = list(map(int, raw_input().split()))
for i in xrange(0, N):
	parity[i] = True if (A[i] & 1 == 1) else False
for i in xrange(N - 1):
	a, b = map(int, raw_input().split())
	a -= 1
	b -= 1
	if parity[a] != parity[b]:
		adj[a].append(b)
		adj[b].append(a)
for i in xrange(N):
	if idx[i] == -1:
		DFS(i, -1)
		path_node += 1
	if parity[i]:
		ans += subtree_size[idx[i]]
print(ans)