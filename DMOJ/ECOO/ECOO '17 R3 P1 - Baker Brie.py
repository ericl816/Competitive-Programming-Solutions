import sys
raw_input = sys.stdin.readline
for x in xrange(10):
  F, D = map(int, raw_input().split())
  summ = [0 for i in range(F)]
  vec = [0 for i in range(F)]
  for i in range(D):
    idx = 0
    f = [int(x) for x in raw_input().split()]
    for j in f:
      summ[idx] += j;
      idx += 1
    vec.append(sum(list(f)))
  ans = 0 
  for i in vec + summ:
    if i % 13 == 0:
      ans += i // 13
  print(ans)