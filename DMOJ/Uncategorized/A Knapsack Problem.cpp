#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 5010
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
using namespace std;

int N, M;
int n[MAXN], v[MAXN], p[MAXN], c[MAXN], f[MAXN];
ll DP[2][MAXN];
ll ans = -INF;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) cin >> n[i] >> v[i] >> p[i];
	for (int i=0; i<N; i++) {
		for (int j=0; j<MAXN; j++) {
			ll num = 0;
			while (j >= num * v[i] && num <= n[i]) {
				DP[i & 1][j] = max(DP[i & 1][j], DP[(i & 1) ^ 1][j - num * v[i]] + num * p[i]);
				++num;
			}
		}
	}
	for (int i=0; i<M; i++) {
		cin >> c[i] >> f[i];
		ans = max(ans, DP[(N - 1) & 1][c[i]] - f[i]);
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