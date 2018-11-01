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

const int LEN = 1000000;
int H, k;
vi houses;

inline int Check (int hose) {
	int minn = H, diam = hose << 1;
	for (size_t i=0; i<houses.size() && houses[0] + diam >= houses[i]; i++) {
		int cnt = 1, curr = houses[i];
		for (int j=i + 1; j<houses.size() && houses[i] + LEN > houses[j] + diam; j++) {
			if (houses[j] > curr) {
				++cnt;
				curr = houses[j] + diam;
			}
		}
		minn = min(minn, cnt);
	}
	return minn;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> H;
	for (int i=0, x; i<H; i++) {
		cin >> x;
		houses.pb(x);
	}
	cin >> k;
	sort(houses.begin(), houses.end());
	int lo = 0, hi = LEN - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (k < Check(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << lo << "\n";
	return 0;
}

/*
4
0
67000
68000
77000
2
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */