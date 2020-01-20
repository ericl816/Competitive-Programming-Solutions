#include <bits/stdc++.h>
#define ll long long
#define MAXN 20010
#define MAXM 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int ,int>
#define umii unordered_map<int, int>
using namespace std;

struct Edge {
	int a, b, dist;
};

int N, M, A, B, L, ans = INF;
vector<Edge> vec;
vector<pii> adj1[MAXN];
queue<int> q;
bool vis[MAXN];
int length1[MAXN], length2[MAXN];

inline void SSSP (int src, int dist[], vector<pii> adj[]) {
	memset(vis, 0, sizeof(vis));
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int node = next.f;
			int cost = next.s;
			int nextcost = dist[curr] + cost;
			if (nextcost < dist[node]) {
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> L;
		A--; B--;
		adj1[A].pb(mp(B, L));
		adj1[B].pb(mp(A, L));
		vec.pb((Edge) {A, B, L});
		vec.pb((Edge) {B, A, L});
	}
	memset(length1, INF, sizeof(length1));
	memset(length2, INF, sizeof(length2));
	SSSP(0, length1, adj1);
	SSSP(N - 1, length2, adj1);
	for (size_t i=0; i<vec.size(); i++) {
		Edge &next = vec[i];
		int length = length1[next.a] + length2[next.b] + next.dist;
		if (ans > length && length1[N - 1] < length) ans = length;
	}
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}