#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
#define INF 0x3f3f3f3f
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

int N;
pii a[MAXN];
int DP[MAXN][3];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) cin >> a[i].f;
	for (int i=1; i<=N; i++) cin >> a[i].s;
	for (int i=1; i<=N; i++) {
		DP[i][0] = max(DP[i - 1][0], max(DP[i - 1][1], DP[i - 1][2])) + a[i].s;
		DP[i][1] = DP[i - 1][0] + a[i].f;
		DP[i][2] = DP[i - 1][1] + a[i].f;
	}
	cout << max(DP[N][0], max(DP[N][1], DP[N][2])) << "\n";
	return 0;
}

/*
7
6 0 -5 7 -9 10 12
3 1 -8 10 5 6 7
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */