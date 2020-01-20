import sys
cnt = sum = 1
for i in sys.stdin.read().strip():
    if i == 'L':
        sum <<= 1
    elif i == 'R':
        sum = sum*2 + cnt
    elif i == '*':
        sum = sum*5 + cnt
        cnt *= 3
print sum