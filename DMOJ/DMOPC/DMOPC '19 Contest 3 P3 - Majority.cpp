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
#define MAXM 300010
#define MAXN 150010
#define MOD 1000000007
#define INF 0x3f3f3f3f
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

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (idx += MAXN; idx<MAXM; idx += idx & -idx) tree[idx] += val;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (idx += MAXN; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

	ll Query (int l, int r) {
		return Query(r) - Query(l - 1);
	}
} tree(MAXM);

int N;
int v[MAXN];
ll PSA[MAXN], SSA[MAXN];
ll ans;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> v[i];
		if (v[i] == 1) PSA[i] = PSA[i - 1] + 1;
		else PSA[i] = PSA[i - 1] - 1;
	}
	for (int i=N; i>=0; i--) {
		if (v[i] == 1) SSA[i] = SSA[i + 1] + 1;
		else SSA[i] = SSA[i + 1] - 1;
	}
	for (int i=1; i<=N + 1; i++) tree.Update(SSA[i], 1);
	for (int i=1; i<=N; i++) {
		tree.Update(SSA[i], -1);
		ans += tree.Query(PSA[N] - PSA[i - 1] - 1);
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