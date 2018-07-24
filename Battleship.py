import sys
raw_input = sys.stdin.readline
n, k = map(int, raw_input().split())
a = []
for i in range(n):
    a.append(raw_input())
maxans = 0
xans = 0
yans = 0
for i in range(n):
    for j in range(n):
        curans = 0
        l = 0
        while l < k and i - l >= 0 and a[i - l][j] == '.':
            l += 1
        r = 0
        while r < k and i + r < n and a[i + r][j] == '.':
            r += 1
        curans += max(0, r + l - k)
        if k != 1:
            l = 0
            while l < k and j - l >= 0 and a[i][j - l] == '.':
                l += 1
            r = 0
            while r < k and j + r < n and a[i][j + r] == '.':
                r += 1
            curans += max(0, r + l - k)
        if curans > maxans:
            maxans = curans
            xans = i
            yans = j
print("{} {}".format(xans + 1, yans + 1))