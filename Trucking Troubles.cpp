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

struct Edge {
	int a, b, c;

	bool operator < (const Edge &e) const {
		return c > e.c;
	}

	bool operator > (const Edge &e) const {
		return c < e.c;
	}
};

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=0; i<N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}

	inline int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	inline bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	inline void Union (int x, int y) {
		int a = Find(x), b = Find(y);
		if (Merge(x, y)) {
			if (rank[a] > rank[b]) {
				lead[b] = a;
				rank[a] += rank[b];
			}
			else {
				lead[a] = b;
				rank[b] += rank[a];
			}
		}
	}
};

Disjoint ds(MAXN);
int c, r, d, x, y, w, ans = INF;
vector<pii> adj[MAXN];
vector<Edge> edgelist;
priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
int weight[MAXN];
bool vis[MAXN];

inline void DFS (int node, int prev, int cost) {
	if (vis[node]) return;
	vis[node] = 1;
	weight[node] = cost;
	for (auto i : adj[node]) {
		if (i.f == prev) continue;
		DFS(i.f, node, min(cost, i.s));
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
	cin >> c >> r >> d;
	while (r--) {
		cin >> x >> y >> w;
		edgelist.pb((Edge) {x, y, w});
	}
	for (auto i : edgelist) pq.push(i);
	ds.make_Set();
	while (!pq.empty()) {
		Edge curr = pq.top();
		pq.pop();
		if (ds.Merge(curr.a, curr.b)) {
			ds.Union(curr.a, curr.b);
			adj[curr.a].pb(mp(curr.b, curr.c));
			adj[curr.b].pb(mp(curr.a, curr.c));
		}
	}
	DFS(1, -1, INF);
	while (d--) {
		int x;
		cin >> x;
		ans = min(ans, weight[x]);
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