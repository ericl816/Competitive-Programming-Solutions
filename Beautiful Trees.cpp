#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// Standard way of finding diameter - DFS/BFS 2 times

int N, a, b, furthest, maxnode, ans;
bool path[MAXN], vis[MAXN];
ll points[MAXN];
vi adj[MAXN];

inline bool isGood (ll y) {
	ll det = 1 + y * 4, sqr = (ll) sqrt(det);
	return sqr * sqr == det;
}

inline void DFS1 (int node, int prev, int depth) {
	if (vis[node]) return;
	vis[node] = 1;
	if (++depth > furthest) {
		furthest = depth;
		maxnode = node;
	}
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS1(next, node, depth);
	}
	vis[node] = 0;
}

inline void DFS2 (int node, int prev, int depth) {
	if (vis[node]) return;
	vis[node] = 1;
	ans = max(ans, ++depth);
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS2(next, node, depth);
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
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> points[i];
		path[i] = isGood(points[i]);
	}
	for (int i=0; i<N - 1; i++) {
		cin >> a >> b;
		if (path[--a] && path[--b]) {
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	for (int i=0; i<N; i++) {
		if (!path[i]) continue;
		DFS1(i, -1, 0);
		DFS2(maxnode, -1, 0);
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