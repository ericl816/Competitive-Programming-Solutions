#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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

int N, Q, k;
int A[MAXN], l[MAXN], r[MAXN];
ll ans[MAXN];
pii m[MAXN], queries[MAXN];

struct BIT {
private:
	int N;
	vector<ll> tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	inline void Update (int idx, ll val) {
		for (; idx<=N; idx += idx &- idx) tree[idx] += val;
	}

	inline ll Query (int idx) {
		ll sum = 0LL;
		for (; idx; idx -= idx &- idx) sum += tree[idx];
		return sum;
	}

	inline ll Query (int x, int y) {
		return Query(y) - Query(x - 1);
	}
};

BIT tree(MAXN);

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
		tree.Update(i, A[i]);
		m[i] = mp(A[i], i);
	}
	for (int i=1; i<=Q; i++) {
		cin >> l[i] >> r[i] >> k;
		queries[i] = mp(k, i);
	}
	sort(m + 1, m + N + 1);
	sort(queries + 1, queries + Q + 1);
	int ind = 1;
	for (int i=1; i<=Q; i++) {
		while (ind <= N && queries[i].f > m[ind].f) {
			tree.Update(m[ind].s, -2 * m[ind].f);
			++ind;
		}
		ans[queries[i].s] = tree.Query(l[queries[i].s], r[queries[i].s]);
	}
	for (int i=1; i<=Q; i++) cout << ans[i] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */