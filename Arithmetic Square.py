a = [input().strip().split() for i in range(3)]

def xcnt(a, b, c):
	res = 0
	if a == 'X':
		res += 1
	if b == 'X':
		res += 1
	if c == 'X':
		res += 1
	return res

def fix(a, b, c):
	if xcnt(a, b, c) != 1:
		return (None, None, None)

	if a == 'X':
		b = int(b)
		c = int(c)
		a = b - (c - b)
	if b == 'X':
		a = int(a)
		c = int(c)
		b = (a + c) // 2
	if c == 'X':
		a = int(a)
		b = int(b)
		c = b + (b - a)
	
	return (a, b, c)

def done():
	for r in a:
		for c in r:
			if c == 'X':
				return False
	return True

def guess():
	if a[1][1] == 'X':
		a[1][1] = 0
		return

	if a[0][1] == 'X':
		a[0][1] = 0
		return
	if a[2][1] == 'X':
		a[2][1] = 0
		return
	if a[1][0] == 'X':
		a[1][0] = 0
		return
	if a[1][2] == 'X':
		a[1][2] = 0
		return

	if a[0][0] == 'X':
		a[0][0] = 0
		return
	if a[0][2] == 'X':
		a[0][2] = 0
		return
	if a[2][0] == 'X':
		a[2][0] = 0
		return
	if a[2][2] == 'X':
		a[2][2] = 0
		return

while not done():
	fixed = False

	d, e, f = fix(a[0][0], a[0][1], a[0][2])
	if d != None:
		fixed = True
		a[0][0] = d
		a[0][1] = e
		a[0][2] = f

	d, e, f = fix(a[1][0], a[1][1], a[1][2])
	if d != None:
		fixed = True
		a[1][0] = d
		a[1][1] = e
		a[1][2] = f

	d, e, f = fix(a[2][0], a[2][1], a[2][2])
	if d != None:
		fixed = True
		a[2][0] = d
		a[2][1] = e
		a[2][2] = f

	d, e, f = fix(a[0][0], a[1][0], a[2][0])
	if d != None:
		fixed = True
		a[0][0] = d
		a[1][0] = e
		a[2][0] = f

	d, e, f = fix(a[0][1], a[1][1], a[2][1])
	if d != None:
		fixed = True
		a[0][1] = d
		a[1][1] = e
		a[2][1] = f

	d, e, f = fix(a[0][2], a[1][2], a[2][2])
	if d != None:
		fixed = True
		a[0][2] = d
		a[1][2] = e
		a[2][2] = f

	if not fixed:
		guess()

for i in range(3):
	print(' '.join([str(c) for c in a[i]]))