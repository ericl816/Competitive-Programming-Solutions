#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 100010
#define MAXN 110
#define INF 0x3f3f3f3f
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

int N, M;
int X[MAXN], Y[MAXN], Sm[MAXN], Pm[MAXN], Sv[MAXN], Pv[MAXN];

inline bool Check (int serving) {
	ll res = 0LL;
	for (int i=0; i<N; i++) {
		int num = serving * X[i] - Y[i];
		if (num <= 0) continue;
		int minn = INF;
		for (int j=0; j * Sm[i]<=num; j++) {
			int k = (int) ceil(1.0 * max(0, num - j * Sm[i]) / Sv[i]); // # of large servings
			minn = min(minn, j * Pm[i] + k * Pv[i]);
		}
		for (int j=0; j * Sv[i]<=num; j++) {
			int k = (int) ceil(1.0 * max(0, num - j * Sv[i]) / Sm[i]); // # of small servings
			minn = min(minn, k * Pm[i] + j * Pv[i]);
		}
		res += minn;
	}
	return res <= M;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> X[i] >> Y[i] >> Sm[i] >> Pm[i] >> Sv[i] >> Pv[i];
	}
	int lo = 0, hi = MAXM;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (Check(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << hi << "\n";
	return 0;
}

/*
2 99966
10 100 96 10 100 11
10 100 80 10 100 11
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */