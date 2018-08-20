#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 55
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

int N, M;
int choc[MAXN][MAXN], PSA[MAXN][MAXN];
int DP[MAXN][MAXN][MAXN][MAXN];

inline int Solve (int x1, int y1, int x2, int y2) {
	int &res = DP[x1][y1][x2][y2];
	if (x1 == x2 && y1 == y2) return res = 0;
	if (~res) return res;
	res = PSA[x2][y2] - PSA[x1 - 1][y2] - PSA[x2][y1 - 1] + PSA[x1 - 1][y1 - 1];
	int val = INF;
	for (int i=x1 + 1; i<=x2; i++) val = min(val, Solve(i, y1, x2, y2) + Solve(x1, y1, i - 1, y2));
	for (int i=y1 + 1; i<=y2; i++) val = min(val, Solve(x1, i, x2, y2) + Solve(x1, y1, x2, i - 1));
	return res += val;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	memset(DP, -1, sizeof(DP));
	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> choc[i][j];
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) PSA[i][j] = choc[i][j] + PSA[i - 1][j] + PSA[i][j - 1] - PSA[i - 1][j - 1];
	cout << Solve(0, 0, N - 1, M - 1) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */