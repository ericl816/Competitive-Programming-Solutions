#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 20
#define MAXN 1000010
#define MOD 1000000007
#define INF 0x3f3f3f3f
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

int N, K;
int a[MAXN];
ll DP[MAXN], res[MAXN], suff_max[MAXN];

// Find max. score attainable using at most K days and with fewest days possible
// Consider suffix_maximum

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) cin >> a[i];
	// Easy case
	if (K >= N) {
		int maxx = 0;
		for (int i=0; i<N; i++) maxx = max(maxx, a[i]);
		cout << maxx << "\n";
		return 0;
	}
	DP[0] = 1LL * a[0];
	for (int i=1; i<K; i++) DP[i] = max(DP[i - 1], 1LL * a[i]);
	for (int i=K; i<N; i+=K) {
		suff_max[i - 1] = res[i - 1] = DP[i - 1];
		for (int j=i - 2; j>=i - K; j--) suff_max[j] = max(suff_max[j + 1], DP[j]);
		int curr = a[i - 1];
		for (int j=i - 2; j>=i - K; j--) {
			res[j] = max(res[j + 1], DP[j] + curr);
			curr = max(curr, a[j]);
		}
		curr = 0;
		for (int j=i; j<min(N, i + K); j++) {
			curr = max(curr, a[j]);
			DP[j] = max(res[j - K], suff_max[j - K] + curr);
		}
	}
	// for (int i=0; i<N; i++) D("%d %lld\n", i, DP[i]);
	cout << DP[N - 1] << "\n";
	return 0;
}

/*
5 3
2 5 7 1 4
Ans: 12

5 4
1 3 5 10 11
Ans: 21
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */