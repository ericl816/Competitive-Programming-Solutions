#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;
int N, P;
ll a[MAXN], PSA[MAXN];
ll ans;
struct BIT {
private:
	int N;
	vector<ll> tree;
public:
	BIT (int N) : N(N), tree(N + 1) { }
	inline void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}
	inline ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
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
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	cin >> P;
	a[0] -= P;
	PSA[0] = a[0];
	for (int i=1; i<N; i++) {
		a[i] += a[i - 1] - P;
		PSA[i] = a[i];
	}
	sort(PSA, PSA + N);
	for (int i=0; i<N; i++) {
		int rank = int(lower_bound(PSA, PSA + N, a[i]) - PSA);
		++rank;
		ans += tree.Query(rank);
		if (a[i] >= 0) ans++;
		tree.Update(rank, 1);
	}
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */