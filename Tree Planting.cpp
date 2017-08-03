#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

const int MAXN = 2010, MOD = 1e9 + 7;

int N, op, r, c, t, ans, BIT[MAXN][MAXN];

void Update (int idx, int val) {
	for (; idx <= r + c; idx += idx & -idx) BIT[r + c - 1][idx] += val;
}

void Query1 (int idx) {
	for (; idx > 0; idx -= idx & -idx) ans = (ans + BIT[r + c - 1][idx]) % MOD;
}

void Query2 (int idx) {
	for (; idx > 0; idx -= idx & -idx) ans = (ans - BIT[r + c - 1][idx]) % MOD;
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
	  scanf("%d %d %d %d", &op, &r, &c, &t);
		if (op == 1) Update(r, t);
		else if (op == 2) {
			Query1(r);
			Query2(r - t - 1);
		}
	}
	printf("%d\n", ans % MOD);
}
