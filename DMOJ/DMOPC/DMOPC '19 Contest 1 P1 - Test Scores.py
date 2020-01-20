import sys
import math
raw_input = sys.stdin.readline
N = int(raw_input())
for i in range(0, N):
  n, a, b, t = map(int, raw_input().split())
  res = math.ceil(1.0 * (t + b * n) / (a + b))
  print(-1 if res > n else int(round(res)))