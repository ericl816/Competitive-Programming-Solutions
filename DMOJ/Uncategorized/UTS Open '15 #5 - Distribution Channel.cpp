#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 50010
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

struct Node {
    int l, r, val;
};

struct Edge {
	int a, b, c;
	bool operator < (const Edge &a) const {
		return c < a.c;
	}
};

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
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
		int a = Find(x);
		int b = Find(y);
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
} ds(MAXM);

int depth[MAXM], par[MAXM], subtree_size[MAXM], head[MAXM], chain[MAXM], vert[MAXM], weight[MAXM], ind[MAXM], arr[MAXM];
int idx, chainNum;
int N, M, a, b, c;
ll cheapest = INF, heaviestedge, totalcost;
vector<Edge> edgelist, unused;
vector<pii> MST[MAXN];
pair<ll, ll> segmax[MAXN << 1];

inline pair<ll, ll> maxPair (const pair<ll, ll> &a, const pair<ll, ll> &b) {
    ll c[4] = {a.f, a.s, b.f, b.s};
    sort(c, c + 4);
    pair<ll, ll> res = mp(c[2], c[3]);
    return res;
}

inline void maxsegUpdate (int idx, int val) {
    idx += N - 1;
    segmax[idx] = mp(val, -INF);
    for (int i=idx >> 1; i; i >>= 1) segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
}

inline pair<ll, ll> maxsegQuery (int l, int r, int idx = 1) {
    l += N - 1;
    r += N - 1;
    pair<ll, ll> maxans = mp(-INF, -INF);
    while (l <= r) {
        if (l & 1) {
            maxans = maxPair(maxans, segmax[l]);
            l++;
        }
        if (!(r & 1)) {
            maxans = maxPair(maxans, segmax[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return maxans;
}

inline void DFS (int node, int prev, int val) {
    depth[node] = val;
    par[node] = prev;
    subtree_size[node] = 1;
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
        if (next.f == prev) continue;
        weight[next.f] = next.s;
        DFS(next.f, node, val + 1);
        subtree_size[node] += subtree_size[next.f];
    }
}

inline void HLD (int node, int prev) {
    if (head[chainNum] == -1) head[chainNum] = node;
    chain[node] = chainNum;
    ind[node] = idx;
    vert[idx++] = node;
    int maxidx = -1;
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
        if (next.f == prev) continue;
        if (maxidx == -1 || subtree_size[maxidx] < subtree_size[next.f]) maxidx = next.f;
    }
    if (~maxidx) HLD(maxidx, node);
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
        if (next.f == prev || next.f == maxidx) continue;
        chainNum++;
        HLD(next.f, node);
    }
}
    
inline void InitHLD () {
    chainNum = 0;
    idx = 1;
    memset(head, -1, sizeof(head));
    DFS(0, -1, 0);
    HLD(0, -1);
    for (int i=1; i<=N; i++) segmax[i + N - 1] = mp(weight[vert[i]], -INF);
    for (int i=N - 1; i>0; i--) segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
}

inline int LCA (int x, int y) {
    while (chain[x] ^ chain[y]) {
        if (depth[head[chain[x]]] < depth[head[chain[y]]]) y = par[head[chain[y]]];
        else x = par[head[chain[x]]];
    }
    return depth[x] < depth[y] ? x : y;
}

inline void HLD_Update (int x, int y, int val) {
    if (par[x] == y) maxsegUpdate(ind[x], val);
    else if (par[y] == x) maxsegUpdate(ind[y], val);
    else assert(0);
}

inline pair<ll, ll> HLD_Query (int x, int y) {
    pair<ll, ll> maxedge = pair<ll, ll>(-INF, -INF);
    while (chain[x] ^ chain[y]) {
        maxedge = maxPair(maxedge, maxsegQuery(ind[head[chain[x]]], ind[x]));
        x = par[head[chain[x]]];
    }
    if (x == y) return maxedge;
    maxedge = maxPair(maxedge, maxsegQuery(ind[y] + 1, ind[x]));
    return maxedge;
}

inline pair<ll, ll> Query_Path (int x, int y) {
    int lca = LCA(x, y);
    return maxPair(HLD_Query(x, lca), HLD_Query(y, lca));
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
	ds.make_Set();
	if (M < N - 1) {
		cout << -1 << "\n";
		return 0;
	}
	for (int i=0; i<M; i++) {
		cin >> a >> b >> c;
		edgelist.pb((Edge) {--a, --b, c});
	}
	sort(edgelist.begin(), edgelist.end());
	for (size_t i=0; i<edgelist.size(); i++) {
		Edge &next = edgelist[i];
		if (ds.Merge(next.a, next.b)) {
			ds.Union(next.a, next.b);
			MST[next.a].pb(mp(next.b, next.c));
			MST[next.b].pb(mp(next.a, next.c));
			totalcost += next.c;
		}
		else unused.pb(next);
	}
	if (unused.empty()) {
		cout << -1 << "\n";
		return 0;
	}
	InitHLD();
	for (size_t i=0; i<unused.size(); i++) {
		Edge &next = unused[i];
        pair<ll, ll> ans = Query_Path(next.a, next.b);
        if ((int) ans.f ^ next.c) heaviestedge = ans.f;
        else if ((int) ans.s ^ -INF && (int) ans.s ^ next.c) heaviestedge = ans.s;
		if (heaviestedge == next.c) continue;
		cheapest = min(cheapest, totalcost + next.c - heaviestedge);
	}
	cout << (cheapest == INF ? -1 : cheapest) << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */

/*
3 3 
1 2 2
2 3 3
1 3 3
ans = 6, not -1
*/