#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define EPS 1e-10
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
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

ll N, M;
ll x[MAXN], y[MAXN], ax[MAXN], bx[MAXN], cx[MAXN], ay[MAXN], by[MAXN], cy[MAXN];

inline long double Area (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
   return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

inline bool Inside (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x, ll y) {
	long double A = Area(x1, y1, x2, y2, x3, y3);
	long double A1 = Area(x, y, x2, y2, x3, y3);  
	long double A2 = Area(x1, y1, x, y, x3, y3);
	long double A3 = Area(x1, y1, x2, y2, x, y);
	return (A == (A1 + A2 + A3));
}

inline bool Collinear (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return ((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2));
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
	for (int i=0; i<N; i++) cin >> x[i] >> y[i];
	for (int i=0; i<M; i++) {
		cin >> ax[i] >> ay[i] >> bx[i] >> by[i] >> cx[i] >> cy[i];
		int ans = 0;
		for (int j=0; j<N; j++) {
			if (Inside(ax[i], ay[i], bx[i], by[i], cx[i], cy[i], x[j], y[j]) || Collinear(ax[i], ay[i], bx[i], by[i], x[j], y[j]) || Collinear(cx[i], cy[i], bx[i], by[i], x[j], y[j]) || Collinear(ax[i], ay[i], cx[i], cy[i], x[j], y[j])) {
				ans++;
				continue;
			}
		}
		cout << ans << "\n";
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