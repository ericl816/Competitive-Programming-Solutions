#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 3010
#define INF 0x3f3f3f3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

ll N, M, D, u, v, t, c, d, tot;
queue<ll> q;
ll dist[MAXN], dist1[MAXN], cost[MAXN];
ll DP[MAXN][MAXN];
bool vis[MAXN], flag[MAXN][MAXN];
vector<pair<ll, ll> > adj[MAXN];

inline void SPFA () {
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		ll curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pair<ll, ll> &next = adj[curr][i];
			if (dist[next.f] > dist[curr] + next.s + tot) {
				dist[next.f] = dist[curr] + next.s + tot;
				if (!vis[next.f]) {
					vis[next.f] = 1;
					q.push(next.f);
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
	cin >> N >> M >> D;
	while (M--) {
		cin >> u >> v >> t;
		adj[u].pb(mp(v, t));
	}
	while (D--) {
	    cin >> c >> d;
	    tot += c;
	    SPFA();
	    if (dist[d] < INF) cout << dist[d] << "\n";
	    else cout << "Cannot Deliver\n";
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