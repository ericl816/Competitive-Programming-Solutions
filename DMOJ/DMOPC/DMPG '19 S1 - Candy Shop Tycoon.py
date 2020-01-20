import sys
raw_input = sys.stdin.readline
a, b, c = map(int, raw_input().split())
C = int(raw_input())
for i in xrange(1, 101):
	for j in xrange(1, 101):
		for k in xrange(1, 101):
			if a * i + b * j + c * k == C:
				print("QUEST CLEARED")
				sys.exit()
print("TRY AGAIN")