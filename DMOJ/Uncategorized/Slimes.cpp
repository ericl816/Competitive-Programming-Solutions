#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 410
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

ll N;
ll a[MAXN], PSA[MAXN];
ll DP[MAXN][MAXN];

inline ll Solve (ll x, ll y) {
	ll &res = DP[x][y];
	if (x == y) return res = 0;
	if (x > y) return res = INF;
	if (~res) return res;
	ll minn = INF;
	for (ll i=x; i<=y; i++) {
		if (i + 1 <= y) minn = min(minn, Solve(x, i) + Solve(i + 1, y) + PSA[y] - PSA[x - 1]);
	}
	return res = minn;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(DP, -1, sizeof(DP));
	for (int i=1; i<=N; i++) {
		cin >> a[i];
		PSA[i] = PSA[i - 1] + a[i];
	}
	cout << Solve(1, N) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */