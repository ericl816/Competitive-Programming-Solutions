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

int N, T;
ll L, R, a, b, c;
ll diffa[MAXN], diffb[MAXN], diffc[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for (int i=1; i<=N; i++) {
		cin >> L >> R >> a >> b >> c;
		diffa[L] += a;
		diffb[L] += b - ((a * L) << 1);
		diffc[L] += a * L * L - b * L + c;
		diffa[R + 1] -= a;
		diffb[R + 1] -= b - ((a * L) << 1);
		diffc[R + 1] -= a * L * L - b * L + c;
	}
	for (int i=1; i<=T; i++) {
		diffa[i] += diffa[i - 1];
		diffb[i] += diffb[i - 1];
		diffc[i] += diffc[i - 1];
	}
	for (int i=1; i<=T; i++) cout << diffa[i] * i * i + diffb[i] * i + diffc[i] << " ";
	cout << "\n";
	return 0;
}

/*
2 6
1 6 1 3 2
3 4 2 2 -200
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */