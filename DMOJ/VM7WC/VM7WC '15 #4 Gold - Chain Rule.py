import sys
raw_input=sys.stdin.readline
N,M=map(int,raw_input().split())
dist1=[-1 for i in range(N)]
dist2=[-1 for i in range(N)]
adj = __import__("collections").defaultdict(list)
for i in range(M):
	a, b, c = map(int, raw_input().split())
	adj[a].append((b, c))
	adj[b].append((a, c))
dist1[0]=dist2[-1]=0
queue = __import__("collections").deque([(0, 0)])
while queue:
	currcost, curr=queue.popleft()
	for next, cost in adj[curr]:
		if dist1[next] > currcost + cost or dist1[next] == -1:
			dist1[next] = currcost + cost
			queue.append((dist1[next], next))
queue.append((0,N-1))
while queue:
	currcost, curr=queue.popleft()
	for next, cost in adj[curr]:
		if dist2[next] > currcost + cost or dist2[next] == -1:
			dist2[next] = currcost + cost
			queue.append((dist2[next], next))
print(max(map(sum, zip(dist1, dist2))))