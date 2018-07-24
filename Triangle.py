import sys
raw_input = sys.stdin.readline
n = int(raw_input())
a = [int(raw_input()) for _ in range(n)]
a.sort()
for i in range(1, n - 1):
    if a[i - 1] + a[i] > a[i + 1]:
        print(a[i - 1], a[i], a[i + 1])
        sys.exit(0)
print(0, 0, 0)