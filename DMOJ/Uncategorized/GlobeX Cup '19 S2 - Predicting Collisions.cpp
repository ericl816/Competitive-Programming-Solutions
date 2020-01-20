#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 7
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-8
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
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

int N, M, a, b;
int f_coeff[MAXN], g_coeff[MAXN];
pii f[MAXN], g[MAXN], deriv_f[MAXN], deriv_g[MAXN];
long double ans;

inline long double Calc_x (pii p[MAXN], int n, long double x) {
	long double sum = 0;
	for (int i=0; i<=n; i++) sum += (pow(x, p[i].f) * p[i].s);
	return sum;
}

inline long double Newton (long double x) {
	long double res = (1.0 * Calc_x(f, N, x) - Calc_x(g, M, x)) / (Calc_x(deriv_f, N, x) - Calc_x(deriv_g, M, x));
	while (abs(res) >= EPS) {
		res = (1.0 * Calc_x(f, N, x) - Calc_x(g, M, x)) / (Calc_x(deriv_f, N, x) - Calc_x(deriv_g, M, x));
		x -= res;
	}
	return x;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<=N; i++) {
		cin >> f_coeff[i];
		f[i] = mp(N - i, f_coeff[i]);
		deriv_f[i] = mp(max(0, N - i - 1), ((N - i) * f_coeff[i]));
	}
	cin >> M;
	for (int i=0; i<=M; i++) {
		cin >> g_coeff[i];
		g[i] = mp(M - i, g_coeff[i]);
		deriv_g[i] = mp(max(0, M - i - 1), ((M - i) * g_coeff[i]));
	}
	cin >> a >> b;
	for (long double i=a; i<=b; i++) {
		long double rt = Newton(i);
		if (a <= rt && rt <= b) {
			cout << fixed << setprecision(8) << rt << "\n";
			return 0;
		}
	}
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