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

// https://codeforces.com/blog/entry/20935

int N, x, y;
int v[MAXN];
ll DP1[MAXN], DP2[MAXN];
vi adj[MAXN];
ll ans;

inline void DFS (int node, int prev) {
	ll sum1 = 0, sum2 = 0;
	for (auto i : adj[node]) {
		if (i == prev) continue;
		DFS(i, node);
		sum1 += DP2[i];
		sum2 += max(DP1[i], DP2[i]);
	}
	DP1[node] = v[node] + sum1;
	DP2[node] = sum2;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) cin >> v[i];
	for (int i=1; i<N; i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	DFS(1, 0);
	ans = max(DP1[1], DP2[1]);
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