import sys
raw_input = sys.stdin.readline
def Solve():
	for i in range(10):
		N = int(raw_input())
		ans = ""
		ss = set()
		for j in range(1, N):
			if N % j == 0: ss.add(j)
		for j in range(5):
			R, C = map(int, raw_input().split())
			cnt = 0
			R -= 1
			C -= 1
			for k in ss:
				if (R // k + C // k) % 2 == 0:
					cnt += 1
			ans += "B" if cnt % 2 == 0 else "G"
		print(ans)
Solve()