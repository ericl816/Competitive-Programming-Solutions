#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
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

int N, x, y, node = -1, ans;
int dist[MAXN];
vi adj[MAXN];

void CalcDist (int node, int par, int val) {
	dist[node] = val;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == par) continue;
		CalcDist(next, node, val + 1);
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N - 1; i++) {
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	CalcDist(0, -1, 0);
	for (int i=0; i<N; i++) if (node == -1 || (dist[node] < dist[i])) node = i;
	CalcDist(node, -1, 0);
	for (int i=0; i<N; i++) ans = max(ans, dist[i]);
	cout << ans << endl;
	return 0;
}