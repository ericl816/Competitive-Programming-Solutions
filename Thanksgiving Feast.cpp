#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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

int N, M, K, A, B, a, b;
ll ans = INF;
int dist1[MAXN], dist2[MAXN], s[MAXN];
bool vis[MAXN];
vi adj[MAXN];
queue<int> q;

inline void SSSP (int src, int dist[]) {
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	dist[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			if (dist[next] > dist[curr] + 1) {
				dist[next] = dist[curr] + 1;
				if (!vis[next]) {
					vis[next] = 1;
					q.push(next);
				}
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
	cin >> N >> M >> K >> A >> B;
	for (int i=0; i<K; i++) {
		cin >> s[i];
		--s[i];
	}
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));
	SSSP(--A, dist1);
	SSSP(--B, dist2);
	for (int i=0; i<K; i++) ans = min(ans, dist1[s[i]] + dist2[s[i]]);
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */