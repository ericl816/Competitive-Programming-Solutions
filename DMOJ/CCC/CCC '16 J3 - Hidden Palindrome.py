import sys
raw_input = sys.stdin.readline
from sys import exit
s = raw_input()
for i in range(len(s), 0, -1):
    for j in range(0, len(s) - i + 1):
        test = s[j : j + i]
        if test[::-1] == test:
            print(i)
            exit(0)