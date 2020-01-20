#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M, Q, C, a, b;
ll ans;
int dist1[MAXN], dist2[MAXN];
queue<int> q;
bool vis[MAXN];
vi adj[MAXN];

inline void BFS (int src, int dist[]) {
	memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	vis[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			if (!vis[next]) {
				vis[next] = 1;
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q >> C;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));
	BFS(C, dist1);
	BFS(C, dist2);
	while (Q--) {
		cin >> a >> b;
		ans = dist1[a] + dist2[b];
		if (ans >= INF) cout << "This is a scam!\n";
		else cout << ans << "\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */