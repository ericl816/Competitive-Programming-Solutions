from functools import reduce
def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(pow(n, 0.5) + 1)) if n % i == 0)))
a=input()
ans=0
for i in range(a):
    b,c=raw_input().split()
    b=int(b)
    for n in sorted(list(factors(b)))[::-1][1:]:
        d=[c[i:i+n] for i in range(0, len(c), n)]
        e=True
        for i in d:
            if i != d[0]:
                e=False
                break
        if e:
            ans = max(ans,n*1.0/(b/n))
            break
print '{:0.10f}'.format(round(ans,10))