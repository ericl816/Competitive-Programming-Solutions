#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 656100
#define MAXN 810
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

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N, size;
int p[MAXN][MAXN];
umii arr;
ll sum;
map<ll, ll> tree[MAXM];
set<int> s;

inline void Update (int x, int y, int val) {
	for (int a=x; a<MAXN; a += a & -a) {
		for (int b=y; b<MAXM; b += b & -b) {
			tree[a][b] += val;
		}
	}
}

inline ll Query (int x, int y) {
	ll sum = 0;
	for (int a=x; a; a -= a & -a) {
		for (int b=y; b; b -= b & -b) {
			sum += tree[a][b];
		}
	}
	return sum;
}

inline ll Query (int x1, int y1, int x2, int y2) {
    return Query(x2, y2) - Query(x2, y1 - 1) - Query(x1 - 1, y2) + Query(x1 - 1, y1 - 1);
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
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> p[i][j];
			s.insert(p[i][j]);
		}
	}
	for (auto i : s) arr[i] = ++size;
	for (int i=0; i<N; i++) {
		for (int j=N - 1; j>=0; j--) {
			ll k = Query(1, arr[p[i][j]], j, 640000);
			sum += k;
			Update(j + 1, min(640000, arr[p[i][j]] + k), 1);
		}
	}
	cout << sum << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */