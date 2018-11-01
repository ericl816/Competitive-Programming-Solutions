import sys
raw_input = sys.stdin.readline
N = int(raw_input())
A = map(int,raw_input().split())
DP = [0, max(A[0], 0)]
for a in A[1:]:
    DP.append(max(DP[-1], DP[-2] + a))
print DP[-1]