#include <stdio.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ll long long
char _;
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
	scan(N);
	for (int i=0; i<N; i++) {
	  scan(op); scan(r); scan(c); scan(t);
		if (op == 1) Update(r, t);
		else ans = (ans + Query(r) - Query(r - t - 1) + MOD) % MOD;
	}
	printf("%d\n", ans % MOD);
}