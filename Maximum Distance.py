testCases = int(input())
for k in range(testCases):
    currentMax = 0
    n = int(input())
    x = raw_input().split()
    x = map(int, x)
    y = raw_input().split()
    y = map(int, y)

    for i in range(n):
        low = 0
        high = n - 1
        while low <= high:
            mid = (low + high) / 2
            if y[mid] >= x[i]:
                low = mid + 1
            else:
                high = mid - 1

        currentMax = max (currentMax, mid - i)

    print "The maximum distance is", currentMax
