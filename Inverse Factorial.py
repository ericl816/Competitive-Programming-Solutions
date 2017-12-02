import math
import sys
input = sys.stdin.readline

arr = ["1", "2", "6", "24", "120"]
n = input().strip()
if n in arr:
  print(arr.index(n) + 1)
  
else:
    lo = 0
    hi = len(n)
    idx = 1
    while lo < hi:
        lo += math.log10(idx)
        if lo < hi:
          idx += 1
        else:
          break
    print(idx - 1)