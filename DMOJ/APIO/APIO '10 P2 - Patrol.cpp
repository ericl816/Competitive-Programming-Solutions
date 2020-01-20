#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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

int N, K, A, B, node, maxnode, longest1, longest2, tot, ans;
vector<pii> adj[MAXN];
int dist[MAXN], par[MAXN], len1[MAXN], len2[MAXN];
bool vis[MAXN];
queue<int> q;

inline void DFS1 (int node, int prev) {
	for (auto i : adj[node]) {
		if (par[node] == i.f || prev == i.f) continue;
		par[i.f] = node;
		dist[i.f] = dist[node] + 1;
		DFS1(i.f, node);
	}
	if (dist[node] > longest1) {
		longest1 = dist[node];
		maxnode = node;
	}
}

inline void DFS2 (int node, int prev) {
	bool flag = 0;
	for (auto i : adj[node]) {
		if (par[node] == i.f || prev == i.f) {
			continue;
		}
		flag = 1;
		par[i.f] = node;
		DFS2(i.f, node);
		if (len1[i.f] + i.s > len1[node]) {
			len2[node] = len1[node];
			len1[node] = len1[i.f] + i.s;
		}
		else if (len1[i.f] + i.s > len2[node]) len2[node] = len1[i.f] + i.s;
	}
	if (!flag) len1[node] = 0;
	longest2 = max(longest2, max(len1[node], max(len2[node], len1[node] + len2[node])));
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	tot = (N - 1) << 1;
	for (int i=1; i<N; i++) {
		cin >> A >> B;
		adj[--A].pb(mp(--B, 1));
		adj[B].pb(mp(A, 1));
	}
	memset(par, -1, sizeof(par));
	DFS1(0, -1);
	dist[maxnode] = longest1 = 0;
	// D("%d %d %d\n", maxnode, dist[maxnode], par[maxnode]);
	par[maxnode] = -1;
	DFS1(maxnode, -1);
	if (K == 1) {
		ans = tot - longest1 + 1;
		cout << ans << "\n";
		return 0;
	}
	while (~par[maxnode]) {
		for (auto i : adj[maxnode]) {
			if (par[maxnode] ^ i.f) continue;
			for (auto j : adj[i.f]) {
				if (maxnode == j.f) {
					j.s = -1;
					break;
				}
			}
			i.s = -1;
			maxnode = i.f;
			break;
		}
	}
	par[0] = -1;
	DFS2(0, -1);
	ans = tot - longest2 - longest1 + 4;
	cout << ans << "\n";
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