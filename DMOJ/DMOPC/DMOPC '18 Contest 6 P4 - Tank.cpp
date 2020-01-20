#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f
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

int N, P, M, ans;
pair<ll, ll> p[MAXN];
ll a[MAXN], b[MAXN], PSA1[MAXN], PSA2[MAXN];
ll minn = INF;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P >> M;
	for (int i=1; i<=N; i++) cin >> p[i].f >> p[i].s;
	for (int i=1; i<=P; i++) cin >> a[i];
	for (int i=1; i<=M; i++) cin >> b[i];
	sort(a + 1, a + P + 1, greater<ll>());
	sort(b + 1, b + M + 1, greater<ll>());
	for (int i=1; i<MAXN; i++) PSA1[i] = PSA1[i - 1] + a[i];
	for (int i=1; i<MAXN; i++) PSA2[i] = PSA2[i - 1] + b[i];
	for (int i=1; i<=N; i++) {
		int idx1 = lower_bound(a + 1, a + P + 1, p[i].f, greater<ll>()) - a, idx2 = lower_bound(b + 1, b + M + 1, p[i].s, greater<ll>()) - b;
		ll sum = PSA1[idx1 - 1] - (idx1 - 1) * p[i].f + PSA2[idx2 - 1] - (idx2 - 1) * p[i].s;
		// D("%d %lld\n", i, sum);
		if (minn > sum) {
			minn = sum;
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */