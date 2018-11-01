import sys
raw_input = sys.stdin.readline
R, C, K = map(int, raw_input().split())
lo_x = 1
hi_x = R
lo_y = 1
hi_y = C
min_score = {}
maxx = 1L << 30

def Query (a, b):
	print "?", a, b
	sys.stdout.flush()
	min_score[a, b] = int(raw_input())

def Check (a, b):
	if a > R or b > C: 
		min_score[a, b] = maxx
	else: 
		Query(a, b)

while lo_x < hi_x or lo_y < hi_y:
	mid_x = (lo_x + hi_x) >> 1
	mid_y = (lo_y + hi_y) >> 1
	Check(mid_x, mid_y)
	Check(mid_x + 1, mid_y)
	Check(mid_x, mid_y + 1)
	if min_score[mid_x, mid_y] < min_score[mid_x + 1, mid_y]: 
		hi_x = mid_x
	else: 
		lo_x = mid_x + 1
	if min_score[mid_x, mid_y] < min_score[mid_x, mid_y + 1]: 
		hi_y = mid_y
	else: 
		lo_y = mid_y + 1
Check(lo_x, lo_y)
print "!", min_score[lo_x, lo_y]