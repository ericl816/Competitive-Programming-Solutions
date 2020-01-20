#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 3110
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int T, R, C;
int comb[MAXN][MAXN];

inline ll PowMod (ll a, ll b) {
	ll val = 1;
	while (b) {
		if (b & 1) val = (val * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return val;
}

inline void Preprocess () {
	for (int i=1; i<=3100; i++) {
		for (int j=1; j<=3100; j++) {
			if (i == j || j == 1) comb[i][j] = 1LL;
			else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
}

inline ll Solve () {
	ll ans = 0LL, parity = 1LL;
	for (int i=0; i<=C; i++) {
		ans = (ans + (comb[C + 1][i + 1] * (PowMod(PowMod(2, C - i) - 1, R)) % MOD) * parity) % MOD;
		parity *= -1LL;
	}
	return (ans % MOD + MOD) % MOD;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Preprocess();
	cin >> T;
	while (T--) {
		cin >> R >> C;
		if (R < C) swap(R, C);
		cout << Solve() << "\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */