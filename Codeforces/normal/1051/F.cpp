#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 18
#define MAXN 100010
#define MAXQ 40
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

// https://codeforces.com/contest/1051/problem/F

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=1; i<=N; i++) {
			lead[i] = i;
			rank[i] = 1;
		}
	}
	
	inline int Find (int x) {
		while (x ^ lead[x]) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	inline bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	inline void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (Merge(x, y)) {
			if (rank[c] > rank[d]) {
				rank[c] += rank[d];
				lead[d] = c;
			}
			else {
				rank[d] += rank[c];
				lead[c] = d;
			}
		}
	}

	inline int Cnt (int x) {
		return rank[x];
	}
};

Disjoint ds(MAXN);

int N, M, Q, a, b, w, s, e, ind, idx;
int depth[MAXN], par[MAXN], nodes[MAXN];
ll dist[MAXN];
ll cost[MAXQ][MAXN];
int anc[MAXM][MAXN];
bool vis[MAXN], flag[MAXN], processed[MAXN];
vector<pii> adj[MAXN];
vector<pair<int, pii> > edgelist;
queue<int> q;
priority_queue<pii, vector<pii>, greater<pii> > pq;

inline void DFS (int node, int prev, ll weight) {
	depth[node] = prev >= 0 ? depth[prev] + 1 : 0;
	par[node] = prev;
	dist[node] = weight;
	vis[node] = 1;
	for (auto i : adj[node]) {
	    if (!vis[i.f]) DFS(i.f, node, weight + i.s);
	}
}

inline void Build_Sparse_Table () {
	memcpy(anc[0], par, sizeof(par));
	for (int i=1; i<MAXM; i++) {
		for (int j=0; j<N; j++) {
			anc[i][j] = anc[i - 1][j] >= 0 ? anc[i - 1][anc[i - 1][j]] : -1;
		}
	}
}

inline int LCA (int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	int diff = depth[x] - depth[y];
	for (int i=0; i<MAXM; i++) {
		if (diff >> i & 1) x = anc[i][x];
	}
	if (x == y) return x;
	for (int i=MAXM - 1; i>=0; i--) {
		if (anc[i][x] ^ anc[i][y]) {
			x = anc[i][x];
			y = anc[i][y];
		}
	}
	return par[x];
}

inline void Dijkstra (int src) {
	int idx = nodes[src];
	cost[idx][src] = 0LL;
	pq.push(mp(0, src));
	while (!pq.empty()) {
		pii curr = pq.top(); pq.pop();
		if (curr.f > cost[idx][curr.s]) continue;
		for (auto i : adj[curr.s]) {
			if (cost[idx][i.f] > cost[idx][curr.s] + i.s) {
				cost[idx][i.f] = cost[idx][curr.s] + i.s;
				pq.push(mp(cost[idx][i.f], i.f));
			}
		}
	}
}

inline void SPFA (int src) {
	int idx = nodes[src];
	cost[idx][src] = 0LL;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		flag[curr] = 0;
		for (auto i : adj[curr]) {
			if (cost[idx][i.f] > cost[idx][curr] + i.s) {
				cost[idx][i.f] = cost[idx][curr] + i.s;
				if (!flag[i.f]) {
					flag[i.f] = 1;
					q.push(i.f);
				}
			}
		}
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
	cin >> N >> M;
	for (int i=1; i<=M; i++) {
		cin >> a >> b >> w;
		edgelist.pb(mp(--a, mp(--b, w)));
	}
	ds.make_Set();
	for (size_t i=0; i<edgelist.size(); i++) {
		pair<int, pii> &next = edgelist[i];
		if (ds.Merge(next.f, next.s.f)) {
			ds.Union(next.f, next.s.f);
			processed[i] = 1;
			adj[next.f].pb(mp(next.s.f, next.s.s));
			adj[next.s.f].pb(mp(next.f, next.s.s));
		}
	}
	DFS(0, -1, 0LL);
	Build_Sparse_Table();
	memset(cost, INF, sizeof(cost));
	for (size_t i=0; i<edgelist.size(); i++) {
		pair<int, pii> &next = edgelist[i];
		if (processed[i]) continue;
		adj[next.f].pb(mp(next.s.f, next.s.s));
		adj[next.s.f].pb(mp(next.f, next.s.s));
	}
	memset(processed, 0, sizeof(processed));
	for (size_t i=0; i<edgelist.size(); i++) {
		pair<int, pii> &next = edgelist[i];
		if (!nodes[next.f]) nodes[next.f] = ind++;
		if (!processed[next.f]) {
			processed[next.f] = 1;
			Dijkstra(next.f);
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> s >> e;
		ll ans = dist[--s] + dist[--e] - (dist[LCA(s, e)] << 1);
		for (int i=0; i<ind; i++) ans = min(ans, cost[i][s] + cost[i][e]);
		cout << ans << "\n";
	}
    return 0;
}

/*
5 4
1 2 1
1 3 1
2 4 1
2 5 1
3
1 2
4 3
4 5

Ans:
1
3
2

8 13
1 2 4
2 3 6
3 4 1
4 5 12
5 6 3
6 7 8
7 8 7
1 4 1
1 8 3
2 6 9
2 7 1
4 6 3
6 8 2
8
1 5
1 7
2 3
2 8
3 7
3 4
6 8
7 8

Ans:
7
5
6
7
7
1
2
7
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */