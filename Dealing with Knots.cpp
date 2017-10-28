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
using namespace std;

int N, a, b, X, Y;
vi adj[MAXN];
bool vis[MAXN];

inline bool DFS (int node, int par) {
	vis[node] = 1;
	if (node == Y) return 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == par) continue;
		if (!vis[next]) 
			if (DFS(next, node)) return 1;
	}
	return 0;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		adj[a].pb(b);
	}
	cin >> X >> Y;
	cout << (DFS(X, -1) ? "Tangled" : "Not Tangled") << "\n";
	return 0;
}