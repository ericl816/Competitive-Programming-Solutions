#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll long long
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;

struct Edge {
	int a, b, dist;
};

int N, M, A, B, L, dist, length1[MAXN], length2[MAXN], ans = INF;
vector<pii> adj1[MAXN], adj2[MAXN];
vector<Edge> vec;
queue<int> q;
bool vis[MAXN];

void ShortestPath (int src, vector<pii> adj[MAXN], int dist[]) {
	q.push(src);
	dist[src] = 0;
	vis[0] = 1;
	while(!q.empty()) {
		int curr = q.front(); q.pop();
		vis[curr] = 0;
		for (pii next : adj[curr]) {
			int node = next.first;
			int cost = next.second;
			int nextcost = dist[curr] + cost;
			if (dist[node] > nextcost) {
				dist[node] = nextcost;
				if (!vis[node]) {
					vis[node] = 1;
					q.push(node);
				}
			}
		}
	}
}

int main () {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &A, &B, &L);
		A--; B--;
		adj1[A].pb(mp(B, L));
		adj2[B].pb(mp(A, L));
		vec.pb((Edge) {A, B, L});
	}
	memset(length1, INF, sizeof(length1));
	memset(length2, INF, sizeof(length2));
	ShortestPath(0, adj1, length1);
	ShortestPath(N - 1, adj2, length2);
	for (Edge next : vec) {
 		dist = length1[next.a] + length2[next.b] + next.dist;
 		if (ans > dist && length1[N - 1] < dist) ans = dist;
	}
	return 0 * printf("%d\n", (ans ^ INF) ? ans : -1);
}