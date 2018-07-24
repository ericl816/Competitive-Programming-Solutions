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

int n, u, v, ans;
int subtree_size[MAXN];
vi adj[MAXN];
vi conn;
bool vis[MAXN];

inline void DFS (int node, int par) {
	if (vis[node]) return;
	vis[node] = 1;
	conn.pb(node);
	subtree_size[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == par) continue;
		DFS(next, node);
		subtree_size[node] += subtree_size[next];
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
	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DFS(1, -1);
	if (n & 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i=1; i<=n; i++) if (i ^ 1 && !(subtree_size[i] & 1)) ans++;
	cout << ans << endl;
	return 0;
}