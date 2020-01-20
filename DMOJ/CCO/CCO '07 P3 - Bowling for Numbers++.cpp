#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 510
#define MAXN 10010
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

int t, n, k, w;
int pins[MAXN], PSA[MAXN];
int DP[MAXM][MAXN];

inline int Solve (int balls, int width) {
	if (balls <= 0 || width < 0) return 0;
	int &val = DP[balls][width];
	if (~val) return val;
	int pos = max(0, width - w);
	int score = PSA[width] - PSA[pos];
	// cout << score << "\n";
	val = max(Solve(balls, width - 1), Solve(balls - 1, pos) + score);
	if (balls >= 2) {
		int sum = 0;
		for (int i=pos; i && i - pos + w - 1; i--) {
			sum += pins[i];
			// cout << sum << "\n";
			val = max(val, Solve(balls - 2, i - 1) + score + sum);
		}
	}
	return val;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n >> k >> w;
		memset(PSA, 0, sizeof(PSA));
		memset(DP, -1, sizeof(DP));
		for (int j=1; j<=n; j++) cin >> pins[j];
		for (int j=1; j<=n + w; j++) PSA[j] = PSA[j - 1] + pins[j];
		cout << Solve(k, n + w) << "\n";
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