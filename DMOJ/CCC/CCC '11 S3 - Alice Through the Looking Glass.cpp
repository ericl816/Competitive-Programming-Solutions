#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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

int T, m, x, y;

inline int QPow (int x, int y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y & 1) return x * QPow(x * x, y >> 1);
	return QPow(x * x, y >> 1);
}

inline bool Crystal (int n, int x, int y) {
	if (n == 0) return 0;
	int x1 = x / QPow(5, n - 1), y1 = y / QPow(5, n - 1);
	if (((x1 == 1 || x1 == 3) && y1 == 0) || (x == 2 && y == 1)) return 1;
	if (((x1 == 1 || x1 == 3) && y1 == 1) || (x1 == 2 && y1 == 2)) return Crystal(n - 1, x % QPow(5, n - 1), y % QPow(5, n - 1));
	return 0;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> m >> x >> y;
		cout << (Crystal(m, x, y) ? "crystal\n" : "empty\n");
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