#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 35
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

int n, t;
int movex[4] = {0, 0, -1, 1};
int movey[4] = {-1, 1, 0, 0};
int grid[MAXN][MAXN], dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pii> q;

inline bool Valid (int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				cin >> grid[i][j];
			}
		}
		memset(dist, INF, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		dist[1][1] = 0;
		vis[1][1] = 1;
		q.push(mp(1, 1));
		while (!q.empty()) {
			pii curr = q.front(); q.pop();
			for (int i=0; i<4; i++) {
				int x = curr.f + movex[i], y = curr.s + movey[i];
				if (abs(grid[curr.f][curr.s] - grid[x][y]) > 2 || !Valid(x, y)) continue;
				int cost = ((grid[x][y] > grid[1][1] || grid[curr.f][curr.s] > grid[1][1]) ? dist[curr.f][curr.s] + 1 : dist[curr.f][curr.s]);
				if (!vis[x][y]) {
					vis[x][y] = 1;
					dist[x][y] = cost;
					q.push(mp(x, y));
				}
			}
		}
		if (dist[n][n] ^ INF) cout << dist[n][n] << "\n\n";
		else cout << "CANNOT MAKE THE TRIP\n\n";
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