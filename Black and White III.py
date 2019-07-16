import sys
raw_input = sys.stdin.readline
K, M = map(int, raw_input().split())
B = sum(raw_input().count('#') for _ in xrange(2 ** K))
MOD = 10 ** 9 + 7
print pow(pow(2, pow(4, M, MOD - 1), MOD) - 1, B, MOD)
