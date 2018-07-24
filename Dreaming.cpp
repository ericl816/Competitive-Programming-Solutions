#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

/*
 * The solution involves computing the furthest distance from one node to any other node in the tree (also known as eccentricity)
 * After we must find the radius and we then connect the radii together, to minimize the max. eccentricity
 * To do this, we must sort the trees by decreasing order first
 * If there are 2 trees, the answer should be: tree 1 radius + tree 2 radius + value of L
 * If there are 3 trees, the answer should be: tree 2 radius + tree 3 radius + 2 * value of L
 * Here, radius = smallest eccentricity of a node (min. of the max. distance between node v to any other node)
 * Centre of a tree is when the eccentricity equals the radius
 */

int N, M, L, a, b, t, furthest, maxnode;
int ans, length = -1, maxdist = -1, radius;
vi radii;
int dist[MAXN], x[MAXN], y[MAXN], z[MAXN], len[MAXN];
bool vis[MAXN];
vector<pii> adj[MAXN];

inline void BFS1 (int src) {
	queue<int> q;
	// memset(dist, INF, sizeof(dist));
	// memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	dist[src] = 0;
	q.push(src);
	length = 0;
	furthest = src;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int nextcost = dist[curr] + next.s;
			if (!vis[next.f]) {
				vis[next.f] = 1;
				dist[next.f] = nextcost;
				if (dist[next.f] > length) {
					length = dist[next.f];
					furthest = next.f;
				}
				q.push(next.f);
			}
		}
	}
}

inline void BFS2 (int src) {
	queue<pii> q;
	// memset(dist, INF, sizeof(dist));
	// memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	q.push(mp(src, -1));
	maxdist = 0;
	maxnode = src;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr.f].size(); i++) {
			pii &next = adj[curr.f][i];
			if (next.f == curr.s) continue;
			int nextcost = dist[curr.f] + next.s;
			dist[next.f] = nextcost;
			if (dist[next.f] > maxdist) {
				maxdist = dist[next.f];
				maxnode = next.f;
			}
			q.push(mp(next.f, curr.f));
		}
	}
}

inline bool get_Radius (int src, int prev, int dest) {
	if (src == dest) {
		radius = min(radius, maxdist);
		len[src] = 0;
		return 1;
	}
	for (size_t i=0; i<adj[src].size(); i++) {
		pii &next = adj[src][i];
		if (next.f == prev) continue;
		if (get_Radius(next.f, src, dest)) {
			len[src] = len[next.f] + next.s;
			radius = min(radius, max(len[src], maxdist - len[src]));
			return 1;
		}
	}
	return 0;
}

int travelTime (int N, int M, int L, int A[], int B[], int T[]) {
	for (int i=0; i<M; i++) {
		adj[A[i]].pb(mp(B[i], T[i]));
		adj[B[i]].pb(mp(A[i], T[i]));
	}
	// Get the distance between node v and every other node in the tree
	for (int i=0; i<N; i++) {
		if (!vis[i]) {
			radius = INF;
			BFS1(i);
			BFS2(furthest);
			get_Radius(furthest, -1, maxnode);
			ans = max(ans, maxdist);
			radii.pb(radius);
		}
	}
	sort(radii.begin(), radii.end(), greater<int>());
	if (radii.size() >= 2) ans = max(ans, radii[0] + radii[1] + L);
	if (radii.size() >= 3) ans = max(ans, radii[1] + radii[2] + (L << 1));
	return ans;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> L;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> t;
		x[i] = a; y[i] = b; z[i] = t;
	}
	cout << travelTime(N, M, L, x, y, z) << endl;
	return 0;
}