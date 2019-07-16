import math

N = int(raw_input().strip())
cost = 0
while N > 1:
    r = int(math.sqrt(N)) + 1
    f = 2
    while f <= r and N % f != 0: 
        f = f + 1    
    if f < N and N % f == 0: 
        x = N / f
        N = N - x
        cost = cost + N / x 
    else:            
        N = N - 1
        cost = cost + N
print cost
