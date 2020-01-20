import sys
s=raw_input()
n=len(s)
l=[(s+s)[i/n:i/n+i%n+1]for i in range(n*n)]
strs = min(filter(lambda x:(x*len(s)).find(s)+1,sorted(l)),key=len)
r = int(sys.stdin.readline())

for i in range(r):
 sys.stdout.write (strs[i])