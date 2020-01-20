import sys
raw_input = sys.stdin.readline
k = int(raw_input())

list = []
for i in range(k):
    n = int(raw_input())
    if n > 0:
        list.append(n)
    else:
        list.pop()

sum = 0
for i in range(len(list)):
    sum = sum + list[i]

print sum