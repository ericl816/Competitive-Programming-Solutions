import sys
raw_input = sys.stdin.readline

c, r = map(int, raw_input().split())
x = 0
y = 0
a, b = map(int, raw_input().split())
while a != 0 or b != 0:
	x = max(0, min(c, x + a))
	y = max(0, min(r, y + b))
	print(str(x) + ' ' + str(y))
	a, b = map(int, raw_input().split())