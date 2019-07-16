#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 5010
#define MAXN 1010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

struct Edge {
	int u, v, z;
	
	bool operator > (const Edge &a) const {
	    return z < a.z;
	}

	bool operator < (const Edge &a) const {
		return z > a.z;
	}
};

struct Disjoint {
private:
	int N, cnt;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), cnt(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		cnt = N;
		for (int i=0; i<N; i++) {
		  lead[i] = i;
		  rank[i] = 0;
		}
	}

	int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (Merge(x, y)) {
			if (rank[c] > rank[d]) {
				lead[d] = c;
				rank[c] += rank[d];
			}
			else {
				lead[c] = d;
				rank[d] += rank[c];
			}
		}
		--cnt;
	}

	int getCnt () {
		return cnt;
	}
};

Disjoint ds(MAXN);
vector<pii> adj[MAXN];
vector<Edge> edgelist;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
int N, M, Q, op;
bool exists;

inline void Build_MST () {
	ds.make_Set();
	for (Edge &edge : edgelist) pq.push(edge);
	for (int i=0; i<N; i++) adj[i].clear();
	while (!pq.empty()) {
		Edge next = pq.top();
		pq.pop();
		if (ds.Merge(next.u, next.v)) {
			ds.Union(next.u, next.v);
			adj[next.u].pb(mp(next.v, next.z));
			adj[next.v].pb(mp(next.u, next.z));
			if (ds.getCnt() == 1) break;
		}
	}
}

inline bool DFS (int node, int tar, int prev, int val) {
	if (node == tar) {
		exists = 1;
		return 1;
	}
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev || next.s < val) continue;
		exists |= DFS(next.f, tar, node, val);
	}
	return exists;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0, u, v, z; i<M; i++) {
		cin >> u >> v >> z;
		edgelist.pb((Edge) {--u, --v, z});
	}
	Build_MST();
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> op;
		if (op == 1) {
			int m, x;
			cin >> m >> x;
			edgelist[--m].z = x;
			Build_MST();
		}
		else if (op == 2) {
			int a, b, w;
			cin >> a >> b >> w;
			exists = 0;
			cout << DFS(--a, --b, -1, w) << "\n";
		}
	}
	return 0;
}