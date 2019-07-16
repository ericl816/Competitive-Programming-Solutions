#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 300010
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
#define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

// http://www.usaco.org/index.php?page=viewproblem&cpid=876

int N, K;
int DP[MAXN], G[MAXN], H[MAXN];
string s;
deque<int> dq;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> s;
	for (int i=1; i<=N; i++) {
		H[i] = H[i - 1] + (s[i - 1] == 'H');
		G[i] = G[i - 1] + (s[i - 1] == 'G');
	}
	dq.pb(0);
	for (int i=1; i<=N; i++) {
		while (!dq.empty() && dq.front() < i - K) dq.pop_front();
		if (!dq.empty()) DP[i] = DP[dq.front()] + (G[i] - G[dq.front()] >= H[i] - H[dq.front()] ? 1 : 0);
		while (!dq.empty() && (DP[dq.back()] > DP[i] || (DP[dq.back()] == DP[i] && G[i] - G[dq.back()] >= H[i] - H[dq.back()]))) dq.pop_back();
		dq.pb(i);
	}
	cout << DP[N] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */