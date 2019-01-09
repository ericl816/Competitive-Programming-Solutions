import sys
raw_input=sys.stdin.readline
A=int(raw_input())
B=int(raw_input())
N=int(raw_input())
motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
for i in range(N):
	m=int(raw_input())
	motels.append(m)
motels.sort()
DP=[0 for i in range(len(motels))]
DP[0]=1
for i in range(len(motels)):
	for j in range(i + 1, len(motels)):
		res = motels[j] - motels[i]
		if A <= res and res <= B: DP[j] += DP[i]
print(DP[len(motels)-1])