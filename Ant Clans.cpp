#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 24
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

int n, m, k, a, b, c, partitions;
int dist[MAXN], MST[1 << MAXN], DP[1 << MAXN];
bool vis[MAXN];
vi edges[MAXN];
vector<pii> adj[MAXN];

/* 
 * Subtracts 31 with number of leading zeros (number of zeros before 1 in binary representation of bit)
 * Same as: __builtin_ctz(bit) -> gets number of trailing zeros
 */
inline int Get_FrontBit (int bit) {
	// return 31 - __builtin_clz(bit);
	return __builtin_ctz(bit);
}

inline int Prims (int bit) {
	MST[bit] = 0;
	memset(vis, 0, sizeof(vis));
	memset(dist, INF, sizeof(dist));
	dist[Get_FrontBit(bit)] = 0;
	for (int i=0; i<partitions - 1; i++) {
		int minnode = -1;
		for (int j=0; j<n; j++) {
			if (bit & (1 << j) && !vis[j] && (minnode == -1 || dist[j] < dist[minnode])) minnode = j;
		}
		if (~minnode) {
			vis[minnode] = 1;
			for (size_t k=0; k<adj[minnode].size(); k++) {
				pii &next = adj[minnode][k];
				if (bit & (1 << next.f) && !vis[next.f]) dist[next.f] = min(dist[next.f], next.s);
			}
		}
	}
	for (int i=0; i<n; i++) {
		if (bit & (1 << i)) MST[bit] = min(MST[bit] + dist[i], INF);
	}
	return MST[bit];
}

inline int Solve (int bit) {
	int &res = DP[bit];
	if (~res) return res;
	int num = __builtin_popcount(bit);
	if (num == partitions) return res = MST[bit];
	if (num < partitions) return res = INF;
	res = INF;
	for (size_t i=0; i<edges[Get_FrontBit(bit)].size(); i++) {
		int &next = edges[Get_FrontBit(bit)][i];
		// cout << next << " " << MST[next] << endl;
		// cout << (next & bit) << endl;
		// if ((next & bit) == next) res = min(res, MST[next] + Solve(bit ^ next));
		if ((next & bit) == next) res = min(res, MST[next] + Solve(bit & ~next));
	}
	return res;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	if (n % k) {
		cout << -1 << "\n";
		return 0;
	}
	partitions = n / k;
	memset(DP, -1, sizeof(DP));
	while (m--) {
		cin >> a >> b >> c;
		adj[--a].pb(mp(--b, c));
		adj[b].pb(mp(a, c));
	}
	for (int i=(1 << partitions) - 1; i<1 << n; i++) {
		if (__builtin_popcount(i) == partitions && Prims(i) ^ INF) edges[Get_FrontBit(i)].pb(i);
	}
	cout << (Solve((1 << n) - 1) == INF ? -1 : Solve((1 << n) - 1)) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */