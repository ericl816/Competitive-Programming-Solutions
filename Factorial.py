import sys
raw_input = sys.stdin.readline
Q = int(raw_input())

def Count_Zeros(n):
    res = 0
    while n > 4:
        res += n // 5
        n //= 5
    return res;

def Lower_Bound():
    lo = 0
    hi = 100000000000
    while lo + 1 < hi:
        mid = (lo + hi) >> 1
        val = Count_Zeros(mid)
        if (val < Q):
            lo = mid;
        else:
            hi = mid
    return hi

idx = Lower_Bound()
print(idx if Count_Zeros(idx) == Q else "No solution")