#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define pb push_back
using namespace std;

int N, C, K, a, b, k, sum[MAXN], ans;
int cherries[MAXN];
vector<pii> adj[MAXN];
bool vis[MAXN];

void DFS(int node, int par) {
	if (vis[node]) return;
	vis[node] = 1;
    for (pii &next : adj[node]) {   
    	int currnode = next.f;
    	int currcost = next.s;
    	if (currnode == par) continue;
    	if (!vis[currnode]) {
    		DFS(currnode, node);
        	sum[node] += currcost + sum[currnode];
        	cherries[node] += cherries[currnode];
        	if (sum[currnode] + currcost <= K && cherries[currnode] >= C) ans++; 
        }
    }
}

int main () {
	scanf("%d %d %d", &N, &C, &K);
	for (int i=0; i<N; i++) scanf("%d", &cherries[i]);
	for (int i=0; i<N - 1; i++) {
		scanf("%d %d %d", &a, &b, &k);
		a--; b--;
		adj[a].pb(mp(b, k));
		adj[b].pb(mp(a, k));
	}
	memset(vis, 0, sizeof(vis));
	DFS(0, -1);
	printf("%d\n", ans);
	return 0;
}