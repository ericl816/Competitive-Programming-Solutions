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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, K, num;
int v[MAXN], mm[MAXN], DP[MAXN];
pii players[MAXN];

inline bool Cmp (pii &a, pii &b) {
	return a.s < b.s;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) {
		cin >> v[i];
		players[i] = mp(i, v[i]);
	}
	sort(players, players + N, Cmp);
	for (int i=0; i<N; i++) mm[players[i].f] = i / K + 1;
	for (int i=0; i<N; i++) {
		DP[i] = 1;
		for (int j=0; j<i; j++) if (mm[j] <= mm[i]) DP[i] = max(DP[i], DP[j] + 1);
		num = max(num, DP[i]);
	}
	cout << N - num << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */