import sys
raw_input = sys.stdin.readline

a = int(raw_input())
b = int(raw_input())
count = 0
for n in range(1,22):
    i = n**6
    if (i >= a) and (i <= b):
        count+=1
print count