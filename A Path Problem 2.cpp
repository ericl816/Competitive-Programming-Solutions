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

int N, M, a, b, c, A, B;
vector<pii> adj[MAXN];
ll dist[MAXN], cnt[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;

inline void Dijkstra (int node) {
	memset(dist, INF, sizeof(dist));
	dist[node] = 0;
	cnt[node] = 1;
	pq.push(mp(0, node));
	while (!pq.empty()) {
		pii curr = pq.top();
		pq.pop();
		if (dist[curr.s] < curr.f) continue;
		for (auto i : adj[curr.s]) {
			if (dist[i.f] > dist[curr.s] + i.s) {
				dist[i.f] = dist[curr.s] + i.s;
				cnt[i.f] = cnt[curr.s];
				pq.push(mp(dist[i.f], i.f));
			}
			else if (dist[i.f] == dist[curr.s] + i.s) {
				cnt[i.f] += cnt[curr.s];
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
	cin >> N >> M >> A >> B;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> c;
		adj[a].pb(mp(b, c));
		adj[b].pb(mp(a, c));
	}
	Dijkstra(A);
	cout << dist[B] << "\n" << cnt[B] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */