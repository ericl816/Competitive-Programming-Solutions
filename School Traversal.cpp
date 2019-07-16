#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 6010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define piui pair<int, unsigned int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

// Solution uses as simple DFS; Complexity: O(N ^ 2) - Simple, but works

int N, a, b, Q, u, v, src;
unsigned int w, dist[MAXN][MAXN];
vector<piui> adj[MAXN];
bool vis[MAXN];

void DFS (int node, int par, unsigned int val) {
	dist[src][node] = val;
	for (unsigned int i=0; i<adj[node].size(); i++) {
		piui &next = adj[node][i];
		int nextnode = next.f;
		unsigned int cost = next.s;
		if (nextnode == par) continue;
		DFS(nextnode, node, cost + val);
	}
}

int main () {
	scan(N);
	for (int i=0; i<N - 1; i++) {
		scan(a); scan(b); scan(w);
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
	}
	for (int i=0; i<N; i++) src = i, DFS(src, -1, (unsigned) 0); // O(N ^ 2) Preprocessing
	scan(Q);
	for (int i=0; i<Q; i++) {
		scan(u); scan(v);
		printf("%u\n", dist[u][v]);
	}
	return 0;
}