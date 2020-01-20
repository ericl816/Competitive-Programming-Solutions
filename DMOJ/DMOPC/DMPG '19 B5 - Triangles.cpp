#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, x, y, c;
vector<pair<int, pii> > vec;

inline bool Cmp (pair<int, pii> &a, pair<int, pii> &b) {
	return a.s.f < b.s.f;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x >> y >> c;
		vec.pb(mp(i + 1, mp(x, c)));
	}
	sort(vec.begin(), vec.end(), Cmp);
	for (size_t i=0; i<vec.size() - 2; i++) {
		int cc = vec[i].s.s + vec[i + 1].s.s + vec[i + 2].s.s;
		if (cc == 3 || cc == 6) continue;
		else {
			cout << vec[i].f << " " << vec[i + 1].f << " " << vec[i + 2].f << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */