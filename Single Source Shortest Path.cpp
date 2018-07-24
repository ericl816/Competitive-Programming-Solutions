#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
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
int N, M, u, v, w, dist[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Dijkstras () {
	memset(dist, INF, sizeof(dist));
	pq.push(mp(0, 0));
	dist[0] = 0;
	while (!pq.empty()) {
		pii curr = pq.top();
		pq.pop();
		if (curr.f > dist[curr.s]) continue;
		for (size_t i=0; i<adj[curr.s].size(); i++) {
			pii &next = adj[curr.s][i];
			if (dist[next.f] > dist[curr.s] + next.s) {
				dist[next.f] = dist[curr.s] + next.s;
				pq.push(mp(dist[next.f], next.f));
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
	SSSP();
	for (int i=0; i<N; i++) {
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}