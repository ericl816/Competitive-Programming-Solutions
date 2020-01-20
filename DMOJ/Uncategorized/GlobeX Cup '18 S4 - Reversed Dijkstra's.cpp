#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1 << 19
#define MAXN 19
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N, M, A, B, V, a, b, minn = INF, ans = INF;
vi adj[MAXN];
bool vis[MAXN][MAXM];

inline void DFS (int node, int prev, int mask, int len) {
	if (vis[node][mask] || !minn) return;
	vis[node][mask] = 1;
	if (node == B) {
		int val = abs(V - len);
		if (val < minn) {
			minn = val;
			ans = len;
		}
		else if (val == minn) ans = min(ans, len);
		return;
	}
	for (auto i : adj[node]) {
	    int res = 1 << i;
		if (!(mask & res)) DFS(i, node, mask | res, len + 1);
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
	scan(N); scan(M); scan(A); scan(B); scan(V);
	while (M--) {
	    scan(a); scan(b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	DFS(A, -1, 1 << A, 0);
	return !printf("%d\n", ans);
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */