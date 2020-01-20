import sys
raw_input = sys.stdin.readline
W = int(raw_input())
N = int(raw_input())
carWeight = [0,0,0]
for i in range(N):
    carWeight.append(int(raw_input()))
carWeight.append (W+1)

carsAcross = 0
i = 3
totalWeight = carWeight[i-3] + carWeight[i-2] + carWeight[i-1] + carWeight[i]
while totalWeight <= W:
    carsAcross = carsAcross + 1
    i = i + 1
    totalWeight = carWeight[i-3] + carWeight[i-2] + carWeight[i-1] + carWeight[i]
print carsAcross