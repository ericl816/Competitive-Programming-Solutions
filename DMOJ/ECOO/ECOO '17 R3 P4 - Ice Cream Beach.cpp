#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 25
#define MAXN 4010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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
ll X[MAXN], F[MAXN];
ll DP[MAXN][MAXM], PSA[MAXN][MAXN], loc[MAXN][MAXN];

inline ll Query (int x, int y, int idx) {
	return PSA[y][idx] - PSA[x - 1][idx];
}

inline ll Get_Loc (int x, int y) {
	ll currdist = Query(x, y, x);
	int lo = x + 1, hi = y;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (Query(x, y, mid) <= Query(x, y, mid - 1)) lo = mid + 1;
		else hi = mid - 1;
	}
	return min(currdist, Query(x, y, hi));
}

inline void Solve () {
	scan(N); scan(M);
	memset(PSA, 0, sizeof(PSA));
	for (int i=1; i<=N; i++) {
		scan(X[i]);
		scan(F[i]);
	}
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) PSA[i][j] = F[i] * abs(X[i] - X[j]) + PSA[i - 1][j]; 
	for (int i=1; i<=N; i++) for (int j=i; j<=N; j++) loc[i][j] = Get_Loc(i, j);
	memset(DP, INF, sizeof(DP));
	for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) if (i <= j) DP[i][j] = 0;
	for (int i=1; i<=N; i++) DP[i][1] = Get_Loc(1, i);
	for (int i=2; i<=N; i++) for (int j=2; j<=M; j++) for (int k=2; k<=i; k++) DP[i][j] = min(DP[i][j], DP[k - 1][j - 1] + loc[k][i]);
	printf("%lld\n", (DP[N][M] + MOD) % MOD);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test_cases = 10;
	while (test_cases--) Solve();
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */