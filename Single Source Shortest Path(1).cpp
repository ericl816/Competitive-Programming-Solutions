#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

int N, M, u, v, w;
int dist[MAXN];
vector<pii> adj[MAXN];
queue<int> q;
bool vis[MAXN];

void SSSP (int src) {
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	vis[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int nextcost = dist[curr] + next.s;
			if (nextcost < dist[next.f]) {
				dist[next.f] = nextcost;
				if (!vis[next.f]) {
					vis[next.f] = 1;
					q.push(next.f);
				}
			}
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> u >> v >> w;
		u--; v--;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	SSSP(0);
	for (int i=0; i<N; i++) {
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}