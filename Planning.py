import sys
raw_input = sys.stdin.readline
MOD = 998244353
N = int(raw_input())
M = (N * (N + 1)) >> 1;
print ((pow(2, M, MOD) + MOD) % MOD)