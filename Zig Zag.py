"""
 * A sequence of integers from 1 to N is said to be zig zag 
 * if the sequence contains each integer exactly once and, 
 * indexing from one, every element at an even index is greater 
 * than the preceding one, and every element at an odd index is 
 * less than the preceding one.
 * For each test case, output the number of unique zig zag sequences
"""
import sys
raw_input = sys.stdin.readline
MOD = 1000000007
DP = [[0 for i in range(10010)] for j in range(2)]
for z in range(10):
	N = int(raw_input())
	DP = [[0 for i in range(10010)] for j in range(2)]
	DP[1][1] = 1
	DP[0][0] = DP[0][1] = 0
	for i in range(2, N + 1):
		print(i)
		for j in range(1, i + 1):
			print(j)
			if i % 2 == 0:
				DP[j][0] = (DP[j - 1][1] + DP[j - 1][0]) % MOD
				DP[j + 1][0] = DP[j][0]
			else:
				DP[j][1] = ((DP[i][0] - (DP[j - 1][0] - DP[j - 1][1])) + MOD) % MOD
				DP[j + 1][1] = DP[j][1]
	print(DP[N][N % 2] % MOD)
