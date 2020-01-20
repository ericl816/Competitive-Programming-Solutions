import sys
raw_input = sys.stdin.readline
A, B, C = map(int, raw_input().split())
X, Y, Z = map(int, raw_input().split())
print(max(abs(A - X), abs(B - Y), abs(C - Z)))
print(int((abs(A - X) * abs(A - X) + abs(B - Y) * abs(B - Y) + abs(C - Z) * abs(C - Z)) ** 0.5))
print(abs(A - X) + abs(B - Y) + abs(C - Z))