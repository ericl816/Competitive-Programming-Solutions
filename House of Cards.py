n,k=map(int,raw_input().split())
l=sorted(map(int,raw_input().split()))
cnt = 1
cur = l[0]
l=l[1:]
for i in l:
    if i >= cur+k:
        cur = i
        cnt += 1
print cnt