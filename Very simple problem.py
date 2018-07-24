import sys
raw_input = sys.stdin.readline
n = int(raw_input())
lo = 0
hi = 2 * n
while lo + 1 < hi:
    mid = (lo + hi) // 2
    if mid * mid <= n:
        lo = mid
    else:
        hi = mid
print(lo)