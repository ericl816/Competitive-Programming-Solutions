import sys
raw_input = sys.stdin.readline
N = int(raw_input())
K = int(raw_input())
D = int(raw_input())
ans = N
while D > 0:
	ans *= K
	D -= 1
print(ans)