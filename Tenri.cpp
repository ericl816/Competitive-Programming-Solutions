#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 20
#define MAXN 5010
#define INF 0x3f3f3f3f
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

int N, S;
int box[MAXN], val[MAXM];
int DP[MAXN][MAXM];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i=0; i<N; i++) {
		cin >> box[i];
		for (int j=0; j<=S; j++) DP[1 << i][j] = (box[i] + j) * (box[i] + j) + j;
	}
	for (int i=1; i<1 << N; i++) {
	    int num = __builtin_popcount(i);
		if (!(num & 1)) continue;
		for (int j=1; j<i; j++) {
			if (!(i & j)) {
				for (int k=0; k<N; k++) {
					if (!((i | j) & (1 << k))) {
						memset(val, 0, sizeof(val));
						int idx = i | j | (1 << k);
						for (int l=0; l<=S; l++) for (int m=0; m<=l; m++) val[l] = max(val[l], DP[i][m] * DP[j][l - m]);
						for (int l=S; l>=0; l--) for (int m=0; m<=l; m++) DP[idx][l] = max(DP[idx][l], min(val[m], (box[k] + l - m) * (box[k] + l - m)) + l - m);
					}
				}
			}
		}
	}
	cout << DP[(1 << N) - 1][S] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */