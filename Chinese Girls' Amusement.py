import sys
raw_input = sys.stdin.readline
from math import gcd
N = int(raw_input())
K = N >> 1
while gcd(N, K) > 1:
    K -= 1
print(K)