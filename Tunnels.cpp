#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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

int N, T, A, B, C, sum;
vector<pii> adj[MAXN];
int dist[MAXN][4];
bool vis[MAXN];

inline void DFS1 (int node, int prev, int weight, int idx) {
	if (vis[node]) return;
	vis[node] = 1;
	dist[node][idx] = weight;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev) continue;
		DFS1(next.f, node, weight + next.s, idx);
	}
}

inline int DFS2 (int idx) {
	int maxnode = 0;
	for (int i=1; i<=N; i++) {
		if (dist[i][idx] > dist[maxnode][idx]) maxnode = i;
	}
	return maxnode;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for (int i=1; i<N; i++) {
		cin >> A >> B >> C;
		adj[A].pb(mp(B, C));
		adj[B].pb(mp(A, C));
		sum += C;
	}
	DFS1(1, -1, 0, 0);
	memset(vis, 0, sizeof(vis));
	DFS1(DFS2(0), -1, 0, 1);
	memset(vis, 0, sizeof(vis));
	DFS1(DFS2(1), -1, 0, 2);
	for (int i=1; i<=N; i++) {
		if (adj[i].size() == T) cout << i << " " << ((sum << 1) - max(dist[i][1], dist[i][2])) << "\n";
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