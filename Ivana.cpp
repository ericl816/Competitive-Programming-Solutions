#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

int N, ans;
int parity[MAXN];
int DP[MAXN][MAXN][MAXN];

inline int Solve (int a, int b, int c) {
	// Make sure to cycle over, since it's a circle
	if (a == -1) a = N - 1;
	if (b == N) b = 0;
	int &val = DP[a][b][c];
	if (~val) return val;
	// 2 integers have to be adjacent
	if (abs(a - b) == 1 || (a == 0 && b == N - 1)) {
		if (a == c) return val = parity[b];
		else if (b == c) return val = parity[a];
		else return val = parity[a] ^ parity[b];
	}
	int maxx = -INF;
	if (a == b) maxx = parity[a] - Solve(a - 1, b + 1, c);
	else {
		if (a >= 0) maxx = max(maxx, parity[a] - Solve(a - 1, b, c));
		if (b < N) maxx = max(maxx, parity[b] - Solve(a, b + 1, c));
	}
	return val = maxx;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0, a; i<N; i++) {
		cin >> a;
		parity[i] = a & 1;
	}
	memset(DP, -1, sizeof(DP));
	for (int i=0; i<N; i++) ans += Solve(i, i, i) > 0;
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