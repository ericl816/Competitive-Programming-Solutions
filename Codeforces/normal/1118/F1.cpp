#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 300010
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

int n, v, u, ans;
int a[MAXN];
vi adj[MAXN];
pii subtree_size[MAXN];

inline void DFS1 (int node, int prev) {
	if (a[node] == 1) subtree_size[node].f++;
	else if (a[node] == 2) subtree_size[node].s++;
	for (auto i : adj[node]) {
		if (i == prev) continue;
		DFS1(i, node);
		subtree_size[node].f += subtree_size[i].f;
		subtree_size[node].s += subtree_size[i].s;
	}
}

inline void DFS2 (int node, int prev) {
	int red = 0, blue = 0;
	for (auto i : adj[node]) {
		if (i == prev) continue;
		DFS2(i, node);
		red = subtree_size[0].f - subtree_size[i].f;
		blue = subtree_size[0].s - subtree_size[i].s;
		if ((!subtree_size[i].f || !subtree_size[i].s) && (!red || !blue)) ++ans;
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=1; i<n; i++) {
		cin >> u >> v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}
	DFS1(0, -1);
	DFS2(0, -1);
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