import sys
raw_input = sys.stdin.readline

n = 0
visited = []

class Node:
    def __init__(self, m, l):
        self.m = m
        self.level = l
        
def done (move):
    global n
    i = 0
    while i < n and move[i] == str(i+1):
        i = i + 1
    return i == n 

def movetoBaseN (move):
    global n
    basen = 0
    for i in range(n):
        for j in range (len(move[i])):
            x = int(move[i][j]) - 1
            basen += i * n**x
    return basen

def createNewMove (oldmove, p1, p2):
    global n
    newmove = []
    for i in range (n):
        newmove.append(oldmove[i])
        
    newmove[p2] = newmove[p1][0:1] + newmove[p2]
    newmove[p1] = newmove[p1][1:]

    if p2 < p1 and newmove[p2][0:1] == str(n):
        return oldmove
    else:
        return newmove
                                                
def search(move):
    global n
    if done(move):
        return 0
    else:
        tree = []
        tree.append(Node(move,0))          
        while len(tree) > 0:   
            x = tree.pop(0)
            for i in range(n):

                if i < n-1:
                    if len(x.m[i+1]) == 0 or x.m[i][0:1] < x.m[i+1][0:1]:
                        newmove = createNewMove(x.m, i, i+1)
                        bn = movetoBaseN (newmove)
                        if not visited[bn]:
                            visited[bn] = True
                            tree.append(Node(newmove,x.level + 1))
                            if done(newmove):
                                return x.level + 1

                if i > 0:
                    if len(x.m[i-1]) == 0 or x.m[i][0:1] < x.m[i-1][0:1]:
                        newmove = createNewMove(x.m, i, i-1)
                        bn = movetoBaseN (newmove)
                        if not visited[bn]:
                            visited[bn] = True
                            tree.append(Node(newmove,x.level + 1))
                            if done(newmove):
                                return x.level + 1
                          
        return "IMPOSSIBLE"     
       
n = int(raw_input().strip())
while n > 0:
 
    visited = []
    size = n**n
    for i in range(size + 1):
        visited.append(False)

    move = raw_input().strip().split()
    print search(move)
    n = int(raw_input().strip())