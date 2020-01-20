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
int N, M, A, B, a, b, c;
ll C;
ll dist[MAXN];
bool vis[MAXN];
vector<pair<int, pii> > adj[MAXN];
queue<pii> q;
inline bool SPFA (int src, int mid) {
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	dist[src] = 0;
	q.push(mp(0, src));
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		vis[curr.s] = 0;
		for (auto i : adj[curr.s]) {
			if (i.f > mid) break;
			if (dist[i.s.f] > dist[curr.s] + i.s.s) {
				dist[i.s.f] = dist[curr.s] + i.s.s;
				if (!vis[i.s.f]) {
					vis[i.s.f] = 1;
					q.push(mp(dist[i.s.f], i.s.f));
				}
			}
		}
	}
	return dist[B] < C;
}
int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=1; i<=M; i++) {
		cin >> a >> b >> c;
		adj[a].pb(mp(i, mp(b, c)));
		adj[b].pb(mp(i, mp(a, c)));
	}
	cin >> A >> B >> C;
	int lo = 0, hi = M;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (SPFA(A, mid)) hi = mid - 1;
		else lo = mid + 1;
	}
	cout << (lo <= M ? lo : -1) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */