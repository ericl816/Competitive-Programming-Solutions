from math import log
n, m = map(int, raw_input().split())
fruits = [raw_input() for i in xrange(n)]
fruit = {j: i for i, j in enumerate(fruits)}
apple = fruits.index('APPLES')
edges = []
for i in xrange(m):
    a, b, c = raw_input().split()
    edges.append((fruit[a], fruit[b], -log(float(c))))
dist = [1e3000] * n
dist[apple] = 0
for i in xrange(1, n):
    z = 0
    for a, b, c in edges:
        if dist[a] + c < dist[b]:
            dist[b] = dist[a] + c
            z = 1
    if not z:
        break
print ['NAW', 'YA'][dist[apple] < -1e-6]