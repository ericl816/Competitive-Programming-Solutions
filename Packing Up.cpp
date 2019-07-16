#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2000010
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

int N, L, last;
ll C[MAXN], x, DP[MAXN], psa[MAXN];

/* 
 * Solution uses DP and is very similar as APIO '10 P1 - Commando
 * However, it is NOT the intended solution, which uses the Convex Hull Trick
 */

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	psa[0] = 0;
	for (int i=1; i<=N; i++) {
		cin >> C[i];
		psa[i] += psa[i - 1] + C[i];
	}
	memset(DP, INF, sizeof(DP));
	DP[0] = 0;
	for (int i=1; i<=N; i++) {
		for (int j=last; j<i; j++) {
			x = psa[i] - psa[j] + i - j - 1;
			if (DP[i] > DP[j] + pow((x - L), 2)) {
				DP[i] = DP[j] + pow((x - L), 2);
				last = j;
			}
		}
	}
	cout << DP[N] << endl;
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */