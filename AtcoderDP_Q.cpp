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

int N;
ll h[MAXN], a[MAXN], tree[MAXN << 2];
ll sum, ans;

inline void Push_Up (ll idx) {
	tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}

inline void Update (ll idx, ll l, ll r, ll ind, ll val) {
	if (l == r) {
		tree[idx] = val;
		return;
	}
	ll mid = (l + r) >> 1;
	if (ind <= mid) Update(idx << 1, l, mid, ind, val);
	else Update(idx << 1 | 1, mid + 1, r, ind, val);
	Push_Up(idx);
}

inline ll Query (ll idx, ll l, ll r, ll l1, ll r1) {
	if (l > r1 || r < l1) return 0LL;
	if (l >= l1 && r <= r1) return tree[idx];
	ll mid = (l + r) >> 1;
	return max(Query(idx << 1, l, mid, l1, r1), Query(idx << 1 | 1, mid + 1, r, l1, r1));
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
	for (int i=1; i<=N; i++) cin >> h[i];
	for (int i=1; i<=N; i++) cin >> a[i];
	for (int i=1; i<=N; i++) {
		sum = Query(1, 1, N, 1, h[i]) + a[i];
		Update(1, 1, N, h[i], sum);
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}

/*
5
1 2 3 4 5
1000000000 1000000000 1000000000 1000000000 1000000000
Ans: 5000000000
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */