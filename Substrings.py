import sys
raw_input = sys.stdin.readline

def LCP(s, t):
    n = min(len(s), len(t))
    for i in range(n):
        if s[i:i+1] != t[i:i+1]:
            return i
    return n

b = int(raw_input())
for n in range(b):
    string = raw_input().strip()
    
    suffix = []
    for i in range(len(string)):
        suffix.append(string[i:])
    suffix.sort()

    count = len(suffix[0]) + 1
    for i in range(1, len(string)):
        lcp = LCP(suffix[i], suffix[i - 1])
        count = count + len(suffix[i]) - lcp
        
    print count
