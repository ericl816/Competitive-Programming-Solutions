#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

/* A small modification to Dijkstra's shortest path algorithm allows us to find roads that are part of shortest paths from a source city
   - to(v) = the number of paths from city C to city v
   - from(v) = the number of paths from city v to any other city
*/

struct State {
  int f, s;
  bool operator < (const State &e) const {
    return s > e.s;
  }
};

struct Edge {
	int idx, f, s;
	bool operator < (const Edge &e) const {
		return s > e.s;
	}
};

int N, M, O, D, L, from[MAXN], to[MAXN], dist[MAXN], num[MAXN];
ll len[MAXN];
vector<Edge> adj[MAXN];
bool vis[MAXN], vis1[MAXN];
priority_queue<State> pq;
stack<int> st;

void SSSP (int src) {
	memset(dist, INF, sizeof(dist));
	memset(from, 0, sizeof(from));
	memset(to, 0, sizeof(to));
	dist[src] = 0;
	to[src] = 1;
	pq.push((State) {src, 0});
	while (!pq.empty()) {
		State curr = pq.top();
		pq.pop();
		int node = curr.f;
		int cost = curr.s;
		if (dist[node] < cost) continue;
		st.push(node);
		for (size_t i=0; i<adj[node].size(); i++) {
			Edge &next = adj[node][i];
			int curridx = next.idx;
			int currnode = next.f;
			int currcost = next.s;
			int nextcost = dist[node] + currcost;
			if (dist[currnode] < nextcost) continue;
			if (nextcost < dist[currnode]) {
				dist[currnode] = nextcost;
				to[currnode] = 0;
				pq.push((State) {currnode, dist[currnode]});
			}
			to[currnode] = (to[currnode] + to[node]) % MOD;
		}
	}
	while (!st.empty()) {
		int curr = st.top();
		st.pop();
		from[curr] = 1;
		for (size_t i=0; i<adj[curr].size(); i++) {
			Edge &next = adj[curr][i];
			int curridx = next.idx;
			int currnode = next.f;
			int currcost = next.s;
			int nextcost = dist[curr] + currcost;
			if (dist[currnode] < nextcost) continue;
			from[curr] = (from[curr] + from[currnode]) % MOD;
			len[currnode] = (ll) ((ll) from[currnode] * (ll) to[curr]) % MOD;
			num[curridx] = (int) (num[curridx] + len[currnode]) % MOD;
		}
	}
}

inline void Solve () {
	for (int i=0; i<M; i++) printf("%d\n", (num[i] + MOD) % MOD);
}

int main () {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &O, &D, &L);
		O--; D--;
		adj[O].pb((Edge) {i, D, L});
	}
	for (int i=0; i<N; i++) SSSP(i);
	Solve();
	return 0;
}