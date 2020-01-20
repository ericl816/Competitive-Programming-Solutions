N = input()
ways = [1,1,1,1,1,1, 1]
for i in range(1,N):
    y = input()
    ways[y] *= (ways[i] + 1)

print ways[N]