#include <bits/stdc++.h>
#define ll long long
#define MAXM 110
#define MAXN 10010
#define INF 0x3f3f3f3f
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
	int a, cost;
	bool flag;
};

struct State {
	int timscost, node, currcost;

	bool operator < (const State &a) const {
		return a.currcost < currcost;
	}
};

int N, M, L, T, x, y, z, nextcost;
vector<Edge> adj[MAXN];
bool has[MAXN];
int dist[MAXN][MAXM];
priority_queue<State> pq;

void Dijkstra () {
	pq.push((State) {0, 0, 0});
	memset(dist, -1, sizeof(dist));
	while (!pq.empty()) {
		State curr = pq.top();
		pq.pop();
		for (size_t i=0; i<adj[curr.node].size(); i++) {
			Edge &next = adj[curr.node][i];
			int node = next.a;
			int cost = next.cost;
			nextcost = curr.currcost + cost + T;
			if (has[curr.node] && (dist[node][cost] == -1 || (nextcost < dist[node][cost]))) {
				dist[node][cost] = nextcost;
				pq.push((State) {cost, node, nextcost});
			}
			if (curr.timscost + cost <= L) {
				nextcost = curr.currcost + cost;
				if (dist[node][curr.timscost + cost] == -1 || (nextcost < dist[node][curr.timscost + cost])) {
					dist[node][curr.timscost + cost] = nextcost;
					pq.push((State) {curr.timscost + cost, node, nextcost});
				}
			}
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> L >> T;
	for (int i=0, x; i<N; i++) {
		cin >> x;
		has[i] = x;
	}
	for (int i=0; i<M; i++) {
		cin >> x >> y >> z;
		x--; y--;
		adj[x].pb((Edge) {y, z, (has[x])});
		adj[y].pb((Edge) {x, z, (has[y])});
	}
	Dijkstra();
	int ans = -1;
	for (int i=0; i<=L; i++) {
		if (ans == -1) ans = dist[N - 1][i];
		else if (~dist[N - 1][i]) ans = min(ans, dist[N - 1][i]);
	}
	cout << ans << endl;
	return 0;	
}