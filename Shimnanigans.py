n, m, x = [int(d) for d in input().split()]
x /= 100
numers = [int(d) for d in input().split()]
denoms = [int(d) for d in input().split()]
numersum = sum(numers)
maxnumer = max(numers)
bestaverage = 1.01
bestdenom = -1
for d in denoms:
    if d >= maxnumer and numersum / d / n >= 0.5:
        if abs(numersum / d / n - x) < bestaverage:
            bestaverage = abs(numersum / d / n - x)
            bestdenom = d
        elif abs(numersum / d / n - x) == bestaverage:
            bestdenom = max(bestdenom, d)
if bestdenom == -1: print('Shimnanigans have failed')
else: print(bestdenom)