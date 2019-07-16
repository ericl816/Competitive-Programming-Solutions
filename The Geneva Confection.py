import sys
raw_input = sys.stdin.readline

p = 0
t = int(raw_input())
p = p + 1

for test in range(t):
    n = int(raw_input())
    p = p + 1
    mountain = []
    for i in range(n):
        mountain.append(int(raw_input()))
        p = p + 1
    branch = []
    mtnCar = n - 1
    nextCar = 1
    state = "Y"

    while state == "Y" and nextCar <= n:
        if mtnCar >= 0 and nextCar == mountain[mtnCar]:
            mtnCar = mtnCar - 1
            nextCar = nextCar + 1
        elif len(branch) > 0 and nextCar == branch[len(branch) - 1]:
            branch.pop(len(branch) - 1)
            nextCar = nextCar + 1
        elif mtnCar >= 0:
            branch.append(mountain[mtnCar])
            mtnCar = mtnCar - 1
        else:
            state = "N"
    print state