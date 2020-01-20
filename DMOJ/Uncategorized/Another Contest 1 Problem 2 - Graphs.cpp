#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100001
#define MOD 1000000007
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

int N, M, Q, x, y, level;
vi adj[MAXN];
int from[MAXN], idx[MAXN], dist[MAXN];
bool vis[MAXN];

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=1; i<=N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}

	inline int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	inline bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	inline void Union (int x, int y) {
		int a = Find(x), b = Find(y);
		if (Merge(x, y)) {
			if (rank[a] > rank[b]) {
				lead[b] = a;
				rank[a] += rank[b];
			}
			else {
				lead[a] = b;
				rank[b] += rank[a];
			}
		}
	}
};

Disjoint ds(MAXN);

inline int BFS (int src, int dest) {
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	vis[src] = vis[dest] = 1;
	dist[src] = dist[dest] = 0;	
	idx[src] = idx[dest] = level;
	from[src] = src;
	from[dest] = dest;
	q.push(src);
	q.push(dest);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (auto i : adj[curr]) {
			if (idx[i] ^ level) {
				if (!vis[i]) {
					vis[i] = 1;
					dist[i] = dist[curr] + 1;
					from[i] = from[curr];
					idx[i] = level;
					q.push(i);
				}
			}
			else if (from[i] ^ from[curr]) return dist[i] + dist[curr] + 1;
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
	cin >> N >> M >> Q;
	ds.make_Set();
	for (int i=1; i<=M; i++) {
		cin >> x >> y;
		ds.Union(x, y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	while (Q--) {
		cin >> x >> y;
		if (x == y) cout << 0 << "\n";
		else if (ds.Merge(x, y)) cout << -1 << "\n";
		else {
			++level;
			cout << BFS(x, y) << "\n";
		}
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