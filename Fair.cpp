#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 110
#define MAXN 100010
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

int n, m, k, s, u, v;
vector<vi> a;
int dist[MAXN][MAXM];
vi adj[MAXN];
bool vis[MAXN];
queue<int> q;

// We run BFS after rebuilding the graph
inline void BFS (int node) {
	for (int i=1; i<=n; i++) {
		dist[i][node] = INF;
		vis[i] = 0;
	}
	for (auto i : a[node]) {
		vis[i] = 1;
		dist[i][node] = 0;
		q.push(i);
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int &next : adj[curr]) {
			if (!vis[next]) {
				vis[next] = 1;
				if (dist[next][node] > dist[curr][node] + 1) {
					dist[next][node] = dist[curr][node] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> s;
	a = vector<vi>(n + 1);
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[x].pb(i);
	}
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// memset(dist, INF, sizeof(dist));
	// Have to BFS k times
	for (int i=1; i<=k; i++) {
		BFS(i);
	}
	for (int i=1; i<=n; i++) {
		ll sum = 0;
		sort(dist[i] + 1, dist[i] + k + 1);
		for (int j=1; j<=s; j++) sum += dist[i][j];
		cout << sum << " ";
	}
	return 0;
}