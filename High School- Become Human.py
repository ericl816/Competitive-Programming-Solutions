import sys
from math import log
x, y = map(int, raw_input().split())
EPS = 1e-8
a = y * log(x)
b = x * log(y)
if abs(a - b) <= EPS: print("=")
elif a < b: print("<")
else: print(">")