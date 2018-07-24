import sys
raw_input = sys.stdin.readline
k, n, s, p = map(int, raw_input().split())
num_sheets = (n + s - 1) // s
sheets = num_sheets * k
print(sheets + p - 1) // p