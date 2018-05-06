l=raw_input()
k=input()
n=[]
p=l[0]
l=l[1:]
for i,c in enumerate(l):
    if c!=p:
        p=c
        n.append(i+1)
n.append(len(l)+1)
p=0
cnt=0
for i in n:
    cnt+=max(0,i-p-k+1)
    p=i
print cnt