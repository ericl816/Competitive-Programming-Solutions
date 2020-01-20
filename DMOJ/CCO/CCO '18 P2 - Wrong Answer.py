import sys
raw_input = sys.stdin.readline
N = 100
print(N)
for i in xrange(0, N):
    if i == 0: print("1 1 1"),
    else:
        if i & 1: print("1"),
        else: print("100"),
        if N - i >= 3: print("100"),
        if N - i >= 4: print("1"),
    for j in xrange(3, N - i - 1): print("100"),
    print