import sys

def path(data):
    xx, yy, moves = data
    if xx == x - 1 and yy == y - 1:
        global distance
        distance = moves + 1
        return
    visited.add((xx, yy))
    if grid[yy][xx] in ["+", "-"]:
        if xx + 1 < x and grid[yy][xx + 1] != "*" and (xx + 1, yy) not in visited:
            queue.append((xx + 1, yy, moves + 1))
        if xx - 1 >= 0 and grid[yy][xx - 1] != "*" and (xx - 1, yy) not in visited:
            queue.append((xx - 1, yy, moves + 1))
    if grid[yy][xx] in ["+", "|"]:
        if yy + 1 < y and grid[yy + 1][xx] != "*" and (xx, yy + 1) not in visited:
            queue.append((xx, yy + 1, moves + 1))
        if yy - 1 >= 0 and grid[yy - 1][xx] != "*" and (xx, yy - 1) not in visited:
            queue.append((xx, yy - 1, moves + 1))


for _ in range(int(sys.stdin.readline())):
    y = int(sys.stdin.readline())
    x = int(sys.stdin.readline())
    grid = [list(sys.stdin.readline()) for _ in range(y)]
    visited = set()
    queue = __import__("collections").deque([(0, 0, 0)])
    distance = -1
    while queue and distance == -1:
        path(queue.popleft())
    print(distance)