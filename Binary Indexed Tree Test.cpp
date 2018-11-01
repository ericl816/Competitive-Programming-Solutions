#include <iostream>
#define ull unsigned long long
using namespace std;
const int MAXN = 100010;
int N, M, arr[MAXN];
ull BIT1[MAXN], BIT2[MAXN];
char ch;

void update (ull (&BIT) [MAXN], int idx, int val) {
  for (; idx<=MAXN; idx += idx &- idx) BIT[idx] += val;
}

ull query (ull (&BIT) [MAXN], int idx) {
  ull ans = 0;
  for (; idx>0; idx ^= idx &- idx) ans += BIT[idx];
  return ans;
}

int main () {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
    update(BIT1, i + 1, arr[i]);
    update(BIT2, arr[i], 1);
  }
  for (int i=0; i<M; i++) {
    scanf(" %c", &ch);
    if (ch == 'C') {
      int x, v;
      scanf("%d %d", &x, &v);
      x--;
      update(BIT1, x + 1, v - arr[x]);
      update(BIT2, arr[x], -1);
      update(BIT2, arr[x] = v, 1);
    }
    else if (ch == 'S') {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%llu\n", query(BIT1, r) - query(BIT1, l - 1));
    }
    else {
      int v;
      scanf("%d", &v);
      printf("%llu\n", query(BIT2, v));
    }
  }
}