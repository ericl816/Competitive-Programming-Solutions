import sys
raw_input = sys.stdin.readline
N, M = map(int, raw_input().split())
adj = __import__("collections").defaultdict(list)
for i in range(M):
	A, B, C = map(int, raw_input().split())
	adj[A].append((B, C))
	adj[B].append((A, C))
dist1 = [-1 for i in range(N)]
dist2 = [-1 for i in range(N)]
dist1[0] = dist2[-1] = 0
queue = __import__("collections").deque([(0, 0)])
while queue:
	curr, currcost = queue.popleft()
	for nextnode, cost in adj[curr]:
		nextcost = currcost + cost
		if nextcost < dist1[nextnode] or dist1[nextnode] == -1:
			dist1[nextnode] = nextcost
			queue.append((nextnode, dist1[nextnode]))
queue.append((N - 1, 0))
while queue:
	curr, currcost = queue.popleft()
	for nextnode, cost in adj[curr]:
		nextcost = currcost + cost
		if nextcost < dist2[nextnode] or dist2[nextnode] == -1:
			dist2[nextnode] = nextcost
			queue.append((nextnode, dist2[nextnode]))
print(max(map(sum, zip(dist1, dist2))))