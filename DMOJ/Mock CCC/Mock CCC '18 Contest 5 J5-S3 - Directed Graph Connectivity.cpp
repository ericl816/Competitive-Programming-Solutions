#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 100010
#define MAXN 105
#define MOD 1000000007
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

int N, M;
bool flag[MAXM], vis[MAXN];
pii flights[MAXM];
vi adj[MAXN];

inline void DFS (int node, int prev) {
	if (vis[node]) return;
	vis[node] = 1;
	for (auto i : adj[node]) {
		if (!vis[flights[i].s] && !flag[i]) DFS(flights[i].s, node);
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> flights[i].f >> flights[i].s;
		adj[flights[i].f].pb(i);
	}
	for (int i=0; i<M; i++) {
		memset(vis, 0, sizeof(vis));
		flag[i] = 1;
		DFS(1, -1);
		flag[i] = 0;
		if (vis[N]) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}