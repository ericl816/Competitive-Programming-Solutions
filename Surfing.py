import sys
raw_input = sys.stdin.readline

nodeassign = {}
node = 0 
graph = [[False for i in xrange(100)]for i in xrange(100)] 
n = int(raw_input())

for i in range(n):
    webpage = raw_input().strip() 
    HTMLcode = ""
    HTML = ""
    while HTML != "</HTML>":
        HTML = raw_input().strip()
        HTMLcode += HTML   
    while HTMLcode.find("A HREF=") != -1: 
        HTMLlink = HTMLcode.find("A HREF=") 
        start = HTMLcode.find('"', HTMLlink) 
        end = HTMLcode.find('"', start + 1)
        link = HTMLcode[start + 1: end]
        print "Link from", webpage, "to", link
        if webpage not in nodeassign:
            nodeassign[webpage] = node
            node += 1 
        if link not in nodeassign:
            nodeassign[link] = node
            node += 1
        graph[nodeassign[webpage]][nodeassign[link]] = True
        HTMLcode = HTMLcode[end + 1:] 

print
here = raw_input().strip() 
while here != "The End":
    there = raw_input().strip() 
    flag = [False for i in xrange(100)]
    queue = [nodeassign[here]]
    flag[nodeassign[here]] = True 
    end = nodeassign[there]
    while queue:
        u = queue.pop(0)
        for i in xrange(100): 
            if graph[u][i] and not flag[i]: 
                flag[i] = True
                queue.append(i)
    if flag[end]:
        print "Can surf from", here, "to", there + "."
    else:
        print "Can't surf from", here, "to", there + "." 
    here = raw_input().strip()
