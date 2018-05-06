n,m,x=map(int,raw_input().split())
N=map(int,raw_input().split())
s=sum(N)
aa=s*1.0/n
M=map(int,raw_input().split())
v=False
mina=100.0
aavg = 0.0
mind=0.0
for i in M:
    if i == 0: continue
    vv = True
    for j in N:
        if j > i:
            vv = False
            break
    avg = aa / i
    if avg < 0.5 or avg > 1.0 or avg < 0.3 or not vv:
        continue
    v=True
    aavg = 1.0 * abs(avg*100.0-x*1.0)
    if aavg < mina:
        mina = aavg
        mind = i
    if abs(aavg-mina)==0:
        mind = i
print(mind if v else "Shimnanigans have failed")