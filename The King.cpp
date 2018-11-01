#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 11
#define MAXN 1024
#define MAXK 110
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

/* 
 * Find the number of ways in which K kings can be placed on an N x M chessboard
 * so that no two kings are not in adjacent squares.
 * Source: http://codeforces.com/problemsets/acmsguru/problem/99999/223
 * Use Bitmask DP
 */

int n, k;
ll DP[MAXM][MAXK][MAXN];

inline ll Solve (int r, int t, int mask) {
	bool a[12], b[12];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	bool adj = 0;
	for (int i=mask, x=1; i>0; i>>=1, x++) b[x] = i & 1;
	for (int i=1; i<=n; i++) {
		if ((b[i] == b[i - 1]) && (b[i])) adj = 1;
	}
	if (adj) return 0;
	if (r == 0) {
		if (__builtin_popcount(mask) ^ t) return 0;
		else return 1;
	}
	ll &ret = DP[r][t][mask];
	if (~ret) return ret;
	ret = 0;
	for (int i=0; i<1 << n; i++) {
		for (int j=i, x=1; j>0; j>>= 1, x++)
			a[x] = j & 1;
		bool check = 1;
		for (int j=1; j<=n; j++) {
			if (b[j]) {
				if ((a[j - 1]) || (a[j]) || (a[j + 1])) check = 0;
			}
		}
		if (check) ret += Solve(r - 1, t - __builtin_popcount(mask), i);
	}
	return ret;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> n >> k;
	cout << Solve(n, k, 0) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */