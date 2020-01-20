#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXQ 22
#define MAXM 100010
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

int N, M, op, a, b, l, r, c;
int goodness[MAXN];
int BIT[MAXQ][MAXN];

inline void Update (int BIT[MAXN], int idx, int val) {
	for (; idx<=MAXN; idx += idx & -idx) BIT[idx] += val;
}

inline void Update (int BIT[MAXQ][MAXN], int idx, int val) {
	Update(BIT[goodness[idx]], idx, -1);
	Update(BIT[val], idx, 1);
	goodness[idx] = val;
}

inline int Query (int BIT[MAXN], int idx) {
	int sum = 0;
	for (; idx; idx -= idx & -idx) sum += BIT[idx];
	return sum;
}

inline int Query (int BIT[MAXN], int l, int r) {
	return Query(BIT, r) - Query(BIT, l - 1);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=1; i<=N; i++) {
		cin >> goodness[i];
		Update(BIT[goodness[i]], i, 1);
	}
	while (M--) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			Update(BIT, a, b);
		}
		else {
			cin >> l >> r >> c;
			int res = 0;
			for (int i=20; i>=0; i--) {
			    res += Query(BIT[i], l, r);
				if (res >= c) {
					cout << i << "\n";
					break;
				}
			}
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