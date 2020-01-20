#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (begin) ? (a) : (b)
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

int k, n;
int x[MAXN], cards[MAXN], freq[MAXN];
long double DP[MAXN], poww[MAXN];
vi mq[MAXN];

inline long double Calc (int a, int b) {
	return DP[a - 1] + poww[b - cards[a] + 1];
}

inline long double Slope (int a, int b) {
	long double res1 = DP[a - 1] + poww[cards[a] - 1], res2 = DP[b - 1] + poww[cards[b] - 1];
	return (res2 - res1) / (2.0 * ((cards[b] - 1) - (cards[a] - 1)));
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i];
		poww[i] = pow(i, k / 2.0);
	}
	DP[0] = 0;
	for (int i=1; i<=n; i++) {
		cards[i] = ++freq[x[i]];
		while (mq[x[i]].size() >= 2 && Slope(mq[x[i]][mq[x[i]].size() - 2], mq[x[i]][mq[x[i]].size() - 1]) <= Slope(mq[x[i]][mq[x[i]].size() - 2], i)) mq[x[i]].pop_back();
		mq[x[i]].pb(i);
		while (mq[x[i]].size() >= 2 && Calc(mq[x[i]][mq[x[i]].size() - 2], cards[i]) >= Calc(mq[x[i]][mq[x[i]].size() - 1], cards[i])) mq[x[i]].pop_back();
		DP[i] = Calc(mq[x[i]].back(), cards[i]);
	}
	cout << fixed << setprecision(10) << DP[n] << "\n";
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