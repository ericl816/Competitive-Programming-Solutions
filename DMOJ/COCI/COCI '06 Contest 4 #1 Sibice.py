import sys
raw_input=sys.stdin.readline
n,w,h=map(int,raw_input().split())
l=w*w+h*h
for i in range(n):
	x = int(raw_input())
	print("DA" if x*x<=l else "NE")