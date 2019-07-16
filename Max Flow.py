T = int(input())
flow = []
for m in range(T):
    flows = []
    num = int(input())
    for n in range(num):
        flows.append(int(input()))
    flow.append(max(flows))
for m in flow:
    print(m)
