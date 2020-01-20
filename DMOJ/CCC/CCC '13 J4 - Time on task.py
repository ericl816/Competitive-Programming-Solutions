t = input()
c = input()
x = []
for i in range(c):
    x.append(input())

x.sort()

sum = 0
count = 0
while count < len(x) and sum <= t:
    sum = sum + x[count]
    count = count + 1
if sum > t:
    print count - 1
else:
    print count