#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
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

int n, r, v, w, idx, ans;
int DFN[MAXN], low[MAXN], cnt[MAXN];
vi adj[MAXN];
mii par;

void TarjansDFS (int node, int prev) {
	low[node] = DFN[node] = idx++;
	for (int &next : adj[node]) {
		if (next == prev) continue;
		if (!DFN[next]) {
			par[next] = node;
			TarjansDFS(next, node);
			low[node] = min(low[node], low[next]);
		}
		else if (next ^ par[node]) low[node] = min(low[node], DFN[next]);
	}
}

int main () {
	scanf("%d %d", &n, &r);
	for (int i=0; i<r; i++) {
		scanf("%d %d", &v, &w);
		adj[v].pb(w);
		adj[w].pb(v);
	}
	TarjansDFS(1, -1);
	for (int i=1; i<=n; i++) for (int &next : adj[i]) if (low[i] ^ low[next]) cnt[low[i]]++;
	for (int i=1; i<=n; i++) if (cnt[i] == 1) ans++;
	// ans = number of leaves in the tree
	return 0 * printf("%d\n", (ans + 1) >> 1);
}