import sys
raw_input = sys.stdin.readline
n = int(raw_input())
t = int(raw_input())

line = [-1000000000]
segy = [-1000000000]   

for i in xrange(n):
    x1, y1, x2, y2, val = map(int, raw_input().split())
    line.append([x1, y1, y2, val])       
    line.append([x2, y1, y2, -val])       
    segy.append(y1)
    segy.append(y2)
line.sort()
segy = list(set(segy))    
segy.sort()

findy = {}     
for i in xrange(1, len(segy)):
    findy[segy[i]] = i
    
yaxis = [0 for i in xrange(len(segy) + 1)]

ans = 0
for i in xrange(1, len(line)):         
    for j in xrange(1, len(segy)):
        if yaxis[j] >= t:
            ans += (segy[j + 1] - segy[j]) * (line[i][0] - line[i - 1][0])
    for j in xrange(findy[line[i][1]], findy[line[i][2]]):
        yaxis[j] += line[i][3]
print(ans)
