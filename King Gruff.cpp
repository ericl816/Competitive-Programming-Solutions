#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

struct Edge {
	int node, dist, cost;
	
	bool operator < (const Edge &e) const {
	  return e.dist < dist;
	}
};

int N, M, A, B, X, Y, L, C, Q, D, lo, hi, idx;
int dist1[MAXN], dist2[MAXN];
bool vis[MAXN];
vector<Edge> adj1[MAXN], adj2[MAXN];
vector<pii> vec;
queue<int> q;

inline void ShortestPath (int src, vector<Edge> adj[], int dist[]) {
	memset(vis, 0, sizeof(vis));
	q.push(src);
	dist[src] = 0;
	vis[src] = 1;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		vis[curr] = 0;
		for (Edge &next : adj[curr]) {
			int nextcost = next.dist + dist[curr];
			if (nextcost < dist[next.node]) {
				dist[next.node] = nextcost;
				if (!vis[next.node]) {
					vis[next.node] = 1;
					q.push(next.node);
			  }
			}
		}
	}
}

int main () {
	scan(N); scan(M); scan(A); scan(B);
	for (size_t i=0; i<M; i++) {
	  scan(X); scan(Y); scan(L); scan(C);
		X--; Y--;
		adj1[X].pb((Edge) {Y, L, C});
		adj2[Y].pb((Edge) {X, L, C});
	}
	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));
	ShortestPath(A - 1, adj1, dist1);
	ShortestPath(B - 1, adj2, dist2);
	for (size_t i=0; i<N; i++) for (Edge &next : adj1[i]) vec.pb(mp(dist1[i] + dist2[next.node] + next.dist, next.cost));
	sort(vec.begin(), vec.end());
	for (size_t i=1; i<vec.size(); i++) vec[i].s += vec[i - 1].s;
	scan(Q);
	for (int i=0; i<Q; i++) {
		scan(D);
		idx = upper_bound(vec.begin(), vec.end(), mp(D, INF)) - vec.begin();
		printf("%d\n", idx ? vec[idx - 1].s : 0);
	}
	return 0;
}