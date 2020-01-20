#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 500010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int N, u, v, w, maxnode, furthest, length = -1, maxdist = -1, diam, radius;
vector<pii> adj[MAXN];
int dist[MAXN], len[MAXN];
bool vis[MAXN];

inline void BFS1 (int src) {
	queue<int> q;
	vis[src] = 1;
	dist[src] = 0;
	q.push(src);
	length = 0;
	furthest = src;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int nextcost = dist[curr] + next.s;
			if (!vis[next.f]) {
				vis[next.f] = 1;
				dist[next.f] = nextcost;
				if (dist[next.f] > length) {
					length = dist[next.f];
					furthest = next.f;
				}
				q.push(next.f);
			}
		}
	}
}

inline void BFS2 (int src) {
	queue<pii> q;
	dist[src] = 0;
	q.push(mp(src, -1));
	maxdist = 0;
	maxnode = src;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr.f].size(); i++) {
			pii &next = adj[curr.f][i];
			if (next.f == curr.s) continue;
			int nextcost = dist[curr.f] + next.s;
			dist[next.f] = nextcost;
			if (dist[next.f] > maxdist) {
				maxdist = dist[next.f];
				maxnode = next.f;
			}
			q.push(mp(next.f, curr.f));
		}
	}
}

inline bool get_Radius (int src, int prev, int dest) {
	if (src == dest) {
		radius = min(radius, maxdist);
		len[src] = 0;
		return 1;
	}
	for (size_t i=0; i<adj[src].size(); i++) {
		pii &next = adj[src][i];
		if (next.f == prev) continue;
		if (get_Radius(next.f, src, dest)) {
			len[src] = len[next.f] + next.s;
			radius = min(radius, max(len[src], maxdist - len[src]));
			return 1;
		}
	}
	return 0;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<N; i++) {
		cin >> u >> v >> w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	for (int i=1; i<=N; i++) {
		if (!vis[i]) {
			radius = INF;
			BFS1(i);
			BFS2(furthest);
			get_Radius(furthest, -1, maxnode);
			diam = max(diam, maxdist);
		}
	}
	cout << diam << "\n" << radius << "\n";
	return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */