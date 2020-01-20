import sys
raw_input = sys.stdin.readline
M, N = map(int, raw_input().split())
grid = [raw_input() for x in range(M)]
black = [set() for x in range(M)]
for row in range(M):
	for col in range(N):
		if (grid[row][col] == '#'):
			black[row].add(col)

for a in range(M):
	for b in range(a, M):
		if a == b: continue
		if len(black[a] & black[b]) >= 2:
			print("no")
			sys.exit()
print("yes")