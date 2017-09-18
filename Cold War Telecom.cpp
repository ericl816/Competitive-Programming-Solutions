#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define si set<int>
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M, x, y, idx, DFN[MAXN], low[MAXN];
vi adj[MAXN];
si crucial;
bool vis[MAXN];

void TarjansDFS(int node, int prev) {
	int cnt = 0; //Stores the number of times the DFS was run
	DFN[node] = low[node] = idx++;
	vis[node] = 1;
	for (int &next : adj[node]) {
	    if (next == prev) continue;
		if (!vis[next]) {
		    cnt++;
		    TarjansDFS(next, node);
		    low[node] = min(low[node], low[next]);
		    //It is an articulation point (if low[next] >= DFN[node] (no path from next to node) && DFN[node] > 0) || (if the DFS was run more than once && DFN[node] == 0)
		    if ((DFN[node] <= low[next] && DFN[node]) || (cnt > 1 && !DFN[node])) crucial.insert(node + 1);
		}
		else if (DFN[next] < low[node]) low[node] = DFN[next];
	}
}

int main () {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &x, &y);
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<N; i++) if (!vis[i]) TarjansDFS(i, -1);
	printf("%d\n", crucial.size());
	for (int nodes : crucial) printf("%d\n", nodes);
	return 0;
}
