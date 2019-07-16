#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 22
#define MAXN 1000010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
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

// Sparse table + DP method

int N, K;
int a[MAXN];
ll DP[MAXN];
ll segmax[MAXM][MAXN];
ll ans;

inline ll Query (int x, int y) {
	int SIZE = log(y - x + 1) / log(2);
	return max(segmax[SIZE][x], segmax[SIZE][y - (1 << SIZE) + 1]);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=1; i<=N; i++) {
		cin >> a[i];
		segmax[0][i] = a[i];
	}
	for (int i=1; i<=(32 - __builtin_clz(N)); i++) {
		for (int j=1; j + (1 << i) - 1<=N; j++) {
			segmax[i][j] = max(segmax[i - 1][j], segmax[i - 1][j + (1 << (i - 1))]);
		}
	}
	if (K >= N) { // Edge case
		cout << Query(1, N) << "\n";
		return 0;
	}
	if (2 * K >= N) {
		// Only need to consider 2 non-overlapping intervals
		for (int i=1; i<=N; i++) {
			if (i <= K && N - i <= K) {
				ll pre = Query(1, i), suff = Query(i + 1, N);
				// D("%d %lld %lld\n", i, pre, suff);
				ans = max(ans, pre + suff);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	for (int i=1, l=0; i<=N; i++) {
		while (l < i - K) l++;
		while ((l + K) / K < (i + K - 1) / K && DP[l] + Query(l + 1, i) <= DP[l + 1] + Query(l + 2, i)) l++;
		DP[i] = DP[l] + Query(l + 1, i); 
	}
	cout << DP[N] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */