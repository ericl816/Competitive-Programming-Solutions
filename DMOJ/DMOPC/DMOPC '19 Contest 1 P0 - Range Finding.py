import sys
raw_input = sys.stdin.readline
N = int(raw_input())
l = list(map(int, raw_input().split()))
print(max(l) - min(l))