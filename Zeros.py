import sys
raw_input = sys.stdin.readline

# Count number of trailing zeros
def Count_Zeros(n):
    res = 0
    while n > 4:
        res += n // 5
        n //= 5
    return res

# Custom implementation of upper_bound
def Upper_Bound(n):
    lo = 0
    hi = 10000000000
    while lo < hi:
        mid = (lo + hi + 1) // 2
        val = Count_Zeros(mid)
        if (val <= n):
            lo = mid;
        else:
            hi = mid - 1
    return hi

a, b = map(int, raw_input().split())
print(Upper_Bound(b) - Upper_Bound(a - 1))
