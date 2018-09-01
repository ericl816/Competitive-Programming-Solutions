#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 100010
#define MAXN 200010
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int B, F;
ll ans;
int f[MAXM], e[MAXM], p[MAXM], t[MAXM];
vi cases;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> B;
	for (int i=0; i<B; i++) {
		cin >> f[i] >> e[i] >> p[i];
	}
	cin >> F;
	for (int i=0; i<F; i++) {
		cin >> t[i];
		cases.pb(t[i]);
	}
	sort(cases.begin(), cases.end());
	for (int i=0; i<B; i++) {
		int ind1 = lower_bound(cases.begin(), cases.end(), f[i]) - cases.begin();
		int ind2 = upper_bound(cases.begin(), cases.end(), e[i]) - cases.begin() - 1;
		if (ind2 < ind1) ans += p[i];
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