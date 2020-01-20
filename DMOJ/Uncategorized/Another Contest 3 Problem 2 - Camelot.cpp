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
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
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

int N;
ll ans;
ll x[MAXN], y[MAXN];
pll points[MAXN];

inline bool Cmp1 (const pii &a, const pii &b) {
	return a.f < b.f;
}

inline bool Cmp2 (const pii &a, const pii &b) {
	return a.s < b.s;
}

inline ll Dist (ll midx, ll midy) {
	ll res = 0LL;
	for (int i=0; i<N; i++) res += max(abs(midx - x[i]), abs(midy - y[i]));
	return res;
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
		cin >> x[i] >> y[i];
		points[i] = mp(x[i] + y[i], x[i] - y[i]);
	}
	sort(points, points + N, Cmp1);
	ll midx = points[(N - 1) >> 1].f;
	sort(points, points + N, Cmp2);
	ll midy = points[(N - 1) >> 1].s;
	ll origx = midx, origy = midy;
	midx = (origx + origy) >> 1;
	midy = (origx - origy) >> 1;
	ans = Dist(midx, midy);
	ans = min(ans, Dist(midx + 1, midy));
	ans = min(ans, Dist(midx - 1, midy));
	ans = min(ans, Dist(midx, midy + 1));
	ans = min(ans, Dist(midx, midy - 1));
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