#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 5010
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

int N, S, u, v, cnt, center;
int subtree_size[MAXN], par[MAXN], depth[MAXN];
ll ans;
vi adj[MAXN];
vector<pii> nodes;
bool is_centroid[MAXN], vis1[MAXN], vis2[MAXN];

inline bool Cmp (pii &a, pii &b) {
	return a.s > b.s;
}

inline void DFS (int node, int height) {
	// depth[node] = height++;
	nodes[node].s = height++;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next ^ par[node]) {
			par[next] = node;
			DFS(next, height);
		}
	}
}

inline void Mark_Nodes (int node, int targ) {
	if (targ == -1) return;
	vis1[node] = 1;
	vis2[node] = 1;
	for (int i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (!vis1[next]) Mark_Nodes(next, targ - 1);
	}
}

inline int Get_Center (int node, int targ) {
	return targ == 0 ? node : Get_Center(par[node], targ - 1);
}

inline int Check (int targ) {
	memset(vis2, 0, sizeof(vis2));
	cnt = 0, center = 0;
	for (int i=0; i<N; i++) {
		if (!vis2[nodes[i].f]) {
			memset(vis1, 0, sizeof(vis1));
			center = Get_Center(nodes[i].f, targ);
			Mark_Nodes(center, targ);
			cnt++;
		}
	}
	return cnt;
}

int main () {
	scan(N); scan(S);
	for (int i=0; i<N; i++) nodes.pb(mp(i, 0));
	for (int i=1; i<N; i++) {
		scan(u); scan(v);
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DFS(0, -1);
	sort(nodes.begin(), nodes.end(), Cmp);
	int lo = 0, hi = MAXN;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (Check(mid) <= S) hi = mid - 1;
		else lo = mid + 1;
	}
    return !printf("%d\n", lo);
}