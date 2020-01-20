#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 10010
#define MAXN 2010
#define INF 254
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
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

int N, V, c, l, prevans;
int d[MAXN];
unsigned char DP[MAXN][MAXM];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> V;
	memset(DP, INF, sizeof(DP));
	for (int i=1; i<=N; i++) cin >> d[i];
	DP[0][0] = 0;
	for (int i=1; i<=N; i++) {
		for (int j=0; j<=10000; j++) {
			if (j >= d[i]) DP[i][j] = min(DP[i - 1][j], DP[i][j - d[i]] + 1);
			else DP[i][j] = DP[i - 1][j];
		}
	}
	while (V--) {
		cin >> c >> l;
		c ^= prevans, l ^= prevans;
		cout << (DP[l][c] == INF ? -1 : DP[l][c]) << "\n";
		prevans = DP[l][c] == INF ? 0 : DP[l][c];
	}
	return 0;
}

/*
6 3
7 10 15 2 3 24
107 3
4 12
26 0

Ans:
8
2
3
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */