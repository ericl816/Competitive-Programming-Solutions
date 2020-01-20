#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

int N, M, u, v, B = -1, R = INF, idx;
int low[MAXN], DFN[MAXN], par[MAXN], subtree_size[MAXN];
bool vis[MAXN];
set<int> points;
vi adj[MAXN];

inline void TarjansDFS (int node, int prev) {
	int cnt = 0;
	int maxR = 1;
	int totR = 0;
	bool art_point = 0;
	DFN[node] = low[node] = idx++;
	subtree_size[node] = 1;
	vis[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		if (!vis[next]) {
			cnt++;
			par[next] = node;
			TarjansDFS(next, node);
			subtree_size[node] += subtree_size[next];
			low[node] = min(low[node], low[next]);
			if ((low[next] >= DFN[node] && DFN[node]) || (cnt > 1 && !DFN[node])) {
				points.insert(node + 1);
				art_point = 1;
				maxR = max(maxR, subtree_size[next]);
				totR += subtree_size[next];
			}
		}
		else if (DFN[next] < low[node]) low[node] = min(low[node], DFN[next]);
	}
	if (art_point) {
		maxR = max(maxR, N - totR - 1);
		if (R >= maxR) {
			R = maxR;
			B = node;
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
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> u >> v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<N; i++) if (!vis[i]) TarjansDFS(i, -1);
	if (R == INF) {
		cout << "-1 -1" << "\n";
		return 0;
	}
	cout << B + 1 << " " << R << "\n";
	return 0;
}