import sys
raw_input = sys.stdin.readline
a=int(raw_input())
b=sorted(map(int,raw_input().split()))
c=sorted(map(int,raw_input().split()))
m=0
for d, e in zip(b,c):
    m=max(abs(d-e),m)
print m