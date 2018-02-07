#include <bits/stdc++.h>
#define ll long long
#define MAXN 50010
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

int N, a, b, c;
int good[MAXN];
mii colours[MAXN];
bool vis[MAXN];
vector<pii> adj[MAXN];
vi nodes;

inline int DFS_Down (int node, int par, int colour) {
	memset(vis, 0, sizeof(vis));
	vis[node] = 1;
	int val = max(0, colours[node][colour] - 1);
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == par) continue;
		if (!vis[next.f]) val += DFS_Down(next.f, node, next.s);
	}
	return val;
}

inline void DFS_Up (int node, int par, int res) {
	memset(vis, 0, sizeof(vis));
	vis[node] = 1;
	good[node] = res;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == par) continue;
		int val = res;
		val += colours[node][next.s] - 1;
		val -= colours[next.f][next.s] - 1;
		if (!vis[next.f])  DFS_Up(next.f, node, val);
	}
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N - 1; i++) {
    	cin >> a >> b >> c;
    	adj[a].pb(mp(b, c));
    	adj[b].pb(mp(a, c));
    	colours[a][c]++;
    	colours[b][c]++;
    }
    DFS_Up(1, -1, DFS_Down(1, -1, -1));
    for (int i=1; i<=N; i++) if (good[i] == 0) nodes.pb(i);
    cout << nodes.size() << endl;
    for (int &next : nodes) cout << next << endl;
    return 0;
}