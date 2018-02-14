#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 105
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Question: Output the number of permutations of the elements 1 to N which has maximum contiguous increasing subsequence with length K, mod 10^9 + 7

int N, K;
ll memof[MAXN];
ll memog[MAXN][MAXN], perm[MAXN][MAXN];

void Choose () {
	for (int i=0; i<MAXN; i++) {
		perm[i][0] = 1;
		for (int j=1; j<=i; j++) perm[i][j] = (perm[i - 1][j - 1] + perm[i - 1][j]) % MOD;
	}
}

ll fun1 (int N);

ll fun2 (int n, int L) {
	ll &x = memog[n][L];
	if (~x) return x;
	if (n < L || L > K) return x = 0;
	if (n == 0) return x = 1;
	if (L == 0) return x = 0;
	x = fun2(n - 1, L - 1);
	for (int i=L + 1; i<=n; i++) {
		ll ch = perm[n - 1][i - 1];
		ll left = fun2(i - 1, L);
		ll right = fun1(n - i) - fun2(n - i, K);
		right = (right % MOD + MOD) % MOD;
		x += (((left * right) % MOD) * ch) % MOD;
		x %= MOD;
	}
	return x;
}

ll fun1 (int N) {
	ll &x = memof[N];
	if (~x) return x;
	if (N == 0) return x = 1;
	x = 0;
	for (int i=0; i<N; i++) {
		ll left = fun1(i);
		ll ch = perm[N - 1][i];
		ll right = fun1(N - i - 1) - fun2(N - i - 1, K);
		right = (right % MOD + MOD) % MOD;
		x += (((left * right) % MOD) * ch) % MOD;
		x %= MOD;
	}
	return x;
}

int main () {
	scan(N); scan(K);
	Choose();
	memset(memof, -1, sizeof(memof));
	memset(memog, -1, sizeof(memog));
	ll res1 = fun1(N);
	memset(memof, -1, sizeof(memof));
	memset(memog, -1, sizeof(memog));
	K--;
	ll res2 = fun1(N);
	ll ans = ((res1 - res2) % MOD + MOD) % MOD;
	return !printf("%lld\n", ans);
}