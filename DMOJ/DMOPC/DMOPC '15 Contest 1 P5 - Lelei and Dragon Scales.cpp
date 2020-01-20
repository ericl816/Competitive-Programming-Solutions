#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 310
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

int W, H, N, ans, tot;
int PSA[MAXN][MAXN];

inline int Calc (int r, int c) {
	tot = 0;
	for (int i=1; i<=r; i++) {
		int j = min(c, N / i);
		tot = max(tot, PSA[r][c] - PSA[r - i][c] - PSA[r][c - j] + PSA[r - i][c - j]);
	}
	return tot;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> W >> H >> N;
	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			cin >> PSA[i][j];
			PSA[i][j] += PSA[i - 1][j] + PSA[i][j - 1] - PSA[i - 1][j - 1];
			ans = max(ans, Calc(i, j));
		}
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