#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1010
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

int N;
string s;
char grid[MAXN][MAXN];
queue<pair<pair<ll, ll>, pii> > q;
int dist[MAXN][MAXN];
string ss[MAXN][MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	if (N == 1) {
	    cout << 0;
	    return 0;
	}
	for (int i=0; i<N; i++) {
		cin >> s;
		for (int j=0; j<N; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == '#') dist[i][j] = -1;
			else dist[i][j] = INF;
		}
	}
	q.push(mp(mp(0LL, 0LL), mp(0, 0)));
	dist[0][0] = 0;
	while (!q.empty()) {
		pair<pair<ll, ll>, pii> curr = q.front(); q.pop();
		if (curr.s == mp(N - 1, N - 1)) {
			ll ans = 1LL * (N - 1) * (N - 1) + curr.f.f * curr.f.f + curr.f.s * curr.f.s;
			cout << ans << "\n";
			return 0;
		}
		if (curr.s.f < N - 1 && dist[curr.s.f + 1][curr.s.s] > dist[curr.s.f][curr.s.s] + 1) {
			dist[curr.s.f + 1][curr.s.s] = dist[curr.s.f][curr.s.s] + 1;
			q.push(mp(mp(curr.f.f, curr.f.s), mp(curr.s.f + 1, curr.s.s)));
		}
		if (curr.s.s > 0 && dist[curr.s.f][curr.s.s - 1] > dist[curr.s.f][curr.s.s] + 1) {
			dist[curr.s.f][curr.s.s - 1] = dist[curr.s.f][curr.s.s] + 1;
			q.push(mp(mp(curr.f.f + 1, curr.f.s), mp(curr.s.f, curr.s.s - 1)));
		}
		if (curr.s.s < N - 1 && dist[curr.s.f][curr.s.s + 1] > dist[curr.s.f][curr.s.s] + 1) {
			dist[curr.s.f][curr.s.s + 1] = dist[curr.s.f][curr.s.s] + 1;
			q.push(mp(mp(curr.f.f, curr.f.s + 1), mp(curr.s.f, curr.s.s + 1)));
		}
	}
	cout << -1 << "\n";
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