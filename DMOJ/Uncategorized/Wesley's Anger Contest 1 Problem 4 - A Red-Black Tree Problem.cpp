#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 4
#define MAXN 110
#define MOD 998244353
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

int N, K, u, v;
char ch;
bool flag[MAXN], vis[MAXN];
ll ans;
ll DP[MAXN][MAXN][MAXM][MAXM];
ll merged[MAXN][MAXM][MAXM];
vi adj[MAXN];

inline void DFS (int node, int prev) {
	if (vis[node]) return;
	vis[node] = 1;
	DP[node][1][flag[node]][flag[node] ^ 1] = 1;
	for (auto next : adj[node]) {
		if (next == prev) continue;
		DFS(next, node);
		for (int i=0; i<=K; i++) {
			for (int j=0; j<=2; j++) {
				for (int k=0; k<=2; k++) {
					merged[i][j][k] = DP[node][i][j][k];
					DP[node][i][j][k] = 0;
				}
			}
		}
		for (int i=0; i<=2; i++) {
			for (int j=0; j<=2; j++) {
				for (int k=0; k<=K; k++) {
					for (int l=0; l<=2; l++) {
						for (int m=0; m<=2; m++) {
							for (int n=0; k + n<=K; n++) {
								DP[node][k + n][min(i + l, 2)][min(j + m, 2)] += merged[k][i][j] * DP[next][n][l][m];
								DP[node][k + n][min(i + l, 2)][min(j + m, 2)] %= MOD;
							}
						}
					}
				}
			}
		}
	}
	DP[node][0][0][0] = 1;
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
	for (int i=1; i<=N; i++) {
		cin >> ch;
		flag[i] = ch == 'R';
	}
	for (int i=1; i<N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DFS(1, -1);
	for (int i=1; i<=N; i++) {
		ans += DP[i][K][2][2];
		ans %= MOD;
	}
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