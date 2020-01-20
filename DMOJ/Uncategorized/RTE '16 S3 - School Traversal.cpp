#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 6010
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, a, b, w, Q, u, v, chainNum, idx;
int par[MAXN], subtree_size[MAXN], head[MAXN], chain[MAXN], vert[MAXN], weight[MAXN], ind[MAXN];
ll depth[MAXN];
vector<pii> adj[MAXN];

inline void DFS (int node, int prev, ll val) {
    depth[node] = val;
    par[node] = prev;
    subtree_size[node] = 1;
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        weight[next.f] = next.s;
        DFS(next.f, node, val + next.s);
        subtree_size[node] += subtree_size[next.f];
    }
}

inline void HLD (int node, int prev) {
    if (head[chainNum] == -1) head[chainNum] = node;
    chain[node] = chainNum;
    ind[node] = idx;
    vert[idx++] = node;
    int maxidx = -1;
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        if (maxidx == -1 || subtree_size[maxidx] < subtree_size[next.f]) maxidx = next.f;
    }
    if (~maxidx) HLD(maxidx, node);
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev || next.f == maxidx) continue;
        chainNum++;
        HLD(next.f, node);
    }
}

inline void InitHLD () {
    chainNum = 0;
    idx = 1;
    memset(head, -1, sizeof(head));
    DFS(1, -1, 0);
    HLD(1, -1);
}

inline int LCA (int x, int y) {
    while (chain[x] ^ chain[y]) {
        if (depth[head[chain[x]]] < depth[head[chain[y]]]) y = par[head[chain[y]]];
        else x = par[head[chain[x]]];
    }
    return depth[x] < depth[y] ? x : y;
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
	memset(par, -1, sizeof(par));
	for (int i=1; i<N; i++) {
		cin >> a >> b >> w;
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
	}
	InitHLD();
	cin >> Q;
	while (Q--) {
		cin >> u >> v;
		cout << depth[u] + depth[v] - (depth[LCA(u, v)] << 1) << "\n";
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