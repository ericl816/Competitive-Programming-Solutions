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
#define EPS 0.000015 
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

int N, M;
long double C, want;
long double bright[MAXN * MAXN];

inline bool Error (long double x, long double y) {
	long double z = x - y;
	if (z < 0) z *= -1;
	return z < EPS;
}

inline long double Comp (long double lo, long double hi) {
	long double mid = (lo + hi) / 2.0, tot = 0.0;
	for (int i=0; i<N * M; i++) {
		if (mid * bright[i] > 1.0) tot++;
		else tot += mid * bright[i];
	}
	if (Error(tot, want)) return mid;
	else if (tot > want) return Comp(lo, mid);
	else if (tot < want) return Comp(mid, hi);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N * M; i++) cin >> bright[i];
	want = N * M * 0.48;
	long double res = Comp(0, 1000);
	if (Error(res, 1)) {
		cout << "correctly exposed\n";
	}
	else if (res < 1) {
		cout << "overexposed\n";
		cout << fixed << setprecision(5) << res << "\n";
	}
	else if (res > 1) {
		cout << "underexposed\n";
		cout << fixed << setprecision(5) << res << "\n";
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