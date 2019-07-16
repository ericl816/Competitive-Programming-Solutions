for _ in range(int(input())):
    s = input()
    while len(s) > 1:
        s = str(sum(int(c) for c in s))
    print(s)