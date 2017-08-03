#include <stdio.h>
#define ll long long
using namespace std;

const int MAXN = 2010, MOD = 1e9 + 7;

int N, op, r, c, t, ans, BIT[MAXN][MAXN];

void Update (int idx, int val) {
	for (; idx <= r + c; idx += idx & -idx) BIT[r + c - 1][idx] += val;
}

int Query (int idx) {
  int sum = 0;
	for (; idx > 0; idx -= idx & -idx) sum = (sum + BIT[r + c - 1][idx]) % MOD;
	return sum;
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
	  scanf("%d %d %d %d", &op, &r, &c, &t);
		if (op == 1) Update(r, t);
		else ans = (ans + Query(r) - Query(r - t - 1) + MOD) % MOD;
	}
	printf("%d\n", ans % MOD);
}
