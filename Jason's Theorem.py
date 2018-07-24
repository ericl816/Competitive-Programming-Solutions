import sys
raw_input = sys.stdin.readline
N = 1L * int(raw_input())
MOD = 1000000007

def Fpow(x, y):
	if y == 0:
		return 1
	if y == 1:
		return x
	if y % 2 == 1:
		return x * Fpow((x * x) % MOD, y >> 1) % MOD
	else:
		return Fpow((x * x) % MOD, y >> 1) % MOD

def Calc(x):
	return 1L * (Fpow(2, N + 3) % MOD - 5 + MOD) % MOD

print((Calc(N) + MOD) % MOD)