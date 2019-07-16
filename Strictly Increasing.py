import sys
raw_input = sys.stdin.readline

def Recur (idx, len):
	if len == 1: return 1
	sum = 0L
	for i in range(idx + 1, b - len + 1):
		sum += Recur(i, len - 1)
	return sum

N = int(raw_input())
a, b = map(int, raw_input().split())
a, b = 0, b - a + 1
print(Recur(0, N - 2))